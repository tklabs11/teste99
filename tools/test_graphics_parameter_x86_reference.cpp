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
constexpr std::uint32_t kDimensionsBlockVa = 0x75f25e;
constexpr std::uint32_t kDimensionsBlockEndVa = 0x75f28f;
constexpr std::uint32_t kPresentationModeBlockVa = 0x75f29f;
constexpr std::uint32_t kPresentationModeBlockEndVa = 0x75f2b7;
constexpr std::uint32_t kBooleanGetterBlockVa = 0x6a25a0;
constexpr std::uint32_t kBooleanGetterBlockEndVa = 0x6a2655;
constexpr std::uint32_t kPresentationWrapperVa = 0x11f7d00;
constexpr std::uint32_t kPresentationWrapperEndVa = 0x11f7dd8;
constexpr std::uint32_t kPresentationGlobalsVa = 0x016f6000;
constexpr std::size_t kPresentationGlobalsSize = 0x5000;

std::uint32_t g_saved_stack_pointer = 0;
std::uint32_t g_reference_ecx = 0;
void* g_reference_block = nullptr;
std::uint32_t g_config_lookup_result = 0;
std::uint8_t g_reference_return_value = 0;
std::uint8_t g_default_config_boolean = 0;

__declspec(naked) void RestoreCallerStack() {
    __asm {
        mov byte ptr [g_reference_return_value], al
        mov esp, dword ptr [g_saved_stack_pointer]
        ret
    }
}

__declspec(naked) void ExecuteReferenceBlock(std::uint32_t*) {
    __asm {
        mov eax, esp
        mov dword ptr [g_saved_stack_pointer], eax
        mov esp, dword ptr [esp + 4]
        mov ecx, dword ptr [g_reference_ecx]
        jmp dword ptr [g_reference_block]
    }
}

__declspec(naked) void ConfigLookupStub() {
    __asm {
        mov eax, dword ptr [g_config_lookup_result]
        ret
    }
}

__declspec(naked) void ConfigValueConstructionStub() {
    __asm {
        mov eax, dword ptr [esp + 4]
        mov edx, dword ptr [eax]
        mov dword ptr [ecx], edx
        mov dl, byte ptr [eax + 0xc]
        mov byte ptr [ecx + 0x10], dl
        mov dx, word ptr [eax + 0xe]
        mov word ptr [ecx + 0x12], dx
        mov eax, ecx
        ret 4
    }
}

__declspec(naked) void ConfigCleanupStub() {
    __asm {
        ret 4
    }
}

bool patchRelativeCall(
    std::uint8_t* block,
    std::size_t call_offset,
    const void* target) {
    if (block == nullptr || target == nullptr) {
        return false;
    }

    const std::intptr_t next_instruction =
        reinterpret_cast<std::intptr_t>(block + call_offset + 5);
    const std::intptr_t displacement =
        reinterpret_cast<std::intptr_t>(target) - next_instruction;
    if (displacement < std::numeric_limits<std::int32_t>::min()
            || displacement > std::numeric_limits<std::int32_t>::max()) {
        return false;
    }

    const std::int32_t relative = static_cast<std::int32_t>(displacement);
    std::memcpy(block + call_offset + 1, &relative, sizeof(relative));
    return block[call_offset] == 0xe8;
}

