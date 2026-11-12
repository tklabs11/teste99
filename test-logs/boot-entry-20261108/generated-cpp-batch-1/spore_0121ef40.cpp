#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ef40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ef40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121ef40: 55 PUSH
        batch_guest_pc = 0x0121ef40u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef41: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ef43: f30f1005d4175d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d17d4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef4b: f30f110548195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1948u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef53: f30f1005d8175d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d17d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef5b: f30f11054c195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d194cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef63: f30f1005dc175d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d17dcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef6b: f30f110550195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1950u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef73: 5d POP
        batch_guest_pc = 0x0121ef73u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121ef74: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
