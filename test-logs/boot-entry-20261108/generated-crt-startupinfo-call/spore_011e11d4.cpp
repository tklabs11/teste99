#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e11d4(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;

    // 0x011e11d4: 682d121e01 PUSH
        t0a = 0x011e122du;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e11d9: 64ff3500000000 PUSH
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t1a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e11e0: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x011e11e4: 896c2410 MOV
        t3 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x011e11e8: 8d6c2410 LEA
        t4 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[5] = t4;
    // 0x011e11ec: 2be0 SUB
        t5a = state.regs[4];
        t5b = state.regs[0];
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x011e11ee: 53 PUSH
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x011e11ef: 56 PUSH
        t7a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x011e11f0: 57 PUSH
        t8a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x011e11f1: a170fe5c01 MOV
        if (!memory.load32(0x015cfe70u, t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x011e11f6: 3145fc XOR
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t10a)) return BatchLiftStatus::invalid_memory;
        t10b = state.regs[0];
        t10r = (t10a ^ t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t10r)) return BatchLiftStatus::invalid_memory;
    // 0x011e11f9: 33c5 XOR
        t11a = state.regs[0];
        t11b = state.regs[5];
        t11r = (t11a ^ t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
        state.regs[0] = t11r;
    // 0x011e11fb: 50 PUSH
        t12a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x011e11fc: 8965e8 MOV
        t13 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x011e11ff: ff75f8 PUSH
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1202: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x011e1205: c745fcfeffffff MOV
        t16 = 0xfffffffeu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x011e120c: 8945f8 MOV
        t17 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x011e120f: 8d45f0 LEA
        t18 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u);
        state.regs[0] = t18;
    // 0x011e1212: 64a300000000 MOV
        t19 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x011e1218: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
