#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0093a650(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0093a650u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;

    // 0x0093a650: b800080000 MOV
    L_0093a650:
        t0 = 0x00000800u;
        state.regs[0] = t0;
    // 0x0093a655: 81ff00080000 CMP
        t1a = state.regs[7];
        t1b = 0x00000800u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
    // 0x0093a65b: 7302 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0093a65f;
    // 0x0093a65d: 8bc7 MOV
        t3 = state.regs[7];
        state.regs[0] = t3;
    // 0x0093a65f: 8b13 MOV
    L_0093a65f:
        batch_guest_pc = 0x0093a65fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t4;
    // 0x0093a661: 8b5230 MOV
        batch_guest_pc = 0x0093a661u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000030u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t5;
    // 0x0093a664: 50 PUSH
        batch_guest_pc = 0x0093a664u;
        t6a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a665: 8d442414 LEA
        t7 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[0] = t7;
    // 0x0093a669: 50 PUSH
        batch_guest_pc = 0x0093a669u;
        t8a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a66a: 8bcb MOV
        t9 = state.regs[3];
        state.regs[1] = t9;
    // 0x0093a66c: ffd2 CALL
        t10_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0093a66eu);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
    // 0x0093a66e: 8bf0 MOV
        t11 = state.regs[0];
        state.regs[6] = t11;
    // 0x0093a670: 83feff CMP
        t12a = state.regs[6];
        t12b = 0xffffffffu;
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x0093a673: 742f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093a6a4;
    // 0x0093a675: 8b8c2418080000 MOV
        batch_guest_pc = 0x0093a675u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000818u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x0093a67c: 8b01 MOV
        batch_guest_pc = 0x0093a67cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x0093a67e: 8b4038 MOV
        batch_guest_pc = 0x0093a67eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000038u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t16;
    // 0x0093a681: 56 PUSH
        batch_guest_pc = 0x0093a681u;
        t17a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a682: 8d542414 LEA
        t18 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[2] = t18;
    // 0x0093a686: 52 PUSH
        batch_guest_pc = 0x0093a686u;
        t19a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a687: ffd0 CALL
        t20_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0093a689u);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
    // 0x0093a689: 84c0 TEST
        t21a = state.regs[0] & 0x000000ffu;
        t21b = state.regs[0] & 0x000000ffu;
        t21r = (t21a & t21b) & 0x000000ffu;
        batch_set_logic_flags(state, t21r, 8u);
    // 0x0093a68b: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093a6a4;
    // 0x0093a68d: 85f6 TEST
        t23a = state.regs[6];
        t23b = state.regs[6];
        t23r = (t23a & t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
    // 0x0093a68f: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093a695;
    // 0x0093a691: 2bfe SUB
        t25a = state.regs[7];
        t25b = state.regs[6];
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
        state.regs[7] = t25r;
    // 0x0093a693: 75bb JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093a650;
    // 0x0093a695: 8bc5 MOV
    L_0093a695:
        t27 = state.regs[5];
        state.regs[0] = t27;
    // 0x0093a697: 2bc7 SUB
        t28a = state.regs[0];
        t28b = state.regs[7];
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
        state.regs[0] = t28r;
    // 0x0093a699: 5f POP
        batch_guest_pc = 0x0093a699u;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t29a;
    // 0x0093a69a: 5e POP
        batch_guest_pc = 0x0093a69au;
        if (!memory.load32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t30a;
    // 0x0093a69b: 5d POP
        batch_guest_pc = 0x0093a69bu;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t31a;
    // 0x0093a69c: 5b POP
        batch_guest_pc = 0x0093a69cu;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t32a;
    // 0x0093a69d: 81c400080000 ADD
        t33a = state.regs[4];
        t33b = 0x00000800u;
        t33r = static_cast<std::uint32_t>(t33a + t33b) & 0xffffffffu;
        batch_set_add_flags(state, t33a, t33b, t33r, 32u);
        state.regs[4] = t33r;
    // 0x0093a6a3: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093a6a4: 5f POP
    L_0093a6a4:
        batch_guest_pc = 0x0093a6a4u;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t35a;
    // 0x0093a6a5: 5e POP
        batch_guest_pc = 0x0093a6a5u;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t36a;
    // 0x0093a6a6: 5d POP
        batch_guest_pc = 0x0093a6a6u;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t37a;
    // 0x0093a6a7: 83c8ff OR
        t38a = state.regs[0];
        t38b = 0xffffffffu;
        t38r = (t38a | t38b) & 0xffffffffu;
        batch_set_logic_flags(state, t38r, 32u);
        state.regs[0] = t38r;
    // 0x0093a6aa: 5b POP
        batch_guest_pc = 0x0093a6aau;
        if (!memory.load32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t39a;
    // 0x0093a6ab: 81c400080000 ADD
        t40a = state.regs[4];
        t40b = 0x00000800u;
        t40r = static_cast<std::uint32_t>(t40a + t40b) & 0xffffffffu;
        batch_set_add_flags(state, t40a, t40b, t40r, 32u);
        state.regs[4] = t40r;
    // 0x0093a6b1: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
