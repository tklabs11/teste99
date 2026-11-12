#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220430(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220430u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01220430: 55 PUSH
        batch_guest_pc = 0x01220430u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220431: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220433: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122043b: f30f1105ac1e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1eacu)) return BatchLiftStatus::invalid_memory;
    // 0x01220443: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122044b: f30f1105b01e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1eb0u)) return BatchLiftStatus::invalid_memory;
    // 0x01220453: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122045b: f30f1105b41e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1eb4u)) return BatchLiftStatus::invalid_memory;
    // 0x01220463: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122046b: f30f1105b81e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1eb8u)) return BatchLiftStatus::invalid_memory;
    // 0x01220473: 5d POP
        batch_guest_pc = 0x01220473u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01220474: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
