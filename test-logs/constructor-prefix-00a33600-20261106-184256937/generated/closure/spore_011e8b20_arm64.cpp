#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e8b20(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9r = 0;
    std::uint32_t t10a = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;

    // 0x011e8b20: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x011e8b24: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e8b25: 8b74240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t2;
    // 0x011e8b29: 8a0e MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t3 << 0u) & 0x000000ffu);
    // 0x011e8b2b: 84c9 TEST
        t4a = state.regs[1] & 0x000000ffu;
        t4b = state.regs[1] & 0x000000ffu;
        t4r = (t4a & t4b) & 0x000000ffu;
        batch_set_logic_flags(state, t4r, 8u);
    // 0x011e8b2d: 8bd0 MOV
        t5 = state.regs[0];
        state.regs[2] = t5;
    // 0x011e8b2f: 740b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e8b3c;
    // 0x011e8b31: 880a MOV
    L_011e8b31:
        t7 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x011e8b33: 8a4e01 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000001u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t8 << 0u) & 0x000000ffu);
    // 0x011e8b36: 42 INC
        t9a = state.regs[2];
        t9r = static_cast<std::uint32_t>(t9a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t9a, t9r, 32u);
        state.regs[2] = t9r;
    // 0x011e8b37: 46 INC
        t10a = state.regs[6];
        t10r = static_cast<std::uint32_t>(t10a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t10a, t10r, 32u);
        state.regs[6] = t10r;
    // 0x011e8b38: 84c9 TEST
        t11a = state.regs[1] & 0x000000ffu;
        t11b = state.regs[1] & 0x000000ffu;
        t11r = (t11a & t11b) & 0x000000ffu;
        batch_set_logic_flags(state, t11r, 8u);
    // 0x011e8b3a: 75f5 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e8b31;
    // 0x011e8b3c: c60200 MOV
    L_011e8b3c:
        t13 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x011e8b3f: 5e POP
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t14a;
    // 0x011e8b40: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
