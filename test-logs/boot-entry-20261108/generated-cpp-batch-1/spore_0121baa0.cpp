#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121baa0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121baa0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121baa0: 55 PUSH
        batch_guest_pc = 0x0121baa0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121baa1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121baa3: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121baab: f30f110538105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1038u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bab3: f30f1005d4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121babb: f30f11053c105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d103cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121bac3: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bacb: f30f110540105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1040u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bad3: 5d POP
        batch_guest_pc = 0x0121bad3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121bad4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
