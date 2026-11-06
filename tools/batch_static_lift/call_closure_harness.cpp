#include "BatchStaticLiftRuntime.hpp"
#if defined(_M_IX86)
#include "recursive_reference_bytes.hpp"
#include "cross_call_reference_bytes.hpp"
#endif
#include "startup_resman_reference_bytes.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>

#if defined(_M_IX86)
#include <Windows.h>
#include <memory>
#include <xmmintrin.h>

static_assert(sizeof(void*) == sizeof(std::uint32_t), "x86 process required");
#endif

BatchLiftStatus spore_lift_006237a0(
    BatchLiftMemory& memory,
    BatchLiftState& state);
BatchLiftStatus spore_lift_00bb9b70(
    BatchLiftMemory& memory,
    BatchLiftState& state);
BatchLiftStatus spore_lift_011e5d80(
    BatchLiftMemory& memory,
    BatchLiftState& state);
BatchLiftStatus spore_lift_00a247f0(
    BatchLiftMemory& memory,
    BatchLiftState& state);
BatchLiftStatus spore_lift_00922150(
    BatchLiftMemory& memory,
    BatchLiftState& state);

namespace {

constexpr std::uint32_t kObjectBase = 0x3000u;
constexpr std::uint32_t kObjectStride = 0x40u;
constexpr std::uint32_t kCrossObjectBase = 0x4000u;
constexpr std::uint32_t kStackSentinel = 0xfedcba98u;
constexpr std::uint32_t kStackCanary = 0x8badf00du;
constexpr std::uint32_t kInitialEsi = 0xcafebabeu;
constexpr std::uint32_t kInitialFlags = 0xa5a50002u;
constexpr std::uint32_t kRegisterSeed = 0x10101010u;
constexpr std::uint32_t kStatusFlags = 0x8d5u;
constexpr std::uint32_t kResmanObjectBase = 0x30000u;
constexpr std::uint32_t kResmanFsBase = 0x7ffe0000u;
constexpr std::uint32_t kResmanIatCreateMutexA = 0x013cc180u;
constexpr std::uint32_t kResmanIatInitializeCriticalSection = 0x013cc2d0u;
constexpr std::uint32_t kResmanIatDeleteCriticalSection = 0x013cc2d4u;
constexpr std::uint32_t kResmanIatEnterCriticalSection = 0x013cc2d8u;
constexpr std::uint32_t kResmanIatLeaveCriticalSection = 0x013cc2dcu;

struct NativeNode {
    std::uint8_t prefix[0x30]{};
    std::uint32_t child{};
    std::uint32_t value{};
};

static_assert(offsetof(NativeNode, child) == 0x30u, "child offset mismatch");
static_assert(offsetof(NativeNode, value) == 0x34u, "value offset mismatch");

bool guest_map(
    BatchLiftMemory& memory,
    std::uint32_t base,
    std::array<std::uint8_t, 0x400>& bytes) {
    return memory.map_region(base, bytes.data(), bytes.size(), true);
}

bool initialize_guest_nodes(
    BatchLiftMemory& memory,
    const std::array<std::uint32_t, 4>& values,
    std::uint32_t depth) {
    for (std::uint32_t index = 0; index <= depth; ++index) {
        const std::uint32_t node = kObjectBase + index * kObjectStride;
        const std::uint32_t child = index < depth
            ? node + kObjectStride : 0u;
        if (!memory.store32(node + 0x30u, child)
            || !memory.store32(node + 0x34u, values[index])) {
            return false;
        }
    }
    return true;
}

struct GuestResult {
    bool passed{};
    std::uint32_t result{};
    std::uint32_t child_result{};
    std::uint32_t flags{};
    std::uint32_t final_esp{};
    std::uint32_t final_eip{};
};

GuestResult run_guest_recursive(
    const std::array<std::uint32_t, 4>& values,
    std::uint32_t depth) {
    BatchLiftMemory memory;
    std::array<std::uint8_t, 0x400> objects{};
    if (!guest_map(memory, kObjectBase, objects)) return {};

    BatchLiftState state{};
    for (std::uint32_t index = 0; index < 8u; ++index) {
        state.regs[index] = kRegisterSeed + index * 0x01010101u;
    }
    state.regs[1] = kObjectBase;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.regs[6] = kInitialEsi;
    state.eflags = kInitialFlags;
    state.eip = 0x006237a0u;
    if (!initialize_guest_nodes(memory, values, depth)
        || !memory.store32(state.regs[4], kStackSentinel)
        || !memory.store32(
            state.regs[4] - 8u - 8u * depth, kStackCanary)) {
        return {};
    }

    std::uint32_t sum = 0u;
    std::uint32_t child_sum = 0u;
    for (std::uint32_t index = 0; index <= depth; ++index) {
        sum += values[index];
        if (index != 0u) child_sum += values[index];
    }
    const BatchLiftStatus status = spore_lift_006237a0(memory, state);
    std::uint32_t canary{};
    bool passed = status == BatchLiftStatus::returned
        && state.regs[0] == sum
        && state.regs[1] == child_sum
        && state.regs[6] == kInitialEsi
        && state.regs[4] == BatchLiftMemory::kEntryEsp + 4u
        && state.eip == kStackSentinel
        && memory.load32(
            BatchLiftMemory::kEntryEsp - 8u - 8u * depth, canary)
        && canary == kStackCanary;

    for (std::uint32_t frame = 0; frame <= depth && passed; ++frame) {
        std::uint32_t saved_esi{};
        passed = memory.load32(
            BatchLiftMemory::kEntryEsp - 4u - 8u * frame, saved_esi)
            && saved_esi == (frame == 0u
                ? kInitialEsi
                : kObjectBase + (frame - 1u) * kObjectStride);
        if (frame < depth && passed) {
            std::uint32_t return_address{};
            passed = memory.load32(
                BatchLiftMemory::kEntryEsp - 8u - 8u * frame,
                return_address)
                && return_address == 0x006237afu;
        }
    }
    return {
        passed,
        state.regs[0],
        child_sum,
        state.eflags,
        state.regs[4],
        state.eip,
    };
}

GuestResult run_guest_cross_call(std::uint32_t value) {
    BatchLiftMemory memory;
    std::array<std::uint8_t, 0x400> object{};
    if (!guest_map(memory, kCrossObjectBase, object)
        || !memory.store32(kCrossObjectBase + 0x194u, value)) {
        return {};
    }
    BatchLiftState state{};
    for (std::uint32_t index = 0; index < 8u; ++index) {
        state.regs[index] = kRegisterSeed + index * 0x01010101u;
    }
    state.regs[1] = kCrossObjectBase;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.regs[6] = kInitialEsi;
    state.eflags = kInitialFlags;
    state.eip = 0x00bb9b70u;
    if (!memory.store32(state.regs[4], kStackSentinel)) return {};

    const BatchLiftStatus status = spore_lift_00bb9b70(memory, state);
    std::uint32_t loaded_value{};
    std::uint32_t return_address{};
    const std::uint32_t expected_result =
        (value & 0xffffff00u) | (value == 5u ? 1u : 0u);
    const bool passed = status == BatchLiftStatus::returned
        && state.regs[0] == expected_result
        && state.regs[1] == kCrossObjectBase
        && state.regs[6] == kInitialEsi
        && state.regs[4] == BatchLiftMemory::kEntryEsp + 4u
        && state.eip == kStackSentinel
        && memory.load32(kCrossObjectBase + 0x194u, loaded_value)
        && loaded_value == value
        && memory.load32(BatchLiftMemory::kEntryEsp - 4u, return_address)
        && return_address == 0x00bb9b75u;
    return {
        passed,
        state.regs[0],
        0u,
        state.eflags,
        state.regs[4],
        state.eip,
    };
}

struct StartupCopyResult {
    bool passed{};
    std::uint32_t result{};
    std::uint32_t destination{};
    std::uint32_t flags{};
    std::uint32_t final_esp{};
    std::uint32_t final_eip{};
};

StartupCopyResult run_guest_startup_string_copy(
    const char* source,
    std::uint32_t startup_stack_esp) {
    constexpr std::uint32_t kStringObjectBase = 0x5000u;
    constexpr std::uint32_t kStringSourceBase = 0x6000u;
    constexpr std::uint32_t kStringObjectVtable = 0x01452998u;
    constexpr std::uint32_t kStringCallReturn = 0x011e5d97u;
    constexpr std::uint32_t kStringReturnSentinel = 0xfedcbau;

    BatchLiftMemory memory;
    std::array<std::uint8_t, 0x40> object{};
    std::array<std::uint8_t, 0x40> source_bytes{};
    const std::size_t source_length = std::strlen(source);
    if (source_length >= source_bytes.size()) return {};
    std::memcpy(source_bytes.data(), source, source_length + 1u);
    if (!memory.map_region(kStringObjectBase, object.data(), object.size(), true)
        || !memory.map_region(
            kStringSourceBase, source_bytes.data(), source_bytes.size(), false)) {
        return {};
    }

    BatchLiftState state{};
    for (std::uint32_t index = 0; index < 8u; ++index) {
        state.regs[index] = kRegisterSeed + index * 0x01010101u;
    }
    state.regs[1] = kStringObjectBase;
    state.regs[4] = startup_stack_esp;
    state.regs[6] = kInitialEsi;
    state.eflags = kInitialFlags;
    state.eip = 0x011e5d80u;
    if (!memory.store32(startup_stack_esp, kStringReturnSentinel)
        || !memory.store32(state.regs[4] + 4u, kStringSourceBase)) {
        return {};
    }

    const BatchLiftStatus status = spore_lift_011e5d80(memory, state);
    std::uint32_t vtable{};
    std::uint32_t nested_return{};
    bool copied = memory.load32(kStringObjectBase, vtable)
        && vtable == kStringObjectVtable;
    for (std::size_t index = 0; index <= source_length && copied; ++index) {
        std::uint32_t byte{};
        copied = memory.load8(
            kStringObjectBase + 4u + static_cast<std::uint32_t>(index), byte)
            && byte == static_cast<std::uint8_t>(source_bytes[index]);
    }
    const bool passed = status == BatchLiftStatus::returned
        && state.regs[0] == kStringObjectBase
        && state.regs[1] == ((kStringObjectBase + 4u) & 0xffffff00u)
        && state.regs[6] == kInitialEsi
        && state.regs[4] == startup_stack_esp + 8u
        && state.eip == kStringReturnSentinel
        && memory.load32(
            startup_stack_esp - 16u, nested_return)
        && nested_return == kStringCallReturn
        && copied;
    return {
        passed,
        state.regs[0],
        state.regs[1],
        state.eflags,
        state.regs[4],
        state.eip,
    };
}

#if defined(_M_IX86)

struct VirtualMemoryDeleter {
    void operator()(void* memory) const noexcept {
        if (memory != nullptr) VirtualFree(memory, 0, MEM_RELEASE);
    }
};

class ExecutableCode {
public:
    ExecutableCode(std::uint32_t first_va, std::uint32_t last_va)
        : first_va_(first_va), size_(last_va - first_va) {
        memory_ = VirtualAlloc(
            nullptr, size_, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (memory_ == nullptr) return;
        std::memset(memory_, 0xcc, size_);
    }

    ~ExecutableCode() {
        if (memory_ != nullptr) VirtualFree(memory_, 0, MEM_RELEASE);
    }

    bool valid() const {
        return memory_ != nullptr;
    }

    template <typename Instructions>
    bool copy(const Instructions& instructions) {
        auto* base = static_cast<std::uint8_t*>(memory_);
        for (const SporeVerifiedInstruction& instruction : instructions) {
            if (instruction.length == 0u || instruction.length > instruction.bytes.size()
                || instruction.address < first_va_
                || static_cast<std::uint64_t>(instruction.address - first_va_)
                    + instruction.length > size_) {
                return false;
            }
            std::memcpy(
                base + (instruction.address - first_va_),
                instruction.bytes.data(),
                instruction.length);
        }
        return true;
    }

    bool make_executable() {
        DWORD old_protection{};
        return VirtualProtect(
                memory_, size_, PAGE_EXECUTE_READ, &old_protection)
            && FlushInstructionCache(GetCurrentProcess(), memory_, size_);
    }

    bool patch32(std::uint32_t address, std::uint32_t value) {
        if (memory_ == nullptr || address < first_va_
            || static_cast<std::uint64_t>(address - first_va_) + 4u > size_) {
            return false;
        }
        std::memcpy(
            static_cast<std::uint8_t*>(memory_) + (address - first_va_),
            &value, sizeof(value));
        return true;
    }

    const std::uint8_t* at(std::uint32_t address) const {
        return static_cast<const std::uint8_t*>(memory_)
            + (address - first_va_);
    }

private:
    std::uint32_t first_va_{};
    std::size_t size_{};
    void* memory_{};
};

class FixedAddressRegion {
public:
    FixedAddressRegion(std::uint32_t base, std::size_t size)
        : base_(base), size_(size) {
        void* requested = reinterpret_cast<void*>(
            static_cast<std::uintptr_t>(base));
        memory_ = VirtualAlloc(
            requested, size_, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (memory_ != requested && memory_ != nullptr) {
            VirtualFree(memory_, 0, MEM_RELEASE);
            memory_ = nullptr;
        }
    }

    explicit FixedAddressRegion(std::size_t size)
        : size_(size), memory_(VirtualAlloc(
            nullptr, size_, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE)) {
        if (memory_ != nullptr) {
            base_ = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(memory_));
        }
    }

