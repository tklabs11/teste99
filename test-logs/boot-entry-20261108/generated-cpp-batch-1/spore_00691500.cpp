#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004558a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690b80(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00691575(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_006915a3(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922a90(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922ab0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00691500(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00691500u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    BatchLiftStatus t53_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62a = 0;

    // 0x00691500: 51 PUSH
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00691501: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00691502: 8bd9 MOV
        t2 = state.regs[1];
        state.regs[3] = t2;
    // 0x00691504: ff83a0010000 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x000001a0u), t3a)) return BatchLiftStatus::invalid_memory;
        t3r = static_cast<std::uint32_t>(t3a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t3a, t3r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x000001a0u), t3r)) return BatchLiftStatus::invalid_memory;
    // 0x0069150a: 8d8398010000 LEA
        t4 = static_cast<std::uint32_t>(state.regs[3] + 0x00000198u);
        state.regs[0] = t4;
    // 0x00691510: 55 PUSH
        t5a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00691511: 8b28 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t6;
    // 0x00691513: 3be8 CMP
        t7a = state.regs[5];
        t7b = state.regs[0];
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x00691515: 0f849b000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006915b6;
    // 0x0069151b: 56 PUSH
        t9a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x0069151c: 57 PUSH
        t10a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0069151d: 8d4900 LEA
        t11 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t11;
    // 0x00691520: 8d7520 LEA
    L_00691520:
        t12 = static_cast<std::uint32_t>(state.regs[5] + 0x00000020u);
        state.regs[6] = t12;
    // 0x00691523: 8bce MOV
        t13 = state.regs[6];
        state.regs[1] = t13;
    // 0x00691525: e866152900 CALL
        t14_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00922a90u, 0x0069152au);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x0069152au) return BatchLiftStatus::invalid_control_flow;
    // 0x0069152a: 8bf8 MOV
        t15 = state.regs[0];
        state.regs[7] = t15;
    // 0x0069152c: 897c2410 MOV
        t16 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00691530: 81ff00000080 CMP
        t17a = state.regs[7];
        t17b = 0x80000000u;
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x00691536: 746b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006915a3;
    // 0x00691538: 8b442418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x0069153c: 3bf8 CMP
        t20a = state.regs[7];
        t20b = state.regs[0];
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x0069153e: 7d63 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_006915a3;
    // 0x00691540: 50 PUSH
        t22a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00691541: 8bce MOV
        t23 = state.regs[6];
        state.regs[1] = t23;
    // 0x00691543: e868152900 CALL
        t24_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00922ab0u, 0x00691548u);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x00691548u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691548: 8b83a8010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x000001a8u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x0069154e: 3b83ac010000 CMP
        t26a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x000001acu), t26b)) return BatchLiftStatus::invalid_memory;
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0xffffffffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 32u);
    // 0x00691554: 8d8ba4010000 LEA
        t27 = static_cast<std::uint32_t>(state.regs[3] + 0x000001a4u);
        state.regs[1] = t27;
    // 0x0069155a: 730e JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0069156a;
    // 0x0069155c: 8d5004 LEA
        t29 = static_cast<std::uint32_t>(state.regs[0] + 0x00000004u);
        state.regs[2] = t29;
    // 0x0069155f: 895104 MOV
        t30 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00691562: 85c0 TEST
        t31a = state.regs[0];
        t31b = state.regs[0];
        t31r = (t31a & t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
    // 0x00691564: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00691575;
    // 0x00691566: 8938 MOV
        t33 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x00691568: eb0b JMP
        goto L_00691575;
    // 0x0069156a: 8d542410 LEA
    L_0069156a:
        t35 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[2] = t35;
    // 0x0069156e: 52 PUSH
        t36a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x0069156f: 50 PUSH
        t37a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00691570: e82b43dcff CALL
        t38_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x004558a0u, 0x00691575u);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
        if (state.eip != 0x00691575u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691575: 8b83bc010000 MOV
    L_00691575:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x000001bcu), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x0069157b: 8d8bb8010000 LEA
        t40 = static_cast<std::uint32_t>(state.regs[3] + 0x000001b8u);
        state.regs[1] = t40;
    // 0x00691581: 89742410 MOV
        t41 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x00691585: 3b4108 CMP
        t42a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t42b)) return BatchLiftStatus::invalid_memory;
        t42r = static_cast<std::uint32_t>(t42a - t42b) & 0xffffffffu;
        batch_set_sub_flags(state, t42a, t42b, t42r, 32u);
    // 0x00691588: 730e JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00691598;
    // 0x0069158a: 8d5004 LEA
        t44 = static_cast<std::uint32_t>(state.regs[0] + 0x00000004u);
        state.regs[2] = t44;
    // 0x0069158d: 895104 MOV
        t45 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x00691590: 85c0 TEST
        t46a = state.regs[0];
        t46b = state.regs[0];
        t46r = (t46a & t46b) & 0xffffffffu;
        batch_set_logic_flags(state, t46r, 32u);
    // 0x00691592: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006915a3;
    // 0x00691594: 8930 MOV
        t48 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00691596: eb0b JMP
        goto L_006915a3;
    // 0x00691598: 8d542410 LEA
    L_00691598:
        t50 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[2] = t50;
    // 0x0069159c: 52 PUSH
        t51a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x0069159d: 50 PUSH
        t52a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x0069159e: e8ddf5ffff CALL
        t53_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00690b80u, 0x006915a3u);
        if (t53_call_status != BatchLiftStatus::returned) return t53_call_status;
        if (state.eip != 0x006915a3u) return BatchLiftStatus::invalid_control_flow;
    // 0x006915a3: 8b6d00 MOV
    L_006915a3:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t54;
    // 0x006915a6: 8d8398010000 LEA
        t55 = static_cast<std::uint32_t>(state.regs[3] + 0x00000198u);
        state.regs[0] = t55;
    // 0x006915ac: 3be8 CMP
        t56a = state.regs[5];
        t56b = state.regs[0];
        t56r = static_cast<std::uint32_t>(t56a - t56b) & 0xffffffffu;
        batch_set_sub_flags(state, t56a, t56b, t56r, 32u);
    // 0x006915ae: 0f856cffffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00691520;
    // 0x006915b4: 5f POP
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t58a;
    // 0x006915b5: 5e POP
        if (!memory.load32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t59a;
    // 0x006915b6: 5d POP
    L_006915b6:
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t60a;
    // 0x006915b7: 5b POP
        if (!memory.load32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t61a;
    // 0x006915b8: 59 POP
        if (!memory.load32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t62a;
    // 0x006915b9: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
