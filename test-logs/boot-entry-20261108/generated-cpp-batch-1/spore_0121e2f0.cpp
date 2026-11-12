#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e2f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e2f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x0121e2f0: 55 PUSH
        batch_guest_pc = 0x0121e2f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e2f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e2f3: dd05c8bb3e01 FLD
        if (!batch_guest_fld64(memory, state, 0x013ebbc8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e2f9: dd1de0175d01 FSTP
        if (!batch_guest_fstp64(memory, state, 0x015d17e0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e2ff: 5d POP
        batch_guest_pc = 0x0121e2ffu;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x0121e300: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
