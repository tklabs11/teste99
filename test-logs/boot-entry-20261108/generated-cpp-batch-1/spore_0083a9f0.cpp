#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00837ff0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0083a9f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0083a9f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;

    // 0x0083a9f0: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0083a9f2: 683f742101 PUSH
        t1a = 0x0121743fu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0083a9f7: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x0083a9fd: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0083a9fe: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa05: 51 PUSH
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa06: 53 PUSH
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa07: 56 PUSH
        t7a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa08: 8bf1 MOV
        t8 = state.regs[1];
        state.regs[6] = t8;
    // 0x0083aa0a: 57 PUSH
        t9a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa0b: bfac7b6601 MOV
        t10 = 0x01667bacu;
        state.regs[7] = t10;
    // 0x0083aa10: bbad7b6601 MOV
        t11 = 0x01667badu;
        state.regs[3] = t11;
    // 0x0083aa15: 8974240c MOV
        t12 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa19: 893e MOV
        t13 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa1b: 897e04 MOV
        t14 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa1e: 895e08 MOV
        t15 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa21: 33c0 XOR
        t16a = state.regs[0];
        t16b = state.regs[0];
        t16r = (t16a ^ t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[0] = t16r;
    // 0x0083aa23: 89442418 MOV
        t17 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa27: 897e10 MOV
        t18 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa2a: 897e14 MOV
        t19 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa2d: 895e18 MOV
        t20 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa30: 897e20 MOV
        t21 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa33: 897e24 MOV
        t22 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa36: 895e28 MOV
        t23 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa39: 894630 MOV
        t24 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa3c: 894634 MOV
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000034u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa3f: 894638 MOV
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000038u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa42: 894644 MOV
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000044u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa45: 894648 MOV
        t28 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000048u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa48: 89464c MOV
        t29 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000004cu), t29)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa4b: 894658 MOV
        t30 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000058u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa4e: 89465c MOV
        t31 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000005cu), t31)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa51: 894660 MOV
        t32 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000060u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa54: 8a4c2420 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t33 << 0u) & 0x000000ffu);
    // 0x0083aa58: 884e6c MOV
        t34 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000006cu), t34)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa5b: 8d4e74 LEA
        t35 = static_cast<std::uint32_t>(state.regs[6] + 0x00000074u);
        state.regs[1] = t35;
    // 0x0083aa5e: c644241805 MOV
        t36 = 0x00000005u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa63: 894670 MOV
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000070u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa66: e885d5ffff CALL
        t38_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00837ff0u, 0x0083aa6bu);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
        if (state.eip != 0x0083aa6bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083aa6b: 8b4c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t39;
    // 0x0083aa6f: 89beb8000000 MOV
        t40 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000000b8u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa75: 89bebc000000 MOV
        t41 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000000bcu), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa7b: 899ec0000000 MOV
        t42 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000000c0u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa81: 5f POP
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t43a;
    // 0x0083aa82: 8bc6 MOV
        t44 = state.regs[6];
        state.regs[0] = t44;
    // 0x0083aa84: 5e POP
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t45a;
    // 0x0083aa85: 5b POP
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t46a;
    // 0x0083aa86: 64890d00000000 MOV
        t47 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x0083aa8d: 83c410 ADD
        t48a = state.regs[4];
        t48b = 0x00000010u;
        t48r = static_cast<std::uint32_t>(t48a + t48b) & 0xffffffffu;
        batch_set_add_flags(state, t48a, t48b, t48r, 32u);
        state.regs[4] = t48r;
    // 0x0083aa90: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
