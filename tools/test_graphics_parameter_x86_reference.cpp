#define NOMINMAX
#include <windows.h>

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>

#include "..\app\src\main\cpp\spore_graphics_parameter_translation.h"

#if !defined(_M_IX86)
#error This reference harness must be built as x86.
#endif

namespace {

constexpr std::uint32_t kWidthArgumentOffset = 0xbc;
constexpr std::uint32_t kHeightArgumentOffset = 0xc0;
constexpr std::uint32_t kWidthFieldOffset = 0x3c;
constexpr std::uint32_t kHeightFieldOffset = 0x40;
constexpr std::uint32_t kConfigByteOffset = 0xc4;
constexpr std::uint32_t kReferenceBlockVa = 0x75f25e;
constexpr std::uint32_t kReferenceBlockEndVa = 0x75f28f;

std::uint32_t g_saved_stack_pointer = 0;
void* g_reference_block = nullptr;

__declspec(naked) void RestoreCallerStack() {
    __asm {
        mov esp, dword ptr [g_saved_stack_pointer]
        ret
    }
}

__declspec(naked) void ExecuteReferenceBlock(std::uint32_t*) {
    __asm {
        mov eax, esp
        mov dword ptr [g_saved_stack_pointer], eax
        mov esp, dword ptr [esp + 4]
        jmp dword ptr [g_reference_block]
    }
}

bool readImage(const std::wstring& path, std::vector<std::uint8_t>* image) {
    std::ifstream input(path, std::ios::binary);
    if (!input) {
        std::fwprintf(stderr, L"Could not open reference PE: %ls\n", path.c_str());
        return false;
    }

    image->assign(
        std::istreambuf_iterator<char>(input),
        std::istreambuf_iterator<char>());
    if (input.bad() || image->empty()) {
        std::fwprintf(stderr, L"Could not read reference PE: %ls\n", path.c_str());
        return false;
    }
    return true;
}

bool extractReferenceBlock(
    const std::vector<std::uint8_t>& image,
    std::vector<std::uint8_t>* block) {
    IMAGE_DOS_HEADER dos_header{};
    if (image.size() < sizeof(dos_header)) {
        std::fprintf(stderr, "Reference PE is shorter than its DOS header\n");
        return false;
    }
    std::memcpy(&dos_header, image.data(), sizeof(dos_header));
    if (dos_header.e_magic != IMAGE_DOS_SIGNATURE
            || dos_header.e_lfanew < 0
            || static_cast<std::size_t>(dos_header.e_lfanew)
                > image.size() - sizeof(DWORD) - sizeof(IMAGE_FILE_HEADER)) {
        std::fprintf(stderr, "Reference PE has an invalid DOS header\n");
        return false;
    }

    const std::size_t nt_offset =
        static_cast<std::size_t>(dos_header.e_lfanew);
    DWORD signature = 0;
    IMAGE_FILE_HEADER file_header{};
    std::memcpy(&signature, image.data() + nt_offset, sizeof(signature));
    std::memcpy(
        &file_header,
        image.data() + nt_offset + sizeof(signature),
        sizeof(file_header));
    if (signature != IMAGE_NT_SIGNATURE
            || file_header.Machine != IMAGE_FILE_MACHINE_I386
            || file_header.SizeOfOptionalHeader < sizeof(IMAGE_OPTIONAL_HEADER32)) {
        std::fprintf(stderr, "Reference PE is not a supported PE32 x86 image\n");
        return false;
    }

    IMAGE_OPTIONAL_HEADER32 optional_header{};
    const std::size_t optional_offset =
        nt_offset + sizeof(signature) + sizeof(file_header);
    if (optional_offset > image.size()
            || sizeof(optional_header) > image.size() - optional_offset) {
        std::fprintf(stderr, "Reference PE has a truncated optional header\n");
        return false;
    }
    std::memcpy(
        &optional_header,
        image.data() + optional_offset,
        sizeof(optional_header));
    if (optional_header.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC) {
        std::fprintf(stderr, "Reference PE optional header is not PE32\n");
        return false;
    }
    if (kReferenceBlockVa < optional_header.ImageBase
            || kReferenceBlockEndVa < optional_header.ImageBase) {
        std::fprintf(stderr, "Reference function VA is below the PE image base\n");
        return false;
    }

    const std::size_t section_offset =
        optional_offset + file_header.SizeOfOptionalHeader;
    if (file_header.NumberOfSections
            > (std::numeric_limits<std::size_t>::max() - section_offset)
                / sizeof(IMAGE_SECTION_HEADER)
            || section_offset
                + file_header.NumberOfSections * sizeof(IMAGE_SECTION_HEADER)
                > image.size()) {
        std::fprintf(stderr, "Reference PE has a truncated section table\n");
        return false;
    }

    const std::uint32_t block_size =
        kReferenceBlockEndVa - kReferenceBlockVa;
    const std::uint64_t block_begin =
        kReferenceBlockVa - optional_header.ImageBase;
    for (WORD i = 0; i < file_header.NumberOfSections; ++i) {
        IMAGE_SECTION_HEADER section{};
        std::memcpy(
            &section,
            image.data() + section_offset + i * sizeof(section),
            sizeof(section));
        const std::uint64_t section_begin = section.VirtualAddress;
        const std::uint64_t section_end =
            section_begin + section.SizeOfRawData;
        const std::uint64_t block_end = block_begin + block_size;
        if (block_begin < section_begin || block_end > section_end) {
            continue;
        }

        const std::uint64_t file_offset =
            static_cast<std::uint64_t>(section.PointerToRawData)
            + (block_begin - section_begin);
        if (file_offset > image.size()
                || block_size > image.size() - file_offset) {
            break;
        }

        block->assign(
            image.begin() + static_cast<std::size_t>(file_offset),
            image.begin() + static_cast<std::size_t>(file_offset + block_size));
        return true;
    }

    std::fprintf(stderr, "Could not map the reference block RVA to PE bytes\n");
    return false;
}

bool runComparison(
    const char* case_name,
    std::uint32_t width,
    std::uint32_t height) {
    constexpr std::size_t kFrameWords = 0xd0 / sizeof(std::uint32_t);
    std::array<std::uint32_t, kFrameWords> frame{};
    frame[0] = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(&RestoreCallerStack));
    frame[kWidthArgumentOffset / sizeof(std::uint32_t)] = width;
    frame[kHeightArgumentOffset / sizeof(std::uint32_t)] = height;
    frame[kConfigByteOffset / sizeof(std::uint32_t)] = 1;
    frame[kWidthFieldOffset / sizeof(std::uint32_t)] = 0xaaaaaaaa;
    frame[kHeightFieldOffset / sizeof(std::uint32_t)] = 0xbbbbbbbb;

