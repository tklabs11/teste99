#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121a850(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121a850u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121a850: 55 PUSH
        batch_guest_pc = 0x0121a850u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121a851: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121a853: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a85b: f30f1105340c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c34u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a863: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a86b: f30f1105380c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c38u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a873: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a87b: f30f11053c0c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c3cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121a883: 5d POP
        batch_guest_pc = 0x0121a883u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121a884: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
