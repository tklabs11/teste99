#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121aaf0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121aaf0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121aaf0: 55 PUSH
        batch_guest_pc = 0x0121aaf0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121aaf1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121aaf3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aafb: f30f1105680d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d68u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab03: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab0b: f30f11056c0d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d6cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab13: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab1b: f30f1105700d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d70u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab23: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab2b: f30f1105740d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d74u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab33: 5d POP
        batch_guest_pc = 0x0121ab33u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121ab34: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
