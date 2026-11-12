#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e450(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e450u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121e450: 55 PUSH
        batch_guest_pc = 0x0121e450u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e451: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e453: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e45b: f30f110554195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1954u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e463: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e46b: f30f110558195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1958u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e473: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e47b: f30f11055c195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d195cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e483: 5d POP
        batch_guest_pc = 0x0121e483u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121e484: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
