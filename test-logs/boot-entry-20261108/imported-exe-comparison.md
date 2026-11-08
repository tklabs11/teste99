# Executável importado no Android — 2026-11-08

O usuário selecionou a raiz da instalação corretamente. O pacote debug
`dev.sporeport.cellstage.dev` contém
`files/Spore/SporeBin/SporeApp.exe` (21.219.840 bytes), copiado da instalação
que atualmente funciona no PC. Seu SHA-256 medido no aparelho por
`adb shell sha256sum` é
`fb66afc320730dec6f80b79301c7c525689859e3d0a99616b657559e8f11a1ae`.
O executável da expansão em `SporebinEP1` tem hash
`27ec1f63f76d3c5b21fb41bc250b45a4a1e8b3e6384604a23042981e0170f00b`.
O app exige o PE de referência
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
(21.219.328 bytes), portanto a frase anterior “aguardando importação
completa” era enganosa: havia um EXE copiado, mas de outra versão.

Uma cópia de análise do EXE do aparelho foi obtida com `adb pull` em
`C:\Users\wesll\AppData\Local\Temp\spore-device-current-base.exe`, fora do
repositório. `pefile` confirmou PE32 x86, base `0x00400000` e entrada
`0x011e11a0` nos dois arquivos. `.rdata`, `.data`, `.tls`, `CONST` e a
primeira seção `.rsrc` são idênticas byte a byte. A seção `.text` difere em
**516 bytes**, distribuídos em 82 sequências, todos entre os VAs
`0x00401899` e `0x00418116`. A última seção `.rsrc` também difere e é
512 bytes maior no arquivo importado.

Os bytes comparados nos VAs `0x011e11a0` (entrada, 10 bytes),
`0x011e1548` (cookie, 150 bytes), `0x00f47ed0` (inicializador, 32 bytes),
`0x00a33600` (construtor, 64 bytes), `0x00921260` (64 bytes) e
`0x00a23780` (64 bytes) são iguais nas duas versões. Como toda diferença
em `.text` está abaixo de `0x00500000`, os bytes das funções do Marco 7
acima desse endereço permanecem iguais. Isso **não** prova equivalência do
boot inteiro: chamadas ou dados de recurso podem alcançar as regiões
modificadas. O hash global novo ainda não foi autorizado como referência
para executar a closure completa.

O aplicativo foi ajustado para distinguir “EXE ausente” de “EXE presente com
hash diferente”. `./gradlew.bat :app:assembleDebug --offline` passou;
`adb install -r` preservou os dados do debug APK. A
[hierarquia de UI após a atualização](apk-import-diagnostic-ui.xml) mostra
o caminho e os hashes esperado/encontrado, em vez de dizer que a importação
está pendente. Nenhum arquivo do jogo foi alterado ou removido.

## Compatibilidade delimitada das sondas — continuação

Uma segunda verificação percorreu os registros exportados das 606 funções
da [closure da entrada](entry-closure.json), comparando cada instrução com
ambos os arquivos. O [resultado reproduzível](current-pe-closure-comparison.json)
foi **606 funções, 42.996 instruções, 128.601 bytes e zero divergências**.
Comando:

```powershell
python tools/batch_static_lift/compare_pe_closure.py `
  --reference 'C:\Program Files (x86)\Steam\steamapps\common\Spore\SPOREFILES\SporeBin\SporeApp.exe' `
  --candidate 'C:\Users\wesll\AppData\Local\Temp\spore-device-current-base.exe' `
  --closure test-logs/boot-entry-20261108/entry-closure.json `
  --output test-logs/boot-entry-20261108/current-pe-closure-comparison.json
```

Isso autoriza apenas a reutilização dos bytes de código verificados nas
sondas existentes. Os 501 callsites indiretos da closure, a seção de recursos
modificada e o estado real de boot permanecem fora dessa prova.

O hash exato da versão atual foi aceito para as **sondas nativas existentes**.
O [APK debug recompilou](current-variant-apk-build.log) e foi instalado com
`adb install -r`, preservando os arquivos importados. A
[tela inicial no aparelho](apk-current-variant-ui.xml) identifica a variante
e deixa o botão Marco 1 habilitado. Ao acioná-lo, a
[tela de resultado](apk-current-variant-marco1-ui.xml) mostrou
`FUN_00461520 recompilada em ARM64: PASS`, 91/91 buscas verificadas e a
chave `0xb1c3e5b6 → mean`. [59 testes Python](current-variant-python-tests.log)
passaram e `git diff --check` não encontrou erros. Isso não executa o boot
nem o menu do Spore; o botão Marco 7 continua uma fixture independente.
