#include "BatchStaticLiftRuntime.hpp"
#include "prefix_reference_bytes.hpp"
#include "closure_reference_bytes.hpp"
#if defined(M7_COMPOSITE_ENTRY)
#include "m7_entry_reference_bytes.hpp"
#endif

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <memory>
#include <vector>

#if defined(_M_IX86)
#include <Windows.h>
#include <intrin.h>

static_assert(sizeof(void*) == sizeof(std::uint32_t), "x86 process required");
#endif

#if defined(_M_IX86)
extern "C" {
volatile std::uint32_t g_prefix_code_entry = 0;
volatile std::uint32_t g_prefix_native_object = 0;
volatile std::uint32_t g_prefix_boundary_address = 0;
volatile std::uint32_t g_prefix_restore_esp = 0;
volatile std::uint32_t g_prefix_entry_esp = 0;
volatile std::uint32_t g_prefix_saved_fs_head = 0;
volatile std::uint32_t g_prefix_boundary_fs_head = 0;
volatile std::uint32_t g_prefix_constructor_entry = 0;
void* g_prefix_data_image = nullptr;
volatile LONG g_prefix_boundary_seen = 0;
volatile std::uint32_t g_prefix_exception_code = 0;
volatile std::uint32_t g_prefix_exception_eip = 0;
volatile std::uint32_t g_prefix_exception_address = 0;
volatile std::uint32_t g_prefix_boundary_words[8]{};
CONTEXT g_prefix_boundary_context{};
}

extern "C" std::uint32_t __cdecl prefix_translate_data_pointer(
    std::uint32_t address);

extern "C" __declspec(naked) void prefix_call_constructor_entry() {
    __asm {
        push ecx
        push dword ptr [esp + 8]
        call prefix_translate_data_pointer
        add esp, 4
        mov dword ptr [esp + 8], eax
        pop ecx
        jmp dword ptr [g_prefix_constructor_entry]
    }
}

extern "C" __declspec(naked) void prefix_original_trampoline() {
    __asm {
        mov eax, dword ptr [g_prefix_saved_fs_head]
        mov dword ptr fs:[0], eax
        mov esp, dword ptr [g_prefix_restore_esp]
        pop edi
        pop esi
        pop ebp
        pop ebx
        ret
    }
}

extern "C" __declspec(naked) void invoke_original_prefix() {
    __asm {
        push ebx
        push ebp
        push esi
        push edi
        mov dword ptr [g_prefix_restore_esp], esp
        // Match the guest stack's low byte so stack-arithmetic flags compare.
        and esp, 0ffffff00h
        lea eax, [esp - 4]
        mov dword ptr [g_prefix_entry_esp], eax
        mov dword ptr fs:[0], 0ffffffffh
        mov ecx, dword ptr [g_prefix_native_object]
        mov ebx, 11223344h
        mov ebp, 55667788h
        mov esi, 99aabbcch
        mov edi, 0ddeeff00h
        mov edx, 12345678h
        mov eax, 87654321h
        push 202h
        popfd
        call dword ptr [g_prefix_code_entry]
        int 3
    }
}
#endif

BatchLiftStatus spore_lift_00a33600(
    BatchLiftMemory& memory,
    BatchLiftState& state);
BatchLiftStatus spore_lift_00fee000(
    BatchLiftMemory& memory,
    BatchLiftState& state);
#if defined(M7_COMPOSITE_ENTRY)
BatchLiftStatus spore_lift_00a2a210(
    BatchLiftMemory& memory,
    BatchLiftState& state);
#endif

namespace {

constexpr std::uint32_t kObjectBase = 0x20000000u;
#if defined(M7_THROUGH_FIFTH_FIRST_CALL)
constexpr std::uint32_t kObjectBytes = 0x115b10u;
#elif defined(M7_THROUGH_FOURTH_FIRST_CALL)
constexpr std::uint32_t kObjectBytes = 0x7c600u;
#elif defined(M7_THROUGH_THIRD_CHILD_RETURN)
constexpr std::uint32_t kObjectBytes = 0x3500u;
#elif defined(M7_THROUGH_SECOND_CHILD_RETURN)
constexpr std::uint32_t kObjectBytes = 0x2500u;
#elif defined(M7_THROUGH_FIRST_CALL)
constexpr std::uint32_t kObjectBytes = 0x1100u;
#else
constexpr std::uint32_t kObjectBytes = 0x404u;
#endif
constexpr std::uint32_t kPrefixStackBase = 0x71000000u;
constexpr std::uint32_t kPrefixStackBytes = 0x4000u;
constexpr std::uint32_t kPrefixStackTopOffset = 0x3000u;
constexpr std::uint32_t kPrefixEntryEsp =
    kPrefixStackBase + kPrefixStackTopOffset - sizeof(std::uint32_t);
constexpr std::uint32_t kObjectCanary = 0x8badf00du;
#if defined(M7_COMPOSITE_ENTRY)
#if defined(M7_THROUGH_FIFTH_THIRD_ENTRY)
constexpr std::uint32_t kCompositeStop = 0x00a23715u;
#elif defined(M7_THROUGH_FIFTH_SECOND_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a30e9eu;
#elif defined(M7_THROUGH_FIFTH_FIRST_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a30e75u;
#elif defined(M7_THROUGH_FIFTH_CHILD_ENTRY)
constexpr std::uint32_t kCompositeStop = 0x00a30e4eu;
#elif defined(M7_THROUGH_FOURTH_CHILD_RETURN)
constexpr std::uint32_t kCompositeStop = 0x00a3387fu;
#elif defined(M7_THROUGH_FOURTH_HELPER_ALLOCATOR_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a2a3e6u;
#elif defined(M7_THROUGH_FOURTH_HELPER_FLOAT_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a236bdu;
#elif defined(M7_THROUGH_FOURTH_THIRD_FIRST_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a236b2u;
#elif defined(M7_THROUGH_FOURTH_THIRD_ENTRY)
constexpr std::uint32_t kCompositeStop = 0x00a23665u;
#elif defined(M7_THROUGH_FOURTH_SECOND_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a2a39eu;
#elif defined(M7_THROUGH_FOURTH_FIRST_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a2a375u;
#elif defined(M7_THROUGH_FOURTH_CHILD_ENTRY)
constexpr std::uint32_t kCompositeStop = 0x00a2a34eu;
#elif defined(M7_THROUGH_THIRD_CHILD_RETURN)
constexpr std::uint32_t kCompositeStop = 0x00a33865u;
#elif defined(M7_THROUGH_SECOND_CHILD_RETURN)
constexpr std::uint32_t kCompositeStop = 0x00a3384bu;
#elif defined(M7_THROUGH_CHILD_RETURN)
constexpr std::uint32_t kCompositeStop = 0x00a33831u;
#elif defined(M7_THROUGH_FLOAT_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a2a2eeu;
#elif defined(M7_THROUGH_MEMSET)
constexpr std::uint32_t kCompositeStop = 0x00a2a2e6u;
#elif defined(M7_THROUGH_THIRD_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a221fcu;
#elif defined(M7_THROUGH_SECOND_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a2a29eu;
#elif defined(M7_THROUGH_FIRST_CALL)
constexpr std::uint32_t kCompositeStop = 0x00a2a275u;
#else
constexpr std::uint32_t kCompositeStop = 0x00a2a24eu;
#endif
#endif
constexpr std::uint32_t kIndexedTestEntry = 0x00fee000u;
constexpr std::uint32_t kIndexedObjectBase = 0x52000000u;
constexpr std::size_t kIndexedObjectBytes = 0x100u;
constexpr std::uint32_t kIndexedStoreValue = 0xdecafbad;
constexpr std::uint32_t kIndexedTestFlags = 0x000008d7u;
#if defined(_M_IX86)
#if defined(M7_THROUGH_FIFTH_CHILD_ENTRY)
constexpr std::uint32_t kAllocationBytes = 0x12000u;
#else
constexpr std::uint32_t kAllocationBytes = 0x10000u;
#endif
volatile std::uint32_t g_indexed_flags_before = 0;
volatile std::uint32_t g_indexed_flags_after = 0;
volatile std::uint32_t g_indexed_exception_code = 0;

__declspec(noinline) bool run_native_indexed_store(
    std::uint8_t* base,
    std::uint32_t index,
    std::uint32_t value) {
    g_indexed_exception_code = 0u;
    __try {
        __asm {
            push esi
            mov esi, base
            mov eax, index
            mov ecx, value
            pushfd
            pop edx
            mov dword ptr [g_indexed_flags_before], edx
            mov dword ptr [esi + eax * 4 + 02ch], ecx
            pushfd
            pop edx
            mov dword ptr [g_indexed_flags_after], edx
            pop esi
        }
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        g_indexed_exception_code = GetExceptionCode();
        return false;
    }
}
#endif
constexpr std::uint32_t kFlagMask = 0x000008c5u;

#if defined(_M_IX86)
constexpr std::uint32_t kClosureCodeBase = 0x00921e00u;
constexpr std::size_t kClosureCodeBytes = 0x1000u;
constexpr std::uint32_t kClosureIatBase = 0x013cc000u;
constexpr std::uint32_t kResmanClosureCodeBase = 0x00a0f000u;
constexpr std::size_t kResmanClosureCodeBytes = 0x16000u;
constexpr std::uint32_t kConstructorClosureCodeBase = 0x011e5000u;
constexpr std::size_t kConstructorClosureCodeBytes = 0x90000u;
std::array<std::uint32_t, 16> g_native_handles{};
std::size_t g_native_handle_count{};
std::array<std::uint32_t, 16> g_native_critical_sections{};
std::size_t g_native_critical_section_count{};

std::uint32_t native_address32(const void* pointer) {
    return static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(pointer));
}

void record_native_handle(HANDLE handle, const char* symbol) {
    const std::uint32_t value = native_address32(handle);
    const bool already_recorded = std::find(
        g_native_handles.begin(),
        g_native_handles.begin()
            + static_cast<std::ptrdiff_t>(g_native_handle_count),
        value) != g_native_handles.begin()
            + static_cast<std::ptrdiff_t>(g_native_handle_count);
    if (handle != nullptr && !already_recorded
        && g_native_handle_count < g_native_handles.size()) {
        g_native_handles[g_native_handle_count++] = value;
    }
    std::fprintf(
        stderr, "NATIVE_IMPORT %s result=%08x\n", symbol, value);
}

extern "C" __declspec(noinline) char* __cdecl prefix_strncpy(
    char* destination,
    const char* source,
    std::size_t count) {
#pragma warning(push)
#pragma warning(disable: 4996)
    char* result = std::strncpy(destination, source, count);
#pragma warning(pop)
    std::fprintf(
        stderr, "NATIVE_IMPORT MSVCR90.dll!strncpy count=%u\n",
        static_cast<unsigned>(count));
    return result;
}

