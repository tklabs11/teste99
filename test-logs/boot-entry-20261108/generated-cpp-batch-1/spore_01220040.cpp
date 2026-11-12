#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220040(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220040u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01220040: 55 PUSH
        batch_guest_pc = 0x01220040u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220041: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220043: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122004b: f30f11053c1f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f3cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220053: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122005b: f30f1105401f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f40u)) return BatchLiftStatus::invalid_memory;
    // 0x01220063: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122006b: f30f1105441f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f44u)) return BatchLiftStatus::invalid_memory;
    // 0x01220073: 5d POP
        batch_guest_pc = 0x01220073u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01220074: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
