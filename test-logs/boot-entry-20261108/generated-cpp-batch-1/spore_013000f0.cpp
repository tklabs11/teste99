#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_013000f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x013000f0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3 = 0;

    // 0x013000f0: 833d38df5401ff CMP
        if (!memory.load32(0x0154df38u, t0a)) return BatchLiftStatus::invalid_memory;
        t0b = 0xffffffffu;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
    // 0x013000f7: 750b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_01300104;
    // 0x013000f9: ff156cc13c01 CALL
        t2_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!TlsAlloc", 0x013cc16cu, 0x013000ffu);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x013000ffu) return BatchLiftStatus::invalid_control_flow;
    // 0x013000ff: a338df5401 MOV
        t3 = state.regs[0];
        if (!memory.store32(0x0154df38u, t3)) return BatchLiftStatus::invalid_memory;
    // 0x01300104: c3 RET
    L_01300104:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
