# RETOMAR AQUI — Spore Android (recompilação estática)

> **Escrito em 2026-11-12 00:10**, antes de formatar o PC.
> Se você está lendo isto depois de formatar: comece pela seção **2** (o que
> salvar) e depois **3** (restaurar o ambiente). A seção **1** diz onde o
> trabalho parou e a **6** diz exatamente qual é o próximo comando.

---

## 0. ANTES DE FORMATAR — faça estes 3 passos

1. **Commitar e dar push deste arquivo.** Ele é a única coisa que ainda não está no
   GitHub. Sem isso, o guia de retomada morre com o disco.

   ```powershell
   cd C:\Users\wesll\AndroidStudioProjects\SporeAndroid
   git add RETOMAR-AQUI.md
   git commit -m "update 27 - guia de retomada"
   git push
   ```

2. **Copiar o arquivo que NÃO está no git** (seção 2.1) para um pendrive/Drive:

   ```powershell
   # ~26 MB no total, é o mínimo absoluto
   C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0086.json
   C:\SporeAnalysis\SporeApp.exe
   ```

   (O `SporeApp.exe` é recuperável da Steam — a hash é idêntica — mas salve junto, é
   barato. O `spore_batch_all_0086.json` **não tem substituto**.)

3. **Opcional, se o pendrive couber 1,3 GB:** copiar `C:\SporeAnalysis\SporeREA4G`
   (projeto Ghidra). Sem ele você reimporta a PE e espera ~1 a 2 h antes da próxima
   medição — mas **nenhuma medição já feita se perde**, tudo está no git.

Confirmar que o push funcionou antes de formatar:

```powershell
git fetch origin; git status -sb     # tem que dizer "## main...origin/main" sem [ahead]
```

---

## 1. Onde o trabalho parou

**768 inicializadores C++ executam até o fim, verdes nos três alvos.**

```
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x01224e20 executed=107 esp_delta=-136
     ebp=entry-4 cookie=consistent imports=5479 initializers=768 ran=768
     last_ran=0x01224dc0 walk=stopped_at_0x01224e20 args=argc1,argv_guest,envp_empty
     sections=8 tls=2 guard=single_instance node=0x5e000010 count=9
     mutex=SingleMgrMutex00001234 encoded=5e000010 neutralized=0x011e073e/244/3/0
     buf=0x01668994 n_sizes=2 fault=none@0x00000000/0 pc=0x00000000
     near=0x00000000+0x0
PASS x86_vs_arm64  (linha idêntica)   PASS arm64_device_run serial=PJMZAEJRX4YLFIDI
PASS 32   FAIL 0   SKIP 3   (8 estágios, x86 + ARM64 + aparelho)
```

O que esses campos significam:

| campo | significado |
| --- | --- |
| `initializers=768` | o lote **registra** 768 inicializadores da tabela |
| `ran=768` | **768 completaram de fato** (corpo retornou E a moldura voltou ao lugar) |
| `failed_at=0x01224e20` | onde o walk parou = o **inicializador #769** |
| `fault=none` | **não houve muro**: o lote acabou, é a fronteira declarada |
| `neutralized=0x011e073e/244/3/0` | o stub de proteção, com o contrato de sempre |
| `imports=5479` | chamadas de import feitas até aqui |

**Relação honesta: 768 de 31 266 inicializadores = 2,5%.** Sem boot, sem menu, sem
render, sem gameplay. Não exagere isso em nenhum relatório futuro.

Estado do repositório no momento deste documento: `main` = `f57fcac update 26`,
árvore limpa, **tudo enviado para <https://github.com/tklabs11/teste99>** (o repo se
chamava `spore_android` e foi renomeado para `teste99`; o nome antigo redireciona).

### O próximo degrau já está medido e cotado

A medição até o inicializador **#2048** já foi feita e unida na closure (fica no
git, não precisa refazer). O que cada degrau pede:

| inicializadores | corpos | instruções | não medidos |
| --- | --- | --- | --- |
| **768 (verde hoje)** | **1 044** | **22 509** | **0** |
| 1024 | 1 302 | 25 686 | 0 |
| 1280 | 1 558 | 28 866 | 0 |
| 1536 | 1 814 | 31 919 | 0 |
| 2048 | 2 326 | 38 219 | 0 |

