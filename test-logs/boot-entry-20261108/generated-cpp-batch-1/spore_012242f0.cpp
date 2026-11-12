#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401540(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_012242f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012242f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;

    // 0x012242f0: 55 PUSH
        batch_guest_pc = 0x012242f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012242f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012242f3: 83ec24 SUB
        t2a = state.regs[4];
        t2b = 0x00000024u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x012242f6: 56 PUSH
        batch_guest_pc = 0x012242f6u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x012242f7: 57 PUSH
        batch_guest_pc = 0x012242f7u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x012242f8: 8d45dc LEA
        t5 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu);
        state.regs[0] = t5;
    // 0x012242fb: 50 PUSH
        batch_guest_pc = 0x012242fbu;
        t6a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x012242fc: e83fd21dff CALL
        if (!batch_guest_call32(memory, state, 0x00401540u, 0x01224301u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_00401540(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x01224301u) return BatchLiftStatus::invalid_control_flow;
    // 0x01224301: 83c404 ADD
        t8a = state.regs[4];
        t8b = 0x00000004u;
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        state.regs[4] = t8r;
    // 0x01224304: b909000000 MOV
        t9 = 0x00000009u;
        state.regs[1] = t9;
    // 0x01224309: 8d75dc LEA
        t10 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu);
        state.regs[6] = t10;
    // 0x0122430c: bf44275d01 MOV
        t11 = 0x015d2744u;
        state.regs[7] = t11;
    // 0x01224311: f3a5 MOVSD.REP
        if (!batch_guest_rep_movs(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
    // 0x01224313: 5f POP
        batch_guest_pc = 0x01224313u;
        if (!memory.load32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t13a;
    // 0x01224314: 5e POP
        batch_guest_pc = 0x01224314u;
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t14a;
    // 0x01224315: 8be5 MOV
        t15 = state.regs[5];
        state.regs[4] = t15;
    // 0x01224317: 5d POP
        batch_guest_pc = 0x01224317u;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t16a;
    // 0x01224318: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
