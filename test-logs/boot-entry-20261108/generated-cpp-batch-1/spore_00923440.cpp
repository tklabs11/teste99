#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00923440(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923440u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3a = 0, t3r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    BatchLiftStatus t9_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;

    // 0x00923440: 8b4104 MOV
        batch_guest_pc = 0x00923440u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00923443: 83f801 CMP
        t1a = state.regs[0];
        t1b = 0x00000001u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
    // 0x00923446: 7e05 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0092344d;
    // 0x00923448: 48 DEC
        t3a = state.regs[0];
        t3r = static_cast<std::uint32_t>(t3a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t3a, t3r, 32u);
        state.regs[0] = t3r;
    // 0x00923449: 894104 MOV
        batch_guest_pc = 0x00923449u;
        t4 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x0092344c: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092344d: 8b01 MOV
    L_0092344d:
        batch_guest_pc = 0x0092344du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x0092344f: 8b5008 MOV
        batch_guest_pc = 0x0092344fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t7;
    // 0x00923452: 6a01 PUSH
        batch_guest_pc = 0x00923452u;
        t8a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00923454: ffd2 CALL
        t9_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00923456u);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
    // 0x00923456: 33c0 XOR
        t10a = state.regs[0];
        t10b = state.regs[0];
        t10r = (t10a ^ t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
        state.regs[0] = t10r;
    // 0x00923458: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