Cresce exatamente **1 corpo por inicializador** — a closure auxiliar saturou, quem
cresce é a própria tabela. Ou seja: até 2048 não falta medição, falta rodar.

---

## 2. O que salvar ANTES de formatar

### 2.1 Obrigatório — e não é óbvio

| # | caminho | tamanho | por quê |
| --- | --- | --- | --- |
| 1 | `C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0086.json` | **6,4 MB** | **NÃO está no git.** O gerador do prefixo CRT abre esse arquivo (`--batch`) e o runner exige que exista. Sem ele, os 8 estágios não rodam. |
| 2 | `C:\SporeAnalysis\SporeApp.exe` | 20 MB | PE de referência. **Recuperável**: é byte a byte igual ao da Steam (`SPOREFILES\SporeBin\SporeApp.exe`, SHA-256 conferido). Salve de qualquer jeito, é barato. |
| 3 | `C:\Users\wesll\ghidra_scripts\*.java` | 100 KB | Os 4 scripts que o Ghidra executa. Já estão no repo em [tools/ghidra_scripts](./tools/ghidra_scripts) — basta copiar de volta. |

### 2.2 Desejável — evita reimportar a PE no Ghidra (estimativa: 1 a 2 h)

| # | caminho | tamanho | observação |
| --- | --- | --- | --- |
| 4 | `C:\SporeAnalysis\SporeREA4G` | **1,3 GB** | projeto Ghidra. **Não é crítico**: todas as medições já feitas estão no git (`closure.json`/`closure-union.json`). Só é necessário para medir corpos **novos**. Se perder, recria-se importando a PE. |

### 2.3 Não precisa salvar

- `C:\SporeAnalysis\runtime-r4` (1,6 GB) — Wine/box64, ignorado pelo git, re-baixável.
- `C:\SporeAnalysis\spore_batch_all.json` (792 MB) e `spore_static_lift_state.json`
  (814 MB) — artefatos de uma investigação anterior.
- Qualquer `%TEMP%\spore-*` (o build limpa sozinho).
- `build/` e `runtime-r4/` do repo — ignorados.

### 2.4 O próprio repositório

Tudo o que importa de código, ferramentas, relatórios, closures e fontes geradas
está **commitado e no GitHub** (6 816 arquivos, `main` = `origin/main`). Depois de
formatar basta:

```powershell
git clone https://github.com/tklabs11/teste99 "C:\Users\wesll\AndroidStudioProjects\SporeAndroid"
```

Confira que voltou o commit certo: `git log --oneline -1` deve mostrar `f57fcac`
(ou um `update N` mais novo que você tenha feito depois deste documento).

---

## 3. Restaurar o ambiente depois de formatar

Versões que estavam funcionando (não invente outras sem necessidade):

| ferramenta | versão / caminho |
| --- | --- |
| Git | 2.56.0 |
| Python | 3.15.2 (só stdlib — **nenhum `pip install` é necessário**) |
| Visual Studio Build Tools | 18 — `C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools` (precisa do **C++ x86**) |
| JDK | Temurin 25.0.5 (Ghidra 12.1.4 exige **21+**) |
| Ghidra | **12.1.4** — `C:\Users\wesll\Documents\ghidra_12.1.4_PUBLIC` |
| Android SDK platform-tools | `%LOCALAPPDATA%\Android\Sdk\platform-tools\adb.exe` |
| Android NDK | **29.0.14206865** — `%LOCALAPPDATA%\Android\Sdk\ndk\29.0.14206865` |
| aparelho de teste | serial **PJMZAEJRX4YLFIDI** (ARM64, USB depurado) |

Passos:

1. Instalar as ferramentas da tabela acima.
2. `git clone` do repositório (seção 2.4).
3. Copiar os scripts do Ghidra para onde o runner procura:

   ```powershell
   New-Item -ItemType Directory -Force C:\Users\wesll\ghidra_scripts
   Copy-Item <repo>\tools\ghidra_scripts\*.java C:\Users\wesll\ghidra_scripts
   ```

