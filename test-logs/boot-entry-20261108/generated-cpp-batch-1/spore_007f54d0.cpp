#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_007f54d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x007f54d0u);
    std::uint32_t t0 = 0;

    // 0x007f54d0: 8b4110 MOV
        batch_guest_pc = 0x007f54d0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000010u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x007f54d3: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
