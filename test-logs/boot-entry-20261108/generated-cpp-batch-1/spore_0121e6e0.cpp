#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e6e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e6e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e6e0: 55 PUSH
        batch_guest_pc = 0x0121e6e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e6e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6eb: f30f1105981a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a98u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6f3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6fb: f30f11059c1a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a9cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e703: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e70b: f30f1105a01a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1aa0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e713: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e71b: f30f1105a41a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1aa4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e723: 5d POP
        batch_guest_pc = 0x0121e723u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e724: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
