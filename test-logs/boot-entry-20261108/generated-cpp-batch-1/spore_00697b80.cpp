#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00923930(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697b80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697b80u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9 = 0;

    // 0x00697b80: 80b99400000000 CMP
        batch_guest_pc = 0x00697b80u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000094u), t0a)) return BatchLiftStatus::invalid_memory;
        t0b = 0x00000000u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0x000000ffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 8u);
    // 0x00697b87: 7413 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697b9c;
    // 0x00697b89: 8b442404 MOV
        batch_guest_pc = 0x00697b89u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00697b8d: 50 PUSH
        batch_guest_pc = 0x00697b8du;
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00697b8e: e89dbd2800 CALL
        if (!batch_guest_call32(memory, state, 0x00923930u, 0x00697b93u)) return BatchLiftStatus::invalid_memory;
        t4_call_status = spore_lift_00923930(memory, state);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x00697b93u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697b93: 84c0 TEST
        t5a = state.regs[0] & 0x000000ffu;
        t5b = state.regs[0] & 0x000000ffu;
        t5r = (t5a & t5b) & 0x000000ffu;
        batch_set_logic_flags(state, t5r, 8u);
    // 0x00697b95: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00697b9c;
    // 0x00697b97: 33c0 XOR
        t7a = state.regs[0];
        t7b = state.regs[0];
        t7r = (t7a ^ t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
        state.regs[0] = t7r;
    // 0x00697b99: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00697b9c: b801000000 MOV
    L_00697b9c:
        t9 = 0x00000001u;
        state.regs[0] = t9;
    // 0x00697ba1: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
