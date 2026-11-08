#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921e00(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922150(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009225d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922620(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00921e60(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10c = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    BatchLiftStatus t29_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40 = 0;
    BatchLiftStatus t41_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46 = 0;
    BatchLiftStatus t47_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;

    // 0x00921e60: 83ec44 SUB
        t0a = state.regs[4];
        t0b = 0x00000044u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00921e63: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e64: 8bd9 MOV
        t2 = state.regs[1];
        state.regs[3] = t2;
    // 0x00921e66: 8b4c244c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t3;
    // 0x00921e6a: 85c9 TEST
        t4a = state.regs[1];
        t4b = state.regs[1];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x00921e6c: 747c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921eea;
    // 0x00921e6e: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e6f: 0fbe7101 MOVSX
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000001u), t7a)) return BatchLiftStatus::invalid_memory;
        t7a = static_cast<std::uint32_t>((t7a ^ 0x00000080u) - 0x00000080u);
        state.regs[6] = t7a;
    // 0x00921e73: 8d4101 LEA
        t8 = static_cast<std::uint32_t>(state.regs[1] + 0x00000001u);
        state.regs[0] = t8;
    // 0x00921e76: f7de NEG
        t9a = state.regs[6];
        t9r = static_cast<std::uint32_t>(0u - t9a) & 0xffffffffu;
        batch_set_neg_flags(state, t9a, t9r, 32u);
        state.regs[6] = t9r;
    // 0x00921e78: 1bf6 SBB
        t10a = state.regs[6];
        t10b = state.regs[6];
        t10c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t10r = static_cast<std::uint32_t>(t10a - t10b - t10c) & 0xffffffffu;
        batch_set_sbb_flags(state, t10a, t10b, t10c, t10r, 32u);
        state.regs[6] = t10r;
    // 0x00921e7a: 23f0 AND
        t11a = state.regs[6];
        t11b = state.regs[0];
        t11r = (t11a & t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
        state.regs[6] = t11r;
    // 0x00921e7c: 8a01 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t12 << 0u) & 0x000000ffu);
    // 0x00921e7e: 57 PUSH
        t13a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e7f: 88442454 MOV
        t14 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000054u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00921e83: 8b7c2454 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000054u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t15;
    // 0x00921e87: 56 PUSH
        t16a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e88: 57 PUSH
        t17a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e89: 6a00 PUSH
        t18a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e8b: 8d4c242c LEA
        t19 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[1] = t19;
    // 0x00921e8f: e83c070000 CALL
        if (!batch_guest_call32(memory, state, 0x009225d0u, 0x00921e94u)) return BatchLiftStatus::invalid_memory;
        t20_call_status = spore_lift_009225d0(memory, state);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x00921e94u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921e94: 56 PUSH
        t21a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e95: 57 PUSH
        t22a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e96: 6a01 PUSH
        t23a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e98: 8d4c2444 LEA
        t24 = static_cast<std::uint32_t>(state.regs[4] + 0x00000044u);
        state.regs[1] = t24;
    // 0x00921e9c: e82f070000 CALL
        if (!batch_guest_call32(memory, state, 0x009225d0u, 0x00921ea1u)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_009225d0(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00921ea1u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921ea1: 56 PUSH
        t26a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00921ea2: 57 PUSH
        t27a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00921ea3: 8d4c2414 LEA
        t28 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[1] = t28;
    // 0x00921ea7: e854ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00921e00u, 0x00921eacu)) return BatchLiftStatus::invalid_memory;
        t29_call_status = spore_lift_00921e00(memory, state);
        if (t29_call_status != BatchLiftStatus::returned) return t29_call_status;
        if (state.eip != 0x00921eacu) return BatchLiftStatus::invalid_control_flow;
    // 0x00921eac: 8d4c2420 LEA
        t30 = static_cast<std::uint32_t>(state.regs[4] + 0x00000020u);
        state.regs[1] = t30;
    // 0x00921eb0: 51 PUSH
        t31a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x00921eb1: 8d4b0c LEA
        t32 = static_cast<std::uint32_t>(state.regs[3] + 0x0000000cu);
        state.regs[1] = t32;
    // 0x00921eb4: e867070000 CALL
        if (!batch_guest_call32(memory, state, 0x00922620u, 0x00921eb9u)) return BatchLiftStatus::invalid_memory;
        t33_call_status = spore_lift_00922620(memory, state);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
        if (state.eip != 0x00921eb9u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921eb9: 5f POP
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t34a;
    // 0x00921eba: 5e POP
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t35a;
    // 0x00921ebb: 84c0 TEST
        t36a = state.regs[0] & 0x000000ffu;
        t36b = state.regs[0] & 0x000000ffu;
        t36r = (t36a & t36b) & 0x000000ffu;
        batch_set_logic_flags(state, t36r, 8u);
    // 0x00921ebd: 742b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921eea;
    // 0x00921ebf: 8d542430 LEA
        t38 = static_cast<std::uint32_t>(state.regs[4] + 0x00000030u);
        state.regs[2] = t38;
    // 0x00921ec3: 52 PUSH
        t39a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
    // 0x00921ec4: 8d4b1c LEA
        t40 = static_cast<std::uint32_t>(state.regs[3] + 0x0000001cu);
        state.regs[1] = t40;
    // 0x00921ec7: e854070000 CALL
        if (!batch_guest_call32(memory, state, 0x00922620u, 0x00921eccu)) return BatchLiftStatus::invalid_memory;
        t41_call_status = spore_lift_00922620(memory, state);
        if (t41_call_status != BatchLiftStatus::returned) return t41_call_status;
        if (state.eip != 0x00921eccu) return BatchLiftStatus::invalid_control_flow;
    // 0x00921ecc: 84c0 TEST
        t42a = state.regs[0] & 0x000000ffu;
        t42b = state.regs[0] & 0x000000ffu;
        t42r = (t42a & t42b) & 0x000000ffu;
        batch_set_logic_flags(state, t42r, 8u);
    // 0x00921ece: 741a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921eea;
    // 0x00921ed0: 8d442404 LEA
        t44 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[0] = t44;
    // 0x00921ed4: 50 PUSH
        t45a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
    // 0x00921ed5: 8d4b30 LEA
        t46 = static_cast<std::uint32_t>(state.regs[3] + 0x00000030u);
        state.regs[1] = t46;
    // 0x00921ed8: e873020000 CALL
        if (!batch_guest_call32(memory, state, 0x00922150u, 0x00921eddu)) return BatchLiftStatus::invalid_memory;
        t47_call_status = spore_lift_00922150(memory, state);
        if (t47_call_status != BatchLiftStatus::returned) return t47_call_status;
        if (state.eip != 0x00921eddu) return BatchLiftStatus::invalid_control_flow;
    // 0x00921edd: 84c0 TEST
        t48a = state.regs[0] & 0x000000ffu;
        t48b = state.regs[0] & 0x000000ffu;
        t48r = (t48a & t48b) & 0x000000ffu;
        batch_set_logic_flags(state, t48r, 8u);
    // 0x00921edf: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921eea;
    // 0x00921ee1: b001 MOV
        t50 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t50 << 0u) & 0x000000ffu);
    // 0x00921ee3: 5b POP
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t51a;
    // 0x00921ee4: 83c444 ADD
        t52a = state.regs[4];
        t52b = 0x00000044u;
        t52r = static_cast<std::uint32_t>(t52a + t52b) & 0xffffffffu;
        batch_set_add_flags(state, t52a, t52b, t52r, 32u);
        state.regs[4] = t52r;
    // 0x00921ee7: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00921eea: 32c0 XOR
    L_00921eea:
        t54a = state.regs[0] & 0x000000ffu;
        t54b = state.regs[0] & 0x000000ffu;
        t54r = (t54a ^ t54b) & 0x000000ffu;
        batch_set_logic_flags(state, t54r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t54r << 0u) & 0x000000ffu);
    // 0x00921eec: 5b POP
        if (!memory.load32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t55a;
    // 0x00921eed: 83c444 ADD
        t56a = state.regs[4];
        t56b = 0x00000044u;
        t56r = static_cast<std::uint32_t>(t56a + t56b) & 0xffffffffu;
        batch_set_add_flags(state, t56a, t56b, t56r, 32u);
        state.regs[4] = t56r;
    // 0x00921ef0: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
