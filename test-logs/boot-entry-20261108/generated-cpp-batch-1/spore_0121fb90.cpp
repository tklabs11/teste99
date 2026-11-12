#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121fb90(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121fb90u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x0121fb90: 55 PUSH
        batch_guest_pc = 0x0121fb90u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121fb91: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121fb93: f30f1005b4bb3e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013ebbb4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121fb9b: f30f1105cc195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d19ccu)) return BatchLiftStatus::invalid_memory;
    // 0x0121fba3: 5d POP
        batch_guest_pc = 0x0121fba3u;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x0121fba4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
