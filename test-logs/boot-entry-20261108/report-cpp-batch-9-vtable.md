# Marco 6 — nono passo: a falta de memória não era um singleton, era o meu `VirtualAlloc` (2026-11-09)

Continuação de `report-cpp-batch-8-order.md`. A correção mais importante deste
passo é sobre o passo anterior: **a conclusão publicada ali estava errada**, e a
instrumentação que fiz agora a desmente com endereço.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Primeiro: a falta passou a nomear a instrução

O `fault=` do passo anterior nomeava o endereço de memória (`0x00000008`) mas não
quem escreveu ali. Eu inferi o corpo a partir do último corpo registrado na
trilha — e **errei**: a trilha mostra os corpos *entrados*, não a instrução.

O lifter agora emite `batch_guest_pc = 0x...;` imediatamente antes de cada
instrução que toca memória (`with_program_counter` em `BatchStaticLift.py`), o
runtime guarda esse valor em `FaultInfo::pc` e o harness imprime `pc=` nas duas
linhas, `FAIL` e `PASS`. Instruções que só mexem em registrador não ganham a
linha, então o código gerado cresce apenas onde há acesso à memória.

Resultado imediato:

```
fault=write@0x00000008/4 pc=0x00935cc9
```

`0x00935cc9` fica em `0x00935c80`, **não** em `0x00926c20` como eu havia
afirmado antes. A instrução é:

```
0x00935cc5: ffd1        CALL ECX            ; a fábrica que [ESP+0x10] guarda
0x00935cc7: 8bf0        MOV  ESI, EAX       ; ← o resultado da fábrica
0x00935cc9: 897e08      MOV  [ESI+8], EDI   ; ← falta quando ESI = 0
```

Ou seja: é uma inserção em lista encadeada por **uma fábrica chamada por
ponteiro**, e o código original **não testa o retorno**. `ESI = 0` porque a
fábrica devolveu zero — não porque faltasse um singleton.

## 2. Por que a fábrica devolveu zero

O log de chamadas passou a imprimir **todos** os argumentos. A última coisa que o
guest pediu antes da falta:

```
VirtualAlloc args=0x00000000,0x01000000,0x00002000,0x00000004 result=0x00000000
VirtualAlloc args=0x00000000,0x01000000,0x00003000,0x00000004 result=0x00000000
last_error code=87
```

`0x01000000` = **16 MB**, `MEM_RESERVE` (0x2000) e depois `MEM_COMMIT|MEM_RESERVE`
(0x3000). Erro 87 (`ERROR_INVALID_PARAMETER`) porque a minha arena de
VirtualAlloc tinha **4 MB**: o pedido não cabia, o shim devolvia 0, e o código do
jogo — que nunca checa — escrevia no ponteiro nulo. A falha era **do meu
ambiente**, não do binário. E é exatamente o mesmo tamanho que o stub de proteção
pede (`0xbfa43` arredondado), o que faz sentido: é o heap que esse subsistema
usa.

### O que mudou no shim

- **Arena maior e fora de colisão**: `0x20000000` com 256 MB de espaço de
  endereço (`0x5d000000`..`0x5d400000` era apertado demais e encostava no heap do
  guest em `0x5e000000` e nos trampolins em `0x5f000000`). Espaço de endereço não
  custa memória do host.
- **Cada commit ganha o seu próprio bloco** (`std::make_unique<std::uint8_t[]>`)
  em vez de um pool de tamanho fixo. Antes, um `std::vector` que crescesse
  invalidaria ponteiros já mapeados; blocos independentes nunca se movem.
- **Limite total de commit** de 256 MB: uma reserva descontrolada falha fechada
  em vez de crescer sem limite.

Efeito: `fault=none`, o walk **atravessa** a fábrica, `imports` 5091 → 5096 e
`sections` 4 → **5**. O muro passou a ser outro, limpo, e nomeado.

## 3. Três muros caíram, um por vez

Cada muro foi resolvido com uma medição e uma janela de dados provada nos bytes
originais — nenhum valor foi inventado.

### 3.1 `0x00925bc0`, um corpo não levantado

