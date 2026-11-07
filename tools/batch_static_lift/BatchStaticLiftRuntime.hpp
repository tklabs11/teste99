#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <condition_variable>
#include <cstring>
#include <cmath>
#include <limits>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#endif

enum class BatchLiftStatus {
    returned,
    invalid_memory,
    invalid_control_flow,
    unsupported_import,
    synchronization_error,
    invalid_x87_state,
    divide_error,
    unsupported_dependency,
};

class BatchLiftMemory;
struct BatchLiftState;

class BatchGuestImportDispatcher {
public:
    virtual ~BatchGuestImportDispatcher() = default;
    virtual BatchLiftStatus invoke_import(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const char* symbol,
        std::uint32_t iat_address) = 0;
    virtual const std::string& last_error() const = 0;
};

struct BatchLiftState {
    std::uint32_t regs[8]{};
    std::uint32_t xmm[8][4]{};
    std::uint64_t x87_stack[8]{};
    std::uint8_t x87_depth = 0;
    std::uint32_t eflags = 0;
    std::uint32_t eip = 0;
    std::uint32_t fs_base = 0;
    BatchGuestImportDispatcher* imports = nullptr;
    std::uint32_t last_error = 0;
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
        std::lock_guard<std::mutex> lock(memory_mutex_);
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

