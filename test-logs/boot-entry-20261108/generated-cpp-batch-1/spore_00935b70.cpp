#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00935a30(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00935a70(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00935c2c(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00935b70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00935b70u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    BatchLiftStatus t9_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;
    BatchLiftStatus t29_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40 = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47a = 0;
    std::uint32_t t48 = 0;
    BatchLiftStatus t49_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    BatchLiftStatus t55_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t60a = 0;
    BatchLiftStatus t61_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t62a = 0;
    BatchLiftStatus t63_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    BatchLiftStatus t66_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75a = 0;
    std::uint32_t t76a = 0, t76b = 0, t76r = 0;

    // 0x00935b70: 83ec60 SUB
        t0a = state.regs[4];
        t0b = 0x00000060u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00935b73: 833d3099660100 CMP
        if (!memory.load32(0x01669930u, t1a)) return BatchLiftStatus::invalid_memory;
        t1b = 0x00000000u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
    // 0x00935b7a: 56 PUSH
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00935b7b: 0f85e0000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00935c61;
    // 0x00935b81: ff1514c13c01 CALL
        t4_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetCurrentProcessId", 0x013cc114u, 0x00935b87u);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x00935b87u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935b87: 50 PUSH
        t5a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00935b88: 8d442428 LEA
        t6 = static_cast<std::uint32_t>(state.regs[4] + 0x00000028u);
        state.regs[0] = t6;
    // 0x00935b8c: 6838e84301 PUSH
        t7a = 0x0143e838u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00935b91: 50 PUSH
        t8a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00935b92: ff15b4c53c01 CALL
        t9_call_status = batch_guest_import_call32(memory, state, "USER32.dll!wsprintfA", 0x013cc5b4u, 0x00935b98u);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
        if (state.eip != 0x00935b98u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935b98: 83c40c ADD
        t10a = state.regs[4];
        t10b = 0x0000000cu;
        t10r = static_cast<std::uint32_t>(t10a + t10b) & 0xffffffffu;
        batch_set_add_flags(state, t10a, t10b, t10r, 32u);
        state.regs[4] = t10r;
    // 0x00935b9b: 8d4c2424 LEA
        t11 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[1] = t11;
    // 0x00935b9f: 51 PUSH
        t12a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00935ba0: 6a00 PUSH
        t13a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00935ba2: 6a00 PUSH
        t14a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00935ba4: ff1580c13c01 CALL
        t15_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!CreateMutexA", 0x013cc180u, 0x00935baau);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x00935baau) return BatchLiftStatus::invalid_control_flow;
    // 0x00935baa: 8bf0 MOV
        t16 = state.regs[0];
        state.regs[6] = t16;
    // 0x00935bac: 85f6 TEST
        t17a = state.regs[6];
        t17b = state.regs[6];
        t17r = (t17a & t17b) & 0xffffffffu;
        batch_set_logic_flags(state, t17r, 32u);
    // 0x00935bae: 0f84a6000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935c5a;
    // 0x00935bb4: 6aff PUSH
        t19a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00935bb6: 56 PUSH
        t20a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00935bb7: ff1584c13c01 CALL
        t21_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!WaitForSingleObject", 0x013cc184u, 0x00935bbdu);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x00935bbdu) return BatchLiftStatus::invalid_control_flow;
    // 0x00935bbd: 83f8ff CMP
        t22a = state.regs[0];
        t22b = 0xffffffffu;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x00935bc0: 0f8486000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935c4c;
    // 0x00935bc6: 6a20 PUSH
        t24a = 0x00000020u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00935bc8: 8d542408 LEA
        t25 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[2] = t25;
    // 0x00935bcc: 52 PUSH
        t26a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00935bcd: 8d44242c LEA
        t27 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[0] = t27;
    // 0x00935bd1: 50 PUSH
        t28a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00935bd2: ff156cc23c01 CALL
        t29_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetEnvironmentVariableA", 0x013cc26cu, 0x00935bd8u);
        if (t29_call_status != BatchLiftStatus::returned) return t29_call_status;
        if (state.eip != 0x00935bd8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935bd8: 85c0 TEST
        t30a = state.regs[0];
        t30b = state.regs[0];
        t30r = (t30a & t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
    // 0x00935bda: 7620 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00935bfc;
    // 0x00935bdc: 807c240400 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t32a)) return BatchLiftStatus::invalid_memory;
        t32b = 0x00000000u;
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0x000000ffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 8u);
    // 0x00935be1: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935bfc;
    // 0x00935be3: 6a10 PUSH
        t34a = 0x00000010u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00935be5: 8d4c2408 LEA
        t35 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[1] = t35;
    // 0x00935be9: 6a00 PUSH
        t36a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00935beb: 51 PUSH
        t37a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00935bec: ff15b8c33c01 CALL
        t38_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_strtoui64", 0x013cc3b8u, 0x00935bf2u);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
        if (state.eip != 0x00935bf2u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935bf2: 83c40c ADD
        t39a = state.regs[4];
        t39b = 0x0000000cu;
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[4] = t39r;
    // 0x00935bf5: a330996601 MOV
        t40 = state.regs[0];
        if (!memory.store32(0x01669930u, t40)) return BatchLiftStatus::invalid_memory;
    // 0x00935bfa: eb30 JMP
        goto L_00935c2c;
    // 0x00935bfc: e82ffeffff CALL
    L_00935bfc:
        if (!batch_guest_call32(memory, state, 0x00935a30u, 0x00935c01u)) return BatchLiftStatus::invalid_memory;
        t42_call_status = spore_lift_00935a30(memory, state);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00935c01u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935c01: 6a00 PUSH
        t43a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c03: 50 PUSH
        t44a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c04: 8d54240c LEA
        t45 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[2] = t45;
    // 0x00935c08: 6830e84301 PUSH
        t46a = 0x0143e830u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c0d: 52 PUSH
        t47a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c0e: a330996601 MOV
        t48 = state.regs[0];
        if (!memory.store32(0x01669930u, t48)) return BatchLiftStatus::invalid_memory;
    // 0x00935c13: ff15a0c43c01 CALL
        t49_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!sprintf", 0x013cc4a0u, 0x00935c19u);
        if (t49_call_status != BatchLiftStatus::returned) return t49_call_status;
        if (state.eip != 0x00935c19u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935c19: 83c410 ADD
        t50a = state.regs[4];
        t50b = 0x00000010u;
        t50r = static_cast<std::uint32_t>(t50a + t50b) & 0xffffffffu;
        batch_set_add_flags(state, t50a, t50b, t50r, 32u);
        state.regs[4] = t50r;
    // 0x00935c1c: 8d442404 LEA
        t51 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[0] = t51;
    // 0x00935c20: 50 PUSH
        t52a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c21: 8d4c2428 LEA
        t53 = static_cast<std::uint32_t>(state.regs[4] + 0x00000028u);
        state.regs[1] = t53;
    // 0x00935c25: 51 PUSH
        t54a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c26: ff1568c23c01 CALL
        t55_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!SetEnvironmentVariableA", 0x013cc268u, 0x00935c2cu);
        if (t55_call_status != BatchLiftStatus::returned) return t55_call_status;
        if (state.eip != 0x00935c2cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00935c2c: 8b1530996601 MOV
    L_00935c2c:
        if (!memory.load32(0x01669930u, t56)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t56;
    // 0x00935c32: 83c208 ADD
        t57a = state.regs[2];
        t57b = 0x00000008u;
        t57r = static_cast<std::uint32_t>(t57a + t57b) & 0xffffffffu;
        batch_set_add_flags(state, t57a, t57b, t57r, 32u);
        state.regs[2] = t57r;
    // 0x00935c35: b801000000 MOV
        t58 = 0x00000001u;
        state.regs[0] = t58;
    // 0x00935c3a: f00fc102 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t59a)) return BatchLiftStatus::invalid_memory;
        t59b = state.regs[0];
        t59r = static_cast<std::uint32_t>(t59a + t59b) & 0xffffffffu;
        batch_set_add_flags(state, t59a, t59b, t59r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t59r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t59a;
    // 0x00935c3e: 56 PUSH
        t60a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c3f: ff158cc13c01 CALL
        t61_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!ReleaseMutex", 0x013cc18cu, 0x00935c45u);
        if (t61_call_status != BatchLiftStatus::returned) return t61_call_status;
        if (state.eip != 0x00935c45u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935c45: 56 PUSH
        t62a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c46: ff15c4c03c01 CALL
        t63_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!CloseHandle", 0x013cc0c4u, 0x00935c4cu);
        if (t63_call_status != BatchLiftStatus::returned) return t63_call_status;
        if (state.eip != 0x00935c4cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00935c4c: 833d3099660100 CMP
    L_00935c4c:
        if (!memory.load32(0x01669930u, t64a)) return BatchLiftStatus::invalid_memory;
        t64b = 0x00000000u;
        t64r = static_cast<std::uint32_t>(t64a - t64b) & 0xffffffffu;
        batch_set_sub_flags(state, t64a, t64b, t64r, 32u);
    // 0x00935c53: 750c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00935c61;
    // 0x00935c55: e816feffff CALL
        if (!batch_guest_call32(memory, state, 0x00935a70u, 0x00935c5au)) return BatchLiftStatus::invalid_memory;
        t66_call_status = spore_lift_00935a70(memory, state);
        if (t66_call_status != BatchLiftStatus::returned) return t66_call_status;
        if (state.eip != 0x00935c5au) return BatchLiftStatus::invalid_control_flow;
    // 0x00935c5a: 32c0 XOR
    L_00935c5a:
        t67a = state.regs[0] & 0x000000ffu;
        t67b = state.regs[0] & 0x000000ffu;
        t67r = (t67a ^ t67b) & 0x000000ffu;
        batch_set_logic_flags(state, t67r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t67r << 0u) & 0x000000ffu);
    // 0x00935c5c: 5e POP
        if (!memory.load32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t68a;
    // 0x00935c5d: 83c460 ADD
        t69a = state.regs[4];
        t69b = 0x00000060u;
        t69r = static_cast<std::uint32_t>(t69a + t69b) & 0xffffffffu;
        batch_set_add_flags(state, t69a, t69b, t69r, 32u);
        state.regs[4] = t69r;
    // 0x00935c60: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00935c61: b934996601 MOV
    L_00935c61:
        t71 = 0x01669934u;
        state.regs[1] = t71;
    // 0x00935c66: ba01000000 MOV
        t72 = 0x00000001u;
        state.regs[2] = t72;
    // 0x00935c6b: f00fc111 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t73a)) return BatchLiftStatus::invalid_memory;
        t73b = state.regs[2];
        t73r = static_cast<std::uint32_t>(t73a + t73b) & 0xffffffffu;
        batch_set_add_flags(state, t73a, t73b, t73r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t73r)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t73a;
    // 0x00935c6f: b001 MOV
        t74 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t74 << 0u) & 0x000000ffu);
    // 0x00935c71: 5e POP
        if (!memory.load32(state.regs[4], t75a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t75a;
    // 0x00935c72: 83c460 ADD
        t76a = state.regs[4];
        t76b = 0x00000060u;
        t76r = static_cast<std::uint32_t>(t76a + t76b) & 0xffffffffu;
        batch_set_add_flags(state, t76a, t76b, t76r, 32u);
        state.regs[4] = t76r;
    // 0x00935c75: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
