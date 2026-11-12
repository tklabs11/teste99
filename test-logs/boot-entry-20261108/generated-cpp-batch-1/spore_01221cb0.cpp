#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221cb0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221cb0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221cb0: 55 PUSH
        batch_guest_pc = 0x01221cb0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221cb1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221cb3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221cbb: f30f1105fc235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23fcu)) return BatchLiftStatus::invalid_memory;
    // 0x01221cc3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ccb: f30f110500245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2400u)) return BatchLiftStatus::invalid_memory;
    // 0x01221cd3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221cdb: f30f110504245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2404u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ce3: 5d POP
        batch_guest_pc = 0x01221ce3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221ce4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
