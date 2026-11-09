#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921df0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092223f(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009221b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11a = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33a = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    BatchLiftStatus t50_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t51 = 0;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0;
    BatchLiftStatus t60_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66a = 0;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t68a = 0;

    // 0x009221b0: 53 PUSH
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009221b1: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009221b2: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x009221b4: 807e2400 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t3a)) return BatchLiftStatus::invalid_memory;
        t3b = 0x00000000u;
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0x000000ffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 8u);
    // 0x009221b8: 57 PUSH
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009221b9: 7464 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092221f;
    // 0x009221bb: 8b5c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t6;
    // 0x009221bf: 833bff CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t7a)) return BatchLiftStatus::invalid_memory;
        t7b = 0xffffffffu;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x009221c2: 56 PUSH
        t8a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x009221c3: 7512 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009221d7;
    // 0x009221c5: ff15d8c23c01 CALL
        t10_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x009221cbu);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x009221cbu) return BatchLiftStatus::invalid_control_flow;
    // 0x009221cb: ff4620 INC
    L_009221cb:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t11a)) return BatchLiftStatus::invalid_memory;
        t11r = static_cast<std::uint32_t>(t11a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t11a, t11r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t11r)) return BatchLiftStatus::invalid_memory;
    // 0x009221ce: 8b4620 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x009221d1: 5f POP
        if (!memory.load32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t13a;
    // 0x009221d2: 5e POP
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t14a;
    // 0x009221d3: 5b POP
        if (!memory.load32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t15a;
    // 0x009221d4: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009221d7: 8b3d88c13c01 MOV
    L_009221d7:
        if (!memory.load32(0x013cc188u, t17)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t17;
    // 0x009221dd: ffd7 CALL
        t18_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[7], 0x009221dfu);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
    // 0x009221df: 85c0 TEST
        t19a = state.regs[0];
        t19b = state.regs[0];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
    // 0x009221e1: 75e8 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009221cb;
    // 0x009221e3: e858b10200 CALL
    L_009221e3:
        t21_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetTickCount", 0x013cc130u, 0x009221e8u);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x009221e8u) return BatchLiftStatus::invalid_control_flow;
    // 0x009221e8: 3b03 CMP
        t22a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t22b)) return BatchLiftStatus::invalid_memory;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x009221ea: 7328 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00922214;
    // 0x009221ec: 8d442410 LEA
        t24 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t24;
    // 0x009221f0: 50 PUSH
        t25a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x009221f1: c744241401000000 MOV
        t26 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x009221f9: e8f2fbffff CALL
        if (!batch_guest_call32(memory, state, 0x00921df0u, 0x009221feu)) return BatchLiftStatus::invalid_memory;
        t27_call_status = spore_lift_00921df0(memory, state);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x009221feu) return BatchLiftStatus::invalid_control_flow;
    // 0x009221fe: 83c404 ADD
        t28a = state.regs[4];
        t28b = 0x00000004u;
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[4] = t28r;
    // 0x00922201: 56 PUSH
        t29a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00922202: ffd7 CALL
        t30_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[7], 0x00922204u);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
    // 0x00922204: 85c0 TEST
        t31a = state.regs[0];
        t31b = state.regs[0];
        t31r = (t31a & t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
    // 0x00922206: 74db JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009221e3;
    // 0x00922208: ff4620 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t33a)) return BatchLiftStatus::invalid_memory;
        t33r = static_cast<std::uint32_t>(t33a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t33a, t33r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t33r)) return BatchLiftStatus::invalid_memory;
    // 0x0092220b: 8b4620 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t34;
    // 0x0092220e: 5f POP
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t35a;
    // 0x0092220f: 5e POP
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t36a;
    // 0x00922210: 5b POP
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t37a;
    // 0x00922211: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00922214: 5f POP
    L_00922214:
        if (!memory.load32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t39a;
    // 0x00922215: 5e POP
        if (!memory.load32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t40a;
    // 0x00922216: b8feffffff MOV
        t41 = 0xfffffffeu;
        state.regs[0] = t41;
    // 0x0092221b: 5b POP
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t42a;
    // 0x0092221c: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092221f: 8b7c2410 MOV
    L_0092221f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t44;
    // 0x00922223: 8b0f MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t45;
    // 0x00922225: 83f9ff CMP
        t46a = state.regs[1];
        t46b = 0xffffffffu;
        t46r = static_cast<std::uint32_t>(t46a - t46b) & 0xffffffffu;
        batch_set_sub_flags(state, t46a, t46b, t46r, 32u);
    // 0x00922228: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092223f;
    // 0x0092222a: 85c9 TEST
        t48a = state.regs[1];
        t48b = state.regs[1];
        t48r = (t48a & t48b) & 0xffffffffu;
        batch_set_logic_flags(state, t48r, 32u);
    // 0x0092222c: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092223f;
    // 0x0092222e: e80db10200 CALL
        t50_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetTickCount", 0x013cc130u, 0x00922233u);
        if (t50_call_status != BatchLiftStatus::returned) return t50_call_status;
        if (state.eip != 0x00922233u) return BatchLiftStatus::invalid_control_flow;
    // 0x00922233: 8b0f MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t51;
    // 0x00922235: 3bc8 CMP
        t52a = state.regs[1];
        t52b = state.regs[0];
        t52r = static_cast<std::uint32_t>(t52a - t52b) & 0xffffffffu;
        batch_set_sub_flags(state, t52a, t52b, t52r, 32u);
    // 0x00922237: 7604 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0092223d;
    // 0x00922239: 2bc8 SUB
        t54a = state.regs[1];
        t54b = state.regs[0];
        t54r = static_cast<std::uint32_t>(t54a - t54b) & 0xffffffffu;
        batch_set_sub_flags(state, t54a, t54b, t54r, 32u);
        state.regs[1] = t54r;
    // 0x0092223b: eb02 JMP
        goto L_0092223f;
    // 0x0092223d: 33c9 XOR
    L_0092223d:
        t56a = state.regs[1];
        t56b = state.regs[1];
        t56r = (t56a ^ t56b) & 0xffffffffu;
        batch_set_logic_flags(state, t56r, 32u);
        state.regs[1] = t56r;
    // 0x0092223f: 51 PUSH
    L_0092223f:
        t57a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x00922240: 8b0e MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t58;
    // 0x00922242: 51 PUSH
        t59a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
    // 0x00922243: ff1584c13c01 CALL
        t60_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!WaitForSingleObject", 0x013cc184u, 0x00922249u);
        if (t60_call_status != BatchLiftStatus::returned) return t60_call_status;
        if (state.eip != 0x00922249u) return BatchLiftStatus::invalid_control_flow;
    // 0x00922249: 3d02010000 CMP
        t61a = state.regs[0];
        t61b = 0x00000102u;
        t61r = static_cast<std::uint32_t>(t61a - t61b) & 0xffffffffu;
        batch_set_sub_flags(state, t61a, t61b, t61r, 32u);
    // 0x0092224e: 74c4 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00922214;
    // 0x00922250: 85c0 TEST
        t63a = state.regs[0];
        t63b = state.regs[0];
        t63r = (t63a & t63b) & 0xffffffffu;
        batch_set_logic_flags(state, t63r, 32u);
    // 0x00922252: 0f8473ffffff JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009221cb;
    // 0x00922258: 5f POP
        if (!memory.load32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t65a;
    // 0x00922259: 5e POP
        if (!memory.load32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t66a;
    // 0x0092225a: 83c8ff OR
        t67a = state.regs[0];
        t67b = 0xffffffffu;
        t67r = (t67a | t67b) & 0xffffffffu;
        batch_set_logic_flags(state, t67r, 32u);
        state.regs[0] = t67r;
    // 0x0092225d: 5b POP
        if (!memory.load32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t68a;
    // 0x0092225e: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
