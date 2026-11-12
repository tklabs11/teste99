#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e510(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e510u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121e510: 55 PUSH
        batch_guest_pc = 0x0121e510u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e511: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e513: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e51b: f30f110584185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1884u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e523: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e52b: f30f110588185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1888u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e533: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e53b: f30f11058c185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d188cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e543: 5d POP
        batch_guest_pc = 0x0121e543u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121e544: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
