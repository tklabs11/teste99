#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223200(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223200u);
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
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;

    // 0x01223200: 55 PUSH
        batch_guest_pc = 0x01223200u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223201: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223203: 51 PUSH
        batch_guest_pc = 0x01223203u;
        t2a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x01223204: c745fc00000000 MOV
        batch_guest_pc = 0x01223204u;
        t3 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0122320b: 8b45fc MOV
        batch_guest_pc = 0x0122320bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0122320e: 25ffffff3f AND
        t5a = state.regs[0];
        t5b = 0x3fffffffu;
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        state.regs[0] = t5r;
    // 0x01223213: 0d00000040 OR
        t6a = state.regs[0];
        t6b = 0x40000000u;
        t6r = (t6a | t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[0] = t6r;
    // 0x01223218: 8945fc MOV
        batch_guest_pc = 0x01223218u;
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x0122321b: b962000000 MOV
        t8 = 0x00000062u;
        state.regs[1] = t8;
    // 0x01223220: 81e1ff000000 AND
        t9a = state.regs[1];
        t9b = 0x000000ffu;
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
        state.regs[1] = t9r;
    // 0x01223226: c1e110 SHL
        t10a = state.regs[1];
        t10c = 16u;
        if (t10c != 0u) {
        t10r = static_cast<std::uint32_t>(t10a << t10c) & 0xffffffffu;
        batch_set_shl_flags(state, t10a, t10c, t10r, 32u);
            state.regs[1] = t10r;
        }
    // 0x01223229: 8b55fc MOV
        batch_guest_pc = 0x01223229u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x0122322c: 81e2ffff00ff AND
        t12a = state.regs[2];
        t12b = 0xff00ffffu;
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
        state.regs[2] = t12r;
    // 0x01223232: 0bd1 OR
        t13a = state.regs[2];
        t13b = state.regs[1];
        t13r = (t13a | t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
        state.regs[2] = t13r;
    // 0x01223234: 8955fc MOV
        batch_guest_pc = 0x01223234u;
        t14 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x01223237: b801000000 MOV
        t15 = 0x00000001u;
        state.regs[0] = t15;
    // 0x0122323c: 25ff000000 AND
        t16a = state.regs[0];
        t16b = 0x000000ffu;
        t16r = (t16a & t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[0] = t16r;
    // 0x01223241: c1e008 SHL
        t17a = state.regs[0];
        t17c = 8u;
        if (t17c != 0u) {
        t17r = static_cast<std::uint32_t>(t17a << t17c) & 0xffffffffu;
        batch_set_shl_flags(state, t17a, t17c, t17r, 32u);
            state.regs[0] = t17r;
        }
    // 0x01223244: 8b4dfc MOV
        batch_guest_pc = 0x01223244u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t18;
    // 0x01223247: 81e1ff00ffff AND
        t19a = state.regs[1];
        t19b = 0xffff00ffu;
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[1] = t19r;
    // 0x0122324d: 0bc8 OR
        t20a = state.regs[1];
        t20b = state.regs[0];
        t20r = (t20a | t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
        state.regs[1] = t20r;
    // 0x0122324f: 894dfc MOV
        batch_guest_pc = 0x0122324fu;
        t21 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x01223252: ba62000000 MOV
        t22 = 0x00000062u;
        state.regs[2] = t22;
    // 0x01223257: 81e2ff000000 AND
        t23a = state.regs[2];
        t23b = 0x000000ffu;
        t23r = (t23a & t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[2] = t23r;
    // 0x0122325d: 8b45fc MOV
        batch_guest_pc = 0x0122325du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t24;
    // 0x01223260: 2500ffffff AND
        t25a = state.regs[0];
        t25b = 0xffffff00u;
        t25r = (t25a & t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
        state.regs[0] = t25r;
    // 0x01223265: 0bc2 OR
        t26a = state.regs[0];
        t26b = state.regs[2];
        t26r = (t26a | t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[0] = t26r;
    // 0x01223267: 8945fc MOV
        batch_guest_pc = 0x01223267u;
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t27)) return BatchLiftStatus::invalid_memory;
    // 0x0122326a: 8b4dfc MOV
        batch_guest_pc = 0x0122326au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t28;
    // 0x0122326d: 890d58225d01 MOV
        batch_guest_pc = 0x0122326du;
        t29 = state.regs[1];
        if (!memory.store32(0x015d2258u, t29)) return BatchLiftStatus::invalid_memory;
    // 0x01223273: 8be5 MOV
        t30 = state.regs[5];
        state.regs[4] = t30;
    // 0x01223275: 5d POP
        batch_guest_pc = 0x01223275u;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t31a;
    // 0x01223276: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
