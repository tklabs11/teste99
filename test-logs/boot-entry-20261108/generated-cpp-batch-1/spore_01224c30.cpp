#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01224c30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01224c30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01224c30: 55 PUSH
        batch_guest_pc = 0x01224c30u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01224c31: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01224c33: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224c3b: f30f1105f4265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26f4u)) return BatchLiftStatus::invalid_memory;
    // 0x01224c43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224c4b: f30f1105f8265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26f8u)) return BatchLiftStatus::invalid_memory;
    // 0x01224c53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224c5b: f30f1105fc265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26fcu)) return BatchLiftStatus::invalid_memory;
    // 0x01224c63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224c6b: f30f110500275d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2700u)) return BatchLiftStatus::invalid_memory;
    // 0x01224c73: 5d POP
        batch_guest_pc = 0x01224c73u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01224c74: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
