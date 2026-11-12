#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c630(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c630u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121c630: 55 PUSH
        batch_guest_pc = 0x0121c630u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c631: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c633: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c63b: f30f11059c135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d139cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c643: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c64b: f30f1105a0135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13a0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c653: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c65b: f30f1105a4135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13a4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c663: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c66b: f30f1105a8135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13a8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c673: 5d POP
        batch_guest_pc = 0x0121c673u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121c674: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
