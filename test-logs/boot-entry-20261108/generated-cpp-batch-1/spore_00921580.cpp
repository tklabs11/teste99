#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00921580(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00921580u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;

    // 0x00921580: 8b4c2404 MOV
        batch_guest_pc = 0x00921580u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t0;
    // 0x00921584: 8b01 MOV
        batch_guest_pc = 0x00921584u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00921586: 85c0 TEST
        t2a = state.regs[0];
        t2b = state.regs[0];
        t2r = (t2a & t2b) & 0xffffffffu;
        batch_set_logic_flags(state, t2r, 32u);
    // 0x00921588: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092159b;
    // 0x0092158a: 8b4804 MOV
        batch_guest_pc = 0x0092158au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x0092158d: 85c9 TEST
        t5a = state.regs[1];
        t5b = state.regs[1];
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
    // 0x0092158f: 7420 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009215b1;
    // 0x00921591: 8bc1 MOV
    L_00921591:
        t7 = state.regs[1];
        state.regs[0] = t7;
    // 0x00921593: 8b4804 MOV
        batch_guest_pc = 0x00921593u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t8;
    // 0x00921596: 85c9 TEST
        t9a = state.regs[1];
        t9b = state.regs[1];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x00921598: 75f7 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921591;
    // 0x0092159a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092159b: 8b4108 MOV
    L_0092159b:
        batch_guest_pc = 0x0092159bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x0092159e: 3b08 CMP
        batch_guest_pc = 0x0092159eu;
        t13a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t13b)) return BatchLiftStatus::invalid_memory;
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x009215a0: 7509 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009215ab;
    // 0x009215a2: 8bc8 MOV
    L_009215a2:
        t15 = state.regs[0];
        state.regs[1] = t15;
    // 0x009215a4: 8b4008 MOV
        batch_guest_pc = 0x009215a4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t16;
    // 0x009215a7: 3b08 CMP
        batch_guest_pc = 0x009215a7u;
        t17a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17b)) return BatchLiftStatus::invalid_memory;
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x009215a9: 74f7 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009215a2;
    // 0x009215ab: 3901 CMP
    L_009215ab:
        batch_guest_pc = 0x009215abu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t19a)) return BatchLiftStatus::invalid_memory;
        t19b = state.regs[0];
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x009215ad: 7502 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009215b1;
    // 0x009215af: 8bc1 MOV
        t21 = state.regs[1];
        state.regs[0] = t21;
    // 0x009215b1: c3 RET
    L_009215b1:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
