#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221c30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221c30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221c30: 55 PUSH
        batch_guest_pc = 0x01221c30u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221c31: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221c33: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c3b: f30f1105fc225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22fcu)) return BatchLiftStatus::invalid_memory;
    // 0x01221c43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c4b: f30f110500235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2300u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c53: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c5b: f30f110504235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2304u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c63: 5d POP
        batch_guest_pc = 0x01221c63u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221c64: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
