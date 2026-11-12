#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121f4e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121f4e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121f4e0: 55 PUSH
        batch_guest_pc = 0x0121f4e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121f4e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121f4e3: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f4eb: f30f1105f4165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d16f4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f4f3: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f4fb: f30f1105f8165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d16f8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f503: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f50b: f30f1105fc165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d16fcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f513: 5d POP
        batch_guest_pc = 0x0121f513u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121f514: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
