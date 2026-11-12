#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e550(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e550u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e550: 55 PUSH
        batch_guest_pc = 0x0121e550u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e551: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e553: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e55b: f30f1105681b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1b68u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e563: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e56b: f30f11056c1b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1b6cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e573: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e57b: f30f1105701b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1b70u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e583: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e58b: f30f1105741b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1b74u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e593: 5d POP
        batch_guest_pc = 0x0121e593u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e594: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
