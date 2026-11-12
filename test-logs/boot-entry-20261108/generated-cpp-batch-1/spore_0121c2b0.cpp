#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c2b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c2b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x0121c2b0: 55 PUSH
        batch_guest_pc = 0x0121c2b0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c2b1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c2b3: f30f100534b23e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb234u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c2bb: f30f5905140f4701 MULSS
        batch_guest_pc = 0x0121c2bbu;
        if (!memory.load32(0x01470f14u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121c2c3: f30f1105b0165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d16b0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c2cb: 5d POP
        batch_guest_pc = 0x0121c2cbu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x0121c2cc: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
