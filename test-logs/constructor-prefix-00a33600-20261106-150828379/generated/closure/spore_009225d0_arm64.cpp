#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009225d0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;

    // 0x009225d0: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009225d4: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009225d5: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x009225d7: 8a4c240c MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t3 << 0u) & 0x000000ffu);
    // 0x009225db: 8906 MOV
        t4 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x009225dd: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x009225e1: 884e04 MOV
        t6 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x009225e4: 85c0 TEST
        t7a = state.regs[0];
        t7b = state.regs[0];
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
    // 0x009225e6: 741a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00922602;
    // 0x009225e8: 6a0f PUSH
        t9a = 0x0000000fu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x009225ea: 50 PUSH
        t10a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x009225eb: 8d5605 LEA
        t11 = static_cast<std::uint32_t>(state.regs[6] + 0x00000005u);
        state.regs[2] = t11;
    // 0x009225ee: 52 PUSH
        t12a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x009225ef: ff15f4c43c01 CALL
        t13_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!strncpy", 0x013cc4f4u, 0x009225f5u);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x009225f5u) return BatchLiftStatus::invalid_control_flow;
    // 0x009225f5: 83c40c ADD
        t14a = state.regs[4];
        t14b = 0x0000000cu;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[4] = t14r;
    // 0x009225f8: c6461400 MOV
        t15 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x009225fc: 8bc6 MOV
        t16 = state.regs[6];
        state.regs[0] = t16;
    // 0x009225fe: 5e POP
        if (!memory.load32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t17a;
    // 0x009225ff: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00922602: c6460500 MOV
    L_00922602:
        t19 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000005u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00922606: 8bc6 MOV
        t20 = state.regs[6];
        state.regs[0] = t20;
    // 0x00922608: 5e POP
        if (!memory.load32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t21a;
    // 0x00922609: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
