#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00620240(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00620230(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00620230u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;

    // 0x00620230: 8b01 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00620232: 3bc1 CMP
        t1a = state.regs[0];
        t1b = state.regs[1];
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
    // 0x00620234: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00620255;
    // 0x00620236: eb08 JMP
        goto L_00620240;
    // 0x00620240: 8b10 MOV
    L_00620240:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t4;
    // 0x00620242: c7400400000000 MOV
        t5 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x00620249: c70000000000 MOV
        t6 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x0062024f: 8bc2 MOV
        t7 = state.regs[2];
        state.regs[0] = t7;
    // 0x00620251: 3bd1 CMP
        t8a = state.regs[2];
        t8b = state.regs[1];
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x00620253: 75eb JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00620240;
    // 0x00620255: c70100000000 MOV
    L_00620255:
        t10 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x0062025b: c7410400000000 MOV
        t11 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00620262: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
