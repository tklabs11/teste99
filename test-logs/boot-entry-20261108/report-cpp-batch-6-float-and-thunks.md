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

## 9. O muro: `0x00404624`, e o que ele não era

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
0x011e073e  ← o que os relatórios 5 e 6 chamaram de "preenchimento de memória"
0x00401714 → 0x00401899 → 0x00401923 → 0x00401953 → 0x00402385
         → 0x00402414 → 0x004029e6 → 0x00402b23 → 0x00403694
         → 0x004036d4 → 0x00403a95 → 0x004044f4 → 0x00404624
```

A instrução que falhava:

```
0x00404624: 66 8b 8a 00 00 00 00   MOV CX, word ptr [EDX]
             estado: eax=0x1298f7fc  edx=0x018d1a00     (EDX fora de toda seção)
```

Os corpos do fim da cadeia têm todos a mesma forma: uma instrução, `JMP rel32`,
e `CC` de enchimento — `XOR EAX,EAX; JMP`, `ADD EDX,0x014d02e7; JMP`,
`ADD EAX,0x1298f7fc; JMP`, `MOV CX,[EDX]; JMP`. Ghidra confirma que cada um é
entrada de função própria (`function_at == function_containing`), então são
fragmentos de thunk reais, não desalinhamento.

**Este passo corrige a leitura do passo 5 e do passo 6.** `0x011e073e` **não** é
preenchimento de memória: é o **stub de proteção**, já medido no Marco 7 e
registrado no README. Evidência anterior, reaproveitada em vez de re-derivada:

- a cadeia de saltos resolve `KERNEL32.dll!VirtualAlloc` no slot `0x013cc1c8` e
  pede **`0xbfa43` bytes com flags `0x3000` e proteção `0x40`** — que é
  exatamente o `PUSH 0xbfa43` em `0x004029e6` seguido do `PUSH 0` / `CALL [EAX]`
  em `0x00402b23`;
- a execução dos bytes originais em Unicorn (com `VirtualAlloc` como fixture)
  alocou, **entrou no bloco gerado** e rodou **1 892 408 instruções** até parar
  em `0x3005ed82` (`mov eax, dword ptr fs:[0x30]`), que exige um ambiente de
  processo Windows — **o thunk não retornou**;
- o harness nativo não conseguiu mapear a PE em `0x00400000` porque o Windows já
  ocupava o intervalo; com realocação o `JMP` relativo de `0x011e073e` muda e
  falta antes do corpo.

Ou seja: a cadeia que o walk executava era o stub **descriptografando o próprio
payload** dentro de um bloco RWX de ~750 KiB. Executá-la dentro do walk de
inicializadores C++ seria um subsistema pela metade — e foi por isso que ela
terminou em falta em `0x00404624` (`EDX` era um *bias* que só a entrada do stub
estabelece).

## 10. A fronteira declarada, e a decisão de neutralizar

Em vez de tratamento especial para "fazer passar", o gerador ganhou
`--stop-body`: um endereço declarado na linha de comando que o lote **nunca**
levanta. Ao ser alcançado, ele entra em `engine_blockers`, o chamador despacha e
o walk para ali nomeando o endereço.

Sobre essa fronteira foi tomada a **decisão formal de neutralizar** o stub,
registrada em
[report.md do Marco 7](marco7-00921260/report.md#neutralização-formal-de-0x011e073e-stub-de-proteção):
os bytes do stub continuam fora do lote, e o harness fornece uma substituição que
honra **apenas** o contrato que o chamador pode observar, medido nos bytes do
callsite — `f(dest, 0, 0x400)` `__cdecl` com limpeza `ADD ESP,0xC` no chamador e
`EAX` descartado. Nenhum bloco RWX, nenhuma descriptografia, nenhum ponteiro
publicado; o payload nunca é mapeado, então qualquer transferência posterior para
dentro dele falha fechado nomeando o endereço. Cada chamada entra na trilha
ordenada como `NEUTRALIZED:011e073e protection-stub-fill`.

O registro separa explicitamente o que foi observado do que foi assumido: não há
execução nativa do stub em Windows (o harness nativo não conseguiu mapear a PE em
`0x00400000`), só emulação com fixture.

Efeito medido:

| | antes | depois |
| --- | --- | --- |
| corpos do lote | 120 | **47** |
| instruções | 7 087 | **1 620** |
| imports | 41 | **29** |
| pendentes | 34 | **1** |
| parada do walk | *falha* em `0x00404624` | **inicializador #8**, `0x01300210` |

A trilha de corpos confirma: os 32 últimos corpos são
`… → 0x00f47480 → 0x00927860`, e o sétimo inicializador **completa**. O walk
segue e para no oitavo inicializador da tabela, que simplesmente não está
registrado no lote — fronteira de lote, não falha de subsistema.

## 11. Estado entregue

```
PASS crt_entry            stop=0x011e0ee7 executed=56  imports=5
PASS crt_startupinfo      stop=0x011e0efe executed=84  imports=6
PASS crt_interlocked      stop=0x011e0f24 executed=93  imports=7
PASS crt_startup_lock     stop=0x011e0f43 executed=88  imports=7
PASS crt_initterm_call    stop=0x011e0f6f executed=97  imports=7
PASS crt_initterm_executed stop=0x011e0f85 executed=102 imports=14 initializers=3/3
PASS crt_startup_state_initializing stop=0x011e0f98 executed=107 imports=14
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x01300210 executed=107
     imports=52 initializers=7 walk=stopped_at_0x01300210 sections=4 tls=2
     guard=single_instance node=0x5e000010 count=3 mutex=SingleMgrMutex00001234
     neutralized=0x011e073e/1024/2/0 buf=0x5e000088
PASS arm64_build 8/8 · PASS x86_vs_arm64 8/8 · PASS arm64_device_run 8/8 (PJMZAEJRX4YLFIDI)
101 testes Python OK
```

`failed_at` é o endereço que o walk exigiu e o lote não tem; `stop` é onde o
prefixo parou antes do walk. `neutralized=` reporta endereço, tamanho do
preenchimento, número de chamadas e quantas saíram do contrato.

## 12. Próximo passo

1. Registrar o oitavo inicializador (`0x01300210`) no lote — é a nova fronteira,
   agora de lote e não de subsistema.
2. Fechar as formas que limitam o lote acima de 310 corpos: `MOVSD.REP`/`MOVSD`
   com `ES:EDI`/`DS:ESI` e `ADC`/`SBB` com carry.
3. Re-medir `0x00407280`, `0x00441440` e `0x004c73f0`, que continuam truncados.

## 13. Arquivos

Modificados: `tools/batch_static_lift/BatchStaticLift.py` (despacho de cauda,
formas x87/SSE/inteiras, `xmmword`), `BatchStaticLiftRuntime.hpp` (modelo x87 com
TOP/status, 27 shims, arena virtual, trilha de corpos, registro de neutralizados),
`boot_entry_crt_harness.cpp` (trilha de corpos, contrato do stub neutralizado,
asserções de seção e guarda), `generate_initterm_guest_image.py` (IAT inteira,
4 janelas, página nula), `generate_cpp_initializer_batch.py` (`--stop-body`),
`test_static_batch_lift.py` (101 testes),
`tools/run_boot_crt_entry_tests.ps1` (lote de 7, arquivo de resposta, fronteira
declarada).

Evidências: `crt-cpp-walk-initializers-lift-x86.log` (trilha completa de corpos e
de imports, incluindo `NEUTRALIZED:`), `run-batch-8-neutralized.log`,
`cpp-batch-generation.log`, e o registro formal em
`marco7-00921260/report.md`.

