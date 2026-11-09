#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009274d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e073e(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00927860(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00927860u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
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
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
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
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84a = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86a = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88a = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90a = 0;
    std::uint32_t t91a = 0;
    std::uint32_t t92a = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    BatchLiftStatus t95_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t96 = 0;
    std::uint32_t t97a = 0;
    std::uint32_t t98a = 0;

    // 0x00927860: 33c0 XOR
        t0a = state.regs[0];
        t0b = state.regs[0];
        t0r = (t0a ^ t0b) & 0xffffffffu;
        batch_set_logic_flags(state, t0r, 32u);
        state.regs[0] = t0r;
    // 0x00927862: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00927863: 56 PUSH
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00927864: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x00927866: 33db XOR
        t4a = state.regs[3];
        t4b = state.regs[3];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[3] = t4r;
    // 0x00927868: 881e MOV
        t5 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x0092786a: 895e04 MOV
        t6 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x0092786d: 894608 MOV
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00927870: 89460c MOV
        t8 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00927873: 894610 MOV
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00927876: 894614 MOV
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00927879: 894618 MOV
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x0092787c: 89461c MOV
        t12 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x0092787f: 894620 MOV
        t13 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00927882: 894624 MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00927885: 894628 MOV
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00927888: 6800040000 PUSH
        t16a = 0x00000400u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x0092788d: 89462c MOV
        t17 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00927890: 8d4630 LEA
        t18 = static_cast<std::uint32_t>(state.regs[6] + 0x00000030u);
        state.regs[0] = t18;
    // 0x00927893: 53 PUSH
        t19a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00927894: 50 PUSH
        t20a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00927895: e8a48e8b00 CALL
        if (!batch_guest_call32(memory, state, 0x011e073eu, 0x0092789au)) return BatchLiftStatus::invalid_memory;
        t21_call_status = spore_lift_011e073e(memory, state);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x0092789au) return BatchLiftStatus::invalid_control_flow;
    // 0x0092789a: 83c40c ADD
        t22a = state.regs[4];
        t22b = 0x0000000cu;
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[4] = t22r;
    // 0x0092789d: 33c0 XOR
        t23a = state.regs[0];
        t23b = state.regs[0];
        t23r = (t23a ^ t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[0] = t23r;
    // 0x0092789f: 898630040000 MOV
        t24 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000430u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x009278a5: 898634040000 MOV
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000434u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x009278ab: 898638040000 MOV
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000438u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x009278b1: 89863c040000 MOV
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000043cu), t27)) return BatchLiftStatus::invalid_memory;
    // 0x009278b7: 899e40040000 MOV
        t28 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000440u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x009278bd: 899e44040000 MOV
        t29 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000444u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x009278c3: 898648040000 MOV
        t30 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000448u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x009278c9: 89864c040000 MOV
        t31 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000044cu), t31)) return BatchLiftStatus::invalid_memory;
    // 0x009278cf: 898650040000 MOV
        t32 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000450u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x009278d5: 898654040000 MOV
        t33 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000454u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x009278db: 898658040000 MOV
        t34 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000458u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x009278e1: 89865c040000 MOV
        t35 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000045cu), t35)) return BatchLiftStatus::invalid_memory;
    // 0x009278e7: 898660040000 MOV
        t36 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000460u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x009278ed: 898664040000 MOV
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000464u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x009278f3: 899e68040000 MOV
        t38 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000468u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x009278f9: 889e6c040000 MOV
        t39 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000046cu), t39)) return BatchLiftStatus::invalid_memory;
    // 0x009278ff: c6866d04000001 MOV
        t40 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000046du), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00927906: 899e70040000 MOV
        t41 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000470u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0092790c: c6867404000009 MOV
        t42 = 0x00000009u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000474u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x00927913: c686750400000a MOV
        t43 = 0x0000000au;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000475u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x0092791a: 899e78040000 MOV
        t44 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000478u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x00927920: 899e7c040000 MOV
        t45 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000047cu), t45)) return BatchLiftStatus::invalid_memory;
    // 0x00927926: 899e80040000 MOV
        t46 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000480u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x0092792c: 889e84040000 MOV
        t47 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000484u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x00927932: 899e88040000 MOV
        t48 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000488u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00927938: 899e8c040000 MOV
        t49 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000048cu), t49)) return BatchLiftStatus::invalid_memory;
    // 0x0092793e: 899e90040000 MOV
        t50 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000490u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00927944: 899e94040000 MOV
        t51 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000494u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x0092794a: 889e98040000 MOV
        t52 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000498u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00927950: 89869c040000 MOV
        t53 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000049cu), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00927956: 8986a0040000 MOV
        t54 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004a0u), t54)) return BatchLiftStatus::invalid_memory;
    // 0x0092795c: 8986a4040000 MOV
        t55 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004a4u), t55)) return BatchLiftStatus::invalid_memory;
    // 0x00927962: 8986a8040000 MOV
        t56 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004a8u), t56)) return BatchLiftStatus::invalid_memory;
    // 0x00927968: 899eac040000 MOV
        t57 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004acu), t57)) return BatchLiftStatus::invalid_memory;
    // 0x0092796e: 899eb0040000 MOV
        t58 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004b0u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x00927974: c786b404000000010000 MOV
        t59 = 0x00000100u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004b4u), t59)) return BatchLiftStatus::invalid_memory;
    // 0x0092797e: 899ec8040000 MOV
        t60 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004c8u), t60)) return BatchLiftStatus::invalid_memory;
    // 0x00927984: 899ecc040000 MOV
        t61 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004ccu), t61)) return BatchLiftStatus::invalid_memory;
    // 0x0092798a: 899ed0040000 MOV
        t62 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004d0u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x00927990: c786d404000000100000 MOV
        t63 = 0x00001000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004d4u), t63)) return BatchLiftStatus::invalid_memory;
    // 0x0092799a: c786d804000000000001 MOV
        t64 = 0x01000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004d8u), t64)) return BatchLiftStatus::invalid_memory;
    // 0x009279a4: c786dc04000000004000 MOV
        t65 = 0x00400000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004dcu), t65)) return BatchLiftStatus::invalid_memory;
    // 0x009279ae: 889ee0040000 MOV
        t66 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x000004e0u), t66)) return BatchLiftStatus::invalid_memory;
    // 0x009279b4: 899ee4040000 MOV
        t67 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004e4u), t67)) return BatchLiftStatus::invalid_memory;
    // 0x009279ba: 8986e8040000 MOV
        t68 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004e8u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x009279c0: 8986ec040000 MOV
        t69 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004ecu), t69)) return BatchLiftStatus::invalid_memory;
    // 0x009279c6: 8986f0040000 MOV
        t70 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004f0u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x009279cc: 8986f4040000 MOV
        t71 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004f4u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x009279d2: 8986f8040000 MOV
        t72 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004f8u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x009279d8: 8986fc040000 MOV
        t73 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004fcu), t73)) return BatchLiftStatus::invalid_memory;
    // 0x009279de: 898600050000 MOV
        t74 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000500u), t74)) return BatchLiftStatus::invalid_memory;
    // 0x009279e4: 898604050000 MOV
        t75 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000504u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x009279ea: 899e08050000 MOV
        t76 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000508u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x009279f0: 889e0c050000 MOV
        t77 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000050cu), t77)) return BatchLiftStatus::invalid_memory;
    // 0x009279f6: c786b804000030699200 MOV
        t78 = 0x00926930u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004b8u), t78)) return BatchLiftStatus::invalid_memory;
    // 0x00927a00: 89b6bc040000 MOV
        t79 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004bcu), t79)) return BatchLiftStatus::invalid_memory;
    // 0x00927a06: c786c0040000e08d9200 MOV
        t80 = 0x00928de0u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004c0u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x00927a10: 8b4c2420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t81;
    // 0x00927a14: 8b54241c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t82)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t82;
    // 0x00927a18: 8b442418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t83;
    // 0x00927a1c: 51 PUSH
        t84a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t84a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a1d: 8b4c2418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t85)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t85;
    // 0x00927a21: 52 PUSH
        t86a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t86a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a22: 8b542418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t87;
    // 0x00927a26: 50 PUSH
        t88a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t88a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a27: 8b442418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t89;
    // 0x00927a2b: 51 PUSH
        t90a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t90a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a2c: 52 PUSH
        t91a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t91a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a2d: 50 PUSH
        t92a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t92a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a2e: 8bce MOV
        t93 = state.regs[6];
        state.regs[1] = t93;
    // 0x00927a30: 89b6c4040000 MOV
        t94 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000004c4u), t94)) return BatchLiftStatus::invalid_memory;
    // 0x00927a36: e895faffff CALL
        if (!batch_guest_call32(memory, state, 0x009274d0u, 0x00927a3bu)) return BatchLiftStatus::invalid_memory;
        t95_call_status = spore_lift_009274d0(memory, state);
        if (t95_call_status != BatchLiftStatus::returned) return t95_call_status;
        if (state.eip != 0x00927a3bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00927a3b: 8bc6 MOV
        t96 = state.regs[6];
        state.regs[0] = t96;
    // 0x00927a3d: 5e POP
        if (!memory.load32(state.regs[4], t97a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t97a;
    // 0x00927a3e: 5b POP
        if (!memory.load32(state.regs[4], t98a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t98a;
    // 0x00927a3f: c21800 RET
        if (!batch_guest_return32(memory, state, 24u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
