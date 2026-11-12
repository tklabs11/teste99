#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121a810(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121a810u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121a810: 55 PUSH
        batch_guest_pc = 0x0121a810u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121a811: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121a813: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a81b: f30f1105c80e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0ec8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a823: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a82b: f30f1105cc0e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0eccu)) return BatchLiftStatus::invalid_memory;
    // 0x0121a833: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a83b: f30f1105d00e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0ed0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a843: 5d POP
        batch_guest_pc = 0x0121a843u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121a844: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
