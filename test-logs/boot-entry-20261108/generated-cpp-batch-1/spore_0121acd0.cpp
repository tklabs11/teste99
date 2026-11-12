#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121acd0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121acd0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121acd0: 55 PUSH
        batch_guest_pc = 0x0121acd0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121acd1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121acd3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121acdb: f30f1105900f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f90u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ace3: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121aceb: f30f1105940f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f94u)) return BatchLiftStatus::invalid_memory;
    // 0x0121acf3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121acfb: f30f1105980f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f98u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad03: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad0b: f30f11059c0f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f9cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad13: 5d POP
        batch_guest_pc = 0x0121ad13u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121ad14: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
