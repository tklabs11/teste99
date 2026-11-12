#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0045f080(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0045f080u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;

    // 0x0045f080: 55 PUSH
        batch_guest_pc = 0x0045f080u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0045f081: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0045f083: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0045f086: 894df8 MOV
        batch_guest_pc = 0x0045f086u;
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0045f089: 8b4508 MOV
        batch_guest_pc = 0x0045f089u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0045f08c: 3b450c CMP
        batch_guest_pc = 0x0045f08cu;
        t5a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t5b)) return BatchLiftStatus::invalid_memory;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x0045f08f: 7438 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0045f0c9;
    // 0x0045f091: 8b4df8 MOV
        batch_guest_pc = 0x0045f091u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x0045f094: 8b5104 MOV
        batch_guest_pc = 0x0045f094u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x0045f097: 2b550c SUB
        batch_guest_pc = 0x0045f097u;
        t9a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t9b)) return BatchLiftStatus::invalid_memory;
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
        state.regs[2] = t9r;
    // 0x0045f09a: 83c201 ADD
        t10a = state.regs[2];
        t10b = 0x00000001u;
        t10r = static_cast<std::uint32_t>(t10a + t10b) & 0xffffffffu;
        batch_set_add_flags(state, t10a, t10b, t10r, 32u);
        state.regs[2] = t10r;
    // 0x0045f09d: 52 PUSH
        batch_guest_pc = 0x0045f09du;
        t11a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x0045f09e: 8b450c MOV
        batch_guest_pc = 0x0045f09eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x0045f0a1: 50 PUSH
        batch_guest_pc = 0x0045f0a1u;
        t13a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x0045f0a2: 8b4d08 MOV
        batch_guest_pc = 0x0045f0a2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x0045f0a5: 51 PUSH
        batch_guest_pc = 0x0045f0a5u;
        t15a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x0045f0a6: ff1580c43c01 CALL
        t16_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memmove", 0x013cc480u, 0x0045f0acu);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x0045f0acu) return BatchLiftStatus::invalid_control_flow;
    // 0x0045f0ac: 83c40c ADD
        t17a = state.regs[4];
        t17b = 0x0000000cu;
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        state.regs[4] = t17r;
    // 0x0045f0af: 8b550c MOV
        batch_guest_pc = 0x0045f0afu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x0045f0b2: 2b5508 SUB
        batch_guest_pc = 0x0045f0b2u;
        t19a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t19b)) return BatchLiftStatus::invalid_memory;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
        state.regs[2] = t19r;
    // 0x0045f0b5: 8b45f8 MOV
        batch_guest_pc = 0x0045f0b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t20;
    // 0x0045f0b8: 8b4804 MOV
        batch_guest_pc = 0x0045f0b8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t21;
    // 0x0045f0bb: 2bca SUB
        t22a = state.regs[1];
        t22b = state.regs[2];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
        state.regs[1] = t22r;
    // 0x0045f0bd: 894dfc MOV
        batch_guest_pc = 0x0045f0bdu;
        t23 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t23)) return BatchLiftStatus::invalid_memory;
    // 0x0045f0c0: 8b55f8 MOV
        batch_guest_pc = 0x0045f0c0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t24;
    // 0x0045f0c3: 8b45fc MOV
        batch_guest_pc = 0x0045f0c3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x0045f0c6: 894204 MOV
        batch_guest_pc = 0x0045f0c6u;
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0045f0c9: 8b4508 MOV
    L_0045f0c9:
        batch_guest_pc = 0x0045f0c9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t27;
    // 0x0045f0cc: 8be5 MOV
        t28 = state.regs[5];
        state.regs[4] = t28;
    // 0x0045f0ce: 5d POP
        batch_guest_pc = 0x0045f0ceu;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t29a;
    // 0x0045f0cf: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
