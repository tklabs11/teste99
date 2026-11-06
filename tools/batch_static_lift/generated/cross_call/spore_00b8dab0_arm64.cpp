#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00b8dab0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;

    // 0x00b8dab0: 8b8194010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000194u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00b8dab6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
