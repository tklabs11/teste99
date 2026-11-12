#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_007611f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x007611f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0;

    // 0x007611f0: 55 PUSH
        batch_guest_pc = 0x007611f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x007611f1: 8b6c240c MOV
        batch_guest_pc = 0x007611f1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t1;
    // 0x007611f5: 57 PUSH
        batch_guest_pc = 0x007611f5u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x007611f6: 33ff XOR
        t3a = state.regs[7];
        t3b = state.regs[7];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[7] = t3r;
    // 0x007611f8: 85ed TEST
        t4a = state.regs[5];
        t4b = state.regs[5];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x007611fa: 7634 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00761230;
    // 0x007611fc: 53 PUSH
        batch_guest_pc = 0x007611fcu;
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x007611fd: 8b5c2410 MOV
        batch_guest_pc = 0x007611fdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t7;
    // 0x00761201: 56 PUSH
        batch_guest_pc = 0x00761201u;
        t8a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00761202: 8b34bb MOV
    L_00761202:
        batch_guest_pc = 0x00761202u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + state.regs[7] * 4u + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t9;
    // 0x00761205: 85f6 TEST
        t10a = state.regs[6];
        t10b = state.regs[6];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x00761207: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00761222;
    // 0x00761209: 8da42400000000 LEA
        t12 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t12;
    // 0x00761210: 8bc6 MOV
    L_00761210:
        t13 = state.regs[6];
        state.regs[0] = t13;
    // 0x00761212: 8b7610 MOV
        batch_guest_pc = 0x00761212u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t14;
    // 0x00761215: 50 PUSH
        batch_guest_pc = 0x00761215u;
        t15a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00761216: e865617e00 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0076121bu)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00f47380(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x0076121bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0076121b: 83c404 ADD
        t17a = state.regs[4];
        t17b = 0x00000004u;
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        state.regs[4] = t17r;
    // 0x0076121e: 85f6 TEST
        t18a = state.regs[6];
        t18b = state.regs[6];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
    // 0x00761220: 75ee JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00761210;
    // 0x00761222: c704bb00000000 MOV
    L_00761222:
        batch_guest_pc = 0x00761222u;
        t20 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + state.regs[7] * 4u + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00761229: 47 INC
        t21a = state.regs[7];
        t21r = static_cast<std::uint32_t>(t21a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t21a, t21r, 32u);
        state.regs[7] = t21r;
    // 0x0076122a: 3bfd CMP
        t22a = state.regs[7];
        t22b = state.regs[5];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x0076122c: 72d4 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00761202;
    // 0x0076122e: 5e POP
        batch_guest_pc = 0x0076122eu;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t24a;
    // 0x0076122f: 5b POP
        batch_guest_pc = 0x0076122fu;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t25a;
    // 0x00761230: 5f POP
    L_00761230:
        batch_guest_pc = 0x00761230u;
        if (!memory.load32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t26a;
    // 0x00761231: 5d POP
        batch_guest_pc = 0x00761231u;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t27a;
    // 0x00761232: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
