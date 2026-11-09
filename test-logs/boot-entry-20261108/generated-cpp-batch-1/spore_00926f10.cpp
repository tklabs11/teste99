#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00926f92(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00926f10(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926f10u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58a = 0;

    // 0x00926f10: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00926f11: 57 PUSH
        t1a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00926f12: 8bf9 MOV
        t2 = state.regs[1];
        state.regs[7] = t2;
    // 0x00926f14: 8b87d4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x000004d4u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00926f1a: 8b4c240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x00926f1e: 48 DEC
        t5a = state.regs[0];
        t5r = static_cast<std::uint32_t>(t5a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t5a, t5r, 32u);
        state.regs[0] = t5r;
    // 0x00926f1f: 8d74081f LEA
        t6 = static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x0000001fu);
        state.regs[6] = t6;
    // 0x00926f23: f7d0 NOT
        t7a = state.regs[0];
        state.regs[0] = (~t7a & 0xffffffffu);
    // 0x00926f25: 23f0 AND
        t8a = state.regs[6];
        t8b = state.regs[0];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[6] = t8r;
    // 0x00926f27: 3bf1 CMP
        t9a = state.regs[6];
        t9b = state.regs[1];
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x00926f29: 0f828f000000 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00926fbe;
    // 0x00926f2f: 80bf9804000000 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000498u), t11a)) return BatchLiftStatus::invalid_memory;
        t11b = 0x00000000u;
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0x000000ffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 8u);
    // 0x00926f36: b800300000 MOV
        t12 = 0x00003000u;
        state.regs[0] = t12;
    // 0x00926f3b: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926f42;
    // 0x00926f3d: b800301000 MOV
        t14 = 0x00103000u;
        state.regs[0] = t14;
    // 0x00926f42: 6a04 PUSH
    L_00926f42:
        t15a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00926f44: 50 PUSH
        t16a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00926f45: 56 PUSH
        t17a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00926f46: 6a00 PUSH
        t18a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00926f48: ff15c8c13c01 CALL
        t19_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!VirtualAlloc", 0x013cc1c8u, 0x00926f4eu);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
        if (state.eip != 0x00926f4eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00926f4e: 85c0 TEST
        t20a = state.regs[0];
        t20b = state.regs[0];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00926f50: 746c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926fbe;
    // 0x00926f52: 01b78c040000 ADD
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000048cu), t22a)) return BatchLiftStatus::invalid_memory;
        t22b = state.regs[6];
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x0000048cu), t22r)) return BatchLiftStatus::invalid_memory;
    // 0x00926f58: ff8788040000 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000488u), t23a)) return BatchLiftStatus::invalid_memory;
        t23r = static_cast<std::uint32_t>(t23a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t23a, t23r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000488u), t23r)) return BatchLiftStatus::invalid_memory;
    // 0x00926f5e: 8bd0 MOV
        t24 = state.regs[0];
        state.regs[2] = t24;
    // 0x00926f60: 83ee10 SUB
        t25a = state.regs[6];
        t25b = 0x00000010u;
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
        state.regs[6] = t25r;
    // 0x00926f63: 83e207 AND
        t26a = state.regs[2];
        t26b = 0x00000007u;
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[2] = t26r;
    // 0x00926f66: 741a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926f82;
    // 0x00926f68: b908000000 MOV
        t28 = 0x00000008u;
        state.regs[1] = t28;
    // 0x00926f6d: 2bca SUB
        t29a = state.regs[1];
        t29b = state.regs[2];
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
        state.regs[1] = t29r;
    // 0x00926f6f: 8d1408 LEA
        t30 = static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000000u);
        state.regs[2] = t30;
    // 0x00926f72: 2bf1 SUB
        t31a = state.regs[6];
        t31b = state.regs[1];
        t31r = static_cast<std::uint32_t>(t31a - t31b) & 0xffffffffu;
        batch_set_sub_flags(state, t31a, t31b, t31r, 32u);
        state.regs[6] = t31r;
    // 0x00926f74: 8bc6 MOV
        t32 = state.regs[6];
        state.regs[0] = t32;
    // 0x00926f76: 2bc1 SUB
        t33a = state.regs[0];
        t33b = state.regs[1];
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
        state.regs[0] = t33r;
    // 0x00926f78: 83c802 OR
        t34a = state.regs[0];
        t34b = 0x00000002u;
        t34r = (t34a | t34b) & 0xffffffffu;
        batch_set_logic_flags(state, t34r, 32u);
        state.regs[0] = t34r;
    // 0x00926f7b: 890a MOV
        t35 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x00926f7d: 894204 MOV
        t36 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00926f80: eb10 JMP
        goto L_00926f92;
    // 0x00926f82: 8bce MOV
    L_00926f82:
        t38 = state.regs[6];
        state.regs[1] = t38;
    // 0x00926f84: 83c902 OR
        t39a = state.regs[1];
        t39b = 0x00000002u;
        t39r = (t39a | t39b) & 0xffffffffu;
        batch_set_logic_flags(state, t39r, 32u);
        state.regs[1] = t39r;
    // 0x00926f87: 8bd0 MOV
        t40 = state.regs[0];
        state.regs[2] = t40;
    // 0x00926f89: c70000000000 MOV
        t41 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x00926f8f: 894804 MOV
        t42 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x00926f92: 8d0432 LEA
    L_00926f92:
        t43 = static_cast<std::uint32_t>(state.regs[2] + state.regs[6] * 1u + 0x00000000u);
        state.regs[0] = t43;
    // 0x00926f95: 8930 MOV
        t44 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x00926f97: c7400413000000 MOV
        t45 = 0x00000013u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x00926f9e: 8b8fa8040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x000004a8u), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t46;
    // 0x00926fa4: 8db79c040000 LEA
        t47 = static_cast<std::uint32_t>(state.regs[7] + 0x0000049cu);
        state.regs[6] = t47;
    // 0x00926faa: 897008 MOV
        t48 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00926fad: 89480c MOV
        t49 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t49)) return BatchLiftStatus::invalid_memory;
    // 0x00926fb0: 89460c MOV
        t50 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00926fb3: 5f POP
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t51a;
    // 0x00926fb4: 894108 MOV
        t52 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00926fb7: 8d4208 LEA
        t53 = static_cast<std::uint32_t>(state.regs[2] + 0x00000008u);
        state.regs[0] = t53;
    // 0x00926fba: 5e POP
        if (!memory.load32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t54a;
    // 0x00926fbb: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00926fbe: 5f POP
    L_00926fbe:
        if (!memory.load32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t56a;
    // 0x00926fbf: 33c0 XOR
        t57a = state.regs[0];
        t57b = state.regs[0];
        t57r = (t57a ^ t57b) & 0xffffffffu;
        batch_set_logic_flags(state, t57r, 32u);
        state.regs[0] = t57r;
    // 0x00926fc1: 5e POP
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t58a;
    // 0x00926fc2: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
