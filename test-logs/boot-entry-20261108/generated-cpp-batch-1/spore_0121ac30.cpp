#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ac30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ac30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121ac30: 55 PUSH
        batch_guest_pc = 0x0121ac30u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac31: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ac33: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac3b: f30f1105d00f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fd0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac4b: f30f1105d40f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fd4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac53: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac5b: f30f1105d80f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fd8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac6b: f30f1105dc0f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fdcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ac73: 5d POP
        batch_guest_pc = 0x0121ac73u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121ac74: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
