#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_006782c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00e25bd0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00e25bd0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    BatchLiftStatus t22_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0, t28c = 0, t28r = 0;
    std::uint32_t t29a = 0, t29r = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;

    // 0x00e25bd0: 53 PUSH
        batch_guest_pc = 0x00e25bd0u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00e25bd1: 8b5c240c MOV
        batch_guest_pc = 0x00e25bd1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t1;
    // 0x00e25bd5: 55 PUSH
        batch_guest_pc = 0x00e25bd5u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00e25bd6: 56 PUSH
        batch_guest_pc = 0x00e25bd6u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00e25bd7: 57 PUSH
        batch_guest_pc = 0x00e25bd7u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00e25bd8: 8bf9 MOV
        t5 = state.regs[1];
        state.regs[7] = t5;
    // 0x00e25bda: 8b4c2414 MOV
        batch_guest_pc = 0x00e25bdau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00e25bde: 8b4704 MOV
        batch_guest_pc = 0x00e25bdeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x00e25be1: 51 PUSH
        batch_guest_pc = 0x00e25be1u;
        t8a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00e25be2: 50 PUSH
        batch_guest_pc = 0x00e25be2u;
        t9a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00e25be3: 53 PUSH
        batch_guest_pc = 0x00e25be3u;
        t10a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00e25be4: e8d72685ff CALL
        if (!batch_guest_call32(memory, state, 0x006782c0u, 0x00e25be9u)) return BatchLiftStatus::invalid_memory;
        t11_call_status = spore_lift_006782c0(memory, state);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x00e25be9u) return BatchLiftStatus::invalid_control_flow;
    // 0x00e25be9: 8b6f04 MOV
        batch_guest_pc = 0x00e25be9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t12;
    // 0x00e25bec: 83c40c ADD
        t13a = state.regs[4];
        t13b = 0x0000000cu;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[4] = t13r;
    // 0x00e25bef: 8bf0 MOV
        t14 = state.regs[0];
        state.regs[6] = t14;
    // 0x00e25bf1: 3bc5 CMP
        t15a = state.regs[0];
        t15b = state.regs[5];
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x00e25bf3: 7314 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00e25c09;
    // 0x00e25bf5: 8b0e MOV
    L_00e25bf5:
        batch_guest_pc = 0x00e25bf5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x00e25bf7: 85c9 TEST
        t18a = state.regs[1];
        t18b = state.regs[1];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
    // 0x00e25bf9: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00e25c02;
    // 0x00e25bfb: 8b11 MOV
        batch_guest_pc = 0x00e25bfbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t20;
    // 0x00e25bfd: 8b4204 MOV
        batch_guest_pc = 0x00e25bfdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00e25c00: ffd0 CALL
        t22_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00e25c02u);
        if (t22_call_status != BatchLiftStatus::returned) return t22_call_status;
    // 0x00e25c02: 83c604 ADD
    L_00e25c02:
        t23a = state.regs[6];
        t23b = 0x00000004u;
        t23r = static_cast<std::uint32_t>(t23a + t23b) & 0xffffffffu;
        batch_set_add_flags(state, t23a, t23b, t23r, 32u);
        state.regs[6] = t23r;
    // 0x00e25c05: 3bf5 CMP
        t24a = state.regs[6];
        t24b = state.regs[5];
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x00e25c07: 72ec JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00e25bf5;
    // 0x00e25c09: 8b442414 MOV
    L_00e25c09:
        batch_guest_pc = 0x00e25c09u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t26;
    // 0x00e25c0d: 2bd8 SUB
        t27a = state.regs[3];
        t27b = state.regs[0];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
        state.regs[3] = t27r;
    // 0x00e25c0f: c1fb02 SAR
        t28a = state.regs[3];
        t28c = 2u;
        if (t28c != 0u) {
        t28r = (t28a >> t28c) | ((t28a & 0x80000000u) ? (0xffffffffu << (32u - t28c)) : 0u);
        batch_set_sar_flags(state, t28a, t28c, t28r, 32u);
            state.regs[3] = t28r;
        }
    // 0x00e25c12: f7db NEG
        t29a = state.regs[3];
        t29r = static_cast<std::uint32_t>(0u - t29a) & 0xffffffffu;
        batch_set_neg_flags(state, t29a, t29r, 32u);
        state.regs[3] = t29r;
    // 0x00e25c14: 03db ADD
        t30a = state.regs[3];
        t30b = state.regs[3];
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[3] = t30r;
    // 0x00e25c16: 03db ADD
        t31a = state.regs[3];
        t31b = state.regs[3];
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[3] = t31r;
    // 0x00e25c18: 015f04 ADD
        batch_guest_pc = 0x00e25c18u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t32a)) return BatchLiftStatus::invalid_memory;
        t32b = state.regs[3];
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t32r)) return BatchLiftStatus::invalid_memory;
    // 0x00e25c1b: 5f POP
        batch_guest_pc = 0x00e25c1bu;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t33a;
    // 0x00e25c1c: 5e POP
        batch_guest_pc = 0x00e25c1cu;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t34a;
    // 0x00e25c1d: 5d POP
        batch_guest_pc = 0x00e25c1du;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t35a;
    // 0x00e25c1e: 5b POP
        batch_guest_pc = 0x00e25c1eu;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t36a;
    // 0x00e25c1f: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
