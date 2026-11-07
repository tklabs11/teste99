#include "BatchStaticLiftRuntime.hpp"

#include <array>
#include <cstdint>
#include <cstdio>

constexpr std::uint32_t kWritable = 0x21000000u;
constexpr std::uint32_t kReadOnly = 0x22000000u;
constexpr std::uint32_t kReturn = 0x00401005u;
constexpr std::uint32_t kIat = 0x013cc478u;

BatchLiftStatus call_memset(BatchLiftMemory& memory, BatchGuestRuntime& runtime,
                            std::uint32_t destination, std::uint32_t value,
                            std::uint32_t count, BatchLiftState& state) {
    state = {};
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.imports = &runtime;
    if (!memory.store32(state.regs[4], destination)
        || !memory.store32(state.regs[4] + 4u, value)
        || !memory.store32(state.regs[4] + 8u, count))
        return BatchLiftStatus::invalid_memory;
    return batch_guest_import_call32(memory, state, "MSVCR90.dll!memset",
                                      kIat, kReturn);
}

int main() {
    BatchLiftMemory memory;
    BatchGuestRuntime runtime;
    std::array<std::uint8_t, 64> writable{};
    std::array<std::uint8_t, 16> read_only{};
    writable.fill(0xa5u);
    read_only.fill(0x5au);
    if (!memory.map_region(kWritable, writable.data(), writable.size(), true)
        || !memory.map_region(kReadOnly, read_only.data(), read_only.size(), false))
        return 1;
    BatchLiftState state{};

    if (call_memset(memory, runtime, kWritable + 8u, 0x123u, 32u, state)
            != BatchLiftStatus::returned
        || state.eip != kReturn || state.regs[0] != kWritable + 8u
        || state.regs[4] != BatchLiftMemory::kEntryEsp)
        return 2;
    for (std::size_t index = 0; index < writable.size(); ++index) {
        const auto expected = index >= 8u && index < 40u ? 0x23u : 0xa5u;
        if (writable[index] != expected) return 3;
    }
    std::puts("PASS memset_low_byte_return_cdecl_and_canaries");

    if (call_memset(memory, runtime, 0x12345678u, 0x1ffu, 0u, state)
            != BatchLiftStatus::returned
        || state.regs[0] != 0x12345678u)
        return 4;
    std::puts("PASS memset_zero_count_no_destination_access");

    const auto before = writable;
    if (call_memset(memory, runtime, kWritable + 63u, 0u, 2u, state)
            != BatchLiftStatus::invalid_memory || writable != before)
        return 5;
    if (call_memset(memory, runtime, 0xfffffffeu, 0u, 4u, state)
            != BatchLiftStatus::invalid_memory || writable != before)
        return 6;
    if (call_memset(memory, runtime, kReadOnly, 0u, 1u, state)
            != BatchLiftStatus::invalid_memory || read_only[0] != 0x5au)
        return 7;
    std::puts("PASS memset_bounds_overflow_and_read_only_rejection");

    if (call_memset(memory, runtime, kWritable + 63u, 0x1abu, 1u, state)
            != BatchLiftStatus::returned || writable[63] != 0xabu)
        return 8;
    std::puts("PASS memset_last_byte_boundary");
    return 0;
}
