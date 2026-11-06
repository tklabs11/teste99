#include "BatchStaticLiftRuntime.hpp"

#include <array>
#include <cstdint>
#include <cstdio>

BatchLiftStatus spore_lift_00921260(BatchLiftMemory&, BatchLiftState&);

int main() {
    struct Case { std::uint32_t alignment, length, stride; };
    constexpr Case cases[] = {{4, 0x960, 12}, {1, 16, 4}, {0, 0, 4}};
    for (std::size_t i = 0; i < 3; ++i) {
        BatchLiftMemory memory;
        std::array<std::uint8_t, 0x1000> object{};
        if (!memory.map_region(0x20000000u, object.data(), object.size(), true)) return 2;
        BatchLiftState state{};
        state.regs[0] = 0x12345678u;
        state.regs[1] = 0x70000300u;
        state.regs[2] = 0xabcdef01u;
        state.regs[3] = 0x33333333u;
        state.regs[4] = BatchLiftMemory::kEntryEsp;
        state.regs[5] = 0x55555555u;
        state.regs[6] = 0x66666666u;
        state.regs[7] = 0x77777777u;
        state.eflags = 0x202u;
        state.eip = 0x00921260u;
        memory.store32(state.regs[4], 0x00921300u);
        memory.store32(state.regs[4] + 4u, 0x20000000u);
        memory.store32(state.regs[4] + 8u, cases[i].length);
        memory.store32(state.regs[4] + 12u, cases[i].stride);
        memory.store32(state.regs[4] + 16u, cases[i].alignment);
        memory.store32(state.regs[4] + 20u, 0u);
        auto status = spore_lift_00921260(memory, state);
        std::uint32_t output = 0;
        memory.load32(0x70000300u, output);
        std::printf("case=%zu status=%u eip=%08x flags=%08x output=%08x regs=", i,
                    static_cast<unsigned>(status), state.eip, state.eflags & 0x8d5u, output);
        for (auto reg : state.regs) std::printf("%08x,", reg);
        std::printf(" object=");
        for (auto byte : object) std::printf("%02x", byte);
        std::printf("\n");
        if (status != BatchLiftStatus::returned) return 3;
    }
}
