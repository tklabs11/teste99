#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <condition_variable>
#include <cstring>
#include <cmath>
#include <deque>
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
    debug_trap,
};

class BatchLiftMemory;
struct BatchLiftState;

// Every lifted body records itself here as it starts. A walk that stops deep in
// engine code names the failing instruction, and this ring says which bodies it
// came through, so a fragment reached by the wrong chain is visible evidence
// instead of a guess. Bounded: the oldest entries are overwritten.
inline constexpr std::size_t kGuestBodyTraceCapacity = 128;

struct BatchGuestBodyTraceState {
    std::uint32_t entries[kGuestBodyTraceCapacity]{};
    std::uint64_t total = 0;

    void note(std::uint32_t entry) {
        entries[total % kGuestBodyTraceCapacity] = entry;
        ++total;
    }
};

inline BatchGuestBodyTraceState batch_guest_body_trace{};

inline void batch_guest_note_body(std::uint32_t entry) {
    batch_guest_body_trace.note(entry);
}

// The guest instruction that owns the next memory access. The lifter emits an
// assignment before every instruction that touches memory, so a fault names the
// instruction that made the access instead of only the address it reached.
inline std::uint32_t batch_guest_pc = 0u;

// Fills `out` (oldest first) and returns how many entries were written.
inline std::size_t batch_guest_body_trace_read(std::uint32_t* out,
                                               std::size_t capacity) {
    const std::size_t available = batch_guest_body_trace.total
            < kGuestBodyTraceCapacity
        ? static_cast<std::size_t>(batch_guest_body_trace.total)
        : kGuestBodyTraceCapacity;
    const std::size_t count = available < capacity ? available : capacity;
    const std::uint64_t first = batch_guest_body_trace.total - count;
    for (std::size_t index = 0; index < count; ++index) {
        out[index] =
            batch_guest_body_trace
                .entries[(first + index) % kGuestBodyTraceCapacity];
    }
    return count;
}

inline bool batch_guest_call32(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t target,
    std::uint32_t return_address);

class BatchGuestImportDispatcher {
public:
    virtual ~BatchGuestImportDispatcher() = default;
    virtual BatchLiftStatus invoke_import(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const char* symbol,
        std::uint32_t iat_address) = 0;
    virtual const std::string& last_error() const = 0;
    // Indirect CALL r32: the target is only known at runtime, so the dispatcher
    // owns the lookup. Implementations that cannot resolve it must fail closed.
    virtual BatchLiftStatus invoke_guest_call(
        BatchLiftMemory&, BatchLiftState&, std::uint32_t, std::uint32_t) {
        return BatchLiftStatus::unsupported_dependency;
    }
    // Indirect tail jump: the target is only known at runtime and no return
    // address is pushed, so the callee returns straight to this body's caller.
    virtual BatchLiftStatus invoke_guest_tail_call(
        BatchLiftMemory&, BatchLiftState&, std::uint32_t) {
        return BatchLiftStatus::unsupported_dependency;
    }
};

struct BatchLiftState {
    std::uint32_t regs[8]{};
    std::uint32_t xmm[8][4]{};
    std::uint64_t x87_stack[8]{};
    std::uint8_t x87_depth = 0;
    std::uint32_t x87_top = 0;
    std::uint32_t eflags = 0;
    // x87 control word as MSVC initializes it. _controlfp_s reads and writes it.
    std::uint32_t x87_control_word = 0x027fu;
    // C0-C3 and TOP of the x87 status word; FNSTSW reports it.
    std::uint32_t x87_status = 0u;
    // CRT shim state that has no guest address of its own.
    std::uint32_t app_type = 0u;
    std::uint32_t unhandled_filter = 0u;
    std::uint32_t user_matherr = 0u;
    std::uint32_t thread_locale = 0u;
    // The guest CRT records the last registered exit handler.
    std::uint32_t exit_handler = 0u;
    std::uint32_t eip = 0;
    std::uint32_t fs_base = 0;
    BatchGuestImportDispatcher* imports = nullptr;
    std::uint32_t last_error = 0;
    // Reads of RDTSC in this run, so the modelled counter advances once per
    // read instead of following the host clock.
    std::uint64_t rdtsc_reads = 0;
    // The same idea for the two Win32 time sources the guest exposes.
    std::uint64_t tick_reads = 0;
    std::uint64_t qpc_reads = 0;
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

// ADC adds the incoming carry, so the addend the flag formulas see is
// right + carry rather than right.
inline void batch_set_adc_flags(
    BatchLiftState& state,
    std::uint32_t left,
    std::uint32_t right,
    std::uint32_t carry,
    std::uint32_t result,
    unsigned width) {
    const std::uint32_t mask = batch_mask(width);
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    left &= mask;
    right &= mask;
    result &= mask;
    const std::uint32_t addend =
        static_cast<std::uint32_t>((right + carry) & mask);
    state.eflags &= ~0x8d5u;
    if (static_cast<std::uint64_t>(left) + right + carry > mask) {
        state.eflags |= 0x001u;
    }
    if (batch_even_parity(static_cast<std::uint8_t>(result))) state.eflags |= 0x004u;
    if (((left ^ right ^ result) & 0x010u) != 0u) state.eflags |= 0x010u;
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
    if (((~(left ^ addend) & (left ^ result)) & sign) != 0u) {
        state.eflags |= 0x800u;
    }
}

inline void batch_set_logic_flags(
    BatchLiftState& state,
    std::uint32_t result,
    unsigned width) {    const std::uint32_t mask = batch_mask(width);
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    result &= mask;
    state.eflags &= ~0x8d5u;
    if (batch_even_parity(static_cast<std::uint8_t>(result))) state.eflags |= 0x004u;
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
}

// SHL semantics: CF is the last bit shifted out, SF/ZF/PF come from the
// result. OF is defined only for a count of one; for larger counts the x86
// manual leaves it undefined, so it is preserved instead of invented.
// SHRD semantics: the count is masked to five bits (four for a 16-bit
// operand) and a zero count leaves both the destination and every flag alone.
// CF is the last bit shifted out of the destination, SF/ZF/PF come from the
// result, and OF is defined only for a count of one.
inline std::uint32_t batch_guest_shrd(
    BatchLiftState& state,
    std::uint32_t destination,
    std::uint32_t source,
    std::uint32_t count,
    unsigned width) {
    const unsigned mask = width == 32u ? 31u : 15u;
    const unsigned shift = static_cast<unsigned>(count) & mask;
    const std::uint32_t limit = batch_mask(width);
    const std::uint32_t value = destination & limit;
    if (shift == 0u) return value;
    const std::uint32_t moved = (value >> shift)
        | ((source & limit) << (width - shift));
    const std::uint32_t result = moved & limit;
    state.eflags &= ~0x8c5u;
    if (((value >> (shift - 1u)) & 1u) != 0u) state.eflags |= 0x001u;
    if (batch_even_parity(static_cast<std::uint8_t>(result))) {
        state.eflags |= 0x004u;
    }
    if (result == 0u) state.eflags |= 0x040u;
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    if ((result & sign) != 0u) state.eflags |= 0x080u;
    if (shift == 1u && (((value ^ result) & sign) != 0u)) {
        state.eflags |= 0x800u;
    }
    return result;
}

// Rotates touch only CF and OF: SF/ZF/PF keep the value they had. CF is the last
// bit moved and OF is defined only for a single-bit count, so a larger count
// clears it instead of inventing a value.
inline std::uint32_t batch_guest_rol(
    BatchLiftState& state, std::uint32_t value, std::uint32_t count) {
    const unsigned shift = static_cast<unsigned>(count) & 31u;
    if (shift == 0u) return value;
    const std::uint32_t result =
        (value << shift) | (value >> (32u - shift));
    state.eflags &= ~0x801u;
    if ((result & 1u) != 0u) state.eflags |= 0x001u;
    if (shift == 1u && (((result >> 31u) ^ (result & 1u)) & 1u) != 0u) {
        state.eflags |= 0x800u;
    }
    return result;
}

inline std::uint32_t batch_guest_ror(
    BatchLiftState& state, std::uint32_t value, std::uint32_t count) {
    const unsigned shift = static_cast<unsigned>(count) & 31u;
    if (shift == 0u) return value;
    const std::uint32_t result =
        (value >> shift) | (value << (32u - shift));
    state.eflags &= ~0x801u;
    if ((result & 0x80000000u) != 0u) state.eflags |= 0x001u;
    if (shift == 1u
            && (((result >> 31u) ^ ((result >> 30u) & 1u)) & 1u) != 0u) {
        state.eflags |= 0x800u;
    }
    return result;
}

inline std::uint32_t batch_guest_rcr(
    BatchLiftState& state, std::uint32_t value, std::uint32_t count) {
    const unsigned shift = static_cast<unsigned>(count) & 31u;
    if (shift == 0u) return value;
    std::uint32_t carry = (state.eflags & 0x001u) != 0u ? 1u : 0u;
    std::uint32_t result = value;
    for (unsigned step = 0; step < shift; ++step) {
        const std::uint32_t next = result & 1u;
        result = (result >> 1u) | (carry << 31u);
        carry = next;
    }
    state.eflags &= ~0x801u;
    if (carry != 0u) state.eflags |= 0x001u;
    if (shift == 1u && (((result >> 31u) ^ carry) & 1u) != 0u) {
        state.eflags |= 0x800u;
    }
    return result;
}

inline void batch_set_shl_flags(
    BatchLiftState& state,
    std::uint32_t value,
    unsigned count,
    std::uint32_t result,
    unsigned width) {
    if (count == 0u) return;
    const std::uint32_t mask = batch_mask(width);
    const std::uint32_t sign = std::uint32_t{1} << (width - 1u);
    value &= mask;
    result &= mask;
    state.eflags &= ~0x8c5u;
    if (count >= width
        || (value & (std::uint32_t{1} << (width - count))) != 0u) {
        state.eflags |= 0x001u;
    }
    if (batch_even_parity(static_cast<std::uint8_t>(result))) {
        state.eflags |= 0x004u;
    }
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & sign) != 0u) state.eflags |= 0x080u;
    if (count == 1u) {
        const bool carry = (state.eflags & 0x001u) != 0u;
        const bool high = (result & sign) != 0u;
        if (high != carry) state.eflags |= 0x800u;
    }
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
    // The guest stack. ESP starts 0x200 below the top so the entry frame has a
    // real thread's megabyte underneath it: the walk now descends into engine
    // code, and a fixture with a few hundred bytes reported the first deep call
    // as a fault. The top is unchanged, so the CRT lock's owner id and every
    // frame address in the harness keep their value.
    static constexpr std::uint32_t kStackBase = 0x6ff00400u;
    static constexpr std::uint32_t kEntryEsp = 0x70000200u;
    static constexpr std::uint32_t kReturnSentinel = 0xf00dcafeu;
    static constexpr std::size_t kStackBytes = 0x00100000u;

    BatchLiftMemory()
        : stack_(std::make_unique<std::uint8_t[]>(kStackBytes)) {
        regions_.push_back({kStackBase, kStackBytes, stack_.get(), true});
        store32(kEntryEsp, kReturnSentinel);
    }

    bool map_region(
        std::uint32_t base,
        std::uint8_t* data,
        std::size_t size,
        bool writable) {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        if (data == nullptr || size == 0) return false;
        const std::uint64_t end = static_cast<std::uint64_t>(base) + size;
        if (end > (std::uint64_t{1} << 32u)) return false;
        for (std::size_t index = 0; index < regions_.size(); ++index) {
            const std::uint64_t old_start = regions_[index].base;
            const std::uint64_t old_end = old_start + regions_[index].size;
            if (static_cast<std::uint64_t>(base) < old_end && old_start < end) return false;
        }
        // A deque grows without moving what is already stored, so the pointers
        // find_region hands out stay valid; a fixed array caps the map at one
        // region per image window plus the TEB, the probe table and the heap,
        // and a VirtualAlloc commit past that cap returns null to the guest.
        regions_.push_back({base, size, data, writable});
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

    // The first access that could not be served, so a failing walk names the
    // address instead of only the status. Only the first one is kept: it is the
    // one that caused the stop.
    struct FaultInfo {
        std::uint32_t address = 0;
        std::uint32_t size = 0;
        std::uint32_t pc = 0;
        // The closest mapped region at or below the address, so a log names the
        // class of the miss instead of only the address: the guest was inside
        // the image when it stepped off the end of a window, or it was nowhere
        // near one.
        std::uint32_t near_base = 0;
        std::uint32_t near_size = 0;
        bool write = false;
        bool valid = false;
    };

    FaultInfo first_fault() const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        return first_fault_;
    }

    void clear_fault() {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        first_fault_ = FaultInfo{};
    }

    // The mapped region that contains an address, for VirtualQuery.
    bool region_bounds(std::uint32_t address,
                       std::uint32_t& base,
                       std::uint32_t& size) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        const Region* region = find_region(address, 1u);
        if (region == nullptr) return false;
        base = region->base;
        size = static_cast<std::uint32_t>(region->size);
        return true;
    }

    bool load8(std::uint32_t address, std::uint32_t& value) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        const Region* region = find_region(address, 1);
        if (region == nullptr) { note_fault(address, 1, false); return false; }
        value = region->data[address - region->base];
        return true;
    }

    bool load16(std::uint32_t address, std::uint32_t& value) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        const Region* region = find_region(address, 2);
        if (region == nullptr) { note_fault(address, 2, false); return false; }
        const std::size_t offset = address - region->base;
        value = static_cast<std::uint32_t>(region->data[offset]) |
            (static_cast<std::uint32_t>(region->data[offset + 1]) << 8u);
        return true;
    }

    bool load32(std::uint32_t address, std::uint32_t& value) const {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        const Region* region = find_region(address, 4);
        if (region == nullptr) { note_fault(address, 4, false); return false; }
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
        if (region == nullptr) { note_fault(address, 8, false); return false; }
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
        if (region == nullptr || !region->writable) { note_fault(address, 1, true); return false; }
        region->data[address - region->base] = static_cast<std::uint8_t>(value);
        return true;
    }

    bool store16(std::uint32_t address, std::uint32_t value) {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        Region* region = find_region(address, 2);
        if (region == nullptr || !region->writable) { note_fault(address, 2, true); return false; }
        const std::size_t offset = address - region->base;
        region->data[offset] = static_cast<std::uint8_t>(value);
        region->data[offset + 1] = static_cast<std::uint8_t>(value >> 8u);
        return true;
    }

    bool store32(std::uint32_t address, std::uint32_t value) {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        Region* region = find_region(address, 4);
        if (region == nullptr || !region->writable) { note_fault(address, 4, true); return false; }
        const std::size_t offset = address - region->base;
        for (unsigned index = 0; index < 4; ++index) {
            region->data[offset + index] = static_cast<std::uint8_t>(value >> (index * 8u));
        }
        return true;
    }

    bool store64(std::uint32_t address, std::uint64_t value) {
        std::lock_guard<std::mutex> lock(memory_mutex_);
        Region* region = find_region(address, 8);
        if (region == nullptr || !region->writable) { note_fault(address, 8, true); return false; }
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
        if (region == nullptr || !region->writable) { note_fault(address, 4, true); return false; }
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
        for (std::size_t index = 0; index < regions_.size(); ++index) {
            const Region& region = regions_[index];
            if (address < region.base) continue;
            const std::uint64_t offset = static_cast<std::uint64_t>(address) - region.base;
            if (offset + size <= region.size) return &region;
        }
        return nullptr;
    }

    Region* find_region(std::uint32_t address, std::size_t size) {
        for (std::size_t index = 0; index < regions_.size(); ++index) {
            Region& region = regions_[index];
            if (address < region.base) continue;
            const std::uint64_t offset = static_cast<std::uint64_t>(address) - region.base;
            if (offset + size <= region.size) return &region;
        }
        return nullptr;
    }

    // The guest map grows with the number of windows the image exposes: the
    // stack plus one region per window, the TEB, the probe table, the heap and
    // every VirtualAlloc commit, so it is a deque rather than a fixed array.
    void note_fault(std::uint32_t address, std::size_t size, bool write) const {
        if (first_fault_.valid) return;
        first_fault_.address = address;
        first_fault_.size = static_cast<std::uint32_t>(size);
        first_fault_.pc = batch_guest_pc;
        first_fault_.write = write;
        first_fault_.valid = true;
        bool found = false;
        for (std::size_t index = 0; index < regions_.size(); ++index) {
            const Region& region = regions_[index];
            if (region.base > address) continue;
            if (found && region.base <= first_fault_.near_base) continue;
            found = true;
            first_fault_.near_base = region.base;
            first_fault_.near_size = static_cast<std::uint32_t>(region.size);
        }
    }

    std::deque<Region> regions_;
    // On the heap: the object is a local in every harness, and a megabyte of
    // stack in the fixture's own frame would be a hazard on the device.
    std::unique_ptr<std::uint8_t[]> stack_;
    mutable FaultInfo first_fault_{};
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