const char* configLookupStatusName(
    SporeGuestConfigBooleanLookupStatus status) {
    switch (status) {
    case SporeGuestConfigBooleanLookupStatus::found:
        return "found";
    case SporeGuestConfigBooleanLookupStatus::missing:
        return "missing";
    case SporeGuestConfigBooleanLookupStatus::unsupported_type:
        return "unsupported-type";
    case SporeGuestConfigBooleanLookupStatus::not_initialized:
        return "not-initialized";
    case SporeGuestConfigBooleanLookupStatus::invalid_fixture:
        return "invalid-fixture";
    }
    return "invalid-status";
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
    std::uint32_t block_va,
    std::uint32_t block_end_va,
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
    if (block_va < optional_header.ImageBase
            || block_end_va < optional_header.ImageBase
            || block_end_va <= block_va) {
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

    const std::uint32_t block_size = block_end_va - block_va;
    const std::uint64_t block_begin =
        block_va - optional_header.ImageBase;
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

bool runPresentationModeComparison(
    void* executable_block) {
    constexpr std::size_t kFrameWords = 0x60 / sizeof(std::uint32_t);
    constexpr std::size_t kSetupFieldIndex = 0x48 / sizeof(std::uint32_t);
    constexpr std::size_t kFormatFieldIndex = 0x4c / sizeof(std::uint32_t);
    constexpr std::size_t kDepthFormatFieldIndex = 0x50 / sizeof(std::uint32_t);
    std::array<std::uint32_t, kFrameWords> frame{};
    frame[0] = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(&RestoreCallerStack));
    for (std::size_t i = 1; i < frame.size(); ++i) {
        frame[i] = 0xa5000000u + static_cast<std::uint32_t>(i);
    }

    const auto untouched_before = frame;
    g_reference_block = executable_block;
    ExecuteReferenceBlock(frame.data());
    const std::uint32_t reference_setup_field_14 =
        frame[kSetupFieldIndex];
    const std::uint32_t reference_format = frame[kFormatFieldIndex];
    const std::uint32_t reference_depth_format =
        frame[kDepthFormatFieldIndex];

    std::array<std::uint32_t, kFrameWords> translated_frame = untouched_before;
    if (!SporeTranslatedSetPresentationModeFields(
            &translated_frame[kSetupFieldIndex],
            &translated_frame[kFormatFieldIndex],
            &translated_frame[kDepthFormatFieldIndex])) {
        std::fprintf(stderr, "Translated presentation-mode block rejected outputs\n");
        return false;
    }

    bool untouched_fields_preserved = true;
    for (std::size_t i = 1; i < frame.size(); ++i) {
        if (i != kSetupFieldIndex && i != kFormatFieldIndex
                && i != kDepthFormatFieldIndex
                && (frame[i] != untouched_before[i]
                    || translated_frame[i] != untouched_before[i])) {
            untouched_fields_preserved = false;
        }
    }
    const bool output_values_match =
        reference_setup_field_14 == translated_frame[kSetupFieldIndex]
        && reference_format == translated_frame[kFormatFieldIndex]
        && reference_depth_format
            == translated_frame[kDepthFormatFieldIndex];
    std::printf(
        "presentation-mode x86-setup-field-14=0x%08x "
        "translated=0x%08x x86-format=%u translated=%u "
        "x86-depth-format=%u translated=%u untouched-fields=%s\n",
        reference_setup_field_14,
        translated_frame[kSetupFieldIndex],
        reference_format,
        translated_frame[kFormatFieldIndex],
        reference_depth_format,
        translated_frame[kDepthFormatFieldIndex],
        untouched_fields_preserved ? "PASS" : "FAIL");
    return output_values_match && untouched_fields_preserved
        && reference_setup_field_14 == 0x16
        && reference_format == 0x15
        && reference_depth_format == 0x4b;
}

bool runConfigBooleanComparison(void* executable_block) {
    constexpr std::uint32_t kHardwareVPKey = 0x00d77e9b;
    constexpr std::size_t kStackTopIndex = 16;
    constexpr std::size_t kMapSize = 0x40;
    constexpr std::size_t kRecordSize = 0x18;
    constexpr std::size_t kLookupCallOffset =
        0x006a25d8 - kBooleanGetterBlockVa;
    constexpr std::size_t kConstructionCallOffset =
        0x006a25fe - kBooleanGetterBlockVa;
    constexpr std::size_t kCleanupCallOffset =
        0x006a263c - kBooleanGetterBlockVa;
    constexpr std::size_t kDefaultBooleanImmediateOffset =
        0x006a2614 - kBooleanGetterBlockVa;

    struct ConfigBooleanCase {
        const char* name;
        bool present;
        std::uint16_t value_type;
        std::uint8_t value_flags;
        std::uint8_t inline_value;
        std::uint8_t indirect_value;
        SporeGuestConfigBooleanLookupStatus expected_status;
    };

    constexpr ConfigBooleanCase cases[] = {
        {"present-false", true, 1, 0, 0, 0,
            SporeGuestConfigBooleanLookupStatus::found},
        {"present-true", true, 1, 0, 1, 0,
            SporeGuestConfigBooleanLookupStatus::found},
        {"present-noncanonical-true", true, 1, 0, 2, 0,
            SporeGuestConfigBooleanLookupStatus::found},
        {"generic-indirect-true", true, 0x10, 0x30, 0, 1,
            SporeGuestConfigBooleanLookupStatus::found},
        {"generic-indirect-false", true, 0x10, 0x30, 0, 0,
            SporeGuestConfigBooleanLookupStatus::found},
        {"unsupported-type", true, 9, 0, 1, 0,
            SporeGuestConfigBooleanLookupStatus::unsupported_type},
        {"missing", false, 0, 0, 0, 0,
            SporeGuestConfigBooleanLookupStatus::missing}
    };

    auto* getter_block = static_cast<std::uint8_t*>(executable_block);
    if (getter_block == nullptr
            || !patchRelativeCall(
                getter_block, kLookupCallOffset,
                reinterpret_cast<const void*>(&ConfigLookupStub))
            || !patchRelativeCall(
                getter_block, kConstructionCallOffset,
                reinterpret_cast<const void*>(&ConfigValueConstructionStub))
            || !patchRelativeCall(
                getter_block, kCleanupCallOffset,
                reinterpret_cast<const void*>(&ConfigCleanupStub))) {
        std::fprintf(stderr, "Could not patch config getter fixture calls\n");
        return false;
    }

    const std::uint32_t default_boolean_address =
        static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(&g_default_config_boolean));
    std::memcpy(
        getter_block + kDefaultBooleanImmediateOffset,
        &default_boolean_address,
        sizeof(default_boolean_address));
    g_reference_block = getter_block;

    bool all_cases_passed = true;
    for (const ConfigBooleanCase& test_case : cases) {
        std::array<std::uint8_t, kRecordSize> record{};
        std::array<std::uint8_t, kMapSize> map{};
        std::uint8_t indirect_value = test_case.indirect_value;
        std::uint32_t record_key = kHardwareVPKey;
        std::memcpy(record.data(), &record_key, sizeof(record_key));

        const std::uint32_t raw_value = test_case.value_type == 0x10
                && (test_case.value_flags & 0x30) != 0
            ? static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&indirect_value))
            : test_case.inline_value;
        std::memcpy(
            record.data() + 4, &raw_value, sizeof(raw_value));
        record[0x10] = test_case.value_flags;
        std::memcpy(
            record.data() + 0x12,
            &test_case.value_type,
            sizeof(test_case.value_type));

        const std::uint32_t record_address =
            static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(record.data()));
        const std::uint32_t vector_end =
            record_address + (test_case.present ? kRecordSize : 0);
        std::memcpy(map.data() + 0x18, &record_address, sizeof(record_address));
        std::memcpy(map.data() + 0x1c, &vector_end, sizeof(vector_end));
        const std::uint32_t no_cached_values = 0;
        std::memcpy(
            map.data() + 0x38,
            &no_cached_values,
            sizeof(no_cached_values));
        g_config_lookup_result =
            test_case.present ? record_address : vector_end;
        g_reference_ecx = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(map.data()));

        std::array<std::uint32_t, 0x80 / sizeof(std::uint32_t)> frame{};
        frame[kStackTopIndex] = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(&RestoreCallerStack));
        frame[kStackTopIndex + 1] = kHardwareVPKey;
        g_reference_return_value = 0;
        ExecuteReferenceBlock(frame.data() + kStackTopIndex);
        const bool reference_value = g_reference_return_value != 0;

        SporeGuestConfigBooleanFixtureRecord translated_record{
            kHardwareVPKey,
            test_case.value_type,
            test_case.value_flags,
            test_case.inline_value,
            test_case.indirect_value
        };
        const SporeGuestConfigBooleanFixtureView config_view{
            test_case.present ? &translated_record : nullptr,
            test_case.present ? 1u : 0u,
            nullptr,
            0,
            true
        };
        bool translated_value = false;
        const SporeGuestConfigBooleanLookupStatus translated_status =
            SporeTranslatedLookupConfigBoolean(
                config_view, kHardwareVPKey, &translated_value);

        const bool case_passed =
            translated_status == test_case.expected_status
            && reference_value == translated_value;
        std::printf(
            "config-query property=HardwareVP case=%s key=0x%08x "
            "type=0x%x flags=0x%02x "
            "x86=%s/0x%02x translated=%s status=%s result=%s\n",
            test_case.name,
            kHardwareVPKey,
            test_case.value_type,
            test_case.value_flags,
            reference_value ? "true" : "false",
            g_reference_return_value,
            translated_value ? "true" : "false",
            configLookupStatusName(translated_status),
            case_passed ? "PASS" : "FAIL");
        all_cases_passed = all_cases_passed && case_passed;
    }

    const SporeGuestConfigBooleanFixtureView uninitialized_view{
        nullptr, 0, nullptr, 0, false
    };
    bool unchanged_value = true;
    const SporeGuestConfigBooleanLookupStatus uninitialized_status =
        SporeTranslatedLookupConfigBoolean(
            uninitialized_view, kHardwareVPKey, &unchanged_value);
    const bool uninitialized_passed =
        uninitialized_status
            == SporeGuestConfigBooleanLookupStatus::not_initialized
        && unchanged_value;
    std::printf(
        "config-query property=HardwareVP case=uninitialized "
        "status=%s output-unchanged=%s result=%s\n",
        configLookupStatusName(uninitialized_status),
        unchanged_value ? "PASS" : "FAIL",
        uninitialized_passed ? "PASS" : "FAIL");

    const std::uint32_t cached_values[] = {0, 7};
    bool cached_cases_passed = true;
    for (std::uint32_t key = 0; key < 2; ++key) {
        std::array<std::uint8_t, kMapSize> map{};
        const std::uint32_t record_begin = 0;
        const std::uint32_t record_end = 0;
        const std::uint32_t cached_count = 2;
        const std::uint32_t cached_address =
            static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(cached_values));
        std::memcpy(
            map.data() + 0x18, &record_begin, sizeof(record_begin));
        std::memcpy(
            map.data() + 0x1c, &record_end, sizeof(record_end));
        std::memcpy(
            map.data() + 0x38, &cached_count, sizeof(cached_count));
        std::memcpy(
            map.data() + 0x3c, &cached_address, sizeof(cached_address));
        g_reference_ecx = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(map.data()));

        std::array<std::uint32_t, 0x80 / sizeof(std::uint32_t)> frame{};
        frame[kStackTopIndex] = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(&RestoreCallerStack));
        frame[kStackTopIndex + 1] = key;
        g_reference_return_value = 0;
        ExecuteReferenceBlock(frame.data() + kStackTopIndex);
        const bool reference_value = g_reference_return_value != 0;

        const SporeGuestConfigBooleanFixtureView cached_view{
            nullptr, 0, cached_values, 2, true
        };
        bool translated_value = false;
        const SporeGuestConfigBooleanLookupStatus status =
            SporeTranslatedLookupConfigBoolean(
                cached_view, key, &translated_value);
        const bool case_passed =
            status == SporeGuestConfigBooleanLookupStatus::found
            && reference_value == translated_value;
        std::printf(
            "config-query property=HardwareVP case=cached-index-%u "
            "x86=%s translated=%s "
            "status=%s result=%s\n",
            key,
            reference_value ? "true" : "false",
            translated_value ? "true" : "false",
            configLookupStatusName(status),
            case_passed ? "PASS" : "FAIL");
        cached_cases_passed = cached_cases_passed && case_passed;
    }

    return all_cases_passed && uninitialized_passed && cached_cases_passed;
}