    ~FixedAddressRegion() {
        if (memory_ != nullptr) VirtualFree(memory_, 0, MEM_RELEASE);
    }

    bool valid() const {
        return memory_ != nullptr;
    }

    void* at(std::uint32_t address) const {
        if (!valid() || address < base_
            || static_cast<std::uint64_t>(address - base_) >= size_) {
            return nullptr;
        }
        return static_cast<std::uint8_t*>(memory_) + (address - base_);
    }

    std::uint32_t address() const {
        return base_;
    }

private:
    std::uint32_t base_{};
    std::size_t size_{};
    void* memory_{};
};

struct NativeResmanResult {
    bool passed{};
    bool esp_balanced{};
    bool fs_restored{};
    bool recursive_lock_passed{};
    std::uint32_t result{};
    std::uint32_t ecx{};
    std::uint32_t esi{};
    std::uint32_t fs_before{};
    std::uint32_t fs_after{};
    std::int32_t lock_count_after_enter{};
    std::int32_t recursion_after_enter{};
    std::uint32_t owner_after_enter{};
    std::int32_t lock_count_after_leave{};
    std::int32_t recursion_after_leave{};
    std::uint32_t owner_after_leave{};
    std::uint32_t native_spin_count{};
    std::array<std::uint32_t, 4> nested_returns{};
    alignas(CRITICAL_SECTION) std::array<std::uint8_t, 0x80> object{};
};

NativeResmanResult run_native_resman_constructor() {
    constexpr std::uint32_t kStringOffset = 0x100u;
    constexpr std::uint32_t kIatInitializeOffset = 0x10u;
    constexpr std::uint32_t kIatDeleteOffset = 0x14u;
    constexpr std::uint32_t kIatEnterOffset = 0x18u;
    constexpr std::uint32_t kIatLeaveOffset = 0x1cu;
    constexpr std::uint32_t kIatCreateMutexOffset = 0x20u;
    using CriticalSectionApi = void (WINAPI*)(LPCRITICAL_SECTION);

    FixedAddressRegion iat_page(0x1000u);
    FixedAddressRegion string_page(0x10000u);
    if (!iat_page.valid() || !string_page.valid()) {
        std::cerr << "ERROR native PE data mapping failed "
                  << "iat=" << iat_page.valid()
                  << " string=" << string_page.valid()
                  << " gle=" << GetLastError() << "\n";
        return {};
    }

    const std::uint32_t native_string_address =
        string_page.address() + kStringOffset;
    std::memcpy(
        string_page.at(native_string_address),
        kSporeDataString_01449334_bytes.data(),
        kSporeDataString_01449334_bytes.size());

    HMODULE kernel = GetModuleHandleA("kernel32.dll");
    if (kernel == nullptr) {
        std::cerr << "ERROR kernel32 module lookup failed gle="
                  << GetLastError() << "\n";
        return {};
    }
    const char* api_names[] = {
        "InitializeCriticalSection",
        "DeleteCriticalSection",
        "EnterCriticalSection",
        "LeaveCriticalSection",
        "CreateMutexA",
    };
    const std::uint32_t iat_offsets[] = {
        kIatInitializeOffset, kIatDeleteOffset, kIatEnterOffset,
        kIatLeaveOffset, kIatCreateMutexOffset,
    };
    for (std::size_t index = 0; index < 5u; ++index) {
        FARPROC api = GetProcAddress(kernel, api_names[index]);
        if (api == nullptr) {
            std::cerr << "ERROR native import lookup failed api="
                      << api_names[index] << " gle=" << GetLastError() << "\n";
            return {};
        }
        const std::uint32_t address = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(api));
        std::memcpy(
            iat_page.at(iat_page.address() + iat_offsets[index]),
            &address, sizeof(address));
    }

