# Marco 6 — segundo lote: a guarda de instância única (2026-11-08)

Continuação de `report-cpp-batch-1-executed.md`. O walk parava em `0x013002d0`
porque esse inicializador chama `0x00935b70`, o primeiro código de **engine** da
cadeia. Este relatório registra a execução dele.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Resultado

```
PASS crt_cpp_walk stop=0x011e0f98 executed=107 esp_delta=-136 ebp=entry-4
     cookie=consistent imports=40 initializers=6 walk=stopped_at_0x0138e640
     args=argc1,argv_guest,envp_empty sections=3 tls=2
     guard=single_instance node=0x5e000010 count=1
     mutex=SingleMgrMutex00001234 encoded=5e000010
PASS arm64_build target=aarch64-linux-android29
PASS x86_vs_arm64 <linha idêntica>
PASS arm64_device_run serial=PJMZAEJRX4YLFIDI
```

Os oito estágios continuam passando, sete com execução no aparelho. O walk foi
de 5 para **6 inicializadores** e agora para em `0x0138e640`.

## 2. O que `0x00935b70` faz

Guarda de instância única do motor, 78 instruções na medição do Ghidra:

```c
if (g_node) { InterlockedIncrement(&g_counter); return true; }      // caminho rápido
wsprintfA(nome, "SingleMgrMutex%08x", GetCurrentProcessId());
h = CreateMutexA(NULL, FALSE, nome);
if (!h) { release(); return false; }
if (WaitForSingleObject(h, INFINITE) == WAIT_FAILED) { ... }
if (GetEnvironmentVariableA(nome, buffer, 0x20) > 0 && buffer[0]) {
    g_node = _strtoui64(buffer, NULL, 16);
} else {
    g_node = node_alloc();                       // 0x00935a30
    sprintf(buffer, "%I64x", g_node);
    SetEnvironmentVariableA(nome, buffer);
}
InterlockedIncrement(&g_node->count);
ReleaseMutex(h);
CloseHandle(h);
if (!g_node) { release(); return false; }
InterlockedIncrement(&g_counter);
return true;
```

Corpos de apoio incluídos no lote (todos folhas ou quase):

| endereço | instruções | o que é |
| --- | --- | --- |
| `0x00935a30` | 20 | aloca o nó: `GetProcessHeap`, `HeapAlloc(h,0,0x37)`, alinha em 16, auto-encadeia, `InitializeCriticalSection(node+0xc)` |
| `0x00935a70` | 29 | libera: `DeleteCriticalSection`, `0x620230`, `HeapFree`, zera `g_node` |
| `0x00620230` | 13 | esvazia a lista encadeada do nó |
| `0x013002d0` | 5 | o inicializador: chama a guarda e registra o destrutor |

## 3. Ordem de chamadas observada (evidência da execução)

Os doze imports da guarda aparecem exatamente nesta ordem, e é isso que o
harness exige:

```
26 GetCurrentProcessId       -> 0x00001234
27 USER32!wsprintfA          -> 22 (strlen de "SingleMgrMutex00001234")
28 CreateMutexA(0,0,nome)
29 WaitForSingleObject(h,-1) -> WAIT_OBJECT_0
30 GetEnvironmentVariableA   -> 0 (processo novo)
31 GetProcessHeap            -> 0x00e0ff01
32 HeapAlloc(hp,0,0x37)      -> 0x5e000000
33 InitializeCriticalSection(0x5e00001c)
34 sprintf("%I64x", no)      -> "5e000010"
35 SetEnvironmentVariableA
36 ReleaseMutex(h)
37 CloseHandle(h)
```

Estado final verificado: nó em `0x5e000010` (bloco cru `0x5e000000` alinhado em
16), lista auto-encadeada (`[no] == [no+4] == no`), contador do nó `1`,
`LockCount = -1` na seção crítica, contador global da guarda `1`.

## 4. Shims novos (11)

