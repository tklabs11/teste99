#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009252af(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925220(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925220u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0;
    BatchLiftStatus t50_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t51a = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61a = 0;

    // 0x00925220: 8b542404 MOV
        batch_guest_pc = 0x00925220u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00925224: 8b442410 MOV
        batch_guest_pc = 0x00925224u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00925228: 55 PUSH
        batch_guest_pc = 0x00925228u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00925229: 56 PUSH
        batch_guest_pc = 0x00925229u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0092522a: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x0092522c: 8b4c2414 MOV
        batch_guest_pc = 0x0092522cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x00925230: 57 PUSH
        batch_guest_pc = 0x00925230u;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925231: 8b7c2414 MOV
        batch_guest_pc = 0x00925231u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t7;
    // 0x00925235: c60601 MOV
        batch_guest_pc = 0x00925235u;
        t8 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00925238: c6460101 MOV
        batch_guest_pc = 0x00925238u;
        t9 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000001u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0092523c: c6460200 MOV
        batch_guest_pc = 0x0092523cu;
        t10 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000002u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00925240: 895604 MOV
        batch_guest_pc = 0x00925240u;
        t11 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00925243: c7460800000000 MOV
        batch_guest_pc = 0x00925243u;
        t12 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x0092524a: 894e0c MOV
        batch_guest_pc = 0x0092524au;
        t13 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t13)) return BatchLiftStatus::invalid_memory;
    // 0x0092524d: 897e10 MOV
        batch_guest_pc = 0x0092524du;
        t14 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00925250: 8b28 MOV
        batch_guest_pc = 0x00925250u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t15;
    // 0x00925252: 896e14 MOV
        batch_guest_pc = 0x00925252u;
        t16 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00925255: 8b6804 MOV
        batch_guest_pc = 0x00925255u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t17;
    // 0x00925258: 896e18 MOV
        batch_guest_pc = 0x00925258u;
        t18 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x0092525b: 8b4008 MOV
        batch_guest_pc = 0x0092525bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x0092525e: 89461c MOV
        batch_guest_pc = 0x0092525eu;
        t20 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00925261: b803000000 MOV
        t21 = 0x00000003u;
        state.regs[0] = t21;
    // 0x00925266: c7462000000000 MOV
        batch_guest_pc = 0x00925266u;
        t22 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x0092526d: 3bd0 CMP
        t23a = state.regs[2];
        t23b = state.regs[0];
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x0092526f: 7737 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_009252a8;
    // 0x00925271: ff2495e8529200 JMP
        batch_guest_pc = 0x00925271u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] * 4u + 0x009252e8u), t25a)) return BatchLiftStatus::invalid_memory;
        switch (t25a) {
        case 0x00925278u: goto L_00925278;
        case 0x00925288u: goto L_00925288;
        case 0x0092529cu: goto L_0092529c;
        default:
        state.eip = t25a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x00925278: 894608 MOV
    L_00925278:
        batch_guest_pc = 0x00925278u;
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0092527b: 85c9 TEST
        t27a = state.regs[1];
        t27b = state.regs[1];
        t27r = (t27a & t27b) & 0xffffffffu;
        batch_set_logic_flags(state, t27r, 32u);
    // 0x0092527d: 7530 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009252af;
    // 0x0092527f: c7460c96000000 MOV
        batch_guest_pc = 0x0092527fu;
        t29 = 0x00000096u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00925286: eb27 JMP
        goto L_009252af;
    // 0x00925288: c7460801000000 MOV
    L_00925288:
        batch_guest_pc = 0x00925288u;
        t31 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x0092528f: 85c9 TEST
        t32a = state.regs[1];
        t32b = state.regs[1];
        t32r = (t32a & t32b) & 0xffffffffu;
        batch_set_logic_flags(state, t32r, 32u);
    // 0x00925291: 751c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009252af;
    // 0x00925293: c7460c19000000 MOV
        batch_guest_pc = 0x00925293u;
        t34 = 0x00000019u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t34)) return BatchLiftStatus::invalid_memory;
    // 0x0092529a: eb13 JMP
        goto L_009252af;
    // 0x0092529c: 894608 MOV
    L_0092529c:
        batch_guest_pc = 0x0092529cu;
        t36 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x0092529f: c7460c96000000 MOV
        batch_guest_pc = 0x0092529fu;
        t37 = 0x00000096u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t37)) return BatchLiftStatus::invalid_memory;
    // 0x009252a6: eb07 JMP
        goto L_009252af;
    // 0x009252a8: c7460801000000 MOV
    L_009252a8:
        batch_guest_pc = 0x009252a8u;
        t39 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x009252af: 85ff TEST
    L_009252af:
        t40a = state.regs[7];
        t40b = state.regs[7];
        t40r = (t40a & t40b) & 0xffffffffu;
        batch_set_logic_flags(state, t40r, 32u);
    // 0x009252b1: 7507 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009252ba;
    // 0x009252b3: c74610bc8c3f01 MOV
        batch_guest_pc = 0x009252b3u;
        t42 = 0x013f8cbcu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x009252ba: 8b0d9c8e6601 MOV
    L_009252ba:
        batch_guest_pc = 0x009252bau;
        if (!memory.load32(0x01668e9cu, t43)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43;
    // 0x009252c0: 8b4910 MOV
        batch_guest_pc = 0x009252c0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000010u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t44;
    // 0x009252c3: 85c9 TEST
        t45a = state.regs[1];
        t45b = state.regs[1];
        t45r = (t45a & t45b) & 0xffffffffu;
        batch_set_logic_flags(state, t45r, 32u);
    // 0x009252c5: 7410 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009252d7;
    // 0x009252c7: 8b11 MOV
        batch_guest_pc = 0x009252c7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t47;
    // 0x009252c9: 8b4218 MOV
        batch_guest_pc = 0x009252c9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000018u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x009252cc: 56 PUSH
        batch_guest_pc = 0x009252ccu;
        t49a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x009252cd: ffd0 CALL
        t50_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009252cfu);
        if (t50_call_status != BatchLiftStatus::returned) return t50_call_status;
    // 0x009252cf: 5f POP
        batch_guest_pc = 0x009252cfu;
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t51a;
    // 0x009252d0: 8bc6 MOV
        t52 = state.regs[6];
        state.regs[0] = t52;
    // 0x009252d2: 5e POP
        batch_guest_pc = 0x009252d2u;
        if (!memory.load32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t53a;
    // 0x009252d3: 5d POP
        batch_guest_pc = 0x009252d3u;
        if (!memory.load32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t54a;
    // 0x009252d4: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009252d7: 5f POP
    L_009252d7:
        batch_guest_pc = 0x009252d7u;
        if (!memory.load32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t56a;
    // 0x009252d8: c60600 MOV
        batch_guest_pc = 0x009252d8u;
        t57 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t57)) return BatchLiftStatus::invalid_memory;
    // 0x009252db: c6460201 MOV
        batch_guest_pc = 0x009252dbu;
        t58 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000002u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x009252df: 8bc6 MOV
        t59 = state.regs[6];
        state.regs[0] = t59;
    // 0x009252e1: 5e POP
        batch_guest_pc = 0x009252e1u;
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t60a;
    // 0x009252e2: 5d POP
        batch_guest_pc = 0x009252e2u;
        if (!memory.load32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t61a;
    // 0x009252e3: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
