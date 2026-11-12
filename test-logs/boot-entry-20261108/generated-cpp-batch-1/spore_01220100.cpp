#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220100(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220100u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01220100: 55 PUSH
        batch_guest_pc = 0x01220100u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220101: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220103: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122010b: f30f1105a01e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1ea0u)) return BatchLiftStatus::invalid_memory;
    // 0x01220113: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122011b: f30f1105a41e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1ea4u)) return BatchLiftStatus::invalid_memory;
    // 0x01220123: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122012b: f30f1105a81e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1ea8u)) return BatchLiftStatus::invalid_memory;
    // 0x01220133: 5d POP
        batch_guest_pc = 0x01220133u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01220134: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
