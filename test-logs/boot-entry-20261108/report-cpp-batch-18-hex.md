# A imagem do guest vira texto hexadecimal (2026-11-10/11)

Continuação de `report-cpp-batch-17-ran192.md`. Este passo não mexe em nenhuma
instrução do guest: ele mexe em **como os bytes da imagem chegam ao compilador**.
O motivo é de tempo, não de correção — e a prova é que a linha `PASS` saiu
**byte a byte igual** à do formato anterior.

Identidade da PE: SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.

## 1. O problema: um header que cresce sete vezes mais rápido que o dado

`generate_initterm_guest_image.py` materializava a imagem como um array de bytes
em C++:

```cpp
inline constexpr std::uint8_t kBatchGuestImage[] = {
    0x4du, 0x5au, 0x90u, ...
};
```

Isso custa ~7 caracteres por byte (`0x`, dois dígitos hex, `u`, `,`, quebra de
linha). Enquanto a imagem tinha dezenas de KB, era irrelevante. Quando o walk da
tabela de inicializadores empurrou a janela até a tabela inteira, a imagem foi
para **139 644 bytes** e o header para:

| formato | tamanho do header | caracteres por byte de imagem |
| --- | --- | --- |
| array de bytes (`0xXXu,`) | **1 063 891 bytes** | ~7,6 |
| texto hex (2 chars/byte) | **326 161 bytes** | ~2,3 |

Redução de **737 730 bytes**, isto é, **3,26×** menor. E, mais importante que o
número absoluto: o custo passa a crescer a ~2,3 caracteres por byte de imagem em
vez de ~7,6, então cada KB novo de janela deixa de custar o triplo.

## 2. Por que hex, e não as duas alternativas óbvias

- **`.incbin`** resolve isso em uma linha na maioria dos montadores e é o que os
  projetos de referência usam no GNU toolchain. **O MSVC não tem `.incbin`.** O
  build x86 do harness é `cl`, então a solução não existe do lado que mais
  compila.
- **base64** custa 4 caracteres por 3 bytes (1,33/byte), melhor que hex. Mas
  exige uma tabela de alfabeto e um decodificador com tratamento de `=` e de
  bits sobrando. Hex precisa de uma função de uma linha (`0-9a-f`) e o
  comprimento declarado já diz se algo veio faltando.

Ou seja: hex é o ponto onde o transporte é **auto-verificável sem tabela** — se
`kBatchGuestImageHex.size() != bytes * 2`, o guest falha alto antes de mapear
qualquer região.

## 3. O que foi gerado

`generate_initterm_guest_image.py` passou a emitir:

```cpp
inline constexpr std::uint32_t kBatchGuestImageBytes = 0x000221dcu;
// The same bytes as hex text, two characters per byte.
inline constexpr std::string_view kBatchGuestImageHex =
    "4d5a90...";
```

em pedaços de 120 caracteres por linha (`hex_literal_lines(blob, width=120)`),
para não criar linhas de 280 mil caracteres que alguns editores e o próprio `cl`
tratam mal.

Do lado do guest, `boot_entry_crt_harness.cpp` ganhou:

```cpp
int hex_nibble(char digit);                                  // -1 fora de 0-9a-f
bool decode_guest_image(std::uint8_t* out, std::size_t bytes);
```

`decode_guest_image` recusa **duas** coisas, e as duas seriam falhas silenciosas
no formato antigo:

1. comprimento diferente de `bytes * 2` — a imagem viria curta e a tabela de
   regiões indexaria além do buffer;
2. qualquer caractere fora de `0-9a-f` minúsculo.

O caminho de falha é explícito: `FAIL crt_entry decode_guest_image` e saída 1,
antes de qualquer `map_region`.

## 4. O resultado: a mesma linha, byte a byte

Rodado em 2026-11-10, imagem hex, `--initializers 384`:

