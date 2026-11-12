# Marco 6 — sétimo passo: 48 inicializadores, ADC e tempo determinístico (2026-11-09)

Continuação de `report-cpp-batch-6-float-and-thunks.md`. O lote do walk subiu de
**7 para 48 inicializadores C++** da tabela real, e o caminho revelou duas coisas
que precisavam de decisão: uma forma de instrução que faltava (`ADC` com carry),
uma instrução que não pode vir do host (`RDTSC`) e **uma dependência de relógio
do host que quebrava a igualdade x86↔ARM64**.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Formas novas no lifter

| forma | tratamento |
| --- | --- |
| `ADC r/m32, r/imm` | lê `CF` **antes** de escrever as flags, soma os três termos e usa `batch_set_adc_flags`, que aplica as fórmulas de AF/OF sobre `right + carry` |
| `ADC r/m8, r/m16` | mesma via, com a máscara da largura |
| `RDTSC` | `batch_guest_rdtsc`: contador **do guest**, não do host |

`ADC` era o único item que faltava da família aritmética: `SBB` já existia. O
`0x011e0846` que o exigia é o auxiliar de conversão `float` → inteiro de 64 bits
da CRT, que soma dois words com propagação de carry.

## 2. Tempo determinístico (a correção que a igualdade exigiu)

Com 48 inicializadores, o walk passou a entrar num laço de espera. A primeira
execução mostrou a divergência:

```
x86 lift:  imports=180843
ARM64:     imports=1251      (mesmo endereço de parada, mesmo estado do guarda)
```

O laço media tempo com `QueryPerformanceCounter`/`GetTickCount`, que vinham do
relógio do host. Num port diferencial isso é inaceitável: o número de iterações
passa a ser propriedade da máquina, não do programa.

Os dois passaram a ser do guest:

| fonte | modelo |
| --- | --- |
| `RDTSC` | base fixa `0x0000100000000000`, passo `0x40` por leitura |
| `QueryPerformanceCounter` | base fixa `0x0000000100000000`, passo `1000` por leitura |
| `GetTickCount` | base fixa `0x00010000`, passo `1` por leitura |
| `QueryPerformanceFrequency` | `10000000` (10 MHz), fixo |

Resultado: `imports=5087` **idêntico** no x86 e no ARM64. A documentação no
código diz que esses valores não são tempo real e que nada no port pode tratá-los
como relógio de parede.

`GetSystemTimeAsFileTime` continua vindo do host: é uma **data**, não um intervalo
decorrido, e o estágio `crt_entry` já o compara dentro de uma janela declarada.

## 3. Shims novos (5)

`GetCurrentProcess` (pseudo-handle `0xffffffff`), `GetPriorityClass`
(`NORMAL_PRIORITY_CLASS`), `SetPriorityClass`, `SetThreadPriority` e
`QueryPerformanceFrequency`. Os três de prioridade afetam apenas escalonamento, e
o guest tem uma thread: são registrados e aceitos, com falha fechada em handle
desconhecido.

## 4. Imagem do guest: 39 regiões

| | antes | agora |
| --- | --- | --- |
| regiões | 29 | **39** (26 da PE, 13 zeradas) |
| bytes | 4 736 | **6 400** |
| endereços cobertos | 49 | **178** |

Três avanços nesta parte:

1. **O scanner passou a ver endereços em argumentos de helper.** Antes ele só
   reconhecia `memory.load32(0x…)`; as leituras que passam por
   `batch_guest_movss_load(memory, state, N, 0x…)`, `batch_guest_fld64(…)`,
   `batch_guest_fstp32(…)`, `batch_guest_x87_compare_memory(…)`,
   `batch_guest_ucomiss_memory(…)`, `batch_guest_xorps_memory(…)` e as conversões
   ficavam invisíveis. O `0x01485718` só apareceu na execução, como falta de
   memória.
2. **Duas lições de falso positivo**, ambas registradas no código: a nota de corpo
   (`batch_guest_note_body(0x…)`) carrega endereço de **código**, e o mesmo vale
   para alvos de despacho — por isso a regra nova usa uma **lista explícita** de
   helpers que recebem endereço de memória, e não "qualquer `batch_guest_*`".
3. **Constantes de `.rdata` e blocos de `.data`** que os helpers de float usam
   ganharam janelas próprias; o bloco `0x015d0c00..0x015d1200` começa exatamente
   onde o `SizeOfRawData` de `.data` termina, então é zero do loader — e o
   gerador prova isso pela tabela de seções, não por suposição.

