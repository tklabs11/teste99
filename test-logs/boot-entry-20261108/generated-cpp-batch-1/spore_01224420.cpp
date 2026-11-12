#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01224420(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01224420u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01224420: 55 PUSH
        batch_guest_pc = 0x01224420u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01224421: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01224423: f30f1005b8275d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d27b8u)) return BatchLiftStatus::invalid_memory;
    // 0x0122442b: f30f1105242a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2a24u)) return BatchLiftStatus::invalid_memory;
    // 0x01224433: f30f1005bc275d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d27bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0122443b: f30f1105282a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2a28u)) return BatchLiftStatus::invalid_memory;
    // 0x01224443: f30f1005c0275d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d27c0u)) return BatchLiftStatus::invalid_memory;
    // 0x0122444b: f30f11052c2a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2a2cu)) return BatchLiftStatus::invalid_memory;
    // 0x01224453: 5d POP
        batch_guest_pc = 0x01224453u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01224454: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
