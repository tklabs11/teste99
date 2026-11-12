#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009267f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009269d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009269e3(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00926960(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926960u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15a = 0, t15c = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t20a = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0, t48c = 0, t48r = 0;
    std::uint32_t t49a = 0, t49c = 0, t49r = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0;

    // 0x00926960: 807c240c00 CMP
        batch_guest_pc = 0x00926960u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t0a)) return BatchLiftStatus::invalid_memory;
        t0b = 0x00000000u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0x000000ffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 8u);
    // 0x00926965: 53 PUSH
        batch_guest_pc = 0x00926965u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00926966: 55 PUSH
        batch_guest_pc = 0x00926966u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00926967: 8b6c240c MOV
        batch_guest_pc = 0x00926967u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t3;
    // 0x0092696b: 56 PUSH
        batch_guest_pc = 0x0092696bu;
        t4a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0092696c: 57 PUSH
        batch_guest_pc = 0x0092696cu;
        t5a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092696d: 8bd9 MOV
        t6 = state.regs[1];
        state.regs[3] = t6;
    // 0x0092696f: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092697d;
    // 0x00926971: 8b4508 MOV
        batch_guest_pc = 0x00926971u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00926974: 8d4b30 LEA
        t9 = static_cast<std::uint32_t>(state.regs[3] + 0x00000030u);
        state.regs[1] = t9;
    // 0x00926977: 894108 MOV
        batch_guest_pc = 0x00926977u;
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x0092697a: 89480c MOV
        batch_guest_pc = 0x0092697au;
        t11 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x0092697d: 8b7c2418 MOV
    L_0092697d:
        batch_guest_pc = 0x0092697du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t12;
    // 0x00926981: 81ff00020000 CMP
        t13a = state.regs[7];
        t13b = 0x00000200u;
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x00926987: 730f JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926998;
    // 0x00926989: c1ef03 SHR
        t15a = state.regs[7];
        t15c = 3u;
        if (t15c != 0u) {
        t15r = static_cast<std::uint32_t>(t15a >> t15c);
        batch_set_shr_flags(state, t15a, t15c, t15r, 32u);
            state.regs[7] = t15r;
        }
    // 0x0092698c: 8bc7 MOV
        t16 = state.regs[7];
        state.regs[0] = t16;
    // 0x0092698e: 8b54c334 MOV
        batch_guest_pc = 0x0092698eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + state.regs[0] * 8u + 0x00000034u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x00926992: 8d74c328 LEA
        t18 = static_cast<std::uint32_t>(state.regs[3] + state.regs[0] * 8u + 0x00000028u);
        state.regs[6] = t18;
    // 0x00926996: eb4b JMP
        goto L_009269e3;
    // 0x00926998: 57 PUSH
    L_00926998:
        batch_guest_pc = 0x00926998u;
        t20a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00926999: e852feffff CALL
        if (!batch_guest_call32(memory, state, 0x009267f0u, 0x0092699eu)) return BatchLiftStatus::invalid_memory;
        t21_call_status = spore_lift_009267f0(memory, state);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x0092699eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092699e: 8b54c334 MOV
        batch_guest_pc = 0x0092699eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + state.regs[0] * 8u + 0x00000034u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x009269a2: 8d74c328 LEA
        t23 = static_cast<std::uint32_t>(state.regs[3] + state.regs[0] * 8u + 0x00000028u);
        state.regs[6] = t23;
    // 0x009269a6: 83c404 ADD
        t24a = state.regs[4];
        t24b = 0x00000004u;
        t24r = static_cast<std::uint32_t>(t24a + t24b) & 0xffffffffu;
        batch_set_add_flags(state, t24a, t24b, t24r, 32u);
        state.regs[4] = t24r;
    // 0x009269a9: 3bf2 CMP
        t25a = state.regs[6];
        t25b = state.regs[2];
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
    // 0x009269ab: 7436 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009269e3;
    // 0x009269ad: 8b4e08 MOV
        batch_guest_pc = 0x009269adu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t27;
    // 0x009269b0: 3b7904 CMP
        batch_guest_pc = 0x009269b0u;
        t28a = state.regs[7];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t28b)) return BatchLiftStatus::invalid_memory;
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x009269b3: 7306 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_009269bb;
    // 0x009269b5: 8bd6 MOV
        t30 = state.regs[6];
        state.regs[2] = t30;
    // 0x009269b7: 8bf1 MOV
        t31 = state.regs[1];
        state.regs[6] = t31;
    // 0x009269b9: eb28 JMP
        goto L_009269e3;
    // 0x009269bb: 8b4a04 MOV
    L_009269bb:
        batch_guest_pc = 0x009269bbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x009269be: 81e1f8ffff7f AND
        t34a = state.regs[1];
        t34b = 0x7ffffff8u;
        t34r = (t34a & t34b) & 0xffffffffu;
        batch_set_logic_flags(state, t34r, 32u);
        state.regs[1] = t34r;
    // 0x009269c4: 3bf9 CMP
        t35a = state.regs[7];
        t35b = state.regs[1];
        t35r = static_cast<std::uint32_t>(t35a - t35b) & 0xffffffffu;
        batch_set_sub_flags(state, t35a, t35b, t35r, 32u);
    // 0x009269c6: 7318 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_009269e0;
    // 0x009269c8: eb06 JMP
        goto L_009269d0;
    // 0x009269d0: 8b520c MOV
    L_009269d0:
        batch_guest_pc = 0x009269d0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t38;
    // 0x009269d3: 8b4a04 MOV
        batch_guest_pc = 0x009269d3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t39;
    // 0x009269d6: 81e1f8ffff7f AND
        t40a = state.regs[1];
        t40b = 0x7ffffff8u;
        t40r = (t40a & t40b) & 0xffffffffu;
        batch_set_logic_flags(state, t40r, 32u);
        state.regs[1] = t40r;
    // 0x009269dc: 3bf9 CMP
        t41a = state.regs[7];
        t41b = state.regs[1];
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
    // 0x009269de: 72f0 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_009269d0;
    // 0x009269e0: 8b7208 MOV
    L_009269e0:
        batch_guest_pc = 0x009269e0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t43;
    // 0x009269e3: 8bc8 MOV
    L_009269e3:
        t44 = state.regs[0];
        state.regs[1] = t44;
    // 0x009269e5: 8bf8 MOV
        t45 = state.regs[0];
        state.regs[7] = t45;
    // 0x009269e7: 83e11f AND
        t46a = state.regs[1];
        t46b = 0x0000001fu;
        t46r = (t46a & t46b) & 0xffffffffu;
        batch_set_logic_flags(state, t46r, 32u);
        state.regs[1] = t46r;
    // 0x009269ea: b801000000 MOV
        t47 = 0x00000001u;
        state.regs[0] = t47;
    // 0x009269ef: d3e0 SHL
        t48a = state.regs[0];
        t48c = (state.regs[1] & 0x1fu);
        if (t48c != 0u) {
        t48r = static_cast<std::uint32_t>(t48a << t48c) & 0xffffffffu;
        batch_set_shl_flags(state, t48a, t48c, t48r, 32u);
            state.regs[0] = t48r;
        }
    // 0x009269f1: c1ff05 SAR
        t49a = state.regs[7];
        t49c = 5u;
        if (t49c != 0u) {
        t49r = (t49a >> t49c) | ((t49a & 0x80000000u) ? (0xffffffffu << (32u - t49c)) : 0u);
        batch_set_sar_flags(state, t49a, t49c, t49r, 32u);
            state.regs[7] = t49r;
        }
    // 0x009269f4: 0984bb30040000 OR
        batch_guest_pc = 0x009269f4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + state.regs[7] * 4u + 0x00000430u), t50a)) return BatchLiftStatus::invalid_memory;
        t50b = state.regs[0];
        t50r = (t50a | t50b) & 0xffffffffu;
        batch_set_logic_flags(state, t50r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + state.regs[7] * 4u + 0x00000430u), t50r)) return BatchLiftStatus::invalid_memory;
    // 0x009269fb: 897508 MOV
        batch_guest_pc = 0x009269fbu;
        t51 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x009269fe: 89550c MOV
        batch_guest_pc = 0x009269feu;
        t52 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00926a01: 5f POP
        batch_guest_pc = 0x00926a01u;
        if (!memory.load32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t53a;
    // 0x00926a02: 896a08 MOV
        batch_guest_pc = 0x00926a02u;
        t54 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t54)) return BatchLiftStatus::invalid_memory;
    // 0x00926a05: 896e0c MOV
        batch_guest_pc = 0x00926a05u;
        t55 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t55)) return BatchLiftStatus::invalid_memory;
    // 0x00926a08: 5e POP
        batch_guest_pc = 0x00926a08u;
        if (!memory.load32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t56a;
    // 0x00926a09: 5d POP
        batch_guest_pc = 0x00926a09u;
        if (!memory.load32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t57a;
    // 0x00926a0a: 5b POP
        batch_guest_pc = 0x00926a0au;
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t58a;
    // 0x00926a0b: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
