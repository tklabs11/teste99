#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e1252(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e1301(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e12a2(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e12a2u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    BatchLiftStatus t23_cpuid_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    BatchLiftStatus t29_cpuid_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t39a = 0, t39r = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43 = 0;

    // 0x011e12a2: 8bff MOV
        t0 = state.regs[7];
        state.regs[7] = t0;
    // 0x011e12a4: 55 PUSH
        batch_guest_pc = 0x011e12a4u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e12a5: 8bec MOV
        t2 = state.regs[4];
        state.regs[5] = t2;
    // 0x011e12a7: 83ec18 SUB
        t3a = state.regs[4];
        t3b = 0x00000018u;
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
        state.regs[4] = t3r;
    // 0x011e12aa: 33c0 XOR
        t4a = state.regs[0];
        t4b = state.regs[0];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[0] = t4r;
    // 0x011e12ac: 53 PUSH
        batch_guest_pc = 0x011e12acu;
        t5a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x011e12ad: 8945fc MOV
        batch_guest_pc = 0x011e12adu;
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t6)) return BatchLiftStatus::invalid_memory;
    // 0x011e12b0: 8945f4 MOV
        batch_guest_pc = 0x011e12b0u;
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x011e12b3: 8945f8 MOV
        batch_guest_pc = 0x011e12b3u;
        t8 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x011e12b6: 53 PUSH
        batch_guest_pc = 0x011e12b6u;
        t9a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x011e12b7: 9c PUSHFD
        if (!batch_guest_pushfd(memory, state)) return BatchLiftStatus::invalid_memory;
    // 0x011e12b8: 58 POP
        batch_guest_pc = 0x011e12b8u;
        if (!memory.load32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[0] = t11a;
    // 0x011e12b9: 8bc8 MOV
        t12 = state.regs[0];
        state.regs[1] = t12;
    // 0x011e12bb: 3500002000 XOR
        t13a = state.regs[0];
        t13b = 0x00200000u;
        t13r = (t13a ^ t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
        state.regs[0] = t13r;
    // 0x011e12c0: 50 PUSH
        batch_guest_pc = 0x011e12c0u;
        t14a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x011e12c1: 9d POPFD
        if (!batch_guest_popfd(memory, state)) return BatchLiftStatus::invalid_memory;
    // 0x011e12c2: 9c PUSHFD
        if (!batch_guest_pushfd(memory, state)) return BatchLiftStatus::invalid_memory;
    // 0x011e12c3: 5a POP
        batch_guest_pc = 0x011e12c3u;
        if (!memory.load32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[2] = t17a;
    // 0x011e12c4: 2bd1 SUB
        t18a = state.regs[2];
        t18b = state.regs[1];
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
        state.regs[2] = t18r;
    // 0x011e12c6: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e12e7;
    // 0x011e12c8: 51 PUSH
        batch_guest_pc = 0x011e12c8u;
        t20a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x011e12c9: 9d POPFD
        if (!batch_guest_popfd(memory, state)) return BatchLiftStatus::invalid_memory;
    // 0x011e12ca: 33c0 XOR
        t22a = state.regs[0];
        t22b = state.regs[0];
        t22r = (t22a ^ t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
        state.regs[0] = t22r;
    // 0x011e12cc: 0fa2 CPUID
        t23_cpuid_status = batch_guest_cpuid(state);
        if (t23_cpuid_status != BatchLiftStatus::returned) return t23_cpuid_status;
    // 0x011e12ce: 8945f4 MOV
        batch_guest_pc = 0x011e12ceu;
        t24 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x011e12d1: 895de8 MOV
        batch_guest_pc = 0x011e12d1u;
        t25 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x011e12d4: 8955ec MOV
        batch_guest_pc = 0x011e12d4u;
        t26 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t26)) return BatchLiftStatus::invalid_memory;
    // 0x011e12d7: 894df0 MOV
        batch_guest_pc = 0x011e12d7u;
        t27 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x011e12da: b801000000 MOV
        t28 = 0x00000001u;
        state.regs[0] = t28;
    // 0x011e12df: 0fa2 CPUID
        t29_cpuid_status = batch_guest_cpuid(state);
        if (t29_cpuid_status != BatchLiftStatus::returned) return t29_cpuid_status;
    // 0x011e12e1: 8955fc MOV
        batch_guest_pc = 0x011e12e1u;
        t30 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t30)) return BatchLiftStatus::invalid_memory;
    // 0x011e12e4: 8945f8 MOV
        batch_guest_pc = 0x011e12e4u;
        t31 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x011e12e7: 5b POP
    L_011e12e7:
        batch_guest_pc = 0x011e12e7u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t32a;
    // 0x011e12e8: f745fc00000004 TEST
        batch_guest_pc = 0x011e12e8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t33a)) return BatchLiftStatus::invalid_memory;
        t33b = 0x04000000u;
        t33r = (t33a & t33b) & 0xffffffffu;
        batch_set_logic_flags(state, t33r, 32u);
    // 0x011e12ef: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e12ff;
    // 0x011e12f1: e85cffffff CALL
        if (!batch_guest_call32(memory, state, 0x011e1252u, 0x011e12f6u)) return BatchLiftStatus::invalid_memory;
        t35_call_status = spore_lift_011e1252(memory, state);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x011e12f6u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e12f6: 85c0 TEST
        t36a = state.regs[0];
        t36b = state.regs[0];
        t36r = (t36a & t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
    // 0x011e12f8: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e12ff;
    // 0x011e12fa: 33c0 XOR
        t38a = state.regs[0];
        t38b = state.regs[0];
        t38r = (t38a ^ t38b) & 0xffffffffu;
        batch_set_logic_flags(state, t38r, 32u);
        state.regs[0] = t38r;
    // 0x011e12fc: 40 INC
        t39a = state.regs[0];
        t39r = static_cast<std::uint32_t>(t39a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t39a, t39r, 32u);
        state.regs[0] = t39r;
    // 0x011e12fd: eb02 JMP
        goto L_011e1301;
    // 0x011e12ff: 33c0 XOR
    L_011e12ff:
        t41a = state.regs[0];
        t41b = state.regs[0];
        t41r = (t41a ^ t41b) & 0xffffffffu;
        batch_set_logic_flags(state, t41r, 32u);
        state.regs[0] = t41r;
    // 0x011e1301: 5b POP
    L_011e1301:
        batch_guest_pc = 0x011e1301u;
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t42a;
    // 0x011e1302: c9 LEAVE
        batch_guest_pc = 0x011e1302u;
        state.regs[4] = state.regs[5];
        if (!memory.load32(state.regs[4], t43)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t43;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
    // 0x011e1303: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
