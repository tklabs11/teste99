# Marco 6 — quarto passo: lotes medidos do subsistema, e dois bloqueios concretos (2026-11-08)

Continuação de `report-cpp-batch-3-boundary.md`. A decisão foi traduzir o
subsistema de objetos em **lotes medidos**. Este relatório registra o que esse
modelo exigiu: sete formas de instrução que faltavam no lifter, as ferramentas de
lote, e os dois bloqueios reais que sobraram.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. O que mudou no lote

**Formas de instrução novas no lifter** (todas com teste):

| forma | semântica implementada |
| --- | --- |
| `XCHG r32, r32` | troca dois registradores; nenhuma flag muda |
| `IMUL r/m32` (1 operando) | `EDX:EAX = EAX * src`, CF/OF quando o produto não cabe |
| `IMUL r32, r/m32` e `IMUL r32, r/m32, imm32` | produto em 64 bits, destino truncado, CF/OF por extensão de sinal |
| `CDQ` | `EDX = sign(EAX)`; nenhuma flag muda |
| `IDIV r/m32` | divisão com sinal de `EDX:EAX`, quociente em EAX, resto em EDX, `divide_error` em zero ou estouro |
| `CMOVcc r32, r/m32` | move condicional reusando a tabela de condições dos `Jcc`; sem flags |
| `[REG*scale + disp]` | memória indexada **sem base** (tabela de despacho) |
| `JMP` para fora do próprio corpo | passa a ser tratado como *tail call* mesmo quando o provedor não marca `CALL_TERMINATOR` |

O último item mudou uma expectativa de teste antiga: um `JMP` para fora do corpo
continua sendo **rejeitado** quando o alvo não está exportado, mas a mensagem
agora nomeia o salto terminal (`tail jump target ... is not in the exported
function set`).

**Ferramentas de lote:**

- `prepare_cpp_initializer_batch.py --roots 0x…`: medir a partir de endereços
  explícitos (sem depender do recorte da tabela).
- `generate_cpp_initializer_batch.py`:
  - `--engine-body 0x…` (repetível) agora **semeia** o BFS na ordem da linha de
    comando — é assim que um corpo alcançado só por ponteiro entra no lote, e a
    ordem vira a prioridade quando o lote é limitado;
  - `--bodies N`: o tamanho do lote passa a ser um orçamento explícito;
  - `--allow-unresolved`: uma chamada direta para corpo não traduzido vira
    **despacho** (`invoke_guest_call`), que falha fechado nomeando o endereço — é
    o limite de lote em runtime, não um stub;
  - `--follow-outside`: segue por **alcançabilidade**, não por faixa de endereço;
  - `pending_bodies`/`kBatchPendingBodies`: lista dos corpos chamados e não
    traduzidos, isto é, onde a execução pode parar.

## 2. Os dois bloqueios medidos

Com a espinha do caminho feliz semeada (`0x00f474d0`, `0x00935c80`,
`0x00f47480`, `0x00927860`, `0x009274d0`, `0x00935b70`) e orçamento de 48 corpos,
a convergência do lote parou em dois pontos — ambos reproduzíveis:

**(a) Fronteira de função corrompida na medição.** O construtor chama
`memset(obj+0x30, 0, 0x400)` através de `0x011e073e`, que é uma cadeia de saltos
terminais pela CRT estática do executável:

```
0x011e073e  JMP  0x00401714
0x00401714  CALL 0x00401899
0x00401899  JMP  0x00401923  →  0x00401953  →  0x00402b23  →  …  →  0x0040726c
0x0040726c  export truncado (2048 instruções, limite do exportador)
```

`0x0040726c` não é uma função: o projeto Ghidra modela ali um bloco de 2048
instruções que atravessa até `0x00409898`. Enquanto essa fronteira não for
re-medida, esse trecho não é traduzível — e o `memset` do construtor está
exatamente atrás dela.

**(b) Tabela de salto (`switch`).** `0x00692372` é
`JMP dword ptr [EAX*0x4 + 0x6923e0]`: um *computed goto* por tabela. O lift não
tem essa capacidade (só `JMP` direto). Ela aparece no ramo do destrutor.

Também segue medido, do passo anterior: o ramo de erro
(`0x00f47430 → 0x009289e0 → 0x00927a50`) tem **1 525/1 526 corpos** — não é o
caminho a percorrer primeiro.

## 3. Estado entregue

Nada disso foi ligado ao estágio publicado: o walk continua parando em
`0x0138e640` e a suíte inteira foi re-executada depois das mudanças de lifter.

```
PASS crt_entry / crt_startupinfo / crt_interlocked / crt_startup_lock
PASS crt_initterm_call / crt_initterm_executed
PASS crt_startup_state_initializing / crt_cpp_walk
     (initializers=6, walk=stopped_at_0x0138e640, guard=single_instance)
PASS arm64_build (8/8) · PASS x86_vs_arm64 (8/8)
PASS arm64_device_run (8/8, serial=PJMZAEJRX4YLFIDI)
93 testes Python OK
```

## 4. Correção de infraestrutura

O runner passou a repetir a execução de binários recém-gerados e o `clang` quando
o Windows responde "arquivo em uso": a varredura em tempo real do Defender segura
o executável recém-escrito por alguns instantes. A repetição **não altera** o que
é executado nem afrouxa asserção alguma — apenas evita falha espúria.

## 5. Próximos passos, na ordem medida

1. Re-medir a fronteira de `0x0040726c` (e a cadeia que chega nela) para obter
   corpos com limites corretos — é o que destrava o `memset` do construtor.
2. Implementar `JMP [index*scale + disp]` (tabela de saltos) no lift, com falha
   fechada quando o destino não for um corpo nem um rótulo do próprio corpo.
3. Só então semear o lote com o construtor completo e ver até onde o walk chega
   dentro de `0x00927860`.

## 6. Arquivos

Modificados: `BatchStaticLift.py`, `generate_cpp_initializer_batch.py`,
`prepare_cpp_initializer_batch.py`, `test_static_batch_lift.py`,
`run_boot_crt_entry_tests.ps1`, `README.md`.

Evidências novas: `cpp-batch-2/closure-union.json` (1 813 corpos medidos até
aqui), `cpp-batch-2-happy/`, `run-after-lifter-forms.log`.
