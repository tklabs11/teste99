# Marco 6 — décimo passo: tabelas lidas do arquivo, e uma pilha de 1 KB (2026-11-09)

Continuação de `report-cpp-batch-9-vtable.md`. O passo anterior terminou com um
muro de dados (`read@0x0143e0xx`) e a observação de que este subsistema é denso em
alvos indiretos. Este passo atacou a causa: descobrir as tabelas **no arquivo**,
em vez de correr atrás de cada slot.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Ferramenta nova: as tabelas vêm do arquivo

`tools/batch_static_lift/find_pointer_tables.py` lê uma seção do PE e reporta
**runs maximais de ponteiros de código**: palavras de 4 bytes que caem na seção
executável. `--into LO HI` filtra os runs que alcançam uma faixa, `--min-entries`
exige um tamanho mínimo.

Para a faixa do subsistema de objetos (`0x00925000..0x00927000`) o resultado é
pequeno e fechado:

| run | entradas | situação |
| --- | --- | --- |
| `0x0143e050` | 9 | todos os 9 já medidos no passo anterior |
| `0x0143e0e4` | 12 | **nenhum** medido |

Ou seja: 21 métodos existem em tabelas para aquela faixa, e 12 faltavam. Os 12
foram medidos numa rodada só: **1 631 corpos / 147 230 instruções / 0 truncados**
(37 pendentes no corte de 40 rodadas — limitado, e dito).

A varredura completa de `.rdata` dá a dimensão do problema: **5 619 runs,
95 366 ponteiros, 50 319 alvos únicos**. Não é viável levantar isso; é viável
mapear o run que o guest lê.

## 2. Medições deste passo

| raiz | corpos | instruções | pendentes no fim |
| --- | --- | --- | --- |
| `0x00925bc0` (passo anterior) | 1 896 | 174 094 | 1 |
| 9 métodos da vtable 1 | 1 905 | 174 406 | 0 |
| `0x00925770` | 1 519 | 135 780 | 39 |
| `0x00697c40` | 1 566 | 142 338 | 54 |
| 12 métodos da vtable 2 | 1 631 | 147 230 | 37 |
| `0x0093c3e0` | 1 | 3 | 0 |

`0x0093c3e0` merece nota: são **três instruções** —
`INC [ECX+4]; MOV EAX,[ECX+4]; RET` —, um helper de contagem de referência
chamado por ponteiro. Ele aparecia como muro só porque não estava no lote.

União medida: **2 247 corpos / 181 085 instruções / 0 truncados**.

## 3. O bug de fixture mais grave até agora: 1 KB de pilha

O walk chegou a `fault=write@0x6ffffffc/4`. O endereço é 4 bytes **abaixo** da base
da pilha guest, e o ESP de entrada é `0x70000200` com a região em
`0x70000000..0x70000400`:

```
kStackBase  = 0x70000000
kEntryEsp   = 0x70000200
kStackBytes = 0x400        ← 512 bytes abaixo do frame de entrada
```

Qualquer cadeia real de chamadas estourava ali. Não era o binário: era o meu
fixture. Corrigido para o que um thread Windows dá de verdade:

```
kStackBase  = 0x6ff00400   ← 1 MiB abaixo do topo
kEntryEsp   = 0x70000200   (inalterado)
kStackBytes = 0x00100000
```

O **topo continua `0x70000400`**, então `kGuestStackBase` — que é o id de dono do
lock do CRT e o campo do TEB — não muda de valor, e todas as molduras que o
harness confere (`kInittermEsp`, `kStartupInfoEsp`, `kBoundaryEsp`) seguem iguais.
O buffer passou para o heap (`std::unique_ptr<std::uint8_t[]>`): o
`BatchLiftMemory` é local no `main` de cada harness, e 1 MiB na moldura do próprio
fixture seria um risco no aparelho.

## 4. Janelas de dados acrescentadas

Todas têm limites **observados no arquivo**, nenhum tamanho arbitrado.

| janela | faixa | tamanho | o que é |
| --- | --- | --- | --- |
| `engine_class_names` | `0x01408240..0x014082f0` | 0xb0 | nomes de classe comparados byte a byte; o bloco começa no primeiro nome e acaba onde a tabela de métodos começa |
| `engine_class_registry_tables` | `0x0143dcc4..0x0143de38` | 0x174 | 93 ponteiros de método indexados pelo registro; entre uma string ASCII e a string `EATrace` |
| `engine_switch_table` | `0x0093a2b8..0x0093a2d8` | 0x20 | tabela de salto de 8 entradas **dentro de `.text`**, entre uma palavra não-ponteiro e o padding `int3` |
| `engine_class_descriptor` | `0x0143dc78..0x0143dc8c` | 0x14 | o sentinela `-1` que o walk lê primeiro, seguido de quatro ponteiros de método |
| `engine_registry_flags` | `0x0154df84..0x0154df94` | 0x10 | quatro palavras de `.data` do registro; o arquivo tem zeros ali |

A tabela de salto em `.text` é um tipo novo: código que lê da própria seção de
código como dado. Nada foi sintetizado — a janela é cópia dos bytes do arquivo e
somente leitura.

## 5. Duas correções no harness (e uma delas era uma exigência errada)

