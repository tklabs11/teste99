# Investigação da tabela de inicializadores C++ (sem expansão)

Data: 2026-11-08
PE de referência: `C:\SporeAnalysis\SporeApp.exe`
SHA-256: `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
Limite do prefixo ao começar: `0x011e0f98`. Nenhuma tradução nova foi feita.

## 1. Os dois argumentos de `_initterm` (bytes originais)

Bytes crus do PE em `0x011e0f85..0x011e0f9d`:

```
a14ce77101  MOV   EAX,[0x0171e74c]      ; __native_startup_state
3bc6        CMP   EAX,ESI               ; ESI = 1 (__initializing)
751b        JNZ   0x011e0fa9            ; não tomado
6898b03e01  PUSH  0x013eb098            ; empilhado PRIMEIRO -> 2o argumento
680cc83c01  PUSH  0x013cc80c            ; empilhado DEPOIS   -> 1o argumento
e871050000  CALL  0x011e150e            ; JMP [0x013cc320] = MSVCR90.dll!_initterm
59          POP   ECX                  ; limpeza cdecl do 1o argumento
```

Em `__cdecl` o primeiro argumento é o **último** `PUSH`, então:

```
_initterm(begin = 0x013cc80c, end = 0x013eb098)
```

Três confirmações independentes:

1. **Ordem de `PUSH`** acima (`end` primeiro, `begin` depois).
2. **Estado no limite** (medido no lift x86 e no ARM64): `[ESP] = 0x013cc80c`,
   `[ESP+4] = 0x013eb098`, `ESP = entry-0x84` com as duas `PUSH` pendentes, e
   `0x011e0f9d` faz `POP ECX` (limpeza do chamador) logo depois do `CALL`.
3. **Semântica do laço**: `_initterm` percorre enquanto `pfbegin < pfend`, logo
   `begin` tem de ser o endereço menor, e `0x013cc80c < 0x013eb098`.

`0x011e150e` é thunk de import: `ff 25 20 c3 3c 01` = `JMP [0x013cc320]`, e a
IAT resolve `MSVCR90.dll!_initterm` (conferido também que `0x013cc31c` é
`_initterm_e`, o thunk vizinho usado antes).

## 2. Os 31.266 valores são ponteiros de código

### Estrutura da faixa

| Medida | Valor |
| --- | --- |
| Faixa | `0x013cc80c..0x013eb098`, `.rdata` cru, 125.068 bytes |
| Slots | 31.267 |
| Nulos dentro da faixa | **1**, exatamente o primeiro slot |
| Entradas não nulas | 31.266, todas distintas |
| Faixa dos alvos | `0x011e0e95 .. 0x013bc960`, todos em `.text` |

O nulo inicial é o marcador de grupo do linker. A vizinhança mostra o padrão
`.CRT$X*` completo:

```
0x013cc7f8 00000000   fim do grupo anterior
0x013cc7fc 0110973a
0x013cc804 01109716
0x013cc808 00000000   marcador
0x013cc80c 00000000   <-- begin (__xc_a)
0x013cc810 011e0e95   primeira entrada
...
0x013eb094 013bc960   última entrada
0x013eb098 00000000   <-- end (__xc_z)
0x013eb09c 00000000   __xi_a
0x013eb0a0 011e10bf   tabela do _initterm_e
0x013eb0ac 00000000   __xi_z
```

Não há subdivisões: nenhum nulo no meio da faixa.

### Os alvos são funções de verdade

Cada entrada aponta para uma função curta, separada da próxima por padding
`CC`. Exemplos lidos do PE:

```
0x013bc900  f3 0f 10 05 7c724f01   MOVSS XMM0,[0x014f727c]
            f3 0f 11 05 f4e67101   MOVSS [0x0171e6f4],XMM0
            c3                     RET

0x013bc940  a1 9c426e01            MOV EAX,[0x016e429c]
            a3 840b5d01            MOV [0x015d0b84],EAX
            c7 05 9c426e01 800b5d01 MOV DWORD [0x016e429c],0x015d0b80
            c3                     RET

0x013000d0  68 007c6601            PUSH 0x01667c00
            ff 15 d0c23c01         CALL [InitializeCriticalSection]
            68 400d3c01            PUSH 0x013c0d40
            e8 0a07eeff            CALL 0x011e0b39
            59                     POP ECX
            c3                     RET