4. Recriar `C:\SporeAnalysis\` com o que você salvou:
   - `SporeApp.exe` (ou copiar de `...\Spore\SPOREFILES\SporeBin\SporeApp.exe`)
   - `spore_batch_all_parts\spore_batch_all_0086.json`
   - `SporeREA4G` (se salvou)
5. Conferir a hash da PE — **isto não é opcional**, os geradores recusam qualquer
   outra build:

   ```powershell
   (Get-FileHash C:\SporeAnalysis\SporeApp.exe -Algorithm SHA256).Hash.ToLower()
   # tem que dar:
   # 6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b
   ```

6. Teste de fumaça (deve dar **32 PASS / 0 FAIL / 3 SKIP**; ~75 min):

   ```powershell
   cd <repo>
   powershell -NoProfile -ExecutionPolicy Bypass -File tools\run_boot_crt_entry_tests.ps1
   ```

   Se o celular não estiver conectado, os `arm64_device_run` falham no push — ligue o
   aparelho e repita, ou rode só o x86 enquanto ajusta o resto.

---

## 4. Regras do projeto (combinadas, valem sempre)

1. **Nunca** commitar nem dar push. O dono commita com mensagem `update N`.
2. **Nunca** afirmar boot, menu, render ou gameplay sem evidência. A frase honesta
   até agora é "**768 de 31 266 inicializadores, sem boot**".
3. **Parar explicitamente** na primeira dependência não suportada, nomeando o
   endereço/símbolo. Não improvisar um shim sem entender a semântica.
4. **Não inflar closure**: se um corpo não foi medido, ele não entra.
5. **Cada passo é**: medir → implementar → validar nos 3 alvos → relatar → esperar
   autorização. Não encadear passos grandes sem reportar.
6. Quando o bug é da **fixture/ferramenta**, o bug é meu e deve ser dito assim.
7. Relatório por passo em `test-logs/boot-entry-20261108/report-*.md` + uma seção no
   [README.md](./README.md).

---

## 5. Como o pipeline funciona (para não se perder)

### 5.1 O alvo

PE32 x86 do Spore, base `0x00400000`. Estamos recompilando **estaticamente** para
ARM64 (Android), sem emulador, validando por execução diferencial.

### 5.2 Os 8 estágios (`tools/run_boot_crt_entry_tests.ps1`)

Do mais raso ao mais fundo, cada um prova uma coisa:

| estágio | o que prova |
| --- | --- |
| `seh-call-boundary` | o prólogo SEH do entry |
| `startupinfo-call` | `GetStartupInfoA` traduzido |
| `interlocked-call` | `InterlockedCompareExchange` + lock |
| `startup-lock` | o bloco de lock do CRT |
| `initterm-call` | chega na chamada `_initterm` com as duas pontas da tabela |
| `initterm-executed` | o `_initterm_e` (tabela C) foi percorrido |
| `startup-state-initializing` | o estado global vira `initializing`, `__app_type=2`, FPU CW `0x0001027f`, tabela C já percorrida |
| **`cpp-walk-initializers`** | **o walk dos 768 inicializadores C++** |

Cada estágio roda em **x86 (lift)**, **ARM64 (clang/NDK)** e **no aparelho**, e as
linhas `PASS` têm que ser idênticas. Os 3 `SKIP` são `original_x86_real_win32`:
nesses estágios não existe referência "original" porque o CRT de verdade inicializa
o processo — não é falha.

### 5.3 O laço de trabalho

```
medir (Ghidra)  →  gerar lote (--initializers N)  →  build x86  →  rodar
      ↑                                                              ↓
      └───── muro de corpo (medição)              muro de dado (linha de log + --apply)
```

- **Muro de dado**: a linha `PASS` traz `fault=read@0x.../N ... near=0x...+0x...`.
  Vira **uma** janela com `resolve_data_faults.py --log <log> --apply`.
- **Muro de corpo**: `failed_at` aponta um endereço e `fault=none`; precisa de
  medição Ghidra (`prepare_cpp_initializer_batch.py`) e de aumentar `--bodies`.

### 5.4 A tabela de inicializadores

- Intervalo: `0x013cc80c` .. `0x013eb098`, **31 267 slots**, 1 nulo (slot 0),
  **31 266 não nulos, todos distintos, todos dentro de `.text`**.
- O próprio CRT empurra as duas pontas (`PUSH 0x013eb09c` / `PUSH 0x013cc80c`).
- A tabela C (`_initterm_e`) começa em `0x013eb09c`.
- O layout bate com MSVC (`__xc_a/__xc_z` e depois `__xi_a/__xi_z`).

---

## 6. Como retomar o trabalho (receita)

### Passo 1 — subir para 1024

```powershell
cd <repo>
powershell -NoProfile -ExecutionPolicy Bypass -File tools\run_boot_crt_entry_tests.ps1 `
    -BatchInitializers 1024 -BatchBodies 1650
```