extern "C" __declspec(noinline) void* __cdecl prefix_memset(
    void* destination, int value, std::size_t count) {
    void* result = std::memset(destination, value, count);
    std::fprintf(stderr, "NATIVE_IMPORT_MODEL MSVCR90.dll!memset "
                         "count=%u value=%u\n",
                 static_cast<unsigned>(count),
                 static_cast<unsigned>(value) & 0xffu);
    return result;
}

extern "C" __declspec(noinline) HANDLE WINAPI prefix_create_mutex(
    LPSECURITY_ATTRIBUTES attributes,
    BOOL initial_owner,
    LPCSTR name) {
    HANDLE result = CreateMutexA(attributes, initial_owner, name);
    record_native_handle(result, "KERNEL32.dll!CreateMutexA");
    return result;
}

extern "C" __declspec(noinline) HANDLE WINAPI prefix_create_semaphore(
    LPSECURITY_ATTRIBUTES attributes,
    LONG initial_count,
    LONG maximum_count,
    LPCSTR name) {
    HANDLE result = CreateSemaphoreA(
        attributes, initial_count, maximum_count, name);
    record_native_handle(result, "KERNEL32.dll!CreateSemaphoreA");
    return result;
}

extern "C" __declspec(noinline) void WINAPI prefix_initialize_critical_section(
    LPCRITICAL_SECTION section) {
    InitializeCriticalSection(section);
    std::fprintf(
        stderr, "NATIVE_IMPORT KERNEL32.dll!InitializeCriticalSection\n");
    const std::uint32_t address = native_address32(section);
    const auto end = g_native_critical_sections.begin()
        + static_cast<std::ptrdiff_t>(g_native_critical_section_count);
    if (std::find(g_native_critical_sections.begin(), end, address) == end
        && g_native_critical_section_count < g_native_critical_sections.size()) {
        g_native_critical_sections[g_native_critical_section_count++] = address;
    }
}

extern "C" __declspec(noinline) void WINAPI prefix_enter_critical_section(
    LPCRITICAL_SECTION section) {
    EnterCriticalSection(section);
    std::fprintf(
        stderr, "NATIVE_IMPORT KERNEL32.dll!EnterCriticalSection\n");
}

extern "C" __declspec(noinline) void WINAPI prefix_leave_critical_section(
    LPCRITICAL_SECTION section) {
    LeaveCriticalSection(section);
    std::fprintf(
        stderr, "NATIVE_IMPORT KERNEL32.dll!LeaveCriticalSection\n");
}

void cleanup_native_synchronization(void* object) {
    const std::uint32_t object_base = native_address32(object);
    for (std::size_t index = 0;
         index < g_native_critical_section_count; ++index) {
        const std::uint32_t address = g_native_critical_sections[index];
        if (address >= object_base
            && address - object_base <= 0x1000u
                - sizeof(CRITICAL_SECTION)) {
            DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(
                static_cast<std::uintptr_t>(address)));
        }
        g_native_critical_sections[index] = 0u;
    }
    g_native_critical_section_count = 0u;
    for (std::size_t index = 0; index < g_native_handle_count; ++index) {
        CloseHandle(reinterpret_cast<HANDLE>(g_native_handles[index]));
        g_native_handles[index] = 0u;
    }
    g_native_handle_count = 0u;
}

template <std::size_t N>
bool copy_verified_instructions(
    std::uint8_t* output,
    std::size_t output_size,
    std::uint32_t address_base,
    const std::array<SporeVerifiedInstruction, N>& instructions) {
    for (const SporeVerifiedInstruction& instruction : instructions) {
        if (instruction.address < address_base) return false;
        const std::size_t offset =
            static_cast<std::size_t>(instruction.address - address_base);
        if (offset > output_size
            || instruction.length > output_size - offset) {
            return false;
        }
        std::memcpy(
            output + offset, instruction.bytes.data(), instruction.length);
    }
    return true;
}

class NativeClosureImage {
public:
    ~NativeClosureImage() {
        if (code != nullptr) VirtualFree(code, 0u, MEM_RELEASE);
        if (resman_code != nullptr) {
            VirtualFree(resman_code, 0u, MEM_RELEASE);
        }
        if (constructor_code != nullptr) {
            VirtualFree(constructor_code, 0u, MEM_RELEASE);
        }
        if (iat != nullptr) VirtualFree(iat, 0u, MEM_RELEASE);
    }

    bool initialize() {
        code = static_cast<std::uint8_t*>(VirtualAlloc(
            nullptr, kClosureCodeBytes, MEM_RESERVE | MEM_COMMIT,
            PAGE_READWRITE));
        resman_code = static_cast<std::uint8_t*>(VirtualAlloc(
            nullptr, kResmanClosureCodeBytes,
            MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
        constructor_code = static_cast<std::uint8_t*>(VirtualAlloc(
            nullptr, kConstructorClosureCodeBytes,
            MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
        iat = static_cast<std::uint8_t*>(VirtualAlloc(
            nullptr, 0x1000u, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
        if (code == nullptr || resman_code == nullptr
            || constructor_code == nullptr || iat == nullptr) {
            return false;
        }
        std::memset(code, 0xccu, kClosureCodeBytes);
        std::memset(resman_code, 0xccu, kResmanClosureCodeBytes);
        std::memset(constructor_code, 0xccu, kConstructorClosureCodeBytes);
        if (!copy_verified_instructions(
                code, kClosureCodeBytes, kClosureCodeBase,
                kSporeInstructions_00921e00)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kClosureCodeBase,
                kSporeInstructions_00921e60)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kClosureCodeBase,
                kSporeInstructions_00921f00)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kClosureCodeBase,
                kSporeInstructions_00922150)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kClosureCodeBase,
                kSporeInstructions_009222a0)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kClosureCodeBase,
                kSporeInstructions_009225d0)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kClosureCodeBase,
                kSporeInstructions_00922620)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kClosureCodeBase,
                kSporeInstructions_00922820)
            || !copy_verified_instructions(
                resman_code, kResmanClosureCodeBytes,
                kResmanClosureCodeBase, kSporeInstructions_00a247f0)
            || !copy_verified_instructions(
                resman_code, kResmanClosureCodeBytes,
                kResmanClosureCodeBase, kSporeInstructions_00a0fdf0)
            || !copy_verified_instructions(
                constructor_code, kConstructorClosureCodeBytes,
                kConstructorClosureCodeBase,
                kSporeInstructions_011e64f0)
            || !copy_verified_instructions(
                constructor_code, kConstructorClosureCodeBytes,
                kConstructorClosureCodeBase,
                kSporeInstructions_011ecd90)
            || !copy_verified_instructions(
                constructor_code, kConstructorClosureCodeBytes,
                kConstructorClosureCodeBase,
                kSporeInstructions_011ecdd0)
            || !copy_verified_instructions(
                constructor_code, kConstructorClosureCodeBytes,
                kConstructorClosureCodeBase,
                kSporeInstructions_011ecde0)
            || !copy_verified_instructions(
                constructor_code, kConstructorClosureCodeBytes,
                kConstructorClosureCodeBase,
                kSporeInstructions_011e5d80)
            || !copy_verified_instructions(
                constructor_code, kConstructorClosureCodeBytes,
                kConstructorClosureCodeBase,
                kSporeInstructions_011e8b20)
            || !install_import(
                code, kClosureCodeBase, kClosureCodeBytes,
                0x00921e18u, 0x013cc4f4u,
                reinterpret_cast<std::uintptr_t>(&prefix_strncpy))
            || !install_import(
                code, kClosureCodeBase, kClosureCodeBytes,
                0x0092216cu, 0x013cc2d0u,
                reinterpret_cast<std::uintptr_t>(
                    &prefix_initialize_critical_section))
            || !install_import(
                code, kClosureCodeBase, kClosureCodeBytes,
                0x00922189u, 0x013cc180u,
                reinterpret_cast<std::uintptr_t>(&prefix_create_mutex))
            || !install_import(
                code, kClosureCodeBase, kClosureCodeBytes,
                0x009225efu, 0x013cc4f4u,
                reinterpret_cast<std::uintptr_t>(&prefix_strncpy))
            || !install_import(
                code, kClosureCodeBase, kClosureCodeBytes,
                0x0092266du, 0x013cc198u,
                reinterpret_cast<std::uintptr_t>(&prefix_create_semaphore))
            || !install_import(
                constructor_code, kConstructorClosureCodeBase,
                kConstructorClosureCodeBytes,
                0x011e653fu, 0x013cc4f4u,
                reinterpret_cast<std::uintptr_t>(&prefix_strncpy))
            || !install_import(
                constructor_code, kConstructorClosureCodeBase,
                kConstructorClosureCodeBytes,
                0x011ecd97u, 0x013cc2d0u,
                reinterpret_cast<std::uintptr_t>(
                    &prefix_initialize_critical_section))
            || !install_import(
                constructor_code, kConstructorClosureCodeBase,
                kConstructorClosureCodeBytes,
                0x011ecdd9u, 0x013cc2d8u,
                reinterpret_cast<std::uintptr_t>(
                    &prefix_enter_critical_section))
            || !install_import(
                constructor_code, kConstructorClosureCodeBase,
                kConstructorClosureCodeBytes,
                0x011ecde9u, 0x013cc2dcu,
                reinterpret_cast<std::uintptr_t>(
                    &prefix_leave_critical_section))) {
            return false;
        }
        return true;
    }

    bool make_executable() {
        DWORD previous_protection{};
        if (!VirtualProtect(
                code, kClosureCodeBytes, PAGE_EXECUTE_READ,
                &previous_protection)
            || !VirtualProtect(
                resman_code, kResmanClosureCodeBytes, PAGE_EXECUTE_READ,
                &previous_protection)
            || !VirtualProtect(
                constructor_code, kConstructorClosureCodeBytes,
                PAGE_EXECUTE_READ, &previous_protection)) {
            return false;
        }
        FlushInstructionCache(
            GetCurrentProcess(), code, kClosureCodeBytes);
        FlushInstructionCache(
            GetCurrentProcess(), resman_code, kResmanClosureCodeBytes);
        FlushInstructionCache(
            GetCurrentProcess(), constructor_code,
            kConstructorClosureCodeBytes);
        return true;
    }

    std::uint8_t* entry(std::uint32_t address) const {
        if (address >= kClosureCodeBase
            && address - kClosureCodeBase < kClosureCodeBytes) {
            return code + (address - kClosureCodeBase);
        }
        if (address >= kResmanClosureCodeBase
            && address - kResmanClosureCodeBase < kResmanClosureCodeBytes) {
            return resman_code + (address - kResmanClosureCodeBase);
        }
        if (address >= kConstructorClosureCodeBase
            && address - kConstructorClosureCodeBase
                < kConstructorClosureCodeBytes) {
            return constructor_code
                + (address - kConstructorClosureCodeBase);
        }
        return nullptr;
    }

