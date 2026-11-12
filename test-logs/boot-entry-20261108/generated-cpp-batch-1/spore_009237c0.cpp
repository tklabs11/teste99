#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923825(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009237c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009237c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;
    BatchLiftStatus t22_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t23a = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40 = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0;

    // 0x009237c0: 53 PUSH
        batch_guest_pc = 0x009237c0u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009237c1: 55 PUSH
        batch_guest_pc = 0x009237c1u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009237c2: 56 PUSH
        batch_guest_pc = 0x009237c2u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009237c3: 57 PUSH
        batch_guest_pc = 0x009237c3u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009237c4: 8bf9 MOV
        t4 = state.regs[1];
        state.regs[7] = t4;
    // 0x009237c6: 8d6f38 LEA
        t5 = static_cast<std::uint32_t>(state.regs[7] + 0x00000038u);
        state.regs[5] = t5;
    // 0x009237c9: 6878dc4301 PUSH
        batch_guest_pc = 0x009237c9u;
        t6a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x009237ce: 8bcd MOV
        t7 = state.regs[5];
        state.regs[1] = t7;
    // 0x009237d0: e8dbe9ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x009237d5u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_009221b0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x009237d5u) return BatchLiftStatus::invalid_control_flow;
    // 0x009237d5: 8b442418 MOV
        batch_guest_pc = 0x009237d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x009237d9: c70000000000 MOV
        batch_guest_pc = 0x009237d9u;
        t10 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x009237df: 8b7718 MOV
        batch_guest_pc = 0x009237dfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t11;
    // 0x009237e2: 8b5f1c MOV
        batch_guest_pc = 0x009237e2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000001cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t12;
    // 0x009237e5: 3bf3 CMP
        t13a = state.regs[6];
        t13b = state.regs[3];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x009237e7: 743c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923825;
    // 0x009237e9: 8da42400000000 LEA
        t15 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t15;
    // 0x009237f0: 8b3e MOV
    L_009237f0:
        batch_guest_pc = 0x009237f0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t16;
    // 0x009237f2: 8b4c2414 MOV
        batch_guest_pc = 0x009237f2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x009237f6: 8b17 MOV
        batch_guest_pc = 0x009237f6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x009237f8: 8b421c MOV
        batch_guest_pc = 0x009237f8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000001cu), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x009237fb: 51 PUSH
        batch_guest_pc = 0x009237fbu;
        t20a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x009237fc: 8bcf MOV
        t21 = state.regs[7];
        state.regs[1] = t21;
    // 0x009237fe: ffd0 CALL
        t22_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00923800u);
        if (t22_call_status != BatchLiftStatus::returned) return t22_call_status;
    // 0x00923800: 50 PUSH
        batch_guest_pc = 0x00923800u;
        t23a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00923801: ff15dcc43c01 CALL
        t24_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_stricmp", 0x013cc4dcu, 0x00923807u);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x00923807u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923807: 83c408 ADD
        t25a = state.regs[4];
        t25b = 0x00000008u;
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[4] = t25r;
    // 0x0092380a: 85c0 TEST
        t26a = state.regs[0];
        t26b = state.regs[0];
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
    // 0x0092380c: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923817;
    // 0x0092380e: 83c604 ADD
        t28a = state.regs[6];
        t28b = 0x00000004u;
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[6] = t28r;
    // 0x00923811: 3bf3 CMP
        t29a = state.regs[6];
        t29b = state.regs[3];
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
    // 0x00923813: 75db JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009237f0;
    // 0x00923815: eb0e JMP
        goto L_00923825;
    // 0x00923817: 8b17 MOV
    L_00923817:
        batch_guest_pc = 0x00923817u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t32;
    // 0x00923819: 8b02 MOV
        batch_guest_pc = 0x00923819u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x0092381b: 8bcf MOV
        t34 = state.regs[7];
        state.regs[1] = t34;
    // 0x0092381d: ffd0 CALL
        t35_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0092381fu);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
    // 0x0092381f: 8b4c2418 MOV
        batch_guest_pc = 0x0092381fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t36;
    // 0x00923823: 8939 MOV
        batch_guest_pc = 0x00923823u;
        t37 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00923825: 8b542418 MOV
    L_00923825:
        batch_guest_pc = 0x00923825u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t38;
    // 0x00923829: 833a00 CMP
        batch_guest_pc = 0x00923829u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t39a)) return BatchLiftStatus::invalid_memory;
        t39b = 0x00000000u;
        t39r = static_cast<std::uint32_t>(t39a - t39b) & 0xffffffffu;
        batch_set_sub_flags(state, t39a, t39b, t39r, 32u);
    // 0x0092382c: 8bcd MOV
        t40 = state.regs[5];
        state.regs[1] = t40;
    // 0x0092382e: 0f95c3 SETNZ
        state.regs[3] = (state.regs[3] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00923831: e83aeaffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00923836u)) return BatchLiftStatus::invalid_memory;
        t42_call_status = spore_lift_00922270(memory, state);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00923836u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923836: 5f POP
        batch_guest_pc = 0x00923836u;
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t43a;
    // 0x00923837: 5e POP
        batch_guest_pc = 0x00923837u;
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t44a;
    // 0x00923838: 5d POP
        batch_guest_pc = 0x00923838u;
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t45a;
    // 0x00923839: 8ac3 MOV
        t46 = state.regs[3] & 0x000000ffu;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t46 << 0u) & 0x000000ffu);
    // 0x0092383b: 5b POP
        batch_guest_pc = 0x0092383bu;
        if (!memory.load32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t47a;
    // 0x0092383c: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
