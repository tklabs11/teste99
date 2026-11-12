#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00925dc0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925dc0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24r = 0;
    std::uint32_t t25a = 0, t25b = 0;
    std::uint32_t t26a = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38r = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51a = 0;

    // 0x00925dc0: 56 PUSH
        batch_guest_pc = 0x00925dc0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925dc1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00925dc3: 8b4614 MOV
        batch_guest_pc = 0x00925dc3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00925dc6: 57 PUSH
        batch_guest_pc = 0x00925dc6u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00925dc7: 8b7c240c MOV
        batch_guest_pc = 0x00925dc7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t4;
    // 0x00925dcb: 3bf8 CMP
        t5a = state.regs[7];
        t5b = state.regs[0];
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x00925dcd: 7607 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00925dd6;
    // 0x00925dcf: 85c0 TEST
        t7a = state.regs[0];
        t7b = state.regs[0];
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
    // 0x00925dd1: 7560 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925e33;
    // 0x00925dd3: 897e14 MOV
        batch_guest_pc = 0x00925dd3u;
        t9 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00925dd6: 837e0800 CMP
    L_00925dd6:
        batch_guest_pc = 0x00925dd6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t10a)) return BatchLiftStatus::invalid_memory;
        t10b = 0x00000000u;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x00925dda: 7547 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925e23;
    // 0x00925ddc: 8b54241c MOV
        batch_guest_pc = 0x00925ddcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t12;
    // 0x00925de0: 8b4e04 MOV
        batch_guest_pc = 0x00925de0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00925de3: 8b01 MOV
        batch_guest_pc = 0x00925de3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00925de5: 52 PUSH
        batch_guest_pc = 0x00925de5u;
        t15a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00925de6: 8b54241c MOV
        batch_guest_pc = 0x00925de6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t16;
    // 0x00925dea: 8b4004 MOV
        batch_guest_pc = 0x00925deau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x00925ded: 52 PUSH
        batch_guest_pc = 0x00925dedu;
        t18a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00925dee: 8b54241c MOV
        batch_guest_pc = 0x00925deeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t19;
    // 0x00925df2: 52 PUSH
        batch_guest_pc = 0x00925df2u;
        t20a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00925df3: 8b54241c MOV
        batch_guest_pc = 0x00925df3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x00925df7: 52 PUSH
        batch_guest_pc = 0x00925df7u;
        t22a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00925df8: 8b5618 MOV
        batch_guest_pc = 0x00925df8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t23;
    // 0x00925dfb: 42 INC
        t24a = state.regs[2];
        t24r = static_cast<std::uint32_t>(t24a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t24a, t24r, 32u);
        state.regs[2] = t24r;
    // 0x00925dfc: 0fafd7 IMUL
        t25a = state.regs[2];
        t25b = state.regs[7];
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t25a)) * static_cast<std::int32_t>(t25b);
        state.regs[2] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x00925dff: 52 PUSH
        batch_guest_pc = 0x00925dffu;
        t26a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00925e00: ffd0 CALL
        t27_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00925e02u);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
    // 0x00925e02: 8b4e0c MOV
        batch_guest_pc = 0x00925e02u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t28;
    // 0x00925e05: 8908 MOV
        batch_guest_pc = 0x00925e05u;
        t29 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00925e07: 89460c MOV
        batch_guest_pc = 0x00925e07u;
        t30 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00925e0a: 33c9 XOR
        t31a = state.regs[1];
        t31b = state.regs[1];
        t31r = (t31a ^ t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
        state.regs[1] = t31r;
    // 0x00925e0c: 03c7 ADD
        t32a = state.regs[0];
        t32b = state.regs[7];
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        state.regs[0] = t32r;
    // 0x00925e0e: 394e18 CMP
        batch_guest_pc = 0x00925e0eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t33a)) return BatchLiftStatus::invalid_memory;
        t33b = state.regs[1];
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
    // 0x00925e11: 7610 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00925e23;
    // 0x00925e13: 8b5608 MOV
    L_00925e13:
        batch_guest_pc = 0x00925e13u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t35;
    // 0x00925e16: 8910 MOV
        batch_guest_pc = 0x00925e16u;
        t36 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00925e18: 894608 MOV
        batch_guest_pc = 0x00925e18u;
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00925e1b: 41 INC
        t38a = state.regs[1];
        t38r = static_cast<std::uint32_t>(t38a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t38a, t38r, 32u);
        state.regs[1] = t38r;
    // 0x00925e1c: 03c7 ADD
        t39a = state.regs[0];
        t39b = state.regs[7];
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[0] = t39r;
    // 0x00925e1e: 3b4e18 CMP
        batch_guest_pc = 0x00925e1eu;
        t40a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t40b)) return BatchLiftStatus::invalid_memory;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0xffffffffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 32u);
    // 0x00925e21: 72f0 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00925e13;
    // 0x00925e23: 8b4608 MOV
    L_00925e23:
        batch_guest_pc = 0x00925e23u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t42;
    // 0x00925e26: ff4610 INC
        batch_guest_pc = 0x00925e26u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t43a)) return BatchLiftStatus::invalid_memory;
        t43r = static_cast<std::uint32_t>(t43a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t43a, t43r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t43r)) return BatchLiftStatus::invalid_memory;
    // 0x00925e29: 8b08 MOV
        batch_guest_pc = 0x00925e29u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t44;
    // 0x00925e2b: 5f POP
        batch_guest_pc = 0x00925e2bu;
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t45a;
    // 0x00925e2c: 894e08 MOV
        batch_guest_pc = 0x00925e2cu;
        t46 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00925e2f: 5e POP
        batch_guest_pc = 0x00925e2fu;
        if (!memory.load32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t47a;
    // 0x00925e30: c21400 RET
        if (!batch_guest_return32(memory, state, 20u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925e33: 5f POP
    L_00925e33:
        batch_guest_pc = 0x00925e33u;
        if (!memory.load32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t49a;
    // 0x00925e34: 33c0 XOR
        t50a = state.regs[0];
        t50b = state.regs[0];
        t50r = (t50a ^ t50b) & 0xffffffffu;
        batch_set_logic_flags(state, t50r, 32u);
        state.regs[0] = t50r;
    // 0x00925e36: 5e POP
        batch_guest_pc = 0x00925e36u;
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t51a;
    // 0x00925e37: c21400 RET
        if (!batch_guest_return32(memory, state, 20u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
