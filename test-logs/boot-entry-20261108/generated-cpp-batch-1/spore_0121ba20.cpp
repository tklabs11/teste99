#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ba20(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ba20u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121ba20: 55 PUSH
        batch_guest_pc = 0x0121ba20u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba21: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ba23: f30f1005c8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba2b: f30f1105c40f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fc4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba33: f30f1005c4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba3b: f30f1105c80f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fc8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba43: f30f1005c0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba4b: f30f1105cc0f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fccu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba53: 5d POP
        batch_guest_pc = 0x0121ba53u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121ba54: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
