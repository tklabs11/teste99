#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00937802(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937827(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937842(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009378a6(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e08d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e0cc0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00937720(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00937720u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t58a = 0, t58r = 0;
    std::uint32_t t59a = 0, t59b = 0, t59c = 0, t59r = 0;
    std::uint32_t t60a = 0, t60r = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69a = 0;
    std::uint32_t t70a = 0;
    std::uint32_t t71a = 0;
    BatchLiftStatus t72_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78a = 0, t78b = 0, t78r = 0;
    BatchLiftStatus t79_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t80a = 0, t80b = 0, t80r = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;
    std::uint32_t t87a = 0, t87b = 0, t87r = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t90a = 0, t90r = 0;
    std::uint32_t t91a = 0, t91r = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t100a = 0, t100b = 0, t100r = 0;
    std::uint32_t t102a = 0, t102b = 0, t102r = 0;
    std::uint32_t t104a = 0, t104r = 0;
    std::uint32_t t105a = 0, t105r = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107a = 0, t107b = 0, t107r = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t111a = 0, t111b = 0, t111r = 0;
    std::uint32_t t113a = 0, t113b = 0, t113r = 0;
    std::uint32_t t115a = 0, t115b = 0, t115r = 0;
    std::uint32_t t117a = 0, t117b = 0, t117r = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120a = 0, t120b = 0, t120r = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125a = 0, t125r = 0;
    std::uint32_t t127 = 0;
    std::uint32_t t128 = 0;
    std::uint32_t t129a = 0, t129b = 0, t129r = 0;
    std::uint32_t t131a = 0, t131b = 0, t131r = 0;
    std::uint32_t t132a = 0, t132r = 0;
    std::uint32_t t133a = 0, t133b = 0, t133r = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t136a = 0, t136b = 0, t136r = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139a = 0, t139b = 0, t139r = 0;
    std::uint32_t t141a = 0, t141b = 0, t141r = 0;
    std::uint32_t t143a = 0, t143b = 0, t143r = 0;
    std::uint32_t t145a = 0, t145r = 0;
    std::uint32_t t146a = 0;
    std::uint32_t t147 = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149a = 0;
    std::uint32_t t150a = 0;
    std::uint32_t t151a = 0;
    std::uint32_t t152a = 0, t152b = 0, t152r = 0;
    std::uint32_t t154 = 0;
    std::uint32_t t155a = 0, t155b = 0, t155r = 0;
    std::uint32_t t157a = 0, t157r = 0;
    std::uint32_t t158a = 0;
    std::uint32_t t159 = 0;
    std::uint32_t t160 = 0;
    std::uint32_t t161a = 0;
    std::uint32_t t162a = 0;
    std::uint32_t t163a = 0;
    std::uint32_t t164a = 0, t164b = 0, t164r = 0;
    std::uint32_t t166a = 0, t166b = 0, t166r = 0;
    std::uint32_t t168a = 0, t168r = 0;
    std::uint32_t t169a = 0;
    std::uint32_t t170 = 0;
    std::uint32_t t171 = 0;
    std::uint32_t t172a = 0;
    std::uint32_t t173a = 0;
    std::uint32_t t174a = 0;
    std::uint32_t t175a = 0, t175b = 0, t175r = 0;
    std::uint32_t t177a = 0, t177b = 0, t177r = 0;
    std::uint32_t t179a = 0, t179b = 0, t179r = 0;
    std::uint32_t t181a = 0, t181b = 0, t181r = 0;
    std::uint32_t t183 = 0;
    std::uint32_t t184a = 0, t184r = 0;
    std::uint32_t t185 = 0;
    std::uint32_t t186a = 0, t186r = 0;
    std::uint32_t t187 = 0;
    std::uint32_t t188a = 0;
    std::uint32_t t189 = 0;
    std::uint32_t t190a = 0;
    std::uint32_t t191a = 0;
    std::uint32_t t192a = 0;
    std::uint32_t t193a = 0, t193b = 0, t193r = 0;

    // 0x00937720: 83ec18 SUB
        t0a = state.regs[4];
        t0b = 0x00000018u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00937723: 8b442420 MOV
        batch_guest_pc = 0x00937723u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00937727: 8b4c2424 MOV
        batch_guest_pc = 0x00937727u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t2;
    // 0x0093772b: 53 PUSH
        batch_guest_pc = 0x0093772bu;
        t3a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0093772c: 55 PUSH
        batch_guest_pc = 0x0093772cu;
        t4a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0093772d: 8b6c2424 MOV
        batch_guest_pc = 0x0093772du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t5;
    // 0x00937731: 56 PUSH
        batch_guest_pc = 0x00937731u;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00937732: 8b7510 MOV
        batch_guest_pc = 0x00937732u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t7;
    // 0x00937735: 33db XOR
        t8a = state.regs[3];
        t8b = state.regs[3];
        t8r = (t8a ^ t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[3] = t8r;
    // 0x00937737: 8974242c MOV
        batch_guest_pc = 0x00937737u;
        t9 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0093773b: 8b742434 MOV
        batch_guest_pc = 0x0093773bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t10;
    // 0x0093773f: 4e DEC
        t11a = state.regs[6];
        t11r = static_cast<std::uint32_t>(t11a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t11a, t11r, 32u);
        state.regs[6] = t11r;
    // 0x00937740: 3bcb CMP
        t12a = state.regs[1];
        t12b = state.regs[3];
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x00937742: 8bd1 MOV
        t13 = state.regs[1];
        state.regs[2] = t13;
    // 0x00937744: 895c2414 MOV
        batch_guest_pc = 0x00937744u;
        t14 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00937748: 895c2410 MOV
        batch_guest_pc = 0x00937748u;
        t15 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0093774c: 895c2418 MOV
        batch_guest_pc = 0x0093774cu;
        t16 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00937750: 895c240c MOV
        batch_guest_pc = 0x00937750u;
        t17 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00937754: 885c2428 MOV
        batch_guest_pc = 0x00937754u;
        t18 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00937758: 881e MOV
        batch_guest_pc = 0x00937758u;
        t19 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x0093775a: 7f14 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00937770;
    // 0x0093775c: 7c04 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00937762;
    // 0x0093775e: 3bc3 CMP
        t22a = state.regs[0];
        t22b = state.regs[3];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x00937760: 770e JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00937770;
    // 0x00937762: 395d10 CMP
    L_00937762:
        batch_guest_pc = 0x00937762u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t24a)) return BatchLiftStatus::invalid_memory;
        t24b = state.regs[3];
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x00937765: 7f09 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00937770;
    // 0x00937767: 385d08 CMP
        batch_guest_pc = 0x00937767u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t26a)) return BatchLiftStatus::invalid_memory;
        t26b = state.regs[3] & 0x000000ffu;
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0x000000ffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 8u);
    // 0x0093776a: 0f84b4010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937924;
    // 0x00937770: 57 PUSH
    L_00937770:
        batch_guest_pc = 0x00937770u;
        t28a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00937771: 8b7d18 MOV
        batch_guest_pc = 0x00937771u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t29;
    // 0x00937774: 83c7a8 ADD
        t30a = state.regs[7];
        t30b = 0xffffffa8u;
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[7] = t30r;
    // 0x00937777: 83ff20 CMP
        t31a = state.regs[7];
        t31b = 0x00000020u;
        t31r = static_cast<std::uint32_t>(t31a - t31b) & 0xffffffffu;
        batch_set_sub_flags(state, t31a, t31b, t31r, 32u);
    // 0x0093777a: 7757 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_009377d3;
    // 0x0093777c: 0fb6bf44799300 MOVZX
        batch_guest_pc = 0x0093777cu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00937944u), t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t33a;
    // 0x00937783: ff24bd30799300 JMP
        batch_guest_pc = 0x00937783u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] * 4u + 0x00937930u), t34a)) return BatchLiftStatus::invalid_memory;
        switch (t34a) {
        case 0x0093778au: goto L_0093778a;
        case 0x0093779eu: goto L_0093779e;
        case 0x009377b5u: goto L_009377b5;
        case 0x009377bcu: goto L_009377bc;
        case 0x009377d3u: goto L_009377d3;
        default:
        state.eip = t34a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x0093778a: b901000000 MOV
    L_0093778a:
        t35 = 0x00000001u;
        state.regs[1] = t35;
    // 0x0093778f: bf02000000 MOV
        t36 = 0x00000002u;
        state.regs[7] = t36;
    // 0x00937794: 894c2418 MOV
        batch_guest_pc = 0x00937794u;
        t37 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00937798: 894c2414 MOV
        batch_guest_pc = 0x00937798u;
        t38 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x0093779c: eb64 JMP
        goto L_00937802;
    // 0x0093779e: bf08000000 MOV
    L_0093779e:
        t40 = 0x00000008u;
        state.regs[7] = t40;
    // 0x009377a3: c744241803000000 MOV
        batch_guest_pc = 0x009377a3u;
        t41 = 0x00000003u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x009377ab: c744241407000000 MOV
        batch_guest_pc = 0x009377abu;
        t42 = 0x00000007u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x009377b3: eb4d JMP
        goto L_00937802;
    // 0x009377b5: bf0a000000 MOV
    L_009377b5:
        t44 = 0x0000000au;
        state.regs[7] = t44;
    // 0x009377ba: eb46 JMP
        goto L_00937802;
    // 0x009377bc: bf10000000 MOV
    L_009377bc:
        t46 = 0x00000010u;
        state.regs[7] = t46;
    // 0x009377c1: c744241804000000 MOV
        batch_guest_pc = 0x009377c1u;
        t47 = 0x00000004u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x009377c9: c74424140f000000 MOV
        batch_guest_pc = 0x009377c9u;
        t48 = 0x0000000fu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x009377d1: eb2f JMP
        goto L_00937802;
    // 0x009377d3: 3bcb CMP
    L_009377d3:
        t50a = state.regs[1];
        t50b = state.regs[3];
        t50r = static_cast<std::uint32_t>(t50a - t50b) & 0xffffffffu;
        batch_set_sub_flags(state, t50a, t50b, t50r, 32u);
    // 0x009377d5: 8b7d04 MOV
        batch_guest_pc = 0x009377d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t51;
    // 0x009377d8: c74424380a000000 MOV
        batch_guest_pc = 0x009377d8u;
        t52 = 0x0000000au;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x009377e0: 897c241c MOV
        batch_guest_pc = 0x009377e0u;
        t53 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t53)) return BatchLiftStatus::invalid_memory;
    // 0x009377e4: 7f13 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_009377f9;
    // 0x009377e6: 7c04 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_009377ec;
    // 0x009377e8: 3bc3 CMP
        t56a = state.regs[0];
        t56b = state.regs[3];
        t56r = static_cast<std::uint32_t>(t56a - t56b) & 0xffffffffu;
        batch_set_sub_flags(state, t56a, t56b, t56r, 32u);
    // 0x009377ea: 730d JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_009377f9;
    // 0x009377ec: f7d8 NEG
    L_009377ec:
        t58a = state.regs[0];
        t58r = static_cast<std::uint32_t>(0u - t58a) & 0xffffffffu;
        batch_set_neg_flags(state, t58a, t58r, 32u);
        state.regs[0] = t58r;
    // 0x009377ee: 13cb ADC
        t59a = state.regs[1];
        t59b = state.regs[3];
        t59c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t59r = static_cast<std::uint32_t>(t59a + t59b + t59c) & 0xffffffffu;
        batch_set_adc_flags(state, t59a, t59b, t59c, t59r, 32u);
        state.regs[1] = t59r;
    // 0x009377f0: f7d9 NEG
        t60a = state.regs[1];
        t60r = static_cast<std::uint32_t>(0u - t60a) & 0xffffffffu;
        batch_set_neg_flags(state, t60a, t60r, 32u);
        state.regs[1] = t60r;
    // 0x009377f2: 8bd1 MOV
        t61 = state.regs[1];
        state.regs[2] = t61;
    // 0x009377f4: c644242c01 MOV
        batch_guest_pc = 0x009377f4u;
        t62 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t62)) return BatchLiftStatus::invalid_memory;
    // 0x009377f9: 8b7c2438 MOV
    L_009377f9:
        batch_guest_pc = 0x009377f9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t63;
    // 0x009377fd: eb03 JMP
        goto L_00937802;
    // 0x00937800: 33db XOR
    L_00937800:
        t65a = state.regs[3];
        t65b = state.regs[3];
        t65r = (t65a ^ t65b) & 0xffffffffu;
        batch_set_logic_flags(state, t65r, 32u);
        state.regs[3] = t65r;
    // 0x00937802: 83ff0a CMP
    L_00937802:
        t66a = state.regs[7];
        t66b = 0x0000000au;
        t66r = static_cast<std::uint32_t>(t66a - t66b) & 0xffffffffu;
        batch_set_sub_flags(state, t66a, t66b, t66r, 32u);
    // 0x00937805: 7511 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937818;
    // 0x00937807: 53 PUSH
        batch_guest_pc = 0x00937807u;
        t68a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
    // 0x00937808: 57 PUSH
        batch_guest_pc = 0x00937808u;
        t69a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t69a)) return BatchLiftStatus::invalid_memory;
    // 0x00937809: 52 PUSH
        batch_guest_pc = 0x00937809u;
        t70a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t70a)) return BatchLiftStatus::invalid_memory;
    // 0x0093780a: 50 PUSH
        batch_guest_pc = 0x0093780au;
        t71a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t71a)) return BatchLiftStatus::invalid_memory;
    // 0x0093780b: e8b0948a00 CALL
        if (!batch_guest_call32(memory, state, 0x011e0cc0u, 0x00937810u)) return BatchLiftStatus::invalid_memory;
        t72_call_status = spore_lift_011e0cc0(memory, state);
        if (t72_call_status != BatchLiftStatus::returned) return t72_call_status;
        if (state.eip != 0x00937810u) return BatchLiftStatus::invalid_control_flow;
    // 0x00937810: 895c2424 MOV
        batch_guest_pc = 0x00937810u;
        t73 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t73)) return BatchLiftStatus::invalid_memory;
    // 0x00937814: 8bd9 MOV
        t74 = state.regs[1];
        state.regs[3] = t74;
    // 0x00937816: eb0f JMP
        goto L_00937827;
    // 0x00937818: 8b4c2418 MOV
    L_00937818:
        batch_guest_pc = 0x00937818u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t76)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t76;
    // 0x0093781c: 8bd8 MOV
        t77 = state.regs[0];
        state.regs[3] = t77;
    // 0x0093781e: 235c2414 AND
        batch_guest_pc = 0x0093781eu;
        t78a = state.regs[3];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t78b)) return BatchLiftStatus::invalid_memory;
        t78r = (t78a & t78b) & 0xffffffffu;
        batch_set_logic_flags(state, t78r, 32u);
        state.regs[3] = t78r;
    // 0x00937822: e8a9908a00 CALL
        if (!batch_guest_call32(memory, state, 0x011e08d0u, 0x00937827u)) return BatchLiftStatus::invalid_memory;
        t79_call_status = spore_lift_011e08d0(memory, state);
        if (t79_call_status != BatchLiftStatus::returned) return t79_call_status;
        if (state.eip != 0x00937827u) return BatchLiftStatus::invalid_control_flow;
    // 0x00937827: 83fb0a CMP
    L_00937827:
        t80a = state.regs[3];
        t80b = 0x0000000au;
        t80r = static_cast<std::uint32_t>(t80a - t80b) & 0xffffffffu;
        batch_set_sub_flags(state, t80a, t80b, t80r, 32u);
    // 0x0093782a: 7d05 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00937831;
    // 0x0093782c: 83c330 ADD
        t82a = state.regs[3];
        t82b = 0x00000030u;
        t82r = static_cast<std::uint32_t>(t82a + t82b) & 0xffffffffu;
        batch_set_add_flags(state, t82a, t82b, t82r, 32u);
        state.regs[3] = t82r;
    // 0x0093782f: eb11 JMP
        goto L_00937842;
    // 0x00937831: 83eb0a SUB
    L_00937831:
        t84a = state.regs[3];
        t84b = 0x0000000au;
        t84r = static_cast<std::uint32_t>(t84a - t84b) & 0xffffffffu;
        batch_set_sub_flags(state, t84a, t84b, t84r, 32u);
        state.regs[3] = t84r;
    // 0x00937834: 837d1878 CMP
        batch_guest_pc = 0x00937834u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t85a)) return BatchLiftStatus::invalid_memory;
        t85b = 0x00000078u;
        t85r = static_cast<std::uint32_t>(t85a - t85b) & 0xffffffffu;
        batch_set_sub_flags(state, t85a, t85b, t85r, 32u);
    // 0x00937838: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093783f;
    // 0x0093783a: 83c361 ADD
        t87a = state.regs[3];
        t87b = 0x00000061u;
        t87r = static_cast<std::uint32_t>(t87a + t87b) & 0xffffffffu;
        batch_set_add_flags(state, t87a, t87b, t87r, 32u);
        state.regs[3] = t87r;
    // 0x0093783d: eb03 JMP
        goto L_00937842;
    // 0x0093783f: 83c341 ADD
    L_0093783f:
        t89a = state.regs[3];
        t89b = 0x00000041u;
        t89r = static_cast<std::uint32_t>(t89a + t89b) & 0xffffffffu;
        batch_set_add_flags(state, t89a, t89b, t89r, 32u);
        state.regs[3] = t89r;
    // 0x00937842: ff442410 INC
    L_00937842:
        batch_guest_pc = 0x00937842u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t90a)) return BatchLiftStatus::invalid_memory;
        t90r = static_cast<std::uint32_t>(t90a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t90a, t90r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t90r)) return BatchLiftStatus::invalid_memory;
    // 0x00937846: 4e DEC
        t91a = state.regs[6];
        t91r = static_cast<std::uint32_t>(t91a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t91a, t91r, 32u);
        state.regs[6] = t91r;
    // 0x00937847: 881e MOV
        batch_guest_pc = 0x00937847u;
        t92 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t92)) return BatchLiftStatus::invalid_memory;
    // 0x00937849: 85d2 TEST
        t93a = state.regs[2];
        t93b = state.regs[2];
        t93r = (t93a & t93b) & 0xffffffffu;
        batch_set_logic_flags(state, t93r, 32u);
    // 0x0093784b: 77b3 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00937800;
    // 0x0093784d: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00937853;
    // 0x0093784f: 85c0 TEST
        t96a = state.regs[0];
        t96b = state.regs[0];
        t96r = (t96a & t96b) & 0xffffffffu;
        batch_set_logic_flags(state, t96r, 32u);
    // 0x00937851: 77ad JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00937800;
    // 0x00937853: 83ff08 CMP
    L_00937853:
        t98a = state.regs[7];
        t98b = 0x00000008u;
        t98r = static_cast<std::uint32_t>(t98a - t98b) & 0xffffffffu;
        batch_set_sub_flags(state, t98a, t98b, t98r, 32u);
    // 0x00937856: 7513 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093786b;
    // 0x00937858: 807d0800 CMP
        batch_guest_pc = 0x00937858u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t100a)) return BatchLiftStatus::invalid_memory;
        t100b = 0x00000000u;
        t100r = static_cast<std::uint32_t>(t100a - t100b) & 0x000000ffu;
        batch_set_sub_flags(state, t100a, t100b, t100r, 8u);
    // 0x0093785c: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093786b;
    // 0x0093785e: 80fb30 CMP
        t102a = state.regs[3] & 0x000000ffu;
        t102b = 0x00000030u;
        t102r = static_cast<std::uint32_t>(t102a - t102b) & 0x000000ffu;
        batch_set_sub_flags(state, t102a, t102b, t102r, 8u);
    // 0x00937861: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093786b;
    // 0x00937863: 4e DEC
        t104a = state.regs[6];
        t104r = static_cast<std::uint32_t>(t104a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t104a, t104r, 32u);
        state.regs[6] = t104r;
    // 0x00937864: ff442410 INC
        batch_guest_pc = 0x00937864u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t105a)) return BatchLiftStatus::invalid_memory;
        t105r = static_cast<std::uint32_t>(t105a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t105a, t105r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t105r)) return BatchLiftStatus::invalid_memory;
    // 0x00937868: c60630 MOV
        batch_guest_pc = 0x00937868u;
        t106 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t106)) return BatchLiftStatus::invalid_memory;
    // 0x0093786b: 837d0002 CMP
    L_0093786b:
        batch_guest_pc = 0x0093786bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t107a)) return BatchLiftStatus::invalid_memory;
        t107b = 0x00000002u;
        t107r = static_cast<std::uint32_t>(t107a - t107b) & 0xffffffffu;
        batch_set_sub_flags(state, t107a, t107b, t107r, 32u);
    // 0x0093786f: 7531 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009378a2;
    // 0x00937871: 807c242c00 CMP
        batch_guest_pc = 0x00937871u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t109a)) return BatchLiftStatus::invalid_memory;
        t109b = 0x00000000u;
        t109r = static_cast<std::uint32_t>(t109a - t109b) & 0x000000ffu;
        batch_set_sub_flags(state, t109a, t109b, t109r, 8u);
    // 0x00937876: 7524 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093789c;
    // 0x00937878: 837c241c00 CMP
        batch_guest_pc = 0x00937878u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t111a)) return BatchLiftStatus::invalid_memory;
        t111b = 0x00000000u;
        t111r = static_cast<std::uint32_t>(t111a - t111b) & 0xffffffffu;
        batch_set_sub_flags(state, t111a, t111b, t111r, 32u);
    // 0x0093787d: 751d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093789c;
    // 0x0093787f: 807d0800 CMP
        batch_guest_pc = 0x0093787fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t113a)) return BatchLiftStatus::invalid_memory;
        t113b = 0x00000000u;
        t113r = static_cast<std::uint32_t>(t113a - t113b) & 0x000000ffu;
        batch_set_sub_flags(state, t113a, t113b, t113r, 8u);
    // 0x00937883: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937897;
    // 0x00937885: 83ff02 CMP
        t115a = state.regs[7];
        t115b = 0x00000002u;
        t115r = static_cast<std::uint32_t>(t115a - t115b) & 0xffffffffu;
        batch_set_sub_flags(state, t115a, t115b, t115r, 32u);
    // 0x00937888: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093788f;
    // 0x0093788a: 83ff10 CMP
        t117a = state.regs[7];
        t117b = 0x00000010u;
        t117r = static_cast<std::uint32_t>(t117a - t117b) & 0xffffffffu;
        batch_set_sub_flags(state, t117a, t117b, t117r, 32u);
    // 0x0093788d: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937897;
    // 0x0093788f: 8b450c MOV
    L_0093788f:
        batch_guest_pc = 0x0093788fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t119)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t119;
    // 0x00937892: 83e802 SUB
        t120a = state.regs[0];
        t120b = 0x00000002u;
        t120r = static_cast<std::uint32_t>(t120a - t120b) & 0xffffffffu;
        batch_set_sub_flags(state, t120a, t120b, t120r, 32u);
        state.regs[0] = t120r;
    // 0x00937895: eb0f JMP
        goto L_009378a6;
    // 0x00937897: 8b450c MOV
    L_00937897:
        batch_guest_pc = 0x00937897u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t122)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t122;
    // 0x0093789a: eb0a JMP
        goto L_009378a6;
    // 0x0093789c: 8b450c MOV
    L_0093789c:
        batch_guest_pc = 0x0093789cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t124)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t124;
    // 0x0093789f: 48 DEC
        t125a = state.regs[0];
        t125r = static_cast<std::uint32_t>(t125a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t125a, t125r, 32u);
        state.regs[0] = t125r;
    // 0x009378a0: eb04 JMP
        goto L_009378a6;
    // 0x009378a2: 8b442430 MOV
    L_009378a2:
        batch_guest_pc = 0x009378a2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t127)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t127;
    // 0x009378a6: 8b4c2410 MOV
    L_009378a6:
        batch_guest_pc = 0x009378a6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t128)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t128;
    // 0x009378aa: 3bc8 CMP
        t129a = state.regs[1];
        t129b = state.regs[0];
        t129r = static_cast<std::uint32_t>(t129a - t129b) & 0xffffffffu;
        batch_set_sub_flags(state, t129a, t129b, t129r, 32u);
    // 0x009378ac: 7d0b JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009378b9;
    // 0x009378ae: 2bc1 SUB
        t131a = state.regs[0];
        t131b = state.regs[1];
        t131r = static_cast<std::uint32_t>(t131a - t131b) & 0xffffffffu;
        batch_set_sub_flags(state, t131a, t131b, t131r, 32u);
        state.regs[0] = t131r;
    // 0x009378b0: 4e DEC
    L_009378b0:
        t132a = state.regs[6];
        t132r = static_cast<std::uint32_t>(t132a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t132a, t132r, 32u);
        state.regs[6] = t132r;
    // 0x009378b1: 83e801 SUB
        t133a = state.regs[0];
        t133b = 0x00000001u;
        t133r = static_cast<std::uint32_t>(t133a - t133b) & 0xffffffffu;
        batch_set_sub_flags(state, t133a, t133b, t133r, 32u);
        state.regs[0] = t133r;
    // 0x009378b4: c60630 MOV
        batch_guest_pc = 0x009378b4u;
        t134 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t134)) return BatchLiftStatus::invalid_memory;
    // 0x009378b7: 75f7 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009378b0;
    // 0x009378b9: 83ff0a CMP
    L_009378b9:
        t136a = state.regs[7];
        t136b = 0x0000000au;
        t136r = static_cast<std::uint32_t>(t136a - t136b) & 0xffffffffu;
        batch_set_sub_flags(state, t136a, t136b, t136r, 32u);
    // 0x009378bc: 754b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937909;
    // 0x009378be: 8b4518 MOV
        batch_guest_pc = 0x009378beu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t138)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t138;
    // 0x009378c1: 83f864 CMP
        t139a = state.regs[0];
        t139b = 0x00000064u;
        t139r = static_cast<std::uint32_t>(t139a - t139b) & 0xffffffffu;
        batch_set_sub_flags(state, t139a, t139b, t139r, 32u);
    // 0x009378c4: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009378cb;
    // 0x009378c6: 83f869 CMP
        t141a = state.regs[0];
        t141b = 0x00000069u;
        t141r = static_cast<std::uint32_t>(t141a - t141b) & 0xffffffffu;
        batch_set_sub_flags(state, t141a, t141b, t141r, 32u);
    // 0x009378c9: 7558 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937923;
    // 0x009378cb: 807c242c00 CMP
    L_009378cb:
        batch_guest_pc = 0x009378cbu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t143a)) return BatchLiftStatus::invalid_memory;
        t143b = 0x00000000u;
        t143r = static_cast<std::uint32_t>(t143a - t143b) & 0x000000ffu;
        batch_set_sub_flags(state, t143a, t143b, t143r, 8u);
    // 0x009378d0: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009378e0;
    // 0x009378d2: 4e DEC
        t145a = state.regs[6];
        t145r = static_cast<std::uint32_t>(t145a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t145a, t145r, 32u);
        state.regs[6] = t145r;
    // 0x009378d3: 5f POP
        batch_guest_pc = 0x009378d3u;
        if (!memory.load32(state.regs[4], t146a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t146a;
    // 0x009378d4: c6062d MOV
        batch_guest_pc = 0x009378d4u;
        t147 = 0x0000002du;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t147)) return BatchLiftStatus::invalid_memory;
    // 0x009378d7: 8bc6 MOV
        t148 = state.regs[6];
        state.regs[0] = t148;
    // 0x009378d9: 5e POP
        batch_guest_pc = 0x009378d9u;
        if (!memory.load32(state.regs[4], t149a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t149a;
    // 0x009378da: 5d POP
        batch_guest_pc = 0x009378dau;
        if (!memory.load32(state.regs[4], t150a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t150a;
    // 0x009378db: 5b POP
        batch_guest_pc = 0x009378dbu;
        if (!memory.load32(state.regs[4], t151a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t151a;
    // 0x009378dc: 83c418 ADD
        t152a = state.regs[4];
        t152b = 0x00000018u;
        t152r = static_cast<std::uint32_t>(t152a + t152b) & 0xffffffffu;
        batch_set_add_flags(state, t152a, t152b, t152r, 32u);
        state.regs[4] = t152r;
    // 0x009378df: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009378e0: 8b4504 MOV
    L_009378e0:
        batch_guest_pc = 0x009378e0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t154)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t154;
    // 0x009378e3: 83f802 CMP
        t155a = state.regs[0];
        t155b = 0x00000002u;
        t155r = static_cast<std::uint32_t>(t155a - t155b) & 0xffffffffu;
        batch_set_sub_flags(state, t155a, t155b, t155r, 32u);
    // 0x009378e6: 750e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009378f6;
    // 0x009378e8: 4e DEC
        t157a = state.regs[6];
        t157r = static_cast<std::uint32_t>(t157a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t157a, t157r, 32u);
        state.regs[6] = t157r;
    // 0x009378e9: 5f POP
        batch_guest_pc = 0x009378e9u;
        if (!memory.load32(state.regs[4], t158a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t158a;
    // 0x009378ea: c6062b MOV
        batch_guest_pc = 0x009378eau;
        t159 = 0x0000002bu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t159)) return BatchLiftStatus::invalid_memory;
    // 0x009378ed: 8bc6 MOV
        t160 = state.regs[6];
        state.regs[0] = t160;
    // 0x009378ef: 5e POP
        batch_guest_pc = 0x009378efu;
        if (!memory.load32(state.regs[4], t161a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t161a;
    // 0x009378f0: 5d POP
        batch_guest_pc = 0x009378f0u;
        if (!memory.load32(state.regs[4], t162a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t162a;
    // 0x009378f1: 5b POP
        batch_guest_pc = 0x009378f1u;
        if (!memory.load32(state.regs[4], t163a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t163a;
    // 0x009378f2: 83c418 ADD
        t164a = state.regs[4];
        t164b = 0x00000018u;
        t164r = static_cast<std::uint32_t>(t164a + t164b) & 0xffffffffu;
        batch_set_add_flags(state, t164a, t164b, t164r, 32u);
        state.regs[4] = t164r;
    // 0x009378f5: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009378f6: 83f803 CMP
    L_009378f6:
        t166a = state.regs[0];
        t166b = 0x00000003u;
        t166r = static_cast<std::uint32_t>(t166a - t166b) & 0xffffffffu;
        batch_set_sub_flags(state, t166a, t166b, t166r, 32u);
    // 0x009378f9: 7528 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937923;
    // 0x009378fb: 4e DEC
        t168a = state.regs[6];
        t168r = static_cast<std::uint32_t>(t168a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t168a, t168r, 32u);
        state.regs[6] = t168r;
    // 0x009378fc: 5f POP
        batch_guest_pc = 0x009378fcu;
        if (!memory.load32(state.regs[4], t169a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t169a;
    // 0x009378fd: c60620 MOV
        batch_guest_pc = 0x009378fdu;
        t170 = 0x00000020u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t170)) return BatchLiftStatus::invalid_memory;
    // 0x00937900: 8bc6 MOV
        t171 = state.regs[6];
        state.regs[0] = t171;
    // 0x00937902: 5e POP
        batch_guest_pc = 0x00937902u;
        if (!memory.load32(state.regs[4], t172a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t172a;
    // 0x00937903: 5d POP
        batch_guest_pc = 0x00937903u;
        if (!memory.load32(state.regs[4], t173a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t173a;
    // 0x00937904: 5b POP
        batch_guest_pc = 0x00937904u;
        if (!memory.load32(state.regs[4], t174a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t174a;
    // 0x00937905: 83c418 ADD
        t175a = state.regs[4];
        t175b = 0x00000018u;
        t175r = static_cast<std::uint32_t>(t175a + t175b) & 0xffffffffu;
        batch_set_add_flags(state, t175a, t175b, t175r, 32u);
        state.regs[4] = t175r;
    // 0x00937908: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00937909: 807d0800 CMP
    L_00937909:
        batch_guest_pc = 0x00937909u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t177a)) return BatchLiftStatus::invalid_memory;
        t177b = 0x00000000u;
        t177r = static_cast<std::uint32_t>(t177a - t177b) & 0x000000ffu;
        batch_set_sub_flags(state, t177a, t177b, t177r, 8u);
    // 0x0093790d: 7414 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937923;
    // 0x0093790f: 83ff02 CMP
        t179a = state.regs[7];
        t179b = 0x00000002u;
        t179r = static_cast<std::uint32_t>(t179a - t179b) & 0xffffffffu;
        batch_set_sub_flags(state, t179a, t179b, t179r, 32u);
    // 0x00937912: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937919;
    // 0x00937914: 83ff10 CMP
        t181a = state.regs[7];
        t181b = 0x00000010u;
        t181r = static_cast<std::uint32_t>(t181a - t181b) & 0xffffffffu;
        batch_set_sub_flags(state, t181a, t181b, t181r, 32u);
    // 0x00937917: 750a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937923;
    // 0x00937919: 8a4d18 MOV
    L_00937919:
        batch_guest_pc = 0x00937919u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t183)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t183 << 0u) & 0x000000ffu);
    // 0x0093791c: 4e DEC
        t184a = state.regs[6];
        t184r = static_cast<std::uint32_t>(t184a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t184a, t184r, 32u);
        state.regs[6] = t184r;
    // 0x0093791d: 880e MOV
        batch_guest_pc = 0x0093791du;
        t185 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t185)) return BatchLiftStatus::invalid_memory;
    // 0x0093791f: 4e DEC
        t186a = state.regs[6];
        t186r = static_cast<std::uint32_t>(t186a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t186a, t186r, 32u);
        state.regs[6] = t186r;
    // 0x00937920: c60630 MOV
        batch_guest_pc = 0x00937920u;
        t187 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t187)) return BatchLiftStatus::invalid_memory;
    // 0x00937923: 5f POP
    L_00937923:
        batch_guest_pc = 0x00937923u;
        if (!memory.load32(state.regs[4], t188a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t188a;
    // 0x00937924: 8bc6 MOV
    L_00937924:
        t189 = state.regs[6];
        state.regs[0] = t189;
    // 0x00937926: 5e POP
        batch_guest_pc = 0x00937926u;
        if (!memory.load32(state.regs[4], t190a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t190a;
    // 0x00937927: 5d POP
        batch_guest_pc = 0x00937927u;
        if (!memory.load32(state.regs[4], t191a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t191a;
    // 0x00937928: 5b POP
        batch_guest_pc = 0x00937928u;
        if (!memory.load32(state.regs[4], t192a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t192a;
    // 0x00937929: 83c418 ADD
        t193a = state.regs[4];
        t193b = 0x00000018u;
        t193r = static_cast<std::uint32_t>(t193a + t193b) & 0xffffffffu;
        batch_set_add_flags(state, t193a, t193b, t193r, 32u);
        state.regs[4] = t193r;
    // 0x0093792c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
