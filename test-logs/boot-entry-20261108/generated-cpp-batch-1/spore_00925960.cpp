#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925960(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925960u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31a = 0;
    BatchLiftStatus t32_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35 = 0;
    BatchLiftStatus t36_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;

    // 0x00925960: 56 PUSH
        batch_guest_pc = 0x00925960u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925961: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00925963: 57 PUSH
        batch_guest_pc = 0x00925963u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00925964: 8d7e20 LEA
        t3 = static_cast<std::uint32_t>(state.regs[6] + 0x00000020u);
        state.regs[7] = t3;
    // 0x00925967: 68fcdf4301 PUSH
        batch_guest_pc = 0x00925967u;
        t4a = 0x0143dffcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0092596c: 8bcf MOV
        t5 = state.regs[7];
        state.regs[1] = t5;
    // 0x0092596e: e83dc8ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00925973u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_009221b0(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00925973u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925973: 8b4c240c MOV
        batch_guest_pc = 0x00925973u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x00925977: 33c0 XOR
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8r = (t8a ^ t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[0] = t8r;
    // 0x00925979: 894120 MOV
        batch_guest_pc = 0x00925979u;
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000020u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0092597c: c6410101 MOV
        batch_guest_pc = 0x0092597cu;
        t10 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x00000001u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00925980: 884102 MOV
        batch_guest_pc = 0x00925980u;
        t11 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x00000002u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00925983: 8b560c MOV
        batch_guest_pc = 0x00925983u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t12;
    // 0x00925986: 8b4608 MOV
        batch_guest_pc = 0x00925986u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00925989: 3bc2 CMP
        t14a = state.regs[0];
        t14b = state.regs[2];
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
    // 0x0092598b: 742d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009259ba;
    // 0x0092598d: 8d4900 LEA
        t16 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t16;
    // 0x00925990: 3908 CMP
    L_00925990:
        batch_guest_pc = 0x00925990u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = state.regs[1];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x00925992: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092599b;
    // 0x00925994: 83c004 ADD
        t19a = state.regs[0];
        t19b = 0x00000004u;
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[0] = t19r;
    // 0x00925997: 3bc2 CMP
        t20a = state.regs[0];
        t20b = state.regs[2];
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x00925999: 75f5 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925990;
    // 0x0092599b: 3bc2 CMP
    L_0092599b:
        t22a = state.regs[0];
        t22b = state.regs[2];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x0092599d: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009259ba;
    // 0x0092599f: 8b4e0c MOV
        batch_guest_pc = 0x0092599fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x009259a2: 8d5004 LEA
        t25 = static_cast<std::uint32_t>(state.regs[0] + 0x00000004u);
        state.regs[2] = t25;
    // 0x009259a5: 3bd1 CMP
        t26a = state.regs[2];
        t26b = state.regs[1];
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0xffffffffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 32u);
    // 0x009259a7: 730d JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_009259b6;
    // 0x009259a9: 2bca SUB
        t28a = state.regs[1];
        t28b = state.regs[2];
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
        state.regs[1] = t28r;
    // 0x009259ab: 51 PUSH
        batch_guest_pc = 0x009259abu;
        t29a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x009259ac: 52 PUSH
        batch_guest_pc = 0x009259acu;
        t30a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x009259ad: 50 PUSH
        batch_guest_pc = 0x009259adu;
        t31a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x009259ae: e891ad8b00 CALL
        t32_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x009259b3u);
        if (t32_call_status != BatchLiftStatus::returned) return t32_call_status;
        if (state.eip != 0x009259b3u) return BatchLiftStatus::invalid_control_flow;
    // 0x009259b3: 83c40c ADD
        t33a = state.regs[4];
        t33b = 0x0000000cu;
        t33r = static_cast<std::uint32_t>(t33a + t33b) & 0xffffffffu;
        batch_set_add_flags(state, t33a, t33b, t33r, 32u);
        state.regs[4] = t33r;
    // 0x009259b6: 83460cfc ADD
    L_009259b6:
        batch_guest_pc = 0x009259b6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t34a)) return BatchLiftStatus::invalid_memory;
        t34b = 0xfffffffcu;
        t34r = static_cast<std::uint32_t>(t34a + t34b) & 0xffffffffu;
        batch_set_add_flags(state, t34a, t34b, t34r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t34r)) return BatchLiftStatus::invalid_memory;
    // 0x009259ba: 8bcf MOV
    L_009259ba:
        t35 = state.regs[7];
        state.regs[1] = t35;
    // 0x009259bc: e8afc8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x009259c1u)) return BatchLiftStatus::invalid_memory;
        t36_call_status = spore_lift_00922270(memory, state);
        if (t36_call_status != BatchLiftStatus::returned) return t36_call_status;
        if (state.eip != 0x009259c1u) return BatchLiftStatus::invalid_control_flow;
    // 0x009259c1: 5f POP
        batch_guest_pc = 0x009259c1u;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t37a;
    // 0x009259c2: 5e POP
        batch_guest_pc = 0x009259c2u;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t38a;
    // 0x009259c3: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
