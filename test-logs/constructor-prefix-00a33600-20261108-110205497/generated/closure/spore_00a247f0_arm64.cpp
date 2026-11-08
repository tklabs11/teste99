#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009222a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e5d80(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00a247f0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;

    // 0x00a247f0: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00a247f2: 6883852101 PUSH
        t1a = 0x01218583u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00a247f7: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00a247fd: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00a247fe: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00a24805: 51 PUSH
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00a24806: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00a24807: 8bf1 MOV
        t7 = state.regs[1];
        state.regs[6] = t7;
    // 0x00a24809: 6834934401 PUSH
        t8a = 0x01449334u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2480e: 89742408 MOV
        t9 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00a24812: e869157c00 CALL
        if (!batch_guest_call32(memory, state, 0x011e5d80u, 0x00a24817u)) return BatchLiftStatus::invalid_memory;
        t10_call_status = spore_lift_011e5d80(memory, state);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x00a24817u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a24817: 33c0 XOR
        t11a = state.regs[0];
        t11b = state.regs[0];
        t11r = (t11a ^ t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
        state.regs[0] = t11r;
    // 0x00a24819: c706f02a4501 MOV
        t12 = 0x01452af0u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00a2481f: 89442410 MOV
        t13 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00a24823: 894614 MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00a24826: 894618 MOV
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00a24829: 89461c MOV
        t16 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00a2482c: 6a01 PUSH
        t17a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2482e: 50 PUSH
        t18a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2482f: 8d4e28 LEA
        t19 = static_cast<std::uint32_t>(state.regs[6] + 0x00000028u);
        state.regs[1] = t19;
    // 0x00a24832: c644241801 MOV
        t20 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00a24837: e864daefff CALL
        if (!batch_guest_call32(memory, state, 0x009222a0u, 0x00a2483cu)) return BatchLiftStatus::invalid_memory;
        t21_call_status = spore_lift_009222a0(memory, state);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x00a2483cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00a2483c: 8b4c2408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x00a24840: 8bc6 MOV
        t23 = state.regs[6];
        state.regs[0] = t23;
    // 0x00a24842: 5e POP
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t24a;
    // 0x00a24843: 64890d00000000 MOV
        t25 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x00a2484a: 83c410 ADD
        t26a = state.regs[4];
        t26b = 0x00000010u;
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[4] = t26r;
    // 0x00a2484d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
