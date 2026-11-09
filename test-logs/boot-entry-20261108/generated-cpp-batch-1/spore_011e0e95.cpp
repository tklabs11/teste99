#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e0e95(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e0e95u);
    std::uint32_t t0a = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    BatchLiftStatus t9_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0;

    // 0x011e0e95: 6894131e01 PUSH
        t0a = 0x011e1394u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0e9a: e850f9ffff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x011e0e9fu)) return BatchLiftStatus::invalid_memory;
        t1_call_status = spore_lift_011e07ef(memory, state);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
        if (state.eip != 0x011e0e9fu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0e9f: a144266f01 MOV
        if (!memory.load32(0x016f2644u, t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x011e0ea4: c7042430266f01 MOV
        t3 = 0x016f2630u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x011e0eab: ff3540266f01 PUSH
        if (!memory.load32(0x016f2640u, t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0eb1: a330266f01 MOV
        t5 = state.regs[0];
        if (!memory.store32(0x016f2630u, t5)) return BatchLiftStatus::invalid_memory;
    // 0x011e0eb6: 6820266f01 PUSH
        t6a = 0x016f2620u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ebb: 6824266f01 PUSH
        t7a = 0x016f2624u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ec0: 681c266f01 PUSH
        t8a = 0x016f261cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ec5: ff1538c33c01 CALL
        t9_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!__getmainargs", 0x013cc338u, 0x011e0ecbu);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
        if (state.eip != 0x011e0ecbu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0ecb: 83c414 ADD
        t10a = state.regs[4];
        t10b = 0x00000014u;
        t10r = static_cast<std::uint32_t>(t10a + t10b) & 0xffffffffu;
        batch_set_add_flags(state, t10a, t10b, t10r, 32u);
        state.regs[4] = t10r;
    // 0x011e0ece: a32c266f01 MOV
        t11 = state.regs[0];
        if (!memory.store32(0x016f262cu, t11)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ed3: 85c0 TEST
        t12a = state.regs[0];
        t12b = state.regs[0];
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
    // 0x011e0ed5: 7d08 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_011e0edf;
    // 0x011e0ed7: 6a08 PUSH
        t14a = 0x00000008u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ed9: e88a040000 CALL
        t15_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_amsg_exit", 0x013cc33cu, 0x011e0edeu);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x011e0edeu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0ede: 59 POP
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t16a;
    // 0x011e0edf: c3 RET
    L_011e0edf:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
