#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009215c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009215c0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;

    // 0x009215c0: 8b4c2404 MOV
        batch_guest_pc = 0x009215c0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t0;
    // 0x009215c4: 8b5108 MOV
        batch_guest_pc = 0x009215c4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t1;
    // 0x009215c7: 394a08 CMP
        batch_guest_pc = 0x009215c7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t2a)) return BatchLiftStatus::invalid_memory;
        t2b = state.regs[1];
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x009215ca: 7509 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009215d5;
    // 0x009215cc: 80790c00 CMP
        batch_guest_pc = 0x009215ccu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t4a)) return BatchLiftStatus::invalid_memory;
        t4b = 0x00000000u;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0x000000ffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 8u);
    // 0x009215d0: 7503 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009215d5;
    // 0x009215d2: 8b01 MOV
        batch_guest_pc = 0x009215d2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x009215d4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009215d5: 8b4104 MOV
    L_009215d5:
        batch_guest_pc = 0x009215d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x009215d8: 85c0 TEST
        t9a = state.regs[0];
        t9b = state.regs[0];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x009215da: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009215eb;
    // 0x009215dc: 8b08 MOV
        batch_guest_pc = 0x009215dcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t11;
    // 0x009215de: 85c9 TEST
        t12a = state.regs[1];
        t12b = state.regs[1];
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
    // 0x009215e0: 741a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009215fc;
    // 0x009215e2: 8bc1 MOV
    L_009215e2:
        t14 = state.regs[1];
        state.regs[0] = t14;
    // 0x009215e4: 8b08 MOV
        batch_guest_pc = 0x009215e4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x009215e6: 85c9 TEST
        t16a = state.regs[1];
        t16b = state.regs[1];
        t16r = (t16a & t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
    // 0x009215e8: 75f8 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009215e2;
    // 0x009215ea: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009215eb: 8bc2 MOV
    L_009215eb:
        t19 = state.regs[2];
        state.regs[0] = t19;
    // 0x009215ed: 3b4804 CMP
        batch_guest_pc = 0x009215edu;
        t20a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t20b)) return BatchLiftStatus::invalid_memory;
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x009215f0: 750a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009215fc;
    // 0x009215f2: 8bc8 MOV
    L_009215f2:
        t22 = state.regs[0];
        state.regs[1] = t22;
    // 0x009215f4: 8b4008 MOV
        batch_guest_pc = 0x009215f4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x009215f7: 3b4804 CMP
        batch_guest_pc = 0x009215f7u;
        t24a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t24b)) return BatchLiftStatus::invalid_memory;
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x009215fa: 74f6 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009215f2;
    // 0x009215fc: c3 RET
    L_009215fc:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
