#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e780(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e780u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e780: 55 PUSH
        batch_guest_pc = 0x0121e780u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e781: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e783: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e78b: f30f110560195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1960u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e793: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e79b: f30f110564195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1964u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7a3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7ab: f30f110568195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1968u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7bb: f30f11056c195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d196cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e7c3: 5d POP
        batch_guest_pc = 0x0121e7c3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e7c4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
