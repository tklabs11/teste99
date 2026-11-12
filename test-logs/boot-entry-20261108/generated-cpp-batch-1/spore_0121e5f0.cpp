#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e5f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e5f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e5f0: 55 PUSH
        batch_guest_pc = 0x0121e5f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e5f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e5fb: f30f110514185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1814u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e603: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e60b: f30f110518185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1818u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e613: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e61b: f30f11051c185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d181cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e623: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e62b: f30f110520185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1820u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e633: 5d POP
        batch_guest_pc = 0x0121e633u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e634: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