    bool is_writable(std::uint32_t address, std::size_t size) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        const Region* region = find_region(address, size);
        return region != nullptr && region->writable;
    }

    bool is_readable(std::uint32_t address, std::size_t size) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        return find_region(address, size) != nullptr;
    }

    bool load8(std::uint32_t address, std::uint32_t& value) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        const Region* region = find_region(address, 1);
        if (region == nullptr) return false;
        value = region->data[address - region->base];
        return true;
    }

    bool load16(std::uint32_t address, std::uint32_t& value) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        const Region* region = find_region(address, 2);
        if (region == nullptr) return false;
        const std::size_t offset = address - region->base;
        value = static_cast<std::uint32_t>(region->data[offset]) |
            (static_cast<std::uint32_t>(region->data[offset + 1]) << 8u);
        return true;
    }

    bool load32(std::uint32_t address, std::uint32_t& value) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        const Region* region = find_region(address, 4);
        if (region == nullptr) return false;
        const std::size_t offset = address - region->base;
        value = static_cast<std::uint32_t>(region->data[offset]) |
            (static_cast<std::uint32_t>(region->data[offset + 1]) << 8u) |
            (static_cast<std::uint32_t>(region->data[offset + 2]) << 16u) |
            (static_cast<std::uint32_t>(region->data[offset + 3]) << 24u);
        return true;
    }

    bool load64(std::uint32_t address, std::uint64_t& value) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        const Region* region = find_region(address, 8);
        if (region == nullptr) return false;
        const std::size_t offset = address - region->base;
        value = 0;
        for (unsigned index = 0; index < 8; ++index) {
            value |= static_cast<std::uint64_t>(region->data[offset + index])
                << (index * 8u);
        }
        return true;
    }

    bool store8(std::uint32_t address, std::uint32_t value) {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        Region* region = find_region(address, 1);
        if (region == nullptr || !region->writable) return false;
        region->data[address - region->base] = static_cast<std::uint8_t>(value);
        return true;
    }

    bool store16(std::uint32_t address, std::uint32_t value) {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        Region* region = find_region(address, 2);
        if (region == nullptr || !region->writable) return false;
        const std::size_t offset = address - region->base;
        region->data[offset] = static_cast<std::uint8_t>(value);
        region->data[offset + 1] = static_cast<std::uint8_t>(value >> 8u);
        return true;
    }

    bool store32(std::uint32_t address, std::uint32_t value) {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        Region* region = find_region(address, 4);
        if (region == nullptr || !region->writable) return false;
        const std::size_t offset = address - region->base;
        for (unsigned index = 0; index < 4; ++index) {
            region->data[offset + index] = static_cast<std::uint8_t>(value >> (index * 8u));
        }
        return true;
    }

    bool store64(std::uint32_t address, std::uint64_t value) {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        Region* region = find_region(address, 8);
        if (region == nullptr || !region->writable) return false;
        const std::size_t offset = address - region->base;
        for (unsigned index = 0; index < 8; ++index) {
            region->data[offset + index] =
                static_cast<std::uint8_t>(value >> (index * 8u));
        }
        return true;
    }

    bool exchange32(
        std::uint32_t address,
        std::uint32_t replacement,
        std::uint32_t& previous) {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        Region* region = find_region(address, 4);
        if (region == nullptr || !region->writable) return false;
        const std::size_t offset = address - region->base;
        previous = static_cast<std::uint32_t>(region->data[offset]) |
            (static_cast<std::uint32_t>(region->data[offset + 1]) << 8u) |
            (static_cast<std::uint32_t>(region->data[offset + 2]) << 16u) |
            (static_cast<std::uint32_t>(region->data[offset + 3]) << 24u);
        for (unsigned index = 0; index < 4; ++index) {
            region->data[offset + index] =
                static_cast<std::uint8_t>(replacement >> (index * 8u));
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

    std::array<Region, 16> regions_{};
    std::array<std::uint8_t, kStackBytes> stack_{};
    std::size_t region_count_ = 0;
    mutable std::mutex memory_mutex_;
};

inline bool batch_guest_xchg32(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t register_index,
    std::uint32_t address) {
    if (register_index >= 8u) return false;
    std::uint32_t previous{};
    if (!memory.exchange32(
            address, state.regs[register_index], previous)) {
        return false;
    }
    state.regs[register_index] = previous;
    return true;
}

inline bool batch_guest_movss_load(
    const BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t destination,
    std::uint32_t address) {
    std::uint32_t value{};
    if (destination >= 8u || !memory.load32(address, value)) return false;
    state.xmm[destination][0] = value;
    state.xmm[destination][1] = 0u;
    state.xmm[destination][2] = 0u;
    state.xmm[destination][3] = 0u;
    return true;
}

inline bool batch_guest_movss_store(
    BatchLiftMemory& memory,
    const BatchLiftState& state,
    std::uint32_t source,
    std::uint32_t address) {
    return source < 8u && memory.store32(address, state.xmm[source][0]);
}

inline bool batch_guest_movss_register_move(
    BatchLiftState& state,
    std::uint32_t destination,
    std::uint32_t source) {
    if (destination >= 8u || source >= 8u) return false;
    state.xmm[destination][0] = state.xmm[source][0];
    return true;
}

inline bool batch_guest_xorps(
    BatchLiftState& state,
    std::uint32_t destination,
    std::uint32_t source) {
    if (destination >= 8u || source >= 8u) return false;
    for (unsigned lane = 0; lane < 4u; ++lane) {
        state.xmm[destination][lane] ^= state.xmm[source][lane];
    }
    return true;
}

inline bool batch_guest_fld64(
    const BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t address) {
    if (state.x87_depth >= 8u) return false;
    std::uint64_t value{};
    if (!memory.load64(address, value)) return false;
    state.x87_stack[state.x87_depth++] = value;
    return true;
}

inline bool batch_guest_fstp64(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t address) {
    if (state.x87_depth == 0u) return false;
    const std::uint64_t value = state.x87_stack[state.x87_depth - 1u];
    if (!memory.store64(address, value)) return false;
    state.x87_stack[--state.x87_depth] = 0u;
    return true;
}

// This bounded path was differential-tested with x87 CW=0x027f (53-bit,
// round-to-nearest) and MXCSR=0x1f80. The guest state does not model changes
// to either control register or x87 exception/status flags.
inline bool batch_guest_fild32(const BatchLiftMemory& memory,
                              BatchLiftState& state, std::uint32_t address) {
    if (state.x87_depth >= 8u) return false;
    std::uint32_t raw{};
    if (!memory.load32(address, raw)) return false;
    const double value = static_cast<double>(static_cast<std::int32_t>(raw));
    std::uint64_t bits{};
    std::memcpy(&bits, &value, sizeof(bits));
    state.x87_stack[state.x87_depth++] = bits;
    return true;
}

inline bool batch_guest_x87_float32_arithmetic(const BatchLiftMemory& memory,
                                                BatchLiftState& state,
                                                std::uint32_t address,
                                                unsigned operation) {
    if (state.x87_depth == 0u) return false;
    std::uint32_t raw{};
    if (!memory.load32(address, raw)) return false;
    double top{};
    float source{};
    std::memcpy(&top, &state.x87_stack[state.x87_depth - 1u], sizeof(top));
    std::memcpy(&source, &raw, sizeof(source));
    const double result = operation == 1u ? top * static_cast<double>(source)
        : operation == 2u ? top / static_cast<double>(source)
        : top + static_cast<double>(source);
    std::memcpy(&state.x87_stack[state.x87_depth - 1u], &result, sizeof(result));
    return true;
}

inline bool batch_guest_fstp32(BatchLiftMemory& memory,
                               BatchLiftState& state, std::uint32_t address) {
    if (state.x87_depth == 0u) return false;
    double top{};
    std::memcpy(&top, &state.x87_stack[state.x87_depth - 1u], sizeof(top));
    const float result = static_cast<float>(top);
    std::uint32_t raw{};
    std::memcpy(&raw, &result, sizeof(raw));
    if (!memory.store32(address, raw)) return false;
    state.x87_stack[--state.x87_depth] = 0u;
    return true;
}

inline bool batch_guest_cvtss2si(BatchLiftState& state,
                                 std::uint32_t destination,
                                 std::uint32_t source) {
    if (destination >= 8u || source >= 8u) return false;
    float value{};
    std::memcpy(&value, &state.xmm[source][0], sizeof(value));
    const double rounded = std::nearbyint(static_cast<double>(value));
    state.regs[destination] = !std::isfinite(rounded) ||
        rounded < -2147483648.0 || rounded >= 2147483648.0
        ? 0x80000000u
        : static_cast<std::uint32_t>(static_cast<std::int32_t>(rounded));
    return true;
}

inline bool batch_guest_cvttss2si_memory(const BatchLiftMemory& memory,
                                         BatchLiftState& state,
                                         std::uint32_t destination,
                                         std::uint32_t address) {
    if (destination >= 8u) return false;
    std::uint32_t raw{};
    if (!memory.load32(address, raw)) return false;
    float value{};
    std::memcpy(&value, &raw, sizeof(value));
    const double truncated = std::trunc(static_cast<double>(value));
    state.regs[destination] = !std::isfinite(truncated) ||
        truncated < -2147483648.0 || truncated >= 2147483648.0
        ? 0x80000000u
        : static_cast<std::uint32_t>(static_cast<std::int32_t>(truncated));
    return true;
}

inline bool batch_guest_cvtsi2ss(BatchLiftState& state,
                                 std::uint32_t destination,
                                 std::uint32_t source) {
    if (destination >= 8u || source >= 8u) return false;
    const float value = static_cast<float>(static_cast<std::int32_t>(state.regs[source]));
    std::memcpy(&state.xmm[destination][0], &value, sizeof(value));
    return true;
}

inline bool batch_guest_ucomiss(BatchLiftState& state,
                                std::uint32_t left,
                                std::uint32_t right) {
    if (left >= 8u || right >= 8u) return false;
    float a{}, b{};
    std::memcpy(&a, &state.xmm[left][0], sizeof(a));
    std::memcpy(&b, &state.xmm[right][0], sizeof(b));
    state.eflags &= ~0x8c5u;
    if (std::isnan(a) || std::isnan(b)) state.eflags |= 0x045u;
    else if (a < b) state.eflags |= 0x001u;
    else if (a == b) state.eflags |= 0x040u;
    return true;
}

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

inline BatchLiftStatus batch_guest_import_call32(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    const char* symbol,
    std::uint32_t iat_address,
    std::uint32_t return_address) {
    if (state.imports == nullptr) return BatchLiftStatus::unsupported_import;
    if (!batch_guest_call32(memory, state, iat_address, return_address)) {
        return BatchLiftStatus::invalid_memory;
    }
    const BatchLiftStatus status = state.imports->invoke_import(
        memory, state, symbol, iat_address);
    if (status != BatchLiftStatus::returned) return status;
    if (state.eip != return_address) return BatchLiftStatus::invalid_control_flow;
    return BatchLiftStatus::returned;
}

struct GuestCriticalSection32 {
    std::uint32_t debug_info;
    std::int32_t lock_count;
    std::int32_t recursion_count;
    std::uint32_t owning_thread;
    std::uint32_t lock_semaphore;
    std::uint32_t spin_count;
};

static_assert(sizeof(GuestCriticalSection32) == 24u);
static_assert(offsetof(GuestCriticalSection32, debug_info) == 0x00u);
static_assert(offsetof(GuestCriticalSection32, lock_count) == 0x04u);
static_assert(offsetof(GuestCriticalSection32, recursion_count) == 0x08u);
static_assert(offsetof(GuestCriticalSection32, owning_thread) == 0x0cu);
static_assert(offsetof(GuestCriticalSection32, lock_semaphore) == 0x10u);
static_assert(offsetof(GuestCriticalSection32, spin_count) == 0x14u);

struct BatchGuestImportCall {
    std::string symbol;
    std::uint32_t iat_address;
    std::vector<std::uint32_t> arguments;
    std::uint32_t result{};
    std::uint32_t last_error{};
    std::uint32_t return_address{};
    std::uint32_t receiver{};
};

class BatchGuestRuntime final : public BatchGuestImportDispatcher {
public:
    ~BatchGuestRuntime() override {
#if defined(_WIN32)
        for (HANDLE handle : native_handles_) {
            if (handle != nullptr) CloseHandle(handle);
        }
#else
        std::lock_guard<std::mutex> lock(registry_mutex_);
        for (const auto& entry : handle_objects_) {
            if (entry.second->initial_owner
                && entry.second->initial_owner_thread
                    == std::this_thread::get_id()) {
                entry.second->initial_owner = false;
                entry.second->mutex.unlock();
            }
        }
#endif
    }

    BatchLiftStatus invoke_import(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const char* symbol,
        std::uint32_t iat_address) override {
        BatchGuestImportCall call{symbol, iat_address, {}};
        std::uint32_t return_address{};
        if (!memory.load32(state.regs[4], return_address)) {
            last_error_ = "import call return address is outside guest memory";
            return BatchLiftStatus::invalid_memory;
        }

        const std::uint32_t argument_count =
            import_argument_count(call.symbol);
        for (std::uint32_t index = 0; index < argument_count; ++index) {
            std::uint32_t argument{};
            if (!memory.load32(
                    state.regs[4] + 4u + index * 4u, argument)) {
                last_error_ = call.symbol
                    + " arguments are outside guest memory";
                calls_.push_back(std::move(call));
                return BatchLiftStatus::invalid_memory;
            }
            call.arguments.push_back(argument);
        }
        call.return_address = return_address;
        call.receiver = state.regs[6];
        calls_.push_back(call);
        last_error_.clear();

        if (call.symbol == "MSVCR90.dll!strncpy") {
            return strncpy_guest(memory, state, call);
        }
        if (call.symbol == "MSVCR90.dll!memset") {
            return memset_guest(memory, state, call);
        }
        if (call.symbol == "KERNEL32.dll!CreateMutexA") {
            return create_mutex(memory, state, call);
        }
        if (call.symbol == "KERNEL32.dll!CreateSemaphoreA") {
            return create_semaphore(memory, state, call);
        }
        if (call.symbol == "KERNEL32.dll!GetLastError") {
            state.regs[0] = state.last_error;
            calls_.back().result = state.regs[0];
            calls_.back().last_error = state.last_error;
            complete_import_call(state, return_address, 0u);
            return BatchLiftStatus::returned;
        }
        if (call.symbol == "KERNEL32.dll!InitializeCriticalSection") {
            return initialize_critical_section(memory, state, call);
        }
        if (call.symbol == "KERNEL32.dll!EnterCriticalSection") {
            return enter_critical_section(memory, state, call);
        }
        if (call.symbol == "KERNEL32.dll!LeaveCriticalSection") {
            return leave_critical_section(memory, state, call);
        }
        if (call.symbol == "KERNEL32.dll!DeleteCriticalSection") {
            return delete_critical_section(memory, state, call);
        }
        last_error_ = "unrecognized guest import: " + call.symbol;
        return BatchLiftStatus::unsupported_import;
    }

    const std::string& last_error() const override {
        return last_error_;
    }

    const std::vector<BatchGuestImportCall>& calls() const {
        return calls_;
    }

    std::uint32_t last_error_code() const {
        return last_error_code_;
    }

    bool same_kernel_object(
        std::uint32_t left_handle,
        std::uint32_t right_handle) const {
        std::lock_guard<std::mutex> lock(registry_mutex_);
        const auto left = handle_objects_.find(left_handle);
        const auto right = handle_objects_.find(right_handle);
        return left != handle_objects_.end()
            && right != handle_objects_.end()
            && left->second == right->second;
    }

    bool semaphore_state(
        std::uint32_t handle,
        std::uint32_t& count,
        std::uint32_t& maximum) const {
        std::lock_guard<std::mutex> lock(registry_mutex_);
        const auto found = handle_objects_.find(handle);
        if (found == handle_objects_.end()
            || found->second->type != KernelObjectType::semaphore) {
            return false;
        }
        count = found->second->semaphore_count;
        maximum = found->second->semaphore_maximum;
        return true;
    }

    bool has_critical_section(std::uint32_t guest_address) const {
        std::lock_guard<std::mutex> lock(registry_mutex_);
        return critical_sections_.find(guest_address) != critical_sections_.end();
    }

private:
    enum class KernelObjectType {
        mutex,
        semaphore,
    };

    struct KernelObject {
        explicit KernelObject(KernelObjectType object_type)
            : type(object_type) {}

        KernelObjectType type;
        std::string name;
        bool inheritable{};
        bool initial_owner{};
        std::thread::id initial_owner_thread{};
        std::uint32_t semaphore_count{};
        std::uint32_t semaphore_maximum{};
        std::recursive_mutex mutex;
        std::mutex semaphore_mutex;
        std::condition_variable semaphore_changed;
    };

    struct NativeCriticalSection {
        std::recursive_mutex mutex;
        std::thread::id owner{};
        std::uint32_t recursion_count{};
        std::uint32_t waiting_entrants{};
    };

    static std::uint32_t import_argument_count(const std::string& symbol) {
        if (symbol == "KERNEL32.dll!InitializeCriticalSection"
            || symbol == "KERNEL32.dll!EnterCriticalSection"
            || symbol == "KERNEL32.dll!LeaveCriticalSection"
            || symbol == "KERNEL32.dll!DeleteCriticalSection") {
            return 1u;
        }
        if (symbol == "KERNEL32.dll!CreateMutexA") return 3u;
        if (symbol == "MSVCR90.dll!strncpy") return 3u;
        if (symbol == "MSVCR90.dll!memset") return 3u;
        if (symbol == "KERNEL32.dll!CreateSemaphoreA") return 4u;
        return 0u;
    }

    void set_guest_error(
        BatchLiftState& state,
        std::uint32_t error,
        std::string diagnostic = {}) {
        state.last_error = error;
        last_error_code_ = error;
        last_error_ = std::move(diagnostic);
#if defined(_WIN32)
        SetLastError(error);
#endif
    }

    static bool read_guest_string(
        const BatchLiftMemory& memory,
        std::uint32_t address,
        std::string& value) {
        value.clear();
        if (address == 0u) return false;
        for (std::uint32_t offset = 0; offset < 260u; ++offset) {
            if (address > std::numeric_limits<std::uint32_t>::max() - offset) {
                return false;
            }
            std::uint32_t byte{};
            if (!memory.load8(address + offset, byte)) return false;
            if (byte == 0u) return true;
            value.push_back(static_cast<char>(byte));
        }
        return false;
    }

    static bool read_security_attributes(
        const BatchLiftMemory& memory,
        std::uint32_t address,
        bool& present,
        bool& inheritable) {
        present = address != 0u;
        inheritable = false;
        if (!present) return true;
        std::uint32_t length{};
        std::uint32_t descriptor{};
        std::uint32_t inherit{};
        if (!memory.load32(address, length)
            || !memory.load32(address + 4u, descriptor)
            || !memory.load32(address + 8u, inherit)) {
            return false;
        }
        if (length != 12u || descriptor != 0u || inherit > 1u) {
            return false;
        }
        inheritable = inherit != 0u;
        return true;
    }

    static void complete_api_call(
        BatchLiftState& state,
        BatchGuestImportCall& call,
        std::uint32_t return_address,
        std::uint32_t argument_bytes,
        std::uint32_t result) {
        state.regs[0] = result;
        call.result = result;
        call.last_error = state.last_error;
        complete_import_call(state, return_address, argument_bytes);
    }

    BatchLiftStatus memset_guest(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        const std::uint32_t destination = call.arguments[0];
        const std::uint8_t value = static_cast<std::uint8_t>(call.arguments[1]);
        const std::uint32_t count = call.arguments[2];
        std::uint32_t return_address{};
        if (!memory.load32(state.regs[4], return_address)) {
            last_error_ = "memset return address is outside guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        if (count != 0u
            && (static_cast<std::uint64_t>(destination) + count
                    > (std::uint64_t{1} << 32u)
                || !memory.is_writable(destination, count))) {
            last_error_ = "memset destination is outside writable guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        for (std::uint32_t offset = 0; offset < count; ++offset) {
            if (!memory.store8(destination + offset, value)) {
                last_error_ = "memset destination changed after validation";
                return BatchLiftStatus::invalid_memory;
            }
        }
        complete_api_call(state, calls_.back(), return_address, 0u, destination);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus strncpy_guest(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        const std::uint32_t destination = call.arguments[0];
        const std::uint32_t source = call.arguments[1];
        const std::uint32_t count = call.arguments[2];
        std::uint32_t return_address{};
        if (!memory.load32(state.regs[4], return_address)) {
            last_error_ = "strncpy return address is outside guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        if (count != 0u
            && (static_cast<std::uint64_t>(destination) + count
                    > (std::uint64_t{1} << 32u)
                || !memory.is_writable(destination, count))) {
            last_error_ = "strncpy destination is outside writable guest memory";
            return BatchLiftStatus::invalid_memory;
        }

        bool terminated = false;
        std::uint32_t source_bytes = count;
        for (std::uint32_t offset = 0; offset < count; ++offset) {
            if (source > std::numeric_limits<std::uint32_t>::max() - offset) {
                last_error_ = "strncpy source address overflows guest address space";
                return BatchLiftStatus::invalid_memory;
            }
            std::uint32_t byte{};
            if (!memory.load8(source + offset, byte)) {
                last_error_ = "strncpy source exceeds mapped guest memory";
                return BatchLiftStatus::invalid_memory;
            }
            if (byte == 0u) {
                source_bytes = offset + 1u;
                terminated = true;
                break;
            }
        }
        for (std::uint32_t offset = 0; offset < source_bytes; ++offset) {
            std::uint32_t byte{};
            if (!memory.load8(source + offset, byte)
                || !memory.store8(destination + offset, byte)) {
                last_error_ = "strncpy guest memory changed after validation";
                return BatchLiftStatus::invalid_memory;
            }
        }
        if (terminated) {
            for (std::uint32_t offset = source_bytes; offset < count; ++offset) {
                if (!memory.store8(destination + offset, 0u)) {
                    last_error_ = "strncpy destination changed after validation";
                    return BatchLiftStatus::invalid_memory;
                }
            }
        }
        complete_api_call(
            state, calls_.back(), return_address, 0u, destination);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus create_mutex(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        std::uint32_t return_address{};
        if (!memory.load32(state.regs[4], return_address)) {
            last_error_ = "CreateMutexA return address is outside guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        bool attributes_present{};
        bool inheritable{};
        if (!read_security_attributes(
                memory, call.arguments[0], attributes_present, inheritable)) {
            set_guest_error(
                state, 87u,
                "CreateMutexA supports only a valid x86 SECURITY_ATTRIBUTES "
                "with a null security descriptor");
            complete_api_call(
                state, calls_.back(), return_address, 12u, 0u);
            return BatchLiftStatus::returned;
        }

        std::string name;
        const std::uint32_t name_address = call.arguments[2];
        if (name_address != 0u
            && !read_guest_string(memory, name_address, name)) {
            last_error_ = "CreateMutexA name is outside mapped guest memory "
                "or exceeds MAX_PATH";
            return BatchLiftStatus::invalid_memory;
        }
        if (name_address != 0u && name.empty()) {
            set_guest_error(state, 123u, "CreateMutexA rejected an empty name");
            complete_api_call(
                state, calls_.back(), return_address, 12u, 0u);
            return BatchLiftStatus::returned;
        }

        const auto existing = name.empty()
            ? std::shared_ptr<KernelObject>{}
            : find_named_object(name);
        if (existing && existing->type != KernelObjectType::mutex) {
            set_guest_error(
                state, 6u,
                "CreateMutexA name is already used by another object type");
            complete_api_call(
                state, calls_.back(), return_address, 12u, 0u);
            return BatchLiftStatus::returned;
        }

        std::shared_ptr<KernelObject> object = existing;
        bool already_exists = static_cast<bool>(existing);
        std::uint32_t handle{};
#if defined(_WIN32)
        SetLastError(0u);
        SECURITY_ATTRIBUTES native_attributes{};
        native_attributes.nLength = sizeof(native_attributes);
        native_attributes.bInheritHandle = inheritable ? TRUE : FALSE;
        HANDLE native_handle = CreateMutexA(
            attributes_present ? &native_attributes : nullptr,
            call.arguments[1] != 0u ? TRUE : FALSE,
            name.empty() ? nullptr : name.c_str());
        const std::uint32_t native_error = GetLastError();
        last_error_code_ = native_error;
        state.last_error = native_error;
        if (native_handle != nullptr) {
            handle = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(native_handle));
            native_handles_.push_back(native_handle);
            already_exists = native_error == 183u;
            if (!object) {
                object = std::make_shared<KernelObject>(
                    KernelObjectType::mutex);
                object->name = name;
                object->inheritable = inheritable;
            }
        }
#else
        if (already_exists) {
            handle = allocate_guest_handle(object);
        } else {
            object = std::make_shared<KernelObject>(KernelObjectType::mutex);
            object->name = name;
            object->inheritable = inheritable;
            if (call.arguments[1] != 0u) {
                object->mutex.lock();
                object->initial_owner = true;
                object->initial_owner_thread = std::this_thread::get_id();
            }
            handle = allocate_guest_handle(object);
        }
        last_error_code_ = already_exists ? 183u : 0u;
        state.last_error = last_error_code_;
#endif
        if (handle != 0u) {
            remember_handle(handle, object);
            if (!name.empty() && !existing) {
                remember_named_object(name, object);
            }
        }
        if (handle == 0u && state.last_error == 0u) {
            set_guest_error(state, 8u, "CreateMutexA failed to allocate a handle");
        } else {
            last_error_ = already_exists
                ? "CreateMutexA opened an existing named mutex"
                : std::string{};
        }
        complete_api_call(
            state, calls_.back(), return_address, 12u, handle);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus create_semaphore(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        std::uint32_t return_address{};
        if (!memory.load32(state.regs[4], return_address)) {
            last_error_ = "CreateSemaphoreA return address is outside guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        bool attributes_present{};
        bool inheritable{};
        if (!read_security_attributes(
                memory, call.arguments[0], attributes_present, inheritable)) {
            set_guest_error(
                state, 87u,
                "CreateSemaphoreA supports only a valid x86 "
                "SECURITY_ATTRIBUTES with a null security descriptor");
            complete_api_call(
                state, calls_.back(), return_address, 16u, 0u);
            return BatchLiftStatus::returned;
        }

        const std::uint32_t initial_count = call.arguments[1];
        const std::uint32_t maximum_count = call.arguments[2];
        std::string name;
        const std::uint32_t name_address = call.arguments[3];
        if (name_address != 0u
            && !read_guest_string(memory, name_address, name)) {
            last_error_ = "CreateSemaphoreA name is outside mapped guest memory "
                "or exceeds MAX_PATH";
            return BatchLiftStatus::invalid_memory;
        }
        if (maximum_count == 0u
            || maximum_count > static_cast<std::uint32_t>(
                std::numeric_limits<std::int32_t>::max())
            || initial_count > maximum_count
            || (name_address != 0u && name.empty())) {
            set_guest_error(
                state, name_address != 0u && name.empty() ? 123u : 87u,
                "CreateSemaphoreA received invalid counts or an empty name");
            complete_api_call(
                state, calls_.back(), return_address, 16u, 0u);
            return BatchLiftStatus::returned;
        }

        const auto existing = name.empty()
            ? std::shared_ptr<KernelObject>{}
            : find_named_object(name);
        if (existing && existing->type != KernelObjectType::semaphore) {
            set_guest_error(
                state, 6u,
                "CreateSemaphoreA name is already used by another object type");
            complete_api_call(
                state, calls_.back(), return_address, 16u, 0u);
            return BatchLiftStatus::returned;
        }

        std::shared_ptr<KernelObject> object = existing;
        const bool already_exists = static_cast<bool>(existing);
        std::uint32_t handle{};
#if defined(_WIN32)
        SetLastError(0u);
        SECURITY_ATTRIBUTES native_attributes{};
        native_attributes.nLength = sizeof(native_attributes);
        native_attributes.bInheritHandle = inheritable ? TRUE : FALSE;
        HANDLE native_handle = CreateSemaphoreA(
            attributes_present ? &native_attributes : nullptr,
            static_cast<LONG>(initial_count),
            static_cast<LONG>(maximum_count),
            name.empty() ? nullptr : name.c_str());
        const std::uint32_t native_error = GetLastError();
        last_error_code_ = native_error;
        state.last_error = native_error;
        if (native_handle != nullptr) {
            handle = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(native_handle));
            native_handles_.push_back(native_handle);
            if (!object) {
                object = std::make_shared<KernelObject>(
                    KernelObjectType::semaphore);
                object->name = name;
                object->inheritable = inheritable;
                object->semaphore_count = initial_count;
                object->semaphore_maximum = maximum_count;
            }
        }
#else
        if (already_exists) {
            handle = allocate_guest_handle(object);
        } else {
            object = std::make_shared<KernelObject>(
                KernelObjectType::semaphore);
            object->name = name;
            object->inheritable = inheritable;
            object->semaphore_count = initial_count;
            object->semaphore_maximum = maximum_count;
            handle = allocate_guest_handle(object);
        }
        last_error_code_ = already_exists ? 183u : 0u;
        state.last_error = last_error_code_;
#endif
        if (handle != 0u) {
            remember_handle(handle, object);
            if (!name.empty() && !existing) {
                remember_named_object(name, object);
            }
        }
        if (handle == 0u && state.last_error == 0u) {
            set_guest_error(
                state, 8u, "CreateSemaphoreA failed to allocate a handle");
        } else {
            last_error_ = already_exists
                ? "CreateSemaphoreA opened an existing named semaphore"
                : std::string{};
        }
        complete_api_call(
            state, calls_.back(), return_address, 16u, handle);
        return BatchLiftStatus::returned;
    }

    std::shared_ptr<KernelObject> find_named_object(
        const std::string& name) const {
        std::lock_guard<std::mutex> lock(registry_mutex_);
        const auto found = named_objects_.find(name);
        return found == named_objects_.end() ? nullptr : found->second.lock();
    }

    void remember_named_object(
        const std::string& name,
        const std::shared_ptr<KernelObject>& object) {
        std::lock_guard<std::mutex> lock(registry_mutex_);
        named_objects_[name] = object;
    }

    void remember_handle(
        std::uint32_t handle,
        const std::shared_ptr<KernelObject>& object) {
        std::lock_guard<std::mutex> lock(registry_mutex_);
        handle_objects_[handle] = object;
    }

    std::uint32_t allocate_guest_handle(
        const std::shared_ptr<KernelObject>& object) {
        std::lock_guard<std::mutex> lock(registry_mutex_);
        if (next_guest_handle_ == 0u) return 0u;
        const std::uint32_t handle = next_guest_handle_++;
        handle_objects_[handle] = object;
        return handle;
    }

    static bool valid_critical_section_memory(
        const BatchLiftMemory& memory,
        std::uint32_t address) {
        return address != 0u
            && memory.is_writable(address, sizeof(GuestCriticalSection32));
    }

    static bool write_critical_section(
        BatchLiftMemory& memory,
        std::uint32_t address,
        std::uint32_t debug_info,
        std::int32_t lock_count,
        std::uint32_t recursion_count,
        std::uint32_t owning_thread) {
        return memory.store32(address, debug_info)
            && memory.store32(address + 4u, static_cast<std::uint32_t>(lock_count))
            && memory.store32(address + 8u, recursion_count)
            && memory.store32(address + 12u, owning_thread)
            && memory.store32(address + 16u, 0u)
            && memory.store32(address + 20u, 0u);
    }

    static void complete_import_call(
        BatchLiftState& state,
        std::uint32_t return_address,
        std::uint32_t argument_bytes) {
        state.regs[4] += 4u + argument_bytes;
        state.eip = return_address;
    }

    BatchLiftStatus initialize_critical_section(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        const std::uint32_t address = call.arguments[0];
        std::uint32_t return_address{};
        if (!valid_critical_section_memory(memory, address)
            || !memory.load32(state.regs[4], return_address)) {
            last_error_ = "InitializeCriticalSection received an invalid guest address";
            return BatchLiftStatus::invalid_memory;
        }
        auto section = std::make_shared<NativeCriticalSection>();
        {
            std::lock_guard<std::mutex> lock(registry_mutex_);
            if (critical_sections_.find(address) != critical_sections_.end()) {
                last_error_ = "InitializeCriticalSection called twice without DeleteCriticalSection";
                return BatchLiftStatus::synchronization_error;
            }
            if (!write_critical_section(memory, address, 0u, -1, 0u, 0u)) {
                last_error_ = "could not initialize the x86 guest critical-section layout";
                return BatchLiftStatus::invalid_memory;
            }
            critical_sections_.emplace(address, std::move(section));
        }
        complete_import_call(state, return_address, 4u);
        return BatchLiftStatus::returned;
    }

    std::shared_ptr<NativeCriticalSection> find_critical_section(
        std::uint32_t address) const {
        std::lock_guard<std::mutex> lock(registry_mutex_);
        const auto found = critical_sections_.find(address);
        return found == critical_sections_.end() ? nullptr : found->second;
    }

    std::uint32_t guest_thread_id(std::thread::id thread) {
        const auto found = guest_thread_ids_.find(thread);
        if (found != guest_thread_ids_.end()) return found->second;
        const std::uint32_t id = next_guest_thread_id_++;
        guest_thread_ids_.emplace(thread, id);
        return id;
    }

    BatchLiftStatus enter_critical_section(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        const std::uint32_t address = call.arguments[0];
        std::uint32_t return_address{};
        if (!valid_critical_section_memory(memory, address)
            || !memory.load32(state.regs[4], return_address)) {
            last_error_ = "EnterCriticalSection received an invalid guest address";
            return BatchLiftStatus::invalid_memory;
        }
        std::shared_ptr<NativeCriticalSection> section;
        {
            std::lock_guard<std::mutex> lock(registry_mutex_);
            const auto found = critical_sections_.find(address);
            if (found == critical_sections_.end()) {
                last_error_ = "EnterCriticalSection called before initialization";
                return BatchLiftStatus::synchronization_error;
            }
            section = found->second;
            ++section->waiting_entrants;
        }
        section->mutex.lock();
        {
            std::lock_guard<std::mutex> lock(registry_mutex_);
            --section->waiting_entrants;
            section->owner = std::this_thread::get_id();
            ++section->recursion_count;
            if (!write_critical_section(
                    memory, address, 0u,
                    static_cast<std::int32_t>(section->recursion_count - 1u),
                    section->recursion_count,
                    guest_thread_id(section->owner))) {
                --section->recursion_count;
                if (section->recursion_count == 0u) section->owner = {};
                section->mutex.unlock();
                last_error_ = "could not update the x86 guest critical-section layout";
                return BatchLiftStatus::invalid_memory;
            }
        }
        complete_import_call(state, return_address, 4u);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus leave_critical_section(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        const std::uint32_t address = call.arguments[0];
        std::uint32_t return_address{};
        if (!valid_critical_section_memory(memory, address)
            || !memory.load32(state.regs[4], return_address)) {
            last_error_ = "LeaveCriticalSection received an invalid guest address";
            return BatchLiftStatus::invalid_memory;
        }
        std::shared_ptr<NativeCriticalSection> section;
        {
            std::lock_guard<std::mutex> lock(registry_mutex_);
            const auto found = critical_sections_.find(address);
            if (found == critical_sections_.end()) {
                last_error_ = "LeaveCriticalSection called before initialization";
                return BatchLiftStatus::synchronization_error;
            }
            section = found->second;
            if (section->owner != std::this_thread::get_id()
                || section->recursion_count == 0u) {
                last_error_ = "LeaveCriticalSection called by a non-owner";
                return BatchLiftStatus::synchronization_error;
            }
            --section->recursion_count;
            if (section->recursion_count == 0u) section->owner = {};
            if (!write_critical_section(
                    memory, address, 0u,
                    section->recursion_count == 0u
                        ? -1
                        : static_cast<std::int32_t>(
                            section->recursion_count - 1u),
                    section->recursion_count,
                    section->recursion_count == 0u
                        ? 0u
                        : guest_thread_id(section->owner))) {
                ++section->recursion_count;
                section->owner = std::this_thread::get_id();
                last_error_ = "could not update the x86 guest critical-section layout";
                return BatchLiftStatus::invalid_memory;
            }
        }
        section->mutex.unlock();
        complete_import_call(state, return_address, 4u);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus delete_critical_section(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        const std::uint32_t address = call.arguments[0];
        std::uint32_t return_address{};
        if (!valid_critical_section_memory(memory, address)
            || !memory.load32(state.regs[4], return_address)) {
            last_error_ = "DeleteCriticalSection received an invalid guest address";
            return BatchLiftStatus::invalid_memory;
        }
        {
            std::lock_guard<std::mutex> lock(registry_mutex_);
            const auto found = critical_sections_.find(address);
            if (found == critical_sections_.end()) {
                last_error_ = "DeleteCriticalSection called before initialization";
                return BatchLiftStatus::synchronization_error;
            }
            if (found->second->recursion_count != 0u
                || found->second->waiting_entrants != 0u) {
                last_error_ = "DeleteCriticalSection called while in use";
                return BatchLiftStatus::synchronization_error;
            }
            critical_sections_.erase(found);
            if (!write_critical_section(memory, address, 0u, 0, 0u, 0u)) {
                last_error_ = "could not clear the deleted x86 guest critical section";
                return BatchLiftStatus::invalid_memory;
            }
        }
        complete_import_call(state, return_address, 4u);
        return BatchLiftStatus::returned;
    }

    mutable std::mutex registry_mutex_;
    std::unordered_map<std::uint32_t, std::shared_ptr<NativeCriticalSection>>
        critical_sections_;
    std::unordered_map<std::thread::id, std::uint32_t> guest_thread_ids_;
    std::uint32_t next_guest_thread_id_ = 1u;
    std::vector<BatchGuestImportCall> calls_;
    std::string last_error_;
    std::uint32_t last_error_code_{};
    mutable std::unordered_map<std::string, std::weak_ptr<KernelObject>>
        named_objects_;
    std::unordered_map<std::uint32_t, std::shared_ptr<KernelObject>>
        handle_objects_;
    std::uint32_t next_guest_handle_ = 0xe0000001u;
#if defined(_WIN32)
    std::vector<HANDLE> native_handles_;
#endif
};
