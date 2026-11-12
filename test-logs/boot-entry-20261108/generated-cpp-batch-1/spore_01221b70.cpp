#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221b70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221b70u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221b70: 55 PUSH
        batch_guest_pc = 0x01221b70u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221b71: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221b73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221b7b: f30f11051c245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d241cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221b83: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221b8b: f30f110520245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2420u)) return BatchLiftStatus::invalid_memory;
    // 0x01221b93: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221b9b: f30f110524245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2424u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ba3: 5d POP
        batch_guest_pc = 0x01221ba3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221ba4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
