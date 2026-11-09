#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402420(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00425a22(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00425a2b(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0042eaa0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_004259e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004259e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0;
    BatchLiftStatus t41_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46a = 0, t46c = 0, t46r = 0;
    std::uint32_t t47a = 0, t47c = 0, t47r = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0;

    // 0x004259e0: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x004259e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x004259e3: 83ec28 SUB
        t2a = state.regs[4];
        t2b = 0x00000028u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x004259e6: 894dd8 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x004259e9: 8b45d8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x004259ec: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x004259ef: 894de4 MOV
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x004259f2: c645fa00 MOV
        t7 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffau), t7)) return BatchLiftStatus::invalid_memory;
    // 0x004259f6: c645fb00 MOV
        t8 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffbu), t8)) return BatchLiftStatus::invalid_memory;
    // 0x004259fa: 8b5508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x004259fd: 52 PUSH
        t10a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x004259fe: 8b45e4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00425a01: 50 PUSH
        t12a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00425a02: 8b4d0c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00425a05: 51 PUSH
        t14a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00425a06: e895900000 CALL
        if (!batch_guest_call32(memory, state, 0x0042eaa0u, 0x00425a0bu)) return BatchLiftStatus::invalid_memory;
        t15_call_status = spore_lift_0042eaa0(memory, state);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x00425a0bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00425a0b: 83c40c ADD
        t16a = state.regs[4];
        t16b = 0x0000000cu;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[4] = t16r;
    // 0x00425a0e: 8945fc MOV
        t17 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00425a11: 8b55d8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x00425a14: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x00425a17: 8945dc MOV
        t20 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00425a1a: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t21;
    // 0x00425a1d: 894de0 MOV
        t22 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00425a20: eb09 JMP
        goto L_00425a2b;
    // 0x00425a22: 8b55e0 MOV
    L_00425a22:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t24;
    // 0x00425a25: 83c204 ADD
        t25a = state.regs[2];
        t25b = 0x00000004u;
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[2] = t25r;
    // 0x00425a28: 8955e0 MOV
        t26 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00425a2b: 8b45e0 MOV
    L_00425a2b:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t27;
    // 0x00425a2e: 3b45dc CMP
        t28a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t28b)) return BatchLiftStatus::invalid_memory;
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x00425a31: 7327 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00425a5a;
    // 0x00425a33: 8b4de0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x00425a36: 833900 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t31a)) return BatchLiftStatus::invalid_memory;
        t31b = 0x00000000u;
        t31r = static_cast<std::uint32_t>(t31a - t31b) & 0xffffffffu;
        batch_set_sub_flags(state, t31a, t31b, t31r, 32u);
    // 0x00425a39: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425a45;
    // 0x00425a3b: 8b55e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t33;
    // 0x00425a3e: 8b0a MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t34;
    // 0x00425a40: e8dbc9fdff CALL
        if (!batch_guest_call32(memory, state, 0x00402420u, 0x00425a45u)) return BatchLiftStatus::invalid_memory;
        t35_call_status = spore_lift_00402420(memory, state);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x00425a45u) return BatchLiftStatus::invalid_control_flow;
    // 0x00425a45: 33c0 XOR
    L_00425a45:
        t36a = state.regs[0];
        t36b = state.regs[0];
        t36r = (t36a ^ t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
        state.regs[0] = t36r;
    // 0x00425a47: 83e001 AND
        t37a = state.regs[0];
        t37b = 0x00000001u;
        t37r = (t37a & t37b) & 0xffffffffu;
        batch_set_logic_flags(state, t37r, 32u);
        state.regs[0] = t37r;
    // 0x00425a4a: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425a58;
    // 0x00425a4c: 8b4de0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t39;
    // 0x00425a4f: 51 PUSH
        t40a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00425a50: e82b19b200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00425a55u)) return BatchLiftStatus::invalid_memory;
        t41_call_status = spore_lift_00f47380(memory, state);
        if (t41_call_status != BatchLiftStatus::returned) return t41_call_status;
        if (state.eip != 0x00425a55u) return BatchLiftStatus::invalid_control_flow;
    // 0x00425a55: 83c404 ADD
        t42a = state.regs[4];
        t42b = 0x00000004u;
        t42r = static_cast<std::uint32_t>(t42a + t42b) & 0xffffffffu;
        batch_set_add_flags(state, t42a, t42b, t42r, 32u);
        state.regs[4] = t42r;
    // 0x00425a58: ebc8 JMP
    L_00425a58:
        goto L_00425a22;
    // 0x00425a5a: 8b550c MOV
    L_00425a5a:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t44;
    // 0x00425a5d: 2b5508 SUB
        t45a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t45b)) return BatchLiftStatus::invalid_memory;
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
        state.regs[2] = t45r;
    // 0x00425a60: c1fa02 SAR
        t46a = state.regs[2];
        t46c = 2u;
        if (t46c != 0u) {
        t46r = (t46a >> t46c) | ((t46a & 0x80000000u) ? (0xffffffffu << (32u - t46c)) : 0u);
        batch_set_sar_flags(state, t46a, t46c, t46r, 32u);
            state.regs[2] = t46r;
        }
    // 0x00425a63: c1e202 SHL
        t47a = state.regs[2];
        t47c = 2u;
        if (t47c != 0u) {
        t47r = static_cast<std::uint32_t>(t47a << t47c) & 0xffffffffu;
        batch_set_shl_flags(state, t47a, t47c, t47r, 32u);
            state.regs[2] = t47r;
        }
    // 0x00425a66: 8b45d8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x00425a69: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t49;
    // 0x00425a6c: 2bca SUB
        t50a = state.regs[1];
        t50b = state.regs[2];
        t50r = static_cast<std::uint32_t>(t50a - t50b) & 0xffffffffu;
        batch_set_sub_flags(state, t50a, t50b, t50r, 32u);
        state.regs[1] = t50r;
    // 0x00425a6e: 8b55d8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t51;
    // 0x00425a71: 894a04 MOV
        t52 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00425a74: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t53;
    // 0x00425a77: 8be5 MOV
        t54 = state.regs[5];
        state.regs[4] = t54;
    // 0x00425a79: 5d POP
        if (!memory.load32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t55a;
    // 0x00425a7a: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
