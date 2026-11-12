#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221780(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221780u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;

    // 0x01221780: 55 PUSH
        batch_guest_pc = 0x01221780u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221781: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221783: 5d POP
        batch_guest_pc = 0x01221783u;
        if (!memory.load32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t2a;
    // 0x01221784: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
