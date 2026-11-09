#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402b23(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00402b30(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004e19a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0068f4d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690120(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_004029e6(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004029e6u);
    std::uint32_t t0a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    BatchLiftStatus t22_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    BatchLiftStatus t29_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52a = 0;

    // 0x004029e6: 6843fa0b00 PUSH
        t0a = 0x000bfa43u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x004029eb: e933010000 JMP
        state.eip = 0x00402b23u;
        return spore_lift_00402b23(memory, state);
    // 0x004029f0: 55 PUSH
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x004029f1: 8bec MOV
        t3 = state.regs[4];
        state.regs[5] = t3;
    // 0x004029f3: 83ec1c SUB
        t4a = state.regs[4];
        t4b = 0x0000001cu;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
        state.regs[4] = t4r;
    // 0x004029f6: 894de8 MOV
        t5 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x004029f9: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x004029fc: e82f010000 CALL
        if (!batch_guest_call32(memory, state, 0x00402b30u, 0x00402a01u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_00402b30(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00402a01u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402a01: e8caca2800 CALL
        if (!batch_guest_call32(memory, state, 0x0068f4d0u, 0x00402a06u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_0068f4d0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00402a06u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402a06: 8945e4 MOV
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00402a09: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x00402a0c: 83c00c ADD
        t11a = state.regs[0];
        t11b = 0x0000000cu;
        t11r = static_cast<std::uint32_t>(t11a + t11b) & 0xffffffffu;
        batch_set_add_flags(state, t11a, t11b, t11r, 32u);
        state.regs[0] = t11r;
    // 0x00402a0f: 8945f8 MOV
        t12 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00402a12: 8b4df8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00402a15: 833900 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t14a)) return BatchLiftStatus::invalid_memory;
        t14b = 0x00000000u;
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
    // 0x00402a18: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402a33;
    // 0x00402a1a: 8b55f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t16;
    // 0x00402a1d: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x00402a1f: 8945fc MOV
        t18 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00402a22: 8b4df8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x00402a25: c70100000000 MOV
        t20 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00402a2b: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t21;
    // 0x00402a2e: e8edd62800 CALL
        if (!batch_guest_call32(memory, state, 0x00690120u, 0x00402a33u)) return BatchLiftStatus::invalid_memory;
        t22_call_status = spore_lift_00690120(memory, state);
        if (t22_call_status != BatchLiftStatus::returned) return t22_call_status;
        if (state.eip != 0x00402a33u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402a33: 8b55f8 MOV
    L_00402a33:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t23;
    // 0x00402a36: 52 PUSH
        t24a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00402a37: 8b45e4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x00402a3a: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t26;
    // 0x00402a3c: 8b4de4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t27;
    // 0x00402a3f: 8b4210 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000010u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x00402a42: ffd0 CALL
        t29_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00402a44u);
        if (t29_call_status != BatchLiftStatus::returned) return t29_call_status;
    // 0x00402a44: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x00402a47: 8b510c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t31;
    // 0x00402a4a: 8955f4 MOV
        t32 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x00402a4d: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x00402a50: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t34;
    // 0x00402a53: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t35;
    // 0x00402a55: 8911 MOV
        t36 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00402a57: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t37;
    // 0x00402a5a: 895104 MOV
        t38 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x00402a5d: 8b4008 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x00402a60: 894108 MOV
        t40 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00402a63: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t41;
    // 0x00402a66: 51 PUSH
        t42a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x00402a67: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43;
    // 0x00402a6a: 83c110 ADD
        t44a = state.regs[1];
        t44b = 0x00000010u;
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        state.regs[1] = t44r;
    // 0x00402a6d: e82eef0d00 CALL
        if (!batch_guest_call32(memory, state, 0x004e19a0u, 0x00402a72u)) return BatchLiftStatus::invalid_memory;
        t45_call_status = spore_lift_004e19a0(memory, state);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
        if (state.eip != 0x00402a72u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402a72: 8b55e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t46;
    // 0x00402a75: c6426401 MOV
        t47 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x00000064u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x00402a79: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x00402a7c: 8a4d0c MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t49 << 0u) & 0x000000ffu);
    // 0x00402a7f: 884865 MOV
        t50 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000065u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00402a82: 8be5 MOV
        t51 = state.regs[5];
        state.regs[4] = t51;
    // 0x00402a84: 5d POP
        if (!memory.load32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t52a;
    // 0x00402a85: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