bool runPresentationWrapperWindowedComparison(void* executable_block) {
    if (executable_block == nullptr) {
        return false;
    }

    void* globals = VirtualAlloc(
        nullptr,
        kPresentationGlobalsSize,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_READWRITE);
    if (globals == nullptr) {
        const DWORD error = GetLastError();
        std::fprintf(
            stderr,
            "Could not allocate x86 reference globals: %lu\n",
            error);
        return false;
    }
    if (reinterpret_cast<std::uintptr_t>(globals)
            + kPresentationGlobalsSize
        > std::numeric_limits<std::uint32_t>::max()) {
        VirtualFree(globals, 0, MEM_RELEASE);
        std::fprintf(stderr, "x86 reference globals exceed 32-bit address space\n");
        return false;
    }

    struct GlobalReference {
        std::uint32_t address;
        std::size_t minimum_count;
        std::size_t actual_count;
    };
    GlobalReference global_references[] = {
        {0x016f8b9c, 1, 0},
        {0x016f8ba0, 1, 0},
        {0x016f8ba4, 1, 0},
        {0x016f8ba8, 1, 0},
        {0x016f8bac, 1, 0},
        {0x016f8bb0, 1, 0},
        {0x016f658c, 1, 0},
        {0x016f8bb8, 1, 0},
        {0x016f8bb4, 1, 0},
        {0x016f8bc0, 1, 0},
        {0x016f8bbc, 1, 0},
        {0x016f8bc4, 1, 0},
        {0x016f8bc8, 2, 0},
        {0x016f8bcc, 2, 0},
        {0x016f8bd0, 1, 0}
    };
    auto* relocated_code = static_cast<std::uint8_t*>(executable_block);
    constexpr std::size_t kWrapperSize =
        kPresentationWrapperEndVa - kPresentationWrapperVa;
    for (std::size_t offset = 0; offset + sizeof(std::uint32_t) <= kWrapperSize;
            ++offset) {
        std::uint32_t referenced_address = 0;
        std::memcpy(
            &referenced_address,
            relocated_code + offset,
            sizeof(referenced_address));
        for (GlobalReference& reference : global_references) {
            if (referenced_address == reference.address) {
                const std::uint32_t relocated_address =
                    static_cast<std::uint32_t>(
                        reinterpret_cast<std::uintptr_t>(globals)
                        + (reference.address - kPresentationGlobalsVa));
                std::memcpy(
                    relocated_code + offset,
                    &relocated_address,
                    sizeof(relocated_address));
                ++reference.actual_count;
                offset += sizeof(std::uint32_t) - 1;
                break;
            }
        }
    }
    for (const GlobalReference& reference : global_references) {
        if (reference.actual_count < reference.minimum_count) {
            VirtualFree(globals, 0, MEM_RELEASE);
            std::fprintf(
                stderr,
                "Unexpected FUN_011f7d00 global reference count for "
                "0x%08x: %zu\n",
                reference.address,
                reference.actual_count);
            return false;
        }
    }

    constexpr std::size_t kStackTopIndex = 16;
    constexpr std::size_t kWindowedInputOffset = 0x24 / sizeof(std::uint32_t);
    constexpr std::size_t kHardwareVPInputOffset = 0x2c / sizeof(std::uint32_t);
    constexpr std::size_t kD3DWindowedOutputOffset =
        0x016f8bbc - kPresentationGlobalsVa;
    std::array<std::uint32_t, 0x40 / sizeof(std::uint32_t)> parameters{};
    bool all_cases_passed = true;

    for (std::uint32_t windowed_input = 0; windowed_input <= 1; ++windowed_input) {
        for (std::uint32_t hardware_vp_input = 0;
                hardware_vp_input <= 1;
                ++hardware_vp_input) {
            std::memset(globals, 0, kPresentationGlobalsSize);
            parameters.fill(0);
            parameters[kWindowedInputOffset] = windowed_input;
            parameters[kHardwareVPInputOffset] = hardware_vp_input;

            std::array<std::uint32_t, 0x80 / sizeof(std::uint32_t)> frame{};
            frame[kStackTopIndex] = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&RestoreCallerStack));
            frame[kStackTopIndex + 1] = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(parameters.data()));
            g_reference_block = executable_block;
            g_reference_ecx = 0;
            ExecuteReferenceBlock(frame.data() + kStackTopIndex);

            std::uint32_t reference_windowed = 0;
            std::memcpy(
                &reference_windowed,
                static_cast<const std::uint8_t*>(globals)
                    + kD3DWindowedOutputOffset,
                sizeof(reference_windowed));
            const std::uint32_t expected_windowed =
                windowed_input == 0 ? 1u : 0u;
            const bool case_passed =
                reference_windowed == expected_windowed
                && parameters[kWindowedInputOffset] == windowed_input
                && parameters[kHardwareVPInputOffset] == hardware_vp_input;
            std::printf(
                "presentation-wrapper windowed-input=%u hardware-vp-input=%u "
                "x86-d3d.Windowed=%u expected=%u result=%s\n",
                windowed_input,
                hardware_vp_input,
                reference_windowed,
                expected_windowed,
                case_passed ? "PASS" : "FAIL");
            all_cases_passed = all_cases_passed && case_passed;
        }
    }

    VirtualFree(globals, 0, MEM_RELEASE);
    return all_cases_passed;
}

}

