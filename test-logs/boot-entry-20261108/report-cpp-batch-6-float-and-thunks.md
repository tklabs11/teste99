# Marco 6 — sexto passo: lifter de float, despacho de cauda e o muro do sétimo inicializador (2026-11-09)

Continuação de `report-cpp-batch-5-boundaries-and-tables.md`. O conjunto de
formas que a biblioteca de float da CRT pedia foi implementado, e com ele o lote
do construtor pôde crescer até atravessar o **sétimo inicializador C++** — que
abre o subsistema de objetos do motor. O walk avança, executa código real de
engine e agora para num endereço concreto, com a cadeia que o levou até lá
registrada como evidência.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. Despacho de cauda no lift

Um `JMP` que sai do corpo e um `JMP [IAT]` no fim de um corpo agora entram pelo
mesmo despachante que o `CALL`, em vez de exigirem que o alvo já esteja
levantado:

- alvo levantado → chamada direta (`state.eip` = alvo, retorno pelo corpo);
- alvo fora do lote → `invoke_guest_tail_call`, que **falha fechado nomeando o
  endereço**. Como um salto de cauda não empilha retorno, o corpo chamado
  retorna direto para o chamador de quem saltou;
- `JMP [IAT]` → `batch_guest_import_tail_call32`: o import lê o retorno que já
  está na pilha e o corpo termina com o status dele.

Sem isso, um lote grande morria na geração (`tail jump target ... is not in the
exported function set`), porque corpos de engine são alcançados por cauda e não
por `CALL`.

## 2. Dois bugs encontrados pelo caminho

**Temporários não declarados.** O regex que declara os temporários no topo de
cada corpo só reconhecia `t<N>`, `t<N>a/b/c/r`. O alvo de um `CALL [mem]` usa
`t<N>t` e ficava sem declaração — erro de compilação `C2065` em 8 corpos. Agora
o padrão inclui `t`.

**`InitializeCriticalSection` não registrava a seção.** A sobrecarga usada pelo
despacho de import escrevia o layout x86 na memória do guest e **não** inseria a
seção no registro; `EnterCriticalSection` exige o registro e falhava com
"called before initialization". Nenhum estágio anterior chamava `Enter`, então o
defeito estava latente desde que a sobrecarga foi escrita. Foi o primeiro
`Enter` do código de engine que o expôs. As duas sobrecargas agora passam por um
único caminho que registra.

## 3. Modelo x87

A pilha virou um banco de oito registradores endereçado por `TOP`, e não mais uma
pilha linear sem nomes — sem isso `FXCH`, `FADDP ST(i),ST(0)` e `FNSTSW` não
teriam semântica.

| grupo | formas |
| --- | --- |
| carga | `FLD m32`, `FLD m64`, `FLD ST(i)`, `FLD1`, `FLDZ`, `FILD m32`, `FILD m64` |
| depósito | `FST m32`, `FSTP m32`, `FSTP m64`, `FSTP ST(i)`, `FISTP m64` |
| aritmética | `FADD/FSUB/FMUL/FDIV/FSUBR/FDIVR` com memória de 32 bits e com registradores; formas `…P` com e sem operandos explícitos |
| unárias | `FABS`, `FCHS`, `FSQRT` |
| comparação | `FCOM`, `FCOMP`, `FCOMPP`, `FUCOMPP`, `FCOMI`, `FCOMIP`, `FUCOMIP`, com C0–C3 no status e, nas formas `FCOMI*`, C3/C2/C0 copiados para ZF/PF/CF |
| estado | `FNSTSW AX` (status + `TOP << 11`) |

Limites declarados, não escondidos:

- os valores são guardados como `double`. A closure medida **não** usa `tbyte`
  (nenhum `FLD m80`), então a precisão estendida de 80 bits do x87 não é
  necessária em nenhum caminho levantado;
- `FILD`/`FISTP` de 64 bits arredondam para o `double` mais próximo acima de 53
  bits — é o único ponto onde este modelo diverge do hardware, e está anotado no
  código;
- as flags de exceção do x87 não são modeladas porque a palavra de controle
  (`0x027f`) deixa todas mascaradas.

## 4. Formas SSE escalares e inteiras

