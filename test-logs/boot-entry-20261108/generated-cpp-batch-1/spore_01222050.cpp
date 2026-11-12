#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222050(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222050u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01222050: 55 PUSH
        batch_guest_pc = 0x01222050u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222051: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222053: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122205b: f30f1105e8245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d24e8u)) return BatchLiftStatus::invalid_memory;
    // 0x01222063: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x0122206b: f30f1105ec245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d24ecu)) return BatchLiftStatus::invalid_memory;
    // 0x01222073: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122207b: f30f1105f0245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d24f0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222083: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122208b: f30f1105f4245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d24f4u)) return BatchLiftStatus::invalid_memory;
    // 0x01222093: 5d POP
        batch_guest_pc = 0x01222093u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01222094: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