Vizinho de `0x925a30`/`0x925cb0`. Medição Ghidra com 60 rodadas a partir dessa
única raiz:

| | resultado |
| --- | --- |
| corpos | **1 896** |
| instruções | **174 094** |
| imports | 63 |
| alvos canonicalizados | 3 405 |
| exports truncados | **0** |
| pendentes no fim | 1 |

Ao fim da 60ª rodada ainda havia 1 corpo novo pendente: a medição é **limitada
por rodadas**, não exaustiva, e isso fica dito. Com `--engine-body 0x925bc0` o
lote foi de 117 para **121 corpos / 4 460 instruções / 37 imports** e o walk
atravessou o corpo.

### 3.2 A vtable do objeto

```
fault=read@0x0143e050/4 pc=0x00925b2d
```

O corpo `0x00925b00` faz:

```
0x00925b1e: 8b5e10   MOV  EBX,[ESI+0x10]   ; o campo que guarda o objeto
0x00925b2b: 8b07     MOV  EAX,[EDI]        ; EDI = ESI, o próprio objeto
0x00925b2d: 8b10     MOV  EDX,[EAX]        ; ← lê [0x0143e050]
0x00925b31: ffd2     CALL EDX
```

`0x0143e050` fica em `.rdata` e **não estava em nenhuma janela** da imagem guest.
A leitura é calculada (o campo 0 do objeto alocado aponta para lá), então a
varredura de endereços absolutos do gerador de imagem não a via — a janela tem de
ser declarada.

Os bytes originais mostram porque é uma vtable e qual é o tamanho:

| endereço | valor | |
| --- | --- | --- |
| `0x0143e050` | `0x00925050` | `.text` |
| `0x0143e054` | `0x00925060` | `.text` |
| `0x0143e058` | `0x009255a0` | `.text` |
| `0x0143e05c` | `0x00925090` | `.text` |
| `0x0143e060` | `0x009251d0` | `.text` |
| `0x0143e064` | `0x009250b0` | `.text` |
| `0x0143e068` | `0x00925b50` | `.text` |
| `0x0143e06c` | `0x00925960` | `.text` |
| `0x0143e070` | `0x00925420` | `.text` |
| `0x0143e074` | `0x45415445` | `"EATE"` — já é string |

Nove slots, e depois vem texto. A janela `engine_object_vtable` cobre exatamente
`0x0143e050..0x0143e074` (0x24 bytes) e é **somente leitura**, lida dos bytes
originais: um ponteiro de método inventado viraria execução de endereço
arbitrário, então nada aqui é sintetizado.

Os nove métodos foram medidos numa rodada só, e essa convergiu:

| raiz | corpos | instruções | pendentes no fim |
| --- | --- | --- | --- |
| 9 métodos da vtable | 1 905 | 174 406 | **0** |

Com o slot 0 (`0x925050`) no lote, o walk passou do `CALL EDX`, `imports` foi a
5108 e o muro foi para `0x00925770`.

### 3.3 `0x00925770`, outro alvo indireto

Resolvido com o `ResolveSporeFunctionEntries` antes de gastar uma medição:
`function_at=null`, `function_containing=null`, mas **`instruction_start=true`** —
é código, não uma função declarada no projeto (o `0x00925730` que já levantamos
também não é). Medição com 40 rodadas: **1 519 corpos / 135 780 instruções / 0
truncados**, com **39 pendentes** no fim — limitada, portando incompleta, e dita
assim.

Efeito: o walk entrou numa **inicializadora de seção**. `sections` foi de 5 para
**7** e `imports` para 5116.

### 3.4 A segunda tabela de métodos

```
fault=read@0x01408324/4 pc=0x00697fe6
0x00697fe6: 8b5014   MOV EDX,[EAX+0x14]
```

`EAX` é o campo 0 de outro objeto e vale `0x01408310`; `+0x14` é o slot 5. O
levantamento dos bytes mostra uma **sequência contígua de 23 ponteiros de
`.text`** de `0x014082f0` a `0x01408348`, precedida de texto ASCII e seguida da
string `"Debug/EA…"` — os limites são observados, não arbitrados. Janela
`engine_class_vtable`, 0x5c bytes, somente leitura.

