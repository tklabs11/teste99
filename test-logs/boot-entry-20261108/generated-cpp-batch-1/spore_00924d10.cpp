#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009199c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923dc0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924c60(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924d10(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924d10u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20 = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29 = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41a = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47a = 0;

    // 0x00924d10: 53 PUSH
        batch_guest_pc = 0x00924d10u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d11: 8b5c2408 MOV
        batch_guest_pc = 0x00924d11u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t1;
    // 0x00924d15: 8b03 MOV
        batch_guest_pc = 0x00924d15u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00924d17: 8b500c MOV
        batch_guest_pc = 0x00924d17u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t3;
    // 0x00924d1a: 56 PUSH
        batch_guest_pc = 0x00924d1au;
        t4a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d1b: 8bf1 MOV
        t5 = state.regs[1];
        state.regs[6] = t5;
    // 0x00924d1d: 57 PUSH
        batch_guest_pc = 0x00924d1du;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d1e: 8bcb MOV
        t7 = state.regs[3];
        state.regs[1] = t7;
    // 0x00924d20: ffd2 CALL
        t8_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924d22u);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
    // 0x00924d22: 8bc8 MOV
        t9 = state.regs[0];
        state.regs[1] = t9;
    // 0x00924d24: 8d7901 LEA
        t10 = static_cast<std::uint32_t>(state.regs[1] + 0x00000001u);
        state.regs[7] = t10;
    // 0x00924d27: 8a11 MOV
    L_00924d27:
        batch_guest_pc = 0x00924d27u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t11 << 0u) & 0x000000ffu);
    // 0x00924d29: 41 INC
        t12a = state.regs[1];
        t12r = static_cast<std::uint32_t>(t12a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t12a, t12r, 32u);
        state.regs[1] = t12r;
    // 0x00924d2a: 84d2 TEST
        t13a = state.regs[2] & 0x000000ffu;
        t13b = state.regs[2] & 0x000000ffu;
        t13r = (t13a & t13b) & 0x000000ffu;
        batch_set_logic_flags(state, t13r, 8u);
    // 0x00924d2c: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924d27;
    // 0x00924d2e: 2bcf SUB
        t15a = state.regs[1];
        t15b = state.regs[7];
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
        state.regs[1] = t15r;
    // 0x00924d30: 03c8 ADD
        t16a = state.regs[1];
        t16b = state.regs[0];
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[1] = t16r;
    // 0x00924d32: 51 PUSH
        batch_guest_pc = 0x00924d32u;
        t17a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d33: 81c61c080000 ADD
        t18a = state.regs[6];
        t18b = 0x0000081cu;
        t18r = static_cast<std::uint32_t>(t18a + t18b) & 0xffffffffu;
        batch_set_add_flags(state, t18a, t18b, t18r, 32u);
        state.regs[6] = t18r;
    // 0x00924d39: 50 PUSH
        batch_guest_pc = 0x00924d39u;
        t19a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d3a: 8bce MOV
        t20 = state.regs[6];
        state.regs[1] = t20;
    // 0x00924d3c: e87f4cffff CALL
        if (!batch_guest_call32(memory, state, 0x009199c0u, 0x00924d41u)) return BatchLiftStatus::invalid_memory;
        t21_call_status = spore_lift_009199c0(memory, state);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x00924d41u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924d41: 8b4604 MOV
        batch_guest_pc = 0x00924d41u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x00924d44: 2b06 SUB
        batch_guest_pc = 0x00924d44u;
        t23a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t23b)) return BatchLiftStatus::invalid_memory;
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
        state.regs[0] = t23r;
    // 0x00924d46: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924d51;
    // 0x00924d48: 8b0e MOV
        batch_guest_pc = 0x00924d48u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t25;
    // 0x00924d4a: 807c01ff0a CMP
        batch_guest_pc = 0x00924d4au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0xffffffffu), t26a)) return BatchLiftStatus::invalid_memory;
        t26b = 0x0000000au;
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0x000000ffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 8u);
    // 0x00924d4f: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924d5a;
    // 0x00924d51: 6a0a PUSH
    L_00924d51:
        batch_guest_pc = 0x00924d51u;
        t28a = 0x0000000au;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d53: 8bce MOV
        t29 = state.regs[6];
        state.regs[1] = t29;
    // 0x00924d55: e806ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00924c60u, 0x00924d5au)) return BatchLiftStatus::invalid_memory;
        t30_call_status = spore_lift_00924c60(memory, state);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x00924d5au) return BatchLiftStatus::invalid_control_flow;
    // 0x00924d5a: 8b430c MOV
    L_00924d5a:
        batch_guest_pc = 0x00924d5au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000000cu), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t31;
    // 0x00924d5d: 83780c64 CMP
        batch_guest_pc = 0x00924d5du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t32a)) return BatchLiftStatus::invalid_memory;
        t32b = 0x00000064u;
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
    // 0x00924d61: 7c1a JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00924d7d;
    // 0x00924d63: 8b501c MOV
        batch_guest_pc = 0x00924d63u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x00924d66: 8b4818 MOV
        batch_guest_pc = 0x00924d66u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35;
    // 0x00924d69: 52 PUSH
        batch_guest_pc = 0x00924d69u;
        t36a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d6a: 8b5014 MOV
        batch_guest_pc = 0x00924d6au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t37;
    // 0x00924d6d: 51 PUSH
        batch_guest_pc = 0x00924d6du;
        t38a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d6e: 52 PUSH
        batch_guest_pc = 0x00924d6eu;
        t39a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d6f: 68acdf4301 PUSH
        batch_guest_pc = 0x00924d6fu;
        t40a = 0x0143dfacu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d74: 56 PUSH
        batch_guest_pc = 0x00924d74u;
        t41a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d75: e846f0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00923dc0u, 0x00924d7au)) return BatchLiftStatus::invalid_memory;
        t42_call_status = spore_lift_00923dc0(memory, state);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00924d7au) return BatchLiftStatus::invalid_control_flow;
    // 0x00924d7a: 83c414 ADD
        t43a = state.regs[4];
        t43b = 0x00000014u;
        t43r = static_cast<std::uint32_t>(t43a + t43b) & 0xffffffffu;
        batch_set_add_flags(state, t43a, t43b, t43r, 32u);
        state.regs[4] = t43r;
    // 0x00924d7d: 8b06 MOV
    L_00924d7d:
        batch_guest_pc = 0x00924d7du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t44;
    // 0x00924d7f: 5f POP
        batch_guest_pc = 0x00924d7fu;
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t45a;
    // 0x00924d80: 5e POP
        batch_guest_pc = 0x00924d80u;
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t46a;
    // 0x00924d81: 5b POP
        batch_guest_pc = 0x00924d81u;
        if (!memory.load32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t47a;
    // 0x00924d82: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
