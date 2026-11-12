#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921300(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00921360(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00921360u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;

    // 0x00921360: 83ec10 SUB
        t0a = state.regs[4];
        t0b = 0x00000010u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00921363: 56 PUSH
        batch_guest_pc = 0x00921363u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00921364: 8d442418 LEA
        t2 = static_cast<std::uint32_t>(state.regs[4] + 0x00000018u);
        state.regs[0] = t2;
    // 0x00921368: 50 PUSH
        batch_guest_pc = 0x00921368u;
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00921369: 6850dc4301 PUSH
        batch_guest_pc = 0x00921369u;
        t4a = 0x0143dc50u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0092136e: 6850d84301 PUSH
        batch_guest_pc = 0x0092136eu;
        t5a = 0x0143d850u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00921373: 8bf1 MOV
        t6 = state.regs[1];
        state.regs[6] = t6;
    // 0x00921375: e886ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00921300u, 0x0092137au)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_00921300(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x0092137au) return BatchLiftStatus::invalid_control_flow;
    // 0x0092137a: 8b10 MOV
        batch_guest_pc = 0x0092137au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x0092137c: 8bca MOV
        t9 = state.regs[2];
        state.regs[1] = t9;
    // 0x0092137e: 83c40c ADD
        t10a = state.regs[4];
        t10b = 0x0000000cu;
        t10r = static_cast<std::uint32_t>(t10a + t10b) & 0xffffffffu;
        batch_set_add_flags(state, t10a, t10b, t10r, 32u);
        state.regs[4] = t10r;
    // 0x00921381: 894c2418 MOV
        batch_guest_pc = 0x00921381u;
        t11 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00921385: db442418 FILD
        if (!batch_guest_fild32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000018u))) return BatchLiftStatus::invalid_memory;
    // 0x00921389: 85c9 TEST
        t13a = state.regs[1];
        t13b = state.regs[1];
        t13r = (t13a & t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
    // 0x0092138b: 7d06 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00921393;
    // 0x0092138d: d805d04f3f01 FADD
        if (!batch_guest_x87_float32_arithmetic(memory, state, 0x013f4fd0u, 0u)) return BatchLiftStatus::invalid_memory;
    // 0x00921393: d80e FMUL
    L_00921393:
        if (!batch_guest_x87_float32_arithmetic(memory, state, static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), 1u)) return BatchLiftStatus::invalid_memory;
    // 0x00921395: d95c2404 FSTP
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x00921399: f30f10442404 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x0092139f: f30f2dc0 CVTSS2SI
        if (!batch_guest_cvtss2si(state, 0u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x009213a3: f30f2ac8 CVTSI2SS
        if (!batch_guest_cvtsi2ss(state, 1u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x009213a7: 8bc8 MOV
        t21 = state.regs[0];
        state.regs[1] = t21;
    // 0x009213a9: 83c101 ADD
        t22a = state.regs[1];
        t22b = 0x00000001u;
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[1] = t22r;
    // 0x009213ac: 0f2ec8 UCOMISS
        if (!batch_guest_ucomiss(state, 1u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x009213af: 0f42c1 CMOVC
        if ((state.eflags & 0x001u) != 0u) state.regs[0] = state.regs[1];
    // 0x009213b2: 894608 MOV
        batch_guest_pc = 0x009213b2u;
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x009213b5: 8bc2 MOV
        t26 = state.regs[2];
        state.regs[0] = t26;
    // 0x009213b7: 5e POP
        batch_guest_pc = 0x009213b7u;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t27a;
    // 0x009213b8: 83c410 ADD
        t28a = state.regs[4];
        t28b = 0x00000010u;
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[4] = t28r;
    // 0x009213bb: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
