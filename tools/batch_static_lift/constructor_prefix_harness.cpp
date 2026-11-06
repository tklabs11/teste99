#include "BatchStaticLiftRuntime.hpp"
#include "prefix_reference_bytes.hpp"
#include "closure_reference_bytes.hpp"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
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
volatile LONG g_prefix_boundary_seen = 0;
volatile std::uint32_t g_prefix_exception_code = 0;
volatile std::uint32_t g_prefix_exception_eip = 0;
volatile std::uint32_t g_prefix_exception_address = 0;
volatile std::uint32_t g_prefix_boundary_words[8]{};
CONTEXT g_prefix_boundary_context{};
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

namespace {

constexpr std::uint32_t kObjectBase = 0x20000000u;
constexpr std::uint32_t kObjectBytes = 0x400u;
constexpr std::uint32_t kPrefixStackBase = 0x71000000u;
constexpr std::uint32_t kPrefixStackBytes = 0x4000u;
constexpr std::uint32_t kPrefixStackTopOffset = 0x3000u;
constexpr std::uint32_t kPrefixEntryEsp =
    kPrefixStackBase + kPrefixStackTopOffset - sizeof(std::uint32_t);
constexpr std::uint32_t kObjectCanary = 0x8badf00du;
#if defined(_M_IX86)
constexpr std::uint32_t kAllocationBytes = 0x10000u;
#endif
constexpr std::uint32_t kFlagMask = 0x000008c5u;

#if defined(_M_IX86)
constexpr std::uint32_t kClosureCodeBase = 0x00921e00u;
constexpr std::size_t kClosureCodeBytes = 0x1000u;
constexpr std::uint32_t kClosureIatBase = 0x013cc000u;
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
    return std::strncpy(destination, source, count);
#pragma warning(pop)
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
    const std::uint32_t address = native_address32(section);
    const auto end = g_native_critical_sections.begin()
        + static_cast<std::ptrdiff_t>(g_native_critical_section_count);
    if (std::find(g_native_critical_sections.begin(), end, address) == end
        && g_native_critical_section_count < g_native_critical_sections.size()) {
        g_native_critical_sections[g_native_critical_section_count++] = address;
    }
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
    const std::array<SporeVerifiedInstruction, N>& instructions) {
    for (const SporeVerifiedInstruction& instruction : instructions) {
        if (instruction.address < kClosureCodeBase) return false;
        const std::size_t offset =
            static_cast<std::size_t>(instruction.address - kClosureCodeBase);
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
        if (iat != nullptr) VirtualFree(iat, 0u, MEM_RELEASE);
    }

    bool initialize() {
        code = static_cast<std::uint8_t*>(VirtualAlloc(
            nullptr, kClosureCodeBytes, MEM_RESERVE | MEM_COMMIT,
            PAGE_READWRITE));
        iat = static_cast<std::uint8_t*>(VirtualAlloc(
            nullptr, 0x1000u, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
        if (code == nullptr || iat == nullptr) return false;
        std::memset(code, 0xccu, kClosureCodeBytes);
        if (!copy_verified_instructions(
                code, kClosureCodeBytes, kSporeInstructions_00921e00)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kSporeInstructions_00921e60)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kSporeInstructions_00921f00)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kSporeInstructions_00922150)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kSporeInstructions_009222a0)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kSporeInstructions_009225d0)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kSporeInstructions_00922620)
            || !copy_verified_instructions(
                code, kClosureCodeBytes, kSporeInstructions_00922820)
            || !install_import(
                0x00921e18u, 0x013cc4f4u,
                reinterpret_cast<std::uintptr_t>(&prefix_strncpy))
            || !install_import(
                0x0092216cu, 0x013cc2d0u,
                reinterpret_cast<std::uintptr_t>(
                    &prefix_initialize_critical_section))
            || !install_import(
                0x00922189u, 0x013cc180u,
                reinterpret_cast<std::uintptr_t>(&prefix_create_mutex))
            || !install_import(
                0x009225efu, 0x013cc4f4u,
                reinterpret_cast<std::uintptr_t>(&prefix_strncpy))
            || !install_import(
                0x0092266du, 0x013cc198u,
                reinterpret_cast<std::uintptr_t>(&prefix_create_semaphore))) {
            return false;
        }
        DWORD previous_protection{};
        if (!VirtualProtect(
                code, kClosureCodeBytes, PAGE_EXECUTE_READ,
                &previous_protection)) {
            return false;
        }
        FlushInstructionCache(
            GetCurrentProcess(), code, kClosureCodeBytes);
        return true;
    }

    std::uint8_t* entry(std::uint32_t address) const {
        if (address < kClosureCodeBase
            || address - kClosureCodeBase >= kClosureCodeBytes) {
            return nullptr;
        }
        return code + (address - kClosureCodeBase);
    }

private:
    bool install_import(
        std::uint32_t site,
        std::uint32_t original_iat,
        std::uintptr_t target) {
        const std::size_t iat_offset = original_iat - kClosureIatBase;
        const std::size_t code_offset = site - kClosureCodeBase;
        if (iat_offset > 0x1000u - sizeof(std::uint32_t)
            || code_offset > kClosureCodeBytes - 6u) {
            return false;
        }
        const std::uint32_t target_address =
            static_cast<std::uint32_t>(target);
        std::memcpy(iat + iat_offset, &target_address, sizeof(target_address));
        const std::uint32_t relocated_iat =
            native_address32(iat + iat_offset);
        std::memcpy(
            code + code_offset + 2u,
            &relocated_iat,
            sizeof(relocated_iat));
        return true;
    }

    std::uint8_t* code{};
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