| símbolo | modelo |
| --- | --- |
| `USER32!wsprintfA`, `MSVCR90!sprintf` | formatador estrito: `%%`, `%s`, `%c`?não, `%d/%i/%u/%x/%X/%p` e `%I64x/%I64u/%I64d`, com largura e zero-pad. Qualquer outra conversão **falha fechado** nomeando o especificador. `wsprintfA` respeita o limite de 1024 bytes |
| `MSVCR90!_strtoui64` | parse com base, `EDX:EAX` como a ABI manda, `endptr` atualizado |
| `KERNEL32!GetProcessHeap` | handle constante `0x00e0ff01` |
| `KERNEL32!HeapAlloc`/`HeapFree` | bump allocator em `0x5e000000..0x5e001000`, blocos alinhados em 16, nunca reutilizados (o endereço do nó fica estável); `HeapFree` valida o ponteiro |
| `KERNEL32!WaitForSingleObject` | guest é monothread: mutex existente é adquirido na hora, `INFINITE` não espera |
| `KERNEL32!ReleaseMutex` | só libera o que este run adquiriu, senão erro 288 |
| `KERNEL32!CloseHandle` | desfaz o nome do handle (objetos do host ficam para o teardown, nada é fechado duas vezes) |
| `KERNEL32!GetEnvironmentVariableA`/`SetEnvironmentVariableA` | ambiente do próprio guest, então o que a mesma execução gravou é lido de volta |

Strings produzidas por shim passam a ser registradas no `BatchGuestImportCall`
(campo `text`): o buffer de pilha do guest já foi reutilizado quando o teste
confere, então ler a memória depois dava lixo (`name=?`).

## 5. Image guest

16 regiões, 2 532 bytes, 23 slots de import, 22 endereços de memória e 16
immediates empilhados cobertos. Janelas novas:

| janela | tamanho | origem |
| --- | --- | --- |
| `engine_format_strings` (`0x0143e830`) | 0x20 | PE — `"%I64x"` e `"SingleMgrMutex%08x"` |
| `engine_guard_globals` (`0x01669930`) | 0x18 | BSS — nó, contador do nó e contador global |

O gerador agora recebe **todas** as fontes (closure da CRT + lote) e separa
acesso de memória (precisa de janela) de immediates empilhados (argumentos, só o
chamado decide se desreferencia).

## 6. Gerador do lote

- `--engine-body` (repetível): entrar em código de engine passa a ser decisão
  explícita na linha de comando, registrada no comando do teste.
- Saltos diretos que caem **dentro** de um corpo já traduzido são fluxo local,
  não dependência: antes apareciam como "bloqueio de engine" (`0x00620240`,
  `0x00935c2c`), agora são filtrados por `lifted_instruction_addresses`.
- O lote 2 tem 6 inicializadores, 16 corpos, 284 instruções e 22 imports;
  `engine_blockers` vazio.

## 7. Bloqueio atual

`0x0138e640` (sétimo endereço não nulo) exige o corpo `0x00f474d0`. O walk falha
fechado e nomeia o endereço:

```
error=_initterm needs a lifted body for 0x0138e640
```

## 8. Limitações registradas

- O formatador cobre as conversões usadas pelos format strings do binário; uma
  conversão nova falha com mensagem, não com string errada.
- O heap do guest é bump-only: sem reuso, sem fragmentação, sem `HeapReAlloc`.
- `CloseHandle` não fecha o handle nativo no meio do run (fica para o teardown),
  para não fechar duas vezes.
- `CreateMutexA` é nativo no Windows; o valor do handle difere entre hosts, então
  nenhum critério de teste depende dele.
- `WaitForSingleObject`/`ReleaseMutex` são modelados sobre o registro do próprio
  runtime, não sobre o mutex do kernel.
- Continua sem execução do x86 original (o walk real inicializa o processo).
- Nada disso é boot, menu, renderização ou gameplay.

## 9. Arquivos

Modificados: `BatchStaticLiftRuntime.hpp`, `boot_entry_crt_harness.cpp`,
`generate_initterm_guest_image.py`, `generate_cpp_initializer_batch.py`,
`test_static_batch_lift.py` (89 testes), `run_boot_crt_entry_tests.ps1`,
`README.md`.

Gerados: `generated-cpp-batch-1/` (16 corpos + `batch_entries.hpp`),
`generated-initterm-guest-image/`, `crt-cpp-walk-initializers-*.log`,
`run-cpp-batch-2-full.log`.
