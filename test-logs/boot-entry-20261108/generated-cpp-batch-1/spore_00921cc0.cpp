#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921b40(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921bc0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921d4b(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00921cc0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00921cc0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24a = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29 = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36 = 0;
    BatchLiftStatus t37_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50 = 0;
    BatchLiftStatus t51_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    BatchLiftStatus t55_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60a = 0;

    // 0x00921cc0: 51 PUSH
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cc1: a138df5401 MOV
        if (!memory.load32(0x0154df38u, t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00921cc6: 53 PUSH
        t2a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cc7: 8b1dbcc23c01 MOV
        if (!memory.load32(0x013cc2bcu, t3)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t3;
    // 0x00921ccd: 83f8ff CMP
        t4a = state.regs[0];
        t4b = 0xffffffffu;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
    // 0x00921cd0: 740b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921cdd;
    // 0x00921cd2: 50 PUSH
        t6a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cd3: ffd3 CALL
        t7_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[3], 0x00921cd5u);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
    // 0x00921cd5: 85c0 TEST
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x00921cd7: 0f858c000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921d69;
    // 0x00921cdd: 56 PUSH
    L_00921cdd:
        t10a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cde: 57 PUSH
        t11a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cdf: ff15b0c03c01 CALL
        t12_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetCurrentThread", 0x013cc0b0u, 0x00921ce5u);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00921ce5u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921ce5: 8b3de4c23c01 MOV
        if (!memory.load32(0x013cc2e4u, t13)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t13;
    // 0x00921ceb: 6a02 PUSH
        t14a = 0x00000002u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00921ced: 6a01 PUSH
        t15a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cef: 8bf0 MOV
        t16 = state.regs[0];
        state.regs[6] = t16;
    // 0x00921cf1: 6a00 PUSH
        t17a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cf3: 8d442418 LEA
        t18 = static_cast<std::uint32_t>(state.regs[4] + 0x00000018u);
        state.regs[0] = t18;
    // 0x00921cf7: 50 PUSH
        t19a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cf8: ffd7 CALL
        t20_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[7], 0x00921cfau);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
    // 0x00921cfa: 50 PUSH
        t21a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cfb: 56 PUSH
        t22a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cfc: ffd7 CALL
        t23_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[7], 0x00921cfeu);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
    // 0x00921cfe: 50 PUSH
        t24a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00921cff: ff1574c13c01 CALL
        t25_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!DuplicateHandle", 0x013cc174u, 0x00921d05u);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00921d05u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921d05: 85c0 TEST
        t26a = state.regs[0];
        t26b = state.regs[0];
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
    // 0x00921d07: 745a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921d63;
    // 0x00921d09: 833d38df5401ff CMP
        if (!memory.load32(0x0154df38u, t28a)) return BatchLiftStatus::invalid_memory;
        t28b = 0xffffffffu;
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x00921d10: 8b74240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t29;
    // 0x00921d14: 7510 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921d26;
    // 0x00921d16: ff156cc13c01 CALL
        t31_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!TlsAlloc", 0x013cc16cu, 0x00921d1cu);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
        if (state.eip != 0x00921d1cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00921d1c: a338df5401 MOV
        t32 = state.regs[0];
        if (!memory.store32(0x0154df38u, t32)) return BatchLiftStatus::invalid_memory;
    // 0x00921d21: 83f8ff CMP
        t33a = state.regs[0];
        t33b = 0xffffffffu;
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
    // 0x00921d24: 743d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921d63;
    // 0x00921d26: 6a00 PUSH
    L_00921d26:
        t35a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00921d28: b9c07b6601 MOV
        t36 = 0x01667bc0u;
        state.regs[1] = t36;
    // 0x00921d2d: e80efeffff CALL
        t37_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00921b40u, 0x00921d32u);
        if (t37_call_status != BatchLiftStatus::returned) return t37_call_status;
        if (state.eip != 0x00921d32u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921d32: 85f6 TEST
        t38a = state.regs[6];
        t38b = state.regs[6];
        t38r = (t38a & t38b) & 0xffffffffu;
        batch_set_logic_flags(state, t38r, 32u);
    // 0x00921d34: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921d3b;
    // 0x00921d36: 6a01 PUSH
        t40a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00921d38: 56 PUSH
        t41a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00921d39: eb10 JMP
        goto L_00921d4b;
    // 0x00921d3b: 8b0d38df5401 MOV
    L_00921d3b:
        if (!memory.load32(0x0154df38u, t43)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43;
    // 0x00921d41: 51 PUSH
        t44a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x00921d42: ffd3 CALL
        t45_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[3], 0x00921d44u);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
    // 0x00921d44: 85c0 TEST
        t46a = state.regs[0];
        t46b = state.regs[0];
        t46r = (t46a & t46b) & 0xffffffffu;
        batch_set_logic_flags(state, t46r, 32u);
    // 0x00921d46: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921d55;
    // 0x00921d48: 6a00 PUSH
        t48a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x00921d4a: 50 PUSH
        t49a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x00921d4b: b9c07b6601 MOV
    L_00921d4b:
        t50 = 0x01667bc0u;
        state.regs[1] = t50;
    // 0x00921d50: e86bfeffff CALL
        t51_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00921bc0u, 0x00921d55u);
        if (t51_call_status != BatchLiftStatus::returned) return t51_call_status;
        if (state.eip != 0x00921d55u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921d55: 8b1538df5401 MOV
    L_00921d55:
        if (!memory.load32(0x0154df38u, t52)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t52;
    // 0x00921d5b: 56 PUSH
        t53a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x00921d5c: 52 PUSH
        t54a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00921d5d: ff1570c13c01 CALL
        t55_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!TlsSetValue", 0x013cc170u, 0x00921d63u);
        if (t55_call_status != BatchLiftStatus::returned) return t55_call_status;
        if (state.eip != 0x00921d63u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921d63: 8b44240c MOV
    L_00921d63:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t56;
    // 0x00921d67: 5f POP
        if (!memory.load32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t57a;
    // 0x00921d68: 5e POP
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t58a;
    // 0x00921d69: 5b POP
    L_00921d69:
        if (!memory.load32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t59a;
    // 0x00921d6a: 59 POP
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t60a;
    // 0x00921d6b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
