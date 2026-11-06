#pragma once

#include "BatchStaticLiftRuntime.hpp"

#include <array>
#include <cstdint>
#include <iostream>

BatchLiftStatus spore_lift_006237a0(
    BatchLiftMemory& memory,
    BatchLiftState& state);

struct GuestCaseResult {
    bool passed{};
    std::uint32_t result{};
    std::uint32_t flags{};
    std::uint32_t child_result{};
    std::uint32_t final_esp{};
    std::uint32_t final_eip{};
    std::uint32_t recursive_calls{};
};

inline std::uint32_t expected_add_flags(
    std::uint32_t initial_flags,
    std::uint32_t left,
    std::uint32_t right) {
    constexpr std::uint32_t arithmetic_mask = 0x8d5u;
    const std::uint32_t result = left + right;
    std::uint32_t flags = initial_flags & ~arithmetic_mask;
    if (result < left) flags |= 1u;
    if (((left ^ right ^ result) & 0x10u) != 0u) flags |= 1u << 4u;
    if (result == 0u) flags |= 1u << 6u;
    if ((result & 0x80000000u) != 0u) flags |= 1u << 7u;
    if (((~(left ^ right) & (left ^ result)) & 0x80000000u) != 0u) {
        flags |= 1u << 11u;
    }

    std::uint8_t parity = static_cast<std::uint8_t>(result);
    parity ^= static_cast<std::uint8_t>(parity >> 4u);
    parity ^= static_cast<std::uint8_t>(parity >> 2u);
    parity ^= static_cast<std::uint8_t>(parity >> 1u);
    if ((parity & 1u) == 0u) flags |= 1u << 2u;
    return flags;
}

inline bool guest_store(
    BatchLiftMemory& memory,
    std::uint32_t address,
    std::uint32_t value) {
    return memory.store32(address, value);
}

inline bool guest_load(
    const BatchLiftMemory& memory,
    std::uint32_t address,
    std::uint32_t& value) {
    return memory.load32(address, value);
}

inline GuestCaseResult run_guest_case(
    const std::array<std::uint32_t, 4>& values,
    std::uint32_t depth,
    std::uint32_t sentinel = 0xfedcba98u) {
    constexpr std::uint32_t first_node = 0x3000u;
    constexpr std::uint32_t node_stride = 0x40u;
    constexpr std::uint32_t stack_top = 0xf000u;
    constexpr std::uint32_t stack_canary = 0x8badf00du;
    constexpr std::uint32_t initial_esi = 0xcafebabeu;
    constexpr std::uint32_t initial_flags = 0xa5a50002u;
    constexpr std::uint32_t register_seed = 0x10101010u;

    BatchLiftMemory memory;
    BatchLiftState state{};
    for (std::uint32_t index = 0u; index < 8u; ++index) {
        state.regs[index] = register_seed + index * 0x01010101u;
    }
    state.regs[1] = first_node;
    state.regs[4] = stack_top;
    state.regs[6] = initial_esi;
    state.eflags = initial_flags;
    state.eip = 0x006237a0u;

    for (std::uint32_t index = 0u; index <= depth; ++index) {
        const std::uint32_t node = first_node + index * node_stride;
        const std::uint32_t child = index < depth
            ? node + node_stride : 0u;
        if (!guest_store(memory, node + 0x30u, child)
            || !guest_store(memory, node + 0x34u, values[index])) {
            return {};
        }
    }
    if (!guest_store(memory, stack_top, sentinel)
        || !guest_store(
            memory, stack_top - 8u - 8u * depth, stack_canary)) {
        return {};
    }

    std::uint32_t sum = 0u;
    for (std::uint32_t index = 0u; index <= depth; ++index) {
        sum += values[index];
    }
    std::uint32_t child_sum = 0u;
    for (std::uint32_t index = 1u; index <= depth; ++index) {
        child_sum += values[index];
    }
    const std::uint32_t expected_flags =
        expected_add_flags(initial_flags, sum - values[0], values[0]);
    const std::uint32_t status_mask = 0x8d5u;

    const BatchLiftStatus status = spore_lift_006237a0(memory, state);
    std::uint32_t actual_canary{};
    bool passed = status == BatchLiftStatus::returned
        && state.regs[0] == sum
        && state.regs[1] == child_sum
        && state.regs[2] == register_seed + 2u * 0x01010101u
        && state.regs[3] == register_seed + 3u * 0x01010101u
        && state.regs[5] == register_seed + 5u * 0x01010101u
        && state.regs[7] == register_seed + 7u * 0x01010101u
        && state.regs[6] == initial_esi
        && state.regs[4] == stack_top + 4u
        && state.eip == sentinel
        && (state.eflags & status_mask) == (expected_flags & status_mask)
        && (state.eflags & ~status_mask) == (initial_flags & ~status_mask)
        && guest_load(
            memory, stack_top - 8u - 8u * depth, actual_canary)
        && actual_canary == stack_canary;

    for (std::uint32_t index = 0u; index <= depth && passed; ++index) {
        const std::uint32_t node = first_node + index * node_stride;
        const std::uint32_t expected_child = index < depth
            ? node + node_stride : 0u;
        std::uint32_t actual_child{};
        std::uint32_t actual_value{};
        passed = guest_load(memory, node + 0x30u, actual_child)
            && guest_load(memory, node + 0x34u, actual_value)
            && actual_child == expected_child
            && actual_value == values[index];
    }
    for (std::uint32_t frame = 0u; frame <= depth && passed; ++frame) {
        std::uint32_t saved_esi{};
        passed = guest_load(
            memory, stack_top - 4u - 8u * frame, saved_esi)
            && saved_esi == (frame == 0u
                ? initial_esi
                : first_node + (frame - 1u) * node_stride);
        if (frame < depth && passed) {
            std::uint32_t return_address{};
            passed = guest_load(
                memory, stack_top - 8u - 8u * frame, return_address)
                && return_address == 0x006237afu;
        }
    }
    return {
        passed,
        state.regs[0],
        state.eflags,
        child_sum,
        state.regs[4],
        state.eip,
        depth,
    };
}

