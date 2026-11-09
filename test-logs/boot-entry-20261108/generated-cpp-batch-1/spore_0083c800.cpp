#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0083c800(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0083c800u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;

    // 0x0083c800: 8bc1 MOV
        t0 = state.regs[1];
        state.regs[0] = t0;
    // 0x0083c802: 33c9 XOR
        t1a = state.regs[1];
        t1b = state.regs[1];
        t1r = (t1a ^ t1b) & 0xffffffffu;
        batch_set_logic_flags(state, t1r, 32u);
        state.regs[1] = t1r;
    // 0x0083c804: c700acb54101 MOV
        t2 = 0x0141b5acu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
    // 0x0083c80a: 894804 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0083c80d: 894808 MOV
        t4 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x0083c810: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
