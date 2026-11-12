#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00923ac0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923c90(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923c90u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;

    // 0x00923c90: 51 PUSH
        batch_guest_pc = 0x00923c90u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923c91: 56 PUSH
        batch_guest_pc = 0x00923c91u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923c92: 57 PUSH
        batch_guest_pc = 0x00923c92u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00923c93: 8b7c2410 MOV
        batch_guest_pc = 0x00923c93u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t3;
    // 0x00923c97: 8b4710 MOV
        batch_guest_pc = 0x00923c97u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00923c9a: 8bf1 MOV
        t5 = state.regs[1];
        state.regs[6] = t5;
    // 0x00923c9c: 89442410 MOV
        batch_guest_pc = 0x00923c9cu;
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00923ca0: 85c0 TEST
        t7a = state.regs[0];
        t7b = state.regs[0];
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
    // 0x00923ca2: 7433 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923cd7;
    // 0x00923ca4: 803800 CMP
        batch_guest_pc = 0x00923ca4u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t9a)) return BatchLiftStatus::invalid_memory;
        t9b = 0x00000000u;
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0x000000ffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 8u);
    // 0x00923ca7: 742e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923cd7;
    // 0x00923ca9: 8d442410 LEA
        t11 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t11;
    // 0x00923cad: 50 PUSH
        batch_guest_pc = 0x00923cadu;
        t12a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00923cae: 8d4c240c LEA
        t13 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t13;
    // 0x00923cb2: 51 PUSH
        batch_guest_pc = 0x00923cb2u;
        t14a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00923cb3: 8d4e1c LEA
        t15 = static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu);
        state.regs[1] = t15;
    // 0x00923cb6: e805feffff CALL
        if (!batch_guest_call32(memory, state, 0x00923ac0u, 0x00923cbbu)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00923ac0(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00923cbbu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923cbb: 8b00 MOV
        batch_guest_pc = 0x00923cbbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x00923cbd: 8d5620 LEA
        t18 = static_cast<std::uint32_t>(state.regs[6] + 0x00000020u);
        state.regs[2] = t18;
    // 0x00923cc0: 3bc2 CMP
        t19a = state.regs[0];
        t19b = state.regs[2];
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x00923cc2: 7413 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923cd7;
    // 0x00923cc4: 8b4014 MOV
        batch_guest_pc = 0x00923cc4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00923cc7: 33c9 XOR
        t22a = state.regs[1];
        t22b = state.regs[1];
        t22r = (t22a ^ t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
        state.regs[1] = t22r;
    // 0x00923cc9: 39470c CMP
        batch_guest_pc = 0x00923cc9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t23a)) return BatchLiftStatus::invalid_memory;
        t23b = state.regs[0];
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x00923ccc: 5f POP
        batch_guest_pc = 0x00923cccu;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t24a;
    // 0x00923ccd: 0f9cc1 SETL
        state.regs[1] = (state.regs[1] & 0xffffff00u) | (((((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00923cd0: 8ac1 MOV
        t26 = state.regs[1] & 0x000000ffu;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t26 << 0u) & 0x000000ffu);
    // 0x00923cd2: 5e POP
        batch_guest_pc = 0x00923cd2u;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t27a;
    // 0x00923cd3: 59 POP
        batch_guest_pc = 0x00923cd3u;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t28a;
    // 0x00923cd4: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00923cd7: 8b4618 MOV
    L_00923cd7:
        batch_guest_pc = 0x00923cd7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t30;
    // 0x00923cda: 33c9 XOR
        t31a = state.regs[1];
        t31b = state.regs[1];
        t31r = (t31a ^ t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
        state.regs[1] = t31r;
    // 0x00923cdc: 39470c CMP
        batch_guest_pc = 0x00923cdcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t32a)) return BatchLiftStatus::invalid_memory;
        t32b = state.regs[0];
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
    // 0x00923cdf: 5f POP
        batch_guest_pc = 0x00923cdfu;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t33a;
    // 0x00923ce0: 0f9cc1 SETL
        state.regs[1] = (state.regs[1] & 0xffffff00u) | (((((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00923ce3: 8ac1 MOV
        t35 = state.regs[1] & 0x000000ffu;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t35 << 0u) & 0x000000ffu);
    // 0x00923ce5: 5e POP
        batch_guest_pc = 0x00923ce5u;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t36a;
    // 0x00923ce6: 59 POP
        batch_guest_pc = 0x00923ce6u;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t37a;
    // 0x00923ce7: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
