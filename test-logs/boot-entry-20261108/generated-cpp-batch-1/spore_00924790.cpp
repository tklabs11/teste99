#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923f30(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924170(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009243d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009247d8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924831(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092488f(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009248cc(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924a19(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a0a360(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924790(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924790u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47a = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0;
    BatchLiftStatus t51_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56 = 0;
    BatchLiftStatus t57_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t58 = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62a = 0, t62b = 0, t62r = 0;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    BatchLiftStatus t69_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t70 = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    BatchLiftStatus t76_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t77 = 0;
    std::uint32_t t78a = 0, t78b = 0, t78r = 0;
    std::uint32_t t80a = 0;
    std::uint32_t t81a = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83a = 0;
    std::uint32_t t84a = 0;
    std::uint32_t t85a = 0;
    BatchLiftStatus t86_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t87 = 0;
    std::uint32_t t88a = 0, t88b = 0, t88r = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t91a = 0;
    std::uint32_t t92 = 0;
    BatchLiftStatus t93_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t94 = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99a = 0;
    std::uint32_t t100 = 0;
    BatchLiftStatus t101_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t102a = 0;
    std::uint32_t t103a = 0;
    std::uint32_t t104a = 0;
    std::uint32_t t105a = 0;
    std::uint32_t t106a = 0;
    std::uint32_t t107a = 0;
    BatchLiftStatus t108_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t109 = 0;
    std::uint32_t t110a = 0, t110b = 0, t110r = 0;
    std::uint32_t t111a = 0, t111b = 0, t111r = 0;
    std::uint32_t t113a = 0;
    std::uint32_t t114 = 0;
    BatchLiftStatus t115_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t116 = 0;
    std::uint32_t t118a = 0, t118b = 0, t118r = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121a = 0;
    std::uint32_t t122 = 0;
    BatchLiftStatus t123_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126 = 0;
    BatchLiftStatus t127_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t128a = 0;
    std::uint32_t t129a = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131a = 0;
    std::uint32_t t132a = 0;
    std::uint32_t t140a = 0, t140b = 0, t140r = 0;
    std::uint32_t t141a = 0;
    std::uint32_t t142a = 0;
    std::uint32_t t143a = 0;
    std::uint32_t t144a = 0;
    std::uint32_t t145 = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t147a = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    BatchLiftStatus t150_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t151 = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153 = 0;
    std::uint32_t t154 = 0;
    std::uint32_t t155a = 0;
    std::uint32_t t156 = 0;
    std::uint32_t t157 = 0;
    std::uint32_t t158 = 0;
    BatchLiftStatus t159_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t160 = 0;
    std::uint32_t t161a = 0;
    std::uint32_t t162 = 0;
    BatchLiftStatus t163_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t164a = 0, t164b = 0, t164r = 0;
    std::uint32_t t166 = 0;
    std::uint32_t t167a = 0, t167b = 0, t167r = 0;
    std::uint32_t t169 = 0;
    std::uint32_t t170 = 0;
    std::uint32_t t171a = 0;
    std::uint32_t t172 = 0;
    BatchLiftStatus t173_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t174 = 0;
    std::uint32_t t175a = 0, t175b = 0, t175r = 0;
    std::uint32_t t177 = 0;
    std::uint32_t t178 = 0;
    std::uint32_t t179 = 0;
    BatchLiftStatus t180_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t181 = 0;
    std::uint32_t t182 = 0;
    std::uint32_t t183 = 0;
    BatchLiftStatus t184_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t185a = 0, t185b = 0, t185r = 0;
    std::uint32_t t187 = 0;
    std::uint32_t t188a = 0, t188b = 0, t188r = 0;
    std::uint32_t t190 = 0;
    std::uint32_t t191 = 0;
    BatchLiftStatus t192_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t193 = 0;
    std::uint32_t t194 = 0;
    std::uint32_t t195 = 0;
    std::uint32_t t196 = 0;
    std::uint32_t t197 = 0;
    BatchLiftStatus t198_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t199a = 0;
    std::uint32_t t200 = 0;
    std::uint32_t t201 = 0;
    BatchLiftStatus t202_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t203 = 0;
    std::uint32_t t204 = 0;
    std::uint32_t t205a = 0;
    std::uint32_t t206 = 0;
    BatchLiftStatus t207_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t208 = 0;
    std::uint32_t t209 = 0;
    std::uint32_t t210 = 0;
    std::uint32_t t211 = 0;
    BatchLiftStatus t212_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t213a = 0, t213b = 0, t213r = 0;
    std::uint32_t t215 = 0;
    std::uint32_t t216a = 0, t216b = 0, t216r = 0;
    std::uint32_t t218 = 0;
    std::uint32_t t219 = 0;
    BatchLiftStatus t220_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t221 = 0;
    std::uint32_t t222 = 0;
    std::uint32_t t223 = 0;
    std::uint32_t t224 = 0;
    std::uint32_t t225 = 0;
    BatchLiftStatus t226_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t227 = 0;
    std::uint32_t t228a = 0;
    std::uint32_t t229 = 0;
    BatchLiftStatus t230_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t231 = 0;
    std::uint32_t t232 = 0;
    std::uint32_t t233a = 0;
    std::uint32_t t234 = 0;
    BatchLiftStatus t235_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t236 = 0;
    std::uint32_t t237 = 0;
    std::uint32_t t238 = 0;
    std::uint32_t t239 = 0;
    std::uint32_t t240 = 0;
    BatchLiftStatus t241_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t242 = 0;
    std::uint32_t t243a = 0, t243b = 0, t243r = 0;
    std::uint32_t t244 = 0;
    std::uint32_t t246 = 0;
    std::uint32_t t247 = 0;
    std::uint32_t t248a = 0, t248b = 0, t248r = 0;
    std::uint32_t t250 = 0;
    std::uint32_t t251 = 0;
    std::uint32_t t252 = 0;
    std::uint32_t t253 = 0;
    BatchLiftStatus t254_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t256 = 0;
    std::uint32_t t257a = 0;
    std::uint32_t t258a = 0;
    BatchLiftStatus t259_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t260 = 0;
    std::uint32_t t261a = 0, t261b = 0, t261r = 0;
    std::uint32_t t263 = 0;
    std::uint32_t t264 = 0;
    std::uint32_t t265 = 0;
    BatchLiftStatus t266_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t267 = 0;
    std::uint32_t t268a = 0, t268b = 0, t268r = 0;
    std::uint32_t t270 = 0;
    std::uint32_t t271 = 0;
    BatchLiftStatus t272_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t273 = 0;
    BatchLiftStatus t274_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t275a = 0;
    std::uint32_t t276a = 0;
    std::uint32_t t277a = 0;
    std::uint32_t t278 = 0;
    std::uint32_t t279a = 0;
    std::uint32_t t280a = 0, t280b = 0, t280r = 0;

    // 0x00924790: 53 PUSH
        batch_guest_pc = 0x00924790u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00924791: 55 PUSH
        batch_guest_pc = 0x00924791u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00924792: 56 PUSH
        batch_guest_pc = 0x00924792u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00924793: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x00924795: 57 PUSH
        batch_guest_pc = 0x00924795u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00924796: 8d6e38 LEA
        t5 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[5] = t5;
    // 0x00924799: 6878dc4301 PUSH
        batch_guest_pc = 0x00924799u;
        t6a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0092479e: 8bcd MOV
        t7 = state.regs[5];
        state.regs[1] = t7;
    // 0x009247a0: e80bdaffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x009247a5u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_009221b0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x009247a5u) return BatchLiftStatus::invalid_control_flow;
    // 0x009247a5: 837e2c00 CMP
        batch_guest_pc = 0x009247a5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t9a)) return BatchLiftStatus::invalid_memory;
        t9b = 0x00000000u;
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x009247a9: 7550 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009247fb;
    // 0x009247ab: 6a00 PUSH
        batch_guest_pc = 0x009247abu;
        t11a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x009247ad: 6a00 PUSH
        batch_guest_pc = 0x009247adu;
        t12a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x009247af: 6a00 PUSH
        batch_guest_pc = 0x009247afu;
        t13a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x009247b1: 6a00 PUSH
        batch_guest_pc = 0x009247b1u;
        t14a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x009247b3: 6878df4301 PUSH
        batch_guest_pc = 0x009247b3u;
        t15a = 0x0143df78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x009247b8: 6a3c PUSH
        batch_guest_pc = 0x009247b8u;
        t16a = 0x0000003cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x009247ba: e8e12b6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x009247bfu)) return BatchLiftStatus::invalid_memory;
        t17_call_status = spore_lift_00f473a0(memory, state);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
        if (state.eip != 0x009247bfu) return BatchLiftStatus::invalid_control_flow;
    // 0x009247bf: 83c418 ADD
        t18a = state.regs[4];
        t18b = 0x00000018u;
        t18r = static_cast<std::uint32_t>(t18a + t18b) & 0xffffffffu;
        batch_set_add_flags(state, t18a, t18b, t18r, 32u);
        state.regs[4] = t18r;
    // 0x009247c2: 85c0 TEST
        t19a = state.regs[0];
        t19b = state.regs[0];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
    // 0x009247c4: 7410 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009247d6;
    // 0x009247c6: 68ac824001 PUSH
        batch_guest_pc = 0x009247c6u;
        t21a = 0x014082acu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x009247cb: 8bc8 MOV
        t22 = state.regs[0];
        state.regs[1] = t22;
    // 0x009247cd: e85ef7ffff CALL
        if (!batch_guest_call32(memory, state, 0x00923f30u, 0x009247d2u)) return BatchLiftStatus::invalid_memory;
        t23_call_status = spore_lift_00923f30(memory, state);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x009247d2u) return BatchLiftStatus::invalid_control_flow;
    // 0x009247d2: 8bf8 MOV
        t24 = state.regs[0];
        state.regs[7] = t24;
    // 0x009247d4: eb02 JMP
        goto L_009247d8;
    // 0x009247d6: 33ff XOR
    L_009247d6:
        t26a = state.regs[7];
        t26b = state.regs[7];
        t26r = (t26a ^ t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[7] = t26r;
    // 0x009247d8: 8b5e2c MOV
    L_009247d8:
        batch_guest_pc = 0x009247d8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t27;
    // 0x009247db: 3bfb CMP
        t28a = state.regs[7];
        t28b = state.regs[3];
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x009247dd: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009247fb;
    // 0x009247df: 85ff TEST
        t30a = state.regs[7];
        t30b = state.regs[7];
        t30r = (t30a & t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
    // 0x009247e1: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009247eb;
    // 0x009247e3: 8b07 MOV
        batch_guest_pc = 0x009247e3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x009247e5: 8b10 MOV
        batch_guest_pc = 0x009247e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t33;
    // 0x009247e7: 8bcf MOV
        t34 = state.regs[7];
        state.regs[1] = t34;
    // 0x009247e9: ffd2 CALL
        t35_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009247ebu);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
    // 0x009247eb: 897e2c MOV
    L_009247eb:
        batch_guest_pc = 0x009247ebu;
        t36 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t36)) return BatchLiftStatus::invalid_memory;
    // 0x009247ee: 85db TEST
        t37a = state.regs[3];
        t37b = state.regs[3];
        t37r = (t37a & t37b) & 0xffffffffu;
        batch_set_logic_flags(state, t37r, 32u);
    // 0x009247f0: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009247fb;
    // 0x009247f2: 8b03 MOV
        batch_guest_pc = 0x009247f2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x009247f4: 8b5004 MOV
        batch_guest_pc = 0x009247f4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t40;
    // 0x009247f7: 8bcb MOV
        t41 = state.regs[3];
        state.regs[1] = t41;
    // 0x009247f9: ffd2 CALL
        t42_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009247fbu);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
    // 0x009247fb: 837e3000 CMP
    L_009247fb:
        batch_guest_pc = 0x009247fbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t43a)) return BatchLiftStatus::invalid_memory;
        t43b = 0x00000000u;
        t43r = static_cast<std::uint32_t>(t43a - t43b) & 0xffffffffu;
        batch_set_sub_flags(state, t43a, t43b, t43r, 32u);
    // 0x009247ff: 7553 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924854;
    // 0x00924801: 6a00 PUSH
        batch_guest_pc = 0x00924801u;
        t45a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
    // 0x00924803: 6a00 PUSH
        batch_guest_pc = 0x00924803u;
        t46a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x00924805: 6a00 PUSH
        batch_guest_pc = 0x00924805u;
        t47a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
    // 0x00924807: 6a00 PUSH
        batch_guest_pc = 0x00924807u;
        t48a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x00924809: 6844df4301 PUSH
        batch_guest_pc = 0x00924809u;
        t49a = 0x0143df44u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x0092480e: 6830100000 PUSH
        batch_guest_pc = 0x0092480eu;
        t50a = 0x00001030u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
    // 0x00924813: e8882b6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00924818u)) return BatchLiftStatus::invalid_memory;
        t51_call_status = spore_lift_00f473a0(memory, state);
        if (t51_call_status != BatchLiftStatus::returned) return t51_call_status;
        if (state.eip != 0x00924818u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924818: 83c418 ADD
        t52a = state.regs[4];
        t52b = 0x00000018u;
        t52r = static_cast<std::uint32_t>(t52a + t52b) & 0xffffffffu;
        batch_set_add_flags(state, t52a, t52b, t52r, 32u);
        state.regs[4] = t52r;
    // 0x0092481b: 85c0 TEST
        t53a = state.regs[0];
        t53b = state.regs[0];
        t53r = (t53a & t53b) & 0xffffffffu;
        batch_set_logic_flags(state, t53r, 32u);
    // 0x0092481d: 7410 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092482f;
    // 0x0092481f: 685c824001 PUSH
        batch_guest_pc = 0x0092481fu;
        t55a = 0x0140825cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x00924824: 8bc8 MOV
        t56 = state.regs[0];
        state.regs[1] = t56;
    // 0x00924826: e8a5fbffff CALL
        if (!batch_guest_call32(memory, state, 0x009243d0u, 0x0092482bu)) return BatchLiftStatus::invalid_memory;
        t57_call_status = spore_lift_009243d0(memory, state);
        if (t57_call_status != BatchLiftStatus::returned) return t57_call_status;
        if (state.eip != 0x0092482bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092482b: 8bf8 MOV
        t58 = state.regs[0];
        state.regs[7] = t58;
    // 0x0092482d: eb02 JMP
        goto L_00924831;
    // 0x0092482f: 33ff XOR
    L_0092482f:
        t60a = state.regs[7];
        t60b = state.regs[7];
        t60r = (t60a ^ t60b) & 0xffffffffu;
        batch_set_logic_flags(state, t60r, 32u);
        state.regs[7] = t60r;
    // 0x00924831: 8b5e30 MOV
    L_00924831:
        batch_guest_pc = 0x00924831u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t61)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t61;
    // 0x00924834: 3bfb CMP
        t62a = state.regs[7];
        t62b = state.regs[3];
        t62r = static_cast<std::uint32_t>(t62a - t62b) & 0xffffffffu;
        batch_set_sub_flags(state, t62a, t62b, t62r, 32u);
    // 0x00924836: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924854;
    // 0x00924838: 85ff TEST
        t64a = state.regs[7];
        t64b = state.regs[7];
        t64r = (t64a & t64b) & 0xffffffffu;
        batch_set_logic_flags(state, t64r, 32u);
    // 0x0092483a: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924844;
    // 0x0092483c: 8b07 MOV
        batch_guest_pc = 0x0092483cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t66;
    // 0x0092483e: 8b10 MOV
        batch_guest_pc = 0x0092483eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t67;
    // 0x00924840: 8bcf MOV
        t68 = state.regs[7];
        state.regs[1] = t68;
    // 0x00924842: ffd2 CALL
        t69_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924844u);
        if (t69_call_status != BatchLiftStatus::returned) return t69_call_status;
    // 0x00924844: 897e30 MOV
    L_00924844:
        batch_guest_pc = 0x00924844u;
        t70 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x00924847: 85db TEST
        t71a = state.regs[3];
        t71b = state.regs[3];
        t71r = (t71a & t71b) & 0xffffffffu;
        batch_set_logic_flags(state, t71r, 32u);
    // 0x00924849: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924854;
    // 0x0092484b: 8b03 MOV
        batch_guest_pc = 0x0092484bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t73;
    // 0x0092484d: 8b5004 MOV
        batch_guest_pc = 0x0092484du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t74;
    // 0x00924850: 8bcb MOV
        t75 = state.regs[3];
        state.regs[1] = t75;
    // 0x00924852: ffd2 CALL
        t76_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924854u);
        if (t76_call_status != BatchLiftStatus::returned) return t76_call_status;
    // 0x00924854: 8b4618 MOV
    L_00924854:
        batch_guest_pc = 0x00924854u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t77)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t77;
    // 0x00924857: 3b461c CMP
        batch_guest_pc = 0x00924857u;
        t78a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t78b)) return BatchLiftStatus::invalid_memory;
        t78r = static_cast<std::uint32_t>(t78a - t78b) & 0xffffffffu;
        batch_set_sub_flags(state, t78a, t78b, t78r, 32u);
    // 0x0092485a: 757a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009248d6;
    // 0x0092485c: 6a00 PUSH
        batch_guest_pc = 0x0092485cu;
        t80a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
    // 0x0092485e: 6a00 PUSH
        batch_guest_pc = 0x0092485eu;
        t81a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t81a)) return BatchLiftStatus::invalid_memory;
    // 0x00924860: 6a00 PUSH
        batch_guest_pc = 0x00924860u;
        t82a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
    // 0x00924862: 6a00 PUSH
        batch_guest_pc = 0x00924862u;
        t83a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t83a)) return BatchLiftStatus::invalid_memory;
    // 0x00924864: 6820df4301 PUSH
        batch_guest_pc = 0x00924864u;
        t84a = 0x0143df20u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t84a)) return BatchLiftStatus::invalid_memory;
    // 0x00924869: 6a24 PUSH
        batch_guest_pc = 0x00924869u;
        t85a = 0x00000024u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t85a)) return BatchLiftStatus::invalid_memory;
    // 0x0092486b: e8302b6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00924870u)) return BatchLiftStatus::invalid_memory;
        t86_call_status = spore_lift_00f473a0(memory, state);
        if (t86_call_status != BatchLiftStatus::returned) return t86_call_status;
        if (state.eip != 0x00924870u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924870: 8bf8 MOV
        t87 = state.regs[0];
        state.regs[7] = t87;
    // 0x00924872: 83c418 ADD
        t88a = state.regs[4];
        t88b = 0x00000018u;
        t88r = static_cast<std::uint32_t>(t88a + t88b) & 0xffffffffu;
        batch_set_add_flags(state, t88a, t88b, t88r, 32u);
        state.regs[4] = t88r;
    // 0x00924875: 85ff TEST
        t89a = state.regs[7];
        t89b = state.regs[7];
        t89r = (t89a & t89b) & 0xffffffffu;
        batch_set_logic_flags(state, t89r, 32u);
    // 0x00924877: 7414 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092488d;
    // 0x00924879: 6850824001 PUSH
        batch_guest_pc = 0x00924879u;
        t91a = 0x01408250u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t91a)) return BatchLiftStatus::invalid_memory;
    // 0x0092487e: 8bcf MOV
        t92 = state.regs[7];
        state.regs[1] = t92;
    // 0x00924880: e8ebf8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00924170u, 0x00924885u)) return BatchLiftStatus::invalid_memory;
        t93_call_status = spore_lift_00924170(memory, state);
        if (t93_call_status != BatchLiftStatus::returned) return t93_call_status;
        if (state.eip != 0x00924885u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924885: c707c0dd4301 MOV
        batch_guest_pc = 0x00924885u;
        t94 = 0x0143ddc0u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t94)) return BatchLiftStatus::invalid_memory;
    // 0x0092488b: eb02 JMP
        goto L_0092488f;
    // 0x0092488d: 33ff XOR
    L_0092488d:
        t96a = state.regs[7];
        t96b = state.regs[7];
        t96r = (t96a ^ t96b) & 0xffffffffu;
        batch_set_logic_flags(state, t96r, 32u);
        state.regs[7] = t96r;
    // 0x0092488f: 8b16 MOV
    L_0092488f:
        batch_guest_pc = 0x0092488fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t97;
    // 0x00924891: 8b421c MOV
        batch_guest_pc = 0x00924891u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000001cu), t98)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t98;
    // 0x00924894: 57 PUSH
        batch_guest_pc = 0x00924894u;
        t99a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t99a)) return BatchLiftStatus::invalid_memory;
    // 0x00924895: 8bce MOV
        t100 = state.regs[6];
        state.regs[1] = t100;
    // 0x00924897: ffd0 CALL
        t101_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924899u);
        if (t101_call_status != BatchLiftStatus::returned) return t101_call_status;
    // 0x00924899: 6a00 PUSH
        batch_guest_pc = 0x00924899u;
        t102a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t102a)) return BatchLiftStatus::invalid_memory;
    // 0x0092489b: 6a00 PUSH
        batch_guest_pc = 0x0092489bu;
        t103a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
    // 0x0092489d: 6a00 PUSH
        batch_guest_pc = 0x0092489du;
        t104a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t104a)) return BatchLiftStatus::invalid_memory;
    // 0x0092489f: 6a00 PUSH
        batch_guest_pc = 0x0092489fu;
        t105a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
    // 0x009248a1: 68fcde4301 PUSH
        batch_guest_pc = 0x009248a1u;
        t106a = 0x0143defcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t106a)) return BatchLiftStatus::invalid_memory;
    // 0x009248a6: 6a24 PUSH
        batch_guest_pc = 0x009248a6u;
        t107a = 0x00000024u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
    // 0x009248a8: e8f32a6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x009248adu)) return BatchLiftStatus::invalid_memory;
        t108_call_status = spore_lift_00f473a0(memory, state);
        if (t108_call_status != BatchLiftStatus::returned) return t108_call_status;
        if (state.eip != 0x009248adu) return BatchLiftStatus::invalid_control_flow;
    // 0x009248ad: 8bf8 MOV
        t109 = state.regs[0];
        state.regs[7] = t109;
    // 0x009248af: 83c418 ADD
        t110a = state.regs[4];
        t110b = 0x00000018u;
        t110r = static_cast<std::uint32_t>(t110a + t110b) & 0xffffffffu;
        batch_set_add_flags(state, t110a, t110b, t110r, 32u);
        state.regs[4] = t110r;
    // 0x009248b2: 85ff TEST
        t111a = state.regs[7];
        t111b = state.regs[7];
        t111r = (t111a & t111b) & 0xffffffffu;
        batch_set_logic_flags(state, t111r, 32u);
    // 0x009248b4: 7414 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009248ca;
    // 0x009248b6: 6840824001 PUSH
        batch_guest_pc = 0x009248b6u;
        t113a = 0x01408240u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t113a)) return BatchLiftStatus::invalid_memory;
    // 0x009248bb: 8bcf MOV
        t114 = state.regs[7];
        state.regs[1] = t114;
    // 0x009248bd: e8aef8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00924170u, 0x009248c2u)) return BatchLiftStatus::invalid_memory;
        t115_call_status = spore_lift_00924170(memory, state);
        if (t115_call_status != BatchLiftStatus::returned) return t115_call_status;
        if (state.eip != 0x009248c2u) return BatchLiftStatus::invalid_control_flow;
    // 0x009248c2: c707fcdd4301 MOV
        batch_guest_pc = 0x009248c2u;
        t116 = 0x0143ddfcu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t116)) return BatchLiftStatus::invalid_memory;
    // 0x009248c8: eb02 JMP
        goto L_009248cc;
    // 0x009248ca: 33ff XOR
    L_009248ca:
        t118a = state.regs[7];
        t118b = state.regs[7];
        t118r = (t118a ^ t118b) & 0xffffffffu;
        batch_set_logic_flags(state, t118r, 32u);
        state.regs[7] = t118r;
    // 0x009248cc: 8b16 MOV
    L_009248cc:
        batch_guest_pc = 0x009248ccu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t119)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t119;
    // 0x009248ce: 8b421c MOV
        batch_guest_pc = 0x009248ceu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000001cu), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t120;
    // 0x009248d1: 57 PUSH
        batch_guest_pc = 0x009248d1u;
        t121a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t121a)) return BatchLiftStatus::invalid_memory;
    // 0x009248d2: 8bce MOV
        t122 = state.regs[6];
        state.regs[1] = t122;
    // 0x009248d4: ffd0 CALL
        t123_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009248d6u);
        if (t123_call_status != BatchLiftStatus::returned) return t123_call_status;
    // 0x009248d6: 8b16 MOV
    L_009248d6:
        batch_guest_pc = 0x009248d6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t124)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t124;
    // 0x009248d8: 8b4218 MOV
        batch_guest_pc = 0x009248d8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000018u), t125)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t125;
    // 0x009248db: 8bce MOV
        t126 = state.regs[6];
        state.regs[1] = t126;
    // 0x009248dd: ffd0 CALL
        t127_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009248dfu);
        if (t127_call_status != BatchLiftStatus::returned) return t127_call_status;
    // 0x009248df: 5f POP
        batch_guest_pc = 0x009248dfu;
        if (!memory.load32(state.regs[4], t128a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t128a;
    // 0x009248e0: 5e POP
        batch_guest_pc = 0x009248e0u;
        if (!memory.load32(state.regs[4], t129a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t129a;
    // 0x009248e1: 8bcd MOV
        t130 = state.regs[5];
        state.regs[1] = t130;
    // 0x009248e3: 5d POP
        batch_guest_pc = 0x009248e3u;
        if (!memory.load32(state.regs[4], t131a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t131a;
    // 0x009248e4: 5b POP
        batch_guest_pc = 0x009248e4u;
        if (!memory.load32(state.regs[4], t132a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t132a;
    // 0x009248e5: e986d9ffff JMP
        state.eip = 0x00922270u;
        return spore_lift_00922270(memory, state);
    // 0x009248ea: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009248eb: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009248ec: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009248ed: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009248ee: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009248ef: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009248f0: 83ec08 SUB
        t140a = state.regs[4];
        t140b = 0x00000008u;
        t140r = static_cast<std::uint32_t>(t140a - t140b) & 0xffffffffu;
        batch_set_sub_flags(state, t140a, t140b, t140r, 32u);
        state.regs[4] = t140r;
    // 0x009248f3: 53 PUSH
        batch_guest_pc = 0x009248f3u;
        t141a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t141a)) return BatchLiftStatus::invalid_memory;
    // 0x009248f4: 55 PUSH
        batch_guest_pc = 0x009248f4u;
        t142a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t142a)) return BatchLiftStatus::invalid_memory;
    // 0x009248f5: 56 PUSH
        batch_guest_pc = 0x009248f5u;
        t143a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t143a)) return BatchLiftStatus::invalid_memory;
    // 0x009248f6: 57 PUSH
        batch_guest_pc = 0x009248f6u;
        t144a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t144a)) return BatchLiftStatus::invalid_memory;
    // 0x009248f7: 8bf9 MOV
        t145 = state.regs[1];
        state.regs[7] = t145;
    // 0x009248f9: 8d6f38 LEA
        t146 = static_cast<std::uint32_t>(state.regs[7] + 0x00000038u);
        state.regs[5] = t146;
    // 0x009248fc: 6878dc4301 PUSH
        batch_guest_pc = 0x009248fcu;
        t147a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t147a)) return BatchLiftStatus::invalid_memory;
    // 0x00924901: 8bcd MOV
        t148 = state.regs[5];
        state.regs[1] = t148;
    // 0x00924903: 896c2418 MOV
        batch_guest_pc = 0x00924903u;
        t149 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t149)) return BatchLiftStatus::invalid_memory;
    // 0x00924907: e8a4d8ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x0092490cu)) return BatchLiftStatus::invalid_memory;
        t150_call_status = spore_lift_009221b0(memory, state);
        if (t150_call_status != BatchLiftStatus::returned) return t150_call_status;
        if (state.eip != 0x0092490cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092490c: 8b74241c MOV
        batch_guest_pc = 0x0092490cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t151)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t151;
    // 0x00924910: 8b16 MOV
        batch_guest_pc = 0x00924910u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t152)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t152;
    // 0x00924912: 8b1f MOV
        batch_guest_pc = 0x00924912u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t153)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t153;
    // 0x00924914: 8d442410 LEA
        t154 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t154;
    // 0x00924918: 50 PUSH
        batch_guest_pc = 0x00924918u;
        t155a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t155a)) return BatchLiftStatus::invalid_memory;
    // 0x00924919: 8b421c MOV
        batch_guest_pc = 0x00924919u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000001cu), t156)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t156;
    // 0x0092491c: 8bce MOV
        t157 = state.regs[6];
        state.regs[1] = t157;
    // 0x0092491e: c744241400000000 MOV
        batch_guest_pc = 0x0092491eu;
        t158 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t158)) return BatchLiftStatus::invalid_memory;
    // 0x00924926: ffd0 CALL
        t159_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924928u);
        if (t159_call_status != BatchLiftStatus::returned) return t159_call_status;
    // 0x00924928: 8b532c MOV
        batch_guest_pc = 0x00924928u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000002cu), t160)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t160;
    // 0x0092492b: 50 PUSH
        batch_guest_pc = 0x0092492bu;
        t161a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t161a)) return BatchLiftStatus::invalid_memory;
    // 0x0092492c: 8bcf MOV
        t162 = state.regs[7];
        state.regs[1] = t162;
    // 0x0092492e: ffd2 CALL
        t163_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924930u);
        if (t163_call_status != BatchLiftStatus::returned) return t163_call_status;
    // 0x00924930: 84c0 TEST
        t164a = state.regs[0] & 0x000000ffu;
        t164b = state.regs[0] & 0x000000ffu;
        t164r = (t164a & t164b) & 0x000000ffu;
        batch_set_logic_flags(state, t164r, 8u);
    // 0x00924932: 742d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924961;
    // 0x00924934: 8b4c2410 MOV
        batch_guest_pc = 0x00924934u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t166)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t166;
    // 0x00924938: 3bce CMP
        t167a = state.regs[1];
        t167b = state.regs[6];
        t167r = static_cast<std::uint32_t>(t167a - t167b) & 0xffffffffu;
        batch_set_sub_flags(state, t167a, t167b, t167r, 32u);
    // 0x0092493a: 0f84ea000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924a2a;
    // 0x00924940: 8b07 MOV
        batch_guest_pc = 0x00924940u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t169)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t169;
    // 0x00924942: 8b5020 MOV
        batch_guest_pc = 0x00924942u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000020u), t170)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t170;
    // 0x00924945: 51 PUSH
        batch_guest_pc = 0x00924945u;
        t171a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t171a)) return BatchLiftStatus::invalid_memory;
    // 0x00924946: 8bcf MOV
        t172 = state.regs[7];
        state.regs[1] = t172;
    // 0x00924948: ffd2 CALL
        t173_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092494au);
        if (t173_call_status != BatchLiftStatus::returned) return t173_call_status;
    // 0x0092494a: 8b4c2410 MOV
        batch_guest_pc = 0x0092494au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t174)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t174;
    // 0x0092494e: 85c9 TEST
        t175a = state.regs[1];
        t175b = state.regs[1];
        t175r = (t175a & t175b) & 0xffffffffu;
        batch_set_logic_flags(state, t175r, 32u);
    // 0x00924950: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924961;
    // 0x00924952: c744241000000000 MOV
        batch_guest_pc = 0x00924952u;
        t177 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t177)) return BatchLiftStatus::invalid_memory;
    // 0x0092495a: 8b01 MOV
        batch_guest_pc = 0x0092495au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t178)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t178;
    // 0x0092495c: 8b5004 MOV
        batch_guest_pc = 0x0092495cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t179)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t179;
    // 0x0092495f: ffd2 CALL
        t180_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924961u);
        if (t180_call_status != BatchLiftStatus::returned) return t180_call_status;
    // 0x00924961: 8b06 MOV
    L_00924961:
        batch_guest_pc = 0x00924961u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t181)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t181;
    // 0x00924963: 8b5038 MOV
        batch_guest_pc = 0x00924963u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000038u), t182)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t182;
    // 0x00924966: 8bce MOV
        t183 = state.regs[6];
        state.regs[1] = t183;
    // 0x00924968: ffd2 CALL
        t184_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092496au);
        if (t184_call_status != BatchLiftStatus::returned) return t184_call_status;
    // 0x0092496a: 85c0 TEST
        t185a = state.regs[0];
        t185b = state.regs[0];
        t185r = (t185a & t185b) & 0xffffffffu;
        batch_set_logic_flags(state, t185r, 32u);
    // 0x0092496c: 7531 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092499f;
    // 0x0092496e: 8b4f30 MOV
        batch_guest_pc = 0x0092496eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000030u), t187)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t187;
    // 0x00924971: 85c9 TEST
        t188a = state.regs[1];
        t188b = state.regs[1];
        t188r = (t188a & t188b) & 0xffffffffu;
        batch_set_logic_flags(state, t188r, 32u);
    // 0x00924973: 742a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092499f;
    // 0x00924975: 8b01 MOV
        batch_guest_pc = 0x00924975u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t190)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t190;
    // 0x00924977: 8b501c MOV
        batch_guest_pc = 0x00924977u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t191)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t191;
    // 0x0092497a: ffd2 CALL
        t192_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092497cu);
        if (t192_call_status != BatchLiftStatus::returned) return t192_call_status;
    // 0x0092497c: 8bd8 MOV
        t193 = state.regs[0];
        state.regs[3] = t193;
    // 0x0092497e: 8b06 MOV
        batch_guest_pc = 0x0092497eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t194)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t194;
    // 0x00924980: 8b501c MOV
        batch_guest_pc = 0x00924980u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t195)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t195;
    // 0x00924983: 8b2b MOV
        batch_guest_pc = 0x00924983u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t196)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t196;
    // 0x00924985: 8bce MOV
        t197 = state.regs[6];
        state.regs[1] = t197;
    // 0x00924987: ffd2 CALL
        t198_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924989u);
        if (t198_call_status != BatchLiftStatus::returned) return t198_call_status;
    // 0x00924989: 50 PUSH
        batch_guest_pc = 0x00924989u;
        t199a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t199a)) return BatchLiftStatus::invalid_memory;
    // 0x0092498a: 8b4514 MOV
        batch_guest_pc = 0x0092498au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000014u), t200)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t200;
    // 0x0092498d: 8bcb MOV
        t201 = state.regs[3];
        state.regs[1] = t201;
    // 0x0092498f: ffd0 CALL
        t202_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924991u);
        if (t202_call_status != BatchLiftStatus::returned) return t202_call_status;
    // 0x00924991: 8b16 MOV
        batch_guest_pc = 0x00924991u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t203)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t203;
    // 0x00924993: 8b4234 MOV
        batch_guest_pc = 0x00924993u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000034u), t204)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t204;
    // 0x00924996: 53 PUSH
        batch_guest_pc = 0x00924996u;
        t205a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t205a)) return BatchLiftStatus::invalid_memory;
    // 0x00924997: 8bce MOV
        t206 = state.regs[6];
        state.regs[1] = t206;
    // 0x00924999: ffd0 CALL
        t207_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0092499bu);
        if (t207_call_status != BatchLiftStatus::returned) return t207_call_status;
    // 0x0092499b: 8b6c2414 MOV
        batch_guest_pc = 0x0092499bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t208)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t208;
    // 0x0092499f: 8b16 MOV
    L_0092499f:
        batch_guest_pc = 0x0092499fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t209)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t209;
    // 0x009249a1: 8b4230 MOV
        batch_guest_pc = 0x009249a1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000030u), t210)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t210;
    // 0x009249a4: 8bce MOV
        t211 = state.regs[6];
        state.regs[1] = t211;
    // 0x009249a6: ffd0 CALL
        t212_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009249a8u);
        if (t212_call_status != BatchLiftStatus::returned) return t212_call_status;
    // 0x009249a8: 85c0 TEST
        t213a = state.regs[0];
        t213b = state.regs[0];
        t213r = (t213a & t213b) & 0xffffffffu;
        batch_set_logic_flags(state, t213r, 32u);
    // 0x009249aa: 7531 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009249dd;
    // 0x009249ac: 8b4f2c MOV
        batch_guest_pc = 0x009249acu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000002cu), t215)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t215;
    // 0x009249af: 85c9 TEST
        t216a = state.regs[1];
        t216b = state.regs[1];
        t216r = (t216a & t216b) & 0xffffffffu;
        batch_set_logic_flags(state, t216r, 32u);
    // 0x009249b1: 742a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009249dd;
    // 0x009249b3: 8b11 MOV
        batch_guest_pc = 0x009249b3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t218)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t218;
    // 0x009249b5: 8b4220 MOV
        batch_guest_pc = 0x009249b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000020u), t219)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t219;
    // 0x009249b8: ffd0 CALL
        t220_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009249bau);
        if (t220_call_status != BatchLiftStatus::returned) return t220_call_status;
    // 0x009249ba: 8b16 MOV
        batch_guest_pc = 0x009249bau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t221)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t221;
    // 0x009249bc: 8bd8 MOV
        t222 = state.regs[0];
        state.regs[3] = t222;
    // 0x009249be: 8b421c MOV
        batch_guest_pc = 0x009249beu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000001cu), t223)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t223;
    // 0x009249c1: 8b2b MOV
        batch_guest_pc = 0x009249c1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t224)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t224;
    // 0x009249c3: 8bce MOV
        t225 = state.regs[6];
        state.regs[1] = t225;
    // 0x009249c5: ffd0 CALL
        t226_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009249c7u);
        if (t226_call_status != BatchLiftStatus::returned) return t226_call_status;
    // 0x009249c7: 8b5518 MOV
        batch_guest_pc = 0x009249c7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t227)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t227;
    // 0x009249ca: 50 PUSH
        batch_guest_pc = 0x009249cau;
        t228a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t228a)) return BatchLiftStatus::invalid_memory;
    // 0x009249cb: 8bcb MOV
        t229 = state.regs[3];
        state.regs[1] = t229;
    // 0x009249cd: ffd2 CALL
        t230_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009249cfu);
        if (t230_call_status != BatchLiftStatus::returned) return t230_call_status;
    // 0x009249cf: 8b06 MOV
        batch_guest_pc = 0x009249cfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t231)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t231;
    // 0x009249d1: 8b502c MOV
        batch_guest_pc = 0x009249d1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000002cu), t232)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t232;
    // 0x009249d4: 53 PUSH
        batch_guest_pc = 0x009249d4u;
        t233a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t233a)) return BatchLiftStatus::invalid_memory;
    // 0x009249d5: 8bce MOV
        t234 = state.regs[6];
        state.regs[1] = t234;
    // 0x009249d7: ffd2 CALL
        t235_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009249d9u);
        if (t235_call_status != BatchLiftStatus::returned) return t235_call_status;
    // 0x009249d9: 8b6c2414 MOV
        batch_guest_pc = 0x009249d9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t236)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t236;
    // 0x009249dd: 8b06 MOV
    L_009249dd:
        batch_guest_pc = 0x009249ddu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t237)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t237;
    // 0x009249df: 8b10 MOV
        batch_guest_pc = 0x009249dfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t238)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t238;
    // 0x009249e1: 8bce MOV
        t239 = state.regs[6];
        state.regs[1] = t239;
    // 0x009249e3: 8974241c MOV
        batch_guest_pc = 0x009249e3u;
        t240 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t240)) return BatchLiftStatus::invalid_memory;
    // 0x009249e7: ffd2 CALL
        t241_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009249e9u);
        if (t241_call_status != BatchLiftStatus::returned) return t241_call_status;
    // 0x009249e9: 8b471c MOV
        batch_guest_pc = 0x009249e9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000001cu), t242)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t242;
    // 0x009249ec: 3b4720 CMP
        batch_guest_pc = 0x009249ecu;
        t243a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000020u), t243b)) return BatchLiftStatus::invalid_memory;
        t243r = static_cast<std::uint32_t>(t243a - t243b) & 0xffffffffu;
        batch_set_sub_flags(state, t243a, t243b, t243r, 32u);
    // 0x009249ef: 8d4f18 LEA
        t244 = static_cast<std::uint32_t>(state.regs[7] + 0x00000018u);
        state.regs[1] = t244;
    // 0x009249f2: 7316 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00924a0a;
    // 0x009249f4: 8d5004 LEA
        t246 = static_cast<std::uint32_t>(state.regs[0] + 0x00000004u);
        state.regs[2] = t246;
    // 0x009249f7: 895104 MOV
        batch_guest_pc = 0x009249f7u;
        t247 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t247)) return BatchLiftStatus::invalid_memory;
    // 0x009249fa: 85c0 TEST
        t248a = state.regs[0];
        t248b = state.regs[0];
        t248r = (t248a & t248b) & 0xffffffffu;
        batch_set_logic_flags(state, t248r, 32u);
    // 0x009249fc: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924a19;
    // 0x009249fe: 8930 MOV
        batch_guest_pc = 0x009249feu;
        t250 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t250)) return BatchLiftStatus::invalid_memory;
    // 0x00924a00: 8b06 MOV
        batch_guest_pc = 0x00924a00u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t251)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t251;
    // 0x00924a02: 8b10 MOV
        batch_guest_pc = 0x00924a02u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t252)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t252;
    // 0x00924a04: 8bce MOV
        t253 = state.regs[6];
        state.regs[1] = t253;
    // 0x00924a06: ffd2 CALL
        t254_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924a08u);
        if (t254_call_status != BatchLiftStatus::returned) return t254_call_status;
    // 0x00924a08: eb0f JMP
        goto L_00924a19;
    // 0x00924a0a: 8d54241c LEA
    L_00924a0a:
        t256 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[2] = t256;
    // 0x00924a0e: 52 PUSH
        batch_guest_pc = 0x00924a0eu;
        t257a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t257a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a0f: 50 PUSH
        batch_guest_pc = 0x00924a0fu;
        t258a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t258a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a10: e84b590e00 CALL
        if (!batch_guest_call32(memory, state, 0x00a0a360u, 0x00924a15u)) return BatchLiftStatus::invalid_memory;
        t259_call_status = spore_lift_00a0a360(memory, state);
        if (t259_call_status != BatchLiftStatus::returned) return t259_call_status;
        if (state.eip != 0x00924a15u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924a15: 8b74241c MOV
        batch_guest_pc = 0x00924a15u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t260)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t260;
    // 0x00924a19: 85f6 TEST
    L_00924a19:
        t261a = state.regs[6];
        t261b = state.regs[6];
        t261r = (t261a & t261b) & 0xffffffffu;
        batch_set_logic_flags(state, t261r, 32u);
    // 0x00924a1b: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924a26;
    // 0x00924a1d: 8b06 MOV
        batch_guest_pc = 0x00924a1du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t263)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t263;
    // 0x00924a1f: 8b5004 MOV
        batch_guest_pc = 0x00924a1fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t264)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t264;
    // 0x00924a22: 8bce MOV
        t265 = state.regs[6];
        state.regs[1] = t265;
    // 0x00924a24: ffd2 CALL
        t266_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924a26u);
        if (t266_call_status != BatchLiftStatus::returned) return t266_call_status;
    // 0x00924a26: 8b4c2410 MOV
    L_00924a26:
        batch_guest_pc = 0x00924a26u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t267)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t267;
    // 0x00924a2a: 85c9 TEST
    L_00924a2a:
        t268a = state.regs[1];
        t268b = state.regs[1];
        t268r = (t268a & t268b) & 0xffffffffu;
        batch_set_logic_flags(state, t268r, 32u);
    // 0x00924a2c: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924a35;
    // 0x00924a2e: 8b01 MOV
        batch_guest_pc = 0x00924a2eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t270)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t270;
    // 0x00924a30: 8b5004 MOV
        batch_guest_pc = 0x00924a30u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t271)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t271;
    // 0x00924a33: ffd2 CALL
        t272_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924a35u);
        if (t272_call_status != BatchLiftStatus::returned) return t272_call_status;
    // 0x00924a35: 8bcd MOV
    L_00924a35:
        t273 = state.regs[5];
        state.regs[1] = t273;
    // 0x00924a37: e834d8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00924a3cu)) return BatchLiftStatus::invalid_memory;
        t274_call_status = spore_lift_00922270(memory, state);
        if (t274_call_status != BatchLiftStatus::returned) return t274_call_status;
        if (state.eip != 0x00924a3cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924a3c: 5f POP
        batch_guest_pc = 0x00924a3cu;
        if (!memory.load32(state.regs[4], t275a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t275a;
    // 0x00924a3d: 5e POP
        batch_guest_pc = 0x00924a3du;
        if (!memory.load32(state.regs[4], t276a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t276a;
    // 0x00924a3e: 5d POP
        batch_guest_pc = 0x00924a3eu;
        if (!memory.load32(state.regs[4], t277a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t277a;
    // 0x00924a3f: b001 MOV
        t278 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t278 << 0u) & 0x000000ffu);
    // 0x00924a41: 5b POP
        batch_guest_pc = 0x00924a41u;
        if (!memory.load32(state.regs[4], t279a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t279a;
    // 0x00924a42: 83c408 ADD
        t280a = state.regs[4];
        t280b = 0x00000008u;
        t280r = static_cast<std::uint32_t>(t280a + t280b) & 0xffffffffu;
        batch_set_add_flags(state, t280a, t280b, t280r, 32u);
        state.regs[4] = t280r;
    // 0x00924a45: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
