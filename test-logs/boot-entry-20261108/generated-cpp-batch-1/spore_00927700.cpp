#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009274d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927740(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009277bb(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927816(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00927700(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00927700u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0, t7c = 0, t7r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t62a = 0, t62b = 0, t62r = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78a = 0, t78b = 0, t78r = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0, t82c = 0, t82r = 0;
    std::uint32_t t83a = 0, t83b = 0, t83r = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87a = 0, t87b = 0, t87r = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t95a = 0, t95b = 0, t95r = 0;
    std::uint32_t t96a = 0;
    std::uint32_t t97a = 0;
    std::uint32_t t98a = 0;
    std::uint32_t t99a = 0;
    std::uint32_t t100a = 0, t100b = 0, t100r = 0;
    std::uint32_t t102a = 0;
    std::uint32_t t103a = 0;
    std::uint32_t t104a = 0;
    std::uint32_t t105a = 0;
    std::uint32_t t106a = 0;
    std::uint32_t t107a = 0;
    BatchLiftStatus t108_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t109a = 0;
    std::uint32_t t110a = 0, t110b = 0, t110r = 0;

    // 0x00927700: 83ec0c SUB
        t0a = state.regs[4];
        t0b = 0x0000000cu;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00927703: 55 PUSH
        batch_guest_pc = 0x00927703u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00927704: 8be9 MOV
        t2 = state.regs[1];
        state.regs[5] = t2;
    // 0x00927706: 8b4504 MOV
        batch_guest_pc = 0x00927706u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00927709: 85c0 TEST
        t4a = state.regs[0];
        t4b = state.regs[0];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x0092770b: 0f8434010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927845;
    // 0x00927711: 53 PUSH
        batch_guest_pc = 0x00927711u;
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00927712: c1e803 SHR
        t7a = state.regs[0];
        t7c = 3u;
        if (t7c != 0u) {
        t7r = static_cast<std::uint32_t>(t7a >> t7c);
        batch_set_shr_flags(state, t7a, t7c, t7r, 32u);
            state.regs[0] = t7r;
        }
    // 0x00927715: 8d448500 LEA
        t8 = static_cast<std::uint32_t>(state.regs[5] + state.regs[0] * 4u + 0x00000000u);
        state.regs[0] = t8;
    // 0x00927719: 8d4d08 LEA
        t9 = static_cast<std::uint32_t>(state.regs[5] + 0x00000008u);
        state.regs[1] = t9;
    // 0x0092771c: 56 PUSH
        batch_guest_pc = 0x0092771cu;
        t10a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0092771d: 89442414 MOV
        batch_guest_pc = 0x0092771du;
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00927721: 894c240c MOV
        batch_guest_pc = 0x00927721u;
        t12 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00927725: 57 PUSH
        batch_guest_pc = 0x00927725u;
        t13a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00927726: 8b01 MOV
    L_00927726:
        batch_guest_pc = 0x00927726u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00927728: 85c0 TEST
        t15a = state.regs[0];
        t15b = state.regs[0];
        t15r = (t15a & t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
    // 0x0092772a: 0f84f6000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927826;
    // 0x00927730: c70100000000 MOV
        batch_guest_pc = 0x00927730u;
        t17 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00927736: eb08 JMP
        goto L_00927740;
    // 0x00927740: 816004fbffff7f AND
    L_00927740:
        batch_guest_pc = 0x00927740u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t19a)) return BatchLiftStatus::invalid_memory;
        t19b = 0x7ffffffbu;
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t19r)) return BatchLiftStatus::invalid_memory;
    // 0x00927747: 8b5804 MOV
        batch_guest_pc = 0x00927747u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t20;
    // 0x0092774a: 8b480c MOV
        batch_guest_pc = 0x0092774au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t21;
    // 0x0092774d: 8bd3 MOV
        t22 = state.regs[3];
        state.regs[2] = t22;
    // 0x0092774f: 81e2f8ffff7f AND
        t23a = state.regs[2];
        t23b = 0x7ffffff8u;
        t23r = (t23a & t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[2] = t23r;
    // 0x00927755: 8b7c0204 MOV
        batch_guest_pc = 0x00927755u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + state.regs[0] * 1u + 0x00000004u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t24;
    // 0x00927759: 8d3402 LEA
        t25 = static_cast<std::uint32_t>(state.regs[2] + state.regs[0] * 1u + 0x00000000u);
        state.regs[6] = t25;
    // 0x0092775c: 81e7f8ffff7f AND
        t26a = state.regs[7];
        t26b = 0x7ffffff8u;
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[7] = t26r;
    // 0x00927762: 894c2414 MOV
        batch_guest_pc = 0x00927762u;
        t27 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00927766: f6c301 TEST
        t28a = state.regs[3] & 0x000000ffu;
        t28b = 0x00000001u;
        t28r = (t28a & t28b) & 0x000000ffu;
        batch_set_logic_flags(state, t28r, 8u);
    // 0x00927769: 7522 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092778d;
    // 0x0092776b: 8b18 MOV
        batch_guest_pc = 0x0092776bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t30;
    // 0x0092776d: 03d3 ADD
        t31a = state.regs[2];
        t31b = state.regs[3];
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[2] = t31r;
    // 0x0092776f: 2bc3 SUB
        t32a = state.regs[0];
        t32b = state.regs[3];
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
        state.regs[0] = t32r;
    // 0x00927771: 8bca MOV
        t33 = state.regs[2];
        state.regs[1] = t33;
    // 0x00927773: 83c901 OR
        t34a = state.regs[1];
        t34b = 0x00000001u;
        t34r = (t34a | t34b) & 0xffffffffu;
        batch_set_logic_flags(state, t34r, 32u);
        state.regs[1] = t34r;
    // 0x00927776: 894804 MOV
        batch_guest_pc = 0x00927776u;
        t35 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x00927779: 8916 MOV
        batch_guest_pc = 0x00927779u;
        t36 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x0092777b: 8b4808 MOV
        batch_guest_pc = 0x0092777bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t37;
    // 0x0092777e: 8b580c MOV
        batch_guest_pc = 0x0092777eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t38;
    // 0x00927781: 89590c MOV
        batch_guest_pc = 0x00927781u;
        t39 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t39)) return BatchLiftStatus::invalid_memory;
    // 0x00927784: 8b480c MOV
        batch_guest_pc = 0x00927784u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t40;
    // 0x00927787: 8b5808 MOV
        batch_guest_pc = 0x00927787u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t41;
    // 0x0092778a: 895908 MOV
        batch_guest_pc = 0x0092778au;
        t42 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x0092778d: f644370401 TEST
    L_0092778d:
        batch_guest_pc = 0x0092778du;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + state.regs[6] * 1u + 0x00000004u), t43a)) return BatchLiftStatus::invalid_memory;
        t43b = 0x00000001u;
        t43r = (t43a & t43b) & 0x000000ffu;
        batch_set_logic_flags(state, t43r, 8u);
    // 0x00927792: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092779c;
    // 0x00927794: 836604fe AND
        batch_guest_pc = 0x00927794u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t45a)) return BatchLiftStatus::invalid_memory;
        t45b = 0xfffffffeu;
        t45r = (t45a & t45b) & 0xffffffffu;
        batch_set_logic_flags(state, t45r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t45r)) return BatchLiftStatus::invalid_memory;
    // 0x00927798: 8916 MOV
        batch_guest_pc = 0x00927798u;
        t46 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x0092779a: eb1f JMP
        goto L_009277bb;
    // 0x0092779c: 8b4e08 MOV
    L_0092779c:
        batch_guest_pc = 0x0092779cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t48;
    // 0x0092779f: 8b5e0c MOV
        batch_guest_pc = 0x0092779fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t49;
    // 0x009277a2: 89590c MOV
        batch_guest_pc = 0x009277a2u;
        t50 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t50)) return BatchLiftStatus::invalid_memory;
    // 0x009277a5: 8b4e0c MOV
        batch_guest_pc = 0x009277a5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t51;
    // 0x009277a8: 8b5e08 MOV
        batch_guest_pc = 0x009277a8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t52;
    // 0x009277ab: 895908 MOV
        batch_guest_pc = 0x009277abu;
        t53 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x009277ae: 03d7 ADD
        t54a = state.regs[2];
        t54b = state.regs[7];
        t54r = static_cast<std::uint32_t>(t54a + t54b) & 0xffffffffu;
        batch_set_add_flags(state, t54a, t54b, t54r, 32u);
        state.regs[2] = t54r;
    // 0x009277b0: 8bca MOV
        t55 = state.regs[2];
        state.regs[1] = t55;
    // 0x009277b2: 83c901 OR
        t56a = state.regs[1];
        t56b = 0x00000001u;
        t56r = (t56a | t56b) & 0xffffffffu;
        batch_set_logic_flags(state, t56r, 32u);
        state.regs[1] = t56r;
    // 0x009277b5: 894804 MOV
        batch_guest_pc = 0x009277b5u;
        t57 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t57)) return BatchLiftStatus::invalid_memory;
    // 0x009277b8: 891402 MOV
        batch_guest_pc = 0x009277b8u;
        t58 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + state.regs[0] * 1u + 0x00000000u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x009277bb: 8bbd40040000 MOV
    L_009277bb:
        batch_guest_pc = 0x009277bbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000440u), t59)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t59;
    // 0x009277c1: 3bc7 CMP
        t60a = state.regs[0];
        t60b = state.regs[7];
        t60r = static_cast<std::uint32_t>(t60a - t60b) & 0xffffffffu;
        batch_set_sub_flags(state, t60a, t60b, t60r, 32u);
    // 0x009277c3: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009277dd;
    // 0x009277c5: 3bf7 CMP
        t62a = state.regs[6];
        t62b = state.regs[7];
        t62r = static_cast<std::uint32_t>(t62a - t62b) & 0xffffffffu;
        batch_set_sub_flags(state, t62a, t62b, t62r, 32u);
    // 0x009277c7: 7414 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009277dd;
    // 0x009277c9: 8b553c MOV
        batch_guest_pc = 0x009277c9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000003cu), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t64;
    // 0x009277cc: 8d4d30 LEA
        t65 = static_cast<std::uint32_t>(state.regs[5] + 0x00000030u);
        state.regs[1] = t65;
    // 0x009277cf: 894808 MOV
        batch_guest_pc = 0x009277cfu;
        t66 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t66)) return BatchLiftStatus::invalid_memory;
    // 0x009277d2: 89500c MOV
        batch_guest_pc = 0x009277d2u;
        t67 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t67)) return BatchLiftStatus::invalid_memory;
    // 0x009277d5: 89410c MOV
        batch_guest_pc = 0x009277d5u;
        t68 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t68)) return BatchLiftStatus::invalid_memory;
    // 0x009277d8: 894208 MOV
        batch_guest_pc = 0x009277d8u;
        t69 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t69)) return BatchLiftStatus::invalid_memory;
    // 0x009277db: eb39 JMP
        goto L_00927816;
    // 0x009277dd: 898540040000 MOV
    L_009277dd:
        batch_guest_pc = 0x009277ddu;
        t71 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000440u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x009277e3: 8bca MOV
        t72 = state.regs[2];
        state.regs[1] = t72;
    // 0x009277e5: 83c901 OR
        t73a = state.regs[1];
        t73b = 0x00000001u;
        t73r = (t73a | t73b) & 0xffffffffu;
        batch_set_logic_flags(state, t73r, 32u);
        state.regs[1] = t73r;
    // 0x009277e8: 89400c MOV
        batch_guest_pc = 0x009277e8u;
        t74 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t74)) return BatchLiftStatus::invalid_memory;
    // 0x009277eb: 894008 MOV
        batch_guest_pc = 0x009277ebu;
        t75 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x009277ee: 894804 MOV
        batch_guest_pc = 0x009277eeu;
        t76 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x009277f1: 891402 MOV
        batch_guest_pc = 0x009277f1u;
        t77 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + state.regs[0] * 1u + 0x00000000u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x009277f4: 80bd6c04000000 CMP
        batch_guest_pc = 0x009277f4u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000046cu), t78a)) return BatchLiftStatus::invalid_memory;
        t78b = 0x00000000u;
        t78r = static_cast<std::uint32_t>(t78a - t78b) & 0x000000ffu;
        batch_set_sub_flags(state, t78a, t78b, t78r, 8u);
    // 0x009277fb: 7519 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927816;
    // 0x009277fd: 8b8540040000 MOV
        batch_guest_pc = 0x009277fdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000440u), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t80;
    // 0x00927803: 8b5004 MOV
        batch_guest_pc = 0x00927803u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t81;
    // 0x00927806: d1ea SHR
        t82a = state.regs[2];
        t82c = 1u;
        if (t82c != 0u) {
        t82r = static_cast<std::uint32_t>(t82a >> t82c);
        batch_set_shr_flags(state, t82a, t82c, t82r, 32u);
            state.regs[2] = t82r;
        }
    // 0x00927808: 81e2fcffff3f AND
        t83a = state.regs[2];
        t83b = 0x3ffffffcu;
        t83r = (t83a & t83b) & 0xffffffffu;
        batch_set_logic_flags(state, t83r, 32u);
        state.regs[2] = t83r;
    // 0x0092780e: 03d0 ADD
        t84a = state.regs[2];
        t84b = state.regs[0];
        t84r = static_cast<std::uint32_t>(t84a + t84b) & 0xffffffffu;
        batch_set_add_flags(state, t84a, t84b, t84r, 32u);
        state.regs[2] = t84r;
    // 0x00927810: 899568040000 MOV
        batch_guest_pc = 0x00927810u;
        t85 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000468u), t85)) return BatchLiftStatus::invalid_memory;
    // 0x00927816: 8b442414 MOV
    L_00927816:
        batch_guest_pc = 0x00927816u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t86)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t86;
    // 0x0092781a: 85c0 TEST
        t87a = state.regs[0];
        t87b = state.regs[0];
        t87r = (t87a & t87b) & 0xffffffffu;
        batch_set_logic_flags(state, t87r, 32u);
    // 0x0092781c: 0f851effffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927740;
    // 0x00927822: 8b4c2410 MOV
        batch_guest_pc = 0x00927822u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t89;
    // 0x00927826: 8bc1 MOV
    L_00927826:
        t90 = state.regs[1];
        state.regs[0] = t90;
    // 0x00927828: 83c104 ADD
        t91a = state.regs[1];
        t91b = 0x00000004u;
        t91r = static_cast<std::uint32_t>(t91a + t91b) & 0xffffffffu;
        batch_set_add_flags(state, t91a, t91b, t91r, 32u);
        state.regs[1] = t91r;
    // 0x0092782b: 894c2410 MOV
        batch_guest_pc = 0x0092782bu;
        t92 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t92)) return BatchLiftStatus::invalid_memory;
    // 0x0092782f: 3b442418 CMP
        batch_guest_pc = 0x0092782fu;
        t93a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t93b)) return BatchLiftStatus::invalid_memory;
        t93r = static_cast<std::uint32_t>(t93a - t93b) & 0xffffffffu;
        batch_set_sub_flags(state, t93a, t93b, t93r, 32u);
    // 0x00927833: 0f85edfeffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927726;
    // 0x00927839: 836504fe AND
        batch_guest_pc = 0x00927839u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t95a)) return BatchLiftStatus::invalid_memory;
        t95b = 0xfffffffeu;
        t95r = (t95a & t95b) & 0xffffffffu;
        batch_set_logic_flags(state, t95r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t95r)) return BatchLiftStatus::invalid_memory;
    // 0x0092783d: 5f POP
        batch_guest_pc = 0x0092783du;
        if (!memory.load32(state.regs[4], t96a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t96a;
    // 0x0092783e: 5e POP
        batch_guest_pc = 0x0092783eu;
        if (!memory.load32(state.regs[4], t97a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t97a;
    // 0x0092783f: 5b POP
        batch_guest_pc = 0x0092783fu;
        if (!memory.load32(state.regs[4], t98a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t98a;
    // 0x00927840: 5d POP
        batch_guest_pc = 0x00927840u;
        if (!memory.load32(state.regs[4], t99a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t99a;
    // 0x00927841: 83c40c ADD
        t100a = state.regs[4];
        t100b = 0x0000000cu;
        t100r = static_cast<std::uint32_t>(t100a + t100b) & 0xffffffffu;
        batch_set_add_flags(state, t100a, t100b, t100r, 32u);
        state.regs[4] = t100r;
    // 0x00927844: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00927845: 6a00 PUSH
    L_00927845:
        batch_guest_pc = 0x00927845u;
        t102a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t102a)) return BatchLiftStatus::invalid_memory;
    // 0x00927847: 6a00 PUSH
        batch_guest_pc = 0x00927847u;
        t103a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
    // 0x00927849: 6a00 PUSH
        batch_guest_pc = 0x00927849u;
        t104a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t104a)) return BatchLiftStatus::invalid_memory;
    // 0x0092784b: 6a01 PUSH
        batch_guest_pc = 0x0092784bu;
        t105a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
    // 0x0092784d: 6a00 PUSH
        batch_guest_pc = 0x0092784du;
        t106a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t106a)) return BatchLiftStatus::invalid_memory;
    // 0x0092784f: 6a00 PUSH
        batch_guest_pc = 0x0092784fu;
        t107a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
    // 0x00927851: e87afcffff CALL
        if (!batch_guest_call32(memory, state, 0x009274d0u, 0x00927856u)) return BatchLiftStatus::invalid_memory;
        t108_call_status = spore_lift_009274d0(memory, state);
        if (t108_call_status != BatchLiftStatus::returned) return t108_call_status;
        if (state.eip != 0x00927856u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927856: 5d POP
        batch_guest_pc = 0x00927856u;
        if (!memory.load32(state.regs[4], t109a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t109a;
    // 0x00927857: 83c40c ADD
        t110a = state.regs[4];
        t110b = 0x0000000cu;
        t110r = static_cast<std::uint32_t>(t110a + t110b) & 0xffffffffu;
        batch_set_add_flags(state, t110a, t110b, t110r, 32u);
        state.regs[4] = t110r;
    // 0x0092785a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
