#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121eec0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121eec0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121eec0: 55 PUSH
        batch_guest_pc = 0x0121eec0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121eec1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121eec3: f30f1005c8175d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d17c8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121eecb: f30f1105d0195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d19d0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121eed3: f30f1005cc175d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d17ccu)) return BatchLiftStatus::invalid_memory;
    // 0x0121eedb: f30f1105d4195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d19d4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121eee3: f30f1005d0175d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d17d0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121eeeb: f30f1105d8195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d19d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121eef3: 5d POP
        batch_guest_pc = 0x0121eef3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121eef4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
