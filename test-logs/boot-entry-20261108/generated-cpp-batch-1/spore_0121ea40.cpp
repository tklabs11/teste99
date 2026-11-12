#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004011c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121ea40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ea40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;

    // 0x0121ea40: 55 PUSH
        batch_guest_pc = 0x0121ea40u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ea41: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ea43: 83ec0c SUB
        t2a = state.regs[4];
        t2b = 0x0000000cu;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0121ea46: 8d45f4 LEA
        t3 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u);
        state.regs[0] = t3;
    // 0x0121ea49: 50 PUSH
        batch_guest_pc = 0x0121ea49u;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ea4a: e871271eff CALL
        if (!batch_guest_call32(memory, state, 0x004011c0u, 0x0121ea4fu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_004011c0(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0121ea4fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0121ea4f: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0121ea52: f30f1045f4 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u))) return BatchLiftStatus::invalid_memory;
    // 0x0121ea57: f30f1105d4175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d17d4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ea5f: f30f1045f8 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u))) return BatchLiftStatus::invalid_memory;
    // 0x0121ea64: f30f1105d8175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d17d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ea6c: f30f1045fc MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu))) return BatchLiftStatus::invalid_memory;
    // 0x0121ea71: f30f1105dc175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d17dcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ea79: 8be5 MOV
        t13 = state.regs[5];
        state.regs[4] = t13;
    // 0x0121ea7b: 5d POP
        batch_guest_pc = 0x0121ea7bu;
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t14a;
    // 0x0121ea7c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
