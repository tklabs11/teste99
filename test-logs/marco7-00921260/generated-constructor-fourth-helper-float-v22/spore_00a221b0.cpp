#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00a221b0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    BatchLiftStatus t22_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;

    // 0x00a221b0: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221b1: 57 PUSH
        t1a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221b2: 8b7c240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t2;
    // 0x00a221b6: 03ff ADD
        t3a = state.regs[7];
        t3b = state.regs[7];
        t3r = static_cast<std::uint32_t>(t3a + t3b) & 0xffffffffu;
        batch_set_add_flags(state, t3a, t3b, t3r, 32u);
        state.regs[7] = t3r;
    // 0x00a221b8: 03ff ADD
        t4a = state.regs[7];
        t4b = state.regs[7];
        t4r = static_cast<std::uint32_t>(t4a + t4b) & 0xffffffffu;
        batch_set_add_flags(state, t4a, t4b, t4r, 32u);
        state.regs[7] = t4r;
    // 0x00a221ba: 8d4704 LEA
        t5 = static_cast<std::uint32_t>(state.regs[7] + 0x00000004u);
        state.regs[0] = t5;
    // 0x00a221bd: 83f80c CMP
        t6a = state.regs[0];
        t6b = 0x0000000cu;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00a221c0: 7533 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00a221f5;
    // 0x00a221c2: 8b411c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00a221c5: 85c0 TEST
        t9a = state.regs[0];
        t9b = state.regs[0];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x00a221c7: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a221d2;
    // 0x00a221c9: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x00a221cb: 89511c MOV
        t12 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00a221ce: 8bf0 MOV
        t13 = state.regs[0];
        state.regs[6] = t13;
    // 0x00a221d0: eb26 JMP
        goto L_00a221f8;
    // 0x00a221d2: 8b492c MOV
    L_00a221d2:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000002cu), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x00a221d5: 68d1000000 PUSH
        t16a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221da: 6838bb3e01 PUSH
        t17a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221df: 6a00 PUSH
        t18a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221e1: 6a00 PUSH
        t19a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221e3: 6850213f01 PUSH
        t20a = 0x013f2150u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221e8: 51 PUSH
        t21a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221e9: e8b2515200 CALL
        state.eip = 0x00a221e9u;
        return BatchLiftStatus::unsupported_dependency;
    // 0x00a221ee: 83c418 ADD
        t23a = state.regs[4];
        t23b = 0x00000018u;
        t23r = static_cast<std::uint32_t>(t23a + t23b) & 0xffffffffu;
        batch_set_add_flags(state, t23a, t23b, t23r, 32u);
        state.regs[4] = t23r;
    // 0x00a221f1: 8bf0 MOV
        t24 = state.regs[0];
        state.regs[6] = t24;
    // 0x00a221f3: eb03 JMP
        goto L_00a221f8;
    // 0x00a221f5: 8b7130 MOV
    L_00a221f5:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000030u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t26;
    // 0x00a221f8: 57 PUSH
    L_00a221f8:
        t27a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221f9: 6a00 PUSH
        t28a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221fb: 56 PUSH
        t29a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00a221fc: e83de57b00 CALL
        t30_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memset", 0x013cc478u, 0x00a22201u);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x00a22201u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a22201: 83c40c ADD
        t31a = state.regs[4];
        t31b = 0x0000000cu;
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[4] = t31r;
    // 0x00a22204: c70437ffffffff MOV
        t32 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + state.regs[6] * 1u + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x00a2220b: 5f POP
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t33a;
    // 0x00a2220c: 8bc6 MOV
        t34 = state.regs[6];
        state.regs[0] = t34;
    // 0x00a2220e: 5e POP
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t35a;
    // 0x00a2220f: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
