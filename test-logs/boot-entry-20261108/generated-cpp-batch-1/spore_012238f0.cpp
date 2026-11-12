#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012238f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012238f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x012238f0: 55 PUSH
        batch_guest_pc = 0x012238f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012238f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012238f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012238fb: f30f1105882a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2a88u)) return BatchLiftStatus::invalid_memory;
    // 0x01223903: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122390b: f30f11058c2a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2a8cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223913: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122391b: f30f1105902a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2a90u)) return BatchLiftStatus::invalid_memory;
    // 0x01223923: 5d POP
        batch_guest_pc = 0x01223923u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01223924: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
