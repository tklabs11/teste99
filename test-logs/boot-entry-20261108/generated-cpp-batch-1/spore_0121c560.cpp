#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c560(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c560u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121c560: 55 PUSH
        batch_guest_pc = 0x0121c560u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c561: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c563: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c56b: f30f110588165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1688u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c573: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c57b: f30f11058c165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d168cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c583: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c58b: f30f110590165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1690u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c593: 5d POP
        batch_guest_pc = 0x0121c593u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121c594: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
