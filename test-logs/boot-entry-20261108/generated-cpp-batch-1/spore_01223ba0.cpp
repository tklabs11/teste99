#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223ba0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223ba0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01223ba0: 55 PUSH
        batch_guest_pc = 0x01223ba0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223ba1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223ba3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223bab: f30f110550285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2850u)) return BatchLiftStatus::invalid_memory;
    // 0x01223bb3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223bbb: f30f110554285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2854u)) return BatchLiftStatus::invalid_memory;
    // 0x01223bc3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223bcb: f30f110558285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2858u)) return BatchLiftStatus::invalid_memory;
    // 0x01223bd3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223bdb: f30f11055c285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d285cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223be3: 5d POP
        batch_guest_pc = 0x01223be3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01223be4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
