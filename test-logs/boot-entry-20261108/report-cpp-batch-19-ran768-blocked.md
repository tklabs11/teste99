# 768 inicializadores: medido, e **bloqueado** (2026-11-11)

Continuação de `report-cpp-batch-18-hex.md`. Este passo ia de 384 para 768 e **não
fechou**. O que segue é o que está medido, o que está provado sobre a causa, e o que
continua sem explicação.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. A medição: barata, como previsto

Antes de medir, a leitura da tabela já dizia o formato: muro em `0x0121fac0` =
inicializador **#385**, e os 384 seguintes são stubs minúsculos (39 funções vazias,
167 cópias de float, 178 registros em `atexit` com só 15 destinos de `CALL`
distintos; 117 formas distintas no total).

| item | valor |
| --- | --- |
| slice medido | inicializadores #385–#768 |
| corpos | **421** |
| instruções | **5 366** |
| truncados | **0** |
| rodadas Ghidra | 5 (384 → +22 → +3 → +11 → +1 → 0) |
| tempo | 2m30s |

União com o medido anterior: **2 873 corpos / 191 443 instruções / 0 truncados**
(2 489 + 421 − 37 sobrepostos).

## 2. O lote: superset estrito

```
lote gerado: 768 inicializadores, 1044 corpos, 22509 instruções,
             55 imports, pendentes 1, bloqueio de engine ['0x011e073e']
```

Os 660 arquivos do lote de 384 foram comparados um a um contra o lote de 768:
**660 presentes, 0 ausentes, 0 com conteúdo diferente**. O lote de 768 é o de 384
mais 384 corpos novos — nada regrediu no que já rodava.

## 3. A imagem: 62 janelas novas

O gerador de imagem recusou construir, nomeando ~600 endereços que os corpos novos
leem e nenhuma janela cobria. `resolve_data_faults.py --log` planejou
**62 janelas** (20 em `.rdata` de `0x013ebba0` a `0x013ec554`, 42 em BSS de
`0x015d2000` a `0x015d2c5c`), aplicadas com `--apply`:

| | regiões | do PE | zeradas | bytes | endereços de closure |
| --- | --- | --- | --- | --- | --- |
| antes | 62 | 47 | 15 | 139 644 | 774 |
| depois | **124** | 66 | 58 | 141 692 | 1 451 |

## 4. O resultado: não fecha

```
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00935cc7 executed=107
     imports=5092 initializers=768 ran=9 last_ran=0x01300310
     walk=stopped_at_0x00000000 sections=4 count=4
     neutralized=0x011e073e/1024/2/0 buf=0x5e000088 n_sizes=1
     fault=write@0x00000008/4 pc=0x00935cc9 near=0x00000000+0x0
```

`last_ran=0x01300310` é o **inicializador #9**. `ran=9`, não 384 e não 768: o walk
morre no **#10**, que já rodava. Idêntico em x86, ARM64 e no aparelho
(`PJMZAEJRX4YLFIDI`), então é determinístico, não ruído.

## 5. A causa é a imagem, não o lote

Uma variável por vez, mesmo stage:

| configuração | raízes | cap | imagem | resultado |
| --- | --- | --- | --- | --- |
| hoje cedo (suíte completa) | 384 | 900 | 62 regiões | **`ran=384`** |
| tentativa de 768 | 768 | 1400 | 124 regiões | `ran=9` |
| **isolação** | **384** | **900** | **124 regiões** | **`ran=9`** |

A terceira linha é a config da primeira com **só a imagem trocada**, e reproduz o
`ran=9`. O lote está descartado (é superset byte a byte). **A imagem é a variável.**

## 6. Onde exatamente quebra

O inicializador #10 (`0x01300120`) faz:

```
PUSH 0x00ee4655          ; um ponteiro de função
CALL 0x00935c80
MOV  [0x01668ea0], EAX
CALL 0x011e07ef
```

Dentro de `0x00935c80`, em `0x00935cbb`:

```
MOV ECX, [ESP+0x10]      ; slot ACIMA do argumento empilhado
...
CALL ECX                 ; 0x00935cc5
MOV ESI, EAX             ; 0x00935cc7
MOV [ESI+8], EDI         ; 0x00935cc9  ← escrita em 0x00000008
```

`CALL ECX` executou um corpo levantado e voltou **0** em EAX; o `MOV [ESI+8], EDI`
gravou no vazio. `[ESP+0x10]` não é argumento: é **moldura do chamador**, e o
harness fabrica EBP (`ebp=entry-4`), então esse slot não é fiel.

## 7. O que NÃO está explicado

A closure estática a partir do #10 tem **11 corpos** e lê/escreve **7 endereços
absolutos**. **Nenhum** deles cai em qualquer das 62 janelas novas. Ou seja: a
ligação entre "imagem maior" e "caminho diferente no #10" **não foi encontrada**.
Não vou escrever uma explicação que não tenho.

Duas possibilidades em aberto, ambas testáveis:

1. alguma das 62 janelas muda o resultado de uma leitura que antes **falhava** e cujo
   fracasso era tolerado em algum ponto do caminho (shim de import, corpo
   neutralizado) — não no corpo que quebra, num vizinho;
2. o slot `[ESP+0x10]` carrega um alvo que depende do **tamanho do lote** (tabela de
   despacho maior) ou do layout de memória do hospedeiro, e a imagem é só o gatilho
   que mudou o layout.

## 8. Consequência dura

`ran=384` **não é reprodutível com a imagem que o 768 exige**. O verde de hoje cedo
dependia das 62 janelas a menos. Isso não retira o valor do passo anterior, mas
rebaixa o 384 de "estado estável" para "estado estável *nesta* imagem".

## 9. Estado deixado na árvore

- As 62 janelas foram **revertidas**; a imagem volta a 62 regiões / 139 644 bytes /
  774 endereços (conferido).
- O plano ficou salvo em `cpp-batch-19-init385-768/window-plan.json` (62 janelas, com
  o texto C++ pronto em `rendered`), reaplicável.
- `run_boot_crt_entry_tests.ps1` voltou a **384 / 900** (último verde) com o caminho
  para tentar 768 escrito no comentário.
- `closure-union.json` mantém os 421 corpos novos (aditivo, conferido: o lote de 384
  sai byte a byte igual).
- 122 testes Python OK.

## 10. Arquivos

Novos: `cpp-batch-19-init385-768/` (`closure.json`, `round1..5.json`,
`resolve1..4.json`, `summary.json`, `prepare.log`, `image-static-reads.log`,
`window-plan.json`), este relatório.

Modificados: `generate_initterm_guest_image.py` (janelas aplicadas e revertidas;
`hex_literal_lines` mantido), `merge_closures.py` usado para a união,
`cpp-batch-2/closure-union.json` (+421 corpos).
