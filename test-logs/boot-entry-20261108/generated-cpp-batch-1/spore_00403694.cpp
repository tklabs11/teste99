#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004036d4(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00403694(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00403694u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;

    // 0x00403694: 8bf0 MOV
        t0 = state.regs[0];
        state.regs[6] = t0;
    // 0x00403696: 8b542410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t1;
    // 0x0040369a: e935000000 JMP
        state.eip = 0x004036d4u;
        return spore_lift_004036d4(memory, state);
    // 0x0040369f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x004036a0: 55 PUSH
        t4a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x004036a1: 8bec MOV
        t5 = state.regs[4];
        state.regs[5] = t5;
    // 0x004036a3: 83ec0c SUB
        t6a = state.regs[4];
        t6b = 0x0000000cu;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x004036a6: 894df8 MOV
        t7 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x004036a9: 8b45f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x004036ac: 83c008 ADD
        t9a = state.regs[0];
        t9b = 0x00000008u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[0] = t9r;
    // 0x004036af: 8945fc MOV
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t10)) return BatchLiftStatus::invalid_memory;
    // 0x004036b2: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t11;
    // 0x004036b5: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t12;
    // 0x004036b8: 83c201 ADD
        t13a = state.regs[2];
        t13b = 0x00000001u;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[2] = t13r;
    // 0x004036bb: 8955f4 MOV
        t14 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x004036be: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x004036c1: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t16;
    // 0x004036c4: 83c101 ADD
        t17a = state.regs[1];
        t17b = 0x00000001u;
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        state.regs[1] = t17r;
    // 0x004036c7: 8b55fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x004036ca: 894a04 MOV
        t19 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x004036cd: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t20;
    // 0x004036d0: 8be5 MOV
        t21 = state.regs[5];
        state.regs[4] = t21;
    // 0x004036d2: 5d POP
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t22a;
    // 0x004036d3: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
