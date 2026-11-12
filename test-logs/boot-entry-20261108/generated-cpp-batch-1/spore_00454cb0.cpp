#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00454d3b(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00455d60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0045f080(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00454cb0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00454cb0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29 = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52 = 0;
    BatchLiftStatus t53_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0;

    // 0x00454cb0: 55 PUSH
        batch_guest_pc = 0x00454cb0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00454cb1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00454cb3: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00454cb6: 894df8 MOV
        batch_guest_pc = 0x00454cb6u;
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00454cb9: 8b450c MOV
        batch_guest_pc = 0x00454cb9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00454cbc: 2b4508 SUB
        batch_guest_pc = 0x00454cbcu;
        t5a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t5b)) return BatchLiftStatus::invalid_memory;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[0] = t5r;
    // 0x00454cbf: 8945fc MOV
        batch_guest_pc = 0x00454cbfu;
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00454cc2: 8b4df8 MOV
        batch_guest_pc = 0x00454cc2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x00454cc5: 8b55f8 MOV
        batch_guest_pc = 0x00454cc5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x00454cc8: 8b4104 MOV
        batch_guest_pc = 0x00454cc8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x00454ccb: 2b02 SUB
        batch_guest_pc = 0x00454ccbu;
        t10a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t10b)) return BatchLiftStatus::invalid_memory;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
        state.regs[0] = t10r;
    // 0x00454ccd: 3945fc CMP
        batch_guest_pc = 0x00454ccdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11a)) return BatchLiftStatus::invalid_memory;
        t11b = state.regs[0];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x00454cd0: 7730 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00454d02;
    // 0x00454cd2: 8b4dfc MOV
        batch_guest_pc = 0x00454cd2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00454cd5: 51 PUSH
        batch_guest_pc = 0x00454cd5u;
        t14a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00454cd6: 8b5508 MOV
        batch_guest_pc = 0x00454cd6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t15;
    // 0x00454cd9: 52 PUSH
        batch_guest_pc = 0x00454cd9u;
        t16a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00454cda: 8b45f8 MOV
        batch_guest_pc = 0x00454cdau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x00454cdd: 8b08 MOV
        batch_guest_pc = 0x00454cddu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t18;
    // 0x00454cdf: 51 PUSH
        batch_guest_pc = 0x00454cdfu;
        t19a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00454ce0: e85fbad800 CALL
        t20_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00454ce5u);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x00454ce5u) return BatchLiftStatus::invalid_control_flow;
    // 0x00454ce5: 83c40c ADD
        t21a = state.regs[4];
        t21b = 0x0000000cu;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[4] = t21r;
    // 0x00454ce8: 8b55f8 MOV
        batch_guest_pc = 0x00454ce8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x00454ceb: 8b4204 MOV
        batch_guest_pc = 0x00454cebu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x00454cee: 50 PUSH
        batch_guest_pc = 0x00454ceeu;
        t24a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00454cef: 8b4df8 MOV
        batch_guest_pc = 0x00454cefu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t25;
    // 0x00454cf2: 8b11 MOV
        batch_guest_pc = 0x00454cf2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t26;
    // 0x00454cf4: 0355fc ADD
        batch_guest_pc = 0x00454cf4u;
        t27a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t27b)) return BatchLiftStatus::invalid_memory;
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        state.regs[2] = t27r;
    // 0x00454cf7: 52 PUSH
        batch_guest_pc = 0x00454cf7u;
        t28a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00454cf8: 8b4df8 MOV
        batch_guest_pc = 0x00454cf8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t29;
    // 0x00454cfb: e880a30000 CALL
        if (!batch_guest_call32(memory, state, 0x0045f080u, 0x00454d00u)) return BatchLiftStatus::invalid_memory;
        t30_call_status = spore_lift_0045f080(memory, state);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x00454d00u) return BatchLiftStatus::invalid_control_flow;
    // 0x00454d00: eb39 JMP
        goto L_00454d3b;
    // 0x00454d02: 8b45f8 MOV
    L_00454d02:
        batch_guest_pc = 0x00454d02u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x00454d05: 8b4df8 MOV
        batch_guest_pc = 0x00454d05u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x00454d08: 8b5004 MOV
        batch_guest_pc = 0x00454d08u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x00454d0b: 2b11 SUB
        batch_guest_pc = 0x00454d0bu;
        t35a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t35b)) return BatchLiftStatus::invalid_memory;
        t35r = static_cast<std::uint32_t>(t35a - t35b) & 0xffffffffu;
        batch_set_sub_flags(state, t35a, t35b, t35r, 32u);
        state.regs[2] = t35r;
    // 0x00454d0d: 52 PUSH
        batch_guest_pc = 0x00454d0du;
        t36a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00454d0e: 8b4508 MOV
        batch_guest_pc = 0x00454d0eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t37;
    // 0x00454d11: 50 PUSH
        batch_guest_pc = 0x00454d11u;
        t38a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x00454d12: 8b4df8 MOV
        batch_guest_pc = 0x00454d12u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t39;
    // 0x00454d15: 8b11 MOV
        batch_guest_pc = 0x00454d15u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t40;
    // 0x00454d17: 52 PUSH
        batch_guest_pc = 0x00454d17u;
        t41a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00454d18: e827bad800 CALL
        t42_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00454d1du);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00454d1du) return BatchLiftStatus::invalid_control_flow;
    // 0x00454d1d: 83c40c ADD
        t43a = state.regs[4];
        t43b = 0x0000000cu;
        t43r = static_cast<std::uint32_t>(t43a + t43b) & 0xffffffffu;
        batch_set_add_flags(state, t43a, t43b, t43r, 32u);
        state.regs[4] = t43r;
    // 0x00454d20: 8b450c MOV
        batch_guest_pc = 0x00454d20u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t44;
    // 0x00454d23: 50 PUSH
        batch_guest_pc = 0x00454d23u;
        t45a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
    // 0x00454d24: 8b4df8 MOV
        batch_guest_pc = 0x00454d24u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t46;
    // 0x00454d27: 8b55f8 MOV
        batch_guest_pc = 0x00454d27u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t47;
    // 0x00454d2a: 8b4104 MOV
        batch_guest_pc = 0x00454d2au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x00454d2d: 2b02 SUB
        batch_guest_pc = 0x00454d2du;
        t49a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t49b)) return BatchLiftStatus::invalid_memory;
        t49r = static_cast<std::uint32_t>(t49a - t49b) & 0xffffffffu;
        batch_set_sub_flags(state, t49a, t49b, t49r, 32u);
        state.regs[0] = t49r;
    // 0x00454d2f: 034508 ADD
        batch_guest_pc = 0x00454d2fu;
        t50a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t50b)) return BatchLiftStatus::invalid_memory;
        t50r = static_cast<std::uint32_t>(t50a + t50b) & 0xffffffffu;
        batch_set_add_flags(state, t50a, t50b, t50r, 32u);
        state.regs[0] = t50r;
    // 0x00454d32: 50 PUSH
        batch_guest_pc = 0x00454d32u;
        t51a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x00454d33: 8b4df8 MOV
        batch_guest_pc = 0x00454d33u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t52;
    // 0x00454d36: e825100000 CALL
        if (!batch_guest_call32(memory, state, 0x00455d60u, 0x00454d3bu)) return BatchLiftStatus::invalid_memory;
        t53_call_status = spore_lift_00455d60(memory, state);
        if (t53_call_status != BatchLiftStatus::returned) return t53_call_status;
        if (state.eip != 0x00454d3bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00454d3b: 8b45f8 MOV
    L_00454d3b:
        batch_guest_pc = 0x00454d3bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t54;
    // 0x00454d3e: 8be5 MOV
        t55 = state.regs[5];
        state.regs[4] = t55;
    // 0x00454d40: 5d POP
        batch_guest_pc = 0x00454d40u;
        if (!memory.load32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t56a;
    // 0x00454d41: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
