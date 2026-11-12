#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926a30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926a30u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0;

    // 0x00926a30: 8b8160040000 MOV
        batch_guest_pc = 0x00926a30u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000460u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00926a36: 8d9148040000 LEA
        t1 = static_cast<std::uint32_t>(state.regs[1] + 0x00000448u);
        state.regs[2] = t1;
    // 0x00926a3c: 56 PUSH
        batch_guest_pc = 0x00926a3cu;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00926a3d: 3bc2 CMP
        t3a = state.regs[0];
        t3b = state.regs[2];
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
    // 0x00926a3f: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926a59;
    // 0x00926a41: 8b4c2408 MOV
        batch_guest_pc = 0x00926a41u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x00926a45: 3bc8 CMP
    L_00926a45:
        t6a = state.regs[1];
        t6b = state.regs[0];
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00926a47: 7209 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00926a52;
    // 0x00926a49: 8b7004 MOV
        batch_guest_pc = 0x00926a49u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t8;
    // 0x00926a4c: 03f0 ADD
        t9a = state.regs[6];
        t9b = state.regs[0];
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[6] = t9r;
    // 0x00926a4e: 3bce CMP
        t10a = state.regs[1];
        t10b = state.regs[6];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x00926a50: 7209 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00926a5b;
    // 0x00926a52: 8b4018 MOV
    L_00926a52:
        batch_guest_pc = 0x00926a52u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x00926a55: 3bc2 CMP
        t13a = state.regs[0];
        t13b = state.regs[2];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x00926a57: 75ec JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00926a45;
    // 0x00926a59: 33c0 XOR
    L_00926a59:
        t15a = state.regs[0];
        t15b = state.regs[0];
        t15r = (t15a ^ t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
        state.regs[0] = t15r;
    // 0x00926a5b: 5e POP
    L_00926a5b:
        batch_guest_pc = 0x00926a5bu;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t16a;
    // 0x00926a5c: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
