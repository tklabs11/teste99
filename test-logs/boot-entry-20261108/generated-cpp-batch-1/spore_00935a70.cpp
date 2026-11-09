#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00620230(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00935a70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00935a70u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24a = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26a = 0;
    std::uint32_t t27 = 0;

    // 0x00935a70: b834996601 MOV
        t0 = 0x01669934u;
        state.regs[0] = t0;
    // 0x00935a75: 83c9ff OR
        t1a = state.regs[1];
        t1b = 0xffffffffu;
        t1r = (t1a | t1b) & 0xffffffffu;
        batch_set_logic_flags(state, t1r, 32u);
        state.regs[1] = t1r;
    // 0x00935a78: f00fc108 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t2a)) return BatchLiftStatus::invalid_memory;
        t2b = state.regs[1];
        t2r = static_cast<std::uint32_t>(t2a + t2b) & 0xffffffffu;
        batch_set_add_flags(state, t2a, t2b, t2r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t2r)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t2a;
    // 0x00935a7c: 7551 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00935acf;
    // 0x00935a7e: a130996601 MOV
        if (!memory.load32(0x01669930u, t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00935a83: 85c0 TEST
        t5a = state.regs[0];
        t5b = state.regs[0];
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
    // 0x00935a85: 7448 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935acf;
    // 0x00935a87: 83c008 ADD
        t7a = state.regs[0];
        t7b = 0x00000008u;
        t7r = static_cast<std::uint32_t>(t7a + t7b) & 0xffffffffu;
        batch_set_add_flags(state, t7a, t7b, t7r, 32u);
        state.regs[0] = t7r;
    // 0x00935a8a: 83caff OR
        t8a = state.regs[2];
        t8b = 0xffffffffu;
        t8r = (t8a | t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[2] = t8r;
    // 0x00935a8d: f00fc110 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t9a)) return BatchLiftStatus::invalid_memory;
        t9b = state.regs[2];
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t9r)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9a;
    // 0x00935a91: 7532 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00935ac5;
    // 0x00935a93: a130996601 MOV
        if (!memory.load32(0x01669930u, t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00935a98: 56 PUSH
        t12a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00935a99: 8bf0 MOV
        t13 = state.regs[0];
        state.regs[6] = t13;
    // 0x00935a9b: 83c00c ADD
        t14a = state.regs[0];
        t14b = 0x0000000cu;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[0] = t14r;
    // 0x00935a9e: 50 PUSH
        t15a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00935a9f: ff15d4c23c01 CALL
        t16_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!DeleteCriticalSection", 0x013cc2d4u, 0x00935aa5u);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00935aa5u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935aa5: 8bce MOV
        t17 = state.regs[6];
        state.regs[1] = t17;
    // 0x00935aa7: e884a7ceff CALL
        if (!batch_guest_call32(memory, state, 0x00620230u, 0x00935aacu)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00620230(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00935aacu) return BatchLiftStatus::invalid_control_flow;
    // 0x00935aac: a130996601 MOV
        if (!memory.load32(0x01669930u, t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x00935ab1: 8b48fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t20;
    // 0x00935ab4: 51 PUSH
        t21a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00935ab5: 6a00 PUSH
        t22a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00935ab7: ff15b8c13c01 CALL
        t23_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetProcessHeap", 0x013cc1b8u, 0x00935abdu);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x00935abdu) return BatchLiftStatus::invalid_control_flow;
    // 0x00935abd: 50 PUSH
        t24a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00935abe: ff15bcc13c01 CALL
        t25_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!HeapFree", 0x013cc1bcu, 0x00935ac4u);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00935ac4u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935ac4: 5e POP
        if (!memory.load32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t26a;
    // 0x00935ac5: c7053099660100000000 MOV
    L_00935ac5:
        t27 = 0x00000000u;
        if (!memory.store32(0x01669930u, t27)) return BatchLiftStatus::invalid_memory;
    // 0x00935acf: c3 RET
    L_00935acf:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