    ExecutableCode code(0x00922150u, 0x011e8b41u);
    if (!code.valid()
        || !code.copy(kSporeInstructions_00922150)
        || !code.copy(kSporeInstructions_009222a0)
        || !code.copy(kSporeInstructions_00a247f0)
        || !code.copy(kSporeInstructions_011e5d80)
        || !code.copy(kSporeInstructions_011e8b20)
        || !code.patch32(
            0x0092216eu,
            iat_page.address() + kIatInitializeOffset)
        || !code.patch32(
            0x0092218bu,
            iat_page.address() + kIatCreateMutexOffset)
        || !code.patch32(0x00a2480au, native_string_address)
        || !code.make_executable()) {
        std::cerr << "ERROR native resman PE code mapping failed\n";
        return {};
    }

    NativeResmanResult result{};
    result.object.fill(0xa5u);
    LPCRITICAL_SECTION section = reinterpret_cast<LPCRITICAL_SECTION>(
        result.object.data() + 0x28u);
    const std::uint32_t function_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(code.at(0x00a247f0u)));
    const std::uint32_t object_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(result.object.data()));
    const std::uint32_t initial_esi = kInitialEsi;
    std::uint32_t saved_esi{};
    std::uint32_t native_result{};
    std::uint32_t native_ecx{};
    std::uint32_t native_esi{};
    std::uint32_t esp_before{};
    std::uint32_t esp_after{};
    std::uint32_t fs_before{};
    std::uint32_t fs_after{};
    std::array<std::uint32_t, 4> nested_returns{};

    __asm {
        mov saved_esi, esi
        mov esi, initial_esi
        mov ecx, object_address
        mov eax, function_address
        mov esp_before, esp
        mov eax, dword ptr fs:[0]
        mov fs_before, eax
        mov eax, function_address
        call eax
        mov native_result, eax
        mov native_ecx, ecx
        mov native_esi, esi
        mov eax, dword ptr fs:[0]
        mov fs_after, eax
        mov esp_after, esp
        mov edx, esp
        mov eax, dword ptr [edx - 32]
        mov nested_returns[0], eax
        mov eax, dword ptr [edx - 36]
        mov nested_returns[4], eax
        mov eax, dword ptr [edx - 68]
        mov nested_returns[8], eax
        mov eax, dword ptr [edx - 80]
        mov nested_returns[12], eax
        mov esi, saved_esi
    }

    const std::uint32_t critical_canary = kStackCanary;
    std::memcpy(result.object.data() + 0x64u, &critical_canary, sizeof(critical_canary));
    std::array<std::uint8_t, 0x80> initialized_object = result.object;
    std::memcpy(
        &result.native_spin_count,
        initialized_object.data() + 0x3cu,
        sizeof(result.native_spin_count));
    auto enter = reinterpret_cast<CriticalSectionApi>(
        GetProcAddress(kernel, "EnterCriticalSection"));
    auto leave = reinterpret_cast<CriticalSectionApi>(
        GetProcAddress(kernel, "LeaveCriticalSection"));
    auto remove = reinterpret_cast<CriticalSectionApi>(
        GetProcAddress(kernel, "DeleteCriticalSection"));
    if (enter == nullptr || leave == nullptr || remove == nullptr) {
        std::cerr << "ERROR native critical-section API lookup failed\n";
        return {};
    }

    enter(section);
    enter(section);
    const bool recursive_enter = section->RecursionCount == 2
        && section->OwningThread != 0u;
    result.lock_count_after_enter = section->LockCount;
    result.recursion_after_enter = section->RecursionCount;
    result.owner_after_enter = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(section->OwningThread));
    leave(section);
    const bool recursive_leave_one = section->RecursionCount == 1;
    leave(section);
    result.recursive_lock_passed = recursive_enter
        && recursive_leave_one
        && section->RecursionCount == 0
        && section->OwningThread == 0u;
    result.lock_count_after_leave = section->LockCount;
    result.recursion_after_leave = section->RecursionCount;
    result.owner_after_leave = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(section->OwningThread));
    remove(section);
    result.object = initialized_object;

    result.esp_balanced = esp_before == esp_after;
    result.fs_restored = fs_before == fs_after;
    result.result = native_result;
    result.ecx = native_ecx;
    result.esi = native_esi;
    result.fs_before = fs_before;
    result.fs_after = fs_after;
    result.nested_returns = nested_returns;
    result.passed = result.esp_balanced && result.fs_restored
        && result.recursive_lock_passed
        && native_result == object_address
        && native_ecx == fs_before
        && native_esi == initial_esi
        && nested_returns[0] == 0u
        && nested_returns[1] == reinterpret_cast<std::uintptr_t>(
            code.at(0x00a2483cu))
        && nested_returns[2] == reinterpret_cast<std::uintptr_t>(
            code.at(0x009222ecu))
        && nested_returns[3] == reinterpret_cast<std::uintptr_t>(
            code.at(0x00922172u));
    return result;
}

