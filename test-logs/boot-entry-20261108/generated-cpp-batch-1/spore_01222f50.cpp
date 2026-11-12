#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222f50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222f50u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01222f50: 55 PUSH
        batch_guest_pc = 0x01222f50u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222f51: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222f53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f5b: f30f1105a8215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21a8u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f6b: f30f1105ac215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21acu)) return BatchLiftStatus::invalid_memory;
    // 0x01222f73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f7b: f30f1105b0215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21b0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f83: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f8b: f30f1105b4215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21b4u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f93: 5d POP
        batch_guest_pc = 0x01222f93u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01222f94: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
