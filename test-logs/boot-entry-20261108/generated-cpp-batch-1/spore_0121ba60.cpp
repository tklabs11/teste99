#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ba60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ba60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121ba60: 55 PUSH
        batch_guest_pc = 0x0121ba60u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba61: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ba63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba6b: f30f110544105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1044u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba73: f30f1005d0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba7b: f30f110548105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1048u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba83: f30f1005ccb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1ccu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba8b: f30f11054c105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d104cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ba93: 5d POP
        batch_guest_pc = 0x0121ba93u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121ba94: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
