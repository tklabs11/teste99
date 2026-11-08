# Estado `__initializing` e a tabela de inicializadores C++

Data: 2026-11-08
PE de referência: `C:\SporeAnalysis\SporeApp.exe`
SHA-256: `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
`HEAD`: `1e3c23714afe3402537da4a117b35aadef49f8c1`, sem commit nem push meus.

## 1. Resultado

O prefixo atravessou o estado de inicialização do CRT e parou no `CALL` que
inicia a tabela de inicializadores C++. Limite novo: **`0x011e0f98`**.

```
PASS crt_startup_state_initializing stop=0x011e0f98 executed=107
     esp_delta=-132 ebp=entry-4 eax=1 esi=1 edi=lock_reg
     cookie=consistent imports=14 initterm_e=walked state=initializing
     cmp=equal table=0x013cc80c..0x013eb098 app_type=2 fpucw=0x0001027f
DETAIL ... walk_called=0x011e0e95 walk_missing=0x013000d0
```

O mesmo snapshot sai idêntico no lift x86 e no ARM64 do aparelho
`PJMZAEJRX4YLFIDI`.

## 2. Instruções que a extensão executou

| Endereço | Instrução | Efeito |
| --- | --- | --- |
| `0x011e0f85` | `MOV EAX,[0x0171e74c]` | `EAX = 1` (`__initializing`) |
| `0x011e0f8a` | `CMP EAX,ESI` | `ESI = 1`, então `ZF = 1` |
| `0x011e0f8c` | `JNZ 0x011e0fa9` | **não** tomado |
| `0x011e0f8e` | `PUSH 0x013eb098` | fim da tabela C++ |
| `0x011e0f93` | `PUSH 0x013cc80c` | início da tabela C++ |
| `0x011e0f98` | `CALL 0x011e150e` | **limite**: `JMP [0x013cc320]` = `MSVCR90.dll!_initterm` |

`ESP = entry-0x84` (as duas `PUSH` ainda pendentes), `EBP = entry-4`,
`[EBP-4] = 1` (try level), estado nativo ainda em `1` (a escrita de `2` está em
`0x011e0f9f`, depois do limite).

## 3. O bloqueio medido

`_initterm(begin=0x013cc80c, end=0x013eb098)` percorre a tabela de
inicializadores estáticos do jogo:

| Medida | Valor |
| --- | --- |
| Faixa | `0x013cc80c..0x013eb098` (`.rdata`, 125.068 bytes) |
| Slots | 31.267 |
| Slots nulos | 1 (o primeiro) |
| Alvos não nulos | **31.266** |
| Alvos distintos | 31.266 (nenhum repetido) |
| Faixa dos alvos | `0x011e0e95 .. 0x013bc960`, todos em `.text` |
| Já traduzidos (batch de 86 + closure) | **0** |

O `_initterm` foi implementado como shim (percorre a tabela, ignora nulos, chama
cada endereço por `invoke_guest_call` e **falha fechado** nomeando o endereço
sem corpo). O probe do estágio usa as duas primeiras entradas reais da tabela:

- chama `0x011e0e95` (registrado só no probe, como stub de contrato);
- recusa `0x013000d0` e reporta exatamente esse endereço.

Ou seja: o próximo corpo necessário é `0x011e0e95`, e depois dele existem mais
31.265 inicializadores, todos distintos e nenhum já traduzido. Essa é a
dimensão real do próximo passo — não é uma dependência isolada.

## 4. Capacidade nova

`_initterm` (import real de MSVCR90, thunk `0x011e150e` → `ff 25 20 c3 3c 01`,
IAT `0x013cc320`) ganhou shim próprio:

- valida `end >= begin`, múltiplo de 4 e legível;
- ignora entradas nulas;
- chama cada inicializador com endereço de retorno sintético
  (`0xfffff000`) e exige que `EIP` e `ESP` voltem exatamente;
- endereço sem corpo → `unsupported_dependency` com o endereço no diagnóstico;
- `__cdecl`: não popa os 8 bytes de argumentos (o guest faz `POP ECX` duas
  vezes em `0x011e0f9d`/`0x011e0f9e`).

O gerador também valida a forma da tabela a cada execução: todos os alvos
precisam estar dentro de `.text`, sem repetição, e o PE candidato precisa
concordar com o de referência.

## 5. Testes

```
PASS crt_startup_state_initializing ... (este estágio, x86 e ARM64)
PASS crt_entry stop=0x011e0ee7 executed=56
PASS crt_startupinfo stop=0x011e0efe executed=84
PASS crt_interlocked stop=0x011e0f24 executed=93
PASS crt_startup_lock stop=0x011e0f43 executed=88
PASS crt_initterm_call stop=0x011e0f6f executed=97
PASS crt_initterm_executed stop=0x011e0f85 executed=102
PASS closure_build routines=10 instructions=193 imports=10
PASS 81 testes Python
PASS pid_prefix + cookie_complete (aparelho)
PASS construtor 0x00a33817 (x86 original vs lift x86 vs ARM64)
```

Os dois últimos estágios não comparam contra os bytes originais do PE: o
`_initterm_e`/`_initterm` reais inicializam o processo hospedeiro. Eles comparam
lift x86 contra lift ARM64 e o runner registra a exceção.

## 6. Limite e próximo bloqueio

Novo limite verificado: **`0x011e0f98`**, 107 instruções executadas.

Bloqueio declarado: a closure de inicializadores estáticos tem **31.266
funções** (`0x011e0e95` é a primeira, `0x013bc960` a última). Executar o boot a
partir daqui exige traduzir e validar essa closure inteira, ou provar que parte
dela nunca é necessária — nenhuma das duas coisas foi feita.

Continua **sem** boot, janela, menu ou renderização: o APK não chama a entrada
do PE. Marco 8 (`0x00a23817 -> FUN_00a221b0`) segue apenas engatilhado.
