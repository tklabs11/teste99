#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401923(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00401899(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00401899u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13a = 0, t13c = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0, t20c = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0, t27c = 0, t27r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0;

    // 0x00401899: 52 PUSH
        t0a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0040189a: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0040189b: e983000000 JMP
        state.eip = 0x00401923u;
        return spore_lift_00401923(memory, state);
    // 0x004018a0: 55 PUSH
        t3a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x004018a1: 8bec MOV
        t4 = state.regs[4];
        state.regs[5] = t4;
    // 0x004018a3: 51 PUSH
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x004018a4: c745fc00000000 MOV
        t6 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t6)) return BatchLiftStatus::invalid_memory;
    // 0x004018ab: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x004018ae: 25ffffff3f AND
        t8a = state.regs[0];
        t8b = 0x3fffffffu;
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[0] = t8r;
    // 0x004018b3: 0d00000040 OR
        t9a = state.regs[0];
        t9b = 0x40000000u;
        t9r = (t9a | t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
        state.regs[0] = t9r;
    // 0x004018b8: 8945fc MOV
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t10)) return BatchLiftStatus::invalid_memory;
    // 0x004018bb: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t11;
    // 0x004018be: 81e1ff000000 AND
        t12a = state.regs[1];
        t12b = 0x000000ffu;
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
        state.regs[1] = t12r;
    // 0x004018c4: c1e110 SHL
        t13a = state.regs[1];
        t13c = 16u;
        if (t13c != 0u) {
        t13r = static_cast<std::uint32_t>(t13a << t13c) & 0xffffffffu;
        batch_set_shl_flags(state, t13a, t13c, t13r, 32u);
            state.regs[1] = t13r;
        }
    // 0x004018c7: 8b55fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x004018ca: 81e2ffff00ff AND
        t15a = state.regs[2];
        t15b = 0xff00ffffu;
        t15r = (t15a & t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
        state.regs[2] = t15r;
    // 0x004018d0: 0bd1 OR
        t16a = state.regs[2];
        t16b = state.regs[1];
        t16r = (t16a | t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[2] = t16r;
    // 0x004018d2: 8955fc MOV
        t17 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x004018d5: 8b450c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x004018d8: 83e01f AND
        t19a = state.regs[0];
        t19b = 0x0000001fu;
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[0] = t19r;
    // 0x004018db: c1e018 SHL
        t20a = state.regs[0];
        t20c = 24u;
        if (t20c != 0u) {
        t20r = static_cast<std::uint32_t>(t20a << t20c) & 0xffffffffu;
        batch_set_shl_flags(state, t20a, t20c, t20r, 32u);
            state.regs[0] = t20r;
        }
    // 0x004018de: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t21;
    // 0x004018e1: 81e1ffffffe0 AND
        t22a = state.regs[1];
        t22b = 0xe0ffffffu;
        t22r = (t22a & t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
        state.regs[1] = t22r;
    // 0x004018e7: 0bc8 OR
        t23a = state.regs[1];
        t23b = state.regs[0];
        t23r = (t23a | t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[1] = t23r;
    // 0x004018e9: 894dfc MOV
        t24 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t24)) return BatchLiftStatus::invalid_memory;
    // 0x004018ec: 8b5510 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t25;
    // 0x004018ef: 81e2ff000000 AND
        t26a = state.regs[2];
        t26b = 0x000000ffu;
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[2] = t26r;
    // 0x004018f5: c1e208 SHL
        t27a = state.regs[2];
        t27c = 8u;
        if (t27c != 0u) {
        t27r = static_cast<std::uint32_t>(t27a << t27c) & 0xffffffffu;
        batch_set_shl_flags(state, t27a, t27c, t27r, 32u);
            state.regs[2] = t27r;
        }
    // 0x004018f8: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x004018fb: 25ff00ffff AND
        t29a = state.regs[0];
        t29b = 0xffff00ffu;
        t29r = (t29a & t29b) & 0xffffffffu;
        batch_set_logic_flags(state, t29r, 32u);
        state.regs[0] = t29r;
    // 0x00401900: 0bc2 OR
        t30a = state.regs[0];
        t30b = state.regs[2];
        t30r = (t30a | t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
        state.regs[0] = t30r;
    // 0x00401902: 8945fc MOV
        t31 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t31)) return BatchLiftStatus::invalid_memory;
    // 0x00401905: 8b4d14 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000014u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t32;
    // 0x00401908: 81e1ff000000 AND
        t33a = state.regs[1];
        t33b = 0x000000ffu;
        t33r = (t33a & t33b) & 0xffffffffu;
        batch_set_logic_flags(state, t33r, 32u);
        state.regs[1] = t33r;
    // 0x0040190e: 8b55fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x00401911: 81e200ffffff AND
        t35a = state.regs[2];
        t35b = 0xffffff00u;
        t35r = (t35a & t35b) & 0xffffffffu;
        batch_set_logic_flags(state, t35r, 32u);
        state.regs[2] = t35r;
    // 0x00401917: 0bd1 OR
        t36a = state.regs[2];
        t36b = state.regs[1];
        t36r = (t36a | t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
        state.regs[2] = t36r;
    // 0x00401919: 8955fc MOV
        t37 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t37)) return BatchLiftStatus::invalid_memory;
    // 0x0040191c: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t38;
    // 0x0040191f: 8be5 MOV
        t39 = state.regs[5];
        state.regs[4] = t39;
    // 0x00401921: 5d POP
        if (!memory.load32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t40a;
    // 0x00401922: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
