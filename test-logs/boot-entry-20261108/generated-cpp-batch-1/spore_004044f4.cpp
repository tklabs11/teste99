#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00404624(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083a9f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083bcd0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c800(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_004044f4(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004044f4u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62a = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t64a = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66a = 0;
    std::uint32_t t67a = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t71a = 0;
    std::uint32_t t72a = 0;
    std::uint32_t t73a = 0;
    std::uint32_t t74a = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76a = 0, t76b = 0, t76r = 0;
    std::uint32_t t77a = 0;
    BatchLiftStatus t78_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0;

    // 0x004044f4: 81c0fcf79812 ADD
        t0a = state.regs[0];
        t0b = 0x1298f7fcu;
        t0r = static_cast<std::uint32_t>(t0a + t0b) & 0xffffffffu;
        batch_set_add_flags(state, t0a, t0b, t0r, 32u);
        state.regs[0] = t0r;
    // 0x004044fa: e925010000 JMP
        state.eip = 0x00404624u;
        return spore_lift_00404624(memory, state);
    // 0x004044ff: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00404500: 55 PUSH
        t3a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00404501: 8bec MOV
        t4 = state.regs[4];
        state.regs[5] = t4;
    // 0x00404503: 51 PUSH
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00404504: 894dfc MOV
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00404507: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x0040450a: e8f1824300 CALL
        if (!batch_guest_call32(memory, state, 0x0083c800u, 0x0040450fu)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_0083c800(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x0040450fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0040450f: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x00404512: c70024b83e01 MOV
        t10 = 0x013eb824u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00404518: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t11;
    // 0x0040451b: c7010cb83e01 MOV
        t12 = 0x013eb80cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00404521: 8b55fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x00404524: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00404527: 894210 MOV
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000010u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0040452a: 6a01 PUSH
        t16a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x0040452c: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x0040452f: 83c114 ADD
        t18a = state.regs[1];
        t18b = 0x00000014u;
        t18r = static_cast<std::uint32_t>(t18a + t18b) & 0xffffffffu;
        batch_set_add_flags(state, t18a, t18b, t18r, 32u);
        state.regs[1] = t18r;
    // 0x00404532: e8b9644300 CALL
        if (!batch_guest_call32(memory, state, 0x0083a9f0u, 0x00404537u)) return BatchLiftStatus::invalid_memory;
        t19_call_status = spore_lift_0083a9f0(memory, state);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
        if (state.eip != 0x00404537u) return BatchLiftStatus::invalid_control_flow;
    // 0x00404537: 6a00 PUSH
        t20a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00404539: 68ccb73e01 PUSH
        t21a = 0x013eb7ccu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x0040453e: 6a0c PUSH
        t22a = 0x0000000cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00404540: 68bcb73e01 PUSH
        t23a = 0x013eb7bcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00404545: 6890b73e01 PUSH
        t24a = 0x013eb790u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x0040454a: 6a07 PUSH
        t25a = 0x00000007u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x0040454c: 6884b73e01 PUSH
        t26a = 0x013eb784u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00404551: 6854b73e01 PUSH
        t27a = 0x013eb754u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00404556: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t28;
    // 0x00404559: 81c1e4000000 ADD
        t29a = state.regs[1];
        t29b = 0x000000e4u;
        t29r = static_cast<std::uint32_t>(t29a + t29b) & 0xffffffffu;
        batch_set_add_flags(state, t29a, t29b, t29r, 32u);
        state.regs[1] = t29r;
    // 0x0040455f: 51 PUSH
        t30a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x00404560: 6a05 PUSH
        t31a = 0x00000005u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x00404562: 683cb73e01 PUSH
        t32a = 0x013eb73cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x00404567: 6808b73e01 PUSH
        t33a = 0x013eb708u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x0040456c: 8b55fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x0040456f: 81c2ec000000 ADD
        t35a = state.regs[2];
        t35b = 0x000000ecu;
        t35r = static_cast<std::uint32_t>(t35a + t35b) & 0xffffffffu;
        batch_set_add_flags(state, t35a, t35b, t35r, 32u);
        state.regs[2] = t35r;
    // 0x00404575: 52 PUSH
        t36a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00404576: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t37;
    // 0x00404579: 05e8000000 ADD
        t38a = state.regs[0];
        t38b = 0x000000e8u;
        t38r = static_cast<std::uint32_t>(t38a + t38b) & 0xffffffffu;
        batch_set_add_flags(state, t38a, t38b, t38r, 32u);
        state.regs[0] = t38r;
    // 0x0040457e: 50 PUSH
        t39a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
    // 0x0040457f: 6a04 PUSH
        t40a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00404581: 68e4b63e01 PUSH
        t41a = 0x013eb6e4u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00404586: 6888b63e01 PUSH
        t42a = 0x013eb688u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x0040458b: 6a03 PUSH
        t43a = 0x00000003u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
    // 0x0040458d: 6870b63e01 PUSH
        t44a = 0x013eb670u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x00404592: 6858b63e01 PUSH
        t45a = 0x013eb658u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
    // 0x00404597: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t46;
    // 0x0040459a: 81c1e0000000 ADD
        t47a = state.regs[1];
        t47b = 0x000000e0u;
        t47r = static_cast<std::uint32_t>(t47a + t47b) & 0xffffffffu;
        batch_set_add_flags(state, t47a, t47b, t47r, 32u);
        state.regs[1] = t47r;
    // 0x004045a0: 51 PUSH
        t48a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x004045a1: 6848b63e01 PUSH
        t49a = 0x013eb648u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x004045a6: 6828b63e01 PUSH
        t50a = 0x013eb628u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
    // 0x004045ab: 6a02 PUSH
        t51a = 0x00000002u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x004045ad: 6820b63e01 PUSH
        t52a = 0x013eb620u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x004045b2: 6800b63e01 PUSH
        t53a = 0x013eb600u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x004045b7: 6a01 PUSH
        t54a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x004045b9: 68f8b53e01 PUSH
        t55a = 0x013eb5f8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x004045be: 68d4b53e01 PUSH
        t56a = 0x013eb5d4u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
    // 0x004045c3: 6a0e PUSH
        t57a = 0x0000000eu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x004045c5: 68ccb53e01 PUSH
        t58a = 0x013eb5ccu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
    // 0x004045ca: 6880b53e01 PUSH
        t59a = 0x013eb580u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
    // 0x004045cf: 6a08 PUSH
        t60a = 0x00000008u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
    // 0x004045d1: 6874b53e01 PUSH
        t61a = 0x013eb574u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x004045d6: 6848b53e01 PUSH
        t62a = 0x013eb548u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
    // 0x004045db: 6a0b PUSH
        t63a = 0x0000000bu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
    // 0x004045dd: 6840b53e01 PUSH
        t64a = 0x013eb540u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t64a)) return BatchLiftStatus::invalid_memory;
    // 0x004045e2: 68e8b43e01 PUSH
        t65a = 0x013eb4e8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
    // 0x004045e7: 6a06 PUSH
        t66a = 0x00000006u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
    // 0x004045e9: 68dcb43e01 PUSH
        t67a = 0x013eb4dcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
    // 0x004045ee: 6878b43e01 PUSH
        t68a = 0x013eb478u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
    // 0x004045f3: 8b55fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t69;
    // 0x004045f6: 81c2dc000000 ADD
        t70a = state.regs[2];
        t70b = 0x000000dcu;
        t70r = static_cast<std::uint32_t>(t70a + t70b) & 0xffffffffu;
        batch_set_add_flags(state, t70a, t70b, t70r, 32u);
        state.regs[2] = t70r;
    // 0x004045fc: 52 PUSH
        t71a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t71a)) return BatchLiftStatus::invalid_memory;
    // 0x004045fd: 6a00 PUSH
        t72a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t72a)) return BatchLiftStatus::invalid_memory;
    // 0x004045ff: 6854b43e01 PUSH
        t73a = 0x013eb454u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t73a)) return BatchLiftStatus::invalid_memory;
    // 0x00404604: 6838b43e01 PUSH
        t74a = 0x013eb438u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t74a)) return BatchLiftStatus::invalid_memory;
    // 0x00404609: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t75;
    // 0x0040460c: 83c014 ADD
        t76a = state.regs[0];
        t76b = 0x00000014u;
        t76r = static_cast<std::uint32_t>(t76a + t76b) & 0xffffffffu;
        batch_set_add_flags(state, t76a, t76b, t76r, 32u);
        state.regs[0] = t76r;
    // 0x0040460f: 50 PUSH
        t77a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t77a)) return BatchLiftStatus::invalid_memory;
    // 0x00404610: e8bb764300 CALL
        if (!batch_guest_call32(memory, state, 0x0083bcd0u, 0x00404615u)) return BatchLiftStatus::invalid_memory;
        t78_call_status = spore_lift_0083bcd0(memory, state);
        if (t78_call_status != BatchLiftStatus::returned) return t78_call_status;
        if (state.eip != 0x00404615u) return BatchLiftStatus::invalid_control_flow;
    // 0x00404615: 81c4b8000000 ADD
        t79a = state.regs[4];
        t79b = 0x000000b8u;
        t79r = static_cast<std::uint32_t>(t79a + t79b) & 0xffffffffu;
        batch_set_add_flags(state, t79a, t79b, t79r, 32u);
        state.regs[4] = t79r;
    // 0x0040461b: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t80;
    // 0x0040461e: 8be5 MOV
        t81 = state.regs[5];
        state.regs[4] = t81;
    // 0x00404620: 5d POP
        if (!memory.load32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t82a;
    // 0x00404621: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
