# Auditoria do boot nativo — 2026-11-08

## Estado e achado

O PE local `SporeApp.exe` foi conferido com SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.
A entrada real é RVA `0x00de11a0`, VA `0x011e11a0`. Os dez bytes
`e8 a3 03 00 00 e9 36 fd ff ff` são `CALL 0x011e1548` em
`0x011e11a0` e `JMP 0x011e0ee0` em `0x011e11a5`; ver
[bytes da entrada](entry-bytes.json).
Os arquivos históricos `tools/sporeapp-entry-probe.json` e
`tools/focused-entry-regions.json` registram outro SHA-256
(`290703b3...`); por isso os bytes e contagens deste relatório foram
recalculados contra o PE verificado, sem reutilizar aqueles hashes antigos.

O export do Ghidra marca o `JMP` como fluxo `CALL_TERMINATOR` porque termina
o procedimento e aponta para o CRT. O diagnóstico anterior tratava qualquer
fluxo cujo nome contivesse `CALL` como uma chamada indireta. Assim, a closure
iniciada na entrada parava em apenas duas funções. A correção separa um `CALL`
de um `JMP` terminal e exige concordância entre operando imediato, destino
de fluxo e referência exportada. A nova
[closure estática](entry-closure.json) alcança **606 funções exportadas** por
`CALL` direto e 13 `JMP` terminais. O caminho até o inicializador é
`0x011e11a0 → 0x011e0ee0 → 0x00f48a20 → 0x00f48850 → 0x00f47ed0`;
o primeiro arco é `JMP`, os seguintes são `CALL`. A medição independente
[a partir do CRT](crt-closure.json) alcançou 593 funções antes dessa correção.
São diagnósticos estáticos, não instruções executadas no Android.

O cookie em `0x015cfe70` tem os bytes iniciais `4e e6 40 bb`, ou seja,
`0xbb40e64e`. A comparação em `0x011e1569` e o salto em `0x011e156b`
levam, com esse valor inicial, ao braço de inicialização em `0x011e157a`.
Esse braço chama primeiro `KERNEL32.dll!GetSystemTimeAsFileTime` em
`0x011e157f` via IAT `0x013cc1cc`; seguem `GetCurrentProcessId`
(`0x011e158b`), `GetCurrentThreadId` (`0x011e1593`), `GetTickCount`
(`0x011e159b`) e `QueryPerformanceCounter` (`0x011e15a7`). Isto descreve
o fluxo com a imagem inicial do PE; não substitui uma captura de execução
real com o loader do Windows.

## Limite para execução

O tradutor agora suporta o `JMP` direto terminal de
`0x011e11a5 → 0x011e0ee0`, sem empilhar outro endereço de retorno e sem
modificar flags. Os corpos originais do cookie e do CRT ainda não foram
executados pelo lift. Também faltam as cinco chamadas de API acima,
o estado de loader/CRT e os demais imports e chamadas indiretas posteriores.
A closure medida tem 501 callsites indiretos, dois corpos internos ausentes
dos exports (`0x0081d470`, `0x011e073e`) e 564 registros de instruções
rejeitadas; essas contagens não indicam quais ramos serão tomados.
Em `0x00f47ed9`, `FUN_00f47ed0` chama o thunk de
`steam_api.dll!SteamAPI_Init` em `0x006b4f20`; seu retorno real ainda não
foi observado. Não foi criado substituto para ele.

No aparelho `PJMZAEJRX4YLFIDI`, o pacote debug
`dev.sporeport.cellstage.dev` abriu a tela **Spore ARM64 — validação da
instalação**; a [hierarquia da interface](apk-ui.xml) mostra o botão Marco 7
rotulado como `fixture`. Na primeira observação a tela mostrou “Pasta
configurada, aguardando importação completa”. A inspeção posterior mostrou
que o EXE estava copiado no caminho correto, mas seu hash era diferente do
PE de referência; veja a [comparação entre versões](imported-exe-comparison.md)
e a [mensagem corrigida no aparelho](apk-import-diagnostic-ui.xml). A fonte da `MainActivity` contém métodos de
compatibilidade sem botão de lançamento conectado e a biblioteca JNI usa
apenas a fixture antiga de cinco funções. Nenhum caminho do APK chama a
entrada `0x011e11a0`. Não houve menu, boot ou renderização do jogo.

Na continuação, a [verificação byte a byte da closure](current-pe-closure-comparison.json)
achou zero diferenças em 42.996 instruções exportadas entre a referência e
o EXE atual do usuário. O hash desta variante foi aceito para as sondas
nativas existentes. O [teste Marco 1 no aparelho](apk-current-variant-marco1-ui.xml)
passou com `FUN_00461520` recompilada em ARM64 e 91/91 buscas verificadas.
Este resultado não amplia o prefixo do construtor nem executa a entrada do PE.

