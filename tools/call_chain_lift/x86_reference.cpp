#include "guest_harness.hpp"
#include "spore_006237a0_bytes.hpp"

#include <Windows.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <memory>
#include <stdexcept>

#if !defined(_M_IX86)
#error The x86 reference harness must be compiled for Windows x86.
#endif

static_assert(sizeof(void*) == sizeof(std::uint32_t), "x86 process required");

namespace {

struct NativeNode {
    std::uint8_t prefix[0x30]{};
    std::uint32_t child{};
    std::uint32_t value{};
};

static_assert(offsetof(NativeNode, child) == 0x30u, "child offset mismatch");
static_assert(offsetof(NativeNode, value) == 0x34u, "value offset mismatch");

struct VirtualMemoryDeleter {
    void operator()(void* memory) const noexcept {
        if (memory != nullptr) {
            VirtualFree(memory, 0, MEM_RELEASE);
        }
    }
};

struct NativeCaseResult {
    bool passed{};
    std::uint32_t result{};
    std::uint32_t child_result{};
    std::uint32_t flags{};
    std::uint32_t final_esp{};
    std::uint32_t recursive_calls{};
};

NativeCaseResult run_native_case(
    const std::uint8_t* function,
    const std::array<std::uint32_t, 4>& values,
    std::uint32_t depth) {
    std::array<NativeNode, 4> nodes{};
    for (std::uint32_t index = 0u; index <= depth; ++index) {
        nodes[index].child = index < depth
            ? static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&nodes[index + 1u]))
            : 0u;
        nodes[index].value = values[index];
    }
    const auto node_snapshot = nodes;
    const std::uint32_t root = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(nodes.data()));
    const std::uint32_t function_address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(function));

    std::uint32_t native_result{};
    std::uint32_t native_ecx{};
    std::uint32_t native_edx{};
    std::uint32_t native_ebx{};
    std::uint32_t native_ebp{};
    std::uint32_t native_edi{};
    std::uint32_t native_esi{};
    std::uint32_t initial_edx{};
    std::uint32_t initial_ebx{};
    std::uint32_t initial_ebp{};
    std::uint32_t initial_edi{};
    std::uint32_t initial_esi{};
    std::uint32_t initial_flags{};
    std::uint32_t native_flags{};
    std::uint32_t esp_before{};
    std::uint32_t esp_after{};
    std::array<std::uint32_t, 4> saved_esi{};
    std::array<std::uint32_t, 3> return_addresses{};

    __asm {
        mov initial_edx, edx
        mov initial_ebx, ebx
        mov initial_ebp, ebp
        mov initial_edi, edi
        mov initial_esi, esi
        pushfd
        pop eax
        mov initial_flags, eax
        mov eax, function_address
        mov ecx, root
        mov esp_before, esp
        call eax
        mov native_result, eax
        mov native_ecx, ecx
        mov native_edx, edx
        mov native_ebx, ebx
        mov native_ebp, ebp
        mov native_edi, edi
        mov native_esi, esi
        pushfd
        pop eax
        mov native_flags, eax
        mov esp_after, esp
        mov edx, esp
        mov eax, dword ptr [edx - 8]
        mov saved_esi[0], eax
        mov eax, dword ptr [edx - 16]
        mov saved_esi[4], eax
        mov eax, dword ptr [edx - 24]
        mov saved_esi[8], eax
        mov eax, dword ptr [edx - 32]
        mov saved_esi[12], eax
        mov eax, dword ptr [edx - 12]
        mov return_addresses[0], eax
        mov eax, dword ptr [edx - 20]
        mov return_addresses[4], eax
        mov eax, dword ptr [edx - 28]
        mov return_addresses[8], eax
    }

    std::uint32_t expected_result = 0u;
    std::uint32_t expected_child_result = 0u;
    for (std::uint32_t index = 0u; index <= depth; ++index) {
        expected_result += values[index];
        if (index != 0u) expected_child_result += values[index];
    }
    bool passed = esp_before == esp_after
        && native_result == expected_result
        && native_ecx == expected_child_result
        && native_edx == initial_edx
        && native_ebx == initial_ebx
        && native_ebp == initial_ebp
        && native_edi == initial_edi
        && native_esi == initial_esi
        && (native_flags & 0x8d5u)
            == (expected_add_flags(
                    initial_flags, expected_child_result, values[0])
                & 0x8d5u)
        && std::memcmp(
            nodes.data(), node_snapshot.data(), sizeof(nodes)) == 0;
    for (std::uint32_t frame = 0u; frame <= depth && passed; ++frame) {
        const std::uint32_t expected_esi = frame == 0u
            ? initial_esi : static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&nodes[frame - 1u]));
        passed = saved_esi[frame] == expected_esi;
        if (frame < depth && passed) {
            passed = return_addresses[frame]
                == static_cast<std::uint32_t>(
                    reinterpret_cast<std::uintptr_t>(function + 15u));
        }
    }
    return {
        passed,
        native_result,
        native_ecx,
        native_flags,
        esp_after,
        depth,
    };
}

} // namespace

