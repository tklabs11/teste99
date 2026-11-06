#include "BatchStaticLiftRuntime.hpp"

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>

BatchLiftStatus spore_lift_00a2a210(BatchLiftMemory&, BatchLiftState&);

int main() {
    constexpr std::uint32_t kObject = 0x20000000u;
    constexpr std::uint32_t kStop = 0x00a2a24eu;
    BatchLiftMemory memory;
    std::array<std::uint8_t, 0x1000> object{};
    std::array<std::uint8_t, 4> fs{};
    if (!memory.map_region(kObject, object.data(), object.size(), true) ||
        !memory.map_region(0x30000000u, fs.data(), fs.size(), true) ||
        !memory.store32(kObject + 0x20u, 0xabcdef01u) ||
        !memory.store32(0x30000000u, 0xffffffffu)) {
        std::puts("fixture_map_failure");
        return 2;
    }
    BatchLiftState state{};
    state.regs[0] = 0x87654321u;
    state.regs[1] = kObject;
    state.regs[2] = 0x12345678u;
    state.regs[3] = 0x11223344u;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.regs[5] = 0x55667788u;
    state.regs[6] = 0x99aabbccu;
    state.regs[7] = 0xddeeff00u;
    state.eflags = 0x202u;
    state.eip = 0x00a2a210u;
    state.fs_base = 0x30000000u;
    const auto initial_esp = state.regs[4];
    if (!memory.store32(initial_esp, BatchLiftMemory::kReturnSentinel)) return 2;
    const auto status = spore_lift_00a2a210(memory, state);
    if (status != BatchLiftStatus::unsupported_dependency ||
        state.eip != kStop) {
        std::printf("lift_failure status=%u eip=%08x\n",
                    static_cast<unsigned>(status), state.eip);
        return 3;
    }
    std::uint32_t fs_head = 0;
    if (!memory.load32(0x30000000u, fs_head)) return 4;
#if defined(__aarch64__) || defined(_M_ARM64)
    constexpr auto* kind = "lift_android_arm64";
#else
    constexpr auto* kind = "lift_x86_host";
#endif
    std::printf("kind=%s boundary=%08x eax=%08x ecx=%08x edx=%08x "
                "ebx=%08x esp_delta=%d ebp=%08x esi=%08x edi=%08x "
                "flags=%08x fs_head=%08x stack=",
                kind, kStop, state.regs[0], state.regs[1], state.regs[2],
                state.regs[3], static_cast<std::int32_t>(state.regs[4] - initial_esp),
                state.regs[5], state.regs[6], state.regs[7],
                state.eflags & 0x8d5u, fs_head);
    for (std::uint32_t offset = 0; offset < 64; ++offset) {
        std::uint32_t value = 0;
        if (!memory.load8(state.regs[4] + offset, value)) return 4;
        std::printf("%02x", value);
    }
    std::putchar('\n');
    return 0;
}
