#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223dd0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223dd0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01223dd0: 55 PUSH
        batch_guest_pc = 0x01223dd0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223dd1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223dd3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223ddb: f30f110518295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2918u)) return BatchLiftStatus::invalid_memory;
    // 0x01223de3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223deb: f30f11051c295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d291cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223df3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223dfb: f30f110520295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2920u)) return BatchLiftStatus::invalid_memory;
    // 0x01223e03: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223e0b: f30f110524295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2924u)) return BatchLiftStatus::invalid_memory;
    // 0x01223e13: 5d POP
        batch_guest_pc = 0x01223e13u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01223e14: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
