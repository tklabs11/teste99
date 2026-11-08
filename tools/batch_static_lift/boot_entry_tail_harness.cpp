#include "BatchStaticLiftRuntime.hpp"

#include <array>
#include <cstdint>
#include <cstdio>

BatchLiftStatus spore_lift_011e11a0(BatchLiftMemory&, BatchLiftState&);

namespace {

constexpr std::uint32_t kEntry = 0x011e11a0u;
constexpr std::uint32_t kCookie = 0x011e1548u;
constexpr std::uint32_t kAfterCookie = 0x011e11a5u;
constexpr std::uint32_t kCrt = 0x011e0ee0u;
constexpr std::uint32_t kFlags = 0x00000203u;

enum class Mode { complete, corrupt_cookie_return, stop_at_crt };
Mode mode = Mode::complete;
unsigned cookie_calls = 0;
unsigned crt_calls = 0;

bool unchanged_registers(const BatchLiftState& state,
                         const std::array<std::uint32_t, 8>& initial) {
    for (unsigned index = 0; index < initial.size(); ++index) {
        if (index != 4 && state.regs[index] != initial[index]) return false;
    }
    return true;
}

bool run_case(Mode test_mode) {
    mode = test_mode;
    cookie_calls = crt_calls = 0;
    BatchLiftMemory memory;
    BatchLiftState state{};
    constexpr std::array<std::uint32_t, 8> initial{
        0x12345678u, 0x23456789u, 0x3456789au, 0x456789abu,
        BatchLiftMemory::kEntryEsp, 0x56789abcu, 0x6789abcdu, 0x789abcdeu,
    };
    for (unsigned index = 0; index < initial.size(); ++index) {
        state.regs[index] = initial[index];
    }
    state.eflags = kFlags;
    state.eip = kEntry;
    const auto result = spore_lift_011e11a0(memory, state);
    if (cookie_calls != 1 || state.eflags != kFlags
            || !unchanged_registers(state, initial)) return false;
    if (test_mode == Mode::complete) {
        return result == BatchLiftStatus::returned && crt_calls == 1
            && state.regs[4] == BatchLiftMemory::kEntryEsp + 4u
            && state.eip == BatchLiftMemory::kReturnSentinel;
    }
    if (test_mode == Mode::corrupt_cookie_return) {
        return result == BatchLiftStatus::invalid_control_flow && crt_calls == 0
            && state.regs[4] == BatchLiftMemory::kEntryEsp
            && state.eip == 0xdeadbeefu;
    }
    return result == BatchLiftStatus::unsupported_dependency && crt_calls == 1
        && state.regs[4] == BatchLiftMemory::kEntryEsp && state.eip == kCrt;
}

}  // namespace

// Test stubs deliberately replace the unimplemented original cookie and CRT.
BatchLiftStatus spore_lift_011e1548(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t return_address = 0;
    if (state.eip != kCookie
            || state.regs[4] != BatchLiftMemory::kEntryEsp - 4u
            || state.eflags != kFlags
            || !memory.load32(state.regs[4], return_address)
            || return_address != kAfterCookie) {
        return BatchLiftStatus::invalid_control_flow;
    }
    ++cookie_calls;
    if (!batch_guest_return32(memory, state)) return BatchLiftStatus::invalid_memory;
    if (mode == Mode::corrupt_cookie_return) state.eip = 0xdeadbeefu;
    return BatchLiftStatus::returned;
}

BatchLiftStatus spore_lift_011e0ee0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t return_address = 0;
    if (state.eip != kCrt
            || state.regs[4] != BatchLiftMemory::kEntryEsp
            || state.eflags != kFlags
            || !memory.load32(state.regs[4], return_address)
            || return_address != BatchLiftMemory::kReturnSentinel) {
        return BatchLiftStatus::invalid_control_flow;
    }
    ++crt_calls;
    if (mode == Mode::stop_at_crt) return BatchLiftStatus::unsupported_dependency;
    return batch_guest_return32(memory, state)
        ? BatchLiftStatus::returned : BatchLiftStatus::invalid_memory;
}

int main() {
    if (!run_case(Mode::complete)) {
        std::puts("FAIL entry_tail complete");
        return 1;
    }
    std::puts("PASS entry_tail complete cookie=1 crt=1 stack=restored flags=preserved");
    if (!run_case(Mode::corrupt_cookie_return)) {
        std::puts("FAIL entry_tail corrupt_cookie_return");
        return 1;
    }
    std::puts("PASS entry_tail corrupt_cookie_return rejected");
    if (!run_case(Mode::stop_at_crt)) {
        std::puts("FAIL entry_tail stop_at_crt");
        return 1;
    }
    std::puts("PASS entry_tail stop_at_crt eip=0x011e0ee0 stack=preserved");
}
