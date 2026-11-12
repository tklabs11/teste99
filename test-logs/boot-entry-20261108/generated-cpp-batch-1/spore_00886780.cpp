#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00885fa0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00886780(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00886780u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;

    // 0x00886780: 53 PUSH
        batch_guest_pc = 0x00886780u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00886781: 55 PUSH
        batch_guest_pc = 0x00886781u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00886782: 56 PUSH
        batch_guest_pc = 0x00886782u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00886783: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x00886785: 33c0 XOR
        t4a = state.regs[0];
        t4b = state.regs[0];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[0] = t4r;
    // 0x00886787: 8906 MOV
        batch_guest_pc = 0x00886787u;
        t5 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x00886789: 894604 MOV
        batch_guest_pc = 0x00886789u;
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x0088678c: 894608 MOV
        batch_guest_pc = 0x0088678cu;
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x0088678f: 8b442410 MOV
        batch_guest_pc = 0x0088678fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00886793: 8b4810 MOV
        batch_guest_pc = 0x00886793u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t9;
    // 0x00886796: 894e10 MOV
        batch_guest_pc = 0x00886796u;
        t10 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00886799: 8b5804 MOV
        batch_guest_pc = 0x00886799u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t11;
    // 0x0088679c: 8b28 MOV
        batch_guest_pc = 0x0088679cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t12;
    // 0x0088679e: 895c2410 MOV
        batch_guest_pc = 0x0088679eu;
        t13 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x008867a2: 2bdd SUB
        t14a = state.regs[3];
        t14b = state.regs[5];
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
        state.regs[3] = t14r;
    // 0x008867a4: 57 PUSH
        batch_guest_pc = 0x008867a4u;
        t15a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x008867a5: 8d5301 LEA
        t16 = static_cast<std::uint32_t>(state.regs[3] + 0x00000001u);
        state.regs[2] = t16;
    // 0x008867a8: 52 PUSH
        batch_guest_pc = 0x008867a8u;
        t17a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x008867a9: 8bce MOV
        t18 = state.regs[6];
        state.regs[1] = t18;
    // 0x008867ab: e8f0f7ffff CALL
        if (!batch_guest_call32(memory, state, 0x00885fa0u, 0x008867b0u)) return BatchLiftStatus::invalid_memory;
        t19_call_status = spore_lift_00885fa0(memory, state);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
        if (state.eip != 0x008867b0u) return BatchLiftStatus::invalid_control_flow;
    // 0x008867b0: 8b3e MOV
        batch_guest_pc = 0x008867b0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t20;
    // 0x008867b2: 53 PUSH
        batch_guest_pc = 0x008867b2u;
        t21a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x008867b3: 55 PUSH
        batch_guest_pc = 0x008867b3u;
        t22a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x008867b4: 57 PUSH
        batch_guest_pc = 0x008867b4u;
        t23a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x008867b5: e88a9f9500 CALL
        t24_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x008867bau);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x008867bau) return BatchLiftStatus::invalid_control_flow;
    // 0x008867ba: 8b442420 MOV
        batch_guest_pc = 0x008867bau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x008867be: 2bfd SUB
        t26a = state.regs[7];
        t26b = state.regs[5];
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0xffffffffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 32u);
        state.regs[7] = t26r;
    // 0x008867c0: 03f8 ADD
        t27a = state.regs[7];
        t27b = state.regs[0];
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        state.regs[7] = t27r;
    // 0x008867c2: 83c40c ADD
        t28a = state.regs[4];
        t28b = 0x0000000cu;
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[4] = t28r;
    // 0x008867c5: 897e04 MOV
        batch_guest_pc = 0x008867c5u;
        t29 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x008867c8: c60700 MOV
        batch_guest_pc = 0x008867c8u;
        t30 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x008867cb: 5f POP
        batch_guest_pc = 0x008867cbu;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t31a;
    // 0x008867cc: 8bc6 MOV
        t32 = state.regs[6];
        state.regs[0] = t32;
    // 0x008867ce: 5e POP
        batch_guest_pc = 0x008867ceu;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t33a;
    // 0x008867cf: 5d POP
        batch_guest_pc = 0x008867cfu;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t34a;
    // 0x008867d0: 5b POP
        batch_guest_pc = 0x008867d0u;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t35a;
    // 0x008867d1: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
