#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00925220(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925420(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925420u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    BatchLiftStatus t28_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;

    // 0x00925420: 56 PUSH
        batch_guest_pc = 0x00925420u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925421: 57 PUSH
        batch_guest_pc = 0x00925421u;
        t1a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00925422: 8d7120 LEA
        t2 = static_cast<std::uint32_t>(state.regs[1] + 0x00000020u);
        state.regs[6] = t2;
    // 0x00925425: 68fcdf4301 PUSH
        batch_guest_pc = 0x00925425u;
        t3a = 0x0143dffcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0092542a: 8bce MOV
        t4 = state.regs[6];
        state.regs[1] = t4;
    // 0x0092542c: e87fcdffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00925431u)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_009221b0(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x00925431u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925431: 6a00 PUSH
        batch_guest_pc = 0x00925431u;
        t6a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925433: 6a00 PUSH
        batch_guest_pc = 0x00925433u;
        t7a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00925435: 6a00 PUSH
        batch_guest_pc = 0x00925435u;
        t8a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00925437: 6a00 PUSH
        batch_guest_pc = 0x00925437u;
        t9a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00925439: 6874e04301 PUSH
        batch_guest_pc = 0x00925439u;
        t10a = 0x0143e074u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0092543e: 6a24 PUSH
        batch_guest_pc = 0x0092543eu;
        t11a = 0x00000024u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00925440: e85b1f6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00925445u)) return BatchLiftStatus::invalid_memory;
        t12_call_status = spore_lift_00f473a0(memory, state);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00925445u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925445: 83c418 ADD
        t13a = state.regs[4];
        t13b = 0x00000018u;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[4] = t13r;
    // 0x00925448: 85c0 TEST
        t14a = state.regs[0];
        t14b = state.regs[0];
        t14r = (t14a & t14b) & 0xffffffffu;
        batch_set_logic_flags(state, t14r, 32u);
    // 0x0092544a: 742b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925477;
    // 0x0092544c: 8b4c2418 MOV
        batch_guest_pc = 0x0092544cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t16;
    // 0x00925450: 8b542414 MOV
        batch_guest_pc = 0x00925450u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x00925454: 51 PUSH
        batch_guest_pc = 0x00925454u;
        t18a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00925455: 8b4c2414 MOV
        batch_guest_pc = 0x00925455u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x00925459: 52 PUSH
        batch_guest_pc = 0x00925459u;
        t20a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x0092545a: 8b542414 MOV
        batch_guest_pc = 0x0092545au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x0092545e: 51 PUSH
        batch_guest_pc = 0x0092545eu;
        t22a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x0092545f: 52 PUSH
        batch_guest_pc = 0x0092545fu;
        t23a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00925460: 8bc8 MOV
        t24 = state.regs[0];
        state.regs[1] = t24;
    // 0x00925462: e8b9fdffff CALL
        if (!batch_guest_call32(memory, state, 0x00925220u, 0x00925467u)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_00925220(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00925467u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925467: 8bce MOV
        t26 = state.regs[6];
        state.regs[1] = t26;
    // 0x00925469: 8bf8 MOV
        t27 = state.regs[0];
        state.regs[7] = t27;
    // 0x0092546b: e800ceffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00925470u)) return BatchLiftStatus::invalid_memory;
        t28_call_status = spore_lift_00922270(memory, state);
        if (t28_call_status != BatchLiftStatus::returned) return t28_call_status;
        if (state.eip != 0x00925470u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925470: 8bc7 MOV
        t29 = state.regs[7];
        state.regs[0] = t29;
    // 0x00925472: 5f POP
        batch_guest_pc = 0x00925472u;
        if (!memory.load32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t30a;
    // 0x00925473: 5e POP
        batch_guest_pc = 0x00925473u;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t31a;
    // 0x00925474: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925477: 8bce MOV
    L_00925477:
        t33 = state.regs[6];
        state.regs[1] = t33;
    // 0x00925479: 33ff XOR
        t34a = state.regs[7];
        t34b = state.regs[7];
        t34r = (t34a ^ t34b) & 0xffffffffu;
        batch_set_logic_flags(state, t34r, 32u);
        state.regs[7] = t34r;
    // 0x0092547b: e8f0cdffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00925480u)) return BatchLiftStatus::invalid_memory;
        t35_call_status = spore_lift_00922270(memory, state);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x00925480u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925480: 8bc7 MOV
        t36 = state.regs[7];
        state.regs[0] = t36;
    // 0x00925482: 5f POP
        batch_guest_pc = 0x00925482u;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t37a;
    // 0x00925483: 5e POP
        batch_guest_pc = 0x00925483u;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t38a;
    // 0x00925484: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
