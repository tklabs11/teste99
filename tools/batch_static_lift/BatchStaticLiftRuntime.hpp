#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

enum class BatchLiftStatus {
    returned,
    invalid_memory,
    invalid_control_flow,
    unsupported_import,
    synchronization_error,
    invalid_x87_state,
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

    std::array<Region, 8> regions_{};
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
};

class BatchGuestRuntime final : public BatchGuestImportDispatcher {
public:
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
        calls_.push_back(call);
        last_error_.clear();

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
        if (call.symbol == "KERNEL32.dll!CreateMutexA") {
            last_error_ = "not implemented: " + call.symbol;
            return BatchLiftStatus::unsupported_import;
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

    bool has_critical_section(std::uint32_t guest_address) const {
        std::lock_guard<std::mutex> lock(registry_mutex_);
        return critical_sections_.find(guest_address) != critical_sections_.end();
    }

private:
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
        return 0u;
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
};
