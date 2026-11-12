#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121bae0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121bae0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121bae0: 55 PUSH
        batch_guest_pc = 0x0121bae0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121bae1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121bae3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121baeb: f30f1105b40f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fb4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121baf3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bafb: f30f1105b80f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fb8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb03: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb0b: f30f1105bc0f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fbcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb13: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb1b: f30f1105c00f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0fc0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb23: 5d POP
        batch_guest_pc = 0x0121bb23u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121bb24: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
