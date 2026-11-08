#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e136e(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e151a(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e1545(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e10bf(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28a = 0;
    BatchLiftStatus t29_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30a = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    BatchLiftStatus t34_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    BatchLiftStatus t37_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    BatchLiftStatus t43_call_status = BatchLiftStatus::invalid_control_flow;
    BatchLiftStatus t44_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47a = 0;
    BatchLiftStatus t48_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t49a = 0;
    BatchLiftStatus t50_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t51a = 0, t51b = 0, t51r = 0;
    std::uint32_t t53a = 0;
    BatchLiftStatus t54_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t55a = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;

    // 0x011e10bf: b84d5a0000 MOV
        t0 = 0x00005a4du;
        state.regs[0] = t0;
    // 0x011e10c4: 66390500004000 CMP
        if (!memory.load16(0x00400000u, t1a)) return BatchLiftStatus::invalid_memory;
        t1b = state.regs[0] & 0x0000ffffu;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0x0000ffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 16u);
    // 0x011e10cb: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e10d1;
    // 0x011e10cd: 33c0 XOR
    L_011e10cd:
        t3a = state.regs[0];
        t3b = state.regs[0];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[0] = t3r;
    // 0x011e10cf: eb4d JMP
        goto L_011e111e;
    // 0x011e10d1: a13c004000 MOV
    L_011e10d1:
        if (!memory.load32(0x0040003cu, t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x011e10d6: 8d8000004000 LEA
        t6 = static_cast<std::uint32_t>(state.regs[0] + 0x00400000u);
        state.regs[0] = t6;
    // 0x011e10dc: 813850450000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t7a)) return BatchLiftStatus::invalid_memory;
        t7b = 0x00004550u;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x011e10e2: 75e9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e10cd;
    // 0x011e10e4: 0fb74818 MOVZX
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t9a;
    // 0x011e10e8: 81f90b010000 CMP
        t10a = state.regs[1];
        t10b = 0x0000010bu;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x011e10ee: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e110b;
    // 0x011e10f0: 81f90b020000 CMP
        t12a = state.regs[1];
        t12b = 0x0000020bu;
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x011e10f6: 75d5 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e10cd;
    // 0x011e10f8: 83b8840000000e CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000084u), t14a)) return BatchLiftStatus::invalid_memory;
        t14b = 0x0000000eu;
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
    // 0x011e10ff: 76cc JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_011e10cd;
    // 0x011e1101: 33c9 XOR
        t16a = state.regs[1];
        t16b = state.regs[1];
        t16r = (t16a ^ t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[1] = t16r;
    // 0x011e1103: 3988f8000000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x000000f8u), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = state.regs[1];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x011e1109: eb0e JMP
        goto L_011e1119;
    // 0x011e110b: 8378740e CMP
    L_011e110b:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000074u), t19a)) return BatchLiftStatus::invalid_memory;
        t19b = 0x0000000eu;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x011e110f: 76bc JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_011e10cd;
    // 0x011e1111: 33c9 XOR
        t21a = state.regs[1];
        t21b = state.regs[1];
        t21r = (t21a ^ t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
        state.regs[1] = t21r;
    // 0x011e1113: 3988e8000000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x000000e8u), t22a)) return BatchLiftStatus::invalid_memory;
        t22b = state.regs[1];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x011e1119: 0f95c1 SETNZ
    L_011e1119:
        state.regs[1] = (state.regs[1] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x011e111c: 8bc1 MOV
        t24 = state.regs[1];
        state.regs[0] = t24;
    // 0x011e111e: 6a02 PUSH
    L_011e111e:
        t25a = 0x00000002u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1120: a328266f01 MOV
        t26 = state.regs[0];
        if (!memory.store32(0x016f2628u, t26)) return BatchLiftStatus::invalid_memory;
    // 0x011e1125: ff1504c33c01 CALL
        t27_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!__set_app_type", 0x013cc304u, 0x011e112bu);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x011e112bu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e112b: 6aff PUSH
        t28a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x011e112d: ff1550c33c01 CALL
        t29_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_encode_pointer", 0x013cc350u, 0x011e1133u);
        if (t29_call_status != BatchLiftStatus::returned) return t29_call_status;
        if (state.eip != 0x011e1133u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1133: 59 POP
        if (!memory.load32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t30a;
    // 0x011e1134: 59 POP
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t31a;
    // 0x011e1135: a35ce77101 MOV
        t32 = state.regs[0];
        if (!memory.store32(0x0171e75cu, t32)) return BatchLiftStatus::invalid_memory;
    // 0x011e113a: a360e77101 MOV
        t33 = state.regs[0];
        if (!memory.store32(0x0171e760u, t33)) return BatchLiftStatus::invalid_memory;
    // 0x011e113f: ff1508c33c01 CALL
        t34_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!__p__fmode", 0x013cc308u, 0x011e1145u);
        if (t34_call_status != BatchLiftStatus::returned) return t34_call_status;
        if (state.eip != 0x011e1145u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1145: 8b0d4c266f01 MOV
        if (!memory.load32(0x016f264cu, t35)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35;
    // 0x011e114b: 8908 MOV
        t36 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x011e114d: ff150cc33c01 CALL
        t37_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!__p__commode", 0x013cc30cu, 0x011e1153u);
        if (t37_call_status != BatchLiftStatus::returned) return t37_call_status;
        if (state.eip != 0x011e1153u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1153: 8b0d48266f01 MOV
        if (!memory.load32(0x016f2648u, t38)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t38;
    // 0x011e1159: 8908 MOV
        t39 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x011e115b: a110c33c01 MOV
        if (!memory.load32(0x013cc310u, t40)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t40;
    // 0x011e1160: 8b00 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t41;
    // 0x011e1162: a348e77101 MOV
        t42 = state.regs[0];
        if (!memory.store32(0x0171e748u, t42)) return BatchLiftStatus::invalid_memory;
    // 0x011e1167: e802020000 CALL
        if (!batch_guest_call32(memory, state, 0x011e136eu, 0x011e116cu)) return BatchLiftStatus::invalid_memory;
        t43_call_status = spore_lift_011e136e(memory, state);
        if (t43_call_status != BatchLiftStatus::returned) return t43_call_status;
        if (state.eip != 0x011e116cu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e116c: e8d4030000 CALL
        if (!batch_guest_call32(memory, state, 0x011e1545u, 0x011e1171u)) return BatchLiftStatus::invalid_memory;
        t44_call_status = spore_lift_011e1545(memory, state);
        if (t44_call_status != BatchLiftStatus::returned) return t44_call_status;
        if (state.eip != 0x011e1171u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1171: 833d84fe5c0100 CMP
        if (!memory.load32(0x015cfe84u, t45a)) return BatchLiftStatus::invalid_memory;
        t45b = 0x00000000u;
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
    // 0x011e1178: 750c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e1186;
    // 0x011e117a: 6845151e01 PUSH
        t47a = 0x011e1545u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
    // 0x011e117f: ff1514c33c01 CALL
        t48_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!__setusermatherr", 0x013cc314u, 0x011e1185u);
        if (t48_call_status != BatchLiftStatus::returned) return t48_call_status;
        if (state.eip != 0x011e1185u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1185: 59 POP
        if (!memory.load32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t49a;
    // 0x011e1186: e88f030000 CALL
    L_011e1186:
        if (!batch_guest_call32(memory, state, 0x011e151au, 0x011e118bu)) return BatchLiftStatus::invalid_memory;
        t50_call_status = spore_lift_011e151a(memory, state);
        if (t50_call_status != BatchLiftStatus::returned) return t50_call_status;
        if (state.eip != 0x011e118bu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e118b: 833d80fe5c01ff CMP
        if (!memory.load32(0x015cfe80u, t51a)) return BatchLiftStatus::invalid_memory;
        t51b = 0xffffffffu;
        t51r = static_cast<std::uint32_t>(t51a - t51b) & 0xffffffffu;
        batch_set_sub_flags(state, t51a, t51b, t51r, 32u);
    // 0x011e1192: 7509 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e119d;
    // 0x011e1194: 6aff PUSH
        t53a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1196: ff1518c33c01 CALL
        t54_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_configthreadlocale", 0x013cc318u, 0x011e119cu);
        if (t54_call_status != BatchLiftStatus::returned) return t54_call_status;
        if (state.eip != 0x011e119cu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e119c: 59 POP
        if (!memory.load32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t55a;
    // 0x011e119d: 33c0 XOR
    L_011e119d:
        t56a = state.regs[0];
        t56b = state.regs[0];
        t56r = (t56a ^ t56b) & 0xffffffffu;
        batch_set_logic_flags(state, t56r, 32u);
        state.regs[0] = t56r;
    // 0x011e119f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
