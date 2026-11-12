#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e870(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e870u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e870: 55 PUSH
        batch_guest_pc = 0x0121e870u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e871: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e873: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e87b: f30f110528195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1928u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e883: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e88b: f30f11052c195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d192cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e893: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e89b: f30f110530195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1930u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8ab: f30f110534195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1934u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8b3: 5d POP
        batch_guest_pc = 0x0121e8b3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e8b4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
