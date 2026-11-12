#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00932e80(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121d580(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121d580u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;

    // 0x0121d580: 55 PUSH
        batch_guest_pc = 0x0121d580u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d581: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121d583: 6a01 PUSH
        batch_guest_pc = 0x0121d583u;
        t2a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d585: 68c59d1c81 PUSH
        batch_guest_pc = 0x0121d585u;
        t3a = 0x811c9dc5u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d58a: 68a8b13e01 PUSH
        batch_guest_pc = 0x0121d58au;
        t4a = 0x013eb1a8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d58f: e8ec5871ff CALL
        if (!batch_guest_call32(memory, state, 0x00932e80u, 0x0121d594u)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_00932e80(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0121d594u) return BatchLiftStatus::invalid_control_flow;
    // 0x0121d594: 83c40c ADD
        t6a = state.regs[4];
        t6b = 0x0000000cu;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0121d597: a390115d01 MOV
        batch_guest_pc = 0x0121d597u;
        t7 = state.regs[0];
        if (!memory.store32(0x015d1190u, t7)) return BatchLiftStatus::invalid_memory;
    // 0x0121d59c: 5d POP
        batch_guest_pc = 0x0121d59cu;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121d59d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
