#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012239b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012239b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x012239b0: 55 PUSH
        batch_guest_pc = 0x012239b0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012239b1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012239b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012239bb: f30f110544295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2944u)) return BatchLiftStatus::invalid_memory;
    // 0x012239c3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012239cb: f30f110548295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2948u)) return BatchLiftStatus::invalid_memory;
    // 0x012239d3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012239db: f30f11054c295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d294cu)) return BatchLiftStatus::invalid_memory;
    // 0x012239e3: 5d POP
        batch_guest_pc = 0x012239e3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012239e4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
