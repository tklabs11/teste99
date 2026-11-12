#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121d660(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121d660u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121d660: 55 PUSH
        batch_guest_pc = 0x0121d660u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d661: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121d663: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d66b: f30f110598155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1598u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d673: f30f1005d4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d67b: f30f11059c155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d159cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121d683: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d68b: f30f1105a0155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d15a0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d693: 5d POP
        batch_guest_pc = 0x0121d693u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121d694: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
