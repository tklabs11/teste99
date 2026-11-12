#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220bf0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220bf0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01220bf0: 55 PUSH
        batch_guest_pc = 0x01220bf0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220bf1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220bf3: f30f10051c1d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1d1cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220bfb: f30f1105901e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e90u)) return BatchLiftStatus::invalid_memory;
    // 0x01220c03: f30f1005201d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1d20u)) return BatchLiftStatus::invalid_memory;
    // 0x01220c0b: f30f1105941e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e94u)) return BatchLiftStatus::invalid_memory;
    // 0x01220c13: f30f1005241d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1d24u)) return BatchLiftStatus::invalid_memory;
    // 0x01220c1b: f30f1105981e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e98u)) return BatchLiftStatus::invalid_memory;
    // 0x01220c23: 5d POP
        batch_guest_pc = 0x01220c23u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01220c24: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