(`1650` = 1302 corpos + 25% de folga. Cap igual à necessidade esconde crescimento.)

### Passo 2 — se aparecer `fault=` na linha PASS

**Essa é a parte que ficou barata.** Não faça build completo por muro:

```powershell
# 1. ler o muro
Select-String test-logs\boot-entry-20261108\crt-cpp-walk-initializers-lift-x86.log -Pattern 'fault='

# 2. virar janela
python tools\batch_static_lift\resolve_data_faults.py `
    --reference C:\SporeAnalysis\SporeApp.exe `
    --log test-logs\boot-entry-20261108\crt-cpp-walk-initializers-lift-x86.log --apply

# 3. regerar a imagem (o header é incluído por UM arquivo: boot_entry_crt_harness.cpp)
python tools\batch_static_lift\generate_initterm_guest_image.py `
    --reference C:\SporeAnalysis\SporeApp.exe `
    --candidate "C:\Program Files (x86)\Steam\steamapps\common\Spore\SPOREFILES\SporeBin\SporeApp.exe" `
    --closure test-logs\boot-entry-20261108\generated-initterm-closure `
              test-logs\boot-entry-20261108\generated-cpp-batch-1 `
    --output test-logs\boot-entry-20261108\generated-initterm-guest-image

# 4. recompilar SÓ o harness e religar (~6 s, não 28 min)
```

Atalho que economiza muito tempo: para iterar só o estágio do walk, rode

```powershell
... -File tools\run_boot_crt_entry_tests.ps1 -Stage cpp-walk-initializers `
    -BatchInitializers 1024 -BatchBodies 1650
```

O script em [tools/run_boot_crt_entry_tests.ps1](./tools/run_boot_crt_entry_tests.ps1)
documenta os flags. Recompilar só o harness é o que transformou 28 min em **6 s** —
se um dia a imagem passar a ser incluída por mais de um arquivo, **esse truque morre**.

### Passo 3 — quando `fault=none`

Significa **lote esgotado**, não muro. Suba `-BatchInitializers` (e o `-BatchBodies`
correspondente) e repita. Depois que fechar verde num degrau, rode a suíte
**completa** (todos os 8 estágios) para pegar ARM64 + aparelho.

### Passo 4 — relatar

Novo `test-logs/boot-entry-20261108/report-cpp-batch-NN-*.md` + seção no README, com
tabela de passos (`ran` por muro), o que ficou sem explicação (se ficou) e a relação
honesta.

---

## 7. Mapa do repositório

