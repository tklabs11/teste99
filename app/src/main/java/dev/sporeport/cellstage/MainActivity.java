package dev.sporeport.cellstage;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.system.ErrnoException;
import android.system.Os;
import android.os.Bundle;
import android.provider.DocumentsContract;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;
import java.io.ByteArrayOutputStream;
import java.security.MessageDigest;
import java.util.Locale;
import java.net.HttpURLConnection;
import java.net.URL;

public final class MainActivity extends Activity {
    private static final int REQUEST_IMPORT_FOLDER = 1001;
    private static final int REQUEST_RUNTIME_ZIP = 1002;
    private static final String PREFS = "spore_port";
    private static final String KEY_IMPORT_URI = "import_uri";
    private static final String EXPECTED_SHA256 =
            "6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b";
    private static final String RUNTIME_DOWNLOAD_URL =
            "https://github.com/Arda9995/sch1levo-runtime/releases/download/"
            + "runtime-r4-wine11.0-box64-0.4.4/"
            + "sch1levo-runtime-r4-wine11.0-box64-0.4.4.zip";
    private static final String RUNTIME_SHA256 =
            "bec6ab018425b27109b62a32ff0322ca3a45f3b0546f44c48621763b9c3dddb8";
    private static final long RUNTIME_SIZE = 463804692L;

    static {
        System.loadLibrary("spore_native_runtime");
    }

