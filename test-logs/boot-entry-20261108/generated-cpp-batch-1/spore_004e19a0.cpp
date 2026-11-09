#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004e1a00(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004e1a15(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004e3e10(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_004e19a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004e19a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39 = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0;

    // 0x004e19a0: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x004e19a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x004e19a3: 83ec10 SUB
        t2a = state.regs[4];
        t2b = 0x00000010u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x004e19a6: 894df4 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x004e19a9: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x004e19ac: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x004e19af: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t6;
    // 0x004e19b2: 3b5108 CMP
        t7a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t7b)) return BatchLiftStatus::invalid_memory;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x004e19b5: 734b JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_004e1a02;
    // 0x004e19b7: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x004e19ba: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t10;
    // 0x004e19bd: 894df8 MOV
        t11 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x004e19c0: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t12;
    // 0x004e19c3: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x004e19c6: 83c00c ADD
        t14a = state.regs[0];
        t14b = 0x0000000cu;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[0] = t14r;
    // 0x004e19c9: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x004e19cc: 894104 MOV
        t16 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x004e19cf: 8b55f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x004e19d2: 8955fc MOV
        t18 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
    // 0x004e19d5: 837dfc00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t19a)) return BatchLiftStatus::invalid_memory;
        t19b = 0x00000000u;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x004e19d9: 741e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004e19f9;
    // 0x004e19db: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x004e19de: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x004e19e1: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t23;
    // 0x004e19e3: 8911 MOV
        t24 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x004e19e5: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t25;
    // 0x004e19e8: 895104 MOV
        t26 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x004e19eb: 8b4008 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t27;
    // 0x004e19ee: 894108 MOV
        t28 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x004e19f1: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t29;
    // 0x004e19f4: 894df0 MOV
        t30 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x004e19f7: eb07 JMP
        goto L_004e1a00;
    // 0x004e19f9: c745f000000000 MOV
    L_004e19f9:
        t32 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x004e1a00: eb13 JMP
    L_004e1a00:
        goto L_004e1a15;
    // 0x004e1a02: 8b5508 MOV
    L_004e1a02:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x004e1a05: 52 PUSH
        t35a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x004e1a06: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t36;
    // 0x004e1a09: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t37;
    // 0x004e1a0c: 51 PUSH
        t38a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x004e1a0d: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t39;
    // 0x004e1a10: e8fb230000 CALL
        if (!batch_guest_call32(memory, state, 0x004e3e10u, 0x004e1a15u)) return BatchLiftStatus::invalid_memory;
        t40_call_status = spore_lift_004e3e10(memory, state);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
        if (state.eip != 0x004e1a15u) return BatchLiftStatus::invalid_control_flow;
    // 0x004e1a15: 8be5 MOV
    L_004e1a15:
        t41 = state.regs[5];
        state.regs[4] = t41;
    // 0x004e1a17: 5d POP
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t42a;
    // 0x004e1a18: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
