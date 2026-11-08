// cpp / boot_cookie_pid_prefix_harness.cpp / x86 and aarch64-linux-android29 / Spore PE prefix
#include "BatchStaticLiftRuntime.hpp"
#include "cookie_reference_bytes.hpp"

#include <array>
#include <chrono>
#include <cstdint>
#include <cstdio>

BatchLiftStatus spore_lift_011e1548(BatchLiftMemory&, BatchLiftState&);

#if defined(BOOT_ENTRY_CHAIN)
BatchLiftStatus spore_lift_011e11a0(BatchLiftMemory&, BatchLiftState&);
#endif

#if defined(BOOT_ENTRY_CHAIN)
// The boundary must be reached before this unresolved CRT destination.
BatchLiftStatus spore_lift_011e0ee0(BatchLiftMemory&, BatchLiftState& state) {
    state.eip = 0x011e0ee0u;
    return BatchLiftStatus::unsupported_dependency;
}
#endif

namespace {

constexpr std::uint32_t kDataAddress = 0x015cfe70u;
#if !defined(SPORE_COOKIE_FUNCTION_COMPLETE)
constexpr bool kPidCallExecuted =
    kCookieBoundaryAddress > kCookieProcessIdCallAddress;
constexpr bool kTidCallExecuted =
    kCookieBoundaryAddress > kCookieThreadIdCallAddress;
constexpr bool kTickCallExecuted =
    kCookieBoundaryAddress > kCookieTickCountCallAddress;
constexpr bool kQpcCallExecuted =
    kCookieBoundaryAddress > kCookiePerformanceCounterCallAddress;
constexpr bool kPidMixed =
    kCookieBoundaryAddress > kCookieProcessIdXorAddress;
constexpr bool kTidMixed =
    kCookieBoundaryAddress > kCookieThreadIdXorAddress;
constexpr bool kTickMixed =
    kCookieBoundaryAddress > kCookieTickCountXorAddress;
constexpr bool kQpcMixed =
    kCookieBoundaryAddress > kCookiePerformanceCounterXorAddress;

constexpr std::uint32_t executed_instruction_count() {
    switch (kCookieBoundaryAddress) {
        case 0x011e158bu: return 20u;
        case 0x011e1591u: return 21u;
        case 0x011e1593u: return 22u;
        case 0x011e1599u: return 23u;
        case 0x011e159bu: return 24u;
        case 0x011e15a1u: return 25u;
        case 0x011e15a3u: return 26u;
        case 0x011e15a6u: return 27u;
        case 0x011e15a7u: return 28u;
        case 0x011e15adu: return 29u;
        case 0x011e15b0u: return 30u;
        case 0x011e15b3u: return 31u;
        case 0x011e15b5u: return 32u;
        default: return 0u;
    }
}

constexpr std::size_t executed_call_count() {
    return 1u + (kPidCallExecuted ? 1u : 0u) + (kTidCallExecuted ? 1u : 0u)
        + (kTickCallExecuted ? 1u : 0u) + (kQpcCallExecuted ? 1u : 0u);
}
#endif  // SPORE_COOKIE_FUNCTION_COMPLETE

#if !defined(SPORE_COOKIE_FUNCTION_COMPLETE)
bool within_host_clock_window(std::uint64_t ticks, std::uint64_t before,
                              std::uint64_t after) {
    return before <= ticks && ticks <= after;
}

std::uint64_t host_ticks_now() {
#if defined(_WIN32)
    FILETIME now{};
    GetSystemTimeAsFileTime(&now);
    return static_cast<std::uint64_t>(now.dwLowDateTime) |
        (static_cast<std::uint64_t>(now.dwHighDateTime) << 32u);
#else
    const auto now = std::chrono::system_clock::now().time_since_epoch();
    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(now);
    const auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(
        now - seconds);
    return static_cast<std::uint64_t>(seconds.count() + 11644473600ll)
        * 10000000ull + static_cast<std::uint64_t>(nanoseconds.count() / 100);
#endif
}
#endif  // SPORE_COOKIE_FUNCTION_COMPLETE

#if !defined(SPORE_COOKIE_FUNCTION_COMPLETE)
bool read_word(const BatchLiftMemory& memory, std::uint32_t address,
               std::uint32_t expected) {
    std::uint32_t actual = 0;
    return memory.load32(address, actual) && actual == expected;
}
#endif  // SPORE_COOKIE_FUNCTION_COMPLETE

// The verified data page is guest memory. Surround it with guard words so an
// out-of-bounds guest write fails inside this harness instead of corrupting
// the host frame.
struct GuardedCookieData {
    std::array<std::uint8_t, 16> lead{};
    std::array<std::uint8_t, 8> bytes{};
    std::array<std::uint8_t, 16> trail{};

