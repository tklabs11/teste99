#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00924bd0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009257a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697ee0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697ee0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33a = 0;
    BatchLiftStatus t34_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t44a = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    BatchLiftStatus t49_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;

    // 0x00697ee0: 6aff PUSH
        batch_guest_pc = 0x00697ee0u;
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00697ee2: 686cd32001 PUSH
        batch_guest_pc = 0x00697ee2u;
        t1a = 0x0120d36cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00697ee7: 64a100000000 MOV
        batch_guest_pc = 0x00697ee7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00697eed: 50 PUSH
        batch_guest_pc = 0x00697eedu;
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00697eee: 64892500000000 MOV
        batch_guest_pc = 0x00697eeeu;
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00697ef5: 51 PUSH
        batch_guest_pc = 0x00697ef5u;
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00697ef6: 56 PUSH
        batch_guest_pc = 0x00697ef6u;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00697ef7: 8bf1 MOV
        t7 = state.regs[1];
        state.regs[6] = t7;
    // 0x00697ef9: 89742404 MOV
        batch_guest_pc = 0x00697ef9u;
        t8 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00697efd: c70610834001 MOV
        batch_guest_pc = 0x00697efdu;
        t9 = 0x01408310u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00697f03: c74604f4824001 MOV
        batch_guest_pc = 0x00697f03u;
        t10 = 0x014082f4u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00697f0a: 8d8ea0000000 LEA
        t11 = static_cast<std::uint32_t>(state.regs[6] + 0x000000a0u);
        state.regs[1] = t11;
    // 0x00697f10: c744241003000000 MOV
        batch_guest_pc = 0x00697f10u;
        t12 = 0x00000003u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00697f18: e883d82800 CALL
        if (!batch_guest_call32(memory, state, 0x009257a0u, 0x00697f1du)) return BatchLiftStatus::invalid_memory;
        t13_call_status = spore_lift_009257a0(memory, state);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x00697f1du) return BatchLiftStatus::invalid_control_flow;
    // 0x00697f1d: 8b8688000000 MOV
        batch_guest_pc = 0x00697f1du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000088u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00697f23: 8b8e90000000 MOV
        batch_guest_pc = 0x00697f23u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000090u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x00697f29: 2bc8 SUB
        t16a = state.regs[1];
        t16b = state.regs[0];
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
        state.regs[1] = t16r;
    // 0x00697f2b: 83e1fe AND
        t17a = state.regs[1];
        t17b = 0xfffffffeu;
        t17r = (t17a & t17b) & 0xffffffffu;
        batch_set_logic_flags(state, t17r, 32u);
        state.regs[1] = t17r;
    // 0x00697f2e: 83f902 CMP
        t18a = state.regs[1];
        t18b = 0x00000002u;
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
    // 0x00697f31: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00697f40;
    // 0x00697f33: 85c0 TEST
        t20a = state.regs[0];
        t20b = state.regs[0];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00697f35: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697f40;
    // 0x00697f37: 50 PUSH
        batch_guest_pc = 0x00697f37u;
        t22a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00697f38: e843f48a00 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00697f3du)) return BatchLiftStatus::invalid_memory;
        t23_call_status = spore_lift_00f47380(memory, state);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x00697f3du) return BatchLiftStatus::invalid_control_flow;
    // 0x00697f3d: 83c404 ADD
        t24a = state.regs[4];
        t24b = 0x00000004u;
        t24r = static_cast<std::uint32_t>(t24a + t24b) & 0xffffffffu;
        batch_set_add_flags(state, t24a, t24b, t24r, 32u);
        state.regs[4] = t24r;
    // 0x00697f40: 8b4678 MOV
    L_00697f40:
        batch_guest_pc = 0x00697f40u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000078u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x00697f43: 8b9680000000 MOV
        batch_guest_pc = 0x00697f43u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000080u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t26;
    // 0x00697f49: 2bd0 SUB
        t27a = state.regs[2];
        t27b = state.regs[0];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
        state.regs[2] = t27r;
    // 0x00697f4b: 83e2fe AND
        t28a = state.regs[2];
        t28b = 0xfffffffeu;
        t28r = (t28a & t28b) & 0xffffffffu;
        batch_set_logic_flags(state, t28r, 32u);
        state.regs[2] = t28r;
    // 0x00697f4e: 83fa02 CMP
        t29a = state.regs[2];
        t29b = 0x00000002u;
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
    // 0x00697f51: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00697f60;
    // 0x00697f53: 85c0 TEST
        t31a = state.regs[0];
        t31b = state.regs[0];
        t31r = (t31a & t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
    // 0x00697f55: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697f60;
    // 0x00697f57: 50 PUSH
        batch_guest_pc = 0x00697f57u;
        t33a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00697f58: e823f48a00 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00697f5du)) return BatchLiftStatus::invalid_memory;
        t34_call_status = spore_lift_00f47380(memory, state);
        if (t34_call_status != BatchLiftStatus::returned) return t34_call_status;
        if (state.eip != 0x00697f5du) return BatchLiftStatus::invalid_control_flow;
    // 0x00697f5d: 83c404 ADD
        t35a = state.regs[4];
        t35b = 0x00000004u;
        t35r = static_cast<std::uint32_t>(t35a + t35b) & 0xffffffffu;
        batch_set_add_flags(state, t35a, t35b, t35r, 32u);
        state.regs[4] = t35r;
    // 0x00697f60: 8b4668 MOV
    L_00697f60:
        batch_guest_pc = 0x00697f60u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000068u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t36;
    // 0x00697f63: 8b4e70 MOV
        batch_guest_pc = 0x00697f63u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000070u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t37;
    // 0x00697f66: 2bc8 SUB
        t38a = state.regs[1];
        t38b = state.regs[0];
        t38r = static_cast<std::uint32_t>(t38a - t38b) & 0xffffffffu;
        batch_set_sub_flags(state, t38a, t38b, t38r, 32u);
        state.regs[1] = t38r;
    // 0x00697f68: 83e1fe AND
        t39a = state.regs[1];
        t39b = 0xfffffffeu;
        t39r = (t39a & t39b) & 0xffffffffu;
        batch_set_logic_flags(state, t39r, 32u);
        state.regs[1] = t39r;
    // 0x00697f6b: 83f902 CMP
        t40a = state.regs[1];
        t40b = 0x00000002u;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0xffffffffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 32u);
    // 0x00697f6e: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00697f7d;
    // 0x00697f70: 85c0 TEST
        t42a = state.regs[0];
        t42b = state.regs[0];
        t42r = (t42a & t42b) & 0xffffffffu;
        batch_set_logic_flags(state, t42r, 32u);
    // 0x00697f72: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697f7d;
    // 0x00697f74: 50 PUSH
        batch_guest_pc = 0x00697f74u;
        t44a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x00697f75: e806f48a00 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00697f7au)) return BatchLiftStatus::invalid_memory;
        t45_call_status = spore_lift_00f47380(memory, state);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
        if (state.eip != 0x00697f7au) return BatchLiftStatus::invalid_control_flow;
    // 0x00697f7a: 83c404 ADD
        t46a = state.regs[4];
        t46b = 0x00000004u;
        t46r = static_cast<std::uint32_t>(t46a + t46b) & 0xffffffffu;
        batch_set_add_flags(state, t46a, t46b, t46r, 32u);
        state.regs[4] = t46r;
    // 0x00697f7d: 8bce MOV
    L_00697f7d:
        t47 = state.regs[6];
        state.regs[1] = t47;
    // 0x00697f7f: c7442410ffffffff MOV
        batch_guest_pc = 0x00697f7fu;
        t48 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00697f87: e844cc2800 CALL
        if (!batch_guest_call32(memory, state, 0x00924bd0u, 0x00697f8cu)) return BatchLiftStatus::invalid_memory;
        t49_call_status = spore_lift_00924bd0(memory, state);
        if (t49_call_status != BatchLiftStatus::returned) return t49_call_status;
        if (state.eip != 0x00697f8cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00697f8c: 8b4c2408 MOV
        batch_guest_pc = 0x00697f8cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t50;
    // 0x00697f90: 5e POP
        batch_guest_pc = 0x00697f90u;
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t51a;
    // 0x00697f91: 64890d00000000 MOV
        batch_guest_pc = 0x00697f91u;
        t52 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00697f98: 83c410 ADD
        t53a = state.regs[4];
        t53b = 0x00000010u;
        t53r = static_cast<std::uint32_t>(t53a + t53b) & 0xffffffffu;
        batch_set_add_flags(state, t53a, t53b, t53r, 32u);
        state.regs[4] = t53r;
    // 0x00697f9b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