private:
    bool install_import(
        std::uint8_t* code_image,
        std::uint32_t code_base,
        std::size_t code_size,
        std::uint32_t site,
        std::uint32_t original_iat,
        std::uintptr_t target) {
        if (original_iat < kClosureIatBase || site < code_base) {
            return false;
        }
        const std::size_t iat_offset = original_iat - kClosureIatBase;
        const std::size_t code_offset = site - code_base;
        if (iat_offset > 0x1000u - sizeof(std::uint32_t)
            || code_offset > code_size - 6u) {
            return false;
        }
        std::uint32_t encoded_iat{};
        std::memcpy(
            &encoded_iat, code_image + code_offset + 2u,
            sizeof(encoded_iat));
        if (code_image[code_offset] != 0xffu
            || code_image[code_offset + 1u] != 0x15u
            || encoded_iat != original_iat) {
            return false;
        }
        const std::uint32_t target_address =
            static_cast<std::uint32_t>(target);
        std::memcpy(iat + iat_offset, &target_address, sizeof(target_address));
        const std::uint32_t relocated_iat =
            native_address32(iat + iat_offset);
        std::memcpy(
            code_image + code_offset + 2u,
            &relocated_iat,
            sizeof(relocated_iat));
        return true;
    }

    std::uint8_t* code{};
    std::uint8_t* resman_code{};
    std::uint8_t* constructor_code{};
    std::uint8_t* iat{};
};

class NativePeDataImage {
public:
    ~NativePeDataImage() {
        for (void* region : mapped_regions_) {
            if (region != nullptr) VirtualFree(region, 0u, MEM_RELEASE);
        }
    }

    bool initialize() {
        constexpr std::uint32_t kPageSize = 0x1000u;
        for (std::size_t index = 0;
             index < kSporePrefixDataRanges.size();
             ++index) {
            const SporeVerifiedDataRange& range =
                kSporePrefixDataRanges[index];
            if (range.bytes == nullptr || range.length == 0u
                || range.address % kPageSize != 0u
                || range.length % kPageSize != 0u) {
                std::fprintf(
                    stderr,
                    "invalid verified PE data range at %08x length=%u\n",
                    range.address,
                    range.length);
                return false;
            }

            mapped_regions_[index] = VirtualAlloc(
                nullptr,
                range.length,
                MEM_RESERVE | MEM_COMMIT,
                PAGE_READWRITE);
            if (mapped_regions_[index] == nullptr) {
                std::fprintf(
                    stderr,
                    "could not allocate verified PE data for %08x "
                    "error=%lu\n",
                    range.address,
                    GetLastError());
                return false;
            }
            std::memcpy(
                mapped_regions_[index],
                range.bytes,
                static_cast<std::size_t>(range.length));
            DWORD previous_protection{};
            if (!VirtualProtect(
                    mapped_regions_[index],
                    range.length,
                    PAGE_READONLY,
                    &previous_protection)) {
                std::fprintf(
                    stderr,
                    "could not protect verified PE data at %08x "
                    "error=%lu\n",
                    range.address,
                    GetLastError());
                return false;
            }
        }
        return true;
    }

    std::uint32_t host_address(
        std::uint32_t guest_address,
        std::uint32_t access_size) const {
        for (std::size_t index = 0;
             index < kSporePrefixDataRanges.size();
             ++index) {
            const SporeVerifiedDataRange& range =
                kSporePrefixDataRanges[index];
            if (guest_address < range.address
                || access_size > range.length
                || guest_address - range.address
                    > range.length - access_size) {
                continue;
            }
            const auto* host_bytes =
                static_cast<const std::uint8_t*>(mapped_regions_[index]);
            return native_address32(
                host_bytes + (guest_address - range.address));
        }
        return 0u;
    }

private:
    std::array<void*, kSporePrefixDataRanges.size()> mapped_regions_{};
};

extern "C" std::uint32_t __cdecl prefix_translate_data_pointer(
    std::uint32_t address) {
    const auto* data_image =
        static_cast<const NativePeDataImage*>(g_prefix_data_image);
    if (data_image == nullptr) return address;
    const std::uint32_t host_address = data_image->host_address(address, 1u);
    return host_address == 0u ? address : host_address;
}

bool relocate_absolute_data_operand(
    std::uint8_t* code,
    std::uint32_t code_entry,
    std::uint32_t instruction_address,
    const std::uint8_t* expected_instruction,
    std::size_t instruction_length,
    std::size_t operand_offset,
    std::uint32_t guest_data_address,
    const NativePeDataImage& data_image) {
    if (instruction_address < code_entry
        || operand_offset > instruction_length
        || sizeof(std::uint32_t) > instruction_length - operand_offset) {
        return false;
    }
    const std::size_t code_offset = instruction_address - code_entry;
    if (std::memcmp(
            code + code_offset,
            expected_instruction,
            instruction_length) != 0) {
        return false;
    }
    const std::uint32_t host_address =
        data_image.host_address(guest_data_address, sizeof(std::uint32_t));
    if (host_address == 0u) return false;
    std::memcpy(
        code + code_offset + operand_offset,
        &host_address,
        sizeof(host_address));
    return true;
}

bool relocate_direct_call(std::uint8_t* instruction, const void* target) {
    if (instruction[0] != 0xe8u) return false;
    const std::int64_t return_address =
        static_cast<std::int64_t>(
            reinterpret_cast<std::uintptr_t>(instruction)) + 5;
    const std::int64_t delta =
        static_cast<std::int64_t>(
            reinterpret_cast<std::uintptr_t>(target)) - return_address;
    if (delta < INT32_MIN || delta > INT32_MAX) return false;
    const std::int32_t encoded_delta = static_cast<std::int32_t>(delta);
    std::memcpy(instruction + 1u, &encoded_delta, sizeof(encoded_delta));
    return true;
}

LONG CALLBACK capture_prefix_boundary(EXCEPTION_POINTERS* exception) {
    if (exception == nullptr
        || exception->ExceptionRecord == nullptr
        || exception->ContextRecord == nullptr) {
        return EXCEPTION_CONTINUE_SEARCH;
    }
    g_prefix_boundary_context = *exception->ContextRecord;
    g_prefix_boundary_fs_head = __readfsdword(0);
    const auto* stack = reinterpret_cast<const std::uint32_t*>(
        exception->ContextRecord->Esp);
    const auto* entry_frame = reinterpret_cast<const std::uint32_t*>(
        static_cast<std::uintptr_t>(g_prefix_entry_esp - 16u));
    for (unsigned index = 0; index < 4; ++index) {
        g_prefix_boundary_words[index] = stack[index];
        g_prefix_boundary_words[index + 4u] = entry_frame[index];
    }
    g_prefix_exception_code = exception->ExceptionRecord->ExceptionCode;
    g_prefix_exception_eip = exception->ContextRecord->Eip;
    g_prefix_exception_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(
            exception->ExceptionRecord->ExceptionAddress));
    g_prefix_boundary_seen =
        g_prefix_exception_code == EXCEPTION_BREAKPOINT
            && g_prefix_exception_eip == g_prefix_boundary_address
        ? 1 : -1;
    exception->ContextRecord->Eip =
        static_cast<DWORD>(reinterpret_cast<std::uintptr_t>(
            &prefix_original_trampoline));
    return EXCEPTION_CONTINUE_EXECUTION;
}
#endif

struct Snapshot {
    std::uint32_t regs[8]{};
    std::uint32_t esp_delta{};
    std::uint32_t eflags{};
    std::uint32_t fs_head_delta{};
    std::uint32_t seh_previous{};
    std::uint32_t seh_handler{};
    std::uint32_t seh_cookie{};
    std::uint32_t stack_object{};
    std::uint32_t saved_registers[4]{};
    std::uint32_t object_words[kObjectBytes / sizeof(std::uint32_t)]{};
};

bool run_guest_indexed_store(
    std::uint32_t index,
    std::array<std::uint8_t, kIndexedObjectBytes>& object,
    BatchLiftStatus& status) {
    BatchLiftMemory memory;
    if (!memory.map_region(
            kIndexedObjectBase, object.data(), object.size(), true)) {
        return false;
    }
    BatchLiftState state{};
    state.regs[0] = index;
    state.regs[1] = kIndexedStoreValue;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.regs[6] = kIndexedObjectBase;
    state.eflags = kIndexedTestFlags;
    state.eip = kIndexedTestEntry;
    status = spore_lift_00fee000(memory, state);
    if (state.eflags != kIndexedTestFlags) {
        return false;
    }
    if (index == 53u) {
        return status == BatchLiftStatus::invalid_memory;
    }
    return status == BatchLiftStatus::returned
        && state.eip == BatchLiftMemory::kReturnSentinel
        && state.regs[4] == BatchLiftMemory::kEntryEsp + 4u;
}

