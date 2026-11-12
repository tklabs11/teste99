#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009222a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923d40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923d40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29 = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;

    // 0x00923d40: 53 PUSH
        batch_guest_pc = 0x00923d40u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d41: 56 PUSH
        batch_guest_pc = 0x00923d41u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d42: 33db XOR
        t2a = state.regs[3];
        t2b = state.regs[3];
        t2r = (t2a ^ t2b) & 0xffffffffu;
        batch_set_logic_flags(state, t2r, 32u);
        state.regs[3] = t2r;
    // 0x00923d44: 53 PUSH
        batch_guest_pc = 0x00923d44u;
        t3a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d45: 53 PUSH
        batch_guest_pc = 0x00923d45u;
        t4a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d46: 53 PUSH
        batch_guest_pc = 0x00923d46u;
        t5a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d47: 8bf1 MOV
        t6 = state.regs[1];
        state.regs[6] = t6;
    // 0x00923d49: 53 PUSH
        batch_guest_pc = 0x00923d49u;
        t7a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d4a: c7460490264401 MOV
        batch_guest_pc = 0x00923d4au;
        t8 = 0x01442690u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00923d51: 688cdc4301 PUSH
        batch_guest_pc = 0x00923d51u;
        t9a = 0x0143dc8cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d56: 6800100000 PUSH
        batch_guest_pc = 0x00923d56u;
        t10a = 0x00001000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d5b: c70620dd4301 MOV
        batch_guest_pc = 0x00923d5bu;
        t11 = 0x0143dd20u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00923d61: c7460404dd4301 MOV
        batch_guest_pc = 0x00923d61u;
        t12 = 0x0143dd04u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00923d68: 885e08 MOV
        batch_guest_pc = 0x00923d68u;
        t13 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00923d6b: e830366200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00923d70u)) return BatchLiftStatus::invalid_memory;
        t14_call_status = spore_lift_00f473a0(memory, state);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x00923d70u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923d70: 89460c MOV
        batch_guest_pc = 0x00923d70u;
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00923d73: c7461000100000 MOV
        batch_guest_pc = 0x00923d73u;
        t16 = 0x00001000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00923d7a: 895e14 MOV
        batch_guest_pc = 0x00923d7au;
        t17 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00923d7d: 895e18 MOV
        batch_guest_pc = 0x00923d7du;
        t18 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00923d80: 895e1c MOV
        batch_guest_pc = 0x00923d80u;
        t19 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00923d83: 895e20 MOV
        batch_guest_pc = 0x00923d83u;
        t20 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00923d86: 895e2c MOV
        batch_guest_pc = 0x00923d86u;
        t21 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00923d89: 83c418 ADD
        t22a = state.regs[4];
        t22b = 0x00000018u;
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[4] = t22r;
    // 0x00923d8c: 895e30 MOV
        batch_guest_pc = 0x00923d8cu;
        t23 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00923d8f: 33c0 XOR
        t24a = state.regs[0];
        t24b = state.regs[0];
        t24r = (t24a ^ t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
        state.regs[0] = t24r;
    // 0x00923d91: 8d4e34 LEA
        t25 = static_cast<std::uint32_t>(state.regs[6] + 0x00000034u);
        state.regs[1] = t25;
    // 0x00923d94: 8701 XCHG
        if (!batch_guest_xchg32(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00923d96: 6a01 PUSH
        batch_guest_pc = 0x00923d96u;
        t27a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d98: 53 PUSH
        batch_guest_pc = 0x00923d98u;
        t28a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00923d99: 8d4e38 LEA
        t29 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[1] = t29;
    // 0x00923d9c: e8ffe4ffff CALL
        if (!batch_guest_call32(memory, state, 0x009222a0u, 0x00923da1u)) return BatchLiftStatus::invalid_memory;
        t30_call_status = spore_lift_009222a0(memory, state);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x00923da1u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923da1: 8bc6 MOV
        t31 = state.regs[6];
        state.regs[0] = t31;
    // 0x00923da3: 5e POP
        batch_guest_pc = 0x00923da3u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t32a;
    // 0x00923da4: 5b POP
        batch_guest_pc = 0x00923da4u;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t33a;
    // 0x00923da5: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
