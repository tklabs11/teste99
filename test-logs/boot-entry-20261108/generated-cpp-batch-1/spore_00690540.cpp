#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0068f450(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0068fff0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690f60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922740(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00690540(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00690540u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0;
    BatchLiftStatus t56_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60 = 0;
    BatchLiftStatus t61_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78a = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    BatchLiftStatus t82_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t83 = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t86a = 0;
    std::uint32_t t87a = 0;
    std::uint32_t t88a = 0;

    // 0x00690540: 53 PUSH
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00690541: 8b5c2408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t1;
    // 0x00690545: 8b4320 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000020u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00690548: 56 PUSH
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00690549: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x0069054b: 858694010000 TEST
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000194u), t5a)) return BatchLiftStatus::invalid_memory;
        t5b = state.regs[0];
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
    // 0x00690551: 750b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0069055e;
    // 0x00690553: 53 PUSH
        t7a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00690554: e8070a0000 CALL
        if (!batch_guest_call32(memory, state, 0x00690f60u, 0x00690559u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_00690f60(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00690559u) return BatchLiftStatus::invalid_control_flow;
    // 0x00690559: 5e POP
        if (!memory.load32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t9a;
    // 0x0069055a: 5b POP
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t10a;
    // 0x0069055b: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0069055e: 8bc8 MOV
    L_0069055e:
        t12 = state.regs[0];
        state.regs[1] = t12;
    // 0x00690560: f7d1 NOT
        t13a = state.regs[1];
        state.regs[1] = (~t13a & 0xffffffffu);
    // 0x00690562: 85c9 TEST
        t14a = state.regs[1];
        t14b = state.regs[1];
        t14r = (t14a & t14b) & 0xffffffffu;
        batch_set_logic_flags(state, t14r, 32u);
    // 0x00690564: 7566 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_006905cc;
    // 0x00690566: 53 PUSH
        t16a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00690567: 8d5664 LEA
        t17 = static_cast<std::uint32_t>(state.regs[6] + 0x00000064u);
        state.regs[2] = t17;
    // 0x0069056a: 52 PUSH
        t18a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x0069056b: 8bce MOV
        t19 = state.regs[6];
        state.regs[1] = t19;
    // 0x0069056d: e87efaffff CALL
        t20_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0068fff0u, 0x00690572u);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x00690572u) return BatchLiftStatus::invalid_control_flow;
    // 0x00690572: 8d463c LEA
        t21 = static_cast<std::uint32_t>(state.regs[6] + 0x0000003cu);
        state.regs[0] = t21;
    // 0x00690575: 394004 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t22a)) return BatchLiftStatus::invalid_memory;
        t22b = state.regs[0];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x00690578: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690599;
    // 0x0069057a: 8b00 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t24;
    // 0x0069057c: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t25;
    // 0x0069057f: 3bc8 CMP
        t26a = state.regs[1];
        t26b = state.regs[0];
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0xffffffffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 32u);
    // 0x00690581: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690599;
    // 0x00690583: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t28;
    // 0x00690585: 8911 MOV
        t29 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00690587: 894a04 MOV
        t30 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x0069058a: 6a01 PUSH
        t31a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x0069058c: 8d4808 LEA
        t32 = static_cast<std::uint32_t>(state.regs[0] + 0x00000008u);
        state.regs[1] = t32;
    // 0x0069058f: 8900 MOV
        t33 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x00690591: 894004 MOV
        t34 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00690594: e8a7212900 CALL
        t35_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00922740u, 0x00690599u);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x00690599u) return BatchLiftStatus::invalid_control_flow;
    // 0x00690599: 8d4644 LEA
    L_00690599:
        t36 = static_cast<std::uint32_t>(state.regs[6] + 0x00000044u);
        state.regs[0] = t36;
    // 0x0069059c: 394004 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t37a)) return BatchLiftStatus::invalid_memory;
        t37b = state.regs[0];
        t37r = static_cast<std::uint32_t>(t37a - t37b) & 0xffffffffu;
        batch_set_sub_flags(state, t37a, t37b, t37r, 32u);
    // 0x0069059f: 0f8482000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690627;
    // 0x006905a5: 8b00 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x006905a7: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t40;
    // 0x006905aa: 3bc8 CMP
        t41a = state.regs[1];
        t41b = state.regs[0];
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
    // 0x006905ac: 7479 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690627;
    // 0x006905ae: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t43;
    // 0x006905b0: 8911 MOV
        t44 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x006905b2: 894a04 MOV
        t45 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x006905b5: 5e POP
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t46a;
    // 0x006905b6: 8900 MOV
        t47 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x006905b8: 894004 MOV
        t48 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x006905bb: 5b POP
        if (!memory.load32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t49a;
    // 0x006905bc: c744240401000000 MOV
        t50 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x006905c4: 8d4808 LEA
        t51 = static_cast<std::uint32_t>(state.regs[0] + 0x00000008u);
        state.regs[1] = t51;
    // 0x006905c7: e974212900 JMP
        state.eip = 0x00922740u;
        return state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_tail_call(memory, state, 0x00922740u);
    // 0x006905cc: 57 PUSH
    L_006905cc:
        t53a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x006905cd: 53 PUSH
        t54a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x006905ce: 50 PUSH
        t55a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x006905cf: e87ceeffff CALL
        t56_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0068f450u, 0x006905d4u);
        if (t56_call_status != BatchLiftStatus::returned) return t56_call_status;
        if (state.eip != 0x006905d4u) return BatchLiftStatus::invalid_control_flow;
    // 0x006905d4: 83c404 ADD
        t57a = state.regs[4];
        t57b = 0x00000004u;
        t57r = static_cast<std::uint32_t>(t57a + t57b) & 0xffffffffu;
        batch_set_add_flags(state, t57a, t57b, t57r, 32u);
        state.regs[4] = t57r;
    // 0x006905d7: 8d84c694000000 LEA
        t58 = static_cast<std::uint32_t>(state.regs[6] + state.regs[0] * 8u + 0x00000094u);
        state.regs[0] = t58;
    // 0x006905de: 50 PUSH
        t59a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
    // 0x006905df: 8bce MOV
        t60 = state.regs[6];
        state.regs[1] = t60;
    // 0x006905e1: e80afaffff CALL
        t61_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0068fff0u, 0x006905e6u);
        if (t61_call_status != BatchLiftStatus::returned) return t61_call_status;
        if (state.eip != 0x006905e6u) return BatchLiftStatus::invalid_control_flow;
    // 0x006905e6: 8dbe98010000 LEA
        t62 = static_cast<std::uint32_t>(state.regs[6] + 0x00000198u);
        state.regs[7] = t62;
    // 0x006905ec: 8b37 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t63;
    // 0x006905ee: 3bf7 CMP
        t64a = state.regs[6];
        t64b = state.regs[7];
        t64r = static_cast<std::uint32_t>(t64a - t64b) & 0xffffffffu;
        batch_set_sub_flags(state, t64a, t64b, t64r, 32u);
    // 0x006905f0: 7434 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690626;
    // 0x006905f2: 837e2400 CMP
    L_006905f2:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t66a)) return BatchLiftStatus::invalid_memory;
        t66b = 0x00000000u;
        t66r = static_cast<std::uint32_t>(t66a - t66b) & 0xffffffffu;
        batch_set_sub_flags(state, t66a, t66b, t66r, 32u);
    // 0x006905f6: 7428 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690620;
    // 0x006905f8: 8b4e2c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t68)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t68;
    // 0x006905fb: 854b20 TEST
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000020u), t69a)) return BatchLiftStatus::invalid_memory;
        t69b = state.regs[1];
        t69r = (t69a & t69b) & 0xffffffffu;
        batch_set_logic_flags(state, t69r, 32u);
    // 0x006905fe: 7420 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690620;
    // 0x00690600: 8b4e0c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t71)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t71;
    // 0x00690603: 8d4608 LEA
        t72 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[0] = t72;
    // 0x00690606: 3bc8 CMP
        t73a = state.regs[1];
        t73b = state.regs[0];
        t73r = static_cast<std::uint32_t>(t73a - t73b) & 0xffffffffu;
        batch_set_sub_flags(state, t73a, t73b, t73r, 32u);
    // 0x00690608: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690620;
    // 0x0069060a: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t75;
    // 0x0069060c: 8911 MOV
        t76 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x0069060e: 894a04 MOV
        t77 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x00690611: 6a01 PUSH
        t78a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t78a)) return BatchLiftStatus::invalid_memory;
    // 0x00690613: 8d4808 LEA
        t79 = static_cast<std::uint32_t>(state.regs[0] + 0x00000008u);
        state.regs[1] = t79;
    // 0x00690616: 8900 MOV
        t80 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x00690618: 894004 MOV
        t81 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t81)) return BatchLiftStatus::invalid_memory;
    // 0x0069061b: e820212900 CALL
        t82_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00922740u, 0x00690620u);
        if (t82_call_status != BatchLiftStatus::returned) return t82_call_status;
        if (state.eip != 0x00690620u) return BatchLiftStatus::invalid_control_flow;
    // 0x00690620: 8b36 MOV
    L_00690620:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t83;
    // 0x00690622: 3bf7 CMP
        t84a = state.regs[6];
        t84b = state.regs[7];
        t84r = static_cast<std::uint32_t>(t84a - t84b) & 0xffffffffu;
        batch_set_sub_flags(state, t84a, t84b, t84r, 32u);
    // 0x00690624: 75cc JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_006905f2;
    // 0x00690626: 5f POP
    L_00690626:
        if (!memory.load32(state.regs[4], t86a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t86a;
    // 0x00690627: 5e POP
    L_00690627:
        if (!memory.load32(state.regs[4], t87a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t87a;
    // 0x00690628: 5b POP
        if (!memory.load32(state.regs[4], t88a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t88a;
    // 0x00690629: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
