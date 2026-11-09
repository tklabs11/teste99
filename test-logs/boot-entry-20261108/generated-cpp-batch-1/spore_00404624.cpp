#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00404651(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083a2f0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00404624(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00404624u);
    std::uint32_t t0 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;

    // 0x00404624: 668b8a00000000 MOV
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffff0000u) | ((t0 << 0u) & 0x0000ffffu);
    // 0x0040462b: e921000000 JMP
        state.eip = 0x00404651u;
        return state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_tail_call(memory, state, 0x00404651u);
    // 0x00404630: 55 PUSH
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00404631: 8bec MOV
        t3 = state.regs[4];
        state.regs[5] = t3;
    // 0x00404633: 51 PUSH
        t4a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00404634: 894dfc MOV
        t5 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t5)) return BatchLiftStatus::invalid_memory;
    // 0x00404637: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x0040463a: 50 PUSH
        t7a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0040463b: 683cb83e01 PUSH
        t8a = 0x013eb83cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00404640: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t9;
    // 0x00404643: 83c114 ADD
        t10a = state.regs[1];
        t10b = 0x00000014u;
        t10r = static_cast<std::uint32_t>(t10a + t10b) & 0xffffffffu;
        batch_set_add_flags(state, t10a, t10b, t10r, 32u);
        state.regs[1] = t10r;
    // 0x00404646: e8a55c4300 CALL
        t11_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0083a2f0u, 0x0040464bu);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x0040464bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0040464b: 8be5 MOV
        t12 = state.regs[5];
        state.regs[4] = t12;
    // 0x0040464d: 5d POP
        if (!memory.load32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t13a;
    // 0x0040464e: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
