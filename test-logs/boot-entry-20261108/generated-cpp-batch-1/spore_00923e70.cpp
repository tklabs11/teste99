#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923e70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923e70u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24a = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;

    // 0x00923e70: 56 PUSH
        batch_guest_pc = 0x00923e70u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e71: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00923e73: c7065cdd4301 MOV
        batch_guest_pc = 0x00923e73u;
        t2 = 0x0143dd5cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
    // 0x00923e79: 8b861c080000 MOV
        batch_guest_pc = 0x00923e79u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000081cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00923e7f: 8b8e24080000 MOV
        batch_guest_pc = 0x00923e7fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000824u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x00923e85: 2bc8 SUB
        t5a = state.regs[1];
        t5b = state.regs[0];
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[1] = t5r;
    // 0x00923e87: 83f901 CMP
        t6a = state.regs[1];
        t6b = 0x00000001u;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00923e8a: 7e15 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00923ea1;
    // 0x00923e8c: 85c0 TEST
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x00923e8e: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923ea1;
    // 0x00923e90: 3b862c080000 CMP
        batch_guest_pc = 0x00923e90u;
        t10a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000082cu), t10b)) return BatchLiftStatus::invalid_memory;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x00923e96: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923ea1;
    // 0x00923e98: 50 PUSH
        batch_guest_pc = 0x00923e98u;
        t12a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e99: e8e2346200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00923e9eu)) return BatchLiftStatus::invalid_memory;
        t13_call_status = spore_lift_00f47380(memory, state);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x00923e9eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923e9e: 83c404 ADD
        t14a = state.regs[4];
        t14b = 0x00000004u;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[4] = t14r;
    // 0x00923ea1: 8b4608 MOV
    L_00923ea1:
        batch_guest_pc = 0x00923ea1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x00923ea4: 8b5610 MOV
        batch_guest_pc = 0x00923ea4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t16;
    // 0x00923ea7: 2bd0 SUB
        t17a = state.regs[2];
        t17b = state.regs[0];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
        state.regs[2] = t17r;
    // 0x00923ea9: 83fa01 CMP
        t18a = state.regs[2];
        t18b = 0x00000001u;
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
    // 0x00923eac: 7e12 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00923ec0;
    // 0x00923eae: 85c0 TEST
        t20a = state.regs[0];
        t20b = state.regs[0];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00923eb0: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923ec0;
    // 0x00923eb2: 3b4618 CMP
        batch_guest_pc = 0x00923eb2u;
        t22a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t22b)) return BatchLiftStatus::invalid_memory;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x00923eb5: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923ec0;
    // 0x00923eb7: 50 PUSH
        batch_guest_pc = 0x00923eb7u;
        t24a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00923eb8: e8c3346200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00923ebdu)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_00f47380(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00923ebdu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923ebd: 83c404 ADD
        t26a = state.regs[4];
        t26b = 0x00000004u;
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[4] = t26r;
    // 0x00923ec0: c70638b93e01 MOV
    L_00923ec0:
        batch_guest_pc = 0x00923ec0u;
        t27 = 0x013eb938u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00923ec6: 5e POP
        batch_guest_pc = 0x00923ec6u;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t28a;
    // 0x00923ec7: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
