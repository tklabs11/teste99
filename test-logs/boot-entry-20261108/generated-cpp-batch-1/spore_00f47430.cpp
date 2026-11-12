#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009289e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00935ad0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00f47430(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00f47430u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3a = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t18a = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;

    // 0x00f47430: a1408b6c01 MOV
        batch_guest_pc = 0x00f47430u;
        if (!memory.load32(0x016c8b40u, t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00f47435: 85c0 TEST
        t1a = state.regs[0];
        t1b = state.regs[0];
        t1r = (t1a & t1b) & 0xffffffffu;
        batch_set_logic_flags(state, t1r, 32u);
    // 0x00f47437: 743c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00f47475;
    // 0x00f47439: 50 PUSH
        batch_guest_pc = 0x00f47439u;
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00f4743a: e891e69eff CALL
        if (!batch_guest_call32(memory, state, 0x00935ad0u, 0x00f4743fu)) return BatchLiftStatus::invalid_memory;
        t4_call_status = spore_lift_00935ad0(memory, state);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x00f4743fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00f4743f: 83c404 ADD
        t5a = state.regs[4];
        t5b = 0x00000004u;
        t5r = static_cast<std::uint32_t>(t5a + t5b) & 0xffffffffu;
        batch_set_add_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00f47442: 84c0 TEST
        t6a = state.regs[0] & 0x000000ffu;
        t6b = state.regs[0] & 0x000000ffu;
        t6r = (t6a & t6b) & 0x000000ffu;
        batch_set_logic_flags(state, t6r, 8u);
    // 0x00f47444: 7425 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00f4746b;
    // 0x00f47446: a1408b6c01 MOV
        batch_guest_pc = 0x00f47446u;
        if (!memory.load32(0x016c8b40u, t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00f4744b: 56 PUSH
        batch_guest_pc = 0x00f4744bu;
        t9a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00f4744c: 8bf0 MOV
        t10 = state.regs[0];
        state.regs[6] = t10;
    // 0x00f4744e: 85c0 TEST
        t11a = state.regs[0];
        t11b = state.regs[0];
        t11r = (t11a & t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
    // 0x00f47450: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00f4746a;
    // 0x00f47452: 8d4818 LEA
        t13 = static_cast<std::uint32_t>(state.regs[0] + 0x00000018u);
        state.regs[1] = t13;
    // 0x00f47455: e886159eff CALL
        if (!batch_guest_call32(memory, state, 0x009289e0u, 0x00f4745au)) return BatchLiftStatus::invalid_memory;
        t14_call_status = spore_lift_009289e0(memory, state);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x00f4745au) return BatchLiftStatus::invalid_control_flow;
    // 0x00f4745a: 56 PUSH
        batch_guest_pc = 0x00f4745au;
        t15a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00f4745b: 6a00 PUSH
        batch_guest_pc = 0x00f4745bu;
        t16a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00f4745d: ff15b8c13c01 CALL
        t17_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetProcessHeap", 0x013cc1b8u, 0x00f47463u);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
        if (state.eip != 0x00f47463u) return BatchLiftStatus::invalid_control_flow;
    // 0x00f47463: 50 PUSH
        batch_guest_pc = 0x00f47463u;
        t18a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00f47464: ff15bcc13c01 CALL
        t19_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!HeapFree", 0x013cc1bcu, 0x00f4746au);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
        if (state.eip != 0x00f4746au) return BatchLiftStatus::invalid_control_flow;
    // 0x00f4746a: 5e POP
    L_00f4746a:
        batch_guest_pc = 0x00f4746au;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t20a;
    // 0x00f4746b: c705408b6c0100000000 MOV
    L_00f4746b:
        batch_guest_pc = 0x00f4746bu;
        t21 = 0x00000000u;
        if (!memory.store32(0x016c8b40u, t21)) return BatchLiftStatus::invalid_memory;
    // 0x00f47475: c3 RET
    L_00f47475:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
