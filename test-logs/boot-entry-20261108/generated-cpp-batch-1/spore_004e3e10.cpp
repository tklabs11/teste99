#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0042dee0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004e3e90(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004e3ebd(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004e3f4c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004e3f87(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004e3fe0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004e4062(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f8b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_004e3e10(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004e3e10u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92a = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97a = 0, t97c = 0, t97r = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103a = 0, t103b = 0, t103r = 0;
    std::uint32_t t105a = 0;
    std::uint32_t t106a = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108a = 0, t108b = 0;
    std::uint32_t t109a = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0, t111b = 0, t111r = 0;
    std::uint32_t t112a = 0;
    BatchLiftStatus t113_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t114a = 0, t114b = 0, t114r = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t118 = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121a = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t123a = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126a = 0;
    BatchLiftStatus t127_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t128a = 0, t128b = 0, t128r = 0;
    std::uint32_t t129 = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132a = 0, t132b = 0, t132r = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t135 = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139 = 0;
    std::uint32_t t140 = 0;
    std::uint32_t t141 = 0;
    std::uint32_t t142 = 0;
    std::uint32_t t143 = 0;
    std::uint32_t t145 = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t147a = 0, t147b = 0, t147r = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150a = 0;
    std::uint32_t t151 = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153a = 0;
    std::uint32_t t154 = 0;
    std::uint32_t t155a = 0;
    BatchLiftStatus t156_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t157a = 0, t157b = 0, t157r = 0;
    std::uint32_t t158 = 0;
    std::uint32_t t159 = 0;
    std::uint32_t t160 = 0;
    std::uint32_t t161 = 0;
    std::uint32_t t162a = 0, t162b = 0, t162r = 0;
    std::uint32_t t164 = 0;
    std::uint32_t t165a = 0;
    std::uint32_t t166 = 0;
    std::uint32_t t167 = 0;
    std::uint32_t t168 = 0;
    std::uint32_t t169 = 0;
    std::uint32_t t170a = 0, t170b = 0, t170r = 0;
    std::uint32_t t172 = 0;
    std::uint32_t t173a = 0, t173b = 0, t173r = 0;
    std::uint32_t t175 = 0;
    std::uint32_t t176 = 0;
    std::uint32_t t177 = 0;
    std::uint32_t t178a = 0;
    BatchLiftStatus t179_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t180a = 0, t180b = 0, t180r = 0;
    std::uint32_t t181 = 0;
    std::uint32_t t182 = 0;
    std::uint32_t t183 = 0;
    std::uint32_t t184 = 0;
    std::uint32_t t185 = 0;
    std::uint32_t t186 = 0;
    std::uint32_t t187 = 0;
    std::uint32_t t188a = 0, t188b = 0;
    std::uint32_t t189a = 0, t189b = 0, t189r = 0;
    std::uint32_t t190 = 0;
    std::uint32_t t191 = 0;
    std::uint32_t t192 = 0;
    std::uint32_t t193a = 0;

    // 0x004e3e10: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e11: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x004e3e13: 81ec90000000 SUB
        t2a = state.regs[4];
        t2b = 0x00000090u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x004e3e19: 894d80 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e1c: 8b4580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x004e3e1f: 8b4d80 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x004e3e22: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t6;
    // 0x004e3e25: 3b5108 CMP
        t7a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t7b)) return BatchLiftStatus::invalid_memory;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x004e3e28: 0f84eb000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004e3f19;
    // 0x004e3e2e: 8b450c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x004e3e31: 8945fc MOV
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t10)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e34: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t11;
    // 0x004e3e37: 3b4d08 CMP
        t12a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t12b)) return BatchLiftStatus::invalid_memory;
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x004e3e3a: 7214 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_004e3e50;
    // 0x004e3e3c: 8b5580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x004e3e3f: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x004e3e42: 3b4204 CMP
        t16a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t16b)) return BatchLiftStatus::invalid_memory;
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x004e3e45: 7309 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_004e3e50;
    // 0x004e3e47: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t18;
    // 0x004e3e4a: 83c10c ADD
        t19a = state.regs[1];
        t19b = 0x0000000cu;
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[1] = t19r;
    // 0x004e3e4d: 894dfc MOV
        t20 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t20)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e50: 8b5580 MOV
    L_004e3e50:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x004e3e53: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x004e3e56: 8945e8 MOV
        t23 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e59: 837de800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t24a)) return BatchLiftStatus::invalid_memory;
        t24b = 0x00000000u;
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x004e3e5d: 7427 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004e3e86;
    // 0x004e3e5f: 8b4d80 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t26;
    // 0x004e3e62: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t27;
    // 0x004e3e65: 83ea0c SUB
        t28a = state.regs[2];
        t28b = 0x0000000cu;
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
        state.regs[2] = t28r;
    // 0x004e3e68: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t29;
    // 0x004e3e6b: 8b0a MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x004e3e6d: 8908 MOV
        t31 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e6f: 8b4a04 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t32;
    // 0x004e3e72: 894804 MOV
        t33 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e75: 8b5208 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x004e3e78: 895008 MOV
        t35 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e7b: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t36;
    // 0x004e3e7e: 89857cffffff MOV
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t37)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e84: eb0a JMP
        goto L_004e3e90;
    // 0x004e3e86: c7857cffffff00000000 MOV
    L_004e3e86:
        t39 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t39)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e90: 8b4d80 MOV
    L_004e3e90:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t40;
    // 0x004e3e93: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t41;
    // 0x004e3e96: 8955d0 MOV
        t42 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd0u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x004e3e99: 8b4580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t43;
    // 0x004e3e9c: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t44;
    // 0x004e3e9f: 83e90c SUB
        t45a = state.regs[1];
        t45b = 0x0000000cu;
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
        state.regs[1] = t45r;
    // 0x004e3ea2: 894dd4 MOV
        t46 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd4u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ea5: c645e200 MOV
        t47 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe2u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ea9: c645e300 MOV
        t48 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe3u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ead: c645e100 MOV
        t49 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe1u), t49)) return BatchLiftStatus::invalid_memory;
    // 0x004e3eb1: 8b55d0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd0u), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t50;
    // 0x004e3eb4: 8955d8 MOV
        t51 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x004e3eb7: 8b45d4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd4u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t52;
    // 0x004e3eba: 8945dc MOV
        t53 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t53)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ebd: 8b4ddc MOV
    L_004e3ebd:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t54;
    // 0x004e3ec0: 3b4d08 CMP
        t55a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t55b)) return BatchLiftStatus::invalid_memory;
        t55r = static_cast<std::uint32_t>(t55a - t55b) & 0xffffffffu;
        batch_set_sub_flags(state, t55a, t55b, t55r, 32u);
    // 0x004e3ec3: 742a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004e3eef;
    // 0x004e3ec5: 8b55dc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t57;
    // 0x004e3ec8: 83ea0c SUB
        t58a = state.regs[2];
        t58b = 0x0000000cu;
        t58r = static_cast<std::uint32_t>(t58a - t58b) & 0xffffffffu;
        batch_set_sub_flags(state, t58a, t58b, t58r, 32u);
        state.regs[2] = t58r;
    // 0x004e3ecb: 8955dc MOV
        t59 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t59)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ece: 8b45d8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t60;
    // 0x004e3ed1: 83e80c SUB
        t61a = state.regs[0];
        t61b = 0x0000000cu;
        t61r = static_cast<std::uint32_t>(t61a - t61b) & 0xffffffffu;
        batch_set_sub_flags(state, t61a, t61b, t61r, 32u);
        state.regs[0] = t61r;
    // 0x004e3ed4: 8945d8 MOV
        t62 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ed7: 8b4ddc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t63;
    // 0x004e3eda: 8b55d8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t64;
    // 0x004e3edd: 8b01 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t65)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t65;
    // 0x004e3edf: 8902 MOV
        t66 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t66)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ee1: 8b4104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t67;
    // 0x004e3ee4: 894204 MOV
        t68 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ee7: 8b4908 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t69;
    // 0x004e3eea: 894a08 MOV
        t70 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x004e3eed: ebce JMP
        goto L_004e3ebd;
    // 0x004e3eef: 8b55fc MOV
    L_004e3eef:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t72)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t72;
    // 0x004e3ef2: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t73;
    // 0x004e3ef5: 8b0a MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t74;
    // 0x004e3ef7: 8908 MOV
        t75 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ef9: 8b4a04 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t76)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t76;
    // 0x004e3efc: 894804 MOV
        t77 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x004e3eff: 8b5208 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t78;
    // 0x004e3f02: 895008 MOV
        t79 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t79)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f05: 8b4580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t80;
    // 0x004e3f08: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t81;
    // 0x004e3f0b: 83c10c ADD
        t82a = state.regs[1];
        t82b = 0x0000000cu;
        t82r = static_cast<std::uint32_t>(t82a + t82b) & 0xffffffffu;
        batch_set_add_flags(state, t82a, t82b, t82r, 32u);
        state.regs[1] = t82r;
    // 0x004e3f0e: 8b5580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t83;
    // 0x004e3f11: 894a04 MOV
        t84 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t84)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f14: e949010000 JMP
        goto L_004e4062;
    // 0x004e3f19: 8b4580 MOV
    L_004e3f19:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t86)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t86;
    // 0x004e3f1c: 8b4d80 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t87;
    // 0x004e3f1f: 8b4004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t88)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t88;
    // 0x004e3f22: 2b01 SUB
        t89a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t89b)) return BatchLiftStatus::invalid_memory;
        t89r = static_cast<std::uint32_t>(t89a - t89b) & 0xffffffffu;
        batch_set_sub_flags(state, t89a, t89b, t89r, 32u);
        state.regs[0] = t89r;
    // 0x004e3f24: 99 CDQ
        state.regs[2] = (state.regs[0] & 0x80000000u) != 0u ? 0xffffffffu : 0u;
    // 0x004e3f25: b90c000000 MOV
        t91 = 0x0000000cu;
        state.regs[1] = t91;
    // 0x004e3f2a: f7f9 IDIV
        t92a = state.regs[1];
        if (t92a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::int64_t divisor = static_cast<std::int64_t>(static_cast<std::int32_t>(t92a));
        const std::int64_t dividend = static_cast<std::int64_t>((static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0]);
        const std::int64_t quotient = dividend / divisor;
        const std::int64_t remainder = dividend % divisor;
        if (quotient < -2147483648ll || quotient > 2147483647ll) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(remainder);
        }
    // 0x004e3f2c: 8945f0 MOV
        t93 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t93)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f2f: 837df000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t94a)) return BatchLiftStatus::invalid_memory;
        t94b = 0x00000000u;
        t94r = static_cast<std::uint32_t>(t94a - t94b) & 0xffffffffu;
        batch_set_sub_flags(state, t94a, t94b, t94r, 32u);
    // 0x004e3f33: 760d JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_004e3f42;
    // 0x004e3f35: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t96;
    // 0x004e3f38: d1e2 SHL
        t97a = state.regs[2];
        t97c = 1u;
        if (t97c != 0u) {
        t97r = static_cast<std::uint32_t>(t97a << t97c) & 0xffffffffu;
        batch_set_shl_flags(state, t97a, t97c, t97r, 32u);
            state.regs[2] = t97r;
        }
    // 0x004e3f3a: 899578ffffff MOV
        t98 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t98)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f40: eb0a JMP
        goto L_004e3f4c;
    // 0x004e3f42: c78578ffffff01000000 MOV
    L_004e3f42:
        t100 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t100)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f4c: 8b8578ffffff MOV
    L_004e3f4c:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t101)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t101;
    // 0x004e3f52: 8945f8 MOV
        t102 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t102)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f55: 837df800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t103a)) return BatchLiftStatus::invalid_memory;
        t103b = 0x00000000u;
        t103r = static_cast<std::uint32_t>(t103a - t103b) & 0xffffffffu;
        batch_set_sub_flags(state, t103a, t103b, t103r, 32u);
    // 0x004e3f59: 7422 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004e3f7d;
    // 0x004e3f5b: 6a00 PUSH
        t105a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f5d: 6a04 PUSH
        t106a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t106a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f5f: 8b4df8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t107)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t107;
    // 0x004e3f62: 6bc90c IMUL
        t108a = state.regs[1];
        t108b = 0x0000000cu;
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t108a)) * static_cast<std::int32_t>(t108b);
        state.regs[1] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x004e3f65: 51 PUSH
        t109a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t109a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f66: 8b5580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t110)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t110;
    // 0x004e3f69: 83c20c ADD
        t111a = state.regs[2];
        t111b = 0x0000000cu;
        t111r = static_cast<std::uint32_t>(t111a + t111b) & 0xffffffffu;
        batch_set_add_flags(state, t111a, t111b, t111r, 32u);
        state.regs[2] = t111r;
    // 0x004e3f6c: 52 PUSH
        t112a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t112a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f6d: e86e9ff4ff CALL
        if (!batch_guest_call32(memory, state, 0x0042dee0u, 0x004e3f72u)) return BatchLiftStatus::invalid_memory;
        t113_call_status = spore_lift_0042dee0(memory, state);
        if (t113_call_status != BatchLiftStatus::returned) return t113_call_status;
        if (state.eip != 0x004e3f72u) return BatchLiftStatus::invalid_control_flow;
    // 0x004e3f72: 83c410 ADD
        t114a = state.regs[4];
        t114b = 0x00000010u;
        t114r = static_cast<std::uint32_t>(t114a + t114b) & 0xffffffffu;
        batch_set_add_flags(state, t114a, t114b, t114r, 32u);
        state.regs[4] = t114r;
    // 0x004e3f75: 898574ffffff MOV
        t115 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff74u), t115)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f7b: eb0a JMP
        goto L_004e3f87;
    // 0x004e3f7d: c78574ffffff00000000 MOV
    L_004e3f7d:
        t117 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff74u), t117)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f87: 8b8574ffffff MOV
    L_004e3f87:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff74u), t118)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t118;
    // 0x004e3f8d: 8945ec MOV
        t119 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t119)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f90: 8b4dec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t120;
    // 0x004e3f93: 51 PUSH
        t121a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t121a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f94: 8b5508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t122)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t122;
    // 0x004e3f97: 52 PUSH
        t123a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t123a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f98: 8b4580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t124)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t124;
    // 0x004e3f9b: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t125)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t125;
    // 0x004e3f9d: 51 PUSH
        t126a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t126a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3f9e: e80db90200 CALL
        if (!batch_guest_call32(memory, state, 0x0050f8b0u, 0x004e3fa3u)) return BatchLiftStatus::invalid_memory;
        t127_call_status = spore_lift_0050f8b0(memory, state);
        if (t127_call_status != BatchLiftStatus::returned) return t127_call_status;
        if (state.eip != 0x004e3fa3u) return BatchLiftStatus::invalid_control_flow;
    // 0x004e3fa3: 83c40c ADD
        t128a = state.regs[4];
        t128b = 0x0000000cu;
        t128r = static_cast<std::uint32_t>(t128a + t128b) & 0xffffffffu;
        batch_set_add_flags(state, t128a, t128b, t128r, 32u);
        state.regs[4] = t128r;
    // 0x004e3fa6: 8945f4 MOV
        t129 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t129)) return BatchLiftStatus::invalid_memory;
    // 0x004e3fa9: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t130)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t130;
    // 0x004e3fac: 8955e4 MOV
        t131 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t131)) return BatchLiftStatus::invalid_memory;
    // 0x004e3faf: 837de400 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t132a)) return BatchLiftStatus::invalid_memory;
        t132b = 0x00000000u;
        t132r = static_cast<std::uint32_t>(t132a - t132b) & 0xffffffffu;
        batch_set_sub_flags(state, t132a, t132b, t132r, 32u);
    // 0x004e3fb3: 7421 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004e3fd6;
    // 0x004e3fb5: 8b450c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t134)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t134;
    // 0x004e3fb8: 8b4de4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t135)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t135;
    // 0x004e3fbb: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t136)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t136;
    // 0x004e3fbd: 8911 MOV
        t137 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t137)) return BatchLiftStatus::invalid_memory;
    // 0x004e3fbf: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t138)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t138;
    // 0x004e3fc2: 895104 MOV
        t139 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t139)) return BatchLiftStatus::invalid_memory;
    // 0x004e3fc5: 8b4008 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t140)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t140;
    // 0x004e3fc8: 894108 MOV
        t141 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t141)) return BatchLiftStatus::invalid_memory;
    // 0x004e3fcb: 8b4de4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t142)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t142;
    // 0x004e3fce: 898d70ffffff MOV
        t143 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff70u), t143)) return BatchLiftStatus::invalid_memory;
    // 0x004e3fd4: eb0a JMP
        goto L_004e3fe0;
    // 0x004e3fd6: c78570ffffff00000000 MOV
    L_004e3fd6:
        t145 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff70u), t145)) return BatchLiftStatus::invalid_memory;
    // 0x004e3fe0: 8b55f4 MOV
    L_004e3fe0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t146)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t146;
    // 0x004e3fe3: 83c20c ADD
        t147a = state.regs[2];
        t147b = 0x0000000cu;
        t147r = static_cast<std::uint32_t>(t147a + t147b) & 0xffffffffu;
        batch_set_add_flags(state, t147a, t147b, t147r, 32u);
        state.regs[2] = t147r;
    // 0x004e3fe6: 8955f4 MOV
        t148 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t148)) return BatchLiftStatus::invalid_memory;
    // 0x004e3fe9: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t149)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t149;
    // 0x004e3fec: 50 PUSH
        t150a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t150a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3fed: 8b4d80 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t151)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t151;
    // 0x004e3ff0: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t152)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t152;
    // 0x004e3ff3: 52 PUSH
        t153a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t153a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ff4: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t154)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t154;
    // 0x004e3ff7: 50 PUSH
        t155a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t155a)) return BatchLiftStatus::invalid_memory;
    // 0x004e3ff8: e8b3b80200 CALL
        if (!batch_guest_call32(memory, state, 0x0050f8b0u, 0x004e3ffdu)) return BatchLiftStatus::invalid_memory;
        t156_call_status = spore_lift_0050f8b0(memory, state);
        if (t156_call_status != BatchLiftStatus::returned) return t156_call_status;
        if (state.eip != 0x004e3ffdu) return BatchLiftStatus::invalid_control_flow;
    // 0x004e3ffd: 83c40c ADD
        t157a = state.regs[4];
        t157b = 0x0000000cu;
        t157r = static_cast<std::uint32_t>(t157a + t157b) & 0xffffffffu;
        batch_set_add_flags(state, t157a, t157b, t157r, 32u);
        state.regs[4] = t157r;
    // 0x004e4000: 8945f4 MOV
        t158 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t158)) return BatchLiftStatus::invalid_memory;
    // 0x004e4003: 8b4d80 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t159)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t159;
    // 0x004e4006: 8b5580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t160)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t160;
    // 0x004e4009: 8b4108 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t161)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t161;
    // 0x004e400c: 2b02 SUB
        t162a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t162b)) return BatchLiftStatus::invalid_memory;
        t162r = static_cast<std::uint32_t>(t162a - t162b) & 0xffffffffu;
        batch_set_sub_flags(state, t162a, t162b, t162r, 32u);
        state.regs[0] = t162r;
    // 0x004e400e: 99 CDQ
        state.regs[2] = (state.regs[0] & 0x80000000u) != 0u ? 0xffffffffu : 0u;
    // 0x004e400f: b90c000000 MOV
        t164 = 0x0000000cu;
        state.regs[1] = t164;
    // 0x004e4014: f7f9 IDIV
        t165a = state.regs[1];
        if (t165a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::int64_t divisor = static_cast<std::int64_t>(static_cast<std::int32_t>(t165a));
        const std::int64_t dividend = static_cast<std::int64_t>((static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0]);
        const std::int64_t quotient = dividend / divisor;
        const std::int64_t remainder = dividend % divisor;
        if (quotient < -2147483648ll || quotient > 2147483647ll) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(remainder);
        }
    // 0x004e4016: 894584 MOV
        t166 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t166)) return BatchLiftStatus::invalid_memory;
    // 0x004e4019: 8b5580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t167)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t167;
    // 0x004e401c: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t168)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t168;
    // 0x004e401e: 894588 MOV
        t169 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff88u), t169)) return BatchLiftStatus::invalid_memory;
    // 0x004e4021: 837d8800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff88u), t170a)) return BatchLiftStatus::invalid_memory;
        t170b = 0x00000000u;
        t170r = static_cast<std::uint32_t>(t170a - t170b) & 0xffffffffu;
        batch_set_sub_flags(state, t170a, t170b, t170r, 32u);
    // 0x004e4025: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004e4042;
    // 0x004e4027: 8b4d88 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff88u), t172)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t172;
    // 0x004e402a: 8379fc00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0xfffffffcu), t173a)) return BatchLiftStatus::invalid_memory;
        t173b = 0x00000000u;
        t173r = static_cast<std::uint32_t>(t173a - t173b) & 0xffffffffu;
        batch_set_sub_flags(state, t173a, t173b, t173r, 32u);
    // 0x004e402e: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004e4042;
    // 0x004e4030: 8b5588 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff88u), t175)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t175;
    // 0x004e4033: 89558c MOV
        t176 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t176)) return BatchLiftStatus::invalid_memory;
    // 0x004e4036: 8b458c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff8cu), t177)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t177;
    // 0x004e4039: 50 PUSH
        t178a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t178a)) return BatchLiftStatus::invalid_memory;
    // 0x004e403a: e84133a600 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x004e403fu)) return BatchLiftStatus::invalid_memory;
        t179_call_status = spore_lift_00f47380(memory, state);
        if (t179_call_status != BatchLiftStatus::returned) return t179_call_status;
        if (state.eip != 0x004e403fu) return BatchLiftStatus::invalid_control_flow;
    // 0x004e403f: 83c404 ADD
        t180a = state.regs[4];
        t180b = 0x00000004u;
        t180r = static_cast<std::uint32_t>(t180a + t180b) & 0xffffffffu;
        batch_set_add_flags(state, t180a, t180b, t180r, 32u);
        state.regs[4] = t180r;
    // 0x004e4042: 8b4d80 MOV
    L_004e4042:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t181)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t181;
    // 0x004e4045: 8b55ec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t182)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t182;
    // 0x004e4048: 8911 MOV
        t183 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t183)) return BatchLiftStatus::invalid_memory;
    // 0x004e404a: 8b4580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t184)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t184;
    // 0x004e404d: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t185)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t185;
    // 0x004e4050: 894804 MOV
        t186 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t186)) return BatchLiftStatus::invalid_memory;
    // 0x004e4053: 8b55f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t187)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t187;
    // 0x004e4056: 6bd20c IMUL
        t188a = state.regs[2];
        t188b = 0x0000000cu;
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t188a)) * static_cast<std::int32_t>(t188b);
        state.regs[2] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x004e4059: 0355ec ADD
        t189a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t189b)) return BatchLiftStatus::invalid_memory;
        t189r = static_cast<std::uint32_t>(t189a + t189b) & 0xffffffffu;
        batch_set_add_flags(state, t189a, t189b, t189r, 32u);
        state.regs[2] = t189r;
    // 0x004e405c: 8b4580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t190)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t190;
    // 0x004e405f: 895008 MOV
        t191 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t191)) return BatchLiftStatus::invalid_memory;
    // 0x004e4062: 8be5 MOV
    L_004e4062:
        t192 = state.regs[5];
        state.regs[4] = t192;
    // 0x004e4064: 5d POP
        if (!memory.load32(state.regs[4], t193a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t193a;
    // 0x004e4065: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
