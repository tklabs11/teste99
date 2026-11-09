#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00690540(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690b50(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00690930(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00690930u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
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
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36 = 0;
    BatchLiftStatus t37_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;

    // 0x00690930: 8b442408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00690934: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00690935: 55 PUSH
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00690936: 56 PUSH
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00690937: 8b742410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t4;
    // 0x0069093b: 837e1c03 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t5a)) return BatchLiftStatus::invalid_memory;
        t5b = 0x00000003u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x0069093f: 8b6e48 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000048u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t6;
    // 0x00690942: 57 PUSH
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00690943: 8bf9 MOV
        t8 = state.regs[1];
        state.regs[7] = t8;
    // 0x00690945: 894648 MOV
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000048u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00690948: 7539 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690983;
    // 0x0069094a: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x0069094d: 8b0e MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x0069094f: 8908 MOV
        t13 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00690951: 894104 MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00690954: c7460400000000 MOV
        t15 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0069095b: c70600000000 MOV
        t16 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00690961: 8b4f60 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000060u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x00690964: 8d475c LEA
        t18 = static_cast<std::uint32_t>(state.regs[7] + 0x0000005cu);
        state.regs[0] = t18;
    // 0x00690967: 894e04 MOV
        t19 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x0069096a: 8906 MOV
        t20 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x0069096c: 897004 MOV
        t21 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x0069096f: 8b5604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x00690972: 8932 MOV
        t23 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00690974: 56 PUSH
        t24a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00690975: 8bcf MOV
        t25 = state.regs[7];
        state.regs[1] = t25;
    // 0x00690977: c7461c02000000 MOV
        t26 = 0x00000002u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0069097e: e8bdfbffff CALL
        if (!batch_guest_call32(memory, state, 0x00690540u, 0x00690983u)) return BatchLiftStatus::invalid_memory;
        t27_call_status = spore_lift_00690540(memory, state);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x00690983u) return BatchLiftStatus::invalid_control_flow;
    // 0x00690983: 8d5e38 LEA
    L_00690983:
        t28 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[3] = t28;
    // 0x00690986: 8b33 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t29;
    // 0x00690988: 3bf3 CMP
        t30a = state.regs[6];
        t30b = state.regs[3];
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
    // 0x0069098a: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006909a2;
    // 0x0069098c: 8d642400 LEA
        t32 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t32;
    // 0x00690990: 8b4610 MOV
    L_00690990:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x00690993: 55 PUSH
        t34a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00690994: 50 PUSH
        t35a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00690995: 8bcf MOV
        t36 = state.regs[7];
        state.regs[1] = t36;
    // 0x00690997: e8b4010000 CALL
        t37_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00690b50u, 0x0069099cu);
        if (t37_call_status != BatchLiftStatus::returned) return t37_call_status;
        if (state.eip != 0x0069099cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069099c: 8b36 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t38;
    // 0x0069099e: 3bf3 CMP
        t39a = state.regs[6];
        t39b = state.regs[3];
        t39r = static_cast<std::uint32_t>(t39a - t39b) & 0xffffffffu;
        batch_set_sub_flags(state, t39a, t39b, t39r, 32u);
    // 0x006909a0: 75ee JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690990;
    // 0x006909a2: 5f POP
    L_006909a2:
        if (!memory.load32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t41a;
    // 0x006909a3: 5e POP
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t42a;
    // 0x006909a4: 5d POP
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t43a;
    // 0x006909a5: 5b POP
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t44a;
    // 0x006909a6: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
