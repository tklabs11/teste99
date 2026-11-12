# Marco 6 — oitavo passo: medição de `0x00925730`, formas de string e o limite de export (2026-11-09)

Continuação de `report-cpp-batch-7-init48.md`. A ordem combinada foi seguida
inteira: (1) medir `0x00925730` e mesclar na closure, (2) fechar as formas de
string para passar de 48 inicializadores, (3) re-medir os três corpos truncados.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Medição de `0x00925730`

Uma medição com 60 rodadas Ghidra a partir dessa única raiz:

| | resultado |
| --- | --- |
| corpos | **1 805** |
| instruções | **158 479** |
| imports | 63 |
| alvos canonicalizados | 3 057 |
| exports truncados | 3 (os mesmos três antigos) |

O número grande é a closure *medida*, não o que o lote levanta: a maior parte
desses 1 805 corpos é alcançada por alvos canonicalizados que o gerador não
segue por chamada direta. Com `0x00925730` como semente e orçamento de 320
corpos, o lote fica em **117 corpos / 4 326 instruções / 36 imports** — ou seja,
o subsistema entrou por 5 corpos, não por 1 805.

Foi criado `tools/batch_static_lift/merge_closures.py` para unir medições por
`entry`, preferindo o registro não truncado e, no empate, o mais recente (que foi
medido com as regras de fronteira atuais). A união passou de 1 813 para
**2 195 corpos / 178 701 instruções / 0 truncados**.

## 2. Formas de string

Ghidra escreve o prefixo de repetição como sufixo do mnemônico
(`MOVSD.REP`, `CMPSB.REPE`), e o operando vem com segmento (`ES:EDI`, `ESI`).
O lifter agora reconhece os sufixos `.REP`, `.REPE`, `.REPNE` e trata:

| mnemônico | modelo |
| --- | --- |
| `MOVSB/MOVSW/MOVSD` | `batch_guest_rep_movs`: copia ECX elementos de DS:ESI para ES:EDI |
| `STOSB/STOSW/STOSD` | `batch_guest_rep_stos`: grava AL/AX/EAX ECX vezes em ES:EDI |
| `CMPSB/CMPSW/CMPSD` | `batch_guest_repe_cmps`: compara e repete enquanto igual (REPE) ou diferente (REPNE) |

Decisões registradas no código:

- **DF é modelado** a partir de `EFLAGS[10]`: a cópia pode descer. Não é um
  "assume-se sempre para cima".
- **limite de `1 << 20` elementos**: um `ECX` corrompido falha fechado em vez de
  rodar por tempo ilimitado; no caminho de falha, ECX/ESI/EDI ficam com o estado
  parcial, como o hardware faria.
- **colisão de nome resolvida por operando**: `MOVSD` sem prefixo e sem operando
  de segmento continua sendo o move escalar SSE; a forma de string só é tomada
  quando há prefixo de repetição ou `ES:`/`DS:` explícito.

Com isso o gerador passou a fechar **64, 96 e 128 inicializadores** (antes
falhava em 64 com `MOVSD.REP`). O lote publicado continua em 48 com orçamento de
320 corpos, para não trocar profundidade por amplitude sem decisão.

## 3. Os três corpos truncados: o limite era meu

Cada um tinha exatamente 2 048 instruções e um vão enorme, o que parecia
medição. O `DescribeSporeAddresses` mostrou as funções reais no provedor:

| corpo | extensão no Ghidra | instruções exportadas antes |
| --- | --- | --- |
| `0x00407280` | `0x00407280..0x0040989a` (9 754 bytes) | 2 048, truncado |
| `0x00441440` | `0x00441440..0x00446fec` (23 468 bytes) | 2 048, truncado |
| `0x004c73f0` | `0x004c73f0..0x004ca425` (12 341 bytes) | 2 048, truncado |

São funções grandes **de verdade** (as três começam com `PUSH EBP`), e a
truncagem vinha do meu próprio teto de export: `MAX_INSTRUCTIONS = 2_048` e
`MAX_SPAN = 0x4000` em `DisassembleSporeRoutines.java`. Elevados para
**16 384** e **0x8000**, a re-medição deu:

