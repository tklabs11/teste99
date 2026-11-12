#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923ed0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923ed0u);
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

    // 0x00923ed0: 56 PUSH
        batch_guest_pc = 0x00923ed0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ed1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00923ed3: c7067cdd4301 MOV
        batch_guest_pc = 0x00923ed3u;
        t2 = 0x0143dd7cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
    // 0x00923ed9: 8b8640020000 MOV
        batch_guest_pc = 0x00923ed9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000240u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00923edf: 8b8e48020000 MOV
        batch_guest_pc = 0x00923edfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000248u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x00923ee5: 2bc8 SUB
        t5a = state.regs[1];
        t5b = state.regs[0];
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[1] = t5r;
    // 0x00923ee7: 83f901 CMP
        t6a = state.regs[1];
        t6b = 0x00000001u;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00923eea: 7e15 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00923f01;
    // 0x00923eec: 85c0 TEST
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x00923eee: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923f01;
    // 0x00923ef0: 3b8650020000 CMP
        batch_guest_pc = 0x00923ef0u;
        t10a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000250u), t10b)) return BatchLiftStatus::invalid_memory;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x00923ef6: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923f01;
    // 0x00923ef8: 50 PUSH
        batch_guest_pc = 0x00923ef8u;
        t12a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ef9: e882346200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00923efeu)) return BatchLiftStatus::invalid_memory;
        t13_call_status = spore_lift_00f47380(memory, state);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x00923efeu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923efe: 83c404 ADD
        t14a = state.regs[4];
        t14b = 0x00000004u;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[4] = t14r;
    // 0x00923f01: 8b4608 MOV
    L_00923f01:
        batch_guest_pc = 0x00923f01u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x00923f04: 8b5610 MOV
        batch_guest_pc = 0x00923f04u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t16;
    // 0x00923f07: 2bd0 SUB
        t17a = state.regs[2];
        t17b = state.regs[0];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
        state.regs[2] = t17r;
    // 0x00923f09: 83fa01 CMP
        t18a = state.regs[2];
        t18b = 0x00000001u;
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
    // 0x00923f0c: 7e12 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00923f20;
    // 0x00923f0e: 85c0 TEST
        t20a = state.regs[0];
        t20b = state.regs[0];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00923f10: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923f20;
    // 0x00923f12: 3b4618 CMP
        batch_guest_pc = 0x00923f12u;
        t22a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t22b)) return BatchLiftStatus::invalid_memory;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x00923f15: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923f20;
    // 0x00923f17: 50 PUSH
        batch_guest_pc = 0x00923f17u;
        t24a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00923f18: e863346200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00923f1du)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_00f47380(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00923f1du) return BatchLiftStatus::invalid_control_flow;
    // 0x00923f1d: 83c404 ADD
        t26a = state.regs[4];
        t26b = 0x00000004u;
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[4] = t26r;
    // 0x00923f20: c70638b93e01 MOV
    L_00923f20:
        batch_guest_pc = 0x00923f20u;
        t27 = 0x013eb938u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00923f26: 5e POP
        batch_guest_pc = 0x00923f26u;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t28a;
    // 0x00923f27: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
