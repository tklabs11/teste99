#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223870(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223870u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01223870: 55 PUSH
        batch_guest_pc = 0x01223870u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223871: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223873: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122387b: f30f110598295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2998u)) return BatchLiftStatus::invalid_memory;
    // 0x01223883: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122388b: f30f11059c295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d299cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223893: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122389b: f30f1105a0295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d29a0u)) return BatchLiftStatus::invalid_memory;
    // 0x012238a3: 5d POP
        batch_guest_pc = 0x012238a3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012238a4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