| corpo | instruções | truncado |
| --- | --- | --- |
| `0x00407280` | **2 182** | não |
| `0x00441440` | **5 316** | não |
| `0x004c73f0` | **2 444** | não |

A closure dessa re-medição tem **789 corpos, 83 935 instruções, 0 truncados**.
Ou seja: a hipótese de "fronteira de função mal medida" não se sustentava; o
limite era de exportação, e está corrigido.

## 4. Onde o walk para agora

```
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00935cc7 executed=107
     imports=5091 initializers=48 walk=stopped_at_0x00000000
     sections=4 tls=2 guard=single_instance node=0x5e000010 count=4
     neutralized=0x011e073e/1024/2/0 buf=0x5e000088 fault=write@0x00000008/4
```

O walk **passou de `0x00925730`** e entrou no subsistema de objetos: a trilha de
corpos termina em `0x00927be0 → 0x009267a0 → 0x009272c0 → 0x00926c20`.

A parada é uma **falta de memória real**, agora com endereço:
`fault=write@0x00000008/4`. A instrução é `MOV [ESI+8], EDI` com `ESI = 0`, e
`ESI` vem de `EAX` — o retorno de uma chamada indireta em `0x00935cc5`
(`CALL ECX`, com `ECX` lido de `[ESP+0x10]`).

Leitura honesta: o código espera um **singleton** que outra etapa do boot
preenche. A janela `0x01668ec0` está mapeada como zero porque o `SizeOfRawData`
de `.data` termina antes dela — isso é o que o *loader* faz, e está provado pela
tabela de seções. Quem deve escrever ali é código de boot anterior a este caminho,
e **isso é a próxima medição, não uma suposição**.

`fault=` no `PASS` é novo neste passo: a linha de sucesso também reporta a falta,
não só a de falha.

## 5. Estado entregue

```
PASS crt_entry / crt_startupinfo / crt_interlocked / crt_startup_lock
PASS crt_initterm_call / crt_initterm_executed (3/3) / crt_startup_state_initializing
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00935cc7 executed=107
     imports=5091 initializers=48 fault=write@0x00000008/4
PASS arm64_build 8/8 · PASS x86_vs_arm64 8/8 · PASS arm64_device_run 8/8 (PJMZAEJRX4YLFIDI)
105 testes Python OK
```

A igualdade x86↔ARM64 compara `imports=5091` e a mesma falta nos dois lados.

## 6. Próximo passo

1. Medir quem escreve `0x01668ec0` no boot real (o singleton que a falta revelou),
   em vez de mapear a palavra com valor inventado.
2. Subir o lote de 48 para 64 inicializadores — o gerador já fecha; falta decidir o
   orçamento de corpos e validar em execução.
3. Incluir as três funções grandes (2 182 + 5 316 + 2 444 instruções) quando algum
   caminho precisar delas; agora elas são medíveis.

## 7. Arquivos

Novos: `tools/batch_static_lift/merge_closures.py`,
`test-logs/boot-entry-20261108/cpp-batch-3/` (medição de `0x00925730`),
`cpp-batch-4-truncated/` e `cpp-batch-5-bigfuncs/` (re-medições).

Modificados: `tools/ghidra_scripts/DisassembleSporeRoutines.java` (teto de export;
cópia em `C:\Users\wesll\ghidra_scripts` também), `BatchStaticLift.py` (formas de
string, prefixos `.REP*`), `BatchStaticLiftRuntime.hpp` (três helpers de string com
DF e limite), `boot_entry_crt_harness.cpp` (`fault=` no `PASS`),
`generate_initterm_guest_image.py`, `test_static_batch_lift.py` (105 testes),
`tools/run_boot_crt_entry_tests.ps1` (semente `0x925730`, orçamento 320),
`test-logs/boot-entry-20261108/cpp-batch-2/closure-union.json` (união medida;
cópia anterior em `closure-union.pre-batch3.json`).

Evidências: `crt-cpp-walk-initializers-lift-x86.log`,
`run-batch-10-order.log`, `cpp-batch-3-measure.log`, `cpp-batch-4-measure.log`,
`cpp-batch-5-measure.log`, `cpp-batch-generation.log`.
