#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00932e80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00932e80u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0, t18r = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20a = 0, t20b = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39a = 0, t39r = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41a = 0, t41b = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t57a = 0, t57b = 0;
    std::uint32_t t58a = 0, t58r = 0;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66a = 0;
    std::uint32_t t67a = 0;

    // 0x00932e80: 8b44240c MOV
        batch_guest_pc = 0x00932e80u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00932e84: 83e800 SUB
        t1a = state.regs[0];
        t1b = 0x00000000u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
        state.regs[0] = t1r;
    // 0x00932e87: 747d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00932f06;
    // 0x00932e89: 83e801 SUB
        t3a = state.regs[0];
        t3b = 0x00000001u;
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
        state.regs[0] = t3r;
    // 0x00932e8c: 53 PUSH
        batch_guest_pc = 0x00932e8cu;
        t4a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00932e8d: 56 PUSH
        batch_guest_pc = 0x00932e8du;
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00932e8e: 57 PUSH
        batch_guest_pc = 0x00932e8eu;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00932e8f: 7441 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00932ed2;
    // 0x00932e91: 83e801 SUB
        t8a = state.regs[0];
        t8b = 0x00000001u;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
        state.regs[0] = t8r;
    // 0x00932e94: 0f858c000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00932f26;
    // 0x00932e9a: 8b742410 MOV
        batch_guest_pc = 0x00932e9au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t10;
    // 0x00932e9e: 0fb606 MOVZX
        batch_guest_pc = 0x00932e9eu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t11a)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11a;
    // 0x00932ea1: 85c0 TEST
        t12a = state.regs[0];
        t12b = state.regs[0];
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
    // 0x00932ea3: 0f847d000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00932f26;
    // 0x00932ea9: 8b1d00c53c01 MOV
        batch_guest_pc = 0x00932ea9u;
        if (!memory.load32(0x013cc500u, t14)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t14;
    // 0x00932eaf: 8b7c2414 MOV
        batch_guest_pc = 0x00932eafu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t15;
    // 0x00932eb3: 0fb6c0 MOVZX
    L_00932eb3:
        t16a = state.regs[0] & 0x000000ffu;
        state.regs[0] = t16a;
    // 0x00932eb6: 50 PUSH
        batch_guest_pc = 0x00932eb6u;
        t17a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00932eb7: 46 INC
        t18a = state.regs[6];
        t18r = static_cast<std::uint32_t>(t18a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t18a, t18r, 32u);
        state.regs[6] = t18r;
    // 0x00932eb8: ffd3 CALL
        t19_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[3], 0x00932ebau);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
    // 0x00932eba: 69ff93010001 IMUL
        t20a = state.regs[7];
        t20b = 0x01000193u;
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t20a)) * static_cast<std::int32_t>(t20b);
        state.regs[7] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x00932ec0: 33f8 XOR
        t21a = state.regs[7];
        t21b = state.regs[0];
        t21r = (t21a ^ t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
        state.regs[7] = t21r;
    // 0x00932ec2: 0fb606 MOVZX
        batch_guest_pc = 0x00932ec2u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22a;
    // 0x00932ec5: 83c404 ADD
        t23a = state.regs[4];
        t23b = 0x00000004u;
        t23r = static_cast<std::uint32_t>(t23a + t23b) & 0xffffffffu;
        batch_set_add_flags(state, t23a, t23b, t23r, 32u);
        state.regs[4] = t23r;
    // 0x00932ec8: 85c0 TEST
        t24a = state.regs[0];
        t24b = state.regs[0];
        t24r = (t24a & t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
    // 0x00932eca: 75e7 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00932eb3;
    // 0x00932ecc: 8bc7 MOV
        t26 = state.regs[7];
        state.regs[0] = t26;
    // 0x00932ece: 5f POP
        batch_guest_pc = 0x00932eceu;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t27a;
    // 0x00932ecf: 5e POP
        batch_guest_pc = 0x00932ecfu;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t28a;
    // 0x00932ed0: 5b POP
        batch_guest_pc = 0x00932ed0u;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t29a;
    // 0x00932ed1: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00932ed2: 8b742410 MOV
    L_00932ed2:
        batch_guest_pc = 0x00932ed2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t31;
    // 0x00932ed6: 0fb606 MOVZX
        batch_guest_pc = 0x00932ed6u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32a;
    // 0x00932ed9: 85c0 TEST
        t33a = state.regs[0];
        t33b = state.regs[0];
        t33r = (t33a & t33b) & 0xffffffffu;
        batch_set_logic_flags(state, t33r, 32u);
    // 0x00932edb: 7449 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00932f26;
    // 0x00932edd: 8b1decc23c01 MOV
        batch_guest_pc = 0x00932eddu;
        if (!memory.load32(0x013cc2ecu, t35)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t35;
    // 0x00932ee3: 8b7c2414 MOV
        batch_guest_pc = 0x00932ee3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t36;
    // 0x00932ee7: 0fb6c8 MOVZX
    L_00932ee7:
        t37a = state.regs[0] & 0x000000ffu;
        state.regs[1] = t37a;
    // 0x00932eea: 51 PUSH
        batch_guest_pc = 0x00932eeau;
        t38a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x00932eeb: 46 INC
        t39a = state.regs[6];
        t39r = static_cast<std::uint32_t>(t39a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t39a, t39r, 32u);
        state.regs[6] = t39r;
    // 0x00932eec: ffd3 CALL
        t40_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[3], 0x00932eeeu);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
    // 0x00932eee: 69ff93010001 IMUL
        t41a = state.regs[7];
        t41b = 0x01000193u;
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t41a)) * static_cast<std::int32_t>(t41b);
        state.regs[7] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x00932ef4: 33f8 XOR
        t42a = state.regs[7];
        t42b = state.regs[0];
        t42r = (t42a ^ t42b) & 0xffffffffu;
        batch_set_logic_flags(state, t42r, 32u);
        state.regs[7] = t42r;
    // 0x00932ef6: 0fb606 MOVZX
        batch_guest_pc = 0x00932ef6u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t43a;
    // 0x00932ef9: 83c404 ADD
        t44a = state.regs[4];
        t44b = 0x00000004u;
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        state.regs[4] = t44r;
    // 0x00932efc: 85c0 TEST
        t45a = state.regs[0];
        t45b = state.regs[0];
        t45r = (t45a & t45b) & 0xffffffffu;
        batch_set_logic_flags(state, t45r, 32u);
    // 0x00932efe: 75e7 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00932ee7;
    // 0x00932f00: 8bc7 MOV
        t47 = state.regs[7];
        state.regs[0] = t47;
    // 0x00932f02: 5f POP
        batch_guest_pc = 0x00932f02u;
        if (!memory.load32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t48a;
    // 0x00932f03: 5e POP
        batch_guest_pc = 0x00932f03u;
        if (!memory.load32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t49a;
    // 0x00932f04: 5b POP
        batch_guest_pc = 0x00932f04u;
        if (!memory.load32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t50a;
    // 0x00932f05: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00932f06: 8b542404 MOV
    L_00932f06:
        batch_guest_pc = 0x00932f06u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t52;
    // 0x00932f0a: 0fb60a MOVZX
        batch_guest_pc = 0x00932f0au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t53a;
    // 0x00932f0d: 8b442408 MOV
        batch_guest_pc = 0x00932f0du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t54;
    // 0x00932f11: 85c9 TEST
        t55a = state.regs[1];
        t55b = state.regs[1];
        t55r = (t55a & t55b) & 0xffffffffu;
        batch_set_logic_flags(state, t55r, 32u);
    // 0x00932f13: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00932f2d;
    // 0x00932f15: 69c093010001 IMUL
    L_00932f15:
        t57a = state.regs[0];
        t57b = 0x01000193u;
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t57a)) * static_cast<std::int32_t>(t57b);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x00932f1b: 42 INC
        t58a = state.regs[2];
        t58r = static_cast<std::uint32_t>(t58a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t58a, t58r, 32u);
        state.regs[2] = t58r;
    // 0x00932f1c: 33c1 XOR
        t59a = state.regs[0];
        t59b = state.regs[1];
        t59r = (t59a ^ t59b) & 0xffffffffu;
        batch_set_logic_flags(state, t59r, 32u);
        state.regs[0] = t59r;
    // 0x00932f1e: 0fb60a MOVZX
        batch_guest_pc = 0x00932f1eu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t60a;
    // 0x00932f21: 85c9 TEST
        t61a = state.regs[1];
        t61b = state.regs[1];
        t61r = (t61a & t61b) & 0xffffffffu;
        batch_set_logic_flags(state, t61r, 32u);
    // 0x00932f23: 75f0 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00932f15;
    // 0x00932f25: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00932f26: 8b442414 MOV
    L_00932f26:
        batch_guest_pc = 0x00932f26u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t64;
    // 0x00932f2a: 5f POP
        batch_guest_pc = 0x00932f2au;
        if (!memory.load32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t65a;
    // 0x00932f2b: 5e POP
        batch_guest_pc = 0x00932f2bu;
        if (!memory.load32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t66a;
    // 0x00932f2c: 5b POP
        batch_guest_pc = 0x00932f2cu;
        if (!memory.load32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t67a;
    // 0x00932f2d: c3 RET
    L_00932f2d:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
