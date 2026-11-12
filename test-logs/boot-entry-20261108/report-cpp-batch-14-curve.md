# Curva de custo da tabela de inicializadores (2026-11-10)

Complemento de `report-cpp-batch-13-init-table.md`. A pergunta era se o custo de
levantar a tabela é **linear** ou **combinatório**. A resposta é linear — mas o
achatamento da curva tinha uma causa diferente da que o número sugeria na
primeira leitura, e essa causa vale mais do que a curva.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Método

`generate_cpp_initializer_batch.py --initializers N` com as mesmas sementes de
corpo de motor em todos os pontos, e `--bodies 20000` — bem acima do que a tabela
precisa — para que a medição não fosse limitada pelo meu orçamento. Cada execução
leva ~2 segundos, então a curva foi até a tabela inteira, não só até 384.

## 2. A curva

| N (inicializadores) | corpos levantados | instruções | corpos não medidos | Δ |
| --- | --- | --- | --- | --- |
| 48 | 254 | 11 509 | 131 | — |
| 96 | 323 | 12 985 | 131 | +69 corpos para +48 ini |
| 192 | 419 | 13 997 | 131 | +96 para +96 |
| 384 | 483 | 14 868 | 259 | +64 para +192 |
| 768 | 483 | 14 868 | 643 | **+0** para +384 |
| 3 072 | 483 | 14 868 | 2 947 | **+0** para +2 304 |
| 12 288 | 483 | 14 868 | 12 163 | **+0** para +9 216 |
| 31 266 | 451 | 12 752 | 31 126 | **+0** para a tabela inteira |

A partir de 384 o número de corpos **congela exatamente**. Ler isso como "o custo
satura" seria errado.

## 3. O que o congelamento realmente diz

A coluna "não medidos" entrega a causa:

- de 384 para cima, `não medidos = N − 125`, **exatamente**, em todos os pontos;
- na tabela inteira, `não medidos = 31 126 = 31 266 − 140`.

Ou seja: **140 dos 31 266 inicializadores (0,45%) estão na closure medida**. Todo
inicializador que não foi medido não pode ser levantado — ele é despachado e o walk
para ali, nomeando o endereço, que é o comportamento correto e já documentado.

O congelamento é o teto da **minha cobertura de medição**, não o teto do binário.

## 4. E o custo por inicializador medido é 1 corpo

Entre os pontos em que inicializadores de fato entram levantados:

| trecho | inicializadores a mais | corpos a mais | corpos por inicializador |
| --- | --- | --- | --- |
| 48 → 96 | +48 | +69 | 1,44 |
| 96 → 192 | +96 | +96 | **1,00** |
| 192 → 384 (só os 64 medidos) | +64 | +64 | **1,00** |

E a média de instruções por corpo **cai** ao longo da curva: 45,3 → 40,2 → 33,4 →
30,8. É a assinatura de helpers compartilhados: os primeiros inicializadores
trazem o runtime junto, os seguintes reaproveitam. Os imports ficaram parados em
**54** de 96 a 31 266, confirmando que nenhum subsistema novo é aberto.

**Não há explosão combinatória.** Cada inicializador custa cerca de um corpo — o
dele mesmo — e o resto já está lá.

## 5. O que isso muda no planejamento

O custo deixa de ser "medo do número" e passa a ser três limites concretos, todos
de ferramenta:

1. **Cobertura de medição.** 140 de 31 266 medidos. Levantar a tabela é medir
   ~31 100 corpos a mais. Pelo ritmo já observado (~1 800 corpos em 4 minutos de
   rodadas Ghidra), isso é da ordem de **algumas horas de medição**, em lotes —
   viável e paralelizável, não proibitivo.
2. **Volume de código gerado.** ~31 100 corpos × ~31 instruções ≈ **965 mil
   instruções** traduzidas. Hoje o modelo é **um `.cpp` por corpo**; com 31 mil
   arquivos, isso não se sustenta — a lista de fontes já estourou a linha de
   comando do Windows em 256 arquivos. Antes de entrar nos milhares, a emissão
   precisa agrupar vários corpos por unidade de tradução.
3. **Tempo de compilação.** Consequência direta de 2: precisa ser medido antes de
   comprometer, não estimado.

## 6. A ação que a curva revelou

O conjunto "131 corpos não medidos" é **o mesmo** de 48 a 192 inicializadores: é a
fronteira de closure desses inicializadores, não os inicializadores que faltam.
Isso dá um alvo de medição fechado e pequeno — 131 corpos — que destrava o trecho
48→192 sem precisar medir inicializador novo.

## 7. Bug encontrado e corrigido no caminho

Gerar a tabela inteira estourava com `IndexError`: o gerador escrevia
`targets[len(roots)]` para "o próximo inicializador", e no fim da tabela esse índice
não existe. Agora há um "não há próximo" explícito (`0x00000000`) no cabeçalho e no
manifesto, com comentário dizendo o que zero significa. Sem essa correção, o lote
da tabela inteira era impossível de gerar — e portanto a curva não fechava.

## 8. Limites desta medição

- Mede **quantidade de corpos e instruções**, não dificuldade: um corpo pode ser
  pequeno e conter uma instrução que o tradutor não modela (`MUL`, `RDTSC`,
  strings — todas já apareceram assim).
- "Não medido" não significa "difícil": significa estritamente "ausente da
  closure".
- A extrapolação de ~965 mil instruções assume a média atual de 31 por corpo; se
  os inicializadores tardios forem maiores, o número sobe.
- Nada disso diz que o boot está perto: prova que o **caminho é linear e
  mensurável**, não que seja curto.
