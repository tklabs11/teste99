#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00926100(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927140(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00928df0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e073e(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009274d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009274d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0, t21r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
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
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87 = 0;
    BatchLiftStatus t88_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t89 = 0;
    std::uint32_t t90a = 0, t90b = 0, t90r = 0;
    std::uint32_t t92a = 0, t92r = 0;
    std::uint32_t t93a = 0;
    BatchLiftStatus t94_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t95a = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t100a = 0, t100b = 0, t100r = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103a = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t105a = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107a = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109a = 0;
    std::uint32_t t110a = 0;
    std::uint32_t t111a = 0;
    std::uint32_t t112 = 0;
    BatchLiftStatus t113_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t114a = 0, t114b = 0, t114r = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t118a = 0, t118b = 0, t118r = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121 = 0;
    std::uint32_t t122a = 0;
    std::uint32_t t123a = 0;
    std::uint32_t t124a = 0;
    BatchLiftStatus t125_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t126 = 0;
    std::uint32_t t127a = 0, t127b = 0, t127r = 0;
    std::uint32_t t128a = 0, t128b = 0, t128r = 0;
    std::uint32_t t130a = 0;
    std::uint32_t t131a = 0;
    std::uint32_t t132 = 0;
    std::uint32_t t133a = 0;

    // 0x009274d0: 53 PUSH
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009274d1: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009274d2: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x009274d4: 33db XOR
        t3a = state.regs[3];
        t3b = state.regs[3];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[3] = t3r;
    // 0x009274d6: 57 PUSH
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009274d7: 381e CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5a)) return BatchLiftStatus::invalid_memory;
        t5b = state.regs[3] & 0x000000ffu;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0x000000ffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 8u);
    // 0x009274d9: 0f857d010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092765c;
    // 0x009274df: c60601 MOV
        t7 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x009274e2: 399ee4040000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000004e4u), t8a)) return BatchLiftStatus::invalid_memory;
        t8b = state.regs[3];
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x009274e8: 7515 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009274ff;
    // 0x009274ea: 8d86e8040000 LEA
        t10 = static_cast<std::uint32_t>(state.regs[6] + 0x000004e8u);
        state.regs[0] = t10;
    // 0x009274f0: 50 PUSH
        t11a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x009274f1: e80aecffff CALL
        if (!batch_guest_call32(memory, state, 0x00926100u, 0x009274f6u)) return BatchLiftStatus::invalid_memory;
        t12_call_status = spore_lift_00926100(memory, state);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x009274f6u) return BatchLiftStatus::invalid_control_flow;
    // 0x009274f6: 83c404 ADD
        t13a = state.regs[4];
        t13b = 0x00000004u;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[4] = t13r;
    // 0x009274f9: 8986e4040000 MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004e4u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x009274ff: 55 PUSH
    L_009274ff:
        t15a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00927500: 8baee4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000004e4u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t16;
    // 0x00927506: 3beb CMP
        t17a = state.regs[5];
        t17b = state.regs[3];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x00927508: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927514;
    // 0x0092750a: 55 PUSH
        t19a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x0092750b: ff15d8c23c01 CALL
        t20_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x00927511u);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x00927511u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927511: ff4518 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t21a)) return BatchLiftStatus::invalid_memory;
        t21r = static_cast<std::uint32_t>(t21a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t21a, t21r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t21r)) return BatchLiftStatus::invalid_memory;
    // 0x00927514: 33c0 XOR
    L_00927514:
        t22a = state.regs[0];
        t22b = state.regs[0];
        t22r = (t22a ^ t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
        state.regs[0] = t22r;
    // 0x00927516: c7460440000000 MOV
        t23 = 0x00000040u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x0092751d: 894608 MOV
        t24 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00927520: 89460c MOV
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t25)) return BatchLiftStatus::invalid_memory;
    // 0x00927523: 894610 MOV
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00927526: 894614 MOV
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00927529: 894618 MOV
        t28 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x0092752c: 89461c MOV
        t29 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t29)) return BatchLiftStatus::invalid_memory;
    // 0x0092752f: 894620 MOV
        t30 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00927532: 6800040000 PUSH
        t31a = 0x00000400u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x00927537: 894624 MOV
        t32 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x0092753a: 8d7e30 LEA
        t33 = static_cast<std::uint32_t>(state.regs[6] + 0x00000030u);
        state.regs[7] = t33;
    // 0x0092753d: 53 PUSH
        t34a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x0092753e: 894628 MOV
        t35 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x00927541: 57 PUSH
        t36a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00927542: 89462c MOV
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00927545: e8f4918b00 CALL
        t38_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x011e073eu, 0x0092754au);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
        if (state.eip != 0x0092754au) return BatchLiftStatus::invalid_control_flow;
    // 0x0092754a: 83c40c ADD
        t39a = state.regs[4];
        t39b = 0x0000000cu;
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[4] = t39r;
    // 0x0092754d: 8bc7 MOV
        t40 = state.regs[7];
        state.regs[0] = t40;
    // 0x0092754f: b97f000000 MOV
        t41 = 0x0000007fu;
        state.regs[1] = t41;
    // 0x00927554: 894008 MOV
    L_00927554:
        t42 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x00927557: 89400c MOV
        t43 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t43)) return BatchLiftStatus::invalid_memory;
    // 0x0092755a: 83c008 ADD
        t44a = state.regs[0];
        t44b = 0x00000008u;
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        state.regs[0] = t44r;
    // 0x0092755d: 83e901 SUB
        t45a = state.regs[1];
        t45b = 0x00000001u;
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
        state.regs[1] = t45r;
    // 0x00927560: 75f2 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927554;
    // 0x00927562: 33c0 XOR
        t47a = state.regs[0];
        t47b = state.regs[0];
        t47r = (t47a ^ t47b) & 0xffffffffu;
        batch_set_logic_flags(state, t47r, 32u);
        state.regs[0] = t47r;
    // 0x00927564: 898630040000 MOV
        t48 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000430u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x0092756a: 898634040000 MOV
        t49 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000434u), t49)) return BatchLiftStatus::invalid_memory;
    // 0x00927570: 898638040000 MOV
        t50 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000438u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00927576: 89863c040000 MOV
        t51 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000043cu), t51)) return BatchLiftStatus::invalid_memory;
    // 0x0092757c: 89be40040000 MOV
        t52 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000440u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00927582: 899e44040000 MOV
        t53 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000444u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00927588: 898e48040000 MOV
        t54 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000448u), t54)) return BatchLiftStatus::invalid_memory;
    // 0x0092758e: 898e4c040000 MOV
        t55 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000044cu), t55)) return BatchLiftStatus::invalid_memory;
    // 0x00927594: 898e50040000 MOV
        t56 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000450u), t56)) return BatchLiftStatus::invalid_memory;
    // 0x0092759a: 898e54040000 MOV
        t57 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000454u), t57)) return BatchLiftStatus::invalid_memory;
    // 0x009275a0: 898e58040000 MOV
        t58 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000458u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x009275a6: 898e5c040000 MOV
        t59 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000045cu), t59)) return BatchLiftStatus::invalid_memory;
    // 0x009275ac: 898e60040000 MOV
        t60 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000460u), t60)) return BatchLiftStatus::invalid_memory;
    // 0x009275b2: 898e64040000 MOV
        t61 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000464u), t61)) return BatchLiftStatus::invalid_memory;
    // 0x009275b8: 8d8648040000 LEA
        t62 = static_cast<std::uint32_t>(state.regs[6] + 0x00000448u);
        state.regs[0] = t62;
    // 0x009275be: 898660040000 MOV
        t63 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000460u), t63)) return BatchLiftStatus::invalid_memory;
    // 0x009275c4: 898664040000 MOV
        t64 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000464u), t64)) return BatchLiftStatus::invalid_memory;
    // 0x009275ca: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t65)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t65;
    // 0x009275cd: 83e001 AND
        t66a = state.regs[0];
        t66b = 0x00000001u;
        t66r = (t66a & t66b) & 0xffffffffu;
        batch_set_logic_flags(state, t66r, 32u);
        state.regs[0] = t66r;
    // 0x009275d0: 83c848 OR
        t67a = state.regs[0];
        t67b = 0x00000048u;
        t67r = (t67a | t67b) & 0xffffffffu;
        batch_set_logic_flags(state, t67r, 32u);
        state.regs[0] = t67r;
    // 0x009275d3: 894604 MOV
        t68 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x009275d6: 8d869c040000 LEA
        t69 = static_cast<std::uint32_t>(state.regs[6] + 0x0000049cu);
        state.regs[0] = t69;
    // 0x009275dc: 899e68040000 MOV
        t70 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000468u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x009275e2: 889e6c040000 MOV
        t71 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000046cu), t71)) return BatchLiftStatus::invalid_memory;
    // 0x009275e8: 899e88040000 MOV
        t72 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000488u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x009275ee: 899e8c040000 MOV
        t73 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000048cu), t73)) return BatchLiftStatus::invalid_memory;
    // 0x009275f4: ba00000100 MOV
        t74 = 0x00010000u;
        state.regs[2] = t74;
    // 0x009275f9: 899690040000 MOV
        t75 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000490u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x009275ff: c7869404000000000200 MOV
        t76 = 0x00020000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000494u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x00927609: 889e98040000 MOV
        t77 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000498u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x0092760f: 8908 MOV
        t78 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t78)) return BatchLiftStatus::invalid_memory;
    // 0x00927611: 894804 MOV
        t79 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t79)) return BatchLiftStatus::invalid_memory;
    // 0x00927614: 894808 MOV
        t80 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x00927617: 89480c MOV
        t81 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t81)) return BatchLiftStatus::invalid_memory;
    // 0x0092761a: 8b8e40040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000440u), t82)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t82;
    // 0x00927620: 8986a4040000 MOV
        t83 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004a4u), t83)) return BatchLiftStatus::invalid_memory;
    // 0x00927626: 8986a8040000 MOV
        t84 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004a8u), t84)) return BatchLiftStatus::invalid_memory;
    // 0x0092762c: c786c804000000000400 MOV
        t85 = 0x00040000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004c8u), t85)) return BatchLiftStatus::invalid_memory;
    // 0x00927636: 8996cc040000 MOV
        t86 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004ccu), t86)) return BatchLiftStatus::invalid_memory;
    // 0x0092763c: 898ed0040000 MOV
        t87 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004d0u), t87)) return BatchLiftStatus::invalid_memory;
    // 0x00927642: e8a9170000 CALL
        if (!batch_guest_call32(memory, state, 0x00928df0u, 0x00927647u)) return BatchLiftStatus::invalid_memory;
        t88_call_status = spore_lift_00928df0(memory, state);
        if (t88_call_status != BatchLiftStatus::returned) return t88_call_status;
        if (state.eip != 0x00927647u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927647: 8986d4040000 MOV
        t89 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004d4u), t89)) return BatchLiftStatus::invalid_memory;
    // 0x0092764d: 3beb CMP
        t90a = state.regs[5];
        t90b = state.regs[3];
        t90r = static_cast<std::uint32_t>(t90a - t90b) & 0xffffffffu;
        batch_set_sub_flags(state, t90a, t90b, t90r, 32u);
    // 0x0092764f: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092765b;
    // 0x00927651: ff4d18 DEC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t92a)) return BatchLiftStatus::invalid_memory;
        t92r = static_cast<std::uint32_t>(t92a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t92a, t92r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t92r)) return BatchLiftStatus::invalid_memory;
    // 0x00927654: 55 PUSH
        t93a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t93a)) return BatchLiftStatus::invalid_memory;
    // 0x00927655: ff15dcc23c01 CALL
        t94_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x0092765bu);
        if (t94_call_status != BatchLiftStatus::returned) return t94_call_status;
        if (state.eip != 0x0092765bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092765b: 5d POP
    L_0092765b:
        if (!memory.load32(state.regs[4], t95a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t95a;
    // 0x0092765c: 8b442410 MOV
    L_0092765c:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t96;
    // 0x00927660: 8b4c2414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t97;
    // 0x00927664: 3bc3 CMP
        t98a = state.regs[0];
        t98b = state.regs[3];
        t98r = static_cast<std::uint32_t>(t98a - t98b) & 0xffffffffu;
        batch_set_sub_flags(state, t98a, t98b, t98r, 32u);
    // 0x00927666: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092766c;
    // 0x00927668: 3bcb CMP
        t100a = state.regs[1];
        t100b = state.regs[3];
        t100r = static_cast<std::uint32_t>(t100a - t100b) & 0xffffffffu;
        batch_set_sub_flags(state, t100a, t100b, t100r, 32u);
    // 0x0092766a: 741d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927689;
    // 0x0092766c: 8b542424 MOV
    L_0092766c:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t102)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t102;
    // 0x00927670: 52 PUSH
        t103a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
    // 0x00927671: 8b542424 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t104)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t104;
    // 0x00927675: 52 PUSH
        t105a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
    // 0x00927676: 8b542424 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t106)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t106;
    // 0x0092767a: 52 PUSH
        t107a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
    // 0x0092767b: 8b542424 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t108)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t108;
    // 0x0092767f: 52 PUSH
        t109a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t109a)) return BatchLiftStatus::invalid_memory;
    // 0x00927680: 51 PUSH
        t110a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t110a)) return BatchLiftStatus::invalid_memory;
    // 0x00927681: 50 PUSH
        t111a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t111a)) return BatchLiftStatus::invalid_memory;
    // 0x00927682: 8bce MOV
        t112 = state.regs[6];
        state.regs[1] = t112;
    // 0x00927684: e8b7faffff CALL
        if (!batch_guest_call32(memory, state, 0x00927140u, 0x00927689u)) return BatchLiftStatus::invalid_memory;
        t113_call_status = spore_lift_00927140(memory, state);
        if (t113_call_status != BatchLiftStatus::returned) return t113_call_status;
        if (state.eip != 0x00927689u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927689: 389e0c050000 CMP
    L_00927689:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x0000050cu), t114a)) return BatchLiftStatus::invalid_memory;
        t114b = state.regs[3] & 0x000000ffu;
        t114r = static_cast<std::uint32_t>(t114a - t114b) & 0x000000ffu;
        batch_set_sub_flags(state, t114a, t114b, t114r, 8u);
    // 0x0092768f: 7526 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009276b7;
    // 0x00927691: c6860c05000001 MOV
        t116 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000050cu), t116)) return BatchLiftStatus::invalid_memory;
    // 0x00927698: 8b3dc08e6601 MOV
        if (!memory.load32(0x01668ec0u, t117)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t117;
    // 0x0092769e: 3bfb CMP
        t118a = state.regs[7];
        t118b = state.regs[3];
        t118r = static_cast<std::uint32_t>(t118a - t118b) & 0xffffffffu;
        batch_set_sub_flags(state, t118a, t118b, t118r, 32u);
    // 0x009276a0: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009276b7;
    // 0x009276a2: 8b4704 MOV
    L_009276a2:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t120;
    // 0x009276a5: 8b0f MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t121)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t121;
    // 0x009276a7: 50 PUSH
        t122a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t122a)) return BatchLiftStatus::invalid_memory;
    // 0x009276a8: 6a01 PUSH
        t123a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t123a)) return BatchLiftStatus::invalid_memory;
    // 0x009276aa: 56 PUSH
        t124a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t124a)) return BatchLiftStatus::invalid_memory;
    // 0x009276ab: ffd1 CALL
        t125_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[1], 0x009276adu);
        if (t125_call_status != BatchLiftStatus::returned) return t125_call_status;
    // 0x009276ad: 8b7f08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t126)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t126;
    // 0x009276b0: 83c40c ADD
        t127a = state.regs[4];
        t127b = 0x0000000cu;
        t127r = static_cast<std::uint32_t>(t127a + t127b) & 0xffffffffu;
        batch_set_add_flags(state, t127a, t127b, t127r, 32u);
        state.regs[4] = t127r;
    // 0x009276b3: 3bfb CMP
        t128a = state.regs[7];
        t128b = state.regs[3];
        t128r = static_cast<std::uint32_t>(t128a - t128b) & 0xffffffffu;
        batch_set_sub_flags(state, t128a, t128b, t128r, 32u);
    // 0x009276b5: 75eb JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009276a2;
    // 0x009276b7: 5f POP
    L_009276b7:
        if (!memory.load32(state.regs[4], t130a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t130a;
    // 0x009276b8: 5e POP
        if (!memory.load32(state.regs[4], t131a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t131a;
    // 0x009276b9: b001 MOV
        t132 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t132 << 0u) & 0x000000ffu);
    // 0x009276bb: 5b POP
        if (!memory.load32(state.regs[4], t133a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t133a;
    // 0x009276bc: c21800 RET
        if (!batch_guest_return32(memory, state, 24u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
