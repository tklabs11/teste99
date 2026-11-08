# Lote 1 dos inicializadores C++: closure medida e primeiro bloqueio

Data: 2026-11-08
PE de referência: `C:\SporeAnalysis\SporeApp.exe`
SHA-256: `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
Estratégia aprovada: lotes de 256 em ordem de tabela, parando na primeira API
sem shim ou na primeira divergência.

## 1. O que o lote 1 é

| Item | Valor |
| --- | --- |
| Fatia da tabela | `0x011e0e95 .. 0x0121dcd0` (256 inicializadores) |
| Próxima entrada não incluída | `0x0121dcf0` |
| Tamanho típico | 4 a 18 instruções por inicializador |

## 2. A closure transitiva não converge

A caminhada por chamadas diretas foi feita com Ghidra, canonicalizando cada
alvo para a função que o contém (`ResolveSporeFunctionEntries`), porque o código
de engine compartilha blocos no meio de funções.

| Rodada | Corpos | Instruções | Novos alvos |
| --- | --- | --- | --- |
| 1 | 256 | — | 27 |
| 12 | 354 | 7.443 | 8 |
| 20 | ~600 | — | — |
| 40 | **1.810** | **137.585** | 46 |

Depois de 40 rodadas a caminhada ainda descobria 46 corpos novos por rodada, com
77 imports distintos e 2.441 alvos canonicalizados. Ou seja: alguns
inicializadores (por exemplo o guard de instância única `0x00935b70`) puxam
código de engine cuja closure alcança o binário inteiro.

**Conclusão:** agrupar por closure não dá um lote limitado. O modelo limitado é
por **inicializador**, na ordem da tabela, parando na primeira dependência não
atendida — que é exatamente a regra de parada combinada.

## 3. Requisitos dos primeiros 16 inicializadores (ordem da tabela)

| # | Inicializador | Instr. | Exige |
| --- | --- | --- | --- |
| 0 | `0x011e0e95` | 18 | `MSVCR90!__getmainargs`, corpo `0x011e07ef`, `_amsg_exit` |
| 1 | `0x013000d0` | 6 | `KERNEL32!InitializeCriticalSection`, corpo `0x011e07ef` |
| 2 | `0x013000f0` | 5 | `KERNEL32!TlsAlloc` |
| 3 | `0x013b64c0` | 6 | `KERNEL32!InitializeCriticalSection`, corpo `0x011e07ef` |
| 4 | `0x013b64e0` | 5 | `KERNEL32!TlsAlloc` |
| 5 | `0x013002d0` | 5 | corpo `0x00935b70` (guard de instância), `0x011e07ef` |
| 6 | `0x0138e640` | 11 | corpo `0x00f474d0`, `0x011e07ef` |
| 7 | `0x01300210` | 4 | corpo `0x011e07ef` |
| 8 | `0x01300310` | 16 | corpo `0x00939d40`, `0x011e07ef` |
| 9 | `0x01300120` | 8 | corpo `0x00935c80`, `0x011e07ef` |
| 10 | `0x01300150` | 8 | corpo `0x00935c80`, `0x011e07ef` |
| 11 | `0x01300180` | 8 | corpo `0x00935c80`, `0x011e07ef` |
| 12 | `0x013001b0` | 8 | corpo `0x009222a0`, `0x011e07ef` |
| 13 | `0x013001d0` | 11 | corpo `0x00925a30`, `0x011e07ef` |
| 14 | `0x0121a720` | 7 | **nada** |
| 15 | `0x0121a740` | 8 | **nada** |

O primeiro bloqueio é o inicializador **#0**, `0x011e0e95`: ele chama
`MSVCR90.dll!__getmainargs`. Pelo formato (18 instruções, imediatamente antes de
`___tmainCRTStartup`, chamando `__getmainargs` e guardando resultados em
`0x016f2630`/`0x016f2640`/`0x016f2644`), essa entrada é o `pre_cpp_init` do
próprio MSVCRT, não código do jogo.

## 4. O lift já está pronto para o lote

`0x011e0e95` (18 instruções) e `0x011e07ef` (12 instruções, helper de CRT com
`atexit`) traduzem sem rejeição e **compilam para ARM64** com
`-Wall -Wextra -Werror`. Falta apenas o shim do `__getmainargs`.

## 5. Lacunas de lifter fechadas nesta etapa

O lote exigiu estas formas, agora implementadas com testes:

| Capacidade | Forma exata usada | Observação |
| --- | --- | --- |
| `SHR` | `SHR r32, imm8` e `SHR r32, CL` | CF = último bit deslocado, OF limpo |
| `SAR` | qualquer imediato 0..31 e `CL` | antes só 1 e 2 |
| `SHL` | `SHL r32, CL` | contagem mascarada em 5 bits |
| `XADD` / `LOCK XADD` | `XADD r/m32, r32` | prefixo `LOCK` é no-op no guest de uma thread, documentado |
| `INT3` | — | vira `BatchLiftStatus::debug_trap` (fatal, não continua) |
| `CALL [mem]` | `CALL dword ptr [EBP+0x14]` | ponteiro lido da memória guest e resolvido por `invoke_guest_call`, que falha fechado |
| operandos indexados | `OR`, `TEST` com `[base + índice*escala + deslocamento]` | antes só `MOV`/`LEA`/`CMP` |

Contagem de tradução na closure canonicalizada do lote: **318 de 354** corpos na
versão convergida parcialmente (os 36 restantes eram alvos que a caminhada ainda
não havia exportado, não lacunas de instrução).

## 6. Ferramentas novas

- `prepare_cpp_initializer_batch.py` — seleciona a fatia da tabela, roda as
  rodadas de desmontagem e **canonicaliza** cada alvo para a função que o
  contém, gravando `closure.json`, `addresses.txt` e `summary.json`.
- `ResolveSporeFunctionEntries.java` — resolve endereço, função no endereço e
  função que contém, sem desmontar nem criar nada.

Efeito medido da canonicalização: sem ela, 51 alvos caíam em blocos do meio de
funções e 52 rotinas falhavam com "branch target not exported"; com ela, os
exports truncados foram para **0**.

## 7. Estado

Nada foi registrado no harness: o walk ainda pararia no inicializador #0.
O prefixo continua em `0x011e0f98`, os sete estágios seguem verdes e os 85
testes Python passam. Artefatos:
`cpp-batch-1/` (`closure.json`, `summary.json`, `batch-1-analysis.json`) e
`cpp-initializer-sample.json`.

## 8. Validação nesta etapa

Depois das mudanças de lifter, os sete estágios foram reconstruídos e
executados: **x86 lift PASS** com as mesmas linhas de antes e **ARM64 compila**
(`PASS arm64_build`) nos sete. O aparelho `PJMZAEJRX4YLFIDI` **estava
desconectado** nesta etapa (o `adb` não listou dispositivo depois de
`kill-server`/`start-server` e `reconnect`), então **não houve execução ARM64 no
dispositivo** aqui; a última execução no aparelho foi no estágio anterior, antes
destas mudanças de lifter.

