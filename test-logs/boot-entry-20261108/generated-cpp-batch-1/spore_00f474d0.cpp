#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00935c80(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47430(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00f474d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00f474d0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;

    // 0x00f474d0: a1408b6c01 MOV
        batch_guest_pc = 0x00f474d0u;
        if (!memory.load32(0x016c8b40u, t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00f474d5: 85c0 TEST
        t1a = state.regs[0];
        t1b = state.regs[0];
        t1r = (t1a & t1b) & 0xffffffffu;
        batch_set_logic_flags(state, t1r, 32u);
    // 0x00f474d7: 751b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00f474f4;
    // 0x00f474d9: 688074f400 PUSH
        batch_guest_pc = 0x00f474d9u;
        t3a = 0x00f47480u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00f474de: 6813749bee PUSH
        batch_guest_pc = 0x00f474deu;
        t4a = 0xee9b7413u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00f474e3: e898e79eff CALL
        if (!batch_guest_call32(memory, state, 0x00935c80u, 0x00f474e8u)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_00935c80(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x00f474e8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00f474e8: 83c408 ADD
        t6a = state.regs[4];
        t6b = 0x00000008u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x00f474eb: a3408b6c01 MOV
        batch_guest_pc = 0x00f474ebu;
        t7 = state.regs[0];
        if (!memory.store32(0x016c8b40u, t7)) return BatchLiftStatus::invalid_memory;
    // 0x00f474f0: 85c0 TEST
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x00f474f2: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00f47513;
    // 0x00f474f4: 8178105c2b0000 CMP
    L_00f474f4:
        batch_guest_pc = 0x00f474f4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t10a)) return BatchLiftStatus::invalid_memory;
        t10b = 0x00002b5cu;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x00f474fb: 7511 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00f4750e;
    // 0x00f474fd: 80781400 CMP
        batch_guest_pc = 0x00f474fdu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t12a)) return BatchLiftStatus::invalid_memory;
        t12b = 0x00000000u;
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0x000000ffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 8u);
    // 0x00f47501: 750b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00f4750e;
    // 0x00f47503: 83c018 ADD
        t14a = state.regs[0];
        t14b = 0x00000018u;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[0] = t14r;
    // 0x00f47506: a3448b6c01 MOV
        batch_guest_pc = 0x00f47506u;
        t15 = state.regs[0];
        if (!memory.store32(0x016c8b44u, t15)) return BatchLiftStatus::invalid_memory;
    // 0x00f4750b: b001 MOV
        t16 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t16 << 0u) & 0x000000ffu);
    // 0x00f4750d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00f4750e: e81dffffff CALL
    L_00f4750e:
        if (!batch_guest_call32(memory, state, 0x00f47430u, 0x00f47513u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00f47430(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00f47513u) return BatchLiftStatus::invalid_control_flow;
    // 0x00f47513: 32c0 XOR
    L_00f47513:
        t19a = state.regs[0] & 0x000000ffu;
        t19b = state.regs[0] & 0x000000ffu;
        t19r = (t19a ^ t19b) & 0x000000ffu;
        batch_set_logic_flags(state, t19r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t19r << 0u) & 0x000000ffu);
    // 0x00f47515: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
