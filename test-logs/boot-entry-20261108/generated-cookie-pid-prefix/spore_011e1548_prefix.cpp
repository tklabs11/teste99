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
    state.eip = 0x011e158bu;
    return BatchLiftStatus::unsupported_dependency;
}
