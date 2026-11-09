#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_006900b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0069012b(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00690120(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00690120u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0, t9r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;

    // 0x00690120: 85c9 TEST
        t0a = state.regs[1];
        t0b = state.regs[1];
        t0r = (t0a & t0b) & 0xffffffffu;
        batch_set_logic_flags(state, t0r, 32u);
    // 0x00690122: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690129;
    // 0x00690124: 8d41f8 LEA
        t2 = static_cast<std::uint32_t>(state.regs[1] + 0xfffffff8u);
        state.regs[0] = t2;
    // 0x00690127: eb02 JMP
        goto L_0069012b;
    // 0x00690129: 33c0 XOR
    L_00690129:
        t4a = state.regs[0];
        t4b = state.regs[0];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[0] = t4r;
    // 0x0069012b: 56 PUSH
    L_0069012b:
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0069012c: 83c04c ADD
        t6a = state.regs[0];
        t6b = 0x0000004cu;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[0] = t6r;
    // 0x0069012f: 83ceff OR
        t7a = state.regs[6];
        t7b = 0xffffffffu;
        t7r = (t7a | t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
        state.regs[6] = t7r;
    // 0x00690132: f00fc130 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t8a)) return BatchLiftStatus::invalid_memory;
        t8b = state.regs[6];
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t8r)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t8a;
    // 0x00690136: 4e DEC
        t9a = state.regs[6];
        t9r = static_cast<std::uint32_t>(t9a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t9a, t9r, 32u);
        state.regs[6] = t9r;
    // 0x00690137: 7523 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0069015c;
    // 0x00690139: 85c9 TEST
        t11a = state.regs[1];
        t11b = state.regs[1];
        t11r = (t11a & t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
    // 0x0069013b: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069014f;
    // 0x0069013d: 8d41f8 LEA
        t13 = static_cast<std::uint32_t>(state.regs[1] + 0xfffffff8u);
        state.regs[0] = t13;
    // 0x00690140: 8bc8 MOV
        t14 = state.regs[0];
        state.regs[1] = t14;
    // 0x00690142: 8b4930 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000030u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x00690145: 50 PUSH
        t16a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00690146: e865ffffff CALL
        if (!batch_guest_call32(memory, state, 0x006900b0u, 0x0069014bu)) return BatchLiftStatus::invalid_memory;
        t17_call_status = spore_lift_006900b0(memory, state);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
        if (state.eip != 0x0069014bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069014b: 8bc6 MOV
        t18 = state.regs[6];
        state.regs[0] = t18;
    // 0x0069014d: 5e POP
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t19a;
    // 0x0069014e: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0069014f: 33c0 XOR
    L_0069014f:
        t21a = state.regs[0];
        t21b = state.regs[0];
        t21r = (t21a ^ t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
        state.regs[0] = t21r;
    // 0x00690151: 33c9 XOR
        t22a = state.regs[1];
        t22b = state.regs[1];
        t22r = (t22a ^ t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
        state.regs[1] = t22r;
    // 0x00690153: 8b4930 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000030u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t23;
    // 0x00690156: 50 PUSH
        t24a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00690157: e854ffffff CALL
        if (!batch_guest_call32(memory, state, 0x006900b0u, 0x0069015cu)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_006900b0(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x0069015cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069015c: 8bc6 MOV
    L_0069015c:
        t26 = state.regs[6];
        state.regs[0] = t26;
    // 0x0069015e: 5e POP
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t27a;
    // 0x0069015f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
