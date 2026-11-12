#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e270(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e270u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x0121e270: 55 PUSH
        batch_guest_pc = 0x0121e270u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e271: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e273: f30f1005140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e27b: f30f5905a8bb3e01 MULSS
        batch_guest_pc = 0x0121e27bu;
        if (!memory.load32(0x013ebba8u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121e283: f30f1105f41b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1bf4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e28b: 5d POP
        batch_guest_pc = 0x0121e28bu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x0121e28c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
