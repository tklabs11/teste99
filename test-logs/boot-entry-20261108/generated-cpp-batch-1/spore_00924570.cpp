#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0060a150(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924570(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924570u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    BatchLiftStatus t22_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;

    // 0x00924570: 8b4108 MOV
        batch_guest_pc = 0x00924570u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00924573: 83c108 ADD
        t1a = state.regs[1];
        t1b = 0x00000008u;
        t1r = static_cast<std::uint32_t>(t1a + t1b) & 0xffffffffu;
        batch_set_add_flags(state, t1a, t1b, t1r, 32u);
        state.regs[1] = t1r;
    // 0x00924576: 56 PUSH
        batch_guest_pc = 0x00924576u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00924577: 8b742408 MOV
        batch_guest_pc = 0x00924577u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t3;
    // 0x0092457b: 3bc6 CMP
        t4a = state.regs[0];
        t4b = state.regs[6];
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
    // 0x0092457d: 7426 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009245a5;
    // 0x0092457f: 3b4104 CMP
        batch_guest_pc = 0x0092457fu;
        t6a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t6b)) return BatchLiftStatus::invalid_memory;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00924582: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092458c;
    // 0x00924584: c60000 MOV
        batch_guest_pc = 0x00924584u;
        t8 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00924587: 8b01 MOV
        batch_guest_pc = 0x00924587u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x00924589: 894104 MOV
        batch_guest_pc = 0x00924589u;
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x0092458c: 8bc6 MOV
    L_0092458c:
        t11 = state.regs[6];
        state.regs[0] = t11;
    // 0x0092458e: 57 PUSH
        batch_guest_pc = 0x0092458eu;
        t12a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x0092458f: 8d7801 LEA
        t13 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[7] = t13;
    // 0x00924592: 8a10 MOV
    L_00924592:
        batch_guest_pc = 0x00924592u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t14 << 0u) & 0x000000ffu);
    // 0x00924594: 40 INC
        t15a = state.regs[0];
        t15r = static_cast<std::uint32_t>(t15a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t15a, t15r, 32u);
        state.regs[0] = t15r;
    // 0x00924595: 84d2 TEST
        t16a = state.regs[2] & 0x000000ffu;
        t16b = state.regs[2] & 0x000000ffu;
        t16r = (t16a & t16b) & 0x000000ffu;
        batch_set_logic_flags(state, t16r, 8u);
    // 0x00924597: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924592;
    // 0x00924599: 2bc7 SUB
        t18a = state.regs[0];
        t18b = state.regs[7];
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
        state.regs[0] = t18r;
    // 0x0092459b: 03c6 ADD
        t19a = state.regs[0];
        t19b = state.regs[6];
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[0] = t19r;
    // 0x0092459d: 50 PUSH
        batch_guest_pc = 0x0092459du;
        t20a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x0092459e: 56 PUSH
        batch_guest_pc = 0x0092459eu;
        t21a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x0092459f: e8ac5bceff CALL
        if (!batch_guest_call32(memory, state, 0x0060a150u, 0x009245a4u)) return BatchLiftStatus::invalid_memory;
        t22_call_status = spore_lift_0060a150(memory, state);
        if (t22_call_status != BatchLiftStatus::returned) return t22_call_status;
        if (state.eip != 0x009245a4u) return BatchLiftStatus::invalid_control_flow;
    // 0x009245a4: 5f POP
        batch_guest_pc = 0x009245a4u;
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t23a;
    // 0x009245a5: 5e POP
    L_009245a5:
        batch_guest_pc = 0x009245a5u;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t24a;
    // 0x009245a6: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
