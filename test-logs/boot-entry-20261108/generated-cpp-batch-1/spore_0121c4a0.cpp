#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c4a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c4a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121c4a0: 55 PUSH
        batch_guest_pc = 0x0121c4a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c4a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4ab: f30f110514165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1614u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4b3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4bb: f30f110518165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1618u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4cb: f30f11051c165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d161cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4d3: 5d POP
        batch_guest_pc = 0x0121c4d3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121c4d4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
