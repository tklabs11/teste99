#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222a60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222a60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10c = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0, t17c = 0, t17r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0;

    // 0x01222a60: 55 PUSH
        batch_guest_pc = 0x01222a60u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222a61: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222a63: 51 PUSH
        batch_guest_pc = 0x01222a63u;
        t2a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x01222a64: c745fc00000000 MOV
        batch_guest_pc = 0x01222a64u;
        t3 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x01222a6b: 8b45fc MOV
        batch_guest_pc = 0x01222a6bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x01222a6e: 25ffffff3f AND
        t5a = state.regs[0];
        t5b = 0x3fffffffu;
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        state.regs[0] = t5r;
    // 0x01222a73: 0d00000040 OR
        t6a = state.regs[0];
        t6b = 0x40000000u;
        t6r = (t6a | t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[0] = t6r;
    // 0x01222a78: 8945fc MOV
        batch_guest_pc = 0x01222a78u;
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x01222a7b: b96a000000 MOV
        t8 = 0x0000006au;
        state.regs[1] = t8;
    // 0x01222a80: 81e1ff000000 AND
        t9a = state.regs[1];
        t9b = 0x000000ffu;
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
        state.regs[1] = t9r;
    // 0x01222a86: c1e110 SHL
        t10a = state.regs[1];
        t10c = 16u;
        if (t10c != 0u) {
        t10r = static_cast<std::uint32_t>(t10a << t10c) & 0xffffffffu;
        batch_set_shl_flags(state, t10a, t10c, t10r, 32u);
            state.regs[1] = t10r;
        }
    // 0x01222a89: 8b55fc MOV
        batch_guest_pc = 0x01222a89u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x01222a8c: 81e2ffff00ff AND
        t12a = state.regs[2];
        t12b = 0xff00ffffu;
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
        state.regs[2] = t12r;
    // 0x01222a92: 0bd1 OR
        t13a = state.regs[2];
        t13b = state.regs[1];
        t13r = (t13a | t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
        state.regs[2] = t13r;
    // 0x01222a94: 8955fc MOV
        batch_guest_pc = 0x01222a94u;
        t14 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x01222a97: b802000000 MOV
        t15 = 0x00000002u;
        state.regs[0] = t15;
    // 0x01222a9c: 25ff000000 AND
        t16a = state.regs[0];
        t16b = 0x000000ffu;
        t16r = (t16a & t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[0] = t16r;
    // 0x01222aa1: c1e008 SHL
        t17a = state.regs[0];
        t17c = 8u;
        if (t17c != 0u) {
        t17r = static_cast<std::uint32_t>(t17a << t17c) & 0xffffffffu;
        batch_set_shl_flags(state, t17a, t17c, t17r, 32u);
            state.regs[0] = t17r;
        }
    // 0x01222aa4: 8b4dfc MOV
        batch_guest_pc = 0x01222aa4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t18;
    // 0x01222aa7: 81e1ff00ffff AND
        t19a = state.regs[1];
        t19b = 0xffff00ffu;
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[1] = t19r;
    // 0x01222aad: 0bc8 OR
        t20a = state.regs[1];
        t20b = state.regs[0];
        t20r = (t20a | t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
        state.regs[1] = t20r;
    // 0x01222aaf: 894dfc MOV
        batch_guest_pc = 0x01222aafu;
        t21 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x01222ab2: 8b55fc MOV
        batch_guest_pc = 0x01222ab2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x01222ab5: 8915b8225d01 MOV
        batch_guest_pc = 0x01222ab5u;
        t23 = state.regs[2];
        if (!memory.store32(0x015d22b8u, t23)) return BatchLiftStatus::invalid_memory;
    // 0x01222abb: 8be5 MOV
        t24 = state.regs[5];
        state.regs[4] = t24;
    // 0x01222abd: 5d POP
        batch_guest_pc = 0x01222abdu;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t25a;
    // 0x01222abe: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
