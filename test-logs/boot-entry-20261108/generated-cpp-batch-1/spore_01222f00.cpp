#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222f00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222f00u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01222f00: 55 PUSH
        batch_guest_pc = 0x01222f00u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222f01: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222f03: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f0b: f30f1105b8215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21b8u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f13: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f1b: f30f1105bc215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21bcu)) return BatchLiftStatus::invalid_memory;
    // 0x01222f23: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f2b: f30f1105c0215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21c0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f33: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f3b: f30f1105c4215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21c4u)) return BatchLiftStatus::invalid_memory;
    // 0x01222f43: 5d POP
        batch_guest_pc = 0x01222f43u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01222f44: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
