#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121bb30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121bb30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121bb30: 55 PUSH
        batch_guest_pc = 0x0121bb30u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb31: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121bb33: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb3b: f30f1105840c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c84u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb4b: f30f1105880c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c88u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb5b: f30f11058c0c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c8cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb6b: f30f1105900c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c90u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb73: 5d POP
        batch_guest_pc = 0x0121bb73u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121bb74: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