`ADDSS/SUBSS/MULSS/DIVSS` (registrador ou memória de 32 bits, aritmética em
`float`, como o hardware — alargar para `double` arredondaria diferente),
`COMISS/UCOMISS` com memória, `MOVSS` com memória indexada, `MOVAPS`,
`XORPS xmm, mem128` (a largura `xmmword` passou a ser reconhecida pelos
analisadores de operando), `CVTTSS2SI r32, xmm`, `CVTSI2SS xmm, mem32`, `LAHF`,
e memória indexada em `MOVZX`/`MOVSX`.

## 5. Shims novos (15)

`GetCurrentThread`, `GetThreadPriority`, `GetSystemInfo`, `InterlockedDecrement`,
`DuplicateHandle`, `SleepEx`, `TlsSetValue`, `VirtualAlloc`, `VirtualFree`,
`VirtualQuery`, `InitializeCriticalSectionAndSpinCount`, `memcpy`/`memmove`,
`_stricmp`, `isalpha`.

`VirtualAlloc` separa **reserva** de **commit**: a reserva só cobra espaço na
arena (`0x5d000000`, 4 MiB) e um commit mapeia as páginas de 4 KiB do pool de
256 KiB. Sem isso, o primeiro `VirtualAlloc(MEM_RESERVE)` do engine devolvia 0 e
o caminho parava ali.

## 6. Imagem do guest

- a IAT inteira (`0x013cc000`, 0x800) passou a ser mapeada e reescrita pelo
  fixup do loader, porque o lote lê como dado qualquer slot que o ligador
  resolveria;
- quatro janelas novas em `.data`, todas provadas como zero pelo loader:
  `0x015fd8c4`, `0x01600508`, `0x01668ec0`, `0x016c8b40..4c`;
- **a página nula continua não mapeada de propósito**: o processo real também
  falha ali, então um caminho que a leia é um caminho errado e deve parar;
- resultado: 20 regiões, 4 512 bytes, 11 copiadas da PE e 9 zeradas.

## 7. Orquestrador

O lote passou a sair de `cpp-batch-2/closure-union.json` com 7 inicializadores,
sementes explícitas do construtor (`0x0138e640`, `0x00f474d0`, `0x00f47480`,
`0x00927860`, `0x00935c80`, `0x00f47430`) e
`--follow-outside --bodies 120 --allow-unresolved`. Os chamadores que ficam fora
do orçamento viram a fronteira do walk: o harness aceita parada no próximo
inicializador **ou** num corpo pendente declarado em `kBatchPendingBodies`.

A lista de fontes passou a viajar em arquivo de resposta (`@arquivo.rsp`): com
120 corpos o comando estourava o limite de 8 192 caracteres do `cmd.exe`
(`Linha de comando muito longa`).

## 8. Medições

| o que | resultado |
| --- | --- |
| lote limpo a partir do construtor (`--bodies`) | **310 corpos**; em 320 falham `MOVSD.REP` com `ES:EDI` e `ADC` |
| lote publicado | **7 inicializadores, 120 corpos, 7 087 instruções, 41 imports, 34 pendentes** |
| imports executados pelo walk | **44** (era 24 com 6 inicializadores) |
| testes Python | **99** (eram 95) |

## 9. O muro: `0x00404624`

O harness ganhou uma **trilha de corpos**: cada corpo levantado registra o próprio
endereço num anel limitado, e o detalhe imprime os 32 últimos. Isso transformou
"onde parou" em evidência. A cadeia da parada:

```
0x0138e640  inicializador #7
0x00f474d0  registro do subsistema
0x00935c80  despacho
0x00935b70  guarda de instância única (reentrada)
0x00f47480  fábrica
0x00927860  construtor do objeto
0x011e073e  preenchimento de memória
0x00401714 → 0x00401899 → 0x00401923 → 0x00401953 → 0x00402385
         → 0x00402414 → 0x004029e6 → 0x00402b23 → 0x00403694
         → 0x004036d4 → 0x00403a95 → 0x004044f4 → 0x00404624
```

A instrução que falha:

```
0x00404624: 66 8b 8a 00 00 00 00   MOV CX, word ptr [EDX]
             estado: eax=0x1298f7fc  edx=0x018d1a00     (EDX fora de toda seção)
```

