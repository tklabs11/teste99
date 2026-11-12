#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00942e50(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009243d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009243d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;

    // 0x009243d0: 53 PUSH
        batch_guest_pc = 0x009243d0u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009243d1: 56 PUSH
        batch_guest_pc = 0x009243d1u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009243d2: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x009243d4: 8d4e08 LEA
        t3 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[1] = t3;
    // 0x009243d7: 8d4114 LEA
        t4 = static_cast<std::uint32_t>(state.regs[1] + 0x00000014u);
        state.regs[0] = t4;
    // 0x009243da: c7065cdd4301 MOV
        batch_guest_pc = 0x009243dau;
        t5 = 0x0143dd5cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x009243e0: c7460400000000 MOV
        batch_guest_pc = 0x009243e0u;
        t6 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x009243e7: 894110 MOV
        batch_guest_pc = 0x009243e7u;
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000010u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x009243ea: 8d9000080000 LEA
        t8 = static_cast<std::uint32_t>(state.regs[0] + 0x00000800u);
        state.regs[2] = t8;
    // 0x009243f0: 57 PUSH
        batch_guest_pc = 0x009243f0u;
        t9a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x009243f1: 8b7c2410 MOV
        batch_guest_pc = 0x009243f1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t10;
    // 0x009243f5: 894104 MOV
        batch_guest_pc = 0x009243f5u;
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x009243f8: 8901 MOV
        batch_guest_pc = 0x009243f8u;
        t12 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x009243fa: 895108 MOV
        batch_guest_pc = 0x009243fau;
        t13 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x009243fd: c60000 MOV
        batch_guest_pc = 0x009243fdu;
        t14 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00924400: 8bc7 MOV
        t15 = state.regs[7];
        state.regs[0] = t15;
    // 0x00924402: 8d5801 LEA
        t16 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[3] = t16;
    // 0x00924405: 8a10 MOV
    L_00924405:
        batch_guest_pc = 0x00924405u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t17 << 0u) & 0x000000ffu);
    // 0x00924407: 40 INC
        t18a = state.regs[0];
        t18r = static_cast<std::uint32_t>(t18a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t18a, t18r, 32u);
        state.regs[0] = t18r;
    // 0x00924408: 84d2 TEST
        t19a = state.regs[2] & 0x000000ffu;
        t19b = state.regs[2] & 0x000000ffu;
        t19r = (t19a & t19b) & 0x000000ffu;
        batch_set_logic_flags(state, t19r, 8u);
    // 0x0092440a: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924405;
    // 0x0092440c: 2bc3 SUB
        t21a = state.regs[0];
        t21b = state.regs[3];
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0xffffffffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 32u);
        state.regs[0] = t21r;
    // 0x0092440e: 03c7 ADD
        t22a = state.regs[0];
        t22b = state.regs[7];
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[0] = t22r;
    // 0x00924410: 50 PUSH
        batch_guest_pc = 0x00924410u;
        t23a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00924411: 57 PUSH
        batch_guest_pc = 0x00924411u;
        t24a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00924412: e839ea0100 CALL
        if (!batch_guest_call32(memory, state, 0x00942e50u, 0x00924417u)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_00942e50(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00924417u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924417: 8d8630080000 LEA
        t26 = static_cast<std::uint32_t>(state.regs[6] + 0x00000830u);
        state.regs[0] = t26;
    // 0x0092441d: 89862c080000 MOV
        batch_guest_pc = 0x0092441du;
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000082cu), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00924423: 8d8800080000 LEA
        t28 = static_cast<std::uint32_t>(state.regs[0] + 0x00000800u);
        state.regs[1] = t28;
    // 0x00924429: 898620080000 MOV
        batch_guest_pc = 0x00924429u;
        t29 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000820u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x0092442f: 89861c080000 MOV
        batch_guest_pc = 0x0092442fu;
        t30 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000081cu), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00924435: 898e24080000 MOV
        batch_guest_pc = 0x00924435u;
        t31 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000824u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x0092443b: 5f POP
        batch_guest_pc = 0x0092443bu;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t32a;
    // 0x0092443c: c60000 MOV
        batch_guest_pc = 0x0092443cu;
        t33 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x0092443f: 8bc6 MOV
        t34 = state.regs[6];
        state.regs[0] = t34;
    // 0x00924441: 5e POP
        batch_guest_pc = 0x00924441u;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t35a;
    // 0x00924442: 5b POP
        batch_guest_pc = 0x00924442u;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t36a;
    // 0x00924443: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
