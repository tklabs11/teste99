#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c7c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c7c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121c7c0: 55 PUSH
        batch_guest_pc = 0x0121c7c0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7c1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c7c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7cb: f30f110530155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1530u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7d3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7db: f30f110534155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1534u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7e3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7eb: f30f110538155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1538u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7fb: f30f11053c155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d153cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c803: 5d POP
        batch_guest_pc = 0x0121c803u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121c804: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
