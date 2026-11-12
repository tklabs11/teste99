# De 13 a 192 inicializadores no mesmo dia (2026-11-10)

Continuação de `report-cpp-batch-16-loop.md`. O laço `falta → planejar → aplicar →
reexecutar` foi levado até onde ele leva, e o limite deixa de ser dado: agora é
medição de código.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. A contagem, medida a cada passo

| passo | registrados | **`ran`** | muro |
| --- | --- | --- | --- |
| início do dia | 48 | 13 | `0x0143da50` (dado) |
| bloco de dados aplicado | 48 | 13 | `0x0121aee0` (corpo) |
| contrato do stub corrigido | 48 | **48** | lote esgotado |
| 96 registrados | 96 | **85** | `0x013eb198` (dado) |
| 6 shims de import | 96 | 85 | `tolower` resolvido, muro virou string |
| tabela de strings | 96 | **96** | lote esgotado |
| 192 registrados + 27 janelas | 192 | **147** | `0x013eb248` (dado) |
| bloco + página BSS | 192 | **192** | lote esgotado |

`ran` é o número de inicializadores **completados** (o corpo retornou e a moldura
voltou ao lugar), contado pelo runtime, não pelo tamanho do lote.

**Estado final: 192 de 192, x86, ARM64 e aparelho `PJMZAEJRX4YLFIDI` idênticos.**
Suíte completa: 32 PASS, 0 FAIL, 3 SKIP.

## 2. O que o `ran=48` revelou

O primeiro salto (13 → 48) não foi trabalho novo: foi perceber que **o lote estava
esgotado**. Todos os 48 inicializadores registrados já completavam, e o walk parava
em `0x0121aee0`, que é o próprio `kBatchNextInitializer` — a fronteira que eu
declaro de propósito. O mesmo aconteceu em 96 e em 192.

Isso significa que a pergunta "quantos o Android executa" tem resposta pelo lote, e
não pelo CRT: **o lote é sempre o teto até o primeiro corpo não levantado.**

## 3. Imports: o guest chama por ponteiro, não por nome

O muro em `ran=85` foi `MSVCR90.dll!tolower` — e `tolower` **não aparece em nenhum
corpo gerado**. A explicação:

```
eip=0x5f000b50  →  trampolim 181  →  IAT 0x013cc2ec  →  MSVCR90.dll!tolower
```

O guest leu o **slot da IAT como dado** (`MOV EAX,[0x013cc2ec]`) e chamou o ponteiro.
O tradutor não vê isso como import; o dispatcher resolve pelo trampolim. É mais um
motivo para a varredura estática de leitura existir.

### Implementados (semântica exata, cdecl)

| símbolo | modelo |
| --- | --- |
| `MSVCR90.dll!tolower` | ASCII, locale "C": `A`-`Z` desce 32, o resto volta igual |
| `MSVCR90.dll!_finite` | lê o `double` como 8 bytes de pilha e testa o expoente |
| `MSVCR90.dll!_isnan` | expoente todo 1 **e** mantissa não nula |
| `MSVCR90.dll!_purecall` | falha fechada: chamada virtual pura encerra o processo no CRT real, e o guest não tem processo |
| `KERNEL32.dll!OutputDebugStringA` | sem efeito, mas valida o ponteiro e a string |
| `KERNEL32.dll!WideCharToMultiByte` | byte por unidade; acima de `0xFF` usa o caractere default; `dst == NULL` é a chamada de dimensionamento |

Detalhe que importa: `_finite`/`_isnan` recebem **8 bytes**, então a contagem de
argumentos é 2 slots de dword, não 1. Errar isso desalinha o `ESP` de toda chamada
seguinte.

### Deixados como fronteira declarada (não implementados)

`KERNEL32.dll!CreateThread`, `MSVCR90.dll!_ecvt`, `_fcvt`, `_gmtime64`,
`_localtime64`, `_time64`, `strftime`. São os que exigem modelo novo — threads de
verdade ou formatação de tempo — e nenhum foi alcançado ainda. Ficam nomeados: se o
walk chegar neles, para e diz qual é.

## 4. Seis defeitos reais na ferramenta, encontrados usando-a

1. **Log em UTF-16.** O `>` do PowerShell grava UTF-16; a ferramenta lia UTF-8 e
   não via falta nenhuma. Agora detecta BOM e UTF-16LE.
2. **Quebra de linha no meio do endereço.** O shell parte a mensagem entre o
   endereço e o nome do corpo. O parse passou a ser do **texto inteiro**, não por
   linha.
