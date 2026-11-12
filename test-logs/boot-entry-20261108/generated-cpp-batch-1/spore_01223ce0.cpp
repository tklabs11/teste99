#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223ce0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223ce0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01223ce0: 55 PUSH
        batch_guest_pc = 0x01223ce0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223ce1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223ce3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223ceb: f30f110550295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2950u)) return BatchLiftStatus::invalid_memory;
    // 0x01223cf3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223cfb: f30f110554295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2954u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d03: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d0b: f30f110558295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2958u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d13: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d1b: f30f11055c295d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d295cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223d23: 5d POP
        batch_guest_pc = 0x01223d23u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01223d24: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
