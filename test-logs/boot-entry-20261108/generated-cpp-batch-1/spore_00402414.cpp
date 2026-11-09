#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402467(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004029e6(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00402414(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00402414u);
    std::uint32_t t0a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;

    // 0x00402414: 6800300000 PUSH
        t0a = 0x00003000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00402419: e9c8050000 JMP
        state.eip = 0x004029e6u;
        return spore_lift_004029e6(memory, state);
    // 0x0040241e: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0040241f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00402420: 55 PUSH
        t4a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00402421: 8bec MOV
        t5 = state.regs[4];
        state.regs[5] = t5;
    // 0x00402423: 51 PUSH
        t6a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00402424: 894dfc MOV
        t7 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00402427: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x0040242a: 83c008 ADD
        t9a = state.regs[0];
        t9b = 0x00000008u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[0] = t9r;
    // 0x0040242d: 83c9ff OR
        t10a = state.regs[1];
        t10b = 0xffffffffu;
        t10r = (t10a | t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
        state.regs[1] = t10r;
    // 0x00402430: f00fc108 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t11a)) return BatchLiftStatus::invalid_memory;
        t11b = state.regs[1];
        t11r = static_cast<std::uint32_t>(t11a + t11b) & 0xffffffffu;
        batch_set_add_flags(state, t11a, t11b, t11r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t11r)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t11a;
    // 0x00402434: 33d2 XOR
        t12a = state.regs[2];
        t12b = state.regs[2];
        t12r = (t12a ^ t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
        state.regs[2] = t12r;
    // 0x00402436: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00402439: 83c008 ADD
        t14a = state.regs[0];
        t14b = 0x00000008u;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[0] = t14r;
    // 0x0040243c: f00fc110 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t15a)) return BatchLiftStatus::invalid_memory;
        t15b = state.regs[2];
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t15r)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t15a;
    // 0x00402440: 83fa01 CMP
        t16a = state.regs[2];
        t16b = 0x00000001u;
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x00402443: 7d16 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_0040245b;
    // 0x00402445: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t18;
    // 0x00402448: 83c108 ADD
        t19a = state.regs[1];
        t19b = 0x00000008u;
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[1] = t19r;
    // 0x0040244b: ba01000000 MOV
        t20 = 0x00000001u;
        state.regs[2] = t20;
    // 0x00402450: f00fc111 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t21a)) return BatchLiftStatus::invalid_memory;
        t21b = state.regs[2];
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t21r)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21a;
    // 0x00402454: b801000000 MOV
        t22 = 0x00000001u;
        state.regs[0] = t22;
    // 0x00402459: eb0c JMP
        goto L_00402467;
    // 0x0040245b: 33c0 XOR
    L_0040245b:
        t24a = state.regs[0];
        t24b = state.regs[0];
        t24r = (t24a ^ t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
        state.regs[0] = t24r;
    // 0x0040245d: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t25;
    // 0x00402460: 83c108 ADD
        t26a = state.regs[1];
        t26b = 0x00000008u;
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[1] = t26r;
    // 0x00402463: f00fc101 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t27a)) return BatchLiftStatus::invalid_memory;
        t27b = state.regs[0];
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t27r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t27a;
    // 0x00402467: 8be5 MOV
    L_00402467:
        t28 = state.regs[5];
        state.regs[4] = t28;
    // 0x00402469: 5d POP
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t29a;
    // 0x0040246a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
