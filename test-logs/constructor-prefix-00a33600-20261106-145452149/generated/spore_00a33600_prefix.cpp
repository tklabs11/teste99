#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00743b50(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;

    // 0x00743b50: 8bc1 MOV
        t0 = state.regs[1];
        state.regs[0] = t0;
    // 0x00743b52: c70000000000 MOV
        t1 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t1)) return BatchLiftStatus::invalid_memory;
    // 0x00743b58: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}

#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00743b50(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921f00(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009222a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e64f0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00a33600(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30 = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t52 = 0;
    BatchLiftStatus t53_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    BatchLiftStatus t62_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;

    // 0x00a33600: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33602: 683e952101 PUSH
        t1a = 0x0121953eu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33607: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00a3360d: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00a3360e: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00a33615: 83ec2c SUB
        t5a = state.regs[4];
        t5b = 0x0000002cu;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00a33618: 53 PUSH
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33619: 55 PUSH
        t7a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00a3361a: 56 PUSH
        t8a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00a3361b: 8bf1 MOV
        t9 = state.regs[1];
        state.regs[6] = t9;
    // 0x00a3361d: 57 PUSH
        t10a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00a3361e: 89742438 MOV
        t11 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00a33622: c7460484b33e01 MOV
        t12 = 0x013eb384u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00a33629: 33db XOR
        t13a = state.regs[3];
        t13b = state.regs[3];
        t13r = (t13a ^ t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
        state.regs[3] = t13r;
    // 0x00a3362b: c706282d4501 MOV
        t14 = 0x01452d28u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00a33631: c74604142d4501 MOV
        t15 = 0x01452d14u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00a33638: 895c2444 MOV
        t16 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00a3363c: 895e08 MOV
        t17 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00a3363f: 895e0c MOV
        t18 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00a33642: 895e10 MOV
        t19 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00a33645: 895e14 MOV
        t20 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00a33648: 895e18 MOV
        t21 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00a3364b: 8d4e20 LEA
        t22 = static_cast<std::uint32_t>(state.regs[6] + 0x00000020u);
        state.regs[1] = t22;
    // 0x00a3364e: c644244401 MOV
        t23 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00a33653: 895e1c MOV
        t24 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00a33656: e8f504d1ff CALL
        if (!batch_guest_call32(memory, state, 0x00743b50u, 0x00a3365bu)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_00743b50(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00a3365bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00a3365b: bf01000000 MOV
        t26 = 0x00000001u;
        state.regs[7] = t26;
    // 0x00a33660: 57 PUSH
        t27a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33661: 8d4e28 LEA
        t28 = static_cast<std::uint32_t>(state.regs[6] + 0x00000028u);
        state.regs[1] = t28;
    // 0x00a33664: 53 PUSH
        t29a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33665: c644244c02 MOV
        t30 = 0x00000002u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00a3366a: e891e8eeff CALL
        if (!batch_guest_call32(memory, state, 0x00921f00u, 0x00a3366fu)) return BatchLiftStatus::invalid_memory;
        t31_call_status = spore_lift_00921f00(memory, state);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
        if (state.eip != 0x00a3366fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00a3366f: bd00f40100 MOV
        t32 = 0x0001f400u;
        state.regs[5] = t32;
    // 0x00a33674: 89ae90000000 MOV
        t33 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000090u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x00a3367a: 889e94000000 MOV
        t34 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000094u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00a33680: 889e95000000 MOV
        t35 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000095u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x00a33686: 889e96000000 MOV
        t36 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000096u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00a3368c: 889e97000000 MOV
        t37 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000097u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00a33692: 889e98000000 MOV
        t38 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000098u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x00a33698: 889e99000000 MOV
        t39 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000099u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x00a3369e: 889e9a000000 MOV
        t40 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000009au), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00a336a4: 889e9b000000 MOV
        t41 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000009bu), t41)) return BatchLiftStatus::invalid_memory;
    // 0x00a336aa: c7869c000000082a4501 MOV
        t42 = 0x01452a08u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000009cu), t42)) return BatchLiftStatus::invalid_memory;
    // 0x00a336b4: c786a0000000182a4501 MOV
        t43 = 0x01452a18u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000000a0u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x00a336be: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x00a336c6: 57 PUSH
        t45a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
    // 0x00a336c7: f30f1186a8000000 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x000000a8u))) return BatchLiftStatus::invalid_memory;
    // 0x00a336cf: f30f1005502f4501 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01452f50u)) return BatchLiftStatus::invalid_memory;
    // 0x00a336d7: 53 PUSH
        t48a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x00a336d8: 8d8eb8000000 LEA
        t49 = static_cast<std::uint32_t>(state.regs[6] + 0x000000b8u);
        state.regs[1] = t49;
    // 0x00a336de: c644244c05 MOV
        t50 = 0x00000005u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00a336e3: f30f1186ac000000 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x000000acu))) return BatchLiftStatus::invalid_memory;
    // 0x00a336eb: c786b000000002000000 MOV
        t52 = 0x00000002u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000000b0u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00a336f5: e8a6ebeeff CALL
        if (!batch_guest_call32(memory, state, 0x009222a0u, 0x00a336fau)) return BatchLiftStatus::invalid_memory;
        t53_call_status = spore_lift_009222a0(memory, state);
        if (t53_call_status != BatchLiftStatus::returned) return t53_call_status;
        if (state.eip != 0x00a336fau) return BatchLiftStatus::invalid_control_flow;
    // 0x00a336fa: 53 PUSH
        t54a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00a336fb: 53 PUSH
        t55a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x00a336fc: 68402f4501 PUSH
        t56a = 0x01452f40u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33701: 8d8ef8000000 LEA
        t57 = static_cast<std::uint32_t>(state.regs[6] + 0x000000f8u);
        state.regs[1] = t57;
    // 0x00a33707: c644245006 MOV
        t58 = 0x00000006u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x00a3370c: c786ec0000000a000000 MOV
        t59 = 0x0000000au;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000000ecu), t59)) return BatchLiftStatus::invalid_memory;
    // 0x00a33716: 89aef0000000 MOV
        t60 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000000f0u), t60)) return BatchLiftStatus::invalid_memory;
    // 0x00a3371c: c786f400000002000000 MOV
        t61 = 0x00000002u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000000f4u), t61)) return BatchLiftStatus::invalid_memory;
    // 0x00a33726: e8c52d7b00 CALL
        if (!batch_guest_call32(memory, state, 0x011e64f0u, 0x00a3372bu)) return BatchLiftStatus::invalid_memory;
        t62_call_status = spore_lift_011e64f0(memory, state);
        if (t62_call_status != BatchLiftStatus::returned) return t62_call_status;
        if (state.eip != 0x00a3372bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00a3372b: 8d8e98010000 LEA
        t63 = static_cast<std::uint32_t>(state.regs[6] + 0x00000198u);
        state.regs[1] = t63;
    // 0x00a33731: c644244407 MOV
        t64 = 0x00000007u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t64)) return BatchLiftStatus::invalid_memory;
    state.eip = 0x00a33736u;
    return BatchLiftStatus::unsupported_dependency;
}
