#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121f5e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121f5e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121f5e0: 55 PUSH
        batch_guest_pc = 0x0121f5e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121f5e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5eb: f30f1105641a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a64u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5fb: f30f1105681a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a68u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f603: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f60b: f30f11056c1a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a6cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f613: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f61b: f30f1105701a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a70u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f623: 5d POP
        batch_guest_pc = 0x0121f623u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121f624: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
