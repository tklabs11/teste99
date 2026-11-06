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
    std::uint32_t eflags = 0;
    std::uint32_t eip = 0;
    std::uint32_t fs_base = 0;
};

inline bool batch_even_parity(std::uint8_t value) {
    value ^= static_cast<std::uint8_t>(value >> 4u);
    value &= 0x0fu;
    return ((0x6996u >> value) & 1u) == 0u;
}

inline std::uint32_t batch_mask(unsigned width) {
    return width == 32u ? 0xffffffffu : ((std::uint32_t{1} << width) - 1u);
}

inline void batch_set_add_flags(
    BatchLiftState& state,
    std::uint32_t left,
    std::uint32_t right,
    std::uint32_t result,
    unsigned width) {
    const std::uint64_t mask = (std::uint64_t{1} << width) - 1u;
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    left &= static_cast<std::uint32_t>(mask);
    right &= static_cast<std::uint32_t>(mask);
    result &= static_cast<std::uint32_t>(mask);
    state.eflags &= ~0x8d5u;
    if (static_cast<std::uint64_t>(left) + right > mask) state.eflags |= 0x001u;
    if (batch_even_parity(static_cast<std::uint8_t>(result))) state.eflags |= 0x004u;
    if (((left ^ right ^ result) & 0x010u) != 0u) state.eflags |= 0x010u;
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
    if (((~(left ^ right) & (left ^ result)) & sign) != 0u) state.eflags |= 0x800u;
}

inline void batch_set_sub_flags(
    BatchLiftState& state,
    std::uint32_t left,
    std::uint32_t right,
    std::uint32_t result,
    unsigned width) {
    const std::uint32_t mask = batch_mask(width);
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    left &= mask;
    right &= mask;
    result &= mask;
    state.eflags &= ~0x8d5u;
    if (left < right) state.eflags |= 0x001u;
    if (batch_even_parity(static_cast<std::uint8_t>(result))) state.eflags |= 0x004u;
    if (((left ^ right ^ result) & 0x010u) != 0u) state.eflags |= 0x010u;
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
    if ((((left ^ right) & (left ^ result)) & sign) != 0u) state.eflags |= 0x800u;
}

inline void batch_set_sbb_flags(
    BatchLiftState& state,
    std::uint32_t left,
    std::uint32_t right,
    std::uint32_t borrow,
    std::uint32_t result,
    unsigned width) {
    const std::uint32_t mask = batch_mask(width);
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    left &= mask;
    right &= mask;
    result &= mask;
    const std::uint64_t subtrahend = static_cast<std::uint64_t>(right) + borrow;
    const std::int64_t signed_left =
        (left & sign) != 0u ? static_cast<std::int64_t>(left) -
            (std::int64_t{1} << width) : left;
    const std::int64_t signed_right =
        (right & sign) != 0u ? static_cast<std::int64_t>(right) -
            (std::int64_t{1} << width) : right;
    const std::int64_t signed_result = signed_left - signed_right - borrow;
    const std::int64_t signed_min = -(std::int64_t{1} << (width - 1u));
    const std::int64_t signed_max = (std::int64_t{1} << (width - 1u)) - 1;
    state.eflags &= ~0x8d5u;
    if (static_cast<std::uint64_t>(left) < subtrahend) state.eflags |= 0x001u;
    if (batch_even_parity(static_cast<std::uint8_t>(result))) state.eflags |= 0x004u;
    if (((left ^ right ^ result) & 0x010u) != 0u) state.eflags |= 0x010u;
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
    if (signed_result < signed_min || signed_result > signed_max) state.eflags |= 0x800u;
}

inline void batch_set_logic_flags(
    BatchLiftState& state,
    std::uint32_t result,
    unsigned width) {
    const std::uint32_t mask = batch_mask(width);
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    result &= mask;
    state.eflags &= ~0x8d5u;
    if (batch_even_parity(static_cast<std::uint8_t>(result))) state.eflags |= 0x004u;
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
}

inline void batch_set_inc_flags(
    BatchLiftState& state,
    std::uint32_t value,
    std::uint32_t result,
    unsigned width) {
    const std::uint32_t mask = batch_mask(width);
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    value &= mask;
    result &= mask;
    state.eflags &= ~0x8d4u;
    if (batch_even_parity(static_cast<std::uint8_t>(result))) state.eflags |= 0x004u;
    if (((value ^ 1u ^ result) & 0x010u) != 0u) state.eflags |= 0x010u;
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
    if (value == sign - 1u) state.eflags |= 0x800u;
}

inline void batch_set_dec_flags(
    BatchLiftState& state,
    std::uint32_t value,
    std::uint32_t result,
    unsigned width) {
    const std::uint32_t mask = batch_mask(width);
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    value &= mask;
    result &= mask;
    state.eflags &= ~0x8d4u;
    if (batch_even_parity(static_cast<std::uint8_t>(result))) state.eflags |= 0x004u;
    if (((value ^ 1u ^ result) & 0x010u) != 0u) state.eflags |= 0x010u;
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
    if (value == sign) state.eflags |= 0x800u;
}

