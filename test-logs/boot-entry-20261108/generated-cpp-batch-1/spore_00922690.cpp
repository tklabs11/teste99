#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00922570(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009226ba(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00922690(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00922690u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    BatchLiftStatus t9_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34 = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47a = 0;
    std::uint32_t t48a = 0, t48r = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53a = 0;
    BatchLiftStatus t54_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58a = 0;
    BatchLiftStatus t59_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t60a = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t66a = 0;
    std::uint32_t t67a = 0;
    std::uint32_t t68a = 0, t68b = 0, t68r = 0;
    std::uint32_t t69 = 0;

    // 0x00922690: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00922691: 8b742408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t1;
    // 0x00922695: 8b06 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00922697: 57 PUSH
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00922698: 8bf9 MOV
        t4 = state.regs[1];
        state.regs[7] = t4;
    // 0x0092269a: 83f8ff CMP
        t5a = state.regs[0];
        t5b = 0xffffffffu;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x0092269d: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009226b8;
    // 0x0092269f: 85c0 TEST
        t7a = state.regs[0];
        t7b = state.regs[0];
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
    // 0x009226a1: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009226b8;
    // 0x009226a3: e898ac0200 CALL
        t9_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetTickCount", 0x013cc130u, 0x009226a8u);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
        if (state.eip != 0x009226a8u) return BatchLiftStatus::invalid_control_flow;
    // 0x009226a8: 8b0e MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t10;
    // 0x009226aa: 3bc8 CMP
        t11a = state.regs[1];
        t11b = state.regs[0];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x009226ac: 7606 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_009226b4;
    // 0x009226ae: 2bc8 SUB
        t13a = state.regs[1];
        t13b = state.regs[0];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
        state.regs[1] = t13r;
    // 0x009226b0: 8bf1 MOV
        t14 = state.regs[1];
        state.regs[6] = t14;
    // 0x009226b2: eb06 JMP
        goto L_009226ba;
    // 0x009226b4: 33f6 XOR
    L_009226b4:
        t16a = state.regs[6];
        t16b = state.regs[6];
        t16r = (t16a ^ t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[6] = t16r;
    // 0x009226b6: eb02 JMP
        goto L_009226ba;
    // 0x009226b8: 8bf0 MOV
    L_009226b8:
        t18 = state.regs[0];
        state.regs[6] = t18;
    // 0x009226ba: 807f0c00 CMP
    L_009226ba:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t19a)) return BatchLiftStatus::invalid_memory;
        t19b = 0x00000000u;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0x000000ffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 8u);
    // 0x009226be: 7443 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00922703;
    // 0x009226c0: 53 PUSH
        t21a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x009226c1: 8d5f04 LEA
        t22 = static_cast<std::uint32_t>(state.regs[7] + 0x00000004u);
        state.regs[3] = t22;
    // 0x009226c4: 53 PUSH
        t23a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x009226c5: ff15fcc03c01 CALL
        t24_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!InterlockedDecrement", 0x013cc0fcu, 0x009226cbu);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x009226cbu) return BatchLiftStatus::invalid_control_flow;
    // 0x009226cb: 85c0 TEST
        t25a = state.regs[0];
        t25b = state.regs[0];
        t25r = (t25a & t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
    // 0x009226cd: 7d22 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009226f1;
    // 0x009226cf: 8b07 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t27;
    // 0x009226d1: 56 PUSH
        t28a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x009226d2: 50 PUSH
        t29a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x009226d3: ff1584c13c01 CALL
        t30_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!WaitForSingleObject", 0x013cc184u, 0x009226d9u);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x009226d9u) return BatchLiftStatus::invalid_control_flow;
    // 0x009226d9: 85c0 TEST
        t31a = state.regs[0];
        t31b = state.regs[0];
        t31r = (t31a & t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
    // 0x009226db: 7414 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009226f1;
    // 0x009226dd: 6a01 PUSH
        t33a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x009226df: 8bcf MOV
        t34 = state.regs[7];
        state.regs[1] = t34;
    // 0x009226e1: e88afeffff CALL
        t35_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00922570u, 0x009226e6u);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x009226e6u) return BatchLiftStatus::invalid_control_flow;
    // 0x009226e6: 5b POP
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t36a;
    // 0x009226e7: 5f POP
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t37a;
    // 0x009226e8: b8feffffff MOV
        t38 = 0xfffffffeu;
        state.regs[0] = t38;
    // 0x009226ed: 5e POP
        if (!memory.load32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t39a;
    // 0x009226ee: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009226f1: 8b03 MOV
    L_009226f1:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t41;
    // 0x009226f3: 33c9 XOR
        t42a = state.regs[1];
        t42b = state.regs[1];
        t42r = (t42a ^ t42b) & 0xffffffffu;
        batch_set_logic_flags(state, t42r, 32u);
        state.regs[1] = t42r;
    // 0x009226f5: 85c0 TEST
        t43a = state.regs[0];
        t43b = state.regs[0];
        t43r = (t43a & t43b) & 0xffffffffu;
        batch_set_logic_flags(state, t43r, 32u);
    // 0x009226f7: 0f9ec1 SETLE
        state.regs[1] = (state.regs[1] & 0xffffff00u) | (((((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x009226fa: 5b POP
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t45a;
    // 0x009226fb: 5f POP
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t46a;
    // 0x009226fc: 5e POP
        if (!memory.load32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t47a;
    // 0x009226fd: 49 DEC
        t48a = state.regs[1];
        t48r = static_cast<std::uint32_t>(t48a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t48a, t48r, 32u);
        state.regs[1] = t48r;
    // 0x009226fe: 23c1 AND
        t49a = state.regs[0];
        t49b = state.regs[1];
        t49r = (t49a & t49b) & 0xffffffffu;
        batch_set_logic_flags(state, t49r, 32u);
        state.regs[0] = t49r;
    // 0x00922700: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00922703: 8b17 MOV
    L_00922703:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t51;
    // 0x00922705: 56 PUSH
        t52a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x00922706: 52 PUSH
        t53a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x00922707: ff1584c13c01 CALL
        t54_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!WaitForSingleObject", 0x013cc184u, 0x0092270du);
        if (t54_call_status != BatchLiftStatus::returned) return t54_call_status;
        if (state.eip != 0x0092270du) return BatchLiftStatus::invalid_control_flow;
    // 0x0092270d: 85c0 TEST
        t55a = state.regs[0];
        t55b = state.regs[0];
        t55r = (t55a & t55b) & 0xffffffffu;
        batch_set_logic_flags(state, t55r, 32u);
    // 0x0092270f: 750f JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00922720;
    // 0x00922711: 83c704 ADD
        t57a = state.regs[7];
        t57b = 0x00000004u;
        t57r = static_cast<std::uint32_t>(t57a + t57b) & 0xffffffffu;
        batch_set_add_flags(state, t57a, t57b, t57r, 32u);
        state.regs[7] = t57r;
    // 0x00922714: 57 PUSH
        t58a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
    // 0x00922715: ff15fcc03c01 CALL
        t59_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!InterlockedDecrement", 0x013cc0fcu, 0x0092271bu);
        if (t59_call_status != BatchLiftStatus::returned) return t59_call_status;
        if (state.eip != 0x0092271bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092271b: 5f POP
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t60a;
    // 0x0092271c: 5e POP
        if (!memory.load32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t61a;
    // 0x0092271d: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00922720: 33c9 XOR
    L_00922720:
        t63a = state.regs[1];
        t63b = state.regs[1];
        t63r = (t63a ^ t63b) & 0xffffffffu;
        batch_set_logic_flags(state, t63r, 32u);
        state.regs[1] = t63r;
    // 0x00922722: 3d02010000 CMP
        t64a = state.regs[0];
        t64b = 0x00000102u;
        t64r = static_cast<std::uint32_t>(t64a - t64b) & 0xffffffffu;
        batch_set_sub_flags(state, t64a, t64b, t64r, 32u);
    // 0x00922727: 0f95c1 SETNZ
        state.regs[1] = (state.regs[1] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x0092272a: 5f POP
        if (!memory.load32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t66a;
    // 0x0092272b: 5e POP
        if (!memory.load32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t67a;
    // 0x0092272c: 83c1fe ADD
        t68a = state.regs[1];
        t68b = 0xfffffffeu;
        t68r = static_cast<std::uint32_t>(t68a + t68b) & 0xffffffffu;
        batch_set_add_flags(state, t68a, t68b, t68r, 32u);
        state.regs[1] = t68r;
    // 0x0092272f: 8bc1 MOV
        t69 = state.regs[1];
        state.regs[0] = t69;
    // 0x00922731: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
