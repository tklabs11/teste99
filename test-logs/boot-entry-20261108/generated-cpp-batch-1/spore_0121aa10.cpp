#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121aa10(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121aa10u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121aa10: 55 PUSH
        batch_guest_pc = 0x0121aa10u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa11: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121aa13: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa1b: f30f1105380e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e38u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa23: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa2b: f30f11053c0e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e3cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa33: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa3b: f30f1105400e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e40u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aa43: 5d POP
        batch_guest_pc = 0x0121aa43u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121aa44: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
