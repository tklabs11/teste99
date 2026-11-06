#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921260(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921360(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00a23570(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47 = 0;
    BatchLiftStatus t48_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t49a = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    BatchLiftStatus t52_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t53a = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0;

    // 0x00a23570: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x00a23578: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00a23579: 55 PUSH
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2357a: 56 PUSH
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2357b: 57 PUSH
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2357c: 8bf1 MOV
        t5 = state.regs[1];
        state.regs[6] = t5;
    // 0x00a2357e: 8b4c242c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00a23582: 33c0 XOR
        t7a = state.regs[0];
        t7b = state.regs[0];
        t7r = (t7a ^ t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
        state.regs[0] = t7r;
    // 0x00a23584: 50 PUSH
        t8a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00a23585: 894608 MOV
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00a23588: 89460c MOV
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00a2358b: 8d5e10 LEA
        t11 = static_cast<std::uint32_t>(state.regs[6] + 0x00000010u);
        state.regs[3] = t11;
    // 0x00a2358e: 6a04 PUSH
        t12a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00a23590: f30f1103 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[3] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00a23594: f30f1005140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x00a2359c: 6a0c PUSH
        t15a = 0x0000000cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2359e: f30f114304 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[3] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x00a235a3: 894308 MOV
        t17 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000008u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00a235a6: 8b29 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t18;
    // 0x00a235a8: 8d7e1c LEA
        t19 = static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu);
        state.regs[7] = t19;
    // 0x00a235ab: 6860090000 PUSH
        t20a = 0x00000960u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00a235b0: 55 PUSH
        t21a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00a235b1: 8bcf MOV
        t22 = state.regs[7];
        state.regs[1] = t22;
    // 0x00a235b3: 8907 MOV
        t23 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00a235b5: e8a6dcefff CALL
        if (!batch_guest_call32(memory, state, 0x00921260u, 0x00a235bau)) return BatchLiftStatus::invalid_memory;
        t24_call_status = spore_lift_00921260(memory, state);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x00a235bau) return BatchLiftStatus::invalid_control_flow;
    // 0x00a235ba: 8b54242c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t25;
    // 0x00a235be: 896f08 MOV
        t26 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00a235c1: 81c560090000 ADD
        t27a = state.regs[5];
        t27b = 0x00000960u;
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        state.regs[5] = t27r;
    // 0x00a235c7: 896f0c MOV
        t28 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00a235ca: c747100c000000 MOV
        t29 = 0x0000000cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00a235d1: 8b4214 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000014u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t30;
    // 0x00a235d4: 894714 MOV
        t31 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000014u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x00a235d7: 8b442414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x00a235db: 83f802 CMP
        t33a = state.regs[0];
        t33b = 0x00000002u;
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
    // 0x00a235de: 731f JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00a235ff;
    // 0x00a235e0: 33c0 XOR
        t35a = state.regs[0];
        t35b = state.regs[0];
        t35r = (t35a ^ t35b) & 0xffffffffu;
        batch_set_logic_flags(state, t35r, 32u);
        state.regs[0] = t35r;
    // 0x00a235e2: 5f POP
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t36a;
    // 0x00a235e3: 89460c MOV
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00a235e6: 894618 MOV
        t38 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x00a235e9: c7460801000000 MOV
        t39 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x00a235f0: c7460428df5401 MOV
        t40 = 0x0154df28u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00a235f7: 8bc6 MOV
        t41 = state.regs[6];
        state.regs[0] = t41;
    // 0x00a235f9: 5e POP
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t42a;
    // 0x00a235fa: 5d POP
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t43a;
    // 0x00a235fb: 5b POP
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t44a;
    // 0x00a235fc: c21c00 RET
        if (!batch_guest_return32(memory, state, 28u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00a235ff: 50 PUSH
    L_00a235ff:
        t46a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x00a23600: 8bcb MOV
        t47 = state.regs[3];
        state.regs[1] = t47;
    // 0x00a23602: e859ddefff CALL
        if (!batch_guest_call32(memory, state, 0x00921360u, 0x00a23607u)) return BatchLiftStatus::invalid_memory;
        t48_call_status = spore_lift_00921360(memory, state);
        if (t48_call_status != BatchLiftStatus::returned) return t48_call_status;
        if (state.eip != 0x00a23607u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a23607: 50 PUSH
        t49a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x00a23608: 8bce MOV
        t50 = state.regs[6];
        state.regs[1] = t50;
    // 0x00a2360a: 894608 MOV
        t51 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x00a2360d: e89eebffff CALL
        state.eip = 0x00a2360du;
        return BatchLiftStatus::unsupported_dependency;
    // 0x00a23612: 5f POP
        if (!memory.load32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t53a;
    // 0x00a23613: 894604 MOV
        t54 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t54)) return BatchLiftStatus::invalid_memory;
    // 0x00a23616: 8bc6 MOV
        t55 = state.regs[6];
        state.regs[0] = t55;
    // 0x00a23618: 5e POP
        if (!memory.load32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t56a;
    // 0x00a23619: 5d POP
        if (!memory.load32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t57a;
    // 0x00a2361a: 5b POP
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t58a;
    // 0x00a2361b: c21c00 RET
        if (!batch_guest_return32(memory, state, 28u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