int main() {
    void* executable = VirtualAlloc(
        nullptr,
        kSporeFunctionBytes.size(),
        MEM_COMMIT | MEM_RESERVE,
        PAGE_READWRITE);
    if (executable == nullptr) {
        std::cerr << "ERROR VirtualAlloc failed\n";
        return 1;
    }
    std::unique_ptr<void, VirtualMemoryDeleter> executable_memory(executable);
    std::copy(
        kSporeFunctionBytes.begin(),
        kSporeFunctionBytes.end(),
        static_cast<std::uint8_t*>(executable_memory.get()));
    DWORD old_protection{};
    if (!VirtualProtect(
            executable_memory.get(),
            kSporeFunctionBytes.size(),
            PAGE_EXECUTE_READ,
            &old_protection)
        || !FlushInstructionCache(
            GetCurrentProcess(),
            executable_memory.get(),
            kSporeFunctionBytes.size())) {
        std::cerr << "ERROR could not make verified PE bytes executable\n";
        return 1;
    }

    const auto* function =
        static_cast<const std::uint8_t*>(executable_memory.get());
    const std::array<std::array<std::uint32_t, 4>, 4> inputs = {{
        {{0u, 0u, 0u, 0u}},
        {{0xffffffffu, 1u, 0u, 0u}},
        {{0x7fffffffu, 1u, 0x80000000u, 0xffffffffu}},
        {{0xdeadbeefu, 0x12345678u, 0xa5a5a5a5u, 0x55555555u}},
    }};
    for (std::uint32_t depth = 0u; depth < inputs.size(); ++depth) {
        const GuestCaseResult guest = run_guest_case(inputs[depth], depth);
        const NativeCaseResult native =
            run_native_case(function, inputs[depth], depth);
        if (!guest.passed || !native.passed
            || guest.result != native.result
            || guest.child_result != native.child_result
            || (guest.flags & 0x8d5u) != (native.flags & 0x8d5u)
            || guest.recursive_calls != native.recursive_calls) {
            std::cerr << "FAIL differential depth=" << depth << "\n";
            return 1;
        }
        std::cout << "PASS x86 differential depth=" << depth
                  << " return=0x" << std::hex << native.result
                  << " child_ecx=0x" << native.child_result
                  << " eflags=0x" << (native.flags & 0x8d5u)
                  << std::dec << " esp_balanced=yes"
                  << " recursive_calls=" << native.recursive_calls
                  << " native_call_return=verified"
                  << " callee_saved=verified object_memory=unchanged\n";
    }
    if (!run_guest_harness(true)) return 1;
    std::cout << "PASS x86_vs_guest cases=" << inputs.size()
              << " function_va=0x006237a0"
              << " reference=verified_pe_bytes\n";
    return 0;
}
