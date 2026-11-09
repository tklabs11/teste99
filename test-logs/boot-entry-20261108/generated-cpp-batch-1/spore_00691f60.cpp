#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0068f670(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00691d30(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00691fa7(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922690(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00691f60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00691f60u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0;
    BatchLiftStatus t48_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52a = 0, t52b = 0, t52c = 0, t52r = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62a = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t67 = 0;
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
    BatchLiftStatus t79_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t80a = 0;
    std::uint32_t t81 = 0;
    BatchLiftStatus t82_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t83 = 0;
    std::uint32_t t84a = 0;
    BatchLiftStatus t85_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t86 = 0;
    std::uint32_t t87a = 0, t87b = 0, t87r = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90a = 0;
    std::uint32_t t91a = 0;
    std::uint32_t t92a = 0;
    std::uint32_t t93a = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;

    // 0x00691f60: 83ec14 SUB
        t0a = state.regs[4];
        t0b = 0x00000014u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00691f63: 55 PUSH
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00691f64: 57 PUSH
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00691f65: 8b7c2424 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t3;
    // 0x00691f69: 8be9 MOV
        t4 = state.regs[1];
        state.regs[5] = t4;
    // 0x00691f6b: 8a4f38 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000038u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t5 << 0u) & 0x000000ffu);
    // 0x00691f6e: 32c0 XOR
        t6a = state.regs[0] & 0x000000ffu;
        t6b = state.regs[0] & 0x000000ffu;
        t6r = (t6a ^ t6b) & 0x000000ffu;
        batch_set_logic_flags(state, t6r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t6r << 0u) & 0x000000ffu);
    // 0x00691f70: 8844240b MOV
        t7 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000bu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00691f74: 84c9 TEST
        t8a = state.regs[1] & 0x000000ffu;
        t8b = state.regs[1] & 0x000000ffu;
        t8r = (t8a & t8b) & 0x000000ffu;
        batch_set_logic_flags(state, t8r, 8u);
    // 0x00691f76: 0f85ed000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00692069;
    // 0x00691f7c: 53 PUSH
        t10a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00691f7d: 56 PUSH
        t11a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00691f7e: 8bff MOV
        t12 = state.regs[7];
        state.regs[7] = t12;
    // 0x00691f80: 8d4564 LEA
    L_00691f80:
        t13 = static_cast<std::uint32_t>(state.regs[5] + 0x00000064u);
        state.regs[0] = t13;
    // 0x00691f83: 8bcd MOV
        t14 = state.regs[5];
        state.regs[1] = t14;
    // 0x00691f85: 394004 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t15a)) return BatchLiftStatus::invalid_memory;
        t15b = state.regs[0];
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x00691f88: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00691f9c;
    // 0x00691f8a: 8b30 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t17;
    // 0x00691f8c: 8b5648 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000048u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x00691f8f: 52 PUSH
        t19a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00691f90: 57 PUSH
        t20a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00691f91: e8dad6ffff CALL
        t21_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0068f670u, 0x00691f96u);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x00691f96u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691f96: 85c0 TEST
        t22a = state.regs[0];
        t22b = state.regs[0];
        t22r = (t22a & t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
    // 0x00691f98: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00691fa9;
    // 0x00691f9a: eb0b JMP
        goto L_00691fa7;
    // 0x00691f9c: 6800000080 PUSH
    L_00691f9c:
        t25a = 0x80000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00691fa1: 57 PUSH
        t26a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00691fa2: e8c9d6ffff CALL
        t27_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0068f670u, 0x00691fa7u);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x00691fa7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691fa7: 8bf0 MOV
    L_00691fa7:
        t28 = state.regs[0];
        state.regs[6] = t28;
    // 0x00691fa9: 85f6 TEST
    L_00691fa9:
        t29a = state.regs[6];
        t29b = state.regs[6];
        t29r = (t29a & t29b) & 0xffffffffu;
        batch_set_logic_flags(state, t29r, 32u);
    // 0x00691fab: 745d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069200a;
    // 0x00691fad: 8b4c2428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t31;
    // 0x00691fb1: 8b4648 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000048u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x00691fb4: 8b5f30 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000030u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t33;
    // 0x00691fb7: 56 PUSH
        t34a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00691fb8: 57 PUSH
        t35a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00691fb9: 51 PUSH
        t36a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00691fba: 8bcd MOV
        t37 = state.regs[5];
        state.regs[1] = t37;
    // 0x00691fbc: 894730 MOV
        t38 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000030u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x00691fbf: e86cfdffff CALL
        t39_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00691d30u, 0x00691fc4u);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
        if (state.eip != 0x00691fc4u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691fc4: 8b742430 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t40;
    // 0x00691fc8: 895f30 MOV
        t41 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000030u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x00691fcb: b301 MOV
        t42 = 0x00000001u;
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t42 << 0u) & 0x000000ffu);
    // 0x00691fcd: 885c2413 MOV
        t43 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x00691fd1: 85f6 TEST
        t44a = state.regs[6];
        t44b = state.regs[6];
        t44r = (t44a & t44b) & 0xffffffffu;
        batch_set_logic_flags(state, t44r, 32u);
    // 0x00691fd3: 0f847f000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00692058;
    // 0x00691fd9: 8d542414 LEA
        t46 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[2] = t46;
    // 0x00691fdd: 52 PUSH
        t47a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
    // 0x00691fde: ff15b8c23c01 CALL
        t48_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!QueryPerformanceCounter", 0x013cc2b8u, 0x00691fe4u);
        if (t48_call_status != BatchLiftStatus::returned) return t48_call_status;
        if (state.eip != 0x00691fe4u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691fe4: 8b4618 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t49;
    // 0x00691fe7: 2b442414 SUB
        t50a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t50b)) return BatchLiftStatus::invalid_memory;
        t50r = static_cast<std::uint32_t>(t50a - t50b) & 0xffffffffu;
        batch_set_sub_flags(state, t50a, t50b, t50r, 32u);
        state.regs[0] = t50r;
    // 0x00691feb: 8b4e1c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t51;
    // 0x00691fee: 1b4c2418 SBB
        t52a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t52b)) return BatchLiftStatus::invalid_memory;
        t52c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t52r = static_cast<std::uint32_t>(t52a - t52b - t52c) & 0xffffffffu;
        batch_set_sbb_flags(state, t52a, t52b, t52c, t52r, 32u);
        state.regs[1] = t52r;
    // 0x00691ff2: 894c2420 MOV
        t53 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00691ff6: 7806 JS
        if (((state.eflags & 0x080u) != 0u)) goto L_00691ffe;
    // 0x00691ff8: 7f5e JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00692058;
    // 0x00691ffa: 85c0 TEST
        t56a = state.regs[0];
        t56b = state.regs[0];
        t56r = (t56a & t56b) & 0xffffffffu;
        batch_set_logic_flags(state, t56r, 32u);
    // 0x00691ffc: 735a JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00692058;
    // 0x00691ffe: 5e POP
    L_00691ffe:
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t58a;
    // 0x00691fff: 8ac3 MOV
        t59 = state.regs[3] & 0x000000ffu;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t59 << 0u) & 0x000000ffu);
    // 0x00692001: 5b POP
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t60a;
    // 0x00692002: 5f POP
        if (!memory.load32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t61a;
    // 0x00692003: 5d POP
        if (!memory.load32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t62a;
    // 0x00692004: 83c414 ADD
        t63a = state.regs[4];
        t63b = 0x00000014u;
        t63r = static_cast<std::uint32_t>(t63a + t63b) & 0xffffffffu;
        batch_set_add_flags(state, t63a, t63b, t63r, 32u);
        state.regs[4] = t63r;
    // 0x00692007: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0069200a: 807c243400 CMP
    L_0069200a:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t65a)) return BatchLiftStatus::invalid_memory;
        t65b = 0x00000000u;
        t65r = static_cast<std::uint32_t>(t65a - t65b) & 0x000000ffu;
        batch_set_sub_flags(state, t65a, t65b, t65r, 8u);
    // 0x0069200f: 7552 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00692063;
    // 0x00692011: 8b5c2428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t67;
    // 0x00692015: 8d7708 LEA
        t68 = static_cast<std::uint32_t>(state.regs[7] + 0x00000008u);
        state.regs[6] = t68;
    // 0x00692018: c7460400000000 MOV
        t69 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t69)) return BatchLiftStatus::invalid_memory;
    // 0x0069201f: c70600000000 MOV
        t70 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x00692025: 8b5540 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000040u), t71)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t71;
    // 0x00692028: 8d453c LEA
        t72 = static_cast<std::uint32_t>(state.regs[5] + 0x0000003cu);
        state.regs[0] = t72;
    // 0x0069202b: 895604 MOV
        t73 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t73)) return BatchLiftStatus::invalid_memory;
    // 0x0069202e: 8906 MOV
        t74 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t74)) return BatchLiftStatus::invalid_memory;
    // 0x00692030: 897004 MOV
        t75 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x00692033: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t76)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t76;
    // 0x00692036: 8930 MOV
        t77 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x00692038: 8b0b MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t78;
    // 0x0069203a: e831022900 CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x0069203fu)) return BatchLiftStatus::invalid_memory;
        t79_call_status = spore_lift_00922270(memory, state);
        if (t79_call_status != BatchLiftStatus::returned) return t79_call_status;
        if (state.eip != 0x0069203fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069203f: 6850374001 PUSH
        t80a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
    // 0x00692044: 8d4e08 LEA
        t81 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[1] = t81;
    // 0x00692047: e844062900 CALL
        if (!batch_guest_call32(memory, state, 0x00922690u, 0x0069204cu)) return BatchLiftStatus::invalid_memory;
        t82_call_status = spore_lift_00922690(memory, state);
        if (t82_call_status != BatchLiftStatus::returned) return t82_call_status;
        if (state.eip != 0x0069204cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069204c: 8b0b MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t83;
    // 0x0069204e: 6850374001 PUSH
        t84a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t84a)) return BatchLiftStatus::invalid_memory;
    // 0x00692053: e858012900 CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00692058u)) return BatchLiftStatus::invalid_memory;
        t85_call_status = spore_lift_009221b0(memory, state);
        if (t85_call_status != BatchLiftStatus::returned) return t85_call_status;
        if (state.eip != 0x00692058u) return BatchLiftStatus::invalid_control_flow;
    // 0x00692058: 8a4f38 MOV
    L_00692058:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000038u), t86)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t86 << 0u) & 0x000000ffu);
    // 0x0069205b: 84c9 TEST
        t87a = state.regs[1] & 0x000000ffu;
        t87b = state.regs[1] & 0x000000ffu;
        t87r = (t87a & t87b) & 0x000000ffu;
        batch_set_logic_flags(state, t87r, 8u);
    // 0x0069205d: 0f841dffffff JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00691f80;
    // 0x00692063: 8a442413 MOV
    L_00692063:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t89 << 0u) & 0x000000ffu);
    // 0x00692067: 5e POP
        if (!memory.load32(state.regs[4], t90a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t90a;
    // 0x00692068: 5b POP
        if (!memory.load32(state.regs[4], t91a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t91a;
    // 0x00692069: 5f POP
    L_00692069:
        if (!memory.load32(state.regs[4], t92a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t92a;
    // 0x0069206a: 5d POP
        if (!memory.load32(state.regs[4], t93a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t93a;
    // 0x0069206b: 83c414 ADD
        t94a = state.regs[4];
        t94b = 0x00000014u;
        t94r = static_cast<std::uint32_t>(t94a + t94b) & 0xffffffffu;
        batch_set_add_flags(state, t94a, t94b, t94r, 32u);
        state.regs[4] = t94r;
    // 0x0069206e: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
