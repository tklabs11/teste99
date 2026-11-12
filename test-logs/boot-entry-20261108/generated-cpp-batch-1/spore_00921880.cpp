#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921600(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921650(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009218bf(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009218e2(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921909(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092195d(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921976(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921988(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009219f8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921aa7(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921b22(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921b28(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00921880(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00921880u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81a = 0, t81b = 0, t81r = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86a = 0, t86b = 0, t86r = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99a = 0, t99b = 0, t99r = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0, t111b = 0, t111r = 0;
    std::uint32_t t113a = 0, t113b = 0, t113r = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116a = 0, t116b = 0, t116r = 0;
    std::uint32_t t118a = 0, t118b = 0, t118r = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121a = 0, t121b = 0, t121r = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124a = 0, t124b = 0, t124r = 0;
    std::uint32_t t126 = 0;
    std::uint32_t t127 = 0;
    std::uint32_t t128 = 0;
    std::uint32_t t129 = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132 = 0;
    std::uint32_t t133a = 0, t133b = 0, t133r = 0;
    std::uint32_t t135 = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t138a = 0, t138b = 0, t138r = 0;
    std::uint32_t t140 = 0;
    std::uint32_t t142 = 0;
    std::uint32_t t143a = 0, t143b = 0, t143r = 0;
    std::uint32_t t145 = 0;
    std::uint32_t t147 = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150 = 0;
    std::uint32_t t151 = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153a = 0, t153b = 0, t153r = 0;
    std::uint32_t t155a = 0, t155b = 0, t155r = 0;
    std::uint32_t t157 = 0;
    std::uint32_t t158a = 0, t158b = 0, t158r = 0;
    std::uint32_t t160a = 0, t160b = 0, t160r = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163a = 0, t163b = 0, t163r = 0;
    std::uint32_t t165a = 0, t165b = 0, t165r = 0;
    std::uint32_t t167 = 0;
    std::uint32_t t168 = 0;
    std::uint32_t t169 = 0;
    std::uint32_t t170 = 0;
    std::uint32_t t171a = 0;
    std::uint32_t t172a = 0;
    BatchLiftStatus t173_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t174 = 0;
    std::uint32_t t175 = 0;
    std::uint32_t t176a = 0, t176b = 0, t176r = 0;
    std::uint32_t t177 = 0;
    std::uint32_t t178 = 0;
    std::uint32_t t179 = 0;
    std::uint32_t t180 = 0;
    std::uint32_t t181a = 0, t181b = 0, t181r = 0;
    std::uint32_t t183 = 0;
    std::uint32_t t184 = 0;
    std::uint32_t t185a = 0;
    std::uint32_t t186a = 0;
    BatchLiftStatus t187_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t189a = 0, t189b = 0, t189r = 0;
    std::uint32_t t191 = 0;
    std::uint32_t t192 = 0;
    std::uint32_t t193 = 0;
    std::uint32_t t194 = 0;
    std::uint32_t t195 = 0;
    std::uint32_t t196 = 0;
    std::uint32_t t197 = 0;
    std::uint32_t t198a = 0, t198b = 0, t198r = 0;
    std::uint32_t t200 = 0;
    std::uint32_t t201 = 0;
    std::uint32_t t202 = 0;
    std::uint32_t t203a = 0, t203b = 0, t203r = 0;
    std::uint32_t t205 = 0;
    std::uint32_t t207 = 0;
    std::uint32_t t208a = 0, t208b = 0, t208r = 0;
    std::uint32_t t210 = 0;
    std::uint32_t t212 = 0;
    std::uint32_t t213 = 0;
    std::uint32_t t214 = 0;
    std::uint32_t t215 = 0;
    std::uint32_t t216 = 0;
    std::uint32_t t217 = 0;
    std::uint32_t t218a = 0, t218b = 0, t218r = 0;
    std::uint32_t t220a = 0, t220b = 0, t220r = 0;
    std::uint32_t t222 = 0;
    std::uint32_t t223a = 0, t223b = 0, t223r = 0;
    std::uint32_t t225a = 0, t225b = 0, t225r = 0;
    std::uint32_t t227 = 0;
    std::uint32_t t228 = 0;
    std::uint32_t t229 = 0;
    std::uint32_t t230a = 0, t230b = 0, t230r = 0;
    std::uint32_t t233 = 0;
    std::uint32_t t234a = 0, t234b = 0, t234r = 0;
    std::uint32_t t236a = 0, t236b = 0, t236r = 0;
    std::uint32_t t238 = 0;
    std::uint32_t t239 = 0;
    std::uint32_t t240 = 0;
    std::uint32_t t241 = 0;
    std::uint32_t t242a = 0;
    std::uint32_t t243a = 0;
    BatchLiftStatus t244_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t245 = 0;
    std::uint32_t t246 = 0;
    std::uint32_t t247a = 0, t247b = 0, t247r = 0;
    std::uint32_t t248 = 0;
    std::uint32_t t249 = 0;
    std::uint32_t t250 = 0;
    std::uint32_t t251 = 0;
    std::uint32_t t252a = 0, t252b = 0, t252r = 0;
    std::uint32_t t254 = 0;
    std::uint32_t t255 = 0;
    std::uint32_t t256a = 0;
    std::uint32_t t257a = 0;
    BatchLiftStatus t258_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t259 = 0;
    std::uint32_t t260a = 0, t260b = 0, t260r = 0;
    std::uint32_t t261a = 0, t261b = 0, t261r = 0;
    std::uint32_t t263 = 0;
    std::uint32_t t264a = 0;
    std::uint32_t t265a = 0;
    std::uint32_t t266a = 0;
    std::uint32_t t267a = 0;

    // 0x00921880: 8b4c2404 MOV
        batch_guest_pc = 0x00921880u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t0;
    // 0x00921884: 8b5104 MOV
        batch_guest_pc = 0x00921884u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t1;
    // 0x00921887: 53 PUSH
        batch_guest_pc = 0x00921887u;
        t2a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00921888: 55 PUSH
        batch_guest_pc = 0x00921888u;
        t3a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00921889: 56 PUSH
        batch_guest_pc = 0x00921889u;
        t4a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0092188a: 57 PUSH
        batch_guest_pc = 0x0092188au;
        t5a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092188b: 8b7c2418 MOV
        batch_guest_pc = 0x0092188bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t6;
    // 0x0092188f: 8bc1 MOV
        t7 = state.regs[1];
        state.regs[0] = t7;
    // 0x00921891: 85d2 TEST
        t8a = state.regs[2];
        t8b = state.regs[2];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x00921893: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921899;
    // 0x00921895: 8b29 MOV
        batch_guest_pc = 0x00921895u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t10;
    // 0x00921897: eb26 JMP
        goto L_009218bf;
    // 0x00921899: 8b31 MOV
    L_00921899:
        batch_guest_pc = 0x00921899u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t12;
    // 0x0092189b: 85f6 TEST
        t13a = state.regs[6];
        t13b = state.regs[6];
        t13r = (t13a & t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
    // 0x0092189d: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009218a3;
    // 0x0092189f: 8bea MOV
        t15 = state.regs[2];
        state.regs[5] = t15;
    // 0x009218a1: eb1c JMP
        goto L_009218bf;
    // 0x009218a3: 8bc6 MOV
    L_009218a3:
        t17 = state.regs[6];
        state.regs[0] = t17;
    // 0x009218a5: 8b5004 MOV
        batch_guest_pc = 0x009218a5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x009218a8: 85d2 TEST
        t19a = state.regs[2];
        t19b = state.regs[2];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
    // 0x009218aa: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009218b9;
    // 0x009218ac: 8d642400 LEA
        t21 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t21;
    // 0x009218b0: 8bc2 MOV
    L_009218b0:
        t22 = state.regs[2];
        state.regs[0] = t22;
    // 0x009218b2: 8b5004 MOV
        batch_guest_pc = 0x009218b2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t23;
    // 0x009218b5: 85d2 TEST
        t24a = state.regs[2];
        t24b = state.regs[2];
        t24r = (t24a & t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
    // 0x009218b7: 75f7 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009218b0;
    // 0x009218b9: 8b28 MOV
    L_009218b9:
        batch_guest_pc = 0x009218b9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t26;
    // 0x009218bb: 3bc1 CMP
        t27a = state.regs[0];
        t27b = state.regs[1];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
    // 0x009218bd: 7574 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921933;
    // 0x009218bf: 8b7008 MOV
    L_009218bf:
        batch_guest_pc = 0x009218bfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t29;
    // 0x009218c2: 85ed TEST
        t30a = state.regs[5];
        t30b = state.regs[5];
        t30r = (t30a & t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
    // 0x009218c4: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009218c9;
    // 0x009218c6: 897508 MOV
        batch_guest_pc = 0x009218c6u;
        t32 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x009218c9: 3b4f08 CMP
    L_009218c9:
        batch_guest_pc = 0x009218c9u;
        t33a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t33b)) return BatchLiftStatus::invalid_memory;
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
    // 0x009218cc: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009218d3;
    // 0x009218ce: 896f08 MOV
        batch_guest_pc = 0x009218ceu;
        t35 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x009218d1: eb0f JMP
        goto L_009218e2;
    // 0x009218d3: 8b4108 MOV
    L_009218d3:
        batch_guest_pc = 0x009218d3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t37;
    // 0x009218d6: 3b4804 CMP
        batch_guest_pc = 0x009218d6u;
        t38a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t38b)) return BatchLiftStatus::invalid_memory;
        t38r = static_cast<std::uint32_t>(t38a - t38b) & 0xffffffffu;
        batch_set_sub_flags(state, t38a, t38b, t38r, 32u);
    // 0x009218d9: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009218e0;
    // 0x009218db: 896804 MOV
        batch_guest_pc = 0x009218dbu;
        t40 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x009218de: eb02 JMP
        goto L_009218e2;
    // 0x009218e0: 8928 MOV
    L_009218e0:
        batch_guest_pc = 0x009218e0u;
        t42 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x009218e2: 3b4f04 CMP
    L_009218e2:
        batch_guest_pc = 0x009218e2u;
        t43a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t43b)) return BatchLiftStatus::invalid_memory;
        t43r = static_cast<std::uint32_t>(t43a - t43b) & 0xffffffffu;
        batch_set_sub_flags(state, t43a, t43b, t43r, 32u);
    // 0x009218e5: 7522 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921909;
    // 0x009218e7: 833900 CMP
        batch_guest_pc = 0x009218e7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t45a)) return BatchLiftStatus::invalid_memory;
        t45b = 0x00000000u;
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
    // 0x009218ea: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921903;
    // 0x009218ec: 8b4504 MOV
        batch_guest_pc = 0x009218ecu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t47;
    // 0x009218ef: 8bd5 MOV
        t48 = state.regs[5];
        state.regs[2] = t48;
    // 0x009218f1: 85c0 TEST
        t49a = state.regs[0];
        t49b = state.regs[0];
        t49r = (t49a & t49b) & 0xffffffffu;
        batch_set_logic_flags(state, t49r, 32u);
    // 0x009218f3: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009218fe;
    // 0x009218f5: 8bd0 MOV
    L_009218f5:
        t51 = state.regs[0];
        state.regs[2] = t51;
    // 0x009218f7: 8b4204 MOV
        batch_guest_pc = 0x009218f7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t52;
    // 0x009218fa: 85c0 TEST
        t53a = state.regs[0];
        t53b = state.regs[0];
        t53r = (t53a & t53b) & 0xffffffffu;
        batch_set_logic_flags(state, t53r, 32u);
    // 0x009218fc: 75f7 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009218f5;
    // 0x009218fe: 895704 MOV
    L_009218fe:
        batch_guest_pc = 0x009218feu;
        t55 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t55)) return BatchLiftStatus::invalid_memory;
    // 0x00921901: eb06 JMP
        goto L_00921909;
    // 0x00921903: 8b4108 MOV
    L_00921903:
        batch_guest_pc = 0x00921903u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t57;
    // 0x00921906: 894704 MOV
        batch_guest_pc = 0x00921906u;
        t58 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x00921909: 3b0f CMP
    L_00921909:
        batch_guest_pc = 0x00921909u;
        t59a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t59b)) return BatchLiftStatus::invalid_memory;
        t59r = static_cast<std::uint32_t>(t59a - t59b) & 0xffffffffu;
        batch_set_sub_flags(state, t59a, t59b, t59r, 32u);
    // 0x0092190b: 757b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921988;
    // 0x0092190d: 83790400 CMP
        batch_guest_pc = 0x0092190du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t61a)) return BatchLiftStatus::invalid_memory;
        t61b = 0x00000000u;
        t61r = static_cast<std::uint32_t>(t61a - t61b) & 0xffffffffu;
        batch_set_sub_flags(state, t61a, t61b, t61r, 32u);
    // 0x00921911: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092192c;
    // 0x00921913: 8b4500 MOV
        batch_guest_pc = 0x00921913u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t63;
    // 0x00921916: 8bd5 MOV
        t64 = state.regs[5];
        state.regs[2] = t64;
    // 0x00921918: 85c0 TEST
        t65a = state.regs[0];
        t65b = state.regs[0];
        t65r = (t65a & t65b) & 0xffffffffu;
        batch_set_logic_flags(state, t65r, 32u);
    // 0x0092191a: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921928;
    // 0x0092191c: 8d642400 LEA
        t67 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t67;
    // 0x00921920: 8bd0 MOV
    L_00921920:
        t68 = state.regs[0];
        state.regs[2] = t68;
    // 0x00921922: 8b02 MOV
        batch_guest_pc = 0x00921922u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t69;
    // 0x00921924: 85c0 TEST
        t70a = state.regs[0];
        t70b = state.regs[0];
        t70r = (t70a & t70b) & 0xffffffffu;
        batch_set_logic_flags(state, t70r, 32u);
    // 0x00921926: 75f8 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921920;
    // 0x00921928: 8917 MOV
    L_00921928:
        batch_guest_pc = 0x00921928u;
        t72 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x0092192a: eb5c JMP
        goto L_00921988;
    // 0x0092192c: 8b5108 MOV
    L_0092192c:
        batch_guest_pc = 0x0092192cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t74;
    // 0x0092192f: 8917 MOV
        batch_guest_pc = 0x0092192fu;
        t75 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x00921931: eb55 JMP
        goto L_00921988;
    // 0x00921933: 8b5104 MOV
    L_00921933:
        batch_guest_pc = 0x00921933u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t77)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t77;
    // 0x00921936: 894208 MOV
        batch_guest_pc = 0x00921936u;
        t78 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t78)) return BatchLiftStatus::invalid_memory;
    // 0x00921939: 8b5104 MOV
        batch_guest_pc = 0x00921939u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t79)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t79;
    // 0x0092193c: 895004 MOV
        batch_guest_pc = 0x0092193cu;
        t80 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x0092193f: 3b01 CMP
        batch_guest_pc = 0x0092193fu;
        t81a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t81b)) return BatchLiftStatus::invalid_memory;
        t81r = static_cast<std::uint32_t>(t81a - t81b) & 0xffffffffu;
        batch_set_sub_flags(state, t81a, t81b, t81r, 32u);
    // 0x00921941: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921947;
    // 0x00921943: 8bf0 MOV
        t83 = state.regs[0];
        state.regs[6] = t83;
    // 0x00921945: eb16 JMP
        goto L_0092195d;
    // 0x00921947: 8b7008 MOV
    L_00921947:
        batch_guest_pc = 0x00921947u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t85)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t85;
    // 0x0092194a: 85ed TEST
        t86a = state.regs[5];
        t86b = state.regs[5];
        t86r = (t86a & t86b) & 0xffffffffu;
        batch_set_logic_flags(state, t86r, 32u);
    // 0x0092194c: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921951;
    // 0x0092194e: 897508 MOV
        batch_guest_pc = 0x0092194eu;
        t88 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t88)) return BatchLiftStatus::invalid_memory;
    // 0x00921951: 896e04 MOV
    L_00921951:
        batch_guest_pc = 0x00921951u;
        t89 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t89)) return BatchLiftStatus::invalid_memory;
    // 0x00921954: 8b11 MOV
        batch_guest_pc = 0x00921954u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t90)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t90;
    // 0x00921956: 8910 MOV
        batch_guest_pc = 0x00921956u;
        t91 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t91)) return BatchLiftStatus::invalid_memory;
    // 0x00921958: 8b11 MOV
        batch_guest_pc = 0x00921958u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t92)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t92;
    // 0x0092195a: 894208 MOV
        batch_guest_pc = 0x0092195au;
        t93 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t93)) return BatchLiftStatus::invalid_memory;
    // 0x0092195d: 3b4f08 CMP
    L_0092195d:
        batch_guest_pc = 0x0092195du;
        t94a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t94b)) return BatchLiftStatus::invalid_memory;
        t94r = static_cast<std::uint32_t>(t94a - t94b) & 0xffffffffu;
        batch_set_sub_flags(state, t94a, t94b, t94r, 32u);
    // 0x00921960: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921967;
    // 0x00921962: 894708 MOV
        batch_guest_pc = 0x00921962u;
        t96 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t96)) return BatchLiftStatus::invalid_memory;
    // 0x00921965: eb0f JMP
        goto L_00921976;
    // 0x00921967: 8b5108 MOV
    L_00921967:
        batch_guest_pc = 0x00921967u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t98)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t98;
    // 0x0092196a: 3b4a04 CMP
        batch_guest_pc = 0x0092196au;
        t99a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t99b)) return BatchLiftStatus::invalid_memory;
        t99r = static_cast<std::uint32_t>(t99a - t99b) & 0xffffffffu;
        batch_set_sub_flags(state, t99a, t99b, t99r, 32u);
    // 0x0092196d: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921974;
    // 0x0092196f: 894204 MOV
        batch_guest_pc = 0x0092196fu;
        t101 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t101)) return BatchLiftStatus::invalid_memory;
    // 0x00921972: eb02 JMP
        goto L_00921976;
    // 0x00921974: 8902 MOV
    L_00921974:
        batch_guest_pc = 0x00921974u;
        t103 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t103)) return BatchLiftStatus::invalid_memory;
    // 0x00921976: 8b5108 MOV
    L_00921976:
        batch_guest_pc = 0x00921976u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t104)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t104;
    // 0x00921979: 895008 MOV
        batch_guest_pc = 0x00921979u;
        t105 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t105)) return BatchLiftStatus::invalid_memory;
    // 0x0092197c: 8a590c MOV
        batch_guest_pc = 0x0092197cu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t106)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t106 << 0u) & 0x000000ffu);
    // 0x0092197f: 8a500c MOV
        batch_guest_pc = 0x0092197fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t107)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t107 << 0u) & 0x000000ffu);
    // 0x00921982: 88580c MOV
        batch_guest_pc = 0x00921982u;
        t108 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t108)) return BatchLiftStatus::invalid_memory;
    // 0x00921985: 88510c MOV
        batch_guest_pc = 0x00921985u;
        t109 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t109)) return BatchLiftStatus::invalid_memory;
    // 0x00921988: b301 MOV
    L_00921988:
        t110 = 0x00000001u;
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t110 << 0u) & 0x000000ffu);
    // 0x0092198a: 38590c CMP
        batch_guest_pc = 0x0092198au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t111a)) return BatchLiftStatus::invalid_memory;
        t111b = state.regs[3] & 0x000000ffu;
        t111r = static_cast<std::uint32_t>(t111a - t111b) & 0x000000ffu;
        batch_set_sub_flags(state, t111a, t111b, t111r, 8u);
    // 0x0092198d: 0f859c010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921b2f;
    // 0x00921993: 3b6f08 CMP
        batch_guest_pc = 0x00921993u;
        t113a = state.regs[5];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t113b)) return BatchLiftStatus::invalid_memory;
        t113r = static_cast<std::uint32_t>(t113a - t113b) & 0xffffffffu;
        batch_set_sub_flags(state, t113a, t113b, t113r, 32u);
    // 0x00921996: 0f848c010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921b28;
    // 0x0092199c: 8d642400 LEA
        t115 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t115;
    // 0x009219a0: 85ed TEST
    L_009219a0:
        t116a = state.regs[5];
        t116b = state.regs[5];
        t116r = (t116a & t116b) & 0xffffffffu;
        batch_set_logic_flags(state, t116r, 32u);
    // 0x009219a2: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009219ad;
    // 0x009219a4: 385d0c CMP
        batch_guest_pc = 0x009219a4u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t118a)) return BatchLiftStatus::invalid_memory;
        t118b = state.regs[3] & 0x000000ffu;
        t118r = static_cast<std::uint32_t>(t118a - t118b) & 0x000000ffu;
        batch_set_sub_flags(state, t118a, t118b, t118r, 8u);
    // 0x009219a7: 0f857b010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921b28;
    // 0x009219ad: 8b4604 MOV
    L_009219ad:
        batch_guest_pc = 0x009219adu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t120;
    // 0x009219b0: 3be8 CMP
        t121a = state.regs[5];
        t121b = state.regs[0];
        t121r = static_cast<std::uint32_t>(t121a - t121b) & 0xffffffffu;
        batch_set_sub_flags(state, t121a, t121b, t121r, 32u);
    // 0x009219b2: 0f85b2000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921a6a;
    // 0x009219b8: 8b06 MOV
        batch_guest_pc = 0x009219b8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t123)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t123;
    // 0x009219ba: 80780c00 CMP
        batch_guest_pc = 0x009219bau;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t124a)) return BatchLiftStatus::invalid_memory;
        t124b = 0x00000000u;
        t124r = static_cast<std::uint32_t>(t124a - t124b) & 0x000000ffu;
        batch_set_sub_flags(state, t124a, t124b, t124r, 8u);
    // 0x009219be: 7543 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921a03;
    // 0x009219c0: 88580c MOV
        batch_guest_pc = 0x009219c0u;
        t126 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t126)) return BatchLiftStatus::invalid_memory;
    // 0x009219c3: 8b06 MOV
        batch_guest_pc = 0x009219c3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t127)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t127;
    // 0x009219c5: c6460c00 MOV
        batch_guest_pc = 0x009219c5u;
        t128 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t128)) return BatchLiftStatus::invalid_memory;
    // 0x009219c9: 8b4804 MOV
        batch_guest_pc = 0x009219c9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t129)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t129;
    // 0x009219cc: 8b5708 MOV
        batch_guest_pc = 0x009219ccu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t130)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t130;
    // 0x009219cf: 890e MOV
        batch_guest_pc = 0x009219cfu;
        t131 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t131)) return BatchLiftStatus::invalid_memory;
    // 0x009219d1: 8b4804 MOV
        batch_guest_pc = 0x009219d1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t132)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t132;
    // 0x009219d4: 85c9 TEST
        t133a = state.regs[1];
        t133b = state.regs[1];
        t133r = (t133a & t133b) & 0xffffffffu;
        batch_set_logic_flags(state, t133r, 32u);
    // 0x009219d6: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009219db;
    // 0x009219d8: 897108 MOV
        batch_guest_pc = 0x009219d8u;
        t135 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t135)) return BatchLiftStatus::invalid_memory;
    // 0x009219db: 8b4e08 MOV
    L_009219db:
        batch_guest_pc = 0x009219dbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t136)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t136;
    // 0x009219de: 894808 MOV
        batch_guest_pc = 0x009219deu;
        t137 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t137)) return BatchLiftStatus::invalid_memory;
    // 0x009219e1: 3bf2 CMP
        t138a = state.regs[6];
        t138b = state.regs[2];
        t138r = static_cast<std::uint32_t>(t138a - t138b) & 0xffffffffu;
        batch_set_sub_flags(state, t138a, t138b, t138r, 32u);
    // 0x009219e3: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009219e9;
    // 0x009219e5: 8bd0 MOV
        t140 = state.regs[0];
        state.regs[2] = t140;
    // 0x009219e7: eb0f JMP
        goto L_009219f8;
    // 0x009219e9: 8b4e08 MOV
    L_009219e9:
        batch_guest_pc = 0x009219e9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t142)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t142;
    // 0x009219ec: 3b7104 CMP
        batch_guest_pc = 0x009219ecu;
        t143a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t143b)) return BatchLiftStatus::invalid_memory;
        t143r = static_cast<std::uint32_t>(t143a - t143b) & 0xffffffffu;
        batch_set_sub_flags(state, t143a, t143b, t143r, 32u);
    // 0x009219ef: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009219f6;
    // 0x009219f1: 894104 MOV
        batch_guest_pc = 0x009219f1u;
        t145 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t145)) return BatchLiftStatus::invalid_memory;
    // 0x009219f4: eb02 JMP
        goto L_009219f8;
    // 0x009219f6: 8901 MOV
    L_009219f6:
        batch_guest_pc = 0x009219f6u;
        t147 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t147)) return BatchLiftStatus::invalid_memory;
    // 0x009219f8: 897004 MOV
    L_009219f8:
        batch_guest_pc = 0x009219f8u;
        t148 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t148)) return BatchLiftStatus::invalid_memory;
    // 0x009219fb: 894608 MOV
        batch_guest_pc = 0x009219fbu;
        t149 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t149)) return BatchLiftStatus::invalid_memory;
    // 0x009219fe: 895708 MOV
        batch_guest_pc = 0x009219feu;
        t150 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t150)) return BatchLiftStatus::invalid_memory;
    // 0x00921a01: 8b06 MOV
        batch_guest_pc = 0x00921a01u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t151)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t151;
    // 0x00921a03: 8b4804 MOV
    L_00921a03:
        batch_guest_pc = 0x00921a03u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t152)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t152;
    // 0x00921a06: 85c9 TEST
        t153a = state.regs[1];
        t153b = state.regs[1];
        t153r = (t153a & t153b) & 0xffffffffu;
        batch_set_logic_flags(state, t153r, 32u);
    // 0x00921a08: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921a0f;
    // 0x00921a0a: 38590c CMP
        batch_guest_pc = 0x00921a0au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t155a)) return BatchLiftStatus::invalid_memory;
        t155b = state.regs[3] & 0x000000ffu;
        t155r = static_cast<std::uint32_t>(t155a - t155b) & 0x000000ffu;
        batch_set_sub_flags(state, t155a, t155b, t155r, 8u);
    // 0x00921a0d: 7513 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921a22;
    // 0x00921a0f: 8b08 MOV
    L_00921a0f:
        batch_guest_pc = 0x00921a0fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t157)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t157;
    // 0x00921a11: 85c9 TEST
        t158a = state.regs[1];
        t158b = state.regs[1];
        t158r = (t158a & t158b) & 0xffffffffu;
        batch_set_logic_flags(state, t158r, 32u);
    // 0x00921a13: 0f84b0000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921ac9;
    // 0x00921a19: 38590c CMP
        batch_guest_pc = 0x00921a19u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t160a)) return BatchLiftStatus::invalid_memory;
        t160b = state.regs[3] & 0x000000ffu;
        t160r = static_cast<std::uint32_t>(t160a - t160b) & 0x000000ffu;
        batch_set_sub_flags(state, t160a, t160b, t160r, 8u);
    // 0x00921a1c: 0f84a7000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921ac9;
    // 0x00921a22: 8b08 MOV
    L_00921a22:
        batch_guest_pc = 0x00921a22u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t162)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t162;
    // 0x00921a24: 85c9 TEST
        t163a = state.regs[1];
        t163b = state.regs[1];
        t163r = (t163a & t163b) & 0xffffffffu;
        batch_set_logic_flags(state, t163r, 32u);
    // 0x00921a26: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921a2d;
    // 0x00921a28: 38590c CMP
        batch_guest_pc = 0x00921a28u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t165a)) return BatchLiftStatus::invalid_memory;
        t165b = state.regs[3] & 0x000000ffu;
        t165r = static_cast<std::uint32_t>(t165a - t165b) & 0x000000ffu;
        batch_set_sub_flags(state, t165a, t165b, t165r, 8u);
    // 0x00921a2b: 751c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921a49;
    // 0x00921a2d: 8b5004 MOV
    L_00921a2d:
        batch_guest_pc = 0x00921a2du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t167)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t167;
    // 0x00921a30: 885a0c MOV
        batch_guest_pc = 0x00921a30u;
        t168 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t168)) return BatchLiftStatus::invalid_memory;
    // 0x00921a33: c6400c00 MOV
        batch_guest_pc = 0x00921a33u;
        t169 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t169)) return BatchLiftStatus::invalid_memory;
    // 0x00921a37: 8b4f08 MOV
        batch_guest_pc = 0x00921a37u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t170)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t170;
    // 0x00921a3a: 51 PUSH
        batch_guest_pc = 0x00921a3au;
        t171a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t171a)) return BatchLiftStatus::invalid_memory;
    // 0x00921a3b: 50 PUSH
        batch_guest_pc = 0x00921a3bu;
        t172a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t172a)) return BatchLiftStatus::invalid_memory;
    // 0x00921a3c: e80ffcffff CALL
        if (!batch_guest_call32(memory, state, 0x00921650u, 0x00921a41u)) return BatchLiftStatus::invalid_memory;
        t173_call_status = spore_lift_00921650(memory, state);
        if (t173_call_status != BatchLiftStatus::returned) return t173_call_status;
        if (state.eip != 0x00921a41u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921a41: 894708 MOV
        batch_guest_pc = 0x00921a41u;
        t174 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t174)) return BatchLiftStatus::invalid_memory;
    // 0x00921a44: 8b06 MOV
        batch_guest_pc = 0x00921a44u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t175)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t175;
    // 0x00921a46: 83c408 ADD
        t176a = state.regs[4];
        t176b = 0x00000008u;
        t176r = static_cast<std::uint32_t>(t176a + t176b) & 0xffffffffu;
        batch_set_add_flags(state, t176a, t176b, t176r, 32u);
        state.regs[4] = t176r;
    // 0x00921a49: 8a560c MOV
    L_00921a49:
        batch_guest_pc = 0x00921a49u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t177)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t177 << 0u) & 0x000000ffu);
    // 0x00921a4c: 88500c MOV
        batch_guest_pc = 0x00921a4cu;
        t178 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t178)) return BatchLiftStatus::invalid_memory;
    // 0x00921a4f: 885e0c MOV
        batch_guest_pc = 0x00921a4fu;
        t179 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t179)) return BatchLiftStatus::invalid_memory;
    // 0x00921a52: 8b00 MOV
        batch_guest_pc = 0x00921a52u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t180)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t180;
    // 0x00921a54: 85c0 TEST
        t181a = state.regs[0];
        t181b = state.regs[0];
        t181r = (t181a & t181b) & 0xffffffffu;
        batch_set_logic_flags(state, t181r, 32u);
    // 0x00921a56: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921a5b;
    // 0x00921a58: 88580c MOV
        batch_guest_pc = 0x00921a58u;
        t183 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t183)) return BatchLiftStatus::invalid_memory;
    // 0x00921a5b: 8b4708 MOV
    L_00921a5b:
        batch_guest_pc = 0x00921a5bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t184)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t184;
    // 0x00921a5e: 50 PUSH
        batch_guest_pc = 0x00921a5eu;
        t185a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t185a)) return BatchLiftStatus::invalid_memory;
    // 0x00921a5f: 56 PUSH
        batch_guest_pc = 0x00921a5fu;
        t186a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t186a)) return BatchLiftStatus::invalid_memory;
    // 0x00921a60: e89bfbffff CALL
        if (!batch_guest_call32(memory, state, 0x00921600u, 0x00921a65u)) return BatchLiftStatus::invalid_memory;
        t187_call_status = spore_lift_00921600(memory, state);
        if (t187_call_status != BatchLiftStatus::returned) return t187_call_status;
        if (state.eip != 0x00921a65u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921a65: e9b8000000 JMP
        goto L_00921b22;
    // 0x00921a6a: 80780c00 CMP
    L_00921a6a:
        batch_guest_pc = 0x00921a6au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t189a)) return BatchLiftStatus::invalid_memory;
        t189b = 0x00000000u;
        t189r = static_cast<std::uint32_t>(t189a - t189b) & 0x000000ffu;
        batch_set_sub_flags(state, t189a, t189b, t189r, 8u);
    // 0x00921a6e: 7542 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921ab2;
    // 0x00921a70: 88580c MOV
        batch_guest_pc = 0x00921a70u;
        t191 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t191)) return BatchLiftStatus::invalid_memory;
    // 0x00921a73: 8b4604 MOV
        batch_guest_pc = 0x00921a73u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t192)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t192;
    // 0x00921a76: c6460c00 MOV
        batch_guest_pc = 0x00921a76u;
        t193 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t193)) return BatchLiftStatus::invalid_memory;
    // 0x00921a7a: 8b08 MOV
        batch_guest_pc = 0x00921a7au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t194)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t194;
    // 0x00921a7c: 8b5708 MOV
        batch_guest_pc = 0x00921a7cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t195)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t195;
    // 0x00921a7f: 894e04 MOV
        batch_guest_pc = 0x00921a7fu;
        t196 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t196)) return BatchLiftStatus::invalid_memory;
    // 0x00921a82: 8b08 MOV
        batch_guest_pc = 0x00921a82u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t197)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t197;
    // 0x00921a84: 85c9 TEST
        t198a = state.regs[1];
        t198b = state.regs[1];
        t198r = (t198a & t198b) & 0xffffffffu;
        batch_set_logic_flags(state, t198r, 32u);
    // 0x00921a86: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921a8b;
    // 0x00921a88: 897108 MOV
        batch_guest_pc = 0x00921a88u;
        t200 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t200)) return BatchLiftStatus::invalid_memory;
    // 0x00921a8b: 8b4e08 MOV
    L_00921a8b:
        batch_guest_pc = 0x00921a8bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t201)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t201;
    // 0x00921a8e: 894808 MOV
        batch_guest_pc = 0x00921a8eu;
        t202 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t202)) return BatchLiftStatus::invalid_memory;
    // 0x00921a91: 3bf2 CMP
        t203a = state.regs[6];
        t203b = state.regs[2];
        t203r = static_cast<std::uint32_t>(t203a - t203b) & 0xffffffffu;
        batch_set_sub_flags(state, t203a, t203b, t203r, 32u);
    // 0x00921a93: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921a99;
    // 0x00921a95: 8bd0 MOV
        t205 = state.regs[0];
        state.regs[2] = t205;
    // 0x00921a97: eb0e JMP
        goto L_00921aa7;
    // 0x00921a99: 8b4e08 MOV
    L_00921a99:
        batch_guest_pc = 0x00921a99u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t207)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t207;
    // 0x00921a9c: 3b31 CMP
        batch_guest_pc = 0x00921a9cu;
        t208a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t208b)) return BatchLiftStatus::invalid_memory;
        t208r = static_cast<std::uint32_t>(t208a - t208b) & 0xffffffffu;
        batch_set_sub_flags(state, t208a, t208b, t208r, 32u);
    // 0x00921a9e: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921aa4;
    // 0x00921aa0: 8901 MOV
        batch_guest_pc = 0x00921aa0u;
        t210 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t210)) return BatchLiftStatus::invalid_memory;
    // 0x00921aa2: eb03 JMP
        goto L_00921aa7;
    // 0x00921aa4: 894104 MOV
    L_00921aa4:
        batch_guest_pc = 0x00921aa4u;
        t212 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t212)) return BatchLiftStatus::invalid_memory;
    // 0x00921aa7: 8930 MOV
    L_00921aa7:
        batch_guest_pc = 0x00921aa7u;
        t213 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t213)) return BatchLiftStatus::invalid_memory;
    // 0x00921aa9: 894608 MOV
        batch_guest_pc = 0x00921aa9u;
        t214 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t214)) return BatchLiftStatus::invalid_memory;
    // 0x00921aac: 895708 MOV
        batch_guest_pc = 0x00921aacu;
        t215 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t215)) return BatchLiftStatus::invalid_memory;
    // 0x00921aaf: 8b4604 MOV
        batch_guest_pc = 0x00921aafu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t216)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t216;
    // 0x00921ab2: 8b08 MOV
    L_00921ab2:
        batch_guest_pc = 0x00921ab2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t217)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t217;
    // 0x00921ab4: 85c9 TEST
        t218a = state.regs[1];
        t218b = state.regs[1];
        t218r = (t218a & t218b) & 0xffffffffu;
        batch_set_logic_flags(state, t218r, 32u);
    // 0x00921ab6: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921abd;
    // 0x00921ab8: 38590c CMP
        batch_guest_pc = 0x00921ab8u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t220a)) return BatchLiftStatus::invalid_memory;
        t220b = state.regs[3] & 0x000000ffu;
        t220r = static_cast<std::uint32_t>(t220a - t220b) & 0x000000ffu;
        batch_set_sub_flags(state, t220a, t220b, t220r, 8u);
    // 0x00921abb: 7520 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921add;
    // 0x00921abd: 8b4804 MOV
    L_00921abd:
        batch_guest_pc = 0x00921abdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t222)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t222;
    // 0x00921ac0: 85c9 TEST
        t223a = state.regs[1];
        t223b = state.regs[1];
        t223r = (t223a & t223b) & 0xffffffffu;
        batch_set_logic_flags(state, t223r, 32u);
    // 0x00921ac2: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921ac9;
    // 0x00921ac4: 38590c CMP
        batch_guest_pc = 0x00921ac4u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t225a)) return BatchLiftStatus::invalid_memory;
        t225b = state.regs[3] & 0x000000ffu;
        t225r = static_cast<std::uint32_t>(t225a - t225b) & 0x000000ffu;
        batch_set_sub_flags(state, t225a, t225b, t225r, 8u);
    // 0x00921ac7: 7514 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921add;
    // 0x00921ac9: 8bee MOV
    L_00921ac9:
        t227 = state.regs[6];
        state.regs[5] = t227;
    // 0x00921acb: c6400c00 MOV
        batch_guest_pc = 0x00921acbu;
        t228 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t228)) return BatchLiftStatus::invalid_memory;
    // 0x00921acf: 8b7608 MOV
        batch_guest_pc = 0x00921acfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t229)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t229;
    // 0x00921ad2: 3b6f08 CMP
        batch_guest_pc = 0x00921ad2u;
        t230a = state.regs[5];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t230b)) return BatchLiftStatus::invalid_memory;
        t230r = static_cast<std::uint32_t>(t230a - t230b) & 0xffffffffu;
        batch_set_sub_flags(state, t230a, t230b, t230r, 32u);
    // 0x00921ad5: 0f85c5feffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009219a0;
    // 0x00921adb: eb4b JMP
        goto L_00921b28;
    // 0x00921add: 8b4804 MOV
    L_00921add:
        batch_guest_pc = 0x00921addu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t233)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t233;
    // 0x00921ae0: 85c9 TEST
        t234a = state.regs[1];
        t234b = state.regs[1];
        t234r = (t234a & t234b) & 0xffffffffu;
        batch_set_logic_flags(state, t234r, 32u);
    // 0x00921ae2: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921ae9;
    // 0x00921ae4: 38590c CMP
        batch_guest_pc = 0x00921ae4u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t236a)) return BatchLiftStatus::invalid_memory;
        t236b = state.regs[3] & 0x000000ffu;
        t236r = static_cast<std::uint32_t>(t236a - t236b) & 0x000000ffu;
        batch_set_sub_flags(state, t236a, t236b, t236r, 8u);
    // 0x00921ae7: 751c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921b05;
    // 0x00921ae9: 8b08 MOV
    L_00921ae9:
        batch_guest_pc = 0x00921ae9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t238)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t238;
    // 0x00921aeb: 88590c MOV
        batch_guest_pc = 0x00921aebu;
        t239 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t239)) return BatchLiftStatus::invalid_memory;
    // 0x00921aee: c6400c00 MOV
        batch_guest_pc = 0x00921aeeu;
        t240 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t240)) return BatchLiftStatus::invalid_memory;
    // 0x00921af2: 8b5708 MOV
        batch_guest_pc = 0x00921af2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t241)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t241;
    // 0x00921af5: 52 PUSH
        batch_guest_pc = 0x00921af5u;
        t242a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t242a)) return BatchLiftStatus::invalid_memory;
    // 0x00921af6: 50 PUSH
        batch_guest_pc = 0x00921af6u;
        t243a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t243a)) return BatchLiftStatus::invalid_memory;
    // 0x00921af7: e804fbffff CALL
        if (!batch_guest_call32(memory, state, 0x00921600u, 0x00921afcu)) return BatchLiftStatus::invalid_memory;
        t244_call_status = spore_lift_00921600(memory, state);
        if (t244_call_status != BatchLiftStatus::returned) return t244_call_status;
        if (state.eip != 0x00921afcu) return BatchLiftStatus::invalid_control_flow;
    // 0x00921afc: 894708 MOV
        batch_guest_pc = 0x00921afcu;
        t245 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t245)) return BatchLiftStatus::invalid_memory;
    // 0x00921aff: 8b4604 MOV
        batch_guest_pc = 0x00921affu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t246)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t246;
    // 0x00921b02: 83c408 ADD
        t247a = state.regs[4];
        t247b = 0x00000008u;
        t247r = static_cast<std::uint32_t>(t247a + t247b) & 0xffffffffu;
        batch_set_add_flags(state, t247a, t247b, t247r, 32u);
        state.regs[4] = t247r;
    // 0x00921b05: 8a4e0c MOV
    L_00921b05:
        batch_guest_pc = 0x00921b05u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t248)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t248 << 0u) & 0x000000ffu);
    // 0x00921b08: 88480c MOV
        batch_guest_pc = 0x00921b08u;
        t249 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t249)) return BatchLiftStatus::invalid_memory;
    // 0x00921b0b: 885e0c MOV
        batch_guest_pc = 0x00921b0bu;
        t250 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t250)) return BatchLiftStatus::invalid_memory;
    // 0x00921b0e: 8b4004 MOV
        batch_guest_pc = 0x00921b0eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t251)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t251;
    // 0x00921b11: 85c0 TEST
        t252a = state.regs[0];
        t252b = state.regs[0];
        t252r = (t252a & t252b) & 0xffffffffu;
        batch_set_logic_flags(state, t252r, 32u);
    // 0x00921b13: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921b18;
    // 0x00921b15: 88580c MOV
        batch_guest_pc = 0x00921b15u;
        t254 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t254)) return BatchLiftStatus::invalid_memory;
    // 0x00921b18: 8b5708 MOV
    L_00921b18:
        batch_guest_pc = 0x00921b18u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t255)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t255;
    // 0x00921b1b: 52 PUSH
        batch_guest_pc = 0x00921b1bu;
        t256a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t256a)) return BatchLiftStatus::invalid_memory;
    // 0x00921b1c: 56 PUSH
        batch_guest_pc = 0x00921b1cu;
        t257a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t257a)) return BatchLiftStatus::invalid_memory;
    // 0x00921b1d: e82efbffff CALL
        if (!batch_guest_call32(memory, state, 0x00921650u, 0x00921b22u)) return BatchLiftStatus::invalid_memory;
        t258_call_status = spore_lift_00921650(memory, state);
        if (t258_call_status != BatchLiftStatus::returned) return t258_call_status;
        if (state.eip != 0x00921b22u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921b22: 894708 MOV
    L_00921b22:
        batch_guest_pc = 0x00921b22u;
        t259 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t259)) return BatchLiftStatus::invalid_memory;
    // 0x00921b25: 83c408 ADD
        t260a = state.regs[4];
        t260b = 0x00000008u;
        t260r = static_cast<std::uint32_t>(t260a + t260b) & 0xffffffffu;
        batch_set_add_flags(state, t260a, t260b, t260r, 32u);
        state.regs[4] = t260r;
    // 0x00921b28: 85ed TEST
    L_00921b28:
        t261a = state.regs[5];
        t261b = state.regs[5];
        t261r = (t261a & t261b) & 0xffffffffu;
        batch_set_logic_flags(state, t261r, 32u);
    // 0x00921b2a: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921b2f;
    // 0x00921b2c: 885d0c MOV
        batch_guest_pc = 0x00921b2cu;
        t263 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t263)) return BatchLiftStatus::invalid_memory;
    // 0x00921b2f: 5f POP
    L_00921b2f:
        batch_guest_pc = 0x00921b2fu;
        if (!memory.load32(state.regs[4], t264a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t264a;
    // 0x00921b30: 5e POP
        batch_guest_pc = 0x00921b30u;
        if (!memory.load32(state.regs[4], t265a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t265a;
    // 0x00921b31: 5d POP
        batch_guest_pc = 0x00921b31u;
        if (!memory.load32(state.regs[4], t266a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t266a;
    // 0x00921b32: 5b POP
        batch_guest_pc = 0x00921b32u;
        if (!memory.load32(state.regs[4], t267a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t267a;
    // 0x00921b33: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
