# `_initterm_e` executado: inicializadores do CRT rodando no guest

Data: 2026-11-08
PE de referência: `C:\SporeAnalysis\SporeApp.exe`
SHA-256: `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
`HEAD`: `1e3c23714afe3402537da4a117b35aadef49f8c1`, sem commit nem push meus.

## 1. Resultado

O prefixo de boot agora atravessa o `CALL 0x011e1514` e executa o corpo real de
`_initterm_e` sobre a tabela `0x013eb09c..0x013eb0ac`. Os três inicializadores
rodam na memória guest, os 14 imports do caminho são atendidos por shims e o
limite avançou de `0x011e0f6f` para `0x011e0f85`.

```
PASS crt_initterm_executed stop=0x011e0f85 executed=102 esp_delta=-124
     ebp=entry-4 eax=0 esi=1 edi=lock_reg cookie=consistent imports=14
     initterm=walked initializers=3/3 app_type=2 fmode=0,0
     encoded_null=consistent adjust_fdiv=propagated sse2=1
     filter=0x011e1318 fpucw=0x0001027f
```

O mesmo snapshot sai idêntico no lift x86 e no ARM64 do aparelho
`PJMZAEJRX4YLFIDI`.

## 2. Ordem real dos imports (14 chamadas)

| # | Símbolo | Argumento verificado | Origem |
| --- | --- | --- | --- |
| 1-5 | `GetSystemTimeAsFileTime`, `GetCurrentProcessId`, `GetCurrentThreadId`, `GetTickCount`, `QueryPerformanceCounter` | — | `__security_init_cookie` |
| 6 | `KERNEL32.dll!GetStartupInfoA` | `STARTUPINFOA*` | `0x011e0ef8` |
| 7 | `KERNEL32.dll!InterlockedCompareExchange` | `&lock`, `StackBase`, `0` | `0x011e0f1e` |
| 8 | `MSVCR90.dll!_initterm_e` | `0x013eb09c`, `0x013eb0ac` | `0x011e0f6f` |
| 9 | `MSVCR90.dll!__set_app_type` | `2` (`_GUI_APP`) | `0x011e1125` |
| 10 | `MSVCR90.dll!_encode_pointer` | `0xffffffff` | `0x011e112d` |
| 11 | `MSVCR90.dll!__p__fmode` | — | `0x011e113f` |
| 12 | `MSVCR90.dll!__p__commode` | — | `0x011e114d` |
| 13 | `MSVCR90.dll!_controlfp_s` | `NULL`, `0x10000`, `0x30000` | `0x011e152a` |
| 14 | `KERNEL32.dll!SetUnhandledExceptionFilter` | `0x011e1318` | `0x011e135f` |

`__setusermatherr` e `_configthreadlocale` **não** são chamados: o código testa
`[0x015cfe84] == 0` e `[0x015cfe80] == -1` e o PE traz `1` e `0xfffffffe`.
`_invoke_watson` e `?terminate` existem como shim fatal, mas o caminho feliz não
passa por eles.

## 3. Efeitos observados na memória guest

| Endereço | Valor | Prova |
| --- | --- | --- |
| `0x016f2628` | `0` | sonda PE32 do `__cinit` (`SizeOfStackCommit > 0xe` e diretório CLR) |
| `0x015cff00` / `0x015cff04` | `0` / `0` | `*__p__fmode()` e `*__p__commode()` receberam `[0x016f264c]` e `[0x016f2648]`, ambos BSS |
| `0x0171e75c` / `0x0171e760` | iguais | `_encode_pointer(0xffffffff)` recalculado a partir do cookie do próprio run |
| `0x0171e748` | `0x0fc0841c` | lido duas vezes: `[0x013cc310]` → `0x0110af9c` → valor |
| `0x0171e754` | `1` | `__get_sse2_info` reportou SSE2 |
| `0x0171e74c` | `1` | estado de inicialização nativa do CRT |
| `0x0171e750` | `0x70000400` | dono do lock (`fs:[0x04]`, base da pilha guest) |

Estado de registradores no limite: `EAX = 0` (resultado de `_initterm_e`),
`ESI = 1`, `EDI = 0x0171e750`, `EBP = entry-4`, `ESP = entry-0x7c`.
O FPU control word ficou em `0x0001027f` (precisão de 53 bits pedida por
`__controlfp`).

## 4. Correções exigidas pela execução

1. **Convenção de chamada dos shims CRT.** Os imports de MSVCRT aqui são
   `__cdecl`: o código guest limpa a pilha (`POP ECX`, `POP ECX`,
   `ADD ESP,0xc`). Os shims estavam popando os argumentos e a pilha ficava 8 a
   12 bytes deslocada. Agora `_initterm_e`, `_amsg_exit`, `__set_app_type`,
   `_encode_pointer`, `__setusermatherr`, `_configthreadlocale`, `_controlfp_s`
   e `_invoke_watson` preservam os argumentos; só os WINAPI
   (`GetStartupInfoA`, `InterlockedCompareExchange`,
   `SetUnhandledExceptionFilter`) continuam popando.
2. **Mapa de registradores do `CPUID`.** O modelo escrevia EBX/ECX/EDX em
   `regs[1..3]`, mas `regs` segue a ordem ModRM (EAX=0, ECX=1, EDX=2, EBX=3).
   Com isso a folha 1 entregava `0x04000000` no registrador errado e
   `__get_sse2_info` devolvia 0. Corrigido; agora devolve 1 nos três lados.
3. **Tempo de vida dos buffers mapeados.** `map_region` guarda ponteiros; os
   buffers do cookie e do lock passaram a viver no escopo de `main`, senão a
   região apontava para pilha morta e o complemento do cookie saía corrompido.
4. **Modelo da sonda de app-type.** O gerador da imagem calculava o bit no
   diretório 12 por engano; o código lê `[optional+0xd0]` (diretório CLR). O
   valor esperado agora vem do PE e vale `0` para este build.

## 5. Suporte novo ao operando de memória

Nenhuma instrução x86 nova foi necessária. O que faltava era **memória guest
real**: o gerador `generate_initterm_guest_image.py` monta 8 janelas (1332
bytes) e falha se a closure tocar qualquer endereço não coberto.

| Janela | Bytes | Origem |
| --- | --- | --- |
| `0x00400000` | `0x400` | cabeçalhos DOS/NT do próprio PE |
| `0x0110af9c` | `4` | célula de `_adjust_fdiv` alcançada pela IAT |
| `0x013cc300` | `0x60` | células de import lidas como dado |
| `0x013eb090` | `0x20` | tabela percorrida por `_initterm_e` |
| `0x015cfe70` | `0x18` | cookie + guardas dos inicializadores (bytes do PE) |
| `0x015cff00` | `8` | `_fmode`/`_commode` do guest (zeros) |
| `0x016f2600` | `0x60` | globais do CRT em BSS (zeros) |
| `0x0171e740` | `0x30` | lock, estado e ponteiros nulos codificados (BSS) |

Cada janela é classificada contra a tabela de seções: ou vem bytes crus do PE
(comparados entre referência e candidato), ou o gerador prova que o loader
zeraria a faixa.

## 6. Testes

```
PASS crt_initterm_executed ... (este estágio, x86 e ARM64)
PASS crt_entry stop=0x011e0ee7 executed=56
PASS crt_startupinfo stop=0x011e0efe executed=84
PASS crt_interlocked stop=0x011e0f24 executed=93
PASS crt_startup_lock stop=0x011e0f43 executed=88
PASS crt_initterm_call stop=0x011e0f6f executed=97
PASS closure_build routines=10 instructions=193 imports=10
PASS 81 testes Python
PASS pid_prefix + cookie_complete (aparelho)
PASS construtor 0x00a33817 (x86 original vs lift x86 vs ARM64)
```

Os cinco estágios anteriores continuam comparando contra os **bytes originais
do PE executados no Windows x86**. O estágio novo não pode: o `_initterm_e`
real inicializa o processo hospedeiro. Por isso ele compara lift x86 contra
lift ARM64 e o runner registra a exceção explicitamente
(`SKIP original_x86_real_win32 ... reason=_initterm_e_runs_process_initialization`).

## 7. Limite e bloqueios

Novo limite verificado: **`0x011e0f85`** (`MOV EAX,[0x0171e74c]` após o `JZ`),
102 instruções executadas, pilha `entry-0x7c`.

Próximo trecho, já visível e não executado: `CMP EAX,ESI; JNZ 0x011e0fa9` e, no
caminho tomado, `PUSH 0x013eb098; PUSH 0x013cc80c; CALL 0x011e150e` (segundo
table walk) antes de `MOV [0x0171e74c],2` e das chamadas restantes de
`_initterm`/`SetUnhandledExceptionFilter`.

Continua **sem** boot, janela, menu ou renderização: o APK não chama a entrada
do PE. Marco 8 (`0x00a23817 -> FUN_00a221b0`) segue apenas engatilhado.
