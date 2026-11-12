#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012238b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012238b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x012238b0: 55 PUSH
        batch_guest_pc = 0x012238b0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012238b1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012238b3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012238bb: f30f1105d0265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26d0u)) return BatchLiftStatus::invalid_memory;
    // 0x012238c3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012238cb: f30f1105d4265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26d4u)) return BatchLiftStatus::invalid_memory;
    // 0x012238d3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012238db: f30f1105d8265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26d8u)) return BatchLiftStatus::invalid_memory;
    // 0x012238e3: 5d POP
        batch_guest_pc = 0x012238e3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012238e4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
