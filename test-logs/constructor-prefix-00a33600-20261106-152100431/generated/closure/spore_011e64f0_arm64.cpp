#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011ecd90(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011ecdd0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011ecde0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e64f0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
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
    std::uint32_t t51a = 0, t51b = 0, t51r = 0;
    std::uint32_t t53 = 0;
    BatchLiftStatus t54_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;
    std::uint32_t t60a = 0, t60r = 0;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t62a = 0, t62b = 0, t62r = 0;
    std::uint32_t t64 = 0;
    BatchLiftStatus t65_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t66a = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69a = 0;
    std::uint32_t t70a = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75a = 0, t75r = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    BatchLiftStatus t78_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t79a = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81a = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83a = 0;

    // 0x011e64f0: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x011e64f4: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e64f5: 55 PUSH
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x011e64f6: 33db XOR
        t3a = state.regs[3];
        t3b = state.regs[3];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[3] = t3r;
    // 0x011e64f8: 56 PUSH
        t4a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x011e64f9: 8bf1 MOV
        t5 = state.regs[1];
        state.regs[6] = t5;
    // 0x011e64fb: 57 PUSH
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x011e64fc: 891e MOV
        t7 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x011e64fe: 895e04 MOV
        t8 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x011e6501: c6460801 MOV
        t9 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x011e6505: 885e09 MOV
        t10 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000009u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x011e6508: 895e6c MOV
        t11 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000006cu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x011e650b: 895e70 MOV
        t12 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000070u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x011e650e: 895e74 MOV
        t13 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000074u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x011e6511: 6a20 PUSH
        t14a = 0x00000020u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x011e6513: 50 PUSH
        t15a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x011e6514: 8d4e0a LEA
        t16 = static_cast<std::uint32_t>(state.regs[6] + 0x0000000au);
        state.regs[1] = t16;
    // 0x011e6517: 8d6e74 LEA
        t17 = static_cast<std::uint32_t>(state.regs[6] + 0x00000074u);
        state.regs[5] = t17;
    // 0x011e651a: 51 PUSH
        t18a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x011e651b: 889e98000000 MOV
        t19 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000098u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x011e6521: 889e99000000 MOV
        t20 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000099u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x011e6527: 889e9a000000 MOV
        t21 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000009au), t21)) return BatchLiftStatus::invalid_memory;
    // 0x011e652d: 889e9b000000 MOV
        t22 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000009bu), t22)) return BatchLiftStatus::invalid_memory;
    // 0x011e6533: 889e9c000000 MOV
        t23 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000009cu), t23)) return BatchLiftStatus::invalid_memory;
    // 0x011e6539: 889e9d000000 MOV
        t24 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000009du), t24)) return BatchLiftStatus::invalid_memory;
    // 0x011e653f: ff15f4c43c01 CALL
        t25_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!strncpy", 0x013cc4f4u, 0x011e6545u);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x011e6545u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e6545: 8a442428 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t26 << 0u) & 0x000000ffu);
    // 0x011e6549: 83c40c ADD
        t27a = state.regs[4];
        t27b = 0x0000000cu;
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        state.regs[4] = t27r;
    // 0x011e654c: a801 TEST
        t28a = state.regs[0] & 0x000000ffu;
        t28b = 0x00000001u;
        t28r = (t28a & t28b) & 0x000000ffu;
        batch_set_logic_flags(state, t28r, 8u);
    // 0x011e654e: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e6557;
    // 0x011e6550: 8bcd MOV
        t30 = state.regs[5];
        state.regs[1] = t30;
    // 0x011e6552: e839680000 CALL
        if (!batch_guest_call32(memory, state, 0x011ecd90u, 0x011e6557u)) return BatchLiftStatus::invalid_memory;
        t31_call_status = spore_lift_011ecd90(memory, state);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
        if (state.eip != 0x011e6557u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e6557: 33d2 XOR
    L_011e6557:
        t32a = state.regs[2];
        t32b = state.regs[2];
        t32r = (t32a ^ t32b) & 0xffffffffu;
        batch_set_logic_flags(state, t32r, 32u);
        state.regs[2] = t32r;
    // 0x011e6559: 8d7e2c LEA
        t33 = static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu);
        state.regs[7] = t33;
    // 0x011e655c: 8bc7 MOV
        t34 = state.regs[7];
        state.regs[0] = t34;
    // 0x011e655e: 8910 MOV
        t35 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x011e6560: 895004 MOV
        t36 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x011e6563: 895008 MOV
        t37 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x011e6566: 89500c MOV
        t38 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t38)) return BatchLiftStatus::invalid_memory;
    // 0x011e6569: 895010 MOV
        t39 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x011e656c: 895014 MOV
        t40 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x011e656f: 895018 MOV
        t41 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x011e6572: 89501c MOV
        t42 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t42)) return BatchLiftStatus::invalid_memory;
    // 0x011e6575: 895020 MOV
        t43 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000020u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x011e6578: 895024 MOV
        t44 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000024u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x011e657b: 895028 MOV
        t45 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000028u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x011e657e: 89502c MOV
        t46 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000002cu), t46)) return BatchLiftStatus::invalid_memory;
    // 0x011e6581: 895030 MOV
        t47 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x011e6584: 895034 MOV
        t48 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000034u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x011e6587: 895038 MOV
        t49 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000038u), t49)) return BatchLiftStatus::invalid_memory;
    // 0x011e658a: 89503c MOV
        t50 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000003cu), t50)) return BatchLiftStatus::invalid_memory;
    // 0x011e658d: 395c2418 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t51a)) return BatchLiftStatus::invalid_memory;
        t51b = state.regs[3];
        t51r = static_cast<std::uint32_t>(t51a - t51b) & 0xffffffffu;
        batch_set_sub_flags(state, t51a, t51b, t51r, 32u);
    // 0x011e6591: 743e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e65d1;
    // 0x011e6593: 8bcd MOV
        t53 = state.regs[5];
        state.regs[1] = t53;
    // 0x011e6595: e836680000 CALL
        if (!batch_guest_call32(memory, state, 0x011ecdd0u, 0x011e659au)) return BatchLiftStatus::invalid_memory;
        t54_call_status = spore_lift_011ecdd0(memory, state);
        if (t54_call_status != BatchLiftStatus::returned) return t54_call_status;
        if (state.eip != 0x011e659au) return BatchLiftStatus::invalid_control_flow;
    // 0x011e659a: 33c0 XOR
        t55a = state.regs[0];
        t55b = state.regs[0];
        t55r = (t55a ^ t55b) & 0xffffffffu;
        batch_set_logic_flags(state, t55r, 32u);
        state.regs[0] = t55r;
    // 0x011e659c: 8bcf MOV
        t56 = state.regs[7];
        state.regs[1] = t56;
    // 0x011e659e: 8bff MOV
        t57 = state.regs[7];
        state.regs[7] = t57;
    // 0x011e65a0: 3919 CMP
    L_011e65a0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t58a)) return BatchLiftStatus::invalid_memory;
        t58b = state.regs[3];
        t58r = static_cast<std::uint32_t>(t58a - t58b) & 0xffffffffu;
        batch_set_sub_flags(state, t58a, t58b, t58r, 32u);
    // 0x011e65a2: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e65bd;
    // 0x011e65a4: 40 INC
        t60a = state.regs[0];
        t60r = static_cast<std::uint32_t>(t60a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t60a, t60r, 32u);
        state.regs[0] = t60r;
    // 0x011e65a5: 83c104 ADD
        t61a = state.regs[1];
        t61b = 0x00000004u;
        t61r = static_cast<std::uint32_t>(t61a + t61b) & 0xffffffffu;
        batch_set_add_flags(state, t61a, t61b, t61r, 32u);
        state.regs[1] = t61r;
    // 0x011e65a8: 83f810 CMP
        t62a = state.regs[0];
        t62b = 0x00000010u;
        t62r = static_cast<std::uint32_t>(t62a - t62b) & 0xffffffffu;
        batch_set_sub_flags(state, t62a, t62b, t62r, 32u);
    // 0x011e65ab: 72f3 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_011e65a0;
    // 0x011e65ad: 8bcd MOV
        t64 = state.regs[5];
        state.regs[1] = t64;
    // 0x011e65af: e82c680000 CALL
        if (!batch_guest_call32(memory, state, 0x011ecde0u, 0x011e65b4u)) return BatchLiftStatus::invalid_memory;
        t65_call_status = spore_lift_011ecde0(memory, state);
        if (t65_call_status != BatchLiftStatus::returned) return t65_call_status;
        if (state.eip != 0x011e65b4u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e65b4: 5f POP
        if (!memory.load32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t66a;
    // 0x011e65b5: 8bc6 MOV
        t67 = state.regs[6];
        state.regs[0] = t67;
    // 0x011e65b7: 5e POP
        if (!memory.load32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t68a;
    // 0x011e65b8: 5d POP
        if (!memory.load32(state.regs[4], t69a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t69a;
    // 0x011e65b9: 5b POP
        if (!memory.load32(state.regs[4], t70a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t70a;
    // 0x011e65ba: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x011e65bd: 8b4c2418 MOV
    L_011e65bd:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t72)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t72;
    // 0x011e65c1: 894c862c MOV
        t73 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + state.regs[0] * 4u + 0x0000002cu), t73)) return BatchLiftStatus::invalid_memory;
    // 0x011e65c5: 8b06 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t74;
    // 0x011e65c7: 40 INC
        t75a = state.regs[0];
        t75r = static_cast<std::uint32_t>(t75a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t75a, t75r, 32u);
        state.regs[0] = t75r;
    // 0x011e65c8: 8bcd MOV
        t76 = state.regs[5];
        state.regs[1] = t76;
    // 0x011e65ca: 8906 MOV
        t77 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x011e65cc: e80f680000 CALL
        if (!batch_guest_call32(memory, state, 0x011ecde0u, 0x011e65d1u)) return BatchLiftStatus::invalid_memory;
        t78_call_status = spore_lift_011ecde0(memory, state);
        if (t78_call_status != BatchLiftStatus::returned) return t78_call_status;
        if (state.eip != 0x011e65d1u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e65d1: 5f POP
    L_011e65d1:
        if (!memory.load32(state.regs[4], t79a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t79a;
    // 0x011e65d2: 8bc6 MOV
        t80 = state.regs[6];
        state.regs[0] = t80;
    // 0x011e65d4: 5e POP
        if (!memory.load32(state.regs[4], t81a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t81a;
    // 0x011e65d5: 5d POP
        if (!memory.load32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t82a;
    // 0x011e65d6: 5b POP
        if (!memory.load32(state.regs[4], t83a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t83a;
    // 0x011e65d7: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