Os corpos do fim da cadeia têm todos a mesma forma: uma instrução, `JMP rel32`,
e `CC` de enchimento — `XOR EAX,EAX; JMP`, `ADD EDX,0x014d02e7; JMP`,
`ADD EAX,0x1298f7fc; JMP`, `MOV CX,[EDX]; JMP`. São **fragmentos de thunk** que o
ligador separou, e o efeito composto que o guest executa é inconsistente:

- `0x00403a95` zera EAX e `0x004044f4` soma `0x1298f7fc`, então EAX termina em
  `0x1298f7fc`, que **não pertence a nenhum módulo** desta imagem;
- `0x00403694` toma EDX de `[ESP+0x10]` e `0x004036d4` soma `0x014d02e7`, um
  valor que cai dentro de `.rdata` — coerente como *bias* de ponteiro, incoerente
  como ajuste de argumento vindo da pilha.

Como o efeito composto não pode ser o do código real, **entrar em `0x00402b23`
pelo salto de cauda de `0x004029e6` não é o caminho verdadeiro**: a cabeça real
desses thunks tem de ser medida, não inferida. Não foi implementado nenhum
tratamento especial para "fazer passar" esse trecho.

Verificações feitas para descartar hipóteses fáceis: o cabeçalho da PE **não**
tem seção ILT nem flags de ligação incremental (`characteristics 0x0102`,
`.text` 0x60000020), e as 7 seções são as esperadas — logo não é um artefato de
`/INCREMENTAL` visível no cabeçalho.

## 10. Estado entregue

```
PASS crt_entry            stop=0x011e0ee7 executed=56  imports=5
PASS crt_startupinfo      stop=0x011e0efe executed=84  imports=6
PASS crt_interlocked      stop=0x011e0f24 executed=93  imports=7
PASS crt_startup_lock     stop=0x011e0f43 executed=88  imports=7
PASS crt_initterm_call    stop=0x011e0f6f executed=97  imports=7
PASS crt_initterm_executed stop=0x011e0f85 executed=102 imports=14 initializers=3/3
PASS crt_startup_state_initializing stop=0x011e0f98 executed=107 imports=14
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00404624 executed=107
     imports=44 initializers=7 sections=3 tls=2
     guard=single_instance node=0x5e000010 count=2 mutex=SingleMgrMutex00001234
PASS arm64_build 8/8 · PASS x86_vs_arm64 8/8 · PASS arm64_device_run 8/8 (PJMZAEJRX4YLFIDI)
99 testes Python OK
```

`failed_at` é o endereço da instrução que não pôde ser executada; `stop` é onde o
prefixo parou antes do walk. O guarda de instância única continua verificado: nó
em `0x5e000010`, contador ≥ 1 e mutex `SingleMgrMutex00001234`.

## 11. Próximo passo

1. Medir a **cabeça** dos thunks de `0x004029e6..0x00404651` a partir do
   chamador real, com a trilha de corpos ligada, para decidir se a cadeia é
   alcançável por projeto ou se a medição criou entradas que não existem.
2. Fechar as formas que limitam o lote acima de 310 corpos: `MOVSD.REP`/`MOVSD`
   com `ES:EDI`/`DS:ESI` e `ADC`/`SBB` com carry.
3. Re-medir `0x00407280`, `0x00441440` e `0x004c73f0`, que continuam truncados.

## 12. Arquivos

Modificados: `tools/batch_static_lift/BatchStaticLift.py` (despacho de cauda,
formas x87/SSE/inteiras, `xmmword`), `BatchStaticLiftRuntime.hpp` (modelo x87 com
TOP/status, 27 shims, arena virtual, trilha de corpos),
`boot_entry_crt_harness.cpp` (trilha de corpos, asserções de seção e guarda),
`generate_initterm_guest_image.py` (IAT inteira, 4 janelas, página nula),
`generate_cpp_initializer_batch.py`, `test_static_batch_lift.py` (99 testes),
`tools/run_boot_crt_entry_tests.ps1` (lote 7, arquivo de resposta).

Evidências: `crt-cpp-walk-initializers-lift-x86.log` (trilha completa de corpos e
de imports), `run-cpp-walk-device.log`, `cpp-batch-generation.log`.
