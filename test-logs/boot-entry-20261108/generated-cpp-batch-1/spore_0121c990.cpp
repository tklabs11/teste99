#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c990(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c990u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121c990: 55 PUSH
        batch_guest_pc = 0x0121c990u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c991: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c993: f30f100594b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb194u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c99b: f30f110568165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1668u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c9a3: f30f100590b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb190u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c9ab: f30f11056c165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d166cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c9b3: f30f10058cb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb18cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c9bb: f30f110570165d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1670u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c9c3: 5d POP
        batch_guest_pc = 0x0121c9c3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121c9c4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
