#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0068f5d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0068f7c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690630(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690930(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690f80(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690fcb(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00690f60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00690f60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    BatchLiftStatus t53_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66a = 0;
    std::uint32_t t67a = 0;
    std::uint32_t t68 = 0;
    BatchLiftStatus t69_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    BatchLiftStatus t89_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t90 = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92a = 0, t92c = 0, t92r = 0;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t97a = 0, t97b = 0, t97r = 0;
    std::uint32_t t98a = 0, t98r = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101a = 0;
    std::uint32_t t102a = 0;
    BatchLiftStatus t103_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t104a = 0;
    std::uint32_t t105a = 0;
    std::uint32_t t106a = 0;
    std::uint32_t t107a = 0;

    // 0x00690f60: 51 PUSH
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00690f61: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00690f62: 56 PUSH
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00690f63: 57 PUSH
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00690f64: 8b7c2414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t4;
    // 0x00690f68: 8d4738 LEA
        t5 = static_cast<std::uint32_t>(state.regs[7] + 0x00000038u);
        state.regs[0] = t5;
    // 0x00690f6b: 8bd9 MOV
        t6 = state.regs[1];
        state.regs[3] = t6;
    // 0x00690f6d: 895c240c MOV
        t7 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00690f71: 394004 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t8a)) return BatchLiftStatus::invalid_memory;
        t8b = state.regs[0];
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x00690f74: 0f849c000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00691016;
    // 0x00690f7a: 55 PUSH
        t10a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00690f7b: eb03 JMP
        goto L_00690f80;
    // 0x00690f80: 8b773c MOV
    L_00690f80:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000003cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t12;
    // 0x00690f83: 8b460c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00690f86: 8b4e08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x00690f89: 8b5610 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t15;
    // 0x00690f8c: 8908 MOV
        t16 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00690f8e: 894104 MOV
        t17 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00690f91: 33ed XOR
        t18a = state.regs[5];
        t18b = state.regs[5];
        t18r = (t18a ^ t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
        state.regs[5] = t18r;
    // 0x00690f93: 896e08 MOV
        t19 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00690f96: 896e0c MOV
        t20 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00690f99: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00690f9c: 8b0e MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x00690f9e: 8908 MOV
        t23 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00690fa0: 894104 MOV
        t24 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00690fa3: 892e MOV
        t25 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x00690fa5: 896e04 MOV
        t26 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00690fa8: 8b4248 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000048u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t27;
    // 0x00690fab: 3b4748 CMP
        t28a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000048u), t28b)) return BatchLiftStatus::invalid_memory;
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x00690fae: 7540 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690ff0;
    // 0x00690fb0: 8b4240 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000040u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t30;
    // 0x00690fb3: 8b6a18 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000018u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t31;
    // 0x00690fb6: 8d5a40 LEA
        t32 = static_cast<std::uint32_t>(state.regs[2] + 0x00000040u);
        state.regs[3] = t32;
    // 0x00690fb9: 3bc3 CMP
        t33a = state.regs[0];
        t33b = state.regs[3];
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
    // 0x00690fbb: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690fdc;
    // 0x00690fbd: 8d4900 LEA
        t35 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t35;
    // 0x00690fc0: 85c0 TEST
    L_00690fc0:
        t36a = state.regs[0];
        t36b = state.regs[0];
        t36r = (t36a & t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
    // 0x00690fc2: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690fc9;
    // 0x00690fc4: 8d48f8 LEA
        t38 = static_cast<std::uint32_t>(state.regs[0] + 0xfffffff8u);
        state.regs[1] = t38;
    // 0x00690fc7: eb02 JMP
        goto L_00690fcb;
    // 0x00690fc9: 33c9 XOR
    L_00690fc9:
        t40a = state.regs[1];
        t40b = state.regs[1];
        t40r = (t40a ^ t40b) & 0xffffffffu;
        batch_set_logic_flags(state, t40r, 32u);
        state.regs[1] = t40r;
    // 0x00690fcb: 8b4914 MOV
    L_00690fcb:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000014u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t41;
    // 0x00690fce: 8b4948 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000048u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t42;
    // 0x00690fd1: 8b00 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t43;
    // 0x00690fd3: 3bcd CMP
        t44a = state.regs[1];
        t44b = state.regs[5];
        t44r = static_cast<std::uint32_t>(t44a - t44b) & 0xffffffffu;
        batch_set_sub_flags(state, t44a, t44b, t44r, 32u);
    // 0x00690fd5: 0f4fe9 CMOVG
        t45a = state.regs[1];
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) state.regs[5] = t45a;
    // 0x00690fd8: 3bc3 CMP
        t46a = state.regs[0];
        t46b = state.regs[3];
        t46r = static_cast<std::uint32_t>(t46a - t46b) & 0xffffffffu;
        batch_set_sub_flags(state, t46a, t46b, t46r, 32u);
    // 0x00690fda: 75e4 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690fc0;
    // 0x00690fdc: 3b6a48 CMP
    L_00690fdc:
        t48a = state.regs[5];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000048u), t48b)) return BatchLiftStatus::invalid_memory;
        t48r = static_cast<std::uint32_t>(t48a - t48b) & 0xffffffffu;
        batch_set_sub_flags(state, t48a, t48b, t48r, 32u);
    // 0x00690fdf: 7d0b JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00690fec;
    // 0x00690fe1: 8b4c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t50;
    // 0x00690fe5: 55 PUSH
        t51a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x00690fe6: 52 PUSH
        t52a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x00690fe7: e844f9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00690930u, 0x00690fecu)) return BatchLiftStatus::invalid_memory;
        t53_call_status = spore_lift_00690930(memory, state);
        if (t53_call_status != BatchLiftStatus::returned) return t53_call_status;
        if (state.eip != 0x00690fecu) return BatchLiftStatus::invalid_control_flow;
    // 0x00690fec: 8b5c2410 MOV
    L_00690fec:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t54;
    // 0x00690ff0: 8b93d4010000 MOV
    L_00690ff0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x000001d4u), t55)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t55;
    // 0x00690ff6: 8d83d0010000 LEA
        t56 = static_cast<std::uint32_t>(state.regs[3] + 0x000001d0u);
        state.regs[0] = t56;
    // 0x00690ffc: 8906 MOV
        t57 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t57)) return BatchLiftStatus::invalid_memory;
    // 0x00690ffe: 895604 MOV
        t58 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x00691001: 897004 MOV
        t59 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t59)) return BatchLiftStatus::invalid_memory;
    // 0x00691004: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t60;
    // 0x00691007: 8930 MOV
        t61 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t61)) return BatchLiftStatus::invalid_memory;
    // 0x00691009: 8d4738 LEA
        t62 = static_cast<std::uint32_t>(state.regs[7] + 0x00000038u);
        state.regs[0] = t62;
    // 0x0069100c: 394004 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t63a)) return BatchLiftStatus::invalid_memory;
        t63b = state.regs[0];
        t63r = static_cast<std::uint32_t>(t63a - t63b) & 0xffffffffu;
        batch_set_sub_flags(state, t63a, t63b, t63r, 32u);
    // 0x0069100f: 0f856bffffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690f80;
    // 0x00691015: 5d POP
        if (!memory.load32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t65a;
    // 0x00691016: 6a00 PUSH
    L_00691016:
        t66a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
    // 0x00691018: 57 PUSH
        t67a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
    // 0x00691019: 8bcb MOV
        t68 = state.regs[3];
        state.regs[1] = t68;
    // 0x0069101b: e810f6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00690630u, 0x00691020u)) return BatchLiftStatus::invalid_memory;
        t69_call_status = spore_lift_00690630(memory, state);
        if (t69_call_status != BatchLiftStatus::returned) return t69_call_status;
        if (state.eip != 0x00691020u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691020: 8b4704 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t70;
    // 0x00691023: 8b0f MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t71)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t71;
    // 0x00691025: 8b771c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000001cu), t72)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t72;
    // 0x00691028: 8908 MOV
        t73 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t73)) return BatchLiftStatus::invalid_memory;
    // 0x0069102a: 894104 MOV
        t74 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t74)) return BatchLiftStatus::invalid_memory;
    // 0x0069102d: c7470400000000 MOV
        t75 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x00691034: c70700000000 MOV
        t76 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x0069103a: 8b8b90000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000090u), t77)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t77;
    // 0x00691040: 8d838c000000 LEA
        t78 = static_cast<std::uint32_t>(state.regs[3] + 0x0000008cu);
        state.regs[0] = t78;
    // 0x00691046: 894f04 MOV
        t79 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t79)) return BatchLiftStatus::invalid_memory;
    // 0x00691049: 8907 MOV
        t80 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x0069104b: 897804 MOV
        t81 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t81)) return BatchLiftStatus::invalid_memory;
    // 0x0069104e: 8b5704 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t82)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t82;
    // 0x00691051: 893a MOV
        t83 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t83)) return BatchLiftStatus::invalid_memory;
    // 0x00691053: 807f3400 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000034u), t84a)) return BatchLiftStatus::invalid_memory;
        t84b = 0x00000000u;
        t84r = static_cast<std::uint32_t>(t84a - t84b) & 0x000000ffu;
        batch_set_sub_flags(state, t84a, t84b, t84r, 8u);
    // 0x00691057: c7471c08000000 MOV
        t85 = 0x00000008u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x0000001cu), t85)) return BatchLiftStatus::invalid_memory;
    // 0x0069105e: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069106c;
    // 0x00691060: 8d4b44 LEA
        t87 = static_cast<std::uint32_t>(state.regs[3] + 0x00000044u);
        state.regs[1] = t87;
    // 0x00691063: c6473400 MOV
        t88 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[7] + 0x00000034u), t88)) return BatchLiftStatus::invalid_memory;
    // 0x00691067: e864e5ffff CALL
        if (!batch_guest_call32(memory, state, 0x0068f5d0u, 0x0069106cu)) return BatchLiftStatus::invalid_memory;
        t89_call_status = spore_lift_0068f5d0(memory, state);
        if (t89_call_status != BatchLiftStatus::returned) return t89_call_status;
        if (state.eip != 0x0069106cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069106c: b801000000 MOV
    L_0069106c:
        t90 = 0x00000001u;
        state.regs[0] = t90;
    // 0x00691071: 8bce MOV
        t91 = state.regs[6];
        state.regs[1] = t91;
    // 0x00691073: d3e0 SHL
        t92a = state.regs[0];
        t92c = (state.regs[1] & 0x1fu);
        if (t92c != 0u) {
        t92r = static_cast<std::uint32_t>(t92a << t92c) & 0xffffffffu;
        batch_set_shl_flags(state, t92a, t92c, t92r, 32u);
            state.regs[0] = t92r;
        }
    // 0x00691075: a87c TEST
        t93a = state.regs[0] & 0x000000ffu;
        t93b = 0x0000007cu;
        t93r = (t93a & t93b) & 0x000000ffu;
        batch_set_logic_flags(state, t93r, 8u);
    // 0x00691077: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00691091;
    // 0x00691079: 8d4f4c LEA
        t95 = static_cast<std::uint32_t>(state.regs[7] + 0x0000004cu);
        state.regs[1] = t95;
    // 0x0069107c: 83caff OR
        t96a = state.regs[2];
        t96b = 0xffffffffu;
        t96r = (t96a | t96b) & 0xffffffffu;
        batch_set_logic_flags(state, t96r, 32u);
        state.regs[2] = t96r;
    // 0x0069107f: f00fc111 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t97a)) return BatchLiftStatus::invalid_memory;
        t97b = state.regs[2];
        t97r = static_cast<std::uint32_t>(t97a + t97b) & 0xffffffffu;
        batch_set_add_flags(state, t97a, t97b, t97r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t97r)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t97a;
    // 0x00691083: 4a DEC
        t98a = state.regs[2];
        t98r = static_cast<std::uint32_t>(t98a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t98a, t98r, 32u);
        state.regs[2] = t98r;
    // 0x00691084: 750b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00691091;
    // 0x00691086: 8b4f30 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000030u), t100)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t100;
    // 0x00691089: 57 PUSH
        t101a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t101a)) return BatchLiftStatus::invalid_memory;
    // 0x0069108a: 6a00 PUSH
        t102a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t102a)) return BatchLiftStatus::invalid_memory;
    // 0x0069108c: e82fe7ffff CALL
        if (!batch_guest_call32(memory, state, 0x0068f7c0u, 0x00691091u)) return BatchLiftStatus::invalid_memory;
        t103_call_status = spore_lift_0068f7c0(memory, state);
        if (t103_call_status != BatchLiftStatus::returned) return t103_call_status;
        if (state.eip != 0x00691091u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691091: 5f POP
    L_00691091:
        if (!memory.load32(state.regs[4], t104a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t104a;
    // 0x00691092: 5e POP
        if (!memory.load32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t105a;
    // 0x00691093: 5b POP
        if (!memory.load32(state.regs[4], t106a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t106a;
    // 0x00691094: 59 POP
        if (!memory.load32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t107a;
    // 0x00691095: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
