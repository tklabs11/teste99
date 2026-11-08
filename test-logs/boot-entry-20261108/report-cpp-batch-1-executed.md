# Marco 6 — lote 1 dos inicializadores C++ executado (2026-11-08)

Continuação de `report-cpp-batch-1.md`. Aquele relatório mediu o lote; este
registra a execução real dos cinco primeiros inicializadores da tabela
`0x013cc80c..0x013eb098` e o novo bloqueio, `0x013002d0`.

Identidade da PE original: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
(referência e candidata coincidem).

## 1. Resultado

| lado | resultado |
| --- | --- |
| lift x86 (Windows) | `PASS crt_cpp_walk stop=0x011e0f98 executed=107 ... imports=26 initializers=5 walk=stopped_at_0x013002d0` |
| build ARM64 (`aarch64-linux-android29`) | `PASS arm64_build` |
| igualdade x86 ↔ ARM64 | `PASS x86_vs_arm64` (linha `PASS` idêntica) |
| execução no aparelho `PJMZAEJRX4YLFIDI` | `PASS arm64_device_run` |

Os oito estágios do arranque passam, sete deles com execução no aparelho:

```
PASS crt_entry stop=0x011e0ee7 executed=56
PASS crt_startupinfo stop=0x011e0efe executed=84
PASS crt_interlocked stop=0x011e0f24 executed=93
PASS crt_startup_lock stop=0x011e0f43 executed=88
PASS crt_initterm_call stop=0x011e0f6f executed=97
PASS crt_initterm_executed stop=0x011e0f85 executed=102
PASS crt_startup_state_initializing stop=0x011e0f98 executed=107
PASS crt_cpp_walk stop=0x011e0f98 executed=107 initializers=5
```

O limite verificado do prefixo continua `0x011e0f98`: o que avançou foi o que
roda **depois** dele. `_initterm` percorre a tabela real, chama cinco corpos
reais e para no sexto endereço, que ainda não tem corpo traduzido.

## 2. O que o walk executou

Ordem da tabela, com as chamadas de import registradas (26 no total; 7 são do
prefixo do CRT, 19 pertencem aos inicializadores):

| # | inicializador | instruções | imports observados |
| --- | --- | --- | --- |
| 0 | `0x011e0e95` (`pre_cpp_init`) | 18 | `_decode_pointer`, `_onexit`, `__getmainargs` |
| 1 | `0x013000d0` | 6 | `_decode_pointer`, `_onexit`, `InitializeCriticalSection(0x01667c00)` |
| 2 | `0x013000f0` | 5 | `TlsAlloc` → 0 |
| 3 | `0x013b64c0` | 6 | `_decode_pointer`, `_onexit`, `InitializeCriticalSection(0x016f4e98)` |
| 4 | `0x013b64e0` | 5 | `TlsAlloc` → 1 |

Paragem: `0x013002d0` (sexto endereço não nulo). O shim de `_initterm` falha
fechado e nomeia o endereço:

```
error=_initterm needs a lifted body for 0x013002d0
walk=stopped_at_0x013002d0
```

`0x013002d0` exige o corpo `0x00935b70`, que é código de engine (guarda de
instância única, com USER32), portanto o lote 2 sai do escopo da CRT e precisa
de decisão própria.

## 3. Endereços resolvidos nesta etapa

| endereço | evidência |
| --- | --- |
| `0x013cc344` = `MSVCR90.dll!_decode_pointer` | valor do slot na PE = RVA `0x0110aedc` → registro `hint/name` "_decode_pointer" em `.rdata`; confere com a tabela de imports |
| `0x013cc348` = `MSVCR90.dll!_onexit` | idem, hint/name "_onexit" |
| `0x013cc34c` = `MSVCR90.dll!_lock` | idem |
| `0x013cc350` = `MSVCR90.dll!_encode_pointer` | idem |
| `0x013cc354` = `MSVCR90.dll!__dllonexit` | idem |
| `0x013cc358` = `MSVCR90.dll!_unlock` | idem |
| `0x01667c00` | seção de uma `CRITICAL_SECTION` do inicializador 1; em `.data` além dos dados crus, logo zerada pelo loader |
| `0x016f4e98` | seção de uma `CRITICAL_SECTION` do inicializador 3; mesma classificação |
| `0x0154df38`, `0x015d0690` | variáveis de `.data` que os inicializadores 2 e 4 alternam |

## 4. Correção estrutural: fixup da IAT como o loader faz

O código de `0x011e074a` (dentro da closure de `pre_cpp_init`) não chama pela
IAT, ele **lê** o slot e chama pelo registrador:

```
0x011e075c  mov esi, dword ptr [0x013cc344]
0x011e0762  call esi
```

Na PE, o slot contém o RVA do registro `hint/name`
(`0x0110aedc` → "_decode_pointer"), que não é código executável. Quem troca
esse valor pelo endereço resolvido é o **loader do Windows**, antes da primeira
instrução. Como o modelo não tinha esse passo, a chamada indireta caía num
endereço inválido.

