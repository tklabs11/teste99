#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221bf0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221bf0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221bf0: 55 PUSH
        batch_guest_pc = 0x01221bf0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221bf1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221bf3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221bfb: f30f11059c245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d249cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221c03: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c0b: f30f1105a0245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d24a0u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c13: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c1b: f30f1105a4245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d24a4u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c23: 5d POP
        batch_guest_pc = 0x01221c23u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221c24: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
