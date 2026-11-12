#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121db00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121db00u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;

    // 0x0121db00: 55 PUSH
        batch_guest_pc = 0x0121db00u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121db01: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121db03: 5d POP
        batch_guest_pc = 0x0121db03u;
        if (!memory.load32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t2a;
    // 0x0121db04: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
