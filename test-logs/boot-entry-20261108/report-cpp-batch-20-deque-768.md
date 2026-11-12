# A parede dos 768 era a minha tabela de regiões (2026-11-11)

Continuação de `report-cpp-batch-19-ran768-blocked.md`, que parou com `ran=9` e sem
explicação. A explicação apareceu, e não era o guest: era o **fixture**, com uma
tabela de tamanho fixo que saturou exatamente quando a imagem cresceu.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. O experimento que denunciou o tipo de causa

Antes de qualquer conserto, um hook de diagnóstico (`SPORE_GUEST_IMAGE_DROP`, lista de
endereços de região a pular no `map_region`, desligado por padrão) permitiu rodar as
62 janelas uma a uma: **62 execuções em 1,8 s**, contra 6 builds de ~17 min.

O resultado foi absurdo para uma causa de dado:

```
derrubar TODAS as 62 janelas  -> ran=384  failed_at=0x0121fac0
derrubar NENHUMA              -> ran=9    failed_at=0x00935cc7
derrubar QUALQUER UMA das 62  -> ran=384
```

Se o problema fosse conteúdo de janela, derrubar uma específica consertaria e as
outras não. **Derrubar qualquer uma conserta** ⇒ o problema é o **número** de regiões,
não o que elas contêm. O dado nunca importou; o espaço da tabela importava.

## 2. A conta que fecha exatamente

`BatchLiftMemory` guardava o mapa em `std::array<Region, 128> regions_`, e
`map_region` recusava além disso:

| região | quantidade |
| --- | --- |
| pilha do guest (construtor) | 1 |
| janelas da imagem (com as 62 novas) | **124** |
| TEB, tabela de probe, heap | 3 |
| **total** | **128** |

Com 128 mapeadas, o primeiro `VirtualAlloc` com `MEM_COMMIT` não tinha onde entrar. O
runtime faz o que o Windows faria — `set_guest_error(8)` e devolve **0** — e o guest,
que não confere `GetLastError`, seguiu usando o 0 como base:

```
CALL ECX          ; 0x00935cc5, um ponteiro de função
MOV ESI, EAX      ; 0x00935cc7, EAX = 0
MOV [ESI+8], EDI  ; 0x00935cc9  ← fault=write@0x00000008/4
```

Derrubar uma janela qualquer liberava um slot, o `VirtualAlloc` funcionava, e o
caminho voltava ao normal. É por isso que o resultado era determinístico e mesmo
assim parecia independente de qual janela fosse removida.

## 3. O conserto

`std::array<Region, 128>` → `std::deque<Region>` com `push_back`. O `deque` não move
o que já está guardado, então os ponteiros de `find_region` continuam válidos — que é
o motivo de não ser `std::vector`. `region_count_` desapareceu; o tamanho é o do
contêiner. O comentário no código diz o porquê, incluindo o sintoma que isso causou.

Nota de honestidade: o `VirtualAlloc` devolver 0 é comportamento correto do Win32. O
bug era a **capacidade artificial** que o provocava; o guest ignorando o erro é
assunto do guest e agora aparece como fault nomeado, não como silêncio.

## 4. Depois do conserto: 384 volta, e 768 avança

Com a imagem de **124 regiões**, sem derrubar nada:

```
PASS crt_cpp_walk failed_at=0x0121fac0 initializers=384 ran=384
     last_ran=0x0121fab0 imports=5322 sections=8 count=9
```

A linha boa de antes, agora com a imagem grande — o `ran=384` não dependia mais da
imagem pequena.

## 5. Os cinco muros de dado até 768

Com o `deque`, o walk passou a andar e a parar em janelas **pequenas demais** — todas
do mesmo tipo: uma leitura/escrita de 8 ou 4 bytes que começa dentro da janela e
termina alguns bytes depois do fim dela.

| `ran` | muro | o que era |
| --- | --- | --- |
| 423 | `read@0x013ebd18/8` em `0x013ebd00+0x1c` | qword lida 4 bytes além da janela |
| 466 | `write@0x015d2058/4` em `0x015d204c+0xc` | dword escrita no fim exato da janela |
| 551 | `read@0x013ec290/8` em `0x013ec278+0x1c` | qword, mesma forma |
| 679 | `read@0x013ec4dc/1` | 1 byte fora |
| 688 | `read@0x013ec540/8` | qword, mesma forma |
| **768** | **`fault=none`** | **fronteira do lote: `0x01224e20`** |

Cada um foi uma linha de log e um `resolve_data_faults.py --log <log> --apply`. O
plano de `0x015d2058` escolheu a **página de 4 KiB** (`data_page_015d2000`), que
absorveu 42 janelas individuais de uma vez — a imagem caiu de 123 para 81 regiões.

## 6. O ciclo de iteração: 28 min → 6 s

