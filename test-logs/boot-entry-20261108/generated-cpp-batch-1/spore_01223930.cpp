#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223930(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223930u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01223930: 55 PUSH
        batch_guest_pc = 0x01223930u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223931: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223933: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122393b: f30f110544285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2844u)) return BatchLiftStatus::invalid_memory;
    // 0x01223943: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122394b: f30f110548285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2848u)) return BatchLiftStatus::invalid_memory;
    // 0x01223953: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122395b: f30f11054c285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d284cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223963: 5d POP
        batch_guest_pc = 0x01223963u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01223964: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
