# Referências externas

Projetos de recompilação estática que servem de referência para este port. Nenhum
deles é copiado: o que se aproveita é a **forma** do trabalho, não código. Todos
exigem a cópia do jogo do próprio usuário, como aqui.

| projeto | alvo | por que importa para nós |
| --- | --- | --- |
| [codepdbh/nfsu1-recompiled](https://github.com/codepdbh/nfsu1-recompiled) | Need for Speed Underground (2003), x86 → nativo, Windows e Android | mostra o ciclo completo de um jogo comercial: funções traduzidas, camada de imports, tradução gráfica e leitura dos assets no formato original |
| [ttom795/Skyrim_Android](https://github.com/ttom795/Skyrim_Android) | Skyrim (2011) → Android | prova que um jogo grande, Direct3D e multithread cabe num Android moderno — e mostra quanto do esforço está fora do tradutor |
| [VinTeRuS/proto-re](https://github.com/VinTeRuS/proto-re) | arcabouço de recompilação estática | referência de organização: levantador, runtime, testes diferenciais |

## O que já temos do padrão

1. **Funções traduzidas para nativo** — `tools/batch_static_lift/BatchStaticLift.py`
   emite C++ por corpo; o harness compila para x86 e para ARM64 e compara as duas
   execuções.
2. **Camada de runtime que honra o contrato do sistema** —
   `BatchStaticLiftRuntime.hpp` atende `KERNEL32`, `MSVCR90` e `USER32` com
   semântica modelada (heap, seções críticas, TLS, mutex nomeado, tempo
   determinístico). Em 2026-11-09 o walk já fazia 5 141 chamadas de import.
3. **Fronteira declarada em vez de suposição** — quando o código entra num
   subsistema que não está levantado, o walk para e **nomeia o endereço**.

## O que ainda falta, e é onde aqueles projetos gastaram o tempo

1. **Tradução gráfica.** O Spore é Direct3D 9; Android não tem D3D9. É uma camada
   inteira, não um shim.
2. **Leitura dos assets no formato original.** `.package` de ~900 MB
   (`Spore_Content`, `Spore_Graphics`, `Spore_Audio*`), formato próprio.
3. **Threads de verdade.** O guest é hoje single-thread com seções críticas
   modeladas. Quando o scheduler do engine aparecer, vira decisão de arquitetura.

## Trilho de trabalho

- Boot fiel. Nada de "atalho de exibição" apresentado como boot.
- Um muro por vez, sempre nomeado por endereço (`failed_at=0x...`, `fault=...`).
- Medir → implementar → validar x86 × ARM64 no aparelho → relatar → aguardar
  autorização.
- Não inflar closure: só semear o que a evidência provou necessário; janela de
  dados só com limites lidos do arquivo.
- Erro de fixture é erro meu, e entra no relatório como tal.
- Nunca commit nem push: o autor do projeto commita.

## Riscos a verificar, não fatos

- **Scripting embutido.** Se o boot chamar a camada de script do engine, é mais um
  runtime para integrar. Verificar quando o walk chegar lá.
- **Número de inicializadores.** A tabela caminhada pelo CRT tem 31 266 entradas
  não nulas; ver `test-logs/boot-entry-20261108/report-cpp-batch-13-init-table.md`
  para a prova de que os limites vêm do binário e de que todas as entradas são
  ponteiros de código — e para o que esse número **não** significa.
