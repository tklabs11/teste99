#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121b980(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121b980u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x0121b980: 55 PUSH
        batch_guest_pc = 0x0121b980u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121b981: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121b983: f30f1005c40d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0dc4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b98b: f30f1105d80c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0cd8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b993: 5d POP
        batch_guest_pc = 0x0121b993u;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x0121b994: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
