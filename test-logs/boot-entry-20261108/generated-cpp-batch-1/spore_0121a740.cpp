#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121a740(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121a740u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t6a = 0;

    // 0x0121a740: 55 PUSH
        batch_guest_pc = 0x0121a740u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121a741: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121a743: f30f100508614801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01486108u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a74b: f30f590544b13e01 MULSS
        batch_guest_pc = 0x0121a74bu;
        if (!memory.load32(0x013eb144u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121a753: f30f5e057cb13e01 DIVSS
        batch_guest_pc = 0x0121a753u;
        if (!memory.load32(0x013eb17cu, t4a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t4a, 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0121a75b: f30f110544115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1144u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a763: 5d POP
        batch_guest_pc = 0x0121a763u;
        if (!memory.load32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t6a;
    // 0x0121a764: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
