#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0068f7c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_006900b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x006900b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;

    // 0x006900b0: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x006900b2: 6858cf2001 PUSH
        t1a = 0x0120cf58u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x006900b7: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x006900bd: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x006900be: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x006900c5: 51 PUSH
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x006900c6: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x006900c7: 8bf1 MOV
        t7 = state.regs[1];
        state.regs[6] = t7;
    // 0x006900c9: 57 PUSH
        t8a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x006900ca: 8d7e08 LEA
        t9 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[7] = t9;
    // 0x006900cd: 6850374001 PUSH
        t10a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x006900d2: 8bcf MOV
        t11 = state.regs[7];
        state.regs[1] = t11;
    // 0x006900d4: 897c240c MOV
        t12 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x006900d8: e8d3202900 CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x006900ddu)) return BatchLiftStatus::invalid_memory;
        t13_call_status = spore_lift_009221b0(memory, state);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x006900ddu) return BatchLiftStatus::invalid_control_flow;
    // 0x006900dd: 8b44241c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x006900e1: 50 PUSH
        t15a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x006900e2: 8d4c240c LEA
        t16 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t16;
    // 0x006900e6: 51 PUSH
        t17a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x006900e7: 8bce MOV
        t18 = state.regs[6];
        state.regs[1] = t18;
    // 0x006900e9: c744241c00000000 MOV
        t19 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t19)) return BatchLiftStatus::invalid_memory;
    // 0x006900f1: e8caf6ffff CALL
        if (!batch_guest_call32(memory, state, 0x0068f7c0u, 0x006900f6u)) return BatchLiftStatus::invalid_memory;
        t20_call_status = spore_lift_0068f7c0(memory, state);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x006900f6u) return BatchLiftStatus::invalid_control_flow;
    // 0x006900f6: 8bcf MOV
        t21 = state.regs[7];
        state.regs[1] = t21;
    // 0x006900f8: c7442414ffffffff MOV
        t22 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00690100: e86b212900 CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00690105u)) return BatchLiftStatus::invalid_memory;
        t23_call_status = spore_lift_00922270(memory, state);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x00690105u) return BatchLiftStatus::invalid_control_flow;
    // 0x00690105: 8b4c240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x00690109: 5f POP
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t25a;
    // 0x0069010a: 5e POP
        if (!memory.load32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t26a;
    // 0x0069010b: 64890d00000000 MOV
        t27 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00690112: 83c410 ADD
        t28a = state.regs[4];
        t28b = 0x00000010u;
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[4] = t28r;
    // 0x00690115: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
