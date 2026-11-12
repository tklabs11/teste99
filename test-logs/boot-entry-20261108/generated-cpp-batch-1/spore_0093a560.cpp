#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0093a1a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0093a560(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0093a560u);
    std::uint32_t t0 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    BatchLiftStatus t32_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;

    // 0x0093a560: 8b442404 MOV
        batch_guest_pc = 0x0093a560u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x0093a564: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a56c: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0093a56f: 53 PUSH
        batch_guest_pc = 0x0093a56fu;
        t3a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a570: 33db XOR
        t4a = state.regs[3];
        t4b = state.regs[3];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[3] = t4r;
    // 0x0093a572: 56 PUSH
        batch_guest_pc = 0x0093a572u;
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a573: 8bf1 MOV
        t6 = state.regs[1];
        state.regs[6] = t6;
    // 0x0093a575: 50 PUSH
        batch_guest_pc = 0x0093a575u;
        t7a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a576: 891e MOV
        batch_guest_pc = 0x0093a576u;
        t8 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x0093a578: 895e04 MOV
        batch_guest_pc = 0x0093a578u;
        t9 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0093a57b: 895e08 MOV
        batch_guest_pc = 0x0093a57bu;
        t10 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x0093a57e: 895e0c MOV
        batch_guest_pc = 0x0093a57eu;
        t11 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x0093a581: 895e10 MOV
        batch_guest_pc = 0x0093a581u;
        t12 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x0093a584: f30f114614 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x00000014u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a589: e812fcffff CALL
        if (!batch_guest_call32(memory, state, 0x0093a1a0u, 0x0093a58eu)) return BatchLiftStatus::invalid_memory;
        t14_call_status = spore_lift_0093a1a0(memory, state);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x0093a58eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a58e: 385c2418 CMP
        batch_guest_pc = 0x0093a58eu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t15a)) return BatchLiftStatus::invalid_memory;
        t15b = state.regs[3] & 0x000000ffu;
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0x000000ffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 8u);
    // 0x0093a592: 7436 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093a5ca;
    // 0x0093a594: 8b0e MOV
        batch_guest_pc = 0x0093a594u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x0093a596: 0b4e04 OR
        batch_guest_pc = 0x0093a596u;
        t18a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t18b)) return BatchLiftStatus::invalid_memory;
        t18r = (t18a | t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
        state.regs[1] = t18r;
    // 0x0093a599: 752f JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093a5ca;
    // 0x0093a59b: 837e1001 CMP
        batch_guest_pc = 0x0093a59bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t20a)) return BatchLiftStatus::invalid_memory;
        t20b = 0x00000001u;
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x0093a59f: 7511 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093a5b2;
    // 0x0093a5a1: 0f31 RDTSC
        if (!batch_guest_rdtsc(state)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a5a3: 8906 MOV
        batch_guest_pc = 0x0093a5a3u;
        t23 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x0093a5a5: 895604 MOV
        batch_guest_pc = 0x0093a5a5u;
        t24 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x0093a5a8: 8bc6 MOV
        t25 = state.regs[6];
        state.regs[0] = t25;
    // 0x0093a5aa: 5e POP
        batch_guest_pc = 0x0093a5aau;
        if (!memory.load32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t26a;
    // 0x0093a5ab: 5b POP
        batch_guest_pc = 0x0093a5abu;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t27a;
    // 0x0093a5ac: 83c408 ADD
        t28a = state.regs[4];
        t28b = 0x00000008u;
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[4] = t28r;
    // 0x0093a5af: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093a5b2: 8d542408 LEA
    L_0093a5b2:
        t30 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[2] = t30;
    // 0x0093a5b6: 52 PUSH
        batch_guest_pc = 0x0093a5b6u;
        t31a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a5b7: ff15b8c23c01 CALL
        t32_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!QueryPerformanceCounter", 0x013cc2b8u, 0x0093a5bdu);
        if (t32_call_status != BatchLiftStatus::returned) return t32_call_status;
        if (state.eip != 0x0093a5bdu) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a5bd: 8b442408 MOV
        batch_guest_pc = 0x0093a5bdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x0093a5c1: 8b4c240c MOV
        batch_guest_pc = 0x0093a5c1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t34;
    // 0x0093a5c5: 894e04 MOV
        batch_guest_pc = 0x0093a5c5u;
        t35 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x0093a5c8: 8906 MOV
        batch_guest_pc = 0x0093a5c8u;
        t36 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x0093a5ca: 8bc6 MOV
    L_0093a5ca:
        t37 = state.regs[6];
        state.regs[0] = t37;
    // 0x0093a5cc: 5e POP
        batch_guest_pc = 0x0093a5ccu;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t38a;
    // 0x0093a5cd: 5b POP
        batch_guest_pc = 0x0093a5cdu;
        if (!memory.load32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t39a;
    // 0x0093a5ce: 83c408 ADD
        t40a = state.regs[4];
        t40b = 0x00000008u;
        t40r = static_cast<std::uint32_t>(t40a + t40b) & 0xffffffffu;
        batch_set_add_flags(state, t40a, t40b, t40r, 32u);
        state.regs[4] = t40r;
    // 0x0093a5d1: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