struct NativeRecursiveResult {
    bool passed{};
    std::uint32_t result{};
    std::uint32_t child_result{};
    std::uint32_t flags{};
    std::uint32_t recursive_calls{};
};

NativeRecursiveResult run_native_recursive(
    const std::uint8_t* function,
    const std::array<std::uint32_t, 4>& values,
    std::uint32_t depth) {
    std::array<NativeNode, 4> nodes{};
    for (std::uint32_t index = 0; index <= depth; ++index) {
        nodes[index].child = index < depth
            ? static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&nodes[index + 1u]))
            : 0u;
        nodes[index].value = values[index];
    }
    const auto snapshot = nodes;
    const std::uint32_t root = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(nodes.data()));
    const std::uint32_t function_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(function));
    std::uint32_t saved_esi{};
    std::uint32_t native_result{};
    std::uint32_t native_ecx{};
    std::uint32_t native_esi{};
    std::uint32_t native_flags{};
    std::uint32_t esp_before{};
    std::uint32_t esp_after{};
    std::array<std::uint32_t, 4> frame_esi{};
    std::array<std::uint32_t, 3> return_addresses{};
    const std::uint32_t initial_esi = kInitialEsi;

    __asm {
        mov saved_esi, esi
        mov esi, initial_esi
        mov ecx, root
        mov eax, function_address
        mov esp_before, esp
        push 0xa5a50002
        popfd
        call eax
        mov native_result, eax
        mov native_ecx, ecx
        mov native_esi, esi
        pushfd
        pop eax
        mov native_flags, eax
        mov esp_after, esp
        mov edx, esp
        mov eax, dword ptr [edx - 8]
        mov frame_esi[0], eax
        mov eax, dword ptr [edx - 16]
        mov frame_esi[4], eax
        mov eax, dword ptr [edx - 24]
        mov frame_esi[8], eax
        mov eax, dword ptr [edx - 32]
        mov frame_esi[12], eax
        mov eax, dword ptr [edx - 12]
        mov return_addresses[0], eax
        mov eax, dword ptr [edx - 20]
        mov return_addresses[4], eax
        mov eax, dword ptr [edx - 28]
        mov return_addresses[8], eax
        mov esi, saved_esi
    }

    std::uint32_t expected_sum = 0u;
    std::uint32_t expected_child_sum = 0u;
    for (std::uint32_t index = 0; index <= depth; ++index) {
        expected_sum += values[index];
        if (index != 0u) expected_child_sum += values[index];
    }
    bool passed = esp_before == esp_after
        && native_result == expected_sum
        && native_ecx == expected_child_sum
        && native_esi == initial_esi
        && std::memcmp(nodes.data(), snapshot.data(), sizeof(nodes)) == 0;
    for (std::uint32_t frame = 0; frame <= depth && passed; ++frame) {
        const std::uint32_t expected_esi = frame == 0u
            ? initial_esi
            : static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&nodes[frame - 1u]));
        passed = frame_esi[frame] == expected_esi;
        if (frame < depth && passed) {
            passed = return_addresses[frame]
                == static_cast<std::uint32_t>(
                    reinterpret_cast<std::uintptr_t>(function + 15u));
        }
    }
    return {passed, native_result, native_ecx, native_flags, depth};
}

struct NativeCrossResult {
    bool passed{};
    std::uint32_t result{};
    std::uint32_t flags{};
};

NativeCrossResult run_native_cross_call(
    const std::uint8_t* function,
    std::uint32_t value) {
    std::array<std::uint8_t, 0x198> object{};
    std::memcpy(object.data() + 0x194u, &value, sizeof(value));
    std::uint32_t function_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(function));
    std::uint32_t object_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(object.data()));
    std::uint32_t native_result{};
    std::uint32_t native_ecx{};
    std::uint32_t native_flags{};
    std::uint32_t esp_before{};
    std::uint32_t esp_after{};
    std::uint32_t native_call_return_address{};
    std::uint32_t saved_esi{};
    std::uint32_t native_esi{};
    const std::uint32_t initial_esi = kInitialEsi;

    __asm {
        mov saved_esi, esi
        mov esi, initial_esi
        mov ecx, object_address
        mov eax, function_address
        mov esp_before, esp
        push 0xa5a50002
        popfd
        call eax
        mov native_result, eax
        mov native_ecx, ecx
        mov native_esi, esi
        pushfd
        pop eax
        mov native_flags, eax
        mov esp_after, esp
        mov edx, esp
        mov eax, dword ptr [edx - 8]
        mov native_call_return_address, eax
        mov esi, saved_esi
    }
    const std::uint32_t expected_result =
        (value & 0xffffff00u) | (value == 5u ? 1u : 0u);
    return {
        esp_before == esp_after
            && native_call_return_address == function_address + 5u
            && native_result == expected_result
            && native_ecx == object_address
            && native_esi == initial_esi,
        native_result,
        native_flags,
    };
}

struct NativeStartupCopyResult {
    bool passed{};
    std::uint32_t result{};
    std::uint32_t ecx{};
    std::uint32_t esi{};
    std::uint32_t flags{};
    std::uint32_t nested_return{};
    std::uint32_t entry_esp{};
    bool esp_balanced{};
};

NativeStartupCopyResult run_native_startup_string_copy(
    const std::uint8_t* function,
    const char* source) {
    constexpr std::uint32_t kStringObjectVtable = 0x01452998u;
    std::array<std::uint8_t, 0x40> object{};
    const std::uint32_t function_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(function));
    const std::uint32_t object_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(object.data()));
    const std::uint32_t source_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(source));
    const std::uint32_t initial_esi = kInitialEsi;
    std::uint32_t saved_esi{};
    std::uint32_t native_result{};
    std::uint32_t native_ecx{};
    std::uint32_t native_esi{};
    std::uint32_t native_flags{};
    std::uint32_t esp_before{};
    std::uint32_t esp_after{};
    std::uint32_t nested_return{};

    __asm {
        mov saved_esi, esi
        mov esi, initial_esi
        mov ecx, object_address
        mov eax, function_address
        mov esp_before, esp
        push source_address
        push 0xa5a50002
        popfd
        call eax
        mov native_result, eax
        mov native_ecx, ecx
        mov native_esi, esi
        pushfd
        pop eax
        mov native_flags, eax
        mov esp_after, esp
        mov edx, esp
        mov eax, dword ptr [edx - 24]
        mov nested_return, eax
        mov esi, saved_esi
    }

    const std::size_t source_length = std::strlen(source);
    bool copied = object.size() >= 4u + source_length + 1u;
    std::uint32_t vtable{};
    if (copied) std::memcpy(&vtable, object.data(), sizeof(vtable));
    copied = copied && vtable == kStringObjectVtable
        && std::memcmp(object.data() + 4u, source, source_length + 1u) == 0;
    return {
        esp_before == esp_after
            && native_result == object_address
            && native_ecx == ((object_address + 4u) & 0xffffff00u)
            && native_esi == initial_esi
            && nested_return == function_address + 0x17u
            && copied,
        native_result,
        native_ecx,
        native_esi,
        native_flags,
        nested_return,
        static_cast<std::uint32_t>(esp_before - 8u),
        esp_before == esp_after,
    };
}

