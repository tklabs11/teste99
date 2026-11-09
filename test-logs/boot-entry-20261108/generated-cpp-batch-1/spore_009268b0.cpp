#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009268b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009268b0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14c = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;

    // 0x009268b0: 8b542408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x009268b4: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x009268b8: 56 PUSH
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009268b9: 8bf2 MOV
        t3 = state.regs[2];
        state.regs[6] = t3;
    // 0x009268bb: 83ce01 OR
        t4a = state.regs[6];
        t4b = 0x00000001u;
        t4r = (t4a | t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[6] = t4r;
    // 0x009268be: 897004 MOV
        t5 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x009268c1: 89400c MOV
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t6)) return BatchLiftStatus::invalid_memory;
    // 0x009268c4: 894008 MOV
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x009268c7: 891410 MOV
        t8 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[2] * 1u + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x009268ca: 80b96c04000000 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000046cu), t9a)) return BatchLiftStatus::invalid_memory;
        t9b = 0x00000000u;
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0x000000ffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 8u);
    // 0x009268d1: 5e POP
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t10a;
    // 0x009268d2: 7519 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009268ed;
    // 0x009268d4: 8b8140040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x009268da: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x009268dd: d1ea SHR
        t14a = state.regs[2];
        t14c = 1u;
        if (t14c != 0u) {
        t14r = static_cast<std::uint32_t>(t14a >> t14c);
        batch_set_shr_flags(state, t14a, t14c, t14r, 32u);
            state.regs[2] = t14r;
        }
    // 0x009268df: 81e2fcffff3f AND
        t15a = state.regs[2];
        t15b = 0x3ffffffcu;
        t15r = (t15a & t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
        state.regs[2] = t15r;
    // 0x009268e5: 03d0 ADD
        t16a = state.regs[2];
        t16b = state.regs[0];
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[2] = t16r;
    // 0x009268e7: 899168040000 MOV
        t17 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000468u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x009268ed: c20800 RET
    L_009268ed:
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