bool run_indexed_store_regression() {
    constexpr std::array<std::uint32_t, 4> valid_indices = {
        0u, 1u, 52u, 0xffffffffu,
    };
#if defined(_M_IX86)
    SYSTEM_INFO system_info{};
    GetSystemInfo(&system_info);
    const std::size_t page_size = system_info.dwPageSize;
    void* guarded_pages = VirtualAlloc(
        nullptr, page_size * 2u, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (guarded_pages == nullptr) {
        std::fprintf(stderr, "could not allocate indexed-store guard pages\n");
        return false;
    }
    DWORD old_protection{};
    auto* guard_page = static_cast<std::uint8_t*>(guarded_pages) + page_size;
    if (!VirtualProtect(
            guard_page, page_size, PAGE_NOACCESS, &old_protection)) {
        VirtualFree(guarded_pages, 0u, MEM_RELEASE);
        std::fprintf(stderr, "could not protect indexed-store guard page\n");
        return false;
    }
    auto* native_object = guard_page - kIndexedObjectBytes;
#endif

    for (const std::uint32_t index : valid_indices) {
        std::array<std::uint8_t, kIndexedObjectBytes> guest_object{};
        BatchLiftStatus status{};
        if (!run_guest_indexed_store(index, guest_object, status)) {
#if defined(_M_IX86)
            VirtualFree(guarded_pages, 0u, MEM_RELEASE);
#endif
            std::fprintf(
                stderr, "indexed-store guest failed for index=%08x\n", index);
            return false;
        }
#if defined(_M_IX86)
        std::memset(native_object, 0, kIndexedObjectBytes);
        const bool native_completed = run_native_indexed_store(
            native_object, index, kIndexedStoreValue);
        if (!native_completed
            || g_indexed_flags_before != g_indexed_flags_after
            || std::memcmp(
                native_object, guest_object.data(), kIndexedObjectBytes) != 0) {
            VirtualFree(guarded_pages, 0u, MEM_RELEASE);
            std::fprintf(
                stderr,
                "indexed-store x86 differential failed for index=%08x "
                "native_flags=%08x/%08x exception=%08x\n",
                index,
                g_indexed_flags_before,
                g_indexed_flags_after,
                g_indexed_exception_code);
            return false;
        }
#endif
    }

    std::array<std::uint8_t, kIndexedObjectBytes> invalid_guest_object{};
    BatchLiftStatus invalid_guest_status{};
    if (!run_guest_indexed_store(
            53u, invalid_guest_object, invalid_guest_status)
        || invalid_guest_status != BatchLiftStatus::invalid_memory
        || std::any_of(
            invalid_guest_object.begin(), invalid_guest_object.end(),
            [](std::uint8_t value) { return value != 0u; })) {
#if defined(_M_IX86)
        VirtualFree(guarded_pages, 0u, MEM_RELEASE);
#endif
        std::fprintf(stderr, "indexed-store guest bounds check failed\n");
        return false;
    }
#if defined(_M_IX86)
    std::memset(native_object, 0, kIndexedObjectBytes);
    const bool native_completed = run_native_indexed_store(
        native_object, 53u, kIndexedStoreValue);
    const bool native_faulted =
        !native_completed
        && g_indexed_exception_code == EXCEPTION_ACCESS_VIOLATION
        && std::all_of(
            native_object, native_object + kIndexedObjectBytes,
            [](std::uint8_t value) { return value == 0u; });
    VirtualFree(guarded_pages, 0u, MEM_RELEASE);
    if (!native_faulted) {
        std::fprintf(
            stderr,
            "indexed-store native bounds check did not raise access violation "
            "(exception=%08x)\n",
            g_indexed_exception_code);
        return false;
    }
    std::printf(
        "PASS indexed_mov x86_reference=windows_x86 native_bytes=894c862c "
        "valid_indices=0,1,52,ffffffff invalid_index=53 "
        "flags=preserved\n");
#else
    std::printf(
        "PASS indexed_mov guest=arm64_lift valid_indices=0,1,52,ffffffff "
        "invalid_index=53 flags=preserved\n");
#endif
    return true;
}

bool read_guest_snapshot(
    BatchLiftMemory& memory,
    const BatchLiftState& state,
    BatchLiftStatus status,
    Snapshot& snapshot) {
    if (status != BatchLiftStatus::unsupported_dependency
        || state.eip !=
#if defined(M7_COMPOSITE_ENTRY)
            kCompositeStop
#else
            kSporePrefixStop
#endif
        ) {
        std::fprintf(
            stderr,
            "guest prefix stopped unexpectedly: status=%u eip=%08x\n",
            static_cast<unsigned>(status),
            state.eip);
        return false;
    }
    for (unsigned index = 0; index < 8; ++index) {
        snapshot.regs[index] = index == 4u ? 0u : state.regs[index];
    }
    snapshot.esp_delta = state.regs[4] - kPrefixEntryEsp;
    snapshot.eflags = state.eflags & kFlagMask;
    std::uint32_t fs_head{};
    if (!memory.load32(0x30000000u, fs_head)
        || !memory.load32(kPrefixEntryEsp - 12u, snapshot.seh_previous)
        || !memory.load32(kPrefixEntryEsp - 8u, snapshot.seh_handler)
        || !memory.load32(kPrefixEntryEsp - 4u, snapshot.seh_cookie)
        || !memory.load32(kPrefixEntryEsp - 16u, snapshot.stack_object)) {
        return false;
    }
    snapshot.fs_head_delta = fs_head - kPrefixEntryEsp;
    for (unsigned index = 0; index < 4; ++index) {
        if (!memory.load32(
                state.regs[4] + index * 4u,
                snapshot.saved_registers[index])) {
            return false;
        }
    }
    for (unsigned index = 0; index < kObjectBytes / sizeof(std::uint32_t); ++index) {
        if (!memory.load32(
                kObjectBase + index * 4u,
                snapshot.object_words[index])) {
            return false;
        }
    }
    return true;
}

bool normalize_guest_handles(
    Snapshot& snapshot,
    const BatchGuestRuntime& runtime) {
    std::array<std::uint32_t, 16> handles{};
    std::size_t handle_count = 0;
    for (const BatchGuestImportCall& call : runtime.calls()) {
        if (call.symbol != "KERNEL32.dll!CreateMutexA"
            && call.symbol != "KERNEL32.dll!CreateSemaphoreA") {
            continue;
        }
        if (call.result == 0u) continue;
        const auto end = handles.begin()
            + static_cast<std::ptrdiff_t>(handle_count);
        if (std::find(handles.begin(), end, call.result) != end) continue;
        if (handle_count >= handles.size()) {
            std::fprintf(stderr, "too many guest handles to normalize\n");
            return false;
        }
        handles[handle_count++] = call.result;
    }

    for (std::uint32_t& value : snapshot.object_words) {
        for (std::size_t index = 0; index < handle_count; ++index) {
            if (value == handles[index]) {
                value = 0xc0000001u + static_cast<std::uint32_t>(index);
                break;
            }
        }
    }
    return true;
}

bool run_lifted_prefix(Snapshot& snapshot) {
    BatchLiftMemory memory;
#if defined(M7_THROUGH_FIFTH_FIRST_CALL)
    std::vector<std::uint8_t> object(kObjectBytes + sizeof(std::uint32_t));
#else
    std::array<std::uint8_t, kObjectBytes + sizeof(std::uint32_t)> object{};
#endif
    std::array<std::uint8_t, kPrefixStackBytes> stack{};
    std::array<std::uint8_t, 4> fs{};
    std::vector<std::vector<std::uint8_t>> pe_data_backing;
    if (!memory.map_region(kObjectBase, object.data(), object.size(), true)
        || !memory.map_region(0x30000000u, fs.data(), fs.size(), true)
        || !memory.map_region(kPrefixStackBase, stack.data(), stack.size(), true)
        || !memory.store32(0x30000000u, 0xffffffffu)
        || !memory.store32(kPrefixStackBase, 0x8badf00du)
        || !memory.store32(
            kPrefixEntryEsp, BatchLiftMemory::kReturnSentinel)
        || !memory.store32(kObjectBase + 0x20u, 0xabcdef01u)
        || !memory.store32(
            kObjectBase + kObjectBytes,
            kObjectCanary)) {
        std::fprintf(stderr, "could not map documented guest input state\n");
        return false;
    }
    pe_data_backing.reserve(kSporePrefixDataRanges.size());
    for (const SporeVerifiedDataRange& range : kSporePrefixDataRanges) {
        if (range.bytes == nullptr || range.length == 0u) {
            std::fprintf(
                stderr,
                "invalid verified PE data range at %08x\n",
                range.address);
            return false;
        }
        pe_data_backing.emplace_back(
            range.bytes,
            range.bytes + static_cast<std::ptrdiff_t>(range.length));
        if (!memory.map_region(
                range.address,
                pe_data_backing.back().data(),
                pe_data_backing.back().size(),
                false)) {
            std::fprintf(
                stderr,
                "could not map verified guest PE data at %08x "
                "length=%u\n",
                range.address,
                range.length);
            return false;
        }
    }
#if defined(M7_THROUGH_SECOND_CALL)
    auto lookup_table = kM7TableBytes;
    if (!memory.map_region(
            0x0143d850u, lookup_table.data(), lookup_table.size(), false)) {
        std::fprintf(stderr, "could not map PE-backed M7 lookup table\n");
        return false;
    }
#endif
#if defined(M7_THROUGH_THIRD_CALL)
    auto scale_bytes = kM7ScaleBytes;
    auto correction_bytes = kM7CorrectionBytes;
    if (!memory.map_region(
            0x01470f14u, scale_bytes.data(), scale_bytes.size(), false)
        || !memory.map_region(
            0x013f4fd0u, correction_bytes.data(),
            correction_bytes.size(), false)) {
        std::fprintf(stderr, "could not map PE-backed M7 float data\n");
        return false;
    }
#endif
#if defined(M7_THROUGH_MEMSET)
    auto post_float_bytes = kM7PostFloatBytes;
    if (!memory.map_region(0x013f0620u, post_float_bytes.data(),
                           post_float_bytes.size(), false)) {
        std::fprintf(stderr, "could not map PE-backed post-memset float\n");
        return false;
    }
#endif
    BatchGuestRuntime runtime;
    BatchLiftState state{};
    state.regs[0] = 0x87654321u;
    state.regs[1] = kObjectBase;
    state.regs[2] = 0x12345678u;
    state.regs[3] = 0x11223344u;
    state.regs[4] = kPrefixEntryEsp;
    state.regs[5] = 0x55667788u;
    state.regs[6] = 0x99aabbccu;
    state.regs[7] = 0xddeeff00u;
    state.eflags = 0x202u;
    state.eip = kSporePrefixEntry;
    state.fs_base = 0x30000000u;
    state.imports = &runtime;
    BatchLiftStatus status = spore_lift_00a33600(memory, state);
    std::uint32_t canary{};
    if (!memory.load32(
            kObjectBase + kObjectBytes, canary)
        || canary != kObjectCanary) {
        std::fprintf(stderr,
                     "guest prefix overwrote the object canary: value=%08x status=%u eip=%08x eax=%08x ebx=%08x ecx=%08x esi=%08x edi=%08x esp=%08x\n",
                     canary, static_cast<unsigned>(status), state.eip,
                     state.regs[0], state.regs[3], state.regs[1],
                     state.regs[6], state.regs[7], state.regs[4]);
        return false;
    }
    if (!memory.load32(kPrefixStackBase, canary) || canary != 0x8badf00du) {
        std::fprintf(stderr, "guest prefix overwrote the stack canary\n");
        return false;
    }
    if (!read_guest_snapshot(memory, state, status, snapshot)
        || !normalize_guest_handles(snapshot, runtime)) {
        return false;
    }
    for (const BatchGuestImportCall& call : runtime.calls()) {
        std::printf(
            "LIFT_IMPORT symbol=%s return=%08x result=%08x last_error=%u\n",
            call.symbol.c_str(),
            call.return_address,
            call.result,
            call.last_error);
    }
    return true;
}

void print_snapshot(const char* label, const Snapshot& snapshot) {
    std::printf(
        "case=%s eax=%08x ecx=%08x edx=%08x ebx=%08x "
        "esp_delta=%08x ebp=%08x esi=%08x edi=%08x "
        "eflags=%08x fs_head_delta=%08x seh_prev=%08x "
        "seh_handler=%08x seh_cookie=%08x stack_object=%08x "
        "saved=%08x,%08x,%08x,%08x object=",
        label,
        snapshot.regs[0],
        snapshot.regs[1],
        snapshot.regs[2],
        snapshot.regs[3],
        snapshot.esp_delta,
        snapshot.regs[5],
        snapshot.regs[6],
        snapshot.regs[7],
        snapshot.eflags,
        snapshot.fs_head_delta,
        snapshot.seh_previous,
        snapshot.seh_handler,
        snapshot.seh_cookie,
        snapshot.stack_object,
        snapshot.saved_registers[0],
        snapshot.saved_registers[1],
        snapshot.saved_registers[2],
        snapshot.saved_registers[3]);
    for (std::size_t index = 0;
         index < kObjectBytes / sizeof(std::uint32_t); ++index) {
        std::printf("%s%08x", index == 0 ? "" : ",", snapshot.object_words[index]);
    }
    std::printf("\n");
    std::fflush(stdout);
}

#if defined(_M_IX86)
bool snapshots_equal(const Snapshot& left, const Snapshot& right) {
#if defined(M7_THROUGH_FOURTH_FIRST_CALL)
    auto left_storage = std::make_unique<Snapshot>(left);
    auto right_storage = std::make_unique<Snapshot>(right);
    Snapshot& normalized_left = *left_storage;
    Snapshot& normalized_right = *right_storage;
#else
    Snapshot normalized_left = left;
    Snapshot normalized_right = right;
#endif
#if !defined(M7_COMPOSITE_ENTRY)
    normalized_left.regs[1] = 0u;
    normalized_right.regs[1] = 0u;
#endif
    normalized_left.regs[2] = 0u;
    normalized_right.regs[2] = 0u;
    return std::memcmp(
        &normalized_left, &normalized_right, sizeof(Snapshot)) == 0;
}

std::uint32_t normalize_object_pointer(
    std::uint32_t address,
    std::uint32_t native_base) {
#if defined(M7_THROUGH_FIFTH_CHILD_ENTRY)
    // LEA at 0x00a30e37 prepares the list base without dereferencing it.
    if (address >= native_base && address - native_base == 0x83340u) {
        return kObjectBase + 0x83340u;
    }
#endif
#if defined(M7_THROUGH_FOURTH_CHILD_RETURN)
    // LEA at 0x00a33874 computes the next subobject address without reading it.
    if (address >= native_base && address - native_base == 0x80424u) {
        return kObjectBase + 0x80424u;
    }
#endif
    if (address < native_base
        || address - native_base >
#if defined(M7_COMPOSITE_ENTRY)
#if defined(M7_THROUGH_FIFTH_FIRST_CALL)
            0x116000u
#elif defined(M7_THROUGH_FOURTH_FIRST_CALL)
            0x7d000u
#elif defined(M7_THROUGH_FOURTH_CHILD_ENTRY)
            0x8000u
#elif defined(M7_THROUGH_THIRD_CHILD_RETURN)
            0x4000u
#elif defined(M7_THROUGH_SECOND_CHILD_RETURN)
            0x3000u
#elif defined(M7_THROUGH_FIRST_CALL)
            0x2000u
#else
            0x1000u
#endif
#else
            kObjectBytes
#endif
        ) {
        return address;
    }
    return kObjectBase + (address - native_base);
}

std::uint32_t normalize_native_stack_pointer(std::uint32_t address) {
    const std::int64_t delta =
        static_cast<std::int64_t>(address)
        - static_cast<std::int64_t>(g_prefix_entry_esp);
    if (delta < -static_cast<std::int64_t>(kPrefixStackTopOffset)
        || delta > static_cast<std::int64_t>(
            kPrefixStackBytes - kPrefixStackTopOffset)) {
        return address;
    }
    return static_cast<std::uint32_t>(
        static_cast<std::int64_t>(kPrefixEntryEsp) + delta);
}

std::uint32_t normalize_native_object_value(
    std::uint32_t value,
    std::uint32_t native_base) {
    value = normalize_object_pointer(value, native_base);
    for (std::size_t index = 0; index < g_native_handle_count; ++index) {
        if (value == g_native_handles[index]) {
            return 0xc0000001u + static_cast<std::uint32_t>(index);
        }
    }
    return value;
}

bool run_original_prefix(Snapshot& snapshot) {
    NativePeDataImage pe_data;
    if (!pe_data.initialize()) {
        std::fprintf(stderr, "could not map verified PE data into x86 address space\n");
        return false;
    }
    NativeClosureImage closure_image;
    if (!closure_image.initialize()) {
        std::fprintf(stderr, "could not build original x86 closure image\n");
        return false;
    }
    constexpr std::array<std::uint8_t, 5> kResmanStringPush{
        0x68u, 0x34u, 0x93u, 0x44u, 0x01u};
    std::uint8_t* resman_entry = closure_image.entry(0x00a247f0u);
    if (resman_entry == nullptr
        || !relocate_absolute_data_operand(
            resman_entry,
            0x00a247f0u,
            0x00a24809u,
            kResmanStringPush.data(),
            kResmanStringPush.size(),
            1u,
            0x01449334u,
            pe_data)
        || !relocate_direct_call(
            resman_entry + (0x00a24812u - 0x00a247f0u),
            closure_image.entry(0x011e5d80u))
        || !relocate_direct_call(
            resman_entry + (0x00a24837u - 0x00a247f0u),
            closure_image.entry(0x009222a0u))) {
        std::fprintf(
            stderr,
            "could not relocate verified resman closure references\n");
        return false;
    }
    if (!closure_image.make_executable()) {
        std::fprintf(stderr, "could not protect original closure code\n");
        return false;
    }
    void* code_allocation = VirtualAlloc(
        nullptr,
        kAllocationBytes,
        MEM_RESERVE | MEM_COMMIT,
        PAGE_EXECUTE_READWRITE);
    void* object = VirtualAlloc(
        nullptr,
#if defined(M7_THROUGH_FIFTH_FIRST_CALL)
        0x116000u,
#elif defined(M7_THROUGH_FOURTH_FIRST_CALL)
        0x7d000u,
#elif defined(M7_THROUGH_FOURTH_CHILD_ENTRY)
        0x8000u,
#elif defined(M7_THROUGH_THIRD_CHILD_RETURN)
        0x4000u,
#elif defined(M7_THROUGH_SECOND_CHILD_RETURN)
        0x3000u,
#elif defined(M7_THROUGH_FIRST_CALL)
        0x2000u,
#else
        0x1000u,
#endif
        MEM_RESERVE | MEM_COMMIT,
        PAGE_READWRITE);
    if (code_allocation == nullptr
        || object == nullptr) {
        std::fprintf(
            stderr,
            "could not map original x86 code/object: code=%p object=%p error=%lu\n",
            code_allocation,
            object,
            GetLastError());
        if (code_allocation != nullptr) VirtualFree(code_allocation, 0, MEM_RELEASE);
        if (object != nullptr) VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }

    auto* root_code = static_cast<std::uint8_t*>(code_allocation) + 0x1000u;
    auto* child_code = static_cast<std::uint8_t*>(code_allocation) + 0x2000u;
    std::memcpy(root_code, kSporePrefixBytes.data(), kSporePrefixBytes.size());
    std::memcpy(child_code, kSporeChildBytes.data(), kSporeChildBytes.size());
#if defined(M7_COMPOSITE_ENTRY)
    auto* m7_code = static_cast<std::uint8_t*>(code_allocation) + 0x4000u;
    std::memcpy(m7_code, kM7EntryBytes.data(), kM7EntryBytes.size());
    m7_code[kM7EntryBytes.size()] = 0xccu;
#if defined(M7_THROUGH_FIRST_CALL)
    auto* m7_target_code = static_cast<std::uint8_t*>(code_allocation) + 0x5000u;
    std::memcpy(m7_target_code, kM7TargetBytes.data(), kM7TargetBytes.size());
#endif
#if defined(M7_THROUGH_SECOND_CALL)
    auto* m7_next_code = static_cast<std::uint8_t*>(code_allocation) + 0x6000u;
    auto* m7_lookup_code = static_cast<std::uint8_t*>(code_allocation) + 0x7000u;
    std::memcpy(m7_next_code, kM7NextBytes.data(), kM7NextBytes.size());
    std::memcpy(m7_lookup_code, kM7LookupBytes.data(), kM7LookupBytes.size());
    auto m7_table = kM7TableBytes;
#endif
#if defined(M7_THROUGH_THIRD_CALL)
    auto* m7_cfg_code = static_cast<std::uint8_t*>(code_allocation) + 0x8000u;
    auto* m7_search2_code = static_cast<std::uint8_t*>(code_allocation) + 0x9000u;
    auto* m7_float_code = static_cast<std::uint8_t*>(code_allocation) + 0xa000u;
    auto* m7_allocator_code = static_cast<std::uint8_t*>(code_allocation) + 0xb000u;
    std::memcpy(m7_cfg_code, kM7CfgBytes.data(), kM7CfgBytes.size());
    std::memcpy(m7_search2_code, kM7Search2Bytes.data(), kM7Search2Bytes.size());
    std::memcpy(m7_float_code, kM7FloatBytes.data(), kM7FloatBytes.size());
    std::memcpy(m7_allocator_code,
                kM7AllocatorBytes.data(), kM7AllocatorBytes.size());
#if defined(M7_THROUGH_FLOAT_CALL)
    auto* m7_float_call_code =
        static_cast<std::uint8_t*>(code_allocation) + 0xc000u;
    std::memcpy(m7_float_call_code, kM7FloatCallBytes.data(),
                kM7FloatCallBytes.size());
#endif
#if defined(M7_THROUGH_SECOND_CHILD_RETURN)
    auto* m7_second_code =
        static_cast<std::uint8_t*>(code_allocation) + 0xd000u;
    std::memcpy(m7_second_code, kM7SecondEntryBytes.data(),
                kM7SecondEntryBytes.size());
    constexpr std::uint32_t kSecondGuardedCallOffset =
        0x00a2f2f3u - 0x00a2f210u;
    if (m7_second_code[kSecondGuardedCallOffset] != 0xe8u) {
        std::fprintf(stderr, "unexpected guarded second child CALL bytes\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    m7_second_code[kSecondGuardedCallOffset] = 0xccu;
#endif
#if defined(M7_THROUGH_FOURTH_CHILD_ENTRY)
    auto* m7_fourth_code =
        static_cast<std::uint8_t*>(code_allocation) + 0xe000u;
    std::memcpy(m7_fourth_code, kM7FourthEntryBytes.data(),
                kM7FourthEntryBytes.size());
    m7_fourth_code[kM7FourthEntryBytes.size()] = 0xccu;
#if defined(M7_THROUGH_FOURTH_CHILD_RETURN)
    constexpr std::uint32_t kFourthGuardedCallOffset =
        0x00a2a3f3u - 0x00a2a310u;
    if (m7_fourth_code[kFourthGuardedCallOffset] != 0xe8u) {
        std::fprintf(stderr, "unexpected guarded fourth child CALL bytes\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    m7_fourth_code[kFourthGuardedCallOffset] = 0xccu;
#endif
#endif
#if defined(M7_THROUGH_FOURTH_THIRD_ENTRY)
    auto* m7_fourth_helper_code =
        static_cast<std::uint8_t*>(code_allocation) + 0xf000u;
    std::memcpy(m7_fourth_helper_code, kM7FourthHelperBytes.data(),
                kM7FourthHelperBytes.size());
    m7_fourth_helper_code[kM7FourthHelperBytes.size()] = 0xccu;
#if defined(M7_THROUGH_FOURTH_THIRD_FIRST_CALL)
    constexpr std::uint32_t kFourthHelperFloatOffset =
        0x00a236b2u - 0x00a23620u;
    constexpr std::uint32_t kFourthHelperAllocatorOffset =
        0x00a236bdu - 0x00a23620u;
    if (m7_fourth_helper_code[kFourthHelperFloatOffset] != 0xe8u
        || m7_fourth_helper_code[kFourthHelperAllocatorOffset] != 0xe8u) {
        std::fprintf(stderr, "unexpected fourth helper guarded CALL bytes\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if !defined(M7_THROUGH_FOURTH_HELPER_FLOAT_CALL)
    m7_fourth_helper_code[kFourthHelperFloatOffset] = 0xccu;
#endif
#if !defined(M7_THROUGH_FOURTH_HELPER_ALLOCATOR_CALL)
    m7_fourth_helper_code[kFourthHelperAllocatorOffset] = 0xccu;
#endif
#endif
#endif
#if defined(M7_THROUGH_FIFTH_CHILD_ENTRY)
    auto* m7_fifth_code =
        static_cast<std::uint8_t*>(code_allocation) + 0x10000u;
    std::memcpy(m7_fifth_code, kM7FifthEntryBytes.data(),
                kM7FifthEntryBytes.size());
    m7_fifth_code[kM7FifthEntryBytes.size()] = 0xccu;
#if defined(M7_THROUGH_FIFTH_THIRD_ENTRY)
    auto* m7_fifth_helper_code =
        static_cast<std::uint8_t*>(code_allocation) + 0x11000u;
    std::memcpy(m7_fifth_helper_code, kM7FifthHelperBytes.data(),
                kM7FifthHelperBytes.size());
    m7_fifth_helper_code[kM7FifthHelperBytes.size()] = 0xccu;
#endif
#endif
#if defined(M7_THROUGH_CHILD_RETURN)
    constexpr std::uint32_t kGuardedCallOffset =
        0x00a2a2f3u - 0x00a2a210u;
    if (m7_code[kGuardedCallOffset] != 0xe8u) {
        std::fprintf(stderr, "unexpected guarded child CALL bytes\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    m7_code[kGuardedCallOffset] = 0xccu;
#endif
    m7_allocator_code[0x00a221e9u - 0x00a221b0u] = 0xccu;
#if !defined(M7_THROUGH_MEMSET)
    m7_allocator_code[0x00a221fcu - 0x00a221b0u] = 0xccu;
#endif
    auto m7_scale = kM7ScaleBytes;
    auto m7_correction = kM7CorrectionBytes;
#if defined(M7_THROUGH_MEMSET)
    auto m7_post_float = kM7PostFloatBytes;
#endif
#endif
#if defined(M7_THROUGH_CHILD_RETURN)
    std::memcpy(root_code + (kSporePrefixStop - kSporePrefixEntry),
                kM7RootTailBytes.data(), kM7RootTailBytes.size());
#if defined(M7_THROUGH_FIFTH_CHILD_ENTRY)
    root_code[0x00a3394fu - kSporePrefixEntry] = 0xccu;
#elif !defined(M7_THROUGH_FOURTH_CHILD_ENTRY) || defined(M7_THROUGH_FOURTH_CHILD_RETURN)
    root_code[kCompositeStop - kSporePrefixEntry] = 0xccu;
#endif
#else
    std::memcpy(root_code + (kSporePrefixStop - kSporePrefixEntry),
                kM7RootCallBytes.data(), kM7RootCallBytes.size());
#endif
#endif
    constexpr std::array<std::uint8_t, 8> kGlobalFloatA{
        0xf3u, 0x0fu, 0x10u, 0x05u, 0x18u, 0x57u, 0x48u, 0x01u};
    constexpr std::array<std::uint8_t, 8> kGlobalFloatB{
        0xf3u, 0x0fu, 0x10u, 0x05u, 0x50u, 0x2fu, 0x45u, 0x01u};
    constexpr std::array<std::uint8_t, 8> kGlobalFloatC{
        0xf3u, 0x0fu, 0x10u, 0x05u, 0x08u, 0x61u, 0x48u, 0x01u};
    if (!relocate_absolute_data_operand(
            root_code,
            kSporePrefixEntry,
            0x00a336beu,
            kGlobalFloatA.data(),
            kGlobalFloatA.size(),
            4u,
            0x01485718u,
            pe_data)
        || !relocate_absolute_data_operand(
            root_code,
            kSporePrefixEntry,
            0x00a336cfu,
            kGlobalFloatB.data(),
            kGlobalFloatB.size(),
            4u,
            0x01452f50u,
            pe_data)
        || !relocate_absolute_data_operand(
            root_code,
            kSporePrefixEntry,
            0x00a337d3u,
            kGlobalFloatC.data(),
            kGlobalFloatC.size(),
            4u,
            0x01486108u,
            pe_data)) {
        std::fprintf(stderr, "could not relocate verified PE global loads\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    if (!relocate_direct_call(
            root_code + kSporeIncludedCallOffset, child_code)
        || !relocate_direct_call(
            root_code + (0x00a3366au - kSporePrefixEntry),
            closure_image.entry(0x00921f00u))
        || !relocate_direct_call(
            root_code + (0x00a336f5u - kSporePrefixEntry),
            closure_image.entry(0x009222a0u))
        || !relocate_direct_call(
            root_code + (0x00a33726u - kSporePrefixEntry),
            reinterpret_cast<const std::uint8_t*>(
                &prefix_call_constructor_entry))
        || !relocate_direct_call(
            root_code + (0x00a33736u - kSporePrefixEntry),
            closure_image.entry(0x00a247f0u))) {
        std::fprintf(stderr, "a verified prefix CALL could not be relocated\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    constexpr std::array<std::uint32_t, 6> kSimpleChildCallSites = {
        0x00a3377eu, 0x00a3378eu, 0x00a3379eu,
        0x00a337aeu, 0x00a337beu, 0x00a337ceu,
    };
    for (const std::uint32_t call_site : kSimpleChildCallSites) {
        if (!relocate_direct_call(
                root_code + (call_site - kSporePrefixEntry),
                closure_image.entry(0x00a0fdf0u))) {
            std::fprintf(
                stderr,
                "could not relocate verified subobject call at %08x\n",
                call_site);
            VirtualFree(code_allocation, 0, MEM_RELEASE);
            VirtualFree(object, 0, MEM_RELEASE);
            return false;
        }
    }
    const std::uint32_t root_runtime_address =
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(root_code));
#if defined(M7_COMPOSITE_ENTRY)
    if (!relocate_direct_call(
            root_code + (kSporePrefixStop - kSporePrefixEntry), m7_code)) {
        std::fprintf(stderr, "could not relocate M7 constructor CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if defined(M7_THROUGH_SECOND_CHILD_RETURN)
    if (!relocate_direct_call(
            root_code + (0x00a33831u - kSporePrefixEntry),
            m7_second_code)) {
        std::fprintf(stderr, "could not relocate second constructor CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if defined(M7_THROUGH_THIRD_CHILD_RETURN)
    if (!relocate_direct_call(
            root_code + (0x00a3384bu - kSporePrefixEntry), m7_code)) {
        std::fprintf(stderr, "could not relocate third constructor CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if defined(M7_THROUGH_FOURTH_CHILD_ENTRY)
    if (!relocate_direct_call(
            root_code + (0x00a33865u - kSporePrefixEntry),
            m7_fourth_code)) {
        std::fprintf(stderr, "could not relocate fourth constructor CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if defined(M7_THROUGH_FIFTH_CHILD_ENTRY)
    if (!relocate_direct_call(
            root_code + (0x00a3387fu - kSporePrefixEntry),
            m7_fifth_code)) {
        std::fprintf(stderr, "could not relocate fifth constructor CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if defined(M7_THROUGH_FIFTH_FIRST_CALL)
    if (!relocate_direct_call(
            m7_fifth_code + (0x00a30e4eu - 0x00a30e10u),
            m7_target_code)) {
        std::fprintf(stderr, "could not relocate fifth child first CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if defined(M7_THROUGH_FIFTH_SECOND_CALL)
    if (!relocate_direct_call(
            m7_fifth_code + (0x00a30e75u - 0x00a30e10u),
            m7_next_code)) {
        std::fprintf(stderr, "could not relocate fifth child second CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if defined(M7_THROUGH_FIFTH_THIRD_ENTRY)
    if (!relocate_direct_call(
            m7_fifth_code + (0x00a30e9eu - 0x00a30e10u),
            m7_fifth_helper_code)) {
        std::fprintf(stderr, "could not relocate fifth child third CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#endif
#endif
#endif
#endif
#endif
#if defined(M7_THROUGH_FOURTH_FIRST_CALL)
    if (!relocate_direct_call(
            m7_fourth_code + (0x00a2a34eu - 0x00a2a310u),
            m7_target_code)) {
        std::fprintf(stderr, "could not relocate fourth child first CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if defined(M7_THROUGH_FOURTH_SECOND_CALL)
    if (!relocate_direct_call(
            m7_fourth_code + (0x00a2a375u - 0x00a2a310u),
            m7_next_code)) {
        std::fprintf(stderr, "could not relocate fourth child second CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#if defined(M7_THROUGH_FOURTH_THIRD_ENTRY)
    if (!relocate_direct_call(
            m7_fourth_code + (0x00a2a39eu - 0x00a2a310u),
            m7_fourth_helper_code)
#if defined(M7_THROUGH_FOURTH_THIRD_FIRST_CALL)
        || !relocate_direct_call(
            m7_fourth_helper_code + (0x00a23665u - 0x00a23620u),
            m7_target_code)
#if defined(M7_THROUGH_FOURTH_HELPER_FLOAT_CALL)
        || !relocate_direct_call(
            m7_fourth_helper_code + (0x00a236b2u - 0x00a23620u),
            m7_float_code)
#if defined(M7_THROUGH_FOURTH_HELPER_ALLOCATOR_CALL)
        || !relocate_direct_call(
            m7_fourth_helper_code + (0x00a236bdu - 0x00a23620u),
            m7_allocator_code)
#endif
#endif
#endif
        ) {
        std::fprintf(stderr, "could not relocate fourth child third CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#endif
#endif
#endif
#endif
#endif
#if defined(M7_THROUGH_FIRST_CALL)
    if (!relocate_direct_call(
            m7_code + (0x00a2a24eu - 0x00a2a210u), m7_target_code)) {
        std::fprintf(stderr, "could not relocate first M7 child CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#endif
#if defined(M7_THROUGH_SECOND_CALL)
    constexpr std::array<std::uint8_t, 5> kM7TableEndPush{
        0x68u, 0x50u, 0xdcu, 0x43u, 0x01u};
    constexpr std::array<std::uint8_t, 5> kM7TableStartPush{
        0x68u, 0x50u, 0xd8u, 0x43u, 0x01u};
    if (std::memcmp(m7_next_code + 5u, kM7TableEndPush.data(), 5u) != 0
        || std::memcmp(m7_next_code + 10u, kM7TableStartPush.data(), 5u) != 0
        || !relocate_direct_call(
            m7_code + (0x00a2a275u - 0x00a2a210u), m7_next_code)
        || !relocate_direct_call(m7_next_code + 15u, m7_lookup_code)) {
        std::fprintf(stderr, "could not relocate verified M7 lookup calls/data\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    const std::uint32_t m7_table_start = native_address32(m7_table.data());
    const std::uint32_t m7_table_end = native_address32(m7_table.data() + 0x400u);
    std::memcpy(m7_next_code + 6u, &m7_table_end, sizeof(m7_table_end));
    std::memcpy(m7_next_code + 11u, &m7_table_start, sizeof(m7_table_start));
#endif
#if defined(M7_THROUGH_THIRD_CALL)
    constexpr std::array<std::uint8_t, 8> kM7InitialLoad{
        0xf3u, 0x0fu, 0x10u, 0x05u, 0x18u, 0x57u, 0x48u, 0x01u};
    constexpr std::array<std::uint8_t, 8> kM7ScaleLoad{
        0xf3u, 0x0fu, 0x10u, 0x05u, 0x14u, 0x0fu, 0x47u, 0x01u};
    constexpr std::array<std::uint8_t, 5> kM7FloatTableEndPush{
        0x68u, 0x50u, 0xdcu, 0x43u, 0x01u};
    constexpr std::array<std::uint8_t, 5> kM7FloatTableStartPush{
        0x68u, 0x50u, 0xd8u, 0x43u, 0x01u};
    constexpr std::array<std::uint8_t, 6> kM7CorrectionAdd{
        0xd8u, 0x05u, 0xd0u, 0x4fu, 0x3fu, 0x01u};
#if defined(M7_THROUGH_MEMSET)
    constexpr std::array<std::uint8_t, 8> kM7PostFloatLoad{
        0xf3u, 0x0fu, 0x10u, 0x05u, 0x20u, 0x06u, 0x3fu, 0x01u};
    constexpr std::array<std::uint8_t, 8> kM7PostScaleLoad{
        0xf3u, 0x0fu, 0x10u, 0x05u, 0x14u, 0x0fu, 0x47u, 0x01u};
    const std::uint32_t post_float_address = native_address32(m7_post_float.data());
#endif
    const std::uint32_t scale_address = native_address32(m7_scale.data());
    const std::uint32_t correction_address = native_address32(m7_correction.data());
    if (!relocate_direct_call(
            m7_code + (0x00a2a29eu - 0x00a2a210u), m7_cfg_code)
        || !relocate_direct_call(
            m7_cfg_code + (0x00a235b5u - 0x00a23570u), m7_target_code)
        || !relocate_direct_call(
            m7_cfg_code + (0x00a23602u - 0x00a23570u), m7_float_code)
        || !relocate_direct_call(
            m7_cfg_code + (0x00a2360du - 0x00a23570u), m7_allocator_code)
        || !relocate_direct_call(
            m7_float_code + (0x00921375u - 0x00921360u), m7_search2_code)
#if defined(M7_THROUGH_MEMSET)
        || !relocate_direct_call(
            m7_allocator_code + (0x00a221fcu - 0x00a221b0u),
            reinterpret_cast<const std::uint8_t*>(&prefix_memset))
#endif
        || !relocate_absolute_data_operand(
            m7_cfg_code, 0x00a23570u, 0x00a23570u,
            kM7InitialLoad.data(), kM7InitialLoad.size(), 4u,
            0x01485718u, pe_data)
        || std::memcmp(m7_cfg_code + (0x00a23594u - 0x00a23570u),
                       kM7ScaleLoad.data(), kM7ScaleLoad.size()) != 0
        || std::memcmp(m7_float_code + (0x00921369u - 0x00921360u),
                       kM7FloatTableEndPush.data(), kM7FloatTableEndPush.size()) != 0
        || std::memcmp(m7_float_code + (0x0092136eu - 0x00921360u),
                       kM7FloatTableStartPush.data(), kM7FloatTableStartPush.size()) != 0
        || std::memcmp(m7_float_code + (0x0092138du - 0x00921360u),
                       kM7CorrectionAdd.data(), kM7CorrectionAdd.size()) != 0) {
        std::fprintf(stderr, "could not relocate verified M7 configuration path\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    std::memcpy(m7_cfg_code + (0x00a23594u - 0x00a23570u) + 4u,
                &scale_address, sizeof(scale_address));
    std::memcpy(m7_float_code + (0x00921369u - 0x00921360u) + 1u,
                &m7_table_end, sizeof(m7_table_end));
    std::memcpy(m7_float_code + (0x0092136eu - 0x00921360u) + 1u,
                &m7_table_start, sizeof(m7_table_start));
    std::memcpy(m7_float_code + (0x0092138du - 0x00921360u) + 2u,
                &correction_address, sizeof(correction_address));
#if defined(M7_THROUGH_FOURTH_THIRD_ENTRY)
    if (!relocate_absolute_data_operand(
            m7_fourth_helper_code, 0x00a23620u, 0x00a23620u,
            kM7InitialLoad.data(), kM7InitialLoad.size(), 4u,
            0x01485718u, pe_data)
        || std::memcmp(
            m7_fourth_helper_code + (0x00a23644u - 0x00a23620u),
            kM7ScaleLoad.data(), kM7ScaleLoad.size()) != 0) {
        std::fprintf(stderr, "could not relocate verified fourth helper data\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    std::memcpy(
        m7_fourth_helper_code + (0x00a23644u - 0x00a23620u) + 4u,
        &scale_address, sizeof(scale_address));
#if defined(M7_THROUGH_FOURTH_HELPER_ALLOCATOR_CALL)
    if (std::memcmp(
            m7_fourth_code + (0x00a2a3a3u - 0x00a2a310u),
            kM7PostFloatLoad.data(), kM7PostFloatLoad.size()) != 0
        || std::memcmp(
            m7_fourth_code + (0x00a2a3b1u - 0x00a2a310u),
            kM7PostScaleLoad.data(), kM7PostScaleLoad.size()) != 0) {
        std::fprintf(stderr, "unexpected fourth child post-call MOVSS bytes\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    std::memcpy(
        m7_fourth_code + (0x00a2a3a3u - 0x00a2a310u) + 4u,
        &post_float_address, sizeof(post_float_address));
    std::memcpy(
        m7_fourth_code + (0x00a2a3b1u - 0x00a2a310u) + 4u,
        &scale_address, sizeof(scale_address));
#if defined(M7_THROUGH_FOURTH_CHILD_RETURN)
    if (!relocate_direct_call(
            m7_fourth_code + (0x00a2a3e6u - 0x00a2a310u),
            m7_float_call_code)) {
        std::fprintf(stderr, "could not relocate fourth child float CALL\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
#endif
#endif
#if defined(M7_THROUGH_FIFTH_THIRD_ENTRY)
    if (!relocate_absolute_data_operand(
            m7_fifth_helper_code, 0x00a236d0u, 0x00a236d0u,
            kM7InitialLoad.data(), kM7InitialLoad.size(), 4u,
            0x01485718u, pe_data)
        || std::memcmp(
            m7_fifth_helper_code + (0x00a236f4u - 0x00a236d0u),
            kM7ScaleLoad.data(), kM7ScaleLoad.size()) != 0) {
        std::fprintf(stderr, "could not relocate fifth helper PE data\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    std::memcpy(
        m7_fifth_helper_code + (0x00a236f4u - 0x00a236d0u) + 4u,
        &scale_address, sizeof(scale_address));
#endif
#endif
#if defined(M7_THROUGH_MEMSET)
    if (std::memcmp(m7_code + (0x00a2a2a3u - 0x00a2a210u),
                    kM7PostFloatLoad.data(), kM7PostFloatLoad.size()) != 0
        || std::memcmp(m7_code + (0x00a2a2b1u - 0x00a2a210u),
                       kM7PostScaleLoad.data(), kM7PostScaleLoad.size()) != 0) {
        std::fprintf(stderr, "unexpected post-memset MOVSS bytes\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    std::memcpy(m7_code + (0x00a2a2a3u - 0x00a2a210u) + 4u,
                &post_float_address, sizeof(post_float_address));
    std::memcpy(m7_code + (0x00a2a2b1u - 0x00a2a210u) + 4u,
                &scale_address, sizeof(scale_address));
#if defined(M7_THROUGH_SECOND_CHILD_RETURN)
    if (!relocate_direct_call(
            m7_second_code + (0x00a2f24eu - 0x00a2f210u), m7_target_code)
        || !relocate_direct_call(
            m7_second_code + (0x00a2f275u - 0x00a2f210u), m7_next_code)
        || !relocate_direct_call(
            m7_second_code + (0x00a2f29eu - 0x00a2f210u), m7_cfg_code)
        || !relocate_direct_call(
            m7_second_code + (0x00a2f2e6u - 0x00a2f210u),
            m7_float_call_code)
        || std::memcmp(
            m7_second_code + (0x00a2f2a3u - 0x00a2f210u),
            kM7PostFloatLoad.data(), kM7PostFloatLoad.size()) != 0
        || std::memcmp(
            m7_second_code + (0x00a2f2b1u - 0x00a2f210u),
            kM7PostScaleLoad.data(), kM7PostScaleLoad.size()) != 0) {
        std::fprintf(stderr, "could not relocate verified second child\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    std::memcpy(
        m7_second_code + (0x00a2f2a3u - 0x00a2f210u) + 4u,
        &post_float_address, sizeof(post_float_address));
    std::memcpy(
        m7_second_code + (0x00a2f2b1u - 0x00a2f210u) + 4u,
        &scale_address, sizeof(scale_address));
#endif
#endif
#if defined(M7_THROUGH_FLOAT_CALL)
    constexpr std::array<std::uint8_t, 6> kM7FloatCorrectionAdd{
        0xd8u, 0x05u, 0xd0u, 0x4fu, 0x3fu, 0x01u};
    constexpr std::array<std::uint8_t, 5> kM7C0TableEndPush{
        0x68u, 0x50u, 0xdcu, 0x43u, 0x01u};
    constexpr std::array<std::uint8_t, 5> kM7C0TableStartPush{
        0x68u, 0x50u, 0xd8u, 0x43u, 0x01u};
    if (!relocate_direct_call(
            m7_code + (0x00a2a2e6u - 0x00a2a210u), m7_float_call_code)
        || !relocate_direct_call(
            m7_float_call_code + (0x009213f7u - 0x009213c0u),
            m7_search2_code)
        || std::memcmp(
            m7_float_call_code + (0x009213d2u - 0x009213c0u),
            kM7FloatCorrectionAdd.data(),
            kM7FloatCorrectionAdd.size()) != 0
        || std::memcmp(
            m7_float_call_code + (0x0092140fu - 0x009213c0u),
            kM7FloatCorrectionAdd.data(),
            kM7FloatCorrectionAdd.size()) != 0
        || std::memcmp(
            m7_float_call_code + (0x009213e9u - 0x009213c0u),
            kM7C0TableEndPush.data(),
            kM7C0TableEndPush.size()) != 0
        || std::memcmp(
            m7_float_call_code + (0x009213eeu - 0x009213c0u),
            kM7C0TableStartPush.data(),
            kM7C0TableStartPush.size()) != 0) {
        std::fprintf(stderr, "could not relocate verified float-call bytes\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    std::memcpy(
        m7_float_call_code + (0x009213d2u - 0x009213c0u) + 2u,
        &correction_address, sizeof(correction_address));
    std::memcpy(
        m7_float_call_code + (0x0092140fu - 0x009213c0u) + 2u,
        &correction_address, sizeof(correction_address));
    std::memcpy(
        m7_float_call_code + (0x009213e9u - 0x009213c0u) + 1u,
        &m7_table_end, sizeof(m7_table_end));
    std::memcpy(
        m7_float_call_code + (0x009213eeu - 0x009213c0u) + 1u,
        &m7_table_start, sizeof(m7_table_start));
#endif
#endif
#if defined(M7_THROUGH_THIRD_CALL)
#if defined(M7_THROUGH_FIFTH_THIRD_ENTRY)
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_fifth_helper_code + kM7FifthHelperBytes.size());
#elif defined(M7_THROUGH_FIFTH_CHILD_ENTRY)
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_fifth_code + kM7FifthEntryBytes.size());
#elif defined(M7_THROUGH_FOURTH_CHILD_RETURN)
    const std::uint32_t boundary_runtime_address = native_address32(
        root_code + (kCompositeStop - kSporePrefixEntry));
#elif defined(M7_THROUGH_FOURTH_HELPER_ALLOCATOR_CALL)
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_fourth_code + kM7FourthEntryBytes.size());
#elif defined(M7_THROUGH_FOURTH_HELPER_FLOAT_CALL)
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_fourth_helper_code + (0x00a236bdu - 0x00a23620u));
#elif defined(M7_THROUGH_FOURTH_THIRD_FIRST_CALL)
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_fourth_helper_code + (0x00a236b2u - 0x00a23620u));
#elif defined(M7_THROUGH_FOURTH_THIRD_ENTRY)
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_fourth_helper_code + kM7FourthHelperBytes.size());
#elif defined(M7_THROUGH_FOURTH_CHILD_ENTRY)
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_fourth_code + kM7FourthEntryBytes.size());
#elif defined(M7_THROUGH_CHILD_RETURN)
    const std::uint32_t boundary_runtime_address = native_address32(
        root_code + (kCompositeStop - kSporePrefixEntry));
#elif defined(M7_THROUGH_MEMSET)
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_code + kM7EntryBytes.size());
#else
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_allocator_code + (kCompositeStop - 0x00a221b0u));
#endif
#else
    const std::uint32_t boundary_runtime_address = native_address32(
        m7_code + kM7EntryBytes.size());
#endif
#else
    const std::uint32_t boundary_runtime_address =
        root_runtime_address + (kSporePrefixStop - kSporePrefixEntry);
    root_code[kSporePrefixStop - kSporePrefixEntry] = 0xccu;
#endif
#if defined(M7_THROUGH_FIFTH_FIRST_CALL)
    std::memset(object, 0, 0x116000u);
#elif defined(M7_THROUGH_FOURTH_FIRST_CALL)
    std::memset(object, 0, 0x7d000u);
#elif defined(M7_THROUGH_FOURTH_CHILD_ENTRY)
    std::memset(object, 0, 0x8000u);
#elif defined(M7_THROUGH_THIRD_CHILD_RETURN)
    std::memset(object, 0, 0x4000u);
#elif defined(M7_THROUGH_SECOND_CHILD_RETURN)
    std::memset(object, 0, 0x3000u);
#elif defined(M7_THROUGH_FIRST_CALL)
    std::memset(object, 0, 0x2000u);
#else
    std::memset(object, 0, 0x1000u);
#endif
    static_cast<std::uint32_t*>(object)[8] = 0xabcdef01u;
    std::memcpy(
        static_cast<std::uint8_t*>(object) + kObjectBytes,
        &kObjectCanary,
        sizeof(kObjectCanary));
    g_native_handles.fill(0u);
    g_native_handle_count = 0u;
    g_native_critical_sections.fill(0u);
    g_native_critical_section_count = 0u;
    if (!FlushInstructionCache(
            GetCurrentProcess(), code_allocation, kAllocationBytes)) {
        std::fprintf(stderr, "could not flush the relocated x86 prefix\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }

    g_prefix_code_entry = root_runtime_address;
    g_prefix_native_object = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(object));
    g_prefix_boundary_address = boundary_runtime_address;
    g_prefix_saved_fs_head = __readfsdword(0);
    g_prefix_boundary_seen = 0;
    g_prefix_exception_code = 0;
    g_prefix_exception_eip = 0;
    g_prefix_exception_address = 0;
    g_prefix_constructor_entry = native_address32(
        closure_image.entry(0x011e64f0u));
    g_prefix_data_image = &pe_data;
    PVOID handler = AddVectoredExceptionHandler(1, capture_prefix_boundary);
    if (handler == nullptr) {
        std::fprintf(stderr, "AddVectoredExceptionHandler failed\n");
        g_prefix_constructor_entry = 0u;
        g_prefix_data_image = nullptr;
        cleanup_native_synchronization(object);
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }

    invoke_original_prefix();
    g_prefix_constructor_entry = 0u;
    g_prefix_data_image = nullptr;
    RemoveVectoredExceptionHandler(handler);
    const bool captured = g_prefix_boundary_seen == 1;
    if (!captured || __readfsdword(0) != g_prefix_saved_fs_head) {
        std::fprintf(
            stderr,
            "original x86 prefix exception code=%08x address=%08x "
            "eip=%08x expected_eip=%08x; host_seh_restored=%u\n",
            g_prefix_exception_code,
            g_prefix_exception_address,
            g_prefix_exception_eip,
            g_prefix_boundary_address,
            __readfsdword(0) == g_prefix_saved_fs_head ? 1u : 0u);
        cleanup_native_synchronization(object);
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    std::uint32_t object_canary{};
    std::memcpy(
        &object_canary,
        static_cast<const std::uint8_t*>(object) + kObjectBytes,
        sizeof(object_canary));
    if (object_canary != kObjectCanary) {
        std::fprintf(stderr, "original x86 prefix overwrote the object canary\n");
        cleanup_native_synchronization(object);
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }

    const CONTEXT& context = g_prefix_boundary_context;
    const std::uint32_t native_object_base = g_prefix_native_object;
    snapshot.regs[0] = normalize_native_stack_pointer(
        normalize_object_pointer(context.Eax, native_object_base));
    snapshot.regs[1] = normalize_native_stack_pointer(
        normalize_object_pointer(context.Ecx, native_object_base));
    snapshot.regs[2] = context.Edx;
    snapshot.regs[3] = normalize_object_pointer(context.Ebx, native_object_base);
    snapshot.regs[4] = 0u;
    snapshot.regs[5] = normalize_object_pointer(context.Ebp, native_object_base);
    snapshot.regs[6] = normalize_object_pointer(context.Esi, native_object_base);
    snapshot.regs[7] = normalize_object_pointer(context.Edi, native_object_base);
    snapshot.esp_delta = context.Esp - g_prefix_entry_esp;
    snapshot.eflags = context.EFlags & kFlagMask;
    snapshot.fs_head_delta =
        g_prefix_boundary_fs_head - g_prefix_entry_esp;
    for (unsigned index = 0; index < 4; ++index) {
        snapshot.saved_registers[index] = normalize_native_stack_pointer(
            normalize_object_pointer(
                g_prefix_boundary_words[index], native_object_base));
    }
    snapshot.stack_object = g_prefix_boundary_words[4];
    snapshot.stack_object = normalize_object_pointer(
        snapshot.stack_object, native_object_base);
    snapshot.seh_previous = g_prefix_boundary_words[5];
    snapshot.seh_handler = g_prefix_boundary_words[6];
    snapshot.seh_cookie = g_prefix_boundary_words[7];
    const auto* object_words = static_cast<const std::uint32_t*>(object);
    for (std::size_t index = 0;
         index < kObjectBytes / sizeof(std::uint32_t); ++index) {
        std::uint32_t value = normalize_native_object_value(
            object_words[index], native_object_base);
        const std::uint32_t object_offset =
            static_cast<std::uint32_t>(index * sizeof(std::uint32_t));
        for (std::size_t section_index = 0;
             section_index < g_native_critical_section_count;
             ++section_index) {
            const std::uint32_t section = g_native_critical_sections[section_index];
            if (section < native_object_base
                || section - native_object_base >= kObjectBytes) {
                continue;
            }
            const std::uint32_t section_offset = section - native_object_base;
            if (object_offset == section_offset
                || object_offset == section_offset + 5u * sizeof(std::uint32_t)) {
                value = 0u;
            }
        }
        snapshot.object_words[index] = value;
    }
    cleanup_native_synchronization(object);
    VirtualFree(code_allocation, 0, MEM_RELEASE);
    VirtualFree(object, 0, MEM_RELEASE);
    return true;
}
#endif

}

int main() {
    if (!run_indexed_store_regression()) return 1;
#if defined(M7_THROUGH_FOURTH_FIRST_CALL)
    auto lifted_storage = std::make_unique<Snapshot>();
    Snapshot& lifted = *lifted_storage;
#else
    Snapshot lifted{};
#endif
    if (!run_lifted_prefix(lifted)) return 1;
    print_snapshot(
#if defined(_M_IX86)
        "lifted_x86",
#else
        "lifted_arm64",
#endif
        lifted);

#if defined(_M_IX86)
#if defined(M7_THROUGH_FOURTH_FIRST_CALL)
    auto original_storage = std::make_unique<Snapshot>();
    Snapshot& original = *original_storage;
#else
    Snapshot original{};
#endif
    if (!run_original_prefix(original)) return 1;
    print_snapshot("original_x86", original);
    if (!snapshots_equal(original, lifted)) {
        std::fprintf(stderr, "original and lifted normalized states differ\n");
        std::fprintf(stderr, "FAIL original x86 versus generated prefix\n");
        return 2;
    }
    std::printf(
        "PASS original_x86_vs_lifted_x86 stop=0x%08x child=0x%08x\n",
#if defined(M7_COMPOSITE_ENTRY)
        kCompositeStop,
        0x00a2a210u);
#else
        kSporePrefixStop,
        kSporeChildEntry);
#endif
#else
    std::printf(
        "PASS lifted_arm64 stop=0x%08x child=0x%08x\n",
#if defined(M7_COMPOSITE_ENTRY)
        kCompositeStop,
        0x00a2a210u);
#else
        kSporePrefixStop,
        kSporeChildEntry);
#endif
#endif
    return 0;
}