#endif

bool run_recursive_cases(bool print_results) {
    const std::array<std::array<std::uint32_t, 4>, 4> inputs = {{
        {{0u, 0u, 0u, 0u}},
        {{0xffffffffu, 1u, 0u, 0u}},
        {{0x7fffffffu, 1u, 0x80000000u, 0xffffffffu}},
        {{0xdeadbeefu, 0x12345678u, 0xa5a5a5a5u, 0x55555555u}},
    }};
#if defined(_M_IX86)
    ExecutableCode code(0x006237a0u, 0x006237c1u);
    if (!code.valid() || !code.copy(kSporeInstructions_006237a0)
        || !code.make_executable()) {
        std::cerr << "ERROR could not map verified recursive PE bytes\n";
        return false;
    }
#endif
    for (std::uint32_t depth = 0; depth < inputs.size(); ++depth) {
        const GuestResult guest = run_guest_recursive(inputs[depth], depth);
        if (!guest.passed) {
            std::cerr << "FAIL recursive guest depth=" << depth << "\n";
            return false;
        }
#if defined(_M_IX86)
        const NativeRecursiveResult native = run_native_recursive(
            code.at(kSporeEntry_006237a0), inputs[depth], depth);
        if (!native.passed
            || guest.result != native.result
            || guest.child_result != native.child_result
            || (guest.flags & kStatusFlags) != (native.flags & kStatusFlags)) {
            std::cerr << "FAIL recursive x86 differential depth=" << depth << "\n";
            return false;
        }
        if (print_results) {
            std::cout << "PASS x86 differential recursive depth=" << depth
                      << " return=0x" << std::hex << native.result
                      << " child_ecx=0x" << native.child_result
                      << " eflags=0x" << (native.flags & kStatusFlags)
                      << std::dec << " esp_balanced=yes"
                      << " guest_return_addresses=verified"
                      << " x86_return_addresses=verified\n";
        }
#else
        if (print_results) {
            std::cout << "PASS arm64 guest recursive depth=" << depth
                      << " return=0x" << std::hex << guest.result
                      << " child_ecx=0x" << guest.child_result
                      << " eflags=0x" << (guest.flags & kStatusFlags)
                      << std::dec << " esp_balanced=yes\n";
        }
#endif
    }
    return true;
}

bool run_distinct_function_calls(bool print_results) {
    const std::array<std::uint32_t, 4> inputs = {
        4u, 5u, 6u, 0xffffffffu,
    };
#if defined(_M_IX86)
    ExecutableCode code(0x00b8dab0u, 0x00bb9b7cu);
    if (!code.valid()
        || !code.copy(kSporeInstructions_00b8dab0)
        || !code.copy(kSporeInstructions_00bb9b70)
        || !code.make_executable()) {
        std::cerr << "ERROR could not map verified inter-function PE bytes\n";
        return false;
    }
#endif
    for (const std::uint32_t value : inputs) {
        const GuestResult guest = run_guest_cross_call(value);
        if (!guest.passed) {
            std::cerr << "FAIL distinct-call guest input=" << value << "\n";
            return false;
        }
#if defined(_M_IX86)
        const NativeCrossResult native = run_native_cross_call(
            code.at(kSporeEntry_00bb9b70), value);
        if (!native.passed
            || guest.result != native.result
            || (guest.flags & kStatusFlags) != (native.flags & kStatusFlags)) {
            std::cerr << "FAIL distinct-call x86 differential input="
                      << value << "\n";
            return false;
        }
        if (print_results) {
            std::cout << "PASS x86 differential distinct_call input=0x"
                      << std::hex << value << " return=0x" << native.result
                      << " eflags=0x" << (native.flags & kStatusFlags)
                      << std::dec << " esp_balanced=yes"
                      << " target=0x00b8dab0 return_address=0x00bb9b75\n";
        }
#else
        if (print_results) {
            std::cout << "PASS arm64 guest distinct_call input=0x"
                      << std::hex << value << " return=0x" << guest.result
                      << " eflags=0x" << (guest.flags & kStatusFlags)
                      << std::dec << " esp_balanced=yes"
                      << " target=0x00b8dab0 return_address=0x00bb9b75\n";
        }
#endif
    }
    return true;
}

bool run_startup_initialization_chain(bool print_results) {
    const std::array<const char*, 3> inputs = {
        "", "A", "Spore_Init_Config",
    };
#if defined(_M_IX86)
    ExecutableCode code(0x011e5d80u, 0x011e8b41u);
    if (!code.valid()
        || !code.copy(kSporeInstructions_011e5d80)
        || !code.copy(kSporeInstructions_011e8b20)
        || !code.make_executable()) {
        std::cerr << "ERROR could not map verified startup-chain PE bytes\n";
        return false;
    }
#endif
    for (const char* source : inputs) {
#if defined(_M_IX86)
        const NativeStartupCopyResult native =
            run_native_startup_string_copy(code.at(0x011e5d80u), source);
        const std::uint32_t guest_entry_esp =
            (BatchLiftMemory::kEntryEsp & 0xffffff00u)
            | (native.entry_esp & 0xffu);
#else
        const std::uint32_t guest_entry_esp = BatchLiftMemory::kEntryEsp;
#endif
        const StartupCopyResult guest =
            run_guest_startup_string_copy(source, guest_entry_esp);
        if (!guest.passed) {
            std::cerr << "FAIL startup string-copy guest input="
                      << (source[0] == '\0' ? "<empty>" : source) << "\n";
            return false;
        }
#if defined(_M_IX86)
        if (!native.passed
            || (guest.flags & kStatusFlags) != (native.flags & kStatusFlags)) {
            std::cerr << "FAIL startup string-copy x86 differential input="
                      << (source[0] == '\0' ? "<empty>" : source)
                      << " native_result=0x" << std::hex << native.result
                      << " native_ecx=0x" << native.ecx
                      << " native_esi=0x" << native.esi
                      << " native_flags=0x" << (native.flags & kStatusFlags)
                      << " native_nested_return=0x" << native.nested_return
                      << std::dec << " native_esp_balanced="
                      << (native.esp_balanced ? "yes" : "no")
                      << " guest_flags=0x" << std::hex
                      << (guest.flags & kStatusFlags) << std::dec << "\n";
            return false;
        }
        if (print_results) {
            std::cout << "PASS x86 differential startup_init_string_copy "
                      << "input_bytes=" << std::strlen(source)
                      << " return=object nested_target=0x011e8b20 "
                      << "nested_return=0x011e5d97 esp_balanced=yes\n";
        }
#else
        if (print_results) {
            std::cout << "PASS arm64 guest startup_init_string_copy "
                      << "input_bytes=" << std::strlen(source)
                      << " return=object nested_target=0x011e8b20 "
                      << "nested_return=0x011e5d97 esp_balanced=yes\n";
        }
#endif
    }
    return true;
}

