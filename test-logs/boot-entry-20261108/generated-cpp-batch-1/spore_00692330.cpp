#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00690630(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690f60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00692150(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_006923b1(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_006923b8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00692330(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00692330u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25 = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27 = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31 = 0;
    BatchLiftStatus t32_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45 = 0;
    BatchLiftStatus t46_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    BatchLiftStatus t49_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;

    // 0x00692330: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00692332: 6858cf2001 PUSH
        t1a = 0x0120cf58u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00692337: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x0069233d: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0069233e: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00692345: 51 PUSH
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00692346: 53 PUSH
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00692347: 55 PUSH
        t7a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00692348: 56 PUSH
        t8a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00692349: 8bf1 MOV
        t9 = state.regs[1];
        state.regs[6] = t9;
    // 0x0069234b: 57 PUSH
        t10a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0069234c: 8d6e08 LEA
        t11 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[5] = t11;
    // 0x0069234f: 6850374001 PUSH
        t12a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00692354: 8bcd MOV
        t13 = state.regs[5];
        state.regs[1] = t13;
    // 0x00692356: 33db XOR
        t14a = state.regs[3];
        t14b = state.regs[3];
        t14r = (t14a ^ t14b) & 0xffffffffu;
        batch_set_logic_flags(state, t14r, 32u);
        state.regs[3] = t14r;
    // 0x00692358: 896c2414 MOV
        t15 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0069235c: e84ffe2800 CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00692361u)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_009221b0(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00692361u) return BatchLiftStatus::invalid_control_flow;
    // 0x00692361: 8b7c2424 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t17;
    // 0x00692365: 8b471c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000001cu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x00692368: 48 DEC
        t19a = state.regs[0];
        t19r = static_cast<std::uint32_t>(t19a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t19a, t19r, 32u);
        state.regs[0] = t19r;
    // 0x00692369: 895c241c MOV
        t20 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t20)) return BatchLiftStatus::invalid_memory;
    // 0x0069236d: 83f807 CMP
        t21a = state.regs[0];
        t21b = 0x00000007u;
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0xffffffffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 32u);
    // 0x00692370: 7746 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_006923b8;
    // 0x00692372: ff2485e0236900 JMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] * 4u + 0x006923e0u), t23a)) return BatchLiftStatus::invalid_memory;
        switch (t23a) {
        case 0x00692379u: goto L_00692379;
        case 0x00692381u: goto L_00692381;
        case 0x00692385u: goto L_00692385;
        case 0x006923a5u: goto L_006923a5;
        case 0x006923b8u: goto L_006923b8;
        default:
        state.eip = t23a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x00692379: 57 PUSH
    L_00692379:
        t24a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x0069237a: 8bce MOV
        t25 = state.regs[6];
        state.regs[1] = t25;
    // 0x0069237c: e8dfebffff CALL
        if (!batch_guest_call32(memory, state, 0x00690f60u, 0x00692381u)) return BatchLiftStatus::invalid_memory;
        t26_call_status = spore_lift_00690f60(memory, state);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x00692381u) return BatchLiftStatus::invalid_control_flow;
    // 0x00692381: b301 MOV
    L_00692381:
        t27 = 0x00000001u;
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t27 << 0u) & 0x000000ffu);
    // 0x00692383: eb33 JMP
        goto L_006923b8;
    // 0x00692385: 6a01 PUSH
    L_00692385:
        t29a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00692387: 57 PUSH
        t30a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x00692388: 8bce MOV
        t31 = state.regs[6];
        state.regs[1] = t31;
    // 0x0069238a: e8a1e2ffff CALL
        if (!batch_guest_call32(memory, state, 0x00690630u, 0x0069238fu)) return BatchLiftStatus::invalid_memory;
        t32_call_status = spore_lift_00690630(memory, state);
        if (t32_call_status != BatchLiftStatus::returned) return t32_call_status;
        if (state.eip != 0x0069238fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069238f: 807c242800 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t33a)) return BatchLiftStatus::invalid_memory;
        t33b = 0x00000000u;
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0x000000ffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 8u);
    // 0x00692394: c7471c06000000 MOV
        t34 = 0x00000006u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x0000001cu), t34)) return BatchLiftStatus::invalid_memory;
    // 0x0069239b: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006923b8;
    // 0x0069239d: 57 PUSH
        t36a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x0069239e: 8d442414 LEA
        t37 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[0] = t37;
    // 0x006923a2: 50 PUSH
        t38a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x006923a3: eb0c JMP
        goto L_006923b1;
    // 0x006923a5: 385c2428 CMP
    L_006923a5:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t40a)) return BatchLiftStatus::invalid_memory;
        t40b = state.regs[3] & 0x000000ffu;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0x000000ffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 8u);
    // 0x006923a9: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006923b8;
    // 0x006923ab: 57 PUSH
        t42a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x006923ac: 8d4c2414 LEA
        t43 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[1] = t43;
    // 0x006923b0: 51 PUSH
        t44a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x006923b1: 8bce MOV
    L_006923b1:
        t45 = state.regs[6];
        state.regs[1] = t45;
    // 0x006923b3: e898fdffff CALL
        if (!batch_guest_call32(memory, state, 0x00692150u, 0x006923b8u)) return BatchLiftStatus::invalid_memory;
        t46_call_status = spore_lift_00692150(memory, state);
        if (t46_call_status != BatchLiftStatus::returned) return t46_call_status;
        if (state.eip != 0x006923b8u) return BatchLiftStatus::invalid_control_flow;
    // 0x006923b8: 8bcd MOV
    L_006923b8:
        t47 = state.regs[5];
        state.regs[1] = t47;
    // 0x006923ba: c744241cffffffff MOV
        t48 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t48)) return BatchLiftStatus::invalid_memory;
    // 0x006923c2: e8a9fe2800 CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x006923c7u)) return BatchLiftStatus::invalid_memory;
        t49_call_status = spore_lift_00922270(memory, state);
        if (t49_call_status != BatchLiftStatus::returned) return t49_call_status;
        if (state.eip != 0x006923c7u) return BatchLiftStatus::invalid_control_flow;
    // 0x006923c7: 8b4c2414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t50;
    // 0x006923cb: 5f POP
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t51a;
    // 0x006923cc: 5e POP
        if (!memory.load32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t52a;
    // 0x006923cd: 5d POP
        if (!memory.load32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t53a;
    // 0x006923ce: 8ac3 MOV
        t54 = state.regs[3] & 0x000000ffu;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t54 << 0u) & 0x000000ffu);
    // 0x006923d0: 5b POP
        if (!memory.load32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t55a;
    // 0x006923d1: 64890d00000000 MOV
        t56 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t56)) return BatchLiftStatus::invalid_memory;
    // 0x006923d8: 83c410 ADD
        t57a = state.regs[4];
        t57b = 0x00000010u;
        t57r = static_cast<std::uint32_t>(t57a + t57b) & 0xffffffffu;
        batch_set_add_flags(state, t57a, t57b, t57r, 32u);
        state.regs[4] = t57r;
    // 0x006923db: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
