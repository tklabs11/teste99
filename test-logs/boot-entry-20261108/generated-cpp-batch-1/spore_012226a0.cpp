#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401850(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_012226a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012226a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;

    // 0x012226a0: 55 PUSH
        batch_guest_pc = 0x012226a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012226a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012226a3: 83ec10 SUB
        t2a = state.regs[4];
        t2b = 0x00000010u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x012226a6: 8d45f0 LEA
        t3 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u);
        state.regs[0] = t3;
    // 0x012226a9: 50 PUSH
        batch_guest_pc = 0x012226a9u;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x012226aa: e8a1f11dff CALL
        if (!batch_guest_call32(memory, state, 0x00401850u, 0x012226afu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_00401850(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x012226afu) return BatchLiftStatus::invalid_control_flow;
    // 0x012226af: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x012226b2: f30f1045f0 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u))) return BatchLiftStatus::invalid_memory;
    // 0x012226b7: f30f1105b8265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26b8u)) return BatchLiftStatus::invalid_memory;
    // 0x012226bf: f30f1045f4 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u))) return BatchLiftStatus::invalid_memory;
    // 0x012226c4: f30f1105bc265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26bcu)) return BatchLiftStatus::invalid_memory;
    // 0x012226cc: f30f1045f8 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u))) return BatchLiftStatus::invalid_memory;
    // 0x012226d1: f30f1105c0265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26c0u)) return BatchLiftStatus::invalid_memory;
    // 0x012226d9: f30f1045fc MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu))) return BatchLiftStatus::invalid_memory;
    // 0x012226de: f30f1105c4265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26c4u)) return BatchLiftStatus::invalid_memory;
    // 0x012226e6: 8be5 MOV
        t15 = state.regs[5];
        state.regs[4] = t15;
    // 0x012226e8: 5d POP
        batch_guest_pc = 0x012226e8u;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t16a;
    // 0x012226e9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
