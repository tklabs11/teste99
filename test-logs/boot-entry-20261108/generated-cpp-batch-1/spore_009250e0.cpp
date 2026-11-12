#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009250e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009250e0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;

    // 0x009250e0: a19c8e6601 MOV
        batch_guest_pc = 0x009250e0u;
        if (!memory.load32(0x01668e9cu, t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009250e5: 8b4010 MOV
        batch_guest_pc = 0x009250e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x009250e8: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
