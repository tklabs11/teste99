# Lock de inicialização do CRT: `InterlockedCompareExchange` e o caminho do `JZ`

Data: 2026-11-08
PE de referência: `C:\SporeAnalysis\SporeApp.exe`
SHA-256: `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
Variante Steam (`SPOREFILES\SporeBin\SporeApp.exe`): mesmo SHA-256.
`HEAD`: `1e3c23714afe3402537da4a117b35aadef49f8c1`.

## 1. Resultado

Dois estágios novos, ambos com `__SEH_prolog4` e `GetStartupInfoA` já dentro:

| Estágio | Limite | Prefixo emitido | Executado |
| --- | --- | --- | --- |
| `interlocked-call` | `0x011e0f24` | 18 registros | 18 |
| `startup-lock` | `0x011e0f43` | 31 registros | 22 |

```
PASS crt_interlocked stop=0x011e0f24 executed=93 esp_delta=-124 ebp=entry-4
     ebx=0 edi=lock_reg cookie=consistent imports=7 icc=acquired previous=0
     owner=stack_base lock=owner try_level=1
     startupinfo=cb,ptrs_valid,reserved_null

PASS crt_startup_lock stop=0x011e0f43 executed=97 esp_delta=-124 ebp=entry-4
     ebx=0 esi=1 edi=lock_reg cookie=consistent imports=7 icc=acquired
     owner=stack_base lock=owner state=0 try_level=1
     startupinfo=cb,ptrs_valid,reserved_null
