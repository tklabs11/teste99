#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121a7b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121a7b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x0121a7b0: 55 PUSH
        batch_guest_pc = 0x0121a7b0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121a7b1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121a7b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a7bb: f30f5c0550b13e01 SUBSS
        batch_guest_pc = 0x0121a7bbu;
        if (!memory.load32(0x013eb150u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121a7c3: f30f11053c115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d113cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121a7cb: 5d POP
        batch_guest_pc = 0x0121a7cbu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x0121a7cc: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
