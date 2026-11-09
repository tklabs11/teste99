#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402420(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0042eb36(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0042eb20(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0042eb20u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38 = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0;

    // 0x0042eb20: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb21: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0042eb23: 83ec14 SUB
        t2a = state.regs[4];
        t2b = 0x00000014u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0042eb26: c645ff00 MOV
        t3 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffffu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb2a: 8b4510 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0042eb2d: 8945ec MOV
        t5 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t5)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb30: 8b4d0c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x0042eb33: 894df0 MOV
        t7 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb36: 8b55f0 MOV
    L_0042eb36:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x0042eb39: 3b5508 CMP
        t9a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t9b)) return BatchLiftStatus::invalid_memory;
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x0042eb3c: 7459 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042eb97;
    // 0x0042eb3e: 8b45f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x0042eb41: 83e804 SUB
        t12a = state.regs[0];
        t12b = 0x00000004u;
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
        state.regs[0] = t12r;
    // 0x0042eb44: 8945f0 MOV
        t13 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb47: 8b4dec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x0042eb4a: 83e904 SUB
        t15a = state.regs[1];
        t15b = 0x00000004u;
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
        state.regs[1] = t15r;
    // 0x0042eb4d: 894dec MOV
        t16 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb50: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x0042eb53: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x0042eb55: 8945f4 MOV
        t19 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb58: 8b4dec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t20;
    // 0x0042eb5b: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x0042eb5e: 3b11 CMP
        t22a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t22b)) return BatchLiftStatus::invalid_memory;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x0042eb60: 7433 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042eb95;
    // 0x0042eb62: 8b45ec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t24;
    // 0x0042eb65: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t25;
    // 0x0042eb67: 894df8 MOV
        t26 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb6a: 837df400 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t27a)) return BatchLiftStatus::invalid_memory;
        t27b = 0x00000000u;
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
    // 0x0042eb6e: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042eb7f;
    // 0x0042eb70: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t29;
    // 0x0042eb73: 83c208 ADD
        t30a = state.regs[2];
        t30b = 0x00000008u;
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[2] = t30r;
    // 0x0042eb76: b801000000 MOV
        t31 = 0x00000001u;
        state.regs[0] = t31;
    // 0x0042eb7b: f00fc102 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t32a)) return BatchLiftStatus::invalid_memory;
        t32b = state.regs[0];
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t32r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32a;
    // 0x0042eb7f: 8b4dec MOV
    L_0042eb7f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x0042eb82: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x0042eb85: 8911 MOV
        t35 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x0042eb87: 837df800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t36a)) return BatchLiftStatus::invalid_memory;
        t36b = 0x00000000u;
        t36r = static_cast<std::uint32_t>(t36a - t36b) & 0xffffffffu;
        batch_set_sub_flags(state, t36a, t36b, t36r, 32u);
    // 0x0042eb8b: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042eb95;
    // 0x0042eb8d: 8b4df8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t38;
    // 0x0042eb90: e88b38fdff CALL
        if (!batch_guest_call32(memory, state, 0x00402420u, 0x0042eb95u)) return BatchLiftStatus::invalid_memory;
        t39_call_status = spore_lift_00402420(memory, state);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
        if (state.eip != 0x0042eb95u) return BatchLiftStatus::invalid_control_flow;
    // 0x0042eb95: eb9f JMP
    L_0042eb95:
        goto L_0042eb36;
    // 0x0042eb97: 8b45ec MOV
    L_0042eb97:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t41;
    // 0x0042eb9a: 8be5 MOV
        t42 = state.regs[5];
        state.regs[4] = t42;
    // 0x0042eb9c: 5d POP
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t43a;
    // 0x0042eb9d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
