#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00690540(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_006908a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_006908a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x006908a0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38 = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;

    // 0x006908a0: 8b442408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x006908a4: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x006908a5: 55 PUSH
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x006908a6: 56 PUSH
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x006908a7: 8b742410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t4;
    // 0x006908ab: 837e1c03 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t5a)) return BatchLiftStatus::invalid_memory;
        t5b = 0x00000003u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x006908af: 57 PUSH
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x006908b0: 8bd9 MOV
        t7 = state.regs[1];
        state.regs[3] = t7;
    // 0x006908b2: 894648 MOV
        t8 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000048u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x006908b5: 7539 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_006908f0;
    // 0x006908b7: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x006908ba: 8b0e MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t11;
    // 0x006908bc: 8908 MOV
        t12 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x006908be: 894104 MOV
        t13 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x006908c1: c7460400000000 MOV
        t14 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x006908c8: c70600000000 MOV
        t15 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x006908ce: 8b4b60 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000060u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t16;
    // 0x006908d1: 8d435c LEA
        t17 = static_cast<std::uint32_t>(state.regs[3] + 0x0000005cu);
        state.regs[0] = t17;
    // 0x006908d4: 894e04 MOV
        t18 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x006908d7: 8906 MOV
        t19 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x006908d9: 897004 MOV
        t20 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x006908dc: 8b5604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x006908df: 8932 MOV
        t22 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x006908e1: 56 PUSH
        t23a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x006908e2: 8bcb MOV
        t24 = state.regs[3];
        state.regs[1] = t24;
    // 0x006908e4: c7461c02000000 MOV
        t25 = 0x00000002u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t25)) return BatchLiftStatus::invalid_memory;
    // 0x006908eb: e850fcffff CALL
        if (!batch_guest_call32(memory, state, 0x00690540u, 0x006908f0u)) return BatchLiftStatus::invalid_memory;
        t26_call_status = spore_lift_00690540(memory, state);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x006908f0u) return BatchLiftStatus::invalid_control_flow;
    // 0x006908f0: 8b7e38 MOV
    L_006908f0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000038u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t27;
    // 0x006908f3: 8d6e38 LEA
        t28 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[5] = t28;
    // 0x006908f6: 3bfd CMP
        t29a = state.regs[7];
        t29b = state.regs[5];
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
    // 0x006908f8: 7420 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069091a;
    // 0x006908fa: 8d9b00000000 LEA
        t31 = static_cast<std::uint32_t>(state.regs[3] + 0x00000000u);
        state.regs[3] = t31;
    // 0x00690900: 8b4710 MOV
    L_00690900:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x00690903: 8b4e48 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000048u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x00690906: 394848 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000048u), t34a)) return BatchLiftStatus::invalid_memory;
        t34b = state.regs[1];
        t34r = static_cast<std::uint32_t>(t34a - t34b) & 0xffffffffu;
        batch_set_sub_flags(state, t34a, t34b, t34r, 32u);
    // 0x00690909: 7d09 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00690914;
    // 0x0069090b: 51 PUSH
        t36a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x0069090c: 50 PUSH
        t37a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x0069090d: 8bcb MOV
        t38 = state.regs[3];
        state.regs[1] = t38;
    // 0x0069090f: e88cffffff CALL
        if (!batch_guest_call32(memory, state, 0x006908a0u, 0x00690914u)) return BatchLiftStatus::invalid_memory;
        t39_call_status = spore_lift_006908a0(memory, state);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
        if (state.eip != 0x00690914u) return BatchLiftStatus::invalid_control_flow;
    // 0x00690914: 8b3f MOV
    L_00690914:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t40;
    // 0x00690916: 3bfd CMP
        t41a = state.regs[7];
        t41b = state.regs[5];
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
    // 0x00690918: 75e6 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690900;
    // 0x0069091a: 5f POP
    L_0069091a:
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t43a;
    // 0x0069091b: 5e POP
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t44a;
    // 0x0069091c: 5d POP
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t45a;
    // 0x0069091d: 5b POP
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t46a;
    // 0x0069091e: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
