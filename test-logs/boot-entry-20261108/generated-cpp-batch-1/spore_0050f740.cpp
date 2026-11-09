#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0050f76c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f77e(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f7ac(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f7b5(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0050f740(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0050f740u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51a = 0, t51b = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0;

    // 0x0050f740: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0050f741: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0050f743: 83ec1c SUB
        t2a = state.regs[4];
        t2b = 0x0000001cu;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0050f746: 894de4 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0050f749: 8b45e4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0050f74c: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x0050f74f: 894dec MOV
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t6)) return BatchLiftStatus::invalid_memory;
    // 0x0050f752: c645fa00 MOV
        t7 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffau), t7)) return BatchLiftStatus::invalid_memory;
    // 0x0050f756: c645fb00 MOV
        t8 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffbu), t8)) return BatchLiftStatus::invalid_memory;
    // 0x0050f75a: c645f900 MOV
        t9 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff9u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0050f75e: 8b5508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t10;
    // 0x0050f761: 8955f0 MOV
        t11 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x0050f764: 8b450c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x0050f767: 8945f4 MOV
        t13 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x0050f76a: eb12 JMP
        goto L_0050f77e;
    // 0x0050f76c: 8b4df0 MOV
    L_0050f76c:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x0050f76f: 83c10c ADD
        t16a = state.regs[1];
        t16b = 0x0000000cu;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[1] = t16r;
    // 0x0050f772: 894df0 MOV
        t17 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x0050f775: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x0050f778: 83c20c ADD
        t19a = state.regs[2];
        t19b = 0x0000000cu;
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[2] = t19r;
    // 0x0050f77b: 8955f4 MOV
        t20 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x0050f77e: 8b45f4 MOV
    L_0050f77e:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x0050f781: 3b45ec CMP
        t22a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t22b)) return BatchLiftStatus::invalid_memory;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x0050f784: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0050f79e;
    // 0x0050f786: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x0050f789: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t25;
    // 0x0050f78c: 8b01 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t26;
    // 0x0050f78e: 8902 MOV
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x0050f790: 8b4104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x0050f793: 894204 MOV
        t29 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x0050f796: 8b4908 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x0050f799: 894a08 MOV
        t31 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x0050f79c: ebce JMP
        goto L_0050f76c;
    // 0x0050f79e: 8b55f0 MOV
    L_0050f79e:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t33;
    // 0x0050f7a1: 8955fc MOV
        t34 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t34)) return BatchLiftStatus::invalid_memory;
    // 0x0050f7a4: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t35;
    // 0x0050f7a7: 8945e8 MOV
        t36 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x0050f7aa: eb09 JMP
        goto L_0050f7b5;
    // 0x0050f7ac: 8b4de8 MOV
    L_0050f7ac:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t38;
    // 0x0050f7af: 83c10c ADD
        t39a = state.regs[1];
        t39b = 0x0000000cu;
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[1] = t39r;
    // 0x0050f7b2: 894de8 MOV
        t40 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x0050f7b5: 8b55e4 MOV
    L_0050f7b5:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t41;
    // 0x0050f7b8: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t42;
    // 0x0050f7bb: 3b4204 CMP
        t43a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t43b)) return BatchLiftStatus::invalid_memory;
        t43r = static_cast<std::uint32_t>(t43a - t43b) & 0xffffffffu;
        batch_set_sub_flags(state, t43a, t43b, t43r, 32u);
    // 0x0050f7be: 7302 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0050f7c2;
    // 0x0050f7c0: ebea JMP
        goto L_0050f7ac;
    // 0x0050f7c2: 8b450c MOV
    L_0050f7c2:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t46;
    // 0x0050f7c5: 2b4508 SUB
        t47a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t47b)) return BatchLiftStatus::invalid_memory;
        t47r = static_cast<std::uint32_t>(t47a - t47b) & 0xffffffffu;
        batch_set_sub_flags(state, t47a, t47b, t47r, 32u);
        state.regs[0] = t47r;
    // 0x0050f7c8: 99 CDQ
        state.regs[2] = (state.regs[0] & 0x80000000u) != 0u ? 0xffffffffu : 0u;
    // 0x0050f7c9: b90c000000 MOV
        t49 = 0x0000000cu;
        state.regs[1] = t49;
    // 0x0050f7ce: f7f9 IDIV
        t50a = state.regs[1];
        if (t50a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::int64_t divisor = static_cast<std::int64_t>(static_cast<std::int32_t>(t50a));
        const std::int64_t dividend = static_cast<std::int64_t>((static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0]);
        const std::int64_t quotient = dividend / divisor;
        const std::int64_t remainder = dividend % divisor;
        if (quotient < -2147483648ll || quotient > 2147483647ll) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(remainder);
        }
    // 0x0050f7d0: 6bc00c IMUL
        t51a = state.regs[0];
        t51b = 0x0000000cu;
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t51a)) * static_cast<std::int32_t>(t51b);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x0050f7d3: 8b55e4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t52;
    // 0x0050f7d6: 8b4a04 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t53;
    // 0x0050f7d9: 2bc8 SUB
        t54a = state.regs[1];
        t54b = state.regs[0];
        t54r = static_cast<std::uint32_t>(t54a - t54b) & 0xffffffffu;
        batch_set_sub_flags(state, t54a, t54b, t54r, 32u);
        state.regs[1] = t54r;
    // 0x0050f7db: 8b55e4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t55)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t55;
    // 0x0050f7de: 894a04 MOV
        t56 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t56)) return BatchLiftStatus::invalid_memory;
    // 0x0050f7e1: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t57;
    // 0x0050f7e4: 8be5 MOV
        t58 = state.regs[5];
        state.regs[4] = t58;
    // 0x0050f7e6: 5d POP
        if (!memory.load32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t59a;
    // 0x0050f7e7: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
