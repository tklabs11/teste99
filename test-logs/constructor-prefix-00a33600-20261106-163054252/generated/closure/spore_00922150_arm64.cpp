#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00922150(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0, t17r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18c = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32a = 0;

    // 0x00922150: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00922154: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00922155: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00922157: 85c0 TEST
        t3a = state.regs[0];
        t3b = state.regs[0];
        t3r = (t3a & t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
    // 0x00922159: 7443 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092219e;
    // 0x0092215b: c7462000000000 MOV
        t5 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000020u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x00922162: 8a08 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t6 << 0u) & 0x000000ffu);
    // 0x00922164: 884e24 MOV
        t7 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00922167: 84c9 TEST
        t8a = state.regs[1] & 0x000000ffu;
        t8b = state.regs[1] & 0x000000ffu;
        t8r = (t8a & t8b) & 0x000000ffu;
        batch_set_logic_flags(state, t8r, 8u);
    // 0x00922169: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00922178;
    // 0x0092216b: 56 PUSH
        t10a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0092216c: ff15d0c23c01 CALL
        t11_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!InitializeCriticalSection", 0x013cc2d0u, 0x00922172u);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x00922172u) return BatchLiftStatus::invalid_control_flow;
    // 0x00922172: b001 MOV
        t12 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t12 << 0u) & 0x000000ffu);
    // 0x00922174: 5e POP
        if (!memory.load32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t13a;
    // 0x00922175: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00922178: 8d4801 LEA
    L_00922178:
        t15 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[1] = t15;
    // 0x0092217b: 0fbe01 MOVSX
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t16a)) return BatchLiftStatus::invalid_memory;
        t16a = static_cast<std::uint32_t>((t16a ^ 0x00000080u) - 0x00000080u);
        state.regs[0] = t16a;
    // 0x0092217e: f7d8 NEG
        t17a = state.regs[0];
        t17r = static_cast<std::uint32_t>(0u - t17a) & 0xffffffffu;
        batch_set_neg_flags(state, t17a, t17r, 32u);
        state.regs[0] = t17r;
    // 0x00922180: 1bc0 SBB
        t18a = state.regs[0];
        t18b = state.regs[0];
        t18c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t18r = static_cast<std::uint32_t>(t18a - t18b - t18c) & 0xffffffffu;
        batch_set_sbb_flags(state, t18a, t18b, t18c, t18r, 32u);
        state.regs[0] = t18r;
    // 0x00922182: 23c1 AND
        t19a = state.regs[0];
        t19b = state.regs[1];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[0] = t19r;
    // 0x00922184: 50 PUSH
        t20a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00922185: 6a00 PUSH
        t21a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00922187: 6a00 PUSH
        t22a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00922189: ff1580c13c01 CALL
        t23_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!CreateMutexA", 0x013cc180u, 0x0092218fu);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x0092218fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092218f: 33c9 XOR
        t24a = state.regs[1];
        t24b = state.regs[1];
        t24r = (t24a ^ t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
        state.regs[1] = t24r;
    // 0x00922191: 85c0 TEST
        t25a = state.regs[0];
        t25b = state.regs[0];
        t25r = (t25a & t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
    // 0x00922193: 8906 MOV
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00922195: 0f95c1 SETNZ
        state.regs[1] = (state.regs[1] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00922198: 8ac1 MOV
        t28 = state.regs[1] & 0x000000ffu;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t28 << 0u) & 0x000000ffu);
    // 0x0092219a: 5e POP
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t29a;
    // 0x0092219b: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092219e: 32c0 XOR
    L_0092219e:
        t31a = state.regs[0] & 0x000000ffu;
        t31b = state.regs[0] & 0x000000ffu;
        t31r = (t31a ^ t31b) & 0x000000ffu;
        batch_set_logic_flags(state, t31r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t31r << 0u) & 0x000000ffu);
    // 0x009221a0: 5e POP
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t32a;
    // 0x009221a1: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
