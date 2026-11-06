#include "BatchStaticLiftRuntime.hpp"
#if defined(_M_IX86)
#include "recursive_reference_bytes.hpp"
#include "cross_call_reference_bytes.hpp"
#include "startup_reference_bytes.hpp"
#endif

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>

#if defined(_M_IX86)
#include <Windows.h>
#include <memory>

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

    const std::uint8_t* at(std::uint32_t address) const {
        return static_cast<const std::uint8_t*>(memory_)
            + (address - first_va_);
    }

private:
    std::uint32_t first_va_{};
    std::size_t size_{};
    void* memory_{};
};

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

} // namespace

int main() {
    if (!run_recursive_cases(true)
        || !run_distinct_function_calls(true)
        || !run_startup_initialization_chain(true)) {
        return 1;
    }
    std::cout << "PASS generated_backend_call_closures recursive=1 "
              << "distinct_functions=2 startup_linked_functions=2 "
              << "shared_state=yes verified_pe_bytes=yes\n";
    return 0;
}
