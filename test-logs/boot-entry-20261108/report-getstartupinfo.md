# `__SEH_prolog4` executado e `GetStartupInfoA` implementado

Data: 2026-11-08
PE de referência: `C:\SporeAnalysis\SporeApp.exe`
SHA-256: `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
Variante Steam (`SPOREFILES\SporeBin\SporeApp.exe`) com o mesmo SHA-256.
`HEAD` no início do trabalho: `1e3c23714afe3402537da4a117b35aadef49f8c1`.

## 1. Resultado

`___tmainCRTStartup` (`0x011e0ee0`) agora executa além do `CALL 0x011e11d4`:

1. `__SEH_prolog4` (`0x011e11d4`, 21 instruções) executa inteira e retorna para
   `0x011e0eec`.
2. O prefixo segue `XOR EBX,EBX`, `MOV [EBP-0x1c],EBX`, `MOV [EBP-0x4],EBX`,
   `LEA EAX,[EBP-0x68]` e `PUSH EAX`.
3. `0x011e0ef8` `CALL [0x013cc29c]` = `KERNEL32.dll!GetStartupInfoA` executa com
   shim de guest.
4. Limite atual: `0x011e0efe` (o `CALL` ocupa `0x011e0ef8`–`0x011e0efd`).

`PASS crt_startupinfo stop=0x011e0efe executed=84 esp_delta=-124 ebp=entry-4
ebx=0 callee_saved=restored cookie=consistent imports=6
startupinfo=cb,ptrs_valid,reserved_null`

Idêntico em: x86 original com APIs reais do Windows, lift x86 e lift ARM64 no
aparelho `PJMZAEJRX4YLFIDI`.

## 2. Evidências por endereço

| Endereço | Bytes | Instrução | Evidência |
| --- | --- | --- | --- |
| `0x011e0ee0` | `6a58` | `PUSH 0x58` | bytes iguais nos dois PEs (gerador recusa divergência) |
| `0x011e0ee2` | `68a88c5001` | `PUSH 0x01508ca8` | idem |
| `0x011e0ee7` | `e8e8020000` | `CALL 0x011e11d4` | `direct_call_target` = `0x011e11d4` |
| `0x011e0eec` | `33db` | `XOR EBX,EBX` | |
| `0x011e0eee` | `895de4` | `MOV [EBP-0x1c],EBX` | |
| `0x011e0ef1` | `895dfc` | `MOV [EBP-0x4],EBX` | |
| `0x011e0ef4` | `8d4598` | `LEA EAX,[EBP-0x68]` | |
| `0x011e0ef7` | `50` | `PUSH EAX` | |
| `0x011e0ef8` | `ff159cc23c01` | `CALL [0x013cc29c]` | IAT de referência resolve `KERNEL32.dll!GetStartupInfoA` |
| `0x011e0efe` | `c745fcfeffffff` | `MOV [EBP-0x4],0xfffffffe` | limite atual, não executado |

`__SEH_prolog4` (`0x011e11d4`–`0x011e1218`) usa o cookie em `0x015cfe70`
(operando absoluto em `0x011e11f1`) e `FS:[0]` em `0x011e11d9` / `0x011e1212`.

## 3. Shim de `GetStartupInfoA`

`BatchStaticLiftRuntime.hpp::get_startup_info`:

- lê `[ESP+4]` (argumento único, `stdcall`);
- exige `is_writable(ptr, 0x44)` antes de qualquer escrita;
- preserva o `cb` já gravado pelo chamador e zera os 16 dwords restantes
  (`lpReserved`/`lpDesktop`/`lpTitle`/`lpReserved2` = `NULL`, flags `0`,
  handles `0`);
- retorna `void` e remove 4 bytes de argumento (`complete_import_call(..., 4u)`);
- destino fora da memória guest → `invalid_memory` sem consumir o argumento.

Probe negativo no harness x86 (`startupinfo_rejects_invalid_destination`): passa
argumento `0x0000f000` (não mapeado) e exige `invalid_memory` com `ESP` e `EIP`
intactos. Roda nos dois lados (x86 lift e ARM64) e não altera a linha `PASS`.

## 4. Divergência observada (não mascarada)

`GetStartupInfoA` real devolveu, neste host:

```
cb=0x00000044 lpReserved=0x01405a80 lpDesktop=0x01404de8 lpTitle=0x01407710
flags=0x00000100 show=0x00000000 handles=0x00000a18,0x00000a00,0x00000a20
```

Isto é o que o **harness** herdou (stdout redirecionado pelo PowerShell,
`STARTF_USESTDHANDLES`), não o estado de um Spore iniciado por double-click. O
guest não tem desktop, título nem handles, e reporta `NULL`/`0`.

Contrato comparado nos três lados (o que o chamador realmente usa):

- `cb` preservado;
- `cbReserved2 == 0` e `lpReserved2 == NULL`;
- `lpReserved`, `lpDesktop`, `lpTitle` nulos **ou** legíveis — no lado Windows
  validado com `VirtualQuery` + varredura de string NUL-terminada (até 260
  bytes); no guest são `NULL`.

Os valores brutos saem na linha `DETAIL`, que não participa da comparação.

## 5. Aritmética de pilha medida

Entry `ESP = 0x70000200`:

| Etapa | Bytes | ESP |
| --- | --- | --- |
| `PUSH 0x58` | −4 | `0x1fc` |
| `PUSH 0x1508ca8` | −4 | `0x1f8` |
| `CALL __SEH_prolog4` (retorno empilhado) | −4 | `0x1f4` |
| prolog: `PUSH handler`, `PUSH FS:[0]` | −8 | `0x1ec` |
| prolog: `SUB ESP,0x58` | −88 | `0x194` |
| prolog: `PUSH EBX/ESI/EDI/EAX/[EBP-8]` | −20 | `0x180` |
| prolog: `RET` | +4 | `0x184` |
| `PUSH EAX` + `CALL` + limpeza `stdcall` | 0 líquido | `0x184` |

Valor observado nos três lados: `ESP = entry - 0x7c = 0x184` e
`EBP = entry - 4 = 0x1fc`. Instruções executadas: `1` (entrada) + `53` (cookie)
+ `9` (prefixo do CRT) + `21` (`__SEH_prolog4`) = **84**.

## 6. Mudança obrigatória no harness x86 original

`__SEH_prolog4` instala um registro de exceção do guest em `FS:[0]`. Um `INT3`
direto no limite dispararia com a cadeia corrompida e o filtro `__except` do
harness nunca rodaria (observado: `STATUS_BREAKPOINT`, `0xC0000003`).

Solução: o limite agora é `JMP rel32` para um stub `naked` que

1. captura `ESP`/`EBP`/`EAX`/`EBX`/`ECX`/`EDX`/`ESI`/`EDI`/`EFLAGS`;
2. restaura o `FS:[0]` real capturado dentro do `__try` de `execute_original`;
3. executa `INT3` para o filtro `capture_boundary`.

O stub também é usado no estágio `seh-call-boundary` (uniformidade); a linha
`PASS` não mudou.

## 7. Testes executados

| Teste | Resultado | Log |
| --- | --- | --- |
| Python `test_static_batch_lift` + `test_m7_effective_address_differential` | 77 OK | `crt-startupinfo-python-tests.log` |
| x86 original vs lift x86, estágio `seh-call-boundary` | PASS | `crt-seh-call-boundary-differential.log` |
| x86 original vs lift x86, estágio `startupinfo-call` | PASS | `crt-startupinfo-call-differential.log` |
| ARM64 no aparelho, ambos os estágios | PASS | `crt-{stage}-arm64.log` |
| Stress ARM64 estágio `startupinfo-call` | 20/20 | `crt-startupinfo-call-arm64-stress.log` |
| Regressão cookie/pid (`run_boot_pid_prefix_tests.ps1`) no aparelho | PASS (5 estágios) | `crt-startupinfo-cookie-regression.log` |

O runner agora reprova qualquer linha de saída fora de `PASS`/`DETAIL` nos três
lados, então o abort `*** stack smashing detected ***` observado antes seria
detectado como falha.

## 8. Bloqueios restantes

**Próximo blocker:** `0x011e0f1e` `CALL [0x013cc194]`
(`KERNEL32.dll!InterlockedCompareExchange`). Dependências imediatas:

- `0x011e0f0c` `MOV EAX,FS:[0x18]` (PEB) e `0x011e0f12` `MOV ESI,[EAX+0x4]`
  → exige PEB de guest coerente;
- global de lock em `0x0171e750` (`__native_startup_lock`) e
  `0x0171e74c` (`__native_startup_state`), lidas/escritas em `0x011e0f43` e
  `0x011e0f5f` → exigem região de dados mapeada;
- `0x011e0f38` `CALL [0x013cc284]` (`KERNEL32.dll!Sleep`) no laço de espera;
- `0x011e0f4e` `CALL 0x011e1368` (`__FF_MSGBANNER`/`_NMSG_WRITE` family) e
  `0x011e0f6f` `CALL 0x011e1514`.

Nada disso foi implementado. Não há evidência de boot, inicialização de
subsistemas, menu ou gameplay; o APK não chama a entrada do PE.

## 9. Arquivos modificados

- `tools/batch_static_lift/BatchStaticLiftRuntime.hpp` — shim
  `GetStartupInfoA`, struct `GuestStartupInfoA` com `static_assert` de `0x44`,
  dispatch e `import_argument_count == 1`.
- `tools/batch_static_lift/generate_boot_crt_prefix.py` — dois estágios,
  validação de continuidade do prefixo, emissão de `spore_011e0ee0.cpp`,
  `spore_011e11d4.cpp` e `crt_reference_bytes.hpp` (bytes, contagens,
  estágio).
- `tools/batch_static_lift/boot_entry_crt_harness.cpp` — harness do lift com
  TEB de guest, seed de `cb`, contrato do `STARTUPINFOA` e probe negativo.
- `tools/batch_static_lift/boot_entry_crt_original_x86.cpp` — stub de captura
  com restauração de `FS:[0]`, thunk de `GetStartupInfoA`, validação de
  ponteiros legíveis.
- `tools/run_boot_crt_entry_tests.ps1` — loop de estágios, build x86/ARM64,
  comparação estrita, execução no aparelho.
- `tools/batch_static_lift/test_static_batch_lift.py` — constantes/estágios do
  gerador do CRT e validação de continuidade (75 → 77 testes).
- `README.md` — seção `__SEH_prolog4` executado e `GetStartupInfoA`
  implementado.

Nenhum commit ou push foi feito.
