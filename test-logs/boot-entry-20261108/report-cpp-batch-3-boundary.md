# Marco 6 — terceiro passo: o limite medido em `0x0138e640` (2026-11-08)

Continuação de `report-cpp-batch-2-guard.md`. O walk para em `0x0138e640` porque
o corpo `0x00f474d0` não está traduzido. Este relatório mede o que esse corpo
exige — e o resultado é o fim do modelo limitado por inicializador.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. O que `0x0138e640` faz

```c
if (g_subsystem == NULL) {                       // [0x016c8b40]
    ok = sub_0x00f474d0();
    g_initialized = 1;                           // [0x016c8b48]
    if (!ok) g_initialized = 0;
}
_atexit_register(0x013c9950);                    // via 0x011e07ef
```

`0x00f474d0` (21 instruções, lido da PE):

```c
if (g_subsystem == NULL) {
    p = sub_0x00935c80(0xee9b7413, sub_0x00f47480);   // registry: chave + fábrica
    g_subsystem = p;
    if (!p) return 0;
}
if (p->magic != 0x2b5c || p->flag != 0) { sub_0x00f47430(); return 0; }  // caminho de erro
g_object = p + 0x18;                             // [0x016c8b44]
return 1;
```

Três funções de engine novas entram aí:

| endereço | instruções | papel |
| --- | --- | --- |
| `0x00935c80` | 55 | registro global: pega a guarda, `EnterCriticalSection`, procura a chave numa lista duplamente ligada, e **chama a fábrica por ponteiro** (`CALL ECX`, argumento 2) |
| `0x00f47480` | 27 | a fábrica: `HeapAlloc(hp,0,0x530)`, grava `[+0x10]=0x2b5c`, `[+0x14]=0`, e chama o construtor `0x00927860(objeto+0x18)` |
| `0x00927860` | 100 | construtor do objeto de 0x530 bytes; chama `0x009274d0` (135) |
| `0x00f47430` | 23 | desmonte do objeto — só no caminho de erro (magic não bate) |

## 2. A medição

Duas medições independentes, ambas com Ghidra headless no projeto
`C:\SporeAnalysis\SporeREA4G`:

| conjunto | corpos (canônicos) | instruções |
| --- | --- | --- |
| closure estática de `0x0138e640` (união das três medições) | **1 525** | **130 269** |
| ramo de erro sozinho (`0x00f47430` → `0x009289e0` → `0x00927a50`) | 1 526 | ~130 000 |
| caminho feliz estático até `0x009274d0` (2 rodadas) | 7 | 413 |

E há um detalhe que a caminhada estática **não** enxerga: a fábrica
`0x00f47480` só é chamada por ponteiro dentro de `0x00935c80`, então nenhuma
análise de chamadas diretas a encontra — foi preciso ler o sítio de chamada em
`0x00f474d0`. Somando essa aresta, o caminho "feliz" também cai no mesmo fecho.

Conclusão medida: **atravessar `0x0138e640` exige traduzir o subsistema de
objetos do motor** (≈1 525 corpos / 130 mil instruções), não uma função isolada.
O modelo de lote limitado, que funcionou para os seis primeiros inicializadores
(CRT e runtime), chega ao fim aqui: o sétimo inicializador da tabela já constrói
um subsistema de engine.

## 3. Estado entregue (sem regressão)

O walk continua parando exatamente onde deve, e a parada está documentada:

```
PASS crt_cpp_walk stop=0x011e0f98 executed=107 imports=40 initializers=6
     walk=stopped_at_0x0138e640 ... guard=single_instance
PASS arm64_build / x86_vs_arm64 / arm64_device_run serial=PJMZAEJRX4YLFIDI
89 testes Python OK
```

Nada foi traduzido neste passo além das medições. Nenhum stub, nenhum retorno
artificial: `0x0138e640` continua bloqueando porque de fato não tem corpo.

## 4. Ferramenta nova

`prepare_cpp_initializer_batch.py --roots 0x...` (repetível): mede a closure a
partir de endereços explícitos, sem depender do recorte da tabela. Foi o que
produziu as medições acima (`cpp-batch-2/`, `cpp-batch-2-happy/`).

## 5. Decisões possíveis

1. **Traduzir o subsistema em lotes medidos.** 1 525 corpos, ~130 mil
   instruções, com imports e shims próprios. São vários passos do tamanho dos
   anteriores (o lote 2 teve 16 corpos), e cada um precisa da sua própria
   validação. É o caminho que continua a tabela na ordem.
2. **Parar a tabela aqui** e registrar 6 de 31 266 inicializadores como o
   alcance atual do walk, voltando a frente para outro ponto da cadeia de boot
   (por exemplo o construtor `FUN_00a33600`, que já tem prefixo verificado).
3. **Reconstruir o registro/objeto por shim** (hand-written `0x00935c80` e
   `0x00f47480` no runtime). Tecnicamente possível, mas troca código original por
   código nosso — sai do que o projeto tem feito até agora e precisa ser uma
   decisão explícita, não um atalho silencioso.

A decisão não é minha: as três mudam o escopo do marco.