```

Idêntico em x86 original com APIs reais do Windows, lift x86 e lift ARM64 no
aparelho `PJMZAEJRX4YLFIDI`.

## 2. Instruções executadas (bytes conferidos nos dois PEs)

| Endereço | Bytes | Instrução | Papel |
| --- | --- | --- | --- |
| `0x011e0efe` | `c745fcfeffffff` | `MOV [EBP-0x4],0xfffffffe` | sai do estado do `__try` |
| `0x011e0f05` | `c745fc01000000` | `MOV [EBP-0x4],1` | try level 1 |
| `0x011e0f0c` | `64a118000000` | `MOV EAX,FS:[0x18]` | TEB (`PEB` fica em `TEB+0x30`) |
| `0x011e0f12` | `8b7004` | `MOV ESI,[EAX+0x4]` | `TEB->StackBase` |
| `0x011e0f15` | `bf50e77101` | `MOV EDI,0x171e750` | `&__native_startup_lock` |
| `0x011e0f1a` | `6a00` | `PUSH 0` | comparand |
| `0x011e0f1c` | `56` | `PUSH ESI` | exchange = dono |
| `0x011e0f1d` | `57` | `PUSH EDI` | destination |
| `0x011e0f1e` | `ff1594c13c01` | `CALL [0x013cc194]` | `InterlockedCompareExchange` |
| `0x011e0f24` | `85c0` | `TEST EAX,EAX` | limite do primeiro estágio |
| `0x011e0f26` | `7418` | `JZ 0x011e0f40` | tomado |
| `0x011e0f40` | `33f6` | `XOR ESI,ESI` | |
| `0x011e0f42` | `46` | `INC ESI` | `ESI = 1` |
| `0x011e0f43` | `a14ce77101` | `MOV EAX,[0x0171e74c]` | limite do segundo estágio |

A IAT de referência resolve `0x013cc194` como
`KERNEL32.dll!InterlockedCompareExchange`, confirmado pelo parser de imports e
revalidado pelo gerador antes de emitir qualquer estágio que passe por ele.

## 3. Modelo de estado do guest

### TEB
`FS:[0x18]` é o TEB; `[TEB+4]` é o `StackBase`, usado como identidade do dono do
lock. O guest passou a ter um TEB mínimo em `0x7ffdf000` (0x40 bytes):

| Offset | Valor | Papel |
| --- | --- | --- |
| `+0x00` | `0xffffffff` | fim da cadeia SEH |
| `+0x04` | `0x70000400` | `StackBase` = topo da pilha mapeada do guest |
| `+0x18` | `0x7ffdf000` | auto-referência que `FS:[0x18]` deve devolver |

Nada foi inventado: a indireção real é seguida de ponta a ponta, e o valor do
dono é derivado do espaço de endereços do próprio guest. No lado Windows o
`StackBase` real da thread é lido em `fs:[0x18]` + `+4` e comparado com o valor
que o código instalou no lock.

### Globais do lock
`0x0171e74c` (`__native_startup_state`) e `0x0171e750` (`__native_startup_lock`)
caem em `.data` **depois de `SizeOfRawData`** (`raw_end = 0x011d0c00`,
`vend = 0x0131e764`), ou seja, o loader preenche com zero. O gerador valida
essa condição com `region_is_bss` e se recusa a emitir o estágio se um build
futuro tiver conteúdo real ali. O harness mapeia `0x0171e740` + `0x20` zerado.

Diagnóstico que evitou um erro: `read_pe_bytes` cai num fallback que trata a RVA
como offset de arquivo quando o endereço está fora dos dados crus — ler essa
região "no PE" devolve conteúdo alheio, não o `.data` do loader. Por isso a
classificação passou a comparar `rva - image_base` contra as seções.

## 4. Shim de `InterlockedCompareExchange`

`BatchStaticLiftRuntime.hpp::interlocked_compare_exchange`:

- três argumentos `stdcall`: `destination`, `exchange`, `comparand` (12 bytes
  removidos no retorno);
- exige `is_writable(destination, 4)` antes de ler o valor anterior;
- compara, troca quando igual, devolve o valor anterior em `EAX`;
- o guest executa uma thread, então a atomicidade é estrutural e não há lock de
  host — declarado no comentário do handler;
- destino fora da memória guest → `invalid_memory`, sem consumir argumentos e
  sem mover `EIP` (probe negativo executado nos dois lados, junto com o probe de
  `GetStartupInfoA`).

## 5. Correções de harness que o avanço exigiu

1. **Ciclo de vida da pilha.** O snapshot do `STARTUPINFOA` já era feito logo
   após `execute_original()`, mas o try level e as palavras no topo da pilha
   eram lidos no fim da `main`, depois de chamadas que reutilizam aquela região
   — e voltaram lixo (`try=0x013b7788`, `words=0093fce7,0093fd0c`). Agora os
   três snapshots são copiados imediatamente após o retorno do código original.
2. **Seed de `cb` fora por 4 bytes.** O `mov dword ptr [esp-6Ch], 44h` escrevia
   no `lpReserved`, não no `cb`: o teste antigo passava porque o
   `GetStartupInfoA` real também grava `cb = 0x44`. Corrigido para `[esp-70h]`,
   que é `EBP - 0x68` de verdade.
3. **`goto` para o limite.** O bloco não tomado tem `JMP 0x011e0f43`, que é o
   limite do estágio: o código gerado referenciava um label inexistente. O
   emissor agora rotula o endereço terminal quando alguma instrução salta nele,
   o que mantém o status `unsupported_dependency` nesse caminho.
4. **Limpeza do runner.** `Remove-Item` do diretório de build falhava
   intermitentemente com "arquivo em uso" logo após executar o binário, e o erro
   do `finally` mascarava o resultado real. Agora há retry com espera.

## 6. Testes

| Teste | Resultado | Log |
| --- | --- | --- |
| Python (`test_static_batch_lift`, `test_m7_effective_address_differential`) | 80 OK | `startup-lock-python-tests.log` |
| x86 original vs lift, 4 estágios | PASS | `crt-*-differential.log` |
| ARM64 no aparelho, 4 estágios | PASS | `crt-*-arm64.log` |
| Stress ARM64 `interlocked-call` | 20/20 | `crt-interlocked-call-arm64-stress.log` |
| Stress ARM64 `startup-lock` | 20/20 | `crt-startup-lock-arm64-stress.log` |
| Regressão cookie/pid (5 estágios) | PASS | `startup-lock-cookie-regression.log` |
| Regressão do construtor (`0x00a33817`) | PASS no aparelho | `startup-lock-constructor-regression.log` |

## 7. Bloqueio seguinte

**Runtime:** o caminho tomado segue por `0x011e0f56`
`MOV EAX,[0x0171e74c]`, `0x011e0f5b TEST`, `0x011e0f5d JNZ 0x011e0f7f`,
`0x011e0f5f MOV [0x0171e74c],ESI`, dois `PUSH` e
`0x011e0f6f CALL 0x011e1514` — cujo corpo **não está recuperado**.

**Tradutor:** o bloco não tomado (`0x011e0f4c`–`0x011e0f54`) está dentro da
closure emitida e contém `0x011e0f4e CALL 0x011e1368` (`_amsg_exit`), também sem
corpo recuperado. É por isso que a fronteira para em `0x011e0f43`: não é falta
de suporte de runtime, é falta de corpo de função para compilar o bloco.

Menor próximo passo: exportar `0x011e1368` e `0x011e1514` do Ghidra com
validação de bytes nos dois PEs, como foi feito para `0x011e11d4`, e então
estender para `0x011e0f6f`.

## 8. Arquivos modificados

- `tools/batch_static_lift/BatchStaticLiftRuntime.hpp` — handler
  `InterlockedCompareExchange` e `import_argument_count == 3`.
- `tools/batch_static_lift/BatchStaticLift.py` — rótulo no endereço terminal
  quando há salto para ele.
- `tools/batch_static_lift/generate_boot_crt_prefix.py` — estágios
  `interlocked-call` e `startup-lock`, validação do `CALL` de ICC, validação
  `region_is_bss` das globais do lock, constantes e manifesto
  (`executed`, endereços do lock, região).
- `tools/batch_static_lift/boot_entry_crt_harness.cpp` — TEB de guest com
  `StackBase`, bloco `.data` zerado, checagens por estágio, probe negativo dos
  dois shims.
- `tools/batch_static_lift/boot_entry_crt_original_x86.cpp` — realocação dos
  três operandos absolutos do lock, thunk de ICC, snapshot imediato de
  `STARTUPINFOA`/try level/pilha, seed de `cb` corrigido.
- `tools/run_boot_crt_entry_tests.ps1` — quatro estágios por padrão, limpeza com
  retry.
- `tools/batch_static_lift/test_static_batch_lift.py` — estágios, constantes do
  lock, `region_is_bss` e rótulo terminal (77 → 80 testes).
- `README.md` — seção do lock de inicialização.

Nenhum commit ou push foi feito.
