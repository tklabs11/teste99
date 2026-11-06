#include <Windows.h>
#include <Psapi.h>

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

static_assert(sizeof(void*) == 4, "native Windows x86 build required");

constexpr std::uintptr_t kImageBase = 0x00400000u;
constexpr std::uintptr_t kThunkAddress = 0x011e073eu;
constexpr std::uintptr_t kAllocatorAddress = 0x00a221b0u;
constexpr std::uintptr_t kVirtualAllocIat = 0x013cc1c8u;

static std::vector<std::uint8_t> read_file(const char* path) {
    FILE* file = nullptr;
    if (fopen_s(&file, path, "rb") || !file) return {};
    if (fseek(file, 0, SEEK_END) || ftell(file) <= 0) {
        fclose(file);
        return {};
    }
    const auto length = static_cast<std::size_t>(ftell(file));
    rewind(file);
    std::vector<std::uint8_t> image(length);
    const auto count = fread(image.data(), 1, length, file);
    fclose(file);
    if (count != length) return {};
    return image;
}

static std::uint32_t relocate_image(std::uint8_t* mapped,
                                    const IMAGE_NT_HEADERS32* nt) {
    const auto delta = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(mapped) - kImageBase);
    if (!delta) return 0;
    const auto& directory = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];
    if (!directory.VirtualAddress || directory.Size < sizeof(IMAGE_BASE_RELOCATION) ||
        static_cast<std::uint64_t>(directory.VirtualAddress) + directory.Size >
            nt->OptionalHeader.SizeOfImage) return UINT32_MAX;
    std::uint32_t applied = 0;
    std::uint32_t position = 0;
    while (position < directory.Size) {
        if (directory.Size - position < sizeof(IMAGE_BASE_RELOCATION)) return UINT32_MAX;
        const auto* block = reinterpret_cast<const IMAGE_BASE_RELOCATION*>(
            mapped + directory.VirtualAddress + position);
        if (block->SizeOfBlock < sizeof(IMAGE_BASE_RELOCATION) ||
            block->SizeOfBlock > directory.Size - position ||
            (block->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) % sizeof(WORD))
            return UINT32_MAX;
        const auto* entries = reinterpret_cast<const WORD*>(block + 1);
        const auto count = (block->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
        for (std::uint32_t index = 0; index < count; ++index) {
            const auto type = entries[index] >> 12;
            const auto rva = static_cast<std::uint64_t>(block->VirtualAddress) +
                             (entries[index] & 0x0fffu);
            if (type == IMAGE_REL_BASED_ABSOLUTE) continue;
            if (type != IMAGE_REL_BASED_HIGHLOW ||
                rva + sizeof(std::uint32_t) > nt->OptionalHeader.SizeOfImage)
                return UINT32_MAX;
            auto* target = reinterpret_cast<std::uint32_t*>(mapped + rva);
            *target += delta;
            ++applied;
        }
        position += block->SizeOfBlock;
    }
    return applied;
}

static int capture_exception(EXCEPTION_POINTERS* info, std::uint32_t* code,
                             std::uint32_t* eip, std::uint32_t* fault,
                             std::uint32_t* access) {
    *code = info->ExceptionRecord->ExceptionCode;
    *eip = info->ContextRecord->Eip;
    if (*code == EXCEPTION_ACCESS_VIOLATION &&
        info->ExceptionRecord->NumberParameters >= 2) {
        *access = static_cast<std::uint32_t>(info->ExceptionRecord->ExceptionInformation[0]);
        *fault = static_cast<std::uint32_t>(info->ExceptionRecord->ExceptionInformation[1]);
    }
    return EXCEPTION_EXECUTE_HANDLER;
}

static int invoke(const std::uint8_t* mapped, std::uint8_t* buffer,
                  std::uint32_t* result, std::uint32_t* exception,
                  std::uint32_t* exception_eip, std::uint32_t* fault,
                  std::uint32_t* access) {
    using Thunk = void* (__cdecl*)(void*, int, std::size_t);
    auto thunk = reinterpret_cast<Thunk>(const_cast<std::uint8_t*>(mapped)
                                         + kThunkAddress - kImageBase);
    __try {
        *result = reinterpret_cast<std::uint32_t>(thunk(buffer, 0, 16));
        return 0;
    } __except(capture_exception(GetExceptionInformation(), exception,
                               exception_eip, fault, access)) {
        return 1;
    }
}

