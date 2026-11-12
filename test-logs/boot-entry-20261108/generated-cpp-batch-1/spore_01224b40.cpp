#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01224b40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01224b40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01224b40: 55 PUSH
        batch_guest_pc = 0x01224b40u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01224b41: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01224b43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224b4b: f30f1105b82a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2ab8u)) return BatchLiftStatus::invalid_memory;
    // 0x01224b53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224b5b: f30f1105bc2a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2abcu)) return BatchLiftStatus::invalid_memory;
    // 0x01224b63: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01224b6b: f30f1105c02a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2ac0u)) return BatchLiftStatus::invalid_memory;
    // 0x01224b73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224b7b: f30f1105c42a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2ac4u)) return BatchLiftStatus::invalid_memory;
    // 0x01224b83: 5d POP
        batch_guest_pc = 0x01224b83u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01224b84: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