bool guest_import_call(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    const char* symbol,
    std::uint32_t iat_address,
    std::uint32_t return_address,
    const std::uint32_t* arguments,
    std::size_t argument_count,
    std::uint32_t stack_before) {
    state.regs[4] = stack_before;
    for (std::size_t index = 0; index < argument_count; ++index) {
        if (!memory.store32(
                stack_before + static_cast<std::uint32_t>(index * 4u),
                arguments[index])) {
            return false;
        }
    }
    const BatchLiftStatus status = batch_guest_import_call32(
        memory, state, symbol, iat_address, return_address);
    return status == BatchLiftStatus::returned
        && state.eip == return_address
        && state.regs[4] == stack_before
            + static_cast<std::uint32_t>(argument_count * 4u);
}

bool run_guest_critical_section_lifecycle(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    BatchGuestRuntime& runtime,
    std::uint32_t section_address) {
    constexpr std::uint32_t kApiStack = 0x70000300u;
    constexpr std::uint32_t kApiReturn = 0xeeee0001u;
    const std::uint32_t argument[] = {section_address};

    if (!guest_import_call(
            memory, state,
            "KERNEL32.dll!EnterCriticalSection",
            kResmanIatEnterCriticalSection, kApiReturn,
            argument, 1u, kApiStack)) {
        return false;
    }
    if (!guest_import_call(
            memory, state,
            "KERNEL32.dll!EnterCriticalSection",
            kResmanIatEnterCriticalSection, kApiReturn,
            argument, 1u, kApiStack)) {
        return false;
    }

    std::uint32_t lock_count{};
    std::uint32_t recursion_count{};
    std::uint32_t owning_thread{};
    if (!memory.load32(section_address + 4u, lock_count)
        || !memory.load32(section_address + 8u, recursion_count)
        || !memory.load32(section_address + 12u, owning_thread)
        || static_cast<std::int32_t>(lock_count) != 1
        || recursion_count != 2u
        || owning_thread == 0u) {
        return false;
    }

    if (!guest_import_call(
            memory, state,
            "KERNEL32.dll!LeaveCriticalSection",
            kResmanIatLeaveCriticalSection, kApiReturn,
            argument, 1u, kApiStack)
        || !memory.load32(section_address + 8u, recursion_count)
        || recursion_count != 1u
        || !guest_import_call(
            memory, state,
            "KERNEL32.dll!LeaveCriticalSection",
            kResmanIatLeaveCriticalSection, kApiReturn,
            argument, 1u, kApiStack)
        || !memory.load32(section_address + 4u, lock_count)
        || !memory.load32(section_address + 8u, recursion_count)
        || !memory.load32(section_address + 12u, owning_thread)
        || static_cast<std::int32_t>(lock_count) != -1
        || recursion_count != 0u
        || owning_thread != 0u) {
        return false;
    }

    if (!guest_import_call(
            memory, state,
            "KERNEL32.dll!DeleteCriticalSection",
            kResmanIatDeleteCriticalSection, kApiReturn,
            argument, 1u, kApiStack)
        || runtime.has_critical_section(section_address)) {
        return false;
    }
    return true;
}

