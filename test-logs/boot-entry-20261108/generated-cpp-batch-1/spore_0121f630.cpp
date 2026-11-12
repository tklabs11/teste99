#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121f630(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121f630u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121f630: 55 PUSH
        batch_guest_pc = 0x0121f630u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121f631: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121f633: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f63b: f30f110530175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1730u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f643: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f64b: f30f110534175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1734u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f653: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f65b: f30f110538175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1738u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f663: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f66b: f30f11053c175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d173cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f673: 5d POP
        batch_guest_pc = 0x0121f673u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121f674: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
