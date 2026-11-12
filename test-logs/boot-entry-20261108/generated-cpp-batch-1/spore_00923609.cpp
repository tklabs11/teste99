#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923609(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923609u);
    std::uint32_t t0 = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;

    // 0x00923609: 8b4c2410 MOV
        batch_guest_pc = 0x00923609u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t0;
    // 0x0092360d: e85eecffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00923612u)) return BatchLiftStatus::invalid_memory;
        t1_call_status = spore_lift_00922270(memory, state);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
        if (state.eip != 0x00923612u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923612: 5d POP
        batch_guest_pc = 0x00923612u;
        if (!memory.load32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t2a;
    // 0x00923613: 5f POP
        batch_guest_pc = 0x00923613u;
        if (!memory.load32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t3a;
    // 0x00923614: 8bc6 MOV
        t4 = state.regs[6];
        state.regs[0] = t4;
    // 0x00923616: 5e POP
        batch_guest_pc = 0x00923616u;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t5a;
    // 0x00923617: 5b POP
        batch_guest_pc = 0x00923617u;
        if (!memory.load32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t6a;
    // 0x00923618: 81c408010000 ADD
        t7a = state.regs[4];
        t7b = 0x00000108u;
        t7r = static_cast<std::uint32_t>(t7a + t7b) & 0xffffffffu;
        batch_set_add_flags(state, t7a, t7b, t7r, 32u);
        state.regs[4] = t7r;
    // 0x0092361e: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
