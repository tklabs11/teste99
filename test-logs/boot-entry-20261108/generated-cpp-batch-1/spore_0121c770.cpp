#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c770(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c770u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121c770: 55 PUSH
        batch_guest_pc = 0x0121c770u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c771: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c773: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c77b: f30f110548155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1548u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c783: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c78b: f30f11054c155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d154cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c793: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c79b: f30f110550155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1550u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7a3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7ab: f30f110554155d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1554u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c7b3: 5d POP
        batch_guest_pc = 0x0121c7b3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121c7b4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
