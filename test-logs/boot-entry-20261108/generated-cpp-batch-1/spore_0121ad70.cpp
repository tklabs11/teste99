#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ad70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ad70u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121ad70: 55 PUSH
        batch_guest_pc = 0x0121ad70u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad71: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ad73: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad7b: f30f11057c0e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e7cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad83: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad8b: f30f1105800e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e80u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad93: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ad9b: f30f1105840e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e84u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ada3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121adab: f30f1105880e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e88u)) return BatchLiftStatus::invalid_memory;
    // 0x0121adb3: 5d POP
        batch_guest_pc = 0x0121adb3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121adb4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
