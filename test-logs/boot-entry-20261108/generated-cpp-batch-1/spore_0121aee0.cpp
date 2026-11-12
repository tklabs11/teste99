#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401160(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121aee0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121aee0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;

    // 0x0121aee0: 55 PUSH
        batch_guest_pc = 0x0121aee0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121aee1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121aee3: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0121aee6: 8d45f8 LEA
        t3 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u);
        state.regs[0] = t3;
    // 0x0121aee9: 50 PUSH
        batch_guest_pc = 0x0121aee9u;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0121aeea: e871621eff CALL
        if (!batch_guest_call32(memory, state, 0x00401160u, 0x0121aeefu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_00401160(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0121aeefu) return BatchLiftStatus::invalid_control_flow;
    // 0x0121aeef: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0121aef2: f30f1045f8 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u))) return BatchLiftStatus::invalid_memory;
    // 0x0121aef7: f30f1105d8105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d10d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aeff: f30f1045fc MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu))) return BatchLiftStatus::invalid_memory;
    // 0x0121af04: f30f1105dc105d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d10dcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121af0c: 8be5 MOV
        t11 = state.regs[5];
        state.regs[4] = t11;
    // 0x0121af0e: 5d POP
        batch_guest_pc = 0x0121af0eu;
        if (!memory.load32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t12a;
    // 0x0121af0f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
