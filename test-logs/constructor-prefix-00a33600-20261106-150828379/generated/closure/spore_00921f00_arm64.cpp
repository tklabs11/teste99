#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921e60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009222a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922820(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00921f00(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    BatchLiftStatus t29_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35 = 0;
    BatchLiftStatus t36_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;

    // 0x00921f00: 83ec14 SUB
        t0a = state.regs[4];
        t0b = 0x00000014u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00921f03: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00921f04: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00921f06: 33c0 XOR
        t3a = state.regs[0];
        t3b = state.regs[0];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[0] = t3r;
    // 0x00921f08: 8701 XCHG
        if (!batch_guest_xchg32(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00921f0a: 6a00 PUSH
        t5a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00921f0c: 6a00 PUSH
        t6a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00921f0e: 8d4e0c LEA
        t7 = static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu);
        state.regs[1] = t7;
    // 0x00921f11: c7460400000000 MOV
        t8 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00921f18: c7460800000000 MOV
        t9 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00921f1f: e8fc080000 CALL
        if (!batch_guest_call32(memory, state, 0x00922820u, 0x00921f24u)) return BatchLiftStatus::invalid_memory;
        t10_call_status = spore_lift_00922820(memory, state);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x00921f24u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921f24: 6a00 PUSH
        t11a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00921f26: 6a00 PUSH
        t12a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00921f28: 8d4e1c LEA
        t13 = static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu);
        state.regs[1] = t13;
    // 0x00921f2b: e8f0080000 CALL
        if (!batch_guest_call32(memory, state, 0x00922820u, 0x00921f30u)) return BatchLiftStatus::invalid_memory;
        t14_call_status = spore_lift_00922820(memory, state);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x00921f30u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921f30: 6a00 PUSH
        t15a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00921f32: 6a00 PUSH
        t16a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00921f34: 8d4e30 LEA
        t17 = static_cast<std::uint32_t>(state.regs[6] + 0x00000030u);
        state.regs[1] = t17;
    // 0x00921f37: e864030000 CALL
        if (!batch_guest_call32(memory, state, 0x009222a0u, 0x00921f3cu)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_009222a0(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00921f3cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00921f3c: 8b44241c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x00921f40: 85c0 TEST
        t20a = state.regs[0];
        t20b = state.regs[0];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00921f42: 7524 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921f68;
    // 0x00921f44: 38442420 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t22a)) return BatchLiftStatus::invalid_memory;
        t22b = state.regs[0] & 0x000000ffu;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0x000000ffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 8u);
    // 0x00921f48: 741e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921f68;
    // 0x00921f4a: 8d542404 LEA
        t24 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[2] = t24;
    // 0x00921f4e: 52 PUSH
        t25a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00921f4f: 8bce MOV
        t26 = state.regs[6];
        state.regs[1] = t26;
    // 0x00921f51: c644240801 MOV
        t27 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00921f56: 88442409 MOV
        t28 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000009u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00921f5a: e801ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00921e60u, 0x00921f5fu)) return BatchLiftStatus::invalid_memory;
        t29_call_status = spore_lift_00921e60(memory, state);
        if (t29_call_status != BatchLiftStatus::returned) return t29_call_status;
        if (state.eip != 0x00921f5fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00921f5f: 8bc6 MOV
        t30 = state.regs[6];
        state.regs[0] = t30;
    // 0x00921f61: 5e POP
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t31a;
    // 0x00921f62: 83c414 ADD
        t32a = state.regs[4];
        t32b = 0x00000014u;
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        state.regs[4] = t32r;
    // 0x00921f65: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00921f68: 50 PUSH
    L_00921f68:
        t34a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00921f69: 8bce MOV
        t35 = state.regs[6];
        state.regs[1] = t35;
    // 0x00921f6b: e8f0feffff CALL
        if (!batch_guest_call32(memory, state, 0x00921e60u, 0x00921f70u)) return BatchLiftStatus::invalid_memory;
        t36_call_status = spore_lift_00921e60(memory, state);
        if (t36_call_status != BatchLiftStatus::returned) return t36_call_status;
        if (state.eip != 0x00921f70u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921f70: 8bc6 MOV
        t37 = state.regs[6];
        state.regs[0] = t37;
    // 0x00921f72: 5e POP
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t38a;
    // 0x00921f73: 83c414 ADD
        t39a = state.regs[4];
        t39b = 0x00000014u;
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[4] = t39r;
    // 0x00921f76: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
