#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00454cb0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924010(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924010u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31a = 0;
    std::uint32_t t32a = 0;

    // 0x00924010: 56 PUSH
        batch_guest_pc = 0x00924010u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00924011: 8b742408 MOV
        batch_guest_pc = 0x00924011u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t1;
    // 0x00924015: 8bc6 MOV
        t2 = state.regs[6];
        state.regs[0] = t2;
    // 0x00924017: 57 PUSH
        batch_guest_pc = 0x00924017u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00924018: 8bf9 MOV
        t4 = state.regs[1];
        state.regs[7] = t4;
    // 0x0092401a: 8d5001 LEA
        t5 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t5;
    // 0x0092401d: 8d4900 LEA
        t6 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t6;
    // 0x00924020: 8a08 MOV
    L_00924020:
        batch_guest_pc = 0x00924020u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t7 << 0u) & 0x000000ffu);
    // 0x00924022: 40 INC
        t8a = state.regs[0];
        t8r = static_cast<std::uint32_t>(t8a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t8a, t8r, 32u);
        state.regs[0] = t8r;
    // 0x00924023: 84c9 TEST
        t9a = state.regs[1] & 0x000000ffu;
        t9b = state.regs[1] & 0x000000ffu;
        t9r = (t9a & t9b) & 0x000000ffu;
        batch_set_logic_flags(state, t9r, 8u);
    // 0x00924025: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924020;
    // 0x00924027: 2bc2 SUB
        t11a = state.regs[0];
        t11b = state.regs[2];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
        state.regs[0] = t11r;
    // 0x00924029: 03c6 ADD
        t12a = state.regs[0];
        t12b = state.regs[6];
        t12r = static_cast<std::uint32_t>(t12a + t12b) & 0xffffffffu;
        batch_set_add_flags(state, t12a, t12b, t12r, 32u);
        state.regs[0] = t12r;
    // 0x0092402b: 50 PUSH
        batch_guest_pc = 0x0092402bu;
        t13a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x0092402c: 56 PUSH
        batch_guest_pc = 0x0092402cu;
        t14a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x0092402d: 8d4f14 LEA
        t15 = static_cast<std::uint32_t>(state.regs[7] + 0x00000014u);
        state.regs[1] = t15;
    // 0x00924030: e87b0cb3ff CALL
        if (!batch_guest_call32(memory, state, 0x00454cb0u, 0x00924035u)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00454cb0(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00924035u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924035: 8b4f04 MOV
        batch_guest_pc = 0x00924035u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x00924038: 85c9 TEST
        t18a = state.regs[1];
        t18b = state.regs[1];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
    // 0x0092403a: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924044;
    // 0x0092403c: 8b01 MOV
        batch_guest_pc = 0x0092403cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t20;
    // 0x0092403e: 8b5018 MOV
        batch_guest_pc = 0x0092403eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x00924041: 56 PUSH
        batch_guest_pc = 0x00924041u;
        t22a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00924042: ffd2 CALL
        t23_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924044u);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
    // 0x00924044: 8b4f08 MOV
    L_00924044:
        batch_guest_pc = 0x00924044u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x00924047: 85c9 TEST
        t25a = state.regs[1];
        t25b = state.regs[1];
        t25r = (t25a & t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
    // 0x00924049: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924053;
    // 0x0092404b: 8b01 MOV
        batch_guest_pc = 0x0092404bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t27;
    // 0x0092404d: 8b5014 MOV
        batch_guest_pc = 0x0092404du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t28;
    // 0x00924050: 56 PUSH
        batch_guest_pc = 0x00924050u;
        t29a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00924051: ffd2 CALL
        t30_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924053u);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
    // 0x00924053: 5f POP
    L_00924053:
        batch_guest_pc = 0x00924053u;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t31a;
    // 0x00924054: 5e POP
        batch_guest_pc = 0x00924054u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t32a;
    // 0x00924055: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
