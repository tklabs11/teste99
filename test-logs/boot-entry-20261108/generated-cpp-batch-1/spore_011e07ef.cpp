#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e074a(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e07efu);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t5a = 0, t5r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6c = 0, t6r = 0;
    std::uint32_t t7a = 0, t7r = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0, t9r = 0;
    std::uint32_t t10a = 0;

    // 0x011e07ef: 8bff MOV
        t0 = state.regs[7];
        state.regs[7] = t0;
    // 0x011e07f1: 55 PUSH
        batch_guest_pc = 0x011e07f1u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e07f2: 8bec MOV
        t2 = state.regs[4];
        state.regs[5] = t2;
    // 0x011e07f4: ff7508 PUSH
        batch_guest_pc = 0x011e07f4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t3a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x011e07f7: e84effffff CALL
        if (!batch_guest_call32(memory, state, 0x011e074au, 0x011e07fcu)) return BatchLiftStatus::invalid_memory;
        t4_call_status = spore_lift_011e074a(memory, state);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x011e07fcu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e07fc: f7d8 NEG
        t5a = state.regs[0];
        t5r = static_cast<std::uint32_t>(0u - t5a) & 0xffffffffu;
        batch_set_neg_flags(state, t5a, t5r, 32u);
        state.regs[0] = t5r;
    // 0x011e07fe: 1bc0 SBB
        t6a = state.regs[0];
        t6b = state.regs[0];
        t6c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t6r = static_cast<std::uint32_t>(t6a - t6b - t6c) & 0xffffffffu;
        batch_set_sbb_flags(state, t6a, t6b, t6c, t6r, 32u);
        state.regs[0] = t6r;
    // 0x011e0800: f7d8 NEG
        t7a = state.regs[0];
        t7r = static_cast<std::uint32_t>(0u - t7a) & 0xffffffffu;
        batch_set_neg_flags(state, t7a, t7r, 32u);
        state.regs[0] = t7r;
    // 0x011e0802: 59 POP
        batch_guest_pc = 0x011e0802u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t8a;
    // 0x011e0803: 48 DEC
        t9a = state.regs[0];
        t9r = static_cast<std::uint32_t>(t9a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t9a, t9r, 32u);
        state.regs[0] = t9r;
    // 0x011e0804: 5d POP
        batch_guest_pc = 0x011e0804u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x011e0805: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
