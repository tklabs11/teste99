#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012244a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012244a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x012244a0: 55 PUSH
        batch_guest_pc = 0x012244a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012244a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012244a3: f30f1005c4275d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d27c4u)) return BatchLiftStatus::invalid_memory;
    // 0x012244ab: f30f110538295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2938u)) return BatchLiftStatus::invalid_memory;
    // 0x012244b3: f30f1005c8275d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d27c8u)) return BatchLiftStatus::invalid_memory;
    // 0x012244bb: f30f11053c295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d293cu)) return BatchLiftStatus::invalid_memory;
    // 0x012244c3: f30f1005cc275d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d27ccu)) return BatchLiftStatus::invalid_memory;
    // 0x012244cb: f30f110540295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2940u)) return BatchLiftStatus::invalid_memory;
    // 0x012244d3: 5d POP
        batch_guest_pc = 0x012244d3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012244d4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
