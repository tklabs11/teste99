#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00692330(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00692400(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00692400u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00692400: 85c9 TEST
        t0a = state.regs[1];
        t0b = state.regs[1];
        t0r = (t0a & t0b) & 0xffffffffu;
        batch_set_logic_flags(state, t0r, 32u);
    // 0x00692402: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069241a;
    // 0x00692404: 8b542404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x00692408: 8d41f8 LEA
        t3 = static_cast<std::uint32_t>(state.regs[1] + 0xfffffff8u);
        state.regs[0] = t3;
    // 0x0069240b: 8bc8 MOV
        t4 = state.regs[0];
        state.regs[1] = t4;
    // 0x0069240d: 8b4930 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000030u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x00692410: 52 PUSH
        t6a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00692411: 50 PUSH
        t7a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00692412: e819ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00692330u, 0x00692417u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_00692330(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00692417u) return BatchLiftStatus::invalid_control_flow;
    // 0x00692417: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0069241a: 8b542404 MOV
    L_0069241a:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t10;
    // 0x0069241e: 33c0 XOR
        t11a = state.regs[0];
        t11b = state.regs[0];
        t11r = (t11a ^ t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
        state.regs[0] = t11r;
    // 0x00692420: 33c9 XOR
        t12a = state.regs[1];
        t12b = state.regs[1];
        t12r = (t12a ^ t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
        state.regs[1] = t12r;
    // 0x00692422: 8b4930 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000030u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00692425: 52 PUSH
        t14a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00692426: 50 PUSH
        t15a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00692427: e804ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00692330u, 0x0069242cu)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00692330(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x0069242cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069242c: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
