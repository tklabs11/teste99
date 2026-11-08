#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e1548(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    BatchLiftStatus t28_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    BatchLiftStatus t32_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43r = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51 = 0;

    // 0x011e1548: 8bff MOV
        t0 = state.regs[7];
        state.regs[7] = t0;
    // 0x011e154a: 55 PUSH
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e154b: 8bec MOV
        t2 = state.regs[4];
        state.regs[5] = t2;
    // 0x011e154d: 83ec10 SUB
        t3a = state.regs[4];
        t3b = 0x00000010u;
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
        state.regs[4] = t3r;
    // 0x011e1550: a170fe5c01 MOV
        if (!memory.load32(0x015cfe70u, t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x011e1555: 8365f800 AND
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t5a)) return BatchLiftStatus::invalid_memory;
        t5b = 0x00000000u;
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t5r)) return BatchLiftStatus::invalid_memory;
    // 0x011e1559: 8365fc00 AND
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t6a)) return BatchLiftStatus::invalid_memory;
        t6b = 0x00000000u;
        t6r = (t6a & t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t6r)) return BatchLiftStatus::invalid_memory;
    // 0x011e155d: 53 PUSH
        t7a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x011e155e: 57 PUSH
        t8a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x011e155f: bf4ee640bb MOV
        t9 = 0xbb40e64eu;
        state.regs[7] = t9;
    // 0x011e1564: bb0000ffff MOV
        t10 = 0xffff0000u;
        state.regs[3] = t10;
    // 0x011e1569: 3bc7 CMP
        t11a = state.regs[0];
        t11b = state.regs[7];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x011e156b: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e157a;
    // 0x011e156d: 85c3 TEST
        t13a = state.regs[3];
        t13b = state.regs[0];
        t13r = (t13a & t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
    // 0x011e156f: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e157a;
    // 0x011e1571: f7d0 NOT
        t15a = state.regs[0];
        state.regs[0] = (~t15a & 0xffffffffu);
    // 0x011e1573: a374fe5c01 MOV
        t16 = state.regs[0];
        if (!memory.store32(0x015cfe74u, t16)) return BatchLiftStatus::invalid_memory;
    // 0x011e1578: eb60 JMP
        state.eip = 0x011e1578u;
        return BatchLiftStatus::unsupported_dependency;
    // 0x011e157a: 56 PUSH
    L_011e157a:
        t18a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x011e157b: 8d45f8 LEA
        t19 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u);
        state.regs[0] = t19;
    // 0x011e157e: 50 PUSH
        t20a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x011e157f: ff15ccc13c01 CALL
        t21_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetSystemTimeAsFileTime", 0x013cc1ccu, 0x011e1585u);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x011e1585u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1585: 8b75fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t22;
    // 0x011e1588: 3375f8 XOR
        t23a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t23b)) return BatchLiftStatus::invalid_memory;
        t23r = (t23a ^ t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[6] = t23r;
    // 0x011e158b: ff1514c13c01 CALL
        t24_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetCurrentProcessId", 0x013cc114u, 0x011e1591u);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x011e1591u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1591: 33f0 XOR
        t25a = state.regs[6];
        t25b = state.regs[0];
        t25r = (t25a ^ t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
        state.regs[6] = t25r;
    // 0x011e1593: ff153cc13c01 CALL
        t26_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetCurrentThreadId", 0x013cc13cu, 0x011e1599u);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x011e1599u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1599: 33f0 XOR
        t27a = state.regs[6];
        t27b = state.regs[0];
        t27r = (t27a ^ t27b) & 0xffffffffu;
        batch_set_logic_flags(state, t27r, 32u);
        state.regs[6] = t27r;
    // 0x011e159b: ff1530c13c01 CALL
        t28_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetTickCount", 0x013cc130u, 0x011e15a1u);
        if (t28_call_status != BatchLiftStatus::returned) return t28_call_status;
        if (state.eip != 0x011e15a1u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e15a1: 33f0 XOR
        t29a = state.regs[6];
        t29b = state.regs[0];
        t29r = (t29a ^ t29b) & 0xffffffffu;
        batch_set_logic_flags(state, t29r, 32u);
        state.regs[6] = t29r;
    // 0x011e15a3: 8d45f0 LEA
        t30 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u);
        state.regs[0] = t30;
    // 0x011e15a6: 50 PUSH
        t31a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x011e15a7: ff15b8c23c01 CALL
        t32_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!QueryPerformanceCounter", 0x013cc2b8u, 0x011e15adu);
        if (t32_call_status != BatchLiftStatus::returned) return t32_call_status;
        if (state.eip != 0x011e15adu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e15ad: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x011e15b0: 3345f0 XOR
        t34a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t34b)) return BatchLiftStatus::invalid_memory;
        t34r = (t34a ^ t34b) & 0xffffffffu;
        batch_set_logic_flags(state, t34r, 32u);
        state.regs[0] = t34r;
    // 0x011e15b3: 33f0 XOR
        t35a = state.regs[6];
        t35b = state.regs[0];
        t35r = (t35a ^ t35b) & 0xffffffffu;
        batch_set_logic_flags(state, t35r, 32u);
        state.regs[6] = t35r;
    // 0x011e15b5: 3bf7 CMP
        t36a = state.regs[6];
        t36b = state.regs[7];
        t36r = static_cast<std::uint32_t>(t36a - t36b) & 0xffffffffu;
        batch_set_sub_flags(state, t36a, t36b, t36r, 32u);
    // 0x011e15b7: 7507 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e15c0;
    // 0x011e15b9: be4fe640bb MOV
        t38 = 0xbb40e64fu;
        state.regs[6] = t38;
    // 0x011e15be: eb0b JMP
        goto L_011e15cb;
    // 0x011e15c0: 85f3 TEST
    L_011e15c0:
        t40a = state.regs[3];
        t40b = state.regs[6];
        t40r = (t40a & t40b) & 0xffffffffu;
        batch_set_logic_flags(state, t40r, 32u);
    // 0x011e15c2: 7507 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e15cb;
    // 0x011e15c4: 8bc6 MOV
        t42 = state.regs[6];
        state.regs[0] = t42;
    // 0x011e15c6: c1e010 SHL
        t43a = state.regs[0];
        t43r = static_cast<std::uint32_t>(t43a << 16u) & 0xffffffffu;
        batch_set_shl_flags(state, t43a, 16u, t43r, 32u);
        state.regs[0] = t43r;
    // 0x011e15c9: 0bf0 OR
        t44a = state.regs[6];
        t44b = state.regs[0];
        t44r = (t44a | t44b) & 0xffffffffu;
        batch_set_logic_flags(state, t44r, 32u);
        state.regs[6] = t44r;
    // 0x011e15cb: 893570fe5c01 MOV
    L_011e15cb:
        t45 = state.regs[6];
        if (!memory.store32(0x015cfe70u, t45)) return BatchLiftStatus::invalid_memory;
    // 0x011e15d1: f7d6 NOT
        t46a = state.regs[6];
        state.regs[6] = (~t46a & 0xffffffffu);
    // 0x011e15d3: 893574fe5c01 MOV
        t47 = state.regs[6];
        if (!memory.store32(0x015cfe74u, t47)) return BatchLiftStatus::invalid_memory;
    // 0x011e15d9: 5e POP
        if (!memory.load32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t48a;
    // 0x011e15da: 5f POP
    L_011e15da:
        if (!memory.load32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t49a;
    // 0x011e15db: 5b POP
        if (!memory.load32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t50a;
    // 0x011e15dc: c9 LEAVE
        state.regs[4] = state.regs[5];
        if (!memory.load32(state.regs[4], t51)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t51;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
    // 0x011e15dd: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
