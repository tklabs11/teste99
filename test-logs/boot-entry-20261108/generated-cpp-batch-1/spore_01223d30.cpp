#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223d30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223d30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01223d30: 55 PUSH
        batch_guest_pc = 0x01223d30u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223d31: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223d33: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d3b: f30f1105942a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2a94u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d43: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223d4b: f30f1105982a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2a98u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d53: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d5b: f30f11059c2a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2a9cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223d63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d6b: f30f1105a02a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2aa0u)) return BatchLiftStatus::invalid_memory;
    // 0x01223d73: 5d POP
        batch_guest_pc = 0x01223d73u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01223d74: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
