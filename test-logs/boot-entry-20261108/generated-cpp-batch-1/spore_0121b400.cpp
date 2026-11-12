#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121b400(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121b400u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121b400: 55 PUSH
        batch_guest_pc = 0x0121b400u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121b401: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121b403: f30f1005600e5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0e60u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b40b: f30f1105540e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e54u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b413: f30f1005640e5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0e64u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b41b: f30f1105580e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e58u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b423: f30f1005680e5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0e68u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b42b: f30f11055c0e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e5cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121b433: 5d POP
        batch_guest_pc = 0x0121b433u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121b434: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
