# Segunda funcao real candidata

## Alvo observado

- Executavel SHA-256: `290703b34fe4573b242c3e271cc90568992abe6fb3fa9333a7341044a759fc74`
- Secao: `.text`
- RVA: `0xD58BE0`
- VA: `0x1158BE0`
- Tamanho observado: 125 bytes
- Corpo observado: 47 instrucoes
- Chamadas diretas internas: nenhuma observada

## Semantica estatica

O corpo usa `ecx` como contador, `esi` como vetor origem, `edi` como vetor destino e `st(1)` como
uma constante carregada por `fld`.

Os offsets observados no frame sao:

- `[ebp + 8]`: contador
- `[ebp + 12]`: escalar de 32 bits
- `[ebp + 16]`: ponteiro origem
- `[ebp + 20]`: ponteiro destino

A estrutura corresponde a uma operacao vetorial:

```cpp
for (size_t i = 0; i < count; ++i) {
    destination[i] += scalar * source[i];
}
```

O x86 contem primeiro um processamento de sobras e depois blocos de quatro elementos. O bloco
unravelado processa elementos em ordem decrescente de indice dentro da palavra do contador.

## Estado da reconstrucao

Esta e uma reconstrucao semantica baseada em disassemblagem. O corpo exato de 125 bytes foi
executado com Unicorn usando o SHA-256 do executavel original em casos de `count` igual a
0, 1, 3, 4, 5, 7 e 9. Todos os resultados `float32` bateram com um modelo independente.

A identidade pelo nome da funcao ou pelos callers ainda nao foi recuperada. Convencao de
chamada, validade dos ponteiros, simetria de NaN, sinal de infinito e aritmetica estendida
ainda precisam de evidencia adicional antes de uma garantia de equivalencia completa.

## Implementacao ARM64 de referencia

O arquivo `lifted_array_kernel.cpp` implementa o candidato como uma API C simples e executa um
vetor de oito elementos. O arquivo `test_lifted_array_kernel.py` fornece um modelo independente para
comparar o checksum.

## Limites

- O candidato nao foi confirmado por callers.
- O nome da funcao nao foi recuperado.
- A implementacao ARM64 ja foi executada no aparelho real, mas ainda nao foi comparada dinamicamente
  contra o corpo x86 original para vetores aleatorios.
- O resultado nao representa o jogo em execucao nem um bloco de gameplay completo.
