#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00921600(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00921600u);
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

    // 0x00921600: 8b542404 MOV
        batch_guest_pc = 0x00921600u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00921604: 8b0a MOV
        batch_guest_pc = 0x00921604u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00921606: 8b4104 MOV
        batch_guest_pc = 0x00921606u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00921609: 8902 MOV
        batch_guest_pc = 0x00921609u;
        t3 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0092160b: 8b4104 MOV
        batch_guest_pc = 0x0092160bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0092160e: 85c0 TEST
        t5a = state.regs[0];
        t5b = state.regs[0];
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
    // 0x00921610: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921615;
    // 0x00921612: 895008 MOV
        batch_guest_pc = 0x00921612u;
        t7 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00921615: 8b4208 MOV
    L_00921615:
        batch_guest_pc = 0x00921615u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00921618: 894108 MOV
        batch_guest_pc = 0x00921618u;
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0092161b: 8b442408 MOV
        batch_guest_pc = 0x0092161bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x0092161f: 3bd0 CMP
        t11a = state.regs[2];
        t11b = state.regs[0];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x00921621: 7509 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092162c;
    // 0x00921623: 895104 MOV
        batch_guest_pc = 0x00921623u;
        t13 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00921626: 8bc1 MOV
        t14 = state.regs[1];
        state.regs[0] = t14;
    // 0x00921628: 894a08 MOV
        batch_guest_pc = 0x00921628u;
        t15 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0092162b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092162c: 56 PUSH
    L_0092162c:
        batch_guest_pc = 0x0092162cu;
        t17a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x0092162d: 8b7208 MOV
        batch_guest_pc = 0x0092162du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t18;
    // 0x00921630: 3b5604 CMP
        batch_guest_pc = 0x00921630u;
        t19a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t19b)) return BatchLiftStatus::invalid_memory;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x00921633: 750b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921640;
    // 0x00921635: 894e04 MOV
        batch_guest_pc = 0x00921635u;
        t21 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00921638: 895104 MOV
        batch_guest_pc = 0x00921638u;
        t22 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x0092163b: 5e POP
        batch_guest_pc = 0x0092163bu;
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t23a;
    // 0x0092163c: 894a08 MOV
        batch_guest_pc = 0x0092163cu;
        t24 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x0092163f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00921640: 890e MOV
    L_00921640:
        batch_guest_pc = 0x00921640u;
        t26 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00921642: 895104 MOV
        batch_guest_pc = 0x00921642u;
        t27 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00921645: 5e POP
        batch_guest_pc = 0x00921645u;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t28a;
    // 0x00921646: 894a08 MOV
        batch_guest_pc = 0x00921646u;
        t29 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00921649: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
