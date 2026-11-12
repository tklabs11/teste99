#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0060a150(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0093a560(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009244d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009244d0u);
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
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    BatchLiftStatus t32_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0;

    // 0x009244d0: 53 PUSH
        batch_guest_pc = 0x009244d0u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009244d1: 56 PUSH
        batch_guest_pc = 0x009244d1u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009244d2: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x009244d4: 8d4e08 LEA
        t3 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[1] = t3;
    // 0x009244d7: 8d4114 LEA
        t4 = static_cast<std::uint32_t>(state.regs[1] + 0x00000014u);
        state.regs[0] = t4;
    // 0x009244da: c7067cdd4301 MOV
        batch_guest_pc = 0x009244dau;
        t5 = 0x0143dd7cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x009244e0: c7460400000000 MOV
        batch_guest_pc = 0x009244e0u;
        t6 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x009244e7: 894110 MOV
        batch_guest_pc = 0x009244e7u;
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000010u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x009244ea: 8d9000020000 LEA
        t8 = static_cast<std::uint32_t>(state.regs[0] + 0x00000200u);
        state.regs[2] = t8;
    // 0x009244f0: 57 PUSH
        batch_guest_pc = 0x009244f0u;
        t9a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x009244f1: 8b7c2410 MOV
        batch_guest_pc = 0x009244f1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t10;
    // 0x009244f5: 894104 MOV
        batch_guest_pc = 0x009244f5u;
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x009244f8: 8901 MOV
        batch_guest_pc = 0x009244f8u;
        t12 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x009244fa: 895108 MOV
        batch_guest_pc = 0x009244fau;
        t13 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x009244fd: c60000 MOV
        batch_guest_pc = 0x009244fdu;
        t14 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00924500: 8bc7 MOV
        t15 = state.regs[7];
        state.regs[0] = t15;
    // 0x00924502: 8d5801 LEA
        t16 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[3] = t16;
    // 0x00924505: 8a10 MOV
    L_00924505:
        batch_guest_pc = 0x00924505u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t17 << 0u) & 0x000000ffu);
    // 0x00924507: 40 INC
        t18a = state.regs[0];
        t18r = static_cast<std::uint32_t>(t18a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t18a, t18r, 32u);
        state.regs[0] = t18r;
    // 0x00924508: 84d2 TEST
        t19a = state.regs[2] & 0x000000ffu;
        t19b = state.regs[2] & 0x000000ffu;
        t19r = (t19a & t19b) & 0x000000ffu;
        batch_set_logic_flags(state, t19r, 8u);
    // 0x0092450a: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924505;
    // 0x0092450c: 2bc3 SUB
        t21a = state.regs[0];
        t21b = state.regs[3];
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0xffffffffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 32u);
        state.regs[0] = t21r;
    // 0x0092450e: 03c7 ADD
        t22a = state.regs[0];
        t22b = state.regs[7];
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[0] = t22r;
    // 0x00924510: 50 PUSH
        batch_guest_pc = 0x00924510u;
        t23a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00924511: 57 PUSH
        batch_guest_pc = 0x00924511u;
        t24a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00924512: e8395cceff CALL
        if (!batch_guest_call32(memory, state, 0x0060a150u, 0x00924517u)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_0060a150(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00924517u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924517: 6a01 PUSH
        batch_guest_pc = 0x00924517u;
        t26a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00924519: 33c0 XOR
        t27a = state.regs[0];
        t27b = state.regs[0];
        t27r = (t27a ^ t27b) & 0xffffffffu;
        batch_set_logic_flags(state, t27r, 32u);
        state.regs[0] = t27r;
    // 0x0092451b: 6a04 PUSH
        batch_guest_pc = 0x0092451bu;
        t28a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x0092451d: 8d8e28020000 LEA
        t29 = static_cast<std::uint32_t>(state.regs[6] + 0x00000228u);
        state.regs[1] = t29;
    // 0x00924523: 6689861c020000 MOV
        batch_guest_pc = 0x00924523u;
        t30 = state.regs[0] & 0x0000ffffu;
        if (!memory.store16(static_cast<std::uint32_t>(state.regs[6] + 0x0000021cu), t30)) return BatchLiftStatus::invalid_memory;
    // 0x0092452a: c7862002000064000000 MOV
        batch_guest_pc = 0x0092452au;
        t31 = 0x00000064u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000220u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x00924534: e827600100 CALL
        if (!batch_guest_call32(memory, state, 0x0093a560u, 0x00924539u)) return BatchLiftStatus::invalid_memory;
        t32_call_status = spore_lift_0093a560(memory, state);
        if (t32_call_status != BatchLiftStatus::returned) return t32_call_status;
        if (state.eip != 0x00924539u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924539: 8d8654020000 LEA
        t33 = static_cast<std::uint32_t>(state.regs[6] + 0x00000254u);
        state.regs[0] = t33;
    // 0x0092453f: 898650020000 MOV
        batch_guest_pc = 0x0092453fu;
        t34 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000250u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00924545: 8d8800080000 LEA
        t35 = static_cast<std::uint32_t>(state.regs[0] + 0x00000800u);
        state.regs[1] = t35;
    // 0x0092454b: 898644020000 MOV
        batch_guest_pc = 0x0092454bu;
        t36 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000244u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00924551: 898640020000 MOV
        batch_guest_pc = 0x00924551u;
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000240u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00924557: 898e48020000 MOV
        batch_guest_pc = 0x00924557u;
        t38 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000248u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x0092455d: 5f POP
        batch_guest_pc = 0x0092455du;
        if (!memory.load32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t39a;
    // 0x0092455e: c60000 MOV
        batch_guest_pc = 0x0092455eu;
        t40 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00924561: 8bc6 MOV
        t41 = state.regs[6];
        state.regs[0] = t41;
    // 0x00924563: 5e POP
        batch_guest_pc = 0x00924563u;
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t42a;
    // 0x00924564: 5b POP
        batch_guest_pc = 0x00924564u;
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t43a;
    // 0x00924565: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
