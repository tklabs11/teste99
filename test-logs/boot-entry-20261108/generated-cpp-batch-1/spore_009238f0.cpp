#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009238f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009238f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;

    // 0x009238f0: 53 PUSH
        batch_guest_pc = 0x009238f0u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009238f1: 56 PUSH
        batch_guest_pc = 0x009238f1u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009238f2: 8b74240c MOV
        batch_guest_pc = 0x009238f2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t2;
    // 0x009238f6: 8bd9 MOV
        t3 = state.regs[1];
        state.regs[3] = t3;
    // 0x009238f8: 57 PUSH
        batch_guest_pc = 0x009238f8u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009238f9: 8b7b30 MOV
        batch_guest_pc = 0x009238f9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000030u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t5;
    // 0x009238fc: 3bf7 CMP
        t6a = state.regs[6];
        t6b = state.regs[7];
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x009238fe: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092391c;
    // 0x00923900: 85f6 TEST
        t8a = state.regs[6];
        t8b = state.regs[6];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x00923902: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092390c;
    // 0x00923904: 8b06 MOV
        batch_guest_pc = 0x00923904u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x00923906: 8b10 MOV
        batch_guest_pc = 0x00923906u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x00923908: 8bce MOV
        t12 = state.regs[6];
        state.regs[1] = t12;
    // 0x0092390a: ffd2 CALL
        t13_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092390cu);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
    // 0x0092390c: 897330 MOV
    L_0092390c:
        batch_guest_pc = 0x0092390cu;
        t14 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000030u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0092390f: 85ff TEST
        t15a = state.regs[7];
        t15b = state.regs[7];
        t15r = (t15a & t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
    // 0x00923911: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092391c;
    // 0x00923913: 8b07 MOV
        batch_guest_pc = 0x00923913u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x00923915: 8b5004 MOV
        batch_guest_pc = 0x00923915u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x00923918: 8bcf MOV
        t19 = state.regs[7];
        state.regs[1] = t19;
    // 0x0092391a: ffd2 CALL
        t20_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092391cu);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
    // 0x0092391c: 5f POP
    L_0092391c:
        batch_guest_pc = 0x0092391cu;
        if (!memory.load32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t21a;
    // 0x0092391d: 5e POP
        batch_guest_pc = 0x0092391du;
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t22a;
    // 0x0092391e: 5b POP
        batch_guest_pc = 0x0092391eu;
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t23a;
    // 0x0092391f: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