Implementação: `install_import_trampolines` grava, em cada slot mapeado, o
endereço de um trampolim guest (`0x5f000000 + 0x10 * i`) e registra o símbolo
correspondente. `invoke_guest_call` reconhece o trampolim e despacha o import
com a convenção de chamada do símbolo. São 23 slots; `_adjust_fdiv`
(`0x013cc310`) fica de fora porque é um import de **dado**: o loader grava o
endereço da variável, não de código, e não há valor verificado para ela.

A janela `import_cells` do image passou a ser gravável, como as páginas de IAT
do Windows são.

## 5. Instruções e shims novos

- `_decode_pointer`: inverso exato de `_encode_pointer`
  (`rotr(p, cookie & 0x1f) ^ cookie`, nulo continua nulo). Ida e volta
  verificadas no walk: `_encode_pointer(0xffffffff)` → `0x2b8d56c0`,
  `_decode_pointer(0x2b8d56c0)` → `0xffffffff`.
- `install_import_trampolines` + tabela `kGuestImportSlots` (23 pares
  slot/símbolo) emitida pelo gerador a partir da tabela de imports da PE.
- `BatchLiftMemory` passou de 16 para 32 regiões (o image agora tem 14 janelas
  mais pilha, TEB e tabela de sonda).
- `_initterm` verifica legibilidade **por slot** em vez de exigir que os 124 KiB
  da tabela estejam mapeados; a mensagem de falha nomeia o slot.
- `__getmainargs` corrigido para `__cdecl`: o código guest faz `add esp,0x14`
  logo depois da chamada, e o shim estava retirando os argumentos outra vez
  (a pilha andava 20 bytes além e o `ret` seguinte estourava em `0x77777777`).

## 6. Janelas de memória novas no image guest

O image tem agora 14 regiões, 2 476 bytes:

| janela | tamanho | origem |
| --- | --- | --- |
| `pe_headers` | 0x400 | PE |
| `adjust_fdiv_cell` | 0x4 | PE |
| `import_cells` | 0x60 | PE, gravável |
| `cpp_initializer_head` | 0x400 | PE (256 primeiros slots da tabela) |
| `initializer_table` | 0x20 | PE (`_initterm_e`) |
| `security_cookie` | 0x18 | PE |
| `fmode_commode` | 0x8 | PE |
| `argv_envp` | 0x40 | PE |
| `initializer_flag` | 0x4 | PE (`0x0154df38`) |
| `initializer_state` | 0x4 | PE (`0x015d0690`) |
| `initializer_critical_section` | 0x18 | BSS (`0x01667c00`) |
| `initializer_critical_section_2` | 0x18 | BSS (`0x016f4e98`) |
| `crt_globals` | 0x60 | BSS |
| `startup_state` | 0x30 | BSS |

O gerador agora separa duas classes de endereço absoluto: acesso de memória
(`load`/`store`, precisa de janela, senão erro) e imediato empilhado (`push`,
que é argumento e só o chamado decide se desreferencia). Ambos vão para o
`manifest.json`, então a lacuna fica visível.

## 7. Limitações registradas

- `_encode_pointer` / `_decode_pointer` são **modelados** (par XOR + rotação
  auto-consistente); a semântica exata da MSVCR90 não foi verificada byte a
  byte. O que está verificado é a ida e volta dentro do guest e o
  `encoded_null` do CRT.
- `_onexit`, `__dllonexit`, `_lock`, `_unlock` aceitam o registro e devolvem o
  argumento; não existe tabela de exit real no guest.
- `_adjust_fdiv` mantém os bytes do arquivo no slot (import de dado sem valor
  verificado). Ele só alimenta `0x0171e748`, que o walk não chama.
- A tabela do `_initterm` está mapeada apenas nos 256 primeiros slots. Um lote
  que ultrapasse esse ponto falha com
  `_initterm table slot 0x... is outside mapped guest memory`.
- `x86 original` não roda nesse estágio: o walk real inicializa o processo e o
  host não sobrevive a ele. A comparação é lift x86 ↔ ARM64 no aparelho.
- Nada aqui é boot, menu, renderização ou gameplay.

## 8. Arquivos

Modificados:

- `tools/batch_static_lift/BatchStaticLiftRuntime.hpp`
- `tools/batch_static_lift/boot_entry_crt_harness.cpp`
- `tools/batch_static_lift/generate_initterm_guest_image.py`
- `tools/batch_static_lift/test_static_batch_lift.py`
- `tools/run_boot_crt_entry_tests.ps1`
- `README.md`

Gerados (em `test-logs/boot-entry-20261108/`):

- `generated-cpp-batch-1/` (11 corpos, 139 instruções, `batch_entries.hpp`)
- `generated-initterm-guest-image/` (14 janelas, 2 476 bytes, slots de import)
- `generated-crt-cpp-walk-initializers/`
- `crt-cpp-walk-initializers-*.log`, `run-cpp-walk-full.log`

## 9. Próximo bloqueio

`0x013002d0` → corpo `0x00935b70` (guarda de instância única; usa
`CreateMutexA`, `WaitForSingleObject`, `wsprintfA`, `_strtoui64`, `sprintf` e
superfície de USER32). É o primeiro código de **engine** na cadeia: exige
decisão explícita antes de traduzir, e não foi iniciado.
