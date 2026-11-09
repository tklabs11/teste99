#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0050f8c8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f8da(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f913(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f92d(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f93f(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0050f8b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0050f8b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0;

    // 0x0050f8b0: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0050f8b1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0050f8b3: 83ec24 SUB
        t2a = state.regs[4];
        t2b = 0x00000024u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0050f8b6: c645fb00 MOV
        t3 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffbu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0050f8ba: 8b4510 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0050f8bd: 8945ec MOV
        t5 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t5)) return BatchLiftStatus::invalid_memory;
    // 0x0050f8c0: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x0050f8c3: 894df0 MOV
        t7 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x0050f8c6: eb12 JMP
        goto L_0050f8da;
    // 0x0050f8c8: 8b55f0 MOV
    L_0050f8c8:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x0050f8cb: 83c20c ADD
        t10a = state.regs[2];
        t10b = 0x0000000cu;
        t10r = static_cast<std::uint32_t>(t10a + t10b) & 0xffffffffu;
        batch_set_add_flags(state, t10a, t10b, t10r, 32u);
        state.regs[2] = t10r;
    // 0x0050f8ce: 8955f0 MOV
        t11 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x0050f8d1: 8b45ec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x0050f8d4: 83c00c ADD
        t13a = state.regs[0];
        t13b = 0x0000000cu;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[0] = t13r;
    // 0x0050f8d7: 8945ec MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0050f8da: 8b4df0 MOV
    L_0050f8da:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x0050f8dd: 3b4d0c CMP
        t16a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t16b)) return BatchLiftStatus::invalid_memory;
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x0050f8e0: 7433 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0050f915;
    // 0x0050f8e2: 8b55ec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x0050f8e5: 8955f4 MOV
        t19 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x0050f8e8: 837df400 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t20a)) return BatchLiftStatus::invalid_memory;
        t20b = 0x00000000u;
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x0050f8ec: 741e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0050f90c;
    // 0x0050f8ee: 8b45f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x0050f8f1: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t23;
    // 0x0050f8f4: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t24;
    // 0x0050f8f6: 8911 MOV
        t25 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x0050f8f8: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t26;
    // 0x0050f8fb: 895104 MOV
        t27 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x0050f8fe: 8b4008 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x0050f901: 894108 MOV
        t29 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x0050f904: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x0050f907: 894ddc MOV
        t31 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t31)) return BatchLiftStatus::invalid_memory;
    // 0x0050f90a: eb07 JMP
        goto L_0050f913;
    // 0x0050f90c: c745dc00000000 MOV
    L_0050f90c:
        t33 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t33)) return BatchLiftStatus::invalid_memory;
    // 0x0050f913: ebb3 JMP
    L_0050f913:
        goto L_0050f8c8;
    // 0x0050f915: 8b55ec MOV
    L_0050f915:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t35;
    // 0x0050f918: 8955fc MOV
        t36 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t36)) return BatchLiftStatus::invalid_memory;
    // 0x0050f91b: c645eb00 MOV
        t37 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffebu), t37)) return BatchLiftStatus::invalid_memory;
    // 0x0050f91f: 8b4510 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t38;
    // 0x0050f922: 8945e0 MOV
        t39 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x0050f925: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t40;
    // 0x0050f928: 894de4 MOV
        t41 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0050f92b: eb12 JMP
        goto L_0050f93f;
    // 0x0050f92d: 8b55e4 MOV
    L_0050f92d:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t43;
    // 0x0050f930: 83c20c ADD
        t44a = state.regs[2];
        t44b = 0x0000000cu;
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        state.regs[2] = t44r;
    // 0x0050f933: 8955e4 MOV
        t45 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x0050f936: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t46;
    // 0x0050f939: 83c00c ADD
        t47a = state.regs[0];
        t47b = 0x0000000cu;
        t47r = static_cast<std::uint32_t>(t47a + t47b) & 0xffffffffu;
        batch_set_add_flags(state, t47a, t47b, t47r, 32u);
        state.regs[0] = t47r;
    // 0x0050f93c: 8945e0 MOV
        t48 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x0050f93f: 8b4de4 MOV
    L_0050f93f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t49;
    // 0x0050f942: 3b4d0c CMP
        t50a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t50b)) return BatchLiftStatus::invalid_memory;
        t50r = static_cast<std::uint32_t>(t50a - t50b) & 0xffffffffu;
        batch_set_sub_flags(state, t50a, t50b, t50r, 32u);
    // 0x0050f945: 7402 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0050f949;
    // 0x0050f947: ebe4 JMP
        goto L_0050f92d;
    // 0x0050f949: 8b45fc MOV
    L_0050f949:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t53;
    // 0x0050f94c: 8be5 MOV
        t54 = state.regs[5];
        state.regs[4] = t54;
    // 0x0050f94e: 5d POP
        if (!memory.load32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t55a;
    // 0x0050f94f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