// MOVAPD copies a full 16 byte SIMD register. Register-to-register only: the
// memory forms are not needed by the recovered CRT closure.
inline bool batch_guest_movapd(
    BatchLiftState& state,
    std::uint32_t destination,
    std::uint32_t source) {
    if (destination >= 8u || source >= 8u) return false;
    for (unsigned lane = 0; lane < 4u; ++lane) {
        state.xmm[destination][lane] = state.xmm[source][lane];
    }
    return true;
}

inline bool batch_guest_pushfd(BatchLiftMemory& memory, BatchLiftState& state) {
    const std::uint32_t value = state.eflags | 0x00000002u;
    const std::uint32_t next = static_cast<std::uint32_t>(state.regs[4] - 4u);
    if (!memory.store32(next, value)) return false;
    state.regs[4] = next;
    return true;
}

inline bool batch_guest_popfd(
    const BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t value{};
    if (!memory.load32(state.regs[4], value)) return false;
    state.eflags = value | 0x00000002u;
    state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
    return true;
}

// The guest CPU is a fixed, documented x86-32 model: the CPUID identification
// bit is writable and basic leaf 1 reports SSE2. Host CPU features are never
// propagated, so every host and ARM64 device answers identically.
inline constexpr std::uint32_t kGuestCpuidMaxBasicLeaf = 1u;
inline constexpr std::uint32_t kGuestCpuidLeaf1Eax = 0x00000600u;
inline constexpr std::uint32_t kGuestCpuidLeaf1Ebx = 0x00000000u;
inline constexpr std::uint32_t kGuestCpuidLeaf1Ecx = 0x00000000u;
inline constexpr std::uint32_t kGuestCpuidLeaf1Edx = 0x04000000u;

inline BatchLiftStatus batch_guest_cpuid(BatchLiftState& state) {
    // regs follows the x86 ModRM order, so EBX is regs[3], not regs[1].
    constexpr std::size_t kEax = 0;
    constexpr std::size_t kEcx = 1;
    constexpr std::size_t kEdx = 2;
    constexpr std::size_t kEbx = 3;
    const std::uint32_t leaf = state.regs[kEax];
    if (leaf == 0u) {
        state.regs[kEax] = kGuestCpuidMaxBasicLeaf;
        state.regs[kEbx] = 0x756e6547u;  // "Genu"
        state.regs[kEdx] = 0x6c65746eu;  // "ntel"
        state.regs[kEcx] = 0x49656e69u;  // "ineI"
        return BatchLiftStatus::returned;
    }
    if (leaf == 1u) {
        state.regs[kEax] = kGuestCpuidLeaf1Eax;
        state.regs[kEbx] = kGuestCpuidLeaf1Ebx;
        state.regs[kEcx] = kGuestCpuidLeaf1Ecx;
        state.regs[kEdx] = kGuestCpuidLeaf1Edx;
        return BatchLiftStatus::returned;
    }
    return BatchLiftStatus::unsupported_dependency;
}

// The guest x87 stack is an eight-entry register file addressed from TOP, so
// FXCH, FADDP ST(i),ST(0) and FNSTSW report the same stack a real FPU does.
// Values are held as IEEE doubles: every x87 form this port lifts either loads
// a 32- or 64-bit operand or is an exact double operation, so the unit's 80-bit
// extended precision is never needed. The status word models C0-C3 and TOP;
// exception flags stay clear because the control word parks every exception
// (CW=0x027f). Integer forms wider than 53 bits are rounded to the nearest
// double, which is the one fidelity limit of this model.
inline constexpr std::uint32_t kX87StatusC0 = 0x0100u;
inline constexpr std::uint32_t kX87StatusC1 = 0x0200u;
inline constexpr std::uint32_t kX87StatusC2 = 0x0400u;
inline constexpr std::uint32_t kX87StatusC3 = 0x4000u;

inline double batch_guest_x87_st(const BatchLiftState& state, unsigned index) {
    const unsigned slot = (state.x87_top + index) & 7u;
    double value{};
    std::memcpy(&value, &state.x87_stack[slot], sizeof(value));
    return value;
}

inline void batch_guest_x87_set(
    BatchLiftState& state, unsigned index, double value) {
    const unsigned slot = (state.x87_top + index) & 7u;
    std::memcpy(&state.x87_stack[slot], &value, sizeof(value));
}

inline bool batch_guest_x87_push(BatchLiftState& state, double value) {
    if (state.x87_depth >= 8u) return false;
    state.x87_top = (state.x87_top + 7u) & 7u;
    ++state.x87_depth;
    batch_guest_x87_set(state, 0u, value);
    return true;
}

inline bool batch_guest_x87_pop(BatchLiftState& state) {
    if (state.x87_depth == 0u) return false;
    const double zero = 0.0;
    std::memcpy(&state.x87_stack[state.x87_top], &zero, sizeof(zero));
    state.x87_top = (state.x87_top + 1u) & 7u;
    --state.x87_depth;
    return true;
}

// operation: 0 add, 1 multiply, 2 divide (left / right),
//            3 subtract (left - right), 4 reversed subtract (right - left),
//            5 reversed divide (right / left).
inline double batch_guest_x87_compute(
    double left, double right, unsigned operation) {
    switch (operation) {
    case 1u: return left * right;
    case 2u: return left / right;
    case 3u: return left - right;
    case 4u: return right - left;
    case 5u: return right / left;
    default: return left + right;
    }
}

inline bool batch_guest_fld32(
    const BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t address) {
    std::uint32_t raw{};
    if (!memory.load32(address, raw)) return false;
    float value{};
    std::memcpy(&value, &raw, sizeof(value));
    return batch_guest_x87_push(state, static_cast<double>(value));
}

inline bool batch_guest_fld64(
    const BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t address) {
    std::uint64_t bits{};
    if (!memory.load64(address, bits)) return false;
    double value{};
    std::memcpy(&value, &bits, sizeof(value));
    return batch_guest_x87_push(state, value);
}

inline bool batch_guest_fld1(BatchLiftState& state) {
    return batch_guest_x87_push(state, 1.0);
}

inline bool batch_guest_fldz(BatchLiftState& state) {
    return batch_guest_x87_push(state, 0.0);
}

// FLD ST(i) pushes a copy, so the stack can grow by one.
inline bool batch_guest_fld_stack(BatchLiftState& state, unsigned index) {
    if (index >= state.x87_depth) return false;
    return batch_guest_x87_push(state, batch_guest_x87_st(state, index));
}

inline bool batch_guest_fst32(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t address) {
    if (state.x87_depth == 0u) return false;
    const float value = static_cast<float>(batch_guest_x87_st(state, 0u));
    std::uint32_t raw{};
    std::memcpy(&raw, &value, sizeof(raw));
    return memory.store32(address, raw);
}

// FSTP ST(i) stores ST(0) into ST(i) and then pops, so ST(0) alone is a plain
// pop and every other index keeps the value one slot lower.
inline bool batch_guest_fstp_stack(BatchLiftState& state, unsigned index) {
    if (state.x87_depth == 0u || index >= state.x87_depth) return false;
    const double top = batch_guest_x87_st(state, 0u);
    if (!batch_guest_x87_pop(state)) return false;
    if (index > 0u) batch_guest_x87_set(state, index - 1u, top);
    return true;
}

inline bool batch_guest_fstp64(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t address) {
    if (state.x87_depth == 0u) return false;
    const double value = batch_guest_x87_st(state, 0u);
    std::uint64_t bits{};
    std::memcpy(&bits, &value, sizeof(bits));
    if (!memory.store64(address, bits)) return false;
    return batch_guest_x87_pop(state);
}

inline bool batch_guest_fistp64(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t address) {
    if (state.x87_depth == 0u) return false;
    const double value = std::nearbyint(batch_guest_x87_st(state, 0u));
    const std::int64_t rounded =
        !std::isfinite(value) || value < -9223372036854775808.0
        || value >= 9223372036854775808.0
        ? INT64_MIN
        : static_cast<std::int64_t>(value);
    std::uint64_t bits{};
    std::memcpy(&bits, &rounded, sizeof(bits));
    if (!memory.store64(address, bits)) return false;
    return batch_guest_x87_pop(state);
}

inline bool batch_guest_x87_abs(BatchLiftState& state) {
    if (state.x87_depth == 0u) return false;
    batch_guest_x87_set(state, 0u, std::fabs(batch_guest_x87_st(state, 0u)));
    return true;
}

inline bool batch_guest_x87_chs(BatchLiftState& state) {
    if (state.x87_depth == 0u) return false;
    batch_guest_x87_set(state, 0u, -batch_guest_x87_st(state, 0u));
    return true;
}

inline bool batch_guest_x87_sqrt(BatchLiftState& state) {
    if (state.x87_depth == 0u) return false;
    batch_guest_x87_set(state, 0u, std::sqrt(batch_guest_x87_st(state, 0u)));
    return true;
}

inline bool batch_guest_x87_fxch(BatchLiftState& state, unsigned index) {
    if (index >= state.x87_depth) return false;
    if (index == 0u) return true;
    const double top = batch_guest_x87_st(state, 0u);
    batch_guest_x87_set(state, 0u, batch_guest_x87_st(state, index));
    batch_guest_x87_set(state, index, top);
    return true;
}

// The compare-class instructions write C0-C3 the same way; FCOMI/FCOMIP and
// FUCOMIP additionally copy C3/C2/C0 into ZF/PF/CF.
inline void batch_guest_x87_compare_flags(
    BatchLiftState& state, double left, double right) {
    state.x87_status &= ~(kX87StatusC0 | kX87StatusC2 | kX87StatusC3);
    if (std::isnan(left) || std::isnan(right)) {
        state.x87_status |=
            kX87StatusC0 | kX87StatusC2 | kX87StatusC3;
    } else if (left < right) {
        state.x87_status |= kX87StatusC0;
    } else if (left == right) {
        state.x87_status |= kX87StatusC3;
    }
}

inline void batch_guest_x87_compare_eflags(BatchLiftState& state) {
    state.eflags &= ~0x8d5u;
    if (state.x87_status & kX87StatusC3) state.eflags |= 0x040u;
    if (state.x87_status & kX87StatusC2) state.eflags |= 0x004u;
    if (state.x87_status & kX87StatusC0) state.eflags |= 0x001u;
}

inline bool batch_guest_x87_compare_value(
    BatchLiftState& state,
    double right,
    unsigned pops,
    bool to_eflags) {
    if (state.x87_depth == 0u) return false;
    batch_guest_x87_compare_flags(
        state, batch_guest_x87_st(state, 0u), right);
    if (to_eflags) batch_guest_x87_compare_eflags(state);
    while (pops-- > 0u) {
        if (!batch_guest_x87_pop(state)) return false;
    }
    return true;
}

inline bool batch_guest_x87_compare_memory(
    const BatchLiftMemory& memory,
    BatchLiftState& state,
    std::uint32_t address,
    unsigned pops,
    bool to_eflags) {
    std::uint32_t raw{};
    if (!memory.load32(address, raw)) return false;
    float value{};
    std::memcpy(&value, &raw, sizeof(value));
    return batch_guest_x87_compare_value(
        state, static_cast<double>(value), pops, to_eflags);
}

inline bool batch_guest_x87_compare_stack(
    BatchLiftState& state,
    unsigned index,
    unsigned pops,
    bool to_eflags) {
    if (index >= state.x87_depth) return false;
    const double right = batch_guest_x87_st(state, index);
    return batch_guest_x87_compare_value(state, right, pops, to_eflags);
}

inline bool batch_guest_fnstsw_ax(BatchLiftState& state) {
    const std::uint32_t status = state.x87_status
        | ((state.x87_top & 7u) << 11u);
    state.regs[0] = (state.regs[0] & 0xffff0000u) | (status & 0xffffu);
    return true;
}

// RDTSC is a deterministic guest cycle counter, not the host clock: every host
// and the ARM64 device must read the same sequence, or a differential run would
// compare two different machines' time bases. The counter starts at a fixed base
// and advances by a constant step on each read, so code that measures elapsed
// time gets a non-zero, repeatable delta. This is a fidelity limit: it is not
// real time, and nothing in the port may treat it as wall clock.
inline constexpr std::uint64_t kGuestRdtscBase = 0x0000100000000000ull;
inline constexpr std::uint64_t kGuestRdtscStep = 0x40ull;

inline bool batch_guest_rdtsc(BatchLiftState& state) {
    const std::uint64_t value =
        kGuestRdtscBase + kGuestRdtscStep * state.rdtsc_reads++;
    state.regs[0] = static_cast<std::uint32_t>(value);
    state.regs[2] = static_cast<std::uint32_t>(value >> 32u);
    return true;
}

// String operations. The guest is single-threaded and models DF from EFLAGS, so
// a copy runs either upward or downward as the program asked. A count beyond the
// limit fails closed instead of running for an unbounded time on a corrupt ECX.
inline constexpr std::uint32_t kGuestStringOpLimit = 1u << 20;

inline std::uint32_t batch_guest_string_step(
    const BatchLiftState& state, unsigned size) {
    return (state.eflags & 0x400u) != 0u
        ? static_cast<std::uint32_t>(0u - size) : size;
}

inline bool batch_guest_string_load(
    const BatchLiftMemory& memory, std::uint32_t address, unsigned size,
    std::uint32_t& value) {
    switch (size) {
    case 1u: return memory.load8(address, value);
    case 2u: return memory.load16(address, value);
    default: return memory.load32(address, value);
    }
}

