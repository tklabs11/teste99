#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00926840(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926c20(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927258(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00927140(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00927140u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11a = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24a = 0, t24r = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29a = 0, t29c = 0, t29r = 0;
    std::uint32_t t30a = 0, t30c = 0, t30r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
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
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59 = 0;
    BatchLiftStatus t60_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68a = 0, t68b = 0, t68r = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83a = 0, t83b = 0, t83r = 0;
    std::uint32_t t85a = 0;
    std::uint32_t t86a = 0;
    std::uint32_t t87a = 0;
    std::uint32_t t88 = 0;
    BatchLiftStatus t89_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t90a = 0, t90b = 0, t90r = 0;
    std::uint32_t t92a = 0, t92r = 0;
    std::uint32_t t93a = 0;
    BatchLiftStatus t94_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t95a = 0;
    std::uint32_t t96a = 0;
    std::uint32_t t97a = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99a = 0;
    std::uint32_t t100a = 0, t100b = 0, t100r = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103a = 0, t103b = 0, t103r = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107a = 0, t107r = 0;
    std::uint32_t t108a = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t110a = 0;
    std::uint32_t t111a = 0;
    std::uint32_t t112 = 0;
    BatchLiftStatus t113_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t114a = 0, t114b = 0, t114r = 0;
    std::uint32_t t116a = 0;
    std::uint32_t t117a = 0;
    std::uint32_t t119a = 0, t119b = 0, t119r = 0;
    std::uint32_t t121a = 0, t121r = 0;
    std::uint32_t t122a = 0;
    BatchLiftStatus t123_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t124a = 0;
    std::uint32_t t125a = 0;
    std::uint32_t t126a = 0;
    std::uint32_t t127a = 0, t127b = 0, t127r = 0;
    std::uint32_t t128a = 0;
    std::uint32_t t129a = 0, t129b = 0, t129r = 0;

    // 0x00927140: 83ec1c SUB
        t0a = state.regs[4];
        t0b = 0x0000001cu;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00927143: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00927144: 55 PUSH
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00927145: 56 PUSH
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00927146: 57 PUSH
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00927147: 8bf9 MOV
        t5 = state.regs[1];
        state.regs[7] = t5;
    // 0x00927149: 8bafe4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x000004e4u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t6;
    // 0x0092714f: 85ed TEST
        t7a = state.regs[5];
        t7b = state.regs[5];
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
    // 0x00927151: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092715d;
    // 0x00927153: 55 PUSH
        t9a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00927154: ff15d8c23c01 CALL
        t10_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x0092715au);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x0092715au) return BatchLiftStatus::invalid_control_flow;
    // 0x0092715a: ff4518 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t11a)) return BatchLiftStatus::invalid_memory;
        t11r = static_cast<std::uint32_t>(t11a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t11a, t11r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t11r)) return BatchLiftStatus::invalid_memory;
    // 0x0092715d: 8b742430 MOV
    L_0092715d:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t12;
    // 0x00927161: 85f6 TEST
        t13a = state.regs[6];
        t13b = state.regs[6];
        t13r = (t13a & t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
    // 0x00927163: 0f8410010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927279;
    // 0x00927169: 8b5c2434 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t15;
    // 0x0092716d: 83fb40 CMP
        t16a = state.regs[3];
        t16b = 0x00000040u;
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x00927170: 0f822d010000 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_009272a3;
    // 0x00927176: 8b8fd4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x000004d4u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t18;
    // 0x0092717c: 33d2 XOR
        t19a = state.regs[2];
        t19b = state.regs[2];
        t19r = (t19a ^ t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[2] = t19r;
    // 0x0092717e: 8bc3 MOV
        t20 = state.regs[3];
        state.regs[0] = t20;
    // 0x00927180: f7f1 DIV
        t21a = state.regs[1];
        if (t21a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::uint64_t dividend = (static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0];
        const std::uint64_t quotient = dividend / t21a;
        if (quotient > 0xffffffffull) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(dividend % t21a);
        }
    // 0x00927182: 85d2 TEST
        t22a = state.regs[2];
        t22b = state.regs[2];
        t22r = (t22a & t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
    // 0x00927184: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092718b;
    // 0x00927186: 49 DEC
        t24a = state.regs[1];
        t24r = static_cast<std::uint32_t>(t24a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t24a, t24r, 32u);
        state.regs[1] = t24r;
    // 0x00927187: f7d1 NOT
        t25a = state.regs[1];
        state.regs[1] = (~t25a & 0xffffffffu);
    // 0x00927189: 23d9 AND
        t26a = state.regs[3];
        t26b = state.regs[1];
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[3] = t26r;
    // 0x0092718b: f6c30f TEST
    L_0092718b:
        t27a = state.regs[3] & 0x000000ffu;
        t27b = 0x0000000fu;
        t27r = (t27a & t27b) & 0x000000ffu;
        batch_set_logic_flags(state, t27r, 8u);
    // 0x0092718e: 7406 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927196;
    // 0x00927190: c1eb04 SHR
        t29a = state.regs[3];
        t29c = 4u;
        if (t29c != 0u) {
        t29r = static_cast<std::uint32_t>(t29a >> t29c);
        batch_set_shr_flags(state, t29a, t29c, t29r, 32u);
            state.regs[3] = t29r;
        }
    // 0x00927193: c1e304 SHL
        t30a = state.regs[3];
        t30c = 4u;
        if (t30c != 0u) {
        t30r = static_cast<std::uint32_t>(t30a << t30c) & 0xffffffffu;
        batch_set_shl_flags(state, t30a, t30c, t30r, 32u);
            state.regs[3] = t30r;
        }
    // 0x00927196: 8a4c243c MOV
    L_00927196:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t31 << 0u) & 0x000000ffu);
    // 0x0092719a: 8b542444 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t32;
    // 0x0092719e: 8d4627 LEA
        t33 = static_cast<std::uint32_t>(state.regs[6] + 0x00000027u);
        state.regs[0] = t33;
    // 0x009271a1: 83e0f8 AND
        t34a = state.regs[0];
        t34b = 0xfffffff8u;
        t34r = (t34a & t34b) & 0xffffffffu;
        batch_set_logic_flags(state, t34r, 32u);
        state.regs[0] = t34r;
    // 0x009271a4: 8906 MOV
        t35 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x009271a6: 8a442438 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t36 << 0u) & 0x000000ffu);
    // 0x009271aa: 88460d MOV
        t37 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000du), t37)) return BatchLiftStatus::invalid_memory;
    // 0x009271ad: 88460e MOV
        t38 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000eu), t38)) return BatchLiftStatus::invalid_memory;
    // 0x009271b0: 884e0f MOV
        t39 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000fu), t39)) return BatchLiftStatus::invalid_memory;
    // 0x009271b3: 8b4c2440 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t40;
    // 0x009271b7: 8d8748040000 LEA
        t41 = static_cast<std::uint32_t>(state.regs[7] + 0x00000448u);
        state.regs[0] = t41;
    // 0x009271bd: 89461c MOV
        t42 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t42)) return BatchLiftStatus::invalid_memory;
    // 0x009271c0: 895e04 MOV
        t43 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x009271c3: 895e08 MOV
        t44 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x009271c6: c6460c00 MOV
        t45 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t45)) return BatchLiftStatus::invalid_memory;
    // 0x009271ca: 894e10 MOV
        t46 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x009271cd: 895614 MOV
        t47 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x009271d0: 8b5018 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t48;
    // 0x009271d3: 895618 MOV
        t49 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t49)) return BatchLiftStatus::invalid_memory;
    // 0x009271d6: 897018 MOV
        t50 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x009271d9: 8b4618 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t51;
    // 0x009271dc: 89701c MOV
        t52 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t52)) return BatchLiftStatus::invalid_memory;
    // 0x009271df: 85c9 TEST
        t53a = state.regs[1];
        t53b = state.regs[1];
        t53r = (t53a & t53b) & 0xffffffffu;
        batch_set_logic_flags(state, t53r, 32u);
    // 0x009271e1: 7523 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927206;
    // 0x009271e3: 6a1c PUSH
        t55a = 0x0000001cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x009271e5: 8d4c2414 LEA
        t56 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[1] = t56;
    // 0x009271e9: 51 PUSH
        t57a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x009271ea: 56 PUSH
        t58a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
    // 0x009271eb: 8974241c MOV
        t59 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t59)) return BatchLiftStatus::invalid_memory;
    // 0x009271ef: ff1534c13c01 CALL
        t60_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!VirtualQuery", 0x013cc134u, 0x009271f5u);
        if (t60_call_status != BatchLiftStatus::returned) return t60_call_status;
        if (state.eip != 0x009271f5u) return BatchLiftStatus::invalid_control_flow;
    // 0x009271f5: 817c242000200000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t61a)) return BatchLiftStatus::invalid_memory;
        t61b = 0x00002000u;
        t61r = static_cast<std::uint32_t>(t61a - t61b) & 0xffffffffu;
        batch_set_sub_flags(state, t61a, t61b, t61r, 32u);
    // 0x009271fd: 7507 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927206;
    // 0x009271ff: c7460400000000 MOV
        t63 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t63)) return BatchLiftStatus::invalid_memory;
    // 0x00927206: 8b0e MOV
    L_00927206:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t64;
    // 0x00927208: 2bf1 SUB
        t65a = state.regs[6];
        t65b = state.regs[1];
        t65r = static_cast<std::uint32_t>(t65a - t65b) & 0xffffffffu;
        batch_set_sub_flags(state, t65a, t65b, t65r, 32u);
        state.regs[6] = t65r;
    // 0x0092720a: 03f3 ADD
        t66a = state.regs[6];
        t66b = state.regs[3];
        t66r = static_cast<std::uint32_t>(t66a + t66b) & 0xffffffffu;
        batch_set_add_flags(state, t66a, t66b, t66r, 32u);
        state.regs[6] = t66r;
    // 0x0092720c: 8bd6 MOV
        t67 = state.regs[6];
        state.regs[2] = t67;
    // 0x0092720e: 83ca01 OR
        t68a = state.regs[2];
        t68b = 0x00000001u;
        t68r = (t68a | t68b) & 0xffffffffu;
        batch_set_logic_flags(state, t68r, 32u);
        state.regs[2] = t68r;
    // 0x00927211: 8bc2 MOV
        t69 = state.regs[2];
        state.regs[0] = t69;
    // 0x00927213: 25f8ffff7f AND
        t70a = state.regs[0];
        t70b = 0x7ffffff8u;
        t70r = (t70a & t70b) & 0xffffffffu;
        batch_set_logic_flags(state, t70r, 32u);
        state.regs[0] = t70r;
    // 0x00927218: 83e809 SUB
        t71a = state.regs[0];
        t71b = 0x00000009u;
        t71r = static_cast<std::uint32_t>(t71a - t71b) & 0xffffffffu;
        batch_set_sub_flags(state, t71a, t71b, t71r, 32u);
        state.regs[0] = t71r;
    // 0x0092721b: 83e0f8 AND
        t72a = state.regs[0];
        t72b = 0xfffffff8u;
        t72r = (t72a & t72b) & 0xffffffffu;
        batch_set_logic_flags(state, t72r, 32u);
        state.regs[0] = t72r;
    // 0x0092721e: 81e207000080 AND
        t73a = state.regs[2];
        t73b = 0x80000007u;
        t73r = (t73a & t73b) & 0xffffffffu;
        batch_set_logic_flags(state, t73r, 32u);
        state.regs[2] = t73r;
    // 0x00927224: 0bd0 OR
        t74a = state.regs[2];
        t74b = state.regs[0];
        t74r = (t74a | t74b) & 0xffffffffu;
        batch_set_logic_flags(state, t74r, 32u);
        state.regs[2] = t74r;
    // 0x00927226: 895104 MOV
        t75 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x00927229: c70100000000 MOV
        t76 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x0092722f: ba08000000 MOV
        t77 = 0x00000008u;
        state.regs[2] = t77;
    // 0x00927234: 89540804 MOV
        t78 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000004u), t78)) return BatchLiftStatus::invalid_memory;
    // 0x00927238: 890408 MOV
        t79 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000000u), t79)) return BatchLiftStatus::invalid_memory;
    // 0x0092723b: 89540808 MOV
        t80 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000008u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x0092723f: 8d5730 LEA
        t81 = static_cast<std::uint32_t>(state.regs[7] + 0x00000030u);
        state.regs[2] = t81;
    // 0x00927242: c744080c09000000 MOV
        t82 = 0x00000009u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x0000000cu), t82)) return BatchLiftStatus::invalid_memory;
    // 0x0092724a: 399740040000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000440u), t83a)) return BatchLiftStatus::invalid_memory;
        t83b = state.regs[2];
        t83r = static_cast<std::uint32_t>(t83a - t83b) & 0xffffffffu;
        batch_set_sub_flags(state, t83a, t83b, t83r, 32u);
    // 0x00927250: 0f95c0 SETNZ
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927253: 0fb6d0 MOVZX
        t85a = state.regs[0] & 0x000000ffu;
        state.regs[2] = t85a;
    // 0x00927256: 52 PUSH
        t86a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t86a)) return BatchLiftStatus::invalid_memory;
    // 0x00927257: 51 PUSH
        t87a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t87a)) return BatchLiftStatus::invalid_memory;
    // 0x00927258: 8bcf MOV
    L_00927258:
        t88 = state.regs[7];
        state.regs[1] = t88;
    // 0x0092725a: e8e1f5ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926840u, 0x0092725fu)) return BatchLiftStatus::invalid_memory;
        t89_call_status = spore_lift_00926840(memory, state);
        if (t89_call_status != BatchLiftStatus::returned) return t89_call_status;
        if (state.eip != 0x0092725fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092725f: 85ed TEST
        t90a = state.regs[5];
        t90b = state.regs[5];
        t90r = (t90a & t90b) & 0xffffffffu;
        batch_set_logic_flags(state, t90r, 32u);
    // 0x00927261: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092726d;
    // 0x00927263: ff4d18 DEC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t92a)) return BatchLiftStatus::invalid_memory;
        t92r = static_cast<std::uint32_t>(t92a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t92a, t92r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t92r)) return BatchLiftStatus::invalid_memory;
    // 0x00927266: 55 PUSH
        t93a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t93a)) return BatchLiftStatus::invalid_memory;
    // 0x00927267: ff15dcc23c01 CALL
        t94_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x0092726du);
        if (t94_call_status != BatchLiftStatus::returned) return t94_call_status;
        if (state.eip != 0x0092726du) return BatchLiftStatus::invalid_control_flow;
    // 0x0092726d: 5f POP
    L_0092726d:
        if (!memory.load32(state.regs[4], t95a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t95a;
    // 0x0092726e: 5e POP
        if (!memory.load32(state.regs[4], t96a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t96a;
    // 0x0092726f: 5d POP
        if (!memory.load32(state.regs[4], t97a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t97a;
    // 0x00927270: b001 MOV
        t98 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t98 << 0u) & 0x000000ffu);
    // 0x00927272: 5b POP
        if (!memory.load32(state.regs[4], t99a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t99a;
    // 0x00927273: 83c41c ADD
        t100a = state.regs[4];
        t100b = 0x0000001cu;
        t100r = static_cast<std::uint32_t>(t100a + t100b) & 0xffffffffu;
        batch_set_add_flags(state, t100a, t100b, t100r, 32u);
        state.regs[4] = t100r;
    // 0x00927276: c21800 RET
        if (!batch_guest_return32(memory, state, 24u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00927279: 8b4c2434 MOV
    L_00927279:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t102)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t102;
    // 0x0092727d: 85c9 TEST
        t103a = state.regs[1];
        t103b = state.regs[1];
        t103r = (t103a & t103b) & 0xffffffffu;
        batch_set_logic_flags(state, t103r, 32u);
    // 0x0092727f: 7622 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_009272a3;
    // 0x00927281: 8b87d4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x000004d4u), t105)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t105;
    // 0x00927287: 8d4c08ff LEA
        t106 = static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0xffffffffu);
        state.regs[1] = t106;
    // 0x0092728b: 48 DEC
        t107a = state.regs[0];
        t107r = static_cast<std::uint32_t>(t107a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t107a, t107r, 32u);
        state.regs[0] = t107r;
    // 0x0092728c: f7d0 NOT
        t108a = state.regs[0];
        state.regs[0] = (~t108a & 0xffffffffu);
    // 0x0092728e: 23c8 AND
        t109a = state.regs[1];
        t109b = state.regs[0];
        t109r = (t109a & t109b) & 0xffffffffu;
        batch_set_logic_flags(state, t109r, 32u);
        state.regs[1] = t109r;
    // 0x00927290: 6a01 PUSH
        t110a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t110a)) return BatchLiftStatus::invalid_memory;
    // 0x00927292: 51 PUSH
        t111a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t111a)) return BatchLiftStatus::invalid_memory;
    // 0x00927293: 8bcf MOV
        t112 = state.regs[7];
        state.regs[1] = t112;
    // 0x00927295: e886f9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926c20u, 0x0092729au)) return BatchLiftStatus::invalid_memory;
        t113_call_status = spore_lift_00926c20(memory, state);
        if (t113_call_status != BatchLiftStatus::returned) return t113_call_status;
        if (state.eip != 0x0092729au) return BatchLiftStatus::invalid_control_flow;
    // 0x0092729a: 85c0 TEST
        t114a = state.regs[0];
        t114b = state.regs[0];
        t114r = (t114a & t114b) & 0xffffffffu;
        batch_set_logic_flags(state, t114r, 32u);
    // 0x0092729c: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009272a3;
    // 0x0092729e: 6a01 PUSH
        t116a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t116a)) return BatchLiftStatus::invalid_memory;
    // 0x009272a0: 50 PUSH
        t117a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t117a)) return BatchLiftStatus::invalid_memory;
    // 0x009272a1: ebb5 JMP
        goto L_00927258;
    // 0x009272a3: 85ed TEST
    L_009272a3:
        t119a = state.regs[5];
        t119b = state.regs[5];
        t119r = (t119a & t119b) & 0xffffffffu;
        batch_set_logic_flags(state, t119r, 32u);
    // 0x009272a5: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009272b1;
    // 0x009272a7: ff4d18 DEC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t121a)) return BatchLiftStatus::invalid_memory;
        t121r = static_cast<std::uint32_t>(t121a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t121a, t121r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t121r)) return BatchLiftStatus::invalid_memory;
    // 0x009272aa: 55 PUSH
        t122a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t122a)) return BatchLiftStatus::invalid_memory;
    // 0x009272ab: ff15dcc23c01 CALL
        t123_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x009272b1u);
        if (t123_call_status != BatchLiftStatus::returned) return t123_call_status;
        if (state.eip != 0x009272b1u) return BatchLiftStatus::invalid_control_flow;
    // 0x009272b1: 5f POP
    L_009272b1:
        if (!memory.load32(state.regs[4], t124a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t124a;
    // 0x009272b2: 5e POP
        if (!memory.load32(state.regs[4], t125a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t125a;
    // 0x009272b3: 5d POP
        if (!memory.load32(state.regs[4], t126a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t126a;
    // 0x009272b4: 32c0 XOR
        t127a = state.regs[0] & 0x000000ffu;
        t127b = state.regs[0] & 0x000000ffu;
        t127r = (t127a ^ t127b) & 0x000000ffu;
        batch_set_logic_flags(state, t127r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t127r << 0u) & 0x000000ffu);
    // 0x009272b6: 5b POP
        if (!memory.load32(state.regs[4], t128a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t128a;
    // 0x009272b7: 83c41c ADD
        t129a = state.regs[4];
        t129b = 0x0000001cu;
        t129r = static_cast<std::uint32_t>(t129a + t129b) & 0xffffffffu;
        batch_set_add_flags(state, t129a, t129b, t129r, 32u);
        state.regs[4] = t129r;
    // 0x009272ba: c21800 RET
        if (!batch_guest_return32(memory, state, 24u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