3. **Classe de caracteres incompleta.** `\(spore_[0-9a-fA-F_/]+\)` omitia `s`, `p`,
   `o`, `r`, então parava na segunda entrada de uma lista
   `spore_a/spore_b/spore_c`. Agora é `\(spore[\w/]*\)`.
4. **Janela de leitura curta.** Eu lia ~520 bytes a partir de um ponto recuado, e a
   varredura para frente terminava **exatamente** no endereço da falta — a string era
   reportada 1 byte mais curta do que o guest precisava. Agora recua 256 e lê até
   4 KB.
5. **Uma janela por string.** Uma tabela de strings adjacentes custava um passo por
   entrada. Agora a janela cresce sobre toda palavra vizinha que seja texto ou NUL e
   para na primeira que não for — limite observado, não margem.
6. **Sobreposição e nome repetido.** O mapa do guest rejeita sobreposição. A regra
   agora é: a janela nova **absorve** o que toca, mas só quando o intervalo todo é
   do mesmo tipo de dado (bytes de arquivo ou BSS zerada); misturar falha alto em vez
   de emitir conteúdo errado. E um plano que reusa um nome declarado **substitui**
   aquele registro.

## 5. Correção de asserção (a terceira do mesmo tipo)

`neutralized=3/1/0` — uma das três chamadas ao stub violava o contrato. A razão:
minha asserção fixava `size == 0x400` e destino no heap. Apareceu
`f(0x01668994, 0, 0xF4)` escrevendo em `.data`. O stub sempre esteve certo (valida
tamanho e gravabilidade); o **teste** é que estava amarrado a valores de uma
observação só. Agora valida a **forma** e reporta quantos tamanhos distintos viu
(`n_sizes=2`).

Padrão que se repete neste projeto: asserção que fixa um valor observado uma vez
vira mentira quando a segunda observação chega.

## 6. Números do lote e da imagem

| | valor |
| --- | --- |
| inicializadores registrados | 192 |
| corpos | 458 |
| instruções | 15 147 |
| imports | 55 |
| corpos não medidos | **0** |
| pendentes | 1 (o stub neutralizado) |
| janelas de imagem | 51 |
| regiões | 51 + extras do harness |

A página BSS de `0x015d1000` sozinha absorveu **26** janelas de leitura estática da
mesma faixa (77 → 51).

## 7. O muro agora

`0x0121ceb0` = `kBatchNextInitializer`. Não é falta: é o lote esgotado outra vez.

Para subir a 384: **128 corpos precisam ser medidos** (o lote de 384 fecha em 522
corpos e hoje falta medir 128). Ou seja, o próximo passo deixa de ser automático —
é uma medição Ghidra.

## 8. Limites

- `ran=192` diz que 192 inicializadores **completam**; não diz que o CRT terminou.
  São 192 de 31 266 (0,61%).
- Os 6 imports deixados como fronteira podem virar muro a qualquer momento.
- `sections=8` e `imports=5254` são do ponto de parada.
- Nada disso é boot, menu, render ou gameplay.

## 9. Arquivos

Novos: `report-cpp-batch-15-ran.md`, `report-cpp-batch-16-loop.md`, este relatório,
`cpp-batch-15-walls/`, `cpp-batch-16-chain/`, `cpp-batch-17-tables/`,
`cpp-batch-2/engine-bodies-tables.txt`, `indirect-targets.json`,
`docs/referencias.md`.

Modificados: `BatchStaticLiftRuntime.hpp` (6 shims, `initializers_completed_`,
`FaultInfo::near_base`), `boot_entry_crt_harness.cpp` (`ran=`, `last_ran=`, `near=`,
contrato do stub por forma), `resolve_data_faults.py` (UTF-16, texto inteiro,
`\w/`, string table, data block, BSS page, reconcile), `BatchStaticLift.py`
(`MUL`, `IMUL r/m8`, `SHRD`, `ROL`/`ROR`/`RCR`, `JMP r32`, `batch_guest_pc`),
`generate_cpp_initializer_batch.py` (`--engine-body-file`, `missing` sem saltos
locais, fim da tabela), `generate_initterm_guest_image.py` (junções e janelas),
`tools/run_boot_crt_entry_tests.ps1` (192 inicializadores, 600 corpos, arquivo de
resposta no ARM64 com separadores dobrados), `test_static_batch_lift.py` (119
testes).
