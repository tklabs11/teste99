#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121b3c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121b3c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121b3c0: 55 PUSH
        batch_guest_pc = 0x0121b3c0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121b3c1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121b3c3: f30f10051c0d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0d1cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121b3cb: f30f1105200f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f20u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b3d3: f30f1005200d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0d20u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b3db: f30f1105240f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f24u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b3e3: f30f1005240d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d0d24u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b3eb: f30f1105280f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f28u)) return BatchLiftStatus::invalid_memory;
    // 0x0121b3f3: 5d POP
        batch_guest_pc = 0x0121b3f3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121b3f4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
