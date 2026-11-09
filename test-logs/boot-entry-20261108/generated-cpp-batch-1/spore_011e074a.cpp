#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e07e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07e6(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e11d4(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e1219(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e074a(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e074au);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12a = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18a = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;
    BatchLiftStatus t22_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31 = 0;
    BatchLiftStatus t32_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0;
    BatchLiftStatus t41_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46 = 0;
    BatchLiftStatus t47_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x011e074a: 6a14 PUSH
        t0a = 0x00000014u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e074c: 68088c5001 PUSH
        t1a = 0x01508c08u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0751: e87e0a0000 CALL
        if (!batch_guest_call32(memory, state, 0x011e11d4u, 0x011e0756u)) return BatchLiftStatus::invalid_memory;
        t2_call_status = spore_lift_011e11d4(memory, state);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x011e0756u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0756: ff3560e77101 PUSH
        if (!memory.load32(0x0171e760u, t3a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x011e075c: 8b3544c33c01 MOV
        if (!memory.load32(0x013cc344u, t4)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t4;
    // 0x011e0762: ffd6 CALL
        t5_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[6], 0x011e0764u);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
    // 0x011e0764: 59 POP
        if (!memory.load32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t6a;
    // 0x011e0765: 8945e4 MOV
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x011e0768: 83f8ff CMP
        t8a = state.regs[0];
        t8b = 0xffffffffu;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x011e076b: 750c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e0779;
    // 0x011e076d: ff7508 PUSH
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0770: ff1548c33c01 CALL
        t11_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_onexit", 0x013cc348u, 0x011e0776u);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x011e0776u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0776: 59 POP
        if (!memory.load32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t12a;
    // 0x011e0777: eb67 JMP
        goto L_011e07e0;
    // 0x011e0779: 6a08 PUSH
    L_011e0779:
        t14a = 0x00000008u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x011e077b: e84c0a0000 CALL
        t15_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_lock", 0x013cc34cu, 0x011e0780u);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x011e0780u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0780: 59 POP
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t16a;
    // 0x011e0781: 8365fc00 AND
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = 0x00000000u;
        t17r = (t17a & t17b) & 0xffffffffu;
        batch_set_logic_flags(state, t17r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t17r)) return BatchLiftStatus::invalid_memory;
    // 0x011e0785: ff3560e77101 PUSH
        if (!memory.load32(0x0171e760u, t18a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x011e078b: ffd6 CALL
        t19_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[6], 0x011e078du);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
    // 0x011e078d: 8945e4 MOV
        t20 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x011e0790: ff355ce77101 PUSH
        if (!memory.load32(0x0171e75cu, t21a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0796: ffd6 CALL
        t22_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[6], 0x011e0798u);
        if (t22_call_status != BatchLiftStatus::returned) return t22_call_status;
    // 0x011e0798: 59 POP
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t23a;
    // 0x011e0799: 59 POP
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t24a;
    // 0x011e079a: 8945e0 MOV
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x011e079d: 8d45e0 LEA
        t26 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u);
        state.regs[0] = t26;
    // 0x011e07a0: 50 PUSH
        t27a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x011e07a1: 8d45e4 LEA
        t28 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u);
        state.regs[0] = t28;
    // 0x011e07a4: 50 PUSH
        t29a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x011e07a5: ff7508 PUSH
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t30a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x011e07a8: 8b3550c33c01 MOV
        if (!memory.load32(0x013cc350u, t31)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t31;
    // 0x011e07ae: ffd6 CALL
        t32_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[6], 0x011e07b0u);
        if (t32_call_status != BatchLiftStatus::returned) return t32_call_status;
    // 0x011e07b0: 59 POP
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t33a;
    // 0x011e07b1: 50 PUSH
        t34a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x011e07b2: e80f0a0000 CALL
        t35_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!__dllonexit", 0x013cc354u, 0x011e07b7u);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x011e07b7u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e07b7: 8945dc MOV
        t36 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t36)) return BatchLiftStatus::invalid_memory;
    // 0x011e07ba: ff75e4 PUSH
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x011e07bd: ffd6 CALL
        t38_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[6], 0x011e07bfu);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
    // 0x011e07bf: a360e77101 MOV
        t39 = state.regs[0];
        if (!memory.store32(0x0171e760u, t39)) return BatchLiftStatus::invalid_memory;
    // 0x011e07c4: ff75e0 PUSH
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t40a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x011e07c7: ffd6 CALL
        t41_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[6], 0x011e07c9u);
        if (t41_call_status != BatchLiftStatus::returned) return t41_call_status;
    // 0x011e07c9: 83c414 ADD
        t42a = state.regs[4];
        t42b = 0x00000014u;
        t42r = static_cast<std::uint32_t>(t42a + t42b) & 0xffffffffu;
        batch_set_add_flags(state, t42a, t42b, t42r, 32u);
        state.regs[4] = t42r;
    // 0x011e07cc: a35ce77101 MOV
        t43 = state.regs[0];
        if (!memory.store32(0x0171e75cu, t43)) return BatchLiftStatus::invalid_memory;
    // 0x011e07d1: c745fcfeffffff MOV
        t44 = 0xfffffffeu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t44)) return BatchLiftStatus::invalid_memory;
    // 0x011e07d8: e809000000 CALL
        if (!batch_guest_call32(memory, state, 0x011e07e6u, 0x011e07ddu)) return BatchLiftStatus::invalid_memory;
        t45_call_status = spore_lift_011e07e6(memory, state);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
        if (state.eip != 0x011e07ddu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e07dd: 8b45dc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t46;
    // 0x011e07e0: e8340a0000 CALL
    L_011e07e0:
        if (!batch_guest_call32(memory, state, 0x011e1219u, 0x011e07e5u)) return BatchLiftStatus::invalid_memory;
        t47_call_status = spore_lift_011e1219(memory, state);
        if (t47_call_status != BatchLiftStatus::returned) return t47_call_status;
        if (state.eip != 0x011e07e5u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e07e5: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
