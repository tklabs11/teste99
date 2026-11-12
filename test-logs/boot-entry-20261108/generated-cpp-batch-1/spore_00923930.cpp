#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923930(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923930u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t32 = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t38a = 0;

    // 0x00923930: 53 PUSH
        batch_guest_pc = 0x00923930u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923931: 55 PUSH
        batch_guest_pc = 0x00923931u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923932: 56 PUSH
        batch_guest_pc = 0x00923932u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00923933: 57 PUSH
        batch_guest_pc = 0x00923933u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00923934: 8bf9 MOV
        t4 = state.regs[1];
        state.regs[7] = t4;
    // 0x00923936: 8d6f34 LEA
        t5 = static_cast<std::uint32_t>(state.regs[7] + 0x00000034u);
        state.regs[5] = t5;
    // 0x00923939: 6878dc4301 PUSH
        batch_guest_pc = 0x00923939u;
        t6a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0092393e: 8bcd MOV
        t7 = state.regs[5];
        state.regs[1] = t7;
    // 0x00923940: e86be8ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00923945u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_009221b0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00923945u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923945: 8b7714 MOV
        batch_guest_pc = 0x00923945u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000014u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t9;
    // 0x00923948: 8b7f18 MOV
        batch_guest_pc = 0x00923948u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t10;
    // 0x0092394b: 3bf7 CMP
        t11a = state.regs[6];
        t11b = state.regs[7];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x0092394d: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923968;
    // 0x0092394f: 8b5c2414 MOV
        batch_guest_pc = 0x0092394fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t13;
    // 0x00923953: 8b0e MOV
    L_00923953:
        batch_guest_pc = 0x00923953u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x00923955: 8b01 MOV
        batch_guest_pc = 0x00923955u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x00923957: 8b5014 MOV
        batch_guest_pc = 0x00923957u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t16;
    // 0x0092395a: 53 PUSH
        batch_guest_pc = 0x0092395au;
        t17a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x0092395b: ffd2 CALL
        t18_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092395du);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
    // 0x0092395d: 84c0 TEST
        t19a = state.regs[0] & 0x000000ffu;
        t19b = state.regs[0] & 0x000000ffu;
        t19r = (t19a & t19b) & 0x000000ffu;
        batch_set_logic_flags(state, t19r, 8u);
    // 0x0092395f: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923978;
    // 0x00923961: 83c604 ADD
        t21a = state.regs[6];
        t21b = 0x00000004u;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[6] = t21r;
    // 0x00923964: 3bf7 CMP
        t22a = state.regs[6];
        t22b = state.regs[7];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x00923966: 75eb JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923953;
    // 0x00923968: 8bcd MOV
    L_00923968:
        t24 = state.regs[5];
        state.regs[1] = t24;
    // 0x0092396a: e801e9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x0092396fu)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_00922270(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x0092396fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092396f: 5f POP
        batch_guest_pc = 0x0092396fu;
        if (!memory.load32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t26a;
    // 0x00923970: 5e POP
        batch_guest_pc = 0x00923970u;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t27a;
    // 0x00923971: 5d POP
        batch_guest_pc = 0x00923971u;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t28a;
    // 0x00923972: b001 MOV
        t29 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t29 << 0u) & 0x000000ffu);
    // 0x00923974: 5b POP
        batch_guest_pc = 0x00923974u;
        if (!memory.load32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t30a;
    // 0x00923975: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00923978: 8bcd MOV
    L_00923978:
        t32 = state.regs[5];
        state.regs[1] = t32;
    // 0x0092397a: e8f1e8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x0092397fu)) return BatchLiftStatus::invalid_memory;
        t33_call_status = spore_lift_00922270(memory, state);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
        if (state.eip != 0x0092397fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092397f: 5f POP
        batch_guest_pc = 0x0092397fu;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t34a;
    // 0x00923980: 5e POP
        batch_guest_pc = 0x00923980u;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t35a;
    // 0x00923981: 5d POP
        batch_guest_pc = 0x00923981u;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t36a;
    // 0x00923982: 32c0 XOR
        t37a = state.regs[0] & 0x000000ffu;
        t37b = state.regs[0] & 0x000000ffu;
        t37r = (t37a ^ t37b) & 0x000000ffu;
        batch_set_logic_flags(state, t37r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t37r << 0u) & 0x000000ffu);
    // 0x00923984: 5b POP
        batch_guest_pc = 0x00923984u;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t38a;
    // 0x00923985: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
