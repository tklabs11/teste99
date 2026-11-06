#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00922620(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0, t22r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23c = 0, t23r = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t38a = 0;

    // 0x00922620: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00922624: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00922625: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00922627: 85c0 TEST
        t3a = state.regs[0];
        t3b = state.regs[0];
        t3r = (t3a & t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
    // 0x00922629: 7455 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00922680;
    // 0x0092262b: 833e00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5a)) return BatchLiftStatus::invalid_memory;
        t5b = 0x00000000u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x0092262e: 7550 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00922680;
    // 0x00922630: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x00922632: 894e04 MOV
        t8 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00922635: 85c9 TEST
        t9a = state.regs[1];
        t9b = state.regs[1];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x00922637: 7d07 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00922640;
    // 0x00922639: c7460400000000 MOV
        t11 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00922640: 8a4804 MOV
    L_00922640:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t12 << 0u) & 0x000000ffu);
    // 0x00922643: 884e0c MOV
        t13 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00922646: 84c9 TEST
        t14a = state.regs[1] & 0x000000ffu;
        t14b = state.regs[1] & 0x000000ffu;
        t14r = (t14a & t14b) & 0x000000ffu;
        batch_set_logic_flags(state, t14r, 8u);
    // 0x00922648: 740b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00922655;
    // 0x0092264a: 6a00 PUSH
        t16a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x0092264c: 68ffffff3f PUSH
        t17a = 0x3fffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00922651: 6a00 PUSH
        t18a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00922653: eb16 JMP
        goto L_0092266b;
    // 0x00922655: 8d4805 LEA
    L_00922655:
        t20 = static_cast<std::uint32_t>(state.regs[0] + 0x00000005u);
        state.regs[1] = t20;
    // 0x00922658: 0fbe01 MOVSX
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t21a)) return BatchLiftStatus::invalid_memory;
        t21a = static_cast<std::uint32_t>((t21a ^ 0x00000080u) - 0x00000080u);
        state.regs[0] = t21a;
    // 0x0092265b: f7d8 NEG
        t22a = state.regs[0];
        t22r = static_cast<std::uint32_t>(0u - t22a) & 0xffffffffu;
        batch_set_neg_flags(state, t22a, t22r, 32u);
        state.regs[0] = t22r;
    // 0x0092265d: 1bc0 SBB
        t23a = state.regs[0];
        t23b = state.regs[0];
        t23c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t23r = static_cast<std::uint32_t>(t23a - t23b - t23c) & 0xffffffffu;
        batch_set_sbb_flags(state, t23a, t23b, t23c, t23r, 32u);
        state.regs[0] = t23r;
    // 0x0092265f: 23c1 AND
        t24a = state.regs[0];
        t24b = state.regs[1];
        t24r = (t24a & t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
        state.regs[0] = t24r;
    // 0x00922661: 50 PUSH
        t25a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00922662: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t26;
    // 0x00922665: 68ffffff3f PUSH
        t27a = 0x3fffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x0092266a: 50 PUSH
        t28a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x0092266b: 6a00 PUSH
    L_0092266b:
        t29a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x0092266d: ff1598c13c01 CALL
        t30_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!CreateSemaphoreA", 0x013cc198u, 0x00922673u);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x00922673u) return BatchLiftStatus::invalid_control_flow;
    // 0x00922673: 8906 MOV
        t31 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x00922675: 33c0 XOR
        t32a = state.regs[0];
        t32b = state.regs[0];
        t32r = (t32a ^ t32b) & 0xffffffffu;
        batch_set_logic_flags(state, t32r, 32u);
        state.regs[0] = t32r;
    // 0x00922677: 3906 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t33a)) return BatchLiftStatus::invalid_memory;
        t33b = state.regs[0];
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
    // 0x00922679: 5e POP
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t34a;
    // 0x0092267a: 0f95c0 SETNZ
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x0092267d: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00922680: 32c0 XOR
    L_00922680:
        t37a = state.regs[0] & 0x000000ffu;
        t37b = state.regs[0] & 0x000000ffu;
        t37r = (t37a ^ t37b) & 0x000000ffu;
        batch_set_logic_flags(state, t37r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t37r << 0u) & 0x000000ffu);
    // 0x00922682: 5e POP
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t38a;
    // 0x00922683: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
