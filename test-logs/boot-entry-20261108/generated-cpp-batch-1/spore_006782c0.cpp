#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_006782c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x006782c0u);
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
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;

    // 0x006782c0: 55 PUSH
        batch_guest_pc = 0x006782c0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x006782c1: 8b6c2408 MOV
        batch_guest_pc = 0x006782c1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t1;
    // 0x006782c5: 3b6c240c CMP
        batch_guest_pc = 0x006782c5u;
        t2a = state.regs[5];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t2b)) return BatchLiftStatus::invalid_memory;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x006782c9: 743e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00678309;
    // 0x006782cb: 53 PUSH
        batch_guest_pc = 0x006782cbu;
        t4a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x006782cc: 8b5c2414 MOV
        batch_guest_pc = 0x006782ccu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t5;
    // 0x006782d0: 56 PUSH
        batch_guest_pc = 0x006782d0u;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x006782d1: 57 PUSH
        batch_guest_pc = 0x006782d1u;
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x006782d2: 8b7500 MOV
    L_006782d2:
        batch_guest_pc = 0x006782d2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t8;
    // 0x006782d5: 8b3b MOV
        batch_guest_pc = 0x006782d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t9;
    // 0x006782d7: 3bf7 CMP
        t10a = state.regs[6];
        t10b = state.regs[7];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x006782d9: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006782f6;
    // 0x006782db: 85f6 TEST
        t12a = state.regs[6];
        t12b = state.regs[6];
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
    // 0x006782dd: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006782e7;
    // 0x006782df: 8b06 MOV
        batch_guest_pc = 0x006782dfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x006782e1: 8b10 MOV
        batch_guest_pc = 0x006782e1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t15;
    // 0x006782e3: 8bce MOV
        t16 = state.regs[6];
        state.regs[1] = t16;
    // 0x006782e5: ffd2 CALL
        t17_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x006782e7u);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
    // 0x006782e7: 8933 MOV
    L_006782e7:
        batch_guest_pc = 0x006782e7u;
        t18 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x006782e9: 85ff TEST
        t19a = state.regs[7];
        t19b = state.regs[7];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
    // 0x006782eb: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006782f6;
    // 0x006782ed: 8b07 MOV
        batch_guest_pc = 0x006782edu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x006782ef: 8b5004 MOV
        batch_guest_pc = 0x006782efu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x006782f2: 8bcf MOV
        t23 = state.regs[7];
        state.regs[1] = t23;
    // 0x006782f4: ffd2 CALL
        t24_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x006782f6u);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
    // 0x006782f6: 83c504 ADD
    L_006782f6:
        t25a = state.regs[5];
        t25b = 0x00000004u;
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[5] = t25r;
    // 0x006782f9: 83c304 ADD
        t26a = state.regs[3];
        t26b = 0x00000004u;
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[3] = t26r;
    // 0x006782fc: 3b6c2418 CMP
        batch_guest_pc = 0x006782fcu;
        t27a = state.regs[5];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t27b)) return BatchLiftStatus::invalid_memory;
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
    // 0x00678300: 75d0 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_006782d2;
    // 0x00678302: 5f POP
        batch_guest_pc = 0x00678302u;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t29a;
    // 0x00678303: 5e POP
        batch_guest_pc = 0x00678303u;
        if (!memory.load32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t30a;
    // 0x00678304: 8bc3 MOV
        t31 = state.regs[3];
        state.regs[0] = t31;
    // 0x00678306: 5b POP
        batch_guest_pc = 0x00678306u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t32a;
    // 0x00678307: 5d POP
        batch_guest_pc = 0x00678307u;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t33a;
    // 0x00678308: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00678309: 8b442410 MOV
    L_00678309:
        batch_guest_pc = 0x00678309u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t35;
    // 0x0067830d: 5d POP
        batch_guest_pc = 0x0067830du;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t36a;
    // 0x0067830e: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
