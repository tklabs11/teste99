#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009282e0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00928a30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00928a30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0, t22r = 0;
    std::uint32_t t23a = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0;

    // 0x00928a30: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a31: 57 PUSH
        t1a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a32: 8bf9 MOV
        t2 = state.regs[1];
        state.regs[7] = t2;
    // 0x00928a34: 8bb7e4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x000004e4u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t3;
    // 0x00928a3a: 85f6 TEST
        t4a = state.regs[6];
        t4b = state.regs[6];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x00928a3c: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928a48;
    // 0x00928a3e: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a3f: ff15d8c23c01 CALL
        t7_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x00928a45u);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00928a45u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928a45: ff4618 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t8a)) return BatchLiftStatus::invalid_memory;
        t8r = static_cast<std::uint32_t>(t8a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t8a, t8r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t8r)) return BatchLiftStatus::invalid_memory;
    // 0x00928a48: 8b442418 MOV
    L_00928a48:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x00928a4c: 8b4c2414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t10;
    // 0x00928a50: 8b542410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x00928a54: 50 PUSH
        t12a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a55: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00928a59: 51 PUSH
        t14a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a5a: 52 PUSH
        t15a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a5b: 50 PUSH
        t16a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a5c: 8bcf MOV
        t17 = state.regs[7];
        state.regs[1] = t17;
    // 0x00928a5e: e87df8ffff CALL
        if (!batch_guest_call32(memory, state, 0x009282e0u, 0x00928a63u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_009282e0(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00928a63u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928a63: 8bf8 MOV
        t19 = state.regs[0];
        state.regs[7] = t19;
    // 0x00928a65: 85f6 TEST
        t20a = state.regs[6];
        t20b = state.regs[6];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00928a67: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928a73;
    // 0x00928a69: ff4e18 DEC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t22a)) return BatchLiftStatus::invalid_memory;
        t22r = static_cast<std::uint32_t>(t22a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t22a, t22r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t22r)) return BatchLiftStatus::invalid_memory;
    // 0x00928a6c: 56 PUSH
        t23a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a6d: ff15dcc23c01 CALL
        t24_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x00928a73u);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x00928a73u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928a73: 8bc7 MOV
    L_00928a73:
        t25 = state.regs[7];
        state.regs[0] = t25;
    // 0x00928a75: 5f POP
        if (!memory.load32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t26a;
    // 0x00928a76: 5e POP
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t27a;
    // 0x00928a77: c22000 RET
        if (!batch_guest_return32(memory, state, 32u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
