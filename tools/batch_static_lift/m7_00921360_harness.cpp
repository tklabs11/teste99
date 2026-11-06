#include "BatchStaticLiftRuntime.hpp"
#include "m7_float_data.hpp"
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>

#if defined(M7_C0)
BatchLiftStatus spore_lift_009213c0(BatchLiftMemory&, BatchLiftState&);
#define M7_FLOAT_LIFT spore_lift_009213c0
constexpr std::uint32_t kEntry = 0x009213c0u;
#else
BatchLiftStatus spore_lift_00921360(BatchLiftMemory&, BatchLiftState&);
#define M7_FLOAT_LIFT spore_lift_00921360
constexpr std::uint32_t kEntry = 0x00921360u;
#endif

int main() {
    struct Case { std::uint32_t key, factor; };
    constexpr Case cases[] = {{0, 0x3f800000u}, {5, 0x3f000000u},
                              {0xffffffffu, 0x3eaaaaabu}, {0x80000000u, 0x3f800000u}};
    for (std::size_t i = 0; i < 4; ++i) {
        BatchLiftMemory memory;
        std::array<std::uint8_t, 16> object{};
        auto table = kM7TableData;
        auto correction = kM7Correction;
        if (!memory.map_region(0x20000000u, object.data(), object.size(), true) ||
            !memory.map_region(0x0143d850u, table.data(), table.size(), false) ||
            !memory.map_region(0x013f4fd0u, correction.data(), correction.size(), false)) return 2;
        memory.store32(0x20000000u, cases[i].factor);
        memory.store32(BatchLiftMemory::kEntryEsp, 0x00921440u);
        memory.store32(BatchLiftMemory::kEntryEsp + 4u, cases[i].key);
        BatchLiftState state{};
        state.regs[1] = 0x20000000u;
        state.regs[4] = BatchLiftMemory::kEntryEsp;
        state.regs[6] = 0x66666666u;
        state.eflags = 0x202u;
        state.eip = kEntry;
        auto status = M7_FLOAT_LIFT(memory, state);
        std::uint32_t output = 0;
        memory.load32(0x20000008u, output);
        std::printf("case=%zu status=%u eax=%08x output=%08x flags=%08x depth=%u\n",
                    i, static_cast<unsigned>(status), state.regs[0], output,
                    state.eflags & 0x8d5u, state.x87_depth);
        if (status != BatchLiftStatus::returned) return 3;
    }
}
