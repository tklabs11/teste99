#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121b440(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121b440u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121b440: 55 PUSH
        batch_guest_pc = 0x0121b440u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121b441: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121b443: f30f1005280d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0d28u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b44b: f30f11059c0e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e9cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121b453: f30f10052c0d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0d2cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121b45b: f30f1105a00e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0ea0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b463: f30f1005300d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0d30u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b46b: f30f1105a40e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0ea4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b473: 5d POP
        batch_guest_pc = 0x0121b473u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121b474: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
