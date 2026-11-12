#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ae40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ae40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x0121ae40: 55 PUSH
        batch_guest_pc = 0x0121ae40u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae41: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ae43: f30f10054cb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb14cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae4b: f30f1105c40e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0ec4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae53: 5d POP
        batch_guest_pc = 0x0121ae53u;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x0121ae54: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
