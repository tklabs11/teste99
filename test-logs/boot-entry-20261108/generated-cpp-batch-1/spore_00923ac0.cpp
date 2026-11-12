#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00923af9(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923ac0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923ac0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;

    // 0x00923ac0: 51 PUSH
        batch_guest_pc = 0x00923ac0u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ac1: 53 PUSH
        batch_guest_pc = 0x00923ac1u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ac2: 8b5c2410 MOV
        batch_guest_pc = 0x00923ac2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t2;
    // 0x00923ac6: 55 PUSH
        batch_guest_pc = 0x00923ac6u;
        t3a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ac7: 8b2ddcc43c01 MOV
        batch_guest_pc = 0x00923ac7u;
        if (!memory.load32(0x013cc4dcu, t4)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t4;
    // 0x00923acd: 56 PUSH
        batch_guest_pc = 0x00923acdu;
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ace: 8b710c MOV
        batch_guest_pc = 0x00923aceu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t6;
    // 0x00923ad1: 83c104 ADD
        t7a = state.regs[1];
        t7b = 0x00000004u;
        t7r = static_cast<std::uint32_t>(t7a + t7b) & 0xffffffffu;
        batch_set_add_flags(state, t7a, t7b, t7r, 32u);
        state.regs[1] = t7r;
    // 0x00923ad4: 57 PUSH
        batch_guest_pc = 0x00923ad4u;
        t8a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ad5: 894c2410 MOV
        batch_guest_pc = 0x00923ad5u;
        t9 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00923ad9: 8bf9 MOV
        t10 = state.regs[1];
        state.regs[7] = t10;
    // 0x00923adb: 85f6 TEST
        t11a = state.regs[6];
        t11b = state.regs[6];
        t11r = (t11a & t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
    // 0x00923add: 7422 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923b01;
    // 0x00923adf: 90 NOP
    // 0x00923ae0: 8b03 MOV
    L_00923ae0:
        batch_guest_pc = 0x00923ae0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00923ae2: 8b4e10 MOV
        batch_guest_pc = 0x00923ae2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x00923ae5: 50 PUSH
        batch_guest_pc = 0x00923ae5u;
        t16a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ae6: 51 PUSH
        batch_guest_pc = 0x00923ae6u;
        t17a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ae7: ffd5 CALL
        t18_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[5], 0x00923ae9u);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
    // 0x00923ae9: 83c408 ADD
        t19a = state.regs[4];
        t19b = 0x00000008u;
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[4] = t19r;
    // 0x00923aec: 85c0 TEST
        t20a = state.regs[0];
        t20b = state.regs[0];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00923aee: 7c07 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00923af7;
    // 0x00923af0: 8bfe MOV
        t22 = state.regs[6];
        state.regs[7] = t22;
    // 0x00923af2: 8b7604 MOV
        batch_guest_pc = 0x00923af2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t23;
    // 0x00923af5: eb02 JMP
        goto L_00923af9;
    // 0x00923af7: 8b36 MOV
    L_00923af7:
        batch_guest_pc = 0x00923af7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t25;
    // 0x00923af9: 85f6 TEST
    L_00923af9:
        t26a = state.regs[6];
        t26b = state.regs[6];
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
    // 0x00923afb: 75e3 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923ae0;
    // 0x00923afd: 8b4c2410 MOV
        batch_guest_pc = 0x00923afdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t28;
    // 0x00923b01: 3bf9 CMP
    L_00923b01:
        t29a = state.regs[7];
        t29b = state.regs[1];
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
    // 0x00923b03: 7422 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923b27;
    // 0x00923b05: 8b4710 MOV
        batch_guest_pc = 0x00923b05u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t31;
    // 0x00923b08: 8b0b MOV
        batch_guest_pc = 0x00923b08u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t32;
    // 0x00923b0a: 50 PUSH
        batch_guest_pc = 0x00923b0au;
        t33a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b0b: 51 PUSH
        batch_guest_pc = 0x00923b0bu;
        t34a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b0c: ffd5 CALL
        t35_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[5], 0x00923b0eu);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
    // 0x00923b0e: 83c408 ADD
        t36a = state.regs[4];
        t36b = 0x00000008u;
        t36r = static_cast<std::uint32_t>(t36a + t36b) & 0xffffffffu;
        batch_set_add_flags(state, t36a, t36b, t36r, 32u);
        state.regs[4] = t36r;
    // 0x00923b11: 85c0 TEST
        t37a = state.regs[0];
        t37b = state.regs[0];
        t37r = (t37a & t37b) & 0xffffffffu;
        batch_set_logic_flags(state, t37r, 32u);
    // 0x00923b13: 7c0e JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00923b23;
    // 0x00923b15: 8b442418 MOV
        batch_guest_pc = 0x00923b15u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x00923b19: 8938 MOV
        batch_guest_pc = 0x00923b19u;
        t40 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00923b1b: 5f POP
        batch_guest_pc = 0x00923b1bu;
        if (!memory.load32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t41a;
    // 0x00923b1c: 5e POP
        batch_guest_pc = 0x00923b1cu;
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t42a;
    // 0x00923b1d: 5d POP
        batch_guest_pc = 0x00923b1du;
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t43a;
    // 0x00923b1e: 5b POP
        batch_guest_pc = 0x00923b1eu;
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t44a;
    // 0x00923b1f: 59 POP
        batch_guest_pc = 0x00923b1fu;
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t45a;
    // 0x00923b20: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00923b23: 8b4c2410 MOV
    L_00923b23:
        batch_guest_pc = 0x00923b23u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t47;
    // 0x00923b27: 8b442418 MOV
    L_00923b27:
        batch_guest_pc = 0x00923b27u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x00923b2b: 5f POP
        batch_guest_pc = 0x00923b2bu;
        if (!memory.load32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t49a;
    // 0x00923b2c: 5e POP
        batch_guest_pc = 0x00923b2cu;
        if (!memory.load32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t50a;
    // 0x00923b2d: 5d POP
        batch_guest_pc = 0x00923b2du;
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t51a;
    // 0x00923b2e: 8908 MOV
        batch_guest_pc = 0x00923b2eu;
        t52 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00923b30: 5b POP
        batch_guest_pc = 0x00923b30u;
        if (!memory.load32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t53a;
    // 0x00923b31: 59 POP
        batch_guest_pc = 0x00923b31u;
        if (!memory.load32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t54a;
    // 0x00923b32: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