static int invoke_allocator(const std::uint8_t* mapped, std::uint8_t* object,
                            std::uint32_t* result, std::uint32_t* exception,
                            std::uint32_t* exception_eip, std::uint32_t* fault,
                            std::uint32_t* access) {
    auto* entry = const_cast<std::uint8_t*>(mapped) + kAllocatorAddress - kImageBase;
    std::uint32_t native_result = 0;
    __try {
        __asm {
            mov ecx, object
            push 4
            mov eax, entry
            call eax
            mov native_result, eax
        }
        *result = native_result;
        return 0;
    } __except(capture_exception(GetExceptionInformation(), exception,
                               exception_eip, fault, access)) {
        return 1;
    }
}

int main(int argc, char** argv) {
    SetErrorMode(SEM_NOGPFAULTERRORBOX);
    if (argc < 2 || argc > 3 ||
        (argc == 3 && std::strcmp(argv[2], "--unmap-nls") != 0 &&
         std::strcmp(argv[2], "--no-reloc") != 0 &&
         std::strcmp(argv[2], "--allocator-call-no-reloc") != 0)) {
        std::puts("usage: m7_protection_thunk_x86_reference.exe <verified SporeApp.exe> [--unmap-nls|--no-reloc|--allocator-call-no-reloc]");
        return 2;
    }
    auto file = read_file(argv[1]);
    if (file.size() < sizeof(IMAGE_DOS_HEADER)) return 3;
    const auto* dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(file.data());
    if (dos->e_magic != IMAGE_DOS_SIGNATURE || dos->e_lfanew < 0 ||
        static_cast<std::size_t>(dos->e_lfanew) + sizeof(IMAGE_NT_HEADERS32) > file.size())
        return 4;
    const auto* nt = reinterpret_cast<const IMAGE_NT_HEADERS32*>(file.data() + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE || nt->FileHeader.Machine != IMAGE_FILE_MACHINE_I386 ||
        nt->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC ||
        nt->OptionalHeader.ImageBase != kImageBase ||
        nt->OptionalHeader.SizeOfImage <= kVirtualAllocIat - kImageBase + 4)
        return 5;
    auto* mapped = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(kImageBase), nt->OptionalHeader.SizeOfImage,
        MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
    if (mapped != reinterpret_cast<void*>(kImageBase)) {
        const auto error = GetLastError();
        MEMORY_BASIC_INFORMATION region{};
        VirtualQuery(reinterpret_cast<void*>(kImageBase), &region, sizeof(region));
        char mapped_name[MAX_PATH]{};
        GetMappedFileNameA(GetCurrentProcess(), reinterpret_cast<void*>(kImageBase),
                           mapped_name, MAX_PATH);
        const auto* expected_suffix = "\\C_850.NLS";
        const auto name_length = std::strlen(mapped_name);
        const auto suffix_length = std::strlen(expected_suffix);
        if (argc == 3 && std::strcmp(argv[2], "--unmap-nls") == 0 &&
            region.AllocationBase == reinterpret_cast<void*>(kImageBase) &&
            region.Type == MEM_MAPPED && name_length >= suffix_length &&
            std::strcmp(mapped_name + name_length - suffix_length, expected_suffix) == 0) {
            const BOOL unmapped = UnmapViewOfFile(region.AllocationBase);
            if (unmapped) {
                mapped = static_cast<std::uint8_t*>(VirtualAlloc(
                    reinterpret_cast<void*>(kImageBase), nt->OptionalHeader.SizeOfImage,
                    MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
            }
            std::printf("isolated_process_nls_unmap=%d remap_after_nls=%p error=%lu\n",
                        unmapped, mapped, GetLastError());
        }
        if (mapped == reinterpret_cast<void*>(kImageBase)) {
            std::fflush(stdout);
        } else {
            std::printf("map_failure requested=00400000 actual=%p error=%lu host_image=%p "
                    "occupied_base=%p occupied_size=%zu state=%08lx type=%08lx mapped_file=%s\n",
                    mapped, error, GetModuleHandleA(nullptr), region.AllocationBase,
                    static_cast<std::size_t>(region.RegionSize), region.State, region.Type, mapped_name);
            mapped = static_cast<std::uint8_t*>(VirtualAlloc(
                reinterpret_cast<void*>(0x20000000u), nt->OptionalHeader.SizeOfImage,
                MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
            if (!mapped) mapped = static_cast<std::uint8_t*>(VirtualAlloc(
                nullptr, nt->OptionalHeader.SizeOfImage,
                MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
            if (!mapped) return 6;
            std::printf("relocated_map=%p\n", mapped);
        }
    }
    if (nt->OptionalHeader.SizeOfHeaders > file.size()) return 7;
    std::memcpy(mapped, file.data(), nt->OptionalHeader.SizeOfHeaders);
    const auto* section = IMAGE_FIRST_SECTION(nt);
    for (unsigned index = 0; index < nt->FileHeader.NumberOfSections; ++index) {
        const auto& part = section[index];
        if (static_cast<std::uint64_t>(part.PointerToRawData) + part.SizeOfRawData > file.size() ||
            static_cast<std::uint64_t>(part.VirtualAddress) + part.SizeOfRawData >
                nt->OptionalHeader.SizeOfImage) return 8;
        std::memcpy(mapped + part.VirtualAddress,
                    file.data() + part.PointerToRawData, part.SizeOfRawData);
    }
    const bool allocator_call = argc == 3 &&
        std::strcmp(argv[2], "--allocator-call-no-reloc") == 0;
    const bool no_reloc_fixture = allocator_call ||
        (argc == 3 && std::strcmp(argv[2], "--no-reloc") == 0);
    const auto relocations = no_reloc_fixture ? 0 : relocate_image(mapped, nt);
    if (relocations == UINT32_MAX) {
        std::puts("relocation_validation_failure");
        return 10;
    }
    auto* slot = reinterpret_cast<void**>(mapped + kVirtualAllocIat - kImageBase);
    *slot = reinterpret_cast<void*>(GetProcAddress(GetModuleHandleA("kernel32.dll"), "VirtualAlloc"));
    if (!*slot) return 9;
    std::array<std::uint8_t, 64> buffer{};
    buffer.fill(0xa5);
    std::array<std::uint8_t, 64> object{};
    const auto destination = reinterpret_cast<std::uint32_t>(buffer.data() + 8);
    std::memcpy(object.data() + 0x30, &destination, 4);
    std::uint32_t result = 0, exception = 0, exception_eip = 0, fault = 0, access = 0;
    std::printf("mapped=%p size=%08x relocations=%u manual_no_reloc_fixture=%d "
                "thunk=%08x virtual_alloc_iat=%p\n",
                mapped, nt->OptionalHeader.SizeOfImage, relocations, no_reloc_fixture,
                static_cast<unsigned>(kThunkAddress), *slot);
    const auto* relocated_stub = mapped + kThunkAddress - kImageBase;
    std::int32_t displacement = 0;
    std::memcpy(&displacement, relocated_stub + 1, sizeof(displacement));
    std::printf("stub_bytes=%02x%02x%02x%02x%02x computed_target=%08x\n",
                relocated_stub[0], relocated_stub[1], relocated_stub[2],
                relocated_stub[3], relocated_stub[4],
                static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(relocated_stub) +
                                           5 + displacement));
    std::fflush(stdout);
    const int status = allocator_call
        ? invoke_allocator(mapped, object.data(), &result, &exception,
                           &exception_eip, &fault, &access)
        : invoke(mapped, buffer.data() + 8, &result, &exception,
                 &exception_eip, &fault, &access);
    std::printf("case=%s destination=%08x\n",
                allocator_call ? "FUN_00a221b0" : "FUN_011e073e", destination);
    std::printf("status=%s result=%08x exception=%08x eip=%08x fault=%08x access=%u buffer=",
                status ? "exception" : "returned", result, exception,
                exception_eip, fault, access);
    for (auto byte : buffer) std::printf("%02x", byte);
    std::putchar('\n');
    std::printf("stub_after=%02x%02x%02x%02x%02x\n",
                relocated_stub[0], relocated_stub[1], relocated_stub[2],
                relocated_stub[3], relocated_stub[4]);
    if (allocator_call && status == 0) {
        buffer.fill(0xa5);
        result = exception = exception_eip = fault = access = 0;
        const int second_status = invoke_allocator(mapped, object.data(), &result,
                                                    &exception, &exception_eip, &fault,
                                                    &access);
        std::printf("second_status=%s result=%08x exception=%08x eip=%08x fault=%08x "
                    "access=%u buffer=",
                    second_status ? "exception" : "returned", result, exception,
                    exception_eip, fault, access);
        for (auto byte : buffer) std::printf("%02x", byte);
        std::putchar('\n');
    }
    // Deliberately leave the mapped image in place until process exit: the
    // original thunk may return pointers into its dynamically allocated code.
    return status;
}
