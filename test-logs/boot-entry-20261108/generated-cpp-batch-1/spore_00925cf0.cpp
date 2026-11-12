#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009289e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925cf0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925cf0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22 = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24a = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;

    // 0x00925cf0: 56 PUSH
        batch_guest_pc = 0x00925cf0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925cf1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00925cf3: 807e0800 CMP
        batch_guest_pc = 0x00925cf3u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t2a)) return BatchLiftStatus::invalid_memory;
        t2b = 0x00000000u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0x000000ffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 8u);
    // 0x00925cf7: c706e4e04301 MOV
        batch_guest_pc = 0x00925cf7u;
        t3 = 0x0143e0e4u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00925cfd: 7436 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925d35;
    // 0x00925cff: 8b460c MOV
        batch_guest_pc = 0x00925cffu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x00925d02: 85c0 TEST
        t6a = state.regs[0];
        t6b = state.regs[0];
        t6r = (t6a & t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
    // 0x00925d04: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925d1c;
    // 0x00925d06: 8b4e10 MOV
        batch_guest_pc = 0x00925d06u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t8;
    // 0x00925d09: 8b5604 MOV
        batch_guest_pc = 0x00925d09u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00925d0c: 51 PUSH
        batch_guest_pc = 0x00925d0cu;
        t10a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00925d0d: 52 PUSH
        batch_guest_pc = 0x00925d0du;
        t11a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00925d0e: 56 PUSH
        batch_guest_pc = 0x00925d0eu;
        t12a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00925d0f: ffd0 CALL
        t13_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00925d11u);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
    // 0x00925d11: 83c40c ADD
        t14a = state.regs[4];
        t14b = 0x0000000cu;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[4] = t14r;
    // 0x00925d14: c70634394001 MOV
        batch_guest_pc = 0x00925d14u;
        t15 = 0x01403934u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00925d1a: 5e POP
        batch_guest_pc = 0x00925d1au;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t16a;
    // 0x00925d1b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925d1c: 57 PUSH
    L_00925d1c:
        batch_guest_pc = 0x00925d1cu;
        t18a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00925d1d: 8b7e04 MOV
        batch_guest_pc = 0x00925d1du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t19;
    // 0x00925d20: 85ff TEST
        t20a = state.regs[7];
        t20b = state.regs[7];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00925d22: 7410 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925d34;
    // 0x00925d24: 8bcf MOV
        t22 = state.regs[7];
        state.regs[1] = t22;
    // 0x00925d26: e8b52c0000 CALL
        if (!batch_guest_call32(memory, state, 0x009289e0u, 0x00925d2bu)) return BatchLiftStatus::invalid_memory;
        t23_call_status = spore_lift_009289e0(memory, state);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x00925d2bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00925d2b: 57 PUSH
        batch_guest_pc = 0x00925d2bu;
        t24a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00925d2c: e84f166200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00925d31u)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_00f47380(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00925d31u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925d31: 83c404 ADD
        t26a = state.regs[4];
        t26b = 0x00000004u;
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[4] = t26r;
    // 0x00925d34: 5f POP
    L_00925d34:
        batch_guest_pc = 0x00925d34u;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t27a;
    // 0x00925d35: c70634394001 MOV
    L_00925d35:
        batch_guest_pc = 0x00925d35u;
        t28 = 0x01403934u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00925d3b: 5e POP
        batch_guest_pc = 0x00925d3bu;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t29a;
    // 0x00925d3c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
