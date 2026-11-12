#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c2d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c2d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t6a = 0;

    // 0x0121c2d0: 55 PUSH
        batch_guest_pc = 0x0121c2d0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c2d1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c2d3: f30f100508614801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01486108u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c2db: f30f590534b23e01 MULSS
        batch_guest_pc = 0x0121c2dbu;
        if (!memory.load32(0x013eb234u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121c2e3: f30f5e057cb13e01 DIVSS
        batch_guest_pc = 0x0121c2e3u;
        if (!memory.load32(0x013eb17cu, t4a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t4a, 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121c2eb: f30f1105bc165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d16bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c2f3: 5d POP
        batch_guest_pc = 0x0121c2f3u;
        if (!memory.load32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t6a;
    // 0x0121c2f4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
