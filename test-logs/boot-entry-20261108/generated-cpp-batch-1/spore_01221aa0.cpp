#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221aa0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221aa0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t6a = 0;

    // 0x01221aa0: 55 PUSH
        batch_guest_pc = 0x01221aa0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221aa1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221aa3: f30f100508614801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01486108u)) return BatchLiftStatus::invalid_memory;
    // 0x01221aab: f30f59057cc23e01 MULSS
        batch_guest_pc = 0x01221aabu;
        if (!memory.load32(0x013ec27cu, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x01221ab3: f30f5e057cb13e01 DIVSS
        batch_guest_pc = 0x01221ab3u;
        if (!memory.load32(0x013eb17cu, t4a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t4a, 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x01221abb: f30f1105b0265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26b0u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ac3: 5d POP
        batch_guest_pc = 0x01221ac3u;
        if (!memory.load32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t6a;
    // 0x01221ac4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
