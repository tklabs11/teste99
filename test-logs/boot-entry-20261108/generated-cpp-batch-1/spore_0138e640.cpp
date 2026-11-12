#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00f474d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0138e640(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0138e640u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9a = 0;

    // 0x0138e640: 833d408b6c0100 CMP
        batch_guest_pc = 0x0138e640u;
        if (!memory.load32(0x016c8b40u, t0a)) return BatchLiftStatus::invalid_memory;
        t0b = 0x00000000u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
    // 0x0138e647: 7510 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0138e659;
    // 0x0138e649: e8828ebbff CALL
        if (!batch_guest_call32(memory, state, 0x00f474d0u, 0x0138e64eu)) return BatchLiftStatus::invalid_memory;
        t2_call_status = spore_lift_00f474d0(memory, state);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x0138e64eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0138e64e: c605488b6c0101 MOV
        batch_guest_pc = 0x0138e64eu;
        t3 = 0x00000001u;
        if (!memory.store8(0x016c8b48u, t3)) return BatchLiftStatus::invalid_memory;
    // 0x0138e655: 84c0 TEST
        t4a = state.regs[0] & 0x000000ffu;
        t4b = state.regs[0] & 0x000000ffu;
        t4r = (t4a & t4b) & 0x000000ffu;
        batch_set_logic_flags(state, t4r, 8u);
    // 0x0138e657: 7507 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0138e660;
    // 0x0138e659: c605488b6c0100 MOV
    L_0138e659:
        batch_guest_pc = 0x0138e659u;
        t6 = 0x00000000u;
        if (!memory.store8(0x016c8b48u, t6)) return BatchLiftStatus::invalid_memory;
    // 0x0138e660: 6850993c01 PUSH
    L_0138e660:
        batch_guest_pc = 0x0138e660u;
        t7a = 0x013c9950u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0138e665: e88521e5ff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x0138e66au)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_011e07ef(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x0138e66au) return BatchLiftStatus::invalid_control_flow;
    // 0x0138e66a: 59 POP
        batch_guest_pc = 0x0138e66au;
        if (!memory.load32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t9a;
    // 0x0138e66b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
