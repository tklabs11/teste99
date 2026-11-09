#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0042df40(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473d0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0042dee0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0042dee0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    BatchLiftStatus t28_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0;

    // 0x0042dee0: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0042dee1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0042dee3: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0042dee6: 837d1008 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t3a)) return BatchLiftStatus::invalid_memory;
        t3b = 0x00000008u;
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
    // 0x0042deea: 7727 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0042df13;
    // 0x0042deec: 68d1000000 PUSH
        t5a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0042def1: 6838bb3e01 PUSH
        t6a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0042def6: 6a00 PUSH
        t7a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0042def8: 6a00 PUSH
        t8a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x0042defa: 6830b43e01 PUSH
        t9a = 0x013eb430u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x0042deff: 8b450c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x0042df02: 50 PUSH
        t11a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x0042df03: e89894b100 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x0042df08u)) return BatchLiftStatus::invalid_memory;
        t12_call_status = spore_lift_00f473a0(memory, state);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x0042df08u) return BatchLiftStatus::invalid_control_flow;
    // 0x0042df08: 83c418 ADD
        t13a = state.regs[4];
        t13b = 0x00000018u;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[4] = t13r;
    // 0x0042df0b: 8945fc MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0042df0e: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x0042df11: eb2d JMP
        goto L_0042df40;
    // 0x0042df13: 68e5000000 PUSH
    L_0042df13:
        t17a = 0x000000e5u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x0042df18: 6838bb3e01 PUSH
        t18a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x0042df1d: 6a00 PUSH
        t19a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x0042df1f: 6a00 PUSH
        t20a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x0042df21: 6830b43e01 PUSH
        t21a = 0x013eb430u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x0042df26: 8b4d14 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000014u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x0042df29: 51 PUSH
        t23a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x0042df2a: 8b5510 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t24;
    // 0x0042df2d: 52 PUSH
        t25a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x0042df2e: 8b450c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t26;
    // 0x0042df31: 50 PUSH
        t27a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x0042df32: e89994b100 CALL
        if (!batch_guest_call32(memory, state, 0x00f473d0u, 0x0042df37u)) return BatchLiftStatus::invalid_memory;
        t28_call_status = spore_lift_00f473d0(memory, state);
        if (t28_call_status != BatchLiftStatus::returned) return t28_call_status;
        if (state.eip != 0x0042df37u) return BatchLiftStatus::invalid_control_flow;
    // 0x0042df37: 83c420 ADD
        t29a = state.regs[4];
        t29b = 0x00000020u;
        t29r = static_cast<std::uint32_t>(t29a + t29b) & 0xffffffffu;
        batch_set_add_flags(state, t29a, t29b, t29r, 32u);
        state.regs[4] = t29r;
    // 0x0042df3a: 8945f8 MOV
        t30 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x0042df3d: 8b45f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t31;
    // 0x0042df40: 8be5 MOV
    L_0042df40:
        t32 = state.regs[5];
        state.regs[4] = t32;
    // 0x0042df42: 5d POP
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t33a;
    // 0x0042df43: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