**5.1 `frame_matches` no ponto errado.** A asserção comparava o EBP **vivo** com
`entry-4`. Isso valia enquanto o walk parava na própria moldura; agora ele para
dentro de código de engine que usa EBP como registrador de propósito geral
(`ebp=0x21004110`, um objeto do heap, não uma moldura). O EBP do prefixo passou a
ser capturado junto com EIP/ESI/EDI, e a asserção é feita nele. A moldura do walk
continua provada por `walk_esp == kInittermEsp` e pelos limites da tabela lidos
naquele endereço.

**5.2 A seção crítica recursiva era legal, e eu recusava.** O walk passou a
executar a sexta seção e a parar com ela **em uso**. O detalhe por seção mostrou:

```
section 5 0x21004110 lock=1 recursion=2 ok=0
```

LockCount 1 com RecursionCount 2 é exatamente a relação de uma seção **adquirida
uma vez e reentrada uma vez** — `LockCount == RecursionCount - 1`. A regra antiga
(`recursion <= 1`) recusava um estado legítimo do Windows. A regra nova é o
invariante, não uma foto:

- livre: `LockCount == -1` e `RecursionCount == 0`;
- em uso: `RecursionCount >= 1` e `LockCount == RecursionCount - 1`.

## 6. Estado entregue

```
PASS crt_entry            imports=5
PASS crt_startupinfo      imports=6   startupinfo=cb,ptrs_valid,reserved_null
PASS crt_interlocked      imports=7   icc=acquired try_level=1
PASS crt_startup_lock     imports=7   state=0
PASS crt_initterm_call    imports=7   table=0x13eb09c..0x13eb0ac
PASS crt_initterm_executed imports=14 initterm=walked initializers=3/3
PASS crt_startup_state_initializing imports=14 state=initializing cmp=equal
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00ff0420 executed=107
     imports=5134 initializers=48 sections=7 tls=2
     guard=single_instance node=0x5e000010 count=8
     neutralized=0x011e073e/1024/2/0 buf=0x5e000088 fault=none
PASS arm64_build 8/8 · PASS x86_vs_arm64 8/8 · PASS arm64_device_run 8/8 (PJMZAEJRX4YLFIDI)
108 testes Python OK
```

Lote: **48 inicializadores, 154 corpos, 6 544 instruções, 41 imports**, 1 pendente
(`0x011e073e`). Imagem: **46 regiões** (33 do PE, 13 zeradas), 7 144 bytes.

Progressão do subsistema neste passo: `imports` 5116 → 5134, `sections` 7
mantido, e o walk atravessou quatro muros de dados sem nenhuma falta de memória.

O muro atual é `0x00ff0420`, um alvo de chamada indireta fora do lote — não é
falta de dados nem erro: é código que ainda não foi levantado.

## 7. Decisão estrutural pendente

O padrão de muro agora é sempre o mesmo: uma tabela em `.rdata` que o guest lê
por ponteiro calculado. Cada iteração custa uma rodada de suite (cerca de 20 min)
para descobrir **um** endereço.

Medido: `.rdata` tem 5 619 runs de ponteiros de código e 95 366 ponteiros. Mapear
todos é inviável como janelas; mapear `.rdata` inteira (1,31 MB) como uma janela
somente-leitura é tecnicamente correto — é o que o loader faz — mas a imagem é
hoje **embutida como array de bytes** no cabeçalho gerado, e 1,31 MB viraria algo
como 8 MB de fonte por estágio.

As saídas a decidir:

1. **Embutir `.rdata` como blob binário** gerado e incluído pelo build (muda o
   formato da imagem; precisa de um caminho que funcione também no ARM64, onde
   não existe a PE em disco).
2. **Continuar por janelas**, usando `find_pointer_tables.py` para achar o run de
   cada falta — é o que este passo fez, e funciona, mas é lento.
3. **Registrar a tabela lida em tempo de execução**: o runtime, ao receber uma
   falta de leitura, informar o run candidato; o gerador então incorpora só
   aquele run. Automatiza o passo que hoje é manual.

Não escolhi sozinho porque muda o modelo da imagem, que é a base de todos os
estágios já validados.

## 8. Próximo passo

1. Levantar `0x00ff0420` (muro atual, corpo fora do lote).
2. Decidir entre 1, 2 e 3 acima para o problema de `.rdata`.
3. Medir os 12 métodos da vtable 2 apenas quando o walk os chamar; estão medidos,
   não estão semeados de propósito, para não inflar o lote.

## 9. Arquivos

Novos: `tools/batch_static_lift/find_pointer_tables.py`,
`test-logs/boot-entry-20261108/pointer-tables-all.json`,
`pointer-tables-925xxx.json`, `cpp-batch-9-697c40/`,
`cpp-batch-10-vtable2/`, `cpp-batch-11-93c3e0/`.

Modificados: `BatchStaticLiftRuntime.hpp` (pilha de 1 MiB em `0x6ff00400`, buffer
no heap), `boot_entry_crt_harness.cpp` (`prefix_ebp` capturado, invariante da
seção crítica, detalhe por seção), `generate_initterm_guest_image.py` (cinco
janelas novas), `test_static_batch_lift.py` (108 testes, inclui o detector de
runs), `tools/run_boot_crt_entry_tests.ps1` (sementes `0x697c40`, `0x93c3e0`,
`0x9248f0`), `cpp-batch-2/closure-union.json` (cópias em
`closure-union.pre-batch9.json` e `.pre-batch10.json`).
