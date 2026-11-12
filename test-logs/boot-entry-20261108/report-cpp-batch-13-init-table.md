# Prova: a tabela de 31 266 entradas é a do CRT (2026-11-10)

Pergunta que originou este relatório: **antes de tratar 31 266 como o total
obrigatório para chegar ao boot, provar que a tabela inteira pertence ao CRT.**
Tentei derrubar o número. Não consegui — mas o número significa menos do que
parece, e a segunda metade deste relatório é sobre isso.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Os limites vêm do binário, não de mim

No `_initterm` real, os dois argumentos são empilhados pela própria rotina de
startup do CRT. Instruções originais em `0x011e0ee0`:

```
0x011e0f65: 68 acb03e01   PUSH 0x013eb0ac     ┐ tabela de inicializadores C
0x011e0f6a: 68 9cb03e01   PUSH 0x013eb09c     ┘
0x011e0f6f: e8 a0050000   CALL _initterm_e
...
0x011e0f8e: 68 98b03e01   PUSH 0x013eb098     ┐ tabela de inicializadores C++
0x011e0f93: 68 0cc83c01   PUSH 0x013cc80c     ┘
0x011e0f98: ff15 ...      CALL _initterm
```

É a sequência canônica do MSVCR90: `_initterm_e(__xi_a, __xi_z)` e depois
`_initterm(__xc_a, __xc_z)`. **Eu não escolhi esses dois números** — o jogo empurra
exatamente `0x013cc80c` e `0x013eb098`, e o harness confere os dois valores lidos
da pilha do guest (`table=0x013cc80c..0x013eb098`).

## 2. Todo o intervalo é um vetor de ponteiros de código

Lendo o intervalo inteiro (0x013cc80c..0x013eb098, 125 068 bytes):

| | |
| --- | --- |
| slots de 4 bytes | 31 267 |
| nulos | **1** (slot 0) |
| não nulos | **31 266** |
| distintos | **31 266** |
| fora de `.text` | **0** |

`_initterm` chama **todos** os slots não nulos, sem filtro. Se um deles fosse dado
e não código, o jogo original quebraria na primeira execução — ele roda. Logo, os
31 266 são funções, e são todas obrigatórias antes de `main`.

## 3. O layout é o do MSVC

- A tabela cai inteira em `.rdata` (`0x013cc000..0x0150b600`), logo depois da região
  da IAT (`0x013cc000`).
- Depois do último slot vem uma palavra **zero** (`0x013eb098`) e, em
  `0x013eb09c`, começa a tabela do `_initterm_e`.
- Duas tabelas adjacentes, C++ e C — exatamente o par `__xc_a/__xc_z` +
  `__xi_a/__xi_z` que o MSVC emite.

## 4. As primeiras entradas são inicializadores do CRT

| slot | valor | observação |
| --- | --- | --- |
| 0 | `0x00000000` | nulo, o walk pula |
| 1 | `0x011e0e95` | dentro do próprio CRT, levantado e executado |
| 2 | `0x013000d0` | levantado e executado |

O MSVC coloca os inicializadores do próprio runtime no começo do array, e os dois
primeiros não nulos são de fato código do CRT/estático — coerente com o que o walk
executa (guarda de instância única, seções críticas, heap, registro de classes).

**Conclusão da primeira metade:** a tabela é a do CRT, os limites são do binário, e
31 266 é o número de chamadas obrigatórias. O número não é inflação minha.

## 5. O que 31 266 NÃO significa

O tamanho da *entrada* não é o tamanho do problema. Amostra aleatória de 300
entradas, decodificada com capstone até o primeiro `RET` (limite 80 bytes):

| medida | valor |
| --- | --- |
| chegam a `RET` em ≤80 bytes | **252 / 300 (84%)** |
| bytes até o `RET`: mínimo | 5 |
| mediana | **25** |
| p90 | 83 |
| entradas ≤ 24 bytes | **147 / 300 (49%)** |
| entradas ≤ 8 bytes | 14 / 300 (5%) |

Ou seja: a entrada típica é um corpo minúsculo — meia dúzia de instruções que
chamam um helper. Um `RET` a 5 bytes é um inicializador vazio.

Distribuição por faixa de 64 KB (as oito mais populosas):

| faixa | entradas |
| --- | --- |
| `0x013a0000` | 1 742 |
| `0x01250000` | 1 512 |
| `0x01360000` | 1 506 |
| `0x013b0000` | 1 444 |
| `0x01340000` | 1 426 |
| `0x01390000` | 1 401 |
| `0x01260000` | 1 294 |
| `0x01380000` | 1 257 |

Onze mil e seiscentas das 31 266 entradas cabem em oito faixas de 64 KB no fim de
`.text` — a banda onde código de template e inicializadores por unidade de
compilação se acumulam.

E o custo real é o **fecho**, não a entrada: das 31 266, apenas **256** já estão na
closure medida (2 336 corpos). E existem entradas caras — a de `0x0138e640` sozinha
arrastou **1 525 corpos**.

## 6. Como dimensionar antes de se comprometer

O gerador já aceita `--initializers N`. O experimento que responde "linear ou
combinatório" custa três execuções: subir para 96, 192 e 384 inicializadores e
registrar `corpos` e `instruções` de cada um.

- Se a curva **achata**, os helpers são compartilhados e o trabalho é longo mas
  previsível.
- Se ela **cresce proporcionalmente**, cada entrada arrasta código novo.

Não rodei essa curva ainda porque ela muda o orçamento de corpos do lote (hoje 256
de 320), e isso é decisão do autor do projeto.

## 7. Limites desta prova

- A PE não tem símbolos: "pertence ao CRT" está provado **estruturalmente** (sítio
  de chamada, layout de seção, conteúdo do array), não por nome.
- A amostra de tamanhos é decodificação linear com teto de 80 bytes; serve para
  dizer "pequeno/médio", não para medir funções exatas.
- Estar na tabela não garante ser trivial: alguns inicializadores abrem subsistemas
  inteiros (o stub de proteção `0x011e073e` é o exemplo já documentado, e é
  fronteira declarada).
- Nada disso diz que o boot está perto: a tabela é **necessária**, não suficiente.
