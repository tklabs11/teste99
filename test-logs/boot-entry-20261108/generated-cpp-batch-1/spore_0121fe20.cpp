#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121fe20(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121fe20u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x0121fe20: 55 PUSH
        batch_guest_pc = 0x0121fe20u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121fe21: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121fe23: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121fe2b: f30f5e0500bc3e01 DIVSS
        batch_guest_pc = 0x0121fe2bu;
        if (!memory.load32(0x013ebc00u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121fe33: f30f1105ec1b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1becu)) return BatchLiftStatus::invalid_memory;
    // 0x0121fe3b: 5d POP
        batch_guest_pc = 0x0121fe3bu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x0121fe3c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
