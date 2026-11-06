#include "BatchStaticLiftRuntime.hpp"
#include <array>
#include <cstdint>
#include <cstdio>

BatchLiftStatus spore_lift_009212c0(BatchLiftMemory&, BatchLiftState&);

int main() {
    constexpr std::uint32_t keys[] = {0, 5, 10, 5};
    constexpr std::uint32_t counts[] = {5, 5, 5, 0};
    for (std::size_t i = 0; i < 4; ++i) {
        BatchLiftMemory memory;
        std::array<std::uint8_t, 0x1000> object{};
        if (!memory.map_region(0x20000000u, object.data(), object.size(), true)) return 2;
        for (unsigned j = 0; j < 5; ++j) memory.store32(0x20000000u + j * 4u, 2u*j+1u);
        memory.store32(0x70000300u, keys[i]);
        memory.store32(BatchLiftMemory::kEntryEsp, 0x00921300u);
        memory.store32(BatchLiftMemory::kEntryEsp + 4u, 0x20000000u);
        memory.store32(BatchLiftMemory::kEntryEsp + 8u, 0x20000000u + counts[i]*4u);
        memory.store32(BatchLiftMemory::kEntryEsp + 12u, 0x70000300u);
        BatchLiftState state{};
        state.regs[4] = BatchLiftMemory::kEntryEsp;
        state.regs[6] = 0x66666666u;
        state.regs[7] = 0x77777777u;
        state.eflags = 0x202u;
        state.eip = 0x009212c0u;
        auto status = spore_lift_009212c0(memory, state);
        std::printf("case=%zu status=%u eax=%08x flags=%08x esi=%08x edi=%08x\n",
                    i, static_cast<unsigned>(status), state.regs[0],
                    state.eflags & 0x8d5u, state.regs[6], state.regs[7]);
        if (status != BatchLiftStatus::returned) return 3;
    }
}
