#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_007f30d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x007f30d0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;

    // 0x007f30d0: 85c9 TEST
        t0a = state.regs[1];
        t0b = state.regs[1];
        t0r = (t0a & t0b) & 0xffffffffu;
        batch_set_logic_flags(state, t0r, 32u);
    // 0x007f30d2: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_007f30d8;
    // 0x007f30d4: 8d4104 LEA
        t2 = static_cast<std::uint32_t>(state.regs[1] + 0x00000004u);
        state.regs[0] = t2;
    // 0x007f30d7: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x007f30d8: 33c0 XOR
    L_007f30d8:
        t4a = state.regs[0];
        t4b = state.regs[0];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[0] = t4r;
    // 0x007f30da: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
