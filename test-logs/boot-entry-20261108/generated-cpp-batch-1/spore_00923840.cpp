#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923840(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923840u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0, t28r = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33 = 0;
    BatchLiftStatus t34_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t35a = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;

    // 0x00923840: 51 PUSH
        batch_guest_pc = 0x00923840u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923841: 53 PUSH
        batch_guest_pc = 0x00923841u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923842: 56 PUSH
        batch_guest_pc = 0x00923842u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00923843: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x00923845: 8d4e38 LEA
        t4 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[1] = t4;
    // 0x00923848: 6878dc4301 PUSH
        batch_guest_pc = 0x00923848u;
        t5a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092384d: 894c240c MOV
        batch_guest_pc = 0x0092384du;
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00923851: e85ae9ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00923856u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_009221b0(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00923856u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923856: 33db XOR
        t8a = state.regs[3];
        t8b = state.regs[3];
        t8r = (t8a ^ t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[3] = t8r;
    // 0x00923858: 395c2410 CMP
        batch_guest_pc = 0x00923858u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t9a)) return BatchLiftStatus::invalid_memory;
        t9b = state.regs[3];
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x0092385c: 7433 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923891;
    // 0x0092385e: 55 PUSH
        batch_guest_pc = 0x0092385eu;
        t11a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x0092385f: 8b6e1c MOV
        batch_guest_pc = 0x0092385fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t12;
    // 0x00923862: 57 PUSH
        batch_guest_pc = 0x00923862u;
        t13a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00923863: 8b7e18 MOV
        batch_guest_pc = 0x00923863u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t14;
    // 0x00923866: 3bfd CMP
        t15a = state.regs[7];
        t15b = state.regs[5];
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x00923868: 7425 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092388f;
    // 0x0092386a: 8d9b00000000 LEA
        t17 = static_cast<std::uint32_t>(state.regs[3] + 0x00000000u);
        state.regs[3] = t17;
    // 0x00923870: 3b5c241c CMP
    L_00923870:
        batch_guest_pc = 0x00923870u;
        t18a = state.regs[3];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t18b)) return BatchLiftStatus::invalid_memory;
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
    // 0x00923874: 7319 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0092388f;
    // 0x00923876: 8b37 MOV
        batch_guest_pc = 0x00923876u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t20;
    // 0x00923878: 8b06 MOV
        batch_guest_pc = 0x00923878u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x0092387a: 8b10 MOV
        batch_guest_pc = 0x0092387au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x0092387c: 8bce MOV
        t23 = state.regs[6];
        state.regs[1] = t23;
    // 0x0092387e: ffd2 CALL
        t24_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00923880u);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
    // 0x00923880: 8b442418 MOV
        batch_guest_pc = 0x00923880u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x00923884: 893498 MOV
        batch_guest_pc = 0x00923884u;
        t26 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[3] * 4u + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00923887: 83c704 ADD
        t27a = state.regs[7];
        t27b = 0x00000004u;
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        state.regs[7] = t27r;
    // 0x0092388a: 43 INC
        t28a = state.regs[3];
        t28r = static_cast<std::uint32_t>(t28a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t28a, t28r, 32u);
        state.regs[3] = t28r;
    // 0x0092388b: 3bfd CMP
        t29a = state.regs[7];
        t29b = state.regs[5];
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
    // 0x0092388d: 75e1 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923870;
    // 0x0092388f: 5f POP
    L_0092388f:
        batch_guest_pc = 0x0092388fu;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t31a;
    // 0x00923890: 5d POP
        batch_guest_pc = 0x00923890u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t32a;
    // 0x00923891: 8b4c2408 MOV
    L_00923891:
        batch_guest_pc = 0x00923891u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x00923895: e8d6e9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x0092389au)) return BatchLiftStatus::invalid_memory;
        t34_call_status = spore_lift_00922270(memory, state);
        if (t34_call_status != BatchLiftStatus::returned) return t34_call_status;
        if (state.eip != 0x0092389au) return BatchLiftStatus::invalid_control_flow;
    // 0x0092389a: 5e POP
        batch_guest_pc = 0x0092389au;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t35a;
    // 0x0092389b: 8bc3 MOV
        t36 = state.regs[3];
        state.regs[0] = t36;
    // 0x0092389d: 5b POP
        batch_guest_pc = 0x0092389du;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t37a;
    // 0x0092389e: 59 POP
        batch_guest_pc = 0x0092389eu;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t38a;
    // 0x0092389f: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
