# Closure de inicialização do CRT: traduzida e compilada

Data: 2026-11-08
PE de referência: `C:\SporeAnalysis\SporeApp.exe`
SHA-256: `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
`HEAD`: `1e3c23714afe3402537da4a117b35aadef49f8c1`.

## 1. Resultado

`_initterm_e(0x013eb09c, 0x013eb0ac)` executa três inicializadores. A closure
completa deles foi levantada, traduzida e **compilada** para x86 e ARM64. Não
foi executada: faltam os shims dos 10 imports.

```
PASS closure_build routines=10 instructions=193 imports=10
     x86_objects=10 arm64_objects=10
```

O prefixo do CRT permanece no limite anterior (`0x011e0f6f`) porque a execução
de `_initterm_e` é exatamente o que ainda falta.

## 2. Grafo da closure

Andado por chamadas diretas a partir da tabela, parando em thunks de import:

| Função | Instr. | Bytes | Papel |
| --- | --- | --- | --- |
| `0x011e10bf` | 58 | 225 | `__cinit`-like |
| `0x011e136e` | 18 | 38 | laço `_initterm` com tabela vazia |
| `0x011e1545` | 2 | 3 | `XOR EAX,EAX; RET` |
| `0x011e151a` | 19 | 43 | `_controlfp_s` + `_invoke_watson` |
| `0x011e1304` | 4 | 13 | grava `__get_sse2_info()` em `0x0171e754` |
| `0x011e12a2` | 45 | 98 | `__get_sse2_info` (bit ID + `CPUID`) |
| `0x011e1252` | 11 | 45 | sonda SSE2 sob `__SEH_prolog4` |
| `0x011e1219` | 11 | 20 | `__SEH_epilog4` |
| `0x011e11d4` | 21 | 72 | `__SEH_prolog4` (já usada pelo prefixo) |
| `0x011e135a` | 4 | 14 | `SetUnhandledExceptionFilter(0x011e1318)` |

`0x011e1318` (filtro de exceção, 22 instruções) **não** entra: ele só é passado
como argumento, nunca chamado no caminho. Fica registrado como conhecido e não
compilado.

Thunks reconhecidos como import (não liftados):

| Thunk | IAT | Símbolo |
| --- | --- | --- |
| `0x011e1312` | `0x013cc340` | `MSVCR90.dll!?terminate@@YAXXZ` |
| `0x011e16f6` | `0x013cc2f0` | `MSVCR90.dll!_controlfp_s` |
| `0x011e16f0` | `0x013cc2f4` | `MSVCR90.dll!_invoke_watson` |

Verificação por thunk: 6 bytes são `FF 25 <iat>` e a IAT resolve o símbolo. Os
dois `CALL` (em `0x011e152a` e `0x011e153b`) foram reescritos como import calls.

## 3. Capacidades novas

`MOVAPD xmm,xmm` — cópia de 16 bytes entre registradores SIMD
(`batch_guest_movapd`). Só a forma registro-registro; a closure não usa memória.

`PUSHFD`/`POPFD` — EFLAGS na pilha guest (`batch_guest_pushfd/popfd`), com bit
21 (ID) preservado, necessário para o teste de disponibilidade de `CPUID`.

`CPUID` — modelo **de guest**, documentado e determinístico:

| Folha | Saída |
| --- | --- |
| 0 | `EAX = 1` (folha básica máxima), vendor `GenuineIntel` |
| 1 | `EAX = 0x00000600`, `EBX = 0`, `ECX = 0`, `EDX = 0x04000000` (SSE2) |
| outra | `unsupported_dependency` (falha fechada) |

Nenhum bit de feature vem do host: x86, ARM64 e qualquer máquina respondem
idêntico. SSE2 é declarado presente porque o alvo (NEON) e o resto do lift já
assumem esse caminho — e a sonda `0x011e1252` traduz de verdade (`MOVAPD` +
frame SEH completo).

`CALL r32` — antes bloqueio duro. Agora o dispatcher expõe
`invoke_guest_call(memory, state, target, return_address)`, resolvido contra os
corpos registrados por `register_guest_function`; alvo sem corpo devolve
`unsupported_dependency` com o endereço no diagnóstico. `CALL [mem]` continua
bloqueado, e há teste para isso.

## 4. Bugs encontrados no caminho

1. `require` (helper local de `translate_instruction`) não existia no ponto onde
   os blocos novos foram escritos — usaram `operands_text` direto.
2. `goto` saltando declaração inline é rejeitado pelo clang/MSVC em modo estrito;
   o status do `CPUID` passou a ser declarado no topo, como o dos `CALL`.
3. `translate_function` levantava exceção ao coletar alvos de chamada quando havia
   `CALL r32`; agora chamadas indiretas ficam de fora da declaração de símbolos.
4. O teste antigo `test_indirect_call_is_reported_as_a_blocker` afirmava o
   bloqueio que deixou de existir; substituído por um teste do novo caminho, com
   outro teste cobrindo `CALL [mem]` ainda bloqueado.

## 5. Testes

| Teste | Resultado | Log |
| --- | --- | --- |
| Python (84) | OK | `closure-python-tests.log` |
| Build da closure x86 + ARM64 | PASS | `initterm-closure-x86-build.log`, `initterm-closure-arm64-build.log` |
| 5 estágios do prefixo no aparelho | PASS | `crt-*-arm64.log` |
| Regressão cookie/pid | PASS | `closure-cookie-regression.log` |
| Regressão do construtor `0x00a33817` | PASS no aparelho | `closure-constructor-regression.log` |

## 6. Próximo bloqueio: execução

Faltam 10 shims, todos com semântica de guest (nada de retorno fixo):

| Import | Args | Semântica necessária |
| --- | --- | --- |
| `MSVCR90.dll!__set_app_type` | 1 | guarda o tipo de aplicação em estado guest |
| `MSVCR90.dll!__p__fmode` | 0 | devolve ponteiro para inteiro na memória guest |
| `MSVCR90.dll!__p__commode` | 0 | idem |
| `MSVCR90.dll!_adjust_fdiv` | 0 | no-op documentado (resultado observável: nenhum) |
| `MSVCR90.dll!__setusermatherr` | 1 | guarda o ponteiro do handler |
| `MSVCR90.dll!_configthreadlocale` | 1 | devolve a configuração anterior (guest) |
| `MSVCR90.dll!_encode_pointer` | 1 | aplica o cookie em `0x015cfe70` |
| `KERNEL32.dll!SetUnhandledExceptionFilter` | 1 | guarda o ponteiro e devolve o anterior (`NULL` no guest) |
| `MSVCR90.dll!_controlfp_s` | 3 | precisa de modelo de control word x87 |
| `MSVCR90.dll!_invoke_watson` | 5 | fatal: falha fechada |

Depois disso: montar o harness do estágio `initterm-executed` com os três
inicializadores registrados e comparar lift x86 contra lift ARM64 — a
`_initterm_e` real não pode ser referência diferencial porque executa
inicialização de processo de verdade dentro do harness (já registrado na nota
anterior).

## 7. Arquivos

- `tools/batch_static_lift/generate_initterm_closure.py` — novo: anda a closure,
  valida bytes nos dois PEs, valida thunks e emite os `spore_*.cpp`.
- `tools/run_initterm_closure_build.ps1` — novo: gera e compila para x86 e ARM64.
- `tools/batch_static_lift/BatchStaticLiftRuntime.hpp` — `MOVAPD`, `PUSHFD`,
  `POPFD`, `CPUID` (modelo de guest), `invoke_guest_call`.
- `tools/batch_static_lift/BatchStaticLift.py` — cinco instruções novas, `CALL
  r32`, declaração do status de `CPUID`, coleta de alvos tolerante a chamada
  indireta.
- `tools/batch_static_lift/test_static_batch_lift.py` — testes das instruções
  novas e do `CALL [mem]` ainda bloqueado (82 → 84).
- `README.md` — seção da closure traduzida.

Nenhum commit ou push foi feito.
