#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00937130(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937177(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009371d9(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937239(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937367(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937422(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009370d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009370d0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0, t48r = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51a = 0, t51b = 0, t51r = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t62a = 0, t62r = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66a = 0, t66r = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74a = 0, t74r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77a = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87a = 0, t87r = 0;
    std::uint32_t t88a = 0, t88b = 0, t88r = 0;
    std::uint32_t t90a = 0, t90b = 0, t90r = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99a = 0, t99r = 0;
    std::uint32_t t101a = 0;
    std::uint32_t t102a = 0, t102b = 0, t102r = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t105a = 0, t105b = 0, t105r = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109a = 0, t109r = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112a = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114a = 0, t114b = 0, t114r = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117a = 0, t117b = 0, t117r = 0;
    std::uint32_t t119a = 0, t119b = 0, t119r = 0;
    std::uint32_t t121a = 0;
    std::uint32_t t122a = 0, t122b = 0, t122r = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125a = 0, t125b = 0, t125r = 0;
    std::uint32_t t127a = 0;
    std::uint32_t t128a = 0;
    std::uint32_t t129a = 0, t129b = 0, t129r = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132a = 0, t132r = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t136a = 0, t136b = 0, t136r = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139a = 0, t139r = 0;
    std::uint32_t t141 = 0;
    std::uint32_t t143 = 0;
    std::uint32_t t145 = 0;
    std::uint32_t t147 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t151 = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153a = 0, t153b = 0, t153r = 0;
    std::uint32_t t155 = 0;
    std::uint32_t t156 = 0;
    std::uint32_t t158a = 0, t158b = 0, t158r = 0;
    std::uint32_t t160a = 0, t160b = 0, t160r = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163a = 0, t163b = 0, t163r = 0;
    std::uint32_t t165 = 0;
    std::uint32_t t166a = 0, t166b = 0, t166r = 0;
    std::uint32_t t168a = 0, t168b = 0, t168r = 0;
    std::uint32_t t170 = 0;
    std::uint32_t t171a = 0, t171b = 0, t171r = 0;
    std::uint32_t t173a = 0, t173b = 0, t173r = 0;
    std::uint32_t t175a = 0, t175b = 0, t175r = 0;
    std::uint32_t t177 = 0;
    std::uint32_t t178a = 0, t178b = 0, t178r = 0;
    std::uint32_t t180a = 0, t180b = 0, t180r = 0;
    std::uint32_t t182a = 0, t182b = 0, t182r = 0;
    std::uint32_t t184a = 0, t184b = 0, t184r = 0;
    std::uint32_t t186 = 0;
    std::uint32_t t187a = 0, t187b = 0, t187r = 0;
    std::uint32_t t188 = 0;
    std::uint32_t t189a = 0, t189r = 0;
    std::uint32_t t190a = 0;
    std::uint32_t t191 = 0;
    std::uint32_t t192a = 0, t192b = 0, t192r = 0;
    std::uint32_t t193a = 0, t193b = 0, t193r = 0;
    std::uint32_t t195a = 0;
    std::uint32_t t196a = 0;
    std::uint32_t t197a = 0, t197b = 0, t197r = 0;
    std::uint32_t t199 = 0;
    std::uint32_t t201a = 0, t201b = 0, t201r = 0;
    std::uint32_t t203 = 0;
    std::uint32_t t205a = 0, t205b = 0, t205r = 0;
    std::uint32_t t207a = 0, t207b = 0, t207r = 0;
    std::uint32_t t209 = 0;
    std::uint32_t t211 = 0;
    std::uint32_t t212 = 0;
    std::uint32_t t213 = 0;
    std::uint32_t t214 = 0;
    std::uint32_t t216a = 0, t216b = 0, t216r = 0;
    std::uint32_t t218 = 0;
    std::uint32_t t219 = 0;
    std::uint32_t t220 = 0;
    std::uint32_t t221a = 0, t221b = 0, t221r = 0;
    std::uint32_t t223 = 0;
    std::uint32_t t225a = 0, t225b = 0, t225r = 0;
    std::uint32_t t227 = 0;
    std::uint32_t t229a = 0, t229b = 0, t229r = 0;
    std::uint32_t t230a = 0, t230b = 0, t230r = 0;
    std::uint32_t t232 = 0;
    std::uint32_t t233 = 0;
    std::uint32_t t234 = 0;
    std::uint32_t t235 = 0;
    std::uint32_t t236 = 0;
    std::uint32_t t237 = 0;
    std::uint32_t t239a = 0;
    std::uint32_t t240a = 0;
    std::uint32_t t241a = 0;
    std::uint32_t t242a = 0;
    std::uint32_t t243a = 0, t243b = 0, t243r = 0;

    // 0x009370d0: 83ec20 SUB
        t0a = state.regs[4];
        t0b = 0x00000020u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x009370d3: 53 PUSH
        batch_guest_pc = 0x009370d3u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009370d4: 55 PUSH
        batch_guest_pc = 0x009370d4u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009370d5: 56 PUSH
        batch_guest_pc = 0x009370d5u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009370d6: 33f6 XOR
        t4a = state.regs[6];
        t4b = state.regs[6];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[6] = t4r;
    // 0x009370d8: 42 INC
        t5a = state.regs[2];
        t5r = static_cast<std::uint32_t>(t5a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t5a, t5r, 32u);
        state.regs[2] = t5r;
    // 0x009370d9: 8bd8 MOV
        t6 = state.regs[0];
        state.regs[3] = t6;
    // 0x009370db: 8a02 MOV
        batch_guest_pc = 0x009370dbu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t7 << 0u) & 0x000000ffu);
    // 0x009370dd: 57 PUSH
        batch_guest_pc = 0x009370ddu;
        t8a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x009370de: bd01000000 MOV
        t9 = 0x00000001u;
        state.regs[5] = t9;
    // 0x009370e3: bfffffff7f MOV
        t10 = 0x7fffffffu;
        state.regs[7] = t10;
    // 0x009370e8: 896c2414 MOV
        batch_guest_pc = 0x009370e8u;
        t11 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x009370ec: 896c2418 MOV
        batch_guest_pc = 0x009370ecu;
        t12 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x009370f0: c644241c00 MOV
        batch_guest_pc = 0x009370f0u;
        t13 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t13)) return BatchLiftStatus::invalid_memory;
    // 0x009370f5: 89742420 MOV
        batch_guest_pc = 0x009370f5u;
        t14 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x009370f9: 897c2424 MOV
        batch_guest_pc = 0x009370f9u;
        t15 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x009370fd: 89742428 MOV
        batch_guest_pc = 0x009370fdu;
        t16 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00937101: 8974242c MOV
        batch_guest_pc = 0x00937101u;
        t17 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00937105: 89742410 MOV
        batch_guest_pc = 0x00937105u;
        t18 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00937109: 3c25 CMP
        t19a = state.regs[0] & 0x000000ffu;
        t19b = 0x00000025u;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0x000000ffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 8u);
    // 0x0093710b: 750d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093711a;
    // 0x0093710d: c744242c25000000 MOV
        batch_guest_pc = 0x0093710du;
        t21 = 0x00000025u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00937115: e908030000 JMP
        goto L_00937422;
    // 0x0093711a: 0fbec8 MOVSX
    L_0093711a:
        t23a = state.regs[0] & 0x000000ffu;
        t23a = static_cast<std::uint32_t>((t23a ^ 0x00000080u) - 0x00000080u);
        state.regs[1] = t23a;
    // 0x0093711d: 83e920 SUB
        t24a = state.regs[1];
        t24b = 0x00000020u;
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
        state.regs[1] = t24r;
    // 0x00937120: 83f910 CMP
        t25a = state.regs[1];
        t25b = 0x00000010u;
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
    // 0x00937123: 7765 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0093718a;
    // 0x00937125: eb09 JMP
        goto L_00937130;
    // 0x00937130: 0fb68954749300 MOVZX
    L_00937130:
        batch_guest_pc = 0x00937130u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00937454u), t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t28a;
    // 0x00937137: ff248d3c749300 JMP
        batch_guest_pc = 0x00937137u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] * 4u + 0x0093743cu), t29a)) return BatchLiftStatus::invalid_memory;
        switch (t29a) {
        case 0x0093713eu: goto L_0093713e;
        case 0x00937144u: goto L_00937144;
        case 0x0093714bu: goto L_0093714b;
        case 0x00937157u: goto L_00937157;
        case 0x0093715eu: goto L_0093715e;
        case 0x00937186u: goto L_00937186;
        default:
        state.eip = t29a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x0093713e: 89742414 MOV
    L_0093713e:
        batch_guest_pc = 0x0093713eu;
        t30 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00937142: eb33 JMP
        goto L_00937177;
    // 0x00937144: bd02000000 MOV
    L_00937144:
        t32 = 0x00000002u;
        state.regs[5] = t32;
    // 0x00937149: eb2c JMP
        goto L_00937177;
    // 0x0093714b: 83fd02 CMP
    L_0093714b:
        t34a = state.regs[5];
        t34b = 0x00000002u;
        t34r = static_cast<std::uint32_t>(t34a - t34b) & 0xffffffffu;
        batch_set_sub_flags(state, t34a, t34b, t34r, 32u);
    // 0x0093714e: 7427 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937177;
    // 0x00937150: bd03000000 MOV
        t36 = 0x00000003u;
        state.regs[5] = t36;
    // 0x00937155: eb20 JMP
        goto L_00937177;
    // 0x00937157: c644241c01 MOV
    L_00937157:
        batch_guest_pc = 0x00937157u;
        t38 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t38)) return BatchLiftStatus::invalid_memory;
    // 0x0093715c: eb19 JMP
        goto L_00937177;
    // 0x0093715e: 8b442414 MOV
    L_0093715e:
        batch_guest_pc = 0x0093715eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t40;
    // 0x00937162: 85c0 TEST
        t41a = state.regs[0];
        t41b = state.regs[0];
        t41r = (t41a & t41b) & 0xffffffffu;
        batch_set_logic_flags(state, t41r, 32u);
    // 0x00937164: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937177;
    // 0x00937166: 83f802 CMP
        t43a = state.regs[0];
        t43b = 0x00000002u;
        t43r = static_cast<std::uint32_t>(t43a - t43b) & 0xffffffffu;
        batch_set_sub_flags(state, t43a, t43b, t43r, 32u);
    // 0x00937169: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093716f;
    // 0x0093716b: 89442410 MOV
        batch_guest_pc = 0x0093716bu;
        t45 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x0093716f: c744241402000000 MOV
    L_0093716f:
        batch_guest_pc = 0x0093716fu;
        t46 = 0x00000002u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00937177: 8a4201 MOV
    L_00937177:
        batch_guest_pc = 0x00937177u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000001u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t47 << 0u) & 0x000000ffu);
    // 0x0093717a: 42 INC
        t48a = state.regs[2];
        t48r = static_cast<std::uint32_t>(t48a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t48a, t48r, 32u);
        state.regs[2] = t48r;
    // 0x0093717b: 0fbec8 MOVSX
        t49a = state.regs[0] & 0x000000ffu;
        t49a = static_cast<std::uint32_t>((t49a ^ 0x00000080u) - 0x00000080u);
        state.regs[1] = t49a;
    // 0x0093717e: 83e920 SUB
        t50a = state.regs[1];
        t50b = 0x00000020u;
        t50r = static_cast<std::uint32_t>(t50a - t50b) & 0xffffffffu;
        batch_set_sub_flags(state, t50a, t50b, t50r, 32u);
        state.regs[1] = t50r;
    // 0x00937181: 83f910 CMP
        t51a = state.regs[1];
        t51b = 0x00000010u;
        t51r = static_cast<std::uint32_t>(t51a - t51b) & 0xffffffffu;
        batch_set_sub_flags(state, t51a, t51b, t51r, 32u);
    // 0x00937184: 76aa JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00937130;
    // 0x00937186: 896c2418 MOV
    L_00937186:
        batch_guest_pc = 0x00937186u;
        t53 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x0093718a: 3c2a CMP
    L_0093718a:
        t54a = state.regs[0] & 0x000000ffu;
        t54b = 0x0000002au;
        t54r = static_cast<std::uint32_t>(t54a - t54b) & 0x000000ffu;
        batch_set_sub_flags(state, t54a, t54b, t54r, 8u);
    // 0x0093718c: 7524 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009371b2;
    // 0x0093718e: 830304 ADD
        batch_guest_pc = 0x0093718eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t56a)) return BatchLiftStatus::invalid_memory;
        t56b = 0x00000004u;
        t56r = static_cast<std::uint32_t>(t56a + t56b) & 0xffffffffu;
        batch_set_add_flags(state, t56a, t56b, t56r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t56r)) return BatchLiftStatus::invalid_memory;
    // 0x00937191: 8b03 MOV
        batch_guest_pc = 0x00937191u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t57;
    // 0x00937193: 8b70fc MOV
        batch_guest_pc = 0x00937193u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t58;
    // 0x00937196: 89742420 MOV
        batch_guest_pc = 0x00937196u;
        t59 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t59)) return BatchLiftStatus::invalid_memory;
    // 0x0093719a: 85f6 TEST
        t60a = state.regs[6];
        t60b = state.regs[6];
        t60r = (t60a & t60b) & 0xffffffffu;
        batch_set_logic_flags(state, t60r, 32u);
    // 0x0093719c: 7d0e JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009371ac;
    // 0x0093719e: f7de NEG
        t62a = state.regs[6];
        t62r = static_cast<std::uint32_t>(0u - t62a) & 0xffffffffu;
        batch_set_neg_flags(state, t62a, t62r, 32u);
        state.regs[6] = t62r;
    // 0x009371a0: c744241400000000 MOV
        batch_guest_pc = 0x009371a0u;
        t63 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t63)) return BatchLiftStatus::invalid_memory;
    // 0x009371a8: 89742420 MOV
        batch_guest_pc = 0x009371a8u;
        t64 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t64)) return BatchLiftStatus::invalid_memory;
    // 0x009371ac: 8a4201 MOV
    L_009371ac:
        batch_guest_pc = 0x009371acu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000001u), t65)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t65 << 0u) & 0x000000ffu);
    // 0x009371af: 42 INC
        t66a = state.regs[2];
        t66r = static_cast<std::uint32_t>(t66a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t66a, t66r, 32u);
        state.regs[2] = t66r;
    // 0x009371b0: eb27 JMP
        goto L_009371d9;
    // 0x009371b2: 0fbec8 MOVSX
    L_009371b2:
        t68a = state.regs[0] & 0x000000ffu;
        t68a = static_cast<std::uint32_t>((t68a ^ 0x00000080u) - 0x00000080u);
        state.regs[1] = t68a;
    // 0x009371b5: 8d69d0 LEA
        t69 = static_cast<std::uint32_t>(state.regs[1] + 0xffffffd0u);
        state.regs[5] = t69;
    // 0x009371b8: 83fd0a CMP
        t70a = state.regs[5];
        t70b = 0x0000000au;
        t70r = static_cast<std::uint32_t>(t70a - t70b) & 0xffffffffu;
        batch_set_sub_flags(state, t70a, t70b, t70r, 32u);
    // 0x009371bb: 7328 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_009371e5;
    // 0x009371bd: 8d4900 LEA
        t72 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t72;
    // 0x009371c0: 8d04b6 LEA
    L_009371c0:
        t73 = static_cast<std::uint32_t>(state.regs[6] + state.regs[6] * 4u + 0x00000000u);
        state.regs[0] = t73;
    // 0x009371c3: 42 INC
        t74a = state.regs[2];
        t74r = static_cast<std::uint32_t>(t74a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t74a, t74r, 32u);
        state.regs[2] = t74r;
    // 0x009371c4: 8d7441d0 LEA
        t75 = static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 2u + 0xffffffd0u);
        state.regs[6] = t75;
    // 0x009371c8: 8a02 MOV
        batch_guest_pc = 0x009371c8u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t76)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t76 << 0u) & 0x000000ffu);
    // 0x009371ca: 0fbec8 MOVSX
        t77a = state.regs[0] & 0x000000ffu;
        t77a = static_cast<std::uint32_t>((t77a ^ 0x00000080u) - 0x00000080u);
        state.regs[1] = t77a;
    // 0x009371cd: 8d69d0 LEA
        t78 = static_cast<std::uint32_t>(state.regs[1] + 0xffffffd0u);
        state.regs[5] = t78;
    // 0x009371d0: 83fd0a CMP
        t79a = state.regs[5];
        t79b = 0x0000000au;
        t79r = static_cast<std::uint32_t>(t79a - t79b) & 0xffffffffu;
        batch_set_sub_flags(state, t79a, t79b, t79r, 32u);
    // 0x009371d3: 72eb JC
        if (((state.eflags & 0x001u) != 0u)) goto L_009371c0;
    // 0x009371d5: 89742420 MOV
        batch_guest_pc = 0x009371d5u;
        t81 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t81)) return BatchLiftStatus::invalid_memory;
    // 0x009371d9: 81fe00040000 CMP
    L_009371d9:
        t82a = state.regs[6];
        t82b = 0x00000400u;
        t82r = static_cast<std::uint32_t>(t82a - t82b) & 0xffffffffu;
        batch_set_sub_flags(state, t82a, t82b, t82r, 32u);
    // 0x009371df: 0f8f3d020000 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00937422;
    // 0x009371e5: 3c2e CMP
    L_009371e5:
        t84a = state.regs[0] & 0x000000ffu;
        t84b = 0x0000002eu;
        t84r = static_cast<std::uint32_t>(t84a - t84b) & 0x000000ffu;
        batch_set_sub_flags(state, t84a, t84b, t84r, 8u);
    // 0x009371e7: 7564 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093724d;
    // 0x009371e9: 8a4201 MOV
        batch_guest_pc = 0x009371e9u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000001u), t86)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t86 << 0u) & 0x000000ffu);
    // 0x009371ec: 42 INC
        t87a = state.regs[2];
        t87r = static_cast<std::uint32_t>(t87a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t87a, t87r, 32u);
        state.regs[2] = t87r;
    // 0x009371ed: 3c2a CMP
        t88a = state.regs[0] & 0x000000ffu;
        t88b = 0x0000002au;
        t88r = static_cast<std::uint32_t>(t88a - t88b) & 0x000000ffu;
        batch_set_sub_flags(state, t88a, t88b, t88r, 8u);
    // 0x009371ef: 751c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093720d;
    // 0x009371f1: 830304 ADD
        batch_guest_pc = 0x009371f1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t90a)) return BatchLiftStatus::invalid_memory;
        t90b = 0x00000004u;
        t90r = static_cast<std::uint32_t>(t90a + t90b) & 0xffffffffu;
        batch_set_add_flags(state, t90a, t90b, t90r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t90r)) return BatchLiftStatus::invalid_memory;
    // 0x009371f4: 8b03 MOV
        batch_guest_pc = 0x009371f4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t91)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t91;
    // 0x009371f6: 8b78fc MOV
        batch_guest_pc = 0x009371f6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t92)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t92;
    // 0x009371f9: 897c2424 MOV
        batch_guest_pc = 0x009371f9u;
        t93 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t93)) return BatchLiftStatus::invalid_memory;
    // 0x009371fd: 85ff TEST
        t94a = state.regs[7];
        t94b = state.regs[7];
        t94r = (t94a & t94b) & 0xffffffffu;
        batch_set_logic_flags(state, t94r, 32u);
    // 0x009371ff: 7d06 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00937207;
    // 0x00937201: 33ff XOR
        t96a = state.regs[7];
        t96b = state.regs[7];
        t96r = (t96a ^ t96b) & 0xffffffffu;
        batch_set_logic_flags(state, t96r, 32u);
        state.regs[7] = t96r;
    // 0x00937203: 897c2424 MOV
        batch_guest_pc = 0x00937203u;
        t97 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t97)) return BatchLiftStatus::invalid_memory;
    // 0x00937207: 8a4201 MOV
    L_00937207:
        batch_guest_pc = 0x00937207u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000001u), t98)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t98 << 0u) & 0x000000ffu);
    // 0x0093720a: 42 INC
        t99a = state.regs[2];
        t99r = static_cast<std::uint32_t>(t99a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t99a, t99r, 32u);
        state.regs[2] = t99r;
    // 0x0093720b: eb2c JMP
        goto L_00937239;
    // 0x0093720d: 0fbec8 MOVSX
    L_0093720d:
        t101a = state.regs[0] & 0x000000ffu;
        t101a = static_cast<std::uint32_t>((t101a ^ 0x00000080u) - 0x00000080u);
        state.regs[1] = t101a;
    // 0x00937210: 33ff XOR
        t102a = state.regs[7];
        t102b = state.regs[7];
        t102r = (t102a ^ t102b) & 0xffffffffu;
        batch_set_logic_flags(state, t102r, 32u);
        state.regs[7] = t102r;
    // 0x00937212: 8d71d0 LEA
        t103 = static_cast<std::uint32_t>(state.regs[1] + 0xffffffd0u);
        state.regs[6] = t103;
    // 0x00937215: 897c2424 MOV
        batch_guest_pc = 0x00937215u;
        t104 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t104)) return BatchLiftStatus::invalid_memory;
    // 0x00937219: 83fe0a CMP
        t105a = state.regs[6];
        t105b = 0x0000000au;
        t105r = static_cast<std::uint32_t>(t105a - t105b) & 0xffffffffu;
        batch_set_sub_flags(state, t105a, t105b, t105r, 32u);
    // 0x0093721c: 732f JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0093724d;
    // 0x0093721e: 8bff MOV
        t107 = state.regs[7];
        state.regs[7] = t107;
    // 0x00937220: 8d04bf LEA
    L_00937220:
        t108 = static_cast<std::uint32_t>(state.regs[7] + state.regs[7] * 4u + 0x00000000u);
        state.regs[0] = t108;
    // 0x00937223: 42 INC
        t109a = state.regs[2];
        t109r = static_cast<std::uint32_t>(t109a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t109a, t109r, 32u);
        state.regs[2] = t109r;
    // 0x00937224: 8d7c41d0 LEA
        t110 = static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 2u + 0xffffffd0u);
        state.regs[7] = t110;
    // 0x00937228: 8a02 MOV
        batch_guest_pc = 0x00937228u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t111)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t111 << 0u) & 0x000000ffu);
    // 0x0093722a: 0fbec8 MOVSX
        t112a = state.regs[0] & 0x000000ffu;
        t112a = static_cast<std::uint32_t>((t112a ^ 0x00000080u) - 0x00000080u);
        state.regs[1] = t112a;
    // 0x0093722d: 8d71d0 LEA
        t113 = static_cast<std::uint32_t>(state.regs[1] + 0xffffffd0u);
        state.regs[6] = t113;
    // 0x00937230: 83fe0a CMP
        t114a = state.regs[6];
        t114b = 0x0000000au;
        t114r = static_cast<std::uint32_t>(t114a - t114b) & 0xffffffffu;
        batch_set_sub_flags(state, t114a, t114b, t114r, 32u);
    // 0x00937233: 72eb JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00937220;
    // 0x00937235: 897c2424 MOV
        batch_guest_pc = 0x00937235u;
        t116 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t116)) return BatchLiftStatus::invalid_memory;
    // 0x00937239: 81ff00040000 CMP
    L_00937239:
        t117a = state.regs[7];
        t117b = 0x00000400u;
        t117r = static_cast<std::uint32_t>(t117a - t117b) & 0xffffffffu;
        batch_set_sub_flags(state, t117a, t117b, t117r, 32u);
    // 0x0093723f: 7e0c JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0093724d;
    // 0x00937241: 81ffffffff7f CMP
        t119a = state.regs[7];
        t119b = 0x7fffffffu;
        t119r = static_cast<std::uint32_t>(t119a - t119b) & 0xffffffffu;
        batch_set_sub_flags(state, t119a, t119b, t119r, 32u);
    // 0x00937247: 0f85d5010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937422;
    // 0x0093724d: 0fbec8 MOVSX
    L_0093724d:
        t121a = state.regs[0] & 0x000000ffu;
        t121a = static_cast<std::uint32_t>((t121a ^ 0x00000080u) - 0x00000080u);
        state.regs[1] = t121a;
    // 0x00937250: 83c1b7 ADD
        t122a = state.regs[1];
        t122b = 0xffffffb7u;
        t122r = static_cast<std::uint32_t>(t122a + t122b) & 0xffffffffu;
        batch_set_add_flags(state, t122a, t122b, t122r, 32u);
        state.regs[1] = t122r;
    // 0x00937253: bd06000000 MOV
        t123 = 0x00000006u;
        state.regs[5] = t123;
    // 0x00937258: 8d7506 LEA
        t124 = static_cast<std::uint32_t>(state.regs[5] + 0x00000006u);
        state.regs[6] = t124;
    // 0x0093725b: 83f931 CMP
        t125a = state.regs[1];
        t125b = 0x00000031u;
        t125r = static_cast<std::uint32_t>(t125a - t125b) & 0xffffffffu;
        batch_set_sub_flags(state, t125a, t125b, t125r, 32u);
    // 0x0093725e: 0f8707010000 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0093736b;
    // 0x00937264: 0fb68988749300 MOVZX
        batch_guest_pc = 0x00937264u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00937488u), t127a)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t127a;
    // 0x0093726b: ff248d68749300 JMP
        batch_guest_pc = 0x0093726bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] * 4u + 0x00937468u), t128a)) return BatchLiftStatus::invalid_memory;
        switch (t128a) {
        case 0x00937272u: goto L_00937272;
        case 0x00937293u: goto L_00937293;
        case 0x009372b4u: goto L_009372b4;
        case 0x009372c1u: goto L_009372c1;
        case 0x009372cau: goto L_009372ca;
        case 0x009372d7u: goto L_009372d7;
        case 0x009372e4u: goto L_009372e4;
        case 0x0093736bu: goto L_0093736b;
        default:
        state.eip = t128a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x00937272: 807a0168 CMP
    L_00937272:
        batch_guest_pc = 0x00937272u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000001u), t129a)) return BatchLiftStatus::invalid_memory;
        t129b = 0x00000068u;
        t129r = static_cast<std::uint32_t>(t129a - t129b) & 0x000000ffu;
        batch_set_sub_flags(state, t129a, t129b, t129r, 8u);
    // 0x00937276: 750e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937286;
    // 0x00937278: c744242801000000 MOV
        batch_guest_pc = 0x00937278u;
        t131 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t131)) return BatchLiftStatus::invalid_memory;
    // 0x00937280: 42 INC
        t132a = state.regs[2];
        t132r = static_cast<std::uint32_t>(t132a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t132a, t132r, 32u);
        state.regs[2] = t132r;
    // 0x00937281: e9e1000000 JMP
        goto L_00937367;
    // 0x00937286: c744242802000000 MOV
    L_00937286:
        batch_guest_pc = 0x00937286u;
        t134 = 0x00000002u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t134)) return BatchLiftStatus::invalid_memory;
    // 0x0093728e: e9d4000000 JMP
        goto L_00937367;
    // 0x00937293: 807a016c CMP
    L_00937293:
        batch_guest_pc = 0x00937293u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000001u), t136a)) return BatchLiftStatus::invalid_memory;
        t136b = 0x0000006cu;
        t136r = static_cast<std::uint32_t>(t136a - t136b) & 0x000000ffu;
        batch_set_sub_flags(state, t136a, t136b, t136r, 8u);
    // 0x00937297: 750e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009372a7;
    // 0x00937299: c744242804000000 MOV
        batch_guest_pc = 0x00937299u;
        t138 = 0x00000004u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t138)) return BatchLiftStatus::invalid_memory;
    // 0x009372a1: 42 INC
        t139a = state.regs[2];
        t139r = static_cast<std::uint32_t>(t139a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t139a, t139r, 32u);
        state.regs[2] = t139r;
    // 0x009372a2: e9c0000000 JMP
        goto L_00937367;
    // 0x009372a7: c744242803000000 MOV
    L_009372a7:
        batch_guest_pc = 0x009372a7u;
        t141 = 0x00000003u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t141)) return BatchLiftStatus::invalid_memory;
    // 0x009372af: e9b3000000 JMP
        goto L_00937367;
    // 0x009372b4: c744242805000000 MOV
    L_009372b4:
        batch_guest_pc = 0x009372b4u;
        t143 = 0x00000005u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t143)) return BatchLiftStatus::invalid_memory;
    // 0x009372bc: e9a6000000 JMP
        goto L_00937367;
    // 0x009372c1: 896c2428 MOV
    L_009372c1:
        batch_guest_pc = 0x009372c1u;
        t145 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t145)) return BatchLiftStatus::invalid_memory;
    // 0x009372c5: e99d000000 JMP
        goto L_00937367;
    // 0x009372ca: c744242807000000 MOV
    L_009372ca:
        batch_guest_pc = 0x009372cau;
        t147 = 0x00000007u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t147)) return BatchLiftStatus::invalid_memory;
    // 0x009372d2: e990000000 JMP
        goto L_00937367;
    // 0x009372d7: c744242808000000 MOV
    L_009372d7:
        batch_guest_pc = 0x009372d7u;
        t149 = 0x00000008u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t149)) return BatchLiftStatus::invalid_memory;
    // 0x009372df: e983000000 JMP
        goto L_00937367;
    // 0x009372e4: 8a4a01 MOV
    L_009372e4:
        batch_guest_pc = 0x009372e4u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000001u), t151)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t151 << 0u) & 0x000000ffu);
    // 0x009372e7: 8d4201 LEA
        t152 = static_cast<std::uint32_t>(state.regs[2] + 0x00000001u);
        state.regs[0] = t152;
    // 0x009372ea: 80f938 CMP
        t153a = state.regs[1] & 0x000000ffu;
        t153b = 0x00000038u;
        t153r = static_cast<std::uint32_t>(t153a - t153b) & 0x000000ffu;
        batch_set_sub_flags(state, t153a, t153b, t153r, 8u);
    // 0x009372ed: 750c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009372fb;
    // 0x009372ef: c74424280a000000 MOV
        batch_guest_pc = 0x009372efu;
        t155 = 0x0000000au;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t155)) return BatchLiftStatus::invalid_memory;
    // 0x009372f7: 8bd0 MOV
        t156 = state.regs[0];
        state.regs[2] = t156;
    // 0x009372f9: eb6c JMP
        goto L_00937367;
    // 0x009372fb: 80f931 CMP
    L_009372fb:
        t158a = state.regs[1] & 0x000000ffu;
        t158b = 0x00000031u;
        t158r = static_cast<std::uint32_t>(t158a - t158b) & 0x000000ffu;
        batch_set_sub_flags(state, t158a, t158b, t158r, 8u);
    // 0x009372fe: 7513 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937313;
    // 0x00937300: 807a0236 CMP
        batch_guest_pc = 0x00937300u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000002u), t160a)) return BatchLiftStatus::invalid_memory;
        t160b = 0x00000036u;
        t160r = static_cast<std::uint32_t>(t160a - t160b) & 0x000000ffu;
        batch_set_sub_flags(state, t160a, t160b, t160r, 8u);
    // 0x00937304: 750d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937313;
    // 0x00937306: c74424280b000000 MOV
        batch_guest_pc = 0x00937306u;
        t162 = 0x0000000bu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t162)) return BatchLiftStatus::invalid_memory;
    // 0x0093730e: 83c202 ADD
        t163a = state.regs[2];
        t163b = 0x00000002u;
        t163r = static_cast<std::uint32_t>(t163a + t163b) & 0xffffffffu;
        batch_set_add_flags(state, t163a, t163b, t163r, 32u);
        state.regs[2] = t163r;
    // 0x00937311: eb54 JMP
        goto L_00937367;
    // 0x00937313: b332 MOV
    L_00937313:
        t165 = 0x00000032u;
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t165 << 0u) & 0x000000ffu);
    // 0x00937315: 80f933 CMP
        t166a = state.regs[1] & 0x000000ffu;
        t166b = 0x00000033u;
        t166r = static_cast<std::uint32_t>(t166a - t166b) & 0x000000ffu;
        batch_set_sub_flags(state, t166a, t166b, t166r, 8u);
    // 0x00937318: 750e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937328;
    // 0x0093731a: 385a02 CMP
        batch_guest_pc = 0x0093731au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000002u), t168a)) return BatchLiftStatus::invalid_memory;
        t168b = state.regs[3] & 0x000000ffu;
        t168r = static_cast<std::uint32_t>(t168a - t168b) & 0x000000ffu;
        batch_set_sub_flags(state, t168a, t168b, t168r, 8u);
    // 0x0093731d: 7509 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937328;
    // 0x0093731f: 89742428 MOV
        batch_guest_pc = 0x0093731fu;
        t170 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t170)) return BatchLiftStatus::invalid_memory;
    // 0x00937323: 83c202 ADD
        t171a = state.regs[2];
        t171b = 0x00000002u;
        t171r = static_cast<std::uint32_t>(t171a + t171b) & 0xffffffffu;
        batch_set_add_flags(state, t171a, t171b, t171r, 32u);
        state.regs[2] = t171r;
    // 0x00937326: eb3f JMP
        goto L_00937367;
    // 0x00937328: 80f936 CMP
    L_00937328:
        t173a = state.regs[1] & 0x000000ffu;
        t173b = 0x00000036u;
        t173r = static_cast<std::uint32_t>(t173a - t173b) & 0x000000ffu;
        batch_set_sub_flags(state, t173a, t173b, t173r, 8u);
    // 0x0093732b: 7513 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937340;
    // 0x0093732d: 807a0234 CMP
        batch_guest_pc = 0x0093732du;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000002u), t175a)) return BatchLiftStatus::invalid_memory;
        t175b = 0x00000034u;
        t175r = static_cast<std::uint32_t>(t175a - t175b) & 0x000000ffu;
        batch_set_sub_flags(state, t175a, t175b, t175r, 8u);
    // 0x00937331: 750d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937340;
    // 0x00937333: c74424280d000000 MOV
        batch_guest_pc = 0x00937333u;
        t177 = 0x0000000du;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t177)) return BatchLiftStatus::invalid_memory;
    // 0x0093733b: 83c202 ADD
        t178a = state.regs[2];
        t178b = 0x00000002u;
        t178r = static_cast<std::uint32_t>(t178a + t178b) & 0xffffffffu;
        batch_set_add_flags(state, t178a, t178b, t178r, 32u);
        state.regs[2] = t178r;
    // 0x0093733e: eb27 JMP
        goto L_00937367;
    // 0x00937340: 80f931 CMP
    L_00937340:
        t180a = state.regs[1] & 0x000000ffu;
        t180b = 0x00000031u;
        t180r = static_cast<std::uint32_t>(t180a - t180b) & 0x000000ffu;
        batch_set_sub_flags(state, t180a, t180b, t180r, 8u);
    // 0x00937343: 0f85dc000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937425;
    // 0x00937349: 385a02 CMP
        batch_guest_pc = 0x00937349u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000002u), t182a)) return BatchLiftStatus::invalid_memory;
        t182b = state.regs[3] & 0x000000ffu;
        t182r = static_cast<std::uint32_t>(t182a - t182b) & 0x000000ffu;
        batch_set_sub_flags(state, t182a, t182b, t182r, 8u);
    // 0x0093734c: 0f85d3000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937425;
    // 0x00937352: 807a0338 CMP
        batch_guest_pc = 0x00937352u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000003u), t184a)) return BatchLiftStatus::invalid_memory;
        t184b = 0x00000038u;
        t184r = static_cast<std::uint32_t>(t184a - t184b) & 0x000000ffu;
        batch_set_sub_flags(state, t184a, t184b, t184r, 8u);
    // 0x00937356: 0f85c9000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937425;
    // 0x0093735c: c74424280e000000 MOV
        batch_guest_pc = 0x0093735cu;
        t186 = 0x0000000eu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t186)) return BatchLiftStatus::invalid_memory;
    // 0x00937364: 83c203 ADD
        t187a = state.regs[2];
        t187b = 0x00000003u;
        t187r = static_cast<std::uint32_t>(t187a + t187b) & 0xffffffffu;
        batch_set_add_flags(state, t187a, t187b, t187r, 32u);
        state.regs[2] = t187r;
    // 0x00937367: 8a4201 MOV
    L_00937367:
        batch_guest_pc = 0x00937367u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000001u), t188)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t188 << 0u) & 0x000000ffu);
    // 0x0093736a: 42 INC
        t189a = state.regs[2];
        t189r = static_cast<std::uint32_t>(t189a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t189a, t189r, 32u);
        state.regs[2] = t189r;
    // 0x0093736b: 0fbec8 MOVSX
    L_0093736b:
        t190a = state.regs[0] & 0x000000ffu;
        t190a = static_cast<std::uint32_t>((t190a ^ 0x00000080u) - 0x00000080u);
        state.regs[1] = t190a;
    // 0x0093736e: 894c242c MOV
        batch_guest_pc = 0x0093736eu;
        t191 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t191)) return BatchLiftStatus::invalid_memory;
    // 0x00937372: 83c1bf ADD
        t192a = state.regs[1];
        t192b = 0xffffffbfu;
        t192r = static_cast<std::uint32_t>(t192a + t192b) & 0xffffffffu;
        batch_set_add_flags(state, t192a, t192b, t192r, 32u);
        state.regs[1] = t192r;
    // 0x00937375: 83f937 CMP
        t193a = state.regs[1];
        t193b = 0x00000037u;
        t193r = static_cast<std::uint32_t>(t193a - t193b) & 0xffffffffu;
        batch_set_sub_flags(state, t193a, t193b, t193r, 32u);
    // 0x00937378: 0f87a4000000 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00937422;
    // 0x0093737e: 0fb689d4749300 MOVZX
        batch_guest_pc = 0x0093737eu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x009374d4u), t195a)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t195a;
    // 0x00937385: ff248dbc749300 JMP
        batch_guest_pc = 0x00937385u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] * 4u + 0x009374bcu), t196a)) return BatchLiftStatus::invalid_memory;
        switch (t196a) {
        case 0x0093738cu: goto L_0093738c;
        case 0x009373b2u: goto L_009373b2;
        case 0x009373b6u: goto L_009373b6;
        case 0x009373c4u: goto L_009373c4;
        case 0x009373dfu: goto L_009373df;
        case 0x00937422u: goto L_00937422;
        default:
        state.eip = t196a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x0093738c: 81ffffffff7f CMP
    L_0093738c:
        t197a = state.regs[7];
        t197b = 0x7fffffffu;
        t197r = static_cast<std::uint32_t>(t197a - t197b) & 0xffffffffu;
        batch_set_sub_flags(state, t197a, t197b, t197r, 32u);
    // 0x00937392: 750d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009373a1;
    // 0x00937394: c744242401000000 MOV
    L_00937394:
        batch_guest_pc = 0x00937394u;
        t199 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t199)) return BatchLiftStatus::invalid_memory;
    // 0x0093739c: e981000000 JMP
        goto L_00937422;
    // 0x009373a1: 837c241402 CMP
    L_009373a1:
        batch_guest_pc = 0x009373a1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t201a)) return BatchLiftStatus::invalid_memory;
        t201b = 0x00000002u;
        t201r = static_cast<std::uint32_t>(t201a - t201b) & 0xffffffffu;
        batch_set_sub_flags(state, t201a, t201b, t201r, 32u);
    // 0x009373a6: 757a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937422;
    // 0x009373a8: c744241401000000 MOV
        batch_guest_pc = 0x009373a8u;
        t203 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t203)) return BatchLiftStatus::invalid_memory;
    // 0x009373b0: eb70 JMP
        goto L_00937422;
    // 0x009373b2: 85ff TEST
    L_009373b2:
        t205a = state.regs[7];
        t205b = state.regs[7];
        t205r = (t205a & t205b) & 0xffffffffu;
        batch_set_logic_flags(state, t205r, 32u);
    // 0x009373b4: 74de JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937394;
    // 0x009373b6: 81ffffffff7f CMP
    L_009373b6:
        t207a = state.regs[7];
        t207b = 0x7fffffffu;
        t207r = static_cast<std::uint32_t>(t207a - t207b) & 0xffffffffu;
        batch_set_sub_flags(state, t207a, t207b, t207r, 32u);
    // 0x009373bc: 7564 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937422;
    // 0x009373be: 896c2424 MOV
        batch_guest_pc = 0x009373beu;
        t209 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t209)) return BatchLiftStatus::invalid_memory;
    // 0x009373c2: eb5e JMP
        goto L_00937422;
    // 0x009373c4: 89742428 MOV
    L_009373c4:
        batch_guest_pc = 0x009373c4u;
        t211 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t211)) return BatchLiftStatus::invalid_memory;
    // 0x009373c8: c744242401000000 MOV
        batch_guest_pc = 0x009373c8u;
        t212 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t212)) return BatchLiftStatus::invalid_memory;
    // 0x009373d0: c744242c78000000 MOV
        batch_guest_pc = 0x009373d0u;
        t213 = 0x00000078u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t213)) return BatchLiftStatus::invalid_memory;
    // 0x009373d8: c644241c01 MOV
        batch_guest_pc = 0x009373d8u;
        t214 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t214)) return BatchLiftStatus::invalid_memory;
    // 0x009373dd: eb43 JMP
        goto L_00937422;
    // 0x009373df: 837c241402 CMP
    L_009373df:
        batch_guest_pc = 0x009373dfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t216a)) return BatchLiftStatus::invalid_memory;
        t216b = 0x00000002u;
        t216r = static_cast<std::uint32_t>(t216a - t216b) & 0xffffffffu;
        batch_set_sub_flags(state, t216a, t216b, t216r, 32u);
    // 0x009373e4: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009373ee;
    // 0x009373e6: 8b4c2410 MOV
        batch_guest_pc = 0x009373e6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t218)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t218;
    // 0x009373ea: 894c2414 MOV
        batch_guest_pc = 0x009373eau;
        t219 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t219)) return BatchLiftStatus::invalid_memory;
    // 0x009373ee: 8b4c2428 MOV
    L_009373ee:
        batch_guest_pc = 0x009373eeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t220)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t220;
    // 0x009373f2: 83f902 CMP
        t221a = state.regs[1];
        t221b = 0x00000002u;
        t221r = static_cast<std::uint32_t>(t221a - t221b) & 0xffffffffu;
        batch_set_sub_flags(state, t221a, t221b, t221r, 32u);
    // 0x009373f5: 750a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937401;
    // 0x009373f7: c744242801000000 MOV
        batch_guest_pc = 0x009373f7u;
        t223 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t223)) return BatchLiftStatus::invalid_memory;
    // 0x009373ff: eb21 JMP
        goto L_00937422;
    // 0x00937401: 83f903 CMP
    L_00937401:
        t225a = state.regs[1];
        t225b = 0x00000003u;
        t225r = static_cast<std::uint32_t>(t225a - t225b) & 0xffffffffu;
        batch_set_sub_flags(state, t225a, t225b, t225r, 32u);
    // 0x00937404: 750a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937410;
    // 0x00937406: c744242809000000 MOV
        batch_guest_pc = 0x00937406u;
        t227 = 0x00000009u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t227)) return BatchLiftStatus::invalid_memory;
    // 0x0093740e: eb12 JMP
        goto L_00937422;
    // 0x00937410: 33c9 XOR
    L_00937410:
        t229a = state.regs[1];
        t229b = state.regs[1];
        t229r = (t229a ^ t229b) & 0xffffffffu;
        batch_set_logic_flags(state, t229r, 32u);
        state.regs[1] = t229r;
    // 0x00937412: 3c73 CMP
        t230a = state.regs[0] & 0x000000ffu;
        t230b = 0x00000073u;
        t230r = static_cast<std::uint32_t>(t230a - t230b) & 0x000000ffu;
        batch_set_sub_flags(state, t230a, t230b, t230r, 8u);
    // 0x00937414: 0f95c1 SETNZ
        state.regs[1] = (state.regs[1] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00937417: 8d0ccd01000000 LEA
        t232 = static_cast<std::uint32_t>(state.regs[1] * 8u + 0x00000001u);
        state.regs[1] = t232;
    // 0x0093741e: 894c2428 MOV
        batch_guest_pc = 0x0093741eu;
        t233 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t233)) return BatchLiftStatus::invalid_memory;
    // 0x00937422: 8d4201 LEA
    L_00937422:
        t234 = static_cast<std::uint32_t>(state.regs[2] + 0x00000001u);
        state.regs[0] = t234;
    // 0x00937425: 8b7c2434 MOV
    L_00937425:
        batch_guest_pc = 0x00937425u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t235)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t235;
    // 0x00937429: b907000000 MOV
        t236 = 0x00000007u;
        state.regs[1] = t236;
    // 0x0093742e: 8d742414 LEA
        t237 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[6] = t237;
    // 0x00937432: f3a5 MOVSD.REP
        if (!batch_guest_rep_movs(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
    // 0x00937434: 5f POP
        batch_guest_pc = 0x00937434u;
        if (!memory.load32(state.regs[4], t239a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t239a;
    // 0x00937435: 5e POP
        batch_guest_pc = 0x00937435u;
        if (!memory.load32(state.regs[4], t240a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t240a;
    // 0x00937436: 5d POP
        batch_guest_pc = 0x00937436u;
        if (!memory.load32(state.regs[4], t241a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t241a;
    // 0x00937437: 5b POP
        batch_guest_pc = 0x00937437u;
        if (!memory.load32(state.regs[4], t242a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t242a;
    // 0x00937438: 83c420 ADD
        t243a = state.regs[4];
        t243b = 0x00000020u;
        t243r = static_cast<std::uint32_t>(t243a + t243b) & 0xffffffffu;
        batch_set_add_flags(state, t243a, t243b, t243r, 32u);
        state.regs[4] = t243r;
    // 0x0093743b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
