#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00454cb0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924170(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924170u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39a = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42a = 0;

    // 0x00924170: 55 PUSH
        batch_guest_pc = 0x00924170u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00924171: 56 PUSH
        batch_guest_pc = 0x00924171u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00924172: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00924174: c706c8dc4301 MOV
        batch_guest_pc = 0x00924174u;
        t3 = 0x0143dcc8u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0092417a: c7460400000000 MOV
        batch_guest_pc = 0x0092417au;
        t4 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00924181: c7460800000000 MOV
        batch_guest_pc = 0x00924181u;
        t5 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x00924188: 57 PUSH
        batch_guest_pc = 0x00924188u;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00924189: 8b7c2410 MOV
        batch_guest_pc = 0x00924189u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t7;
    // 0x0092418d: 8d4e14 LEA
        t8 = static_cast<std::uint32_t>(state.regs[6] + 0x00000014u);
        state.regs[1] = t8;
    // 0x00924190: c6460c01 MOV
        batch_guest_pc = 0x00924190u;
        t9 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00924194: c7461000000000 MOV
        batch_guest_pc = 0x00924194u;
        t10 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x0092419b: 8bc7 MOV
        t11 = state.regs[7];
        state.regs[0] = t11;
    // 0x0092419d: c701ac7b6601 MOV
        batch_guest_pc = 0x0092419du;
        t12 = 0x01667bacu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x009241a3: c74104ac7b6601 MOV
        batch_guest_pc = 0x009241a3u;
        t13 = 0x01667bacu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x009241aa: c74108ad7b6601 MOV
        batch_guest_pc = 0x009241aau;
        t14 = 0x01667badu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x009241b1: 8d6801 LEA
        t15 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[5] = t15;
    // 0x009241b4: 8a10 MOV
    L_009241b4:
        batch_guest_pc = 0x009241b4u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t16 << 0u) & 0x000000ffu);
    // 0x009241b6: 40 INC
        t17a = state.regs[0];
        t17r = static_cast<std::uint32_t>(t17a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t17a, t17r, 32u);
        state.regs[0] = t17r;
    // 0x009241b7: 84d2 TEST
        t18a = state.regs[2] & 0x000000ffu;
        t18b = state.regs[2] & 0x000000ffu;
        t18r = (t18a & t18b) & 0x000000ffu;
        batch_set_logic_flags(state, t18r, 8u);
    // 0x009241b9: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009241b4;
    // 0x009241bb: 2bc5 SUB
        t20a = state.regs[0];
        t20b = state.regs[5];
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
        state.regs[0] = t20r;
    // 0x009241bd: 03c7 ADD
        t21a = state.regs[0];
        t21b = state.regs[7];
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[0] = t21r;
    // 0x009241bf: 50 PUSH
        batch_guest_pc = 0x009241bfu;
        t22a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x009241c0: 57 PUSH
        batch_guest_pc = 0x009241c0u;
        t23a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x009241c1: e8ea0ab3ff CALL
        if (!batch_guest_call32(memory, state, 0x00454cb0u, 0x009241c6u)) return BatchLiftStatus::invalid_memory;
        t24_call_status = spore_lift_00454cb0(memory, state);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x009241c6u) return BatchLiftStatus::invalid_control_flow;
    // 0x009241c6: 8b4e04 MOV
        batch_guest_pc = 0x009241c6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t25;
    // 0x009241c9: 85c9 TEST
        t26a = state.regs[1];
        t26b = state.regs[1];
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
    // 0x009241cb: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009241d5;
    // 0x009241cd: 8b01 MOV
        batch_guest_pc = 0x009241cdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x009241cf: 8b5018 MOV
        batch_guest_pc = 0x009241cfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t29;
    // 0x009241d2: 57 PUSH
        batch_guest_pc = 0x009241d2u;
        t30a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x009241d3: ffd2 CALL
        t31_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009241d5u);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
    // 0x009241d5: 8b4e08 MOV
    L_009241d5:
        batch_guest_pc = 0x009241d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t32;
    // 0x009241d8: 85c9 TEST
        t33a = state.regs[1];
        t33b = state.regs[1];
        t33r = (t33a & t33b) & 0xffffffffu;
        batch_set_logic_flags(state, t33r, 32u);
    // 0x009241da: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009241e4;
    // 0x009241dc: 8b01 MOV
        batch_guest_pc = 0x009241dcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t35;
    // 0x009241de: 8b5014 MOV
        batch_guest_pc = 0x009241deu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t36;
    // 0x009241e1: 57 PUSH
        batch_guest_pc = 0x009241e1u;
        t37a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x009241e2: ffd2 CALL
        t38_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009241e4u);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
    // 0x009241e4: 5f POP
    L_009241e4:
        batch_guest_pc = 0x009241e4u;
        if (!memory.load32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t39a;
    // 0x009241e5: 8bc6 MOV
        t40 = state.regs[6];
        state.regs[0] = t40;
    // 0x009241e7: 5e POP
        batch_guest_pc = 0x009241e7u;
        if (!memory.load32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t41a;
    // 0x009241e8: 5d POP
        batch_guest_pc = 0x009241e8u;
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t42a;
    // 0x009241e9: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
