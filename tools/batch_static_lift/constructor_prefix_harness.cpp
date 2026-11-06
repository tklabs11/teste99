#include "BatchStaticLiftRuntime.hpp"
#include "prefix_reference_bytes.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>

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
#if defined(_M_IX86)
constexpr std::uint32_t kObjectBytes = 0x40u;
constexpr std::uint32_t kAllocationBytes = 0x10000u;
#endif
constexpr std::uint32_t kFlagMask = 0x000008c5u;

#if defined(_M_IX86)
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
    for (unsigned index = 0; index < 4; ++index) {
        g_prefix_boundary_words[index] = stack[index];
    }
    g_prefix_boundary_words[4] = stack[16];
    g_prefix_boundary_words[5] = stack[17];
    g_prefix_boundary_words[6] = stack[18];
    g_prefix_boundary_words[7] = stack[19];
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
    std::uint32_t object_words[9]{};
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
    snapshot.esp_delta = state.regs[4] - BatchLiftMemory::kEntryEsp;
    snapshot.eflags = state.eflags & kFlagMask;
    std::uint32_t fs_head{};
    if (!memory.load32(0x30000000u, fs_head)
        || !memory.load32(BatchLiftMemory::kEntryEsp - 12u, snapshot.seh_previous)
        || !memory.load32(BatchLiftMemory::kEntryEsp - 8u, snapshot.seh_handler)
        || !memory.load32(BatchLiftMemory::kEntryEsp - 4u, snapshot.seh_cookie)
        || !memory.load32(BatchLiftMemory::kEntryEsp - 16u, snapshot.stack_object)) {
        return false;
    }
    snapshot.fs_head_delta = fs_head - BatchLiftMemory::kEntryEsp;
    for (unsigned index = 0; index < 4; ++index) {
        if (!memory.load32(
                state.regs[4] + index * 4u,
                snapshot.saved_registers[index])) {
            return false;
        }
    }
    for (unsigned index = 0; index < 9; ++index) {
        if (!memory.load32(
                kObjectBase + index * 4u,
                snapshot.object_words[index])) {
            return false;
        }
    }
    return true;
}

bool run_lifted_prefix(Snapshot& snapshot) {
    BatchLiftMemory memory;
    std::array<std::uint8_t, 0x40> object{};
    std::array<std::uint8_t, 4> fs{};
    if (!memory.map_region(kObjectBase, object.data(), object.size(), true)
        || !memory.map_region(0x30000000u, fs.data(), fs.size(), true)
        || !memory.store32(0x30000000u, 0xffffffffu)
        || !memory.store32(kObjectBase + 0x20u, 0xabcdef01u)) {
        std::fprintf(stderr, "could not map documented guest input state\n");
        return false;
    }
    BatchLiftState state{};
    state.regs[0] = 0x87654321u;
    state.regs[1] = kObjectBase;
    state.regs[2] = 0x12345678u;
    state.regs[3] = 0x11223344u;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.regs[5] = 0x55667788u;
    state.regs[6] = 0x99aabbccu;
    state.regs[7] = 0xddeeff00u;
    state.eflags = 0x202u;
    state.eip = kSporePrefixEntry;
    state.fs_base = 0x30000000u;
    const BatchLiftStatus status =
        spore_lift_00a33600(memory, state);
    return read_guest_snapshot(memory, state, status, snapshot);
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
    for (std::size_t index = 0; index < 9; ++index) {
        std::printf("%s%08x", index == 0 ? "" : ",", snapshot.object_words[index]);
    }
    std::printf("\n");
    std::fflush(stdout);
}

#if defined(_M_IX86)
bool snapshots_equal(const Snapshot& left, const Snapshot& right) {
    return std::memcmp(&left, &right, sizeof(Snapshot)) == 0;
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

bool run_original_prefix(Snapshot& snapshot) {
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
    const std::int64_t call_return = static_cast<std::int64_t>(
        reinterpret_cast<std::uintptr_t>(root_code)
        + kSporeIncludedCallOffset + 5u);
    const std::int64_t call_delta =
        static_cast<std::int64_t>(reinterpret_cast<std::uintptr_t>(child_code))
        - call_return;
    if (call_delta < INT32_MIN || call_delta > INT32_MAX) {
        std::fprintf(stderr, "included CALL relocation is outside rel32 range\n");
        VirtualFree(code_allocation, 0, MEM_RELEASE);
        VirtualFree(object, 0, MEM_RELEASE);
        return false;
    }
    const std::int32_t relocated_call = static_cast<std::int32_t>(call_delta);
    std::memcpy(
        root_code + kSporeIncludedCallOffset + 1u,
        &relocated_call,
        sizeof(relocated_call));
    const std::uint32_t root_runtime_address =
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(root_code));
    const std::uint32_t boundary_runtime_address =
        root_runtime_address + (kSporePrefixStop - kSporePrefixEntry);
    root_code[kSporePrefixStop - kSporePrefixEntry] = 0xccu;
    std::memset(object, 0, 0x1000u);
    static_cast<std::uint32_t*>(object)[8] = 0xabcdef01u;

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
    for (std::size_t index = 0; index < 9; ++index) {
        snapshot.object_words[index] = object_words[index];
    }
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
