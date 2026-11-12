#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e820(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e820u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e820: 55 PUSH
        batch_guest_pc = 0x0121e820u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e821: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e823: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e82b: f30f110500185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1800u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e833: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e83b: f30f110504185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1804u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e843: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e84b: f30f110508185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1808u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e853: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e85b: f30f11050c185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d180cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e863: 5d POP
        batch_guest_pc = 0x0121e863u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e864: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
