#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009212c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00921340(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00921340u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;

    // 0x00921340: 8d442404 LEA
        t0 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[0] = t0;
    // 0x00921344: 50 PUSH
        batch_guest_pc = 0x00921344u;
        t1a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00921345: 6850dc4301 PUSH
        batch_guest_pc = 0x00921345u;
        t2a = 0x0143dc50u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0092134a: 6850d84301 PUSH
        batch_guest_pc = 0x0092134au;
        t3a = 0x0143d850u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0092134f: e86cffffff CALL
        if (!batch_guest_call32(memory, state, 0x009212c0u, 0x00921354u)) return BatchLiftStatus::invalid_memory;
        t4_call_status = spore_lift_009212c0(memory, state);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x00921354u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921354: 8b40fc MOV
        batch_guest_pc = 0x00921354u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x00921357: 83c40c ADD
        t6a = state.regs[4];
        t6b = 0x0000000cu;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0092135a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
