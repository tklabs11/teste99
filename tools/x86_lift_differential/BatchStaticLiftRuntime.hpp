#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

enum class BatchLiftStatus {
    returned,
    invalid_memory,
    invalid_control_flow,
};

struct BatchLiftState {
    std::uint32_t regs[8]{};
    std::uint32_t eflags{};
    std::uint32_t eip{};
};

class BatchLiftMemory {
public:
    static constexpr std::uint32_t base = 0x1000u;
    static constexpr std::size_t size = 0x10000u;

    bool load32(std::uint32_t address, std::uint32_t& value) const {
        std::size_t offset{};
        if (!get_offset(address, offset)) {
            return false;
        }

        value = static_cast<std::uint32_t>(bytes_[offset])
            | (static_cast<std::uint32_t>(bytes_[offset + 1]) << 8u)
            | (static_cast<std::uint32_t>(bytes_[offset + 2]) << 16u)
            | (static_cast<std::uint32_t>(bytes_[offset + 3]) << 24u);
        return true;
    }

    bool store32(std::uint32_t address, std::uint32_t value) {
        std::size_t offset{};
        if (!get_offset(address, offset)) {
            return false;
        }

        bytes_[offset] = static_cast<std::uint8_t>(value);
        bytes_[offset + 1] = static_cast<std::uint8_t>(value >> 8u);
        bytes_[offset + 2] = static_cast<std::uint8_t>(value >> 16u);
        bytes_[offset + 3] = static_cast<std::uint8_t>(value >> 24u);
        return true;
    }

private:
    bool get_offset(std::uint32_t address, std::size_t& offset) const {
        if (address < base || address - base > size - sizeof(std::uint32_t)) {
            return false;
        }
        offset = static_cast<std::size_t>(address - base);
        return true;
    }

    std::array<std::uint8_t, size> bytes_{};
};

inline bool batch_guest_push32(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t value) {
    const std::uint32_t next_stack = state.regs[4] - 4u;
    if (!memory.store32(next_stack, value)) {
        return false;
    }
    state.regs[4] = next_stack;
    return true;
}

inline bool batch_guest_pop32(
    const BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t& value) {
    if (!memory.load32(state.regs[4], value)) {
        return false;
    }
    state.regs[4] += 4u;
    return true;
}

inline bool batch_guest_call32(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t target,
    std::uint32_t return_address) {
    if (!batch_guest_push32(memory, state, return_address)) {
        return false;
    }
    state.eip = target;
    return true;
}

inline bool batch_guest_return32(
    const BatchLiftMemory& memory,
    BatchLiftState& state) {
    return batch_guest_pop32(memory, state, state.eip);
}

inline void batch_set_logic_flags(
    BatchLiftState& state,
    std::uint32_t result,
    std::uint32_t width) {
    constexpr std::uint32_t carry_flag = 1u << 0u;
    constexpr std::uint32_t parity_flag = 1u << 2u;
    constexpr std::uint32_t auxiliary_carry_flag = 1u << 4u;
    constexpr std::uint32_t zero_flag = 1u << 6u;
    constexpr std::uint32_t sign_flag = 1u << 7u;
    constexpr std::uint32_t overflow_flag = 1u << 11u;
    constexpr std::uint32_t logic_flags =
        carry_flag | parity_flag | auxiliary_carry_flag
        | zero_flag | sign_flag | overflow_flag;

    state.eflags &= ~logic_flags;
    if (result == 0u) {
        state.eflags |= zero_flag;
    }
    if (width != 0u && width <= 32u
        && (result & (1u << (width - 1u))) != 0u) {
        state.eflags |= sign_flag;
    }

    std::uint8_t low_byte = static_cast<std::uint8_t>(result);
    std::uint8_t bit_count = 0u;
    for (unsigned int bit = 0; bit < 8u; ++bit) {
        bit_count = static_cast<std::uint8_t>(
            bit_count + ((low_byte >> bit) & 1u));
    }
    if ((bit_count & 1u) == 0u) {
        state.eflags |= parity_flag;
    }
}

inline std::uint32_t batch_guest_add32(
    BatchLiftState& state,
    std::uint32_t left,
    std::uint32_t right) {
    constexpr std::uint32_t carry_flag = 1u << 0u;
    constexpr std::uint32_t parity_flag = 1u << 2u;
    constexpr std::uint32_t auxiliary_carry_flag = 1u << 4u;
    constexpr std::uint32_t zero_flag = 1u << 6u;
    constexpr std::uint32_t sign_flag = 1u << 7u;
    constexpr std::uint32_t overflow_flag = 1u << 11u;
    constexpr std::uint32_t arithmetic_flags =
        carry_flag | parity_flag | auxiliary_carry_flag
        | zero_flag | sign_flag | overflow_flag;

    const std::uint64_t wide_result =
        static_cast<std::uint64_t>(left) + right;
    const std::uint32_t result = static_cast<std::uint32_t>(wide_result);
    state.eflags &= ~arithmetic_flags;
    if ((wide_result >> 32u) != 0u) {
        state.eflags |= carry_flag;
    }
    if (((left ^ right ^ result) & 0x10u) != 0u) {
        state.eflags |= auxiliary_carry_flag;
    }
    if (result == 0u) {
        state.eflags |= zero_flag;
    }
    if ((result & 0x80000000u) != 0u) {
        state.eflags |= sign_flag;
    }
    if (((~(left ^ right) & (left ^ result)) & 0x80000000u) != 0u) {
        state.eflags |= overflow_flag;
    }

    std::uint8_t low_byte = static_cast<std::uint8_t>(result);
    std::uint8_t bit_count = 0u;
    for (unsigned int bit = 0; bit < 8u; ++bit) {
        bit_count = static_cast<std::uint8_t>(
            bit_count + ((low_byte >> bit) & 1u));
    }
    if ((bit_count & 1u) == 0u) {
        state.eflags |= parity_flag;
    }
    return result;
}