```

Distribuição do primeiro byte em todas as 31.266 entradas:

| Primeiro byte | Interpretação | Ocorrências |
| --- | --- | --- |
| `0x33` | `XOR r32,r/m32` | 8.391 |
| `0x55` | `PUSH EBP` | 7.360 |
| `0xF3` | `MOVSS`/`MOVSD` (prefixo) | 5.225 |
| `0x0F` | instrução SSE de dois bytes | 4.156 |
| `0x83` | grupo ALU com imediato | 2.200 |
| `0x68` / `0x6A` | `PUSH imm32` / `PUSH imm8` | 2.275 |
| `0xA1` | `MOV EAX,[moffs]` | 758 |
| `0xB9` / `0xDD` / `0xD9` | `MOV ECX,imm` / x87 | 783 |
| `0x8D` / `0xE8` / `0x53` / `0x51` | `LEA` / `CALL` / `PUSH` | 47 |
| restantes | prefixos e `MOV r8,r/m8` | 71 |

### Confirmação por desmontagem (amostra de 24 entradas)

Exportei 24 entradas (primeiras 8, índices 4096-4099, 16384-16387 e últimas 8)
e desmontei com Ghidra (`DisassembleSporeRoutines`):

- **24/24** desmontaram por completo, sem `decode failed`;
- **24/24** terminam em `RET`;
- cada corpo cabe exatamente no seu slot, antes do padding `CC`;
- instruções por rotina: 3, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6,
  7, 7, 11, 13, 18 (total 143; mediana 5,5).

### Custo medido do conjunto

| Medida | Valor |
| --- | --- |
| Rotinas a traduzir | **31.266** |
| Código somado (até o padding) | **1.996.940 bytes** (~2,0 MB) |
| Padding `CC` descartado | 286.938 bytes |
| Tamanho por rotina (min/mediana/max) | 5 / 26 / 4.096 bytes |
| Distribuição | 1.106 até 8 B; 995 até 16 B; 14.876 até 32 B; 8.286 até 64 B; 3.589 até 128 B; 1.415 até 256 B; 999 maiores |
| Instruções estimadas | ~460 mil (1,997 MB a ~4,3 B por instrução) |

### O que as rotinas chamam (amostra)

Das 24 amostradas, **17 não chamam nada** (só stores constantes e `MOVSS`). As 7
que chamam usam apenas:

- imports: `KERNEL32!InitializeCriticalSection`, `KERNEL32!TlsAlloc`,
  `MSVCR90!__getmainargs`;
- internos: `0x011e07ef` (12 instruções, helper de CRT, aparece em 5),
  `0x00935b70` (78 instruções, **guard de instância única**: `CreateMutexA`,
  `WaitForSingleObject`, `wsprintfA`, `_strtoui64`, `sprintf`,
  `GetEnvironmentVariableA`, `SetEnvironmentVariableA`), `0x00f474d0`
  (21 instruções), `0x010802b0` (20 instruções, sem chamadas).

Ou seja: a maioria das raízes é folha, mas as poucas que não são puxam código de
engine e **nova superfície de API** (USER32 no guard de instância).

### Limitação de ferramenta registrada

O inventário Ghidra do projeto (`spore_functions_current.csv`, 57.801 funções)
identifica só **9.351** dos 31.266 alvos como entradas de função. Isso não é
evidência de que os outros 21.915 sejam dados: a análise do projeto está
incompleta, é o mesmo motivo pelo qual `0x011e10bf`, `0x011e1304` e `0x011e135a`
"não existiam" antes. A desmontagem por endereço cobre o que o inventário não
cobre.

## 3. Cabeça e cauda contra a imagem PE original

Conversão VA, seção e offset de arquivo, lendo os bytes crus:

| Registro | VA | Seção | Offset | Valor |
| --- | --- | --- | --- | --- |
| slot inicial (nulo) | `0x013cc80c` | `.rdata` | `0xfcbc0c` | `0x00000000` |
| primeira entrada | `0x013cc810` | `.rdata` | `0xfcbc10` | `0x011e0e95` |
| segunda entrada | `0x013cc814` | `.rdata` | `0xfcbc14` | `0x013000d0` |
| última entrada | `0x013eb094` | `.rdata` | `0xfea494` | `0x013bc960` |
| slot final (nulo) | `0x013eb098` | `.rdata` | `0xfea498` | `0x00000000` |

Comparações feitas:

1. **Arquivo contra leitura por VA** (primeiros `0x40` bytes): idênticos.
2. **Janela emitida no guest contra o arquivo**: a região `cpp_initializer_head`
   (`0x013cc80c` mais `0x40`, origem `raw`) do header gerado é byte a byte igual
   ao arquivo.
3. **Runtime x86 e ARM64**: o `DETAIL` do estágio registra
   `walk_called=0x011e0e95 walk_missing=0x013000d0` nos dois lados, ou seja o
   guest leu exatamente os valores do arquivo.

Nenhuma entrada depende de realocação: a imagem não tem seção `.reloc`
(`/FIXED`), então o loader não ajusta esses ponteiros.

## 4. Consequência para a tradução

`_initterm` chama **toda** entrada não nula, na ordem do array:

```c
while (pfbegin < pfend) { if (*pfbegin) (**pfbegin)(); ++pfbegin; }
```

Como só existe um nulo (o marcador inicial), **não há subconjunto pulável**: as
31.266 rotinas são necessárias, na ordem da tabela. Priorizar algumas e pular
outras produziria um walk que diverge do original no primeiro pulo.

A única economia possível é provar que alguma ramificação interna nunca é
tomada, e isso exige executar, não inspecionar a tabela.

## 5. Estado

Nada foi traduzido nesta etapa. O prefixo continua em `0x011e0f98`, os sete
estágios seguem verdes, e a decisão de como atacar as 31.266 rotinas fica em
aberto.

- [medição da tabela](./cpp-initializer-table.json)
- [amostra desmontada](./cpp-initializer-sample.json)
- [helpers internos](./cpp-initializer-helpers.json)
