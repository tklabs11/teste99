#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00921650(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00921650u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29 = 0;

    // 0x00921650: 8b542404 MOV
        batch_guest_pc = 0x00921650u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00921654: 8b4a04 MOV
        batch_guest_pc = 0x00921654u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00921657: 8b01 MOV
        batch_guest_pc = 0x00921657u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00921659: 894204 MOV
        batch_guest_pc = 0x00921659u;
        t3 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0092165c: 8b01 MOV
        batch_guest_pc = 0x0092165cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0092165e: 85c0 TEST
        t5a = state.regs[0];
        t5b = state.regs[0];
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
    // 0x00921660: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921665;
    // 0x00921662: 895008 MOV
        batch_guest_pc = 0x00921662u;
        t7 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00921665: 8b4208 MOV
    L_00921665:
        batch_guest_pc = 0x00921665u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00921668: 894108 MOV
        batch_guest_pc = 0x00921668u;
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0092166b: 8b442408 MOV
        batch_guest_pc = 0x0092166bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x0092166f: 3bd0 CMP
        t11a = state.regs[2];
        t11b = state.regs[0];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x00921671: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092167b;
    // 0x00921673: 8911 MOV
        batch_guest_pc = 0x00921673u;
        t13 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00921675: 8bc1 MOV
        t14 = state.regs[1];
        state.regs[0] = t14;
    // 0x00921677: 894a08 MOV
        batch_guest_pc = 0x00921677u;
        t15 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0092167a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092167b: 56 PUSH
    L_0092167b:
        batch_guest_pc = 0x0092167bu;
        t17a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x0092167c: 8b7208 MOV
        batch_guest_pc = 0x0092167cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t18;
    // 0x0092167f: 3b16 CMP
        batch_guest_pc = 0x0092167fu;
        t19a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t19b)) return BatchLiftStatus::invalid_memory;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x00921681: 7509 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092168c;
    // 0x00921683: 890e MOV
        batch_guest_pc = 0x00921683u;
        t21 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00921685: 8911 MOV
        batch_guest_pc = 0x00921685u;
        t22 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00921687: 5e POP
        batch_guest_pc = 0x00921687u;
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t23a;
    // 0x00921688: 894a08 MOV
        batch_guest_pc = 0x00921688u;
        t24 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x0092168b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092168c: 894e04 MOV
    L_0092168c:
        batch_guest_pc = 0x0092168cu;
        t26 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0092168f: 8911 MOV
        batch_guest_pc = 0x0092168fu;
        t27 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00921691: 5e POP
        batch_guest_pc = 0x00921691u;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t28a;
    // 0x00921692: 894a08 MOV
        batch_guest_pc = 0x00921692u;
        t29 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00921695: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
