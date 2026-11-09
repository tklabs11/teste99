#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009268f0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00926db0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926db0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13a = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0, t37c = 0, t37r = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t51a = 0, t51b = 0, t51r = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0;
    BatchLiftStatus t59_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t75a = 0, t75b = 0, t75r = 0;
    std::uint32_t t76a = 0, t76b = 0, t76r = 0;
    std::uint32_t t77a = 0, t77b = 0, t77r = 0;
    std::uint32_t t78a = 0;
    std::uint32_t t79a = 0;
    std::uint32_t t80 = 0;
    BatchLiftStatus t81_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t82 = 0;
    std::uint32_t t83a = 0, t83b = 0, t83r = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87a = 0, t87b = 0, t87r = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99a = 0, t99b = 0, t99r = 0;
    std::uint32_t t101a = 0, t101r = 0;
    std::uint32_t t102a = 0;
    BatchLiftStatus t103_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t104a = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106a = 0;
    std::uint32_t t107a = 0;
    std::uint32_t t108a = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;

    // 0x00926db0: 83ec10 SUB
        t0a = state.regs[4];
        t0b = 0x00000010u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00926db3: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00926db4: 55 PUSH
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00926db5: 56 PUSH
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00926db6: 8be9 MOV
        t4 = state.regs[1];
        state.regs[5] = t4;
    // 0x00926db8: 57 PUSH
        t5a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00926db9: 8bbde4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004e4u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t6;
    // 0x00926dbf: 896c2410 MOV
        t7 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00926dc3: 897c2414 MOV
        t8 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00926dc7: 85ff TEST
        t9a = state.regs[7];
        t9b = state.regs[7];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x00926dc9: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926dd5;
    // 0x00926dcb: 57 PUSH
        t11a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00926dcc: ff15d8c23c01 CALL
        t12_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x00926dd2u);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00926dd2u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926dd2: ff4718 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t13a)) return BatchLiftStatus::invalid_memory;
        t13r = static_cast<std::uint32_t>(t13a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t13a, t13r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t13r)) return BatchLiftStatus::invalid_memory;
    // 0x00926dd5: 8b9d60040000 MOV
    L_00926dd5:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000460u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t14;
    // 0x00926ddb: 33f6 XOR
        t15a = state.regs[6];
        t15b = state.regs[6];
        t15r = (t15a ^ t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
        state.regs[6] = t15r;
    // 0x00926ddd: 8d8548040000 LEA
        t16 = static_cast<std::uint32_t>(state.regs[5] + 0x00000448u);
        state.regs[0] = t16;
    // 0x00926de3: 89742418 MOV
        t17 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00926de7: 3bd8 CMP
        t18a = state.regs[3];
        t18b = state.regs[0];
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
    // 0x00926de9: 0f8405010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926ef4;
    // 0x00926def: 90 NOP
    // 0x00926df0: 807b0d00 CMP
    L_00926df0:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[3] + 0x0000000du), t21a)) return BatchLiftStatus::invalid_memory;
        t21b = 0x00000000u;
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0x000000ffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 8u);
    // 0x00926df4: 0f84e5000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926edf;
    // 0x00926dfa: 8b7304 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t23;
    // 0x00926dfd: f6441ef401 TEST
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + state.regs[3] * 1u + 0xfffffff4u), t24a)) return BatchLiftStatus::invalid_memory;
        t24b = 0x00000001u;
        t24r = (t24a & t24b) & 0x000000ffu;
        batch_set_logic_flags(state, t24r, 8u);
    // 0x00926e02: 8d741ef0 LEA
        t25 = static_cast<std::uint32_t>(state.regs[6] + state.regs[3] * 1u + 0xfffffff0u);
        state.regs[6] = t25;
    // 0x00926e06: 0f85d3000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00926edf;
    // 0x00926e0c: 2b36 SUB
        t27a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t27b)) return BatchLiftStatus::invalid_memory;
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
        state.regs[6] = t27r;
    // 0x00926e0e: 807b0f00 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[3] + 0x0000000fu), t28a)) return BatchLiftStatus::invalid_memory;
        t28b = 0x00000000u;
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0x000000ffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 8u);
    // 0x00926e12: 0f84c7000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926edf;
    // 0x00926e18: 8b7e04 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t30;
    // 0x00926e1b: 8b542424 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t31;
    // 0x00926e1f: 81e7f8ffff7f AND
        t32a = state.regs[7];
        t32b = 0x7ffffff8u;
        t32r = (t32a & t32b) & 0xffffffffu;
        batch_set_logic_flags(state, t32r, 32u);
        state.regs[7] = t32r;
    // 0x00926e25: 83c240 ADD
        t33a = state.regs[2];
        t33b = 0x00000040u;
        t33r = static_cast<std::uint32_t>(t33a + t33b) & 0xffffffffu;
        batch_set_add_flags(state, t33a, t33b, t33r, 32u);
        state.regs[2] = t33r;
    // 0x00926e28: 3bfa CMP
        t34a = state.regs[7];
        t34b = state.regs[2];
        t34r = static_cast<std::uint32_t>(t34a - t34b) & 0xffffffffu;
        batch_set_sub_flags(state, t34a, t34b, t34r, 32u);
    // 0x00926e2a: 0f86ab000000 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00926edb;
    // 0x00926e30: 8b85dc040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004dcu), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t36;
    // 0x00926e36: d1e8 SHR
        t37a = state.regs[0];
        t37c = 1u;
        if (t37c != 0u) {
        t37r = static_cast<std::uint32_t>(t37a >> t37c);
        batch_set_shr_flags(state, t37a, t37c, t37r, 32u);
            state.regs[0] = t37r;
        }
    // 0x00926e38: 05ffff0000 ADD
        t38a = state.regs[0];
        t38b = 0x0000ffffu;
        t38r = static_cast<std::uint32_t>(t38a + t38b) & 0xffffffffu;
        batch_set_add_flags(state, t38a, t38b, t38r, 32u);
        state.regs[0] = t38r;
    // 0x00926e3d: 250000ffff AND
        t39a = state.regs[0];
        t39b = 0xffff0000u;
        t39r = (t39a & t39b) & 0xffffffffu;
        batch_set_logic_flags(state, t39r, 32u);
        state.regs[0] = t39r;
    // 0x00926e42: 8bcf MOV
        t40 = state.regs[7];
        state.regs[1] = t40;
    // 0x00926e44: 2bca SUB
        t41a = state.regs[1];
        t41b = state.regs[2];
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
        state.regs[1] = t41r;
    // 0x00926e46: 8d1400 LEA
        t42 = static_cast<std::uint32_t>(state.regs[0] + state.regs[0] * 1u + 0x00000000u);
        state.regs[2] = t42;
    // 0x00926e49: 8be8 MOV
        t43 = state.regs[0];
        state.regs[5] = t43;
    // 0x00926e4b: 3bd1 CMP
        t44a = state.regs[2];
        t44b = state.regs[1];
        t44r = static_cast<std::uint32_t>(t44a - t44b) & 0xffffffffu;
        batch_set_sub_flags(state, t44a, t44b, t44r, 32u);
    // 0x00926e4d: 730b JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926e5a;
    // 0x00926e4f: 8d1400 LEA
        t46 = static_cast<std::uint32_t>(state.regs[0] + state.regs[0] * 1u + 0x00000000u);
        state.regs[2] = t46;
    // 0x00926e52: 03d0 ADD
    L_00926e52:
        t47a = state.regs[2];
        t47b = state.regs[0];
        t47r = static_cast<std::uint32_t>(t47a + t47b) & 0xffffffffu;
        batch_set_add_flags(state, t47a, t47b, t47r, 32u);
        state.regs[2] = t47r;
    // 0x00926e54: 03e8 ADD
        t48a = state.regs[5];
        t48b = state.regs[0];
        t48r = static_cast<std::uint32_t>(t48a + t48b) & 0xffffffffu;
        batch_set_add_flags(state, t48a, t48b, t48r, 32u);
        state.regs[5] = t48r;
    // 0x00926e56: 3bd1 CMP
        t49a = state.regs[2];
        t49b = state.regs[1];
        t49r = static_cast<std::uint32_t>(t49a - t49b) & 0xffffffffu;
        batch_set_sub_flags(state, t49a, t49b, t49r, 32u);
    // 0x00926e58: 72f8 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00926e52;
    // 0x00926e5a: 3be9 CMP
    L_00926e5a:
        t51a = state.regs[5];
        t51b = state.regs[1];
        t51r = static_cast<std::uint32_t>(t51a - t51b) & 0xffffffffu;
        batch_set_sub_flags(state, t51a, t51b, t51r, 32u);
    // 0x00926e5c: 7379 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926ed7;
    // 0x00926e5e: 8b4304 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t53;
    // 0x00926e61: 6800400000 PUSH
        t54a = 0x00004000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00926e66: 2bc5 SUB
        t55a = state.regs[0];
        t55b = state.regs[5];
        t55r = static_cast<std::uint32_t>(t55a - t55b) & 0xffffffffu;
        batch_set_sub_flags(state, t55a, t55b, t55r, 32u);
        state.regs[0] = t55r;
    // 0x00926e68: 03c3 ADD
        t56a = state.regs[0];
        t56b = state.regs[3];
        t56r = static_cast<std::uint32_t>(t56a + t56b) & 0xffffffffu;
        batch_set_add_flags(state, t56a, t56b, t56r, 32u);
        state.regs[0] = t56r;
    // 0x00926e6a: 55 PUSH
        t57a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x00926e6b: 50 PUSH
        t58a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
    // 0x00926e6c: ff15c4c13c01 CALL
        t59_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!VirtualFree", 0x013cc1c4u, 0x00926e72u);
        if (t59_call_status != BatchLiftStatus::returned) return t59_call_status;
        if (state.eip != 0x00926e72u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926e72: 85c0 TEST
        t60a = state.regs[0];
        t60b = state.regs[0];
        t60r = (t60a & t60b) & 0xffffffffu;
        batch_set_logic_flags(state, t60r, 32u);
    // 0x00926e74: 7461 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926ed7;
    // 0x00926e76: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t62;
    // 0x00926e7a: 016c2418 ADD
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t63a)) return BatchLiftStatus::invalid_memory;
        t63b = state.regs[5];
        t63r = static_cast<std::uint32_t>(t63a + t63b) & 0xffffffffu;
        batch_set_add_flags(state, t63a, t63b, t63r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t63r)) return BatchLiftStatus::invalid_memory;
    // 0x00926e7e: 296b04 SUB
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t64a)) return BatchLiftStatus::invalid_memory;
        t64b = state.regs[5];
        t64r = static_cast<std::uint32_t>(t64a - t64b) & 0xffffffffu;
        batch_set_sub_flags(state, t64a, t64b, t64r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t64r)) return BatchLiftStatus::invalid_memory;
    // 0x00926e81: 3bb040040000 CMP
        t65a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000440u), t65b)) return BatchLiftStatus::invalid_memory;
        t65r = static_cast<std::uint32_t>(t65a - t65b) & 0xffffffffu;
        batch_set_sub_flags(state, t65a, t65b, t65r, 32u);
    // 0x00926e87: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926e9b;
    // 0x00926e89: 8b4e08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t67;
    // 0x00926e8c: 8b560c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t68)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t68;
    // 0x00926e8f: 89510c MOV
        t69 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t69)) return BatchLiftStatus::invalid_memory;
    // 0x00926e92: 8b460c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t70;
    // 0x00926e95: 8b4e08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t71)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t71;
    // 0x00926e98: 894808 MOV
        t72 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x00926e9b: 8b5604 MOV
    L_00926e9b:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t73;
    // 0x00926e9e: 2bfd SUB
        t74a = state.regs[7];
        t74b = state.regs[5];
        t74r = static_cast<std::uint32_t>(t74a - t74b) & 0xffffffffu;
        batch_set_sub_flags(state, t74a, t74b, t74r, 32u);
        state.regs[7] = t74r;
    // 0x00926ea0: 81e207000080 AND
        t75a = state.regs[2];
        t75b = 0x80000007u;
        t75r = (t75a & t75b) & 0xffffffffu;
        batch_set_logic_flags(state, t75r, 32u);
        state.regs[2] = t75r;
    // 0x00926ea6: 83c710 ADD
        t76a = state.regs[7];
        t76b = 0x00000010u;
        t76r = static_cast<std::uint32_t>(t76a + t76b) & 0xffffffffu;
        batch_set_add_flags(state, t76a, t76b, t76r, 32u);
        state.regs[7] = t76r;
    // 0x00926ea9: 0bfa OR
        t77a = state.regs[7];
        t77b = state.regs[2];
        t77r = (t77a | t77b) & 0xffffffffu;
        batch_set_logic_flags(state, t77r, 32u);
        state.regs[7] = t77r;
    // 0x00926eab: 6a00 PUSH
        t78a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t78a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ead: 56 PUSH
        t79a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t79a)) return BatchLiftStatus::invalid_memory;
    // 0x00926eae: 897e04 MOV
        t80 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x00926eb1: e83afaffff CALL
        if (!batch_guest_call32(memory, state, 0x009268f0u, 0x00926eb6u)) return BatchLiftStatus::invalid_memory;
        t81_call_status = spore_lift_009268f0(memory, state);
        if (t81_call_status != BatchLiftStatus::returned) return t81_call_status;
        if (state.eip != 0x00926eb6u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926eb6: 8b442418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t82)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t82;
    // 0x00926eba: 83c408 ADD
        t83a = state.regs[4];
        t83b = 0x00000008u;
        t83r = static_cast<std::uint32_t>(t83a + t83b) & 0xffffffffu;
        batch_set_add_flags(state, t83a, t83b, t83r, 32u);
        state.regs[4] = t83r;
    // 0x00926ebd: 3bb040040000 CMP
        t84a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000440u), t84b)) return BatchLiftStatus::invalid_memory;
        t84r = static_cast<std::uint32_t>(t84a - t84b) & 0xffffffffu;
        batch_set_sub_flags(state, t84a, t84b, t84r, 32u);
    // 0x00926ec3: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926ed7;
    // 0x00926ec5: 8b483c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000003cu), t86)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t86;
    // 0x00926ec8: 83c030 ADD
        t87a = state.regs[0];
        t87b = 0x00000030u;
        t87r = static_cast<std::uint32_t>(t87a + t87b) & 0xffffffffu;
        batch_set_add_flags(state, t87a, t87b, t87r, 32u);
        state.regs[0] = t87r;
    // 0x00926ecb: 894608 MOV
        t88 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t88)) return BatchLiftStatus::invalid_memory;
    // 0x00926ece: 894e0c MOV
        t89 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t89)) return BatchLiftStatus::invalid_memory;
    // 0x00926ed1: 89700c MOV
        t90 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t90)) return BatchLiftStatus::invalid_memory;
    // 0x00926ed4: 897108 MOV
        t91 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t91)) return BatchLiftStatus::invalid_memory;
    // 0x00926ed7: 8b6c2410 MOV
    L_00926ed7:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t92)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t92;
    // 0x00926edb: 8b7c2414 MOV
    L_00926edb:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t93)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t93;
    // 0x00926edf: 8b5b18 MOV
    L_00926edf:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000018u), t94)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t94;
    // 0x00926ee2: 8d8548040000 LEA
        t95 = static_cast<std::uint32_t>(state.regs[5] + 0x00000448u);
        state.regs[0] = t95;
    // 0x00926ee8: 3bd8 CMP
        t96a = state.regs[3];
        t96b = state.regs[0];
        t96r = static_cast<std::uint32_t>(t96a - t96b) & 0xffffffffu;
        batch_set_sub_flags(state, t96a, t96b, t96r, 32u);
    // 0x00926eea: 0f8500ffffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00926df0;
    // 0x00926ef0: 8b742418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t98)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t98;
    // 0x00926ef4: 85ff TEST
    L_00926ef4:
        t99a = state.regs[7];
        t99b = state.regs[7];
        t99r = (t99a & t99b) & 0xffffffffu;
        batch_set_logic_flags(state, t99r, 32u);
    // 0x00926ef6: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926f02;
    // 0x00926ef8: ff4f18 DEC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t101a)) return BatchLiftStatus::invalid_memory;
        t101r = static_cast<std::uint32_t>(t101a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t101a, t101r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t101r)) return BatchLiftStatus::invalid_memory;
    // 0x00926efb: 57 PUSH
        t102a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t102a)) return BatchLiftStatus::invalid_memory;
    // 0x00926efc: ff15dcc23c01 CALL
        t103_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x00926f02u);
        if (t103_call_status != BatchLiftStatus::returned) return t103_call_status;
        if (state.eip != 0x00926f02u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926f02: 5f POP
    L_00926f02:
        if (!memory.load32(state.regs[4], t104a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t104a;
    // 0x00926f03: 8bc6 MOV
        t105 = state.regs[6];
        state.regs[0] = t105;
    // 0x00926f05: 5e POP
        if (!memory.load32(state.regs[4], t106a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t106a;
    // 0x00926f06: 5d POP
        if (!memory.load32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t107a;
    // 0x00926f07: 5b POP
        if (!memory.load32(state.regs[4], t108a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t108a;
    // 0x00926f08: 83c410 ADD
        t109a = state.regs[4];
        t109b = 0x00000010u;
        t109r = static_cast<std::uint32_t>(t109a + t109b) & 0xffffffffu;
        batch_set_add_flags(state, t109a, t109b, t109r, 32u);
        state.regs[4] = t109r;
    // 0x00926f0b: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