    GuardedCookieData() {
        lead.fill(0xa5u);
        trail.fill(0x5au);
        bytes = kCookieInitialData;
    }

    bool guards_intact() const {
        for (std::uint8_t value : lead) {
            if (value != 0xa5u) return false;
        }
        for (std::uint8_t value : trail) {
            if (value != 0x5au) return false;
        }
        return true;
    }
};

constexpr std::uint32_t kStackGuardBase = 0x70000300u;
constexpr std::uint32_t kStackGuardWords = 0x40u;
constexpr std::uint32_t kStackGuardPattern = 0xc3c3c3c3u;

bool arm_stack_guard(BatchLiftMemory& memory) {
    for (std::uint32_t index = 0; index < kStackGuardWords; ++index) {
        if (!memory.store32(
                kStackGuardBase + index * 4u, kStackGuardPattern)) {
            return false;
        }
    }
    return true;
}

bool stack_guard_intact(const BatchLiftMemory& memory) {
    for (std::uint32_t index = 0; index < kStackGuardWords; ++index) {
        std::uint32_t value = 0;
        if (!memory.load32(kStackGuardBase + index * 4u, value)
            || value != kStackGuardPattern) {
            return false;
        }
    }
    return true;
}

}  // namespace

#if defined(SPORE_COOKIE_FUNCTION_COMPLETE)
namespace {

// Standalone execution of the complete ___security_init_cookie: the function
// builds its own frame, mixes real host entropy, stores the cookie and
// returns to the sentinel address already present at the entry stack slot.
int run_complete_cookie() {
    BatchLiftMemory memory;
    GuardedCookieData initial_data;
    if (!memory.map_region(kDataAddress, initial_data.bytes.data(),
                           initial_data.bytes.size(), true)
        || !arm_stack_guard(memory)) {
        std::puts("FAIL cookie_complete map_data");
        return 1;
    }
    BatchLiftState state{};
    BatchGuestRuntime imports;
    state.imports = &imports;
    constexpr std::array<std::uint32_t, 8> initial{
        0x11111111u, 0x22222222u, 0x33333333u, 0x44444444u,
        BatchLiftMemory::kEntryEsp, 0x55555555u, 0x66666666u, 0x77777777u,
    };
    for (unsigned index = 0; index < initial.size(); ++index) {
        state.regs[index] = initial[index];
    }
    state.eflags = 0x202u;
    state.eip = 0x011e1548u;
    const auto status = spore_lift_011e1548(memory, state);

    std::uint32_t cookie_low = 0, cookie_high = 0;
    const bool cookie_readable =
        memory.load32(kDataAddress, cookie_low) &&
        memory.load32(kDataAddress + 4u, cookie_high);
    const bool returned =
        status == BatchLiftStatus::returned &&
        state.eip == BatchLiftMemory::kReturnSentinel &&
        state.regs[4] == BatchLiftMemory::kEntryEsp + 4u;
    const bool registers_restored =
        state.regs[3] == initial[3] && state.regs[5] == initial[5] &&
        state.regs[6] == initial[6] && state.regs[7] == initial[7];
    const bool cookie_consistent = cookie_readable && cookie_low != 0u &&
        (cookie_low & 0xffff0000u) != 0u && cookie_high == ~cookie_low;
    const bool guards_ok =
        initial_data.guards_intact() && stack_guard_intact(memory);
    const auto& calls = imports.calls();
    bool calls_ok = calls.size() == 5u;
    if (calls_ok) {
        calls_ok =
            calls[0].symbol == "KERNEL32.dll!GetSystemTimeAsFileTime" &&
            calls[1].symbol == "KERNEL32.dll!GetCurrentProcessId" &&
            calls[2].symbol == "KERNEL32.dll!GetCurrentThreadId" &&
            calls[3].symbol == "KERNEL32.dll!GetTickCount" &&
            calls[4].symbol == "KERNEL32.dll!QueryPerformanceCounter";
    }
    if (calls_ok) {
        for (const auto& call : calls) {
            calls_ok = calls_ok && call.return_address != 0u;
        }
    }
    if (!returned || !registers_restored || !cookie_consistent ||
            !guards_ok || !calls_ok) {
        std::printf("FAIL cookie_complete status=%u eip=0x%08x esp=0x%08x "
                    "returned=%d regs=%d cookie=%d guards=%d calls=%d\n",
                    static_cast<unsigned>(status), state.eip, state.regs[4],
                    returned, registers_restored, cookie_consistent,
                    guards_ok, calls_ok);
        return 1;
    }
    std::printf("PASS cookie_complete returned=1 esp_delta=4 "
                "regs_restored=1 cookie_consistent=1 cookie_high_word=1 "
                "guards=1 imports=5 instructions=53\n");
    std::printf("DETAIL cookie_complete cookie=0x%08x complement=0x%08x\n",
                cookie_low, cookie_high);
    return 0;
}

}  // namespace
#endif

