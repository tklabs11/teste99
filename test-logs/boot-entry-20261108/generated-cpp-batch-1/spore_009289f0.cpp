#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00927be0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009289f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009289f0u);
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
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18a = 0, t18r = 0;
    std::uint32_t t19a = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;

    // 0x009289f0: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009289f1: 57 PUSH
        t1a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009289f2: 8bf9 MOV
        t2 = state.regs[1];
        state.regs[7] = t2;
    // 0x009289f4: 8bb7e4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x000004e4u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t3;
    // 0x009289fa: 85f6 TEST
        t4a = state.regs[6];
        t4b = state.regs[6];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x009289fc: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928a08;
    // 0x009289fe: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x009289ff: ff15d8c23c01 CALL
        t7_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x00928a05u);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00928a05u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928a05: ff4618 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t8a)) return BatchLiftStatus::invalid_memory;
        t8r = static_cast<std::uint32_t>(t8a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t8a, t8r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t8r)) return BatchLiftStatus::invalid_memory;
    // 0x00928a08: 8b442410 MOV
    L_00928a08:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x00928a0c: 8b4c240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t10;
    // 0x00928a10: 50 PUSH
        t11a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a11: 51 PUSH
        t12a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a12: 8bcf MOV
        t13 = state.regs[7];
        state.regs[1] = t13;
    // 0x00928a14: e8c7f1ffff CALL
        if (!batch_guest_call32(memory, state, 0x00927be0u, 0x00928a19u)) return BatchLiftStatus::invalid_memory;
        t14_call_status = spore_lift_00927be0(memory, state);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x00928a19u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928a19: 8bf8 MOV
        t15 = state.regs[0];
        state.regs[7] = t15;
    // 0x00928a1b: 85f6 TEST
        t16a = state.regs[6];
        t16b = state.regs[6];
        t16r = (t16a & t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
    // 0x00928a1d: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928a29;
    // 0x00928a1f: ff4e18 DEC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t18a)) return BatchLiftStatus::invalid_memory;
        t18r = static_cast<std::uint32_t>(t18a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t18a, t18r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t18r)) return BatchLiftStatus::invalid_memory;
    // 0x00928a22: 56 PUSH
        t19a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00928a23: ff15dcc23c01 CALL
        t20_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x00928a29u);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x00928a29u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928a29: 8bc7 MOV
    L_00928a29:
        t21 = state.regs[7];
        state.regs[0] = t21;
    // 0x00928a2b: 5f POP
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t22a;
    // 0x00928a2c: 5e POP
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t23a;
    // 0x00928a2d: c21800 RET
        if (!batch_guest_return32(memory, state, 24u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
