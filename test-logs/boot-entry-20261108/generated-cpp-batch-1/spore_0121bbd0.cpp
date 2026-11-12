#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121bbd0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121bbd0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121bbd0: 55 PUSH
        batch_guest_pc = 0x0121bbd0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbd1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121bbd3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbdb: f30f1105580c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c58u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbe3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbeb: f30f11055c0c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c5cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbf3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbfb: f30f1105600c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c60u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bc03: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bc0b: f30f1105640c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c64u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bc13: 5d POP
        batch_guest_pc = 0x0121bc13u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121bc14: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
