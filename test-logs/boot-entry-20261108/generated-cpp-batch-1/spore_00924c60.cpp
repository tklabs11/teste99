#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00887090(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924c92(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924c60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924c60u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34r = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38 = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;

    // 0x00924c60: 83ec08 SUB
        t0a = state.regs[4];
        t0b = 0x00000008u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00924c63: 56 PUSH
        batch_guest_pc = 0x00924c63u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00924c64: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00924c66: 8b4e04 MOV
        batch_guest_pc = 0x00924c66u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t3;
    // 0x00924c69: 8b5608 MOV
        batch_guest_pc = 0x00924c69u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t4;
    // 0x00924c6c: 8d4101 LEA
        t5 = static_cast<std::uint32_t>(state.regs[1] + 0x00000001u);
        state.regs[0] = t5;
    // 0x00924c6f: 3bc2 CMP
        t6a = state.regs[0];
        t6b = state.regs[2];
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00924c71: 7555 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924cc8;
    // 0x00924c73: 8b06 MOV
        batch_guest_pc = 0x00924c73u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00924c75: 2bc8 SUB
        t9a = state.regs[1];
        t9b = state.regs[0];
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
        state.regs[1] = t9r;
    // 0x00924c77: 2bd0 SUB
        t10a = state.regs[2];
        t10b = state.regs[0];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
        state.regs[2] = t10r;
    // 0x00924c79: 57 PUSH
        batch_guest_pc = 0x00924c79u;
        t11a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00924c7a: 8d42ff LEA
        t12 = static_cast<std::uint32_t>(state.regs[2] + 0xffffffffu);
        state.regs[0] = t12;
    // 0x00924c7d: 8d7901 LEA
        t13 = static_cast<std::uint32_t>(state.regs[1] + 0x00000001u);
        state.regs[7] = t13;
    // 0x00924c80: 897c240c MOV
        batch_guest_pc = 0x00924c80u;
        t14 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00924c84: 83f808 CMP
        t15a = state.regs[0];
        t15b = 0x00000008u;
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x00924c87: 7604 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00924c8d;
    // 0x00924c89: 03c0 ADD
        t17a = state.regs[0];
        t17b = state.regs[0];
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        state.regs[0] = t17r;
    // 0x00924c8b: eb05 JMP
        goto L_00924c92;
    // 0x00924c8d: b808000000 MOV
    L_00924c8d:
        t19 = 0x00000008u;
        state.regs[0] = t19;
    // 0x00924c92: 3bc7 CMP
    L_00924c92:
        t20a = state.regs[0];
        t20b = state.regs[7];
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x00924c94: 89442408 MOV
        batch_guest_pc = 0x00924c94u;
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00924c98: 5f POP
        batch_guest_pc = 0x00924c98u;
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t22a;
    // 0x00924c99: 8d442408 LEA
        t23 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[0] = t23;
    // 0x00924c9d: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00924ca3;
    // 0x00924c9f: 8d442404 LEA
        t25 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[0] = t25;
    // 0x00924ca3: 8b00 MOV
    L_00924ca3:
        batch_guest_pc = 0x00924ca3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t26;
    // 0x00924ca5: 89442404 MOV
        batch_guest_pc = 0x00924ca5u;
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00924ca9: 3bc1 CMP
        t28a = state.regs[0];
        t28b = state.regs[1];
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x00924cab: 894c2408 MOV
        batch_guest_pc = 0x00924cabu;
        t29 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00924caf: 8d442408 LEA
        t30 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[0] = t30;
    // 0x00924cb3: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00924cb9;
    // 0x00924cb5: 8d442404 LEA
        t32 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[0] = t32;
    // 0x00924cb9: 8b00 MOV
    L_00924cb9:
        batch_guest_pc = 0x00924cb9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x00924cbb: 40 INC
        t34a = state.regs[0];
        t34r = static_cast<std::uint32_t>(t34a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t34a, t34r, 32u);
        state.regs[0] = t34r;
    // 0x00924cbc: 3bc2 CMP
        t35a = state.regs[0];
        t35b = state.regs[2];
        t35r = static_cast<std::uint32_t>(t35a - t35b) & 0xffffffffu;
        batch_set_sub_flags(state, t35a, t35b, t35r, 32u);
    // 0x00924cbe: 7608 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00924cc8;
    // 0x00924cc0: 50 PUSH
        batch_guest_pc = 0x00924cc0u;
        t37a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00924cc1: 8bce MOV
        t38 = state.regs[6];
        state.regs[1] = t38;
    // 0x00924cc3: e8c823f6ff CALL
        if (!batch_guest_call32(memory, state, 0x00887090u, 0x00924cc8u)) return BatchLiftStatus::invalid_memory;
        t39_call_status = spore_lift_00887090(memory, state);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
        if (state.eip != 0x00924cc8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924cc8: 8b4e04 MOV
    L_00924cc8:
        batch_guest_pc = 0x00924cc8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t40;
    // 0x00924ccb: 8a542410 MOV
        batch_guest_pc = 0x00924ccbu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t41 << 0u) & 0x000000ffu);
    // 0x00924ccf: 8811 MOV
        batch_guest_pc = 0x00924ccfu;
        t42 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x00924cd1: ff4604 INC
        batch_guest_pc = 0x00924cd1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t43a)) return BatchLiftStatus::invalid_memory;
        t43r = static_cast<std::uint32_t>(t43a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t43a, t43r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t43r)) return BatchLiftStatus::invalid_memory;
    // 0x00924cd4: 8b7604 MOV
        batch_guest_pc = 0x00924cd4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t44;
    // 0x00924cd7: c60600 MOV
        batch_guest_pc = 0x00924cd7u;
        t45 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x00924cda: 5e POP
        batch_guest_pc = 0x00924cdau;
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t46a;
    // 0x00924cdb: 83c408 ADD
        t47a = state.regs[4];
        t47b = 0x00000008u;
        t47r = static_cast<std::uint32_t>(t47a + t47b) & 0xffffffffu;
        batch_set_add_flags(state, t47a, t47b, t47r, 32u);
        state.regs[4] = t47r;
    // 0x00924cde: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
