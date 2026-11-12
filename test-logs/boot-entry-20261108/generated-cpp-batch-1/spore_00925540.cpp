#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00697fa0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925540(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925540u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
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
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32a = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;

    // 0x00925540: 53 PUSH
        batch_guest_pc = 0x00925540u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925541: 56 PUSH
        batch_guest_pc = 0x00925541u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00925542: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00925544: c7460400000000 MOV
        batch_guest_pc = 0x00925544u;
        t3 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0092554b: c70600000000 MOV
        batch_guest_pc = 0x0092554bu;
        t4 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00925551: 57 PUSH
        batch_guest_pc = 0x00925551u;
        t5a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00925552: c7461000000000 MOV
        batch_guest_pc = 0x00925552u;
        t6 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00925559: e8422ad7ff CALL
        if (!batch_guest_call32(memory, state, 0x00697fa0u, 0x0092555eu)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_00697fa0(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x0092555eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092555e: 8b5e10 MOV
        batch_guest_pc = 0x0092555eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t8;
    // 0x00925561: 8bf8 MOV
        t9 = state.regs[0];
        state.regs[7] = t9;
    // 0x00925563: 3bfb CMP
        t10a = state.regs[7];
        t10b = state.regs[3];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x00925565: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925583;
    // 0x00925567: 85ff TEST
        t12a = state.regs[7];
        t12b = state.regs[7];
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
    // 0x00925569: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925573;
    // 0x0092556b: 8b07 MOV
        batch_guest_pc = 0x0092556bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x0092556d: 8b10 MOV
        batch_guest_pc = 0x0092556du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t15;
    // 0x0092556f: 8bcf MOV
        t16 = state.regs[7];
        state.regs[1] = t16;
    // 0x00925571: ffd2 CALL
        t17_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00925573u);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
    // 0x00925573: 897e10 MOV
    L_00925573:
        batch_guest_pc = 0x00925573u;
        t18 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00925576: 85db TEST
        t19a = state.regs[3];
        t19b = state.regs[3];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
    // 0x00925578: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925583;
    // 0x0092557a: 8b03 MOV
        batch_guest_pc = 0x0092557au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x0092557c: 8b5004 MOV
        batch_guest_pc = 0x0092557cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x0092557f: 8bcb MOV
        t23 = state.regs[3];
        state.regs[1] = t23;
    // 0x00925581: ffd2 CALL
        t24_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00925583u);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
    // 0x00925583: a19c8e6601 MOV
    L_00925583:
        batch_guest_pc = 0x00925583u;
        if (!memory.load32(0x01668e9cu, t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x00925588: 8b4810 MOV
        batch_guest_pc = 0x00925588u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t26;
    // 0x0092558b: 8b11 MOV
        batch_guest_pc = 0x0092558bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t27;
    // 0x0092558d: 8b4610 MOV
        batch_guest_pc = 0x0092558du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x00925590: 8b5210 MOV
        batch_guest_pc = 0x00925590u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000010u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t29;
    // 0x00925593: 50 PUSH
        batch_guest_pc = 0x00925593u;
        t30a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x00925594: ffd2 CALL
        t31_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00925596u);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
    // 0x00925596: 5f POP
        batch_guest_pc = 0x00925596u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t32a;
    // 0x00925597: 8bc6 MOV
        t33 = state.regs[6];
        state.regs[0] = t33;
    // 0x00925599: 5e POP
        batch_guest_pc = 0x00925599u;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t34a;
    // 0x0092559a: 5b POP
        batch_guest_pc = 0x0092559au;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t35a;
    // 0x0092559b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