## Primeiros bytes reais da entrada: CALL e JMP terminal

O [gerador delimitado](../../tools/batch_static_lift/generate_boot_entry_tail.py)
validou os dez bytes da entrada em **ambos** os PEs e gerou
[`spore_lift_011e11a0`](generated-entry-tail/spore_011e11a0.cpp), com
[manifesto](generated-entry-tail/manifest.json). A função traduzida executa
`0x011e11a0: CALL 0x011e1548` e, após o retorno, `0x011e11a5: JMP
0x011e0ee0`. **Os dois destinos são stubs do harness**, não os corpos
originais do cookie e do CRT.

Um harness Windows x86 mapeou os dez bytes originais nos endereços PE e
substituiu somente esses dois destinos por stubs `MOV marcador,1; RET`, que
preservam flags. [Execução dos bytes originais](entry-original-x86.log),
[lift x86](entry-tail-x86.log) e [lift ARM64 no aparelho](entry-tail-arm64-device.log)
passaram: os dois destinos foram visitados, os flags comparáveis foram
preservados e o salto ao CRT não adicionou uma palavra à pilha. O lift também
rejeitou um retorno de cookie alterado e propagou a parada no CRT com
`EIP=0x011e0ee0`. O último byte original executado nessa prova é
**`0x011e11a9`**, o fim do `JMP`. Essa comparação valida somente a semântica
do CALL/JMP da entrada sob stubs controlados; não é boot nem execução do
cookie ou CRT originais.
A [conferência das propriedades nos três logs](entry-tail-differential.log)
passou.

Reprodução: gerar com `python tools/batch_static_lift/generate_boot_entry_tail.py
--reference <PE de referência> --candidate <PE atual> --batch
C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0086.json --output
test-logs/boot-entry-20261108/generated-entry-tail`; compilar e executar
com [script x86 original](build-entry-original-x86.cmd),
[script lift x86](build-entry-tail-x86.cmd) e
[script ARM64/ADB](run-entry-tail-arm64.ps1); após os dois builds Windows,
executar `entry_original_verified_x86.exe` e `entry_tail_lift_x86.exe` na
pasta do relatório. Os [builds x86 original](entry-original-x86-build.log),
[lift x86](entry-tail-x86-build.log) e [ARM64](entry-tail-arm64-build.log)
passaram.

## Execução e regressões

- `python -m unittest discover -s tools/batch_static_lift -p test_static_batch_lift.py -v`: [**60 testes passaram**](tail-jump-python-tests.log); os testes novos verificam o destino do `JMP` terminal, sua chamada sem empilhar retorno e a rejeição de destino ausente ou inconsistente.
- `python tools/batch_static_lift/diagnose_call_closure.py --exe <PE verificado> --batch-dir C:\SporeAnalysis\spore_batch_all_parts --root 0x011e11a0 --report test-logs/boot-entry-20261108/entry-closure.json`: **606 funções, 13 saltos terminais**, sem geração de código.
- O binário ARM64 v42 já existente foi enviado e executado via `C:\platform-tools\adb.exe`. O [log do aparelho](v42-android-rerun.log) registra `PASS lifted_arm64 stop=0x00a23817`. A [comparação](v42-differential-rerun.log) com o log x86 original e lift x86 passou para registradores comparáveis, flags, pilha e objeto da fixture. EDX volátil permanece excluído da igualdade. Esse binário independente usa estado artificial do harness e **não é o APK nem boot do jogo**.
- `git diff --check` passou. Nenhum commit ou push foi feito.

O último byte executado e comparado no prefixo do construtor continua sendo
**`0x00a23816`**, antes de `0x00a23817 → FUN_00a221b0` sob a fixture v42.
O primeiro bloqueio de execução **original** do boot permanece em
`0x011e1548` (`___security_init_cookie`): o harness da entrada retorna
imediatamente desse destino, enquanto o corpo real segue até a primeira
chamada de API em `0x011e157f`. O salto ao CRT já tem semântica de lift
testada, mas o CRT real em `0x011e0ee0` e o estado de loader/imports ainda
faltam. A versão importada foi liberada para as sondas delimitadas, não para
boot. Nenhum código da entrada foi ligado ao APK.

