#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004206d3(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004206e8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00425a80(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00420660(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00420660u);
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
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45 = 0;
    BatchLiftStatus t46_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0;

    // 0x00420660: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00420661: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00420663: 83ec14 SUB
        t2a = state.regs[4];
        t2b = 0x00000014u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00420666: 894df0 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00420669: 8b45f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0042066c: 8b4df0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x0042066f: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t6;
    // 0x00420672: 3b5108 CMP
        t7a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t7b)) return BatchLiftStatus::invalid_memory;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x00420675: 735e JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_004206d5;
    // 0x00420677: 8b45f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x0042067a: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t10;
    // 0x0042067d: 894df8 MOV
        t11 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00420680: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t12;
    // 0x00420683: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00420686: 83c004 ADD
        t14a = state.regs[0];
        t14b = 0x00000004u;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[0] = t14r;
    // 0x00420689: 8b4df0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x0042068c: 894104 MOV
        t16 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x0042068f: 8b55f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x00420692: 8955fc MOV
        t18 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00420695: 837dfc00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t19a)) return BatchLiftStatus::invalid_memory;
        t19b = 0x00000000u;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x00420699: 7431 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004206cc;
    // 0x0042069b: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x0042069e: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x004206a1: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t23;
    // 0x004206a3: 8910 MOV
        t24 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x004206a5: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x004206a8: 833800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t26a)) return BatchLiftStatus::invalid_memory;
        t26b = 0x00000000u;
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0xffffffffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 32u);
    // 0x004206ab: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004206c4;
    // 0x004206ad: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t28;
    // 0x004206b0: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t29;
    // 0x004206b2: 8955f4 MOV
        t30 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x004206b5: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t31;
    // 0x004206b8: 83c008 ADD
        t32a = state.regs[0];
        t32b = 0x00000008u;
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        state.regs[0] = t32r;
    // 0x004206bb: b901000000 MOV
        t33 = 0x00000001u;
        state.regs[1] = t33;
    // 0x004206c0: f00fc108 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t34a)) return BatchLiftStatus::invalid_memory;
        t34b = state.regs[1];
        t34r = static_cast<std::uint32_t>(t34a + t34b) & 0xffffffffu;
        batch_set_add_flags(state, t34a, t34b, t34r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t34r)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t34a;
    // 0x004206c4: 8b55fc MOV
    L_004206c4:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t35;
    // 0x004206c7: 8955ec MOV
        t36 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t36)) return BatchLiftStatus::invalid_memory;
    // 0x004206ca: eb07 JMP
        goto L_004206d3;
    // 0x004206cc: c745ec00000000 MOV
    L_004206cc:
        t38 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t38)) return BatchLiftStatus::invalid_memory;
    // 0x004206d3: eb13 JMP
    L_004206d3:
        goto L_004206e8;
    // 0x004206d5: 8b4508 MOV
    L_004206d5:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t40;
    // 0x004206d8: 50 PUSH
        t41a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x004206d9: 8b4df0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t42;
    // 0x004206dc: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t43;
    // 0x004206df: 52 PUSH
        t44a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x004206e0: 8b4df0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t45;
    // 0x004206e3: e898530000 CALL
        if (!batch_guest_call32(memory, state, 0x00425a80u, 0x004206e8u)) return BatchLiftStatus::invalid_memory;
        t46_call_status = spore_lift_00425a80(memory, state);
        if (t46_call_status != BatchLiftStatus::returned) return t46_call_status;
        if (state.eip != 0x004206e8u) return BatchLiftStatus::invalid_control_flow;
    // 0x004206e8: 8be5 MOV
    L_004206e8:
        t47 = state.regs[5];
        state.regs[4] = t47;
    // 0x004206ea: 5d POP
        if (!memory.load32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t48a;
    // 0x004206eb: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