O walk então leu o slot e chamou o método, parando em `0x00697c40` — um corpo que
não está no lote. `fault=none`.

## 4. Estado entregue

```
PASS crt_entry            imports=5
PASS crt_startupinfo      imports=6   startupinfo=cb,ptrs_valid,reserved_null
PASS crt_interlocked      imports=7   icc=acquired try_level=1
PASS crt_startup_lock     imports=7   state=0
PASS crt_initterm_call    imports=7   table=0x13eb09c..0x13eb0ac
PASS crt_initterm_executed imports=14 initterm=walked initializers=3/3
PASS crt_startup_state_initializing imports=14 state=initializing cmp=equal
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00697c40 executed=107
     imports=5116 initializers=48 sections=7 tls=2
     guard=single_instance node=0x5e000010 count=8
     neutralized=0x011e073e/1024/2/0 buf=0x5e000088 fault=none
PASS arm64_build 8/8 · PASS x86_vs_arm64 8/8 · PASS arm64_device_run 8/8 (PJMZAEJRX4YLFIDI)
106 testes Python OK
```

Números do lote neste ponto: **48 inicializadores, 128 corpos, 4 642
instruções, 37 imports**, 1 pendente (o `0x011e073e` neutralizado). Imagem com
**41 regiões** (28 do PE, 13 zeradas), 6 528 bytes. União medida: **2 218 corpos /
179 458 instruções / 0 truncados**.

A progressão do subsistema neste passo, com a arena corrigida:
`sections` 4 → 5 → 7, `imports` 5091 → 5116, `count` do guard 4 → 8.

## 6. Correções ao registro anterior

1. **Não há "singleton nulo"**. A escrita em `0x00000008` era um ponteiro de
   retorno nulo da minha própria fábrica de `VirtualAlloc`, e o código original
   não testa esse retorno.
2. **A trilha de corpos não localiza a falta.** Ela mostra o que foi *entrado*.
   O `pc=` agora localiza a instrução, e ele mostrou que eu havia nomeado o corpo
   errado (`0x00926c20` em vez de `0x00935c80`).
3. **`0x00926c20` não é um inicializador quebrado**: é o gerenciador de heap que
   reserva 16 MB e entrega o bloco; ele *trata* a falha (`TEST EAX,EAX / JZ`), o
   chamador é que não trata.

## 7. Próximo passo

1. Levantar `0x00697c40`, o método que o slot 5 da segunda tabela chama — é o
   muro atual, um corpo que não está no lote.
2. O padrão está claro: este subsistema é **denso em alvos indiretos**, e cada
   iteração custa uma medição Ghidra de 15 a 20 minutos. Vale medir a faixa
   `0x00925000..0x00927000` de uma vez (exportar todas as entradas de função da
   faixa) em vez de correr atrás de um alvo por vez.
3. Revisitar os corpos que só existem porque a arena era pequena, para não deixar
   no relatório um muro que já não existe.

## 8. Arquivos

Novos: `test-logs/boot-entry-20261108/cpp-batch-6-925bc0/` (medição de
`0x00925bc0`), `cpp-batch-7-vtable/` (medição dos nove métodos) e
`cpp-batch-8-925770/` (medição de `0x00925770`).

Modificados: `BatchStaticLiftRuntime.hpp` (arena de 256 MB em `0x20000000`,
commit por bloco, limite de 256 MB, `batch_guest_pc` e `FaultInfo::pc`),
`BatchStaticLift.py` (`with_program_counter`), `boot_entry_crt_harness.cpp`
(`pc=` nas duas linhas, todos os argumentos no `DETAIL` das chamadas, `last_error`
no detalhe), `generate_initterm_guest_image.py` (janelas `engine_object_vtable` e
`engine_class_vtable`), `test_static_batch_lift.py` (106 testes),
`tools/run_boot_crt_entry_tests.ps1` (sementes `0x925bc0`, `0x925050`,
`0x925770`), `test-logs/boot-entry-20261108/cpp-batch-2/closure-union.json`
(cópias anteriores em `closure-union.pre-batch6.json`, `.pre-batch7.json` e
`.pre-batch8.json`).
