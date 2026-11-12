#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00939e4f(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00939ea5(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e0846(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00939d40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00939d40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27 = 0;
    BatchLiftStatus t28_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t75a = 0;
    BatchLiftStatus t76_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t77 = 0;
    std::uint32_t t78a = 0, t78b = 0, t78r = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81a = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    BatchLiftStatus t84_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t85 = 0;
    std::uint32_t t86a = 0;
    BatchLiftStatus t87_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95a = 0, t95r = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t101a = 0;
    std::uint32_t t102a = 0;
    BatchLiftStatus t103_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t104 = 0;
    std::uint32_t t105a = 0;
    BatchLiftStatus t106_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t108 = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112a = 0, t112b = 0, t112c = 0, t112r = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115a = 0, t115b = 0, t115r = 0;
    std::uint32_t t116a = 0, t116b = 0, t116r = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121 = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126a = 0, t126b = 0, t126r = 0;
    std::uint32_t t128a = 0, t128b = 0, t128r = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t132 = 0;
    std::uint32_t t133 = 0;
    std::uint32_t t141a = 0, t141b = 0, t141r = 0;
    std::uint32_t t142a = 0, t142b = 0, t142c = 0, t142r = 0;
    std::uint32_t t143 = 0;
    std::uint32_t t144 = 0;
    std::uint32_t t145a = 0, t145b = 0, t145r = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t148a = 0, t148b = 0, t148r = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150 = 0;
    BatchLiftStatus t155_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t156 = 0;
    std::uint32_t t157 = 0;
    std::uint32_t t158 = 0;
    std::uint32_t t159 = 0;
    std::uint32_t t160a = 0;
    BatchLiftStatus t161_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t162 = 0;
    std::uint32_t t163a = 0;
    std::uint32_t t164a = 0;
    BatchLiftStatus t165_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t166 = 0;
    std::uint32_t t167a = 0;
    std::uint32_t t168a = 0;
    BatchLiftStatus t169_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t175a = 0, t175b = 0, t175r = 0;
    std::uint32_t t176a = 0, t176b = 0, t176r = 0;
    std::uint32_t t177 = 0;
    std::uint32_t t181a = 0;
    std::uint32_t t184a = 0;
    std::uint32_t t186a = 0;
    std::uint32_t t187a = 0;
    std::uint32_t t206 = 0;
    std::uint32_t t207a = 0;
    BatchLiftStatus t208_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t209 = 0;
    std::uint32_t t210a = 0;
    BatchLiftStatus t211_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t212 = 0;
    std::uint32_t t213a = 0, t213b = 0, t213r = 0;
    std::uint32_t t214 = 0;
    std::uint32_t t215a = 0, t215b = 0, t215c = 0, t215r = 0;
    std::uint32_t t216a = 0, t216b = 0, t216r = 0;
    std::uint32_t t219a = 0, t219b = 0, t219r = 0;
    std::uint32_t t221 = 0;
    std::uint32_t t222 = 0;
    std::uint32_t t223a = 0, t223b = 0, t223r = 0;
    std::uint32_t t230 = 0;
    std::uint32_t t231a = 0, t231b = 0, t231r = 0;
    std::uint32_t t232 = 0;
    std::uint32_t t233a = 0, t233b = 0, t233r = 0;
    std::uint32_t t234 = 0;
    std::uint32_t t238a = 0;
    std::uint32_t t241a = 0;
    std::uint32_t t243a = 0;
    std::uint32_t t244a = 0;
    std::uint32_t t264 = 0;
    std::uint32_t t265 = 0;
    std::uint32_t t267a = 0, t267b = 0, t267r = 0;
    std::uint32_t t268a = 0, t268b = 0, t268c = 0, t268r = 0;
    std::uint32_t t269a = 0, t269b = 0, t269r = 0;
    std::uint32_t t272a = 0, t272b = 0, t272r = 0;
    std::uint32_t t274 = 0;
    std::uint32_t t275 = 0;
    std::uint32_t t276a = 0, t276b = 0, t276r = 0;
    std::uint32_t t278 = 0;
    std::uint32_t t279 = 0;
    std::uint32_t t280a = 0;
    std::uint32_t t281a = 0;
    std::uint32_t t282a = 0;
    std::uint32_t t283a = 0;
    std::uint32_t t284 = 0;
    std::uint32_t t285a = 0;

    // 0x00939d40: 55 PUSH
        batch_guest_pc = 0x00939d40u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00939d41: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00939d43: 83e4f8 AND
        t2a = state.regs[4];
        t2b = 0xfffffff8u;
        t2r = (t2a & t2b) & 0xffffffffu;
        batch_set_logic_flags(state, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00939d46: 83ec50 SUB
        t3a = state.regs[4];
        t3b = 0x00000050u;
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
        state.regs[4] = t3r;
    // 0x00939d49: 53 PUSH
        batch_guest_pc = 0x00939d49u;
        t4a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00939d4a: 55 PUSH
        batch_guest_pc = 0x00939d4au;
        t5a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00939d4b: 56 PUSH
        batch_guest_pc = 0x00939d4bu;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00939d4c: 33f6 XOR
        t7a = state.regs[6];
        t7b = state.regs[6];
        t7r = (t7a ^ t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
        state.regs[6] = t7r;
    // 0x00939d4e: 57 PUSH
        batch_guest_pc = 0x00939d4eu;
        t8a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00939d4f: 3935ecea5401 CMP
        batch_guest_pc = 0x00939d4fu;
        if (!memory.load32(0x0154eaecu, t9a)) return BatchLiftStatus::invalid_memory;
        t9b = state.regs[6];
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x00939d55: 0f8731040000 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0093a18c;
    // 0x00939d5b: 720d JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00939d6a;
    // 0x00939d5d: 833de8ea540101 CMP
        batch_guest_pc = 0x00939d5du;
        if (!memory.load32(0x0154eae8u, t12a)) return BatchLiftStatus::invalid_memory;
        t12b = 0x00000001u;
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x00939d64: 0f8722040000 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0093a18c;
    // 0x00939d6a: ff15e4c23c01 CALL
    L_00939d6a:
        t14_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetCurrentProcess", 0x013cc2e4u, 0x00939d70u);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x00939d70u) return BatchLiftStatus::invalid_control_flow;
    // 0x00939d70: 8bf8 MOV
        t15 = state.regs[0];
        state.regs[7] = t15;
    // 0x00939d72: 57 PUSH
        batch_guest_pc = 0x00939d72u;
        t16a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00939d73: 897c241c MOV
        batch_guest_pc = 0x00939d73u;
        t17 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00939d77: ff15a8c03c01 CALL
        t18_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetPriorityClass", 0x013cc0a8u, 0x00939d7du);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00939d7du) return BatchLiftStatus::invalid_control_flow;
    // 0x00939d7d: 89442420 MOV
        batch_guest_pc = 0x00939d7du;
        t19 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00939d81: ff15b0c03c01 CALL
        t20_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetCurrentThread", 0x013cc0b0u, 0x00939d87u);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x00939d87u) return BatchLiftStatus::invalid_control_flow;
    // 0x00939d87: 8be8 MOV
        t21 = state.regs[0];
        state.regs[5] = t21;
    // 0x00939d89: 55 PUSH
        batch_guest_pc = 0x00939d89u;
        t22a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00939d8a: 896c2420 MOV
        batch_guest_pc = 0x00939d8au;
        t23 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00939d8e: ff15acc03c01 CALL
        t24_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetThreadPriority", 0x013cc0acu, 0x00939d94u);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x00939d94u) return BatchLiftStatus::invalid_control_flow;
    // 0x00939d94: 6800010000 PUSH
        batch_guest_pc = 0x00939d94u;
        t25a = 0x00000100u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00939d99: 57 PUSH
        batch_guest_pc = 0x00939d99u;
        t26a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00939d9a: 8944242c MOV
        batch_guest_pc = 0x00939d9au;
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00939d9e: ff15a4c03c01 CALL
        t28_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!SetPriorityClass", 0x013cc0a4u, 0x00939da4u);
        if (t28_call_status != BatchLiftStatus::returned) return t28_call_status;
        if (state.eip != 0x00939da4u) return BatchLiftStatus::invalid_control_flow;
    // 0x00939da4: 6a0f PUSH
        batch_guest_pc = 0x00939da4u;
        t29a = 0x0000000fu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00939da6: 55 PUSH
        batch_guest_pc = 0x00939da6u;
        t30a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x00939da7: ff15a0c03c01 CALL
        t31_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!SetThreadPriority", 0x013cc0a0u, 0x00939dadu);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
        if (state.eip != 0x00939dadu) return BatchLiftStatus::invalid_control_flow;
    // 0x00939dad: 8b1db8c23c01 MOV
        batch_guest_pc = 0x00939dadu;
        if (!memory.load32(0x013cc2b8u, t32)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t32;
    // 0x00939db3: 8935f0ea5401 MOV
        batch_guest_pc = 0x00939db3u;
        t33 = state.regs[6];
        if (!memory.store32(0x0154eaf0u, t33)) return BatchLiftStatus::invalid_memory;
    // 0x00939db9: 8935f4ea5401 MOV
        batch_guest_pc = 0x00939db9u;
        t34 = state.regs[6];
        if (!memory.store32(0x0154eaf4u, t34)) return BatchLiftStatus::invalid_memory;
    // 0x00939dbf: 89742410 MOV
        batch_guest_pc = 0x00939dbfu;
        t35 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x00939dc3: 8d442430 LEA
    L_00939dc3:
        t36 = static_cast<std::uint32_t>(state.regs[4] + 0x00000030u);
        state.regs[0] = t36;
    // 0x00939dc7: 50 PUSH
        batch_guest_pc = 0x00939dc7u;
        t37a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00939dc8: ffd3 CALL
        t38_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[3], 0x00939dcau);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
    // 0x00939dca: 0f31 RDTSC
        if (!batch_guest_rdtsc(state)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939dcc: 89442438 MOV
        batch_guest_pc = 0x00939dccu;
        t40 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00939dd0: 8bc2 MOV
        t41 = state.regs[2];
        state.regs[0] = t41;
    // 0x00939dd2: 8bca MOV
        t42 = state.regs[2];
        state.regs[1] = t42;
    // 0x00939dd4: 25ffffff7f AND
        t43a = state.regs[0];
        t43b = 0x7fffffffu;
        t43r = (t43a & t43b) & 0xffffffffu;
        batch_set_logic_flags(state, t43r, 32u);
        state.regs[0] = t43r;
    // 0x00939dd9: 81e100000080 AND
        t44a = state.regs[1];
        t44b = 0x80000000u;
        t44r = (t44a & t44b) & 0xffffffffu;
        batch_set_logic_flags(state, t44r, 32u);
        state.regs[1] = t44r;
    // 0x00939ddf: 8944243c MOV
        batch_guest_pc = 0x00939ddfu;
        t45 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t45)) return BatchLiftStatus::invalid_memory;
    // 0x00939de3: df6c2438 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000038u))) return BatchLiftStatus::invalid_memory;
    // 0x00939de7: 8b442434 MOV
        batch_guest_pc = 0x00939de7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t47;
    // 0x00939deb: 894c242c MOV
        batch_guest_pc = 0x00939debu;
        t48 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00939def: 8b4c2430 MOV
        batch_guest_pc = 0x00939defu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t49;
    // 0x00939df3: 89742428 MOV
        batch_guest_pc = 0x00939df3u;
        t50 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00939df7: df6c2428 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000028u))) return BatchLiftStatus::invalid_memory;
    // 0x00939dfb: 894c2440 MOV
        batch_guest_pc = 0x00939dfbu;
        t52 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00939dff: 8bc8 MOV
        t53 = state.regs[0];
        state.regs[1] = t53;
    // 0x00939e01: d9e0 FCHS
        if (!batch_guest_x87_chs(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e03: 25ffffff7f AND
        t55a = state.regs[0];
        t55b = 0x7fffffffu;
        t55r = (t55a & t55b) & 0xffffffffu;
        batch_set_logic_flags(state, t55r, 32u);
        state.regs[0] = t55r;
    // 0x00939e08: dec1 FADDP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 0u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e0a: 81e100000080 AND
        t57a = state.regs[1];
        t57b = 0x80000000u;
        t57r = (t57a & t57b) & 0xffffffffu;
        batch_set_logic_flags(state, t57r, 32u);
        state.regs[1] = t57r;
    // 0x00939e10: 89442444 MOV
        batch_guest_pc = 0x00939e10u;
        t58 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x00939e14: df6c2440 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000040u))) return BatchLiftStatus::invalid_memory;
    // 0x00939e18: 894c244c MOV
        batch_guest_pc = 0x00939e18u;
        t60 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t60)) return BatchLiftStatus::invalid_memory;
    // 0x00939e1c: 89742448 MOV
        batch_guest_pc = 0x00939e1cu;
        t61 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t61)) return BatchLiftStatus::invalid_memory;
    // 0x00939e20: df6c2448 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000048u))) return BatchLiftStatus::invalid_memory;
    // 0x00939e24: d9e0 FCHS
        if (!batch_guest_x87_chs(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e26: dec1 FADDP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 0u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e28: def9 FDIVP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 2u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e2a: dd0590ea4301 FLD
        if (!batch_guest_fld64(memory, state, 0x0143ea90u)) return BatchLiftStatus::invalid_memory;
    // 0x00939e30: d9c9 FXCH
        if (!batch_guest_x87_fxch(state, 1u)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e32: dbf1 FCOMI
        if (!batch_guest_x87_compare_stack(state, 1u, 0u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e34: ddd9 FSTP
        if (!batch_guest_fstp_stack(state, 1u)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e36: 7655 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00939e8d;
    // 0x00939e38: dd0588ea4301 FLD
        if (!batch_guest_fld64(memory, state, 0x0143ea88u)) return BatchLiftStatus::invalid_memory;
    // 0x00939e3e: dff1 FCOMIP
        if (!batch_guest_x87_compare_stack(state, 1u, 1u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e40: ddd8 FSTP
        if (!batch_guest_fstp_stack(state, 0u)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e42: 764b JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00939e8f;
    // 0x00939e44: 68f0ea5401 PUSH
        batch_guest_pc = 0x00939e44u;
        t75a = 0x0154eaf0u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t75a)) return BatchLiftStatus::invalid_memory;
    // 0x00939e49: ff159cc03c01 CALL
        t76_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!QueryPerformanceFrequency", 0x013cc09cu, 0x00939e4fu);
        if (t76_call_status != BatchLiftStatus::returned) return t76_call_status;
        if (state.eip != 0x00939e4fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00939e4f: 8b15f0ea5401 MOV
    L_00939e4f:
        batch_guest_pc = 0x00939e4fu;
        if (!memory.load32(0x0154eaf0u, t77)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t77;
    // 0x00939e55: 0b15f4ea5401 OR
        batch_guest_pc = 0x00939e55u;
        t78a = state.regs[2];
        if (!memory.load32(0x0154eaf4u, t78b)) return BatchLiftStatus::invalid_memory;
        t78r = (t78a | t78b) & 0xffffffffu;
        batch_set_logic_flags(state, t78r, 32u);
        state.regs[2] = t78r;
    // 0x00939e5b: 0f851a010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00939f7b;
    // 0x00939e61: 8d442430 LEA
        t80 = static_cast<std::uint32_t>(state.regs[4] + 0x00000030u);
        state.regs[0] = t80;
    // 0x00939e65: 50 PUSH
        batch_guest_pc = 0x00939e65u;
        t81a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t81a)) return BatchLiftStatus::invalid_memory;
    // 0x00939e66: 8974245c MOV
        batch_guest_pc = 0x00939e66u;
        t82 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000005cu), t82)) return BatchLiftStatus::invalid_memory;
    // 0x00939e6a: 89742460 MOV
        batch_guest_pc = 0x00939e6au;
        t83 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000060u), t83)) return BatchLiftStatus::invalid_memory;
    // 0x00939e6e: ff159cc03c01 CALL
        t84_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!QueryPerformanceFrequency", 0x013cc09cu, 0x00939e74u);
        if (t84_call_status != BatchLiftStatus::returned) return t84_call_status;
        if (state.eip != 0x00939e74u) return BatchLiftStatus::invalid_control_flow;
    // 0x00939e74: 8d4c2428 LEA
        t85 = static_cast<std::uint32_t>(state.regs[4] + 0x00000028u);
        state.regs[1] = t85;
    // 0x00939e78: 51 PUSH
        batch_guest_pc = 0x00939e78u;
        t86a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t86a)) return BatchLiftStatus::invalid_memory;
    // 0x00939e79: ffd3 CALL
        t87_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[3], 0x00939e7bu);
        if (t87_call_status != BatchLiftStatus::returned) return t87_call_status;
    // 0x00939e7b: 0f31 RDTSC
        if (!batch_guest_rdtsc(state)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939e7d: 8b2d7cc13c01 MOV
        batch_guest_pc = 0x00939e7du;
        if (!memory.load32(0x013cc17cu, t89)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t89;
    // 0x00939e83: 8954243c MOV
        batch_guest_pc = 0x00939e83u;
        t90 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t90)) return BatchLiftStatus::invalid_memory;
    // 0x00939e87: 89442438 MOV
        batch_guest_pc = 0x00939e87u;
        t91 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t91)) return BatchLiftStatus::invalid_memory;
    // 0x00939e8b: eb18 JMP
        goto L_00939ea5;
    // 0x00939e8d: ddd8 FSTP
    L_00939e8d:
        if (!batch_guest_fstp_stack(state, 0u)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939e8f: 8b442410 MOV
    L_00939e8f:
        batch_guest_pc = 0x00939e8fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t94)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t94;
    // 0x00939e93: 40 INC
        t95a = state.regs[0];
        t95r = static_cast<std::uint32_t>(t95a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t95a, t95r, 32u);
        state.regs[0] = t95r;
    // 0x00939e94: 83f805 CMP
        t96a = state.regs[0];
        t96b = 0x00000005u;
        t96r = static_cast<std::uint32_t>(t96a - t96b) & 0xffffffffu;
        batch_set_sub_flags(state, t96a, t96b, t96r, 32u);
    // 0x00939e97: 89442410 MOV
        batch_guest_pc = 0x00939e97u;
        t97 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t97)) return BatchLiftStatus::invalid_memory;
    // 0x00939e9b: 0f8c22ffffff JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00939dc3;
    // 0x00939ea1: ebac JMP
        goto L_00939e4f;
    // 0x00939ea3: ddd8 FSTP
    L_00939ea3:
        if (!batch_guest_fstp_stack(state, 0u)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939ea5: 6a01 PUSH
    L_00939ea5:
        batch_guest_pc = 0x00939ea5u;
        t101a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t101a)) return BatchLiftStatus::invalid_memory;
    // 0x00939ea7: 6a32 PUSH
        batch_guest_pc = 0x00939ea7u;
        t102a = 0x00000032u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t102a)) return BatchLiftStatus::invalid_memory;
    // 0x00939ea9: ffd5 CALL
        t103_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[5], 0x00939eabu);
        if (t103_call_status != BatchLiftStatus::returned) return t103_call_status;
    // 0x00939eab: 8d542410 LEA
        t104 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[2] = t104;
    // 0x00939eaf: 52 PUSH
        batch_guest_pc = 0x00939eafu;
        t105a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
    // 0x00939eb0: ffd3 CALL
        t106_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[3], 0x00939eb2u);
        if (t106_call_status != BatchLiftStatus::returned) return t106_call_status;
    // 0x00939eb2: 0f31 RDTSC
        if (!batch_guest_rdtsc(state)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939eb4: 8b7c2410 MOV
        batch_guest_pc = 0x00939eb4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t108)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t108;
    // 0x00939eb8: 2b7c2428 SUB
        batch_guest_pc = 0x00939eb8u;
        t109a = state.regs[7];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t109b)) return BatchLiftStatus::invalid_memory;
        t109r = static_cast<std::uint32_t>(t109a - t109b) & 0xffffffffu;
        batch_set_sub_flags(state, t109a, t109b, t109r, 32u);
        state.regs[7] = t109r;
    // 0x00939ebc: 8bc8 MOV
        t110 = state.regs[0];
        state.regs[1] = t110;
    // 0x00939ebe: 8b442414 MOV
        batch_guest_pc = 0x00939ebeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t111)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t111;
    // 0x00939ec2: 1b44242c SBB
        batch_guest_pc = 0x00939ec2u;
        t112a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t112b)) return BatchLiftStatus::invalid_memory;
        t112c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t112r = static_cast<std::uint32_t>(t112a - t112b - t112c) & 0xffffffffu;
        batch_set_sbb_flags(state, t112a, t112b, t112c, t112r, 32u);
        state.regs[0] = t112r;
    // 0x00939ec6: 897c2448 MOV
        batch_guest_pc = 0x00939ec6u;
        t113 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t113)) return BatchLiftStatus::invalid_memory;
    // 0x00939eca: 8bf8 MOV
        t114 = state.regs[0];
        state.regs[7] = t114;
    // 0x00939ecc: 25ffffff7f AND
        t115a = state.regs[0];
        t115b = 0x7fffffffu;
        t115r = (t115a & t115b) & 0xffffffffu;
        batch_set_logic_flags(state, t115r, 32u);
        state.regs[0] = t115r;
    // 0x00939ed1: 81e700000080 AND
        t116a = state.regs[7];
        t116b = 0x80000000u;
        t116r = (t116a & t116b) & 0xffffffffu;
        batch_set_logic_flags(state, t116r, 32u);
        state.regs[7] = t116r;
    // 0x00939ed7: 8944244c MOV
        batch_guest_pc = 0x00939ed7u;
        t117 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t117)) return BatchLiftStatus::invalid_memory;
    // 0x00939edb: df6c2448 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000048u))) return BatchLiftStatus::invalid_memory;
    // 0x00939edf: 8b442434 MOV
        batch_guest_pc = 0x00939edfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t119)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t119;
    // 0x00939ee3: 897c2444 MOV
        batch_guest_pc = 0x00939ee3u;
        t120 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t120)) return BatchLiftStatus::invalid_memory;
    // 0x00939ee7: 8b7c2430 MOV
        batch_guest_pc = 0x00939ee7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t121)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t121;
    // 0x00939eeb: 89742440 MOV
        batch_guest_pc = 0x00939eebu;
        t122 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t122)) return BatchLiftStatus::invalid_memory;
    // 0x00939eef: df6c2440 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000040u))) return BatchLiftStatus::invalid_memory;
    // 0x00939ef3: 897c2450 MOV
        batch_guest_pc = 0x00939ef3u;
        t124 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t124)) return BatchLiftStatus::invalid_memory;
    // 0x00939ef7: 8bf8 MOV
        t125 = state.regs[0];
        state.regs[7] = t125;
    // 0x00939ef9: 25ffffff7f AND
        t126a = state.regs[0];
        t126b = 0x7fffffffu;
        t126r = (t126a & t126b) & 0xffffffffu;
        batch_set_logic_flags(state, t126r, 32u);
        state.regs[0] = t126r;
    // 0x00939efe: d9e0 FCHS
        if (!batch_guest_x87_chs(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939f00: 81e700000080 AND
        t128a = state.regs[7];
        t128b = 0x80000000u;
        t128r = (t128a & t128b) & 0xffffffffu;
        batch_set_logic_flags(state, t128r, 32u);
        state.regs[7] = t128r;
    // 0x00939f06: dec1 FADDP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 0u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939f08: 89442454 MOV
        batch_guest_pc = 0x00939f08u;
        t130 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000054u), t130)) return BatchLiftStatus::invalid_memory;
    // 0x00939f0c: df6c2450 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000050u))) return BatchLiftStatus::invalid_memory;
    // 0x00939f10: 897c245c MOV
        batch_guest_pc = 0x00939f10u;
        t132 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000005cu), t132)) return BatchLiftStatus::invalid_memory;
    // 0x00939f14: 89742458 MOV
        batch_guest_pc = 0x00939f14u;
        t133 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000058u), t133)) return BatchLiftStatus::invalid_memory;
    // 0x00939f18: df6c2458 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000058u))) return BatchLiftStatus::invalid_memory;
    // 0x00939f1c: d9e0 FCHS
        if (!batch_guest_x87_chs(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939f1e: dec1 FADDP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 0u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939f20: def9 FDIVP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 2u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939f22: dd0538f34001 FLD
        if (!batch_guest_fld64(memory, state, 0x0140f338u)) return BatchLiftStatus::invalid_memory;
    // 0x00939f28: dff1 FCOMIP
        if (!batch_guest_x87_compare_stack(state, 1u, 1u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939f2a: 0f8773ffffff JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00939ea3;
    // 0x00939f30: 2b4c2438 SUB
        batch_guest_pc = 0x00939f30u;
        t141a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t141b)) return BatchLiftStatus::invalid_memory;
        t141r = static_cast<std::uint32_t>(t141a - t141b) & 0xffffffffu;
        batch_set_sub_flags(state, t141a, t141b, t141r, 32u);
        state.regs[1] = t141r;
    // 0x00939f34: 1b54243c SBB
        batch_guest_pc = 0x00939f34u;
        t142a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t142b)) return BatchLiftStatus::invalid_memory;
        t142c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t142r = static_cast<std::uint32_t>(t142a - t142b - t142c) & 0xffffffffu;
        batch_set_sbb_flags(state, t142a, t142b, t142c, t142r, 32u);
        state.regs[2] = t142r;
    // 0x00939f38: 894c2458 MOV
        batch_guest_pc = 0x00939f38u;
        t143 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000058u), t143)) return BatchLiftStatus::invalid_memory;
    // 0x00939f3c: 8bc2 MOV
        t144 = state.regs[2];
        state.regs[0] = t144;
    // 0x00939f3e: 81e2ffffff7f AND
        t145a = state.regs[2];
        t145b = 0x7fffffffu;
        t145r = (t145a & t145b) & 0xffffffffu;
        batch_set_logic_flags(state, t145r, 32u);
        state.regs[2] = t145r;
    // 0x00939f44: 8954245c MOV
        batch_guest_pc = 0x00939f44u;
        t146 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000005cu), t146)) return BatchLiftStatus::invalid_memory;
    // 0x00939f48: df6c2458 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000058u))) return BatchLiftStatus::invalid_memory;
    // 0x00939f4c: 2500000080 AND
        t148a = state.regs[0];
        t148b = 0x80000000u;
        t148r = (t148a & t148b) & 0xffffffffu;
        batch_set_logic_flags(state, t148r, 32u);
        state.regs[0] = t148r;
    // 0x00939f51: 8944245c MOV
        batch_guest_pc = 0x00939f51u;
        t149 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000005cu), t149)) return BatchLiftStatus::invalid_memory;
    // 0x00939f55: 89742458 MOV
        batch_guest_pc = 0x00939f55u;
        t150 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000058u), t150)) return BatchLiftStatus::invalid_memory;
    // 0x00939f59: df6c2458 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000058u))) return BatchLiftStatus::invalid_memory;
    // 0x00939f5d: d9e0 FCHS
        if (!batch_guest_x87_chs(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939f5f: dec1 FADDP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 0u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939f61: def1 FDIVRP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 5u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939f63: e8de688a00 CALL
        if (!batch_guest_call32(memory, state, 0x011e0846u, 0x00939f68u)) return BatchLiftStatus::invalid_memory;
        t155_call_status = spore_lift_011e0846(memory, state);
        if (t155_call_status != BatchLiftStatus::returned) return t155_call_status;
        if (state.eip != 0x00939f68u) return BatchLiftStatus::invalid_control_flow;
    // 0x00939f68: 8b7c2418 MOV
        batch_guest_pc = 0x00939f68u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t156)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t156;
    // 0x00939f6c: 8b6c241c MOV
        batch_guest_pc = 0x00939f6cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t157)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t157;
    // 0x00939f70: a3f0ea5401 MOV
        batch_guest_pc = 0x00939f70u;
        t158 = state.regs[0];
        if (!memory.store32(0x0154eaf0u, t158)) return BatchLiftStatus::invalid_memory;
    // 0x00939f75: 8915f4ea5401 MOV
        batch_guest_pc = 0x00939f75u;
        t159 = state.regs[2];
        if (!memory.store32(0x0154eaf4u, t159)) return BatchLiftStatus::invalid_memory;
    // 0x00939f7b: 68e8ea5401 PUSH
    L_00939f7b:
        batch_guest_pc = 0x00939f7bu;
        t160a = 0x0154eae8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t160a)) return BatchLiftStatus::invalid_memory;
    // 0x00939f80: ff159cc03c01 CALL
        t161_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!QueryPerformanceFrequency", 0x013cc09cu, 0x00939f86u);
        if (t161_call_status != BatchLiftStatus::returned) return t161_call_status;
        if (state.eip != 0x00939f86u) return BatchLiftStatus::invalid_control_flow;
    // 0x00939f86: 8b442420 MOV
        batch_guest_pc = 0x00939f86u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t162)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t162;
    // 0x00939f8a: 50 PUSH
        batch_guest_pc = 0x00939f8au;
        t163a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t163a)) return BatchLiftStatus::invalid_memory;
    // 0x00939f8b: 57 PUSH
        batch_guest_pc = 0x00939f8bu;
        t164a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t164a)) return BatchLiftStatus::invalid_memory;
    // 0x00939f8c: ff15a4c03c01 CALL
        t165_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!SetPriorityClass", 0x013cc0a4u, 0x00939f92u);
        if (t165_call_status != BatchLiftStatus::returned) return t165_call_status;
        if (state.eip != 0x00939f92u) return BatchLiftStatus::invalid_control_flow;
    // 0x00939f92: 8b4c2424 MOV
        batch_guest_pc = 0x00939f92u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t166)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t166;
    // 0x00939f96: 51 PUSH
        batch_guest_pc = 0x00939f96u;
        t167a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t167a)) return BatchLiftStatus::invalid_memory;
    // 0x00939f97: 55 PUSH
        batch_guest_pc = 0x00939f97u;
        t168a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t168a)) return BatchLiftStatus::invalid_memory;
    // 0x00939f98: ff15a0c03c01 CALL
        t169_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!SetThreadPriority", 0x013cc0a0u, 0x00939f9eu);
        if (t169_call_status != BatchLiftStatus::returned) return t169_call_status;
        if (state.eip != 0x00939f9eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00939f9e: df2de8ea5401 FILD
        if (!batch_guest_fild64(memory, state, 0x0154eae8u)) return BatchLiftStatus::invalid_memory;
    // 0x00939fa4: d9e8 FLD1
        if (!batch_guest_fld1(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939fa6: f30f100d18574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 1u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x00939fae: def1 FDIVRP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 5u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00939fb0: 0f28f1 MOVAPS
        if (!batch_guest_movaps(state, 6u, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939fb3: 83cfff OR
        t175a = state.regs[7];
        t175b = 0xffffffffu;
        t175r = (t175a | t175b) & 0xffffffffu;
        batch_set_logic_flags(state, t175r, 32u);
        state.regs[7] = t175r;
    // 0x00939fb6: 83ceff OR
        t176a = state.regs[6];
        t176b = 0xffffffffu;
        t176r = (t176a | t176b) & 0xffffffffu;
        batch_set_logic_flags(state, t176r, 32u);
        state.regs[6] = t176r;
    // 0x00939fb9: bd08000000 MOV
        t177 = 0x00000008u;
        state.regs[5] = t177;
    // 0x00939fbe: d95c2424 FSTP
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000024u))) return BatchLiftStatus::invalid_memory;
    // 0x00939fc2: f30f10442424 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x00000024u))) return BatchLiftStatus::invalid_memory;
    // 0x00939fc8: 0f28d0 MOVAPS
        if (!batch_guest_movaps(state, 2u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939fcb: f30f59150c1f3f01 MULSS
        batch_guest_pc = 0x00939fcbu;
        if (!memory.load32(0x013f1f0cu, t181a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 2u, t181a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939fd3: 0f28e8 MOVAPS
        if (!batch_guest_movaps(state, 5u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939fd6: 0f28d8 MOVAPS
        if (!batch_guest_movaps(state, 3u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939fd9: f30f591db4c53e01 MULSS
        batch_guest_pc = 0x00939fd9u;
        if (!memory.load32(0x013ec5b4u, t184a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 3u, t184a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939fe1: 0f28e0 MOVAPS
        if (!batch_guest_movaps(state, 4u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939fe4: f30f590580ea4301 MULSS
        batch_guest_pc = 0x00939fe4u;
        if (!memory.load32(0x0143ea80u, t186a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t186a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939fec: f30f592548f53e01 MULSS
        batch_guest_pc = 0x00939fecu;
        if (!memory.load32(0x013ef548u, t187a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 4u, t187a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939ff4: f30f5ef0 DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 6u, state.xmm[0u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00939ff8: f30f110558996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x01669958u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a000: 0f28c1 MOVAPS
        if (!batch_guest_movaps(state, 0u, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a003: f30f5ec4 DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, state.xmm[4u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a007: f30f110588996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x01669988u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a00f: 0f28c1 MOVAPS
        if (!batch_guest_movaps(state, 0u, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a012: f30f5ec3 DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, state.xmm[3u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a016: f30f11058c996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x0166998cu)) return BatchLiftStatus::invalid_memory;
    // 0x0093a01e: 0f28c1 MOVAPS
        if (!batch_guest_movaps(state, 0u, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a021: f30f5ec5 DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, state.xmm[5u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a025: f30f5eca DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 1u, state.xmm[2u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a029: f30f11155c996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 2u, 0x0166995cu)) return BatchLiftStatus::invalid_memory;
    // 0x0093a031: f30f112d80996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 5u, 0x01669980u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a039: f30f111d6c996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 3u, 0x0166996cu)) return BatchLiftStatus::invalid_memory;
    // 0x0093a041: f30f112574996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 4u, 0x01669974u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a049: f30f113570996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 6u, 0x01669970u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a051: f30f110560996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x01669960u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a059: f30f110d9c996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 1u, 0x0166999cu)) return BatchLiftStatus::invalid_memory;
    // 0x0093a061: 8d542450 LEA
    L_0093a061:
        t206 = static_cast<std::uint32_t>(state.regs[4] + 0x00000050u);
        state.regs[2] = t206;
    // 0x0093a065: 52 PUSH
        batch_guest_pc = 0x0093a065u;
        t207a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t207a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a066: ffd3 CALL
        t208_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[3], 0x0093a068u);
        if (t208_call_status != BatchLiftStatus::returned) return t208_call_status;
    // 0x0093a068: 8d442458 LEA
        t209 = static_cast<std::uint32_t>(state.regs[4] + 0x00000058u);
        state.regs[0] = t209;
    // 0x0093a06c: 50 PUSH
        batch_guest_pc = 0x0093a06cu;
        t210a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t210a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a06d: ffd3 CALL
        t211_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[3], 0x0093a06fu);
        if (t211_call_status != BatchLiftStatus::returned) return t211_call_status;
    // 0x0093a06f: 8b4c2458 MOV
        batch_guest_pc = 0x0093a06fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000058u), t212)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t212;
    // 0x0093a073: 2b4c2450 SUB
        batch_guest_pc = 0x0093a073u;
        t213a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t213b)) return BatchLiftStatus::invalid_memory;
        t213r = static_cast<std::uint32_t>(t213a - t213b) & 0xffffffffu;
        batch_set_sub_flags(state, t213a, t213b, t213r, 32u);
        state.regs[1] = t213r;
    // 0x0093a077: 8b44245c MOV
        batch_guest_pc = 0x0093a077u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000005cu), t214)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t214;
    // 0x0093a07b: 1b442454 SBB
        batch_guest_pc = 0x0093a07bu;
        t215a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000054u), t215b)) return BatchLiftStatus::invalid_memory;
        t215c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t215r = static_cast<std::uint32_t>(t215a - t215b - t215c) & 0xffffffffu;
        batch_set_sbb_flags(state, t215a, t215b, t215c, t215r, 32u);
        state.regs[0] = t215r;
    // 0x0093a07f: 3bf0 CMP
        t216a = state.regs[6];
        t216b = state.regs[0];
        t216r = static_cast<std::uint32_t>(t216a - t216b) & 0xffffffffu;
        batch_set_sub_flags(state, t216a, t216b, t216r, 32u);
    // 0x0093a081: 720a JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0093a08d;
    // 0x0093a083: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0093a089;
    // 0x0093a085: 3bf9 CMP
        t219a = state.regs[7];
        t219b = state.regs[1];
        t219r = static_cast<std::uint32_t>(t219a - t219b) & 0xffffffffu;
        batch_set_sub_flags(state, t219a, t219b, t219r, 32u);
    // 0x0093a087: 7604 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0093a08d;
    // 0x0093a089: 8bf9 MOV
    L_0093a089:
        t221 = state.regs[1];
        state.regs[7] = t221;
    // 0x0093a08b: 8bf0 MOV
        t222 = state.regs[0];
        state.regs[6] = t222;
    // 0x0093a08d: 83ed01 SUB
    L_0093a08d:
        t223a = state.regs[5];
        t223b = 0x00000001u;
        t223r = static_cast<std::uint32_t>(t223a - t223b) & 0xffffffffu;
        batch_set_sub_flags(state, t223a, t223b, t223r, 32u);
        state.regs[5] = t223r;
    // 0x0093a090: 75cf JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093a061;
    // 0x0093a092: df2df0ea5401 FILD
        if (!batch_guest_fild64(memory, state, 0x0154eaf0u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a098: f30f100d18574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 1u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a0a0: d9e8 FLD1
        if (!batch_guest_fld1(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x0093a0a2: 0f28f1 MOVAPS
        if (!batch_guest_movaps(state, 6u, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0a5: def1 FDIVRP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 5u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x0093a0a7: 893da0996601 MOV
        batch_guest_pc = 0x0093a0a7u;
        t230 = state.regs[7];
        if (!memory.store32(0x016699a0u, t230)) return BatchLiftStatus::invalid_memory;
    // 0x0093a0ad: 83cbff OR
        t231a = state.regs[3];
        t231b = 0xffffffffu;
        t231r = (t231a | t231b) & 0xffffffffu;
        batch_set_logic_flags(state, t231r, 32u);
        state.regs[3] = t231r;
    // 0x0093a0b0: 8935a4996601 MOV
        batch_guest_pc = 0x0093a0b0u;
        t232 = state.regs[6];
        if (!memory.store32(0x016699a4u, t232)) return BatchLiftStatus::invalid_memory;
    // 0x0093a0b6: 83cfff OR
        t233a = state.regs[7];
        t233b = 0xffffffffu;
        t233r = (t233a | t233b) & 0xffffffffu;
        batch_set_logic_flags(state, t233r, 32u);
        state.regs[7] = t233r;
    // 0x0093a0b9: bd08000000 MOV
        t234 = 0x00000008u;
        state.regs[5] = t234;
    // 0x0093a0be: d95c2424 FSTP
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000024u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a0c2: f30f10442424 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x00000024u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a0c8: 0f28d0 MOVAPS
        if (!batch_guest_movaps(state, 2u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0cb: f30f59150c1f3f01 MULSS
        batch_guest_pc = 0x0093a0cbu;
        if (!memory.load32(0x013f1f0cu, t238a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 2u, t238a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0d3: 0f28e8 MOVAPS
        if (!batch_guest_movaps(state, 5u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0d6: 0f28d8 MOVAPS
        if (!batch_guest_movaps(state, 3u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0d9: f30f591db4c53e01 MULSS
        batch_guest_pc = 0x0093a0d9u;
        if (!memory.load32(0x013ec5b4u, t241a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 3u, t241a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0e1: 0f28e0 MOVAPS
        if (!batch_guest_movaps(state, 4u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0e4: f30f590580ea4301 MULSS
        batch_guest_pc = 0x0093a0e4u;
        if (!memory.load32(0x0143ea80u, t243a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, t243a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0ec: f30f592548f53e01 MULSS
        batch_guest_pc = 0x0093a0ecu;
        if (!memory.load32(0x013ef548u, t244a)) return BatchLiftStatus::invalid_memory;
        if (!batch_guest_sse_scalar_arithmetic(state, 4u, t244a, 2u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0f4: f30f5ef0 DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 6u, state.xmm[0u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a0f8: f30f110550996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x01669950u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a100: 0f28c1 MOVAPS
        if (!batch_guest_movaps(state, 0u, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a103: f30f5ec4 DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, state.xmm[4u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a107: f30f110584996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x01669984u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a10f: 0f28c1 MOVAPS
        if (!batch_guest_movaps(state, 0u, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a112: f30f5ec3 DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, state.xmm[3u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a116: f30f110590996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x01669990u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a11e: 0f28c1 MOVAPS
        if (!batch_guest_movaps(state, 0u, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a121: f30f5ec5 DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 0u, state.xmm[5u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a125: f30f5eca DIVSS
        if (!batch_guest_sse_scalar_arithmetic(state, 1u, state.xmm[2u][0], 3u)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a129: f30f111594996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 2u, 0x01669994u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a131: f30f112d7c996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 5u, 0x0166997cu)) return BatchLiftStatus::invalid_memory;
    // 0x0093a139: f30f111d54996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 3u, 0x01669954u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a141: f30f112568996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 4u, 0x01669968u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a149: f30f113578996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 6u, 0x01669978u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a151: f30f110598996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x01669998u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a159: f30f110d64996601 MOVSS
        if (!batch_guest_movss_store(memory, state, 1u, 0x01669964u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a161: 0f31 RDTSC
    L_0093a161:
        if (!batch_guest_rdtsc(state)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a163: 8bf2 MOV
        t264 = state.regs[2];
        state.regs[6] = t264;
    // 0x0093a165: 8bc8 MOV
        t265 = state.regs[0];
        state.regs[1] = t265;
    // 0x0093a167: 0f31 RDTSC
        if (!batch_guest_rdtsc(state)) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a169: 2bc1 SUB
        t267a = state.regs[0];
        t267b = state.regs[1];
        t267r = static_cast<std::uint32_t>(t267a - t267b) & 0xffffffffu;
        batch_set_sub_flags(state, t267a, t267b, t267r, 32u);
        state.regs[0] = t267r;
    // 0x0093a16b: 1bd6 SBB
        t268a = state.regs[2];
        t268b = state.regs[6];
        t268c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t268r = static_cast<std::uint32_t>(t268a - t268b - t268c) & 0xffffffffu;
        batch_set_sbb_flags(state, t268a, t268b, t268c, t268r, 32u);
        state.regs[2] = t268r;
    // 0x0093a16d: 3bfa CMP
        t269a = state.regs[7];
        t269b = state.regs[2];
        t269r = static_cast<std::uint32_t>(t269a - t269b) & 0xffffffffu;
        batch_set_sub_flags(state, t269a, t269b, t269r, 32u);
    // 0x0093a16f: 720a JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0093a17b;
    // 0x0093a171: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0093a177;
    // 0x0093a173: 3bd8 CMP
        t272a = state.regs[3];
        t272b = state.regs[0];
        t272r = static_cast<std::uint32_t>(t272a - t272b) & 0xffffffffu;
        batch_set_sub_flags(state, t272a, t272b, t272r, 32u);
    // 0x0093a175: 7604 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0093a17b;
    // 0x0093a177: 8bd8 MOV
    L_0093a177:
        t274 = state.regs[0];
        state.regs[3] = t274;
    // 0x0093a179: 8bfa MOV
        t275 = state.regs[2];
        state.regs[7] = t275;
    // 0x0093a17b: 83ed01 SUB
    L_0093a17b:
        t276a = state.regs[5];
        t276b = 0x00000001u;
        t276r = static_cast<std::uint32_t>(t276a - t276b) & 0xffffffffu;
        batch_set_sub_flags(state, t276a, t276b, t276r, 32u);
        state.regs[5] = t276r;
    // 0x0093a17e: 75e1 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093a161;
    // 0x0093a180: 891da8996601 MOV
        batch_guest_pc = 0x0093a180u;
        t278 = state.regs[3];
        if (!memory.store32(0x016699a8u, t278)) return BatchLiftStatus::invalid_memory;
    // 0x0093a186: 893dac996601 MOV
        batch_guest_pc = 0x0093a186u;
        t279 = state.regs[7];
        if (!memory.store32(0x016699acu, t279)) return BatchLiftStatus::invalid_memory;
    // 0x0093a18c: 5f POP
    L_0093a18c:
        batch_guest_pc = 0x0093a18cu;
        if (!memory.load32(state.regs[4], t280a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t280a;
    // 0x0093a18d: 5e POP
        batch_guest_pc = 0x0093a18du;
        if (!memory.load32(state.regs[4], t281a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t281a;
    // 0x0093a18e: 5d POP
        batch_guest_pc = 0x0093a18eu;
        if (!memory.load32(state.regs[4], t282a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t282a;
    // 0x0093a18f: 5b POP
        batch_guest_pc = 0x0093a18fu;
        if (!memory.load32(state.regs[4], t283a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t283a;
    // 0x0093a190: 8be5 MOV
        t284 = state.regs[5];
        state.regs[4] = t284;
    // 0x0093a192: 5d POP
        batch_guest_pc = 0x0093a192u;
        if (!memory.load32(state.regs[4], t285a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t285a;
    // 0x0093a193: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
