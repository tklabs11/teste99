#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e11d4(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e0ee0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e0ee0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t26a = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30a = 0, t30r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34a = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36a = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0;
    BatchLiftStatus t44_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t50 = 0;

    // 0x011e0ee0: 6a58 PUSH
        t0a = 0x00000058u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ee2: 68a88c5001 PUSH
        t1a = 0x01508ca8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ee7: e8e8020000 CALL
        if (!batch_guest_call32(memory, state, 0x011e11d4u, 0x011e0eecu)) return BatchLiftStatus::invalid_memory;
        t2_call_status = spore_lift_011e11d4(memory, state);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x011e0eecu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0eec: 33db XOR
        t3a = state.regs[3];
        t3b = state.regs[3];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[3] = t3r;
    // 0x011e0eee: 895de4 MOV
        t4 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ef1: 895dfc MOV
        t5 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t5)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ef4: 8d4598 LEA
        t6 = static_cast<std::uint32_t>(state.regs[5] + 0xffffff98u);
        state.regs[0] = t6;
    // 0x011e0ef7: 50 PUSH
        t7a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ef8: ff159cc23c01 CALL
        t8_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetStartupInfoA", 0x013cc29cu, 0x011e0efeu);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x011e0efeu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0efe: c745fcfeffffff MOV
        t9 = 0xfffffffeu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t9)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f05: c745fc01000000 MOV
        t10 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t10)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f0c: 64a118000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000018u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x011e0f12: 8b7004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t12;
    // 0x011e0f15: bf50e77101 MOV
        t13 = 0x0171e750u;
        state.regs[7] = t13;
    // 0x011e0f1a: 6a00 PUSH
    L_011e0f1a:
        t14a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f1c: 56 PUSH
        t15a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f1d: 57 PUSH
        t16a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f1e: ff1594c13c01 CALL
        t17_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!InterlockedCompareExchange", 0x013cc194u, 0x011e0f24u);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
        if (state.eip != 0x011e0f24u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0f24: 85c0 TEST
        t18a = state.regs[0];
        t18b = state.regs[0];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
    // 0x011e0f26: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e0f40;
    // 0x011e0f28: 3bc6 CMP
        t20a = state.regs[0];
        t20b = state.regs[6];
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x011e0f2a: 7507 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e0f33;
    // 0x011e0f2c: 33f6 XOR
        t22a = state.regs[6];
        t22b = state.regs[6];
        t22r = (t22a ^ t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
        state.regs[6] = t22r;
    // 0x011e0f2e: 46 INC
        t23a = state.regs[6];
        t23r = static_cast<std::uint32_t>(t23a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t23a, t23r, 32u);
        state.regs[6] = t23r;
    // 0x011e0f2f: 8bde MOV
        t24 = state.regs[6];
        state.regs[3] = t24;
    // 0x011e0f31: eb10 JMP
        goto L_011e0f43;
    // 0x011e0f33: 68e8030000 PUSH
    L_011e0f33:
        t26a = 0x000003e8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f38: ff1584c23c01 CALL
        t27_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!Sleep", 0x013cc284u, 0x011e0f3eu);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x011e0f3eu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0f3e: ebda JMP
        goto L_011e0f1a;
    // 0x011e0f40: 33f6 XOR
    L_011e0f40:
        t29a = state.regs[6];
        t29b = state.regs[6];
        t29r = (t29a ^ t29b) & 0xffffffffu;
        batch_set_logic_flags(state, t29r, 32u);
        state.regs[6] = t29r;
    // 0x011e0f42: 46 INC
        t30a = state.regs[6];
        t30r = static_cast<std::uint32_t>(t30a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t30a, t30r, 32u);
        state.regs[6] = t30r;
    // 0x011e0f43: a14ce77101 MOV
    L_011e0f43:
        if (!memory.load32(0x0171e74cu, t31)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t31;
    // 0x011e0f48: 3bc6 CMP
        t32a = state.regs[0];
        t32b = state.regs[6];
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
    // 0x011e0f4a: 750a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e0f56;
    // 0x011e0f4c: 6a1f PUSH
        t34a = 0x0000001fu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f4e: e815040000 CALL
        t35_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_amsg_exit", 0x013cc33cu, 0x011e0f53u);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x011e0f53u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0f53: 59 POP
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t36a;
    // 0x011e0f54: eb2f JMP
        goto L_011e0f85;
    // 0x011e0f56: a14ce77101 MOV
    L_011e0f56:
        if (!memory.load32(0x0171e74cu, t38)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t38;
    // 0x011e0f5b: 85c0 TEST
        t39a = state.regs[0];
        t39b = state.regs[0];
        t39r = (t39a & t39b) & 0xffffffffu;
        batch_set_logic_flags(state, t39r, 32u);
    // 0x011e0f5d: 7520 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e0f7f;
    // 0x011e0f5f: 89354ce77101 MOV
        t41 = state.regs[6];
        if (!memory.store32(0x0171e74cu, t41)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f65: 68acb03e01 PUSH
        t42a = 0x013eb0acu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f6a: 689cb03e01 PUSH
        t43a = 0x013eb09cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0f6f: e8a0050000 CALL
        t44_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_initterm_e", 0x013cc31cu, 0x011e0f74u);
        if (t44_call_status != BatchLiftStatus::returned) return t44_call_status;
        if (state.eip != 0x011e0f74u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0f74: 59 POP
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t45a;
    // 0x011e0f75: 59 POP
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t46a;
    // 0x011e0f76: 85c0 TEST
        t47a = state.regs[0];
        t47b = state.regs[0];
        t47r = (t47a & t47b) & 0xffffffffu;
        batch_set_logic_flags(state, t47r, 32u);
    // 0x011e0f78: 740b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e0f85;
    // 0x011e0f7a: e92e010000 JMP
        goto L_011e10ad;
    // 0x011e0f7f: 893538266f01 MOV
    L_011e0f7f:
        t50 = state.regs[6];
        if (!memory.store32(0x016f2638u, t50)) return BatchLiftStatus::invalid_memory;
    L_011e0f85:
    state.eip = 0x011e0f85u;
    return BatchLiftStatus::unsupported_dependency;
    L_011e10ad:
    state.eip = 0x011e10adu;
    return BatchLiftStatus::unsupported_dependency;
    L_011e11d4:
    state.eip = 0x011e11d4u;
    return BatchLiftStatus::unsupported_dependency;
    L_011e1368:
    state.eip = 0x011e1368u;
    return BatchLiftStatus::unsupported_dependency;
    L_011e1514:
    state.eip = 0x011e1514u;
    return BatchLiftStatus::unsupported_dependency;
}
