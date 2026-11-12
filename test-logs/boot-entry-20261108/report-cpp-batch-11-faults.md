# Marco 6 — décimo primeiro passo: a falta vira janela em um comando (2026-11-09)

Opção 3 escolhida pelo usuário: o runtime informa a falta e o gerador incorpora
**só** a janela que aquela falta provou faltar.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. O que o runtime pode e o que ele não pode

A formulação original era "o runtime informa o run candidato". Isso não é
possível no runtime: ele roda no aparelho, não tem a PE em disco e não conhece
tabela nenhuma. O que ele **pode** — e agora faz — é dizer o endereço, a largura,
a instrução e **a região mapeada mais próxima**, que é o que classifica a falta:

```
fault=read@0x0143dd9c/4 pc=0x00697cae near=0x01408240+0xb0
```

`near=` é a maior região mapeada cujo início é menor ou igual ao endereço. Duas
leituras possíveis, imediatas:

- `near=0x00000000+0x0` — o guest estava fora de tudo, e a falta é ponteiro nulo
  ou índice perdido;
- `near=0x01408240+0xb0` — o guest saiu de uma janela conhecida por 0x5C bytes,
  ou seja, é dado do arquivo que falta mapear.

O cálculo é feito uma vez, na primeira falta, sobre a tabela de regiões que o
próprio runtime já mantém.

## 2. A janela: o gerador a deriva do log

`tools/batch_static_lift/resolve_data_faults.py`:

```
python tools/batch_static_lift/resolve_data_faults.py \
    --reference C:\SporeAnalysis\SporeApp.exe \
    --log test-logs/boot-entry-20261108/crt-cpp-walk-initializers-lift-x86.log \
    --apply
```

Para cada `fault=` do log ele:

1. confere se uma janela declarada já serve o acesso — se sim, reporta
   `covered <nome>` e **não** duplica nada;
2. senão localiza a seção do PE, lê os bytes a partir da palavra alinhada, sem
   nunca passar do fim da seção;
3. decide o tipo pela evidência, nesta ordem:
   - **run de ponteiros de código** — o endereço cai num run maximal de palavras
     que apontam para `.text`; a janela cobre o run inteiro e a razão registra
     **onde o run termina** (padding `int3`, palavra zero, texto ou a palavra
     concreta);
   - **string** — o byte é imprimível; a janela cobre o run imprimível, incluindo
     o terminador, e para no primeiro byte que não é nem imprimível nem `\0`;
   - **palavra** — caso contrário, cobre o acesso alinhado; `writable` só é
     verdadeiro em `.data`;
4. imprime a entrada no formato do `WINDOWS` e, com `--apply`, insere no
   `generate_initterm_guest_image.py`.

A inserção é idempotente (lista vazia não escreve nada) e a suíte de testes
verifica que o arquivo continua sendo Python válido depois dela.

## 3. Validação contra o que já estava à mão

Rodando o planejador contra as faltas reais dos passos anteriores:

| endereço | resultado |
| --- | --- |
| `0x0143e050/4` | `covered` por `engine_object_vtable` |
| `0x0143dd9c/4` | `covered` por `engine_class_registry_tables` |
| `0x0093a2cc/4` | `covered` por `engine_switch_table` |
| `0x01408324/4` | `covered` por `engine_class_vtable` |
| `0x0143dc78/4` | `covered` por `engine_class_descriptor` |
| `0x014082ac/1` | `covered` por `engine_class_names` |
| `0x0143e0e4/4` | **run de 12 ponteiros, 0x30 bytes** |

As seis primeiras eram as janelas que eu havia calculado à mão nos passos
anteriores; a ferramenta as reconhece e não as toca — é a confirmação de que os
limites escolhidos à mão estavam certos. A sétima é uma tabela que eu havia
removido por não estar em uso ainda; agora ela entra pelo caminho formal, e a
razão registrada é gerada, não digitada.

## 4. Estado entregue

```
PASS crt_entry            imports=5
PASS crt_startupinfo      imports=6
PASS crt_interlocked      imports=7
PASS crt_startup_lock     imports=7
PASS crt_initterm_call    imports=7
PASS crt_initterm_executed imports=14
PASS crt_startup_state_initializing imports=14
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x00ff0420 executed=107
     imports=5134 initializers=48 sections=7 tls=2
     guard=single_instance node=0x5e000010 count=8
     neutralized=0x011e073e/1024/2/0 buf=0x5e000088
     fault=none@0x00000000/0 pc=0x00000000 near=0x00000000+0x0
PASS arm64_build 8/8 · PASS x86_vs_arm64 8/8 · PASS arm64_device_run 8/8 (PJMZAEJRX4YLFIDI)
113 testes Python OK
```

Janelas: 47. O muro continua sendo `0x00ff0420`, um alvo de chamada indireta fora
do lote — **código**, não dado.

Nota de honestidade sobre o `near=`: o campo está compilado e impresso nas duas
linhas, mas nesta execução a falta é `none`, então o valor zero não é uma medição
do caso interessante. Ele será observado de verdade na próxima falta.

## 5. Próximo passo

1. Levantar `0x00ff0420` (o muro atual de código).
2. A partir daí o ciclo é: rodar, ler `fault=.../pc=.../near=...`, um comando de
   `resolve_data_faults.py --apply`, rodar de novo. Cada iteração deixa de exigir
   investigação manual de tabela.
3. Decidir se o `--apply` deve rodar dentro do runner. Hoje ele é manual de
   propósito: a lista de janelas é a base de todos os estágios validados, e uma
   mutação automática durante o build esconderia o que mudou.

## 6. Arquivos

Novos: `tools/batch_static_lift/resolve_data_faults.py`.

Modificados: `BatchStaticLiftRuntime.hpp` (`FaultInfo::near_base`/`near_size`
calculados na primeira falta), `boot_entry_crt_harness.cpp` (`near=` nas linhas
`FAIL` e `PASS`), `generate_initterm_guest_image.py` (janela `rdata_0143e0e4`
inserida pela ferramenta), `test_static_batch_lift.py` (113 testes: leitura de
faltas do log, limites de string, janela que já cobre, e inserção que mantém o
arquivo válido e idempotente).
