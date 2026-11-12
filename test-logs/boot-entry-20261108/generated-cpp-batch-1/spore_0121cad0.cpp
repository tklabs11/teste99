#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004011c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121cad0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121cad0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;

    // 0x0121cad0: 55 PUSH
        batch_guest_pc = 0x0121cad0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121cad1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121cad3: 83ec0c SUB
        t2a = state.regs[4];
        t2b = 0x0000000cu;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0121cad6: 8d45f4 LEA
        t3 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u);
        state.regs[0] = t3;
    // 0x0121cad9: 50 PUSH
        batch_guest_pc = 0x0121cad9u;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0121cada: e8e1461eff CALL
        if (!batch_guest_call32(memory, state, 0x004011c0u, 0x0121cadfu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_004011c0(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0121cadfu) return BatchLiftStatus::invalid_control_flow;
    // 0x0121cadf: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0121cae2: f30f1045f4 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u))) return BatchLiftStatus::invalid_memory;
    // 0x0121cae7: f30f11057c125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d127cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121caef: f30f1045f8 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u))) return BatchLiftStatus::invalid_memory;
    // 0x0121caf4: f30f110580125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1280u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cafc: f30f1045fc MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu))) return BatchLiftStatus::invalid_memory;
    // 0x0121cb01: f30f110584125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1284u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cb09: 8be5 MOV
        t13 = state.regs[5];
        state.regs[4] = t13;
    // 0x0121cb0b: 5d POP
        batch_guest_pc = 0x0121cb0bu;
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t14a;
    // 0x0121cb0c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
