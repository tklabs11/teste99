#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222e60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222e60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01222e60: 55 PUSH
        batch_guest_pc = 0x01222e60u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222e61: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222e63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e6b: f30f11050c255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d250cu)) return BatchLiftStatus::invalid_memory;
    // 0x01222e73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e7b: f30f110510255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2510u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e83: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e8b: f30f110514255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2514u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e93: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222e9b: f30f110518255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2518u)) return BatchLiftStatus::invalid_memory;
    // 0x01222ea3: 5d POP
        batch_guest_pc = 0x01222ea3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01222ea4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
