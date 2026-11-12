#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222140(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222140u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01222140: 55 PUSH
        batch_guest_pc = 0x01222140u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222141: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222143: f30f100588b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb188u)) return BatchLiftStatus::invalid_memory;
    // 0x0122214b: f30f1105dc225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22dcu)) return BatchLiftStatus::invalid_memory;
    // 0x01222153: f30f100584b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb184u)) return BatchLiftStatus::invalid_memory;
    // 0x0122215b: f30f1105e0225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22e0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222163: f30f100580b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb180u)) return BatchLiftStatus::invalid_memory;
    // 0x0122216b: f30f1105e4225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22e4u)) return BatchLiftStatus::invalid_memory;
    // 0x01222173: 5d POP
        batch_guest_pc = 0x01222173u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01222174: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
