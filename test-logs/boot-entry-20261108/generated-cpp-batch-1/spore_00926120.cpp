#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926120(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926120u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0, t4r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;

    // 0x00926120: 56 PUSH
        batch_guest_pc = 0x00926120u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00926121: 8b742408 MOV
        batch_guest_pc = 0x00926121u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t1;
    // 0x00926125: 56 PUSH
        batch_guest_pc = 0x00926125u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00926126: ff15d8c23c01 CALL
        t3_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x0092612cu);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x0092612cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092612c: ff4618 INC
        batch_guest_pc = 0x0092612cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t4a)) return BatchLiftStatus::invalid_memory;
        t4r = static_cast<std::uint32_t>(t4a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t4a, t4r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t4r)) return BatchLiftStatus::invalid_memory;
    // 0x0092612f: 8b4618 MOV
        batch_guest_pc = 0x0092612fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x00926132: 5e POP
        batch_guest_pc = 0x00926132u;
        if (!memory.load32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t6a;
    // 0x00926133: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