inline bool run_guest_harness(bool print_results) {
    const std::array<std::array<std::uint32_t, 4>, 4> inputs = {{
        {{0u, 0u, 0u, 0u}},
        {{0xffffffffu, 1u, 0u, 0u}},
        {{0x7fffffffu, 1u, 0x80000000u, 0xffffffffu}},
        {{0xdeadbeefu, 0x12345678u, 0xa5a5a5a5u, 0x55555555u}},
    }};
    std::uint32_t cases = 0u;
    for (std::uint32_t depth = 0u; depth < inputs.size(); ++depth) {
        const GuestCaseResult result = run_guest_case(inputs[depth], depth);
        if (!result.passed) {
            std::cerr << "FAIL guest depth=" << depth << "\n";
            return false;
        }
        ++cases;
        if (print_results) {
            std::cout << "PASS guest depth=" << depth
                      << " result=0x" << std::hex << result.result
                      << " child=0x" << result.child_result
                      << " flags=0x" << result.flags
                      << " esp=0x" << result.final_esp
                      << " eip=0x" << result.final_eip
                      << std::dec << " recursive_calls="
                      << result.recursive_calls
                      << " guest_return_addresses=verified"
                      << " stack_canary=verified memory=unchanged\n";
        }
    }
    const GuestCaseResult colliding_return = run_guest_case(
        inputs[2], 2u, 0x006237afu);
    if (!colliding_return.passed) {
        std::cerr << "FAIL guest external return-address collision\n";
        return false;
    }

    BatchLiftMemory bad_memory;
    BatchLiftState bad_target{};
    bad_target.eip = 0xdeadbeefu;
    const bool rejects_unknown_target =
        spore_lift_006237a0(bad_memory, bad_target)
        == BatchLiftStatus::invalid_control_flow;
    BatchLiftState bad_stack{};
    bad_stack.eip = 0x006237a0u;
    bad_stack.regs[1] = 0x3000u;
    bad_stack.regs[4] = BatchLiftMemory::base;
    const bool rejects_stack_underflow =
        spore_lift_006237a0(bad_memory, bad_stack)
            == BatchLiftStatus::invalid_memory
        && bad_stack.regs[4] == BatchLiftMemory::base;
    if (!rejects_unknown_target || !rejects_stack_underflow) {
        std::cerr << "FAIL guest rejection paths\n";
        return false;
    }
    if (print_results) {
        std::cout << "PASS guest_rejections unknown_target="
                  << (rejects_unknown_target ? "rejected" : "accepted")
                  << " stack_underflow="
                  << (rejects_stack_underflow ? "rejected" : "accepted")
                  << "\nPASS guest_return_address_collision="
                  << "0x006237af handled_by_call_depth"
                  << "\nPASS guest_harness cases=" << cases
                  << " recursive_CALL_and_RET=executed\n";
    }
    return true;
}
