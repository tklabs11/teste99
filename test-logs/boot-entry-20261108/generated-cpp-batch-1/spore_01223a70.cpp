#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223a70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223a70u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01223a70: 55 PUSH
        batch_guest_pc = 0x01223a70u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223a71: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223a73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223a7b: f30f110574285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2874u)) return BatchLiftStatus::invalid_memory;
    // 0x01223a83: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223a8b: f30f110578285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2878u)) return BatchLiftStatus::invalid_memory;
    // 0x01223a93: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223a9b: f30f11057c285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d287cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223aa3: 5d POP
        batch_guest_pc = 0x01223aa3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01223aa4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