inline bool batch_guest_string_store(
    BatchLiftMemory& memory, std::uint32_t address, unsigned size,
    std::uint32_t value) {
    switch (size) {
    case 1u: return memory.store8(address, value);
    case 2u: return memory.store16(address, value);
    default: return memory.store32(address, value);
    }
}

// REP MOVS: copy ECX elements from DS:ESI to ES:EDI.
inline bool batch_guest_rep_movs(
    BatchLiftMemory& memory, BatchLiftState& state, unsigned size) {
    std::uint32_t count = state.regs[1];
    if (count > kGuestStringOpLimit) return false;
    const std::uint32_t step = batch_guest_string_step(state, size);
    std::uint32_t source = state.regs[6];
    std::uint32_t destination = state.regs[7];
    while (count > 0u) {
        std::uint32_t value{};
        if (!batch_guest_string_load(memory, source, size, value)
                || !batch_guest_string_store(memory, destination, size, value)) {
            state.regs[1] = count;
            state.regs[6] = source;
            state.regs[7] = destination;
            return false;
        }
        source = static_cast<std::uint32_t>(source + step);
        destination = static_cast<std::uint32_t>(destination + step);
        --count;
    }
    state.regs[1] = 0u;
    state.regs[6] = source;
    state.regs[7] = destination;
    return true;
}

// REP STOS: store ECX copies of AL/AX/EAX at ES:EDI.
inline bool batch_guest_rep_stos(
    BatchLiftMemory& memory, BatchLiftState& state, unsigned size) {
    std::uint32_t count = state.regs[1];
    if (count > kGuestStringOpLimit) return false;
    const std::uint32_t step = batch_guest_string_step(state, size);
    const std::uint32_t value = size == 1u
        ? (state.regs[0] & 0xffu)
        : size == 2u ? (state.regs[0] & 0xffffu) : state.regs[0];
    std::uint32_t destination = state.regs[7];
    while (count > 0u) {
        if (!batch_guest_string_store(memory, destination, size, value)) {
            state.regs[1] = count;
            state.regs[7] = destination;
            return false;
        }
        destination = static_cast<std::uint32_t>(destination + step);
        --count;
    }
    state.regs[1] = 0u;
    state.regs[7] = destination;
    return true;
}

// REPE/REPNE CMPS: compare DS:ESI with ES:EDI, repeating while the comparison
// matches (REPE) or differs (REPNE).
inline bool batch_guest_repe_cmps(
    BatchLiftMemory& memory, BatchLiftState& state, unsigned size,
    bool repeat_while_equal) {
    std::uint32_t count = state.regs[1];
    if (count > kGuestStringOpLimit) return false;
    const std::uint32_t step = batch_guest_string_step(state, size);
    std::uint32_t source = state.regs[6];
    std::uint32_t destination = state.regs[7];
    while (count > 0u) {
        std::uint32_t left{}, right{};
        const bool readable =
            batch_guest_string_load(memory, source, size, left)
            && batch_guest_string_load(memory, destination, size, right);
        if (!readable) {
            state.regs[1] = count;
            state.regs[6] = source;
            state.regs[7] = destination;
            return false;
        }
        const std::uint32_t mask = batch_mask(size * 8u);
        const std::uint32_t result =
            static_cast<std::uint32_t>(left - right) & mask;
        batch_set_sub_flags(state, left, right, result, size * 8u);
        source = static_cast<std::uint32_t>(source + step);
        destination = static_cast<std::uint32_t>(destination + step);
        --count;
        const bool equal = (state.eflags & 0x040u) != 0u;
        if (count == 0u || equal != repeat_while_equal) break;
    }
    state.regs[1] = count;
    state.regs[6] = source;
    state.regs[7] = destination;
    return true;
}

// SHR and SAR keep CF as the last bit shifted out; ZF/SF/PF follow the
// result, and both clear OF for single-bit counts.
inline void batch_set_shr_flags(
    BatchLiftState& state,
    std::uint32_t value,
    unsigned count,
    std::uint32_t result,
    unsigned width) {
    if (count == 0u) return;
    const std::uint32_t mask = batch_mask(width);
    value &= mask;
    result &= mask;
    state.eflags &= ~0x8c5u;
    const unsigned bit = count <= width ? count - 1u : width - 1u;
    if ((value & (std::uint32_t{1} << bit)) != 0u) {
        state.eflags |= 0x001u;
    }
    if (batch_even_parity(static_cast<std::uint8_t>(result))) {
        state.eflags |= 0x004u;
    }
    if (result == 0u) state.eflags |= 0x040u;
    if ((result & (std::uint32_t{1} << (width - 1u))) != 0u) {
        state.eflags |= 0x080u;
    }
}

inline void batch_set_sar_flags(
    BatchLiftState& state,
    std::uint32_t value,
    unsigned count,
    std::uint32_t result,
    unsigned width) {
    batch_set_shr_flags(state, value, count, result, width);
    // SAR clears OF for every count.
    state.eflags &= ~0x800u;
}

// This bounded path was differential-tested with x87 CW=0x027f (53-bit,
// round-to-nearest) and MXCSR=0x1f80. The guest state does not model changes
// to either control register or x87 exception flags.
inline bool batch_guest_fild32(const BatchLiftMemory& memory,
                              BatchLiftState& state, std::uint32_t address) {
    std::uint32_t raw{};
    if (!memory.load32(address, raw)) return false;
    return batch_guest_x87_push(
        state, static_cast<double>(static_cast<std::int32_t>(raw)));
}

inline bool batch_guest_fild64(const BatchLiftMemory& memory,
                              BatchLiftState& state, std::uint32_t address) {
    std::uint64_t raw{};
    if (!memory.load64(address, raw)) return false;
    return batch_guest_x87_push(
        state, static_cast<double>(static_cast<std::int64_t>(raw)));
}

inline bool batch_guest_x87_float32_arithmetic(const BatchLiftMemory& memory,
                                                BatchLiftState& state,
                                                std::uint32_t address,
                                                unsigned operation) {
    if (state.x87_depth == 0u) return false;
    std::uint32_t raw{};
    if (!memory.load32(address, raw)) return false;
    float source{};
    std::memcpy(&source, &raw, sizeof(source));
    batch_guest_x87_set(
        state, 0u,
        batch_guest_x87_compute(
            batch_guest_x87_st(state, 0u),
            static_cast<double>(source),
            operation));
    return true;
}

// ST(destination) = ST(destination) <op> ST(source), optionally popping ST(0)
// afterwards, which is the shape of every register arithmetic form.
inline bool batch_guest_x87_arithmetic_stack(BatchLiftState& state,
                                             unsigned destination,
                                             unsigned source,
                                             unsigned operation,
                                             bool pop) {
    if (destination >= state.x87_depth || source >= state.x87_depth) {
        return false;
    }
    const double result = batch_guest_x87_compute(
        batch_guest_x87_st(state, destination),
        batch_guest_x87_st(state, source),
        operation);
    batch_guest_x87_set(state, destination, result);
    return !pop || batch_guest_x87_pop(state);
}