    private TextView status;
    private TextView runtimeStatus;
    private Button importButton;
    private Button nativeChainButton;
    private Button dbpfResourceButton;
    private Button sdlTestButton;
    private Button launchButton;
    private Button cancelButton;
    private Button runtimeButton;
    private Button manualRuntimeButton;
    private ProgressBar progress;
    private boolean importing;
    private boolean importCancelled;
    private int totalFiles;
    private int importedFiles;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        buildUi();
        runtimeStatus.setText(nativeRuntimeInfo());
        refreshStatus();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (resultCode != RESULT_OK || data == null) {
            return;
        }
        if (requestCode == REQUEST_IMPORT_FOLDER) {
            Uri treeUri = data.getData();
            if (treeUri == null) {
                status.setText("Falha: nenhuma pasta foi selecionada.");
                return;
            }
            getContentResolver().takePersistableUriPermission(
                    treeUri, Intent.FLAG_GRANT_READ_URI_PERMISSION);
            getSharedPreferences(PREFS, MODE_PRIVATE).edit()
                    .putString(KEY_IMPORT_URI, treeUri.toString())
                    .apply();
            refreshStatus();
            importFolder(treeUri);
        } else if (requestCode == REQUEST_RUNTIME_ZIP) {
            Uri zipUri = data.getData();
            if (zipUri != null) {
                importRuntimeZip(zipUri);
            }
        }
    }

    @Override
    public void onBackPressed() {
        if (!importing) {
            super.onBackPressed();
        }
    }

    private void buildUi() {
        getWindow().setStatusBarColor(0xFF101A2A);
        getWindow().setNavigationBarColor(0xFF101A2A);

        LinearLayout root = new LinearLayout(this);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setBackgroundColor(0xFF101A2A);
        int padding = (int) (16 * getResources().getDisplayMetrics().density);
        root.setPadding(padding, padding, padding, padding);

        TextView title = new TextView(this);
        title.setText("Spore ARM64");
        title.setTextColor(0xFFEAF2F8);
        title.setTextSize(28);
        title.setPadding(0, 0, 0, padding / 2);

        TextView subtitle = new TextView(this);
        subtitle.setText("Recompilação estática — validação da instalação");
        subtitle.setTextColor(0xFFB5C8DA);
        subtitle.setTextSize(15);
        subtitle.setPadding(0, 0, 0, padding / 2);

        runtimeStatus = new TextView(this);
        runtimeStatus.setTextColor(0xFF80CBC4);
        runtimeStatus.setTextSize(14);
        runtimeStatus.setPadding(0, 0, 0, padding / 2);

        status = new TextView(this);
        status.setTextColor(0xFFDCE9F4);
        status.setTextSize(14);
        status.setPadding(0, 0, 0, padding / 2);
        status.setMinHeight((int) (72 * getResources().getDisplayMetrics().density));

        progress = new ProgressBar(this, null, android.R.attr.progressBarStyleHorizontal);
        progress.setIndeterminate(true);
        progress.setVisibility(View.GONE);

        importButton = new Button(this);
        importButton.setText("CHOOSER SPORE FOLDER");
        importButton.setAllCaps(false);
        importButton.setOnClickListener(v -> openFolderPicker());

        nativeChainButton = new Button(this);
        nativeChainButton.setText(R.string.native_chain_button);
        nativeChainButton.setAllCaps(false);
        nativeChainButton.setEnabled(false);
        nativeChainButton.setOnClickListener(v -> runNativeSporeChain());

        dbpfResourceButton = new Button(this);
        dbpfResourceButton.setText(R.string.dbpf_resource_button);
        dbpfResourceButton.setAllCaps(false);
        dbpfResourceButton.setEnabled(false);
        dbpfResourceButton.setOnClickListener(v -> loadOriginalCellResource());

        sdlTestButton = new Button(this);
        sdlTestButton.setText("Abrir teste de vídeo SDL2");
        sdlTestButton.setAllCaps(false);
        sdlTestButton.setOnClickListener(v -> new AlertDialog.Builder(this)
                .setTitle("Teste de vídeo nativo")
                .setItems(new String[]{
                        "SDL2 + OpenGL ES",
                        "SDL2 + Vulkan",
                        "Direct3D 9 via DXVK-native + Vulkan",
                        "Translated Spore graphics boundary probe (manual regression)",
                        "Translated Spore window-global increment",
                        "Translated Spore device-global increment"},
                        (dialog, which) -> {
                            Class<?> activityClass;
                            switch (which) {
                                case 0:
                                    activityClass = SDLTestActivity.class;
                                    break;
                                case 1:
                                    activityClass = SDLVulkanTestActivity.class;
                                    break;
                                case 2:
                                    activityClass = SDLDirect3D9TestActivity.class;
                                    break;
                                case 3:
                                    activityClass = SDLTranslatedGraphicsTestActivity.class;
                                    break;
                                case 4:
                                    activityClass =
                                            SDLTranslatedWindowGlobalTestActivity.class;
                                    break;
                                case 5:
                                    activityClass =
                                            SDLTranslatedDeviceGlobalTestActivity.class;
                                    break;
                                default:
                                    return;
                            }
                            startActivity(new Intent(this, activityClass));
                        })
                .show());

        runtimeButton = new Button(this);
        manualRuntimeButton = new Button(this);
        launchButton = new Button(this);
        launchButton.setEnabled(false);

        cancelButton = new Button(this);
        cancelButton.setText("Cancelar importação");
        cancelButton.setAllCaps(false);
        cancelButton.setEnabled(false);
        cancelButton.setOnClickListener(v -> {
            importCancelled = true;
            status.setText("Cancelando importação...");
            cancelButton.setEnabled(false);
        });

        root.addView(title);
        root.addView(subtitle);
        root.addView(runtimeStatus);
        root.addView(status, new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT));
        root.addView(progress, new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                (int) (8 * getResources().getDisplayMetrics().density)));
        root.addView(importButton, new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT));
        root.addView(nativeChainButton, new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT));
        root.addView(dbpfResourceButton, new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT));
        root.addView(sdlTestButton, new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT));
        root.addView(cancelButton, new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT));
        setContentView(root);
    }

    private void openFolderPicker() {
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT_TREE);
        intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION
                | Intent.FLAG_GRANT_PERSISTABLE_URI_PERMISSION);
        intent.putExtra(DocumentsContract.EXTRA_INITIAL_URI,
                DocumentsContract.buildRootsUri("com.android.externalstorage.documents"));
        startActivityForResult(intent, REQUEST_IMPORT_FOLDER);
    }

    private void openRuntimePicker() {
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        intent.addCategory(Intent.CATEGORY_OPENABLE);
        intent.setType("application/zip");
        intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
        startActivityForResult(intent, REQUEST_RUNTIME_ZIP);
    }

    private void downloadRuntime() {
        runtimeButton.setEnabled(false);
        manualRuntimeButton.setEnabled(false);
        progress.setVisibility(View.VISIBLE);
        progress.setIndeterminate(false);
        progress.setMax(1000);
        progress.setProgress(0);
        status.setText("Baixando runtime ARM64...");

        new Thread(() -> {
            File archive = new File(getExternalFilesDir(null),
                    "sch1levo-runtime-r4-wine11.0-box64-0.4.4.zip");
            try {
                URL url = new URL(RUNTIME_DOWNLOAD_URL);
                HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                connection.setInstanceFollowRedirects(true);
                connection.setConnectTimeout(30_000);
                connection.setReadTimeout(120_000);
                connection.connect();

                int responseCode = connection.getResponseCode();
                if (responseCode < 200 || responseCode >= 300) {
                    throw new IOException("Download HTTP " + responseCode);
                }
                long contentLength = connection.getContentLengthLong();
                if (contentLength > 0) {
                    progress.setMax((int) Math.min(1000, contentLength));
                }

                try (InputStream input = connection.getInputStream();
                     OutputStream output = new FileOutputStream(archive)) {
                    byte[] buffer = new byte[1024 * 1024];
                    long downloaded = 0;
                    int count;
                    long lastUpdate = 0;
                    while ((count = input.read(buffer)) != -1) {
                        output.write(buffer, 0, count);
                        downloaded += count;
                        long now = System.currentTimeMillis();
                        if (now - lastUpdate >= 250) {
                            lastUpdate = now;
                            long current = downloaded;
                            runOnUiThread(() -> {
                                if (progress.isIndeterminate()) {
                                    progress.setIndeterminate(false);
                                    progress.setMax(1000);
                                }
                                int percent = contentLength > 0
                                        ? (int) (current * 1000 / contentLength)
                                        : 0;
                                progress.setProgress(percent);
                                status.setText("Baixando runtime ARM64... "
                                        + formatBytes(current) + (contentLength > 0
                                        ? " / " + formatBytes(contentLength) : ""));
                            });
                        }
                    }
                } finally {
                    connection.disconnect();
                }

                if (archive.length() != RUNTIME_SIZE) {
                    throw new IOException("Tamanho inesperado: " + archive.length()
                            + " bytes (esperado " + RUNTIME_SIZE + ")");
                }
                String hash = sha256(archive);
                if (!RUNTIME_SHA256.equalsIgnoreCase(hash)) {
                    throw new IOException("SHA-256 inesperado: " + hash);
                }

                runOnUiThread(() -> status.setText(
                        "Download verificado.\nExtraindo runtime ARM64..."));
                installRuntimeFile(archive);
            } catch (Throwable e) {
                archive.delete();
                runOnUiThread(() -> {
                    progress.setVisibility(View.GONE);
                    status.setText("Falha no download automático: "
                            + e.getMessage() + "\nVocê pode tentar pelo botão ZIP manual.");
                    runtimeButton.setEnabled(true);
                    manualRuntimeButton.setEnabled(true);
                });
            }
        }).start();
    }

    private String formatBytes(long bytes) {
        if (bytes < 1024L * 1024L) {
            return bytes / 1024L + " KB";
        }
        return String.format(Locale.US, "%.1f MB", bytes / (1024.0f * 1024.0f));
    }

    private File getRuntimeDir() {
        return new File(getFilesDir(), "compat-runtime");
    }

    private void refreshStatus() {
        SharedPreferences prefs = getSharedPreferences(PREFS, MODE_PRIVATE);
        String uri = prefs.getString(KEY_IMPORT_URI, null);
        File installed = new File(getExternalFilesDir(null), "Spore");
        File exe = findVerifiedSporeExe(installed);
        File gamePackage = findSporeGamePackage(installed);
        dbpfResourceButton.setEnabled(gamePackage.isFile() && !importing);
        File runtimeDir = getRuntimeDir();
        File runtimeWrapper = findRuntimeWrapper(runtimeDir);
        if (exe.isFile()) {
            String hash = sha256(exe);
            if (EXPECTED_SHA256.equalsIgnoreCase(hash)) {
                status.setText("EXE encontrado e verificado\n" + exe.getAbsolutePath());
                launchButton.setEnabled(runtimeWrapper != null);
                nativeChainButton.setEnabled(true);
            } else {
                status.setText("EXE encontrado, mas SHA-256 diferente\nEsperado: "
                        + EXPECTED_SHA256 + "\nRecebido: " + hash);
                launchButton.setEnabled(false);
                nativeChainButton.setEnabled(false);
            }
        } else if (uri != null) {
            status.setText("Pasta configurada, aguardando importação completa.\n" + uri);
            nativeChainButton.setEnabled(false);
        } else {
            status.setText("Nenhuma instalação do Spore importada.");
            nativeChainButton.setEnabled(false);
        }
    }

    private void runNativeSporeChain() {
        File root = new File(getExternalFilesDir(null), "Spore");
        File exe = findVerifiedSporeExe(root);
        String actualHash = exe.isFile() ? sha256(exe) : "ausente";
        if (!EXPECTED_SHA256.equalsIgnoreCase(actualHash)) {
            status.setText(R.string.native_chain_blocked);
            nativeChainButton.setEnabled(false);
            return;
        }

        nativeChainButton.setEnabled(false);
        importButton.setEnabled(false);
        status.setText(R.string.native_chain_running);
        new Thread(() -> {
            String result;
            try {
                result = nativeSporeLookup(exe.getAbsolutePath(), 0xB1C3E5B6);
            } catch (RuntimeException error) {
                result = getString(R.string.native_chain_failure, error.getMessage());
            }
            String renderedResult = result;
            boolean passed = renderedResult.startsWith(
                    "FUN_00461520 recompilada em ARM64: PASS");
            String verifiedResult = passed
                    ? "MARCO 1 — EXECUÇÃO REAL PASS\n"
                            + "PE original verificado: SHA-256 " + actualHash + "\n"
                            + renderedResult
                    : renderedResult;
            runOnUiThread(() -> {
                status.setText(verifiedResult);
                importButton.setEnabled(true);
                nativeChainButton.setEnabled(true);
            });
        }).start();
    }

    private void loadOriginalCellResource() {
        File root = new File(getExternalFilesDir(null), "Spore");
        File gamePackage = findSporeGamePackage(root);
        if (!gamePackage.isFile()) {
            status.setText("Spore_Game.package não foi encontrado na instalação importada.");
            dbpfResourceButton.setEnabled(false);
            return;
        }

        dbpfResourceButton.setEnabled(false);
        importButton.setEnabled(false);
        status.setText(R.string.dbpf_resource_running);
        new Thread(() -> {
            String result;
            try {
                final String resourceName = "cell_Eggkid";
                long instanceHash = nativeSporeNameHash(resourceName);
                if (instanceHash != 0x7ADE24E1L) {
                    throw new IllegalStateException(String.format(
                            Locale.US,
                            "Unexpected FNV-1 instance hash for %s: 0x%08X",
                            resourceName,
                            (int) instanceHash));
                }
                byte[] resource = nativeReadDbpfResource(
                        gamePackage.getAbsolutePath(),
                        0xDFAD9F51,
                        0,
                        (int) instanceHash);
                result = String.format(
                        Locale.US,
                        "Semântica FUN_00932e80 FNV-1 (ASCII lowercase): %s -> 0x%08X\n"
                                + "DBPF TGI 0xDFAD9F51:0x00000000:0x%08X carregado\n"
                                + "Arquivo: %s\nBytes descomprimidos: %d\nSHA-256: %s",
                        resourceName,
                        (int) instanceHash,
                        (int) instanceHash,
                        gamePackage.getName(),
                        resource.length,
                        sha256(resource));
            } catch (RuntimeException error) {
                result = getString(
                        R.string.dbpf_resource_failure, error.getMessage());
            }
            String renderedResult = result;
            runOnUiThread(() -> {
                status.setText(renderedResult);
                importButton.setEnabled(true);
                dbpfResourceButton.setEnabled(gamePackage.isFile());
            });
        }).start();
    }

    private File findSporeGamePackage(File root) {
        File[] candidates = new File[]{
                new File(root, "SPOREFILES/Data/Spore_Game.package"),
                new File(root, "Data/Spore_Game.package")
        };
        for (File candidate : candidates) {
            if (candidate.isFile()) {
                return candidate;
            }
        }
        return new File(root, "__missing_Spore_Game.package__");
    }

    private File findVerifiedSporeExe(File root) {
        if (!root.isDirectory()) {
            return new File(root, "__missing__");
        }
        File[] exactCandidates = new File[]{
                new File(root, "SPOREFILES/SporeBin/SporeApp.exe"),
                new File(root, "SporeBin/SporeApp.exe"),
                new File(root, "SporeApp.exe")
        };
        for (File candidate : exactCandidates) {
            if (candidate.isFile()
                    && EXPECTED_SHA256.equalsIgnoreCase(sha256(candidate))) {
                return candidate;
            }
        }
        return findSporeExeRecursively(root);
    }

    private File findSporeExeRecursively(File directory) {
        File[] children = directory.listFiles();
        if (children == null) {
            return new File(directory, "__missing__");
        }
        for (File child : children) {
            if (child.isDirectory()) {
                File result = findSporeExeRecursively(child);
                if (result.isFile()) {
                    return result;
                }
            } else if (child.getName().equalsIgnoreCase("SporeApp.exe")) {
                if (EXPECTED_SHA256.equalsIgnoreCase(sha256(child))) {
                    return child;
                }
            }
        }
        return new File(directory, "__missing__");
    }

    private void importRuntimeZip(Uri zipUri) {
        runtimeButton.setEnabled(false);
        manualRuntimeButton.setEnabled(false);
        status.setText("Extraindo runtime ARM64...");
        new Thread(() -> {
            try {
                File archive = new File(getExternalFilesDir(null), "manual-runtime.zip");
                try (InputStream source = getContentResolver().openInputStream(zipUri)) {
                    if (source == null) {
                        throw new IOException("Não foi possível abrir o ZIP do runtime.");
                    }
                    try (OutputStream output = new FileOutputStream(archive)) {
                        byte[] buffer = new byte[1024 * 1024];
                        int count;
                        while ((count = source.read(buffer)) != -1) {
                            output.write(buffer, 0, count);
                        }
                    }
                }
                installRuntimeFile(archive);
            } catch (Throwable e) {
                runOnUiThread(() -> {
                    status.setText("Falha ao instalar runtime: " + e.getMessage());
                    runtimeButton.setEnabled(true);
                    manualRuntimeButton.setEnabled(true);
                });
            }
        }).start();
    }

    private void installRuntimeFile(File archive) {
        new Thread(() -> {
            File runtimeDir = getRuntimeDir();
            try {
                deleteTree(runtimeDir);
                runtimeDir.mkdirs();
                try (InputStream source = new FileInputStream(archive)) {
                    extractZipSafely(source, runtimeDir, () -> false);
                }
                File wrapper = findRuntimeWrapper(runtimeDir);
                if (wrapper != null) {
                    wrapper.setReadable(true, true);
                    wrapper.setExecutable(true, true);
                }
                markExecutableFiles(new File(runtimeDir, "bin"));
                markExecutableFiles(new File(runtimeDir, "wine/lib/wine/x86_64-unix"));
                markExecutableFiles(new File(runtimeDir, "wine/bin"));

                String probe = probeRuntime(runtimeDir);
                String result = wrapper == null
                        ? "Runtime extraído, mas bin/sch1levo-runtime não foi encontrado."
                        : probe;
                runOnUiThread(() -> {
                    progress.setVisibility(View.GONE);
                    status.setText(result);
                    runtimeButton.setEnabled(true);
                    manualRuntimeButton.setEnabled(true);
                    refreshStatus();
                });
            } catch (Throwable e) {
                runOnUiThread(() -> {
                    progress.setVisibility(View.GONE);
                    status.setText("Falha ao instalar runtime: " + e.getMessage());
                    runtimeButton.setEnabled(true);
                    manualRuntimeButton.setEnabled(true);
                });
            }
        }).start();
    }

    private void extractZipSafely(
            InputStream source,
            File destination,
            java.util.concurrent.Callable<Boolean> cancelled) throws Exception {
        String canonicalDestination = destination.getCanonicalPath() + File.separator;
        try (ZipInputStream zip = new ZipInputStream(new BufferedInputStream(source))) {
            ZipEntry entry;
            byte[] buffer = new byte[1024 * 1024];
            while ((entry = zip.getNextEntry()) != null) {
                if (Boolean.TRUE.equals(cancelled.call())) {
                    throw new IOException("Importação cancelada pelo usuário.");
                }
                String entryName = entry.getName();
                if (entryName == null || entryName.isEmpty()) {
                    throw new IOException("Entrada ZIP sem nome.");
                }

                String normalizedName = entryName.replace('\\', '/');
                if (normalizedName.startsWith("/")
                        || normalizedName.matches("^[A-Za-z]:/.*")) {
                    throw new IOException("Entrada ZIP absoluta: " + entryName);
                }

                StringBuilder safeParts = new StringBuilder();
                for (String part : normalizedName.split("/", -1)) {
                    if (part.isEmpty() || part.equals(".")) {
                        continue;
                    }
                    if (part.equals("..")) {
                        throw new IOException("Entrada ZIP insegura: " + entryName);
                    }
                    if (safeParts.length() > 0) {
                        safeParts.append('/');
                    }
                    safeParts.append(part);
                }
                if (safeParts.length() == 0) {
                    zip.closeEntry();
                    continue;
                }

                File target = new File(destination, safeParts.toString().replace('/', File.separatorChar));
                String canonicalTarget = target.getCanonicalPath();
                if (!canonicalTarget.startsWith(canonicalDestination)) {
                    throw new IOException("Entrada ZIP insegura: " + entry.getName());
                }
                if (entry.isDirectory()) {
                    target.mkdirs();
                } else {
                    File parent = target.getParentFile();
                    if (parent != null) {
                        parent.mkdirs();
                    }
                    try (OutputStream output = new FileOutputStream(target)) {
                        int count;
                        while ((count = zip.read(buffer)) != -1) {
                            output.write(buffer, 0, count);
                        }
                    }
                }
                zip.closeEntry();
            }
        }
    }

    private File findRuntimeWrapper(File runtimeDir) {
        File[] candidates = {
                new File(runtimeDir, "bin/sch1levo-runtime"),
                new File(runtimeDir, "sch1levo-runtime"),
                new File(runtimeDir, "box64")
        };
        for (File candidate : candidates) {
            if (candidate.isFile()) {
                return candidate;
            }
        }
        return null;
    }

    private void markExecutableFiles(File directory) {
        if (directory == null || !directory.isDirectory()) {
            return;
        }
        File[] children = directory.listFiles();
        if (children == null) {
            return;
        }
        for (File child : children) {
            if (child.isDirectory()) {
                markExecutableFiles(child);
            } else {
                child.setReadable(true, true);
                child.setExecutable(true, true);
            }
        }
    }

    private boolean isShellScript(File file) {
        if (!file.isFile()) {
            return false;
        }
        try (FileInputStream input = new FileInputStream(file)) {
            byte[] header = new byte[2];
            return input.read(header) == 2
                    && header[0] == '#'
                    && header[1] == '!';
        } catch (IOException e) {
            return false;
        }
    }

    private File prepareExecutableRuntime(File source) throws IOException {
        File[] candidates = {
                new File("/data/local/tmp/dev.sporeport.cellstage-runtime"),
                new File(getCodeCacheDir(), "compat-runtime")
        };
        File selected = null;
        IOException lastError = null;
        for (File candidate : candidates) {
            try {
                if (!candidate.exists() && !candidate.mkdirs()) {
                    throw new IOException("Não foi possível criar: "
                            + candidate.getAbsolutePath());
                }
                if (!candidate.canWrite()) {
                    throw new IOException("Sem permissão de escrita: "
                            + candidate.getAbsolutePath());
                }
                File complete = new File(candidate, ".stage.complete");
                if (!complete.isFile()) {
                    deleteTree(candidate);
                    if (!candidate.mkdirs()) {
                        throw new IOException("Não foi possível preparar: "
                                + candidate.getAbsolutePath());
                    }
                    copyTree(source, candidate);
                    markExecutableFiles(new File(candidate, "bin"));
                    markExecutableFiles(new File(candidate, "wine/lib/wine/x86_64-unix"));
                    markExecutableFiles(new File(candidate, "wine/bin"));
                    try (FileOutputStream marker = new FileOutputStream(complete)) {
                        marker.write("complete\n".getBytes("UTF-8"));
                    }
                }
                installNativeBox64Launcher(new File(candidate, "bin/box64"));
                patchRuntimeWrapper(new File(candidate, "bin/sch1levo-runtime"));
                installWineLoaderShims(candidate);
                selected = candidate;
                break;
            } catch (IOException e) {
                lastError = e;
            }
        }
        if (selected == null) {
            throw new IOException("Nenhuma área executável disponível. "
                    + (lastError != null ? lastError.getMessage() : ""));
        }
        return selected;
    }

    private void copyTree(File source, File destination) throws IOException {
        if (source.isDirectory()) {
            if (!destination.exists() && !destination.mkdirs()) {
                throw new IOException("Falha ao criar diretório: "
                        + destination.getAbsolutePath());
            }
            File[] children = source.listFiles();
            if (children != null) {
                for (File child : children) {
                    copyTree(child, new File(destination, child.getName()));
                }
            }
        } else if (source.isFile()) {
            File parent = destination.getParentFile();
            if (parent != null) {
                parent.mkdirs();
            }
            try (InputStream input = new FileInputStream(source);
                 OutputStream output = new FileOutputStream(destination)) {
                byte[] buffer = new byte[1024 * 1024];
                int count;
                while ((count = input.read(buffer)) != -1) {
                    output.write(buffer, 0, count);
                }
            }
            destination.setReadable(true, true);
        }
    }

    private void installNativeBox64Launcher(File launcher) throws IOException {
        String nativeDir = getApplicationInfo().nativeLibraryDir;
        File nativeBox64 = new File(nativeDir, "libbox64.so");
        File nativeLoader = new File(nativeDir, "libldlinux.so");
        if (!nativeBox64.isFile() || !nativeLoader.isFile()) {
            throw new IOException(
                    "Bibliotecas nativas Box64/loader não encontradas em "
                            + nativeDir);
        }

        StringBuilder script = new StringBuilder();
        script.append("#!/system/bin/sh\n");
        script.append("RT=\"$(cd \"$(dirname \"$0\")/..\" && pwd)\"\n");
        script.append("export LD_LIBRARY_PATH=\"$RT/glibc/lib:$RT/wine/lib/wine/x86_64-unix:$RT/wine/lib:$RT/box64-x64lib\"\n");
        script.append("exec \"").append(nativeLoader.getAbsolutePath())
                .append("\" \"").append(nativeBox64.getAbsolutePath())
                .append("\" \"$@\"\n");
        try (FileOutputStream output = new FileOutputStream(launcher, false)) {
            output.write(script.toString().getBytes("UTF-8"));
        }
        launcher.setReadable(true, true);
        launcher.setExecutable(true, true);
    }

    private void installWineLoaderShims(File runtimeDir) throws IOException {
        File unixDir = new File(runtimeDir, "wine/lib/wine/x86_64-unix");
        installWineLoaderShim(
                new File(getApplicationInfo().nativeLibraryDir,
                        "libwine-loader-reexec.so"),
                new File(unixDir, "wine"),
                new File(unixDir, "wine.box64-original"));
        installWineLoaderShim(
                new File(getApplicationInfo().nativeLibraryDir,
                        "libwine-preloader-reexec.so"),
                new File(unixDir, "wine-preloader"),
                new File(unixDir, "wine-preloader.box64-original"));
        File wineServerHelper = new File(getApplicationInfo().nativeLibraryDir,
                "libwineserver-reexec.so");
        if (!wineServerHelper.isFile()) {
            throw new IOException("Helper wineserver não encontrado: "
                    + wineServerHelper.getAbsolutePath());
        }
    }

    private void installWineLoaderShim(
            File helper,
            File loader,
            File originalLoader) throws IOException {
        if (!helper.isFile()) {
            throw new IOException("Helper Wine não encontrado: "
                    + helper.getAbsolutePath());
        }
        if (!originalLoader.isFile()) {
            if (!loader.isFile()) {
                throw new IOException("Loader Wine original não encontrado: "
                        + loader.getAbsolutePath());
            }
            copyFile(loader, originalLoader);
            originalLoader.setReadable(true, true);
            originalLoader.setExecutable(true, true);
        }
        boolean loaderExists = loader.exists();
        boolean loaderDeleted = loader.delete();
        if ((loaderExists && !loaderDeleted) || loader.exists()) {
            throw new IOException("Não foi possível substituir o loader Wine: "
                    + loader.getAbsolutePath());
        }
        try {
            Os.symlink(helper.getAbsolutePath(), loader.getAbsolutePath());
        } catch (ErrnoException e) {
            throw new IOException("Não foi possível criar o link do loader Wine: "
                    + loader.getAbsolutePath(), e);
        }
    }

    private void copyFile(File source, File destination) throws IOException {
        File parent = destination.getParentFile();
        if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
            throw new IOException("Falha ao criar diretório: "
                    + parent.getAbsolutePath());
        }
        try (InputStream input = new FileInputStream(source);
             OutputStream output = new FileOutputStream(destination, false)) {
            byte[] buffer = new byte[16384];
            int count;
            while ((count = input.read(buffer)) != -1) {
                output.write(buffer, 0, count);
            }
        }
    }

    private void patchRuntimeWrapper(File wrapper) throws IOException {
        // Normalize Windows line endings and a possible UTF-8 BOM before Android sh reads it.
        String script;
        try (InputStream input = getAssets().open("sch1levo-runtime");
             ByteArrayOutputStream buffer = new ByteArrayOutputStream()) {
            byte[] bytes = new byte[16384];
            int count;
            while ((count = input.read(bytes)) != -1) {
                buffer.write(bytes, 0, count);
            }
            script = buffer.toString("UTF-8");
        }
        if (script.startsWith("\uFEFF")) {
            script = script.substring(1);
        }
        script = script.replace("\r\n", "\n").replace('\r', '\n');
        if (!script.startsWith("#!/system/bin/sh\n")) {
            throw new IOException("Asset sch1levo-runtime: cabeçalho shell inválido.");
        }
        try (OutputStream output = new FileOutputStream(wrapper, false)) {
            output.write(script.getBytes("UTF-8"));
        }
        wrapper.setReadable(true, true);
    }

    private String runtimeDiagnostics(File wrapper) {
        StringBuilder result = new StringBuilder();
        result.append("Arquivo: ").append(wrapper.getAbsolutePath()).append("\n");
        result.append("Existe=").append(wrapper.isFile())
                .append(", executável=").append(wrapper.canExecute())
                .append(", legível=").append(wrapper.canRead()).append("\n");
        try (FileInputStream input = new FileInputStream(wrapper)) {
            byte[] first = new byte[64];
            int count = input.read(first);
            result.append("Primeiros bytes=").append(count > 0 ? bytesToHex(first, count) : "(vazio)");
        } catch (IOException e) {
            result.append("Falha ao ler cabeçalho: ").append(e.getMessage());
        }
        try {
            File mountInfo = new File("/proc/self/mountinfo");
            if (mountInfo.canRead()) {
                try (BufferedReader reader = new BufferedReader(new FileReader(mountInfo))) {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        if (line.contains(" /data/ ") || line.contains(" /data")) {
                            result.append("\nMount: ").append(line);
                            break;
                        }
                    }
                }
            }
        } catch (IOException ignored) {
        }
        return result.toString();
    }

    private String bytesToHex(byte[] bytes, int count) {
        StringBuilder hex = new StringBuilder();
        for (int i = 0; i < count && i < 16; i++) {
            hex.append(String.format(Locale.US, "%02x", bytes[i] & 0xff));
            if (i + 1 < count) {
                hex.append(' ');
            }
        }
        return hex.toString();
    }

    private String probeRuntime(File runtimeDir) {
        File wrapper = findRuntimeWrapper(runtimeDir);
        if (wrapper == null) {
            return "Runtime instalado, mas o executável principal não foi encontrado.";
        }
        try {
            wrapper.setReadable(true, true);
            wrapper.setExecutable(true, true);
            ProcessBuilder builder;
            if (isShellScript(wrapper)) {
                builder = new ProcessBuilder("/system/bin/sh",
                        wrapper.getAbsolutePath(), "version");
            } else {
                builder = new ProcessBuilder(
                        wrapper.getAbsolutePath(), "version");
            }
            builder.environment().put("SPORE_NATIVE_DIR", getApplicationInfo().nativeLibraryDir);
            builder.directory(runtimeDir);
            builder.redirectErrorStream(true);
            Process process = builder.start();
            ByteArrayOutputStream output = new ByteArrayOutputStream();
            try (InputStream input = process.getInputStream()) {
                byte[] buffer = new byte[16 * 1024];
                int count;
                while ((count = input.read(buffer)) != -1) {
                    output.write(buffer, 0, count);
                }
            }
            int exit = process.waitFor();
            String text = output.toString("UTF-8").trim();
            return "Runtime instalado e executável\n"
                    + "Comando: " + wrapper.getName() + " version\n"
                    + "Exit: " + exit + "\n"
                    + (text.isEmpty() ? "(sem saída)" : text);
        } catch (Exception e) {
            return "Runtime extraído, mas o probe falhou: " + e.getMessage()
                    + "\n\nDiagnóstico:\n" + runtimeDiagnostics(wrapper);
        }
    }

    private void importFolder(Uri treeUri) {
        setImporting(true);
        status.setText("Preparando importação...");
        new Thread(() -> {
            File destination = new File(getExternalFilesDir(null), "Spore");
            try {
                deleteTree(destination);
                importCancelled = false;
                runOnUiThread(() -> status.setText("Contando arquivos..."));
                totalFiles = countDocumentTree(treeUri);
                importedFiles = 0;
                runOnUiThread(() -> {
                    progress.setIndeterminate(false);
                    progress.setMax(Math.max(totalFiles, 1));
                    progress.setProgress(0);
                    status.setText("Importando 0/" + totalFiles + " arquivos...");
                });
                copyDocumentTree(treeUri, destination);
                File exe = findVerifiedSporeExe(destination);
                runOnUiThread(() -> {
                    if (importCancelled) {
                        deleteTree(destination);
                        status.setText("Importação cancelada.");
                        refreshStatus();
                        setImporting(false);
                        return;
                    }
                    if (exe.isFile()) {
                        String hash = sha256(exe);
                        status.setText("Importação concluída\nEXE SHA-256: " + hash);
                    } else {
                        status.setText("A pasta foi copiada, mas SporeApp.exe não foi encontrada.\n"
                                + "Selecione a raiz da instalação, não apenas SporeBin.");
                    }
                    refreshStatus();
                    setImporting(false);
                });
            } catch (Throwable e) {
                runOnUiThread(() -> {
                    if (importCancelled) {
                        deleteTree(destination);
                        status.setText("Importação cancelada pelo usuário.");
                    } else {
                        status.setText("Falha na importação: " + e.getMessage());
                    }
                    setImporting(false);
                });
            }
        }).start();
    }

    private int countDocumentTree(Uri source) {
        return countDocumentChildren(source, DocumentsContract.getTreeDocumentId(source));
    }

    private int countDocumentChildren(Uri source, String documentId) {
        Uri children = DocumentsContract.buildChildDocumentsUriUsingTree(source, documentId);
        int count = 0;
        try (android.database.Cursor cursor = getContentResolver().query(
                children,
                new String[]{
                        DocumentsContract.Document.COLUMN_DOCUMENT_ID,
                        DocumentsContract.Document.COLUMN_MIME_TYPE
                },
                null, null, null)) {
            if (cursor == null) {
                return 0;
            }
            while (cursor.moveToNext()) {
                String childId = cursor.getString(0);
                String mime = cursor.getString(1);
                if (DocumentsContract.Document.MIME_TYPE_DIR.equals(mime)) {
                    count += countDocumentChildren(source, childId);
                } else {
                    count++;
                }
            }
        }
        return count;
    }

    private void deleteTree(File path) {
        if (!path.exists()) {
            return;
        }
        if (path.isDirectory()) {
            File[] children = path.listFiles();
            if (children != null) {
                for (File child : children) {
                    deleteTree(child);
                }
            }
        }
        path.delete();
    }

    private void copyDocumentTree(Uri source, File destination) throws IOException {
        copyChildren(source, DocumentsContract.getTreeDocumentId(source), destination);
    }

    private void copyChildren(Uri source, String parentDocumentId, File destination) throws IOException {
        destination.mkdirs();
        Uri children = DocumentsContract.buildChildDocumentsUriUsingTree(
                source, parentDocumentId);
        android.database.Cursor cursor = getContentResolver().query(
                children,
                new String[]{
                        DocumentsContract.Document.COLUMN_DOCUMENT_ID,
                        DocumentsContract.Document.COLUMN_DISPLAY_NAME,
                        DocumentsContract.Document.COLUMN_MIME_TYPE,
                        DocumentsContract.Document.COLUMN_SIZE
                },
                null, null, null);
        if (cursor == null) {
            throw new IOException("Não foi possível listar a pasta selecionada.");
        }
        try (cursor) {
            while (cursor.moveToNext()) {
                String childDocumentId = cursor.getString(0);
                String name = cursor.getString(1);
                String mime = cursor.getString(2);
                if (importCancelled) {
                    throw new IOException("Importação cancelada pelo usuário.");
                }
                Uri documentUri = DocumentsContract.buildDocumentUriUsingTree(source, childDocumentId);
                File target = new File(destination, sanitizeName(name));
                if (DocumentsContract.Document.MIME_TYPE_DIR.equals(mime)) {
                    copyChildren(source, childDocumentId, target);
                } else if (target.exists()) {
                    // Keep newer installation data intact if it is already being re-imported.
                    target.delete();
                    copyDocumentFile(documentUri, target);
                    reportImportedFile(name);
                } else {
                    copyDocumentFile(documentUri, target);
                    reportImportedFile(name);
                }
            }
        }
    }

    private void reportImportedFile(String name) {
        importedFiles++;
        int current = importedFiles;
        int total = Math.max(totalFiles, 1);
        runOnUiThread(() -> {
            progress.setProgress(Math.min(current, total));
            status.setText(current * 100 / total + "% — " + current + "/" + total
                    + " arquivos\nImportando: " + name);
        });
    }

    private void copyDocumentFile(Uri uri, File target) throws IOException {
        try (InputStream input = getContentResolver().openInputStream(uri);
             OutputStream output = new FileOutputStream(target)) {
            if (input == null) {
                throw new IOException("Não foi possível abrir: " + target.getName());
            }
            byte[] buffer = new byte[1024 * 1024];
            int count;
            while ((count = input.read(buffer)) != -1) {
                output.write(buffer, 0, count);
            }
        }
    }

    private String sanitizeName(String name) {
        String safe = name == null ? "unnamed" : name.replaceAll("[\\\\/:*?\"<>|]", "_");
        return safe.isEmpty() ? "unnamed" : safe;
    }

    private void setImporting(boolean value) {
        importing = value;
        runOnUiThread(() -> {
            progress.setVisibility(value ? View.VISIBLE : View.GONE);
            importButton.setEnabled(!value);
            if (value) {
                nativeChainButton.setEnabled(false);
                dbpfResourceButton.setEnabled(false);
            }
            runtimeButton.setEnabled(!value);
            manualRuntimeButton.setEnabled(!value);
            launchButton.setEnabled(!value && launchButton.isEnabled());
            cancelButton.setEnabled(value);
            if (value) {
                progress.setIndeterminate(true);
            }
        });
    }

    private void startCompatibility() {
        File gameRoot = new File(getExternalFilesDir(null), "Spore");
        File exe = findVerifiedSporeExe(gameRoot);
        File runtimeDir = getRuntimeDir();
        File runtimeWrapper = findRuntimeWrapper(runtimeDir);
        File box64 = runtimeWrapper != null && runtimeWrapper.getName().equals("box64")
                ? runtimeWrapper : new File(runtimeDir, "bin/box64");
        File wine = new File(runtimeDir, "wine/bin/wine");
        File dxvk = new File(runtimeDir, "dxvk");

        StringBuilder report = new StringBuilder();
        report.append("1/5 Importação: concluída\n");
        report.append("   EXE: ").append(exe.getAbsolutePath()).append("\n");
        report.append("2/5 Runtime ARM64: ")
                .append(runtimeWrapper != null ? "instalado" : "não localizado").append("\n");
        report.append("   Executável: ").append(runtimeWrapper != null
                ? runtimeWrapper.getAbsolutePath() : box64.getAbsolutePath()).append("\n");
        report.append("3/5 Windows/Win32: ")
                .append(wine.isFile() ? "Wine localizado" : "não localizado").append("\n");
        report.append("   Esperado: ").append(wine.getAbsolutePath()).append("\n");
        report.append("4/5 Gráficos D3D9: ")
                .append(dxvk.isDirectory() ? "DXVK localizado" : "não localizado").append("\n");
        report.append("   Esperado: ").append(dxvk.getAbsolutePath()).append("\n");
        report.append("5/5 Boot do Spore: bloqueado até o runtime completar as etapas 2-4");

        status.setText(report.toString());
        writeCompatibilityLog(report.toString(),
                exe, runtimeDir, box64, wine, dxvk);

        if (runtimeWrapper != null) {
            launchButton.setEnabled(false);
            runtimeButton.setEnabled(false);
            manualRuntimeButton.setEnabled(false);
            status.setText(report + "\n\nExecutando testes do runtime...");
            new Thread(() -> {
                File probeRuntimeDir;
                File probeWrapper;
                String stagingReport;
                try {
                    probeRuntimeDir = prepareExecutableRuntime(runtimeDir);
                    probeWrapper = findRuntimeWrapper(probeRuntimeDir);
                    stagingReport = "Área executável: "
                            + probeRuntimeDir.getAbsolutePath();
                    if (probeWrapper != null) {
                        probeWrapper.setReadable(true, true);
                        probeWrapper.setExecutable(true, true);
                    }
                } catch (Exception e) {
                    probeRuntimeDir = runtimeDir;
                    probeWrapper = runtimeWrapper;
                    stagingReport = "Falha ao preparar área executável: "
                            + e.getMessage();
                }
                String version = probeWrapper != null
                        ? runRuntimeProbe(probeRuntimeDir, probeWrapper, "version")
                        : "Falha ao preparar staging do runtime.";
                String prefix = probeWrapper != null
                        ? runRuntimeProbe(probeRuntimeDir, probeWrapper, "prefix-init")
                        : "Falha ao preparar staging do runtime.";
                String d3dProbe = probeWrapper != null
                        ? runRuntimeProbe(probeRuntimeDir, probeWrapper, "d3d11-probe")
                        : "Falha ao preparar staging do runtime.";
                boolean prefixReady = prefix.startsWith("Exit: 0\n")
                        && prefix.contains("PREFIX_OK")
                        && prefix.contains("HELLO_OK");
                boolean displayReady = d3dProbe.startsWith("Exit: 0\n")
                        && !d3dProbe.contains("NOT_AVAILABLE");
                String finalReport = report.toString()
                        + "\n\n" + stagingReport
                        + "\n\n[TESTE 1 - version]\n" + version
                        + "\n\n[TESTE 2 - prefix-init]\n" + prefix
                        + "\n\n[TESTE 3 - d3d11-probe]\n" + d3dProbe
                        + "\n\nResultado: " + (
                                prefixReady && displayReady
                                        ? "Probes retornaram sucesso; renderização do Spore ainda não verificada."
                                        : prefixReady
                                        ? "Camada PE console validada; ponte de display e D3D11 estão pendentes."
                                        : "Runtime não passou no boot de compatibilidade.");
                writeCompatibilityLog(finalReport,
                        exe, runtimeDir, box64, wine, dxvk);
                runOnUiThread(() -> {
                    status.setText(finalReport);
                    launchButton.setEnabled(prefixReady && displayReady);
                    runtimeButton.setEnabled(true);
                    manualRuntimeButton.setEnabled(true);
                });
            }).start();
        }
    }

    private String runRuntimeProbe(
            File runtimeDir,
            File wrapper,
            String command) {
        try {
            wrapper.setReadable(true, true);
            wrapper.setExecutable(true, true);
            ProcessBuilder builder;
            if (isShellScript(wrapper)) {
                builder = new ProcessBuilder("/system/bin/sh",
                        wrapper.getAbsolutePath(), command);
            } else {
                builder = new ProcessBuilder(
                        wrapper.getAbsolutePath(), command);
            }
            builder.environment().put("SPORE_NATIVE_DIR", getApplicationInfo().nativeLibraryDir);
            builder.directory(runtimeDir);
            builder.redirectErrorStream(true);
            builder.environment().put("SCH1LEVO_DATA",
                    new File(runtimeDir, "test-data").getAbsolutePath());
            builder.environment().put("SCH1LEVO_PREFIX",
                    new File(runtimeDir, "prefix").getAbsolutePath());
            builder.environment().put("SCH1LEVO_BOX64_LOG", "0");
            Process process = builder.start();
            ByteArrayOutputStream output = new ByteArrayOutputStream();
            try (InputStream input = process.getInputStream()) {
                byte[] buffer = new byte[16 * 1024];
                int count;
                while ((count = input.read(buffer)) != -1) {
                    output.write(buffer, 0, count);
                }
            }
            int exit = process.waitFor();
            String text = output.toString("UTF-8").trim();
            return "Exit: " + exit + "\n"
                    + (text.isEmpty() ? "(sem saída)" : text);
        } catch (Exception e) {
            return "Falha ao executar: " + e.getMessage()
                    + "\n\nDiagnóstico:\n" + runtimeDiagnostics(wrapper);
        }
    }

    private void writeCompatibilityLog(
            String report,
            File exe,
            File runtimeDir,
            File box64,
            File wine,
            File dxvk) {
        File log = new File(runtimeDir, "compatibility_boot.log");
        runtimeDir.mkdirs();
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(log, false))) {
            writer.write("Spore PC Compatibility bootstrap\n");
            writer.write("Package: dev.sporeport.cellstage\n");
            writer.write("ABI: arm64-v8a\n");
            writer.write("EXE_SHA256: ");
            writer.write(sha256(exe));
            writer.write("\nEXE_PATH: ");
            writer.write(exe.getAbsolutePath());
            writer.write("\nbox64_present: ");
            writer.write(Boolean.toString(box64.isFile()));
            writer.write("\nwine_present: ");
            writer.write(Boolean.toString(wine.isFile()));
            writer.write("\ndxvk_present: ");
            writer.write(Boolean.toString(dxvk.isDirectory()));
            writer.write("\n\n");
            writer.write(report);
            writer.write("\n");
        } catch (IOException e) {
            status.setText(report + "\nFalha ao gravar diagnóstico: " + e.getMessage());
        }
    }

    private static String sha256(File file) {
        try (FileInputStream input = new FileInputStream(file)) {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] buffer = new byte[1024 * 1024];
            int count;
            while ((count = input.read(buffer)) != -1) {
                digest.update(buffer, 0, count);
            }
            StringBuilder result = new StringBuilder();
            for (byte value : digest.digest()) {
                result.append(String.format(Locale.US, "%02x", value));
            }
            return result.toString();
        } catch (Exception e) {
            return "erro: " + e.getMessage();
        }
    }

    private static String sha256(byte[] bytes) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(bytes);
            StringBuilder result = new StringBuilder();
            for (byte value : hash) {
                result.append(String.format(Locale.US, "%02x", value));
            }
            return result.toString();
        } catch (Exception e) {
            throw new IllegalStateException("Could not hash decoded resource", e);
        }
    }

    private static native String nativeRuntimeInfo();
    private static native String nativeSporeLookup(String executablePath, int key);
    private static native long nativeSporeNameHash(String name);
    private static native byte[] nativeReadDbpfResource(
            String packagePath, int type, int group, int instance);
}
