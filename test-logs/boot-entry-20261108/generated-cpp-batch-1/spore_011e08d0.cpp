#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e08d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e08d0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0;
    std::uint32_t t5a = 0, t5c = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10c = 0, t10r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;

    // 0x011e08d0: 80f940 CMP
        t0a = state.regs[1] & 0x000000ffu;
        t0b = 0x00000040u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0x000000ffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 8u);
    // 0x011e08d3: 7315 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_011e08ea;
    // 0x011e08d5: 80f920 CMP
        t2a = state.regs[1] & 0x000000ffu;
        t2b = 0x00000020u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0x000000ffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 8u);
    // 0x011e08d8: 7306 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_011e08e0;
    // 0x011e08da: 0fadd0 SHRD
        t4a = state.regs[0];
        t4b = state.regs[2];
        {
            const std::uint32_t result = batch_guest_shrd(state, t4a, t4b, state.regs[1], 32u);
            state.regs[0] = result;
        }
    // 0x011e08dd: d3ea SHR
        t5a = state.regs[2];
        t5c = (state.regs[1] & 0x1fu);
        if (t5c != 0u) {
        t5r = static_cast<std::uint32_t>(t5a >> t5c);
        batch_set_shr_flags(state, t5a, t5c, t5r, 32u);
            state.regs[2] = t5r;
        }
    // 0x011e08df: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x011e08e0: 8bc2 MOV
    L_011e08e0:
        t7 = state.regs[2];
        state.regs[0] = t7;
    // 0x011e08e2: 33d2 XOR
        t8a = state.regs[2];
        t8b = state.regs[2];
        t8r = (t8a ^ t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[2] = t8r;
    // 0x011e08e4: 80e11f AND
        t9a = state.regs[1] & 0x000000ffu;
        t9b = 0x0000001fu;
        t9r = (t9a & t9b) & 0x000000ffu;
        batch_set_logic_flags(state, t9r, 8u);
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t9r << 0u) & 0x000000ffu);
    // 0x011e08e7: d3e8 SHR
        t10a = state.regs[0];
        t10c = (state.regs[1] & 0x1fu);
        if (t10c != 0u) {
        t10r = static_cast<std::uint32_t>(t10a >> t10c);
        batch_set_shr_flags(state, t10a, t10c, t10r, 32u);
            state.regs[0] = t10r;
        }
    // 0x011e08e9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x011e08ea: 33c0 XOR
    L_011e08ea:
        t12a = state.regs[0];
        t12b = state.regs[0];
        t12r = (t12a ^ t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
        state.regs[0] = t12r;
    // 0x011e08ec: 33d2 XOR
        t13a = state.regs[2];
        t13b = state.regs[2];
        t13r = (t13a ^ t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
        state.regs[2] = t13r;
    // 0x011e08ee: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
