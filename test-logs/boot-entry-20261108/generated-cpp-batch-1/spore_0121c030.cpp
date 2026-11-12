#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c030(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c030u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x0121c030: 55 PUSH
        batch_guest_pc = 0x0121c030u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c031: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c033: f30f100534b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb134u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c03b: f30f110530115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1130u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c043: 5d POP
        batch_guest_pc = 0x0121c043u;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x0121c044: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
