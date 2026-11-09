#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402414(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00402420(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00420660(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0067dd60(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00402385(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00402385u);
    std::uint32_t t0a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9 = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    BatchLiftStatus t22_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t43 = 0;
    BatchLiftStatus t44_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0;

    // 0x00402385: 6840000000 PUSH
        t0a = 0x00000040u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0040238a: e985000000 JMP
        state.eip = 0x00402414u;
        return spore_lift_00402414(memory, state);
    // 0x0040238f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00402390: 55 PUSH
        t3a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00402391: 8bec MOV
        t4 = state.regs[4];
        state.regs[5] = t4;
    // 0x00402393: 83ec20 SUB
        t5a = state.regs[4];
        t5b = 0x00000020u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00402396: 894de4 MOV
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00402399: 837d1000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t7a)) return BatchLiftStatus::invalid_memory;
        t7b = 0x00000000u;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x0040239d: 7507 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_004023a6;
    // 0x0040239f: c7451000000000 MOV
        t9 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x004023a6: e8b5b92700 CALL
    L_004023a6:
        if (!batch_guest_call32(memory, state, 0x0067dd60u, 0x004023abu)) return BatchLiftStatus::invalid_memory;
        t10_call_status = spore_lift_0067dd60(memory, state);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x004023abu) return BatchLiftStatus::invalid_control_flow;
    // 0x004023ab: 8945e0 MOV
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x004023ae: 8b4510 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x004023b1: 50 PUSH
        t13a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x004023b2: 8b4d0c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x004023b5: 51 PUSH
        t15a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x004023b6: 8b5508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t16;
    // 0x004023b9: 52 PUSH
        t17a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x004023ba: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x004023bd: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t19;
    // 0x004023bf: 8b4de0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t20;
    // 0x004023c2: 8b4220 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000020u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x004023c5: ffd0 CALL
        t22_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x004023c7u);
        if (t22_call_status != BatchLiftStatus::returned) return t22_call_status;
    // 0x004023c7: 8945fc MOV
        t23 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t23)) return BatchLiftStatus::invalid_memory;
    // 0x004023ca: 837dfc00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t24a)) return BatchLiftStatus::invalid_memory;
        t24b = 0x00000000u;
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x004023ce: 743e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0040240e;
    // 0x004023d0: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t26;
    // 0x004023d3: 894df8 MOV
        t27 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x004023d6: 837df800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t28a)) return BatchLiftStatus::invalid_memory;
        t28b = 0x00000000u;
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x004023da: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_004023f1;
    // 0x004023dc: 8b55f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t30;
    // 0x004023df: 8955f4 MOV
        t31 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x004023e2: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x004023e5: 83c008 ADD
        t33a = state.regs[0];
        t33b = 0x00000008u;
        t33r = static_cast<std::uint32_t>(t33a + t33b) & 0xffffffffu;
        batch_set_add_flags(state, t33a, t33b, t33r, 32u);
        state.regs[0] = t33r;
    // 0x004023e8: b901000000 MOV
        t34 = 0x00000001u;
        state.regs[1] = t34;
    // 0x004023ed: f00fc108 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t35a)) return BatchLiftStatus::invalid_memory;
        t35b = state.regs[1];
        t35r = static_cast<std::uint32_t>(t35a + t35b) & 0xffffffffu;
        batch_set_add_flags(state, t35a, t35b, t35r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t35r)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35a;
    // 0x004023f1: 8d55f8 LEA
    L_004023f1:
        t36 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u);
        state.regs[2] = t36;
    // 0x004023f4: 52 PUSH
        t37a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x004023f5: 8b4de4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t38;
    // 0x004023f8: 83c138 ADD
        t39a = state.regs[1];
        t39b = 0x00000038u;
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[1] = t39r;
    // 0x004023fb: e860e20100 CALL
        if (!batch_guest_call32(memory, state, 0x00420660u, 0x00402400u)) return BatchLiftStatus::invalid_memory;
        t40_call_status = spore_lift_00420660(memory, state);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
        if (state.eip != 0x00402400u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402400: 837df800 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t41a)) return BatchLiftStatus::invalid_memory;
        t41b = 0x00000000u;
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
    // 0x00402404: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0040240e;
    // 0x00402406: 8b4df8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43;
    // 0x00402409: e812000000 CALL
        if (!batch_guest_call32(memory, state, 0x00402420u, 0x0040240eu)) return BatchLiftStatus::invalid_memory;
        t44_call_status = spore_lift_00402420(memory, state);
        if (t44_call_status != BatchLiftStatus::returned) return t44_call_status;
        if (state.eip != 0x0040240eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0040240e: 8be5 MOV
    L_0040240e:
        t45 = state.regs[5];
        state.regs[4] = t45;
    // 0x00402410: 5d POP
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t46a;
    // 0x00402411: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
