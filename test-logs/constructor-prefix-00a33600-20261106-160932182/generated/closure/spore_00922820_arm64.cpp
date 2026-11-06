#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00922620(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00922820(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;

    // 0x00922820: 83ec18 SUB
        t0a = state.regs[4];
        t0b = 0x00000018u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00922823: 33c0 XOR
        t1a = state.regs[0];
        t1b = state.regs[0];
        t1r = (t1a ^ t1b) & 0xffffffffu;
        batch_set_logic_flags(state, t1r, 32u);
        state.regs[0] = t1r;
    // 0x00922825: 56 PUSH
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00922826: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x00922828: 8b4c2420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x0092282c: b201 MOV
        t5 = 0x00000001u;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t5 << 0u) & 0x000000ffu);
    // 0x0092282e: 8906 MOV
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00922830: 894604 MOV
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00922833: 894608 MOV
        t8 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00922836: 88560c MOV
        t9 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00922839: 3bc8 CMP
        t10a = state.regs[1];
        t10b = state.regs[0];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x0092283b: 7527 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00922864;
    // 0x0092283d: 38442424 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t12a)) return BatchLiftStatus::invalid_memory;
        t12b = state.regs[0] & 0x000000ffu;
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0x000000ffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 8u);
    // 0x00922841: 7421 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00922864;
    // 0x00922843: 89442404 MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00922847: 88442409 MOV
        t15 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000009u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0092284b: 8d442404 LEA
        t16 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[0] = t16;
    // 0x0092284f: 50 PUSH
        t17a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00922850: 8bce MOV
        t18 = state.regs[6];
        state.regs[1] = t18;
    // 0x00922852: 8854240c MOV
        t19 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00922856: e8c5fdffff CALL
        if (!batch_guest_call32(memory, state, 0x00922620u, 0x0092285bu)) return BatchLiftStatus::invalid_memory;
        t20_call_status = spore_lift_00922620(memory, state);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x0092285bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092285b: 8bc6 MOV
        t21 = state.regs[6];
        state.regs[0] = t21;
    // 0x0092285d: 5e POP
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t22a;
    // 0x0092285e: 83c418 ADD
        t23a = state.regs[4];
        t23b = 0x00000018u;
        t23r = static_cast<std::uint32_t>(t23a + t23b) & 0xffffffffu;
        batch_set_add_flags(state, t23a, t23b, t23r, 32u);
        state.regs[4] = t23r;
    // 0x00922861: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00922864: 51 PUSH
    L_00922864:
        t25a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00922865: 8bce MOV
        t26 = state.regs[6];
        state.regs[1] = t26;
    // 0x00922867: e8b4fdffff CALL
        if (!batch_guest_call32(memory, state, 0x00922620u, 0x0092286cu)) return BatchLiftStatus::invalid_memory;
        t27_call_status = spore_lift_00922620(memory, state);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x0092286cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092286c: 8bc6 MOV
        t28 = state.regs[6];
        state.regs[0] = t28;
    // 0x0092286e: 5e POP
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t29a;
    // 0x0092286f: 83c418 ADD
        t30a = state.regs[4];
        t30b = 0x00000018u;
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[4] = t30r;
    // 0x00922872: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