Arquivos de código alterados nesta auditoria:
`tools/batch_static_lift/BatchStaticLift.py`,
`tools/batch_static_lift/diagnose_call_closure.py`,
`tools/batch_static_lift/compare_pe_closure.py`,
`tools/batch_static_lift/generate_boot_entry_tail.py`,
`tools/batch_static_lift/boot_entry_tail_harness.cpp`,
`tools/batch_static_lift/boot_entry_original_x86.cpp`,
`tools/batch_static_lift/test_static_batch_lift.py` e
`app/src/main/java/dev/sporeport/cellstage/MainActivity.java`.
O repositório permaneceu em `main` no HEAD
`4a889b95238046b83b5737797a29cc0154d96115`, com alterações locais
anteriores preservadas.

## Continuação: da entrada real até a primeira chamada Win32

O [gerador do cookie](../../tools/batch_static_lift/generate_boot_cookie_prefix.py)
verificou os 53 registros de `___security_init_cookie` (`0x011e1548`)
contra os dois PEs e conferiu os oito bytes `.data` em `0x015cfe70`:
`4e e6 40 bb b1 19 bf 44`. O [manifesto](generated-cookie-prefix/manifest.json)
e os [bytes gerados](generated-cookie-prefix/cookie_reference_bytes.hpp)
delimitam o prefixo em **`0x011e157f`**, antes de
`CALL dword ptr [0x013cc1cc]` (`KERNEL32.dll!GetSystemTimeAsFileTime`).
O [lift gerado](generated-cookie-prefix/spore_011e1548_prefix.cpp) traduz
21 registros anteriores à chamada; sob o valor inicial do PE, o `JZ` em
`0x011e156b` vai a `0x011e157a`, de modo que **16 instruções do cookie**
são executadas. O `JMP` do ramo alternativo em `0x011e1578` é guardado
como dependência não suportada; sua semântica posterior não foi assumida.

O [harness Windows x86](../../tools/batch_static_lift/boot_cookie_original_x86.cpp)
executou bytes extraídos do PE, realocados para memória executável. Somente
os operandos absolutos de dados em `0x011e1550` e `0x011e1573` foram
ajustados para a cópia local dos oito bytes `.data`; o primeiro byte da
chamada em `0x011e157f` foi substituído por `INT3` para capturar o estado
**antes** da API. Nenhum retorno de Win32 foi modelado. A tentativa inicial
de reservar os endereços absolutos do PE no processo Windows falhou; a
realocação delimitada resolveu esse impedimento sem alterar os bytes de
decisão nem os saltos relativos executados.

Os testes isolados de `___security_init_cookie` passaram em
[x86 original realocado](cookie-original-x86.log),
[lift x86](cookie-prefix-x86.log) e
[ARM64 no aparelho](cookie-prefix-arm64-device.log). A prova composta
iniciou em **`0x011e11a0`**, executou seu `CALL 0x011e1548` e as 16
instruções do cookie, parando antes da API. A
[comparação tripla](boot-entry-prefix-differential.log) passou para os
registradores normalizados, flags `0x044` (máscara `0x8d5`), pilha,
locais zerados e dados do PE sem alteração. O último byte executado da
função cookie foi **`0x011e157e`**; `0x011e157f` não foi executado. O
`JMP` da entrada em `0x011e11a5` também não é executado nesta prova
composta, pois o cookie ainda não retornou. Uma fixture **artificial** com
cookie inicial `0x12345678` confirmou, apenas nos lifts x86/ARM64, que
o ramo alternativo para na guarda `0x011e1578`.

Reprodução: gerar com `python tools/batch_static_lift/generate_boot_cookie_prefix.py
--reference <PE de referência> --candidate <PE atual> --batch
C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0086.json --output
test-logs/boot-entry-20261108/generated-cookie-prefix`; compilar com
[original x86](build-boot-entry-prefix-original-x86.cmd) e
[lift x86](build-boot-entry-prefix-lift-x86.cmd), executar os respectivos
`.exe` da pasta do relatório e rodar
`./test-logs/boot-entry-20261108/run-cookie-prefix-arm64.ps1 -EntryChain
-DeviceSerial PJMZAEJRX4YLFIDI`. Os
[builds x86 original](boot-entry-prefix-original-x86-build.log),
[lift x86](boot-entry-prefix-lift-x86-build.log) e
[ARM64](boot-entry-prefix-arm64-build.log) passaram.

**Próximo bloqueio:** a primeira chamada original do cookie em
`0x011e157f → KERNEL32.dll!GetSystemTimeAsFileTime`. Será necessário
validar a semântica de escrita do `FILETIME`, efeitos no estado e os imports
seguintes antes de retornar ao CRT. A chamada não foi executada ou
substituída nesta prova. O APK continua sem iniciar a entrada do PE; as
execuções ARM64 acima são binários independentes via ADB. Não houve boot,
menu nem renderização. Nenhum commit ou push foi feito.

## Referência externa: Skyrim_Android

