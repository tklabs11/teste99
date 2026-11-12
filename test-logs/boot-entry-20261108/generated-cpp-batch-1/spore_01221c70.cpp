#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221c70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221c70u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221c70: 55 PUSH
        batch_guest_pc = 0x01221c70u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221c71: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221c73: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c7b: f30f110508265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2608u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c83: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c8b: f30f11050c265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d260cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221c93: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221c9b: f30f110510265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2610u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ca3: 5d POP
        batch_guest_pc = 0x01221ca3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221ca4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
