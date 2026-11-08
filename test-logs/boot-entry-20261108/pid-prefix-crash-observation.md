# Abort observado no primeiro run ARM64 dos estágios `GetCurrentProcessId`

## O que foi observado

Na primeira execução de `run_boot_pid_prefix_tests.ps1 -DeviceSerial
PJMZAEJRX4YLFIDI` no aparelho, cada estágio imprimiu a linha de PASS e, em
seguida, o processo emitiu:

```
*** stack smashing detected ***:  terminated
```

Trecho do console do operador:

```
PASS arm64_build target=aarch64-linux-android29
*** stack smashing detected ***:  terminated
PASS x86_vs_arm64 PASS pid_prefix boundary=0x011e158b executed=20 ...
*** stack smashing detected ***:  terminated
PASS x86_vs_arm64 PASS pid_prefix boundary=0x011e1591 executed=21 ...
PASS arm64_device_run serial=PJMZAEJRX4YLFIDI
```

Fatos que isso estabelece:

- as duas linhas de PASS foram produzidas pelo binário ARM64 antes do aborto;
- o script aceitou o run porque só procurava por linhas `^PASS ` e o código de
  saída não chegou como diferente de zero pelo ADB.

## O que foi verificado depois

O mesmo binário, recompilado e executado pelo ADB, não abortou em nenhuma das
execuções abaixo:

| Verificação | Execuções | Falhas |
| --- | --- | --- |
| Run direto `pid-call-prefix` | 40 | 0 |
| Loop `sh` com stdout suprimido | 100 | 0 |
| Stress `sh` com guardas, 2 estágios × 150 | 300 | 0 |
| `run_boot_pid_prefix_tests.ps1` completo com aparelho | 3 | 0 |

Ver [stress no aparelho](./pid-prefix-stress-arm64.log).

Nenhuma cópia do texto de aborto sobreviveu nos logs do repositório: o
arquivo `pid-call-prefix-arm64.log` foi reescrito pelos runs seguintes antes da
investigação. O texto acima é a evidência disponível.

## O que foi alterado para não passar em silêncio nem perder o diagnóstico

1. `boot_cookie_pid_prefix_harness.cpp` agora cerca a página de dados do PE com
   palavras de guarda (`0xa5` antes, `0x5a` depois) e arma uma região de guarda
   em `0x70000300`–`0x700003ff` acima do `ESP` inicial da pilha guest. Uma
   escrita fora dos limites da fixture passa a falhar com diagnóstico
   explícito (`data_guard=0` ou `stack_guard=0`) em vez de depender do canário
   do compilador.
2. `run_boot_pid_prefix_tests.ps1` rejeita qualquer linha de saída que não seja
   `PASS ` ou `DETAIL `, tanto no x86 quanto no ARM64. Um aborto com mensagem do
   sistema agora reprova o run mesmo que o código de saída chegue como zero.

## Estado e risco residual

- Os dois estágios continuam aprovados no aparelho com a versão atual:
  `0x011e158b` (20 instruções) e `0x011e1591` (21 instruções).
- O aborto não foi reproduzido em mais de 440 execuções após a observação, com
  o mesmo compilador e as mesmas flags (`-O2 -Wall -Wextra -Werror`,
  `aarch64-linux-android29`).
- A causa raiz permanece desconhecida. Não há evidência de que o lift escreva
  fora da memória guest: os acessos do runtime são verificados por região e as
  guardas novas não acusaram nada.
- Se o aborto voltar, o runner agora falha e as guardas indicam se a origem é a
  fixture de dados, a pilha guest ou nenhuma das duas.
