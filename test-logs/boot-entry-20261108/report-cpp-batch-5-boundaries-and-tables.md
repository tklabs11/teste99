# Marco 6 — quinto passo: fronteiras de função, tabelas de salto, e o novo alvo (2026-11-08)

Continuação de `report-cpp-batch-4-lifter-and-limits.md`. Os dois bloqueios
apontados no passo anterior foram atacados: a fronteira de função na medição e a
tabela de saltos no lift. O resultado muda o mapa do caminho.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Fronteira de função na medição (Ghidra)

`DisassembleSporeRoutines.java` fazia descida recursiva seguindo **todo** salto.
Um despachante que salta para outra função engolia a função inteira, e o corpo
saía com 2048 instruções e export truncado.

Regra nova: um salto **incondicional** cujo destino pertence a outra função
termina o corpo (é *tail call*, o alvo é medido por si). Salto **condicional**
continua sendo seguido, porque compilador funde caudas idênticas no intervalo de
uma função vizinha — bloquear isso quebrava corpos legítimos (foi o que a
primeira versão da regra fez com `0x0040193c`, e a correção veio da própria
medição).

**Prova da correção:**

| corpo | antes | depois |
| --- | --- | --- |
| `0x0040726c` | 2048 instruções, export truncado, atravessando até `0x00409898` | **375 instruções, exato** |
| cadeia de `0x011e073e` (o preenchimento de memória do construtor) | terminava no blob truncado | **14 corpos, 559 instruções, 0 truncados, 0 imports** |

A cadeia medida, na ordem:

```
0x011e073e → 0x00401714 → 0x00401899 → 0x00401923 → 0x00401930/0x00401953/0x00401960
          → 0x00402385 → 0x00402414 → 0x00402420 → 0x004029e6 → 0x00420660
          → 0x00425a80 (229) → 0x0067dd60
```

## 2. Tabela de saltos no lift

`JMP dword ptr [EAX*0x4 + 0x6923e0]` (o `switch` do motor) passou a ser
traduzido como **despacho computado**:

- o slot é lido da memória do guest (`load32` da expressão de endereço);
- o destino é escolhido por `switch` sobre os rótulos que o provedor resolveu
  (`flows_to`) — `case 0x…: goto L_…;`
- um slot que não nomeia nenhum desses rótulos **falha fechado**:
  `state.eip = <alvo>` e `unsupported_dependency`, sem inventar destino.

## 3. O que a medição corrigida revelou

Com a fronteira certa, o preenchimento de memória do construtor deixa de morrer
num blob — e segue para a **biblioteca de ponto flutuante da CRT**:
`0x004098d2`, `0x00409dc2`, `0x0040a164`, `0x0040a581`, `0x0040aea3`,
`0x0040cca3`, `0x0040cd72`, …

O que falta ali, medido nas mensagens do lifter:

| falta | onde aparece |
| --- | --- |
| `FLD` de 32 bits e de 80 bits (estendido) | `0x004098ad`, `0x00409903`, `0x0040cbb…` |
| `FLD1` | `0x0041c5e4` |
| `FABS` | `0x0040a14d` |
| `XORPS` com operando de memória | `0x00409aa2`, `0x00409c6a` |
| `MOVSS` com `XMM0` na forma que o provider emite | `0x00409cef`, `0x00409d16` |

Três corpos continuam truncados mesmo com a regra nova e precisam de nova
medição: `0x00407280`, `0x00441440`, `0x004c73f0`.

## 4. Estado entregue

Nada disso foi ligado ao estágio publicado: o walk continua parando em
`0x0138e640`, e a suíte inteira passou depois das duas mudanças.

```
PASS crt_entry / crt_startupinfo / crt_interlocked / crt_startup_lock
PASS crt_initterm_call / crt_initterm_executed / crt_startup_state_initializing
PASS crt_cpp_walk ... initializers=6 walk=stopped_at_0x0138e640 guard=single_instance
PASS arm64_build 8/8 · PASS x86_vs_arm64 8/8 · PASS arm64_device_run 8/8 (PJMZAEJRX4YLFIDI)
95 testes Python OK
```

## 5. Próximo passo, medido

1. `FLD m32`, `FLD1`, `FABS`, `XORPS xmm, mem` e `MOVSS` com `XMM0` — as formas
   que a biblioteca de float da CRT usa.
2. Re-medir `0x00407280`, `0x00441440`, `0x004c73f0`.
3. Semear o construtor completo (`0x00927860`) e ver onde o walk para dentro de
   `0x0138e640`.

## 6. Arquivos

Modificados: `tools/ghidra_scripts/DisassembleSporeRoutines.java` (e a cópia em
`C:\Users\wesll\ghidra_scripts`), `BatchStaticLift.py`,
`test_static_batch_lift.py`, `README.md`.

Evidências novas: `cpp-batch-2-chain/` (cadeia de preenchimento de memória,
14 corpos), `cpp-batch-2-truncated/` (230 corpos re-medidos),
`cpp-batch-2/closure-union.json` (1 813 corpos), `run-after-boundary-fix.log`.
