#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121dec0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121dec0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x0121dec0: 55 PUSH
        batch_guest_pc = 0x0121dec0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121dec1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121dec3: f30f1005140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x0121decb: f30f59057cb23e01 MULSS
        batch_guest_pc = 0x0121decbu;
        if (!memory.load32(0x013eb27cu, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121ded3: f30f110598165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1698u)) return BatchLiftStatus::invalid_memory;
    // 0x0121dedb: 5d POP
        batch_guest_pc = 0x0121dedbu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x0121dedc: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