O `initterm_guest_image.hpp` é incluído por **um único arquivo**
(`boot_entry_crt_harness.cpp`); os 1044 corpos não o veem. Então, depois de um build
completo do lote, cada repetição é: regerar a imagem, recompilar **um** objeto,
religar. Medido: **6 segundos**. Foi o que permitiu varrer os cinco muros na mesma
tarde em vez de cinco builds de meia hora.

## 7. O resultado

```
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x01224e20 executed=107
     esp_delta=-136 ebp=entry-4 cookie=consistent imports=5479
     initializers=768 ran=768 last_ran=0x01224dc0
     walk=stopped_at_0x01224e20 args=argc1,argv_guest,envp_empty
     sections=8 tls=2 guard=single_instance count=9
     neutralized=0x011e073e/244/3/0 buf=0x01668994 n_sizes=2
     fault=none@0x00000000/0 pc=0x00000000 near=0x00000000+0x0
```

`fault=none` e `stopped_at=0x01224e20`, que é o **inicializador #769**: não houve
muro, o lote acabou. Duas execuções seguidas dão a linha idêntica.

Suíte completa, 8 estágios, x86 + ARM64 + aparelho:

```
PASS 32   FAIL 0   SKIP 3
PASS x86_vs_arm64 PASS crt_cpp_walk ... initializers=768 ran=768
PASS arm64_device_run stage=cpp-walk-initializers serial=PJMZAEJRX4YLFIDI
```

Os 3 SKIP são os `original_x86_real_win32` de desenho — o CRT real inicializa o
processo, então não há o que comparar nesses estágios.

O stub neutralizado continua com `244/3/0 n_sizes=2` e `buf=0x01668994`, iguais aos de
antes — nada mudou nele. `imports=5479` (era 5322 em 384) é o guest indo mais fundo.

## 8. Limites

- **768 de 31 266 = 2,5%** da tabela. Sem boot, sem menu, sem render, sem gameplay.
- O muro agora é de **cobertura**: para ir além é medir mais corpos (`prepare_cpp_initializer_batch`),
  não resolver mecanismo novo.
- O hook `SPORE_GUEST_IMAGE_DROP` fica no código, desligado por padrão: ele não muda
  nada sem a variável de ambiente, e foi o que transformou 2 h de bisect em 2 s.
- A varredura de regiões em `find_region` é linear; com o `deque` ela cresce sem
  limite teórico. Para o tamanho atual (79 janelas + commits) é irrelevante, mas é
  um custo que existe.

## 9. Arquivos

Novos: este relatório, `cpp-batch-19-init385-768/` (medição do slice), os cinco
`cpp-batch-21-slice4..8/` (medição até 2048), o log do laço `diag768-last.log`.

Modificados: `BatchStaticLiftRuntime.hpp` (`std::deque<Region>`, `region_count_`
removido), `boot_entry_crt_harness.cpp` (`SPORE_GUEST_IMAGE_DROP`,
`hex_value`, `region_is_dropped`), `generate_initterm_guest_image.py` (5 janelas
reparadas, `data_page_015d2000`), `run_boot_crt_entry_tests.ps1` (768 / 1400),
`cpp-batch-2/closure-union.json` (+421 corpos do slice 385-768, +1 281 dos
slices 4-8), `README.md`.

## 10. O próximo degrau, já medido e cotado

A medição até o inicializador **#2048** está paga: cinco slices de 256
(`cpp-batch-21-slice4..8/`, 4m42s no total) unidos na união, que foi de 2 873 para
**4 154 corpos / 207 121 instruções / 0 truncados**. A união foi refeita com backup
(`closure-union.pre-batch21.json`) e o lote de 768 foi **reconferido arquivo por
arquivo depois da união: 1 044 arquivos, 0 ausentes, 0 diferentes** — o estado
verificado não mudou.

O gerador, com `--bodies 6000` para não cortar nada, diz o que cada degrau pede:

| inicializadores | corpos | instruções | não medidos |
| --- | --- | --- | --- |
| 768 (verde) | 1 044 | 22 509 | 0 |
| 1024 | 1 302 | 25 686 | 0 |
| 1280 | 1 558 | 28 866 | 0 |
| 1536 | 1 814 | 31 919 | 0 |
| 2048 | 2 326 | 38 219 | 0 |

O crescimento é **exatamente 1 corpo por inicializador** — a closure auxiliar está
saturada, quem cresce é a própria tabela. Para subir:

1. `run_boot_crt_entry_tests.ps1 -BatchInitializers <N> -BatchBodies <corpos + 25%>`;
2. deixar o build x86 terminar e olhar a linha `PASS`: se houver `fault=`, é uma linha
   de log e um `resolve_data_faults.py --log <log> --apply`;
3. regerar a imagem, recompilar **só** `boot_entry_crt_harness.cpp` e religar (~6 s),
   repetindo até `fault=none`;
4. aí sim rodar a suíte completa para x86 + ARM64 + aparelho.

O passo 3 é o que mudou o custo desta tarde: sem ele cada muro custa um build inteiro.
