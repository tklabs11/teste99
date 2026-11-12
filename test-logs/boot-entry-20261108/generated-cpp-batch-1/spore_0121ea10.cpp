#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401190(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121ea10(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ea10u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;

    // 0x0121ea10: 55 PUSH
        batch_guest_pc = 0x0121ea10u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ea11: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ea13: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0121ea16: 8d45f8 LEA
        t3 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u);
        state.regs[0] = t3;
    // 0x0121ea19: 50 PUSH
        batch_guest_pc = 0x0121ea19u;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ea1a: e871271eff CALL
        if (!batch_guest_call32(memory, state, 0x00401190u, 0x0121ea1fu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_00401190(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0121ea1fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0121ea1f: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0121ea22: f30f1045f8 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u))) return BatchLiftStatus::invalid_memory;
    // 0x0121ea27: f30f1105001b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1b00u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ea2f: f30f1045fc MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu))) return BatchLiftStatus::invalid_memory;
    // 0x0121ea34: f30f1105041b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1b04u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ea3c: 8be5 MOV
        t11 = state.regs[5];
        state.regs[4] = t11;
    // 0x0121ea3e: 5d POP
        batch_guest_pc = 0x0121ea3eu;
        if (!memory.load32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t12a;
    // 0x0121ea3f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
