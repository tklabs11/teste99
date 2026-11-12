#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c720(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c720u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121c720: 55 PUSH
        batch_guest_pc = 0x0121c720u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c721: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c723: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c72b: f30f110588155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1588u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c733: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c73b: f30f11058c155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d158cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c743: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c74b: f30f110590155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1590u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c753: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c75b: f30f110594155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1594u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c763: 5d POP
        batch_guest_pc = 0x0121c763u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121c764: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
