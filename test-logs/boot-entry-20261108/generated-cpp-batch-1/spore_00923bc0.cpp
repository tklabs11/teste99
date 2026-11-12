#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921580(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923ac0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923b40(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923b80(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923bc0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923bc0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    BatchLiftStatus t29_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43a = 0;
    BatchLiftStatus t44_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51a = 0, t51b = 0, t51r = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55 = 0;
    BatchLiftStatus t56_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62a = 0;
    BatchLiftStatus t63_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73a = 0;
    std::uint32_t t74a = 0;
    std::uint32_t t75a = 0, t75b = 0, t75r = 0;
    std::uint32_t t76a = 0;
    std::uint32_t t77a = 0;

    // 0x00923bc0: 51 PUSH
        batch_guest_pc = 0x00923bc0u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923bc1: 8b442408 MOV
        batch_guest_pc = 0x00923bc1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00923bc5: 55 PUSH
        batch_guest_pc = 0x00923bc5u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00923bc6: 56 PUSH
        batch_guest_pc = 0x00923bc6u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00923bc7: 57 PUSH
        batch_guest_pc = 0x00923bc7u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00923bc8: 8bf9 MOV
        t5 = state.regs[1];
        state.regs[7] = t5;
    // 0x00923bca: 85c0 TEST
        t6a = state.regs[0];
        t6b = state.regs[0];
        t6r = (t6a & t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
    // 0x00923bcc: 744a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923c18;
    // 0x00923bce: 803800 CMP
        batch_guest_pc = 0x00923bceu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t8a)) return BatchLiftStatus::invalid_memory;
        t8b = 0x00000000u;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0x000000ffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 8u);
    // 0x00923bd1: 7445 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923c18;
    // 0x00923bd3: 8d442414 LEA
        t10 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[0] = t10;
    // 0x00923bd7: 50 PUSH
        batch_guest_pc = 0x00923bd7u;
        t11a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00923bd8: 8d4c2410 LEA
        t12 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[1] = t12;
    // 0x00923bdc: 8d771c LEA
        t13 = static_cast<std::uint32_t>(state.regs[7] + 0x0000001cu);
        state.regs[6] = t13;
    // 0x00923bdf: 51 PUSH
        batch_guest_pc = 0x00923bdfu;
        t14a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00923be0: 8bce MOV
        t15 = state.regs[6];
        state.regs[1] = t15;
    // 0x00923be2: e8d9feffff CALL
        if (!batch_guest_call32(memory, state, 0x00923ac0u, 0x00923be7u)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00923ac0(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00923be7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923be7: 8d5720 LEA
        t17 = static_cast<std::uint32_t>(state.regs[7] + 0x00000020u);
        state.regs[2] = t17;
    // 0x00923bea: 8b7c240c MOV
        batch_guest_pc = 0x00923beau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t18;
    // 0x00923bee: 3bfa CMP
        t19a = state.regs[7];
        t19b = state.regs[2];
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x00923bf0: 0f8488000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923c7e;
    // 0x00923bf6: 8b4710 MOV
        batch_guest_pc = 0x00923bf6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00923bf9: 50 PUSH
        batch_guest_pc = 0x00923bf9u;
        t22a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00923bfa: e881376200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00923bffu)) return BatchLiftStatus::invalid_memory;
        t23_call_status = spore_lift_00f47380(memory, state);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x00923bffu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923bff: 8bc4 MOV
        t24 = state.regs[4];
        state.regs[0] = t24;
    // 0x00923c01: 8d4c2418 LEA
        t25 = static_cast<std::uint32_t>(state.regs[4] + 0x00000018u);
        state.regs[1] = t25;
    // 0x00923c05: 51 PUSH
        batch_guest_pc = 0x00923c05u;
        t26a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00923c06: 8bce MOV
        t27 = state.regs[6];
        state.regs[1] = t27;
    // 0x00923c08: 8938 MOV
        batch_guest_pc = 0x00923c08u;
        t28 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00923c0a: e871ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00923b80u, 0x00923c0fu)) return BatchLiftStatus::invalid_memory;
        t29_call_status = spore_lift_00923b80(memory, state);
        if (t29_call_status != BatchLiftStatus::returned) return t29_call_status;
        if (state.eip != 0x00923c0fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923c0f: b001 MOV
        t30 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t30 << 0u) & 0x000000ffu);
    // 0x00923c11: 5f POP
        batch_guest_pc = 0x00923c11u;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t31a;
    // 0x00923c12: 5e POP
        batch_guest_pc = 0x00923c12u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t32a;
    // 0x00923c13: 5d POP
        batch_guest_pc = 0x00923c13u;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t33a;
    // 0x00923c14: 59 POP
        batch_guest_pc = 0x00923c14u;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t34a;
    // 0x00923c15: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00923c18: 8b7724 MOV
    L_00923c18:
        batch_guest_pc = 0x00923c18u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000024u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t36;
    // 0x00923c1b: 8d6f20 LEA
        t37 = static_cast<std::uint32_t>(state.regs[7] + 0x00000020u);
        state.regs[5] = t37;
    // 0x00923c1e: 3bf5 CMP
        t38a = state.regs[6];
        t38b = state.regs[5];
        t38r = static_cast<std::uint32_t>(t38a - t38b) & 0xffffffffu;
        batch_set_sub_flags(state, t38a, t38b, t38r, 32u);
    // 0x00923c20: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923c3a;
    // 0x00923c22: 8b5610 MOV
    L_00923c22:
        batch_guest_pc = 0x00923c22u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t40;
    // 0x00923c25: 52 PUSH
        batch_guest_pc = 0x00923c25u;
        t41a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00923c26: e855376200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00923c2bu)) return BatchLiftStatus::invalid_memory;
        t42_call_status = spore_lift_00f47380(memory, state);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00923c2bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923c2b: 56 PUSH
        batch_guest_pc = 0x00923c2bu;
        t43a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
    // 0x00923c2c: e84fd9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00921580u, 0x00923c31u)) return BatchLiftStatus::invalid_memory;
        t44_call_status = spore_lift_00921580(memory, state);
        if (t44_call_status != BatchLiftStatus::returned) return t44_call_status;
        if (state.eip != 0x00923c31u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923c31: 8bf0 MOV
        t45 = state.regs[0];
        state.regs[6] = t45;
    // 0x00923c33: 83c408 ADD
        t46a = state.regs[4];
        t46b = 0x00000008u;
        t46r = static_cast<std::uint32_t>(t46a + t46b) & 0xffffffffu;
        batch_set_add_flags(state, t46a, t46b, t46r, 32u);
        state.regs[4] = t46r;
    // 0x00923c36: 3bf5 CMP
        t47a = state.regs[6];
        t47b = state.regs[5];
        t47r = static_cast<std::uint32_t>(t47a - t47b) & 0xffffffffu;
        batch_set_sub_flags(state, t47a, t47b, t47r, 32u);
    // 0x00923c38: 75e8 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923c22;
    // 0x00923c3a: 8b7728 MOV
    L_00923c3a:
        batch_guest_pc = 0x00923c3au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000028u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t49;
    // 0x00923c3d: 83c71c ADD
        t50a = state.regs[7];
        t50b = 0x0000001cu;
        t50r = static_cast<std::uint32_t>(t50a + t50b) & 0xffffffffu;
        batch_set_add_flags(state, t50a, t50b, t50r, 32u);
        state.regs[7] = t50r;
    // 0x00923c40: 85f6 TEST
        t51a = state.regs[6];
        t51b = state.regs[6];
        t51r = (t51a & t51b) & 0xffffffffu;
        batch_set_logic_flags(state, t51r, 32u);
    // 0x00923c42: 7420 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923c64;
    // 0x00923c44: 8b06 MOV
    L_00923c44:
        batch_guest_pc = 0x00923c44u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t53;
    // 0x00923c46: 50 PUSH
        batch_guest_pc = 0x00923c46u;
        t54a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00923c47: 8bcf MOV
        t55 = state.regs[7];
        state.regs[1] = t55;
    // 0x00923c49: e8f2feffff CALL
        if (!batch_guest_call32(memory, state, 0x00923b40u, 0x00923c4eu)) return BatchLiftStatus::invalid_memory;
        t56_call_status = spore_lift_00923b40(memory, state);
        if (t56_call_status != BatchLiftStatus::returned) return t56_call_status;
        if (state.eip != 0x00923c4eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923c4e: 8b4f18 MOV
        batch_guest_pc = 0x00923c4eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t57;
    // 0x00923c51: 8b11 MOV
        batch_guest_pc = 0x00923c51u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t58;
    // 0x00923c53: 8b420c MOV
        batch_guest_pc = 0x00923c53u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t59)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t59;
    // 0x00923c56: 8b6e04 MOV
        batch_guest_pc = 0x00923c56u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t60;
    // 0x00923c59: 6a18 PUSH
        batch_guest_pc = 0x00923c59u;
        t61a = 0x00000018u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x00923c5b: 56 PUSH
        batch_guest_pc = 0x00923c5bu;
        t62a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
    // 0x00923c5c: ffd0 CALL
        t63_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00923c5eu);
        if (t63_call_status != BatchLiftStatus::returned) return t63_call_status;
    // 0x00923c5e: 8bf5 MOV
        t64 = state.regs[5];
        state.regs[6] = t64;
    // 0x00923c60: 85ed TEST
        t65a = state.regs[5];
        t65b = state.regs[5];
        t65r = (t65a & t65b) & 0xffffffffu;
        batch_set_logic_flags(state, t65r, 32u);
    // 0x00923c62: 75e0 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923c44;
    // 0x00923c64: 8d4704 LEA
    L_00923c64:
        t67 = static_cast<std::uint32_t>(state.regs[7] + 0x00000004u);
        state.regs[0] = t67;
    // 0x00923c67: 8900 MOV
        batch_guest_pc = 0x00923c67u;
        t68 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x00923c69: 894708 MOV
        batch_guest_pc = 0x00923c69u;
        t69 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t69)) return BatchLiftStatus::invalid_memory;
    // 0x00923c6c: c7470c00000000 MOV
        batch_guest_pc = 0x00923c6cu;
        t70 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t70)) return BatchLiftStatus::invalid_memory;
    // 0x00923c73: c6471000 MOV
        batch_guest_pc = 0x00923c73u;
        t71 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x00923c77: c7471400000000 MOV
        batch_guest_pc = 0x00923c77u;
        t72 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000014u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x00923c7e: 5f POP
    L_00923c7e:
        batch_guest_pc = 0x00923c7eu;
        if (!memory.load32(state.regs[4], t73a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t73a;
    // 0x00923c7f: 5e POP
        batch_guest_pc = 0x00923c7fu;
        if (!memory.load32(state.regs[4], t74a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t74a;
    // 0x00923c80: 32c0 XOR
        t75a = state.regs[0] & 0x000000ffu;
        t75b = state.regs[0] & 0x000000ffu;
        t75r = (t75a ^ t75b) & 0x000000ffu;
        batch_set_logic_flags(state, t75r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t75r << 0u) & 0x000000ffu);
    // 0x00923c82: 5d POP
        batch_guest_pc = 0x00923c82u;
        if (!memory.load32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t76a;
    // 0x00923c83: 59 POP
        batch_guest_pc = 0x00923c83u;
        if (!memory.load32(state.regs[4], t77a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t77a;
    // 0x00923c84: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
