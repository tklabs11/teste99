#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121a720(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121a720u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x0121a720: 55 PUSH
        batch_guest_pc = 0x0121a720u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121a721: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121a723: f30f100544b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb144u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a72b: f30f5905140f4701 MULSS
        batch_guest_pc = 0x0121a72bu;
        if (!memory.load32(0x01470f14u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121a733: f30f110538115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1138u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a73b: 5d POP
        batch_guest_pc = 0x0121a73bu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x0121a73c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
