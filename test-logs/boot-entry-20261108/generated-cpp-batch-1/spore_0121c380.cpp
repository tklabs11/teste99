#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c380(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c380u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x0121c380: 55 PUSH
        batch_guest_pc = 0x0121c380u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c381: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c383: dd0548b23e01 FLD
        if (!batch_guest_fld64(memory, state, 0x013eb248u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c389: dd1d88125d01 FSTP
        if (!batch_guest_fstp64(memory, state, 0x015d1288u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c38f: 5d POP
        batch_guest_pc = 0x0121c38fu;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x0121c390: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
