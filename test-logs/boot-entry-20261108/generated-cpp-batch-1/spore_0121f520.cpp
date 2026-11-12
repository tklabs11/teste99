#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121f520(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121f520u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121f520: 55 PUSH
        batch_guest_pc = 0x0121f520u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121f521: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121f523: f30f1005c8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f52b: f30f1105741a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a74u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f533: f30f1005c4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f53b: f30f1105781a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a78u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f543: f30f1005c0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f54b: f30f11057c1a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a7cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f553: 5d POP
        batch_guest_pc = 0x0121f553u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121f554: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
