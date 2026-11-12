#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009242f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009242f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t28a = 0;
    BatchLiftStatus t29_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;

    // 0x009242f0: 56 PUSH
        batch_guest_pc = 0x009242f0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009242f1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x009242f3: c706c8dc4301 MOV
        batch_guest_pc = 0x009242f3u;
        t2 = 0x0143dcc8u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
    // 0x009242f9: 8b4614 MOV
        batch_guest_pc = 0x009242f9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x009242fc: 8b4e1c MOV
        batch_guest_pc = 0x009242fcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x009242ff: 2bc8 SUB
        t5a = state.regs[1];
        t5b = state.regs[0];
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[1] = t5r;
    // 0x00924301: 83f901 CMP
        t6a = state.regs[1];
        t6b = 0x00000001u;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00924304: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00924313;
    // 0x00924306: 85c0 TEST
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x00924308: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924313;
    // 0x0092430a: 50 PUSH
        batch_guest_pc = 0x0092430au;
        t10a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0092430b: e870306200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00924310u)) return BatchLiftStatus::invalid_memory;
        t11_call_status = spore_lift_00f47380(memory, state);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x00924310u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924310: 83c404 ADD
        t12a = state.regs[4];
        t12b = 0x00000004u;
        t12r = static_cast<std::uint32_t>(t12a + t12b) & 0xffffffffu;
        batch_set_add_flags(state, t12a, t12b, t12r, 32u);
        state.regs[4] = t12r;
    // 0x00924313: 8b4e08 MOV
    L_00924313:
        batch_guest_pc = 0x00924313u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00924316: 85c9 TEST
        t14a = state.regs[1];
        t14b = state.regs[1];
        t14r = (t14a & t14b) & 0xffffffffu;
        batch_set_logic_flags(state, t14r, 32u);
    // 0x00924318: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924321;
    // 0x0092431a: 8b11 MOV
        batch_guest_pc = 0x0092431au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t16;
    // 0x0092431c: 8b4204 MOV
        batch_guest_pc = 0x0092431cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x0092431f: ffd0 CALL
        t18_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924321u);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
    // 0x00924321: 8b4e04 MOV
    L_00924321:
        batch_guest_pc = 0x00924321u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x00924324: 85c9 TEST
        t20a = state.regs[1];
        t20b = state.regs[1];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00924326: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092432f;
    // 0x00924328: 8b11 MOV
        batch_guest_pc = 0x00924328u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x0092432a: 8b4204 MOV
        batch_guest_pc = 0x0092432au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x0092432d: ffd0 CALL
        t24_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0092432fu);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
    // 0x0092432f: f644240801 TEST
    L_0092432f:
        batch_guest_pc = 0x0092432fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t25a)) return BatchLiftStatus::invalid_memory;
        t25b = 0x00000001u;
        t25r = (t25a & t25b) & 0x000000ffu;
        batch_set_logic_flags(state, t25r, 8u);
    // 0x00924334: c70638b93e01 MOV
        batch_guest_pc = 0x00924334u;
        t26 = 0x013eb938u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0092433a: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924345;
    // 0x0092433c: 56 PUSH
        batch_guest_pc = 0x0092433cu;
        t28a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x0092433d: e83e306200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00924342u)) return BatchLiftStatus::invalid_memory;
        t29_call_status = spore_lift_00f47380(memory, state);
        if (t29_call_status != BatchLiftStatus::returned) return t29_call_status;
        if (state.eip != 0x00924342u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924342: 83c404 ADD
        t30a = state.regs[4];
        t30b = 0x00000004u;
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[4] = t30r;
    // 0x00924345: 8bc6 MOV
    L_00924345:
        t31 = state.regs[6];
        state.regs[0] = t31;
    // 0x00924347: 5e POP
        batch_guest_pc = 0x00924347u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t32a;
    // 0x00924348: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
