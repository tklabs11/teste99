#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c6d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c6d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121c6d0: 55 PUSH
        batch_guest_pc = 0x0121c6d0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6d1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c6d3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6db: f30f110508135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1308u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6eb: f30f11050c135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d130cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6f3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6fb: f30f110510135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1310u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c703: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c70b: f30f110514135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1314u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c713: 5d POP
        batch_guest_pc = 0x0121c713u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121c714: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
