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
BatchLiftStatus spore_lift_00a0fdf0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a247f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a2a210(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a2a310(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a2f210(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a30e10(BatchLiftMemory& memory, BatchLiftState& state);
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
    BatchLiftStatus t65_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t66 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t76 = 0;
    BatchLiftStatus t77_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    BatchLiftStatus t80_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    BatchLiftStatus t83_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    BatchLiftStatus t86_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    BatchLiftStatus t89_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t90 = 0;
    std::uint32_t t91 = 0;
    BatchLiftStatus t92_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t94 = 0;
    std::uint32_t t95a = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98a = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104 = 0;
    BatchLiftStatus t106_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t107 = 0;
    std::uint32_t t108a = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110a = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112 = 0;
    BatchLiftStatus t113_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t114 = 0;
    std::uint32_t t115a = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117a = 0;
    std::uint32_t t118 = 0;
    std::uint32_t t119 = 0;
    BatchLiftStatus t120_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t121 = 0;
    std::uint32_t t122a = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124a = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126 = 0;
    BatchLiftStatus t127_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t128 = 0;
    std::uint32_t t129a = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131a = 0;
    std::uint32_t t132 = 0;
    std::uint32_t t133 = 0;
    BatchLiftStatus t134_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t139 = 0;
    std::uint32_t t140 = 0;
    std::uint32_t t141 = 0;
    std::uint32_t t142 = 0;
    std::uint32_t t143 = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t147 = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153 = 0;
    std::uint32_t t154 = 0;
    std::uint32_t t155 = 0;
    std::uint32_t t156 = 0;
    std::uint32_t t157 = 0;
    std::uint32_t t158 = 0;
    std::uint32_t t159 = 0;
    std::uint32_t t160 = 0;
    std::uint32_t t161 = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163 = 0;
    std::uint32_t t164 = 0;
    std::uint32_t t165 = 0;
    std::uint32_t t166a = 0;
    std::uint32_t t167 = 0;
    std::uint32_t t168a = 0;
    std::uint32_t t169 = 0;
    std::uint32_t t170 = 0;

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
    // 0x00a33736: e8b510ffff CALL
        if (!batch_guest_call32(memory, state, 0x00a247f0u, 0x00a3373bu)) return BatchLiftStatus::invalid_memory;
        t65_call_status = spore_lift_00a247f0(memory, state);
        if (t65_call_status != BatchLiftStatus::returned) return t65_call_status;
        if (state.eip != 0x00a3373bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00a3373b: 899ef8010000 MOV
        t66 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000001f8u), t66)) return BatchLiftStatus::invalid_memory;
    // 0x00a33741: 0f57c0 XORPS
        if (!batch_guest_xorps(state, 0u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00a33744: b8f4010000 MOV
        t68 = 0x000001f4u;
        state.regs[0] = t68;
    // 0x00a33749: c644244409 MOV
        t69 = 0x00000009u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t69)) return BatchLiftStatus::invalid_memory;
    // 0x00a3374e: 889efc010000 MOV
        t70 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x000001fcu), t70)) return BatchLiftStatus::invalid_memory;
    // 0x00a33754: c7860002000003000000 MOV
        t71 = 0x00000003u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000200u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x00a3375e: 898604020000 MOV
        t72 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000204u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x00a33764: 898608020000 MOV
        t73 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000208u), t73)) return BatchLiftStatus::invalid_memory;
    // 0x00a3376a: 89860c020000 MOV
        t74 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000020cu), t74)) return BatchLiftStatus::invalid_memory;
    // 0x00a33770: f30f118610020000 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x00000210u))) return BatchLiftStatus::invalid_memory;
    // 0x00a33778: 8d8e14020000 LEA
        t76 = static_cast<std::uint32_t>(state.regs[6] + 0x00000214u);
        state.regs[1] = t76;
    // 0x00a3377e: e86dc6fdff CALL
        if (!batch_guest_call32(memory, state, 0x00a0fdf0u, 0x00a33783u)) return BatchLiftStatus::invalid_memory;
        t77_call_status = spore_lift_00a0fdf0(memory, state);
        if (t77_call_status != BatchLiftStatus::returned) return t77_call_status;
        if (state.eip != 0x00a33783u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a33783: 8d8e64020000 LEA
        t78 = static_cast<std::uint32_t>(state.regs[6] + 0x00000264u);
        state.regs[1] = t78;
    // 0x00a33789: c64424440a MOV
        t79 = 0x0000000au;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t79)) return BatchLiftStatus::invalid_memory;
    // 0x00a3378e: e85dc6fdff CALL
        if (!batch_guest_call32(memory, state, 0x00a0fdf0u, 0x00a33793u)) return BatchLiftStatus::invalid_memory;
        t80_call_status = spore_lift_00a0fdf0(memory, state);
        if (t80_call_status != BatchLiftStatus::returned) return t80_call_status;
        if (state.eip != 0x00a33793u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a33793: 8d8eb4020000 LEA
        t81 = static_cast<std::uint32_t>(state.regs[6] + 0x000002b4u);
        state.regs[1] = t81;
    // 0x00a33799: c64424440b MOV
        t82 = 0x0000000bu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t82)) return BatchLiftStatus::invalid_memory;
    // 0x00a3379e: e84dc6fdff CALL
        if (!batch_guest_call32(memory, state, 0x00a0fdf0u, 0x00a337a3u)) return BatchLiftStatus::invalid_memory;
        t83_call_status = spore_lift_00a0fdf0(memory, state);
        if (t83_call_status != BatchLiftStatus::returned) return t83_call_status;
        if (state.eip != 0x00a337a3u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a337a3: 8d8e04030000 LEA
        t84 = static_cast<std::uint32_t>(state.regs[6] + 0x00000304u);
        state.regs[1] = t84;
    // 0x00a337a9: c64424440c MOV
        t85 = 0x0000000cu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t85)) return BatchLiftStatus::invalid_memory;
    // 0x00a337ae: e83dc6fdff CALL
        if (!batch_guest_call32(memory, state, 0x00a0fdf0u, 0x00a337b3u)) return BatchLiftStatus::invalid_memory;
        t86_call_status = spore_lift_00a0fdf0(memory, state);
        if (t86_call_status != BatchLiftStatus::returned) return t86_call_status;
        if (state.eip != 0x00a337b3u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a337b3: 8d8e54030000 LEA
        t87 = static_cast<std::uint32_t>(state.regs[6] + 0x00000354u);
        state.regs[1] = t87;
    // 0x00a337b9: c64424440d MOV
        t88 = 0x0000000du;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t88)) return BatchLiftStatus::invalid_memory;
    // 0x00a337be: e82dc6fdff CALL
        if (!batch_guest_call32(memory, state, 0x00a0fdf0u, 0x00a337c3u)) return BatchLiftStatus::invalid_memory;
        t89_call_status = spore_lift_00a0fdf0(memory, state);
        if (t89_call_status != BatchLiftStatus::returned) return t89_call_status;
        if (state.eip != 0x00a337c3u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a337c3: 8d8ea4030000 LEA
        t90 = static_cast<std::uint32_t>(state.regs[6] + 0x000003a4u);
        state.regs[1] = t90;
    // 0x00a337c9: c64424440e MOV
        t91 = 0x0000000eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t91)) return BatchLiftStatus::invalid_memory;
    // 0x00a337ce: e81dc6fdff CALL
        if (!batch_guest_call32(memory, state, 0x00a0fdf0u, 0x00a337d3u)) return BatchLiftStatus::invalid_memory;
        t92_call_status = spore_lift_00a0fdf0(memory, state);
        if (t92_call_status != BatchLiftStatus::returned) return t92_call_status;
        if (state.eip != 0x00a337d3u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a337d3: f30f100508614801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01486108u)) return BatchLiftStatus::invalid_memory;
    // 0x00a337db: 8d442413 LEA
        t94 = static_cast<std::uint32_t>(state.regs[4] + 0x00000013u);
        state.regs[0] = t94;
    // 0x00a337df: 50 PUSH
        t95a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t95a)) return BatchLiftStatus::invalid_memory;
    // 0x00a337e0: 8d4c2433 LEA
        t96 = static_cast<std::uint32_t>(state.regs[4] + 0x00000033u);
        state.regs[1] = t96;
    // 0x00a337e4: 889ef4030000 MOV
        t97 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x000003f4u), t97)) return BatchLiftStatus::invalid_memory;
    // 0x00a337ea: 51 PUSH
        t98a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t98a)) return BatchLiftStatus::invalid_memory;
    // 0x00a337eb: 889ef5030000 MOV
        t99 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x000003f5u), t99)) return BatchLiftStatus::invalid_memory;
    // 0x00a337f1: 8d8e04040000 LEA
        t100 = static_cast<std::uint32_t>(state.regs[6] + 0x00000404u);
        state.regs[1] = t100;
    // 0x00a337f7: c644244c0f MOV
        t101 = 0x0000000fu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t101)) return BatchLiftStatus::invalid_memory;
    // 0x00a337fc: 899ef8030000 MOV
        t102 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000003f8u), t102)) return BatchLiftStatus::invalid_memory;
    // 0x00a33802: 889efc030000 MOV
        t103 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x000003fcu), t103)) return BatchLiftStatus::invalid_memory;
    // 0x00a33808: c686fd03000001 MOV
        t104 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x000003fdu), t104)) return BatchLiftStatus::invalid_memory;
    // 0x00a3380f: f30f118600040000 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x00000400u))) return BatchLiftStatus::invalid_memory;
    // 0x00a33817: e8f469ffff CALL
        if (!batch_guest_call32(memory, state, 0x00a2a210u, 0x00a3381cu)) return BatchLiftStatus::invalid_memory;
        t106_call_status = spore_lift_00a2a210(memory, state);
        if (t106_call_status != BatchLiftStatus::returned) return t106_call_status;
        if (state.eip != 0x00a3381cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00a3381c: 8d542415 LEA
        t107 = static_cast<std::uint32_t>(state.regs[4] + 0x00000015u);
        state.regs[2] = t107;
    // 0x00a33820: 52 PUSH
        t108a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t108a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33821: 8d44242b LEA
        t109 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002bu);
        state.regs[0] = t109;
    // 0x00a33825: 50 PUSH
        t110a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t110a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33826: 8d8ef4130000 LEA
        t111 = static_cast<std::uint32_t>(state.regs[6] + 0x000013f4u);
        state.regs[1] = t111;
    // 0x00a3382c: c644244c10 MOV
        t112 = 0x00000010u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t112)) return BatchLiftStatus::invalid_memory;
    // 0x00a33831: e8dab9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00a2f210u, 0x00a33836u)) return BatchLiftStatus::invalid_memory;
        t113_call_status = spore_lift_00a2f210(memory, state);
        if (t113_call_status != BatchLiftStatus::returned) return t113_call_status;
        if (state.eip != 0x00a33836u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a33836: 8d4c2417 LEA
        t114 = static_cast<std::uint32_t>(state.regs[4] + 0x00000017u);
        state.regs[1] = t114;
    // 0x00a3383a: 51 PUSH
        t115a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t115a)) return BatchLiftStatus::invalid_memory;
    // 0x00a3383b: 8d54243b LEA
        t116 = static_cast<std::uint32_t>(state.regs[4] + 0x0000003bu);
        state.regs[2] = t116;
    // 0x00a3383f: 52 PUSH
        t117a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t117a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33840: 8d8ee4230000 LEA
        t118 = static_cast<std::uint32_t>(state.regs[6] + 0x000023e4u);
        state.regs[1] = t118;
    // 0x00a33846: c644244c11 MOV
        t119 = 0x00000011u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t119)) return BatchLiftStatus::invalid_memory;
    // 0x00a3384b: e8c069ffff CALL
        if (!batch_guest_call32(memory, state, 0x00a2a210u, 0x00a33850u)) return BatchLiftStatus::invalid_memory;
        t120_call_status = spore_lift_00a2a210(memory, state);
        if (t120_call_status != BatchLiftStatus::returned) return t120_call_status;
        if (state.eip != 0x00a33850u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a33850: 8d442419 LEA
        t121 = static_cast<std::uint32_t>(state.regs[4] + 0x00000019u);
        state.regs[0] = t121;
    // 0x00a33854: 50 PUSH
        t122a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t122a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33855: 8d4c242d LEA
        t123 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002du);
        state.regs[1] = t123;
    // 0x00a33859: 51 PUSH
        t124a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t124a)) return BatchLiftStatus::invalid_memory;
    // 0x00a3385a: 8d8ed4330000 LEA
        t125 = static_cast<std::uint32_t>(state.regs[6] + 0x000033d4u);
        state.regs[1] = t125;
    // 0x00a33860: c644244c12 MOV
        t126 = 0x00000012u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t126)) return BatchLiftStatus::invalid_memory;
    // 0x00a33865: e8a66affff CALL
        if (!batch_guest_call32(memory, state, 0x00a2a310u, 0x00a3386au)) return BatchLiftStatus::invalid_memory;
        t127_call_status = spore_lift_00a2a310(memory, state);
        if (t127_call_status != BatchLiftStatus::returned) return t127_call_status;
        if (state.eip != 0x00a3386au) return BatchLiftStatus::invalid_control_flow;
    // 0x00a3386a: 8d54241b LEA
        t128 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001bu);
        state.regs[2] = t128;
    // 0x00a3386e: 52 PUSH
        t129a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t129a)) return BatchLiftStatus::invalid_memory;
    // 0x00a3386f: 8d442435 LEA
        t130 = static_cast<std::uint32_t>(state.regs[4] + 0x00000035u);
        state.regs[0] = t130;
    // 0x00a33873: 50 PUSH
        t131a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t131a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33874: 8d8e24040800 LEA
        t132 = static_cast<std::uint32_t>(state.regs[6] + 0x00080424u);
        state.regs[1] = t132;
    // 0x00a3387a: c644244c13 MOV
        t133 = 0x00000013u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t133)) return BatchLiftStatus::invalid_memory;
    // 0x00a3387f: e88cd5ffff CALL
        if (!batch_guest_call32(memory, state, 0x00a30e10u, 0x00a33884u)) return BatchLiftStatus::invalid_memory;
        t134_call_status = spore_lift_00a30e10(memory, state);
        if (t134_call_status != BatchLiftStatus::returned) return t134_call_status;
        if (state.eip != 0x00a33884u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a33884: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x00a3388c: f30f100d140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 1u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x00a33894: f30f11860c8a1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x00118a0cu))) return BatchLiftStatus::invalid_memory;
    // 0x00a3389c: f30f118e108a1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 1u, static_cast<std::uint32_t>(state.regs[6] + 0x00118a10u))) return BatchLiftStatus::invalid_memory;
    // 0x00a338a4: bd28df5401 MOV
        t139 = 0x0154df28u;
        state.regs[5] = t139;
    // 0x00a338a9: 89be048a1100 MOV
        t140 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a04u), t140)) return BatchLiftStatus::invalid_memory;
    // 0x00a338af: 89ae008a1100 MOV
        t141 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a00u), t141)) return BatchLiftStatus::invalid_memory;
    // 0x00a338b5: 899e088a1100 MOV
        t142 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a08u), t142)) return BatchLiftStatus::invalid_memory;
    // 0x00a338bb: 899e148a1100 MOV
        t143 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a14u), t143)) return BatchLiftStatus::invalid_memory;
    // 0x00a338c1: f30f11862c8a1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x00118a2cu))) return BatchLiftStatus::invalid_memory;
    // 0x00a338c9: f30f118e308a1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 1u, static_cast<std::uint32_t>(state.regs[6] + 0x00118a30u))) return BatchLiftStatus::invalid_memory;
    // 0x00a338d1: 89be248a1100 MOV
        t146 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a24u), t146)) return BatchLiftStatus::invalid_memory;
    // 0x00a338d7: 89ae208a1100 MOV
        t147 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a20u), t147)) return BatchLiftStatus::invalid_memory;
    // 0x00a338dd: 899e288a1100 MOV
        t148 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a28u), t148)) return BatchLiftStatus::invalid_memory;
    // 0x00a338e3: 899e348a1100 MOV
        t149 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a34u), t149)) return BatchLiftStatus::invalid_memory;
    // 0x00a338e9: f30f11864c8a1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x00118a4cu))) return BatchLiftStatus::invalid_memory;
    // 0x00a338f1: f30f118e508a1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 1u, static_cast<std::uint32_t>(state.regs[6] + 0x00118a50u))) return BatchLiftStatus::invalid_memory;
    // 0x00a338f9: 89be448a1100 MOV
        t152 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a44u), t152)) return BatchLiftStatus::invalid_memory;
    // 0x00a338ff: 89ae408a1100 MOV
        t153 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a40u), t153)) return BatchLiftStatus::invalid_memory;
    // 0x00a33905: 899e488a1100 MOV
        t154 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a48u), t154)) return BatchLiftStatus::invalid_memory;
    // 0x00a3390b: 899e548a1100 MOV
        t155 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a54u), t155)) return BatchLiftStatus::invalid_memory;
    // 0x00a33911: 8d86608a1100 LEA
        t156 = static_cast<std::uint32_t>(state.regs[6] + 0x00118a60u);
        state.regs[0] = t156;
    // 0x00a33917: 895804 MOV
        t157 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t157)) return BatchLiftStatus::invalid_memory;
    // 0x00a3391a: 895808 MOV
        t158 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t158)) return BatchLiftStatus::invalid_memory;
    // 0x00a3391d: 89580c MOV
        t159 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t159)) return BatchLiftStatus::invalid_memory;
    // 0x00a33920: 8900 MOV
        t160 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t160)) return BatchLiftStatus::invalid_memory;
    // 0x00a33922: 8986648a1100 MOV
        t161 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a64u), t161)) return BatchLiftStatus::invalid_memory;
    // 0x00a33928: 899e688a1100 MOV
        t162 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a68u), t162)) return BatchLiftStatus::invalid_memory;
    // 0x00a3392e: 889e6c8a1100 MOV
        t163 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00118a6cu), t163)) return BatchLiftStatus::invalid_memory;
    // 0x00a33934: 899e708a1100 MOV
        t164 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00118a70u), t164)) return BatchLiftStatus::invalid_memory;
    // 0x00a3393a: 8d4c241d LEA
        t165 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001du);
        state.regs[1] = t165;
    // 0x00a3393e: 51 PUSH
        t166a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t166a)) return BatchLiftStatus::invalid_memory;
    // 0x00a3393f: 8d54242f LEA
        t167 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002fu);
        state.regs[2] = t167;
    // 0x00a33943: 52 PUSH
        t168a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t168a)) return BatchLiftStatus::invalid_memory;
    // 0x00a33944: 8d8e788a1100 LEA
        t169 = static_cast<std::uint32_t>(state.regs[6] + 0x00118a78u);
        state.regs[1] = t169;
    // 0x00a3394a: c644244c18 MOV
        t170 = 0x00000018u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t170)) return BatchLiftStatus::invalid_memory;
    state.eip = 0x00a3394fu;
    return BatchLiftStatus::unsupported_dependency;
}
