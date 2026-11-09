#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00926fd0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009276c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009276c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12a = 0, t12r = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18a = 0, t18r = 0;
    std::uint32_t t19a = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;

    // 0x009276c0: 53 PUSH
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009276c1: 8b5c2408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t1;
    // 0x009276c5: 57 PUSH
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009276c6: 8bf9 MOV
        t3 = state.regs[1];
        state.regs[7] = t3;
    // 0x009276c8: 85db TEST
        t4a = state.regs[3];
        t4b = state.regs[3];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x009276ca: 742c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009276f8;
    // 0x009276cc: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x009276cd: 8bb7e4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x000004e4u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t7;
    // 0x009276d3: 85f6 TEST
        t8a = state.regs[6];
        t8b = state.regs[6];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x009276d5: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009276e1;
    // 0x009276d7: 56 PUSH
        t10a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x009276d8: ff15d8c23c01 CALL
        t11_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x009276deu);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x009276deu) return BatchLiftStatus::invalid_control_flow;
    // 0x009276de: ff4618 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t12a)) return BatchLiftStatus::invalid_memory;
        t12r = static_cast<std::uint32_t>(t12a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t12a, t12r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t12r)) return BatchLiftStatus::invalid_memory;
    // 0x009276e1: 53 PUSH
    L_009276e1:
        t13a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x009276e2: 8bcf MOV
        t14 = state.regs[7];
        state.regs[1] = t14;
    // 0x009276e4: e8e7f8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926fd0u, 0x009276e9u)) return BatchLiftStatus::invalid_memory;
        t15_call_status = spore_lift_00926fd0(memory, state);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x009276e9u) return BatchLiftStatus::invalid_control_flow;
    // 0x009276e9: 85f6 TEST
        t16a = state.regs[6];
        t16b = state.regs[6];
        t16r = (t16a & t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
    // 0x009276eb: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009276f7;
    // 0x009276ed: ff4e18 DEC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t18a)) return BatchLiftStatus::invalid_memory;
        t18r = static_cast<std::uint32_t>(t18a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t18a, t18r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t18r)) return BatchLiftStatus::invalid_memory;
    // 0x009276f0: 56 PUSH
        t19a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x009276f1: ff15dcc23c01 CALL
        t20_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x009276f7u);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x009276f7u) return BatchLiftStatus::invalid_control_flow;
    // 0x009276f7: 5e POP
    L_009276f7:
        if (!memory.load32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t21a;
    // 0x009276f8: 5f POP
    L_009276f8:
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t22a;
    // 0x009276f9: 5b POP
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t23a;
    // 0x009276fa: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
