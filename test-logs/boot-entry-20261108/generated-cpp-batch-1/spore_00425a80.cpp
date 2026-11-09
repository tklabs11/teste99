#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402420(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00425b14(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00425bc6(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00425bf8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00425c84(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00425d24(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0042dee0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0042eb20(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00425a80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00425a80u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0;
    BatchLiftStatus t64_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76a = 0, t76b = 0, t76r = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81a = 0, t81b = 0, t81r = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;
    std::uint32_t t87 = 0;
    BatchLiftStatus t88_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t99a = 0, t99c = 0, t99r = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101a = 0, t101b = 0, t101r = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104a = 0, t104c = 0, t104r = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110a = 0, t110b = 0, t110r = 0;
    std::uint32_t t112a = 0;
    std::uint32_t t113a = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115a = 0, t115c = 0, t115r = 0;
    std::uint32_t t116a = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t118a = 0, t118b = 0, t118r = 0;
    std::uint32_t t119a = 0;
    BatchLiftStatus t120_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t121a = 0, t121b = 0, t121r = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126 = 0;
    std::uint32_t t127 = 0;
    std::uint32_t t128 = 0;
    std::uint32_t t129 = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132a = 0, t132b = 0, t132r = 0;
    std::uint32_t t133a = 0, t133c = 0, t133r = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t135a = 0, t135b = 0, t135r = 0;
    std::uint32_t t136a = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t138a = 0;
    std::uint32_t t139 = 0;
    std::uint32_t t140a = 0;
    BatchLiftStatus t141_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t142a = 0, t142b = 0, t142r = 0;
    std::uint32_t t143 = 0;
    std::uint32_t t144 = 0;
    std::uint32_t t145 = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t147 = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150a = 0, t150b = 0, t150r = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153 = 0;
    std::uint32_t t154 = 0;
    std::uint32_t t155 = 0;
    std::uint32_t t156 = 0;
    std::uint32_t t157a = 0, t157b = 0, t157r = 0;
    std::uint32_t t159 = 0;
    std::uint32_t t160 = 0;
    std::uint32_t t161 = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163a = 0, t163b = 0, t163r = 0;
    std::uint32_t t164 = 0;
    std::uint32_t t165a = 0, t165b = 0, t165r = 0;
    std::uint32_t t166 = 0;
    std::uint32_t t167 = 0;
    std::uint32_t t169 = 0;
    std::uint32_t t170 = 0;
    std::uint32_t t171a = 0, t171b = 0, t171r = 0;
    std::uint32_t t172 = 0;
    std::uint32_t t173 = 0;
    std::uint32_t t174 = 0;
    std::uint32_t t175 = 0;
    std::uint32_t t176 = 0;
    std::uint32_t t177 = 0;
    std::uint32_t t178a = 0, t178b = 0, t178r = 0;
    std::uint32_t t179a = 0, t179c = 0, t179r = 0;
    std::uint32_t t180 = 0;
    std::uint32_t t181a = 0, t181b = 0, t181r = 0;
    std::uint32_t t182a = 0;
    std::uint32_t t183 = 0;
    std::uint32_t t184a = 0;
    std::uint32_t t185 = 0;
    std::uint32_t t186a = 0;
    BatchLiftStatus t187_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t188a = 0, t188b = 0, t188r = 0;
    std::uint32_t t189 = 0;
    std::uint32_t t190 = 0;
    std::uint32_t t191 = 0;
    std::uint32_t t192 = 0;
    std::uint32_t t193 = 0;
    std::uint32_t t194 = 0;
    std::uint32_t t195 = 0;
    std::uint32_t t196 = 0;
    std::uint32_t t197a = 0, t197b = 0, t197r = 0;
    std::uint32_t t198a = 0, t198c = 0, t198r = 0;
    std::uint32_t t199 = 0;
    std::uint32_t t200 = 0;
    std::uint32_t t201 = 0;
    std::uint32_t t202 = 0;
    std::uint32_t t203a = 0, t203b = 0, t203r = 0;
    std::uint32_t t205 = 0;
    std::uint32_t t206a = 0, t206b = 0, t206r = 0;
    std::uint32_t t208 = 0;
    std::uint32_t t209 = 0;
    std::uint32_t t210 = 0;
    std::uint32_t t211a = 0;
    BatchLiftStatus t212_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t213a = 0, t213b = 0, t213r = 0;
    std::uint32_t t214 = 0;
    std::uint32_t t215 = 0;
    std::uint32_t t216 = 0;
    std::uint32_t t217 = 0;
    std::uint32_t t218 = 0;
    std::uint32_t t219 = 0;
    std::uint32_t t220 = 0;
    std::uint32_t t221 = 0;
    std::uint32_t t222 = 0;
    std::uint32_t t223 = 0;
    std::uint32_t t224 = 0;
    std::uint32_t t225a = 0;
    std::uint32_t t226 = 0;
    std::uint32_t t227a = 0;

    // 0x00425a80: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00425a81: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00425a83: 81ec84000000 SUB
        t2a = state.regs[4];
        t2b = 0x00000084u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00425a89: 56 PUSH
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00425a8a: 894d8c MOV
        t4 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00425a8d: 8b458c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x00425a90: 8b4d8c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00425a93: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t7;
    // 0x00425a96: 3b5108 CMP
        t8a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t8b)) return BatchLiftStatus::invalid_memory;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x00425a99: 0f84ff000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425b9e;
    // 0x00425a9f: 8b450c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x00425aa2: 8945fc MOV
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00425aa5: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x00425aa8: 3b4d08 CMP
        t13a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t13b)) return BatchLiftStatus::invalid_memory;
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x00425aab: 7214 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00425ac1;
    // 0x00425aad: 8b558c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t15;
    // 0x00425ab0: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t16;
    // 0x00425ab3: 3b4204 CMP
        t17a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t17b)) return BatchLiftStatus::invalid_memory;
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x00425ab6: 7309 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00425ac1;
    // 0x00425ab8: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x00425abb: 83c104 ADD
        t20a = state.regs[1];
        t20b = 0x00000004u;
        t20r = static_cast<std::uint32_t>(t20a + t20b) & 0xffffffffu;
        batch_set_add_flags(state, t20a, t20b, t20r, 32u);
        state.regs[1] = t20r;
    // 0x00425abe: 894dfc MOV
        t21 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00425ac1: 8b558c MOV
    L_00425ac1:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x00425ac4: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x00425ac7: 8945e8 MOV
        t24 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00425aca: 837de800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t25a)) return BatchLiftStatus::invalid_memory;
        t25b = 0x00000000u;
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
    // 0x00425ace: 743d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425b0d;
    // 0x00425ad0: 8b4d8c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t27;
    // 0x00425ad3: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t28;
    // 0x00425ad6: 83ea04 SUB
        t29a = state.regs[2];
        t29b = 0x00000004u;
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
        state.regs[2] = t29r;
    // 0x00425ad9: 8955dc MOV
        t30 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00425adc: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t31;
    // 0x00425adf: 8b4ddc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t32;
    // 0x00425ae2: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t33;
    // 0x00425ae4: 8910 MOV
        t34 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00425ae6: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t35;
    // 0x00425ae9: 833800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t36a)) return BatchLiftStatus::invalid_memory;
        t36b = 0x00000000u;
        t36r = static_cast<std::uint32_t>(t36a - t36b) & 0xffffffffu;
        batch_set_sub_flags(state, t36a, t36b, t36r, 32u);
    // 0x00425aec: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425b05;
    // 0x00425aee: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t38;
    // 0x00425af1: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t39;
    // 0x00425af3: 8955e0 MOV
        t40 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00425af6: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t41;
    // 0x00425af9: 83c008 ADD
        t42a = state.regs[0];
        t42b = 0x00000008u;
        t42r = static_cast<std::uint32_t>(t42a + t42b) & 0xffffffffu;
        batch_set_add_flags(state, t42a, t42b, t42r, 32u);
        state.regs[0] = t42r;
    // 0x00425afc: b901000000 MOV
        t43 = 0x00000001u;
        state.regs[1] = t43;
    // 0x00425b01: f00fc108 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t44a)) return BatchLiftStatus::invalid_memory;
        t44b = state.regs[1];
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t44r)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t44a;
    // 0x00425b05: 8b55e8 MOV
    L_00425b05:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t45;
    // 0x00425b08: 895588 MOV
        t46 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff88u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00425b0b: eb07 JMP
        goto L_00425b14;
    // 0x00425b0d: c7458800000000 MOV
    L_00425b0d:
        t48 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff88u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00425b14: 8b458c MOV
    L_00425b14:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t49;
    // 0x00425b17: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t50;
    // 0x00425b1a: 894dc0 MOV
        t51 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc0u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x00425b1d: 8b558c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t52;
    // 0x00425b20: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t53;
    // 0x00425b23: 83e804 SUB
        t54a = state.regs[0];
        t54b = 0x00000004u;
        t54r = static_cast<std::uint32_t>(t54a - t54b) & 0xffffffffu;
        batch_set_sub_flags(state, t54a, t54b, t54r, 32u);
        state.regs[0] = t54r;
    // 0x00425b26: 8945c4 MOV
        t55 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t55)) return BatchLiftStatus::invalid_memory;
    // 0x00425b29: c645da00 MOV
        t56 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdau), t56)) return BatchLiftStatus::invalid_memory;
    // 0x00425b2d: c645db00 MOV
        t57 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdbu), t57)) return BatchLiftStatus::invalid_memory;
    // 0x00425b31: 8b4dc0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc0u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t58;
    // 0x00425b34: 51 PUSH
        t59a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
    // 0x00425b35: 8b55c4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t60;
    // 0x00425b38: 52 PUSH
        t61a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x00425b39: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t62;
    // 0x00425b3c: 50 PUSH
        t63a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
    // 0x00425b3d: e8de8f0000 CALL
        if (!batch_guest_call32(memory, state, 0x0042eb20u, 0x00425b42u)) return BatchLiftStatus::invalid_memory;
        t64_call_status = spore_lift_0042eb20(memory, state);
        if (t64_call_status != BatchLiftStatus::returned) return t64_call_status;
        if (state.eip != 0x00425b42u) return BatchLiftStatus::invalid_control_flow;
    // 0x00425b42: 83c40c ADD
        t65a = state.regs[4];
        t65b = 0x0000000cu;
        t65r = static_cast<std::uint32_t>(t65a + t65b) & 0xffffffffu;
        batch_set_add_flags(state, t65a, t65b, t65r, 32u);
        state.regs[4] = t65r;
    // 0x00425b45: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t66;
    // 0x00425b48: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t67;
    // 0x00425b4a: 8955b8 MOV
        t68 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x00425b4d: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t69;
    // 0x00425b50: 8b4db8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t70;
    // 0x00425b53: 3b08 CMP
        t71a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t71b)) return BatchLiftStatus::invalid_memory;
        t71r = static_cast<std::uint32_t>(t71a - t71b) & 0xffffffffu;
        batch_set_sub_flags(state, t71a, t71b, t71r, 32u);
    // 0x00425b55: 7433 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425b8a;
    // 0x00425b57: 8b5508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t73;
    // 0x00425b5a: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t74;
    // 0x00425b5c: 8945bc MOV
        t75 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffbcu), t75)) return BatchLiftStatus::invalid_memory;
    // 0x00425b5f: 837db800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t76a)) return BatchLiftStatus::invalid_memory;
        t76b = 0x00000000u;
        t76r = static_cast<std::uint32_t>(t76a - t76b) & 0xffffffffu;
        batch_set_sub_flags(state, t76a, t76b, t76r, 32u);
    // 0x00425b63: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425b74;
    // 0x00425b65: 8b4db8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t78;
    // 0x00425b68: 83c108 ADD
        t79a = state.regs[1];
        t79b = 0x00000008u;
        t79r = static_cast<std::uint32_t>(t79a + t79b) & 0xffffffffu;
        batch_set_add_flags(state, t79a, t79b, t79r, 32u);
        state.regs[1] = t79r;
    // 0x00425b6b: ba01000000 MOV
        t80 = 0x00000001u;
        state.regs[2] = t80;
    // 0x00425b70: f00fc111 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t81a)) return BatchLiftStatus::invalid_memory;
        t81b = state.regs[2];
        t81r = static_cast<std::uint32_t>(t81a + t81b) & 0xffffffffu;
        batch_set_add_flags(state, t81a, t81b, t81r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t81r)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t81a;
    // 0x00425b74: 8b4508 MOV
    L_00425b74:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t82)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t82;
    // 0x00425b77: 8b4db8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t83;
    // 0x00425b7a: 8908 MOV
        t84 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t84)) return BatchLiftStatus::invalid_memory;
    // 0x00425b7c: 837dbc00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffbcu), t85a)) return BatchLiftStatus::invalid_memory;
        t85b = 0x00000000u;
        t85r = static_cast<std::uint32_t>(t85a - t85b) & 0xffffffffu;
        batch_set_sub_flags(state, t85a, t85b, t85r, 32u);
    // 0x00425b80: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425b8a;
    // 0x00425b82: 8b4dbc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffbcu), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t87;
    // 0x00425b85: e896c8fdff CALL
        if (!batch_guest_call32(memory, state, 0x00402420u, 0x00425b8au)) return BatchLiftStatus::invalid_memory;
        t88_call_status = spore_lift_00402420(memory, state);
        if (t88_call_status != BatchLiftStatus::returned) return t88_call_status;
        if (state.eip != 0x00425b8au) return BatchLiftStatus::invalid_control_flow;
    // 0x00425b8a: 8b558c MOV
    L_00425b8a:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t89;
    // 0x00425b8d: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t90)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t90;
    // 0x00425b90: 83c004 ADD
        t91a = state.regs[0];
        t91b = 0x00000004u;
        t91r = static_cast<std::uint32_t>(t91a + t91b) & 0xffffffffu;
        batch_set_add_flags(state, t91a, t91b, t91r, 32u);
        state.regs[0] = t91r;
    // 0x00425b93: 8b4d8c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t92)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t92;
    // 0x00425b96: 894104 MOV
        t93 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t93)) return BatchLiftStatus::invalid_memory;
    // 0x00425b99: e986010000 JMP
        goto L_00425d24;
    // 0x00425b9e: 8b558c MOV
    L_00425b9e:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t95)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t95;
    // 0x00425ba1: 8b458c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t96;
    // 0x00425ba4: 8b4a04 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t97;
    // 0x00425ba7: 2b08 SUB
        t98a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t98b)) return BatchLiftStatus::invalid_memory;
        t98r = static_cast<std::uint32_t>(t98a - t98b) & 0xffffffffu;
        batch_set_sub_flags(state, t98a, t98b, t98r, 32u);
        state.regs[1] = t98r;
    // 0x00425ba9: c1f902 SAR
        t99a = state.regs[1];
        t99c = 2u;
        if (t99c != 0u) {
        t99r = (t99a >> t99c) | ((t99a & 0x80000000u) ? (0xffffffffu << (32u - t99c)) : 0u);
        batch_set_sar_flags(state, t99a, t99c, t99r, 32u);
            state.regs[1] = t99r;
        }
    // 0x00425bac: 894df0 MOV
        t100 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t100)) return BatchLiftStatus::invalid_memory;
    // 0x00425baf: 837df000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t101a)) return BatchLiftStatus::invalid_memory;
        t101b = 0x00000000u;
        t101r = static_cast<std::uint32_t>(t101a - t101b) & 0xffffffffu;
        batch_set_sub_flags(state, t101a, t101b, t101r, 32u);
    // 0x00425bb3: 760a JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00425bbf;
    // 0x00425bb5: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t103)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t103;
    // 0x00425bb8: d1e2 SHL
        t104a = state.regs[2];
        t104c = 1u;
        if (t104c != 0u) {
        t104r = static_cast<std::uint32_t>(t104a << t104c) & 0xffffffffu;
        batch_set_shl_flags(state, t104a, t104c, t104r, 32u);
            state.regs[2] = t104r;
        }
    // 0x00425bba: 895584 MOV
        t105 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t105)) return BatchLiftStatus::invalid_memory;
    // 0x00425bbd: eb07 JMP
        goto L_00425bc6;
    // 0x00425bbf: c7458401000000 MOV
    L_00425bbf:
        t107 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t107)) return BatchLiftStatus::invalid_memory;
    // 0x00425bc6: 8b4584 MOV
    L_00425bc6:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t108)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t108;
    // 0x00425bc9: 8945f8 MOV
        t109 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t109)) return BatchLiftStatus::invalid_memory;
    // 0x00425bcc: 837df800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t110a)) return BatchLiftStatus::invalid_memory;
        t110b = 0x00000000u;
        t110r = static_cast<std::uint32_t>(t110a - t110b) & 0xffffffffu;
        batch_set_sub_flags(state, t110a, t110b, t110r, 32u);
    // 0x00425bd0: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425bf1;
    // 0x00425bd2: 6a00 PUSH
        t112a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t112a)) return BatchLiftStatus::invalid_memory;
    // 0x00425bd4: 6a04 PUSH
        t113a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t113a)) return BatchLiftStatus::invalid_memory;
    // 0x00425bd6: 8b4df8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t114)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t114;
    // 0x00425bd9: c1e102 SHL
        t115a = state.regs[1];
        t115c = 2u;
        if (t115c != 0u) {
        t115r = static_cast<std::uint32_t>(t115a << t115c) & 0xffffffffu;
        batch_set_shl_flags(state, t115a, t115c, t115r, 32u);
            state.regs[1] = t115r;
        }
    // 0x00425bdc: 51 PUSH
        t116a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t116a)) return BatchLiftStatus::invalid_memory;
    // 0x00425bdd: 8b558c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t117)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t117;
    // 0x00425be0: 83c20c ADD
        t118a = state.regs[2];
        t118b = 0x0000000cu;
        t118r = static_cast<std::uint32_t>(t118a + t118b) & 0xffffffffu;
        batch_set_add_flags(state, t118a, t118b, t118r, 32u);
        state.regs[2] = t118r;
    // 0x00425be3: 52 PUSH
        t119a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t119a)) return BatchLiftStatus::invalid_memory;
    // 0x00425be4: e8f7820000 CALL
        if (!batch_guest_call32(memory, state, 0x0042dee0u, 0x00425be9u)) return BatchLiftStatus::invalid_memory;
        t120_call_status = spore_lift_0042dee0(memory, state);
        if (t120_call_status != BatchLiftStatus::returned) return t120_call_status;
        if (state.eip != 0x00425be9u) return BatchLiftStatus::invalid_control_flow;
    // 0x00425be9: 83c410 ADD
        t121a = state.regs[4];
        t121b = 0x00000010u;
        t121r = static_cast<std::uint32_t>(t121a + t121b) & 0xffffffffu;
        batch_set_add_flags(state, t121a, t121b, t121r, 32u);
        state.regs[4] = t121r;
    // 0x00425bec: 894580 MOV
        t122 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t122)) return BatchLiftStatus::invalid_memory;
    // 0x00425bef: eb07 JMP
        goto L_00425bf8;
    // 0x00425bf1: c7458000000000 MOV
    L_00425bf1:
        t124 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t124)) return BatchLiftStatus::invalid_memory;
    // 0x00425bf8: 8b4580 MOV
    L_00425bf8:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t125)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t125;
    // 0x00425bfb: 8945ec MOV
        t126 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t126)) return BatchLiftStatus::invalid_memory;
    // 0x00425bfe: 8b4d8c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t127)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t127;
    // 0x00425c01: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t128)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t128;
    // 0x00425c03: 8955ac MOV
        t129 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffacu), t129)) return BatchLiftStatus::invalid_memory;
    // 0x00425c06: c645b301 MOV
        t130 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb3u), t130)) return BatchLiftStatus::invalid_memory;
    // 0x00425c0a: 8b7508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t131)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t131;
    // 0x00425c0d: 2b75ac SUB
        t132a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffacu), t132b)) return BatchLiftStatus::invalid_memory;
        t132r = static_cast<std::uint32_t>(t132a - t132b) & 0xffffffffu;
        batch_set_sub_flags(state, t132a, t132b, t132r, 32u);
        state.regs[6] = t132r;
    // 0x00425c10: c1fe02 SAR
        t133a = state.regs[6];
        t133c = 2u;
        if (t133c != 0u) {
        t133r = (t133a >> t133c) | ((t133a & 0x80000000u) ? (0xffffffffu << (32u - t133c)) : 0u);
        batch_set_sar_flags(state, t133a, t133c, t133r, 32u);
            state.regs[6] = t133r;
        }
    // 0x00425c13: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t134)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t134;
    // 0x00425c16: 2b45ac SUB
        t135a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffacu), t135b)) return BatchLiftStatus::invalid_memory;
        t135r = static_cast<std::uint32_t>(t135a - t135b) & 0xffffffffu;
        batch_set_sub_flags(state, t135a, t135b, t135r, 32u);
        state.regs[0] = t135r;
    // 0x00425c19: 50 PUSH
        t136a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t136a)) return BatchLiftStatus::invalid_memory;
    // 0x00425c1a: 8b4dac MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffacu), t137)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t137;
    // 0x00425c1d: 51 PUSH
        t138a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t138a)) return BatchLiftStatus::invalid_memory;
    // 0x00425c1e: 8b55ec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t139)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t139;
    // 0x00425c21: 52 PUSH
        t140a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t140a)) return BatchLiftStatus::invalid_memory;
    // 0x00425c22: e81dabdb00 CALL
        t141_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00425c27u);
        if (t141_call_status != BatchLiftStatus::returned) return t141_call_status;
        if (state.eip != 0x00425c27u) return BatchLiftStatus::invalid_control_flow;
    // 0x00425c27: 83c40c ADD
        t142a = state.regs[4];
        t142b = 0x0000000cu;
        t142r = static_cast<std::uint32_t>(t142a + t142b) & 0xffffffffu;
        batch_set_add_flags(state, t142a, t142b, t142r, 32u);
        state.regs[4] = t142r;
    // 0x00425c2a: 8d04b0 LEA
        t143 = static_cast<std::uint32_t>(state.regs[0] + state.regs[6] * 4u + 0x00000000u);
        state.regs[0] = t143;
    // 0x00425c2d: 8945b4 MOV
        t144 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb4u), t144)) return BatchLiftStatus::invalid_memory;
    // 0x00425c30: c645b201 MOV
        t145 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb2u), t145)) return BatchLiftStatus::invalid_memory;
    // 0x00425c34: 8b4db4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb4u), t146)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t146;
    // 0x00425c37: 894df4 MOV
        t147 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t147)) return BatchLiftStatus::invalid_memory;
    // 0x00425c3a: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t148)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t148;
    // 0x00425c3d: 8955e4 MOV
        t149 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t149)) return BatchLiftStatus::invalid_memory;
    // 0x00425c40: 837de400 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t150a)) return BatchLiftStatus::invalid_memory;
        t150b = 0x00000000u;
        t150r = static_cast<std::uint32_t>(t150a - t150b) & 0xffffffffu;
        batch_set_sub_flags(state, t150a, t150b, t150r, 32u);
    // 0x00425c44: 7434 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425c7a;
    // 0x00425c46: 8b45e4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t152)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t152;
    // 0x00425c49: 8b4d0c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t153)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t153;
    // 0x00425c4c: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t154)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t154;
    // 0x00425c4e: 8910 MOV
        t155 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t155)) return BatchLiftStatus::invalid_memory;
    // 0x00425c50: 8b45e4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t156)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t156;
    // 0x00425c53: 833800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t157a)) return BatchLiftStatus::invalid_memory;
        t157b = 0x00000000u;
        t157r = static_cast<std::uint32_t>(t157a - t157b) & 0xffffffffu;
        batch_set_sub_flags(state, t157a, t157b, t157r, 32u);
    // 0x00425c56: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425c6f;
    // 0x00425c58: 8b4de4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t159)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t159;
    // 0x00425c5b: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t160)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t160;
    // 0x00425c5d: 8955a8 MOV
        t161 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa8u), t161)) return BatchLiftStatus::invalid_memory;
    // 0x00425c60: 8b45a8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa8u), t162)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t162;
    // 0x00425c63: 83c008 ADD
        t163a = state.regs[0];
        t163b = 0x00000008u;
        t163r = static_cast<std::uint32_t>(t163a + t163b) & 0xffffffffu;
        batch_set_add_flags(state, t163a, t163b, t163r, 32u);
        state.regs[0] = t163r;
    // 0x00425c66: b901000000 MOV
        t164 = 0x00000001u;
        state.regs[1] = t164;
    // 0x00425c6b: f00fc108 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t165a)) return BatchLiftStatus::invalid_memory;
        t165b = state.regs[1];
        t165r = static_cast<std::uint32_t>(t165a + t165b) & 0xffffffffu;
        batch_set_add_flags(state, t165a, t165b, t165r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t165r)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t165a;
    // 0x00425c6f: 8b55e4 MOV
    L_00425c6f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t166)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t166;
    // 0x00425c72: 89957cffffff MOV
        t167 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t167)) return BatchLiftStatus::invalid_memory;
    // 0x00425c78: eb0a JMP
        goto L_00425c84;
    // 0x00425c7a: c7857cffffff00000000 MOV
    L_00425c7a:
        t169 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t169)) return BatchLiftStatus::invalid_memory;
    // 0x00425c84: 8b45f4 MOV
    L_00425c84:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t170)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t170;
    // 0x00425c87: 83c004 ADD
        t171a = state.regs[0];
        t171b = 0x00000004u;
        t171r = static_cast<std::uint32_t>(t171a + t171b) & 0xffffffffu;
        batch_set_add_flags(state, t171a, t171b, t171r, 32u);
        state.regs[0] = t171r;
    // 0x00425c8a: 8945f4 MOV
        t172 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t172)) return BatchLiftStatus::invalid_memory;
    // 0x00425c8d: 8b4d8c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t173)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t173;
    // 0x00425c90: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t174)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t174;
    // 0x00425c93: 89559c MOV
        t175 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff9cu), t175)) return BatchLiftStatus::invalid_memory;
    // 0x00425c96: c645a301 MOV
        t176 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa3u), t176)) return BatchLiftStatus::invalid_memory;
    // 0x00425c9a: 8b759c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff9cu), t177)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t177;
    // 0x00425c9d: 2b7508 SUB
        t178a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t178b)) return BatchLiftStatus::invalid_memory;
        t178r = static_cast<std::uint32_t>(t178a - t178b) & 0xffffffffu;
        batch_set_sub_flags(state, t178a, t178b, t178r, 32u);
        state.regs[6] = t178r;
    // 0x00425ca0: c1fe02 SAR
        t179a = state.regs[6];
        t179c = 2u;
        if (t179c != 0u) {
        t179r = (t179a >> t179c) | ((t179a & 0x80000000u) ? (0xffffffffu << (32u - t179c)) : 0u);
        batch_set_sar_flags(state, t179a, t179c, t179r, 32u);
            state.regs[6] = t179r;
        }
    // 0x00425ca3: 8b459c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff9cu), t180)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t180;
    // 0x00425ca6: 2b4508 SUB
        t181a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t181b)) return BatchLiftStatus::invalid_memory;
        t181r = static_cast<std::uint32_t>(t181a - t181b) & 0xffffffffu;
        batch_set_sub_flags(state, t181a, t181b, t181r, 32u);
        state.regs[0] = t181r;
    // 0x00425ca9: 50 PUSH
        t182a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t182a)) return BatchLiftStatus::invalid_memory;
    // 0x00425caa: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t183)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t183;
    // 0x00425cad: 51 PUSH
        t184a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t184a)) return BatchLiftStatus::invalid_memory;
    // 0x00425cae: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t185)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t185;
    // 0x00425cb1: 52 PUSH
        t186a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t186a)) return BatchLiftStatus::invalid_memory;
    // 0x00425cb2: e88daadb00 CALL
        t187_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00425cb7u);
        if (t187_call_status != BatchLiftStatus::returned) return t187_call_status;
        if (state.eip != 0x00425cb7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00425cb7: 83c40c ADD
        t188a = state.regs[4];
        t188b = 0x0000000cu;
        t188r = static_cast<std::uint32_t>(t188a + t188b) & 0xffffffffu;
        batch_set_add_flags(state, t188a, t188b, t188r, 32u);
        state.regs[4] = t188r;
    // 0x00425cba: 8d04b0 LEA
        t189 = static_cast<std::uint32_t>(state.regs[0] + state.regs[6] * 4u + 0x00000000u);
        state.regs[0] = t189;
    // 0x00425cbd: 8945a4 MOV
        t190 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t190)) return BatchLiftStatus::invalid_memory;
    // 0x00425cc0: c645a201 MOV
        t191 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa2u), t191)) return BatchLiftStatus::invalid_memory;
    // 0x00425cc4: 8b4da4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t192)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t192;
    // 0x00425cc7: 894df4 MOV
        t193 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t193)) return BatchLiftStatus::invalid_memory;
    // 0x00425cca: 8b558c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t194)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t194;
    // 0x00425ccd: 8b458c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t195)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t195;
    // 0x00425cd0: 8b4a08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t196)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t196;
    // 0x00425cd3: 2b08 SUB
        t197a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t197b)) return BatchLiftStatus::invalid_memory;
        t197r = static_cast<std::uint32_t>(t197a - t197b) & 0xffffffffu;
        batch_set_sub_flags(state, t197a, t197b, t197r, 32u);
        state.regs[1] = t197r;
    // 0x00425cd5: c1f902 SAR
        t198a = state.regs[1];
        t198c = 2u;
        if (t198c != 0u) {
        t198r = (t198a >> t198c) | ((t198a & 0x80000000u) ? (0xffffffffu << (32u - t198c)) : 0u);
        batch_set_sar_flags(state, t198a, t198c, t198r, 32u);
            state.regs[1] = t198r;
        }
    // 0x00425cd8: 894d90 MOV
        t199 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff90u), t199)) return BatchLiftStatus::invalid_memory;
    // 0x00425cdb: 8b558c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t200)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t200;
    // 0x00425cde: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t201)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t201;
    // 0x00425ce0: 894594 MOV
        t202 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff94u), t202)) return BatchLiftStatus::invalid_memory;
    // 0x00425ce3: 837d9400 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff94u), t203a)) return BatchLiftStatus::invalid_memory;
        t203b = 0x00000000u;
        t203r = static_cast<std::uint32_t>(t203a - t203b) & 0xffffffffu;
        batch_set_sub_flags(state, t203a, t203b, t203r, 32u);
    // 0x00425ce7: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425d04;
    // 0x00425ce9: 8b4d94 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff94u), t205)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t205;
    // 0x00425cec: 8379fc00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0xfffffffcu), t206a)) return BatchLiftStatus::invalid_memory;
        t206b = 0x00000000u;
        t206r = static_cast<std::uint32_t>(t206a - t206b) & 0xffffffffu;
        batch_set_sub_flags(state, t206a, t206b, t206r, 32u);
    // 0x00425cf0: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00425d04;
    // 0x00425cf2: 8b5594 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff94u), t208)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t208;
    // 0x00425cf5: 895598 MOV
        t209 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff98u), t209)) return BatchLiftStatus::invalid_memory;
    // 0x00425cf8: 8b4598 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff98u), t210)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t210;
    // 0x00425cfb: 50 PUSH
        t211a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t211a)) return BatchLiftStatus::invalid_memory;
    // 0x00425cfc: e87f16b200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00425d01u)) return BatchLiftStatus::invalid_memory;
        t212_call_status = spore_lift_00f47380(memory, state);
        if (t212_call_status != BatchLiftStatus::returned) return t212_call_status;
        if (state.eip != 0x00425d01u) return BatchLiftStatus::invalid_control_flow;
    // 0x00425d01: 83c404 ADD
        t213a = state.regs[4];
        t213b = 0x00000004u;
        t213r = static_cast<std::uint32_t>(t213a + t213b) & 0xffffffffu;
        batch_set_add_flags(state, t213a, t213b, t213r, 32u);
        state.regs[4] = t213r;
    // 0x00425d04: 8b4d8c MOV
    L_00425d04:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t214)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t214;
    // 0x00425d07: 8b55ec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t215)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t215;
    // 0x00425d0a: 8911 MOV
        t216 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t216)) return BatchLiftStatus::invalid_memory;
    // 0x00425d0c: 8b458c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t217)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t217;
    // 0x00425d0f: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t218)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t218;
    // 0x00425d12: 894804 MOV
        t219 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t219)) return BatchLiftStatus::invalid_memory;
    // 0x00425d15: 8b55f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t220)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t220;
    // 0x00425d18: 8b45ec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t221)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t221;
    // 0x00425d1b: 8d0c90 LEA
        t222 = static_cast<std::uint32_t>(state.regs[0] + state.regs[2] * 4u + 0x00000000u);
        state.regs[1] = t222;
    // 0x00425d1e: 8b558c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t223)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t223;
    // 0x00425d21: 894a08 MOV
        t224 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t224)) return BatchLiftStatus::invalid_memory;
    // 0x00425d24: 5e POP
    L_00425d24:
        if (!memory.load32(state.regs[4], t225a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t225a;
    // 0x00425d25: 8be5 MOV
        t226 = state.regs[5];
        state.regs[4] = t226;
    // 0x00425d27: 5d POP
        if (!memory.load32(state.regs[4], t227a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t227a;
    // 0x00425d28: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