| caminho | o que é |
| --- | --- |
| [tools/run_boot_crt_entry_tests.ps1](./tools/run_boot_crt_entry_tests.ps1) | **o orquestrador**: 8 estágios, x86 + ARM64 + aparelho. Default hoje: 768 / 1400 |
| [tools/batch_static_lift/BatchStaticLift.py](./tools/batch_static_lift/BatchStaticLift.py) | o lifter x86 → C++ |
| [tools/batch_static_lift/BatchStaticLiftRuntime.hpp](./tools/batch_static_lift/BatchStaticLiftRuntime.hpp) | **o runtime do guest**: memória, imports/shims, x87/SSE, pilha, contadores |
| [tools/batch_static_lift/boot_entry_crt_harness.cpp](./tools/batch_static_lift/boot_entry_crt_harness.cpp) | o harness diferencial; imprime a linha `PASS` |
| [tools/batch_static_lift/generate_cpp_initializer_batch.py](./tools/batch_static_lift/generate_cpp_initializer_batch.py) | gera o lote de N inicializadores a partir da closure |
| [tools/batch_static_lift/prepare_cpp_initializer_batch.py](./tools/batch_static_lift/prepare_cpp_initializer_batch.py) | **mede** a closure no Ghidra (é o passo caro) |
| [tools/batch_static_lift/generate_initterm_guest_image.py](./tools/batch_static_lift/generate_initterm_guest_image.py) | a imagem de memória do guest: **lista `WINDOWS`** + emissão hex |
| [tools/batch_static_lift/resolve_data_faults.py](./tools/batch_static_lift/resolve_data_faults.py) | fault do log → **uma** janela (`--apply` é idempotente) |
| [tools/batch_static_lift/merge_closures.py](./tools/batch_static_lift/merge_closures.py) | une medições; prefere registro não truncado |
| [tools/batch_static_lift/find_pointer_tables.py](./tools/batch_static_lift/find_pointer_tables.py) | acha sequências de ponteiros de código (semente das tabelas de classe) |
| [tools/batch_static_lift/test_static_batch_lift.py](./tools/batch_static_lift/test_static_batch_lift.py) | **122 testes** Python (`python -m unittest test_static_batch_lift`) |
| [tools/ghidra_scripts/](./tools/ghidra_scripts) | os 4 scripts do Ghidra (copiar para `C:\Users\wesll\ghidra_scripts`) |
| [docs/referencias.md](./docs/referencias.md) | os 3 projetos de referência e o que já compartilhamos com eles |
| `test-logs/boot-entry-20261108/cpp-batch-2/closure-union.json` | **4 154 corpos / 207 121 instruções / 0 truncados** — a união de todas as medições |
| `test-logs/boot-entry-20261108/generated-cpp-batch-1/` | as 1 044 fontes C++ do lote de 768 (geradas, no git) |
| `test-logs/boot-entry-20261108/generated-initterm-guest-image/` | a imagem atual: **79 regiões** (63 do PE + 16 zeradas), 144 028 bytes |
| `test-logs/boot-entry-20261108/report-*.md` | 28 relatórios, um por passo, em ordem cronológica |
| `test-logs/boot-entry-20261108/cpp-batch-21-slice4..8/` | as medições de 1024, 1280, 1536 e 2048 — **já pagas** |

---

## 8. Decisões técnicas que NÃO devem ser desfeitas

1. **`ran` é a única contagem honesta.** `initializers=N` é o que o lote *registra*;
   `ran` só conta quem retornou **e** devolveu a moldura (`eip == retorno` e
   `regs[4] == entry_esp`). Já erramos isso uma vez (48 registrados, 13 executando).
2. **A imagem viaja como texto hex**, não como array de bytes. Motivo: array custa
   ~7,6 caracteres por byte e o header passou de 1 MB (25 min por stage); hex custa
   ~2,3 (header de 326 KB). `.incbin` não existe no MSVC; base64 exigiria tabela +
   decodificador. `decode_guest_image` **falha fechado** se o tamanho não for `2N`.
3. **`std::deque<Region>`, não `std::array<Region, 128>`.** A tabela fixa saturava em
   exatamente 128 regiões (pilha + 124 janelas + TEB/probe/heap) e o `VirtualAlloc` do
   guest passava a devolver 0 → `write@0x00000008`. Use `deque`, não `vector`: o
   `deque` não move o que já está guardado, então os ponteiros de `find_region` valem.
4. **Import por ponteiro existe.** O guest faz `MOV EAX,[iat]; CALL EAX`, então um
   import pode ser alcançado sem aparecer em nenhum corpo gerado. Trampolins em
   `0x5f000000 + 0x10*i`; índice `i` = i-ésimo slot de `manifest.import_slots`.
5. **`double` ocupa 2 slots de argumento.** `import_argument_count` precisa devolver
   2 para `_finite`/`_isnan`, senão o `ESP` desalinha em toda chamada seguinte.
6. **BSS é página inteira (4 KiB).** O arquivo não tem bytes para delimitar BSS; é a
   granularidade do loader. `image.classify` devolve raw/bss/none.
7. **O stub `0x011e073e` fica neutralizado.** `f(dest, value, size)` cdecl com
   `value = 0`; o payload nunca é mapeado. Contrato validado por **forma**
   (`n_sizes=2`), não por tamanho fixo.
8. **`SPORE_GUEST_IMAGE_DROP`** (variável de ambiente, desligada por padrão) deixa
   regiões fora do mapa por endereço. Foi o que permitiu varrer 62 janelas em 1,8 s.
   Mantenha: é diagnóstico, não muda nada sem a variável.
