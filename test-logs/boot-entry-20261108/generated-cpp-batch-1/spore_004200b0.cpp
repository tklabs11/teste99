#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401f20(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00420050(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004200ca(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004200d2(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004253c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00501ef0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_004200b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004200b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10 = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;
    BatchLiftStatus t29_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;

    // 0x004200b0: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x004200b1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x004200b3: 83ec18 SUB
        t2a = state.regs[4];
        t2b = 0x00000018u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x004200b6: 894de8 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x004200b9: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x004200bc: 83c008 ADD
        t5a = state.regs[0];
        t5b = 0x00000008u;
        t5r = static_cast<std::uint32_t>(t5a + t5b) & 0xffffffffu;
        batch_set_add_flags(state, t5a, t5b, t5r, 32u);
        state.regs[0] = t5r;
    // 0x004200bf: 50 PUSH
        t6a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x004200c0: 8d4df0 LEA
        t7 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u);
        state.regs[1] = t7;
    // 0x004200c3: e888ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00420050u, 0x004200c8u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_00420050(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x004200c8u) return BatchLiftStatus::invalid_control_flow;
    // 0x004200c8: eb08 JMP
        goto L_004200d2;
    // 0x004200ca: 8d4df0 LEA
    L_004200ca:
        t10 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u);
        state.regs[1] = t10;
    // 0x004200cd: e8ee520000 CALL
        t11_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x004253c0u, 0x004200d2u);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x004200d2u) return BatchLiftStatus::invalid_control_flow;
    // 0x004200d2: 8b4de8 MOV
    L_004200d2:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x004200d5: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x004200d8: 33c0 XOR
        t14a = state.regs[0];
        t14b = state.regs[0];
        t14r = (t14a ^ t14b) & 0xffffffffu;
        batch_set_logic_flags(state, t14r, 32u);
        state.regs[0] = t14r;
    // 0x004200da: 3b5118 CMP
        t15a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000018u), t15b)) return BatchLiftStatus::invalid_memory;
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x004200dd: 0f95c0 SETNZ
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x004200e0: 0fb6c8 MOVZX
        t17a = state.regs[0] & 0x000000ffu;
        state.regs[1] = t17a;
    // 0x004200e3: 85c9 TEST
        t18a = state.regs[1];
        t18b = state.regs[1];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
    // 0x004200e5: 7423 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0042010a;
    // 0x004200e7: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t20;
    // 0x004200ea: 8955ec MOV
        t21 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x004200ed: 8b4dec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x004200f0: e82b1efeff CALL
        t23_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00401f20u, 0x004200f5u);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x004200f5u) return BatchLiftStatus::invalid_control_flow;
    // 0x004200f5: 33c0 XOR
        t24a = state.regs[0];
        t24b = state.regs[0];
        t24r = (t24a ^ t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
        state.regs[0] = t24r;
    // 0x004200f7: 83e001 AND
        t25a = state.regs[0];
        t25b = 0x00000001u;
        t25r = (t25a & t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
        state.regs[0] = t25r;
    // 0x004200fa: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00420108;
    // 0x004200fc: 8b4dec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t27;
    // 0x004200ff: 51 PUSH
        t28a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00420100: e87b72b200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00420105u)) return BatchLiftStatus::invalid_memory;
        t29_call_status = spore_lift_00f47380(memory, state);
        if (t29_call_status != BatchLiftStatus::returned) return t29_call_status;
        if (state.eip != 0x00420105u) return BatchLiftStatus::invalid_control_flow;
    // 0x00420105: 83c404 ADD
        t30a = state.regs[4];
        t30b = 0x00000004u;
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[4] = t30r;
    // 0x00420108: ebc0 JMP
    L_00420108:
        goto L_004200ca;
    // 0x0042010a: 8b4de8 MOV
    L_0042010a:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t32;
    // 0x0042010d: e8de1d0e00 CALL
        t33_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00501ef0u, 0x00420112u);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
        if (state.eip != 0x00420112u) return BatchLiftStatus::invalid_control_flow;
    // 0x00420112: 8be5 MOV
        t34 = state.regs[5];
        state.regs[4] = t34;
    // 0x00420114: 5d POP
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t35a;
    // 0x00420115: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
