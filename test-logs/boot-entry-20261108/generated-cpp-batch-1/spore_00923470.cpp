#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00923470(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923470u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0, t7r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;

    // 0x00923470: 8bc1 MOV
        t0 = state.regs[1];
        state.regs[0] = t0;
    // 0x00923472: 8b4c2404 MOV
        batch_guest_pc = 0x00923472u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00923476: 81f93d22ab23 CMP
        t2a = state.regs[1];
        t2b = 0x23ab223du;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x0092347c: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092348c;
    // 0x0092347e: 33d2 XOR
        t4a = state.regs[2];
        t4b = state.regs[2];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[2] = t4r;
    // 0x00923480: 81f96e513fee CMP
        t5a = state.regs[1];
        t5b = 0xee3f516eu;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x00923486: 0f95c2 SETNZ
        state.regs[2] = (state.regs[2] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00923489: 4a DEC
        t7a = state.regs[2];
        t7r = static_cast<std::uint32_t>(t7a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t7a, t7r, 32u);
        state.regs[2] = t7r;
    // 0x0092348a: 23c2 AND
        t8a = state.regs[0];
        t8b = state.regs[2];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[0] = t8r;
    // 0x0092348c: c20400 RET
    L_0092348c:
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
