#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009215c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923de0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924099(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009240dc(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924060(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924060u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32a = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39a = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55 = 0;
    BatchLiftStatus t56_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64a = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69a = 0;
    std::uint32_t t70a = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72a = 0;

    // 0x00924060: 53 PUSH
        batch_guest_pc = 0x00924060u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00924061: 55 PUSH
        batch_guest_pc = 0x00924061u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00924062: 8b6c2410 MOV
        batch_guest_pc = 0x00924062u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t2;
    // 0x00924066: 8bd9 MOV
        t3 = state.regs[1];
        state.regs[3] = t3;
    // 0x00924068: 56 PUSH
        batch_guest_pc = 0x00924068u;
        t4a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00924069: 8b730c MOV
        batch_guest_pc = 0x00924069u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000000cu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t5;
    // 0x0092406c: 57 PUSH
        batch_guest_pc = 0x0092406cu;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0092406d: 8d7b04 LEA
        t7 = static_cast<std::uint32_t>(state.regs[3] + 0x00000004u);
        state.regs[7] = t7;
    // 0x00924070: b001 MOV
        t8 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t8 << 0u) & 0x000000ffu);
    // 0x00924072: 85f6 TEST
        t9a = state.regs[6];
        t9b = state.regs[6];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x00924074: 7427 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092409d;
    // 0x00924076: 8b4610 MOV
    L_00924076:
        batch_guest_pc = 0x00924076u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00924079: 8b4d00 MOV
        batch_guest_pc = 0x00924079u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x0092407c: 50 PUSH
        batch_guest_pc = 0x0092407cu;
        t13a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x0092407d: 51 PUSH
        batch_guest_pc = 0x0092407du;
        t14a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x0092407e: ff15dcc43c01 CALL
        t15_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_stricmp", 0x013cc4dcu, 0x00924084u);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x00924084u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924084: 83c408 ADD
        t16a = state.regs[4];
        t16b = 0x00000008u;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[4] = t16r;
    // 0x00924087: 85c0 TEST
        t17a = state.regs[0];
        t17b = state.regs[0];
        t17r = (t17a & t17b) & 0xffffffffu;
        batch_set_logic_flags(state, t17r, 32u);
    // 0x00924089: 0f9cc0 SETL
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x0092408c: 8bfe MOV
        t19 = state.regs[6];
        state.regs[7] = t19;
    // 0x0092408e: 84c0 TEST
        t20a = state.regs[0] & 0x000000ffu;
        t20b = state.regs[0] & 0x000000ffu;
        t20r = (t20a & t20b) & 0x000000ffu;
        batch_set_logic_flags(state, t20r, 8u);
    // 0x00924090: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924097;
    // 0x00924092: 8b7604 MOV
        batch_guest_pc = 0x00924092u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t22;
    // 0x00924095: eb02 JMP
        goto L_00924099;
    // 0x00924097: 8b36 MOV
    L_00924097:
        batch_guest_pc = 0x00924097u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t24;
    // 0x00924099: 85f6 TEST
    L_00924099:
        t25a = state.regs[6];
        t25b = state.regs[6];
        t25r = (t25a & t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
    // 0x0092409b: 75d9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924076;
    // 0x0092409d: 8bf7 MOV
    L_0092409d:
        t27 = state.regs[7];
        state.regs[6] = t27;
    // 0x0092409f: 84c0 TEST
        t28a = state.regs[0] & 0x000000ffu;
        t28b = state.regs[0] & 0x000000ffu;
        t28r = (t28a & t28b) & 0x000000ffu;
        batch_set_logic_flags(state, t28r, 8u);
    // 0x009240a1: 7410 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009240b3;
    // 0x009240a3: 3b7b08 CMP
        batch_guest_pc = 0x009240a3u;
        t30a = state.regs[7];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000008u), t30b)) return BatchLiftStatus::invalid_memory;
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
    // 0x009240a6: 742b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009240d3;
    // 0x009240a8: 57 PUSH
        batch_guest_pc = 0x009240a8u;
        t32a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x009240a9: e812d5ffff CALL
        if (!batch_guest_call32(memory, state, 0x009215c0u, 0x009240aeu)) return BatchLiftStatus::invalid_memory;
        t33_call_status = spore_lift_009215c0(memory, state);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
        if (state.eip != 0x009240aeu) return BatchLiftStatus::invalid_control_flow;
    // 0x009240ae: 83c404 ADD
        t34a = state.regs[4];
        t34b = 0x00000004u;
        t34r = static_cast<std::uint32_t>(t34a + t34b) & 0xffffffffu;
        batch_set_add_flags(state, t34a, t34b, t34r, 32u);
        state.regs[4] = t34r;
    // 0x009240b1: 8bf8 MOV
        t35 = state.regs[0];
        state.regs[7] = t35;
    // 0x009240b3: 8b4500 MOV
    L_009240b3:
        batch_guest_pc = 0x009240b3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t36;
    // 0x009240b6: 8b4f10 MOV
        batch_guest_pc = 0x009240b6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t37;
    // 0x009240b9: 50 PUSH
        batch_guest_pc = 0x009240b9u;
        t38a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x009240ba: 51 PUSH
        batch_guest_pc = 0x009240bau;
        t39a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
    // 0x009240bb: ff15dcc43c01 CALL
        t40_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_stricmp", 0x013cc4dcu, 0x009240c1u);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
        if (state.eip != 0x009240c1u) return BatchLiftStatus::invalid_control_flow;
    // 0x009240c1: 83c408 ADD
        t41a = state.regs[4];
        t41b = 0x00000008u;
        t41r = static_cast<std::uint32_t>(t41a + t41b) & 0xffffffffu;
        batch_set_add_flags(state, t41a, t41b, t41r, 32u);
        state.regs[4] = t41r;
    // 0x009240c4: 85c0 TEST
        t42a = state.regs[0];
        t42b = state.regs[0];
        t42r = (t42a & t42b) & 0xffffffffu;
        batch_set_logic_flags(state, t42r, 32u);
    // 0x009240c6: 7d30 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009240f8;
    // 0x009240c8: 6a00 PUSH
        batch_guest_pc = 0x009240c8u;
        t44a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x009240ca: 55 PUSH
        batch_guest_pc = 0x009240cau;
        t45a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
    // 0x009240cb: 56 PUSH
        batch_guest_pc = 0x009240cbu;
        t46a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x009240cc: 8d542424 LEA
        t47 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[2] = t47;
    // 0x009240d0: 52 PUSH
        batch_guest_pc = 0x009240d0u;
        t48a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x009240d1: eb09 JMP
        goto L_009240dc;
    // 0x009240d3: 6a00 PUSH
    L_009240d3:
        batch_guest_pc = 0x009240d3u;
        t50a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
    // 0x009240d5: 55 PUSH
        batch_guest_pc = 0x009240d5u;
        t51a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x009240d6: 57 PUSH
        batch_guest_pc = 0x009240d6u;
        t52a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x009240d7: 8d442424 LEA
        t53 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[0] = t53;
    // 0x009240db: 50 PUSH
        batch_guest_pc = 0x009240dbu;
        t54a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x009240dc: 8bcb MOV
    L_009240dc:
        t55 = state.regs[3];
        state.regs[1] = t55;
    // 0x009240de: e8fdfcffff CALL
        if (!batch_guest_call32(memory, state, 0x00923de0u, 0x009240e3u)) return BatchLiftStatus::invalid_memory;
        t56_call_status = spore_lift_00923de0(memory, state);
        if (t56_call_status != BatchLiftStatus::returned) return t56_call_status;
        if (state.eip != 0x009240e3u) return BatchLiftStatus::invalid_control_flow;
    // 0x009240e3: 8b442414 MOV
        batch_guest_pc = 0x009240e3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t57;
    // 0x009240e7: 8b4c2418 MOV
        batch_guest_pc = 0x009240e7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t58;
    // 0x009240eb: 5f POP
        batch_guest_pc = 0x009240ebu;
        if (!memory.load32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t59a;
    // 0x009240ec: 5e POP
        batch_guest_pc = 0x009240ecu;
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t60a;
    // 0x009240ed: 5d POP
        batch_guest_pc = 0x009240edu;
        if (!memory.load32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t61a;
    // 0x009240ee: 8908 MOV
        batch_guest_pc = 0x009240eeu;
        t62 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x009240f0: c6400401 MOV
        batch_guest_pc = 0x009240f0u;
        t63 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t63)) return BatchLiftStatus::invalid_memory;
    // 0x009240f4: 5b POP
        batch_guest_pc = 0x009240f4u;
        if (!memory.load32(state.regs[4], t64a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t64a;
    // 0x009240f5: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009240f8: 8b442414 MOV
    L_009240f8:
        batch_guest_pc = 0x009240f8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t66;
    // 0x009240fc: 8938 MOV
        batch_guest_pc = 0x009240fcu;
        t67 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t67)) return BatchLiftStatus::invalid_memory;
    // 0x009240fe: 5f POP
        batch_guest_pc = 0x009240feu;
        if (!memory.load32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t68a;
    // 0x009240ff: 5e POP
        batch_guest_pc = 0x009240ffu;
        if (!memory.load32(state.regs[4], t69a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t69a;
    // 0x00924100: 5d POP
        batch_guest_pc = 0x00924100u;
        if (!memory.load32(state.regs[4], t70a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t70a;
    // 0x00924101: c6400400 MOV
        batch_guest_pc = 0x00924101u;
        t71 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x00924105: 5b POP
        batch_guest_pc = 0x00924105u;
        if (!memory.load32(state.regs[4], t72a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t72a;
    // 0x00924106: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
