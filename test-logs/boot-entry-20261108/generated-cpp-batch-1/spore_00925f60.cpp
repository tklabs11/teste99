#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00925d60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925f60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925f60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;

    // 0x00925f60: 56 PUSH
        batch_guest_pc = 0x00925f60u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925f61: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00925f63: c70604e14301 MOV
        batch_guest_pc = 0x00925f63u;
        t2 = 0x0143e104u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
    // 0x00925f69: e8f2fdffff CALL
        if (!batch_guest_call32(memory, state, 0x00925d60u, 0x00925f6eu)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_00925d60(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x00925f6eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00925f6e: f644240801 TEST
        batch_guest_pc = 0x00925f6eu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t4a)) return BatchLiftStatus::invalid_memory;
        t4b = 0x00000001u;
        t4r = (t4a & t4b) & 0x000000ffu;
        batch_set_logic_flags(state, t4r, 8u);
    // 0x00925f73: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925f7e;
    // 0x00925f75: 56 PUSH
        batch_guest_pc = 0x00925f75u;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925f76: e805146200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00925f7bu)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_00f47380(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00925f7bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00925f7b: 83c404 ADD
        t8a = state.regs[4];
        t8b = 0x00000004u;
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        state.regs[4] = t8r;
    // 0x00925f7e: 8bc6 MOV
    L_00925f7e:
        t9 = state.regs[6];
        state.regs[0] = t9;
    // 0x00925f80: 5e POP
        batch_guest_pc = 0x00925f80u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t10a;
    // 0x00925f81: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
