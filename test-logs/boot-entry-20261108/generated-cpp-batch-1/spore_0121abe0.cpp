#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121abe0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121abe0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121abe0: 55 PUSH
        batch_guest_pc = 0x0121abe0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121abe1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121abe3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121abeb: f30f1105e80f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fe8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121abf3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121abfb: f30f1105ec0f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fecu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac03: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac0b: f30f1105f00f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0ff0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac13: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac1b: f30f1105f40f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0ff4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac23: 5d POP
        batch_guest_pc = 0x0121ac23u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121ac24: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
