# Thunks recuperados, `_initterm_e` identificado e limite em `0x011e0f6f`

Data: 2026-11-08
PE de referência: `C:\SporeAnalysis\SporeApp.exe`
SHA-256: `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
`HEAD`: `1e3c23714afe3402537da4a117b35aadef49f8c1`.

## 1. Resultado

| Item | Fato |
| --- | --- |
| `0x011e1368` | `ff253cc33c01` — thunk de `MSVCR90.dll!_amsg_exit` (IAT `0x013cc33c`) |
| `0x011e1514` | `ff251cc33c01` — thunk de `MSVCR90.dll!_initterm_e` (IAT `0x013cc31c`) |
| Bloqueio de tradução | removido: o `CALL 0x011e1368` do bloco não tomado virou import call |
| Novo limite | `0x011e0f6f` (`CALL _initterm_e`), executado até ele |

```
PASS crt_initterm_call stop=0x011e0f6f executed=97 esp_delta=-132 ebp=entry-4
     ebx=0 esi=1 edi=lock_reg cookie=consistent imports=7 icc=acquired
     owner=stack_base lock=owner state=1 try_level=1
     table=0x13eb09c..0x13eb0ac startupinfo=cb,ptrs_valid,reserved_null
```

Idêntico em x86 original (Win32 real), lift x86 e lift ARM64 no aparelho
`PJMZAEJRX4YLFIDI`.

## 2. Como os corpos foram recuperados

O batch `spore_batch_all_0086.json` não continha os dois alvos. A exportação
foi refeita no projeto Ghidra já analisado (`C:\SporeAnalysis\SporeREA4G`,
programa `SporeApp.exe`) com um script novo,
`tools/ghidra_scripts/ExportSporeFunctionByAddress.java`, que emite o mesmo
schema do `ExportSporeFunctionBatch.java` para endereços explícitos.

Resultado: ambos são `JMP [IAT]` de 6 bytes. Não existe corpo a liftar; o que
importa é a identidade do import. O lifter já suportava
`direct_import_aliases`, e o gerador agora valida a cadeia completa antes de
emitir:

1. o `CALL` no CRT ainda aponta para o thunk;
2. os 6 bytes do thunk são `FF 25 <iat>`;
3. a IAT resolve para o símbolo esperado.

Qualquer divergência aborta a geração.

**Terceiro achado.** `0x011e10bf`, `0x011e1304` e `0x011e135a` (os
inicializadores da tabela) não existiam no Ghidra: sem função e sem instrução.
Foram decodificados com `tools/ghidra_scripts/DisassembleSporeRoutines.java`,
que faz descida recursiva a partir da entrada (segue `CALL` no fallthrough e
`JMP`/`Jcc` nos alvos) em um projeto temporário `-noanalysis`:

| Entrada | Instruções | Bytes cobertos |
| --- | --- | --- |
| `0x011e10bf` | 58 | 225 |
| `0x011e1304` | 4 | 13 |
| `0x011e135a` | 4 | 14 |

Evidência: `test-logs/boot-entry-20261108/crt_init_routines.json`.

## 3. Tabela de inicializadores (verificada no PE)

`_initterm_e(begin=0x013eb09c, end=0x013eb0ac)` — 4 slots, fim exclusivo:

| Slot | Valor |
| --- | --- |
| `0x013eb09c` | `0` (ignorado) |
| `0x013eb0a0` | `0x011e10bf` |
| `0x013eb0a4` | `0x011e1304` |
| `0x013eb0a8` | `0x011e135a` |

O harness confere os dois valores empilhados em `0x011e0f65`/`0x011e0f6a`
contra as constantes emitidas pelo gerador (`kInittermTable`,
`kInittermTableEnd`), nos dois lados.

## 4. Shims novos

`_initterm_e` (`BatchStaticLiftRuntime.hpp::initterm_e`):

- valida `end >= begin`, alinhamento de 4 e legibilidade dos limites na memória
  guest;
- pula slots nulos, invoca cada alvo por `batch_guest_call32` com o retorno
  sentinela `kBatchGuestInitializerReturn`, confere que o `ESP` voltou ao valor
  de entrada e que o `EIP` é o sentinela;
- agrega o resultado e para no primeiro inicializador que retorna diferente de
  zero, como a implementação da MSVCR90;
- alvo sem corpo registrado → `unsupported_dependency` com o endereço no
  diagnóstico (falha fechada).

`_amsg_exit`: fatal por definição (a rotina real imprime a mensagem e termina o
processo). O guest não tem processo para encerrar, então retorna
`unsupported_dependency` com o tipo de erro. Nunca executa neste prefixo.

Os inicializadores são registrados por
`BatchGuestRuntime::register_guest_function(address, fnptr)`. A assinatura é
ponteiro de função, não `std::function`: `std::function` arrastou
`_ZTVNSt6__ndk117bad_function_callE` e quebrou o vínculo do binário ARM64 no
aparelho (o `libc++` não existe lá). Foi detectado na primeira execução ADB e
corrigido antes de qualquer resultado ser considerado válido.

Probes no harness (rodam em x86 e ARM64, sem alterar a linha `PASS`):

- tabela `{0, 0x011e10bf, 0x011e1304}` com os dois inicializadores registrados
  → ordem 1, 2, resultado agregado `7`, `ESP` restaurado;
- slot 1 apontando para `0x011e135a` sem corpo → `unsupported_dependency`,
  diagnóstico com `011e135a`, `ESP`/`EIP` intactos.

## 5. Correção de contagem

`startup-lock` reportava `executed=97`, somando os 9 registros do bloco
`_amsg_exit` que está emitido mas não é tomado. A contagem correta é 13
instruções de prefixo → `executed=88`. A linha `PASS` do estágio mudou e foi
revalidada nos três lados.

## 6. Testes

| Teste | Resultado | Log |
| --- | --- | --- |
| Python (82 testes) | OK | `initterm-python-tests.log` |
| 5 estágios x86 original vs lift | PASS | `crt-*-differential.log` |
| 5 estágios ARM64 no aparelho | PASS | `crt-*-arm64.log` |
| Stress `interlocked-call`, `startup-lock`, `initterm-call` | 20/20 cada | `crt-*-arm64-stress.log` |
| Regressão cookie/pid (5 estágios) | PASS | `initterm-cookie-regression.log` |
| Regressão do construtor `0x00a33817` | PASS no aparelho | `initterm-constructor-regression.log` |

O aparelho caiu durante a sessão (`adb devices` vazio); voltou após
`adb kill-server`/`start-server` e todos os estágios rodaram. O período sem
aparelho está registrado e nenhuma validação ARM64 foi declarada nele.

## 7. Próximo bloqueio

Executar `_initterm_e` exige, como corpo liftado:

- `0x011e10bf` (58 instruções) e seus imports `MSVCR90.dll!__set_app_type`,
  `_encode_pointer`, `__p__fmode`, `__p__commode`, `_adjust_fdiv`,
  `__setusermatherr`, `_configthreadlocale`;
- `0x011e10bf → 0x011e136e`, `0x011e1545`, `0x011e151a`;
- `0x011e1304 → 0x011e12a2`;
- `0x011e135a → SetUnhandledExceptionFilter` + `0x011e1318`.

Além do volume, há um limite de método: a `_initterm_e` real executa
inicialização de processo de verdade dentro do harness x86 (chama
`__set_app_type`, instala filtro de exceção, ajusta `_fmode`/`_commode`). Ela
não pode ser usada como referência diferencial; a próxima etapa precisa
comparar lift-versus-lift com inicializadores registrados e declarar isso de
forma explícita, em vez de fingir paridade com o código original.

## 8. Arquivos modificados

- `tools/batch_static_lift/BatchStaticLiftRuntime.hpp` — shims `_initterm_e` e
  `_amsg_exit`, registro de funções guest (ponteiro), `hex32`,
  `kBatchGuestInitializerReturn`, contagens de argumento.
- `tools/batch_static_lift/BatchStaticLift.py` — `static_source` aceita
  `exit_targets` e rotula saídas de prefixo.
- `tools/batch_static_lift/generate_boot_crt_prefix.py` — estágio
  `initterm-call`, aliases de thunk validados, validação da tabela de
  inicializadores, constantes e manifesto.
- `tools/batch_static_lift/boot_entry_crt_harness.cpp` — estágio novo, TEB,
  bloco de lock, probes do shim.
- `tools/batch_static_lift/boot_entry_crt_original_x86.cpp` — realocação das
  duas leituras de `__native_startup_state`, estágio novo, relator de falhas
  opcional (`SPORE_HARNESS_DIAGNOSTICS`).
- `tools/run_boot_crt_entry_tests.ps1` — cinco estágios por padrão.
- `tools/batch_static_lift/test_static_batch_lift.py` — estágios, aliases,
  tabela, `exit_targets` (80 → 82 testes).
- `tools/ghidra_scripts/` — exportação por endereço, descrição de endereços e
  disassembly recursivo.
- `README.md` — seção do bloqueio de tradução removido.

Nenhum commit ou push foi feito.
