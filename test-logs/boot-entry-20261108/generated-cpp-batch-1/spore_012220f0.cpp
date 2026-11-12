#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012220f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012220f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x012220f0: 55 PUSH
        batch_guest_pc = 0x012220f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012220f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012220f3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012220fb: f30f1105d0235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23d0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222103: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122210b: f30f1105d4235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23d4u)) return BatchLiftStatus::invalid_memory;
    // 0x01222113: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122211b: f30f1105d8235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23d8u)) return BatchLiftStatus::invalid_memory;
    // 0x01222123: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122212b: f30f1105dc235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23dcu)) return BatchLiftStatus::invalid_memory;
    // 0x01222133: 5d POP
        batch_guest_pc = 0x01222133u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01222134: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
