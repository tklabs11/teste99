#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00403785(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00403a95(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_004036d4(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004036d4u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0;

    // 0x004036d4: 81c2e7024d01 ADD
        t0a = state.regs[2];
        t0b = 0x014d02e7u;
        t0r = static_cast<std::uint32_t>(t0a + t0b) & 0xffffffffu;
        batch_set_add_flags(state, t0a, t0b, t0r, 32u);
        state.regs[2] = t0r;
    // 0x004036da: e9b6030000 JMP
        state.eip = 0x00403a95u;
        return spore_lift_00403a95(memory, state);
    // 0x004036df: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x004036e0: 55 PUSH
        t3a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x004036e1: 8bec MOV
        t4 = state.regs[4];
        state.regs[5] = t4;
    // 0x004036e3: 83ec20 SUB
        t5a = state.regs[4];
        t5b = 0x00000020u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x004036e6: 894de0 MOV
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x004036e9: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x004036ec: c70000000000 MOV
        t8 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x004036f2: 8b4de0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t9;
    // 0x004036f5: c7410400000000 MOV
        t10 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x004036fc: 8b55e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x004036ff: c7420800000000 MOV
        t12 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00403706: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00403709: 83c00c ADD
        t14a = state.regs[0];
        t14b = 0x0000000cu;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[0] = t14r;
    // 0x0040370c: 8945fc MOV
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0040370f: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t16;
    // 0x00403712: c70198fba82e MOV
        t17 = 0x2ea8fb98u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00403718: 33d2 XOR
        t18a = state.regs[2];
        t18b = state.regs[2];
        t18r = (t18a ^ t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
        state.regs[2] = t18r;
    // 0x0040371a: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x0040371d: 66895004 MOV
        t20 = state.regs[2] & 0x0000ffffu;
        if (!memory.store16(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00403721: b904000000 MOV
        t21 = 0x00000004u;
        state.regs[1] = t21;
    // 0x00403726: 8b55fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x00403729: 66894a06 MOV
        t23 = state.regs[1] & 0x0000ffffu;
        if (!memory.store16(static_cast<std::uint32_t>(state.regs[2] + 0x00000006u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x0040372d: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t24;
    // 0x00403730: 83c014 ADD
        t25a = state.regs[0];
        t25b = 0x00000014u;
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[0] = t25r;
    // 0x00403733: 8945f8 MOV
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00403736: 8b4df8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t27;
    // 0x00403739: c70100000000 MOV
        t28 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x0040373f: 8b55e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t29;
    // 0x00403742: 83c218 ADD
        t30a = state.regs[2];
        t30b = 0x00000018u;
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[2] = t30r;
    // 0x00403745: 8955f4 MOV
        t31 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x00403748: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x0040374b: c70000000000 MOV
        t33 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x00403751: 8b4de0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t34;
    // 0x00403754: 83c11c ADD
        t35a = state.regs[1];
        t35b = 0x0000001cu;
        t35r = static_cast<std::uint32_t>(t35a + t35b) & 0xffffffffu;
        batch_set_add_flags(state, t35a, t35b, t35r, 32u);
        state.regs[1] = t35r;
    // 0x00403757: 894df0 MOV
        t36 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x0040375a: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t37;
    // 0x0040375d: c70200000000 MOV
        t38 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x00403763: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x00403766: 83c020 ADD
        t40a = state.regs[0];
        t40b = 0x00000020u;
        t40r = static_cast<std::uint32_t>(t40a + t40b) & 0xffffffffu;
        batch_set_add_flags(state, t40a, t40b, t40r, 32u);
        state.regs[0] = t40r;
    // 0x00403769: 8945ec MOV
        t41 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0040376c: 8b4dec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t42;
    // 0x0040376f: c70100000000 MOV
        t43 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x00403775: c745e403000000 MOV
        t44 = 0x00000003u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x0040377c: 8b55e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t45;
    // 0x0040377f: 83c224 ADD
        t46a = state.regs[2];
        t46b = 0x00000024u;
        t46r = static_cast<std::uint32_t>(t46a + t46b) & 0xffffffffu;
        batch_set_add_flags(state, t46a, t46b, t46r, 32u);
        state.regs[2] = t46r;
    // 0x00403782: 8955e8 MOV
        t47 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x00403785: 8b45e4 MOV
    L_00403785:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x00403788: 83e801 SUB
        t49a = state.regs[0];
        t49b = 0x00000001u;
        t49r = static_cast<std::uint32_t>(t49a - t49b) & 0xffffffffu;
        batch_set_sub_flags(state, t49a, t49b, t49r, 32u);
        state.regs[0] = t49r;
    // 0x0040378b: 8945e4 MOV
        t50 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x0040378e: 7814 JS
        if (((state.eflags & 0x080u) != 0u)) goto L_004037a4;
    // 0x00403790: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t52;
    // 0x00403793: c70100000000 MOV
        t53 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00403799: 8b55e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t54;
    // 0x0040379c: 83c204 ADD
        t55a = state.regs[2];
        t55b = 0x00000004u;
        t55r = static_cast<std::uint32_t>(t55a + t55b) & 0xffffffffu;
        batch_set_add_flags(state, t55a, t55b, t55r, 32u);
        state.regs[2] = t55r;
    // 0x0040379f: 8955e8 MOV
        t56 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t56)) return BatchLiftStatus::invalid_memory;
    // 0x004037a2: ebe1 JMP
        goto L_00403785;
    // 0x004037a4: 8b45e0 MOV
    L_004037a4:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t58;
    // 0x004037a7: 8be5 MOV
        t59 = state.regs[5];
        state.regs[4] = t59;
    // 0x004037a9: 5d POP
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t60a;
    // 0x004037aa: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
