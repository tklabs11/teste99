#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e7d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e7d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e7d0: 55 PUSH
        batch_guest_pc = 0x0121e7d0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7d1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e7d3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7db: f30f1105401a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a40u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7e3: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7eb: f30f1105441a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a44u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7f3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7fb: f30f1105481a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a48u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e803: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e80b: f30f11054c1a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a4cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e813: 5d POP
        batch_guest_pc = 0x0121e813u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e814: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
