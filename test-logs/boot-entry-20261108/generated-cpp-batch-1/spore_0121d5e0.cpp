#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121d5e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121d5e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121d5e0: 55 PUSH
        batch_guest_pc = 0x0121d5e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d5e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121d5e3: f30f1005c8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d5eb: f30f110524155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1524u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d5f3: f30f1005c4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d5fb: f30f110528155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1528u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d603: f30f1005c0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d60b: f30f11052c155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d152cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121d613: 5d POP
        batch_guest_pc = 0x0121d613u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121d614: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
