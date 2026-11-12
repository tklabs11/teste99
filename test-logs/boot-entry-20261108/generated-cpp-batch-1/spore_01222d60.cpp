#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222d60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222d60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01222d60: 55 PUSH
        batch_guest_pc = 0x01222d60u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222d61: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222d63: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x01222d6b: f30f110598215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2198u)) return BatchLiftStatus::invalid_memory;
    // 0x01222d73: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x01222d7b: f30f11059c215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d219cu)) return BatchLiftStatus::invalid_memory;
    // 0x01222d83: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x01222d8b: f30f1105a0215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21a0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222d93: 5d POP
        batch_guest_pc = 0x01222d93u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01222d94: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
