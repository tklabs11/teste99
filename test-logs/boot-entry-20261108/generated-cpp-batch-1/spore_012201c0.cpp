#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012201c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012201c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x012201c0: 55 PUSH
        batch_guest_pc = 0x012201c0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012201c1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012201c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012201cb: f30f1105cc1d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1dccu)) return BatchLiftStatus::invalid_memory;
    // 0x012201d3: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x012201db: f30f1105d01d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1dd0u)) return BatchLiftStatus::invalid_memory;
    // 0x012201e3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012201eb: f30f1105d41d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1dd4u)) return BatchLiftStatus::invalid_memory;
    // 0x012201f3: 5d POP
        batch_guest_pc = 0x012201f3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012201f4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
