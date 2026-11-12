#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00942e50(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009199c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009199c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26a = 0, t26r = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42a = 0;
    BatchLiftStatus t43_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50 = 0;
    BatchLiftStatus t51_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t52a = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56a = 0;

    // 0x009199c0: 53 PUSH
        batch_guest_pc = 0x009199c0u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009199c1: 55 PUSH
        batch_guest_pc = 0x009199c1u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009199c2: 8b6c2410 MOV
        batch_guest_pc = 0x009199c2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t2;
    // 0x009199c6: 56 PUSH
        batch_guest_pc = 0x009199c6u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009199c7: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x009199c9: 8b06 MOV
        batch_guest_pc = 0x009199c9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x009199cb: 8b4e04 MOV
        batch_guest_pc = 0x009199cbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x009199ce: 57 PUSH
        batch_guest_pc = 0x009199ceu;
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x009199cf: 8b7c2414 MOV
        batch_guest_pc = 0x009199cfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t8;
    // 0x009199d3: 8bdd MOV
        t9 = state.regs[5];
        state.regs[3] = t9;
    // 0x009199d5: 2bdf SUB
        t10a = state.regs[3];
        t10b = state.regs[7];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
        state.regs[3] = t10r;
    // 0x009199d7: 2bc8 SUB
        t11a = state.regs[1];
        t11b = state.regs[0];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
        state.regs[1] = t11r;
    // 0x009199d9: 3bd9 CMP
        t12a = state.regs[3];
        t12b = state.regs[1];
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x009199db: 7735 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00919a12;
    // 0x009199dd: 53 PUSH
        batch_guest_pc = 0x009199ddu;
        t14a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x009199de: 57 PUSH
        batch_guest_pc = 0x009199deu;
        t15a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x009199df: 50 PUSH
        batch_guest_pc = 0x009199dfu;
        t16a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x009199e0: e85f6d8c00 CALL
        t17_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x009199e5u);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
        if (state.eip != 0x009199e5u) return BatchLiftStatus::invalid_control_flow;
    // 0x009199e5: 8b3e MOV
        batch_guest_pc = 0x009199e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t18;
    // 0x009199e7: 8b6e04 MOV
        batch_guest_pc = 0x009199e7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t19;
    // 0x009199ea: 03fb ADD
        t20a = state.regs[7];
        t20b = state.regs[3];
        t20r = static_cast<std::uint32_t>(t20a + t20b) & 0xffffffffu;
        batch_set_add_flags(state, t20a, t20b, t20r, 32u);
        state.regs[7] = t20r;
    // 0x009199ec: 83c40c ADD
        t21a = state.regs[4];
        t21b = 0x0000000cu;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[4] = t21r;
    // 0x009199ef: 3bfd CMP
        t22a = state.regs[7];
        t22b = state.regs[5];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x009199f1: 743a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00919a2d;
    // 0x009199f3: 8bc5 MOV
        t24 = state.regs[5];
        state.regs[0] = t24;
    // 0x009199f5: 2bc5 SUB
        t25a = state.regs[0];
        t25b = state.regs[5];
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
        state.regs[0] = t25r;
    // 0x009199f7: 40 INC
        t26a = state.regs[0];
        t26r = static_cast<std::uint32_t>(t26a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t26a, t26r, 32u);
        state.regs[0] = t26r;
    // 0x009199f8: 50 PUSH
        batch_guest_pc = 0x009199f8u;
        t27a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x009199f9: 55 PUSH
        batch_guest_pc = 0x009199f9u;
        t28a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x009199fa: 57 PUSH
        batch_guest_pc = 0x009199fau;
        t29a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x009199fb: ff1580c43c01 CALL
        t30_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memmove", 0x013cc480u, 0x00919a01u);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x00919a01u) return BatchLiftStatus::invalid_control_flow;
    // 0x00919a01: 83c40c ADD
        t31a = state.regs[4];
        t31b = 0x0000000cu;
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[4] = t31r;
    // 0x00919a04: 2bfd SUB
        t32a = state.regs[7];
        t32b = state.regs[5];
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
        state.regs[7] = t32r;
    // 0x00919a06: 017e04 ADD
        batch_guest_pc = 0x00919a06u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t33a)) return BatchLiftStatus::invalid_memory;
        t33b = state.regs[7];
        t33r = static_cast<std::uint32_t>(t33a + t33b) & 0xffffffffu;
        batch_set_add_flags(state, t33a, t33b, t33r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t33r)) return BatchLiftStatus::invalid_memory;
    // 0x00919a09: 5f POP
        batch_guest_pc = 0x00919a09u;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t34a;
    // 0x00919a0a: 8bc6 MOV
        t35 = state.regs[6];
        state.regs[0] = t35;
    // 0x00919a0c: 5e POP
        batch_guest_pc = 0x00919a0cu;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t36a;
    // 0x00919a0d: 5d POP
        batch_guest_pc = 0x00919a0du;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t37a;
    // 0x00919a0e: 5b POP
        batch_guest_pc = 0x00919a0eu;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t38a;
    // 0x00919a0f: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00919a12: 51 PUSH
    L_00919a12:
        batch_guest_pc = 0x00919a12u;
        t40a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00919a13: 57 PUSH
        batch_guest_pc = 0x00919a13u;
        t41a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00919a14: 50 PUSH
        batch_guest_pc = 0x00919a14u;
        t42a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x00919a15: e82a6d8c00 CALL
        t43_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00919a1au);
        if (t43_call_status != BatchLiftStatus::returned) return t43_call_status;
        if (state.eip != 0x00919a1au) return BatchLiftStatus::invalid_control_flow;
    // 0x00919a1a: 8b4e04 MOV
        batch_guest_pc = 0x00919a1au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t44;
    // 0x00919a1d: 2b0e SUB
        batch_guest_pc = 0x00919a1du;
        t45a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t45b)) return BatchLiftStatus::invalid_memory;
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
        state.regs[1] = t45r;
    // 0x00919a1f: 83c40c ADD
        t46a = state.regs[4];
        t46b = 0x0000000cu;
        t46r = static_cast<std::uint32_t>(t46a + t46b) & 0xffffffffu;
        batch_set_add_flags(state, t46a, t46b, t46r, 32u);
        state.regs[4] = t46r;
    // 0x00919a22: 03cf ADD
        t47a = state.regs[1];
        t47b = state.regs[7];
        t47r = static_cast<std::uint32_t>(t47a + t47b) & 0xffffffffu;
        batch_set_add_flags(state, t47a, t47b, t47r, 32u);
        state.regs[1] = t47r;
    // 0x00919a24: 55 PUSH
        batch_guest_pc = 0x00919a24u;
        t48a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x00919a25: 51 PUSH
        batch_guest_pc = 0x00919a25u;
        t49a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x00919a26: 8bce MOV
        t50 = state.regs[6];
        state.regs[1] = t50;
    // 0x00919a28: e823940200 CALL
        if (!batch_guest_call32(memory, state, 0x00942e50u, 0x00919a2du)) return BatchLiftStatus::invalid_memory;
        t51_call_status = spore_lift_00942e50(memory, state);
        if (t51_call_status != BatchLiftStatus::returned) return t51_call_status;
        if (state.eip != 0x00919a2du) return BatchLiftStatus::invalid_control_flow;
    // 0x00919a2d: 5f POP
    L_00919a2d:
        batch_guest_pc = 0x00919a2du;
        if (!memory.load32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t52a;
    // 0x00919a2e: 8bc6 MOV
        t53 = state.regs[6];
        state.regs[0] = t53;
    // 0x00919a30: 5e POP
        batch_guest_pc = 0x00919a30u;
        if (!memory.load32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t54a;
    // 0x00919a31: 5d POP
        batch_guest_pc = 0x00919a31u;
        if (!memory.load32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t55a;
    // 0x00919a32: 5b POP
        batch_guest_pc = 0x00919a32u;
        if (!memory.load32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t56a;
    // 0x00919a33: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
