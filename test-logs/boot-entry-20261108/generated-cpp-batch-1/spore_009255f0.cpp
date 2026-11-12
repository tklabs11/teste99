#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_007611f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009256e2(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009255f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009255f0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    BatchLiftStatus t37_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t38a = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56 = 0;
    BatchLiftStatus t57_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t58a = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t64a = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t74a = 0, t74c = 0, t74r = 0;
    std::uint32_t t75a = 0, t75b = 0, t75r = 0;
    std::uint32_t t77a = 0;
    std::uint32_t t78a = 0, t78b = 0, t78r = 0;
    std::uint32_t t80a = 0;
    std::uint32_t t81a = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83a = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85a = 0;
    std::uint32_t t86a = 0;
    BatchLiftStatus t87_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t88a = 0, t88b = 0, t88r = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;
    std::uint32_t t95a = 0;
    std::uint32_t t96a = 0;
    std::uint32_t t97a = 0;
    BatchLiftStatus t98_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t99 = 0;
    std::uint32_t t100a = 0, t100b = 0, t100r = 0;
    std::uint32_t t101a = 0, t101b = 0, t101r = 0;
    std::uint32_t t103a = 0, t103b = 0, t103r = 0;
    std::uint32_t t105a = 0;
    BatchLiftStatus t106_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t107a = 0, t107b = 0, t107r = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0, t111c = 0, t111r = 0;
    std::uint32_t t112 = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116a = 0;
    std::uint32_t t117a = 0;
    std::uint32_t t118a = 0;

    // 0x009255f0: 83ec0c SUB
        t0a = state.regs[4];
        t0b = 0x0000000cu;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x009255f3: 53 PUSH
        batch_guest_pc = 0x009255f3u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009255f4: 55 PUSH
        batch_guest_pc = 0x009255f4u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009255f5: 56 PUSH
        batch_guest_pc = 0x009255f5u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009255f6: 57 PUSH
        batch_guest_pc = 0x009255f6u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009255f7: 8be9 MOV
        t5 = state.regs[1];
        state.regs[5] = t5;
    // 0x009255f9: 68fcdf4301 PUSH
        batch_guest_pc = 0x009255f9u;
        t6a = 0x0143dffcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x009255fe: 896c2414 MOV
        batch_guest_pc = 0x009255feu;
        t7 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00925602: e8a9cbffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00925607u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_009221b0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00925607u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925607: 8b7d34 MOV
        batch_guest_pc = 0x00925607u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000034u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t9;
    // 0x0092560a: 8b37 MOV
        batch_guest_pc = 0x0092560au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t10;
    // 0x0092560c: 85f6 TEST
        t11a = state.regs[6];
        t11b = state.regs[6];
        t11r = (t11a & t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
    // 0x0092560e: 7511 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925621;
    // 0x00925610: 83c704 ADD
        t13a = state.regs[7];
        t13b = 0x00000004u;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[7] = t13r;
    // 0x00925613: 3937 CMP
        batch_guest_pc = 0x00925613u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t14a)) return BatchLiftStatus::invalid_memory;
        t14b = state.regs[6];
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
    // 0x00925615: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092561f;
    // 0x00925617: 83c704 ADD
    L_00925617:
        t16a = state.regs[7];
        t16b = 0x00000004u;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[7] = t16r;
    // 0x0092561a: 833f00 CMP
        batch_guest_pc = 0x0092561au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = 0x00000000u;
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x0092561d: 74f8 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925617;
    // 0x0092561f: 8b37 MOV
    L_0092561f:
        batch_guest_pc = 0x0092561fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t19;
    // 0x00925621: 8b4538 MOV
    L_00925621:
        batch_guest_pc = 0x00925621u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000038u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t20;
    // 0x00925624: 8b4d34 MOV
        batch_guest_pc = 0x00925624u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000034u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t21;
    // 0x00925627: 8b0481 MOV
        batch_guest_pc = 0x00925627u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 4u + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x0092562a: 8d5d30 LEA
        t23 = static_cast<std::uint32_t>(state.regs[5] + 0x00000030u);
        state.regs[3] = t23;
    // 0x0092562d: 89442414 MOV
        batch_guest_pc = 0x0092562du;
        t24 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00925631: 3bf0 CMP
        t25a = state.regs[6];
        t25b = state.regs[0];
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
    // 0x00925633: 7442 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925677;
    // 0x00925635: 8b6e0c MOV
    L_00925635:
        batch_guest_pc = 0x00925635u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t27;
    // 0x00925638: 85ed TEST
        t28a = state.regs[5];
        t28b = state.regs[5];
        t28r = (t28a & t28b) & 0xffffffffu;
        batch_set_logic_flags(state, t28r, 32u);
    // 0x0092563a: 7422 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092565e;
    // 0x0092563c: 8b159c8e6601 MOV
        batch_guest_pc = 0x0092563cu;
        if (!memory.load32(0x01668e9cu, t30)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t30;
    // 0x00925642: 8b4a10 MOV
        batch_guest_pc = 0x00925642u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000010u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t31;
    // 0x00925645: 85c9 TEST
        t32a = state.regs[1];
        t32b = state.regs[1];
        t32r = (t32a & t32b) & 0xffffffffu;
        batch_set_logic_flags(state, t32r, 32u);
    // 0x00925647: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925651;
    // 0x00925649: 8b01 MOV
        batch_guest_pc = 0x00925649u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t34;
    // 0x0092564b: 8b501c MOV
        batch_guest_pc = 0x0092564bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t35;
    // 0x0092564e: 55 PUSH
        batch_guest_pc = 0x0092564eu;
        t36a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x0092564f: ffd2 CALL
        t37_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00925651u);
        if (t37_call_status != BatchLiftStatus::returned) return t37_call_status;
    // 0x00925651: 55 PUSH
    L_00925651:
        batch_guest_pc = 0x00925651u;
        t38a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x00925652: e8291d6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00925657u)) return BatchLiftStatus::invalid_memory;
        t39_call_status = spore_lift_00f47380(memory, state);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
        if (state.eip != 0x00925657u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925657: 8b442418 MOV
        batch_guest_pc = 0x00925657u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t40;
    // 0x0092565b: 83c404 ADD
        t41a = state.regs[4];
        t41b = 0x00000004u;
        t41r = static_cast<std::uint32_t>(t41a + t41b) & 0xffffffffu;
        batch_set_add_flags(state, t41a, t41b, t41r, 32u);
        state.regs[4] = t41r;
    // 0x0092565e: 8b7610 MOV
    L_0092565e:
        batch_guest_pc = 0x0092565eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t42;
    // 0x00925661: 85f6 TEST
        t43a = state.regs[6];
        t43b = state.regs[6];
        t43r = (t43a & t43b) & 0xffffffffu;
        batch_set_logic_flags(state, t43r, 32u);
    // 0x00925663: 750a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092566f;
    // 0x00925665: 8b7704 MOV
    L_00925665:
        batch_guest_pc = 0x00925665u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t45;
    // 0x00925668: 83c704 ADD
        t46a = state.regs[7];
        t46b = 0x00000004u;
        t46r = static_cast<std::uint32_t>(t46a + t46b) & 0xffffffffu;
        batch_set_add_flags(state, t46a, t46b, t46r, 32u);
        state.regs[7] = t46r;
    // 0x0092566b: 85f6 TEST
        t47a = state.regs[6];
        t47b = state.regs[6];
        t47r = (t47a & t47b) & 0xffffffffu;
        batch_set_logic_flags(state, t47r, 32u);
    // 0x0092566d: 74f6 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925665;
    // 0x0092566f: 3bf0 CMP
    L_0092566f:
        t49a = state.regs[6];
        t49b = state.regs[0];
        t49r = static_cast<std::uint32_t>(t49a - t49b) & 0xffffffffu;
        batch_set_sub_flags(state, t49a, t49b, t49r, 32u);
    // 0x00925671: 75c2 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925635;
    // 0x00925673: 8b6c2410 MOV
        batch_guest_pc = 0x00925673u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t51;
    // 0x00925677: 8b4308 MOV
    L_00925677:
        batch_guest_pc = 0x00925677u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000008u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t52;
    // 0x0092567a: 8b4b04 MOV
        batch_guest_pc = 0x0092567au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t53;
    // 0x0092567d: 50 PUSH
        batch_guest_pc = 0x0092567du;
        t54a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x0092567e: 51 PUSH
        batch_guest_pc = 0x0092567eu;
        t55a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x0092567f: 8bcb MOV
        t56 = state.regs[3];
        state.regs[1] = t56;
    // 0x00925681: e86abbe3ff CALL
        if (!batch_guest_call32(memory, state, 0x007611f0u, 0x00925686u)) return BatchLiftStatus::invalid_memory;
        t57_call_status = spore_lift_007611f0(memory, state);
        if (t57_call_status != BatchLiftStatus::returned) return t57_call_status;
        if (state.eip != 0x00925686u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925686: 5f POP
        batch_guest_pc = 0x00925686u;
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t58a;
    // 0x00925687: c7430c00000000 MOV
        batch_guest_pc = 0x00925687u;
        t59 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x0000000cu), t59)) return BatchLiftStatus::invalid_memory;
    // 0x0092568e: 5e POP
        batch_guest_pc = 0x0092568eu;
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t60a;
    // 0x0092568f: c6455000 MOV
        batch_guest_pc = 0x0092568fu;
        t61 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000050u), t61)) return BatchLiftStatus::invalid_memory;
    // 0x00925693: 8bcd MOV
        t62 = state.regs[5];
        state.regs[1] = t62;
    // 0x00925695: 5d POP
        batch_guest_pc = 0x00925695u;
        if (!memory.load32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t63a;
    // 0x00925696: 5b POP
        batch_guest_pc = 0x00925696u;
        if (!memory.load32(state.regs[4], t64a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t64a;
    // 0x00925697: 83c40c ADD
        t65a = state.regs[4];
        t65b = 0x0000000cu;
        t65r = static_cast<std::uint32_t>(t65a + t65b) & 0xffffffffu;
        batch_set_add_flags(state, t65a, t65b, t65r, 32u);
        state.regs[4] = t65r;
    // 0x0092569a: e9d1cbffff JMP
        state.eip = 0x00922270u;
        return spore_lift_00922270(memory, state);
    // 0x0092569f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009256a0: 53 PUSH
        batch_guest_pc = 0x009256a0u;
        t68a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
    // 0x009256a1: 8b5c2408 MOV
        batch_guest_pc = 0x009256a1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t69;
    // 0x009256a5: 56 PUSH
        batch_guest_pc = 0x009256a5u;
        t70a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t70a)) return BatchLiftStatus::invalid_memory;
    // 0x009256a6: 8bf1 MOV
        t71 = state.regs[1];
        state.regs[6] = t71;
    // 0x009256a8: 8b4608 MOV
        batch_guest_pc = 0x009256a8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t72)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t72;
    // 0x009256ab: 2b06 SUB
        batch_guest_pc = 0x009256abu;
        t73a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t73b)) return BatchLiftStatus::invalid_memory;
        t73r = static_cast<std::uint32_t>(t73a - t73b) & 0xffffffffu;
        batch_set_sub_flags(state, t73a, t73b, t73r, 32u);
        state.regs[0] = t73r;
    // 0x009256ad: c1f802 SAR
        t74a = state.regs[0];
        t74c = 2u;
        if (t74c != 0u) {
        t74r = (t74a >> t74c) | ((t74a & 0x80000000u) ? (0xffffffffu << (32u - t74c)) : 0u);
        batch_set_sar_flags(state, t74a, t74c, t74r, 32u);
            state.regs[0] = t74r;
        }
    // 0x009256b0: 3bd8 CMP
        t75a = state.regs[3];
        t75b = state.regs[0];
        t75r = static_cast<std::uint32_t>(t75a - t75b) & 0xffffffffu;
        batch_set_sub_flags(state, t75a, t75b, t75r, 32u);
    // 0x009256b2: 766c JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00925720;
    // 0x009256b4: 57 PUSH
        batch_guest_pc = 0x009256b4u;
        t77a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t77a)) return BatchLiftStatus::invalid_memory;
    // 0x009256b5: 85db TEST
        t78a = state.regs[3];
        t78b = state.regs[3];
        t78r = (t78a & t78b) & 0xffffffffu;
        batch_set_logic_flags(state, t78r, 32u);
    // 0x009256b7: 7427 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009256e0;
    // 0x009256b9: 68d1000000 PUSH
        batch_guest_pc = 0x009256b9u;
        t80a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
    // 0x009256be: 6838bb3e01 PUSH
        batch_guest_pc = 0x009256beu;
        t81a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t81a)) return BatchLiftStatus::invalid_memory;
    // 0x009256c3: 6a00 PUSH
        batch_guest_pc = 0x009256c3u;
        t82a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
    // 0x009256c5: 6a00 PUSH
        batch_guest_pc = 0x009256c5u;
        t83a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t83a)) return BatchLiftStatus::invalid_memory;
    // 0x009256c7: 8d0c9d00000000 LEA
        t84 = static_cast<std::uint32_t>(state.regs[3] * 4u + 0x00000000u);
        state.regs[1] = t84;
    // 0x009256ce: 6800e04301 PUSH
        batch_guest_pc = 0x009256ceu;
        t85a = 0x0143e000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t85a)) return BatchLiftStatus::invalid_memory;
    // 0x009256d3: 51 PUSH
        batch_guest_pc = 0x009256d3u;
        t86a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t86a)) return BatchLiftStatus::invalid_memory;
    // 0x009256d4: e8c71c6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x009256d9u)) return BatchLiftStatus::invalid_memory;
        t87_call_status = spore_lift_00f473a0(memory, state);
        if (t87_call_status != BatchLiftStatus::returned) return t87_call_status;
        if (state.eip != 0x009256d9u) return BatchLiftStatus::invalid_control_flow;
    // 0x009256d9: 83c418 ADD
        t88a = state.regs[4];
        t88b = 0x00000018u;
        t88r = static_cast<std::uint32_t>(t88a + t88b) & 0xffffffffu;
        batch_set_add_flags(state, t88a, t88b, t88r, 32u);
        state.regs[4] = t88r;
    // 0x009256dc: 8bf8 MOV
        t89 = state.regs[0];
        state.regs[7] = t89;
    // 0x009256de: eb02 JMP
        goto L_009256e2;
    // 0x009256e0: 33ff XOR
    L_009256e0:
        t91a = state.regs[7];
        t91b = state.regs[7];
        t91r = (t91a ^ t91b) & 0xffffffffu;
        batch_set_logic_flags(state, t91r, 32u);
        state.regs[7] = t91r;
    // 0x009256e2: 8b06 MOV
    L_009256e2:
        batch_guest_pc = 0x009256e2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t92)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t92;
    // 0x009256e4: 8b5604 MOV
        batch_guest_pc = 0x009256e4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t93)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t93;
    // 0x009256e7: 2bd0 SUB
        t94a = state.regs[2];
        t94b = state.regs[0];
        t94r = static_cast<std::uint32_t>(t94a - t94b) & 0xffffffffu;
        batch_set_sub_flags(state, t94a, t94b, t94r, 32u);
        state.regs[2] = t94r;
    // 0x009256e9: 52 PUSH
        batch_guest_pc = 0x009256e9u;
        t95a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t95a)) return BatchLiftStatus::invalid_memory;
    // 0x009256ea: 50 PUSH
        batch_guest_pc = 0x009256eau;
        t96a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t96a)) return BatchLiftStatus::invalid_memory;
    // 0x009256eb: 57 PUSH
        batch_guest_pc = 0x009256ebu;
        t97a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t97a)) return BatchLiftStatus::invalid_memory;
    // 0x009256ec: e853b08b00 CALL
        t98_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x009256f1u);
        if (t98_call_status != BatchLiftStatus::returned) return t98_call_status;
        if (state.eip != 0x009256f1u) return BatchLiftStatus::invalid_control_flow;
    // 0x009256f1: 8b06 MOV
        batch_guest_pc = 0x009256f1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t99)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t99;
    // 0x009256f3: 83c40c ADD
        t100a = state.regs[4];
        t100b = 0x0000000cu;
        t100r = static_cast<std::uint32_t>(t100a + t100b) & 0xffffffffu;
        batch_set_add_flags(state, t100a, t100b, t100r, 32u);
        state.regs[4] = t100r;
    // 0x009256f6: 85c0 TEST
        t101a = state.regs[0];
        t101b = state.regs[0];
        t101r = (t101a & t101b) & 0xffffffffu;
        batch_set_logic_flags(state, t101r, 32u);
    // 0x009256f8: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925709;
    // 0x009256fa: 8378fc00 CMP
        batch_guest_pc = 0x009256fau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t103a)) return BatchLiftStatus::invalid_memory;
        t103b = 0x00000000u;
        t103r = static_cast<std::uint32_t>(t103a - t103b) & 0xffffffffu;
        batch_set_sub_flags(state, t103a, t103b, t103r, 32u);
    // 0x009256fe: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925709;
    // 0x00925700: 50 PUSH
        batch_guest_pc = 0x00925700u;
        t105a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
    // 0x00925701: e87a1c6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00925706u)) return BatchLiftStatus::invalid_memory;
        t106_call_status = spore_lift_00f47380(memory, state);
        if (t106_call_status != BatchLiftStatus::returned) return t106_call_status;
        if (state.eip != 0x00925706u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925706: 83c404 ADD
        t107a = state.regs[4];
        t107b = 0x00000004u;
        t107r = static_cast<std::uint32_t>(t107a + t107b) & 0xffffffffu;
        batch_set_add_flags(state, t107a, t107b, t107r, 32u);
        state.regs[4] = t107r;
    // 0x00925709: 8b4604 MOV
    L_00925709:
        batch_guest_pc = 0x00925709u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t108)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t108;
    // 0x0092570c: 2b06 SUB
        batch_guest_pc = 0x0092570cu;
        t109a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t109b)) return BatchLiftStatus::invalid_memory;
        t109r = static_cast<std::uint32_t>(t109a - t109b) & 0xffffffffu;
        batch_set_sub_flags(state, t109a, t109b, t109r, 32u);
        state.regs[0] = t109r;
    // 0x0092570e: 8d0c9f LEA
        t110 = static_cast<std::uint32_t>(state.regs[7] + state.regs[3] * 4u + 0x00000000u);
        state.regs[1] = t110;
    // 0x00925711: c1f802 SAR
        t111a = state.regs[0];
        t111c = 2u;
        if (t111c != 0u) {
        t111r = (t111a >> t111c) | ((t111a & 0x80000000u) ? (0xffffffffu << (32u - t111c)) : 0u);
        batch_set_sar_flags(state, t111a, t111c, t111r, 32u);
            state.regs[0] = t111r;
        }
    // 0x00925714: 8d0487 LEA
        t112 = static_cast<std::uint32_t>(state.regs[7] + state.regs[0] * 4u + 0x00000000u);
        state.regs[0] = t112;
    // 0x00925717: 893e MOV
        batch_guest_pc = 0x00925717u;
        t113 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t113)) return BatchLiftStatus::invalid_memory;
    // 0x00925719: 894604 MOV
        batch_guest_pc = 0x00925719u;
        t114 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t114)) return BatchLiftStatus::invalid_memory;
    // 0x0092571c: 894e08 MOV
        batch_guest_pc = 0x0092571cu;
        t115 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t115)) return BatchLiftStatus::invalid_memory;
    // 0x0092571f: 5f POP
        batch_guest_pc = 0x0092571fu;
        if (!memory.load32(state.regs[4], t116a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t116a;
    // 0x00925720: 5e POP
    L_00925720:
        batch_guest_pc = 0x00925720u;
        if (!memory.load32(state.regs[4], t117a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t117a;
    // 0x00925721: 5b POP
        batch_guest_pc = 0x00925721u;
        if (!memory.load32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t118a;
    // 0x00925722: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
