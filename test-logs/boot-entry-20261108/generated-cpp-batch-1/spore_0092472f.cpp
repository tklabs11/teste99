#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921580(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924600(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0092472f(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0092472fu);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    BatchLiftStatus t9_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25 = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27a = 0;
    BatchLiftStatus t28_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;

    // 0x0092472f: 8b4500 MOV
        batch_guest_pc = 0x0092472fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00924732: 8b3e MOV
        batch_guest_pc = 0x00924732u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t1;
    // 0x00924734: 8b501c MOV
        batch_guest_pc = 0x00924734u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x00924737: 8bcd MOV
        t3 = state.regs[5];
        state.regs[1] = t3;
    // 0x00924739: 83c718 ADD
        t4a = state.regs[7];
        t4b = 0x00000018u;
        t4r = static_cast<std::uint32_t>(t4a + t4b) & 0xffffffffu;
        batch_set_add_flags(state, t4a, t4b, t4r, 32u);
        state.regs[7] = t4r;
    // 0x0092473c: ffd2 CALL
        t5_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092473eu);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
    // 0x0092473e: 50 PUSH
        batch_guest_pc = 0x0092473eu;
        t6a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0092473f: 8b07 MOV
        batch_guest_pc = 0x0092473fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x00924741: 8bce MOV
        t8 = state.regs[6];
        state.regs[1] = t8;
    // 0x00924743: ffd0 CALL
        t9_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924745u);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
    // 0x00924745: 8b4d18 MOV
        batch_guest_pc = 0x00924745u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t10;
    // 0x00924748: 51 PUSH
        batch_guest_pc = 0x00924748u;
        t11a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00924749: 8d542417 LEA
        t12 = static_cast<std::uint32_t>(state.regs[4] + 0x00000017u);
        state.regs[2] = t12;
    // 0x0092474d: 52 PUSH
        batch_guest_pc = 0x0092474du;
        t13a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x0092474e: 8bce MOV
        t14 = state.regs[6];
        state.regs[1] = t14;
    // 0x00924750: 885c241b MOV
        batch_guest_pc = 0x00924750u;
        t15 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001bu), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00924754: e8a7feffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924759u)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00924600(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00924759u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924759: 8b7d24 MOV
        batch_guest_pc = 0x00924759u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000024u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t17;
    // 0x0092475c: 8d5d20 LEA
        t18 = static_cast<std::uint32_t>(state.regs[5] + 0x00000020u);
        state.regs[3] = t18;
    // 0x0092475f: 3bfb CMP
        t19a = state.regs[7];
        t19b = state.regs[3];
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x00924761: 741e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924781;
    // 0x00924763: 8b4714 MOV
    L_00924763:
        batch_guest_pc = 0x00924763u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000014u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00924766: 8b4f10 MOV
        batch_guest_pc = 0x00924766u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x00924769: 50 PUSH
        batch_guest_pc = 0x00924769u;
        t23a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x0092476a: 51 PUSH
        batch_guest_pc = 0x0092476au;
        t24a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x0092476b: 8bce MOV
        t25 = state.regs[6];
        state.regs[1] = t25;
    // 0x0092476d: e88efeffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924772u)) return BatchLiftStatus::invalid_memory;
        t26_call_status = spore_lift_00924600(memory, state);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x00924772u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924772: 57 PUSH
        batch_guest_pc = 0x00924772u;
        t27a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00924773: e808ceffff CALL
        if (!batch_guest_call32(memory, state, 0x00921580u, 0x00924778u)) return BatchLiftStatus::invalid_memory;
        t28_call_status = spore_lift_00921580(memory, state);
        if (t28_call_status != BatchLiftStatus::returned) return t28_call_status;
        if (state.eip != 0x00924778u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924778: 8bf8 MOV
        t29 = state.regs[0];
        state.regs[7] = t29;
    // 0x0092477a: 83c404 ADD
        t30a = state.regs[4];
        t30b = 0x00000004u;
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[4] = t30r;
    // 0x0092477d: 3bfb CMP
        t31a = state.regs[7];
        t31b = state.regs[3];
        t31r = static_cast<std::uint32_t>(t31a - t31b) & 0xffffffffu;
        batch_set_sub_flags(state, t31a, t31b, t31r, 32u);
    // 0x0092477f: 75e2 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924763;
    // 0x00924781: 5f POP
    L_00924781:
        batch_guest_pc = 0x00924781u;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t33a;
    // 0x00924782: 8bc6 MOV
        t34 = state.regs[6];
        state.regs[0] = t34;
    // 0x00924784: 5e POP
        batch_guest_pc = 0x00924784u;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t35a;
    // 0x00924785: 5d POP
        batch_guest_pc = 0x00924785u;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t36a;
    // 0x00924786: 5b POP
        batch_guest_pc = 0x00924786u;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t37a;
    // 0x00924787: 59 POP
        batch_guest_pc = 0x00924787u;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t38a;
    // 0x00924788: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