inline void batch_set_neg_flags(
    BatchLiftState& state,
    std::uint32_t value,
    std::uint32_t result,
    unsigned width) {
    const std::uint32_t mask = batch_mask(width);
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    value &= mask;
    result &= mask;
    state.eflags &= ~0x8d5u;
    if (value != 0u) state.eflags |= 0x001u;
    if (batch_even_parity(static_cast<std::uint8_t>(result))) state.eflags |= 0x004u;
    if (((value ^ result) & 0x010u) != 0u) state.eflags |= 0x010u;
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
    if (value == sign) state.eflags |= 0x800u;
}

class BatchLiftMemory {
public:
    static constexpr std::uint32_t kStackBase = 0x70000000u;
    static constexpr std::uint32_t kEntryEsp = 0x70000200u;
    static constexpr std::uint32_t kReturnSentinel = 0xf00dcafeu;
    static constexpr std::size_t kStackBytes = 0x400;

    BatchLiftMemory() {
        regions_[0] = {kStackBase, kStackBytes, stack_.data(), true};
        region_count_ = 1;
        store32(kEntryEsp, kReturnSentinel);
    }

    bool map_region(
        std::uint32_t base,
        std::uint8_t* data,
        std::size_t size,
        bool writable) {
        if (data == nullptr || size == 0 || region_count_ >= regions_.size()) return false;
        const std::uint64_t end = static_cast<std::uint64_t>(base) + size;
        if (end > (std::uint64_t{1} << 32u)) return false;
        for (std::size_t index = 0; index < region_count_; ++index) {
            const std::uint64_t old_start = regions_[index].base;
            const std::uint64_t old_end = old_start + regions_[index].size;
            if (static_cast<std::uint64_t>(base) < old_end && old_start < end) return false;
        }
        regions_[region_count_++] = {base, size, data, writable};
        return true;
    }

    bool load8(std::uint32_t address, std::uint32_t& value) const {
        const Region* region = find_region(address, 1);
        if (region == nullptr) return false;
        value = region->data[address - region->base];
        return true;
    }

    bool load16(std::uint32_t address, std::uint32_t& value) const {
        const Region* region = find_region(address, 2);
        if (region == nullptr) return false;
        const std::size_t offset = address - region->base;
        value = static_cast<std::uint32_t>(region->data[offset]) |
            (static_cast<std::uint32_t>(region->data[offset + 1]) << 8u);
        return true;
    }

    bool load32(std::uint32_t address, std::uint32_t& value) const {
        const Region* region = find_region(address, 4);
        if (region == nullptr) return false;
        const std::size_t offset = address - region->base;
        value = static_cast<std::uint32_t>(region->data[offset]) |
            (static_cast<std::uint32_t>(region->data[offset + 1]) << 8u) |
            (static_cast<std::uint32_t>(region->data[offset + 2]) << 16u) |
            (static_cast<std::uint32_t>(region->data[offset + 3]) << 24u);
        return true;
    }

    bool store8(std::uint32_t address, std::uint32_t value) {
        Region* region = find_region(address, 1);
        if (region == nullptr || !region->writable) return false;
        region->data[address - region->base] = static_cast<std::uint8_t>(value);
        return true;
    }

    bool store16(std::uint32_t address, std::uint32_t value) {
        Region* region = find_region(address, 2);
        if (region == nullptr || !region->writable) return false;
        const std::size_t offset = address - region->base;
        region->data[offset] = static_cast<std::uint8_t>(value);
        region->data[offset + 1] = static_cast<std::uint8_t>(value >> 8u);
        return true;
    }

    bool store32(std::uint32_t address, std::uint32_t value) {
        Region* region = find_region(address, 4);
        if (region == nullptr || !region->writable) return false;
        const std::size_t offset = address - region->base;
        for (unsigned index = 0; index < 4; ++index) {
            region->data[offset + index] = static_cast<std::uint8_t>(value >> (index * 8u));
        }
        return true;
    }

private:
    struct Region {
        std::uint32_t base;
        std::size_t size;
        std::uint8_t* data;
        bool writable;
    };

    const Region* find_region(std::uint32_t address, std::size_t size) const {
        for (std::size_t index = 0; index < region_count_; ++index) {
            const Region& region = regions_[index];
            if (address < region.base) continue;
            const std::uint64_t offset = static_cast<std::uint64_t>(address) - region.base;
            if (offset + size <= region.size) return &region;
        }
        return nullptr;
    }

    Region* find_region(std::uint32_t address, std::size_t size) {
        for (std::size_t index = 0; index < region_count_; ++index) {
            Region& region = regions_[index];
            if (address < region.base) continue;
            const std::uint64_t offset = static_cast<std::uint64_t>(address) - region.base;
            if (offset + size <= region.size) return &region;
        }
        return nullptr;
    }

    std::array<Region, 8> regions_{};
    std::array<std::uint8_t, kStackBytes> stack_{};
    std::size_t region_count_ = 0;
};

inline bool batch_guest_call32(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t target,
    std::uint32_t return_address) {
    const std::uint32_t next_esp =
        static_cast<std::uint32_t>(state.regs[4] - 4u);
    if (!memory.store32(next_esp, return_address)) return false;
    state.regs[4] = next_esp;
    state.eip = target;
    return true;
}

inline bool batch_guest_return32(
    const BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t cleanup = 0u) {
    std::uint32_t return_address{};
    if (!memory.load32(state.regs[4], return_address)) return false;
    state.regs[4] = static_cast<std::uint32_t>(
        state.regs[4] + 4u + cleanup);
    state.eip = return_address;
    return true;
}
