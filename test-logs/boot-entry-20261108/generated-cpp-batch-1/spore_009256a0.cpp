#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009256e2(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009256a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009256a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0, t6c = 0, t6r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37a = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43c = 0, t43r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0;

    // 0x009256a0: 53 PUSH
        batch_guest_pc = 0x009256a0u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009256a1: 8b5c2408 MOV
        batch_guest_pc = 0x009256a1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t1;
    // 0x009256a5: 56 PUSH
        batch_guest_pc = 0x009256a5u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009256a6: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x009256a8: 8b4608 MOV
        batch_guest_pc = 0x009256a8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x009256ab: 2b06 SUB
        batch_guest_pc = 0x009256abu;
        t5a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5b)) return BatchLiftStatus::invalid_memory;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[0] = t5r;
    // 0x009256ad: c1f802 SAR
        t6a = state.regs[0];
        t6c = 2u;
        if (t6c != 0u) {
        t6r = (t6a >> t6c) | ((t6a & 0x80000000u) ? (0xffffffffu << (32u - t6c)) : 0u);
        batch_set_sar_flags(state, t6a, t6c, t6r, 32u);
            state.regs[0] = t6r;
        }
    // 0x009256b0: 3bd8 CMP
        t7a = state.regs[3];
        t7b = state.regs[0];
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x009256b2: 766c JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00925720;
    // 0x009256b4: 57 PUSH
        batch_guest_pc = 0x009256b4u;
        t9a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x009256b5: 85db TEST
        t10a = state.regs[3];
        t10b = state.regs[3];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x009256b7: 7427 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009256e0;
    // 0x009256b9: 68d1000000 PUSH
        batch_guest_pc = 0x009256b9u;
        t12a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x009256be: 6838bb3e01 PUSH
        batch_guest_pc = 0x009256beu;
        t13a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x009256c3: 6a00 PUSH
        batch_guest_pc = 0x009256c3u;
        t14a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x009256c5: 6a00 PUSH
        batch_guest_pc = 0x009256c5u;
        t15a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x009256c7: 8d0c9d00000000 LEA
        t16 = static_cast<std::uint32_t>(state.regs[3] * 4u + 0x00000000u);
        state.regs[1] = t16;
    // 0x009256ce: 6800e04301 PUSH
        batch_guest_pc = 0x009256ceu;
        t17a = 0x0143e000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x009256d3: 51 PUSH
        batch_guest_pc = 0x009256d3u;
        t18a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x009256d4: e8c71c6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x009256d9u)) return BatchLiftStatus::invalid_memory;
        t19_call_status = spore_lift_00f473a0(memory, state);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
        if (state.eip != 0x009256d9u) return BatchLiftStatus::invalid_control_flow;
    // 0x009256d9: 83c418 ADD
        t20a = state.regs[4];
        t20b = 0x00000018u;
        t20r = static_cast<std::uint32_t>(t20a + t20b) & 0xffffffffu;
        batch_set_add_flags(state, t20a, t20b, t20r, 32u);
        state.regs[4] = t20r;
    // 0x009256dc: 8bf8 MOV
        t21 = state.regs[0];
        state.regs[7] = t21;
    // 0x009256de: eb02 JMP
        goto L_009256e2;
    // 0x009256e0: 33ff XOR
    L_009256e0:
        t23a = state.regs[7];
        t23b = state.regs[7];
        t23r = (t23a ^ t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[7] = t23r;
    // 0x009256e2: 8b06 MOV
    L_009256e2:
        batch_guest_pc = 0x009256e2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t24;
    // 0x009256e4: 8b5604 MOV
        batch_guest_pc = 0x009256e4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t25;
    // 0x009256e7: 2bd0 SUB
        t26a = state.regs[2];
        t26b = state.regs[0];
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0xffffffffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 32u);
        state.regs[2] = t26r;
    // 0x009256e9: 52 PUSH
        batch_guest_pc = 0x009256e9u;
        t27a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x009256ea: 50 PUSH
        batch_guest_pc = 0x009256eau;
        t28a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x009256eb: 57 PUSH
        batch_guest_pc = 0x009256ebu;
        t29a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x009256ec: e853b08b00 CALL
        t30_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x009256f1u);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x009256f1u) return BatchLiftStatus::invalid_control_flow;
    // 0x009256f1: 8b06 MOV
        batch_guest_pc = 0x009256f1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t31;
    // 0x009256f3: 83c40c ADD
        t32a = state.regs[4];
        t32b = 0x0000000cu;
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        state.regs[4] = t32r;
    // 0x009256f6: 85c0 TEST
        t33a = state.regs[0];
        t33b = state.regs[0];
        t33r = (t33a & t33b) & 0xffffffffu;
        batch_set_logic_flags(state, t33r, 32u);
    // 0x009256f8: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925709;
    // 0x009256fa: 8378fc00 CMP
        batch_guest_pc = 0x009256fau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t35a)) return BatchLiftStatus::invalid_memory;
        t35b = 0x00000000u;
        t35r = static_cast<std::uint32_t>(t35a - t35b) & 0xffffffffu;
        batch_set_sub_flags(state, t35a, t35b, t35r, 32u);
    // 0x009256fe: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925709;
    // 0x00925700: 50 PUSH
        batch_guest_pc = 0x00925700u;
        t37a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00925701: e87a1c6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00925706u)) return BatchLiftStatus::invalid_memory;
        t38_call_status = spore_lift_00f47380(memory, state);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
        if (state.eip != 0x00925706u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925706: 83c404 ADD
        t39a = state.regs[4];
        t39b = 0x00000004u;
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[4] = t39r;
    // 0x00925709: 8b4604 MOV
    L_00925709:
        batch_guest_pc = 0x00925709u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t40;
    // 0x0092570c: 2b06 SUB
        batch_guest_pc = 0x0092570cu;
        t41a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t41b)) return BatchLiftStatus::invalid_memory;
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
        state.regs[0] = t41r;
    // 0x0092570e: 8d0c9f LEA
        t42 = static_cast<std::uint32_t>(state.regs[7] + state.regs[3] * 4u + 0x00000000u);
        state.regs[1] = t42;
    // 0x00925711: c1f802 SAR
        t43a = state.regs[0];
        t43c = 2u;
        if (t43c != 0u) {
        t43r = (t43a >> t43c) | ((t43a & 0x80000000u) ? (0xffffffffu << (32u - t43c)) : 0u);
        batch_set_sar_flags(state, t43a, t43c, t43r, 32u);
            state.regs[0] = t43r;
        }
    // 0x00925714: 8d0487 LEA
        t44 = static_cast<std::uint32_t>(state.regs[7] + state.regs[0] * 4u + 0x00000000u);
        state.regs[0] = t44;
    // 0x00925717: 893e MOV
        batch_guest_pc = 0x00925717u;
        t45 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x00925719: 894604 MOV
        batch_guest_pc = 0x00925719u;
        t46 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x0092571c: 894e08 MOV
        batch_guest_pc = 0x0092571cu;
        t47 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x0092571f: 5f POP
        batch_guest_pc = 0x0092571fu;
        if (!memory.load32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t48a;
    // 0x00925720: 5e POP
    L_00925720:
        batch_guest_pc = 0x00925720u;
        if (!memory.load32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t49a;
    // 0x00925721: 5b POP
        batch_guest_pc = 0x00925721u;
        if (!memory.load32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t50a;
    // 0x00925722: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
