# Marco 6 — décimo segundo passo: cinco formas de instrução, e o build ARM64 no limite (2026-11-09)

Continuação de `report-cpp-batch-11-faults.md`. Depois de fechar a opção 3, semear
os métodos da tabela de registro expôs o que faltava no tradutor — e o limite da
linha de comando do Windows.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. O lote saltou de 155 para 256 corpos

Os 51 métodos da tabela de registro (`0x0143dcc4`) que ainda não estavam medidos
foram levantados numa rodada só: **598 corpos / 42 155 instruções / 62 imports**,
0 exports truncados, 41 pendentes no corte de 25 rodadas. União medida: **2 336
corpos / 184 481 instruções**.

A lista de sementes saiu do runner e foi para
`cpp-batch-2/engine-bodies-registry.txt`, com a origem declarada no comentário.
Foi para isso que o gerador ganhou `--engine-body-file` (um endereço por linha,
`#` comenta): uma linha de 51 sementes no runner seria ilegível.

## 2. O que o tradutor não sabia fazer

Com os corpos semeados, o gerador recusou o lote e nomeou cada instrução que não
sabia traduzir. Cinco formas faltavam, todas implementadas com semântica de x86,
não com aproximação:

| forma | encontrada em | modelo |
| --- | --- | --- |
| `JMP r32` | `0x009234ec` (`JMP EAX`) | despacho de cauda: um salto não empilha retorno, então o destino volta direto para o chamador do corpo |
| `MUL r/m32` | `0x011e0ce1`, `0x011e0ce9`, `0x011e0d0f`, `0x011e0d19` | não assinado: `EDX:EAX` recebe o produto de 64 bits, CF/OF se a metade alta não é zero |
| `IMUL r/m8` | `0x00937c85` (`IMUL DL`) | `AX = AL × DL` assinado, CF/OF quando o produto não cabe em `int8` |
| `SHRD r/m32, r32, CL` | `0x011e08da` | `batch_guest_shrd`, contagem mascarada em 5 bits (4 no caso de 16), CF = último bit que saiu, OF só para contagem 1 |
| `RCR r/m32, CL` | `0x011e0d01`, `0x011e0d05` | `batch_guest_rcr`, rotação **através** do carry bit a bit |
| `ROL`/`ROR` | preventivo | mesma família, só CF e OF mudam; SF/ZF/PF ficam |

O `SHRD` recebeu também `batch_guest_shrd` no runtime porque a contagem pode vir
do CL em tempo de execução e deslocar por 32 é comportamento indefinido em C++.

## 3. Um erro de compilação que valeu a correção

O primeiro lote gerado não compilou:

```
spore_011e08d0.cpp(34): error C2373: 't4r': redefinição; modificadores de tipo diferentes
```

O corpo já declara `t4a`, `t4b` e `t4r` para a instrução de índice 4, e eu
declarava `const std::uint32_t t4r = batch_guest_shrd(...)`. As duas formas novas
passaram a emitir um bloco próprio com um `result` de escopo local, então não há
colisão possível com temporários do corpo — e o mesmo vale para as rotações.

## 4. Dois limites de ferramenta, não de código

**4.1 A linha de comando do Windows.** Com 256 fontes, o build ARM64 falhou com
"O nome do arquivo ou a extensão é muito grande": o `clang++` recebia todas as
fontes como argumentos. Passou a usar arquivo de resposta, como o build x86 já
fazia.

**4.2 E aí apareceu uma armadilha de verdade.** Com o arquivo de resposta, o
`clang` reclamou de arquivos que não existiam:

```
clang++: error: no such file or directory:
'C:UserswesllAndroidStudioProjectsSporeAndroidtoolsbatch_static_liftboot_entry_crt_harness.cpp'
```

O parser de arquivo de resposta do `clang` trata `\` como escape, então cada
separador de caminho desapareceu. Os separadores agora vão dobrados (`\\`) ao
escrever o arquivo. O `cl` da Microsoft **não** aplica essa regra, e é por isso
que o build x86 funcionava com o mesmo tipo de arquivo — o comentário no runner
diz isso, para ninguém "unificar" os dois e quebrar um deles.

## 5. Estado entregue

```
PASS crt_entry            imports=5
PASS crt_startupinfo      imports=6
PASS crt_interlocked      imports=7
PASS crt_startup_lock     imports=7
PASS crt_initterm_call    imports=7
PASS crt_initterm_executed imports=14
PASS crt_startup_state_initializing imports=14
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x0068f9b0 executed=107
     imports=5141 initializers=48 sections=7 tls=2
     guard=single_instance node=0x5e000010 count=8
     neutralized=0x011e073e/1024/2/0 buf=0x5e000088
     fault=none@0x00000000/0 pc=0x00000000 near=0x00000000+0x0
PASS arm64_build 8/8 · PASS x86_vs_arm64 8/8 · PASS arm64_device_run 8/8 (PJMZAEJRX4YLFIDI)
115 testes Python OK
```

Lote: **48 inicializadores, 256 corpos, 11 636 instruções, 54 imports**, 2
pendentes. Imagem: 47 regiões, 7 192 bytes. `imports` do walk: 5134 → **5141**.

O muro atual é `0x0068f9b0`, um alvo de chamada indireta fora do lote.

## 6. Próximo passo

1. Levantar `0x0068f9b0` — o padrão continua: método de tabela, pequeno.
2. O orçamento de corpos está em 320 e o lote usa 256: ainda há folga, mas o
   próximo salto de sementes precisa de decisão explícita.
3. A tabela de registro tem 93 slots e 58 alvos únicos; os que sobraram já estão
   medidos e podem ser semeados quando o walk os chamar.

## 7. Arquivos

Novos: `test-logs/boot-entry-20261108/cpp-batch-12-ff0420/`,
`cpp-batch-13-registry/`, `cpp-batch-2/engine-bodies-registry.txt`.

Modificados: `BatchStaticLift.py` (`MUL`, `IMUL r/m8`, `SHRD`, `ROL`/`ROR`/`RCR`,
`JMP r32`), `BatchStaticLiftRuntime.hpp` (`batch_guest_shrd`,
`batch_guest_rol`/`ror`/`rcr`), `generate_cpp_initializer_batch.py`
(`--engine-body-file`), `tools/run_boot_crt_entry_tests.ps1` (sementes em arquivo,
arquivo de resposta no build ARM64 com separadores dobrados),
`test_static_batch_lift.py` (115 testes).
