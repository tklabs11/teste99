#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e390(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e390u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121e390: 55 PUSH
        batch_guest_pc = 0x0121e390u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e391: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e393: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e39b: f30f1105f4195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d19f4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e3a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e3ab: f30f1105f8195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d19f8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e3b3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e3bb: f30f1105fc195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d19fcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e3c3: 5d POP
        batch_guest_pc = 0x0121e3c3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121e3c4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
