#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009267a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009267a0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;

    // 0x009267a0: 8b442404 MOV
        batch_guest_pc = 0x009267a0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009267a4: 83c00b ADD
        t1a = state.regs[0];
        t1b = 0x0000000bu;
        t1r = static_cast<std::uint32_t>(t1a + t1b) & 0xffffffffu;
        batch_set_add_flags(state, t1a, t1b, t1r, 32u);
        state.regs[0] = t1r;
    // 0x009267a7: 83f810 CMP
        t2a = state.regs[0];
        t2b = 0x00000010u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x009267aa: 7604 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_009267b0;
    // 0x009267ac: 83e0f8 AND
        t4a = state.regs[0];
        t4b = 0xfffffff8u;
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[0] = t4r;
    // 0x009267af: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009267b0: b810000000 MOV
    L_009267b0:
        t6 = 0x00000010u;
        state.regs[0] = t6;
    // 0x009267b5: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
