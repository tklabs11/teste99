#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ff70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ff70u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x0121ff70: 55 PUSH
        batch_guest_pc = 0x0121ff70u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ff71: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ff73: dd0518bd3e01 FLD
        if (!batch_guest_fld64(memory, state, 0x013ebd18u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ff79: dd1d281d5d01 FSTP
        if (!batch_guest_fstp64(memory, state, 0x015d1d28u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ff7f: 5d POP
        batch_guest_pc = 0x0121ff7fu;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x0121ff80: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
