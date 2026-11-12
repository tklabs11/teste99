#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012220a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012220a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x012220a0: 55 PUSH
        batch_guest_pc = 0x012220a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012220a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012220a3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012220ab: f30f1105a8225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22a8u)) return BatchLiftStatus::invalid_memory;
    // 0x012220b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012220bb: f30f1105ac225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22acu)) return BatchLiftStatus::invalid_memory;
    // 0x012220c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012220cb: f30f1105b0225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22b0u)) return BatchLiftStatus::invalid_memory;
    // 0x012220d3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012220db: f30f1105b4225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22b4u)) return BatchLiftStatus::invalid_memory;
    // 0x012220e3: 5d POP
        batch_guest_pc = 0x012220e3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x012220e4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