A tabela de regiões do runtime subiu de 32 para **128**: a imagem já ocupa 39 e o
`VirtualAlloc` do guest acrescenta as suas.

## 5. Diagnóstico que faltava: endereço da falta

`BatchLiftMemory` passou a guardar **a primeira** leitura/escrita que não pôde ser
servida, e o `FAIL` do harness imprime:

```
fault=read@0x01485718/4
```

Sem isso, uma falta de memória no meio de 287 instruções só dizia "invalid_memory".
Foi esse campo que permitiu achar, em sequência, `0x0140f338` (um `double`) e
`0x01485718` (um `float`) em vez de adivinhar.

## 6. Bússola da fronteira

O harness aceitava parada em dois casos (próximo inicializador, corpo pendente).
Agora aceita qualquer parada **que nomeie um endereço**:

- `unsupported_dependency` com o endereço no erro (o despachante deixa o endereço
  em `EIP` e o nome em `last_error`), ou
- `invalid_memory` com `EIP` definido.

Isso é o que uma fronteira significa: o walk parou num lugar identificado. Os dois
casos antigos continuam preferenciais e aparecem no `PASS`.

## 7. Onde o walk para agora

```
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00925730 executed=107
     imports=5087 initializers=48 walk=stopped_at_0x00925730 sections=4 tls=2
     guard=single_instance node=0x5e000010 count=4 mutex=SingleMgrMutex00001234
     neutralized=0x011e073e/1024/2/0 buf=0x5e000088
```

A trilha de corpos dos 32 últimos mostra que o walk executou, entre outros,
`0x01300310` (nono inicializador), `0x00939d40` (auxiliar de thread/perfil),
`0x011e0846` (conversão `float`→`int64`, o que exigiu `ADC`), `0x01300120`, e
reentrou na guarda de instância única (`0x00935c80` → `0x00935b70`, contador 4).

**`0x00925730` é uma chamada indireta cujo corpo ainda não foi medido.** Ele não
está na closure de 1 813 corpos: é a próxima raiz a medir com o script Ghidra, e
por isso o walk para ali nomeando-o — não por suposição nem por tratamento
especial.

## 8. Estado entregue

```
PASS crt_entry            stop=0x011e0ee7 executed=56  imports=5
PASS crt_startupinfo      stop=0x011e0efe executed=84  imports=6
PASS crt_interlocked      stop=0x011e0f24 executed=93  imports=7
PASS crt_startup_lock     stop=0x011e0f43 executed=88  imports=7
PASS crt_initterm_call    stop=0x011e0f6f executed=97  imports=7
PASS crt_initterm_executed stop=0x011e0f85 executed=102 imports=14 initializers=3/3
PASS crt_startup_state_initializing stop=0x011e0f98 executed=107 imports=14
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00925730 executed=107
     imports=5087 initializers=48 walk=stopped_at_0x00925730
PASS arm64_build 8/8 · PASS x86_vs_arm64 8/8 · PASS arm64_device_run 8/8 (PJMZAEJRX4YLFIDI)
103 testes Python OK
```

A igualdade x86↔ARM64 agora compara `imports=5087` nos dois lados: o laço de
espera termina no mesmo número de iterações em qualquer máquina.

## 9. Próximo passo

1. Medir `0x00925730` (e a closure que ele abrir) e mesclar na closure do lote.
2. Formas que limitam o lote acima de 48 inicializadores: `MOVSD.REP`/`MOVSD`
   com `ES:EDI`/`DS:ESI` — os primeiros corpos que falham em `--initializers 64`.
3. Re-medir `0x00407280`, `0x00441440` e `0x004c73f0`, que continuam truncados.

## 10. Arquivos

Modificados: `tools/batch_static_lift/BatchStaticLift.py` (`ADC`, `RDTSC`),
`BatchStaticLiftRuntime.hpp` (`batch_set_adc_flags`, `batch_guest_rdtsc`, tempo
determinístico, 5 shims, diagnóstico de falta, 128 regiões),
`boot_entry_crt_harness.cpp` (fronteira nomeada, `fault=` no `FAIL`),
`generate_initterm_guest_image.py` (scanner de helper, 10 janelas),
`test_static_batch_lift.py` (103 testes),
`tools/run_boot_crt_entry_tests.ps1` (48 inicializadores).

Evidências: `crt-cpp-walk-initializers-lift-x86.log` (trilha de corpos, 5 087
imports, `NEUTRALIZED:`), `crt-cpp-walk-initializers-arm64.log`,
`run-batch-9-init48.log`, `cpp-batch-generation.log`,
`initterm-guest-image.log`.