bool read_guest_snapshot(
    BatchLiftMemory& memory,
    const BatchLiftState& state,
    BatchLiftStatus status,
    Snapshot& snapshot) {
    if (status != BatchLiftStatus::unsupported_dependency
        || state.eip != kSporePrefixStop) {
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
    std::array<std::uint8_t, kObjectBytes> object{};
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
            kObjectBase + kObjectBytes - sizeof(std::uint32_t),
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
    const BatchLiftStatus status =
        spore_lift_00a33600(memory, state);
    std::uint32_t canary{};
    if (!memory.load32(
            kObjectBase + kObjectBytes - sizeof(std::uint32_t), canary)
        || canary != kObjectCanary) {
        std::fprintf(stderr, "guest prefix overwrote the object canary\n");
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
    Snapshot normalized_left = left;
    Snapshot normalized_right = right;
    normalized_left.regs[1] = 0u;
    normalized_left.regs[2] = 0u;
    normalized_right.regs[1] = 0u;
    normalized_right.regs[2] = 0u;
    return std::memcmp(
        &normalized_left, &normalized_right, sizeof(Snapshot)) == 0;
}

std::uint32_t normalize_object_pointer(
    std::uint32_t address,
    std::uint32_t native_base) {
    if (address < native_base
        || address - native_base >= kObjectBytes) {
        return address;
    }
    return kObjectBase + (address - native_base);
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
    void* code_allocation = VirtualAlloc(
        nullptr,
        kAllocationBytes,
        MEM_RESERVE | MEM_COMMIT,
        PAGE_EXECUTE_READWRITE);
    void* object = VirtualAlloc(
        nullptr,
        0x1000u,
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
    constexpr std::array<std::uint8_t, 8> kGlobalFloatA{
        0xf3u, 0x0fu, 0x10u, 0x05u, 0x18u, 0x57u, 0x48u, 0x01u};
    constexpr std::array<std::uint8_t, 8> kGlobalFloatB{
        0xf3u, 0x0fu, 0x10u, 0x05u, 0x50u, 0x2fu, 0x45u, 0x01u};
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
            closure_image.entry(0x009222a0u))) {
        std::fprintf(stderr, "a verified prefix CALL could not be relocated\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    const std::uint32_t root_runtime_address =
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(root_code));
    const std::uint32_t boundary_runtime_address =
        root_runtime_address + (kSporePrefixStop - kSporePrefixEntry);
    root_code[kSporePrefixStop - kSporePrefixEntry] = 0xccu;
    std::memset(object, 0, 0x1000u);
    static_cast<std::uint32_t*>(object)[8] = 0xabcdef01u;
    static_cast<std::uint32_t*>(object)[
        kObjectBytes / sizeof(std::uint32_t) - 1u] = kObjectCanary;
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
    PVOID handler = AddVectoredExceptionHandler(1, capture_prefix_boundary);
    if (handler == nullptr) {
        std::fprintf(stderr, "AddVectoredExceptionHandler failed\n");
        cleanup_native_synchronization(object);
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }

    invoke_original_prefix();
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

    const CONTEXT& context = g_prefix_boundary_context;
    const std::uint32_t native_object_base = g_prefix_native_object;
    snapshot.regs[0] = normalize_object_pointer(context.Eax, native_object_base);
    snapshot.regs[1] = normalize_object_pointer(context.Ecx, native_object_base);
    snapshot.regs[2] = context.Edx;
    snapshot.regs[3] = context.Ebx;
    snapshot.regs[4] = 0u;
    snapshot.regs[5] = context.Ebp;
    snapshot.regs[6] = normalize_object_pointer(context.Esi, native_object_base);
    snapshot.regs[7] = context.Edi;
    snapshot.esp_delta = context.Esp - g_prefix_entry_esp;
    snapshot.eflags = context.EFlags & kFlagMask;
    snapshot.fs_head_delta =
        g_prefix_boundary_fs_head - g_prefix_entry_esp;
    for (unsigned index = 0; index < 4; ++index) {
        snapshot.saved_registers[index] = g_prefix_boundary_words[index];
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
    Snapshot lifted{};
    if (!run_lifted_prefix(lifted)) return 1;
    print_snapshot(
#if defined(_M_IX86)
        "lifted_x86",
#else
        "lifted_arm64",
#endif
        lifted);

#if defined(_M_IX86)
    Snapshot original{};
    if (!run_original_prefix(original)) return 1;
    print_snapshot("original_x86", original);
    if (!snapshots_equal(original, lifted)) {
        std::fprintf(stderr, "original and lifted normalized states differ\n");
        std::fprintf(stderr, "FAIL original x86 versus generated prefix\n");
        return 2;
    }
    std::printf(
        "PASS original_x86_vs_lifted_x86 stop=0x%08x child=0x%08x\n",
        kSporePrefixStop,
        kSporeChildEntry);
#else
    std::printf(
        "PASS lifted_arm64 stop=0x%08x child=0x%08x\n",
        kSporePrefixStop,
        kSporeChildEntry);
#endif
    return 0;
}
