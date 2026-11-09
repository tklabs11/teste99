#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0067dd60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0067dd60u);
    std::uint32_t t0 = 0;

    // 0x0067dd60: a1c4d85f01 MOV
        if (!memory.load32(0x015fd8c4u, t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x0067dd65: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
