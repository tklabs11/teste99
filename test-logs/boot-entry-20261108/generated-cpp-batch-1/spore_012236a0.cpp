#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012236a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012236a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x012236a0: 55 PUSH
        batch_guest_pc = 0x012236a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012236a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012236a3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012236ab: f30f5e0510c33e01 DIVSS
        batch_guest_pc = 0x012236abu;
        if (!memory.load32(0x013ec310u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x012236b3: f30f110598265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2698u)) return BatchLiftStatus::invalid_memory;
    // 0x012236bb: 5d POP
        batch_guest_pc = 0x012236bbu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x012236bc: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
