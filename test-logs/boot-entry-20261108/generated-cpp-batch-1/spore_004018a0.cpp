#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_004018a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004018a0u);
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
    std::uint32_t t24a = 0, t24c = 0, t24r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0;

    // 0x004018a0: 55 PUSH
        batch_guest_pc = 0x004018a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x004018a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x004018a3: 51 PUSH
        batch_guest_pc = 0x004018a3u;
        t2a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x004018a4: c745fc00000000 MOV
        batch_guest_pc = 0x004018a4u;
        t3 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x004018ab: 8b45fc MOV
        batch_guest_pc = 0x004018abu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x004018ae: 25ffffff3f AND
        t5a = state.regs[0];
        t5b = 0x3fffffffu;
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        state.regs[0] = t5r;
    // 0x004018b3: 0d00000040 OR
        t6a = state.regs[0];
        t6b = 0x40000000u;
        t6r = (t6a | t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[0] = t6r;
    // 0x004018b8: 8945fc MOV
        batch_guest_pc = 0x004018b8u;
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x004018bb: 8b4d08 MOV
        batch_guest_pc = 0x004018bbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t8;
    // 0x004018be: 81e1ff000000 AND
        t9a = state.regs[1];
        t9b = 0x000000ffu;
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
        state.regs[1] = t9r;
    // 0x004018c4: c1e110 SHL
        t10a = state.regs[1];
        t10c = 16u;
        if (t10c != 0u) {
        t10r = static_cast<std::uint32_t>(t10a << t10c) & 0xffffffffu;
        batch_set_shl_flags(state, t10a, t10c, t10r, 32u);
            state.regs[1] = t10r;
        }
    // 0x004018c7: 8b55fc MOV
        batch_guest_pc = 0x004018c7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x004018ca: 81e2ffff00ff AND
        t12a = state.regs[2];
        t12b = 0xff00ffffu;
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
        state.regs[2] = t12r;
    // 0x004018d0: 0bd1 OR
        t13a = state.regs[2];
        t13b = state.regs[1];
        t13r = (t13a | t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
        state.regs[2] = t13r;
    // 0x004018d2: 8955fc MOV
        batch_guest_pc = 0x004018d2u;
        t14 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x004018d5: 8b450c MOV
        batch_guest_pc = 0x004018d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x004018d8: 83e01f AND
        t16a = state.regs[0];
        t16b = 0x0000001fu;
        t16r = (t16a & t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[0] = t16r;
    // 0x004018db: c1e018 SHL
        t17a = state.regs[0];
        t17c = 24u;
        if (t17c != 0u) {
        t17r = static_cast<std::uint32_t>(t17a << t17c) & 0xffffffffu;
        batch_set_shl_flags(state, t17a, t17c, t17r, 32u);
            state.regs[0] = t17r;
        }
    // 0x004018de: 8b4dfc MOV
        batch_guest_pc = 0x004018deu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t18;
    // 0x004018e1: 81e1ffffffe0 AND
        t19a = state.regs[1];
        t19b = 0xe0ffffffu;
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[1] = t19r;
    // 0x004018e7: 0bc8 OR
        t20a = state.regs[1];
        t20b = state.regs[0];
        t20r = (t20a | t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
        state.regs[1] = t20r;
    // 0x004018e9: 894dfc MOV
        batch_guest_pc = 0x004018e9u;
        t21 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x004018ec: 8b5510 MOV
        batch_guest_pc = 0x004018ecu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x004018ef: 81e2ff000000 AND
        t23a = state.regs[2];
        t23b = 0x000000ffu;
        t23r = (t23a & t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[2] = t23r;
    // 0x004018f5: c1e208 SHL
        t24a = state.regs[2];
        t24c = 8u;
        if (t24c != 0u) {
        t24r = static_cast<std::uint32_t>(t24a << t24c) & 0xffffffffu;
        batch_set_shl_flags(state, t24a, t24c, t24r, 32u);
            state.regs[2] = t24r;
        }
    // 0x004018f8: 8b45fc MOV
        batch_guest_pc = 0x004018f8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x004018fb: 25ff00ffff AND
        t26a = state.regs[0];
        t26b = 0xffff00ffu;
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[0] = t26r;
    // 0x00401900: 0bc2 OR
        t27a = state.regs[0];
        t27b = state.regs[2];
        t27r = (t27a | t27b) & 0xffffffffu;
        batch_set_logic_flags(state, t27r, 32u);
        state.regs[0] = t27r;
    // 0x00401902: 8945fc MOV
        batch_guest_pc = 0x00401902u;
        t28 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00401905: 8b4d14 MOV
        batch_guest_pc = 0x00401905u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000014u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t29;
    // 0x00401908: 81e1ff000000 AND
        t30a = state.regs[1];
        t30b = 0x000000ffu;
        t30r = (t30a & t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
        state.regs[1] = t30r;
    // 0x0040190e: 8b55fc MOV
        batch_guest_pc = 0x0040190eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t31;
    // 0x00401911: 81e200ffffff AND
        t32a = state.regs[2];
        t32b = 0xffffff00u;
        t32r = (t32a & t32b) & 0xffffffffu;
        batch_set_logic_flags(state, t32r, 32u);
        state.regs[2] = t32r;
    // 0x00401917: 0bd1 OR
        t33a = state.regs[2];
        t33b = state.regs[1];
        t33r = (t33a | t33b) & 0xffffffffu;
        batch_set_logic_flags(state, t33r, 32u);
        state.regs[2] = t33r;
    // 0x00401919: 8955fc MOV
        batch_guest_pc = 0x00401919u;
        t34 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t34)) return BatchLiftStatus::invalid_memory;
    // 0x0040191c: 8b45fc MOV
        batch_guest_pc = 0x0040191cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t35;
    // 0x0040191f: 8be5 MOV
        t36 = state.regs[5];
        state.regs[4] = t36;
    // 0x00401921: 5d POP
        batch_guest_pc = 0x00401921u;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t37a;
    // 0x00401922: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
