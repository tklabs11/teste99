#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012205b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012205b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x012205b0: 55 PUSH
        batch_guest_pc = 0x012205b0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012205b1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012205b3: f30f100594b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb194u)) return BatchLiftStatus::invalid_memory;
    // 0x012205bb: f30f1105fc205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20fcu)) return BatchLiftStatus::invalid_memory;
    // 0x012205c3: f30f100590b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb190u)) return BatchLiftStatus::invalid_memory;
    // 0x012205cb: f30f110500215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2100u)) return BatchLiftStatus::invalid_memory;
    // 0x012205d3: f30f10058cb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb18cu)) return BatchLiftStatus::invalid_memory;
    // 0x012205db: f30f110504215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2104u)) return BatchLiftStatus::invalid_memory;
    // 0x012205e3: 5d POP
        batch_guest_pc = 0x012205e3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012205e4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
