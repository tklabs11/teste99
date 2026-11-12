#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009222a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009256a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009258f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009258f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    BatchLiftStatus t22_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27 = 0;
    BatchLiftStatus t28_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t29a = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34a = 0;

    // 0x009258f0: 56 PUSH
        batch_guest_pc = 0x009258f0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009258f1: 6a00 PUSH
        batch_guest_pc = 0x009258f1u;
        t1a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009258f3: 6a00 PUSH
        batch_guest_pc = 0x009258f3u;
        t2a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009258f5: 6a00 PUSH
        batch_guest_pc = 0x009258f5u;
        t3a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009258f7: 6a00 PUSH
        batch_guest_pc = 0x009258f7u;
        t4a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009258f9: 6888e04301 PUSH
        batch_guest_pc = 0x009258f9u;
        t5a = 0x0143e088u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x009258fe: 6a58 PUSH
        batch_guest_pc = 0x009258feu;
        t6a = 0x00000058u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925900: e89b1a6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00925905u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_00f473a0(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00925905u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925905: 8bf0 MOV
        t8 = state.regs[0];
        state.regs[6] = t8;
    // 0x00925907: 83c418 ADD
        t9a = state.regs[4];
        t9b = 0x00000018u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[4] = t9r;
    // 0x0092590a: 85f6 TEST
        t10a = state.regs[6];
        t10b = state.regs[6];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x0092590c: 7449 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925957;
    // 0x0092590e: 57 PUSH
        batch_guest_pc = 0x0092590eu;
        t12a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x0092590f: c70650e04301 MOV
        batch_guest_pc = 0x0092590fu;
        t13 = 0x0143e050u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00925915: c7460400000000 MOV
        batch_guest_pc = 0x00925915u;
        t14 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0092591c: 8d7e08 LEA
        t15 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[7] = t15;
    // 0x0092591f: 6a01 PUSH
        batch_guest_pc = 0x0092591fu;
        t16a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00925921: 6a00 PUSH
        batch_guest_pc = 0x00925921u;
        t17a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00925923: 8d4e20 LEA
        t18 = static_cast<std::uint32_t>(state.regs[6] + 0x00000020u);
        state.regs[1] = t18;
    // 0x00925926: c70700000000 MOV
        batch_guest_pc = 0x00925926u;
        t19 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x0092592c: c7470400000000 MOV
        batch_guest_pc = 0x0092592cu;
        t20 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00925933: c7470800000000 MOV
        batch_guest_pc = 0x00925933u;
        t21 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x0092593a: e861c9ffff CALL
        if (!batch_guest_call32(memory, state, 0x009222a0u, 0x0092593fu)) return BatchLiftStatus::invalid_memory;
        t22_call_status = spore_lift_009222a0(memory, state);
        if (t22_call_status != BatchLiftStatus::returned) return t22_call_status;
        if (state.eip != 0x0092593fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092593f: 33c0 XOR
        t23a = state.regs[0];
        t23b = state.regs[0];
        t23r = (t23a ^ t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[0] = t23r;
    // 0x00925941: 8d4e50 LEA
        t24 = static_cast<std::uint32_t>(state.regs[6] + 0x00000050u);
        state.regs[1] = t24;
    // 0x00925944: 8701 XCHG
        if (!batch_guest_xchg32(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00925946: 6800100000 PUSH
        batch_guest_pc = 0x00925946u;
        t26a = 0x00001000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x0092594b: 8bcf MOV
        t27 = state.regs[7];
        state.regs[1] = t27;
    // 0x0092594d: e84efdffff CALL
        if (!batch_guest_call32(memory, state, 0x009256a0u, 0x00925952u)) return BatchLiftStatus::invalid_memory;
        t28_call_status = spore_lift_009256a0(memory, state);
        if (t28_call_status != BatchLiftStatus::returned) return t28_call_status;
        if (state.eip != 0x00925952u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925952: 5f POP
        batch_guest_pc = 0x00925952u;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t29a;
    // 0x00925953: 8bc6 MOV
        t30 = state.regs[6];
        state.regs[0] = t30;
    // 0x00925955: 5e POP
        batch_guest_pc = 0x00925955u;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t31a;
    // 0x00925956: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925957: 33c0 XOR
    L_00925957:
        t33a = state.regs[0];
        t33b = state.regs[0];
        t33r = (t33a ^ t33b) & 0xffffffffu;
        batch_set_logic_flags(state, t33r, 32u);
        state.regs[0] = t33r;
    // 0x00925959: 5e POP
        batch_guest_pc = 0x00925959u;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t34a;
    // 0x0092595a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
