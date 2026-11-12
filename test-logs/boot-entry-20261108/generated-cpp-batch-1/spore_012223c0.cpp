#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004012c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_012223c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012223c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;

    // 0x012223c0: 55 PUSH
        batch_guest_pc = 0x012223c0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012223c1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012223c3: 83ec0c SUB
        t2a = state.regs[4];
        t2b = 0x0000000cu;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x012223c6: 8d45f4 LEA
        t3 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u);
        state.regs[0] = t3;
    // 0x012223c9: 50 PUSH
        batch_guest_pc = 0x012223c9u;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x012223ca: e8f1ee1dff CALL
        if (!batch_guest_call32(memory, state, 0x004012c0u, 0x012223cfu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_004012c0(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x012223cfu) return BatchLiftStatus::invalid_control_flow;
    // 0x012223cf: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x012223d2: f30f1045f4 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u))) return BatchLiftStatus::invalid_memory;
    // 0x012223d7: f30f11051c225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d221cu)) return BatchLiftStatus::invalid_memory;
    // 0x012223df: f30f1045f8 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u))) return BatchLiftStatus::invalid_memory;
    // 0x012223e4: f30f110520225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2220u)) return BatchLiftStatus::invalid_memory;
    // 0x012223ec: f30f1045fc MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu))) return BatchLiftStatus::invalid_memory;
    // 0x012223f1: f30f110524225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2224u)) return BatchLiftStatus::invalid_memory;
    // 0x012223f9: 8be5 MOV
        t13 = state.regs[5];
        state.regs[4] = t13;
    // 0x012223fb: 5d POP
        batch_guest_pc = 0x012223fbu;
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t14a;
    // 0x012223fc: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
