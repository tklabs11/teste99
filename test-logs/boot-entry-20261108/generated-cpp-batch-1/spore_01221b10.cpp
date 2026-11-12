#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221b10(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221b10u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x01221b10: 55 PUSH
        batch_guest_pc = 0x01221b10u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221b11: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221b13: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221b1b: f30f5c0588c23e01 SUBSS
        batch_guest_pc = 0x01221b1bu;
        if (!memory.load32(0x013ec288u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x01221b23: f30f1105a8265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26a8u)) return BatchLiftStatus::invalid_memory;
    // 0x01221b2b: 5d POP
        batch_guest_pc = 0x01221b2bu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x01221b2c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
