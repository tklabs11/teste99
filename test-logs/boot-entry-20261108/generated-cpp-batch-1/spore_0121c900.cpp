#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c900(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c900u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121c900: 55 PUSH
        batch_guest_pc = 0x0121c900u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c901: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c903: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c90b: f30f1105d8135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c913: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c91b: f30f1105dc135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13dcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c923: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c92b: f30f1105e0135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13e0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c933: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c93b: f30f1105e4135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13e4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c943: 5d POP
        batch_guest_pc = 0x0121c943u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121c944: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
