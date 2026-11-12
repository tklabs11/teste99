#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121aa50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121aa50u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121aa50: 55 PUSH
        batch_guest_pc = 0x0121aa50u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa51: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121aa53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa5b: f30f1105bc105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d10bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa6b: f30f1105c0105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d10c0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa7b: f30f1105c4105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d10c4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa83: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa8b: f30f1105c8105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d10c8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa93: 5d POP
        batch_guest_pc = 0x0121aa93u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121aa94: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
