#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00922150(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009222a0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;

    // 0x009222a0: 33c0 XOR
        t0a = state.regs[0];
        t0b = state.regs[0];
        t0r = (t0a ^ t0b) & 0xffffffffu;
        batch_set_logic_flags(state, t0r, 32u);
        state.regs[0] = t0r;
    // 0x009222a2: 83ec14 SUB
        t1a = state.regs[4];
        t1b = 0x00000014u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
        state.regs[4] = t1r;
    // 0x009222a5: 56 PUSH
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009222a6: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x009222a8: 8b4c241c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x009222ac: 894620 MOV
        t5 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x009222af: 894628 MOV
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x009222b2: b201 MOV
        t7 = 0x00000001u;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t7 << 0u) & 0x000000ffu);
    // 0x009222b4: 885624 MOV
        t8 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x009222b7: 8906 MOV
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x009222b9: 894604 MOV
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x009222bc: 894608 MOV
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x009222bf: 89460c MOV
        t12 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x009222c2: 894610 MOV
        t13 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x009222c5: 894614 MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x009222c8: 894618 MOV
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x009222cb: 89461c MOV
        t16 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x009222ce: 3bc8 CMP
        t17a = state.regs[1];
        t17b = state.regs[0];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x009222d0: 7523 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009222f5;
    // 0x009222d2: 38442420 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t19a)) return BatchLiftStatus::invalid_memory;
        t19b = state.regs[0] & 0x000000ffu;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0x000000ffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 8u);
    // 0x009222d6: 741d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009222f5;
    // 0x009222d8: 88442405 MOV
        t21 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000005u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x009222dc: 8d442404 LEA
        t22 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[0] = t22;
    // 0x009222e0: 50 PUSH
        t23a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x009222e1: 8bce MOV
        t24 = state.regs[6];
        state.regs[1] = t24;
    // 0x009222e3: 88542408 MOV
        t25 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x009222e7: e864feffff CALL
        if (!batch_guest_call32(memory, state, 0x00922150u, 0x009222ecu)) return BatchLiftStatus::invalid_memory;
        t26_call_status = spore_lift_00922150(memory, state);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x009222ecu) return BatchLiftStatus::invalid_control_flow;
    // 0x009222ec: 8bc6 MOV
        t27 = state.regs[6];
        state.regs[0] = t27;
    // 0x009222ee: 5e POP
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t28a;
    // 0x009222ef: 83c414 ADD
        t29a = state.regs[4];
        t29b = 0x00000014u;
        t29r = static_cast<std::uint32_t>(t29a + t29b) & 0xffffffffu;
        batch_set_add_flags(state, t29a, t29b, t29r, 32u);
        state.regs[4] = t29r;
    // 0x009222f2: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009222f5: 51 PUSH
    L_009222f5:
        t31a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x009222f6: 8bce MOV
        t32 = state.regs[6];
        state.regs[1] = t32;
    // 0x009222f8: e853feffff CALL
        if (!batch_guest_call32(memory, state, 0x00922150u, 0x009222fdu)) return BatchLiftStatus::invalid_memory;
        t33_call_status = spore_lift_00922150(memory, state);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
        if (state.eip != 0x009222fdu) return BatchLiftStatus::invalid_control_flow;
    // 0x009222fd: 8bc6 MOV
        t34 = state.regs[6];
        state.regs[0] = t34;
    // 0x009222ff: 5e POP
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t35a;
    // 0x00922300: 83c414 ADD
        t36a = state.regs[4];
        t36b = 0x00000014u;
        t36r = static_cast<std::uint32_t>(t36a + t36b) & 0xffffffffu;
        batch_set_add_flags(state, t36a, t36b, t36r, 32u);
        state.regs[4] = t36r;
    // 0x00922303: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
