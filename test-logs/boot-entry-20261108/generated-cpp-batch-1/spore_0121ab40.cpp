#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ab40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ab40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121ab40: 55 PUSH
        batch_guest_pc = 0x0121ab40u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab41: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ab43: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab4b: f30f1105b40d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0db4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab5b: f30f1105b80d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0db8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab63: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab6b: f30f1105bc0d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0dbcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab7b: f30f1105c00d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0dc0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ab83: 5d POP
        batch_guest_pc = 0x0121ab83u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121ab84: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
