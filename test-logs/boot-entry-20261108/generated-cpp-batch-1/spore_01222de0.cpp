#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222de0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222de0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01222de0: 55 PUSH
        batch_guest_pc = 0x01222de0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222de1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222de3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222deb: f30f11059c255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d259cu)) return BatchLiftStatus::invalid_memory;
    // 0x01222df3: f30f1005d0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222dfb: f30f1105a0255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d25a0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e03: f30f1005ccb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1ccu)) return BatchLiftStatus::invalid_memory;
    // 0x01222e0b: f30f1105a4255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d25a4u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e13: 5d POP
        batch_guest_pc = 0x01222e13u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01222e14: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
