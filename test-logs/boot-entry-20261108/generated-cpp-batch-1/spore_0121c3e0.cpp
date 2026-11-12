#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c3e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c3e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121c3e0: 55 PUSH
        batch_guest_pc = 0x0121c3e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c3e3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3eb: f30f110580115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1180u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3f3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3fb: f30f110584115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1184u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c403: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c40b: f30f110588115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1188u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c413: 5d POP
        batch_guest_pc = 0x0121c413u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121c414: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