bool run_guest_resman_constructor(bool print_results) {
    constexpr std::uint32_t kFsSentinel = 0x1234abcdu;
    constexpr std::uint32_t kStringObjectVtable = 0x01452af0u;
    constexpr std::uint32_t kCriticalSectionOffset = 0x28u;
    std::array<std::uint8_t, 0x80> object{};
    std::array<std::uint8_t, 0x100> fs_region{};
    auto string_bytes = kSporeDataString_01449334_bytes;
    object.fill(0xa5u);
    fs_region.fill(0x5au);

    BatchLiftMemory memory;
    if (!memory.map_region(
            kResmanObjectBase, object.data(), object.size(), true)
        || !memory.map_region(
            kSporeDataString_01449334_address,
            string_bytes.data(), string_bytes.size(), false)
        || !memory.map_region(
            kResmanFsBase, fs_region.data(), fs_region.size(), true)
        || !memory.store32(kResmanFsBase, kFsSentinel)
        || !memory.store32(
            kResmanObjectBase + kCriticalSectionOffset + 0x3cu,
            kStackCanary)) {
        std::cerr << "ERROR could not map original PE string and guest state\n";
        return false;
    }

    BatchGuestRuntime runtime;
    BatchLiftState state{};
    for (std::uint32_t index = 0; index < 8u; ++index) {
        state.regs[index] = kRegisterSeed + index * 0x01010101u;
    }
    state.regs[1] = kResmanObjectBase;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.regs[6] = kInitialEsi;
    state.eflags = kInitialFlags;
    state.eip = 0x00a247f0u;
    state.fs_base = kResmanFsBase;
    state.imports = &runtime;
    if (!memory.store32(state.regs[4], kStackSentinel)
        || !memory.store32(state.regs[4] - 0x100u, kStackCanary)) {
        std::cerr << "ERROR could not initialize resman guest stack\n";
        return false;
    }

    const BatchLiftStatus status = spore_lift_00a247f0(memory, state);
    std::uint32_t object_vtable{};
    std::uint32_t lock_count{};
    std::uint32_t recursion_count{};
    std::uint32_t owning_thread{};
    std::uint32_t lock_semaphore{};
    std::uint32_t spin_count{};
    std::uint32_t restored_fs{};
    std::uint32_t stack_canary{};
    std::uint32_t object_canary{};
    const bool object_valid =
        memory.load32(kResmanObjectBase, object_vtable)
        && object_vtable == kStringObjectVtable
        && std::memcmp(
            object.data() + 4u,
            string_bytes.data(),
            string_bytes.size()) == 0
        && object[0x4cu] == 1u
        && memory.load32(
            kResmanObjectBase + kCriticalSectionOffset + 4u, lock_count)
        && static_cast<std::int32_t>(lock_count) == -1
        && memory.load32(
            kResmanObjectBase + kCriticalSectionOffset + 8u,
            recursion_count)
        && recursion_count == 0u
        && memory.load32(
            kResmanObjectBase + kCriticalSectionOffset + 12u,
            owning_thread)
        && owning_thread == 0u
        && memory.load32(
            kResmanObjectBase + kCriticalSectionOffset + 16u,
            lock_semaphore)
        && lock_semaphore == 0u
        && memory.load32(
            kResmanObjectBase + kCriticalSectionOffset + 20u, spin_count)
        && spin_count == 0u
        && memory.load32(
            kResmanObjectBase + kCriticalSectionOffset + 0x3cu,
            object_canary)
        && object_canary == kStackCanary
        && memory.load32(kResmanFsBase, restored_fs)
        && restored_fs == kFsSentinel
        && memory.load32(
            BatchLiftMemory::kEntryEsp - 0x100u, stack_canary)
        && stack_canary == kStackCanary;
    const bool call_valid = runtime.calls().size() == 1u
        && runtime.calls()[0].symbol
            == "KERNEL32.dll!InitializeCriticalSection"
        && runtime.calls()[0].iat_address
            == kResmanIatInitializeCriticalSection
        && runtime.calls()[0].arguments.size() == 1u
        && runtime.calls()[0].arguments[0]
            == kResmanObjectBase + kCriticalSectionOffset;
    const bool state_valid = status == BatchLiftStatus::returned
        && state.regs[0] == kResmanObjectBase
        && state.regs[1] == kFsSentinel
        && state.regs[6] == kInitialEsi
        && state.regs[4] == BatchLiftMemory::kEntryEsp + 4u
        && state.eip == kStackSentinel;
    if (!object_valid || !call_valid || !state_valid
        || !runtime.has_critical_section(
            kResmanObjectBase + kCriticalSectionOffset)) {
        std::cerr << "FAIL resman constructor status="
                  << static_cast<int>(status)
                  << " import_count=" << runtime.calls().size()
                  << " object_valid=" << object_valid
                  << " call_valid=" << call_valid
                  << " state_valid=" << state_valid
                  << " eax=0x" << std::hex << state.regs[0]
                  << " ecx=0x" << state.regs[1]
                  << " esi=0x" << state.regs[6]
                  << " esp=0x" << state.regs[4]
                  << " eip=0x" << state.eip
                  << " vtable=0x" << object_vtable
                  << " lock=0x" << lock_count
                  << " recursion=0x" << recursion_count
                  << " fs=0x" << restored_fs
                  << " stack_canary=0x" << stack_canary
                  << " object_canary=0x" << object_canary
                  << std::dec
                  << " error=" << runtime.last_error() << "\n";
        return false;
    }

#if defined(_M_IX86)
    const NativeResmanResult native = run_native_resman_constructor();
    auto guest_object = object;
    auto native_object = native.object;
    std::fill_n(
        guest_object.begin() + kCriticalSectionOffset,
        sizeof(std::uint32_t), std::uint8_t{0});
    std::fill_n(
        native_object.begin() + kCriticalSectionOffset,
        sizeof(std::uint32_t), std::uint8_t{0});
    std::fill_n(
        guest_object.begin() + 0x3cu,
        sizeof(std::uint32_t), std::uint8_t{0});
    std::fill_n(
        native_object.begin() + 0x3cu,
        sizeof(std::uint32_t), std::uint8_t{0});
    const std::uint32_t expected_returns[] = {
        0u, 0x00a2483cu, 0x009222ecu, 0x00922172u,
    };
    bool stack_returns_match = true;
    for (std::size_t index = 0; index < 4u; ++index) {
        std::uint32_t return_address{};
        stack_returns_match = stack_returns_match
            && memory.load32(
                BatchLiftMemory::kEntryEsp
                    - std::array<std::uint32_t, 4>{0x1cu, 0x20u, 0x40u, 0x4cu}[index],
                return_address)
            && return_address == expected_returns[index];
    }
    const bool object_matches = std::memcmp(
        guest_object.data(), native_object.data(), guest_object.size()) == 0;
    if (!native.passed || !stack_returns_match || !object_matches) {
        std::cerr << "FAIL x86 differential resman constructor "
                  << "native_passed=" << native.passed
                  << " stack_returns_match=" << stack_returns_match
                  << " object_matches=" << object_matches
                  << " esp_balanced=" << native.esp_balanced
                  << " fs_restored=" << native.fs_restored
                  << " recursive_lock=" << native.recursive_lock_passed
                  << " native_result=0x" << std::hex << native.result
                  << " native_ecx=0x" << native.ecx
                  << " native_fs=0x" << native.fs_before
                  << " returns=[0x" << native.nested_returns[0]
                  << ",0x" << native.nested_returns[1]
                  << ",0x" << native.nested_returns[2]
                  << ",0x" << native.nested_returns[3] << "]"
                  << " critical=[lock:" << std::dec
                  << native.lock_count_after_enter
                  << ",rec:" << native.recursion_after_enter
                  << ",owner:" << native.owner_after_enter
                  << " -> lock:" << native.lock_count_after_leave
                  << ",rec:" << native.recursion_after_leave
                  << ",owner:" << native.owner_after_leave << "]"
                  << " native_spin_count=0x" << std::hex
                  << native.native_spin_count
                  << std::dec << "\n";
        if (!object_matches) {
            std::cerr << "object byte differences:";
            for (std::size_t index = 0; index < guest_object.size(); ++index) {
                if (guest_object[index] != native_object[index]) {
                    std::cerr << " [0x" << std::hex << index << ":0x"
                              << static_cast<unsigned>(guest_object[index])
                              << "!=0x"
                              << static_cast<unsigned>(native_object[index])
                              << "]";
                }
            }
            std::cerr << std::dec << "\n";
        }
        return false;
    }
    if (print_results) {
        std::cout << "PASS x86 differential resman_constructor "
                  << "object_bytes=" << guest_object.size()
                  << " critical_section_debug_pointer=normalized "
                  << "opaque_spin_count=excluded native=0x" << std::hex
                  << native.native_spin_count << " guest=0x0" << std::dec << " "
                  << "stack_return_sites=4 esp_balanced=yes fs_restored=yes "
                  << "recursive_lock=2/2/delete=passed\n";
    }
#else
    if (print_results) {
        std::cout << "PASS arm64 guest resman_constructor "
                  << "string=PE:0x01449334 bytes="
                  << string_bytes.size()
                  << " object=verified esp_balanced=yes fs_restored=yes "
                  << "import=KERNEL32.dll!InitializeCriticalSection\n";
    }
#endif

    if (!run_guest_critical_section_lifecycle(
            memory, state, runtime,
            kResmanObjectBase + kCriticalSectionOffset)) {
        std::cerr << "FAIL critical-section recursive lifecycle\n";
        return false;
    }
    if (object[0x7fu] != 0xa5u) {
        std::cerr << "FAIL resman constructor changed object guard bytes\n";
        return false;
    }
    if (print_results) {
        std::cout << "PASS guest critical_section "
                  << "layout=x86-24-byte recursion=2 enter=2 leave=2 "
                  << "delete=passed\n";
    }
    return true;
}

