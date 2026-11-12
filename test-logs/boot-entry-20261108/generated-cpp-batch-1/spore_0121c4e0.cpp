#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c4e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c4e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121c4e0: 55 PUSH
        batch_guest_pc = 0x0121c4e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c4e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4eb: f30f110508145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1408u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4f3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c4fb: f30f11050c145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d140cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c503: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c50b: f30f110510145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1410u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c513: 5d POP
        batch_guest_pc = 0x0121c513u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121c514: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
