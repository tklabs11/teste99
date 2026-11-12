#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223b50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223b50u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01223b50: 55 PUSH
        batch_guest_pc = 0x01223b50u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223b51: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223b53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223b5b: f30f110504285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2804u)) return BatchLiftStatus::invalid_memory;
    // 0x01223b63: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223b6b: f30f110508285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2808u)) return BatchLiftStatus::invalid_memory;
    // 0x01223b73: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223b7b: f30f11050c285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d280cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223b83: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223b8b: f30f110510285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2810u)) return BatchLiftStatus::invalid_memory;
    // 0x01223b93: 5d POP
        batch_guest_pc = 0x01223b93u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01223b94: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
