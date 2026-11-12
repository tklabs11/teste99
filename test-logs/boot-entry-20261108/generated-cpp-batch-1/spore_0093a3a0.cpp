#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0093a3d2(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0093a3a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0093a3a0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20c = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31a = 0, t31b = 0, t31c = 0, t31r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0, t33b = 0, t33c = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42a = 0, t42b = 0, t42c = 0, t42r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;

    // 0x0093a3a0: 83ec08 SUB
        t0a = state.regs[4];
        t0b = 0x00000008u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x0093a3a3: 53 PUSH
        batch_guest_pc = 0x0093a3a3u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a3a4: 56 PUSH
        batch_guest_pc = 0x0093a3a4u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a3a5: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x0093a3a7: 8b06 MOV
        batch_guest_pc = 0x0093a3a7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0093a3a9: 0b4604 OR
        batch_guest_pc = 0x0093a3a9u;
        t5a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t5b)) return BatchLiftStatus::invalid_memory;
        t5r = (t5a | t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        state.regs[0] = t5r;
    // 0x0093a3ac: 8b5e0c MOV
        batch_guest_pc = 0x0093a3acu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t6;
    // 0x0093a3af: 57 PUSH
        batch_guest_pc = 0x0093a3afu;
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a3b0: 8b7e08 MOV
        batch_guest_pc = 0x0093a3b0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t8;
    // 0x0093a3b3: 7455 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093a40a;
    // 0x0093a3b5: 837e1001 CMP
        batch_guest_pc = 0x0093a3b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t10a)) return BatchLiftStatus::invalid_memory;
        t10b = 0x00000001u;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x0093a3b9: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093a3bf;
    // 0x0093a3bb: 0f31 RDTSC
        if (!batch_guest_rdtsc(state)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a3bd: eb13 JMP
        goto L_0093a3d2;
    // 0x0093a3bf: 8d4c240c LEA
    L_0093a3bf:
        t14 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t14;
    // 0x0093a3c3: 51 PUSH
        batch_guest_pc = 0x0093a3c3u;
        t15a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a3c4: ff15b8c23c01 CALL
        t16_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!QueryPerformanceCounter", 0x013cc2b8u, 0x0093a3cau);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x0093a3cau) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a3ca: 8b44240c MOV
        batch_guest_pc = 0x0093a3cau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x0093a3ce: 8b542410 MOV
        batch_guest_pc = 0x0093a3ceu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x0093a3d2: 2b06 SUB
    L_0093a3d2:
        batch_guest_pc = 0x0093a3d2u;
        t19a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t19b)) return BatchLiftStatus::invalid_memory;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
        state.regs[0] = t19r;
    // 0x0093a3d4: 1b5604 SBB
        batch_guest_pc = 0x0093a3d4u;
        t20a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t20b)) return BatchLiftStatus::invalid_memory;
        t20c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t20r = static_cast<std::uint32_t>(t20a - t20b - t20c) & 0xffffffffu;
        batch_set_sbb_flags(state, t20a, t20b, t20c, t20r, 32u);
        state.regs[2] = t20r;
    // 0x0093a3d7: 8bc8 MOV
        t21 = state.regs[0];
        state.regs[1] = t21;
    // 0x0093a3d9: 8bc2 MOV
        t22 = state.regs[2];
        state.regs[0] = t22;
    // 0x0093a3db: 8b15a4996601 MOV
        batch_guest_pc = 0x0093a3dbu;
        if (!memory.load32(0x016699a4u, t23)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t23;
    // 0x0093a3e1: 3bc2 CMP
        t24a = state.regs[0];
        t24b = state.regs[2];
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x0093a3e3: 721f JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0093a404;
    // 0x0093a3e5: 8b35a0996601 MOV
        batch_guest_pc = 0x0093a3e5u;
        if (!memory.load32(0x016699a0u, t26)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t26;
    // 0x0093a3eb: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0093a3f1;
    // 0x0093a3ed: 3bce CMP
        t28a = state.regs[1];
        t28b = state.regs[6];
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x0093a3ef: 7613 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0093a404;
    // 0x0093a3f1: 2bce SUB
    L_0093a3f1:
        t30a = state.regs[1];
        t30b = state.regs[6];
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
        state.regs[1] = t30r;
    // 0x0093a3f3: 1bc2 SBB
        t31a = state.regs[0];
        t31b = state.regs[2];
        t31c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t31r = static_cast<std::uint32_t>(t31a - t31b - t31c) & 0xffffffffu;
        batch_set_sbb_flags(state, t31a, t31b, t31c, t31r, 32u);
        state.regs[0] = t31r;
    // 0x0093a3f5: 03f9 ADD
        t32a = state.regs[7];
        t32b = state.regs[1];
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        state.regs[7] = t32r;
    // 0x0093a3f7: 13d8 ADC
        t33a = state.regs[3];
        t33b = state.regs[0];
        t33c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t33r = static_cast<std::uint32_t>(t33a + t33b + t33c) & 0xffffffffu;
        batch_set_adc_flags(state, t33a, t33b, t33c, t33r, 32u);
        state.regs[3] = t33r;
    // 0x0093a3f9: 8bc7 MOV
        t34 = state.regs[7];
        state.regs[0] = t34;
    // 0x0093a3fb: 5f POP
        batch_guest_pc = 0x0093a3fbu;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t35a;
    // 0x0093a3fc: 5e POP
        batch_guest_pc = 0x0093a3fcu;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t36a;
    // 0x0093a3fd: 8bd3 MOV
        t37 = state.regs[3];
        state.regs[2] = t37;
    // 0x0093a3ff: 5b POP
        batch_guest_pc = 0x0093a3ffu;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t38a;
    // 0x0093a400: 83c408 ADD
        t39a = state.regs[4];
        t39b = 0x00000008u;
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[4] = t39r;
    // 0x0093a403: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093a404: 83c701 ADD
    L_0093a404:
        t41a = state.regs[7];
        t41b = 0x00000001u;
        t41r = static_cast<std::uint32_t>(t41a + t41b) & 0xffffffffu;
        batch_set_add_flags(state, t41a, t41b, t41r, 32u);
        state.regs[7] = t41r;
    // 0x0093a407: 83d300 ADC
        t42a = state.regs[3];
        t42b = 0x00000000u;
        t42c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t42r = static_cast<std::uint32_t>(t42a + t42b + t42c) & 0xffffffffu;
        batch_set_adc_flags(state, t42a, t42b, t42c, t42r, 32u);
        state.regs[3] = t42r;
    // 0x0093a40a: 8bc7 MOV
    L_0093a40a:
        t43 = state.regs[7];
        state.regs[0] = t43;
    // 0x0093a40c: 5f POP
        batch_guest_pc = 0x0093a40cu;
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t44a;
    // 0x0093a40d: 5e POP
        batch_guest_pc = 0x0093a40du;
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t45a;
    // 0x0093a40e: 8bd3 MOV
        t46 = state.regs[3];
        state.regs[2] = t46;
    // 0x0093a410: 5b POP
        batch_guest_pc = 0x0093a410u;
        if (!memory.load32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t47a;
    // 0x0093a411: 83c408 ADD
        t48a = state.regs[4];
        t48b = 0x00000008u;
        t48r = static_cast<std::uint32_t>(t48a + t48b) & 0xffffffffu;
        batch_set_add_flags(state, t48a, t48b, t48r, 32u);
        state.regs[4] = t48r;
    // 0x0093a414: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
