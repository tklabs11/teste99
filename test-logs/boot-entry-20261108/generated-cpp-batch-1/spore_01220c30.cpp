#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004018a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_01220c30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220c30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;

    // 0x01220c30: 55 PUSH
        batch_guest_pc = 0x01220c30u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220c31: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220c33: 51 PUSH
        batch_guest_pc = 0x01220c33u;
        t2a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x01220c34: 6a00 PUSH
        batch_guest_pc = 0x01220c34u;
        t3a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x01220c36: 6a2b PUSH
        batch_guest_pc = 0x01220c36u;
        t4a = 0x0000002bu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x01220c38: 6a01 PUSH
        batch_guest_pc = 0x01220c38u;
        t5a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x01220c3a: 6a60 PUSH
        batch_guest_pc = 0x01220c3au;
        t6a = 0x00000060u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x01220c3c: e85f0c1eff CALL
        if (!batch_guest_call32(memory, state, 0x004018a0u, 0x01220c41u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_004018a0(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x01220c41u) return BatchLiftStatus::invalid_control_flow;
    // 0x01220c41: 83c410 ADD
        t8a = state.regs[4];
        t8b = 0x00000010u;
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        state.regs[4] = t8r;
    // 0x01220c44: a3d81f5d01 MOV
        batch_guest_pc = 0x01220c44u;
        t9 = state.regs[0];
        if (!memory.store32(0x015d1fd8u, t9)) return BatchLiftStatus::invalid_memory;
    // 0x01220c49: 8be5 MOV
        t10 = state.regs[5];
        state.regs[4] = t10;
    // 0x01220c4b: 5d POP
        batch_guest_pc = 0x01220c4bu;
        if (!memory.load32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t11a;
    // 0x01220c4c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