A leitura de [runtime/main.c](https://github.com/ttom795/Skyrim_Android/blob/main/runtime/main.c)
mostra uma ponte que carrega as seções PE, aplica relocations, resolve a IAT
e chama a entrada recompilada. Em
[runtime/shims.c](https://github.com/ttom795/Skyrim_Android/blob/main/runtime/shims.c),
imports sem implementação são identificados e falham quando chamados. Isso
aponta para um próximo passo concreto no Spore: conectar a entrada ao APK
com um loader e uma ponte de imports observáveis, depois de validar cada
chamada necessária. A implementação de
[`GetSystemTimeAsFileTime`](https://github.com/ttom795/Skyrim_Android/blob/main/runtime/kernel32.c)
naquela referência converte o relógio Unix para `FILETIME` e grava oito
bytes no ponteiro recebido. É uma referência de desenho, não uma prova da
semântica da chamada no Spore; seu valor depende do relógio real, e nenhuma
resposta foi inventada para avançar o prefixo atual.

## Continuação: primeira API Win32 executada

O [gerador](../../tools/batch_static_lift/generate_boot_cookie_prefix.py)
agora aceita `--include-time-call`. Ele conferiu nos dois PEs os bytes
`ff15ccc13c01` em `0x011e157f`, o slot IAT `0x013cc1cc` e seu símbolo
`KERNEL32.dll!GetSystemTimeAsFileTime`. O
[novo manifesto](generated-cookie-time-prefix/manifest.json) delimita o
prefixo em **`0x011e1585`**. A chamada é executada; o `MOV` seguinte,
em `0x011e1585`, ainda não é. O último byte executado é **`0x011e1584`**.
Sob os dados iniciais reais do PE, são 18 instruções desde `0x011e11a0`:
uma da entrada, 16 anteriores no cookie e a chamada Win32.

No [harness x86 original](../../tools/batch_static_lift/boot_cookie_time_original_x86.cpp),
os mesmos bytes PE realocados chamam a **API real do Windows** por um slot
IAT local; `INT3` captura o estado em `0x011e1585`. O
[lift x86](boot-entry-time-lift-x86.log) e o
[ARM64 no aparelho](boot-entry-time-arm64-device.log) usam a implementação
focada em [BatchStaticLiftRuntime.hpp](../../tools/batch_static_lift/BatchStaticLiftRuntime.hpp):
ela obtém o relógio real, grava oito bytes `FILETIME` na memória guest e
aplica o retorno `stdcall` com limpeza de quatro bytes de argumento.
Destinos inválidos ou não graváveis falham antes da escrita. O valor do
relógio varia entre as execuções; cada teste exige que ele caia entre duas
leituras do relógio do próprio host. A
[comparação tripla](boot-entry-time-differential.log) confere fronteira,
registradores preservados, pilha, destino escrito e dados PE inalterados.
EAX, ECX, EDX e flags após uma API `void` não têm resultado exigido pelo
contrato usado aqui e ficam fora da igualdade.

Os [testes de casos-limite](../../tools/batch_static_lift/boot_time_import_tests.cpp)
passaram em [x86](time-import-tests-x86.log) e
[ARM64 no aparelho](time-import-tests-arm64-device.log): escrita de oito
bytes em ponteiros desalinhados graváveis, ponteiros nulo e com wrap,
região somente leitura, região curta e limpeza da pilha. Passaram também
[60 testes Python](time-import-python-tests.log).
O [prefixo anterior regenerado](time-import-prior-prefix-regression.log)
produziu o mesmo arquivo C++ por SHA-256. Reproduzir com
`python tools/batch_static_lift/generate_boot_cookie_prefix.py --reference
<PE de referência> --candidate <PE atual> --batch
C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0086.json --output
test-logs/boot-entry-20261108/generated-cookie-time-prefix
--include-time-call`; os builds x86 estão em
[original](build-boot-entry-time-original-x86.cmd),
[lift](build-boot-entry-time-lift-x86.cmd) e
[testes da API](build-time-import-tests-x86.cmd). Os scripts ARM64 são
[prefixo](run-boot-entry-time-arm64.ps1) e
[casos-limite](run-time-import-tests-arm64.ps1). Nenhum valor de tempo foi
fixado para simular sucesso.

**Próximo bloqueio:** `0x011e1585 MOV ESI,[EBP-4]` e
`0x011e1588 XOR ESI,[EBP-8]`, seguidos por
`0x011e158b CALL [0x013cc114]` para `GetCurrentProcessId`. O prefixo
executado ainda depende de estado isolado do harness. O APK não chama a
entrada recompilada e não houve boot nem menu do jogo. Nenhum commit/push.
