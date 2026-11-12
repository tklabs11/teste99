#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00939d40(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_01300310(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01300310u);
    std::uint32_t t12a = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14a = 0;

    // 0x01300310: e92b9a63ff JMP
        state.eip = 0x00939d40u;
        return spore_lift_00939d40(memory, state);
    // 0x01300315: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x01300316: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x01300317: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x01300318: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x01300319: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0130031a: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0130031b: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0130031c: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0130031d: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0130031e: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0130031f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x01300320: 68800f3c01 PUSH
        batch_guest_pc = 0x01300320u;
        t12a = 0x013c0f80u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x01300325: e8c504eeff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x0130032au)) return BatchLiftStatus::invalid_memory;
        t13_call_status = spore_lift_011e07ef(memory, state);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x0130032au) return BatchLiftStatus::invalid_control_flow;
    // 0x0130032a: 59 POP
        batch_guest_pc = 0x0130032au;
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t14a;
    // 0x0130032b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
