#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00925100(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925100u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    BatchLiftStatus t9_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    BatchLiftStatus t44_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;
    BatchLiftStatus t50_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t51a = 0;
    BatchLiftStatus t52_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;

    // 0x00925100: a1a08e6601 MOV
        batch_guest_pc = 0x00925100u;
        if (!memory.load32(0x01668ea0u, t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00925105: 81ec0c020000 SUB
        t1a = state.regs[4];
        t1b = 0x0000020cu;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
        state.regs[4] = t1r;
    // 0x0092510b: 83781001 CMP
        batch_guest_pc = 0x0092510bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t2a)) return BatchLiftStatus::invalid_memory;
        t2b = 0x00000001u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x0092510f: 0f85ac000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009251c1;
    // 0x00925115: 8b8c2414020000 MOV
        batch_guest_pc = 0x00925115u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000214u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x0092511c: 6800020000 PUSH
        batch_guest_pc = 0x0092511cu;
        t5a = 0x00000200u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00925121: 51 PUSH
        batch_guest_pc = 0x00925121u;
        t6a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925122: 8d542414 LEA
        t7 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[2] = t7;
    // 0x00925126: 52 PUSH
        batch_guest_pc = 0x00925126u;
        t8a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00925127: ff15f4c43c01 CALL
        t9_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!strncpy", 0x013cc4f4u, 0x0092512du);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
        if (state.eip != 0x0092512du) return BatchLiftStatus::invalid_control_flow;
    // 0x0092512d: 8d442418 LEA
        t10 = static_cast<std::uint32_t>(state.regs[4] + 0x00000018u);
        state.regs[0] = t10;
    // 0x00925131: 83c40c ADD
        t11a = state.regs[4];
        t11b = 0x0000000cu;
        t11r = static_cast<std::uint32_t>(t11a + t11b) & 0xffffffffu;
        batch_set_add_flags(state, t11a, t11b, t11r, 32u);
        state.regs[4] = t11r;
    // 0x00925134: c684240b02000000 MOV
        batch_guest_pc = 0x00925134u;
        t12 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000020bu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x0092513c: 8d5001 LEA
        t13 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t13;
    // 0x0092513f: 90 NOP
    // 0x00925140: 8a08 MOV
    L_00925140:
        batch_guest_pc = 0x00925140u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t15 << 0u) & 0x000000ffu);
    // 0x00925142: 40 INC
        t16a = state.regs[0];
        t16r = static_cast<std::uint32_t>(t16a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t16a, t16r, 32u);
        state.regs[0] = t16r;
    // 0x00925143: 84c9 TEST
        t17a = state.regs[1] & 0x000000ffu;
        t17b = state.regs[1] & 0x000000ffu;
        t17r = (t17a & t17b) & 0x000000ffu;
        batch_set_logic_flags(state, t17r, 8u);
    // 0x00925145: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925140;
    // 0x00925147: 2bc2 SUB
        t19a = state.regs[0];
        t19b = state.regs[2];
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
        state.regs[0] = t19r;
    // 0x00925149: b900020000 MOV
        t20 = 0x00000200u;
        state.regs[1] = t20;
    // 0x0092514e: 2bc8 SUB
        t21a = state.regs[1];
        t21b = state.regs[0];
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0xffffffffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 32u);
        state.regs[1] = t21r;
    // 0x00925150: 56 PUSH
        batch_guest_pc = 0x00925150u;
        t22a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00925151: 83f945 CMP
        t23a = state.regs[1];
        t23b = 0x00000045u;
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x00925154: 7213 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00925169;
    // 0x00925156: 57 PUSH
        batch_guest_pc = 0x00925156u;
        t25a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00925157: 8d7c0414 LEA
        t26 = static_cast<std::uint32_t>(state.regs[4] + state.regs[0] * 1u + 0x00000014u);
        state.regs[7] = t26;
    // 0x0092515b: b911000000 MOV
        t27 = 0x00000011u;
        state.regs[1] = t27;
    // 0x00925160: be08e04301 MOV
        t28 = 0x0143e008u;
        state.regs[6] = t28;
    // 0x00925165: f3a5 MOVSD.REP
        if (!batch_guest_rep_movs(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
    // 0x00925167: a4 MOVSB
        if (!batch_guest_rep_movs(memory, state, 1u)) return BatchLiftStatus::invalid_memory;
    // 0x00925168: 5f POP
        batch_guest_pc = 0x00925168u;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t31a;
    // 0x00925169: 8b842414020000 MOV
    L_00925169:
        batch_guest_pc = 0x00925169u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000214u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x00925170: 6a00 PUSH
        batch_guest_pc = 0x00925170u;
        t33a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00925172: 6a00 PUSH
        batch_guest_pc = 0x00925172u;
        t34a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00925174: 8d4c240c LEA
        t35 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t35;
    // 0x00925178: 51 PUSH
        batch_guest_pc = 0x00925178u;
        t36a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00925179: 6800509200 PUSH
        batch_guest_pc = 0x00925179u;
        t37a = 0x00925000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x0092517e: 6800000100 PUSH
        batch_guest_pc = 0x0092517eu;
        t38a = 0x00010000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x00925183: 8d542424 LEA
        t39 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[2] = t39;
    // 0x00925187: 6a00 PUSH
        batch_guest_pc = 0x00925187u;
        t40a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00925189: 8954241c MOV
        batch_guest_pc = 0x00925189u;
        t41 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0092518d: 89442420 MOV
        batch_guest_pc = 0x0092518du;
        t42 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x00925191: c744242400000000 MOV
        batch_guest_pc = 0x00925191u;
        t43 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x00925199: ff15b0c13c01 CALL
        t44_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!CreateThread", 0x013cc1b0u, 0x0092519fu);
        if (t44_call_status != BatchLiftStatus::returned) return t44_call_status;
        if (state.eip != 0x0092519fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092519f: 8bf0 MOV
        t45 = state.regs[0];
        state.regs[6] = t45;
    // 0x009251a1: 85f6 TEST
        t46a = state.regs[6];
        t46b = state.regs[6];
        t46r = (t46a & t46b) & 0xffffffffu;
        batch_set_logic_flags(state, t46r, 32u);
    // 0x009251a3: 7410 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009251b5;
    // 0x009251a5: 6aff PUSH
        batch_guest_pc = 0x009251a5u;
        t48a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x009251a7: 56 PUSH
        batch_guest_pc = 0x009251a7u;
        t49a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x009251a8: ff1584c13c01 CALL
        t50_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!WaitForSingleObject", 0x013cc184u, 0x009251aeu);
        if (t50_call_status != BatchLiftStatus::returned) return t50_call_status;
        if (state.eip != 0x009251aeu) return BatchLiftStatus::invalid_control_flow;
    // 0x009251ae: 56 PUSH
        batch_guest_pc = 0x009251aeu;
        t51a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x009251af: ff15c4c03c01 CALL
        t52_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!CloseHandle", 0x013cc0c4u, 0x009251b5u);
        if (t52_call_status != BatchLiftStatus::returned) return t52_call_status;
        if (state.eip != 0x009251b5u) return BatchLiftStatus::invalid_control_flow;
    // 0x009251b5: 8b44240c MOV
    L_009251b5:
        batch_guest_pc = 0x009251b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t53;
    // 0x009251b9: 5e POP
        batch_guest_pc = 0x009251b9u;
        if (!memory.load32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t54a;
    // 0x009251ba: 81c40c020000 ADD
        t55a = state.regs[4];
        t55b = 0x0000020cu;
        t55r = static_cast<std::uint32_t>(t55a + t55b) & 0xffffffffu;
        batch_set_add_flags(state, t55a, t55b, t55r, 32u);
        state.regs[4] = t55r;
    // 0x009251c0: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009251c1: 33c0 XOR
    L_009251c1:
        t57a = state.regs[0];
        t57b = state.regs[0];
        t57r = (t57a ^ t57b) & 0xffffffffu;
        batch_set_logic_flags(state, t57r, 32u);
        state.regs[0] = t57r;
    // 0x009251c3: 81c40c020000 ADD
        t58a = state.regs[4];
        t58b = 0x0000020cu;
        t58r = static_cast<std::uint32_t>(t58a + t58b) & 0xffffffffu;
        batch_set_add_flags(state, t58a, t58b, t58r, 32u);
        state.regs[4] = t58r;
    // 0x009251c9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
