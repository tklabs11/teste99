#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0091a530(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923dc0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923dc0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;

    // 0x00923dc0: 8b4c2408 MOV
        batch_guest_pc = 0x00923dc0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t0;
    // 0x00923dc4: 56 PUSH
        batch_guest_pc = 0x00923dc4u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923dc5: 8b742408 MOV
        batch_guest_pc = 0x00923dc5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t2;
    // 0x00923dc9: 8d442410 LEA
        t3 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t3;
    // 0x00923dcd: 50 PUSH
        batch_guest_pc = 0x00923dcdu;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00923dce: 51 PUSH
        batch_guest_pc = 0x00923dceu;
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00923dcf: 8bce MOV
        t6 = state.regs[6];
        state.regs[1] = t6;
    // 0x00923dd1: e85a67ffff CALL
        if (!batch_guest_call32(memory, state, 0x0091a530u, 0x00923dd6u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_0091a530(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00923dd6u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923dd6: 8bc6 MOV
        t8 = state.regs[6];
        state.regs[0] = t8;
    // 0x00923dd8: 5e POP
        batch_guest_pc = 0x00923dd8u;
        if (!memory.load32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t9a;
    // 0x00923dd9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
