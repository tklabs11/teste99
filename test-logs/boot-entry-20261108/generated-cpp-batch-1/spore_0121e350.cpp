#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e350(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e350u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121e350: 55 PUSH
        batch_guest_pc = 0x0121e350u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e351: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e353: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e35b: f30f1105e0165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d16e0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e363: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e36b: f30f1105e4165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d16e4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e373: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e37b: f30f1105e8165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d16e8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e383: 5d POP
        batch_guest_pc = 0x0121e383u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121e384: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
