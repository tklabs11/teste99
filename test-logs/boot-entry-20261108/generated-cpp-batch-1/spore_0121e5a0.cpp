#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e5a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e5a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e5a0: 55 PUSH
        batch_guest_pc = 0x0121e5a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e5a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5ab: f30f1105f0185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d18f0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5b3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5bb: f30f1105f4185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d18f4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5c3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5cb: f30f1105f8185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d18f8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5d3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5db: f30f1105fc185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d18fcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5e3: 5d POP
        batch_guest_pc = 0x0121e5e3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e5e4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
