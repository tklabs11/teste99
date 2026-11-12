#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121f6d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121f6d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121f6d0: 55 PUSH
        batch_guest_pc = 0x0121f6d0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6d1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121f6d3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6db: f30f110504175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1704u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6eb: f30f110508175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1708u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6fb: f30f11050c175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d170cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f703: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f70b: f30f110510175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1710u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f713: 5d POP
        batch_guest_pc = 0x0121f713u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121f714: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
