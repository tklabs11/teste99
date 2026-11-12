#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221210(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221210u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221210: 55 PUSH
        batch_guest_pc = 0x01221210u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221211: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221213: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122121b: f30f11053c205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d203cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221223: f30f1005d0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d0u)) return BatchLiftStatus::invalid_memory;
    // 0x0122122b: f30f110540205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2040u)) return BatchLiftStatus::invalid_memory;
    // 0x01221233: f30f1005ccb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1ccu)) return BatchLiftStatus::invalid_memory;
    // 0x0122123b: f30f110544205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2044u)) return BatchLiftStatus::invalid_memory;
    // 0x01221243: 5d POP
        batch_guest_pc = 0x01221243u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221244: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
