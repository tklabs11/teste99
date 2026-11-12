#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0057cc10(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00925cb0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923f30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923f30u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;

    // 0x00923f30: 8b442404 MOV
        batch_guest_pc = 0x00923f30u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00923f34: 53 PUSH
        batch_guest_pc = 0x00923f34u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923f35: 56 PUSH
        batch_guest_pc = 0x00923f35u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00923f36: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x00923f38: 33db XOR
        t4a = state.regs[3];
        t4b = state.regs[3];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[3] = t4r;
    // 0x00923f3a: 8d4e08 LEA
        t5 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[1] = t5;
    // 0x00923f3d: c7069cdd4301 MOV
        batch_guest_pc = 0x00923f3du;
        t6 = 0x0143dd9cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00923f43: 895e04 MOV
        batch_guest_pc = 0x00923f43u;
        t7 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00923f46: 50 PUSH
        batch_guest_pc = 0x00923f46u;
        t8a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00923f47: 8919 MOV
        batch_guest_pc = 0x00923f47u;
        t9 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00923f49: 895904 MOV
        batch_guest_pc = 0x00923f49u;
        t10 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00923f4c: 895908 MOV
        batch_guest_pc = 0x00923f4cu;
        t11 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00923f4f: e8bc8cc5ff CALL
        if (!batch_guest_call32(memory, state, 0x0057cc10u, 0x00923f54u)) return BatchLiftStatus::invalid_memory;
        t12_call_status = spore_lift_0057cc10(memory, state);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00923f54u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923f54: c7461801000000 MOV
        batch_guest_pc = 0x00923f54u;
        t13 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00923f5b: e8501d0000 CALL
        if (!batch_guest_call32(memory, state, 0x00925cb0u, 0x00923f60u)) return BatchLiftStatus::invalid_memory;
        t14_call_status = spore_lift_00925cb0(memory, state);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x00923f60u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923f60: 8d4e20 LEA
        t15 = static_cast<std::uint32_t>(state.regs[6] + 0x00000020u);
        state.regs[1] = t15;
    // 0x00923f63: 33d2 XOR
        t16a = state.regs[2];
        t16b = state.regs[2];
        t16r = (t16a ^ t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[2] = t16r;
    // 0x00923f65: 895104 MOV
        batch_guest_pc = 0x00923f65u;
        t17 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00923f68: 895108 MOV
        batch_guest_pc = 0x00923f68u;
        t18 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00923f6b: 89510c MOV
        batch_guest_pc = 0x00923f6bu;
        t19 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00923f6e: 894634 MOV
        batch_guest_pc = 0x00923f6eu;
        t20 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000034u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00923f71: 895e38 MOV
        batch_guest_pc = 0x00923f71u;
        t21 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000038u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00923f74: 895e28 MOV
        batch_guest_pc = 0x00923f74u;
        t22 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00923f77: 885e2c MOV
        batch_guest_pc = 0x00923f77u;
        t23 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00923f7a: 895e30 MOV
        batch_guest_pc = 0x00923f7au;
        t24 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00923f7d: 894e24 MOV
        batch_guest_pc = 0x00923f7du;
        t25 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x00923f80: 8bc6 MOV
        t26 = state.regs[6];
        state.regs[0] = t26;
    // 0x00923f82: 5e POP
        batch_guest_pc = 0x00923f82u;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t27a;
    // 0x00923f83: 8909 MOV
        batch_guest_pc = 0x00923f83u;
        t28 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00923f85: 5b POP
        batch_guest_pc = 0x00923f85u;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t29a;
    // 0x00923f86: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