inline bool batch_guest_fstp32(BatchLiftMemory& memory,
                               BatchLiftState& state, std::uint32_t address) {
    if (state.x87_depth == 0u) return false;
    const float result = static_cast<float>(batch_guest_x87_st(state, 0u));
    std::uint32_t raw{};
    std::memcpy(&raw, &result, sizeof(raw));
    if (!memory.store32(address, raw)) return false;
    return batch_guest_x87_pop(state);
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

inline bool batch_guest_cvtsi2ss_memory(const BatchLiftMemory& memory,
                                        BatchLiftState& state,
                                        std::uint32_t destination,
                                        std::uint32_t address) {
    std::uint32_t raw{};
    if (destination >= 8u || !memory.load32(address, raw)) return false;
    const float value = static_cast<float>(static_cast<std::int32_t>(raw));
    std::memcpy(&state.xmm[destination][0], &value, sizeof(value));
    return true;
}

inline bool batch_guest_cvttss2si(BatchLiftState& state,
                                  std::uint32_t destination,
                                  std::uint32_t source) {
    if (destination >= 8u || source >= 8u) return false;
    float value{};
    std::memcpy(&value, &state.xmm[source][0], sizeof(value));
    const double truncated = std::trunc(static_cast<double>(value));
    state.regs[destination] = !std::isfinite(truncated) ||
        truncated < -2147483648.0 || truncated >= 2147483648.0
        ? 0x80000000u
        : static_cast<std::uint32_t>(static_cast<std::int32_t>(truncated));
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

// COMISS, UCOMISS and the memory form all report the same three flags, so the
// operand is resolved to a value first and the flags are set once.
inline bool batch_guest_ucomiss_value(BatchLiftState& state,
                                      std::uint32_t left,
                                      std::uint32_t right_bits) {
    if (left >= 8u) return false;
    float a{}, b{};
    std::memcpy(&a, &state.xmm[left][0], sizeof(a));
    std::memcpy(&b, &right_bits, sizeof(b));
    state.eflags &= ~0x8c5u;
    if (std::isnan(a) || std::isnan(b)) state.eflags |= 0x045u;
    else if (a < b) state.eflags |= 0x001u;
    else if (a == b) state.eflags |= 0x040u;
    return true;
}

inline bool batch_guest_ucomiss_memory(const BatchLiftMemory& memory,
                                       BatchLiftState& state,
                                       std::uint32_t left,
                                       std::uint32_t address) {
    std::uint32_t bits{};
    if (left >= 8u || !memory.load32(address, bits)) return false;
    return batch_guest_ucomiss_value(state, left, bits);
}

// Scalar single-precision arithmetic rounds in float, exactly as SSE does;
// widening to double first would round differently.
inline bool batch_guest_sse_scalar_arithmetic(BatchLiftState& state,
                                              std::uint32_t destination,
                                              std::uint32_t source_bits,
                                              unsigned operation) {
    if (destination >= 8u) return false;
    float left{}, right{};
    std::memcpy(&left, &state.xmm[destination][0], sizeof(left));
    std::memcpy(&right, &source_bits, sizeof(right));
    const float result = operation == 1u ? left - right
        : operation == 2u ? left * right
        : operation == 3u ? left / right
        : left + right;
    std::memcpy(&state.xmm[destination][0], &result, sizeof(result));
    return true;
}

inline bool batch_guest_xorps_memory(const BatchLiftMemory& memory,
                                     BatchLiftState& state,
                                     std::uint32_t destination,
                                     std::uint32_t address) {
    if (destination >= 8u) return false;
    for (unsigned lane = 0; lane < 4u; ++lane) {
        std::uint32_t value{};
        if (!memory.load32(address + lane * 4u, value)) return false;
        state.xmm[destination][lane] ^= value;
    }
    return true;
}

// MOVAPS and MOVAPD move the same sixteen bytes; only the naming differs.
inline bool batch_guest_movaps(BatchLiftState& state,
                               std::uint32_t destination,
                               std::uint32_t source) {
    return batch_guest_movapd(state, destination, source);
}

// AH <- SF:ZF:0:AF:0:PF:1:CF
inline bool batch_guest_lahf(BatchLiftState& state) {
    std::uint32_t flags = 0x02u;
    if (state.eflags & 0x001u) flags |= 0x01u;
    if (state.eflags & 0x004u) flags |= 0x04u;
    if (state.eflags & 0x010u) flags |= 0x10u;
    if (state.eflags & 0x040u) flags |= 0x40u;
    if (state.eflags & 0x080u) flags |= 0x80u;
    state.regs[0] = (state.regs[0] & 0xffff00ffu) | (flags << 8u);
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

// JMP [IAT]: the return address the import will use is already on the guest
// stack, so nothing is pushed and the body ends with the import's status.
inline BatchLiftStatus batch_guest_import_tail_call32(
    BatchLiftMemory& memory,
    BatchLiftState& state,
    const char* symbol,
    std::uint32_t iat_address) {
    if (state.imports == nullptr) return BatchLiftStatus::unsupported_import;
    return state.imports->invoke_import(memory, state, symbol, iat_address);
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

// The guest process id stands in for the host process id. Only the CRT entropy
// mix consumes it, and the host value is machine-specific, so no comparison
// across hosts can require the original number. It stays fixed and nonzero.
inline constexpr std::uint32_t kBatchGuestProcessId = 0x1234u;

// Return address installed while the CRT initializer table runs a guest
// routine. It is not code: reaching it back means the initializer returned.
inline constexpr std::uint32_t kBatchGuestInitializerReturn = 0xfffff000u;

// MSVCR90 keeps _fmode and _commode inside itself, so the guest stands in with
// two writable guest ints. Callers only ever reach them through __p__fmode and
// __p__commode, and __cinit copies the loader-zeroed defaults into them.
inline constexpr std::uint32_t kGuestFmodeAddress = 0x015cff00u;
inline constexpr std::uint32_t kGuestCommodeAddress = 0x015cff04u;
// _security_cookie global that __security_init_cookie fills in.
inline constexpr std::uint32_t kGuestSecurityCookieAddress = 0x015cfe70u;

// The guest has no process command line of its own, so __getmainargs reports a
// single argument with the program name and an empty environment. Both arrays
// and the string live in one writable guest window.
inline constexpr std::uint32_t kGuestArgvArray = 0x015cff40u;
inline constexpr std::uint32_t kGuestEnvpArray = 0x015cff48u;
inline constexpr std::uint32_t kGuestProgramName = 0x015cff50u;
inline constexpr char kGuestProgramNameText[] = "SporeApp.exe";
inline constexpr std::uint32_t kGuestArgumentCount = 1u;

// The MSVCRT imports in this closure are __cdecl: the guest code adjusts the
// stack itself (POP ECX, POP ECX or ADD ESP,0xc), so the shim leaves the
// argument bytes in place. Only the WINAPI imports pop their own arguments.
inline constexpr std::uint32_t kGuestCdeclCleanup = 0u;

// The Windows loader rewrites every import slot with the resolved address of
// the imported routine before the first instruction runs, so a slot read as
// data is a callable pointer. The guest image keeps the file's pre-fixup
// hint/name RVAs, so the same fixup is applied here: each mapped slot receives
// a guest trampoline address that dispatches its symbol. The addresses are
// labels, not code; the dispatcher resolves them before anything executes.
inline constexpr std::uint32_t kGuestImportTrampolineBase = 0x5f000000u;
inline constexpr std::uint32_t kGuestImportTrampolineStride = 0x10u;

struct BatchImportSlot {
    std::uint32_t address;
    const char* symbol;
};

// The guest heap: HeapAlloc bumps a block inside it, so a node the engine keeps
// alive has a stable address for the whole run. The heap handle is a constant
// the guest only ever passes back to HeapAlloc and HeapFree.
inline constexpr std::uint32_t kGuestProcessHeapHandle = 0x00e0ff01u;
inline constexpr std::uint32_t kGuestHeapBase = 0x5e000000u;
inline constexpr std::uint32_t kGuestHeapBytes = 0x00001000u;
// VirtualAlloc hands out address space from a guest arena that costs no host
// memory until it is committed, and every committed reservation gets its own
// host block so a later commit can never move an earlier mapping. The arena is
// far larger than the CRT needs because the engine reserves its own heap here:
// the first initializer that asks for one requests 16 MB in a single call.
inline constexpr std::uint32_t kGuestVirtualArenaBase = 0x20000000u;
inline constexpr std::uint32_t kGuestVirtualArenaBytes = 0x10000000u;
// Committed bytes the guest may hold at once. Reached only by a runaway
// reservation, which fails closed instead of growing without a bound.
inline constexpr std::uint64_t kGuestVirtualCommitLimitBytes = 0x10000000ull;
// Sizes of the two Windows structures the guest fills in by hand.
inline constexpr std::uint32_t kSystemInfoBytes = 36u;
inline constexpr std::uint32_t kMemoryBasicInformationBytes = 28u;
// QueryPerformanceFrequency reports this fixed counter rate in the guest.
inline constexpr std::uint64_t kGuestPerformanceFrequency = 10000000ull;
// Deterministic time the guest presents to code that measures elapsed time. A
// read advances the counter by one step, so every host and the ARM64 device see
// the same sequence and a differential run compares like with like. These are
// not wall-clock values.
inline constexpr std::uint32_t kGuestTickBase = 0x00010000u;
inline constexpr std::uint64_t kGuestQpcBase = 0x0000000100000000ull;
inline constexpr std::uint64_t kGuestQpcStep = 1000ull;

struct BatchGuestImportCall {
    std::string symbol;
    std::uint32_t iat_address;
    std::vector<std::uint32_t> arguments;
    std::uint32_t result{};
    std::uint32_t last_error{};
    std::uint32_t return_address{};
    std::uint32_t receiver{};
    // The guest string a shim consumed or produced, recorded when the call
    // happens: the stack buffer it came from is gone by the time a test looks.
    std::string text;
};

class BatchGuestRuntime final : public BatchGuestImportDispatcher {
public:
    using GuestFunction =
        BatchLiftStatus (*)(BatchLiftMemory&, BatchLiftState&);

    // The CRT initializer table calls guest routines by address. Only compiled
    // bodies may be registered; anything else fails closed with its address.
    void register_guest_function(std::uint32_t address, GuestFunction body) {
        guest_functions_[address] = body;
    }

    // Reset the guest TLS index counter so one run always hands out the same
    // indices.
    void reset_tls_indexes() { tls_indexes_ = 0u; }

    // A neutralized body replaces PE bytes the port does not lift, so the
    // contract it upholds has to be written down and checked by the harness.
    // The callback owns the whole call: it reads its own arguments, performs
    // only the effects the contract names, and returns through the caller's
    // return address like any other callee.
    using NeutralizedBody = BatchLiftStatus (*)(
        BatchGuestRuntime&, BatchLiftMemory&, BatchLiftState&);

    void register_neutralized_body(
        std::uint32_t entry, const char* note, NeutralizedBody body) {
        neutralized_bodies_[entry] = {std::string(note), body};
    }

    // Records a neutralized call in the same ordered trace as the imports, so a
    // neutralization is never invisible in a run.
    void note_neutralized_call(
        std::uint32_t entry,
        const char* note,
        std::uint32_t result,
        std::initializer_list<std::uint32_t> arguments) {
        BatchGuestImportCall call{};
        call.symbol = std::string("NEUTRALIZED:") + hex32(entry) + " " + note;
        call.iat_address = entry;
        call.arguments.assign(arguments.begin(), arguments.end());
        call.result = result;
        calls_.push_back(std::move(call));
    }

    // Apply the loader's import-address fixup to the mapped import slots: each
    // slot keeps the address of a guest trampoline that resolves to its symbol,
    // so reading a slot as data yields something that can be called.
    bool install_import_trampolines(
        BatchLiftMemory& memory,
        const BatchImportSlot* slots,
        std::size_t count) {
        for (std::size_t index = 0; index < count; ++index) {
            const std::uint32_t address = kGuestImportTrampolineBase
                + kGuestImportTrampolineStride
                    * static_cast<std::uint32_t>(index);
            if (!memory.store32(slots[index].address, address)) {
                last_error_ = std::string("import slot 0x")
                    + hex32(slots[index].address)
                    + " is not mapped writable for the loader fixup";
                return false;
            }
            import_trampolines_[address] = slots[index].symbol;
        }
        return true;
    }

    BatchLiftStatus invoke_guest_call(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        std::uint32_t target,
        std::uint32_t return_address) override {
        const auto trampoline = import_trampolines_.find(target);
        if (trampoline != import_trampolines_.end()) {
            if (!batch_guest_call32(memory, state, target, return_address)) {
                return BatchLiftStatus::invalid_memory;
            }
            const BatchLiftStatus status = invoke_import(
                memory, state, trampoline->second.c_str(), target);
            if (status != BatchLiftStatus::returned) return status;
            if (state.eip != return_address) {
                return BatchLiftStatus::invalid_control_flow;
            }
            return BatchLiftStatus::returned;
        }
        const auto neutralized = neutralized_bodies_.find(target);
        if (neutralized != neutralized_bodies_.end()) {
            if (!batch_guest_call32(memory, state, target, return_address)) {
                return BatchLiftStatus::invalid_memory;
            }
            const BatchLiftStatus status =
                neutralized->second.body(*this, memory, state);
            if (status != BatchLiftStatus::returned) return status;
            if (state.eip != return_address) {
                return BatchLiftStatus::invalid_control_flow;
            }
            return BatchLiftStatus::returned;
        }
        const auto body = guest_functions_.find(target);
        if (body == guest_functions_.end()) {
            // Name the boundary the way the walk reports it: the address that
            // has no lifted body is left in EIP.
            state.eip = target;
            last_error_ =
                "no lifted body for indirect call target 0x" + hex32(target);
            return BatchLiftStatus::unsupported_dependency;
        }
        if (!batch_guest_call32(memory, state, target, return_address)) {
            return BatchLiftStatus::invalid_memory;
        }
        const BatchLiftStatus status = body->second(memory, state);
        if (status != BatchLiftStatus::returned) return status;
        if (state.eip != return_address) {
            return BatchLiftStatus::invalid_control_flow;
        }
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus invoke_guest_tail_call(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        std::uint32_t target) override {
        const auto trampoline = import_trampolines_.find(target);
        if (trampoline != import_trampolines_.end()) {
            // A tail-called import returns to this body's caller, so the shim
            // reads that return address off the guest stack as usual.
            return invoke_import(
                memory, state, trampoline->second.c_str(), target);
        }
        const auto neutralized = neutralized_bodies_.find(target);
        if (neutralized != neutralized_bodies_.end()) {
            // A neutralized body keeps the caller's return address on the
            // stack, so no extra frame is pushed here either.
            return neutralized->second.body(*this, memory, state);
        }
        const auto body = guest_functions_.find(target);
        if (body == guest_functions_.end()) {
            state.eip = target;
            last_error_ =
                "no lifted body for tail jump target 0x" + hex32(target);
            return BatchLiftStatus::unsupported_dependency;
        }
        return body->second(memory, state);
    }

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
        BatchGuestImportCall call{};
        call.symbol = symbol;
        call.iat_address = iat_address;
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
        if (call.symbol == "KERNEL32.dll!GetSystemTimeAsFileTime") {
            return get_system_time_as_file_time(memory, state, call);
        }
        if (call.symbol == "KERNEL32.dll!GetCurrentProcessId") {
            return get_current_process_id(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetCurrentThreadId") {
            return get_current_thread_id(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetStartupInfoA") {
            return get_startup_info(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!InterlockedCompareExchange") {
            return interlocked_compare_exchange(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_initterm_e") {
            return initterm_e(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_initterm") {
            return initterm(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_amsg_exit") {
            return amsg_exit(calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!__set_app_type") {
            return set_app_type(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!__getmainargs") {
            return get_main_args(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!InitializeCriticalSection") {
            return initialize_critical_section(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!TlsAlloc") {
            return tls_alloc(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!sprintf") {
            return sprintf_guest(memory, state, calls_.back());
        }
        if (call.symbol == "USER32.dll!wsprintfA") {
            return wsprintf_guest(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_strtoui64") {
            return strtoui64_guest(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetProcessHeap") {
            return get_process_heap(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!HeapAlloc") {
            return heap_alloc(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!HeapFree") {
            return heap_free(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetCurrentThread") {
            return get_current_thread(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetCurrentProcess") {
            return get_current_process(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetPriorityClass") {
            return get_priority_class(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!SetPriorityClass") {
            return set_priority_class(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!SetThreadPriority") {
            return set_thread_priority(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!QueryPerformanceFrequency") {
            return query_performance_frequency(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetThreadPriority") {
            return get_thread_priority(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetSystemInfo") {
            return get_system_info(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!InterlockedDecrement") {
            return interlocked_decrement(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!DuplicateHandle") {
            return duplicate_handle(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!SleepEx") {
            return sleep_ex(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!TlsSetValue") {
            return tls_set_value(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!VirtualAlloc") {
            return virtual_alloc(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!VirtualFree") {
            return virtual_free(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!VirtualQuery") {
            return virtual_query(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!InitializeCriticalSectionAndSpinCount") {
            return initialize_critical_section_and_spin_count(
                memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!memcpy"
                || call.symbol == "MSVCR90.dll!memmove") {
            return memcpy_guest(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_stricmp") {
            return stricmp_guest(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!isalpha") {
            return isalpha_guest(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!tolower") {
            return tolower_guest(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_finite") {
            return finite_guest(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_isnan") {
            return isnan_guest(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_purecall") {
            return purecall_guest(calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!OutputDebugStringA") {
            return output_debug_string(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!WideCharToMultiByte") {
            return wide_char_to_multi_byte(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetEnvironmentVariableA") {
            return get_environment_variable(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!SetEnvironmentVariableA") {
            return set_environment_variable(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!WaitForSingleObject") {
            return wait_for_single_object(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!ReleaseMutex") {
            return release_mutex(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!CloseHandle") {
            return close_handle(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!TlsFree") {
            return tls_free(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_lock"
                || call.symbol == "MSVCR90.dll!_unlock") {
            return lock_table(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_onexit"
                || call.symbol == "MSVCR90.dll!__dllonexit") {
            return onexit_registration(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!__p__fmode") {
            return p_fmode(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!__p__commode") {
            return p_commode(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_adjust_fdiv") {
            return adjust_fdiv(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!__setusermatherr") {
            return set_user_matherr(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_configthreadlocale") {
            return config_thread_locale(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_encode_pointer") {
            return encode_pointer(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_decode_pointer") {
            return decode_pointer(memory, state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!SetUnhandledExceptionFilter") {
            return set_unhandled_exception_filter(state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_controlfp_s") {
            return controlfp_s(memory, state, calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!_invoke_watson") {
            return invoke_watson(calls_.back());
        }
        if (call.symbol == "MSVCR90.dll!?terminate@@YAXXZ") {
            return terminate(calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!GetTickCount") {
            return get_tick_count(state, calls_.back());
        }
        if (call.symbol == "KERNEL32.dll!QueryPerformanceCounter") {
            return query_performance_counter(memory, state, calls_.back());
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

    // How many table initializers ran to completion, and the last one that did.
    // A walk that stops early still reports what it really executed.
    std::uint32_t initializers_completed() const {
        return initializers_completed_;
    }

    std::uint32_t last_initializer() const {
        return last_initializer_;
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
        if (symbol == "KERNEL32.dll!GetSystemTimeAsFileTime") return 1u;
        if (symbol == "KERNEL32.dll!GetCurrentProcessId") return 0u;
        if (symbol == "KERNEL32.dll!GetCurrentThreadId") return 0u;
        if (symbol == "KERNEL32.dll!GetStartupInfoA") return 1u;
        if (symbol == "KERNEL32.dll!InterlockedCompareExchange") return 3u;
        if (symbol == "MSVCR90.dll!_initterm_e") return 2u;
        if (symbol == "MSVCR90.dll!_initterm") return 2u;
        if (symbol == "MSVCR90.dll!_amsg_exit") return 1u;
        if (symbol == "MSVCR90.dll!__set_app_type") return 1u;
        if (symbol == "MSVCR90.dll!__getmainargs") return 5u;
        if (symbol == "KERNEL32.dll!InitializeCriticalSection") return 1u;
        if (symbol == "KERNEL32.dll!TlsAlloc") return 0u;
        if (symbol == "KERNEL32.dll!TlsFree") return 1u;
        if (symbol == "MSVCR90.dll!sprintf") return 2u;
        if (symbol == "USER32.dll!wsprintfA") return 2u;
        if (symbol == "MSVCR90.dll!_strtoui64") return 3u;
        if (symbol == "KERNEL32.dll!GetProcessHeap") return 0u;
        if (symbol == "KERNEL32.dll!HeapAlloc") return 3u;
        if (symbol == "KERNEL32.dll!HeapFree") return 3u;
        if (symbol == "KERNEL32.dll!GetCurrentThread") return 0u;
        if (symbol == "KERNEL32.dll!GetCurrentProcess") return 0u;
        if (symbol == "KERNEL32.dll!GetPriorityClass") return 1u;
        if (symbol == "KERNEL32.dll!SetPriorityClass") return 2u;
        if (symbol == "KERNEL32.dll!SetThreadPriority") return 2u;
        if (symbol == "KERNEL32.dll!QueryPerformanceFrequency") return 1u;
        if (symbol == "KERNEL32.dll!GetThreadPriority") return 1u;
        if (symbol == "KERNEL32.dll!GetSystemInfo") return 1u;
        if (symbol == "KERNEL32.dll!InterlockedDecrement") return 1u;
        if (symbol == "KERNEL32.dll!DuplicateHandle") return 7u;
        if (symbol == "KERNEL32.dll!SleepEx") return 2u;
        if (symbol == "KERNEL32.dll!TlsSetValue") return 2u;
        if (symbol == "KERNEL32.dll!VirtualAlloc") return 4u;
        if (symbol == "KERNEL32.dll!VirtualFree") return 3u;
        if (symbol == "KERNEL32.dll!VirtualQuery") return 3u;
        if (symbol == "KERNEL32.dll!InitializeCriticalSectionAndSpinCount") {
            return 2u;
        }
        if (symbol == "MSVCR90.dll!memcpy"
                || symbol == "MSVCR90.dll!memmove") {
            return 3u;
        }
        if (symbol == "MSVCR90.dll!_stricmp") return 2u;
        if (symbol == "MSVCR90.dll!isalpha") return 1u;
        if (symbol == "MSVCR90.dll!tolower") return 1u;
        // A double argument occupies two dword slots on the x86 stack.
        if (symbol == "MSVCR90.dll!_finite"
                || symbol == "MSVCR90.dll!_isnan") {
            return 2u;
        }
        if (symbol == "MSVCR90.dll!_purecall") return 0u;
        if (symbol == "KERNEL32.dll!OutputDebugStringA") return 1u;
        if (symbol == "KERNEL32.dll!WideCharToMultiByte") return 8u;
        if (symbol == "KERNEL32.dll!GetEnvironmentVariableA") return 3u;
        if (symbol == "KERNEL32.dll!SetEnvironmentVariableA") return 2u;
        if (symbol == "KERNEL32.dll!WaitForSingleObject") return 2u;
        if (symbol == "KERNEL32.dll!ReleaseMutex") return 1u;
        if (symbol == "KERNEL32.dll!CloseHandle") return 1u;
        if (symbol == "MSVCR90.dll!_lock") return 1u;
        if (symbol == "MSVCR90.dll!_unlock") return 1u;
        if (symbol == "MSVCR90.dll!_onexit") return 1u;
        if (symbol == "MSVCR90.dll!__dllonexit") return 1u;
        if (symbol == "MSVCR90.dll!__p__fmode") return 0u;
        if (symbol == "MSVCR90.dll!__p__commode") return 0u;
        if (symbol == "MSVCR90.dll!_adjust_fdiv") return 0u;
        if (symbol == "MSVCR90.dll!__setusermatherr") return 1u;
        if (symbol == "MSVCR90.dll!_configthreadlocale") return 1u;
        if (symbol == "MSVCR90.dll!_encode_pointer") return 1u;
        if (symbol == "MSVCR90.dll!_decode_pointer") return 1u;
        if (symbol == "KERNEL32.dll!SetUnhandledExceptionFilter") return 1u;
        if (symbol == "MSVCR90.dll!_controlfp_s") return 3u;
        if (symbol == "MSVCR90.dll!_invoke_watson") return 5u;
        if (symbol == "MSVCR90.dll!?terminate@@YAXXZ") return 0u;
        if (symbol == "KERNEL32.dll!GetTickCount") return 0u;
        if (symbol == "KERNEL32.dll!QueryPerformanceCounter") return 1u;
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

    BatchLiftStatus get_system_time_as_file_time(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        const std::uint32_t destination = call.arguments[0];
        if (!memory.is_writable(destination, 8u)) {
            last_error_ = "GetSystemTimeAsFileTime destination is outside writable guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        std::uint64_t ticks{};
#if defined(_WIN32)
        FILETIME now{};
        GetSystemTimeAsFileTime(&now);
        ticks = static_cast<std::uint64_t>(now.dwLowDateTime) |
            (static_cast<std::uint64_t>(now.dwHighDateTime) << 32u);
#else
        const auto now = std::chrono::system_clock::now().time_since_epoch();
        const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(now);
        const auto remainder = std::chrono::duration_cast<std::chrono::nanoseconds>(
            now - seconds);
        constexpr std::int64_t kUnixToFileTimeSeconds = 11644473600ll;
        const std::int64_t filetime_seconds =
            seconds.count() + kUnixToFileTimeSeconds;
        if (filetime_seconds < 0) {
            last_error_ = "GetSystemTimeAsFileTime host clock predates FILETIME epoch";
            return BatchLiftStatus::invalid_control_flow;
        }
        ticks = static_cast<std::uint64_t>(filetime_seconds) * 10000000ull +
            static_cast<std::uint64_t>(remainder.count() / 100);
#endif
        if (!memory.store64(destination, ticks)) {
            last_error_ = "GetSystemTimeAsFileTime destination changed after validation";
            return BatchLiftStatus::invalid_memory;
        }
        // The API returns void. EAX and flags have no defined result here.
        complete_import_call(state, call.return_address, 4u);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus get_current_process_id(
        BatchLiftState& state,
        BatchGuestImportCall& call) {
        // stdcall with no arguments: only the four return-address bytes leave
        // the stack. EFLAGS after a Win32 call are not part of the contract.
        complete_api_call(
            state, call, call.return_address, 0u, kBatchGuestProcessId);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus get_current_thread_id(
        BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t id = guest_thread_id(std::this_thread::get_id());
        complete_api_call(state, call, call.return_address, 0u, id);
        return BatchLiftStatus::returned;
    }

    // Guest-side STARTUPINFOA. The layout matches the 32-bit Win32 structure;
    // no host pointer or handle is ever copied into guest memory.
    struct GuestStartupInfoA {
        std::uint32_t cb;
        std::uint32_t reserved;
        std::uint32_t desktop;
        std::uint32_t title;
        std::uint32_t x;
        std::uint32_t y;
        std::uint32_t x_size;
        std::uint32_t y_size;
        std::uint32_t x_count_chars;
        std::uint32_t y_count_chars;
        std::uint32_t fill_attribute;
        std::uint32_t flags;
        std::uint16_t show_window;
        std::uint16_t reserved2_size;
        std::uint32_t reserved2;
        std::uint32_t std_input;
        std::uint32_t std_output;
        std::uint32_t std_error;
    };

    static_assert(sizeof(GuestStartupInfoA) == 0x44u);

    BatchLiftStatus get_startup_info(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t address = call.arguments[0];
        if (!memory.is_writable(address, sizeof(GuestStartupInfoA))) {
            last_error_ =
                "GetStartupInfoA structure is outside writable guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        // The caller owns cb; the API reports into the rest of the structure.
        // This guest has no console, desktop, window or inherited handles, so
        // every pointer and handle stays null and every geometry value zero.
        std::uint32_t cb = 0;
        if (!memory.load32(address, cb)) {
            last_error_ = "GetStartupInfoA could not read cb";
            return BatchLiftStatus::invalid_memory;
        }
        for (std::uint32_t offset = 4u; offset < sizeof(GuestStartupInfoA);
             offset += 4u) {
            if (!memory.store32(address + offset, 0u)) {
                last_error_ =
                    "GetStartupInfoA structure changed after validation";
                return BatchLiftStatus::invalid_memory;
            }
        }
        if (!memory.store32(address, cb)) {
            last_error_ = "GetStartupInfoA could not restore cb";
            return BatchLiftStatus::invalid_memory;
        }
        // The API returns void: only the four argument bytes leave the stack.
        complete_import_call(state, call.return_address, 4u);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus get_tick_count(
        BatchLiftState& state,
        BatchGuestImportCall& call) {
        // Deterministic guest ticks, for the same reason as the RDTSC model: a
        // host clock here makes an elapsed-time loop in guest code run a
        // different number of iterations on every machine.
        const std::uint32_t ticks = kGuestTickBase
            + static_cast<std::uint32_t>(state.tick_reads++);
        complete_api_call(state, call, call.return_address, 0u, ticks);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus query_performance_counter(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t destination = call.arguments[0];
        if (!memory.is_writable(destination, 8u)) {
            last_error_ =
                "QueryPerformanceCounter destination is outside writable "
                "guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        // Same reason as GetTickCount: the counter is the guest's own, stepped
        // once per read at the frequency QueryPerformanceFrequency reports, so
        // an elapsed-time loop ends after a fixed number of iterations on every
        // host. The value is not real time and nothing may treat it as such.
        const std::uint64_t value =
            kGuestQpcBase + kGuestQpcStep * state.qpc_reads++;
        if (!memory.store64(destination, value)) {
            last_error_ =
                "QueryPerformanceCounter destination changed after validation";
            return BatchLiftStatus::invalid_memory;
        }
        complete_api_call(state, call, call.return_address, 4u, 1u);
        return BatchLiftStatus::returned;
    }

    // void __set_app_type(int): MSVCR90 records whether the image is a console
    // or windowed application. Nothing else in this closure observes it.
    BatchLiftStatus set_app_type(
        BatchLiftState& state, BatchGuestImportCall& call) {
        state.app_type = call.arguments[0];
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, 0u);
        return BatchLiftStatus::returned;
    }

    // int* __p__fmode(void) / int* __p__commode(void)
    BatchLiftStatus p_fmode(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        if (!memory.is_writable(kGuestFmodeAddress, 4u)
                || !memory.is_writable(kGuestCommodeAddress, 4u)) {
            last_error_ =
                "the guest CRT _fmode/_commode ints are not mapped writable";
            return BatchLiftStatus::invalid_memory;
        }
        complete_api_call(
            state, call, call.return_address, 0u, kGuestFmodeAddress);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus p_commode(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        if (!memory.is_writable(kGuestFmodeAddress, 4u)
                || !memory.is_writable(kGuestCommodeAddress, 4u)) {
            last_error_ =
                "the guest CRT _fmode/_commode ints are not mapped writable";
            return BatchLiftStatus::invalid_memory;
        }
        complete_api_call(
            state, call, call.return_address, 0u, kGuestCommodeAddress);
        return BatchLiftStatus::returned;
    }

    // int __getmainargs(int* argc, char*** argv, char*** envp, int newmode,
    //                   void* startupinfo): the guest reports its own program
    // name as the single argument and an empty environment.
    BatchLiftStatus get_main_args(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t argc_pointer = call.arguments[0];
        const std::uint32_t argv_pointer = call.arguments[1];
        const std::uint32_t envp_pointer = call.arguments[2];
        const bool writable =
            memory.is_writable(kGuestArgvArray, 12u)
            && memory.is_writable(kGuestEnvpArray, 4u)
            && memory.is_writable(
                kGuestProgramName, sizeof(kGuestProgramNameText))
            && memory.is_writable(argc_pointer, 4u)
            && memory.is_writable(argv_pointer, 4u)
            && memory.is_writable(envp_pointer, 4u);
        if (!writable) {
            last_error_ =
                "__getmainargs pointers are outside writable guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        for (std::size_t index = 0; index < sizeof(kGuestProgramNameText);
                ++index) {
            if (!memory.store8(
                    kGuestProgramName + static_cast<std::uint32_t>(index),
                    static_cast<std::uint8_t>(kGuestProgramNameText[index]))) {
                return BatchLiftStatus::invalid_memory;
            }
        }
        const bool stored =
            memory.store32(argc_pointer, kGuestArgumentCount)
            && memory.store32(argv_pointer, kGuestArgvArray)
            && memory.store32(envp_pointer, kGuestEnvpArray)
            && memory.store32(kGuestArgvArray, kGuestProgramName)
            && memory.store32(kGuestArgvArray + 4u, 0u)
            && memory.store32(kGuestEnvpArray, 0u);
        if (!stored) {
            last_error_ = "__getmainargs could not build the guest argv/envp";
            return BatchLiftStatus::invalid_memory;
        }
        // __getmainargs is __cdecl here: the guest adds 0x14 to ESP itself right
        // after the call, so the shim must leave the arguments in place.
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, 0u);
        return BatchLiftStatus::returned;
    }

    // void InitializeCriticalSection(LPCRITICAL_SECTION): the guest documents
    // a single thread, so the section only records its initial counters.
    BatchLiftStatus initialize_critical_section_with(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call,
        std::uint32_t argument_bytes, std::uint32_t result) {
        return initialize_critical_section_registered(
            memory, state, call, argument_bytes, result);
    }

    BatchLiftStatus initialize_critical_section(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        return initialize_critical_section_with(memory, state, call, 4u, 0u);
    }

    // BOOL InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION, DWORD):
    // the spin count only tunes contention, which one guest thread cannot hit.
    BatchLiftStatus initialize_critical_section_and_spin_count(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        return initialize_critical_section_with(memory, state, call, 8u, 1u);
    }

    // HANDLE GetCurrentProcess(void): the pseudo-handle Windows returns for the
    // calling process is a documented constant.
    BatchLiftStatus get_current_process(
        BatchLiftState& state, BatchGuestImportCall& call) {
        complete_api_call(state, call, call.return_address, 0u, 0xffffffffu);
        return BatchLiftStatus::returned;
    }

    // DWORD GetPriorityClass(HANDLE)
    BatchLiftStatus get_priority_class(
        BatchLiftState& state, BatchGuestImportCall& call) {
        if (call.arguments[0] != 0xffffffffu) {
            set_guest_error(state, 6u, "GetPriorityClass received an unknown handle");
            complete_api_call(state, call, call.return_address, 4u, 0u);
            return BatchLiftStatus::returned;
        }
        // NORMAL_PRIORITY_CLASS: the one guest process runs at normal priority,
        // so the reported class never depends on the host scheduler.
        complete_api_call(state, call, call.return_address, 4u, 0x20u);
        return BatchLiftStatus::returned;
    }

    // BOOL SetPriorityClass(HANDLE, DWORD): scheduling only, and the guest has a
    // single thread, so the request is recorded and accepted.
    BatchLiftStatus set_priority_class(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const bool known = call.arguments[0] == 0xffffffffu;
        set_guest_error(state, known ? 0u : 6u,
                        known ? "" : "SetPriorityClass received an unknown handle");
        complete_api_call(state, call, call.return_address, 8u,
                          known ? 1u : 0u);
        return BatchLiftStatus::returned;
    }

    // BOOL SetThreadPriority(HANDLE, int)
    BatchLiftStatus set_thread_priority(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const bool known = call.arguments[0] == 0xfffffffeu
            || call.arguments[0] == 0xffffffffu;
        set_guest_error(state, known ? 0u : 6u,
                        known ? "" : "SetThreadPriority received an unknown handle");
        complete_api_call(state, call, call.return_address, 8u,
                          known ? 1u : 0u);
        return BatchLiftStatus::returned;
    }

    // BOOL QueryPerformanceFrequency(LARGE_INTEGER*): the guest declares a fixed
    // 10 MHz counter so a frequency read is identical on every host. The counter
    // value itself comes from QueryPerformanceCounter and is host-derived; code
    // that turns it into seconds is therefore host-dependent, which is a
    // documented limitation rather than a modelled clock.
    BatchLiftStatus query_performance_frequency(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t destination = call.arguments[0];
        if (!memory.is_writable(destination, 8u)) {
            last_error_ =
                "QueryPerformanceFrequency destination is outside writable "
                "guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        if (!memory.store64(destination, kGuestPerformanceFrequency)) {
            last_error_ =
                "QueryPerformanceFrequency destination changed after validation";
            return BatchLiftStatus::invalid_memory;
        }
        complete_api_call(state, call, call.return_address, 4u, 1u);
        return BatchLiftStatus::returned;
    }

    // ulong_ptr TlsAlloc(void): the guest hands out indices from zero upward.
    BatchLiftStatus tls_alloc(BatchLiftState& state,
                              BatchGuestImportCall& call) {
        const std::uint32_t index = tls_indexes_++;
        complete_api_call(state, call, call.return_address, 0u, index);
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus tls_free(BatchLiftState& state,
                             BatchGuestImportCall& call) {
        complete_api_call(state, call, call.return_address, 4u, 1u);
        return BatchLiftStatus::returned;
    }

    // void _lock(int) / void _unlock(int): the CRT protects its own tables.
    // One guest thread means no contention, and both are recorded as calls.
    BatchLiftStatus lock_table(BatchLiftState& state,
                               BatchGuestImportCall& call) {
        complete_api_call(state, call, call.return_address, 4u, 0u);
        return BatchLiftStatus::returned;
    }

    // _onexit_t _onexit(_onexit_t) / __dllonexit: the guest CRT keeps no exit
    // table, so a registration is accepted and the previous head is returned.
    BatchLiftStatus onexit_registration(BatchLiftState& state,
                                        BatchGuestImportCall& call) {
        state.exit_handler = call.arguments[0];
        complete_api_call(state, call, call.return_address, 4u,
                          call.arguments[0]);
        return BatchLiftStatus::returned;
    }

    // void _adjust_fdiv(void): the routine only refreshes an internal float
    // adjustment hook that this build never calls.
    BatchLiftStatus adjust_fdiv(BatchLiftState& state,
                                BatchGuestImportCall& call) {
        complete_api_call(state, call, call.return_address, 0u, 0u);
        return BatchLiftStatus::returned;
    }

    // int __setusermatherr(_UserMathErrorFunctionPointer)
    BatchLiftStatus set_user_matherr(
        BatchLiftState& state, BatchGuestImportCall& call) {
        state.user_matherr = call.arguments[0];
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, 0u);
        return BatchLiftStatus::returned;
    }

    // int _configthreadlocale(int): -1 queries, otherwise sets; returns the
    // previous configuration.
    BatchLiftStatus config_thread_locale(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint32_t requested = call.arguments[0];
        const std::uint32_t previous = state.thread_locale;
        if (requested != 0xffffffffu) {
            state.thread_locale = requested;
        }
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, previous);
        return BatchLiftStatus::returned;
    }

    // void* _encode_pointer(void*): MSVCR90 XORs the pointer with the security
    // cookie and rotates left by the cookie's low five bits.
    BatchLiftStatus encode_pointer(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t pointer = call.arguments[0];
        std::uint32_t cookie{};
        if (!memory.load32(kGuestSecurityCookieAddress, cookie)) {
            last_error_ =
                "the guest security cookie is not mapped for _encode_pointer";
            return BatchLiftStatus::invalid_memory;
        }
        std::uint32_t encoded = 0u;
        if (pointer != 0u) {
            const std::uint32_t shift = cookie & 0x1fu;
            const std::uint32_t mixed = pointer ^ cookie;
            encoded = shift == 0u
                ? mixed
                : static_cast<std::uint32_t>(
                      (mixed << shift) | (mixed >> (32u - shift)));
        }
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, encoded);
        return BatchLiftStatus::returned;
    }

    // void* _decode_pointer(void*): the exact inverse of _encode_pointer, so an
    // encoded pointer round-trips through both. A null pointer stays null.
    BatchLiftStatus decode_pointer(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t pointer = call.arguments[0];
        std::uint32_t cookie{};
        if (!memory.load32(kGuestSecurityCookieAddress, cookie)) {
            last_error_ =
                "the guest security cookie is not mapped for _decode_pointer";
            return BatchLiftStatus::invalid_memory;
        }
        std::uint32_t decoded = 0u;
        if (pointer != 0u) {
            const std::uint32_t shift = cookie & 0x1fu;
            const std::uint32_t rotated = shift == 0u
                ? pointer
                : static_cast<std::uint32_t>(
                      (pointer >> shift) | (pointer << (32u - shift)));
            decoded = rotated ^ cookie;
        }
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, decoded);
        return BatchLiftStatus::returned;
    }

    // The engine's format strings only need a small, exact subset. Anything
    // else fails closed instead of producing a wrong string.
    static std::string unsigned_digits(
        std::uint64_t value, unsigned base, bool upper) {
        static const char lower_digits[] = "0123456789abcdef";
        static const char upper_digits[] = "0123456789ABCDEF";
        const char* table = upper ? upper_digits : lower_digits;
        std::string text;
        if (value == 0u) return "0";
        while (value != 0u) {
            text.insert(text.begin(), table[value % base]);
            value /= base;
        }
        return text;
    }

    static std::string pad_left(
        const std::string& text, std::uint32_t width, bool zero_pad,
        const std::string& prefix) {
        const std::size_t length = text.size() + prefix.size();
        if (length >= width) return prefix + text;
        return prefix + std::string(width - length, zero_pad ? '0' : ' ') + text;
    }

    bool read_variadic_arg(
        BatchLiftMemory& memory, std::uint32_t stack_pointer,
        std::uint32_t index, std::uint32_t& value) {
        // Index 0 is the first argument, right above the return address.
        const std::uint64_t address = static_cast<std::uint64_t>(stack_pointer)
            + 4u + static_cast<std::uint64_t>(index) * 4u;
        if (address > 0xffffffffu) {
            last_error_ = "a variadic argument is outside the guest address space";
            return false;
        }
        if (!memory.load32(static_cast<std::uint32_t>(address), value)) {
            last_error_ = "a variadic argument is outside guest memory";
            return false;
        }
        return true;
    }

    bool format_into(
        BatchLiftMemory& memory,
        std::uint32_t stack_pointer,
        const std::string& format,
        std::uint32_t first_argument,
        std::string& out) {
        out.clear();
        std::uint32_t argument = first_argument;
        std::size_t index = 0;
        while (index < format.size()) {
            if (format[index] != '%') {
                out.push_back(format[index++]);
                continue;
            }
            ++index;
            if (index < format.size() && format[index] == '%') {
                out.push_back('%');
                ++index;
                continue;
            }
            bool zero_pad = false;
            std::uint32_t width = 0;
            if (index < format.size() && format[index] == '0') {
                zero_pad = true;
                ++index;
            }
            while (index < format.size() && format[index] >= '0'
                    && format[index] <= '9') {
                width = width * 10u
                    + static_cast<std::uint32_t>(format[index] - '0');
                ++index;
            }
            if (width > 512u) {
                last_error_ = "a guest format width above 512 is not modelled";
                return false;
            }
            bool wide = false;
            if (index + 3u <= format.size()
                    && format.compare(index, 3, "I64") == 0) {
                wide = true;
                index += 3;
            }
            if (index >= format.size()) {
                last_error_ = "a guest format string ends in a conversion";
                return false;
            }
            const char specifier = format[index++];
            if (specifier == 's') {
                std::uint32_t pointer{};
                if (!read_variadic_arg(
                        memory, stack_pointer, argument++, pointer)) {
                    return false;
                }
                std::string text;
                if (pointer == 0u) {
                    text = "(null)";
                } else if (!read_guest_string(memory, pointer, text)) {
                    last_error_ = "%s argument is outside mapped guest memory";
                    return false;
                }
                out += pad_left(text, width, false, {});
                continue;
            }
            std::uint32_t low{}, high{};
            if (!read_variadic_arg(memory, stack_pointer, argument++, low)) {
                return false;
            }
            if (wide && !read_variadic_arg(
                    memory, stack_pointer, argument++, high)) {
                return false;
            }
            const std::uint64_t value =
                (static_cast<std::uint64_t>(high) << 32u) | low;
            switch (specifier) {
            case 'd':
            case 'i': {
                const std::int64_t signed_value = wide
                    ? static_cast<std::int64_t>(value)
                    : static_cast<std::int64_t>(
                          static_cast<std::int32_t>(low));
                const bool negative = signed_value < 0;
                const std::uint64_t magnitude = negative
                    ? ~static_cast<std::uint64_t>(signed_value) + 1u
                    : static_cast<std::uint64_t>(signed_value);
                out += pad_left(unsigned_digits(magnitude, 10u, false), width,
                                zero_pad, negative ? "-" : "");
                break;
            }
            case 'u':
                out += pad_left(unsigned_digits(value, 10u, false), width,
                                zero_pad, {});
                break;
            case 'x':
            case 'X':
                out += pad_left(unsigned_digits(value, 16u, specifier == 'X'),
                                width, zero_pad, {});
                break;
            case 'p':
                out += pad_left(unsigned_digits(value, 16u, false),
                                width == 0u ? 8u : width, true, {});
                break;
            default:
                last_error_ = std::string("guest format conversion '%")
                    + (wide ? "I64" : "") + specifier
                    + "' is not modelled";
                return false;
            }
        }
        return true;
    }

    bool write_guest_string(
        BatchLiftMemory& memory, std::uint32_t destination,
        const std::string& text) {
        if (!memory.is_writable(
                destination, static_cast<std::size_t>(text.size()) + 1u)) {
            last_error_ = "the formatted string destination is not writable";
            return false;
        }
        for (std::size_t index = 0; index < text.size(); ++index) {
            if (!memory.store8(
                    destination + static_cast<std::uint32_t>(index),
                    static_cast<std::uint8_t>(text[index]))) {
                return false;
            }
        }
        return memory.store8(
            destination + static_cast<std::uint32_t>(text.size()), 0u);
    }

    // int sprintf(char* buffer, const char* format, ...): the guest keeps its
    // own buffer, so only the bytes are written. __cdecl: the caller pops.
    BatchLiftStatus sprintf_guest(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t destination = call.arguments[0];
        std::string format;
        if (!read_guest_string(memory, call.arguments[1], format)) {
            last_error_ = "sprintf format is outside mapped guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        std::string text;
        if (!format_into(memory, state.regs[4], format, 2u, text)) {
            return BatchLiftStatus::unsupported_dependency;
        }
        if (!write_guest_string(memory, destination, text)) {
            return BatchLiftStatus::invalid_memory;
        }
        calls_.back().text = text;
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup,
                          static_cast<std::uint32_t>(text.size()));
        return BatchLiftStatus::returned;
    }

    // int wsprintfA(char* buffer, const char* format, ...): the same formatter
    // under the documented 1024-byte limit of the USER32 routine.
    BatchLiftStatus wsprintf_guest(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t destination = call.arguments[0];
        std::string format;
        if (!read_guest_string(memory, call.arguments[1], format)) {
            last_error_ = "wsprintfA format is outside mapped guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        std::string text;
        if (!format_into(memory, state.regs[4], format, 2u, text)) {
            return BatchLiftStatus::unsupported_dependency;
        }
        if (text.size() >= 1024u) {
            last_error_ = "wsprintfA produced 1024 bytes or more";
            return BatchLiftStatus::unsupported_dependency;
        }
        if (!write_guest_string(memory, destination, text)) {
            return BatchLiftStatus::invalid_memory;
        }
        calls_.back().text = text;
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup,
                          static_cast<std::uint32_t>(text.size()));
        return BatchLiftStatus::returned;
    }

    // unsigned __int64 _strtoui64(const char*, char**, int): the guest reads
    // only EAX here, but the high half goes to EDX as the ABI requires.
    BatchLiftStatus strtoui64_guest(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        std::string text;
        if (call.arguments[0] != 0u
                && !read_guest_string(memory, call.arguments[0], text)) {
            last_error_ = "_strtoui64 text is outside mapped guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        const std::uint32_t base = call.arguments[2];
        if (base != 0u && (base < 2u || base > 36u)) {
            state.regs[0] = 0u;
            state.regs[2] = 0u;
            if (call.arguments[1] != 0u
                    && !memory.store32(call.arguments[1], call.arguments[0])) {
                return BatchLiftStatus::invalid_memory;
            }
            complete_api_call(state, call, call.return_address,
                              kGuestCdeclCleanup, 0u);
            return BatchLiftStatus::returned;
        }
        std::size_t consumed = 0;
        std::uint64_t value = 0u;
        while (consumed < text.size()
                && (text[consumed] == ' ' || text[consumed] == '\t')) {
            ++consumed;
        }
        const std::size_t digits_start = consumed;
        for (; consumed < text.size(); ++consumed) {
            const char character = text[consumed];
            std::uint32_t digit = 64u;
            if (character >= '0' && character <= '9') {
                digit = static_cast<std::uint32_t>(character - '0');
            } else if (character >= 'a' && character <= 'z') {
                digit = static_cast<std::uint32_t>(character - 'a') + 10u;
            } else if (character >= 'A' && character <= 'Z') {
                digit = static_cast<std::uint32_t>(character - 'A') + 10u;
            }
            const std::uint32_t radix = base == 0u ? 16u : base;
            if (digit >= radix) break;
            value = value * radix + digit;
        }
        if (call.arguments[1] != 0u) {
            const std::uint32_t remaining = consumed > digits_start
                ? static_cast<std::uint32_t>(text.size() - consumed)
                : static_cast<std::uint32_t>(text.size());
            if (!memory.store32(call.arguments[1],
                                call.arguments[0] + remaining)) {
                return BatchLiftStatus::invalid_memory;
            }
        }
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup,
                          static_cast<std::uint32_t>(value));
        state.regs[2] = static_cast<std::uint32_t>(value >> 32u);
        calls_.back().result = static_cast<std::uint32_t>(value);
        return BatchLiftStatus::returned;
    }

    // HANDLE GetProcessHeap(void)
    BatchLiftStatus get_process_heap(
        BatchLiftState& state, BatchGuestImportCall& call) {
        complete_api_call(state, call, call.return_address, 0u,
                          kGuestProcessHeapHandle);
        return BatchLiftStatus::returned;
    }
    // LPVOID HeapAlloc(HANDLE, DWORD, SIZE_T): a bump allocator inside the
    // guest heap window. Blocks are never reused, so an address stays valid for
    // the whole run, which is what the engine node stores.
    BatchLiftStatus heap_alloc(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint32_t bytes = call.arguments[2];
        const std::uint32_t rounded = (bytes + 0x0fu) & ~0x0fu;
        const std::uint32_t offset = heap_used_;
        if (call.arguments[0] != kGuestProcessHeapHandle
                || bytes == 0u
                || offset > kGuestHeapBytes - rounded) {
            set_guest_error(state, 8u,
                            "HeapAlloc is outside the modelled guest heap");
            complete_api_call(state, call, call.return_address, 12u, 0u);
            return BatchLiftStatus::returned;
        }
        heap_used_ = offset + rounded;
        complete_api_call(state, call, call.return_address, 12u,
                          kGuestHeapBase + offset);
        return BatchLiftStatus::returned;
    }

    // BOOL HeapFree(HANDLE, DWORD, LPVOID)
    BatchLiftStatus heap_free(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint32_t address = call.arguments[2];
        const bool inside = call.arguments[0] == kGuestProcessHeapHandle
            && address >= kGuestHeapBase
            && address < kGuestHeapBase + kGuestHeapBytes;
        if (!inside) {
            set_guest_error(state, 87u,
                            "HeapFree received a pointer outside the guest heap");
            complete_api_call(state, call, call.return_address, 12u, 0u);
            return BatchLiftStatus::returned;
        }
        complete_api_call(state, call, call.return_address, 12u, 1u);
        return BatchLiftStatus::returned;
    }

    // HANDLE GetCurrentThread(void): the guest runs one thread, so the
    // pseudo-handle Windows returns for the calling thread is a constant.
    BatchLiftStatus get_current_thread(
        BatchLiftState& state, BatchGuestImportCall& call) {
        complete_api_call(state, call, call.return_address, 0u, 0xfffffffeu);
        return BatchLiftStatus::returned;
    }

    // int GetThreadPriority(HANDLE): the one guest thread runs at normal.
    BatchLiftStatus get_thread_priority(
        BatchLiftState& state, BatchGuestImportCall& call) {
        complete_api_call(state, call, call.return_address, 4u, 0u);
        return BatchLiftStatus::returned;
    }

    // void GetSystemInfo(LPSYSTEM_INFO): one x86 processor, 4 KiB pages and the
    // documented 64 KiB allocation granularity, fixed so every host agrees.
    BatchLiftStatus get_system_info(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t address = call.arguments[0];
        if (!memory.is_writable(address, kSystemInfoBytes)) {
            last_error_ = "GetSystemInfo target is not writable guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        const std::uint32_t words[kSystemInfoBytes / 4u] = {
            0x00000000u,  // wProcessorArchitecture (x86) and wReserved
            0x00001000u,  // dwPageSize
            0x00010000u,  // lpMinimumApplicationAddress
            0x7ffeffffu,  // lpMaximumApplicationAddress
            0x00000001u,  // dwActiveProcessorMask
            0x00000001u,  // dwNumberOfProcessors
            0x00000000u,  // dwProcessorType
            0x00010000u,  // dwAllocationGranularity
            0x00000000u,  // wProcessorLevel and wProcessorRevision
        };
        for (std::uint32_t index = 0; index < kSystemInfoBytes / 4u; ++index) {
            if (!memory.store32(address + index * 4u, words[index])) {
                last_error_ = "GetSystemInfo target changed after validation";
                return BatchLiftStatus::invalid_memory;
            }
        }
        complete_api_call(state, call, call.return_address, 4u, 0u);
        return BatchLiftStatus::returned;
    }

    // LONG InterlockedDecrement(LPLONG): the value is read and written through
    // guest memory and the subtraction flags follow the locked operation.
    BatchLiftStatus interlocked_decrement(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        std::uint32_t value{};
        if (!memory.load32(call.arguments[0], value)) {
            last_error_ = "InterlockedDecrement target is outside guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        const std::uint32_t next = static_cast<std::uint32_t>(value - 1u);
        if (!memory.store32(call.arguments[0], next)) {
            last_error_ = "InterlockedDecrement target changed after validation";
            return BatchLiftStatus::invalid_memory;
        }
        batch_set_add_flags(state, value, 0xffffffffu, next, 32u);
        complete_api_call(state, call, call.return_address, 4u, next);
        return BatchLiftStatus::returned;
    }

    // HANDLE DuplicateHandle(...): one process owns every handle here, so the
    // duplicate is the same guest handle value written to the output slot.
    BatchLiftStatus duplicate_handle(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t output = call.arguments[3];
        if (!memory.is_writable(output, 4u)) {
            set_guest_error(state, 87u,
                            "DuplicateHandle output is not writable");
            complete_api_call(state, call, call.return_address, 28u, 0u);
            return BatchLiftStatus::returned;
        }
        const std::uint32_t duplicate = call.arguments[1];
        if (!memory.store32(output, duplicate)) {
            last_error_ = "DuplicateHandle output changed after validation";
            return BatchLiftStatus::invalid_memory;
        }
        complete_api_call(state, call, call.return_address, 28u, 1u);
        return BatchLiftStatus::returned;
    }

    // DWORD SleepEx(DWORD, BOOL): the guest has no scheduler to yield to, so
    // the delay is recorded and no APC is reported as delivered.
    BatchLiftStatus sleep_ex(
        BatchLiftState& state, BatchGuestImportCall& call) {
        complete_api_call(state, call, call.return_address, 8u, 0u);
        return BatchLiftStatus::returned;
    }

    // BOOL TlsSetValue(DWORD, LPVOID): per-index values for the one thread.
    BatchLiftStatus tls_set_value(
        BatchLiftState& state, BatchGuestImportCall& call) {
        tls_values_[call.arguments[0]] = call.arguments[1];
        complete_api_call(state, call, call.return_address, 8u, 1u);
        return BatchLiftStatus::returned;
    }

    // LPVOID VirtualAlloc(LPVOID, SIZE_T, DWORD, DWORD): the guest models no
    // page protection. A reservation only claims address space inside the
    // reserve arena; a commit maps the requested 4 KiB pages from the pool.
    BatchLiftStatus virtual_alloc(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t requested = call.arguments[0];
        const std::uint32_t bytes = call.arguments[1];
        const std::uint32_t kind = call.arguments[2];
        const bool reserve = (kind & 0x2000u) != 0u;
        const bool commit = (kind & 0x1000u) != 0u;
        const std::string detail = " (address=0x" + hex32(requested)
            + " size=0x" + hex32(bytes) + " type=0x" + hex32(kind) + ")";
        if (bytes == 0u || (!reserve && !commit)) {
            set_guest_error(state, 87u,
                std::string("VirtualAlloc received a request the guest cannot honour")
                + detail);
            complete_api_call(state, call, call.return_address, 16u, 0u);
            return BatchLiftStatus::returned;
        }
        std::uint32_t base = requested;
        if (!reserve) {
            if (base == 0u || !memory.is_readable(base, 1u)
                    || !memory.is_writable(base, 1u)) {
                set_guest_error(state, 487u,
                    std::string("VirtualAlloc commit names an address the guest "
                                "did not reserve") + detail);
                complete_api_call(state, call, call.return_address, 16u, 0u);
                return BatchLiftStatus::returned;
            }
            complete_api_call(state, call, call.return_address, 16u, base);
            return BatchLiftStatus::returned;
        }
        if (base == 0u) {
            base = kGuestVirtualArenaBase + virtual_arena_used_;
        }
        if (base < kGuestVirtualArenaBase
                || base >= kGuestVirtualArenaBase + kGuestVirtualArenaBytes
                || bytes > kGuestVirtualArenaBytes
                    - (base - kGuestVirtualArenaBase)) {
            set_guest_error(state, 87u,
                std::string("VirtualAlloc reservation is outside the guest "
                            "arena") + detail);
            complete_api_call(state, call, call.return_address, 16u, 0u);
            return BatchLiftStatus::returned;
        }
        if (commit) {
            const std::uint32_t rounded = (bytes + 0xfffu) & ~0xfffu;
            if (virtual_committed_ + rounded > kGuestVirtualCommitLimitBytes) {
                set_guest_error(state, 8u,
                    std::string("the guest reached its committed-memory limit")
                    + detail);
                complete_api_call(state, call, call.return_address, 16u, 0u);
                return BatchLiftStatus::returned;
            }
            auto block = std::make_unique<std::uint8_t[]>(rounded);
            if (!memory.map_region(base, block.get(), rounded, true)) {
                set_guest_error(state, 8u,
                    std::string("the guest region table cannot map another "
                                "commit") + detail);
                complete_api_call(state, call, call.return_address, 16u, 0u);
                return BatchLiftStatus::returned;
            }
            virtual_commits_.push_back(std::move(block));
            virtual_committed_ += rounded;
        }
        virtual_arena_used_ = base - kGuestVirtualArenaBase + bytes;
        virtual_arena_used_ = (virtual_arena_used_ + 0xfffu) & ~0xfffu;
        complete_api_call(state, call, call.return_address, 16u, base);
        return BatchLiftStatus::returned;
    }

    // BOOL VirtualFree(LPVOID, SIZE_T, DWORD): nothing in this port observes a
    // re-used page, so a release is accepted and the mapping stays.
    BatchLiftStatus virtual_free(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        if (!memory.is_readable(call.arguments[0], 1u)) {
            set_guest_error(state, 87u,
                            "VirtualFree received an address the guest does not map");
            complete_api_call(state, call, call.return_address, 12u, 0u);
            return BatchLiftStatus::returned;
        }
        complete_api_call(state, call, call.return_address, 12u, 1u);
        return BatchLiftStatus::returned;
    }

    // SIZE_T VirtualQuery(LPCVOID, PMEMORY_BASIC_INFORMATION, SIZE_T)
    BatchLiftStatus virtual_query(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t probe = call.arguments[0];
        const std::uint32_t output = call.arguments[1];
        const std::uint32_t size = call.arguments[2];
        std::uint32_t base = 0, region = 0;
        if (size < kMemoryBasicInformationBytes) {
            set_guest_error(state, 87u,
                            "VirtualQuery buffer is smaller than one MBI");
            complete_api_call(state, call, call.return_address, 12u, 0u);
            return BatchLiftStatus::returned;
        }
        if (!memory.is_writable(output, kMemoryBasicInformationBytes)) {
            last_error_ = "VirtualQuery output is not writable guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        if (!memory.region_bounds(probe, base, region)) {
            set_guest_error(state, 87u, "VirtualQuery address is not mapped");
            complete_api_call(state, call, call.return_address, 12u, 0u);
            return BatchLiftStatus::returned;
        }
        const std::uint32_t fields[kMemoryBasicInformationBytes / 4u] = {
            probe,      // BaseAddress
            base,       // AllocationBase
            0x04u,      // AllocationProtect (PAGE_READWRITE)
            region,     // RegionSize
            0x1000u,    // State (MEM_COMMIT)
            0x04u,      // Protect (PAGE_READWRITE)
            0x20000u,   // Type (MEM_PRIVATE)
        };
        for (std::uint32_t index = 0; index < kMemoryBasicInformationBytes / 4u;
             ++index) {
            if (!memory.store32(output + index * 4u, fields[index])) {
                last_error_ = "VirtualQuery output changed after validation";
                return BatchLiftStatus::invalid_memory;
            }
        }
        complete_api_call(state, call, call.return_address, 12u,
                          kMemoryBasicInformationBytes);
        return BatchLiftStatus::returned;
    }

    // void *memcpy(void*, const void*, size_t)
    BatchLiftStatus memcpy_guest(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t destination = call.arguments[0];
        const std::uint32_t source = call.arguments[1];
        const std::uint32_t count = call.arguments[2];
        if (count != 0u
                && (!memory.is_readable(source, count)
                    || !memory.is_writable(destination, count))) {
            last_error_ = "memcpy range is outside mapped guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        // An overlap is served like memmove: the source is read first.
        std::vector<std::uint8_t> staging(count);
        for (std::uint32_t offset = 0; offset < count; ++offset) {
            std::uint32_t byte{};
            if (!memory.load8(source + offset, byte)) {
                last_error_ = "memcpy source is outside guest memory";
                return BatchLiftStatus::invalid_memory;
            }
            staging[offset] = static_cast<std::uint8_t>(byte);
        }
        for (std::uint32_t offset = 0; offset < count; ++offset) {
            if (!memory.store8(destination + offset, staging[offset])) {
                last_error_ = "memcpy destination is outside guest memory";
                return BatchLiftStatus::invalid_memory;
            }
        }
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, destination);
        return BatchLiftStatus::returned;
    }

    // int _stricmp(const char*, const char*)
    BatchLiftStatus stricmp_guest(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        std::string left, right;
        if (!read_guest_string(memory, call.arguments[0], left)
                || !read_guest_string(memory, call.arguments[1], right)) {
            last_error_ = "_stricmp argument is not a readable guest string";
            return BatchLiftStatus::invalid_memory;
        }
        const auto fold = [](char value) {
            const unsigned char raw = static_cast<unsigned char>(value);
            return raw >= 'A' && raw <= 'Z'
                ? static_cast<unsigned char>(raw - 'A' + 'a') : raw;
        };
        std::int32_t result = 0;
        for (std::size_t index = 0;; ++index) {
            const unsigned char a = index < left.size()
                ? fold(left[index]) : 0u;
            const unsigned char b = index < right.size()
                ? fold(right[index]) : 0u;
            if (a != b) {
                result = a < b ? -1 : 1;
                break;
            }
            if (a == 0u) break;
        }
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup,
                          static_cast<std::uint32_t>(result));
        return BatchLiftStatus::returned;
    }

    // int isalpha(int)
    BatchLiftStatus isalpha_guest(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint32_t value = call.arguments[0] & 0xffu;
        const bool alpha = (value >= 'A' && value <= 'Z')
            || (value >= 'a' && value <= 'z');
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, alpha ? 1u : 0u);
        return BatchLiftStatus::returned;
    }

    // int tolower(int): ASCII only, which is what the C locale the guest runs
    // under defines. A byte outside A-Z is returned unchanged.
    BatchLiftStatus tolower_guest(
        BatchLiftState& state, BatchGuestImportCall& call) {
        std::uint32_t value = call.arguments[0] & 0xffu;
        if (value >= 'A' && value <= 'Z') value += 32u;
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, value);
        return BatchLiftStatus::returned;
    }

    // The two classification helpers take a double, so the two stack slots are
    // read as one 64-bit value and inspected by bit pattern: that is what the CRT
    // does, and it avoids depending on host floating-point behaviour.
    static std::uint64_t double_bits(const BatchGuestImportCall& call) {
        const std::uint64_t low = call.arguments[0];
        const std::uint64_t high = call.arguments[1];
        return low | (high << 32u);
    }

    // int _finite(double): nonzero when the exponent field is not all ones, so
    // NaN and both infinities report zero.
    BatchLiftStatus finite_guest(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint64_t bits = double_bits(call);
        const bool finite = ((bits >> 52u) & 0x7ffu) != 0x7ffu;
        complete_api_call(state, call, call.return_address, 8u,
                          finite ? 1u : 0u);
        return BatchLiftStatus::returned;
    }

    // int _isnan(double): all-ones exponent with a non-zero mantissa.
    BatchLiftStatus isnan_guest(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint64_t bits = double_bits(call);
        const bool exp_all_ones = ((bits >> 52u) & 0x7ffu) == 0x7ffu;
        const bool mantissa = (bits & 0xfffffffffffffull) != 0u;
        complete_api_call(state, call, call.return_address, 8u,
                          (exp_all_ones && mantissa) ? 1u : 0u);
        return BatchLiftStatus::returned;
    }

    // void _purecall(void): a pure virtual call terminates the process in the
    // real CRT. The guest has no process to end, so it fails closed and says so
    // rather than pretending the call returned.
    BatchLiftStatus purecall_guest(BatchGuestImportCall& call) {
        last_error_ = "_purecall: pure virtual call reached from 0x"
            + hex32(call.return_address);
        return BatchLiftStatus::unsupported_dependency;
    }

    // void OutputDebugStringA(LPCSTR): the guest has no debugger attached, so the
    // call is accepted and has no effect. The pointer is validated so a bad one
    // still fails instead of being ignored.
    BatchLiftStatus output_debug_string(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t text = call.arguments[0];
        if (text != 0u && !memory.is_readable(text, 1u)) {
            last_error_ = "OutputDebugStringA received a pointer outside guest "
                          "memory";
            return BatchLiftStatus::invalid_memory;
        }
        if (text != 0u) {
            std::string ignored;
            if (!read_guest_string(memory, text, ignored)) {
                last_error_ = "OutputDebugStringA string runs outside guest memory";
                return BatchLiftStatus::invalid_memory;
            }
        }
        complete_api_call(state, call, call.return_address, 4u, 0u);
        return BatchLiftStatus::returned;
    }

    // int WideCharToMultiByte(cp, flags, src, cchWide, dst, cbMulti, defchar,
    // used): the guest only converts its own identifiers, so a byte-per-unit
    // conversion is exact for ASCII and falls back to the default character for
    // anything above 0xFF. A NULL destination is the sizing call.
    BatchLiftStatus wide_char_to_multi_byte(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t source = call.arguments[2];
        const std::int32_t wide_length =
            static_cast<std::int32_t>(call.arguments[3]);
        const std::uint32_t destination = call.arguments[4];
        const std::int32_t destination_bytes =
            static_cast<std::int32_t>(call.arguments[5]);
        const std::uint32_t default_char = call.arguments[6];
        const std::uint32_t used = call.arguments[7];
        if (source == 0u) {
            last_error_ = "WideCharToMultiByte received a null source";
            complete_api_call(state, call, call.return_address, 32u, 0u);
            return BatchLiftStatus::returned;
        }
        std::vector<std::uint8_t> converted;
        for (std::int32_t index = 0; ; ++index) {
            if (wide_length >= 0 && index >= wide_length) break;
            std::uint32_t unit{};
            if (!memory.load16(source + static_cast<std::uint32_t>(index) * 2u,
                               unit)) {
                last_error_ = "WideCharToMultiByte source is outside guest "
                              "memory";
                return BatchLiftStatus::invalid_memory;
            }
            if (wide_length < 0 && unit == 0u) break;
            converted.push_back(unit <= 0xffu
                ? static_cast<std::uint8_t>(unit)
                : static_cast<std::uint8_t>(default_char & 0xffu));
        }
        const std::uint32_t count =
            static_cast<std::uint32_t>(converted.size());
        if (destination != 0u && destination_bytes > 0) {
            const std::uint32_t written =
                static_cast<std::uint32_t>(destination_bytes) < count
                ? static_cast<std::uint32_t>(destination_bytes) : count;
            for (std::uint32_t index = 0; index < written; ++index) {
                if (!memory.store8(destination + index, converted[index])) {
                    last_error_ = "WideCharToMultiByte destination is outside "
                                  "guest memory";
                    return BatchLiftStatus::invalid_memory;
                }
            }
            if (used != 0u && !memory.store32(used, written)) {
                last_error_ = "WideCharToMultiByte counter is outside guest "
                              "memory";
                return BatchLiftStatus::invalid_memory;
            }
            complete_api_call(state, call, call.return_address, 32u, written);
            return BatchLiftStatus::returned;
        }
        complete_api_call(state, call, call.return_address, 32u, count);
        return BatchLiftStatus::returned;
    }

    // DWORD GetEnvironmentVariableA(LPCSTR, LPSTR, DWORD): the guest keeps its
    // own environment, so a variable the same run set is visible again.
    BatchLiftStatus get_environment_variable(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        std::string name;
        if (!read_guest_string(memory, call.arguments[0], name)) {
            last_error_ =
                "GetEnvironmentVariableA name is outside mapped guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        const auto found = environment_.find(name);
        if (found == environment_.end()) {
            set_guest_error(state, 203u, {});
            complete_api_call(state, call, call.return_address, 12u, 0u);
            return BatchLiftStatus::returned;
        }
        const std::string& value = found->second;
        const std::uint32_t required =
            static_cast<std::uint32_t>(value.size()) + 1u;
        if (call.arguments[1] == 0u || call.arguments[2] < required) {
            complete_api_call(state, call, call.return_address, 12u, required);
            return BatchLiftStatus::returned;
        }
        if (!write_guest_string(memory, call.arguments[1], value)) {
            return BatchLiftStatus::invalid_memory;
        }
        complete_api_call(state, call, call.return_address, 12u,
                          static_cast<std::uint32_t>(value.size()));
        return BatchLiftStatus::returned;
    }

    // BOOL SetEnvironmentVariableA(LPCSTR, LPCSTR)
    BatchLiftStatus set_environment_variable(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        std::string name;
        if (!read_guest_string(memory, call.arguments[0], name)) {
            last_error_ =
                "SetEnvironmentVariableA name is outside mapped guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        if (call.arguments[1] == 0u) {
            environment_.erase(name);
            complete_api_call(state, call, call.return_address, 8u, 1u);
            return BatchLiftStatus::returned;
        }
        std::string value;
        if (!read_guest_string(memory, call.arguments[1], value)) {
            last_error_ =
                "SetEnvironmentVariableA value is outside mapped guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        environment_[name] = value;
        calls_.back().text = value;
        complete_api_call(state, call, call.return_address, 8u, 1u);
        return BatchLiftStatus::returned;
    }

    // DWORD WaitForSingleObject(HANDLE, DWORD): the guest is single threaded,
    // so an existing mutex is acquired immediately and INFINITE never waits.
    BatchLiftStatus wait_for_single_object(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint32_t handle = call.arguments[0];
        const auto found = handle_objects_.find(handle);
        if (found == handle_objects_.end()
                || found->second->type != KernelObjectType::mutex) {
            set_guest_error(state, 6u,
                            "WaitForSingleObject received an invalid handle");
            complete_api_call(state, call, call.return_address, 8u,
                              0xffffffffu);
            return BatchLiftStatus::returned;
        }
        found->second->mutex.lock();
        owned_mutexes_.push_back(handle);
        complete_api_call(state, call, call.return_address, 8u, 0u);
        return BatchLiftStatus::returned;
    }

    // BOOL ReleaseMutex(HANDLE)
    BatchLiftStatus release_mutex(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint32_t handle = call.arguments[0];
        const auto owned = std::find(
            owned_mutexes_.begin(), owned_mutexes_.end(), handle);
        const auto found = handle_objects_.find(handle);
        if (owned == owned_mutexes_.end() || found == handle_objects_.end()) {
            set_guest_error(state, 288u,
                            "ReleaseMutex called by a non-owner");
            complete_api_call(state, call, call.return_address, 4u, 0u);
            return BatchLiftStatus::returned;
        }
        found->second->mutex.unlock();
        owned_mutexes_.erase(owned);
        complete_api_call(state, call, call.return_address, 4u, 1u);
        return BatchLiftStatus::returned;
    }

    // BOOL CloseHandle(HANDLE): the handle stops naming an object. Host-side
    // kernel objects stay open until the run ends, so nothing is closed twice.
    BatchLiftStatus close_handle(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint32_t handle = call.arguments[0];
        const auto found = handle_objects_.find(handle);
        if (found == handle_objects_.end()) {
            set_guest_error(state, 6u, "CloseHandle received an invalid handle");
            complete_api_call(state, call, call.return_address, 4u, 0u);
            return BatchLiftStatus::returned;
        }
        const auto owned = std::find(
            owned_mutexes_.begin(), owned_mutexes_.end(), handle);
        if (owned != owned_mutexes_.end()) {
            found->second->mutex.unlock();
            owned_mutexes_.erase(owned);
        }
        handle_objects_.erase(found);
        complete_api_call(state, call, call.return_address, 4u, 1u);
        return BatchLiftStatus::returned;
    }

    // LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(filter)
    BatchLiftStatus set_unhandled_exception_filter(
        BatchLiftState& state, BatchGuestImportCall& call) {
        const std::uint32_t previous = state.unhandled_filter;
        state.unhandled_filter = call.arguments[0];
        complete_api_call(state, call, call.return_address, 4u, previous);
        return BatchLiftStatus::returned;
    }

    // errno_t _controlfp_s(unsigned* current, unsigned new_control,
    //                      unsigned mask)
    BatchLiftStatus controlfp_s(
        BatchLiftMemory& memory, BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t current_pointer = call.arguments[0];
        const std::uint32_t requested = call.arguments[1];
        const std::uint32_t mask = call.arguments[2];
        if (current_pointer != 0u) {
            if (!memory.is_writable(current_pointer, 4u)
                    || !memory.store32(current_pointer,
                                       state.x87_control_word)) {
                last_error_ =
                    "_controlfp_s current pointer is outside writable guest "
                    "memory";
                return BatchLiftStatus::invalid_memory;
            }
        }
        if (current_pointer == 0u && mask == 0u) {
            // Query only.
            complete_api_call(state, call, call.return_address,
                              kGuestCdeclCleanup, state.x87_control_word);
            return BatchLiftStatus::returned;
        }
        state.x87_control_word =
            (state.x87_control_word & ~mask) | (requested & mask);
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, 0u);
        return BatchLiftStatus::returned;
    }

    // void _invoke_watson(...): terminates the process after reporting. The
    // guest has no process to end, so it fails closed.
    BatchLiftStatus invoke_watson(BatchGuestImportCall& call) {
        last_error_ = "_invoke_watson is fatal in the guest";
        (void)call;
        return BatchLiftStatus::unsupported_dependency;
    }

    // void terminate(void): the CRT calls std::terminate on unhandled paths.
    BatchLiftStatus terminate(BatchGuestImportCall& call) {
        last_error_ = "std::terminate is fatal in the guest";
        (void)call;
        return BatchLiftStatus::unsupported_dependency;
    }

    // int _initterm_e(_PIFV* begin, _PIFV* end): walk the guest table, skip null
    // entries and stop at the first initializer that returns nonzero.
    BatchLiftStatus initterm_e(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t begin = call.arguments[0];
        const std::uint32_t end = call.arguments[1];
        if (end < begin || ((end - begin) % 4u) != 0u
                || !memory.is_readable(begin, end - begin)) {
            last_error_ =
                "_initterm_e table bounds are outside readable guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        std::uint32_t result = 0;
        for (std::uint32_t slot = begin; slot < end; slot += 4u) {
            std::uint32_t target{};
            if (!memory.load32(slot, target)) {
                last_error_ = "_initterm_e table changed after validation";
                return BatchLiftStatus::invalid_memory;
            }
            if (target == 0u) continue;
            const auto body = guest_functions_.find(target);
            if (body == guest_functions_.end()) {
                last_error_ = "_initterm_e needs a lifted body for 0x"
                    + hex32(target);
                return BatchLiftStatus::unsupported_dependency;
            }
            const std::uint32_t entry_esp = state.regs[4];
            if (!batch_guest_call32(
                    memory, state, target, kBatchGuestInitializerReturn)) {
                return BatchLiftStatus::invalid_memory;
            }
            const BatchLiftStatus status = body->second(memory, state);
            if (status != BatchLiftStatus::returned) return status;
            if (state.eip != kBatchGuestInitializerReturn
                    || state.regs[4] != entry_esp) {
                return BatchLiftStatus::invalid_control_flow;
            }
            result = state.regs[0];
            if (result != 0u) break;
        }
        // The guest pops both table arguments itself right after the call.
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, result);
        return BatchLiftStatus::returned;
    }

    // void _initterm(_PVFV* begin, _PVFV* end): walk the guest table, skip null
    // entries and call every initializer. It returns void and never stops on a
    // result. An address without a compiled body fails closed and names itself,
    // so the walk can never pretend a constructor ran.
    BatchLiftStatus initterm(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t begin = call.arguments[0];
        const std::uint32_t end = call.arguments[1];
        // The table spans 124 KiB of real PE data but the guest image maps only
        // the slots a batch can reach, so readability is checked per slot.
        if (end < begin || ((end - begin) % 4u) != 0u) {
            last_error_ = "_initterm table bounds are not a pointer array";
            return BatchLiftStatus::invalid_memory;
        }
        for (std::uint32_t slot = begin; slot < end; slot += 4u) {
            std::uint32_t target{};
            if (!memory.load32(slot, target)) {
                last_error_ = "_initterm table slot 0x" + hex32(slot)
                    + " is outside mapped guest memory";
                return BatchLiftStatus::invalid_memory;
            }
            if (target == 0u) continue;
            const auto neutralized = neutralized_bodies_.find(target);
            const auto body = guest_functions_.find(target);
            if (body == guest_functions_.end()
                    && neutralized == neutralized_bodies_.end()) {
                // The table entry the batch does not register is the walk's
                // boundary, so it is left in EIP and named in the error.
                state.eip = target;
                last_error_ =
                    "_initterm needs a lifted body for 0x" + hex32(target);
                return BatchLiftStatus::unsupported_dependency;
            }
            const std::uint32_t entry_esp = state.regs[4];
            if (!batch_guest_call32(
                    memory, state, target, kBatchGuestInitializerReturn)) {
                return BatchLiftStatus::invalid_memory;
            }
            const BatchLiftStatus status =
                neutralized != neutralized_bodies_.end()
                ? neutralized->second.body(*this, memory, state)
                : body->second(memory, state);
            if (status != BatchLiftStatus::returned) return status;
            if (state.eip != kBatchGuestInitializerReturn
                    || state.regs[4] != entry_esp) {
                return BatchLiftStatus::invalid_control_flow;
            }
            // Counted only after the body returned and the frame came back, so
            // the number is what actually ran and not what was attempted.
            ++initializers_completed_;
            last_initializer_ = target;
        }
        complete_api_call(state, call, call.return_address,
                          kGuestCdeclCleanup, 0u);
        return BatchLiftStatus::returned;
    }

    // void _amsg_exit(int errnum): the real routine prints the CRT message and
    // terminates the process. The guest has no process to end, so it fails
    // closed instead of pretending to continue.
    BatchLiftStatus amsg_exit(BatchGuestImportCall& call) {
        last_error_ = "_amsg_exit is fatal in the guest for error type 0x"
            + hex32(call.arguments[0]);
        return BatchLiftStatus::unsupported_dependency;
    }

    static std::string hex32(std::uint32_t value) {
        static const char digits[] = "0123456789abcdef";
        std::string text(8, '0');
        for (int index = 7; index >= 0; --index) {
            text[static_cast<std::size_t>(index)] = digits[value & 0xfu];
            value >>= 4u;
        }
        return text;
    }

    BatchLiftStatus interlocked_compare_exchange(        BatchLiftMemory& memory,
        BatchLiftState& state,
        BatchGuestImportCall& call) {
        const std::uint32_t destination = call.arguments[0];
        const std::uint32_t exchange = call.arguments[1];
        const std::uint32_t comparand = call.arguments[2];
        std::uint32_t previous{};
        if (!memory.is_writable(destination, 4u)
                || !memory.load32(destination, previous)) {
            last_error_ =
                "InterlockedCompareExchange destination is outside writable "
                "guest memory";
            return BatchLiftStatus::invalid_memory;
        }
        // The guest executes a single thread, so the compare-exchange is
        // atomic by construction and needs no host side lock.
        if (previous == comparand
                && !memory.store32(destination, exchange)) {
            last_error_ =
                "InterlockedCompareExchange destination changed after "
                "validation";
            return BatchLiftStatus::invalid_memory;
        }
        complete_api_call(state, call, call.return_address, 12u, previous);
        return BatchLiftStatus::returned;
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
        calls_.back().text = name;

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

    BatchLiftStatus initialize_critical_section_registered(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call,
        std::uint32_t argument_bytes,
        std::uint32_t result) {
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
        complete_import_call(state, return_address, argument_bytes);
        state.regs[0] = result;
        return BatchLiftStatus::returned;
    }

    BatchLiftStatus initialize_critical_section(
        BatchLiftMemory& memory,
        BatchLiftState& state,
        const BatchGuestImportCall& call) {
        return initialize_critical_section_registered(
            memory, state, call, 4u, 0u);
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
    std::unordered_map<std::uint32_t, GuestFunction> guest_functions_;
    // PE bodies the port deliberately does not lift, each paired with the
    // written contract its neutralized implementation upholds.
    struct NeutralizedBodyEntry {
        std::string note;
        NeutralizedBody body;
    };
    std::unordered_map<std::uint32_t, NeutralizedBodyEntry> neutralized_bodies_;
    // Loader-fixup labels written into the mapped import slots, keyed by the
    // trampoline address the slot now holds.
    std::unordered_map<std::uint32_t, std::string> import_trampolines_;
    // Guest heap cursor, the mutexes this run acquired, and the guest
    // environment the engine reads back through the Win32 API.
    std::uint32_t heap_used_{};
    std::vector<std::uint32_t> owned_mutexes_;
    std::unordered_map<std::string, std::string> environment_;
    // The guest TLS allocator hands out indices from zero upward.
    std::uint32_t tls_indexes_{};
    std::uint32_t initializers_completed_{};
    std::uint32_t last_initializer_{};
    std::unordered_map<std::uint32_t, std::uint32_t> tls_values_;
    // VirtualAlloc's committed blocks and how many bytes they total.
    std::vector<std::unique_ptr<std::uint8_t[]>> virtual_commits_;
    std::uint64_t virtual_committed_{};
    std::uint32_t virtual_arena_used_{};
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
