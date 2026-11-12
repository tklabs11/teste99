#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00923aa0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923aa0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;

    // 0x00923aa0: 8b4908 MOV
        batch_guest_pc = 0x00923aa0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t0;
    // 0x00923aa3: 8b01 MOV
        batch_guest_pc = 0x00923aa3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00923aa5: 8b542404 MOV
        batch_guest_pc = 0x00923aa5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x00923aa9: 8b4010 MOV
        batch_guest_pc = 0x00923aa9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00923aac: 52 PUSH
        batch_guest_pc = 0x00923aacu;
        t4a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00923aad: ffd0 CALL
        t5_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00923aafu);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
    // 0x00923aaf: 50 PUSH
        batch_guest_pc = 0x00923aafu;
        t6a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ab0: ff1564c13c01 CALL
        t7_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!OutputDebugStringA", 0x013cc164u, 0x00923ab6u);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00923ab6u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923ab6: 33c0 XOR
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8r = (t8a ^ t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[0] = t8r;
    // 0x00923ab8: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
