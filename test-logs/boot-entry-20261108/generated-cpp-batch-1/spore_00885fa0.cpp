#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00885fa0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00885fa0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0;

    // 0x00885fa0: 56 PUSH
        batch_guest_pc = 0x00885fa0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00885fa1: 57 PUSH
        batch_guest_pc = 0x00885fa1u;
        t1a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00885fa2: 8b7c240c MOV
        batch_guest_pc = 0x00885fa2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t2;
    // 0x00885fa6: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x00885fa8: 83ff01 CMP
        t4a = state.regs[7];
        t4b = 0x00000001u;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
    // 0x00885fab: 762b JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00885fd8;
    // 0x00885fad: 68d1000000 PUSH
        batch_guest_pc = 0x00885fadu;
        t6a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00885fb2: 6838bb3e01 PUSH
        batch_guest_pc = 0x00885fb2u;
        t7a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00885fb7: 6a00 PUSH
        batch_guest_pc = 0x00885fb7u;
        t8a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00885fb9: 6a00 PUSH
        batch_guest_pc = 0x00885fb9u;
        t9a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00885fbb: 6850213f01 PUSH
        batch_guest_pc = 0x00885fbbu;
        t10a = 0x013f2150u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00885fc0: 57 PUSH
        batch_guest_pc = 0x00885fc0u;
        t11a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00885fc1: e8da136c00 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00885fc6u)) return BatchLiftStatus::invalid_memory;
        t12_call_status = spore_lift_00f473a0(memory, state);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00885fc6u) return BatchLiftStatus::invalid_control_flow;
    // 0x00885fc6: 83c418 ADD
        t13a = state.regs[4];
        t13b = 0x00000018u;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[4] = t13r;
    // 0x00885fc9: 8906 MOV
        batch_guest_pc = 0x00885fc9u;
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00885fcb: 894604 MOV
        batch_guest_pc = 0x00885fcbu;
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00885fce: 03c7 ADD
        t16a = state.regs[0];
        t16b = state.regs[7];
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[0] = t16r;
    // 0x00885fd0: 5f POP
        batch_guest_pc = 0x00885fd0u;
        if (!memory.load32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t17a;
    // 0x00885fd1: 894608 MOV
        batch_guest_pc = 0x00885fd1u;
        t18 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00885fd4: 5e POP
        batch_guest_pc = 0x00885fd4u;
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t19a;
    // 0x00885fd5: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00885fd8: 5f POP
    L_00885fd8:
        batch_guest_pc = 0x00885fd8u;
        if (!memory.load32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t21a;
    // 0x00885fd9: c706ac7b6601 MOV
        batch_guest_pc = 0x00885fd9u;
        t22 = 0x01667bacu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00885fdf: c74604ac7b6601 MOV
        batch_guest_pc = 0x00885fdfu;
        t23 = 0x01667bacu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00885fe6: c74608ad7b6601 MOV
        batch_guest_pc = 0x00885fe6u;
        t24 = 0x01667badu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00885fed: 5e POP
        batch_guest_pc = 0x00885fedu;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t25a;
    // 0x00885fee: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
