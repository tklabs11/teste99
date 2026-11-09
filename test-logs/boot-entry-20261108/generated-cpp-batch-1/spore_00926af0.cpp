#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00926b3d(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926bbf(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00926af0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926af0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t75a = 0, t75b = 0, t75r = 0;
    std::uint32_t t76a = 0;
    std::uint32_t t77a = 0;
    std::uint32_t t78a = 0;
    std::uint32_t t79a = 0;
    std::uint32_t t80a = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t97a = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100a = 0;
    std::uint32_t t101a = 0;
    std::uint32_t t102a = 0;
    std::uint32_t t103a = 0;

    // 0x00926af0: 51 PUSH
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00926af1: 807c241c00 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t1a)) return BatchLiftStatus::invalid_memory;
        t1b = 0x00000000u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0x000000ffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 8u);
    // 0x00926af6: 8b542408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x00926afa: 53 PUSH
        t3a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00926afb: 55 PUSH
        t4a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00926afc: 8b6c2418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t5;
    // 0x00926b00: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00926b01: 57 PUSH
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00926b02: 894c2410 MOV
        t8 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00926b06: 7420 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926b28;
    // 0x00926b08: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x00926b0b: 8b742428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t11;
    // 0x00926b0f: 8b7c2424 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t12;
    // 0x00926b13: 25f8ffff7f AND
        t13a = state.regs[0];
        t13b = 0x7ffffff8u;
        t13r = (t13a & t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
        state.regs[0] = t13r;
    // 0x00926b18: 2bc5 SUB
        t14a = state.regs[0];
        t14b = state.regs[5];
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
        state.regs[0] = t14r;
    // 0x00926b1a: 03c2 ADD
        t15a = state.regs[0];
        t15b = state.regs[2];
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        state.regs[0] = t15r;
    // 0x00926b1c: 8d443008 LEA
        t16 = static_cast<std::uint32_t>(state.regs[0] + state.regs[6] * 1u + 0x00000008u);
        state.regs[0] = t16;
    // 0x00926b20: f7df NEG
        t17a = state.regs[7];
        t17r = static_cast<std::uint32_t>(0u - t17a) & 0xffffffffu;
        batch_set_neg_flags(state, t17a, t17r, 32u);
        state.regs[7] = t17r;
    // 0x00926b22: 23c7 AND
        t18a = state.regs[0];
        t18b = state.regs[7];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
        state.regs[0] = t18r;
    // 0x00926b24: 2bc6 SUB
        t19a = state.regs[0];
        t19b = state.regs[6];
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
        state.regs[0] = t19r;
    // 0x00926b26: eb15 JMP
        goto L_00926b3d;
    // 0x00926b28: 8b742424 MOV
    L_00926b28:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t21;
    // 0x00926b2c: 8b7c2428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t22;
    // 0x00926b30: 8d0432 LEA
        t23 = static_cast<std::uint32_t>(state.regs[2] + state.regs[6] * 1u + 0x00000000u);
        state.regs[0] = t23;
    // 0x00926b33: 8d443807 LEA
        t24 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 1u + 0x00000007u);
        state.regs[0] = t24;
    // 0x00926b37: f7de NEG
        t25a = state.regs[6];
        t25r = static_cast<std::uint32_t>(0u - t25a) & 0xffffffffu;
        batch_set_neg_flags(state, t25a, t25r, 32u);
        state.regs[6] = t25r;
    // 0x00926b39: 23c6 AND
        t26a = state.regs[0];
        t26b = state.regs[6];
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[0] = t26r;
    // 0x00926b3b: 2bc7 SUB
        t27a = state.regs[0];
        t27b = state.regs[7];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
        state.regs[0] = t27r;
    // 0x00926b3d: 8b7a08 MOV
    L_00926b3d:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t28;
    // 0x00926b40: 8b5a0c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t29;
    // 0x00926b43: 895f0c MOV
        t30 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00926b46: 8b7a0c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t31;
    // 0x00926b49: 8b5a08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t32;
    // 0x00926b4c: 83e808 SUB
        t33a = state.regs[0];
        t33b = 0x00000008u;
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
        state.regs[0] = t33r;
    // 0x00926b4f: 895f08 MOV
        t34 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00926b52: 8b7c241c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t35;
    // 0x00926b56: 8bf0 MOV
        t36 = state.regs[0];
        state.regs[6] = t36;
    // 0x00926b58: 2bf2 SUB
        t37a = state.regs[6];
        t37b = state.regs[2];
        t37r = static_cast<std::uint32_t>(t37a - t37b) & 0xffffffffu;
        batch_set_sub_flags(state, t37a, t37b, t37r, 32u);
        state.regs[6] = t37r;
    // 0x00926b5a: 03f5 ADD
        t38a = state.regs[6];
        t38b = state.regs[5];
        t38r = static_cast<std::uint32_t>(t38a + t38b) & 0xffffffffu;
        batch_set_add_flags(state, t38a, t38b, t38r, 32u);
        state.regs[6] = t38r;
    // 0x00926b5c: 8bdf MOV
        t39 = state.regs[7];
        state.regs[3] = t39;
    // 0x00926b5e: 2bde SUB
        t40a = state.regs[3];
        t40b = state.regs[6];
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0xffffffffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 32u);
        state.regs[3] = t40r;
    // 0x00926b60: 83fb10 CMP
        t41a = state.regs[3];
        t41b = 0x00000010u;
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
    // 0x00926b63: 7307 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926b6c;
    // 0x00926b65: 834c3a0401 OR
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + state.regs[7] * 1u + 0x00000004u), t43a)) return BatchLiftStatus::invalid_memory;
        t43b = 0x00000001u;
        t43r = (t43a | t43b) & 0xffffffffu;
        batch_set_logic_flags(state, t43r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + state.regs[7] * 1u + 0x00000004u), t43r)) return BatchLiftStatus::invalid_memory;
    // 0x00926b6a: eb53 JMP
        goto L_00926bbf;
    // 0x00926b6c: 83c130 ADD
    L_00926b6c:
        t45a = state.regs[1];
        t45b = 0x00000030u;
        t45r = static_cast<std::uint32_t>(t45a + t45b) & 0xffffffffu;
        batch_set_add_flags(state, t45a, t45b, t45r, 32u);
        state.regs[1] = t45r;
    // 0x00926b6f: 8b490c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t46;
    // 0x00926b72: 894c242c MOV
        t47 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t47)) return BatchLiftStatus::invalid_memory;
    // 0x00926b76: 8b4c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t48;
    // 0x00926b7a: 83c130 ADD
        t49a = state.regs[1];
        t49b = 0x00000030u;
        t49r = static_cast<std::uint32_t>(t49a + t49b) & 0xffffffffu;
        batch_set_add_flags(state, t49a, t49b, t49r, 32u);
        state.regs[1] = t49r;
    // 0x00926b7d: 894c1608 MOV
        t50 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + state.regs[2] * 1u + 0x00000008u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00926b81: 8b4c242c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t51;
    // 0x00926b85: 8d3c16 LEA
        t52 = static_cast<std::uint32_t>(state.regs[6] + state.regs[2] * 1u + 0x00000000u);
        state.regs[7] = t52;
    // 0x00926b88: 894f0c MOV
        t53 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00926b8b: 8b4c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t54;
    // 0x00926b8f: 83c130 ADD
        t55a = state.regs[1];
        t55b = 0x00000030u;
        t55r = static_cast<std::uint32_t>(t55a + t55b) & 0xffffffffu;
        batch_set_add_flags(state, t55a, t55b, t55r, 32u);
        state.regs[1] = t55r;
    // 0x00926b92: 89790c MOV
        t56 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t56)) return BatchLiftStatus::invalid_memory;
    // 0x00926b95: 8b4c242c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t57;
    // 0x00926b99: 897908 MOV
        t58 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x00926b9c: 8b4c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t59)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t59;
    // 0x00926ba0: 81fe00020000 CMP
        t60a = state.regs[6];
        t60b = 0x00000200u;
        t60r = static_cast<std::uint32_t>(t60a - t60b) & 0xffffffffu;
        batch_set_sub_flags(state, t60a, t60b, t60r, 32u);
    // 0x00926ba6: 7306 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926bae;
    // 0x00926ba8: 89b944040000 MOV
        t62 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000444u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x00926bae: 83ce01 OR
    L_00926bae:
        t63a = state.regs[6];
        t63b = 0x00000001u;
        t63r = (t63a | t63b) & 0xffffffffu;
        batch_set_logic_flags(state, t63r, 32u);
        state.regs[6] = t63r;
    // 0x00926bb1: 897204 MOV
        t64 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t64)) return BatchLiftStatus::invalid_memory;
    // 0x00926bb4: 8bf3 MOV
        t65 = state.regs[3];
        state.regs[6] = t65;
    // 0x00926bb6: 83ce01 OR
        t66a = state.regs[6];
        t66b = 0x00000001u;
        t66r = (t66a | t66b) & 0xffffffffu;
        batch_set_logic_flags(state, t66r, 32u);
        state.regs[6] = t66r;
    // 0x00926bb9: 897704 MOV
        t67 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t67)) return BatchLiftStatus::invalid_memory;
    // 0x00926bbc: 891c1f MOV
        t68 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + state.regs[3] * 1u + 0x00000000u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x00926bbf: 8b7a04 MOV
    L_00926bbf:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t69;
    // 0x00926bc2: 81e7f8ffff7f AND
        t70a = state.regs[7];
        t70b = 0x7ffffff8u;
        t70r = (t70a & t70b) & 0xffffffffu;
        batch_set_logic_flags(state, t70r, 32u);
        state.regs[7] = t70r;
    // 0x00926bc8: 8bf7 MOV
        t71 = state.regs[7];
        state.regs[6] = t71;
    // 0x00926bca: 2bf5 SUB
        t72a = state.regs[6];
        t72b = state.regs[5];
        t72r = static_cast<std::uint32_t>(t72a - t72b) & 0xffffffffu;
        batch_set_sub_flags(state, t72a, t72b, t72r, 32u);
        state.regs[6] = t72r;
    // 0x00926bcc: 83fe10 CMP
        t73a = state.regs[6];
        t73b = 0x00000010u;
        t73r = static_cast<std::uint32_t>(t73a - t73b) & 0xffffffffu;
        batch_set_sub_flags(state, t73a, t73b, t73r, 32u);
    // 0x00926bcf: 730d JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926bde;
    // 0x00926bd1: 834c170401 OR
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + state.regs[2] * 1u + 0x00000004u), t75a)) return BatchLiftStatus::invalid_memory;
        t75b = 0x00000001u;
        t75r = (t75a | t75b) & 0xffffffffu;
        batch_set_logic_flags(state, t75r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + state.regs[2] * 1u + 0x00000004u), t75r)) return BatchLiftStatus::invalid_memory;
    // 0x00926bd6: 5f POP
        if (!memory.load32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t76a;
    // 0x00926bd7: 5e POP
        if (!memory.load32(state.regs[4], t77a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t77a;
    // 0x00926bd8: 5d POP
        if (!memory.load32(state.regs[4], t78a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t78a;
    // 0x00926bd9: 5b POP
        if (!memory.load32(state.regs[4], t79a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t79a;
    // 0x00926bda: 59 POP
        if (!memory.load32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t80a;
    // 0x00926bdb: c21800 RET
        if (!batch_guest_return32(memory, state, 24u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00926bde: 8d7930 LEA
    L_00926bde:
        t82 = static_cast<std::uint32_t>(state.regs[1] + 0x00000030u);
        state.regs[7] = t82;
    // 0x00926be1: 8b4f0c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t83;
    // 0x00926be4: 897a08 MOV
        t84 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t84)) return BatchLiftStatus::invalid_memory;
    // 0x00926be7: 894a0c MOV
        t85 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t85)) return BatchLiftStatus::invalid_memory;
    // 0x00926bea: 89570c MOV
        t86 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t86)) return BatchLiftStatus::invalid_memory;
    // 0x00926bed: 8d1c16 LEA
        t87 = static_cast<std::uint32_t>(state.regs[6] + state.regs[2] * 1u + 0x00000000u);
        state.regs[3] = t87;
    // 0x00926bf0: 895108 MOV
        t88 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t88)) return BatchLiftStatus::invalid_memory;
    // 0x00926bf3: 81fd00020000 CMP
        t89a = state.regs[5];
        t89b = 0x00000200u;
        t89r = static_cast<std::uint32_t>(t89a - t89b) & 0xffffffffu;
        batch_set_sub_flags(state, t89a, t89b, t89r, 32u);
    // 0x00926bf9: 730a JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926c05;
    // 0x00926bfb: 8b4c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t91)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t91;
    // 0x00926bff: 899144040000 MOV
        t92 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000444u), t92)) return BatchLiftStatus::invalid_memory;
    // 0x00926c05: 896b04 MOV
    L_00926c05:
        t93 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t93)) return BatchLiftStatus::invalid_memory;
    // 0x00926c08: 834c2b0401 OR
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + state.regs[5] * 1u + 0x00000004u), t94a)) return BatchLiftStatus::invalid_memory;
        t94b = 0x00000001u;
        t94r = (t94a | t94b) & 0xffffffffu;
        batch_set_logic_flags(state, t94r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + state.regs[5] * 1u + 0x00000004u), t94r)) return BatchLiftStatus::invalid_memory;
    // 0x00926c0d: 8bce MOV
        t95 = state.regs[6];
        state.regs[1] = t95;
    // 0x00926c0f: 83c901 OR
        t96a = state.regs[1];
        t96b = 0x00000001u;
        t96r = (t96a | t96b) & 0xffffffffu;
        batch_set_logic_flags(state, t96r, 32u);
        state.regs[1] = t96r;
    // 0x00926c12: 5f POP
        if (!memory.load32(state.regs[4], t97a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t97a;
    // 0x00926c13: 894a04 MOV
        t98 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t98)) return BatchLiftStatus::invalid_memory;
    // 0x00926c16: 8933 MOV
        t99 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t99)) return BatchLiftStatus::invalid_memory;
    // 0x00926c18: 5e POP
        if (!memory.load32(state.regs[4], t100a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t100a;
    // 0x00926c19: 5d POP
        if (!memory.load32(state.regs[4], t101a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t101a;
    // 0x00926c1a: 5b POP
        if (!memory.load32(state.regs[4], t102a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t102a;
    // 0x00926c1b: 59 POP
        if (!memory.load32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t103a;
    // 0x00926c1c: c21800 RET
        if (!batch_guest_return32(memory, state, 24u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
