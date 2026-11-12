#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121a910(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121a910u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121a910: 55 PUSH
        batch_guest_pc = 0x0121a910u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121a911: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121a913: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a91b: f30f1105b0105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d10b0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a923: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a92b: f30f1105b4105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d10b4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a933: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a93b: f30f1105b8105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d10b8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a943: 5d POP
        batch_guest_pc = 0x0121a943u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121a944: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
