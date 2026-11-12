#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e0d38(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e0cc0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e0cc0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23c = 0, t23r = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0, t25c = 0, t25r = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42a = 0, t42r = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t44a = 0, t44b = 0, t44c = 0, t44r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47a = 0, t47b = 0, t47c = 0, t47r = 0;
    std::uint32_t t48a = 0, t48r = 0;
    std::uint32_t t49a = 0, t49r = 0;
    std::uint32_t t50a = 0, t50b = 0, t50c = 0, t50r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0;

    // 0x011e0cc0: 56 PUSH
        batch_guest_pc = 0x011e0cc0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0cc1: 8b442414 MOV
        batch_guest_pc = 0x011e0cc1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x011e0cc5: 0bc0 OR
        t2a = state.regs[0];
        t2b = state.regs[0];
        t2r = (t2a | t2b) & 0xffffffffu;
        batch_set_logic_flags(state, t2r, 32u);
        state.regs[0] = t2r;
    // 0x011e0cc7: 7528 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e0cf1;
    // 0x011e0cc9: 8b4c2410 MOV
        batch_guest_pc = 0x011e0cc9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x011e0ccd: 8b44240c MOV
        batch_guest_pc = 0x011e0ccdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x011e0cd1: 33d2 XOR
        t6a = state.regs[2];
        t6b = state.regs[2];
        t6r = (t6a ^ t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[2] = t6r;
    // 0x011e0cd3: f7f1 DIV
        t7a = state.regs[1];
        if (t7a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::uint64_t dividend = (static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0];
        const std::uint64_t quotient = dividend / t7a;
        if (quotient > 0xffffffffull) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(dividend % t7a);
        }
    // 0x011e0cd5: 8bd8 MOV
        t8 = state.regs[0];
        state.regs[3] = t8;
    // 0x011e0cd7: 8b442408 MOV
        batch_guest_pc = 0x011e0cd7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x011e0cdb: f7f1 DIV
        t10a = state.regs[1];
        if (t10a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::uint64_t dividend = (static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0];
        const std::uint64_t quotient = dividend / t10a;
        if (quotient > 0xffffffffull) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(dividend % t10a);
        }
    // 0x011e0cdd: 8bf0 MOV
        t11 = state.regs[0];
        state.regs[6] = t11;
    // 0x011e0cdf: 8bc3 MOV
        t12 = state.regs[3];
        state.regs[0] = t12;
    // 0x011e0ce1: f7642410 MUL
        batch_guest_pc = 0x011e0ce1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t13a)) return BatchLiftStatus::invalid_memory;
        {
        const std::uint64_t product = static_cast<std::uint64_t>(state.regs[0]) * static_cast<std::uint64_t>(t13a);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.regs[2] = static_cast<std::uint32_t>(product >> 32u);
        state.eflags &= ~0x801u;
        if (state.regs[2] != 0u) state.eflags |= 0x801u;
        }
    // 0x011e0ce5: 8bc8 MOV
        t14 = state.regs[0];
        state.regs[1] = t14;
    // 0x011e0ce7: 8bc6 MOV
        t15 = state.regs[6];
        state.regs[0] = t15;
    // 0x011e0ce9: f7642410 MUL
        batch_guest_pc = 0x011e0ce9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t16a)) return BatchLiftStatus::invalid_memory;
        {
        const std::uint64_t product = static_cast<std::uint64_t>(state.regs[0]) * static_cast<std::uint64_t>(t16a);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.regs[2] = static_cast<std::uint32_t>(product >> 32u);
        state.eflags &= ~0x801u;
        if (state.regs[2] != 0u) state.eflags |= 0x801u;
        }
    // 0x011e0ced: 03d1 ADD
        t17a = state.regs[2];
        t17b = state.regs[1];
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        state.regs[2] = t17r;
    // 0x011e0cef: eb47 JMP
        goto L_011e0d38;
    // 0x011e0cf1: 8bc8 MOV
    L_011e0cf1:
        t19 = state.regs[0];
        state.regs[1] = t19;
    // 0x011e0cf3: 8b5c2410 MOV
        batch_guest_pc = 0x011e0cf3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t20;
    // 0x011e0cf7: 8b54240c MOV
        batch_guest_pc = 0x011e0cf7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x011e0cfb: 8b442408 MOV
        batch_guest_pc = 0x011e0cfbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x011e0cff: d1e9 SHR
    L_011e0cff:
        t23a = state.regs[1];
        t23c = 1u;
        if (t23c != 0u) {
        t23r = static_cast<std::uint32_t>(t23a >> t23c);
        batch_set_shr_flags(state, t23a, t23c, t23r, 32u);
            state.regs[1] = t23r;
        }
    // 0x011e0d01: d1db RCR
        t24a = state.regs[3];
        {
            const std::uint32_t result = batch_guest_rcr(state, t24a, 0x00000001u);
            state.regs[3] = result;
        }
    // 0x011e0d03: d1ea SHR
        t25a = state.regs[2];
        t25c = 1u;
        if (t25c != 0u) {
        t25r = static_cast<std::uint32_t>(t25a >> t25c);
        batch_set_shr_flags(state, t25a, t25c, t25r, 32u);
            state.regs[2] = t25r;
        }
    // 0x011e0d05: d1d8 RCR
        t26a = state.regs[0];
        {
            const std::uint32_t result = batch_guest_rcr(state, t26a, 0x00000001u);
            state.regs[0] = result;
        }
    // 0x011e0d07: 0bc9 OR
        t27a = state.regs[1];
        t27b = state.regs[1];
        t27r = (t27a | t27b) & 0xffffffffu;
        batch_set_logic_flags(state, t27r, 32u);
        state.regs[1] = t27r;
    // 0x011e0d09: 75f4 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e0cff;
    // 0x011e0d0b: f7f3 DIV
        t29a = state.regs[3];
        if (t29a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::uint64_t dividend = (static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0];
        const std::uint64_t quotient = dividend / t29a;
        if (quotient > 0xffffffffull) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(dividend % t29a);
        }
    // 0x011e0d0d: 8bf0 MOV
        t30 = state.regs[0];
        state.regs[6] = t30;
    // 0x011e0d0f: f7642414 MUL
        batch_guest_pc = 0x011e0d0fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t31a)) return BatchLiftStatus::invalid_memory;
        {
        const std::uint64_t product = static_cast<std::uint64_t>(state.regs[0]) * static_cast<std::uint64_t>(t31a);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.regs[2] = static_cast<std::uint32_t>(product >> 32u);
        state.eflags &= ~0x801u;
        if (state.regs[2] != 0u) state.eflags |= 0x801u;
        }
    // 0x011e0d13: 8bc8 MOV
        t32 = state.regs[0];
        state.regs[1] = t32;
    // 0x011e0d15: 8b442410 MOV
        batch_guest_pc = 0x011e0d15u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x011e0d19: f7e6 MUL
        t34a = state.regs[6];
        {
        const std::uint64_t product = static_cast<std::uint64_t>(state.regs[0]) * static_cast<std::uint64_t>(t34a);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.regs[2] = static_cast<std::uint32_t>(product >> 32u);
        state.eflags &= ~0x801u;
        if (state.regs[2] != 0u) state.eflags |= 0x801u;
        }
    // 0x011e0d1b: 03d1 ADD
        t35a = state.regs[2];
        t35b = state.regs[1];
        t35r = static_cast<std::uint32_t>(t35a + t35b) & 0xffffffffu;
        batch_set_add_flags(state, t35a, t35b, t35r, 32u);
        state.regs[2] = t35r;
    // 0x011e0d1d: 720e JC
        if (((state.eflags & 0x001u) != 0u)) goto L_011e0d2d;
    // 0x011e0d1f: 3b54240c CMP
        batch_guest_pc = 0x011e0d1fu;
        t37a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t37b)) return BatchLiftStatus::invalid_memory;
        t37r = static_cast<std::uint32_t>(t37a - t37b) & 0xffffffffu;
        batch_set_sub_flags(state, t37a, t37b, t37r, 32u);
    // 0x011e0d23: 7708 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_011e0d2d;
    // 0x011e0d25: 720f JC
        if (((state.eflags & 0x001u) != 0u)) goto L_011e0d36;
    // 0x011e0d27: 3b442408 CMP
        batch_guest_pc = 0x011e0d27u;
        t40a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t40b)) return BatchLiftStatus::invalid_memory;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0xffffffffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 32u);
    // 0x011e0d2b: 7609 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_011e0d36;
    // 0x011e0d2d: 4e DEC
    L_011e0d2d:
        t42a = state.regs[6];
        t42r = static_cast<std::uint32_t>(t42a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t42a, t42r, 32u);
        state.regs[6] = t42r;
    // 0x011e0d2e: 2b442410 SUB
        batch_guest_pc = 0x011e0d2eu;
        t43a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t43b)) return BatchLiftStatus::invalid_memory;
        t43r = static_cast<std::uint32_t>(t43a - t43b) & 0xffffffffu;
        batch_set_sub_flags(state, t43a, t43b, t43r, 32u);
        state.regs[0] = t43r;
    // 0x011e0d32: 1b542414 SBB
        batch_guest_pc = 0x011e0d32u;
        t44a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t44b)) return BatchLiftStatus::invalid_memory;
        t44c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t44r = static_cast<std::uint32_t>(t44a - t44b - t44c) & 0xffffffffu;
        batch_set_sbb_flags(state, t44a, t44b, t44c, t44r, 32u);
        state.regs[2] = t44r;
    // 0x011e0d36: 33db XOR
    L_011e0d36:
        t45a = state.regs[3];
        t45b = state.regs[3];
        t45r = (t45a ^ t45b) & 0xffffffffu;
        batch_set_logic_flags(state, t45r, 32u);
        state.regs[3] = t45r;
    // 0x011e0d38: 2b442408 SUB
    L_011e0d38:
        batch_guest_pc = 0x011e0d38u;
        t46a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t46b)) return BatchLiftStatus::invalid_memory;
        t46r = static_cast<std::uint32_t>(t46a - t46b) & 0xffffffffu;
        batch_set_sub_flags(state, t46a, t46b, t46r, 32u);
        state.regs[0] = t46r;
    // 0x011e0d3c: 1b54240c SBB
        batch_guest_pc = 0x011e0d3cu;
        t47a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t47b)) return BatchLiftStatus::invalid_memory;
        t47c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t47r = static_cast<std::uint32_t>(t47a - t47b - t47c) & 0xffffffffu;
        batch_set_sbb_flags(state, t47a, t47b, t47c, t47r, 32u);
        state.regs[2] = t47r;
    // 0x011e0d40: f7da NEG
        t48a = state.regs[2];
        t48r = static_cast<std::uint32_t>(0u - t48a) & 0xffffffffu;
        batch_set_neg_flags(state, t48a, t48r, 32u);
        state.regs[2] = t48r;
    // 0x011e0d42: f7d8 NEG
        t49a = state.regs[0];
        t49r = static_cast<std::uint32_t>(0u - t49a) & 0xffffffffu;
        batch_set_neg_flags(state, t49a, t49r, 32u);
        state.regs[0] = t49r;
    // 0x011e0d44: 83da00 SBB
        t50a = state.regs[2];
        t50b = 0x00000000u;
        t50c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t50r = static_cast<std::uint32_t>(t50a - t50b - t50c) & 0xffffffffu;
        batch_set_sbb_flags(state, t50a, t50b, t50c, t50r, 32u);
        state.regs[2] = t50r;
    // 0x011e0d47: 8bca MOV
        t51 = state.regs[2];
        state.regs[1] = t51;
    // 0x011e0d49: 8bd3 MOV
        t52 = state.regs[3];
        state.regs[2] = t52;
    // 0x011e0d4b: 8bd9 MOV
        t53 = state.regs[1];
        state.regs[3] = t53;
    // 0x011e0d4d: 8bc8 MOV
        t54 = state.regs[0];
        state.regs[1] = t54;
    // 0x011e0d4f: 8bc6 MOV
        t55 = state.regs[6];
        state.regs[0] = t55;
    // 0x011e0d51: 5e POP
        batch_guest_pc = 0x011e0d51u;
        if (!memory.load32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t56a;
    // 0x011e0d52: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
