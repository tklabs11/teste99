#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00ae6970(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00ae6970u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26a = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28a = 0;

    // 0x00ae6970: 53 PUSH
        batch_guest_pc = 0x00ae6970u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00ae6971: 56 PUSH
        batch_guest_pc = 0x00ae6971u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00ae6972: 8bd9 MOV
        t2 = state.regs[1];
        state.regs[3] = t2;
    // 0x00ae6974: 8b33 MOV
        batch_guest_pc = 0x00ae6974u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t3;
    // 0x00ae6976: 57 PUSH
        batch_guest_pc = 0x00ae6976u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00ae6977: 8b7b04 MOV
        batch_guest_pc = 0x00ae6977u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t5;
    // 0x00ae697a: 3bf7 CMP
        t6a = state.regs[6];
        t6b = state.regs[7];
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00ae697c: 7316 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00ae6994;
    // 0x00ae697e: 8bff MOV
        t8 = state.regs[7];
        state.regs[7] = t8;
    // 0x00ae6980: 8b0e MOV
    L_00ae6980:
        batch_guest_pc = 0x00ae6980u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t9;
    // 0x00ae6982: 85c9 TEST
        t10a = state.regs[1];
        t10b = state.regs[1];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x00ae6984: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00ae698d;
    // 0x00ae6986: 8b01 MOV
        batch_guest_pc = 0x00ae6986u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x00ae6988: 8b5004 MOV
        batch_guest_pc = 0x00ae6988u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x00ae698b: ffd2 CALL
        t14_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00ae698du);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
    // 0x00ae698d: 83c604 ADD
    L_00ae698d:
        t15a = state.regs[6];
        t15b = 0x00000004u;
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        state.regs[6] = t15r;
    // 0x00ae6990: 3bf7 CMP
        t16a = state.regs[6];
        t16b = state.regs[7];
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x00ae6992: 72ec JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00ae6980;
    // 0x00ae6994: 8b03 MOV
    L_00ae6994:
        batch_guest_pc = 0x00ae6994u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x00ae6996: 5f POP
        batch_guest_pc = 0x00ae6996u;
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t19a;
    // 0x00ae6997: 5e POP
        batch_guest_pc = 0x00ae6997u;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t20a;
    // 0x00ae6998: 5b POP
        batch_guest_pc = 0x00ae6998u;
        if (!memory.load32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t21a;
    // 0x00ae6999: 85c0 TEST
        t22a = state.regs[0];
        t22b = state.regs[0];
        t22r = (t22a & t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
    // 0x00ae699b: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00ae69aa;
    // 0x00ae699d: 8378fc00 CMP
        batch_guest_pc = 0x00ae699du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t24a)) return BatchLiftStatus::invalid_memory;
        t24b = 0x00000000u;
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x00ae69a1: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00ae69aa;
    // 0x00ae69a3: 50 PUSH
        batch_guest_pc = 0x00ae69a3u;
        t26a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00ae69a4: e8d7094600 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00ae69a9u)) return BatchLiftStatus::invalid_memory;
        t27_call_status = spore_lift_00f47380(memory, state);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x00ae69a9u) return BatchLiftStatus::invalid_control_flow;
    // 0x00ae69a9: 59 POP
        batch_guest_pc = 0x00ae69a9u;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t28a;
    // 0x00ae69aa: c3 RET
    L_00ae69aa:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
