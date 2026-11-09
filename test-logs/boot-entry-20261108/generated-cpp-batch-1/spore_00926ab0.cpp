#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00926a30(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00926ab0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926ab0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18a = 0;

    // 0x00926ab0: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ab1: 8b742408 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t1;
    // 0x00926ab5: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00926ab8: 25f8ffff7f AND
        t3a = state.regs[0];
        t3b = 0x7ffffff8u;
        t3r = (t3a & t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[0] = t3r;
    // 0x00926abd: 83f810 CMP
        t4a = state.regs[0];
        t4b = 0x00000010u;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
    // 0x00926ac0: 731b JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926add;
    // 0x00926ac2: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ac3: e868ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00926a30u, 0x00926ac8u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_00926a30(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00926ac8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926ac8: 85c0 TEST
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x00926aca: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926add;
    // 0x00926acc: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t10;
    // 0x00926acf: 8d5401f0 LEA
        t11 = static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0xfffffff0u);
        state.regs[2] = t11;
    // 0x00926ad3: 3bf2 CMP
        t12a = state.regs[6];
        t12b = state.regs[2];
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x00926ad5: 7206 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00926add;
    // 0x00926ad7: b001 MOV
        t14 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t14 << 0u) & 0x000000ffu);
    // 0x00926ad9: 5e POP
        if (!memory.load32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t15a;
    // 0x00926ada: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00926add: 32c0 XOR
    L_00926add:
        t17a = state.regs[0] & 0x000000ffu;
        t17b = state.regs[0] & 0x000000ffu;
        t17r = (t17a ^ t17b) & 0x000000ffu;
        batch_set_logic_flags(state, t17r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t17r << 0u) & 0x000000ffu);
    // 0x00926adf: 5e POP
        if (!memory.load32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t18a;
    // 0x00926ae0: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
