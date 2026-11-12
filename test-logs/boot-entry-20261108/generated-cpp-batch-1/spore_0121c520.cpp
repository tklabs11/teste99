#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c520(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c520u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121c520: 55 PUSH
        batch_guest_pc = 0x0121c520u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c521: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c523: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c52b: f30f110530165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1630u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c533: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c53b: f30f110534165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1634u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c543: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c54b: f30f110538165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1638u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c553: 5d POP
        batch_guest_pc = 0x0121c553u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121c554: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
