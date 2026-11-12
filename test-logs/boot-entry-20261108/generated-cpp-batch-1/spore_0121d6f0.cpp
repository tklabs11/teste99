#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121d6f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121d6f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121d6f0: 55 PUSH
        batch_guest_pc = 0x0121d6f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d6f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121d6f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d6fb: f30f1105d0115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11d0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d703: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d70b: f30f1105d4115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11d4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d713: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d71b: f30f1105d8115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d723: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d72b: f30f1105dc115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11dcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121d733: 5d POP
        batch_guest_pc = 0x0121d733u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121d734: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
