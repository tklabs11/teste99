#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221d30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221d30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221d30: 55 PUSH
        batch_guest_pc = 0x01221d30u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221d31: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221d33: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221d3b: f30f11057c265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d267cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221d43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221d4b: f30f110580265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2680u)) return BatchLiftStatus::invalid_memory;
    // 0x01221d53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221d5b: f30f110584265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2684u)) return BatchLiftStatus::invalid_memory;
    // 0x01221d63: 5d POP
        batch_guest_pc = 0x01221d63u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221d64: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
