#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e4d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e4d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121e4d0: 55 PUSH
        batch_guest_pc = 0x0121e4d0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e4d1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e4d3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e4db: f30f1105d01b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1bd0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e4e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e4eb: f30f1105d41b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1bd4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e4f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e4fb: f30f1105d81b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1bd8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e503: 5d POP
        batch_guest_pc = 0x0121e503u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121e504: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
