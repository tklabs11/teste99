#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0042f538(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0042f54a(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0042f530(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0042f530u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    BatchLiftStatus t29_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0;

    // 0x0042f530: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0042f531: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0042f533: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0042f536: eb12 JMP
        goto L_0042f54a;
    // 0x0042f538: 8b4510 MOV
    L_0042f538:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0042f53b: 83c004 ADD
        t5a = state.regs[0];
        t5b = 0x00000004u;
        t5r = static_cast<std::uint32_t>(t5a + t5b) & 0xffffffffu;
        batch_set_add_flags(state, t5a, t5b, t5r, 32u);
        state.regs[0] = t5r;
    // 0x0042f53e: 894510 MOV
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x0042f541: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x0042f544: 83c104 ADD
        t8a = state.regs[1];
        t8b = 0x00000004u;
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        state.regs[1] = t8r;
    // 0x0042f547: 894d08 MOV
        t9 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0042f54a: 8b5508 MOV
    L_0042f54a:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t10;
    // 0x0042f54d: 3b550c CMP
        t11a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t11b)) return BatchLiftStatus::invalid_memory;
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x0042f550: 7449 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042f59b;
    // 0x0042f552: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x0042f555: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x0042f557: 894df8 MOV
        t15 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0042f55a: 8b5510 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t16;
    // 0x0042f55d: 8b45f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x0042f560: 3b02 CMP
        t18a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t18b)) return BatchLiftStatus::invalid_memory;
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
    // 0x0042f562: 7435 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042f599;
    // 0x0042f564: 8b4d10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t20;
    // 0x0042f567: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x0042f569: 8955fc MOV
        t22 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t22)) return BatchLiftStatus::invalid_memory;
    // 0x0042f56c: 837df800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t23a)) return BatchLiftStatus::invalid_memory;
        t23b = 0x00000000u;
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x0042f570: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042f57e;
    // 0x0042f572: 8b45f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x0042f575: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t26;
    // 0x0042f577: 8b4df8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t27;
    // 0x0042f57a: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x0042f57c: ffd0 CALL
        t29_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0042f57eu);
        if (t29_call_status != BatchLiftStatus::returned) return t29_call_status;
    // 0x0042f57e: 8b4d10 MOV
    L_0042f57e:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x0042f581: 8b55f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t31;
    // 0x0042f584: 8911 MOV
        t32 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x0042f586: 837dfc00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t33a)) return BatchLiftStatus::invalid_memory;
        t33b = 0x00000000u;
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
    // 0x0042f58a: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042f599;
    // 0x0042f58c: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t35;
    // 0x0042f58f: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t36;
    // 0x0042f591: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t37;
    // 0x0042f594: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t38;
    // 0x0042f597: ffd0 CALL
        t39_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0042f599u);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
    // 0x0042f599: eb9d JMP
    L_0042f599:
        goto L_0042f538;
    // 0x0042f59b: 8b4510 MOV
    L_0042f59b:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t41;
    // 0x0042f59e: 8be5 MOV
        t42 = state.regs[5];
        state.regs[4] = t42;
    // 0x0042f5a0: 5d POP
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t43a;
    // 0x0042f5a1: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
