#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <android/log.h>

#define REEXEC_LOG(...) \
    __android_log_print(ANDROID_LOG_INFO, "SporeWineReexec", __VA_ARGS__)

#ifndef SPORE_REEXEC_PRELOADER
#define SPORE_REEXEC_PRELOADER 0
#endif
#ifndef SPORE_REEXEC_WINESERVER
#define SPORE_REEXEC_WINESERVER 0
#endif

int main(int argc, char **argv) {
    const char *runtime = getenv("SPORE_RUNTIME_DIR");
    const char *native = getenv("SPORE_NATIVE_DIR");
    const char *data = getenv("SCH1LEVO_DATA");
    REEXEC_LOG("helper=%s argc=%d runtime=%s native=%s data=%s",
               SPORE_REEXEC_WINESERVER ? "wineserver" :
               SPORE_REEXEC_PRELOADER ? "preloader" : "loader",
               argc, runtime ? runtime : "(unset)",
               native ? native : "(unset)", data ? data : "(unset)");
    for (int i = 0; i < argc; ++i) {
        REEXEC_LOG("argv[%d]=%s", i, argv[i] ? argv[i] : "(null)");
    }
    if (!runtime || !native) {
        fputs("Wine re-exec helper requires SPORE_RUNTIME_DIR and SPORE_NATIVE_DIR\n",
              stderr);
        return 125;
    }

    if (data) {
        char log_path[4096];
        int log_length = snprintf(log_path, sizeof(log_path),
                                  "%s/wine-reexec.log", data);
        if (log_length >= 0 && (size_t)log_length < sizeof(log_path)) {
            FILE *log = fopen(log_path, "a");
            if (log) {
                fprintf(log, "helper=%s argc=%d runtime=%s native=%s\n",
                        SPORE_REEXEC_WINESERVER ? "wineserver" :
                        SPORE_REEXEC_PRELOADER ? "preloader" : "loader",
                        argc, runtime, native);
                for (int i = 0; i < argc; ++i) {
                    fprintf(log, "argv[%d]=%s\n", i,
                            argv[i] ? argv[i] : "(null)");
                }
                fclose(log);
            } else {
                perror("Wine re-exec helper: fopen log");
            }
        } else {
            fputs("Wine re-exec helper: log path is too long\n", stderr);
        }
    } else {
        fputs("Wine re-exec helper: SCH1LEVO_DATA not set for logging\n", stderr);
    }

    char ldlinux[4096];
    char box64[4096];
    char guest[4096];
    char library_path[16384];
    int path_length = snprintf(ldlinux, sizeof(ldlinux), "%s/libldlinux.so", native);
    if (path_length < 0 || (size_t)path_length >= sizeof(ldlinux)) {
        fputs("Wine re-exec helper: native loader path is too long\n", stderr);
        return 125;
    }
    path_length = snprintf(box64, sizeof(box64), "%s/libbox64.so", native);
    if (path_length < 0 || (size_t)path_length >= sizeof(box64)) {
        fputs("Wine re-exec helper: Box64 path is too long\n", stderr);
        return 125;
    }
    path_length = snprintf(
        guest, sizeof(guest), "%s/%s", runtime,
        SPORE_REEXEC_WINESERVER
            ? "wine/bin/wineserver"
            : "wine/lib/wine/x86_64-unix/wine.box64-original");
    if (path_length < 0 || (size_t)path_length >= sizeof(guest)) {
        fputs("Wine re-exec helper: Wine loader path is too long\n", stderr);
        return 125;
    }
    path_length = snprintf(
        library_path, sizeof(library_path),
        "%s/glibc/lib:%s/wine/lib/wine/x86_64-unix:%s/wine/lib:%s/box64-x64lib",
        runtime, runtime, runtime, runtime);
    if (path_length < 0 || (size_t)path_length >= sizeof(library_path)) {
        fputs("Wine re-exec helper: library path is too long\n", stderr);
        return 125;
    }
    if (setenv("LD_LIBRARY_PATH", library_path, 1) != 0) {
        perror("Wine re-exec helper: setenv");
        return 125;
    }

    char **child_argv = calloc((size_t)argc + 3, sizeof(*child_argv));
    if (!child_argv) {
        perror("Wine re-exec helper: calloc");
        return 125;
    }
    child_argv[0] = ldlinux;
    child_argv[1] = box64;
    child_argv[2] = guest;
    int first_argument = SPORE_REEXEC_PRELOADER && !SPORE_REEXEC_WINESERVER
        ? 2
        : 1;
    int child_index = 3;
    for (int i = first_argument; i < argc; ++i) {
        child_argv[child_index++] = argv[i];
    }
    child_argv[child_index] = NULL;

    execv(ldlinux, child_argv);
    fprintf(stderr, "Wine re-exec helper: execv(%s) failed: %s\n",
            ldlinux, strerror(errno));
    if (data) {
        char log_path[4096];
        int log_length = snprintf(log_path, sizeof(log_path),
                                  "%s/wine-reexec.log", data);
        if (log_length >= 0 && (size_t)log_length < sizeof(log_path)) {
            FILE *log = fopen(log_path, "a");
            if (log) {
                fprintf(log, "execv(%s) failed: %s\n", ldlinux,
                        strerror(errno));
                fclose(log);
            } else {
                perror("Wine re-exec helper: fopen error log");
            }
        }
    }
    free(child_argv);
    return 127;
}
