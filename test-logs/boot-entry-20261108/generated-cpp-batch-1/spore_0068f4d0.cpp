#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0068f4d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0068f4d0u);
    std::uint32_t t0 = 0;

    // 0x0068f4d0: a108056001 MOV
        if (!memory.load32(0x01600508u, t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x0068f4d5: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