9. **Fronteiras declaradas** (não modeladas, falham fechado nomeando-se):
   `CreateThread`, `_ecvt`, `_fcvt`, `_gmtime64`, `_localtime64`, `_time64`,
   `strftime`. Qualquer uma pode virar o próximo muro e exige decisão de modelagem.

---

## 9. Armadilhas já pagas (não repita)

Todas foram bugs **meus**, encontrados usando a ferramenta — estão aqui para não
voltar:

| sintoma | causa real |
| --- | --- |
| `ran` travado em N−125 | os "corpos faltando" eram saltos **internos** já medidos; o filtro de saltos locais existia para `engine`/`pending_bodies` mas não para `missing` |
| `IndexError` no fim da tabela | `targets[len(roots)]` quando o lote chega ao último slot |
| `ERROR_INVALID_PARAMETER 87` → null deref | arena `VirtualAlloc` de 4 MB e o engine pedindo 16 MB |
| escrita em `0x6ffffffc` | pilha do guest de 1 KB |
| seção crítica legítima recusada | asserção `recursion <= 1` |
| `neutralized=3/1/0` | teste amarrado a `size == 0x400` e destino no heap (agora valida a forma) |
| build ARM64 morre com `-Werror` | `-Wunneeded-internal-declaration`: função auxiliar sem chamador nos estágios que não usam a imagem → `[[maybe_unused]]` |
| log ilegível | PowerShell `>` escreve **UTF-16**; `resolve_data_faults` já lê os dois |
| janela não aplicada | regex casava `0x4` e o arquivo escreve `0x04` |
| build ARM64 com caminho errado | resposta do **clang** trata `\` como escape (dobrar separadores); o `cl` do MSVC **não** |

---

## 10. Próximos passos, em ordem

1. **1024** (`-BatchInitializers 1024 -BatchBodies 1650`): já medido, só rodar. Muros de
   dado saem em ~6 s com o laço da seção 6.
2. **1280** e **1536**: mesma receita, +256 corpos cada, também já medidos.
3. **2048**: idem (2 326 corpos).
4. Depois disso é preciso **medir mais** (`prepare_cpp_initializer_batch.py`), sempre
   ~1 corpo novo por inicializador.
5. Em paralelo, decidir o que fazer com as fronteiras declaradas (seção 8.9) quando
   alguma aparecer.

**Quando o assunto "boot" voltar**: o CRT terminar é uma condição *necessária* e não
*suficiente*. Depois dos 31 266 inicializadores ainda há: as DLLs do jogo
(`Simulator`, `UI`, `Graphics`…), o leitor de `.package` (~900 MB de conteúdo
empacotado), codec de vídeo e renderizador. Não prometa intro.

---

## 11. Referências externas (o trilho)

- [codepdbh/nfsu1-recompiled](https://github.com/codepdbh/nfsu1-recompiled) — NFS
  Underground recompilado estaticamente para Windows e Android, sem emulador.
- [ttom795/Skyrim_Android](https://github.com/ttom795/Skyrim_Android) — recompilação
  estática de Skyrim para Android.
- [VinTeRuS/proto-re](https://github.com/VinTeRuS/proto-re) — ferramentas de
  recompilação estática.

O que já compartilhamos com eles e o que ainda falta está em
[docs/referencias.md](./docs/referencias.md).

---

## 12. Resumo de uma linha

**O CRT do Spore executa 768 dos 31 266 inicializadores C++ em x86, ARM64 e no
aparelho, com as três linhas `PASS` idênticas; o próximo degrau (1024) já está medido
e o laço de conserto de muro custa segundos, não meia hora.**

---

## 13. Aviso — a máquina estava infectada (levantado em 2026-11-12)

Não é parte do projeto, mas afeta a restauração. Fatos coletados do Defender:

| item | o que era |
| --- | --- |
| `Virus:Win32/Expiro.HAC!MTB` | **infeccioso de arquivo** (PE). 92 detecções entre **04/11 e 05/11** |
| `Virus:Win32/Floxif.H` | **infeccioso de arquivo**. Primeira detecção em **02/11** |
| `Trojan:Win32/Wacatac.H!ml` + `Behavior:Win32/Persistence.A!ml` | loader com persistência: serviço falso `MicrosoftEdgeUpdateSvcsF3BE7F68` + Run key `MicrosoftEdgeUpdateRunF3BE7F68`, payload em `C:\ProgramData\71f9e176e5c46e92\34B40686F3BE7F68\` |

Ou seja: **a infecção existia há ~10 dias**, não foi um evento de uma noite.

### O que foi atingido (37+ arquivos), e o que isso significa para a restauração

- `C:\Users\wesll\Documents\ghidra_12.1.4_PUBLIC\...\demangler_gnu_v2_41.exe` e
  `ghidra_12.2_PUBLIC\...\decompile.exe` → **NÃO restaure o Ghidra de backup;
  reinstale limpo.**
- `C:\msys64\usr\bin\as.exe`, `ucrt64\bin\clang.exe`, `cpp.exe`
- `Telegram.exe`, `Updater.exe`, `Spotify.exe`, vários `python.exe` de `.venv`,
  `node_modules\**\*.exe`, instaladores no `Downloads`
- **4 binários do nosso projeto** (`BatchStaticLiftX86Reference_*.exe`,
  `reachable_x86_reference.exe`) — em `workspaceStorage` do VS Code

Regra prática: **não restaure nenhum `.exe`/`.dll` de backup.** Reinstale as
ferramentas e recompile o que for nosso.

### O que foi verificado LIMPO (pode confiar)

- **O repositório no GitHub**: `HEAD == origin/main` (`f57fcac`), árvore limpa, e os
  **10 `.exe` rastreados** passaram pelo `MpCmdRun -Scan -DisableRemediation` =
  `found no threats`. Além disso, todo o conteúdo é texto/fonte regenerável.
- **`C:\SporeBackup\MINIMO`**: `SporeApp.exe` com hash
  `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b` (intacto) e
  Defender `found no threats`. Os demais arquivos são `.json`/`.java`/`.md` — texto,
  não carregam infeccioso de PE.
- **`C:\Users\wesll\ghidra_scripts\*.java`** — texto.

### Credenciais (faça de outro aparelho)

`Telegram.exe` foi atingido, então: encerrar as outras sessões no Telegram, ativar
2FA, e trocar senhas/tokens de GitHub (PAT), Steam, Discord, Spotify e e-mail.

### Teste de aceitação depois de formatar

O `PASS` é um retrato determinístico. Depois de reinstalar tudo e rodar a suíte, a
linha tem que ser **byte a byte igual** à da seção 1. Se for, os resultados anteriores
não estavam contaminados; se não for, o que mudou é a diferença a investigar.

### Varredura do disco D: (feita em 2026-11-12)

- **1 970 executáveis** (`.exe/.dll/.scr/.cpl/.ocx/.sys/.com`) varridos um a um com
  `MpCmdRun -DisableRemediation`: **7 sinalizados**, todos em `.venv` de Python
  (`lyric_studio` e `samanta`): `t64.exe`, `f2py.exe`, `hf.exe`, `idna.exe`,
  `onnxruntime_test.exe`, `pyav.exe` → `Trojan:Win32/Wacatac.*!ml` e `Sabsik.FL.A!ml`.
- **1 963 não sinalizados**, incluindo `D:\SPOREFILES`, `D:\SteamLibrary`,
  `D:\SporeAndroid`, `D:\varios projects`, `D:\arquivos nvme`, `D:\mtstore`,
  `D:\tktech`, `D:\documents`.
- **Mas**: 4 arquivos do D: que já foram detectados como Expiro/Floxif no histórico
  (`D:\documents\DavyjonesAI\...\electron.exe`, `D:\documents\ml\backend\.venv\Scripts\python.exe`,
  `D:\tktech\iphonexr\venv\...\t32.exe` e `w32.exe`) **continuam existindo e hoje não
  são sinalizados**. Ou seja: **um passe só com ML não é prova de limpeza**.
- Existe um **cofre do Avast** em `D:\$AV_ASW\$VAULT` com 11 itens em quarentena de
  **02/11 02:32–03:04** (~900 MB, `.dat` cifrados e inertes). Confirma a data do
  evento; deve ser **apagado**, não copiado.

**Conclusão: formatar só o C: não basta.** Um `.exe` infectado que sobreviva no D: e
seja executado depois re-infecta tudo. Apague/refaça o D: também, ou no mínimo apague
todo `.venv`, `node_modules`, `dist`, `build` e o `$AV_ASW`, e rode a varredura de novo.

### O que já foi apagado do D: (2026-11-12, ~1 GB liberado)

- Os **7 sinalizados** (`t64.exe`, `f2py.exe`, `hf.exe`, `idna.exe`,
  `onnxruntime_test.exe`, `pyav.exe` nos `.venv` de `lyric_studio` e `samanta`).
- Os **4 que o histórico marcou como Expiro/Floxif** e seguiam existindo:
  `D:\documents\DavyjonesAI\node_modules\electron\dist\electron.exe`,
  `D:\documents\ml\backend\.venv\Scripts\python.exe`,
  `D:\tktech\iphonexr\venv\...\t32.exe` e `w32.exe`.
- O **cofre do Avast** `D:\$AV_ASW` (11 itens em quarentena, ~814 MB). Precisou de
  shell elevado: o dono era `BUILTIN\Administradores`.

Re-varredura depois das exclusões: **1 959 executáveis, 0 sinalizados**. Continua
valendo o aviso: 0 sinalizado não é prova de limpeza com dois infecciosos
polimórficos, então o caminho seguro segue sendo refazer o D:.

### Por que a infecção VOLTOU depois de formatar (descoberto em 12/11, 01:00)

O dono já havia formatado o C: uma vez, e a infecção reapareceu. O histórico do
Defender mostra o motivo — **as primeiras detecções depois daquela formatação foram
todas no D:**:

```
02/11 15:59  Virus:Win32/Floxif.H   D:\tktech\iphonexr\venv\...\distlib\t32.exe
02/11 15:59  Virus:Win32/Floxif.H   D:\tktech\iphonexr\venv\...\distlib\w32.exe
02/11 15:59  Trojan:Win32/Sabsik.FL.A!ml  D:\varios projects\ghidra_12.2_PUBLIC\docs\...\WallaceSrc.exe
02/11 15:59  Trojan:Win32/Wacatac.H!ml    D:\varios projects\ghidra_12.2_PUBLIC\docs\...\WallaceVersion2.exe
```

Ou seja: **o reservatório era o D:, que nunca foi limpo.** Depois de reinstalar, usar
aqueles projetos (venv de `tktech`, a cópia do Ghidra em `varios projects`) re-infectou
a instalação nova. Não foi o disco C:.

O que foi verificado limpo nessa investigação: a **mídia de instalação** (E: `ESD-USB`,
227 executáveis, 0 sinalizados), **nenhuma exclusão** no Defender
(`Exclusions\Paths`/`Extensions`/`Processes` = 0 entradas), **nenhum autostart falso**
(as Run keys são SecurityHealth, Realtek, Java Update, OneDrive, EA, FDM, SCSKiller e
navegadores) e nenhuma tarefa agendada suspeita.

### Mapa dos discos (para o plano de limpeza)

| disco | modelo | tamanho | estilo | conteúdo |
| --- | --- | --- | --- | --- |
| 0 | ST3500312CS (SATA) | 465,8 GB | MBR | **D: (TK TECH)** — disco físico separado |
| 1 | FORCE le 200 (SATA) | 238,5 GB | GPT | EFI 1 GB + **237 GB Linux (`0fc63daf…`)**, ocultos, sem letra |
| 2 | KINGSTON SNV2S1000G (NVMe) | 931,5 GB | GPT | **C:** + EFI + MSR + Recovery (Windows) |
| 3 | Generic Flash Disk (USB) | 14,6 GB | MBR | E: `ESD-USB` (mídia do Windows, limpa) |

Como o D: é um **disco separado**, dá para zerá-lo sem tocar no Windows:

```text
diskpart
  list disk
  select disk 0        <-- confirme que é o ST3500312CS / 465 GB (D:)
  clean
  create partition primary
  format fs=ntfs quick label="TK TECH"
  assign letter=D
  exit
```

Depois: reinstalar o Windows pela mídia E: (verificada limpa), e **nunca** restaurar
`.exe`/`.dll`/`.venv`/`node_modules` de backup antigo — só texto. A partição Linux de
237 GB do disco 1 também pode guardar `.exe` infectado; se não for usada, apague também.
