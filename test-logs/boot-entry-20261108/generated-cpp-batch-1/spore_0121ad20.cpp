#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ad20(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ad20u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121ad20: 55 PUSH
        batch_guest_pc = 0x0121ad20u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad21: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ad23: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad2b: f30f1105540d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d54u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad33: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad3b: f30f1105580d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d58u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad4b: f30f11055c0d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d5cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad53: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad5b: f30f1105600d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d60u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad63: 5d POP
        batch_guest_pc = 0x0121ad63u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121ad64: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
