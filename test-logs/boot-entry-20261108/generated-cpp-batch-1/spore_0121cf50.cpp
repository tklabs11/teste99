#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121cf50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121cf50u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121cf50: 55 PUSH
        batch_guest_pc = 0x0121cf50u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf51: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121cf53: f30f100570125d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1270u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf5b: f30f110580145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1480u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf63: f30f100574125d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1274u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf6b: f30f110584145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1484u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf73: f30f100578125d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1278u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf7b: f30f110588145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1488u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf83: 5d POP
        batch_guest_pc = 0x0121cf83u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121cf84: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
