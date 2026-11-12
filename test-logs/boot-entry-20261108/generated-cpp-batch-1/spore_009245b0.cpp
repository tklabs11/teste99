#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009244d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009245e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009245b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009245b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;

    // 0x009245b0: 56 PUSH
        batch_guest_pc = 0x009245b0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009245b1: 6a00 PUSH
        batch_guest_pc = 0x009245b1u;
        t1a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009245b3: 6a00 PUSH
        batch_guest_pc = 0x009245b3u;
        t2a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009245b5: 6a00 PUSH
        batch_guest_pc = 0x009245b5u;
        t3a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009245b7: 6a00 PUSH
        batch_guest_pc = 0x009245b7u;
        t4a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009245b9: 6868de4301 PUSH
        batch_guest_pc = 0x009245b9u;
        t5a = 0x0143de68u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x009245be: 68580a0000 PUSH
        batch_guest_pc = 0x009245beu;
        t6a = 0x00000a58u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x009245c3: 8bf1 MOV
        t7 = state.regs[1];
        state.regs[6] = t7;
    // 0x009245c5: e8d62d6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x009245cau)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_00f473a0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x009245cau) return BatchLiftStatus::invalid_control_flow;
    // 0x009245ca: 83c418 ADD
        t9a = state.regs[4];
        t9b = 0x00000018u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[4] = t9r;
    // 0x009245cd: 85c0 TEST
        t10a = state.regs[0];
        t10b = state.regs[0];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x009245cf: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009245de;
    // 0x009245d1: 8b4e08 MOV
        batch_guest_pc = 0x009245d1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x009245d4: 51 PUSH
        batch_guest_pc = 0x009245d4u;
        t13a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x009245d5: 8bc8 MOV
        t14 = state.regs[0];
        state.regs[1] = t14;
    // 0x009245d7: e8f4feffff CALL
        if (!batch_guest_call32(memory, state, 0x009244d0u, 0x009245dcu)) return BatchLiftStatus::invalid_memory;
        t15_call_status = spore_lift_009244d0(memory, state);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x009245dcu) return BatchLiftStatus::invalid_control_flow;
    // 0x009245dc: eb02 JMP
        goto L_009245e0;
    // 0x009245de: 33c0 XOR
    L_009245de:
        t17a = state.regs[0];
        t17b = state.regs[0];
        t17r = (t17a ^ t17b) & 0xffffffffu;
        batch_set_logic_flags(state, t17r, 32u);
        state.regs[0] = t17r;
    // 0x009245e0: 668b8e1c020000 MOV
    L_009245e0:
        batch_guest_pc = 0x009245e0u;
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[6] + 0x0000021cu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffff0000u) | ((t18 << 0u) & 0x0000ffffu);
    // 0x009245e7: 6689881c020000 MOV
        batch_guest_pc = 0x009245e7u;
        t19 = state.regs[1] & 0x0000ffffu;
        if (!memory.store16(static_cast<std::uint32_t>(state.regs[0] + 0x0000021cu), t19)) return BatchLiftStatus::invalid_memory;
    // 0x009245ee: 8b9620020000 MOV
        batch_guest_pc = 0x009245eeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000220u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t20;
    // 0x009245f4: 899020020000 MOV
        batch_guest_pc = 0x009245f4u;
        t21 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000220u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x009245fa: 5e POP
        batch_guest_pc = 0x009245fau;
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t22a;
    // 0x009245fb: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
