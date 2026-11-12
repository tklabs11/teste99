#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0091a530(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924cf0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923db0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923db0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;

    // 0x00923db0: 83e904 SUB
        t0a = state.regs[1];
        t0b = 0x00000004u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[1] = t0r;
    // 0x00923db3: e9380f0000 JMP
        state.eip = 0x00924cf0u;
        return spore_lift_00924cf0(memory, state);
    // 0x00923db8: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00923db9: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00923dba: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00923dbb: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00923dbc: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00923dbd: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00923dbe: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00923dbf: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00923dc0: 8b4c2408 MOV
        batch_guest_pc = 0x00923dc0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t10;
    // 0x00923dc4: 56 PUSH
        batch_guest_pc = 0x00923dc4u;
        t11a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00923dc5: 8b742408 MOV
        batch_guest_pc = 0x00923dc5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t12;
    // 0x00923dc9: 8d442410 LEA
        t13 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t13;
    // 0x00923dcd: 50 PUSH
        batch_guest_pc = 0x00923dcdu;
        t14a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00923dce: 51 PUSH
        batch_guest_pc = 0x00923dceu;
        t15a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00923dcf: 8bce MOV
        t16 = state.regs[6];
        state.regs[1] = t16;
    // 0x00923dd1: e85a67ffff CALL
        if (!batch_guest_call32(memory, state, 0x0091a530u, 0x00923dd6u)) return BatchLiftStatus::invalid_memory;
        t17_call_status = spore_lift_0091a530(memory, state);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
        if (state.eip != 0x00923dd6u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923dd6: 8bc6 MOV
        t18 = state.regs[6];
        state.regs[0] = t18;
    // 0x00923dd8: 5e POP
        batch_guest_pc = 0x00923dd8u;
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t19a;
    // 0x00923dd9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
