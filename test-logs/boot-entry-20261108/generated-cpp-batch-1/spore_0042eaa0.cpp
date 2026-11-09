#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402420(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0042eab8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0042eaca(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0042eaa0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0042eaa0u);
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
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t39 = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0;

    // 0x0042eaa0: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0042eaa1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0042eaa3: 83ec14 SUB
        t2a = state.regs[4];
        t2b = 0x00000014u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0042eaa6: c645ff00 MOV
        t3 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffffu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0042eaaa: 8b4510 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0042eaad: 8945ec MOV
        t5 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t5)) return BatchLiftStatus::invalid_memory;
    // 0x0042eab0: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x0042eab3: 894df0 MOV
        t7 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x0042eab6: eb12 JMP
        goto L_0042eaca;
    // 0x0042eab8: 8b55ec MOV
    L_0042eab8:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x0042eabb: 83c204 ADD
        t10a = state.regs[2];
        t10b = 0x00000004u;
        t10r = static_cast<std::uint32_t>(t10a + t10b) & 0xffffffffu;
        batch_set_add_flags(state, t10a, t10b, t10r, 32u);
        state.regs[2] = t10r;
    // 0x0042eabe: 8955ec MOV
        t11 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x0042eac1: 8b45f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x0042eac4: 83c004 ADD
        t13a = state.regs[0];
        t13b = 0x00000004u;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[0] = t13r;
    // 0x0042eac7: 8945f0 MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0042eaca: 8b4df0 MOV
    L_0042eaca:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x0042eacd: 3b4d0c CMP
        t16a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t16b)) return BatchLiftStatus::invalid_memory;
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x0042ead0: 7447 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042eb19;
    // 0x0042ead2: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x0042ead5: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x0042ead7: 8945f4 MOV
        t20 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x0042eada: 8b4dec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t21;
    // 0x0042eadd: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x0042eae0: 3b11 CMP
        t23a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t23b)) return BatchLiftStatus::invalid_memory;
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x0042eae2: 7433 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042eb17;
    // 0x0042eae4: 8b45ec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x0042eae7: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t26;
    // 0x0042eae9: 894df8 MOV
        t27 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x0042eaec: 837df400 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t28a)) return BatchLiftStatus::invalid_memory;
        t28b = 0x00000000u;
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x0042eaf0: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042eb01;
    // 0x0042eaf2: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t30;
    // 0x0042eaf5: 83c208 ADD
        t31a = state.regs[2];
        t31b = 0x00000008u;
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[2] = t31r;
    // 0x0042eaf8: b801000000 MOV
        t32 = 0x00000001u;
        state.regs[0] = t32;
    // 0x0042eafd: f00fc102 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t33a)) return BatchLiftStatus::invalid_memory;
        t33b = state.regs[0];
        t33r = static_cast<std::uint32_t>(t33a + t33b) & 0xffffffffu;
        batch_set_add_flags(state, t33a, t33b, t33r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t33r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33a;
    // 0x0042eb01: 8b4dec MOV
    L_0042eb01:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t34;
    // 0x0042eb04: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t35;
    // 0x0042eb07: 8911 MOV
        t36 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb09: 837df800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t37a)) return BatchLiftStatus::invalid_memory;
        t37b = 0x00000000u;
        t37r = static_cast<std::uint32_t>(t37a - t37b) & 0xffffffffu;
        batch_set_sub_flags(state, t37a, t37b, t37r, 32u);
    // 0x0042eb0d: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042eb17;
    // 0x0042eb0f: 8b4df8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t39;
    // 0x0042eb12: e80939fdff CALL
        if (!batch_guest_call32(memory, state, 0x00402420u, 0x0042eb17u)) return BatchLiftStatus::invalid_memory;
        t40_call_status = spore_lift_00402420(memory, state);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
        if (state.eip != 0x0042eb17u) return BatchLiftStatus::invalid_control_flow;
    // 0x0042eb17: eb9f JMP
    L_0042eb17:
        goto L_0042eab8;
    // 0x0042eb19: 8b45ec MOV
    L_0042eb19:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t42;
    // 0x0042eb1c: 8be5 MOV
        t43 = state.regs[5];
        state.regs[4] = t43;
    // 0x0042eb1e: 5d POP
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t44a;
    // 0x0042eb1f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
