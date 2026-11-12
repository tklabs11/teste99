#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00925cb0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925cb0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;

    // 0x00925cb0: a1ac8e6601 MOV
        batch_guest_pc = 0x00925cb0u;
        if (!memory.load32(0x01668eacu, t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00925cb5: 33c9 XOR
        t1a = state.regs[1];
        t1b = state.regs[1];
        t1r = (t1a ^ t1b) & 0xffffffffu;
        batch_set_logic_flags(state, t1r, 32u);
        state.regs[1] = t1r;
    // 0x00925cb7: 3bc1 CMP
        t2a = state.regs[0];
        t2b = state.regs[1];
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x00925cb9: 752e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925ce9;
    // 0x00925cbb: 390d84df5401 CMP
        batch_guest_pc = 0x00925cbbu;
        if (!memory.load32(0x0154df84u, t4a)) return BatchLiftStatus::invalid_memory;
        t4b = state.regs[1];
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
    // 0x00925cc1: 751c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925cdf;
    // 0x00925cc3: a1448b6c01 MOV
        batch_guest_pc = 0x00925cc3u;
        if (!memory.load32(0x016c8b44u, t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x00925cc8: a384df5401 MOV
        batch_guest_pc = 0x00925cc8u;
        t7 = state.regs[0];
        if (!memory.store32(0x0154df84u, t7)) return BatchLiftStatus::invalid_memory;
    // 0x00925ccd: 880d88df5401 MOV
        batch_guest_pc = 0x00925ccdu;
        t8 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(0x0154df88u, t8)) return BatchLiftStatus::invalid_memory;
    // 0x00925cd3: 890d8cdf5401 MOV
        batch_guest_pc = 0x00925cd3u;
        t9 = state.regs[1];
        if (!memory.store32(0x0154df8cu, t9)) return BatchLiftStatus::invalid_memory;
    // 0x00925cd9: 890d90df5401 MOV
        batch_guest_pc = 0x00925cd9u;
        t10 = state.regs[1];
        if (!memory.store32(0x0154df90u, t10)) return BatchLiftStatus::invalid_memory;
    // 0x00925cdf: b880df5401 MOV
    L_00925cdf:
        t11 = 0x0154df80u;
        state.regs[0] = t11;
    // 0x00925ce4: a3ac8e6601 MOV
        batch_guest_pc = 0x00925ce4u;
        t12 = state.regs[0];
        if (!memory.store32(0x01668eacu, t12)) return BatchLiftStatus::invalid_memory;
    // 0x00925ce9: c3 RET
    L_00925ce9:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