int main() {
#if defined(SPORE_COOKIE_FUNCTION_COMPLETE)
    return run_complete_cookie();
#else
    BatchLiftMemory memory;
    GuardedCookieData initial_data;
    if (!memory.map_region(kDataAddress, initial_data.bytes.data(),
                           initial_data.bytes.size(), true)
        || !arm_stack_guard(memory)) {
        std::puts("FAIL pid_prefix map_data");
        return 1;
    }
    BatchLiftState state{};
    BatchGuestRuntime imports;
    state.imports = &imports;
    constexpr std::array<std::uint32_t, 8> initial{
        0x11111111u, 0x22222222u, 0x33333333u, 0x44444444u,
        BatchLiftMemory::kEntryEsp, 0x55555555u, 0x66666666u, 0x77777777u,
    };
    for (unsigned index = 0; index < initial.size(); ++index) {
        state.regs[index] = initial[index];
    }
    state.eflags = 0x202u;
#if defined(BOOT_ENTRY_CHAIN)
    state.eip = 0x011e11a0u;
    const std::uint64_t before = host_ticks_now();
    const auto status = spore_lift_011e11a0(memory, state);
    const std::uint64_t after = host_ticks_now();
    const auto entry_esp = BatchLiftMemory::kEntryEsp - 4u;
#else
    state.eip = 0x011e1548u;
    const std::uint64_t before = host_ticks_now();
    const auto status = spore_lift_011e1548(memory, state);
    const std::uint64_t after = host_ticks_now();
    const auto entry_esp = BatchLiftMemory::kEntryEsp;
#endif
    const bool registers_match =
        state.regs[3] == 0xffff0000u && state.regs[4] == entry_esp - 32u &&
        state.regs[5] == entry_esp - 4u && state.regs[7] == 0xbb40e64eu;
    // [ESP] still holds the pointer pushed for the time call; every later
    // call pushes and pops its return address at the same slot.
    // The QPC call consumes its pushed argument, so the slot keeps that
    // pointer. The zero-argument calls leave their own return address there.
    const std::uint32_t last_call_return =
        kQpcCallExecuted ? static_cast<std::uint32_t>(entry_esp - 20u) :
        kTickCallExecuted ? 0x011e15a1u :
        kTidCallExecuted ? 0x011e1599u :
        kPidCallExecuted ? 0x011e1591u :
        static_cast<std::uint32_t>(entry_esp - 12u);
    const bool stack_matches =
        read_word(memory, entry_esp - 36u, last_call_return) &&
        read_word(memory, entry_esp - 32u, initial[6]) &&
        read_word(memory, entry_esp - 28u, initial[7]) &&
        read_word(memory, entry_esp - 24u, initial[3]) &&
        read_word(memory, entry_esp - 4u, initial[5]) &&
#if defined(BOOT_ENTRY_CHAIN)
        read_word(memory, entry_esp, 0x011e11a5u) &&
#endif
        read_word(memory, BatchLiftMemory::kEntryEsp,
                  BatchLiftMemory::kReturnSentinel);

    std::uint32_t time_low = 0, time_high = 0;
    const auto time_address = entry_esp - 12u;
    const bool time_readable =
        memory.load32(time_address, time_low) &&
        memory.load32(time_address + 4u, time_high);
    const std::uint64_t filetime =
        static_cast<std::uint64_t>(time_low) |
        (static_cast<std::uint64_t>(time_high) << 32u);
    const bool time_plausible = time_readable && time_low != 0u &&
        within_host_clock_window(filetime, before, after);

    const auto& calls = imports.calls();
    std::uint32_t pid_value = 0, tid_value = 0, tick_value = 0;
    std::uint64_t qpc_value = 0;
    bool pid_seen = false, tid_seen = false, tick_seen = false,
        qpc_seen = false;
    bool calls_match = calls.size() == executed_call_count() && calls.size() >= 1u;
    if (calls_match) {
        const auto& time = calls[0];
        calls_match = time.symbol == "KERNEL32.dll!GetSystemTimeAsFileTime" &&
            time.iat_address == 0x013cc1ccu &&
            time.arguments.size() == 1u &&
            time.arguments[0] == entry_esp - 12u &&
            time.return_address == 0x011e1585u;
    }
    for (std::size_t index = 1; index < calls.size(); ++index) {
        const auto& call = calls[index];
        if (call.symbol == "KERNEL32.dll!GetCurrentProcessId") {
            pid_value = call.result;
            pid_seen = call.result != 0u && call.arguments.empty() &&
                call.iat_address == 0x013cc114u &&
                call.return_address == 0x011e1591u;
        } else if (call.symbol == "KERNEL32.dll!GetCurrentThreadId") {
            tid_value = call.result;
            tid_seen = call.result != 0u && call.arguments.empty() &&
                call.iat_address == 0x013cc13cu &&
                call.return_address == 0x011e1599u;
        } else if (call.symbol == "KERNEL32.dll!GetTickCount") {
            tick_value = call.result;
            tick_seen = call.arguments.empty() &&
                call.iat_address == 0x013cc130u &&
                call.return_address == 0x011e15a1u;
        } else if (call.symbol == "KERNEL32.dll!QueryPerformanceCounter") {
            qpc_seen = call.result == 1u && call.arguments.size() == 1u &&
                call.arguments[0] == entry_esp - 20u &&
                call.iat_address == 0x013cc2b8u &&
                call.return_address == 0x011e15adu;
        } else {
            calls_match = false;
        }
    }
    calls_match = calls_match &&
        pid_seen == kPidCallExecuted && tid_seen == kTidCallExecuted &&
        tick_seen == kTickCallExecuted && qpc_seen == kQpcCallExecuted;

    std::uint32_t qpc_low = 0, qpc_high = 0;
    const auto qpc_address = entry_esp - 20u;
    const bool qpc_readable =
        memory.load32(qpc_address, qpc_low) &&
        memory.load32(qpc_address + 4u, qpc_high);
    if (qpc_readable) {
        qpc_value = static_cast<std::uint64_t>(qpc_low) |
            (static_cast<std::uint64_t>(qpc_high) << 32u);
    }

    // ESI accumulates the CRT entropy exactly as the original bytes do.
    std::uint32_t expected_esi = time_low ^ time_high;
    if (kPidMixed) expected_esi ^= pid_value;
    if (kTidMixed) expected_esi ^= tid_value;
    if (kTickMixed) expected_esi ^= tick_value;
    if (kQpcMixed) expected_esi ^= qpc_low ^ qpc_high;
    bool esi_matches = state.regs[6] == expected_esi;
    if (kQpcMixed && qpc_value == 0u) esi_matches = false;
    if (kQpcCallExecuted && !qpc_readable) esi_matches = false;

    if (status != BatchLiftStatus::unsupported_dependency ||
            state.eip != kCookieBoundaryAddress || !registers_match ||
            !stack_matches || !esi_matches || !time_plausible ||
            !calls_match || !initial_data.guards_intact() ||
            !stack_guard_intact(memory) ||
            initial_data.bytes != kCookieInitialData) {
        std::printf("FAIL pid_prefix status=%u eip=0x%08x esp=0x%08x "
                    "esi=0x%08x expected_esi=0x%08x regs=%d stack=%d "
                    "esi_mix=%d time=%d calls=%d data_guard=%d stack_guard=%d\n",
                    static_cast<unsigned>(status), state.eip, state.regs[4],
                    state.regs[6], expected_esi, registers_match,
                    stack_matches, esi_matches, time_plausible, calls_match,
                    initial_data.guards_intact() ? 1 : 0,
                    stack_guard_intact(memory) ? 1 : 0);
        return 1;
    }
    std::printf("PASS pid_prefix boundary=0x%08x executed=%u "
                "pid_call_executed=%u esp_delta=-32 ebp_delta=-4 "
                "ebx=0x%08x edi=0x%08x esi_mix=verified "
                "filetime=within_host_window data=unchanged\n",
                state.eip, executed_instruction_count(),
                kPidCallExecuted ? 1u : 0u, state.regs[3], state.regs[7]);
    std::printf("DETAIL pid_prefix filetime_mix=0x%08x pid=0x%08x "
                "tid=0x%08x tick=0x%08x qpc=0x%016llx imports=%u\n",
                time_low ^ time_high, pid_value, tid_value, tick_value,
                static_cast<unsigned long long>(qpc_value),
                static_cast<unsigned>(calls.size()));

    // Deliberately artificial cookie value: the unvalidated branch must stop.
    BatchLiftMemory alternate_memory;
    GuardedCookieData alternate_data;
    alternate_data.bytes[0] = 0x78u;
    alternate_data.bytes[1] = 0x56u;
    alternate_data.bytes[2] = 0x34u;
    alternate_data.bytes[3] = 0x12u;
    if (!alternate_memory.map_region(
            kDataAddress, alternate_data.bytes.data(),
            alternate_data.bytes.size(), true)) {
        std::puts("FAIL pid_prefix alternate_map");
        return 1;
    }
    BatchLiftState alternate_state{};
    alternate_state.imports = &imports;
    for (unsigned index = 0; index < initial.size(); ++index) {
        alternate_state.regs[index] = initial[index];
    }
    alternate_state.eflags = 0x202u;
#if defined(BOOT_ENTRY_CHAIN)
    alternate_state.eip = 0x011e11a0u;
    const auto alternate_status = spore_lift_011e11a0(
        alternate_memory, alternate_state);
#else
    alternate_state.eip = 0x011e1548u;
    const auto alternate_status = spore_lift_011e1548(
        alternate_memory, alternate_state);
#endif
    if (alternate_status != BatchLiftStatus::unsupported_dependency ||
            alternate_state.eip != 0x011e1578u ||
            !alternate_data.guards_intact() ||
            !read_word(alternate_memory, kDataAddress, 0x12345678u) ||
            !read_word(alternate_memory, kDataAddress + 4u, 0xedcba987u)) {
        std::printf("FAIL pid_prefix alternate_fixture status=%u eip=0x%08x\n",
                    static_cast<unsigned>(alternate_status), alternate_state.eip);
        return 1;
    }
    std::puts("PASS pid_prefix alternate_fixture guarded=0x011e1578");
#endif  // SPORE_COOKIE_FUNCTION_COMPLETE
}
