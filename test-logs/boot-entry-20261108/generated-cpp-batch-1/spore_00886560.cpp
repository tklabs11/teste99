#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00886200(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00886560(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00886560u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16r = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19a = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;

    // 0x00886560: 56 PUSH
        batch_guest_pc = 0x00886560u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00886561: 57 PUSH
        batch_guest_pc = 0x00886561u;
        t1a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00886562: 8bf9 MOV
        t2 = state.regs[1];
        state.regs[7] = t2;
    // 0x00886564: 8b7704 MOV
        batch_guest_pc = 0x00886564u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t3;
    // 0x00886567: 8b17 MOV
        batch_guest_pc = 0x00886567u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t4;
    // 0x00886569: 8b4c240c MOV
        batch_guest_pc = 0x00886569u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x0088656d: 8bc6 MOV
        t6 = state.regs[6];
        state.regs[0] = t6;
    // 0x0088656f: 2bc2 SUB
        t7a = state.regs[0];
        t7b = state.regs[2];
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
        state.regs[0] = t7r;
    // 0x00886571: 3bc8 CMP
        t8a = state.regs[1];
        t8b = state.regs[0];
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x00886573: 7324 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00886599;
    // 0x00886575: 53 PUSH
        batch_guest_pc = 0x00886575u;
        t10a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00886576: 8d1c0a LEA
        t11 = static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0x00000000u);
        state.regs[3] = t11;
    // 0x00886579: 3bde CMP
        t12a = state.regs[3];
        t12b = state.regs[6];
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x0088657b: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00886593;
    // 0x0088657d: 8bc6 MOV
        t14 = state.regs[6];
        state.regs[0] = t14;
    // 0x0088657f: 2bc6 SUB
        t15a = state.regs[0];
        t15b = state.regs[6];
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
        state.regs[0] = t15r;
    // 0x00886581: 40 INC
        t16a = state.regs[0];
        t16r = static_cast<std::uint32_t>(t16a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t16a, t16r, 32u);
        state.regs[0] = t16r;
    // 0x00886582: 50 PUSH
        batch_guest_pc = 0x00886582u;
        t17a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00886583: 56 PUSH
        batch_guest_pc = 0x00886583u;
        t18a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00886584: 53 PUSH
        batch_guest_pc = 0x00886584u;
        t19a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00886585: ff1580c43c01 CALL
        t20_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memmove", 0x013cc480u, 0x0088658bu);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x0088658bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0088658b: 2bde SUB
        t21a = state.regs[3];
        t21b = state.regs[6];
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0xffffffffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 32u);
        state.regs[3] = t21r;
    // 0x0088658d: 83c40c ADD
        t22a = state.regs[4];
        t22b = 0x0000000cu;
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[4] = t22r;
    // 0x00886590: 015f04 ADD
        batch_guest_pc = 0x00886590u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t23a)) return BatchLiftStatus::invalid_memory;
        t23b = state.regs[3];
        t23r = static_cast<std::uint32_t>(t23a + t23b) & 0xffffffffu;
        batch_set_add_flags(state, t23a, t23b, t23r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t23r)) return BatchLiftStatus::invalid_memory;
    // 0x00886593: 5b POP
    L_00886593:
        batch_guest_pc = 0x00886593u;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t24a;
    // 0x00886594: 5f POP
    L_00886594:
        batch_guest_pc = 0x00886594u;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t25a;
    // 0x00886595: 5e POP
        batch_guest_pc = 0x00886595u;
        if (!memory.load32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t26a;
    // 0x00886596: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00886599: 76f9 JBE
    L_00886599:
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00886594;
    // 0x0088659b: 2bc8 SUB
        t29a = state.regs[1];
        t29b = state.regs[0];
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
        state.regs[1] = t29r;
    // 0x0088659d: 6a00 PUSH
        batch_guest_pc = 0x0088659du;
        t30a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x0088659f: 51 PUSH
        batch_guest_pc = 0x0088659fu;
        t31a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x008865a0: 8bcf MOV
        t32 = state.regs[7];
        state.regs[1] = t32;
    // 0x008865a2: e859fcffff CALL
        if (!batch_guest_call32(memory, state, 0x00886200u, 0x008865a7u)) return BatchLiftStatus::invalid_memory;
        t33_call_status = spore_lift_00886200(memory, state);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
        if (state.eip != 0x008865a7u) return BatchLiftStatus::invalid_control_flow;
    // 0x008865a7: 5f POP
        batch_guest_pc = 0x008865a7u;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t34a;
    // 0x008865a8: 5e POP
        batch_guest_pc = 0x008865a8u;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t35a;
    // 0x008865a9: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
