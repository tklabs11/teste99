#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009268f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009268f0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;

    // 0x009268f0: 8b4c2404 MOV
        batch_guest_pc = 0x009268f0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t0;
    // 0x009268f4: 8b5104 MOV
        batch_guest_pc = 0x009268f4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t1;
    // 0x009268f7: 8bc2 MOV
        t2 = state.regs[2];
        state.regs[0] = t2;
    // 0x009268f9: 25f8ffff7f AND
        t3a = state.regs[0];
        t3b = 0x7ffffff8u;
        t3r = (t3a & t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[0] = t3r;
    // 0x009268fe: 83e809 SUB
        t4a = state.regs[0];
        t4b = 0x00000009u;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
        state.regs[0] = t4r;
    // 0x00926901: 83e0f8 AND
        t5a = state.regs[0];
        t5b = 0xfffffff8u;
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        state.regs[0] = t5r;
    // 0x00926904: 81e207000080 AND
        t6a = state.regs[2];
        t6b = 0x80000007u;
        t6r = (t6a & t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[2] = t6r;
    // 0x0092690a: 0bd0 OR
        t7a = state.regs[2];
        t7b = state.regs[0];
        t7r = (t7a | t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
        state.regs[2] = t7r;
    // 0x0092690c: 895104 MOV
        batch_guest_pc = 0x0092690cu;
        t8 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x0092690f: 8b542408 MOV
        batch_guest_pc = 0x0092690fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00926913: 83ca08 OR
        t10a = state.regs[2];
        t10b = 0x00000008u;
        t10r = (t10a | t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
        state.regs[2] = t10r;
    // 0x00926916: 890408 MOV
        batch_guest_pc = 0x00926916u;
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00926919: 89540804 MOV
        batch_guest_pc = 0x00926919u;
        t12 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000004u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x0092691d: c744080808000000 MOV
        batch_guest_pc = 0x0092691du;
        t13 = 0x00000008u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00926925: c744080c09000000 MOV
        batch_guest_pc = 0x00926925u;
        t14 = 0x00000009u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x0000000cu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0092692d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
