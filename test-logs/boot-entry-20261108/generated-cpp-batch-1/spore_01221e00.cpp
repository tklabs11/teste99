#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221e00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221e00u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01221e00: 55 PUSH
        batch_guest_pc = 0x01221e00u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221e01: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221e03: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e0b: f30f110598235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2398u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e13: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e1b: f30f11059c235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d239cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221e23: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e2b: f30f1105a0235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23a0u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e33: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e3b: f30f1105a4235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23a4u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e43: 5d POP
        batch_guest_pc = 0x01221e43u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01221e44: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
