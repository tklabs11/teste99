#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00420050(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00420050u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;

    // 0x00420050: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00420051: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00420053: 51 PUSH
        t2a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00420054: 894dfc MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00420057: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0042005a: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x0042005d: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t6;
    // 0x0042005f: 8910 MOV
        t7 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00420061: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00420064: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t9;
    // 0x00420067: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t10;
    // 0x0042006a: 895004 MOV
        t11 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x0042006d: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x00420070: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00420073: 8b5108 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x00420076: 895008 MOV
        t15 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00420079: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t16;
    // 0x0042007c: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x0042007f: 8b510c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x00420082: 89500c MOV
        t19 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00420085: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t20;
    // 0x00420088: 8be5 MOV
        t21 = state.regs[5];
        state.regs[4] = t21;
    // 0x0042008a: 5d POP
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t22a;
    // 0x0042008b: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
