#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00925100(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923a60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923a60u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;

    // 0x00923a60: 8b4908 MOV
        batch_guest_pc = 0x00923a60u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t0;
    // 0x00923a63: 8b01 MOV
        batch_guest_pc = 0x00923a63u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00923a65: 8b5010 MOV
        batch_guest_pc = 0x00923a65u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x00923a68: 56 PUSH
        batch_guest_pc = 0x00923a68u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00923a69: 8b742408 MOV
        batch_guest_pc = 0x00923a69u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t4;
    // 0x00923a6d: 57 PUSH
        batch_guest_pc = 0x00923a6du;
        t5a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00923a6e: 56 PUSH
        batch_guest_pc = 0x00923a6eu;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00923a6f: ffd2 CALL
        t7_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00923a71u);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
    // 0x00923a71: 8bf8 MOV
        t8 = state.regs[0];
        state.regs[7] = t8;
    // 0x00923a73: 8b06 MOV
        batch_guest_pc = 0x00923a73u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x00923a75: 8b5008 MOV
        batch_guest_pc = 0x00923a75u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t10;
    // 0x00923a78: 8bce MOV
        t11 = state.regs[6];
        state.regs[1] = t11;
    // 0x00923a7a: ffd2 CALL
        t12_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00923a7cu);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
    // 0x00923a7c: 85c0 TEST
        t13a = state.regs[0];
        t13b = state.regs[0];
        t13r = (t13a & t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
    // 0x00923a7e: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923a85;
    // 0x00923a80: b86c9f4001 MOV
        t15 = 0x01409f6cu;
        state.regs[0] = t15;
    // 0x00923a85: 57 PUSH
    L_00923a85:
        batch_guest_pc = 0x00923a85u;
        t16a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00923a86: 50 PUSH
        batch_guest_pc = 0x00923a86u;
        t17a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00923a87: e874160000 CALL
        if (!batch_guest_call32(memory, state, 0x00925100u, 0x00923a8cu)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00925100(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00923a8cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923a8c: 83c408 ADD
        t19a = state.regs[4];
        t19b = 0x00000008u;
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[4] = t19r;
    // 0x00923a8f: 5f POP
        batch_guest_pc = 0x00923a8fu;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t20a;
    // 0x00923a90: 5e POP
        batch_guest_pc = 0x00923a90u;
        if (!memory.load32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t21a;
    // 0x00923a91: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
