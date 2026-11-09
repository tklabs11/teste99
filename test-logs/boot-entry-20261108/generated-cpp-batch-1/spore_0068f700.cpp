#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00922880(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0068f700(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0068f700u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;

    // 0x0068f700: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f702: 688acd2001 PUSH
        t1a = 0x0120cd8au;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f707: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x0068f70d: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f70e: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x0068f715: 51 PUSH
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f716: 81c1d8010000 ADD
        t6a = state.regs[1];
        t6b = 0x000001d8u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[1] = t6r;
    // 0x0068f71c: 56 PUSH
        t7a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f71d: 394904 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t8a)) return BatchLiftStatus::invalid_memory;
        t8b = state.regs[1];
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x0068f720: 7569 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0068f78b;
    // 0x0068f722: 6a00 PUSH
        t10a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f724: 6a00 PUSH
        t11a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f726: 6a00 PUSH
        t12a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f728: 6a00 PUSH
        t13a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f72a: 689c374001 PUSH
        t14a = 0x0140379cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f72f: 6a18 PUSH
        t15a = 0x00000018u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f731: e86a7c8b00 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x0068f736u)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00f473a0(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x0068f736u) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f736: 8bf0 MOV
        t17 = state.regs[0];
        state.regs[6] = t17;
    // 0x0068f738: 83c418 ADD
        t18a = state.regs[4];
        t18b = 0x00000018u;
        t18r = static_cast<std::uint32_t>(t18a + t18b) & 0xffffffffu;
        batch_set_add_flags(state, t18a, t18b, t18r, 32u);
        state.regs[4] = t18r;
    // 0x0068f73b: 89742404 MOV
        t19 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x0068f73f: c744241000000000 MOV
        t20 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x0068f747: 85f6 TEST
        t21a = state.regs[6];
        t21b = state.regs[6];
        t21r = (t21a & t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
    // 0x0068f749: 742e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f779;
    // 0x0068f74b: 6a00 PUSH
        t23a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f74d: 8d4e08 LEA
        t24 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[1] = t24;
    // 0x0068f750: c7460400000000 MOV
        t25 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x0068f757: c70600000000 MOV
        t26 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0068f75d: e81e312900 CALL
        t27_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00922880u, 0x0068f762u);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x0068f762u) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f762: 8936 MOV
        t28 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x0068f764: 897604 MOV
        t29 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x0068f767: 8bc6 MOV
        t30 = state.regs[6];
        state.regs[0] = t30;
    // 0x0068f769: 5e POP
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t31a;
    // 0x0068f76a: 8b4c2404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t32;
    // 0x0068f76e: 64890d00000000 MOV
        t33 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x0068f775: 83c410 ADD
        t34a = state.regs[4];
        t34b = 0x00000010u;
        t34r = static_cast<std::uint32_t>(t34a + t34b) & 0xffffffffu;
        batch_set_add_flags(state, t34a, t34b, t34r, 32u);
        state.regs[4] = t34r;
    // 0x0068f778: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0068f779: 33c0 XOR
    L_0068f779:
        t36a = state.regs[0];
        t36b = state.regs[0];
        t36r = (t36a ^ t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
        state.regs[0] = t36r;
    // 0x0068f77b: 5e POP
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t37a;
    // 0x0068f77c: 8b4c2404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t38;
    // 0x0068f780: 64890d00000000 MOV
        t39 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x0068f787: 83c410 ADD
        t40a = state.regs[4];
        t40b = 0x00000010u;
        t40r = static_cast<std::uint32_t>(t40a + t40b) & 0xffffffffu;
        batch_set_add_flags(state, t40a, t40b, t40r, 32u);
        state.regs[4] = t40r;
    // 0x0068f78a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0068f78b: 8b01 MOV
    L_0068f78b:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t42;
    // 0x0068f78d: 8bd0 MOV
        t43 = state.regs[0];
        state.regs[2] = t43;
    // 0x0068f78f: 8b32 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t44;
    // 0x0068f791: 894e04 MOV
        t45 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x0068f794: 8b31 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t46;
    // 0x0068f796: 8b36 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t47;
    // 0x0068f798: 8931 MOV
        t48 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x0068f79a: 3bd1 CMP
        t49a = state.regs[2];
        t49b = state.regs[1];
        t49r = static_cast<std::uint32_t>(t49a - t49b) & 0xffffffffu;
        batch_set_sub_flags(state, t49a, t49b, t49r, 32u);
    // 0x0068f79c: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f7ab;
    // 0x0068f79e: c7420400000000 MOV
        t51 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7a5: c70200000000 MOV
        t52 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7ab: 8b4c2408 MOV
    L_0068f7ab:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t53;
    // 0x0068f7af: 5e POP
        if (!memory.load32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t54a;
    // 0x0068f7b0: 64890d00000000 MOV
        t55 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t55)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7b7: 83c410 ADD
        t56a = state.regs[4];
        t56b = 0x00000010u;
        t56r = static_cast<std::uint32_t>(t56a + t56b) & 0xffffffffu;
        batch_set_add_flags(state, t56a, t56b, t56r, 32u);
        state.regs[4] = t56r;
    // 0x0068f7ba: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
