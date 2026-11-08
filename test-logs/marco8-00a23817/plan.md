# Marco 8 — plano v43 (engatilhado, não executado)

Este arquivo registra a varredura e o plano para retomar o construtor em
`0x00a23817 → FUN_00a221b0`. Nada aqui foi executado: o aparelho estava
desconectado e o marco 8 não foi iniciado.

## Estado herdado (v42)

- Prefixo composto de `FUN_00a2a210` a partir do construtor, 71 instruções
  verificadas, 70 traduzidas.
- Chamada do construtor `0x00a33817 → FUN_00a2a210` executada na fixture.
- Limite validado: **`0x00a23817`**. Último byte executado: **`0x00a23816`**.
- Bytes da chamada no PE: `e894e9ffff` → destino `0x00a221b0`.
- Comparação x86 original / lift x86 / ARM64 aprovada no aparelho
  `PJMZAEJRX4YLFIDI` antes da desconexão.
- Objeto de fixture: `0x118b60` bytes mais canário após o fim.
- PE de referência SHA-256
  `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## Varredura do próximo alvo

Fonte: [scan-00a221b0.json](./scan-00a221b0.json), gerado por
`diagnose_call_closure.py` com os batches `0041`, `0034`, `0021`, `0040` e
`0086`, raiz `0x00a221b0`.

| Campo | Valor |
| --- | --- |
| Função | `FUN_00a221b0` |
| Instruções | 37 |
| Bytes verificados | 98 |
| Instruções não suportadas | 0 |
| Chamadas indiretas | 0 |
| Destinos ausentes dos exports | 2 |

Chamadas diretas do corpo:

| Site | Destino | Classificação | Situação conhecida |
| --- | --- | --- | --- |
| `0x00a221e9` | `0x00f473a0` | body ausente | ramo condicional; pulado quando a lista livre não está vazia |
| `0x00a221fc` | `0x011e073e` | body ausente | thunk; resolve para `MSVCR90.dll!memset` no callsite observado no processo real |

Observações que sustentam o plano:

- A execução isolada anterior de `FUN_00a221b0` (família v29–v33) provou que,
  nessa fixture, a lista livre não vazia desvia de `0x00f473a0` e alcança
  `0x00a221fc`.
- A captura do processo real `SporeApp.exe` identificou o desvio de
  `0x011e073e` para `MSVCR90.dll!memset` após a primeira resolução, com
  `0x31c` bytes zerados nessa chamada posterior.
- Portanto o primeiro limite honesto depois de `0x00a23817` é `0x00a221fc`,
  não a entrada da função.

## Definição do v43

Objetivo: executar a chamada `0x00a23817 → FUN_00a221b0`, entrar no ramo que
pula `0x00f473a0` e parar **antes** de `0x00a221fc`.

- Limite esperado: `0x00a221fc`.
- Último byte esperado: `0x00a221fb`.
- Instruções novas da filha: 18.
- Semântica nova de instrução x86: nenhuma esperada.

## Passos de implementação

1. `tools/batch_static_lift/generate_m7_00a2a210_entry.py`
   - nova flag `--through-sixth-helper-allocator-call`;
   - define correspondente `M7_THROUGH_SIXTH_HELPER_ALLOCATOR_CALL`;
   - inclui as 18 primeiras instruções de `FUN_00a221b0` no prefixo composto e
     grava `boundary = 0x00a221fc`, `boundary_executed = false`.
2. `tools/batch_static_lift/constructor_prefix_harness.cpp`
   - `kCompositeStop = 0x00a221fcu` sob o novo define;
   - mantém `kObjectBytes = 0x118b60` e o canário após o objeto;
   - mantém a cadeia de defines do v42 e acrescenta apenas o novo estágio.
3. Fixture
   - objeto de `0x118b60` bytes com o mesmo preenchimento documentado do v42;
   - a lista livre precisa permanecer não vazia; o campo que a materializa deve
     ser registrado no relatório do v43, não inferido;
   - nenhum valor de retorno de `0x00f473a0` deve ser preparado, porque esse
     ramo não é executado.
4. Validação
   - x86: bytes originais do PE em Unicorn ou harness nativo, lift x86 e
     comparação de registradores comparáveis, flags, pilha, objeto e canário;
   - ARM64: mesmo binário via clang `aarch64-linux-android29`, executado por
     ADB no aparelho;
   - regressão: v42 recompilado deve continuar aprovado e interromper em
     `0x00a23817`.

## Comandos previstos

Cadeia de defines do v42 (arquivo
`test-logs/marco7-00921260/build-m7-constructor-sixth-helper-float-call-x86.cmd`)
acrescida de:

```
/DM7_THROUGH_SIXTH_HELPER_ALLOCATOR_CALL
```

Build x86 e ARM64 seguem o mesmo padrão dos estágios anteriores, com os
diretórios:

- `test-logs/marco7-00921260/generated-constructor-sixth-helper-allocator-call-v43/`
- `test-logs/constructor-prefix-00a33600-20261106-173351200/generated/`
- `test-logs/constructor-prefix-00a33600-20261106-173351200/generated/closure/`

## Critérios de aceite do v43

- Snapshots equivalentes entre bytes x86 originais, lift x86 e lift ARM64 no
  aparelho.
- Último byte executado `0x00a221fb`, com parada explícita em `0x00a221fc`.
- Nenhuma substituição de `0x00f473a0` por resultado pronto.
- Regressão v42 aprovada.
- Testes Python aprovados sem alterar critérios existentes.

## Bloqueios e riscos registrados

- Se a fixture materializar uma lista livre vazia, o limite passa a ser
  `0x00a221e9` e isso deve ser reportado como resultado, não contornado.
- `0x00f473a0` continua sem corpo recuperado; nenhuma semântica foi inventada.
- O alias `memset` em `0x00a221fc` só deve ser usado no v44, e apenas com a
  evidência já registrada do processo real.
