#include "BatchStaticLiftRuntime.hpp"

#include <array>
#include <cstdint>
#include <cstdio>

namespace {

constexpr char kSymbol[] = "KERNEL32.dll!GetSystemTimeAsFileTime";
constexpr std::uint32_t kIat = 0x013cc1ccu;
constexpr std::uint32_t kReturn = 0x011e1585u;

bool run_case(std::uint32_t pointer, bool mapped, bool writable,
              BatchLiftStatus expected) {
    BatchLiftMemory memory;
    std::array<std::uint8_t, 12> region{};
    region.fill(0xa5u);
    constexpr std::uint32_t kRegion = 0x50000000u;
    if (mapped && !memory.map_region(kRegion, region.data(), region.size(),
                                      writable)) return false;
    BatchGuestRuntime imports;
    BatchLiftState state{};
    state.imports = &imports;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    if (!memory.store32(state.regs[4], pointer)) return false;
    const auto status = batch_guest_import_call32(
        memory, state, kSymbol, kIat, kReturn);
    if (status != expected || imports.calls().size() != 1u ||
        imports.calls()[0].arguments.size() != 1u ||
        imports.calls()[0].arguments[0] != pointer ||
        imports.calls()[0].iat_address != kIat) return false;
    if (expected == BatchLiftStatus::returned) {
        std::uint64_t filetime{};
        return state.eip == kReturn &&
            state.regs[4] == BatchLiftMemory::kEntryEsp + 4u &&
            memory.load64(pointer, filetime) && filetime > 0u &&
            region.front() == 0xa5u && region.back() == 0xa5u;
    }
    for (std::uint8_t byte : region) {
        if (byte != 0xa5u) return false;
    }
    return state.eip == kIat &&
        state.regs[4] == BatchLiftMemory::kEntryEsp - 4u;
}

}  // namespace

int main() {
    if (!run_case(0x50000001u, true, true, BatchLiftStatus::returned) ||
        !run_case(0x50000003u, true, true, BatchLiftStatus::returned) ||
        !run_case(0u, false, false, BatchLiftStatus::invalid_memory) ||
        !run_case(0xfffffffcu, false, false, BatchLiftStatus::invalid_memory) ||
        !run_case(0x50000001u, true, false, BatchLiftStatus::invalid_memory) ||
        !run_case(0x50000005u, true, true, BatchLiftStatus::invalid_memory)) {
        std::puts("FAIL time_import memory_or_stdcall");
        return 1;
    }
    std::puts("PASS time_import writable_unaligned=2 null=guarded wrap=guarded readonly=guarded short=guarded stdcall=4bytes");
}
