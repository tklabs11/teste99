#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921260(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00a2a210(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;

    // 0x00a2a210: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a212: 6858822101 PUSH
        t1a = 0x01218258u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a217: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00a2a21d: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a21e: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a225: 83ec28 SUB
        t5a = state.regs[4];
        t5b = 0x00000028u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00a2a228: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a229: 57 PUSH
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a22a: 6a00 PUSH
        t8a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a22c: 6a04 PUSH
        t9a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a22e: 8bf1 MOV
        t10 = state.regs[1];
        state.regs[6] = t10;
    // 0x00a2a230: 6a0c PUSH
        t11a = 0x0000000cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a232: 6860090000 PUSH
        t12a = 0x00000960u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a237: 8dbe5c030000 LEA
        t13 = static_cast<std::uint32_t>(state.regs[6] + 0x0000035cu);
        state.regs[7] = t13;
    // 0x00a2a23d: 57 PUSH
        t14a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a23e: 8d4c242c LEA
        t15 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[1] = t15;
    // 0x00a2a242: 8974241c MOV
        t16 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a246: c744242c00000000 MOV
        t17 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a24e: e80d70efff CALL
        if (!batch_guest_call32(memory, state, 0x00921260u, 0x00a2a253u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00921260(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00a2a253u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a2a253: 897c2420 MOV
        t19 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a257: 8d4634 LEA
        t20 = static_cast<std::uint32_t>(state.regs[6] + 0x00000034u);
        state.regs[0] = t20;
    // 0x00a2a25a: 81c760090000 ADD
        t21a = state.regs[7];
        t21b = 0x00000960u;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[7] = t21r;
    // 0x00a2a260: 68c9000000 PUSH
        t22a = 0x000000c9u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a265: 897c2428 MOV
        t23 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a269: c744242c0c000000 MOV
        t24 = 0x0000000cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a271: 89442430 MOV
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t25)) return BatchLiftStatus::invalid_memory;
    state.eip = 0x00a2a275u;
    return BatchLiftStatus::unsupported_dependency;
}