```
PASS crt_cpp_walk stop=0x011e0f98 failed_at=0x0121fac0 executed=107 esp_delta=-136
     ebp=entry-4 cookie=consistent imports=5322 initializers=384 ran=384
     last_ran=0x0121fab0 walk=stopped_at_0x0121fac0 args=argc1,argv_guest,envp_empty
     sections=8 tls=2 guard=single_instance node=0x5e000010 count=9
     mutex=SingleMgrMutex00001234 encoded=5e000010 neutralized=0x011e073e/244/3/0
     buf=0x01668994 n_sizes=2 fault=none@0x00000000/0 pc=0x00000000
     near=0x00000000+0x0
```

Comparação literal com a execução anterior (imagem de 1 MB, 21:14 de 2026-11-10):
**as duas linhas são idênticas**. `ran=384`, `imports=5322`, `executed=107`,
`sections=8`, `neutralized`, `buf=`, `n_sizes=2` — nada mudou. O transporte é
invisível para o comportamento, que é exatamente o que se queria.

`PASS arm64_build` também saiu, com o mesmo header compilado por `clang`. Na
primeira execução o `arm64_device_run` **não** rodou: o push ADB falhou porque não
havia device conectado na hora (celular desplugado de madrugada). Reexecutada a
suíte completa com o aparelho presente:

```
PASS 32   FAIL 0   SKIP 3      (8 estágios, x86 + ARM64 + aparelho)
PASS x86_vs_arm64   (linha idêntica à do x86)
PASS arm64_device_run stage=cpp-walk-initializers serial=PJMZAEJRX4YLFIDI
```

Os 3 SKIP são os `original_x86_real_win32` de desenho — o CRT real inicializa o
processo, então não há o que comparar nesses estágios.

## 5. O custo, medido

| etapa | imagem 1 MB | imagem hex |
| --- | --- | --- |
| geração concluída | 21:15:03 | 21:46:52 |
| `PASS crt_cpp_walk` (build + link + run x86) | 21:35:59 | 22:02:55 |
| **duração da metade x86 do stage** | **20m56s** | **16m03s** |

Cerca de **23% menos** tempo na metade x86 do stage. Ressalva honesta: são duas
medições únicas, em estados de máquina diferentes, não um benchmark controlado.
O ganho que importa não é esse número — é a inclinação: com ~2,3 chars/byte em
vez de ~7,6, subir a imagem de 139 KB para 300 KB custa ~700 KB de header em vez
de ~2,3 MB.

## 6. Testes

`test_static_batch_lift.py`: **122 testes** (eram 119). Três novos em
`GuestImageHexTransportTests`, e o terceiro é o que amarra os dois lados:

- `test_hex_literals_round_trip_to_the_blob` — concatenar as linhas e
  `bytes.fromhex` devolve exatamente o blob.
- `test_every_line_stays_inside_the_requested_width` — nenhuma linha passa de
  120 caracteres; 500 bytes dão 9 linhas, só a última curta.
- `test_the_alphabet_is_the_one_the_cpp_decoder_accepts` — o alfabeto emitido é
  exatamente `0-9a-f`. Isso não é redundante: `hex_nibble` do lado C++ recusa
  maiúsculas, então uma mudança para `.hex().upper()` falharia fechada no guest,
  e o teste avisa antes de um build de 16 minutos.

## 7. Limites

- `ran=384` continua sendo **384 de 31 266** inicializadores (1,2%). Nada de
  boot, menu, render ou gameplay.
- O transporte hex só foi provado até onde a imagem atual chega (139 644 bytes,
  62 regiões). Se a imagem passar de alguns MB, `std::string_view` de 2N
  caracteres ainda é grande; aí sim vale reconsiderar.
- `arm64_device_run`: na primeira execução ficou pendente por falta de device
  conectado; a suíte reexecutada com o aparelho presente passou nos 8 estágios.
- O muro atual segue sendo o lote esgotado em `0x0121fac0`.

## 8. Arquivos

Novos: este relatório.

Modificados: `generate_initterm_guest_image.py` (emissão hex +
`hex_literal_lines`), `boot_entry_crt_harness.cpp` (`hex_nibble`,
`decode_guest_image`, falha fechada), `test_static_batch_lift.py` (3 testes).
