#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121fe00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121fe00u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x0121fe00: 55 PUSH
        batch_guest_pc = 0x0121fe00u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121fe01: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121fe03: f30f1005140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x0121fe0b: f30f590508bc3e01 MULSS
        batch_guest_pc = 0x0121fe0bu;
        if (!memory.load32(0x013ebc08u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121fe13: f30f1105e01b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1be0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121fe1b: 5d POP
        batch_guest_pc = 0x0121fe1bu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x0121fe1c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
