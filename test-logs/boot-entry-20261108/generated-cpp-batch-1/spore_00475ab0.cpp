#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00475b26(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00475ab0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00475ab0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;

    // 0x00475ab0: 55 PUSH
        batch_guest_pc = 0x00475ab0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00475ab1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00475ab3: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00475ab6: 894df8 MOV
        batch_guest_pc = 0x00475ab6u;
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00475ab9: 837d0801 CMP
        batch_guest_pc = 0x00475ab9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t4a)) return BatchLiftStatus::invalid_memory;
        t4b = 0x00000001u;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
    // 0x00475abd: 7645 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00475b04;
    // 0x00475abf: 68d1000000 PUSH
        batch_guest_pc = 0x00475abfu;
        t6a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00475ac4: 6838bb3e01 PUSH
        batch_guest_pc = 0x00475ac4u;
        t7a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00475ac9: 6a00 PUSH
        batch_guest_pc = 0x00475ac9u;
        t8a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00475acb: 6a00 PUSH
        batch_guest_pc = 0x00475acbu;
        t9a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00475acd: 6830b43e01 PUSH
        batch_guest_pc = 0x00475acdu;
        t10a = 0x013eb430u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00475ad2: 8b4508 MOV
        batch_guest_pc = 0x00475ad2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00475ad5: 50 PUSH
        batch_guest_pc = 0x00475ad5u;
        t12a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00475ad6: e8c518ad00 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00475adbu)) return BatchLiftStatus::invalid_memory;
        t13_call_status = spore_lift_00f473a0(memory, state);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x00475adbu) return BatchLiftStatus::invalid_control_flow;
    // 0x00475adb: 83c418 ADD
        t14a = state.regs[4];
        t14b = 0x00000018u;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[4] = t14r;
    // 0x00475ade: 8945fc MOV
        batch_guest_pc = 0x00475adeu;
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00475ae1: 8b4df8 MOV
        batch_guest_pc = 0x00475ae1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t16;
    // 0x00475ae4: 8b55fc MOV
        batch_guest_pc = 0x00475ae4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x00475ae7: 8911 MOV
        batch_guest_pc = 0x00475ae7u;
        t18 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00475ae9: 8b45f8 MOV
        batch_guest_pc = 0x00475ae9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x00475aec: 8b4df8 MOV
        batch_guest_pc = 0x00475aecu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t20;
    // 0x00475aef: 8b11 MOV
        batch_guest_pc = 0x00475aefu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x00475af1: 895004 MOV
        batch_guest_pc = 0x00475af1u;
        t22 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00475af4: 8b45f8 MOV
        batch_guest_pc = 0x00475af4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x00475af7: 8b08 MOV
        batch_guest_pc = 0x00475af7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x00475af9: 034d08 ADD
        batch_guest_pc = 0x00475af9u;
        t25a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t25b)) return BatchLiftStatus::invalid_memory;
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[1] = t25r;
    // 0x00475afc: 8b55f8 MOV
        batch_guest_pc = 0x00475afcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t26;
    // 0x00475aff: 894a08 MOV
        batch_guest_pc = 0x00475affu;
        t27 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00475b02: eb22 JMP
        goto L_00475b26;
    // 0x00475b04: 8b45f8 MOV
    L_00475b04:
        batch_guest_pc = 0x00475b04u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t29;
    // 0x00475b07: c700ac7b6601 MOV
        batch_guest_pc = 0x00475b07u;
        t30 = 0x01667bacu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00475b0d: 8b4df8 MOV
        batch_guest_pc = 0x00475b0du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t31;
    // 0x00475b10: 8b55f8 MOV
        batch_guest_pc = 0x00475b10u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t32;
    // 0x00475b13: 8b02 MOV
        batch_guest_pc = 0x00475b13u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x00475b15: 894104 MOV
        batch_guest_pc = 0x00475b15u;
        t34 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00475b18: 8b4df8 MOV
        batch_guest_pc = 0x00475b18u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35;
    // 0x00475b1b: 8b11 MOV
        batch_guest_pc = 0x00475b1bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t36;
    // 0x00475b1d: 83c201 ADD
        t37a = state.regs[2];
        t37b = 0x00000001u;
        t37r = static_cast<std::uint32_t>(t37a + t37b) & 0xffffffffu;
        batch_set_add_flags(state, t37a, t37b, t37r, 32u);
        state.regs[2] = t37r;
    // 0x00475b20: 8b45f8 MOV
        batch_guest_pc = 0x00475b20u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t38;
    // 0x00475b23: 895008 MOV
        batch_guest_pc = 0x00475b23u;
        t39 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x00475b26: 8be5 MOV
    L_00475b26:
        t40 = state.regs[5];
        state.regs[4] = t40;
    // 0x00475b28: 5d POP
        batch_guest_pc = 0x00475b28u;
        if (!memory.load32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t41a;
    // 0x00475b29: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
