# O laço fechado: 11 → 13 inicializadores (2026-11-10)

Continuação de `report-cpp-batch-15-ran.md`. Objetivo deste passo: semear o que já
estava medido e ver quantos inicializadores isso destrava, seguindo a opção 3
(falta → janela → reexecução) até onde ela levar.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Resultado

| etapa | `ran` | `sections` | `imports` | muro |
| --- | --- | --- | --- | --- |
| linha de base | 11 | 7 | 5 141 | `0x00fcc210` (corpo) |
| tabelas de classe semeadas | 11 | 7 | 5 192 | `0x009250b0` (corpo) |
| **+ bloco de dados `0x0143dff4`** | **12** | 7 | 5 216 | `0x01668950` (dado) |
| **+ página BSS `0x01668000`** | **13** | **8** | 5 219 | `0x0143da50` (dado) |

O 12º inicializador (`0x01300180`) e o 13º (`0x013001b0`) agora completam. O laço
`falta → planejar → aplicar → reexecutar` funcionou três vezes seguidas, x86 e ARM64
idênticos e no aparelho.

## 2. O lote está completo pela primeira vez

`faltando=0`, `pendentes=1` (só o stub neutralizado `0x011e073e`). 295 corpos,
12 786 instruções, 55 imports.

Para chegar lá foi preciso semear os **alvos indiretos das tabelas de classe** —
que o gerador não pode descobrir, porque só o guest sabe qual slot lê:

| tabela | alvos únicos |
| --- | --- |
| `engine_object_vtable` | 9 |
| `rdata_0143e0e4` | 12 |
| `engine_class_vtable` | 23 |
| `engine_class_descriptor` | 4 |
| `engine_class_registry_tables` | 62 |

90 únicos, **88 medidos e semeados**, 2 falsos positivos descartados. Arquivo novo:
`cpp-batch-2/engine-bodies-tables.txt`, com a origem e a lista dos não medidos.

## 3. Dois falsos positivos do meu detector de ponteiros

`0x00657461` e `0x00736c65` são ASCII — `"ate\0"` e `"sle\0"` — que caem dentro de
`.text` e foram lidos como ponteiro de código. O detector **não consegue** distinguir
texto de ponteiro; fica registrado como limite da ferramenta, e as duas palavras
foram riscadas da lista com o motivo escrito no arquivo.

## 4. Correções na ferramenta de janelas

Três defeitos reais, encontrados usando a ferramenta em produção:

1. **Bloco de dados não existia como classe.** Uma leitura em `0x0143dffc` (bloco de
   sentinelas `-1` entre texto e tabela) gerava janela de **4 bytes** — um passo por
   falta. Agora há `data_block`: um bloco de palavras que não são texto nem ponteiro
   de código, delimitado pelo que está no arquivo.
2. **BSS não tem bytes para delimitar nada.** Ali o plano derivava limites de bytes
   do arquivo que **não são** os do guest (o loader zera). Agora BSS é planejado
   como **página inteira** (`bss_page`), a granularidade do próprio loader, e a
   checagem acontece antes de qualquer leitura do arquivo.
3. **Sobreposição de janelas.** A página de 4 KB continha duas janelas anteriores, e
   o mapa do guest rejeita sobreposição. `apply_windows` agora **substitui** janelas
   contidas — mas só quando os dois lados são BSS, para nunca apagar bytes de arquivo
   silenciosamente. Um quarto bug apareceu no próprio conserto: o regex de remoção
   casava `0x4` e o arquivo escreve `0x04`, então uma janela sobrevivia à remoção.

Também: `--write` para declarar acesso de escrita em endereço explícito, e a razão da
janela agora diz `reads` ou `writes` conforme o caso — antes dizia `reads` numa
escrita.

## 5. O que cada iteração custa

Medido neste passo: **uma execução da suíte por muro**, ~10 minutos, e um comando
para a janela. Três muros em uma sessão. O gargalo agora é claro e honesto:

- muro de **dado** → 1 comando + 1 execução;
- muro de **corpo** → 1 medição Ghidra (segundos a minutos) + semear + 1 execução.

## 6. Estado entregue

```
PASS 32, FAIL 0, SKIP 3 — os 8 estágios em x86, ARM64 e aparelho (PJMZAEJRX4YLFIDI)
PASS crt_cpp_walk failed_at=0x009212c0 imports=5219 initializers=48 ran=13
     last_ran=0x013001b0 sections=8 tls=2 guard count=9
     neutralized=0x011e073e/1024/2/0 fault=read@0x0143da50/4 pc=0x009212e4
     near=0x0140f338+0x8
119 testes Python OK
```

Imagem: 47 regiões (35 do PE, 12 zeradas), 11 248 bytes. União medida: 2 351 corpos.

## 7. Próximo passo

O muro é `read@0x0143da50` e o `near` já diz o que é: logo depois da janela
`0x0140f338` (uma constante dupla). É outra falta de dado de 4 bytes — o plano
automatizado resolve. Depois dela, o laço continua.

## 8. Limites

- `ran` é o número de inicializadores **completados** numa execução; cada muro
  interrompe a contagem, então ela cresce um a um.
- `sections=8` e `imports=5219` são do ponto de parada, não do fim do boot.
- Semear alvos de tabela aumenta o lote (295 corpos) mas **não** mede nada novo; o
  teto de corpos subiu para 400 justamente para não esconder crescimento.
