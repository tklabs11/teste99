#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121a7f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121a7f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x0121a7f0: 55 PUSH
        batch_guest_pc = 0x0121a7f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121a7f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121a7f3: dd0558b13e01 FLD
        if (!batch_guest_fld64(memory, state, 0x013eb158u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a7f9: dd1d380d5d01 FSTP
        if (!batch_guest_fstp64(memory, state, 0x015d0d38u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a7ff: 5d POP
        batch_guest_pc = 0x0121a7ffu;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x0121a800: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
