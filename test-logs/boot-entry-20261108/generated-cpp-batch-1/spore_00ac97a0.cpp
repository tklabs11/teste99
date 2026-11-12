#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00ac97a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00ac97a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;

    // 0x00ac97a0: 55 PUSH
        batch_guest_pc = 0x00ac97a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00ac97a1: 8b6c240c MOV
        batch_guest_pc = 0x00ac97a1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t1;
    // 0x00ac97a5: 3b6c2408 CMP
        batch_guest_pc = 0x00ac97a5u;
        t2a = state.regs[5];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t2b)) return BatchLiftStatus::invalid_memory;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x00ac97a9: 743f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00ac97ea;
    // 0x00ac97ab: 53 PUSH
        batch_guest_pc = 0x00ac97abu;
        t4a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00ac97ac: 8b5c2414 MOV
        batch_guest_pc = 0x00ac97acu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t5;
    // 0x00ac97b0: 56 PUSH
        batch_guest_pc = 0x00ac97b0u;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00ac97b1: 57 PUSH
        batch_guest_pc = 0x00ac97b1u;
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00ac97b2: 8b75fc MOV
    L_00ac97b2:
        batch_guest_pc = 0x00ac97b2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t8;
    // 0x00ac97b5: 8b7bfc MOV
        batch_guest_pc = 0x00ac97b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0xfffffffcu), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t9;
    // 0x00ac97b8: 83ed04 SUB
        t10a = state.regs[5];
        t10b = 0x00000004u;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
        state.regs[5] = t10r;
    // 0x00ac97bb: 83eb04 SUB
        t11a = state.regs[3];
        t11b = 0x00000004u;
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
        state.regs[3] = t11r;
    // 0x00ac97be: 3bf7 CMP
        t12a = state.regs[6];
        t12b = state.regs[7];
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x00ac97c0: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00ac97dd;
    // 0x00ac97c2: 85f6 TEST
        t14a = state.regs[6];
        t14b = state.regs[6];
        t14r = (t14a & t14b) & 0xffffffffu;
        batch_set_logic_flags(state, t14r, 32u);
    // 0x00ac97c4: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00ac97ce;
    // 0x00ac97c6: 8b06 MOV
        batch_guest_pc = 0x00ac97c6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t16;
    // 0x00ac97c8: 8b10 MOV
        batch_guest_pc = 0x00ac97c8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x00ac97ca: 8bce MOV
        t18 = state.regs[6];
        state.regs[1] = t18;
    // 0x00ac97cc: ffd2 CALL
        t19_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00ac97ceu);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
    // 0x00ac97ce: 8933 MOV
    L_00ac97ce:
        batch_guest_pc = 0x00ac97ceu;
        t20 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00ac97d0: 85ff TEST
        t21a = state.regs[7];
        t21b = state.regs[7];
        t21r = (t21a & t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
    // 0x00ac97d2: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00ac97dd;
    // 0x00ac97d4: 8b07 MOV
        batch_guest_pc = 0x00ac97d4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x00ac97d6: 8b5004 MOV
        batch_guest_pc = 0x00ac97d6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t24;
    // 0x00ac97d9: 8bcf MOV
        t25 = state.regs[7];
        state.regs[1] = t25;
    // 0x00ac97db: ffd2 CALL
        t26_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00ac97ddu);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
    // 0x00ac97dd: 3b6c2414 CMP
    L_00ac97dd:
        batch_guest_pc = 0x00ac97ddu;
        t27a = state.regs[5];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t27b)) return BatchLiftStatus::invalid_memory;
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
    // 0x00ac97e1: 75cf JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00ac97b2;
    // 0x00ac97e3: 5f POP
        batch_guest_pc = 0x00ac97e3u;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t29a;
    // 0x00ac97e4: 5e POP
        batch_guest_pc = 0x00ac97e4u;
        if (!memory.load32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t30a;
    // 0x00ac97e5: 8bc3 MOV
        t31 = state.regs[3];
        state.regs[0] = t31;
    // 0x00ac97e7: 5b POP
        batch_guest_pc = 0x00ac97e7u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t32a;
    // 0x00ac97e8: 5d POP
        batch_guest_pc = 0x00ac97e8u;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t33a;
    // 0x00ac97e9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00ac97ea: 8b442410 MOV
    L_00ac97ea:
        batch_guest_pc = 0x00ac97eau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t35;
    // 0x00ac97ee: 5d POP
        batch_guest_pc = 0x00ac97eeu;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t36a;
    // 0x00ac97ef: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
