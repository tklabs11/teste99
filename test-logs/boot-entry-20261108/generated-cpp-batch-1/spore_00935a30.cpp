#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00935a30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00935a30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0;

    // 0x00935a30: 56 PUSH
        batch_guest_pc = 0x00935a30u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00935a31: 6a37 PUSH
        batch_guest_pc = 0x00935a31u;
        t1a = 0x00000037u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00935a33: 6a00 PUSH
        batch_guest_pc = 0x00935a33u;
        t2a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00935a35: ff15b8c13c01 CALL
        t3_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetProcessHeap", 0x013cc1b8u, 0x00935a3bu);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x00935a3bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00935a3b: 50 PUSH
        batch_guest_pc = 0x00935a3bu;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00935a3c: ff15b4c13c01 CALL
        t5_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!HeapAlloc", 0x013cc1b4u, 0x00935a42u);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x00935a42u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935a42: 8d7013 LEA
        t6 = static_cast<std::uint32_t>(state.regs[0] + 0x00000013u);
        state.regs[6] = t6;
    // 0x00935a45: 83e6f0 AND
        t7a = state.regs[6];
        t7b = 0xfffffff0u;
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
        state.regs[6] = t7r;
    // 0x00935a48: 8946fc MOV
        batch_guest_pc = 0x00935a48u;
        t8 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0xfffffffcu), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00935a4b: 897604 MOV
        batch_guest_pc = 0x00935a4bu;
        t9 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00935a4e: 8936 MOV
        batch_guest_pc = 0x00935a4eu;
        t10 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00935a50: 33c0 XOR
        t11a = state.regs[0];
        t11b = state.regs[0];
        t11r = (t11a ^ t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
        state.regs[0] = t11r;
    // 0x00935a52: 8d4e08 LEA
        t12 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[1] = t12;
    // 0x00935a55: 8701 XCHG
        if (!batch_guest_xchg32(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00935a57: 8d560c LEA
        t14 = static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu);
        state.regs[2] = t14;
    // 0x00935a5a: 52 PUSH
        batch_guest_pc = 0x00935a5au;
        t15a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00935a5b: ff15d0c23c01 CALL
        t16_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!InitializeCriticalSection", 0x013cc2d0u, 0x00935a61u);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00935a61u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935a61: 8bc6 MOV
        t17 = state.regs[6];
        state.regs[0] = t17;
    // 0x00935a63: 5e POP
        batch_guest_pc = 0x00935a63u;
        if (!memory.load32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t18a;
    // 0x00935a64: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
