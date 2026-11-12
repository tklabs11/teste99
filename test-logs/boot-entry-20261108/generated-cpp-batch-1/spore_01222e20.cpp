#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222e20(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222e20u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01222e20: 55 PUSH
        batch_guest_pc = 0x01222e20u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222e21: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222e23: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e2b: f30f110590255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2590u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e33: f30f1005d4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d4u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e3b: f30f110594255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2594u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e43: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e4b: f30f110598255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2598u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e53: 5d POP
        batch_guest_pc = 0x01222e53u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01222e54: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
