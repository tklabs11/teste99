#include "BatchStaticLiftRuntime.hpp"
#include "cookie_reference_bytes.hpp"

#include <array>
#include <chrono>
#include <cstdint>
#include <cstdio>

BatchLiftStatus spore_lift_011e1548(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_011e11a0(BatchLiftMemory&, BatchLiftState&);

#if defined(BOOT_ENTRY_CHAIN)
// The boundary must be reached before this unresolved CRT destination.
BatchLiftStatus spore_lift_011e0ee0(BatchLiftMemory&, BatchLiftState& state) {
    state.eip = 0x011e0ee0u;
    return BatchLiftStatus::unsupported_dependency;
}
#endif

namespace {

constexpr std::uint32_t kDataAddress = 0x015cfe70u;
constexpr std::uint32_t kBoundary = 0x011e1585u;

std::uint64_t host_filetime() {
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
    return static_cast<std::uint64_t>(seconds.count() + 11644473600ll) *
        10000000ull + static_cast<std::uint64_t>(nanoseconds.count() / 100);
#endif
}

bool read_word(const BatchLiftMemory& memory, std::uint32_t address,
               std::uint32_t expected) {
    std::uint32_t actual = 0;
    return memory.load32(address, actual) && actual == expected;
}

}  // namespace

int main() {
    BatchLiftMemory memory;
    auto initial_data = kCookieInitialData;
    if (!memory.map_region(kDataAddress, initial_data.data(),
                           initial_data.size(), true)) {
        std::puts("FAIL cookie_prefix map_data");
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
    const std::uint64_t before = host_filetime();
    const auto status = spore_lift_011e11a0(memory, state);
    const std::uint64_t after = host_filetime();
    const auto entry_esp = BatchLiftMemory::kEntryEsp - 4u;
#else
    state.eip = 0x011e1548u;
    const std::uint64_t before = host_filetime();
    const auto status = spore_lift_011e1548(memory, state);
    const std::uint64_t after = host_filetime();
    const auto entry_esp = BatchLiftMemory::kEntryEsp;
#endif
    const bool registers_match =
        state.regs[3] == 0xffff0000u && state.regs[4] == entry_esp - 32u &&
        state.regs[5] == entry_esp - 4u && state.regs[6] == initial[6] &&
        state.regs[7] == 0xbb40e64eu;
    const bool stack_matches =
        read_word(memory, entry_esp - 36u, entry_esp - 12u) &&
        read_word(memory, entry_esp - 32u, initial[6]) &&
        read_word(memory, entry_esp - 28u, initial[7]) &&
        read_word(memory, entry_esp - 24u, initial[3]) &&
        read_word(memory, entry_esp - 4u, initial[5]) &&
#if defined(BOOT_ENTRY_CHAIN)
        read_word(memory, entry_esp, 0x011e11a5u) &&
#endif
        read_word(memory, BatchLiftMemory::kEntryEsp,
                  BatchLiftMemory::kReturnSentinel);
    std::uint64_t filetime{};
    const bool time_matches = memory.load64(entry_esp - 12u, filetime) &&
        before <= filetime && filetime <= after;
    const bool import_matches = imports.calls().size() == 1u &&
        imports.calls()[0].symbol ==
            "KERNEL32.dll!GetSystemTimeAsFileTime" &&
        imports.calls()[0].iat_address == 0x013cc1ccu &&
        imports.calls()[0].arguments.size() == 1u &&
        imports.calls()[0].arguments[0] == entry_esp - 12u &&
        imports.calls()[0].return_address == kBoundary;
    if (status != BatchLiftStatus::unsupported_dependency ||
            state.eip != kBoundary || !registers_match || !stack_matches ||
            !time_matches || !import_matches ||
            initial_data != kCookieInitialData) {
        std::printf("FAIL cookie_prefix status=%u eip=0x%08x eax=0x%08x "
                    "esp=0x%08x regs=%d stack=%d time=%d import=%d\n",
                    static_cast<unsigned>(status), state.eip, state.regs[0],
                    state.regs[4], registers_match, stack_matches,
                    time_matches, import_matches);
        return 1;
    }
#if defined(BOOT_ENTRY_CHAIN)
    std::printf("PASS boot_entry_time_prefix boundary=0x%08x executed=18 "
#else
    std::printf("PASS cookie_time_prefix boundary=0x%08x executed=17 "
#endif
                "esp_delta=-32 ebp_delta=-4 "
                "ebx=0x%08x esi=0x%08x edi=0x%08x "
                "filetime=within_host_window data=unchanged\n",
                state.eip, state.regs[3], state.regs[6], state.regs[7]);

    // Deliberately artificial cookie value: the unvalidated branch must stop.
    BatchLiftMemory alternate_memory;
    auto alternate_data = kCookieInitialData;
    alternate_data[0] = 0x78u;
    alternate_data[1] = 0x56u;
    alternate_data[2] = 0x34u;
    alternate_data[3] = 0x12u;
    if (!alternate_memory.map_region(kDataAddress, alternate_data.data(),
                                     alternate_data.size(), true)) {
        std::puts("FAIL cookie_prefix alternate_map");
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
            !read_word(alternate_memory, kDataAddress, 0x12345678u) ||
            !read_word(alternate_memory, kDataAddress + 4u, 0xedcba987u)) {
        std::printf("FAIL cookie_prefix alternate_fixture status=%u eip=0x%08x\n",
                    static_cast<unsigned>(alternate_status), alternate_state.eip);
        return 1;
    }
    std::puts("PASS cookie_prefix alternate_fixture guarded=0x011e1578");
}