bool run_guest_create_mutex_rejection(bool print_results) {
    constexpr std::uint32_t kMutexConfig = kResmanObjectBase + 0x60u;
    std::array<std::uint8_t, 0x100> object{};
    BatchLiftMemory memory;
    if (!memory.map_region(
            kResmanObjectBase, object.data(), object.size(), true)
        || !memory.store8(kMutexConfig, 0u)
        || !memory.store8(kMutexConfig + 1u, 1u)) {
        return false;
    }

    BatchGuestRuntime runtime;
    BatchLiftState state{};
    state.regs[1] = kResmanObjectBase;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.eip = 0x00922150u;
    state.imports = &runtime;
    if (!memory.store32(state.regs[4], kStackSentinel)
        || !memory.store32(state.regs[4] + 4u, kMutexConfig)) {
        return false;
    }
    const BatchLiftStatus status = spore_lift_00922150(memory, state);
    const bool passed = status == BatchLiftStatus::unsupported_import
        && state.eip == kResmanIatCreateMutexA
        && state.regs[4] != BatchLiftMemory::kEntryEsp + 4u
        && runtime.calls().size() == 1u
        && runtime.calls()[0].symbol == "KERNEL32.dll!CreateMutexA"
        && runtime.calls()[0].iat_address == kResmanIatCreateMutexA
        && runtime.calls()[0].arguments.size() == 3u
        && runtime.calls()[0].arguments[0] == 0u
        && runtime.calls()[0].arguments[1] == 0u
        && runtime.calls()[0].arguments[2] == kMutexConfig + 1u
        && runtime.last_error().find("not implemented")
            != std::string::npos;
    if (!passed) {
        std::cerr << "FAIL CreateMutexA rejection status="
                  << static_cast<int>(status)
                  << " import_count=" << runtime.calls().size()
                  << " error=" << runtime.last_error() << "\n";
        return false;
    }
    if (print_results) {
        std::cout << "PASS explicit import rejection "
                  << "import=KERNEL32.dll!CreateMutexA "
                  << "diagnostic=\"" << runtime.last_error()
                  << "\" execution_stopped=yes\n";
    }
    return true;
}

bool run_movss_transfer_regression(bool print_results) {
    constexpr std::uint32_t kMemoryBase = 0x2000u;
    constexpr std::uint32_t kSourceAddress = kMemoryBase + 4u;
    constexpr std::uint32_t kDestinationAddress = kMemoryBase + 12u;
    constexpr std::uint32_t kScalarBits = 0x3f123456u;
    constexpr std::uint32_t kMovssInitialFlags = 0x8d5u;
    std::array<std::uint8_t, 0x20> bytes{};
    BatchLiftMemory memory;
    if (!memory.map_region(
            kMemoryBase, bytes.data(), bytes.size(), true)
        || !memory.store32(kSourceAddress, kScalarBits)
        || !memory.store32(kDestinationAddress, 0xaaaaaaaaU)) {
        return false;
    }

    BatchLiftState state{};
    state.eflags = kMovssInitialFlags;
    state.xmm[0][1] = 0x11111111u;
    state.xmm[0][2] = 0x22222222u;
    state.xmm[0][3] = 0x33333333u;
    state.xmm[1][0] = 0x40506070u;
    state.xmm[1][1] = 0x41424344u;
    state.xmm[1][2] = 0x51525354u;
    state.xmm[1][3] = 0x61626364u;
    state.xmm[2][1] = 0x71727374u;
    state.xmm[2][2] = 0x81828384u;
    state.xmm[2][3] = 0x91929394u;

    bool native_matches = true;
#if defined(_M_IX86)
    float native_source{};
    std::memcpy(&native_source, &kScalarBits, sizeof(kScalarBits));
    std::array<std::uint32_t, 4> loaded_lanes{};
    _mm_storeu_ps(
        reinterpret_cast<float*>(loaded_lanes.data()),
        _mm_load_ss(&native_source));
    const __m128 native_destination = _mm_castsi128_ps(
        _mm_loadu_si128(
            reinterpret_cast<const __m128i*>(state.xmm[2])));
    const __m128 native_register_source = _mm_castsi128_ps(
        _mm_loadu_si128(
            reinterpret_cast<const __m128i*>(state.xmm[1])));
    std::array<std::uint32_t, 4> moved_lanes{};
    _mm_storeu_ps(
        reinterpret_cast<float*>(moved_lanes.data()),
        _mm_move_ss(native_destination, native_register_source));
#else
    const std::array<std::uint32_t, 4> loaded_lanes{
        kScalarBits, 0u, 0u, 0u};
    const std::array<std::uint32_t, 4> moved_lanes{
        state.xmm[1][0], state.xmm[2][1],
        state.xmm[2][2], state.xmm[2][3]};
#endif

    const bool load_passed = batch_guest_movss_load(
            memory, state, 0u, kSourceAddress)
        && std::equal(
            std::begin(loaded_lanes), std::end(loaded_lanes),
            std::begin(state.xmm[0]));
    const bool move_passed = batch_guest_movss_register_move(
            state, 2u, 1u)
        && std::equal(
            std::begin(moved_lanes), std::end(moved_lanes),
            std::begin(state.xmm[2]));
    const bool store_passed = batch_guest_movss_store(
            memory, state, 2u, kDestinationAddress);
    std::uint32_t stored_value{};
    const bool memory_passed = memory.load32(
        kDestinationAddress, stored_value)
        && stored_value == state.xmm[2][0]
        && bytes[16] == 0u
        && bytes[17] == 0u
        && bytes[18] == 0u
        && bytes[19] == 0u;
#if defined(_M_IX86)
    float native_stored{};
    _mm_store_ss(&native_stored, _mm_move_ss(
        native_destination, native_register_source));
    std::uint32_t native_stored_bits{};
    std::memcpy(&native_stored_bits, &native_stored, sizeof(native_stored_bits));
    native_matches = std::equal(
            std::begin(loaded_lanes), std::end(loaded_lanes),
            std::begin(state.xmm[0]))
        && std::equal(
            std::begin(moved_lanes), std::end(moved_lanes),
            std::begin(state.xmm[2]))
        && native_stored_bits == stored_value;
#endif
    const std::uint32_t low_before_invalid_load = state.xmm[3][0];
    const bool bounds_passed =
        !batch_guest_movss_load(
            memory, state, 3u, kMemoryBase + 0x1eu)
        && state.xmm[3][0] == low_before_invalid_load
        && !batch_guest_movss_store(
            memory, state, 2u, kMemoryBase + 0x1eu);
    const bool flags_passed = state.eflags == kMovssInitialFlags;
    if (!load_passed || !move_passed || !store_passed
        || !memory_passed || !native_matches || !bounds_passed
        || !flags_passed) {
        std::cerr << "FAIL movss_transfer load=" << load_passed
                  << " move=" << move_passed
                  << " store=" << store_passed
                  << " memory=" << memory_passed
                  << " native=" << native_matches
                  << " bounds=" << bounds_passed
                  << " flags=" << flags_passed << "\n";
        return false;
    }
    if (print_results) {
        std::cout << "PASS movss_transfer forms=memory_to_xmm,xmm_to_xmm,"
                  << "xmm_to_memory upper_lanes=verified flags=preserved "
                  << "bounds=checked"
#if defined(_M_IX86)
                  << " reference=x86_SSE"
#else
                  << " reference=verified_scalar_semantics"
#endif
                  << "\n";
    }
    return true;
}

} // namespace

int main() {
    if (!run_movss_transfer_regression(true)
        || !run_recursive_cases(true)
        || !run_distinct_function_calls(true)
        || !run_startup_initialization_chain(true)
        || !run_guest_resman_constructor(true)
        || !run_guest_create_mutex_rejection(true)) {
        return 1;
    }
    std::cout << "PASS generated_backend_call_closures recursive=1 "
              << "distinct_functions=2 startup_linked_functions=2 "
              << "import_startup_functions=5 "
              << "shared_state=yes verified_pe_bytes=yes\n";
    return 0;
}