int wmain(int argc, wchar_t** argv) {
    std::setvbuf(stdout, nullptr, _IONBF, 0);
    if (argc != 2) {
        std::fwprintf(stderr, L"Usage: %ls <SporeApp.exe>\n", argv[0]);
        return 2;
    }

    std::vector<std::uint8_t> image;
    std::vector<std::uint8_t> dimensions_reference_bytes;
    std::vector<std::uint8_t> mode_reference_bytes;
    std::vector<std::uint8_t> config_reference_bytes;
    std::vector<std::uint8_t> presentation_wrapper_reference_bytes;
    if (!readImage(argv[1], &image)
            || !extractReferenceBlock(
                image,
                kDimensionsBlockVa,
                kDimensionsBlockEndVa,
                &dimensions_reference_bytes)
            || !extractReferenceBlock(
                image,
                kPresentationModeBlockVa,
                kPresentationModeBlockEndVa,
                &mode_reference_bytes)
            || !extractReferenceBlock(
                image,
                kBooleanGetterBlockVa,
                kBooleanGetterBlockEndVa,
                &config_reference_bytes)
            || !extractReferenceBlock(
                image,
                kPresentationWrapperVa,
                kPresentationWrapperEndVa,
                &presentation_wrapper_reference_bytes)) {
        return 1;
    }

    auto* dimensions_executable_block = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr,
        dimensions_reference_bytes.size() + 1,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE));
    if (dimensions_executable_block == nullptr) {
        std::fprintf(stderr, "VirtualAlloc failed: %lu\n", GetLastError());
        return 1;
    }
    std::memcpy(
        dimensions_executable_block,
        dimensions_reference_bytes.data(),
        dimensions_reference_bytes.size());
    dimensions_executable_block[dimensions_reference_bytes.size()] = 0xc3;
    g_reference_block = dimensions_executable_block;

    std::printf(
        "reference-function=FUN_0075f030 dimensions-block-va="
        "0x%08x-0x%08x executed-original-bytes=%zu\n",
        kDimensionsBlockVa,
        kDimensionsBlockEndVa,
        dimensions_reference_bytes.size());

    const bool first = runComparison("wide", 1280, 720);
    const bool second = runComparison("portrait-shaped", 480, 900);
    auto* mode_executable_block = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr,
        mode_reference_bytes.size() + 1,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE));
    if (mode_executable_block == nullptr) {
        VirtualFree(dimensions_executable_block, 0, MEM_RELEASE);
        std::fprintf(stderr, "VirtualAlloc failed: %lu\n", GetLastError());
        return 1;
    }
    std::memcpy(
        mode_executable_block,
        mode_reference_bytes.data(),
        mode_reference_bytes.size());
    mode_executable_block[mode_reference_bytes.size()] = 0xc3;
    std::printf(
        "reference-function=FUN_0075f030 presentation-mode-block-va="
        "0x%08x-0x%08x executed-original-bytes=%zu\n",
        kPresentationModeBlockVa,
        kPresentationModeBlockEndVa,
        mode_reference_bytes.size());
    const bool presentation_mode =
        runPresentationModeComparison(mode_executable_block);
    auto* config_executable_block = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr,
        config_reference_bytes.size() + 1,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE));
    if (config_executable_block == nullptr) {
        VirtualFree(dimensions_executable_block, 0, MEM_RELEASE);
        VirtualFree(mode_executable_block, 0, MEM_RELEASE);
        std::fprintf(stderr, "VirtualAlloc failed: %lu\n", GetLastError());
        return 1;
    }
    std::memcpy(
        config_executable_block,
        config_reference_bytes.data(),
        config_reference_bytes.size());
    config_executable_block[config_reference_bytes.size()] = 0xc3;
    std::printf(
        "reference-function=FUN_006a25a0 config-boolean-block-va="
        "0x%08x-0x%08x executed-original-bytes=%zu "
        "search-and-value-construction=fixture-stubs\n",
        kBooleanGetterBlockVa,
        kBooleanGetterBlockEndVa,
        config_reference_bytes.size());
    const bool config_boolean =
        runConfigBooleanComparison(config_executable_block);
    auto* presentation_wrapper_executable_block =
        static_cast<std::uint8_t*>(VirtualAlloc(
            nullptr,
            presentation_wrapper_reference_bytes.size() + 1,
            MEM_COMMIT | MEM_RESERVE,
            PAGE_EXECUTE_READWRITE));
    if (presentation_wrapper_executable_block == nullptr) {
        VirtualFree(dimensions_executable_block, 0, MEM_RELEASE);
        VirtualFree(mode_executable_block, 0, MEM_RELEASE);
        VirtualFree(config_executable_block, 0, MEM_RELEASE);
        std::fprintf(stderr, "VirtualAlloc failed: %lu\n", GetLastError());
        return 1;
    }
    std::memcpy(
        presentation_wrapper_executable_block,
        presentation_wrapper_reference_bytes.data(),
        presentation_wrapper_reference_bytes.size());
    presentation_wrapper_executable_block[
        presentation_wrapper_reference_bytes.size()] = 0xc3;
    std::printf(
        "reference-function=FUN_011f7d00 presentation-wrapper-va="
        "0x%08x-0x%08x executed-original-bytes=%zu\n",
        kPresentationWrapperVa,
        kPresentationWrapperEndVa,
        presentation_wrapper_reference_bytes.size());
    const bool presentation_wrapper_windowed =
        runPresentationWrapperWindowedComparison(
            presentation_wrapper_executable_block);
    std::uint32_t unused_width = 0;
    const bool null_rejected =
        !SporeTranslatedCopyBackBufferDimensions(
            nullptr, &unused_width, 1, 2)
        && !SporeTranslatedCopyBackBufferDimensions(
            &unused_width, nullptr, 1, 2)
        && !SporeTranslatedCopyBackBufferDimensions(
            &unused_width, &unused_width, 1, 2);

    VirtualFree(dimensions_executable_block, 0, MEM_RELEASE);
    VirtualFree(mode_executable_block, 0, MEM_RELEASE);
    VirtualFree(config_executable_block, 0, MEM_RELEASE);
    VirtualFree(presentation_wrapper_executable_block, 0, MEM_RELEASE);
    g_reference_block = nullptr;

    if (!first || !second || !presentation_mode || !config_boolean
            || !presentation_wrapper_windowed || !null_rejected) {
        std::fprintf(stderr, "x86 reference comparison: FAIL\n");
        return 1;
    }
    std::printf(
        "x86-original-vs-translated=PASS "
        "null-output-rejection=PASS presentation-mode=PASS "
        "config-boolean=PASS presentation-wrapper-windowed=PASS\n");
    return 0;
}
