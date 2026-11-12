#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c420(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c420u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121c420: 55 PUSH
        batch_guest_pc = 0x0121c420u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c421: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c423: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c42b: f30f1105a4145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d14a4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c433: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c43b: f30f1105a8145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d14a8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c443: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c44b: f30f1105ac145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d14acu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c453: 5d POP
        batch_guest_pc = 0x0121c453u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121c454: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
