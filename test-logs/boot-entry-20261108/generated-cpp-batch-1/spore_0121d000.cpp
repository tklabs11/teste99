#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121d000(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121d000u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121d000: 55 PUSH
        batch_guest_pc = 0x0121d000u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d001: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121d003: f30f10057c125d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d127cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121d00b: f30f1105f8135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13f8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d013: f30f100580125d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1280u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d01b: f30f1105fc135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13fcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121d023: f30f100584125d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1284u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d02b: f30f110500145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1400u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d033: 5d POP
        batch_guest_pc = 0x0121d033u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121d034: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
