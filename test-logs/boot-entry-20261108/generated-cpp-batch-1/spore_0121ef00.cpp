#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ef00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ef00u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121ef00: 55 PUSH
        batch_guest_pc = 0x0121ef00u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef01: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ef03: f30f10050c195d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d190cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef0b: f30f110500195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1900u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef13: f30f100510195d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1910u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef1b: f30f110504195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1904u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef23: f30f100514195d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1914u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef2b: f30f110508195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1908u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ef33: 5d POP
        batch_guest_pc = 0x0121ef33u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121ef34: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
