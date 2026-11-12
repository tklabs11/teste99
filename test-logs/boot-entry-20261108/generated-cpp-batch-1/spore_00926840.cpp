#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926840(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926840u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23c = 0, t23r = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26 = 0;

    // 0x00926840: 8b8140040000 MOV
        batch_guest_pc = 0x00926840u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00926846: 8b542404 MOV
        batch_guest_pc = 0x00926846u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t1;
    // 0x0092684a: 899140040000 MOV
        batch_guest_pc = 0x0092684au;
        t2 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t2)) return BatchLiftStatus::invalid_memory;
    // 0x00926850: 89520c MOV
        batch_guest_pc = 0x00926850u;
        t3 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00926853: 8b9140040000 MOV
        batch_guest_pc = 0x00926853u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t4;
    // 0x00926859: 56 PUSH
        batch_guest_pc = 0x00926859u;
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092685a: 8b720c MOV
        batch_guest_pc = 0x0092685au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t6;
    // 0x0092685d: 897208 MOV
        batch_guest_pc = 0x0092685du;
        t7 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00926860: 8d5130 LEA
        t8 = static_cast<std::uint32_t>(state.regs[1] + 0x00000030u);
        state.regs[2] = t8;
    // 0x00926863: 3bc2 CMP
        t9a = state.regs[0];
        t9b = state.regs[2];
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x00926865: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092687d;
    // 0x00926867: 807c240c00 CMP
        batch_guest_pc = 0x00926867u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t11a)) return BatchLiftStatus::invalid_memory;
        t11b = 0x00000000u;
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0x000000ffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 8u);
    // 0x0092686c: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092687d;
    // 0x0092686e: 8b720c MOV
        batch_guest_pc = 0x0092686eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t13;
    // 0x00926871: 895008 MOV
        batch_guest_pc = 0x00926871u;
        t14 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00926874: 89700c MOV
        batch_guest_pc = 0x00926874u;
        t15 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00926877: 89420c MOV
        batch_guest_pc = 0x00926877u;
        t16 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x0092687a: 894608 MOV
        batch_guest_pc = 0x0092687au;
        t17 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x0092687d: 80b96c04000000 CMP
    L_0092687d:
        batch_guest_pc = 0x0092687du;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000046cu), t18a)) return BatchLiftStatus::invalid_memory;
        t18b = 0x00000000u;
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0x000000ffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 8u);
    // 0x00926884: 5e POP
        batch_guest_pc = 0x00926884u;
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t19a;
    // 0x00926885: 7519 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009268a0;
    // 0x00926887: 8b8140040000 MOV
        batch_guest_pc = 0x00926887u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x0092688d: 8b5004 MOV
        batch_guest_pc = 0x0092688du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x00926890: d1ea SHR
        t23a = state.regs[2];
        t23c = 1u;
        if (t23c != 0u) {
        t23r = static_cast<std::uint32_t>(t23a >> t23c);
        batch_set_shr_flags(state, t23a, t23c, t23r, 32u);
            state.regs[2] = t23r;
        }
    // 0x00926892: 81e2fcffff3f AND
        t24a = state.regs[2];
        t24b = 0x3ffffffcu;
        t24r = (t24a & t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
        state.regs[2] = t24r;
    // 0x00926898: 03d0 ADD
        t25a = state.regs[2];
        t25b = state.regs[0];
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[2] = t25r;
    // 0x0092689a: 899168040000 MOV
        batch_guest_pc = 0x0092689au;
        t26 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000468u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x009268a0: c20800 RET
    L_009268a0:
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
