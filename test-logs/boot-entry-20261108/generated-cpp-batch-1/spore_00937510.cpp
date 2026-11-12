#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009375ba(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009375c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009375d8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009375f3(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937656(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00937510(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00937510u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t46a = 0, t46r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58a = 0, t58c = 0, t58r = 0;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t68a = 0, t68b = 0, t68r = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70r = 0;
    std::uint32_t t71a = 0, t71r = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77a = 0, t77b = 0, t77r = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t81a = 0, t81b = 0, t81r = 0;
    std::uint32_t t83a = 0, t83r = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85a = 0, t85r = 0;
    std::uint32_t t86a = 0, t86b = 0, t86r = 0;
    std::uint32_t t88a = 0, t88b = 0, t88r = 0;
    std::uint32_t t90a = 0, t90b = 0, t90r = 0;
    std::uint32_t t92a = 0, t92b = 0, t92r = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99a = 0, t99b = 0, t99r = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104a = 0, t104r = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107a = 0, t107b = 0, t107r = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0, t111r = 0;
    std::uint32_t t112a = 0, t112b = 0, t112r = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t115a = 0;
    std::uint32_t t116a = 0, t116b = 0, t116r = 0;
    std::uint32_t t118 = 0;
    std::uint32_t t119a = 0, t119b = 0, t119r = 0;
    std::uint32_t t121a = 0, t121b = 0, t121r = 0;
    std::uint32_t t123a = 0, t123b = 0, t123r = 0;
    std::uint32_t t125a = 0, t125r = 0;
    std::uint32_t t126a = 0;
    std::uint32_t t127 = 0;
    std::uint32_t t128 = 0;
    std::uint32_t t129a = 0;
    std::uint32_t t130a = 0;
    std::uint32_t t131a = 0, t131b = 0, t131r = 0;
    std::uint32_t t133 = 0;
    std::uint32_t t134a = 0, t134b = 0, t134r = 0;
    std::uint32_t t136a = 0, t136r = 0;
    std::uint32_t t137a = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139 = 0;
    std::uint32_t t140a = 0;
    std::uint32_t t141a = 0;
    std::uint32_t t142a = 0, t142b = 0, t142r = 0;
    std::uint32_t t144a = 0, t144b = 0, t144r = 0;
    std::uint32_t t146a = 0, t146r = 0;
    std::uint32_t t147a = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150a = 0;
    std::uint32_t t151a = 0;
    std::uint32_t t152a = 0, t152b = 0, t152r = 0;
    std::uint32_t t154a = 0, t154b = 0, t154r = 0;
    std::uint32_t t156a = 0, t156b = 0, t156r = 0;
    std::uint32_t t158a = 0, t158b = 0, t158r = 0;
    std::uint32_t t160 = 0;
    std::uint32_t t161a = 0, t161r = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163a = 0, t163r = 0;
    std::uint32_t t164 = 0;
    std::uint32_t t165a = 0;
    std::uint32_t t166 = 0;
    std::uint32_t t167a = 0;
    std::uint32_t t168a = 0;
    std::uint32_t t169a = 0, t169b = 0, t169r = 0;

    // 0x00937510: 83ec10 SUB
        t0a = state.regs[4];
        t0b = 0x00000010u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00937513: 55 PUSH
        batch_guest_pc = 0x00937513u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00937514: 56 PUSH
        batch_guest_pc = 0x00937514u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00937515: 8b74241c MOV
        batch_guest_pc = 0x00937515u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t3;
    // 0x00937519: 57 PUSH
        batch_guest_pc = 0x00937519u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0093751a: 8bf9 MOV
        t5 = state.regs[1];
        state.regs[7] = t5;
    // 0x0093751c: 8b5710 MOV
        batch_guest_pc = 0x0093751cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t6;
    // 0x0093751f: 33c9 XOR
        t7a = state.regs[1];
        t7b = state.regs[1];
        t7r = (t7a ^ t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
        state.regs[1] = t7r;
    // 0x00937521: 4e DEC
        t8a = state.regs[6];
        t8r = static_cast<std::uint32_t>(t8a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t8a, t8r, 32u);
        state.regs[6] = t8r;
    // 0x00937522: 33ed XOR
        t9a = state.regs[5];
        t9b = state.regs[5];
        t9r = (t9a ^ t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
        state.regs[5] = t9r;
    // 0x00937524: 3bc1 CMP
        t10a = state.regs[0];
        t10b = state.regs[1];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x00937526: 894c2414 MOV
        batch_guest_pc = 0x00937526u;
        t11 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x0093752a: 894c2410 MOV
        batch_guest_pc = 0x0093752au;
        t12 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x0093752e: 89542418 MOV
        batch_guest_pc = 0x0093752eu;
        t13 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00937532: 884c240f MOV
        batch_guest_pc = 0x00937532u;
        t14 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000fu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00937536: 880e MOV
        batch_guest_pc = 0x00937536u;
        t15 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00937538: 7f0e JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00937548;
    // 0x0093753a: 394f10 CMP
        batch_guest_pc = 0x0093753au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = state.regs[1];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x0093753d: 7f09 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00937548;
    // 0x0093753f: 384f08 CMP
        batch_guest_pc = 0x0093753fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t19a)) return BatchLiftStatus::invalid_memory;
        t19b = state.regs[1] & 0x000000ffu;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0x000000ffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 8u);
    // 0x00937542: 0f8489010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009376d1;
    // 0x00937548: 8b5718 MOV
    L_00937548:
        batch_guest_pc = 0x00937548u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x0093754b: 83c2a8 ADD
        t22a = state.regs[2];
        t22b = 0xffffffa8u;
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[2] = t22r;
    // 0x0093754e: 83fa20 CMP
        t23a = state.regs[2];
        t23b = 0x00000020u;
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x00937551: 774d JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_009375a0;
    // 0x00937553: 0fb692f0769300 MOVZX
        batch_guest_pc = 0x00937553u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x009376f0u), t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t25a;
    // 0x0093755a: ff2495dc769300 JMP
        batch_guest_pc = 0x0093755au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] * 4u + 0x009376dcu), t26a)) return BatchLiftStatus::invalid_memory;
        switch (t26a) {
        case 0x00937561u: goto L_00937561;
        case 0x00937572u: goto L_00937572;
        case 0x00937584u: goto L_00937584;
        case 0x0093758eu: goto L_0093758e;
        case 0x009375a0u: goto L_009375a0;
        default:
        state.eip = t26a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x00937561: b901000000 MOV
    L_00937561:
        t27 = 0x00000001u;
        state.regs[1] = t27;
    // 0x00937566: c744242002000000 MOV
        batch_guest_pc = 0x00937566u;
        t28 = 0x00000002u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x0093756e: 8be9 MOV
        t29 = state.regs[1];
        state.regs[5] = t29;
    // 0x00937570: eb48 JMP
        goto L_009375ba;
    // 0x00937572: b903000000 MOV
    L_00937572:
        t31 = 0x00000003u;
        state.regs[1] = t31;
    // 0x00937577: c744242008000000 MOV
        batch_guest_pc = 0x00937577u;
        t32 = 0x00000008u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x0093757f: 8d6904 LEA
        t33 = static_cast<std::uint32_t>(state.regs[1] + 0x00000004u);
        state.regs[5] = t33;
    // 0x00937582: eb36 JMP
        goto L_009375ba;
    // 0x00937584: c74424200a000000 MOV
    L_00937584:
        batch_guest_pc = 0x00937584u;
        t35 = 0x0000000au;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x0093758c: eb2c JMP
        goto L_009375ba;
    // 0x0093758e: b904000000 MOV
    L_0093758e:
        t37 = 0x00000004u;
        state.regs[1] = t37;
    // 0x00937593: c744242010000000 MOV
        batch_guest_pc = 0x00937593u;
        t38 = 0x00000010u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x0093759b: 8d690b LEA
        t39 = static_cast<std::uint32_t>(state.regs[1] + 0x0000000bu);
        state.regs[5] = t39;
    // 0x0093759e: eb1a JMP
        goto L_009375ba;
    // 0x009375a0: 3bc1 CMP
    L_009375a0:
        t41a = state.regs[0];
        t41b = state.regs[1];
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
    // 0x009375a2: 8b5704 MOV
        batch_guest_pc = 0x009375a2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t42;
    // 0x009375a5: c74424200a000000 MOV
        batch_guest_pc = 0x009375a5u;
        t43 = 0x0000000au;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x009375ad: 89542414 MOV
        batch_guest_pc = 0x009375adu;
        t44 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x009375b1: 7d07 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009375ba;
    // 0x009375b3: f7d8 NEG
        t46a = state.regs[0];
        t46r = static_cast<std::uint32_t>(0u - t46a) & 0xffffffffu;
        batch_set_neg_flags(state, t46a, t46r, 32u);
        state.regs[0] = t46r;
    // 0x009375b5: c644240f01 MOV
        batch_guest_pc = 0x009375b5u;
        t47 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000fu), t47)) return BatchLiftStatus::invalid_memory;
    // 0x009375ba: 53 PUSH
    L_009375ba:
        batch_guest_pc = 0x009375bau;
        t48a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x009375bb: eb03 JMP
        goto L_009375c0;
    // 0x009375c0: 837c24240a CMP
    L_009375c0:
        batch_guest_pc = 0x009375c0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t50a)) return BatchLiftStatus::invalid_memory;
        t50b = 0x0000000au;
        t50r = static_cast<std::uint32_t>(t50a - t50b) & 0xffffffffu;
        batch_set_sub_flags(state, t50a, t50b, t50r, 32u);
    // 0x009375c5: 750b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009375d2;
    // 0x009375c7: 33d2 XOR
        t52a = state.regs[2];
        t52b = state.regs[2];
        t52r = (t52a ^ t52b) & 0xffffffffu;
        batch_set_logic_flags(state, t52r, 32u);
        state.regs[2] = t52r;
    // 0x009375c9: bb0a000000 MOV
        t53 = 0x0000000au;
        state.regs[3] = t53;
    // 0x009375ce: f7f3 DIV
        t54a = state.regs[3];
        if (t54a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::uint64_t dividend = (static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0];
        const std::uint64_t quotient = dividend / t54a;
        if (quotient > 0xffffffffull) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(dividend % t54a);
        }
    // 0x009375d0: eb06 JMP
        goto L_009375d8;
    // 0x009375d2: 8bd5 MOV
    L_009375d2:
        t56 = state.regs[5];
        state.regs[2] = t56;
    // 0x009375d4: 23d0 AND
        t57a = state.regs[2];
        t57b = state.regs[0];
        t57r = (t57a & t57b) & 0xffffffffu;
        batch_set_logic_flags(state, t57r, 32u);
        state.regs[2] = t57r;
    // 0x009375d6: d3e8 SHR
        t58a = state.regs[0];
        t58c = (state.regs[1] & 0x1fu);
        if (t58c != 0u) {
        t58r = static_cast<std::uint32_t>(t58a >> t58c);
        batch_set_shr_flags(state, t58a, t58c, t58r, 32u);
            state.regs[0] = t58r;
        }
    // 0x009375d8: 83fa0a CMP
    L_009375d8:
        t59a = state.regs[2];
        t59b = 0x0000000au;
        t59r = static_cast<std::uint32_t>(t59a - t59b) & 0xffffffffu;
        batch_set_sub_flags(state, t59a, t59b, t59r, 32u);
    // 0x009375db: 7d05 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009375e2;
    // 0x009375dd: 83c230 ADD
        t61a = state.regs[2];
        t61b = 0x00000030u;
        t61r = static_cast<std::uint32_t>(t61a + t61b) & 0xffffffffu;
        batch_set_add_flags(state, t61a, t61b, t61r, 32u);
        state.regs[2] = t61r;
    // 0x009375e0: eb11 JMP
        goto L_009375f3;
    // 0x009375e2: 83ea0a SUB
    L_009375e2:
        t63a = state.regs[2];
        t63b = 0x0000000au;
        t63r = static_cast<std::uint32_t>(t63a - t63b) & 0xffffffffu;
        batch_set_sub_flags(state, t63a, t63b, t63r, 32u);
        state.regs[2] = t63r;
    // 0x009375e5: 837f1878 CMP
        batch_guest_pc = 0x009375e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t64a)) return BatchLiftStatus::invalid_memory;
        t64b = 0x00000078u;
        t64r = static_cast<std::uint32_t>(t64a - t64b) & 0xffffffffu;
        batch_set_sub_flags(state, t64a, t64b, t64r, 32u);
    // 0x009375e9: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009375f0;
    // 0x009375eb: 83c261 ADD
        t66a = state.regs[2];
        t66b = 0x00000061u;
        t66r = static_cast<std::uint32_t>(t66a + t66b) & 0xffffffffu;
        batch_set_add_flags(state, t66a, t66b, t66r, 32u);
        state.regs[2] = t66r;
    // 0x009375ee: eb03 JMP
        goto L_009375f3;
    // 0x009375f0: 83c241 ADD
    L_009375f0:
        t68a = state.regs[2];
        t68b = 0x00000041u;
        t68r = static_cast<std::uint32_t>(t68a + t68b) & 0xffffffffu;
        batch_set_add_flags(state, t68a, t68b, t68r, 32u);
        state.regs[2] = t68r;
    // 0x009375f3: 8b5c2414 MOV
    L_009375f3:
        batch_guest_pc = 0x009375f3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t69;
    // 0x009375f7: 4e DEC
        t70a = state.regs[6];
        t70r = static_cast<std::uint32_t>(t70a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t70a, t70r, 32u);
        state.regs[6] = t70r;
    // 0x009375f8: 43 INC
        t71a = state.regs[3];
        t71r = static_cast<std::uint32_t>(t71a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t71a, t71r, 32u);
        state.regs[3] = t71r;
    // 0x009375f9: 8816 MOV
        batch_guest_pc = 0x009375f9u;
        t72 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x009375fb: 895c2414 MOV
        batch_guest_pc = 0x009375fbu;
        t73 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t73)) return BatchLiftStatus::invalid_memory;
    // 0x009375ff: 85c0 TEST
        t74a = state.regs[0];
        t74b = state.regs[0];
        t74r = (t74a & t74b) & 0xffffffffu;
        batch_set_logic_flags(state, t74r, 32u);
    // 0x00937601: 77bd JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_009375c0;
    // 0x00937603: 8b4c2424 MOV
        batch_guest_pc = 0x00937603u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t76)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t76;
    // 0x00937607: 83f908 CMP
        t77a = state.regs[1];
        t77b = 0x00000008u;
        t77r = static_cast<std::uint32_t>(t77a - t77b) & 0xffffffffu;
        batch_set_sub_flags(state, t77a, t77b, t77r, 32u);
    // 0x0093760a: 7510 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093761c;
    // 0x0093760c: 807f0800 CMP
        batch_guest_pc = 0x0093760cu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t79a)) return BatchLiftStatus::invalid_memory;
        t79b = 0x00000000u;
        t79r = static_cast<std::uint32_t>(t79a - t79b) & 0x000000ffu;
        batch_set_sub_flags(state, t79a, t79b, t79r, 8u);
    // 0x00937610: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093761c;
    // 0x00937612: 80fa30 CMP
        t81a = state.regs[2] & 0x000000ffu;
        t81b = 0x00000030u;
        t81r = static_cast<std::uint32_t>(t81a - t81b) & 0x000000ffu;
        batch_set_sub_flags(state, t81a, t81b, t81r, 8u);
    // 0x00937615: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093761c;
    // 0x00937617: 4e DEC
        t83a = state.regs[6];
        t83r = static_cast<std::uint32_t>(t83a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t83a, t83r, 32u);
        state.regs[6] = t83r;
    // 0x00937618: c60630 MOV
        batch_guest_pc = 0x00937618u;
        t84 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t84)) return BatchLiftStatus::invalid_memory;
    // 0x0093761b: 43 INC
        t85a = state.regs[3];
        t85r = static_cast<std::uint32_t>(t85a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t85a, t85r, 32u);
        state.regs[3] = t85r;
    // 0x0093761c: 833f02 CMP
    L_0093761c:
        batch_guest_pc = 0x0093761cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t86a)) return BatchLiftStatus::invalid_memory;
        t86b = 0x00000002u;
        t86r = static_cast<std::uint32_t>(t86a - t86b) & 0xffffffffu;
        batch_set_sub_flags(state, t86a, t86b, t86r, 32u);
    // 0x0093761f: 7531 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937652;
    // 0x00937621: 807c241300 CMP
        batch_guest_pc = 0x00937621u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t88a)) return BatchLiftStatus::invalid_memory;
        t88b = 0x00000000u;
        t88r = static_cast<std::uint32_t>(t88a - t88b) & 0x000000ffu;
        batch_set_sub_flags(state, t88a, t88b, t88r, 8u);
    // 0x00937626: 7524 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093764c;
    // 0x00937628: 837c241800 CMP
        batch_guest_pc = 0x00937628u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t90a)) return BatchLiftStatus::invalid_memory;
        t90b = 0x00000000u;
        t90r = static_cast<std::uint32_t>(t90a - t90b) & 0xffffffffu;
        batch_set_sub_flags(state, t90a, t90b, t90r, 32u);
    // 0x0093762d: 751d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093764c;
    // 0x0093762f: 807f0800 CMP
        batch_guest_pc = 0x0093762fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t92a)) return BatchLiftStatus::invalid_memory;
        t92b = 0x00000000u;
        t92r = static_cast<std::uint32_t>(t92a - t92b) & 0x000000ffu;
        batch_set_sub_flags(state, t92a, t92b, t92r, 8u);
    // 0x00937633: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937647;
    // 0x00937635: 83f902 CMP
        t94a = state.regs[1];
        t94b = 0x00000002u;
        t94r = static_cast<std::uint32_t>(t94a - t94b) & 0xffffffffu;
        batch_set_sub_flags(state, t94a, t94b, t94r, 32u);
    // 0x00937638: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093763f;
    // 0x0093763a: 83f910 CMP
        t96a = state.regs[1];
        t96b = 0x00000010u;
        t96r = static_cast<std::uint32_t>(t96a - t96b) & 0xffffffffu;
        batch_set_sub_flags(state, t96a, t96b, t96r, 32u);
    // 0x0093763d: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937647;
    // 0x0093763f: 8b470c MOV
    L_0093763f:
        batch_guest_pc = 0x0093763fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t98)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t98;
    // 0x00937642: 83e802 SUB
        t99a = state.regs[0];
        t99b = 0x00000002u;
        t99r = static_cast<std::uint32_t>(t99a - t99b) & 0xffffffffu;
        batch_set_sub_flags(state, t99a, t99b, t99r, 32u);
        state.regs[0] = t99r;
    // 0x00937645: eb0f JMP
        goto L_00937656;
    // 0x00937647: 8b470c MOV
    L_00937647:
        batch_guest_pc = 0x00937647u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t101)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t101;
    // 0x0093764a: eb0a JMP
        goto L_00937656;
    // 0x0093764c: 8b470c MOV
    L_0093764c:
        batch_guest_pc = 0x0093764cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t103)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t103;
    // 0x0093764f: 48 DEC
        t104a = state.regs[0];
        t104r = static_cast<std::uint32_t>(t104a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t104a, t104r, 32u);
        state.regs[0] = t104r;
    // 0x00937650: eb04 JMP
        goto L_00937656;
    // 0x00937652: 8b44241c MOV
    L_00937652:
        batch_guest_pc = 0x00937652u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t106)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t106;
    // 0x00937656: 3bd8 CMP
    L_00937656:
        t107a = state.regs[3];
        t107b = state.regs[0];
        t107r = static_cast<std::uint32_t>(t107a - t107b) & 0xffffffffu;
        batch_set_sub_flags(state, t107a, t107b, t107r, 32u);
    // 0x00937658: 7d0f JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00937669;
    // 0x0093765a: 2bc3 SUB
        t109a = state.regs[0];
        t109b = state.regs[3];
        t109r = static_cast<std::uint32_t>(t109a - t109b) & 0xffffffffu;
        batch_set_sub_flags(state, t109a, t109b, t109r, 32u);
        state.regs[0] = t109r;
    // 0x0093765c: 8d642400 LEA
        t110 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t110;
    // 0x00937660: 4e DEC
    L_00937660:
        t111a = state.regs[6];
        t111r = static_cast<std::uint32_t>(t111a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t111a, t111r, 32u);
        state.regs[6] = t111r;
    // 0x00937661: 83e801 SUB
        t112a = state.regs[0];
        t112b = 0x00000001u;
        t112r = static_cast<std::uint32_t>(t112a - t112b) & 0xffffffffu;
        batch_set_sub_flags(state, t112a, t112b, t112r, 32u);
        state.regs[0] = t112r;
    // 0x00937664: c60630 MOV
        batch_guest_pc = 0x00937664u;
        t113 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t113)) return BatchLiftStatus::invalid_memory;
    // 0x00937667: 75f7 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937660;
    // 0x00937669: 5b POP
    L_00937669:
        batch_guest_pc = 0x00937669u;
        if (!memory.load32(state.regs[4], t115a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t115a;
    // 0x0093766a: 83f90a CMP
        t116a = state.regs[1];
        t116b = 0x0000000au;
        t116r = static_cast<std::uint32_t>(t116a - t116b) & 0xffffffffu;
        batch_set_sub_flags(state, t116a, t116b, t116r, 32u);
    // 0x0093766d: 7548 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009376b7;
    // 0x0093766f: 8b4718 MOV
        batch_guest_pc = 0x0093766fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t118)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t118;
    // 0x00937672: 83f864 CMP
        t119a = state.regs[0];
        t119b = 0x00000064u;
        t119r = static_cast<std::uint32_t>(t119a - t119b) & 0xffffffffu;
        batch_set_sub_flags(state, t119a, t119b, t119r, 32u);
    // 0x00937675: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093767c;
    // 0x00937677: 83f869 CMP
        t121a = state.regs[0];
        t121b = 0x00000069u;
        t121r = static_cast<std::uint32_t>(t121a - t121b) & 0xffffffffu;
        batch_set_sub_flags(state, t121a, t121b, t121r, 32u);
    // 0x0093767a: 7555 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009376d1;
    // 0x0093767c: 807c240f00 CMP
    L_0093767c:
        batch_guest_pc = 0x0093767cu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000fu), t123a)) return BatchLiftStatus::invalid_memory;
        t123b = 0x00000000u;
        t123r = static_cast<std::uint32_t>(t123a - t123b) & 0x000000ffu;
        batch_set_sub_flags(state, t123a, t123b, t123r, 8u);
    // 0x00937681: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937690;
    // 0x00937683: 4e DEC
        t125a = state.regs[6];
        t125r = static_cast<std::uint32_t>(t125a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t125a, t125r, 32u);
        state.regs[6] = t125r;
    // 0x00937684: 5f POP
        batch_guest_pc = 0x00937684u;
        if (!memory.load32(state.regs[4], t126a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t126a;
    // 0x00937685: c6062d MOV
        batch_guest_pc = 0x00937685u;
        t127 = 0x0000002du;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t127)) return BatchLiftStatus::invalid_memory;
    // 0x00937688: 8bc6 MOV
        t128 = state.regs[6];
        state.regs[0] = t128;
    // 0x0093768a: 5e POP
        batch_guest_pc = 0x0093768au;
        if (!memory.load32(state.regs[4], t129a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t129a;
    // 0x0093768b: 5d POP
        batch_guest_pc = 0x0093768bu;
        if (!memory.load32(state.regs[4], t130a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t130a;
    // 0x0093768c: 83c410 ADD
        t131a = state.regs[4];
        t131b = 0x00000010u;
        t131r = static_cast<std::uint32_t>(t131a + t131b) & 0xffffffffu;
        batch_set_add_flags(state, t131a, t131b, t131r, 32u);
        state.regs[4] = t131r;
    // 0x0093768f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00937690: 8b7f04 MOV
    L_00937690:
        batch_guest_pc = 0x00937690u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t133)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t133;
    // 0x00937693: 83ff02 CMP
        t134a = state.regs[7];
        t134b = 0x00000002u;
        t134r = static_cast<std::uint32_t>(t134a - t134b) & 0xffffffffu;
        batch_set_sub_flags(state, t134a, t134b, t134r, 32u);
    // 0x00937696: 750d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009376a5;
    // 0x00937698: 4e DEC
        t136a = state.regs[6];
        t136r = static_cast<std::uint32_t>(t136a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t136a, t136r, 32u);
        state.regs[6] = t136r;
    // 0x00937699: 5f POP
        batch_guest_pc = 0x00937699u;
        if (!memory.load32(state.regs[4], t137a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t137a;
    // 0x0093769a: c6062b MOV
        batch_guest_pc = 0x0093769au;
        t138 = 0x0000002bu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t138)) return BatchLiftStatus::invalid_memory;
    // 0x0093769d: 8bc6 MOV
        t139 = state.regs[6];
        state.regs[0] = t139;
    // 0x0093769f: 5e POP
        batch_guest_pc = 0x0093769fu;
        if (!memory.load32(state.regs[4], t140a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t140a;
    // 0x009376a0: 5d POP
        batch_guest_pc = 0x009376a0u;
        if (!memory.load32(state.regs[4], t141a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t141a;
    // 0x009376a1: 83c410 ADD
        t142a = state.regs[4];
        t142b = 0x00000010u;
        t142r = static_cast<std::uint32_t>(t142a + t142b) & 0xffffffffu;
        batch_set_add_flags(state, t142a, t142b, t142r, 32u);
        state.regs[4] = t142r;
    // 0x009376a4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009376a5: 83ff03 CMP
    L_009376a5:
        t144a = state.regs[7];
        t144b = 0x00000003u;
        t144r = static_cast<std::uint32_t>(t144a - t144b) & 0xffffffffu;
        batch_set_sub_flags(state, t144a, t144b, t144r, 32u);
    // 0x009376a8: 7527 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009376d1;
    // 0x009376aa: 4e DEC
        t146a = state.regs[6];
        t146r = static_cast<std::uint32_t>(t146a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t146a, t146r, 32u);
        state.regs[6] = t146r;
    // 0x009376ab: 5f POP
        batch_guest_pc = 0x009376abu;
        if (!memory.load32(state.regs[4], t147a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t147a;
    // 0x009376ac: c60620 MOV
        batch_guest_pc = 0x009376acu;
        t148 = 0x00000020u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t148)) return BatchLiftStatus::invalid_memory;
    // 0x009376af: 8bc6 MOV
        t149 = state.regs[6];
        state.regs[0] = t149;
    // 0x009376b1: 5e POP
        batch_guest_pc = 0x009376b1u;
        if (!memory.load32(state.regs[4], t150a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t150a;
    // 0x009376b2: 5d POP
        batch_guest_pc = 0x009376b2u;
        if (!memory.load32(state.regs[4], t151a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t151a;
    // 0x009376b3: 83c410 ADD
        t152a = state.regs[4];
        t152b = 0x00000010u;
        t152r = static_cast<std::uint32_t>(t152a + t152b) & 0xffffffffu;
        batch_set_add_flags(state, t152a, t152b, t152r, 32u);
        state.regs[4] = t152r;
    // 0x009376b6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009376b7: 807f0800 CMP
    L_009376b7:
        batch_guest_pc = 0x009376b7u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t154a)) return BatchLiftStatus::invalid_memory;
        t154b = 0x00000000u;
        t154r = static_cast<std::uint32_t>(t154a - t154b) & 0x000000ffu;
        batch_set_sub_flags(state, t154a, t154b, t154r, 8u);
    // 0x009376bb: 7414 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009376d1;
    // 0x009376bd: 83f902 CMP
        t156a = state.regs[1];
        t156b = 0x00000002u;
        t156r = static_cast<std::uint32_t>(t156a - t156b) & 0xffffffffu;
        batch_set_sub_flags(state, t156a, t156b, t156r, 32u);
    // 0x009376c0: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009376c7;
    // 0x009376c2: 83f910 CMP
        t158a = state.regs[1];
        t158b = 0x00000010u;
        t158r = static_cast<std::uint32_t>(t158a - t158b) & 0xffffffffu;
        batch_set_sub_flags(state, t158a, t158b, t158r, 32u);
    // 0x009376c5: 750a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009376d1;
    // 0x009376c7: 8a4718 MOV
    L_009376c7:
        batch_guest_pc = 0x009376c7u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t160)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t160 << 0u) & 0x000000ffu);
    // 0x009376ca: 4e DEC
        t161a = state.regs[6];
        t161r = static_cast<std::uint32_t>(t161a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t161a, t161r, 32u);
        state.regs[6] = t161r;
    // 0x009376cb: 8806 MOV
        batch_guest_pc = 0x009376cbu;
        t162 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t162)) return BatchLiftStatus::invalid_memory;
    // 0x009376cd: 4e DEC
        t163a = state.regs[6];
        t163r = static_cast<std::uint32_t>(t163a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t163a, t163r, 32u);
        state.regs[6] = t163r;
    // 0x009376ce: c60630 MOV
        batch_guest_pc = 0x009376ceu;
        t164 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t164)) return BatchLiftStatus::invalid_memory;
    // 0x009376d1: 5f POP
    L_009376d1:
        batch_guest_pc = 0x009376d1u;
        if (!memory.load32(state.regs[4], t165a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t165a;
    // 0x009376d2: 8bc6 MOV
        t166 = state.regs[6];
        state.regs[0] = t166;
    // 0x009376d4: 5e POP
        batch_guest_pc = 0x009376d4u;
        if (!memory.load32(state.regs[4], t167a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t167a;
    // 0x009376d5: 5d POP
        batch_guest_pc = 0x009376d5u;
        if (!memory.load32(state.regs[4], t168a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t168a;
    // 0x009376d6: 83c410 ADD
        t169a = state.regs[4];
        t169b = 0x00000010u;
        t169r = static_cast<std::uint32_t>(t169a + t169b) & 0xffffffffu;
        batch_set_add_flags(state, t169a, t169b, t169r, 32u);
        state.regs[4] = t169r;
    // 0x009376d9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
