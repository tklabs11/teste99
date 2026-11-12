#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c3a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c3a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121c3a0: 55 PUSH
        batch_guest_pc = 0x0121c3a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c3a3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3ab: f30f110528145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1428u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3bb: f30f11052c145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d142cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3cb: f30f110530145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1430u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c3d3: 5d POP
        batch_guest_pc = 0x0121c3d3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121c3d4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
