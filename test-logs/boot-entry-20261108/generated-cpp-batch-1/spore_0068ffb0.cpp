#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0068ffcc(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0068ffb0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0068ffb0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0;

    // 0x0068ffb0: 8b4c2404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t0;
    // 0x0068ffb4: 8b4118 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000018u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x0068ffb7: 56 PUSH
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0068ffb8: 8d7140 LEA
        t3 = static_cast<std::uint32_t>(state.regs[1] + 0x00000040u);
        state.regs[6] = t3;
    // 0x0068ffbb: 8b0e MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x0068ffbd: 3bce CMP
        t5a = state.regs[1];
        t5b = state.regs[6];
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x0068ffbf: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068ffdd;
    // 0x0068ffc1: 85c9 TEST
    L_0068ffc1:
        t7a = state.regs[1];
        t7b = state.regs[1];
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
    // 0x0068ffc3: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068ffca;
    // 0x0068ffc5: 8d51f8 LEA
        t9 = static_cast<std::uint32_t>(state.regs[1] + 0xfffffff8u);
        state.regs[2] = t9;
    // 0x0068ffc8: eb02 JMP
        goto L_0068ffcc;
    // 0x0068ffca: 33d2 XOR
    L_0068ffca:
        t11a = state.regs[2];
        t11b = state.regs[2];
        t11r = (t11a ^ t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
        state.regs[2] = t11r;
    // 0x0068ffcc: 8b5214 MOV
    L_0068ffcc:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000014u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t12;
    // 0x0068ffcf: 8b5248 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000048u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x0068ffd2: 8b09 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x0068ffd4: 3bd0 CMP
        t15a = state.regs[2];
        t15b = state.regs[0];
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x0068ffd6: 0f4fc2 CMOVG
        t16a = state.regs[2];
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) state.regs[0] = t16a;
    // 0x0068ffd9: 3bce CMP
        t17a = state.regs[1];
        t17b = state.regs[6];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x0068ffdb: 75e4 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0068ffc1;
    // 0x0068ffdd: 5e POP
    L_0068ffdd:
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t19a;
    // 0x0068ffde: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
