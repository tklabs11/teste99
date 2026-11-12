#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220520(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220520u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01220520: 55 PUSH
        batch_guest_pc = 0x01220520u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220521: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220523: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122052b: f30f1105701e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e70u)) return BatchLiftStatus::invalid_memory;
    // 0x01220533: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122053b: f30f1105741e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e74u)) return BatchLiftStatus::invalid_memory;
    // 0x01220543: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122054b: f30f1105781e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e78u)) return BatchLiftStatus::invalid_memory;
    // 0x01220553: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122055b: f30f11057c1e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e7cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220563: 5d POP
        batch_guest_pc = 0x01220563u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01220564: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
