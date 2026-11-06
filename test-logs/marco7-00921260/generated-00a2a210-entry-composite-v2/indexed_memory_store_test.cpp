#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00fee000(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;

    // 0x00fee000: 894c862c MOV
        t0 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + state.regs[0] * 4u + 0x0000002cu), t0)) return BatchLiftStatus::invalid_memory;
    // 0x00fee004: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
