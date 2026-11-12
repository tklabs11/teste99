#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012202f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012202f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x012202f0: 55 PUSH
        batch_guest_pc = 0x012202f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012202f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012202f3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012202fb: f30f1105a81d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1da8u)) return BatchLiftStatus::invalid_memory;
    // 0x01220303: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122030b: f30f1105ac1d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1dacu)) return BatchLiftStatus::invalid_memory;
    // 0x01220313: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122031b: f30f1105b01d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1db0u)) return BatchLiftStatus::invalid_memory;
    // 0x01220323: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122032b: f30f1105b41d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1db4u)) return BatchLiftStatus::invalid_memory;
    // 0x01220333: 5d POP
        batch_guest_pc = 0x01220333u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01220334: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
