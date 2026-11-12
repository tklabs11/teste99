#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e000(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e000u);
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

    // 0x0121e000: 55 PUSH
        batch_guest_pc = 0x0121e000u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e001: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e003: 51 PUSH
        batch_guest_pc = 0x0121e003u;
        t2a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e004: c745fc00000000 MOV
        batch_guest_pc = 0x0121e004u;
        t3 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0121e00b: 8b45fc MOV
        batch_guest_pc = 0x0121e00bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0121e00e: 25ffffff3f AND
        t5a = state.regs[0];
        t5b = 0x3fffffffu;
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        state.regs[0] = t5r;
    // 0x0121e013: 0d00000040 OR
        t6a = state.regs[0];
        t6b = 0x40000000u;
        t6r = (t6a | t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[0] = t6r;
    // 0x0121e018: 8945fc MOV
        batch_guest_pc = 0x0121e018u;
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x0121e01b: b962000000 MOV
        t8 = 0x00000062u;
        state.regs[1] = t8;
    // 0x0121e020: 81e1ff000000 AND
        t9a = state.regs[1];
        t9b = 0x000000ffu;
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
        state.regs[1] = t9r;
    // 0x0121e026: c1e110 SHL
        t10a = state.regs[1];
        t10c = 16u;
        if (t10c != 0u) {
        t10r = static_cast<std::uint32_t>(t10a << t10c) & 0xffffffffu;
        batch_set_shl_flags(state, t10a, t10c, t10r, 32u);
            state.regs[1] = t10r;
        }
    // 0x0121e029: 8b55fc MOV
        batch_guest_pc = 0x0121e029u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x0121e02c: 81e2ffff00ff AND
        t12a = state.regs[2];
        t12b = 0xff00ffffu;
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
        state.regs[2] = t12r;
    // 0x0121e032: 0bd1 OR
        t13a = state.regs[2];
        t13b = state.regs[1];
        t13r = (t13a | t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
        state.regs[2] = t13r;
    // 0x0121e034: 8955fc MOV
        batch_guest_pc = 0x0121e034u;
        t14 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0121e037: b860000000 MOV
        t15 = 0x00000060u;
        state.regs[0] = t15;
    // 0x0121e03c: 25ff000000 AND
        t16a = state.regs[0];
        t16b = 0x000000ffu;
        t16r = (t16a & t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[0] = t16r;
    // 0x0121e041: c1e008 SHL
        t17a = state.regs[0];
        t17c = 8u;
        if (t17c != 0u) {
        t17r = static_cast<std::uint32_t>(t17a << t17c) & 0xffffffffu;
        batch_set_shl_flags(state, t17a, t17c, t17r, 32u);
            state.regs[0] = t17r;
        }
    // 0x0121e044: 8b4dfc MOV
        batch_guest_pc = 0x0121e044u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t18;
    // 0x0121e047: 81e1ff00ffff AND
        t19a = state.regs[1];
        t19b = 0xffff00ffu;
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[1] = t19r;
    // 0x0121e04d: 0bc8 OR
        t20a = state.regs[1];
        t20b = state.regs[0];
        t20r = (t20a | t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
        state.regs[1] = t20r;
    // 0x0121e04f: 894dfc MOV
        batch_guest_pc = 0x0121e04fu;
        t21 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x0121e052: 8b55fc MOV
        batch_guest_pc = 0x0121e052u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x0121e055: 89157c115d01 MOV
        batch_guest_pc = 0x0121e055u;
        t23 = state.regs[2];
        if (!memory.store32(0x015d117cu, t23)) return BatchLiftStatus::invalid_memory;
    // 0x0121e05b: 8be5 MOV
        t24 = state.regs[5];
        state.regs[4] = t24;
    // 0x0121e05d: 5d POP
        batch_guest_pc = 0x0121e05du;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t25a;
    // 0x0121e05e: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
