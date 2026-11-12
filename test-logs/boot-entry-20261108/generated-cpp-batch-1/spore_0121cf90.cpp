#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121cf90(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121cf90u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121cf90: 55 PUSH
        batch_guest_pc = 0x0121cf90u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf91: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121cf93: f30f1005bc135d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d13bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf9b: f30f1105ac135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13acu)) return BatchLiftStatus::invalid_memory;
    // 0x0121cfa3: f30f1005c0135d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d13c0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cfab: f30f1105b0135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13b0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cfb3: f30f1005c4135d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d13c4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cfbb: f30f1105b4135d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d13b4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cfc3: 5d POP
        batch_guest_pc = 0x0121cfc3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121cfc4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
