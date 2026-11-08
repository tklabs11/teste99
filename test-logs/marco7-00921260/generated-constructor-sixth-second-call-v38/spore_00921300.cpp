#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00921300(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0, t3r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;

    // 0x00921300: 8b542408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00921304: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00921308: 2bd0 SUB
        t2a = state.regs[2];
        t2b = state.regs[0];
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[2] = t2r;
    // 0x0092130a: c1fa02 SAR
        t3a = state.regs[2];
        t3r = (t3a >> 2u) | ((t3a & 0x80000000u) ? (0xffffffffu << 30u) : 0u);
        batch_set_logic_flags(state, t3r, 32u);
        if ((t3a & 2u) != 0u) state.eflags |= 0x001u;
        state.regs[2] = t3r;
    // 0x0092130d: 85d2 TEST
        t4a = state.regs[2];
        t4b = state.regs[2];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x0092130f: 7e2d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0092133e;
    // 0x00921311: 8b4c240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00921315: 56 PUSH
        t7a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00921316: 8b31 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t8;
    // 0x00921318: 57 PUSH
        t9a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00921319: 8da42400000000 LEA
        t10 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t10;
    // 0x00921320: 8bca MOV
    L_00921320:
        t11 = state.regs[2];
        state.regs[1] = t11;
    // 0x00921322: d1f9 SAR
        t12a = state.regs[1];
        t12r = (t12a >> 1u) | ((t12a & 0x80000000u) ? (0xffffffffu << 31u) : 0u);
        batch_set_logic_flags(state, t12r, 32u);
        if ((t12a & 1u) != 0u) state.eflags |= 0x001u;
        state.regs[1] = t12r;
    // 0x00921324: 393488 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 4u + 0x00000000u), t13a)) return BatchLiftStatus::invalid_memory;
        t13b = state.regs[6];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x00921327: 730d JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00921336;
    // 0x00921329: 83cfff OR
        t15a = state.regs[7];
        t15b = 0xffffffffu;
        t15r = (t15a | t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
        state.regs[7] = t15r;
    // 0x0092132c: 2bf9 SUB
        t16a = state.regs[7];
        t16b = state.regs[1];
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
        state.regs[7] = t16r;
    // 0x0092132e: 8d448804 LEA
        t17 = static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 4u + 0x00000004u);
        state.regs[0] = t17;
    // 0x00921332: 03d7 ADD
        t18a = state.regs[2];
        t18b = state.regs[7];
        t18r = static_cast<std::uint32_t>(t18a + t18b) & 0xffffffffu;
        batch_set_add_flags(state, t18a, t18b, t18r, 32u);
        state.regs[2] = t18r;
    // 0x00921334: eb02 JMP
        goto L_00921338;
    // 0x00921336: 8bd1 MOV
    L_00921336:
        t20 = state.regs[1];
        state.regs[2] = t20;
    // 0x00921338: 85d2 TEST
    L_00921338:
        t21a = state.regs[2];
        t21b = state.regs[2];
        t21r = (t21a & t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
    // 0x0092133a: 7fe4 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00921320;
    // 0x0092133c: 5f POP
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t23a;
    // 0x0092133d: 5e POP
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t24a;
    // 0x0092133e: c3 RET
    L_0092133e:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