    ExecuteReferenceBlock(frame.data());
    const std::uint32_t reference_width =
        frame[kWidthFieldOffset / sizeof(std::uint32_t)];
    const std::uint32_t reference_height =
        frame[kHeightFieldOffset / sizeof(std::uint32_t)];

    std::uint32_t translated_width = 0;
    std::uint32_t translated_height = 0;
    if (!SporeTranslatedCopyBackBufferDimensions(
            &translated_width,
            &translated_height,
            reference_width,
            reference_height)) {
        std::fprintf(stderr, "%s: translated helper rejected valid outputs\n", case_name);
        return false;
    }

    std::printf(
        "case=%s input-width=%u input-height=%u "
        "x86-width=%u x86-height=%u translated-width=%u translated-height=%u\n",
        case_name,
        width,
        height,
        reference_width,
        reference_height,
        translated_width,
        translated_height);
    return reference_width == width
        && reference_height == height
        && translated_width == reference_width
        && translated_height == reference_height;
}

}

int wmain(int argc, wchar_t** argv) {
    if (argc != 2) {
        std::fwprintf(stderr, L"Usage: %ls <SporeApp.exe>\n", argv[0]);
        return 2;
    }

    std::vector<std::uint8_t> image;
    std::vector<std::uint8_t> reference_bytes;
    if (!readImage(argv[1], &image)
            || !extractReferenceBlock(image, &reference_bytes)) {
        return 1;
    }

    auto* executable_block = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr,
        reference_bytes.size() + 1,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE));
    if (executable_block == nullptr) {
        std::fprintf(stderr, "VirtualAlloc failed: %lu\n", GetLastError());
        return 1;
    }
    std::memcpy(executable_block, reference_bytes.data(), reference_bytes.size());
    executable_block[reference_bytes.size()] = 0xc3;
    g_reference_block = executable_block;

    std::printf(
        "reference-function=FUN_0075f030 block-va=0x%08x-0x%08x "
        "executed-original-bytes=%zu\n",
        kReferenceBlockVa,
        kReferenceBlockEndVa,
        reference_bytes.size());

    const bool first = runComparison("wide", 1280, 720);
    const bool second = runComparison("portrait-shaped", 480, 900);
    std::uint32_t unused_width = 0;
    const bool null_rejected =
        !SporeTranslatedCopyBackBufferDimensions(
            nullptr, &unused_width, 1, 2)
        && !SporeTranslatedCopyBackBufferDimensions(
            &unused_width, nullptr, 1, 2)
        && !SporeTranslatedCopyBackBufferDimensions(
            &unused_width, &unused_width, 1, 2);

    VirtualFree(executable_block, 0, MEM_RELEASE);
    g_reference_block = nullptr;

    if (!first || !second || !null_rejected) {
        std::fprintf(stderr, "x86 reference comparison: FAIL\n");
        return 1;
    }
    std::printf("x86-original-vs-translated=PASS null-output-rejection=PASS\n");
    return 0;
}
