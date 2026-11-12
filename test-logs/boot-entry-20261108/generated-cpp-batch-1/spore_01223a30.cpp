#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223a30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223a30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01223a30: 55 PUSH
        batch_guest_pc = 0x01223a30u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223a31: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223a33: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223a3b: f30f1105282c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2c28u)) return BatchLiftStatus::invalid_memory;
    // 0x01223a43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223a4b: f30f11052c2c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2c2cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223a53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223a5b: f30f1105302c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2c30u)) return BatchLiftStatus::invalid_memory;
    // 0x01223a63: 5d POP
        batch_guest_pc = 0x01223a63u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01223a64: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
