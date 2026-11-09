#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402467(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00402420(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00402420u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0;

    // 0x00402420: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00402421: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00402423: 51 PUSH
        t2a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00402424: 894dfc MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00402427: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0040242a: 83c008 ADD
        t5a = state.regs[0];
        t5b = 0x00000008u;
        t5r = static_cast<std::uint32_t>(t5a + t5b) & 0xffffffffu;
        batch_set_add_flags(state, t5a, t5b, t5r, 32u);
        state.regs[0] = t5r;
    // 0x0040242d: 83c9ff OR
        t6a = state.regs[1];
        t6b = 0xffffffffu;
        t6r = (t6a | t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[1] = t6r;
    // 0x00402430: f00fc108 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t7a)) return BatchLiftStatus::invalid_memory;
        t7b = state.regs[1];
        t7r = static_cast<std::uint32_t>(t7a + t7b) & 0xffffffffu;
        batch_set_add_flags(state, t7a, t7b, t7r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t7r)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7a;
    // 0x00402434: 33d2 XOR
        t8a = state.regs[2];
        t8b = state.regs[2];
        t8r = (t8a ^ t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[2] = t8r;
    // 0x00402436: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x00402439: 83c008 ADD
        t10a = state.regs[0];
        t10b = 0x00000008u;
        t10r = static_cast<std::uint32_t>(t10a + t10b) & 0xffffffffu;
        batch_set_add_flags(state, t10a, t10b, t10r, 32u);
        state.regs[0] = t10r;
    // 0x0040243c: f00fc110 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t11a)) return BatchLiftStatus::invalid_memory;
        t11b = state.regs[2];
        t11r = static_cast<std::uint32_t>(t11a + t11b) & 0xffffffffu;
        batch_set_add_flags(state, t11a, t11b, t11r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t11r)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11a;
    // 0x00402440: 83fa01 CMP
        t12a = state.regs[2];
        t12b = 0x00000001u;
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x00402443: 7d16 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_0040245b;
    // 0x00402445: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x00402448: 83c108 ADD
        t15a = state.regs[1];
        t15b = 0x00000008u;
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        state.regs[1] = t15r;
    // 0x0040244b: ba01000000 MOV
        t16 = 0x00000001u;
        state.regs[2] = t16;
    // 0x00402450: f00fc111 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = state.regs[2];
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t17r)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17a;
    // 0x00402454: b801000000 MOV
        t18 = 0x00000001u;
        state.regs[0] = t18;
    // 0x00402459: eb0c JMP
        goto L_00402467;
    // 0x0040245b: 33c0 XOR
    L_0040245b:
        t20a = state.regs[0];
        t20b = state.regs[0];
        t20r = (t20a ^ t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
        state.regs[0] = t20r;
    // 0x0040245d: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t21;
    // 0x00402460: 83c108 ADD
        t22a = state.regs[1];
        t22b = 0x00000008u;
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[1] = t22r;
    // 0x00402463: f00fc101 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t23a)) return BatchLiftStatus::invalid_memory;
        t23b = state.regs[0];
        t23r = static_cast<std::uint32_t>(t23a + t23b) & 0xffffffffu;
        batch_set_add_flags(state, t23a, t23b, t23r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t23r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23a;
    // 0x00402467: 8be5 MOV
    L_00402467:
        t24 = state.regs[5];
        state.regs[4] = t24;
    // 0x00402469: 5d POP
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t25a;
    // 0x0040246a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
