#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121b9e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121b9e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121b9e0: 55 PUSH
        batch_guest_pc = 0x0121b9e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121b9e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121b9e3: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121b9eb: f30f1105480c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c48u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b9f3: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121b9fb: f30f11054c0c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c4cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba03: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba0b: f30f1105500c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c50u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba13: 5d POP
        batch_guest_pc = 0x0121ba13u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121ba14: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
