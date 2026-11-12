#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00923380(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923380u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;

    // 0x00923380: 8bc1 MOV
        t0 = state.regs[1];
        state.regs[0] = t0;
    // 0x00923382: 8b4c2404 MOV
        batch_guest_pc = 0x00923382u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00923386: 81f9f01f9f0e CMP
        t2a = state.regs[1];
        t2b = 0x0e9f1ff0u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x0092338c: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009233a4;
    // 0x0092338e: 81f937429f6e CMP
        t4a = state.regs[1];
        t4b = 0x6e9f4237u;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
    // 0x00923394: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009233a4;
    // 0x00923396: 33d2 XOR
        t6a = state.regs[2];
        t6b = state.regs[2];
        t6r = (t6a ^ t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[2] = t6r;
    // 0x00923398: 81f96e513fee CMP
        t7a = state.regs[1];
        t7b = 0xee3f516eu;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x0092339e: 0f95c2 SETNZ
        state.regs[2] = (state.regs[2] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x009233a1: 4a DEC
        t9a = state.regs[2];
        t9r = static_cast<std::uint32_t>(t9a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t9a, t9r, 32u);
        state.regs[2] = t9r;
    // 0x009233a2: 23c2 AND
        t10a = state.regs[0];
        t10b = state.regs[2];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
        state.regs[0] = t10r;
    // 0x009233a4: c20400 RET
    L_009233a4:
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
