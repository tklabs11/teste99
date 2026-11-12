#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223630(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223630u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t5a = 0;

    // 0x01223630: 55 PUSH
        batch_guest_pc = 0x01223630u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223631: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223633: f30f100520c33e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013ec320u)) return BatchLiftStatus::invalid_memory;
    // 0x0122363b: f30f5905140f4701 MULSS
        batch_guest_pc = 0x0122363bu;
        if (!memory.load32(0x01470f14u, t3a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t3a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x01223643: f30f110590265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2690u)) return BatchLiftStatus::invalid_memory;
    // 0x0122364b: 5d POP
        batch_guest_pc = 0x0122364bu;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x0122364c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
