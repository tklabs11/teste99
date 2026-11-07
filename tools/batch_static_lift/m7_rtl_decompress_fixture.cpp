#include <Windows.h>

#include <array>
#include <cstdint>
#include <cstdio>
#include <vector>

namespace {
constexpr std::size_t kInputSize = 0x5dd98u;
constexpr std::size_t kOutputCapacity = 0x1198c8u;
using RtlDecompressBufferFn = LONG(NTAPI*)(
    USHORT, PUCHAR, ULONG, PUCHAR, ULONG, PULONG);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::fprintf(stderr, "usage: m7_rtl_decompress_fixture <input> <output>\n");
        return 2;
    }
    FILE* input = nullptr;
    if (fopen_s(&input, argv[1], "rb") != 0 || input == nullptr) {
        std::fprintf(stderr, "could not open compressed fixture\n");
        return 2;
    }
    std::vector<std::uint8_t> compressed(kInputSize);
    const std::size_t read = std::fread(compressed.data(), 1, compressed.size(), input);
    const int extra = std::fgetc(input);
    std::fclose(input);
    if (read != kInputSize || extra != EOF) {
        std::fprintf(stderr, "compressed fixture length mismatch\n");
        return 2;
    }
    HMODULE ntdll = GetModuleHandleW(L"ntdll.dll");
    if (ntdll == nullptr) {
        std::fprintf(stderr, "NTDLL is not loaded\n");
        return 2;
    }
    auto* decompress = reinterpret_cast<RtlDecompressBufferFn>(
        GetProcAddress(ntdll, "RtlDecompressBuffer"));
    if (decompress == nullptr) {
        std::fprintf(stderr, "RtlDecompressBuffer export is absent\n");
        return 2;
    }
    std::vector<std::uint8_t> output(kOutputCapacity);
    ULONG actual = 0;
    const LONG status = decompress(
        0x102u, output.data(), static_cast<ULONG>(output.size()),
        compressed.data(), static_cast<ULONG>(compressed.size()), &actual);
    std::printf("API=NTDLL!RtlDecompressBuffer host=x86_windows "
                "fixture=synthetic_loader_and_allocation format=0x102 "
                "input_size=0x%zx output_capacity=0x%zx "
                "status=0x%08lx output_size=0x%08lx\n",
                compressed.size(), output.size(),
                static_cast<unsigned long>(status),
                static_cast<unsigned long>(actual));
    if (status != 0 || actual > output.size()) return 1;
    std::printf("OUTPUT_HEAD=");
    for (std::size_t index = 0; index < 32 && index < actual; ++index)
        std::printf("%02x", output[index]);
    std::putchar('\n');
    HANDLE file = CreateFileA(
        argv[2], GENERIC_WRITE, 0, nullptr, CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        std::fprintf(stderr, "could not create output artifact: error=%lu\n",
                     GetLastError());
        return 2;
    }
    DWORD written = 0;
    const BOOL ok = WriteFile(file, output.data(), actual, &written, nullptr);
    CloseHandle(file);
    if (!ok || written != actual) {
        std::fprintf(stderr, "could not write complete output artifact\n");
        return 2;
    }
    std::printf("OUTPUT_ARTIFACT=%s\n", argv[2]);
    return 0;
}
