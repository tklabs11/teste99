# Quantos inicializadores o Android executa de fato (2026-11-10)

Pergunta do autor do projeto: *quantos inicializadores o Android consegue realmente
executar em sequência, sem falhar?*

Resposta medida: **11**. Não 48.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Correção de um número que eu vinha repetindo

Todos os relatórios anteriores dizem `initializers=48`. Esse é o número que o lote
**registra** em `kBatchInitializerCount` — quantas entradas da tabela o lote se
compromete a cobrir —, e **não** quantas rodaram. Eu apresentei esse número como se
fosse execução. Não era.

Para não repetir o erro, o runtime agora conta o que de fato acontece: incrementa
`initializers_completed_` **só depois** de o corpo retornar e a moldura voltar ao
lugar (`state.eip == return` e `ESP` igual ao de entrada). O harness imprime
`ran=` e `last_ran=` nas duas linhas, `PASS` e `FAIL`.

## 2. O número medido

```
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00fcc210 executed=107
     imports=5141 initializers=48 ran=11 last_ran=0x01300150
     sections=7 tls=2 guard=single_instance count=8 fault=none
PASS x86_vs_arm64  (a mesma linha)
PASS arm64_device_run serial=PJMZAEJRX4YLFIDI
```

Os onze primeiros inicializadores não nulos, em ordem de tabela:

| # | alvo |
| --- | --- |
| 1 | `0x011e0e95` |
| 2 | `0x013000d0` |
| 3 | `0x013000f0` |
| 4 | `0x013b64c0` |
| 5 | `0x013b64e0` |
| 6 | `0x013002d0` |
| 7 | `0x0138e640` |
| 8 | `0x01300210` |
| 9 | `0x01300310` |
| 10 | `0x01300120` |
| 11 | `0x01300150` ← último que completou |

O 12º (`0x01300180`) começa e **não** completa: sua cadeia interna alcança um corpo
que não está no lote.

## 3. O limite não é o Android

O x86 e o ARM64 produzem **a mesma linha**, incluindo `ran=11` e `last_ran`. O
aparelho (`PJMZAEJRX4YLFIDI`) também. Portanto o teto não é da plataforma: é da
minha **cobertura de medição**. Não há nada no Android impedindo os 11; há código
não levantado impedindo o 12º.

## 4. Os "131 corpos" não eram corpos — e medi-los teria sido trabalho perdido

Antes de medir, verifiquei: **todos os 131 endereços da lista `missing_bodies`
estão dentro de corpos já medidos**. São saltos internos, por exemplo:

```
0x00454cb0 -> 0x00454d00 JMP 0x00454d3b     (dentro do próprio corpo)
0x00620230 -> 0x00620236 JMP 0x00620240
```

O gerador só filtrava saltos locais ao montar `engine` e `pending_bodies`, e
esquecia `missing` — que é justamente a lista que eu ia mandar medir. Corrigido, a
lista caiu de **131 para 1**:

| antes | depois |
| --- | --- |
| 131 "não medidos" | **1** realmente ausente: `0x0093a650` |

## 5. O que foi medido de verdade

Dois corpos, os únicos reais:

| corpo | extensão | instruções |
| --- | --- | --- |
| `0x0068f9b0` | `0x68f9b0..0x68f9df` | 3 corpos na rodada com `0x0093a650` |
| `0x0093a650` | `0x93a650..0x93a6b1` | (mesma rodada) |

Fronteira fechada e pequena: 2 corpos, 67 instruções, 0 imports novos, 0
truncados. União medida: **2 337 corpos / 184 523 instruções**.

## 6. O muro andou, a contagem não

Com os dois levantados o walk passou de `0x0068f9b0` para `0x00fcc210` — e `ran`
continuou **11**. A leitura correta: o 12º inicializador (`0x01300180`) é uma cadeia
longa de chamadas indiretas (é a tabela do registro de classes, a mesma faixa dos
93 ponteiros), e cada elo não levantado para o walk. Fechar o 12º exige levantar
essa cadeia, não um corpo.

`0x00fcc210` é um dos alvos da tabela de registro já lida do arquivo — está medido
como parte dos 93, mas não está semeado no lote.

## 7. O que isso muda na resposta ao autor

- O número honesto de execução é **11**, e ele é igual em x86, ARM64 e aparelho.
- "48" era registro de lote; "31 266" é o tamanho obrigatório da tabela. Nenhum dos
  dois é o que roda.
- O caminho para subir a contagem não é medir volume: é fechar a cadeia do próximo
  inicializador. Cada inicializador tem sua própria cadeia, e é aí que o custo
  aparece — não na tabela.

## 8. Limites desta medição

- `ran` conta inicializadores **completados**, não tentados. Um que começa e falha
  não entra, o que é o critério pedido ("sem falhar").
- Medido com a linha de base atual (48 registrados). Com mais inicializadores
  registrados, o teto continua sendo o primeiro corpo não levantado.
- O `sections=7`, `imports=5141` e `guard count=8` são do mesmo ponto de parada, não
  do fim do boot.

## 9. Suíte completa depois da mudança

A contagem nova toca o runtime compartilhado, então a suíte inteira foi reexecutada:
**32 PASS, 0 FAIL, 3 SKIP** (os três `SKIP` são o `original_x86_real_win32` dos
estágios que executam o walk real, que inicializa o processo de verdade e não pode
ser comparado).

Os 8 estágios passaram em x86, ARM64 e no aparelho `PJMZAEJRX4YLFIDI`, com a linha
`x86_vs_arm64` idêntica em todos. A mudança é aditiva (`ran=`/`last_ran=`) e não
alterou nenhum valor anterior: `imports`, `executed`, `sections`, `guard` e
`neutralized` seguem os mesmos dos passos anteriores.

