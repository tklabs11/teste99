#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121a9d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121a9d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121a9d0: 55 PUSH
        batch_guest_pc = 0x0121a9d0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121a9d1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121a9d3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a9db: f30f110524115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1124u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a9e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a9eb: f30f110528115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1128u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a9f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a9fb: f30f11052c115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d112cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa03: 5d POP
        batch_guest_pc = 0x0121aa03u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121aa04: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
