#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_006782c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009241f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009241f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40 = 0;
    BatchLiftStatus t41_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t42a = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0;

    // 0x009241f0: 56 PUSH
        batch_guest_pc = 0x009241f0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009241f1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x009241f3: 57 PUSH
        batch_guest_pc = 0x009241f3u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009241f4: 8d7e38 LEA
        t3 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[7] = t3;
    // 0x009241f7: 6878dc4301 PUSH
        batch_guest_pc = 0x009241f7u;
        t4a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009241fc: 8bcf MOV
        t5 = state.regs[7];
        state.regs[1] = t5;
    // 0x009241fe: e8addfffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00924203u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_009221b0(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00924203u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924203: 8b4618 MOV
        batch_guest_pc = 0x00924203u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x00924206: 8b4e1c MOV
        batch_guest_pc = 0x00924206u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t8;
    // 0x00924209: 3bc1 CMP
        t9a = state.regs[0];
        t9b = state.regs[1];
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x0092420b: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092421c;
    // 0x0092420d: 8b54240c MOV
        batch_guest_pc = 0x0092420du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x00924211: 3910 CMP
    L_00924211:
        batch_guest_pc = 0x00924211u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t12a)) return BatchLiftStatus::invalid_memory;
        t12b = state.regs[2];
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x00924213: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092422a;
    // 0x00924215: 83c004 ADD
        t14a = state.regs[0];
        t14b = 0x00000004u;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[0] = t14r;
    // 0x00924218: 3bc1 CMP
        t15a = state.regs[0];
        t15b = state.regs[1];
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x0092421a: 75f5 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924211;
    // 0x0092421c: 8bcf MOV
    L_0092421c:
        t17 = state.regs[7];
        state.regs[1] = t17;
    // 0x0092421e: e84de0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00924223u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00922270(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00924223u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924223: 5f POP
        batch_guest_pc = 0x00924223u;
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t19a;
    // 0x00924224: 32c0 XOR
        t20a = state.regs[0] & 0x000000ffu;
        t20b = state.regs[0] & 0x000000ffu;
        t20r = (t20a ^ t20b) & 0x000000ffu;
        batch_set_logic_flags(state, t20r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t20r << 0u) & 0x000000ffu);
    // 0x00924226: 5e POP
        batch_guest_pc = 0x00924226u;
        if (!memory.load32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t21a;
    // 0x00924227: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092422a: 8b561c MOV
    L_0092422a:
        batch_guest_pc = 0x0092422au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t23;
    // 0x0092422d: 8d4804 LEA
        t24 = static_cast<std::uint32_t>(state.regs[0] + 0x00000004u);
        state.regs[1] = t24;
    // 0x00924230: 3bca CMP
        t25a = state.regs[1];
        t25b = state.regs[2];
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
    // 0x00924232: 730b JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0092423f;
    // 0x00924234: 50 PUSH
        batch_guest_pc = 0x00924234u;
        t27a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00924235: 52 PUSH
        batch_guest_pc = 0x00924235u;
        t28a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00924236: 51 PUSH
        batch_guest_pc = 0x00924236u;
        t29a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00924237: e88440d5ff CALL
        if (!batch_guest_call32(memory, state, 0x006782c0u, 0x0092423cu)) return BatchLiftStatus::invalid_memory;
        t30_call_status = spore_lift_006782c0(memory, state);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x0092423cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092423c: 83c40c ADD
        t31a = state.regs[4];
        t31b = 0x0000000cu;
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[4] = t31r;
    // 0x0092423f: 83461cfc ADD
    L_0092423f:
        batch_guest_pc = 0x0092423fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t32a)) return BatchLiftStatus::invalid_memory;
        t32b = 0xfffffffcu;
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t32r)) return BatchLiftStatus::invalid_memory;
    // 0x00924243: 8b761c MOV
        batch_guest_pc = 0x00924243u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t33;
    // 0x00924246: 8b0e MOV
        batch_guest_pc = 0x00924246u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t34;
    // 0x00924248: 85c9 TEST
        t35a = state.regs[1];
        t35b = state.regs[1];
        t35r = (t35a & t35b) & 0xffffffffu;
        batch_set_logic_flags(state, t35r, 32u);
    // 0x0092424a: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924253;
    // 0x0092424c: 8b01 MOV
        batch_guest_pc = 0x0092424cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t37;
    // 0x0092424e: 8b5004 MOV
        batch_guest_pc = 0x0092424eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t38;
    // 0x00924251: ffd2 CALL
        t39_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924253u);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
    // 0x00924253: 8bcf MOV
    L_00924253:
        t40 = state.regs[7];
        state.regs[1] = t40;
    // 0x00924255: e816e0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x0092425au)) return BatchLiftStatus::invalid_memory;
        t41_call_status = spore_lift_00922270(memory, state);
        if (t41_call_status != BatchLiftStatus::returned) return t41_call_status;
        if (state.eip != 0x0092425au) return BatchLiftStatus::invalid_control_flow;
    // 0x0092425a: 5f POP
        batch_guest_pc = 0x0092425au;
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t42a;
    // 0x0092425b: b001 MOV
        t43 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t43 << 0u) & 0x000000ffu);
    // 0x0092425d: 5e POP
        batch_guest_pc = 0x0092425du;
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t44a;
    // 0x0092425e: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
