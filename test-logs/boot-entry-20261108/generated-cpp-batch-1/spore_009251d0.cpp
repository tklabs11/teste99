#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009251d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009251d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;

    // 0x009251d0: 56 PUSH
        batch_guest_pc = 0x009251d0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009251d1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x009251d3: 57 PUSH
        batch_guest_pc = 0x009251d3u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009251d4: 8d7e20 LEA
        t3 = static_cast<std::uint32_t>(state.regs[6] + 0x00000020u);
        state.regs[7] = t3;
    // 0x009251d7: 68fcdf4301 PUSH
        batch_guest_pc = 0x009251d7u;
        t4a = 0x0143dffcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009251dc: 8bcf MOV
        t5 = state.regs[7];
        state.regs[1] = t5;
    // 0x009251de: e8cdcfffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x009251e3u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_009221b0(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x009251e3u) return BatchLiftStatus::invalid_control_flow;
    // 0x009251e3: 8b4e08 MOV
        batch_guest_pc = 0x009251e3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x009251e6: 8b560c MOV
        batch_guest_pc = 0x009251e6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x009251e9: 8b44240c MOV
        batch_guest_pc = 0x009251e9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x009251ed: 894604 MOV
        batch_guest_pc = 0x009251edu;
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x009251f0: 3bca CMP
        t11a = state.regs[1];
        t11b = state.regs[2];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x009251f2: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092520d;
    // 0x009251f4: 55 PUSH
        batch_guest_pc = 0x009251f4u;
        t13a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x009251f5: 8b01 MOV
    L_009251f5:
        batch_guest_pc = 0x009251f5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x009251f7: 8b6e04 MOV
        batch_guest_pc = 0x009251f7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t15;
    // 0x009251fa: 83c104 ADD
        t16a = state.regs[1];
        t16b = 0x00000004u;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[1] = t16r;
    // 0x009251fd: 896820 MOV
        batch_guest_pc = 0x009251fdu;
        t17 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000020u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00925200: c6400101 MOV
        batch_guest_pc = 0x00925200u;
        t18 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000001u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00925204: c6400200 MOV
        batch_guest_pc = 0x00925204u;
        t19 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000002u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00925208: 3bca CMP
        t20a = state.regs[1];
        t20b = state.regs[2];
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x0092520a: 75e9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009251f5;
    // 0x0092520c: 5d POP
        batch_guest_pc = 0x0092520cu;
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t22a;
    // 0x0092520d: 8bcf MOV
    L_0092520d:
        t23 = state.regs[7];
        state.regs[1] = t23;
    // 0x0092520f: e85cd0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00925214u)) return BatchLiftStatus::invalid_memory;
        t24_call_status = spore_lift_00922270(memory, state);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x00925214u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925214: 5f POP
        batch_guest_pc = 0x00925214u;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t25a;
    // 0x00925215: 5e POP
        batch_guest_pc = 0x00925215u;
        if (!memory.load32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t26a;
    // 0x00925216: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
