#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009370d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937510(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937720(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937970(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937ea2(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937ea6(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937eba(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0093808e(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009380ea(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009381f2(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00938244(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00938250(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00937da0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00937da0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28r = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38t = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    BatchLiftStatus t50_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74a = 0;
    std::uint32_t t75 = 0;
    BatchLiftStatus t76_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t77a = 0, t77b = 0, t77r = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t95a = 0, t95b = 0, t95r = 0;
    std::uint32_t t97a = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t100a = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t105a = 0, t105b = 0, t105r = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112a = 0, t112b = 0, t112r = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116a = 0;
    std::uint32_t t117a = 0;
    std::uint32_t t118a = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120a = 0;
    BatchLiftStatus t121_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t122a = 0, t122b = 0, t122r = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125a = 0, t125b = 0, t125r = 0;
    std::uint32_t t127 = 0;
    std::uint32_t t128 = 0;
    std::uint32_t t129a = 0, t129b = 0, t129r = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132 = 0;
    std::uint32_t t134a = 0, t134b = 0, t134r = 0;
    std::uint32_t t136a = 0, t136b = 0, t136r = 0;
    std::uint32_t t138a = 0, t138b = 0, t138r = 0;
    std::uint32_t t140 = 0;
    std::uint32_t t141a = 0, t141b = 0, t141r = 0;
    std::uint32_t t142 = 0;
    std::uint32_t t143 = 0;
    std::uint32_t t145 = 0;
    std::uint32_t t146a = 0, t146b = 0, t146r = 0;
    std::uint32_t t147 = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150a = 0, t150b = 0, t150r = 0;
    std::uint32_t t152a = 0, t152b = 0, t152r = 0;
    std::uint32_t t154a = 0, t154b = 0, t154r = 0;
    std::uint32_t t156a = 0, t156b = 0, t156r = 0;
    std::uint32_t t158a = 0;
    std::uint32_t t159 = 0;
    std::uint32_t t161a = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163 = 0;
    std::uint32_t t165 = 0;
    std::uint32_t t167a = 0, t167b = 0, t167r = 0;
    std::uint32_t t168 = 0;
    std::uint32_t t169a = 0;
    std::uint32_t t170 = 0;
    std::uint32_t t171a = 0, t171b = 0, t171r = 0;
    std::uint32_t t172 = 0;
    std::uint32_t t174a = 0;
    BatchLiftStatus t175_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t176a = 0, t176b = 0, t176r = 0;
    std::uint32_t t178 = 0;
    std::uint32_t t179a = 0, t179b = 0, t179r = 0;
    std::uint32_t t180 = 0;
    std::uint32_t t181a = 0, t181b = 0, t181r = 0;
    std::uint32_t t183 = 0;
    std::uint32_t t184a = 0, t184b = 0, t184r = 0;
    std::uint32_t t186 = 0;
    std::uint32_t t187 = 0;
    std::uint32_t t188 = 0;
    std::uint32_t t189a = 0, t189b = 0, t189r = 0;
    std::uint32_t t191a = 0, t191b = 0, t191r = 0;
    std::uint32_t t192 = 0;
    std::uint32_t t195a = 0, t195b = 0, t195r = 0;
    std::uint32_t t197a = 0, t197b = 0, t197r = 0;
    std::uint32_t t198a = 0, t198b = 0, t198r = 0;
    std::uint32_t t201a = 0, t201b = 0, t201r = 0;
    std::uint32_t t203a = 0, t203b = 0, t203r = 0;
    std::uint32_t t204a = 0, t204b = 0, t204r = 0;
    std::uint32_t t206a = 0, t206b = 0, t206r = 0;
    std::uint32_t t207a = 0, t207c = 0, t207r = 0;
    std::uint32_t t208a = 0, t208b = 0, t208r = 0;
    std::uint32_t t210a = 0;
    std::uint32_t t211a = 0;
    std::uint32_t t212a = 0;
    std::uint32_t t213 = 0;
    std::uint32_t t214a = 0;
    std::uint32_t t215a = 0;
    std::uint32_t t216a = 0;
    std::uint32_t t217a = 0;
    std::uint32_t t218a = 0;
    BatchLiftStatus t219_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t220 = 0;
    std::uint32_t t221a = 0, t221b = 0, t221r = 0;
    std::uint32_t t223 = 0;
    std::uint32_t t224a = 0, t224b = 0, t224r = 0;
    std::uint32_t t225a = 0, t225b = 0, t225r = 0;
    std::uint32_t t226a = 0, t226b = 0, t226r = 0;
    std::uint32_t t228 = 0;
    std::uint32_t t229a = 0;
    std::uint32_t t230a = 0;
    std::uint32_t t231a = 0;
    std::uint32_t t232t = 0;
    BatchLiftStatus t232_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t233a = 0, t233b = 0, t233r = 0;
    std::uint32_t t234a = 0, t234b = 0, t234r = 0;
    std::uint32_t t236a = 0, t236b = 0, t236r = 0;
    std::uint32_t t238 = 0;
    std::uint32_t t239a = 0;
    std::uint32_t t240a = 0;
    std::uint32_t t241a = 0;
    std::uint32_t t242a = 0;
    std::uint32_t t243a = 0, t243b = 0, t243r = 0;
    std::uint32_t t245 = 0;
    std::uint32_t t246a = 0, t246b = 0, t246r = 0;
    std::uint32_t t248 = 0;
    std::uint32_t t249 = 0;
    std::uint32_t t250 = 0;
    std::uint32_t t251a = 0, t251b = 0, t251r = 0;
    std::uint32_t t253a = 0, t253b = 0, t253r = 0;
    std::uint32_t t254a = 0, t254b = 0, t254r = 0;
    std::uint32_t t256a = 0, t256b = 0, t256r = 0;
    std::uint32_t t258a = 0, t258r = 0;
    std::uint32_t t259a = 0, t259b = 0, t259r = 0;
    std::uint32_t t261a = 0, t261b = 0, t261r = 0;
    std::uint32_t t263a = 0, t263b = 0, t263r = 0;
    std::uint32_t t265a = 0, t265r = 0;
    std::uint32_t t266a = 0, t266b = 0, t266r = 0;
    std::uint32_t t268a = 0, t268b = 0, t268r = 0;
    std::uint32_t t270 = 0;
    std::uint32_t t271 = 0;
    std::uint32_t t272a = 0, t272b = 0, t272r = 0;
    std::uint32_t t273 = 0;
    std::uint32_t t274 = 0;
    std::uint32_t t275a = 0, t275r = 0;
    std::uint32_t t276a = 0, t276b = 0, t276r = 0;
    std::uint32_t t278a = 0;
    std::uint32_t t279 = 0;
    std::uint32_t t280 = 0;
    std::uint32_t t282 = 0;
    std::uint32_t t283 = 0;
    std::uint32_t t285 = 0;
    std::uint32_t t286 = 0;
    std::uint32_t t288 = 0;
    std::uint32_t t290 = 0;
    std::uint32_t t291 = 0;
    std::uint32_t t293 = 0;
    std::uint32_t t294 = 0;
    std::uint32_t t296 = 0;
    std::uint32_t t297a = 0, t297b = 0, t297r = 0;
    std::uint32_t t298a = 0, t298b = 0, t298r = 0;
    std::uint32_t t299 = 0;
    std::uint32_t t300 = 0;
    std::uint32_t t301 = 0;
    std::uint32_t t303 = 0;
    std::uint32_t t304 = 0;
    std::uint32_t t306 = 0;
    std::uint32_t t307 = 0;
    std::uint32_t t309 = 0;
    std::uint32_t t310 = 0;
    std::uint32_t t311 = 0;
    std::uint32_t t312a = 0, t312b = 0, t312r = 0;
    std::uint32_t t313 = 0;
    std::uint32_t t314 = 0;
    std::uint32_t t316a = 0, t316b = 0, t316r = 0;
    std::uint32_t t318 = 0;
    std::uint32_t t319a = 0, t319b = 0, t319r = 0;
    std::uint32_t t321 = 0;
    std::uint32_t t322a = 0, t322b = 0, t322r = 0;
    std::uint32_t t324a = 0, t324b = 0, t324r = 0;
    std::uint32_t t326a = 0, t326b = 0, t326r = 0;
    std::uint32_t t328 = 0;
    std::uint32_t t329a = 0;
    std::uint32_t t330a = 0;
    std::uint32_t t331a = 0;
    std::uint32_t t332t = 0;
    BatchLiftStatus t332_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t333a = 0, t333b = 0, t333r = 0;
    std::uint32_t t334a = 0, t334b = 0, t334r = 0;
    std::uint32_t t336a = 0, t336r = 0;
    std::uint32_t t337a = 0, t337r = 0;
    std::uint32_t t339 = 0;
    std::uint32_t t340a = 0, t340b = 0, t340r = 0;
    std::uint32_t t343 = 0;
    std::uint32_t t344a = 0;
    std::uint32_t t345 = 0;
    std::uint32_t t346a = 0;
    std::uint32_t t347a = 0;
    std::uint32_t t348t = 0;
    BatchLiftStatus t348_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t349a = 0, t349b = 0, t349r = 0;
    std::uint32_t t350a = 0, t350b = 0, t350r = 0;
    std::uint32_t t352a = 0, t352r = 0;
    std::uint32_t t353a = 0, t353b = 0, t353r = 0;
    std::uint32_t t355a = 0, t355b = 0, t355r = 0;
    std::uint32_t t357 = 0;
    std::uint32_t t358a = 0;
    std::uint32_t t359a = 0;
    std::uint32_t t360a = 0;
    std::uint32_t t361t = 0;
    BatchLiftStatus t361_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t362a = 0, t362b = 0, t362r = 0;
    std::uint32_t t363a = 0, t363b = 0, t363r = 0;
    std::uint32_t t365a = 0, t365b = 0, t365r = 0;
    std::uint32_t t367a = 0, t367b = 0, t367r = 0;
    std::uint32_t t368 = 0;
    std::uint32_t t370 = 0;
    std::uint32_t t371a = 0;
    std::uint32_t t372 = 0;
    std::uint32_t t373a = 0;
    std::uint32_t t374a = 0;
    std::uint32_t t375t = 0;
    BatchLiftStatus t375_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t376a = 0, t376b = 0, t376r = 0;
    std::uint32_t t377a = 0, t377b = 0, t377r = 0;
    std::uint32_t t379a = 0, t379r = 0;
    std::uint32_t t380a = 0, t380b = 0, t380r = 0;
    std::uint32_t t382a = 0, t382b = 0, t382r = 0;
    std::uint32_t t383 = 0;
    std::uint32_t t385a = 0;
    std::uint32_t t386a = 0;
    std::uint32_t t387a = 0;
    std::uint32_t t388a = 0, t388b = 0, t388r = 0;
    std::uint32_t t389a = 0;
    std::uint32_t t390a = 0, t390b = 0, t390r = 0;

    // 0x00937da0: 81ec38040000 SUB
        t0a = state.regs[4];
        t0b = 0x00000438u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00937da6: 53 PUSH
        batch_guest_pc = 0x00937da6u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00937da7: b901000000 MOV
        t2 = 0x00000001u;
        state.regs[1] = t2;
    // 0x00937dac: 55 PUSH
        batch_guest_pc = 0x00937dacu;
        t3a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00937dad: 894c2418 MOV
        batch_guest_pc = 0x00937dadu;
        t4 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00937db1: 894c241c MOV
        batch_guest_pc = 0x00937db1u;
        t5 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t5)) return BatchLiftStatus::invalid_memory;
    // 0x00937db5: 33c9 XOR
        t6a = state.regs[1];
        t6b = state.regs[1];
        t6r = (t6a ^ t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[1] = t6r;
    // 0x00937db7: 56 PUSH
        batch_guest_pc = 0x00937db7u;
        t7a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00937db8: 57 PUSH
        batch_guest_pc = 0x00937db8u;
        t8a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00937db9: 8bd8 MOV
        t9 = state.regs[0];
        state.regs[3] = t9;
    // 0x00937dbb: 884c2428 MOV
        batch_guest_pc = 0x00937dbbu;
        t10 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00937dbf: 894c242c MOV
        batch_guest_pc = 0x00937dbfu;
        t11 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00937dc3: c7442430ffffff7f MOV
        batch_guest_pc = 0x00937dc3u;
        t12 = 0x7fffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00937dcb: 894c2434 MOV
        batch_guest_pc = 0x00937dcbu;
        t13 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00937dcf: 894c2438 MOV
        batch_guest_pc = 0x00937dcfu;
        t14 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00937dd3: 894c2414 MOV
        batch_guest_pc = 0x00937dd3u;
        t15 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00937dd7: 894c241c MOV
        batch_guest_pc = 0x00937dd7u;
        t16 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00937ddb: 894c2418 MOV
        batch_guest_pc = 0x00937ddbu;
        t17 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00937ddf: 3808 CMP
        batch_guest_pc = 0x00937ddfu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t18a)) return BatchLiftStatus::invalid_memory;
        t18b = state.regs[1] & 0x000000ffu;
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0x000000ffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 8u);
    // 0x00937de1: 0f840c030000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009380f3;
    // 0x00937de7: 8a03 MOV
    L_00937de7:
        batch_guest_pc = 0x00937de7u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t20 << 0u) & 0x000000ffu);
    // 0x00937de9: bf09000000 MOV
        t21 = 0x00000009u;
        state.regs[7] = t21;
    // 0x00937dee: 8beb MOV
        t22 = state.regs[3];
        state.regs[5] = t22;
    // 0x00937df0: 84c0 TEST
        t23a = state.regs[0] & 0x000000ffu;
        t23b = state.regs[0] & 0x000000ffu;
        t23r = (t23a & t23b) & 0x000000ffu;
        batch_set_logic_flags(state, t23r, 8u);
    // 0x00937df2: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937e00;
    // 0x00937df4: 3c25 CMP
    L_00937df4:
        t25a = state.regs[0] & 0x000000ffu;
        t25b = 0x00000025u;
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0x000000ffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 8u);
    // 0x00937df6: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937e00;
    // 0x00937df8: 8a4501 MOV
        batch_guest_pc = 0x00937df8u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x00000001u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t27 << 0u) & 0x000000ffu);
    // 0x00937dfb: 45 INC
        t28a = state.regs[5];
        t28r = static_cast<std::uint32_t>(t28a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t28a, t28r, 32u);
        state.regs[5] = t28r;
    // 0x00937dfc: 84c0 TEST
        t29a = state.regs[0] & 0x000000ffu;
        t29b = state.regs[0] & 0x000000ffu;
        t29r = (t29a & t29b) & 0x000000ffu;
        batch_set_logic_flags(state, t29r, 8u);
    // 0x00937dfe: 75f4 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937df4;
    // 0x00937e00: 8bf5 MOV
    L_00937e00:
        t31 = state.regs[5];
        state.regs[6] = t31;
    // 0x00937e02: 2bf3 SUB
        t32a = state.regs[6];
        t32b = state.regs[3];
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
        state.regs[6] = t32r;
    // 0x00937e04: 7423 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937e29;
    // 0x00937e06: 8b842450040000 MOV
        batch_guest_pc = 0x00937e06u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000450u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t34;
    // 0x00937e0d: 50 PUSH
        batch_guest_pc = 0x00937e0du;
        t35a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00937e0e: 56 PUSH
        batch_guest_pc = 0x00937e0eu;
        t36a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00937e0f: 53 PUSH
        batch_guest_pc = 0x00937e0fu;
        t37a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00937e10: ff942458040000 CALL
        batch_guest_pc = 0x00937e10u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000458u), t38t)) return BatchLiftStatus::invalid_memory;
        t38_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, t38t, 0x00937e17u);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
    // 0x00937e17: 83c40c ADD
        t39a = state.regs[4];
        t39b = 0x0000000cu;
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[4] = t39r;
    // 0x00937e1a: 83f8ff CMP
        t40a = state.regs[0];
        t40b = 0xffffffffu;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0xffffffffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 32u);
    // 0x00937e1d: 0f84ad040000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009382d0;
    // 0x00937e23: 01742414 ADD
        batch_guest_pc = 0x00937e23u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t42a)) return BatchLiftStatus::invalid_memory;
        t42b = state.regs[6];
        t42r = static_cast<std::uint32_t>(t42a + t42b) & 0xffffffffu;
        batch_set_add_flags(state, t42a, t42b, t42r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t42r)) return BatchLiftStatus::invalid_memory;
    // 0x00937e27: 8bdd MOV
        t43 = state.regs[5];
        state.regs[3] = t43;
    // 0x00937e29: 807d0000 CMP
    L_00937e29:
        batch_guest_pc = 0x00937e29u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t44a)) return BatchLiftStatus::invalid_memory;
        t44b = 0x00000000u;
        t44r = static_cast<std::uint32_t>(t44a - t44b) & 0x000000ffu;
        batch_set_sub_flags(state, t44a, t44b, t44r, 8u);
    // 0x00937e2d: 0f84b7020000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009380ea;
    // 0x00937e33: 8d4c2420 LEA
        t46 = static_cast<std::uint32_t>(state.regs[4] + 0x00000020u);
        state.regs[1] = t46;
    // 0x00937e37: 51 PUSH
        batch_guest_pc = 0x00937e37u;
        t47a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
    // 0x00937e38: 8d842458040000 LEA
        t48 = static_cast<std::uint32_t>(state.regs[4] + 0x00000458u);
        state.regs[0] = t48;
    // 0x00937e3f: 8bd5 MOV
        t49 = state.regs[5];
        state.regs[2] = t49;
    // 0x00937e41: e88af2ffff CALL
        if (!batch_guest_call32(memory, state, 0x009370d0u, 0x00937e46u)) return BatchLiftStatus::invalid_memory;
        t50_call_status = spore_lift_009370d0(memory, state);
        if (t50_call_status != BatchLiftStatus::returned) return t50_call_status;
        if (state.eip != 0x00937e46u) return BatchLiftStatus::invalid_control_flow;
    // 0x00937e46: 8bd8 MOV
        t51 = state.regs[0];
        state.regs[3] = t51;
    // 0x00937e48: 8b44243c MOV
        batch_guest_pc = 0x00937e48u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t52;
    // 0x00937e4c: 83c0db ADD
        t53a = state.regs[0];
        t53b = 0xffffffdbu;
        t53r = static_cast<std::uint32_t>(t53a + t53b) & 0xffffffffu;
        batch_set_add_flags(state, t53a, t53b, t53r, 32u);
        state.regs[0] = t53r;
    // 0x00937e4f: 83c404 ADD
        t54a = state.regs[4];
        t54b = 0x00000004u;
        t54r = static_cast<std::uint32_t>(t54a + t54b) & 0xffffffffu;
        batch_set_add_flags(state, t54a, t54b, t54r, 32u);
        state.regs[4] = t54r;
    // 0x00937e52: 895c243c MOV
        batch_guest_pc = 0x00937e52u;
        t55 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t55)) return BatchLiftStatus::invalid_memory;
    // 0x00937e56: 83f853 CMP
        t56a = state.regs[0];
        t56b = 0x00000053u;
        t56r = static_cast<std::uint32_t>(t56a - t56b) & 0xffffffffu;
        batch_set_sub_flags(state, t56a, t56b, t56r, 32u);
    // 0x00937e59: 0f8762020000 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_009380c1;
    // 0x00937e5f: 0fb69000839300 MOVZX
        batch_guest_pc = 0x00937e5fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00938300u), t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t58a;
    // 0x00937e66: ff2495e0829300 JMP
        batch_guest_pc = 0x00937e66u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] * 4u + 0x009382e0u), t59a)) return BatchLiftStatus::invalid_memory;
        switch (t59a) {
        case 0x00937e6du: goto L_00937e6d;
        case 0x00937f66u: goto L_00937f66;
        case 0x00937ffeu: goto L_00937ffe;
        case 0x00938031u: goto L_00938031;
        case 0x009380c1u: goto L_009380c1;
        case 0x00938151u: goto L_00938151;
        case 0x009381b2u: goto L_009381b2;
        case 0x009381e4u: goto L_009381e4;
        default:
        state.eip = t59a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x00937e6d: 8b442434 MOV
    L_00937e6d:
        batch_guest_pc = 0x00937e6du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t60;
    // 0x00937e71: 83f804 CMP
        t61a = state.regs[0];
        t61b = 0x00000004u;
        t61r = static_cast<std::uint32_t>(t61a - t61b) & 0xffffffffu;
        batch_set_sub_flags(state, t61a, t61b, t61r, 32u);
    // 0x00937e74: 0f84ba000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937f34;
    // 0x00937e7a: 83f803 CMP
        t63a = state.regs[0];
        t63b = 0x00000003u;
        t63r = static_cast<std::uint32_t>(t63a - t63b) & 0xffffffffu;
        batch_set_sub_flags(state, t63a, t63b, t63r, 32u);
    // 0x00937e7d: 0f848d000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937f10;
    // 0x00937e83: 83f808 CMP
        t65a = state.regs[0];
        t65b = 0x00000008u;
        t65r = static_cast<std::uint32_t>(t65a - t65b) & 0xffffffffu;
        batch_set_sub_flags(state, t65a, t65b, t65r, 32u);
    // 0x00937e86: 0f8484000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937f10;
    // 0x00937e8c: 83f80d CMP
        t67a = state.regs[0];
        t67b = 0x0000000du;
        t67r = static_cast<std::uint32_t>(t67a - t67b) & 0xffffffffu;
        batch_set_sub_flags(state, t67a, t67b, t67r, 32u);
    // 0x00937e8f: 0f8497000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937f2c;
    // 0x00937e95: 83f80e CMP
        t69a = state.regs[0];
        t69b = 0x0000000eu;
        t69r = static_cast<std::uint32_t>(t69a - t69b) & 0xffffffffu;
        batch_set_sub_flags(state, t69a, t69b, t69r, 32u);
    // 0x00937e98: 7538 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937ed2;
    // 0x00937e9a: 8384245404000010 ADD
        batch_guest_pc = 0x00937e9au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t71a)) return BatchLiftStatus::invalid_memory;
        t71b = 0x00000010u;
        t71r = static_cast<std::uint32_t>(t71a + t71b) & 0xffffffffu;
        batch_set_add_flags(state, t71a, t71b, t71r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t71r)) return BatchLiftStatus::invalid_memory;
    // 0x00937ea2: 8b44241c MOV
    L_00937ea2:
        batch_guest_pc = 0x00937ea2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t72)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t72;
    // 0x00937ea6: 8d8c2448040000 LEA
    L_00937ea6:
        t73 = static_cast<std::uint32_t>(state.regs[4] + 0x00000448u);
        state.regs[1] = t73;
    // 0x00937ead: 51 PUSH
        batch_guest_pc = 0x00937eadu;
        t74a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t74a)) return BatchLiftStatus::invalid_memory;
    // 0x00937eae: 8d4c2424 LEA
        t75 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[1] = t75;
    // 0x00937eb2: e859f6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00937510u, 0x00937eb7u)) return BatchLiftStatus::invalid_memory;
        t76_call_status = spore_lift_00937510(memory, state);
        if (t76_call_status != BatchLiftStatus::returned) return t76_call_status;
        if (state.eip != 0x00937eb7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00937eb7: 83c404 ADD
        t77a = state.regs[4];
        t77b = 0x00000004u;
        t77r = static_cast<std::uint32_t>(t77a + t77b) & 0xffffffffu;
        batch_set_add_flags(state, t77a, t77b, t77r, 32u);
        state.regs[4] = t77r;
    // 0x00937eba: 8bf0 MOV
    L_00937eba:
        t78 = state.regs[0];
        state.regs[6] = t78;
    // 0x00937ebc: 85f6 TEST
        t79a = state.regs[6];
        t79b = state.regs[6];
        t79r = (t79a & t79b) & 0xffffffffu;
        batch_set_logic_flags(state, t79r, 32u);
    // 0x00937ebe: 0f84fd010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009380c1;
    // 0x00937ec4: 8dbc2447040000 LEA
        t81 = static_cast<std::uint32_t>(state.regs[4] + 0x00000447u);
        state.regs[7] = t81;
    // 0x00937ecb: 2bfe SUB
    L_00937ecb:
        t82a = state.regs[7];
        t82b = state.regs[6];
        t82r = static_cast<std::uint32_t>(t82a - t82b) & 0xffffffffu;
        batch_set_sub_flags(state, t82a, t82b, t82r, 32u);
        state.regs[7] = t82r;
    // 0x00937ecd: e920030000 JMP
        goto L_009381f2;
    // 0x00937ed2: 8b8c2454040000 MOV
    L_00937ed2:
        batch_guest_pc = 0x00937ed2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t84)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t84;
    // 0x00937ed9: 83c104 ADD
        t85a = state.regs[1];
        t85b = 0x00000004u;
        t85r = static_cast<std::uint32_t>(t85a + t85b) & 0xffffffffu;
        batch_set_add_flags(state, t85a, t85b, t85r, 32u);
        state.regs[1] = t85r;
    // 0x00937edc: 898c2454040000 MOV
        batch_guest_pc = 0x00937edcu;
        t86 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t86)) return BatchLiftStatus::invalid_memory;
    // 0x00937ee3: 8b49fc MOV
        batch_guest_pc = 0x00937ee3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0xfffffffcu), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t87;
    // 0x00937ee6: 894c241c MOV
        batch_guest_pc = 0x00937ee6u;
        t88 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t88)) return BatchLiftStatus::invalid_memory;
    // 0x00937eea: 83f802 CMP
        t89a = state.regs[0];
        t89b = 0x00000002u;
        t89r = static_cast<std::uint32_t>(t89a - t89b) & 0xffffffffu;
        batch_set_sub_flags(state, t89a, t89b, t89r, 32u);
    // 0x00937eed: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937f07;
    // 0x00937eef: 83f80b CMP
        t91a = state.regs[0];
        t91b = 0x0000000bu;
        t91r = static_cast<std::uint32_t>(t91a - t91b) & 0xffffffffu;
        batch_set_sub_flags(state, t91a, t91b, t91r, 32u);
    // 0x00937ef2: 7413 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937f07;
    // 0x00937ef4: 83f801 CMP
        t93a = state.regs[0];
        t93b = 0x00000001u;
        t93r = static_cast<std::uint32_t>(t93a - t93b) & 0xffffffffu;
        batch_set_sub_flags(state, t93a, t93b, t93r, 32u);
    // 0x00937ef7: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937efe;
    // 0x00937ef9: 83f80a CMP
        t95a = state.regs[0];
        t95b = 0x0000000au;
        t95r = static_cast<std::uint32_t>(t95a - t95b) & 0xffffffffu;
        batch_set_sub_flags(state, t95a, t95b, t95r, 32u);
    // 0x00937efc: 75a4 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937ea2;
    // 0x00937efe: 0fbec1 MOVSX
    L_00937efe:
        t97a = state.regs[1] & 0x000000ffu;
        t97a = static_cast<std::uint32_t>((t97a ^ 0x00000080u) - 0x00000080u);
        state.regs[0] = t97a;
    // 0x00937f01: 8944241c MOV
        batch_guest_pc = 0x00937f01u;
        t98 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t98)) return BatchLiftStatus::invalid_memory;
    // 0x00937f05: eb9b JMP
        goto L_00937ea2;
    // 0x00937f07: 0fbfc9 MOVSX
    L_00937f07:
        t100a = state.regs[1] & 0x0000ffffu;
        t100a = static_cast<std::uint32_t>((t100a ^ 0x00008000u) - 0x00008000u);
        state.regs[1] = t100a;
    // 0x00937f0a: 894c241c MOV
        batch_guest_pc = 0x00937f0au;
        t101 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t101)) return BatchLiftStatus::invalid_memory;
    // 0x00937f0e: eb92 JMP
        goto L_00937ea2;
    // 0x00937f10: 8b842454040000 MOV
    L_00937f10:
        batch_guest_pc = 0x00937f10u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t103)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t103;
    // 0x00937f17: 8b10 MOV
        batch_guest_pc = 0x00937f17u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t104)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t104;
    // 0x00937f19: 83c004 ADD
        t105a = state.regs[0];
        t105b = 0x00000004u;
        t105r = static_cast<std::uint32_t>(t105a + t105b) & 0xffffffffu;
        batch_set_add_flags(state, t105a, t105b, t105r, 32u);
        state.regs[0] = t105r;
    // 0x00937f1c: 89842454040000 MOV
        batch_guest_pc = 0x00937f1cu;
        t106 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t106)) return BatchLiftStatus::invalid_memory;
    // 0x00937f23: 8954241c MOV
        batch_guest_pc = 0x00937f23u;
        t107 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t107)) return BatchLiftStatus::invalid_memory;
    // 0x00937f27: e976ffffff JMP
        goto L_00937ea2;
    // 0x00937f2c: c744243404000000 MOV
    L_00937f2c:
        batch_guest_pc = 0x00937f2cu;
        t109 = 0x00000004u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t109)) return BatchLiftStatus::invalid_memory;
    // 0x00937f34: 8b842454040000 MOV
    L_00937f34:
        batch_guest_pc = 0x00937f34u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t110)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t110;
    // 0x00937f3b: 8b08 MOV
        batch_guest_pc = 0x00937f3bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t111)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t111;
    // 0x00937f3d: 83c008 ADD
        t112a = state.regs[0];
        t112b = 0x00000008u;
        t112r = static_cast<std::uint32_t>(t112a + t112b) & 0xffffffffu;
        batch_set_add_flags(state, t112a, t112b, t112r, 32u);
        state.regs[0] = t112r;
    // 0x00937f40: 89842454040000 MOV
        batch_guest_pc = 0x00937f40u;
        t113 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t113)) return BatchLiftStatus::invalid_memory;
    // 0x00937f47: 8b40fc MOV
        batch_guest_pc = 0x00937f47u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t114)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t114;
    // 0x00937f4a: 8d942448040000 LEA
        t115 = static_cast<std::uint32_t>(state.regs[4] + 0x00000448u);
        state.regs[2] = t115;
    // 0x00937f51: 52 PUSH
        batch_guest_pc = 0x00937f51u;
        t116a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t116a)) return BatchLiftStatus::invalid_memory;
    // 0x00937f52: 50 PUSH
        batch_guest_pc = 0x00937f52u;
        t117a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t117a)) return BatchLiftStatus::invalid_memory;
    // 0x00937f53: 51 PUSH
        batch_guest_pc = 0x00937f53u;
        t118a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
    // 0x00937f54: 8d44242c LEA
        t119 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[0] = t119;
    // 0x00937f58: 50 PUSH
        batch_guest_pc = 0x00937f58u;
        t120a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t120a)) return BatchLiftStatus::invalid_memory;
    // 0x00937f59: e8c2f7ffff CALL
        if (!batch_guest_call32(memory, state, 0x00937720u, 0x00937f5eu)) return BatchLiftStatus::invalid_memory;
        t121_call_status = spore_lift_00937720(memory, state);
        if (t121_call_status != BatchLiftStatus::returned) return t121_call_status;
        if (state.eip != 0x00937f5eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00937f5e: 83c410 ADD
        t122a = state.regs[4];
        t122b = 0x00000010u;
        t122r = static_cast<std::uint32_t>(t122a + t122b) & 0xffffffffu;
        batch_set_add_flags(state, t122a, t122b, t122r, 32u);
        state.regs[4] = t122r;
    // 0x00937f61: e954ffffff JMP
        goto L_00937eba;
    // 0x00937f66: 8b442434 MOV
    L_00937f66:
        batch_guest_pc = 0x00937f66u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t124)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t124;
    // 0x00937f6a: 83f803 CMP
        t125a = state.regs[0];
        t125b = 0x00000003u;
        t125r = static_cast<std::uint32_t>(t125a - t125b) & 0xffffffffu;
        batch_set_sub_flags(state, t125a, t125b, t125r, 32u);
    // 0x00937f6d: 751e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937f8d;
    // 0x00937f6f: 8b842454040000 MOV
        batch_guest_pc = 0x00937f6fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t127)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t127;
    // 0x00937f76: 8b10 MOV
        batch_guest_pc = 0x00937f76u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t128)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t128;
    // 0x00937f78: 83c004 ADD
        t129a = state.regs[0];
        t129b = 0x00000004u;
        t129r = static_cast<std::uint32_t>(t129a + t129b) & 0xffffffffu;
        batch_set_add_flags(state, t129a, t129b, t129r, 32u);
        state.regs[0] = t129r;
    // 0x00937f7b: 89842454040000 MOV
        batch_guest_pc = 0x00937f7bu;
        t130 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t130)) return BatchLiftStatus::invalid_memory;
    // 0x00937f82: 89542418 MOV
        batch_guest_pc = 0x00937f82u;
        t131 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t131)) return BatchLiftStatus::invalid_memory;
    // 0x00937f86: 8bc2 MOV
        t132 = state.regs[2];
        state.regs[0] = t132;
    // 0x00937f88: e919ffffff JMP
        goto L_00937ea6;
    // 0x00937f8d: 83f804 CMP
    L_00937f8d:
        t134a = state.regs[0];
        t134b = 0x00000004u;
        t134r = static_cast<std::uint32_t>(t134a - t134b) & 0xffffffffu;
        batch_set_sub_flags(state, t134a, t134b, t134r, 32u);
    // 0x00937f90: 74a2 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937f34;
    // 0x00937f92: 83f80d CMP
        t136a = state.regs[0];
        t136b = 0x0000000du;
        t136r = static_cast<std::uint32_t>(t136a - t136b) & 0xffffffffu;
        batch_set_sub_flags(state, t136a, t136b, t136r, 32u);
    // 0x00937f95: 7495 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937f2c;
    // 0x00937f97: 83f80e CMP
        t138a = state.regs[0];
        t138b = 0x0000000eu;
        t138r = static_cast<std::uint32_t>(t138a - t138b) & 0xffffffffu;
        batch_set_sub_flags(state, t138a, t138b, t138r, 32u);
    // 0x00937f9a: 751a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937fb6;
    // 0x00937f9c: 8b842454040000 MOV
        batch_guest_pc = 0x00937f9cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t140)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t140;
    // 0x00937fa3: 83c010 ADD
        t141a = state.regs[0];
        t141b = 0x00000010u;
        t141r = static_cast<std::uint32_t>(t141a + t141b) & 0xffffffffu;
        batch_set_add_flags(state, t141a, t141b, t141r, 32u);
        state.regs[0] = t141r;
    // 0x00937fa6: 89842454040000 MOV
        batch_guest_pc = 0x00937fa6u;
        t142 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t142)) return BatchLiftStatus::invalid_memory;
    // 0x00937fad: 8b442418 MOV
        batch_guest_pc = 0x00937fadu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t143)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t143;
    // 0x00937fb1: e9f0feffff JMP
        goto L_00937ea6;
    // 0x00937fb6: 8b8c2454040000 MOV
    L_00937fb6:
        batch_guest_pc = 0x00937fb6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t145)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t145;
    // 0x00937fbd: 83c104 ADD
        t146a = state.regs[1];
        t146b = 0x00000004u;
        t146r = static_cast<std::uint32_t>(t146a + t146b) & 0xffffffffu;
        batch_set_add_flags(state, t146a, t146b, t146r, 32u);
        state.regs[1] = t146r;
    // 0x00937fc0: 898c2454040000 MOV
        batch_guest_pc = 0x00937fc0u;
        t147 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t147)) return BatchLiftStatus::invalid_memory;
    // 0x00937fc7: 8b49fc MOV
        batch_guest_pc = 0x00937fc7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0xfffffffcu), t148)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t148;
    // 0x00937fca: 894c2418 MOV
        batch_guest_pc = 0x00937fcau;
        t149 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t149)) return BatchLiftStatus::invalid_memory;
    // 0x00937fce: 83f802 CMP
        t150a = state.regs[0];
        t150b = 0x00000002u;
        t150r = static_cast<std::uint32_t>(t150a - t150b) & 0xffffffffu;
        batch_set_sub_flags(state, t150a, t150b, t150r, 32u);
    // 0x00937fd1: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937fee;
    // 0x00937fd3: 83f80b CMP
        t152a = state.regs[0];
        t152b = 0x0000000bu;
        t152r = static_cast<std::uint32_t>(t152a - t152b) & 0xffffffffu;
        batch_set_sub_flags(state, t152a, t152b, t152r, 32u);
    // 0x00937fd6: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937fee;
    // 0x00937fd8: 83f801 CMP
        t154a = state.regs[0];
        t154b = 0x00000001u;
        t154r = static_cast<std::uint32_t>(t154a - t154b) & 0xffffffffu;
        batch_set_sub_flags(state, t154a, t154b, t154r, 32u);
    // 0x00937fdb: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937fe2;
    // 0x00937fdd: 83f80a CMP
        t156a = state.regs[0];
        t156b = 0x0000000au;
        t156r = static_cast<std::uint32_t>(t156a - t156b) & 0xffffffffu;
        batch_set_sub_flags(state, t156a, t156b, t156r, 32u);
    // 0x00937fe0: 7513 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937ff5;
    // 0x00937fe2: 0fb6c1 MOVZX
    L_00937fe2:
        t158a = state.regs[1] & 0x000000ffu;
        state.regs[0] = t158a;
    // 0x00937fe5: 89442418 MOV
        batch_guest_pc = 0x00937fe5u;
        t159 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t159)) return BatchLiftStatus::invalid_memory;
    // 0x00937fe9: e9b8feffff JMP
        goto L_00937ea6;
    // 0x00937fee: 0fb7c9 MOVZX
    L_00937fee:
        t161a = state.regs[1] & 0x0000ffffu;
        state.regs[1] = t161a;
    // 0x00937ff1: 894c2418 MOV
        batch_guest_pc = 0x00937ff1u;
        t162 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t162)) return BatchLiftStatus::invalid_memory;
    // 0x00937ff5: 8b442418 MOV
    L_00937ff5:
        batch_guest_pc = 0x00937ff5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t163)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t163;
    // 0x00937ff9: e9a8feffff JMP
        goto L_00937ea6;
    // 0x00937ffe: 8b842454040000 MOV
    L_00937ffe:
        batch_guest_pc = 0x00937ffeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t165)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t165;
    // 0x00938005: dd00 FLD
        if (!batch_guest_fld64(memory, state, static_cast<std::uint32_t>(state.regs[0] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00938007: 83c008 ADD
        t167a = state.regs[0];
        t167b = 0x00000008u;
        t167r = static_cast<std::uint32_t>(t167a + t167b) & 0xffffffffu;
        batch_set_add_flags(state, t167a, t167b, t167r, 32u);
        state.regs[0] = t167r;
    // 0x0093800a: 8d942448040000 LEA
        t168 = static_cast<std::uint32_t>(state.regs[4] + 0x00000448u);
        state.regs[2] = t168;
    // 0x00938011: 52 PUSH
        batch_guest_pc = 0x00938011u;
        t169a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t169a)) return BatchLiftStatus::invalid_memory;
    // 0x00938012: 89842458040000 MOV
        batch_guest_pc = 0x00938012u;
        t170 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000458u), t170)) return BatchLiftStatus::invalid_memory;
    // 0x00938019: 83ec08 SUB
        t171a = state.regs[4];
        t171b = 0x00000008u;
        t171r = static_cast<std::uint32_t>(t171a - t171b) & 0xffffffffu;
        batch_set_sub_flags(state, t171a, t171b, t171r, 32u);
        state.regs[4] = t171r;
    // 0x0093801c: 8d44242c LEA
        t172 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[0] = t172;
    // 0x00938020: dd1c24 FSTP
        if (!batch_guest_fstp64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00938023: 50 PUSH
        batch_guest_pc = 0x00938023u;
        t174a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t174a)) return BatchLiftStatus::invalid_memory;
    // 0x00938024: e847f9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00937970u, 0x00938029u)) return BatchLiftStatus::invalid_memory;
        t175_call_status = spore_lift_00937970(memory, state);
        if (t175_call_status != BatchLiftStatus::returned) return t175_call_status;
        if (state.eip != 0x00938029u) return BatchLiftStatus::invalid_control_flow;
    // 0x00938029: 83c410 ADD
        t176a = state.regs[4];
        t176b = 0x00000010u;
        t176r = static_cast<std::uint32_t>(t176a + t176b) & 0xffffffffu;
        batch_set_add_flags(state, t176a, t176b, t176r, 32u);
        state.regs[4] = t176r;
    // 0x0093802c: e989feffff JMP
        goto L_00937eba;
    // 0x00938031: 8b842454040000 MOV
    L_00938031:
        batch_guest_pc = 0x00938031u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t178)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t178;
    // 0x00938038: 83c004 ADD
        t179a = state.regs[0];
        t179b = 0x00000004u;
        t179r = static_cast<std::uint32_t>(t179a + t179b) & 0xffffffffu;
        batch_set_add_flags(state, t179a, t179b, t179r, 32u);
        state.regs[0] = t179r;
    // 0x0093803b: 89842454040000 MOV
        batch_guest_pc = 0x0093803bu;
        t180 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t180)) return BatchLiftStatus::invalid_memory;
    // 0x00938042: 397c2434 CMP
        batch_guest_pc = 0x00938042u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t181a)) return BatchLiftStatus::invalid_memory;
        t181b = state.regs[7];
        t181r = static_cast<std::uint32_t>(t181a - t181b) & 0xffffffffu;
        batch_set_sub_flags(state, t181a, t181b, t181r, 32u);
    // 0x00938046: 0f85b6000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00938102;
    // 0x0093804c: 8b40fc MOV
        batch_guest_pc = 0x0093804cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t183)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t183;
    // 0x0093804f: 85c0 TEST
        t184a = state.regs[0];
        t184b = state.regs[0];
        t184r = (t184a & t184b) & 0xffffffffu;
        batch_set_logic_flags(state, t184r, 32u);
    // 0x00938051: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00938058;
    // 0x00938053: b860ea4301 MOV
        t186 = 0x0143ea60u;
        state.regs[0] = t186;
    // 0x00938058: 8b4c2430 MOV
    L_00938058:
        batch_guest_pc = 0x00938058u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t187)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t187;
    // 0x0093805c: 8bf8 MOV
        t188 = state.regs[0];
        state.regs[7] = t188;
    // 0x0093805e: 81f9ffffff7f CMP
        t189a = state.regs[1];
        t189b = 0x7fffffffu;
        t189r = static_cast<std::uint32_t>(t189a - t189b) & 0xffffffffu;
        batch_set_sub_flags(state, t189a, t189b, t189r, 32u);
    // 0x00938064: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093807f;
    // 0x00938066: 66833800 CMP
        batch_guest_pc = 0x00938066u;
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t191a)) return BatchLiftStatus::invalid_memory;
        t191b = 0x00000000u;
        t191r = static_cast<std::uint32_t>(t191a - t191b) & 0x0000ffffu;
        batch_set_sub_flags(state, t191a, t191b, t191r, 16u);
    // 0x0093806a: 8d0c48 LEA
        t192 = static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 2u + 0x00000000u);
        state.regs[1] = t192;
    // 0x0093806d: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093808e;
    // 0x0093806f: 90 NOP
    // 0x00938070: 3bf9 CMP
    L_00938070:
        t195a = state.regs[7];
        t195b = state.regs[1];
        t195r = static_cast<std::uint32_t>(t195a - t195b) & 0xffffffffu;
        batch_set_sub_flags(state, t195a, t195b, t195r, 32u);
    // 0x00938072: 731a JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0093808e;
    // 0x00938074: 83c702 ADD
        t197a = state.regs[7];
        t197b = 0x00000002u;
        t197r = static_cast<std::uint32_t>(t197a + t197b) & 0xffffffffu;
        batch_set_add_flags(state, t197a, t197b, t197r, 32u);
        state.regs[7] = t197r;
    // 0x00938077: 66833f00 CMP
        batch_guest_pc = 0x00938077u;
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t198a)) return BatchLiftStatus::invalid_memory;
        t198b = 0x00000000u;
        t198r = static_cast<std::uint32_t>(t198a - t198b) & 0x0000ffffu;
        batch_set_sub_flags(state, t198a, t198b, t198r, 16u);
    // 0x0093807b: 75f3 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00938070;
    // 0x0093807d: eb0f JMP
        goto L_0093808e;
    // 0x0093807f: 66833800 CMP
    L_0093807f:
        batch_guest_pc = 0x0093807fu;
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t201a)) return BatchLiftStatus::invalid_memory;
        t201b = 0x00000000u;
        t201r = static_cast<std::uint32_t>(t201a - t201b) & 0x0000ffffu;
        batch_set_sub_flags(state, t201a, t201b, t201r, 16u);
    // 0x00938083: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093808e;
    // 0x00938085: 83c702 ADD
    L_00938085:
        t203a = state.regs[7];
        t203b = 0x00000002u;
        t203r = static_cast<std::uint32_t>(t203a + t203b) & 0xffffffffu;
        batch_set_add_flags(state, t203a, t203b, t203r, 32u);
        state.regs[7] = t203r;
    // 0x00938088: 66833f00 CMP
        batch_guest_pc = 0x00938088u;
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t204a)) return BatchLiftStatus::invalid_memory;
        t204b = 0x00000000u;
        t204r = static_cast<std::uint32_t>(t204a - t204b) & 0x0000ffffu;
        batch_set_sub_flags(state, t204a, t204b, t204r, 16u);
    // 0x0093808c: 75f7 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00938085;
    // 0x0093808e: 2bf8 SUB
    L_0093808e:
        t206a = state.regs[7];
        t206b = state.regs[0];
        t206r = static_cast<std::uint32_t>(t206a - t206b) & 0xffffffffu;
        batch_set_sub_flags(state, t206a, t206b, t206r, 32u);
        state.regs[7] = t206r;
    // 0x00938090: d1ff SAR
        t207a = state.regs[7];
        t207c = 1u;
        if (t207c != 0u) {
        t207r = (t207a >> t207c) | ((t207a & 0x80000000u) ? (0xffffffffu << (32u - t207c)) : 0u);
        batch_set_sar_flags(state, t207a, t207c, t207r, 32u);
            state.regs[7] = t207r;
        }
    // 0x00938092: 85ff TEST
        t208a = state.regs[7];
        t208b = state.regs[7];
        t208r = (t208a & t208b) & 0xffffffffu;
        batch_set_logic_flags(state, t208r, 32u);
    // 0x00938094: 0f8e54010000 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_009381ee;
    // 0x0093809a: 6a00 PUSH
        batch_guest_pc = 0x0093809au;
        t210a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t210a)) return BatchLiftStatus::invalid_memory;
    // 0x0093809c: 6a00 PUSH
        batch_guest_pc = 0x0093809cu;
        t211a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t211a)) return BatchLiftStatus::invalid_memory;
    // 0x0093809e: 6808040000 PUSH
        batch_guest_pc = 0x0093809eu;
        t212a = 0x00000408u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t212a)) return BatchLiftStatus::invalid_memory;
    // 0x009380a3: 8d4c244c LEA
        t213 = static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu);
        state.regs[1] = t213;
    // 0x009380a7: 51 PUSH
        batch_guest_pc = 0x009380a7u;
        t214a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t214a)) return BatchLiftStatus::invalid_memory;
    // 0x009380a8: 57 PUSH
        batch_guest_pc = 0x009380a8u;
        t215a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t215a)) return BatchLiftStatus::invalid_memory;
    // 0x009380a9: 50 PUSH
        batch_guest_pc = 0x009380a9u;
        t216a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t216a)) return BatchLiftStatus::invalid_memory;
    // 0x009380aa: 6a00 PUSH
        batch_guest_pc = 0x009380aau;
        t217a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t217a)) return BatchLiftStatus::invalid_memory;
    // 0x009380ac: 68e9fd0000 PUSH
        batch_guest_pc = 0x009380acu;
        t218a = 0x0000fde9u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t218a)) return BatchLiftStatus::invalid_memory;
    // 0x009380b1: ff1524c23c01 CALL
        t219_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!WideCharToMultiByte", 0x013cc224u, 0x009380b7u);
        if (t219_call_status != BatchLiftStatus::returned) return t219_call_status;
        if (state.eip != 0x009380b7u) return BatchLiftStatus::invalid_control_flow;
    // 0x009380b7: 8bf8 MOV
        t220 = state.regs[0];
        state.regs[7] = t220;
    // 0x009380b9: 85ff TEST
        t221a = state.regs[7];
        t221b = state.regs[7];
        t221r = (t221a & t221b) & 0xffffffffu;
        batch_set_logic_flags(state, t221r, 32u);
    // 0x009380bb: 0f8d2d010000 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009381ee;
    // 0x009380c1: 8bc3 MOV
    L_009380c1:
        t223 = state.regs[3];
        state.regs[0] = t223;
    // 0x009380c3: 2bc5 SUB
        t224a = state.regs[0];
        t224b = state.regs[5];
        t224r = static_cast<std::uint32_t>(t224a - t224b) & 0xffffffffu;
        batch_set_sub_flags(state, t224a, t224b, t224r, 32u);
        state.regs[0] = t224r;
    // 0x009380c5: 01442414 ADD
        batch_guest_pc = 0x009380c5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t225a)) return BatchLiftStatus::invalid_memory;
        t225b = state.regs[0];
        t225r = static_cast<std::uint32_t>(t225a + t225b) & 0xffffffffu;
        batch_set_add_flags(state, t225a, t225b, t225r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t225r)) return BatchLiftStatus::invalid_memory;
    // 0x009380c9: 85c0 TEST
        t226a = state.regs[0];
        t226b = state.regs[0];
        t226r = (t226a & t226b) & 0xffffffffu;
        batch_set_logic_flags(state, t226r, 32u);
    // 0x009380cb: 741d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009380ea;
    // 0x009380cd: 8b8c2450040000 MOV
        batch_guest_pc = 0x009380cdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000450u), t228)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t228;
    // 0x009380d4: 51 PUSH
        batch_guest_pc = 0x009380d4u;
        t229a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t229a)) return BatchLiftStatus::invalid_memory;
    // 0x009380d5: 50 PUSH
        batch_guest_pc = 0x009380d5u;
        t230a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t230a)) return BatchLiftStatus::invalid_memory;
    // 0x009380d6: 55 PUSH
        batch_guest_pc = 0x009380d6u;
        t231a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t231a)) return BatchLiftStatus::invalid_memory;
    // 0x009380d7: ff942458040000 CALL
        batch_guest_pc = 0x009380d7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000458u), t232t)) return BatchLiftStatus::invalid_memory;
        t232_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, t232t, 0x009380deu);
        if (t232_call_status != BatchLiftStatus::returned) return t232_call_status;
    // 0x009380de: 83c40c ADD
        t233a = state.regs[4];
        t233b = 0x0000000cu;
        t233r = static_cast<std::uint32_t>(t233a + t233b) & 0xffffffffu;
        batch_set_add_flags(state, t233a, t233b, t233r, 32u);
        state.regs[4] = t233r;
    // 0x009380e1: 83f8ff CMP
        t234a = state.regs[0];
        t234b = 0xffffffffu;
        t234r = static_cast<std::uint32_t>(t234a - t234b) & 0xffffffffu;
        batch_set_sub_flags(state, t234a, t234b, t234r, 32u);
    // 0x009380e4: 0f84e6010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009382d0;
    // 0x009380ea: 803b00 CMP
    L_009380ea:
        batch_guest_pc = 0x009380eau;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t236a)) return BatchLiftStatus::invalid_memory;
        t236b = 0x00000000u;
        t236r = static_cast<std::uint32_t>(t236a - t236b) & 0x000000ffu;
        batch_set_sub_flags(state, t236a, t236b, t236r, 8u);
    // 0x009380ed: 0f85f4fcffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937de7;
    // 0x009380f3: 8b442414 MOV
    L_009380f3:
        batch_guest_pc = 0x009380f3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t238)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t238;
    // 0x009380f7: 5f POP
        batch_guest_pc = 0x009380f7u;
        if (!memory.load32(state.regs[4], t239a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t239a;
    // 0x009380f8: 5e POP
        batch_guest_pc = 0x009380f8u;
        if (!memory.load32(state.regs[4], t240a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t240a;
    // 0x009380f9: 5d POP
        batch_guest_pc = 0x009380f9u;
        if (!memory.load32(state.regs[4], t241a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t241a;
    // 0x009380fa: 5b POP
        batch_guest_pc = 0x009380fau;
        if (!memory.load32(state.regs[4], t242a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t242a;
    // 0x009380fb: 81c438040000 ADD
        t243a = state.regs[4];
        t243b = 0x00000438u;
        t243r = static_cast<std::uint32_t>(t243a + t243b) & 0xffffffffu;
        batch_set_add_flags(state, t243a, t243b, t243r, 32u);
        state.regs[4] = t243r;
    // 0x00938101: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00938102: 8b70fc MOV
    L_00938102:
        batch_guest_pc = 0x00938102u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t245)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t245;
    // 0x00938105: 85f6 TEST
        t246a = state.regs[6];
        t246b = state.regs[6];
        t246r = (t246a & t246b) & 0xffffffffu;
        batch_set_logic_flags(state, t246r, 32u);
    // 0x00938107: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093810e;
    // 0x00938109: be58ea4301 MOV
        t248 = 0x0143ea58u;
        state.regs[6] = t248;
    // 0x0093810e: 8b442430 MOV
    L_0093810e:
        batch_guest_pc = 0x0093810eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t249)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t249;
    // 0x00938112: 8bfe MOV
        t250 = state.regs[6];
        state.regs[7] = t250;
    // 0x00938114: 3dffffff7f CMP
        t251a = state.regs[0];
        t251b = 0x7fffffffu;
        t251r = static_cast<std::uint32_t>(t251a - t251b) & 0xffffffffu;
        batch_set_sub_flags(state, t251a, t251b, t251r, 32u);
    // 0x00938119: 7420 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093813b;
    // 0x0093811b: 03c6 ADD
        t253a = state.regs[0];
        t253b = state.regs[6];
        t253r = static_cast<std::uint32_t>(t253a + t253b) & 0xffffffffu;
        batch_set_add_flags(state, t253a, t253b, t253r, 32u);
        state.regs[0] = t253r;
    // 0x0093811d: 803e00 CMP
        batch_guest_pc = 0x0093811du;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t254a)) return BatchLiftStatus::invalid_memory;
        t254b = 0x00000000u;
        t254r = static_cast<std::uint32_t>(t254a - t254b) & 0x000000ffu;
        batch_set_sub_flags(state, t254a, t254b, t254r, 8u);
    // 0x00938120: 0f84a5fdffff JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937ecb;
    // 0x00938126: 3bf8 CMP
    L_00938126:
        t256a = state.regs[7];
        t256b = state.regs[0];
        t256r = static_cast<std::uint32_t>(t256a - t256b) & 0xffffffffu;
        batch_set_sub_flags(state, t256a, t256b, t256r, 32u);
    // 0x00938128: 0f839dfdffff JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00937ecb;
    // 0x0093812e: 47 INC
        t258a = state.regs[7];
        t258r = static_cast<std::uint32_t>(t258a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t258a, t258r, 32u);
        state.regs[7] = t258r;
    // 0x0093812f: 803f00 CMP
        batch_guest_pc = 0x0093812fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t259a)) return BatchLiftStatus::invalid_memory;
        t259b = 0x00000000u;
        t259r = static_cast<std::uint32_t>(t259a - t259b) & 0x000000ffu;
        batch_set_sub_flags(state, t259a, t259b, t259r, 8u);
    // 0x00938132: 75f2 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00938126;
    // 0x00938134: 2bfe SUB
        t261a = state.regs[7];
        t261b = state.regs[6];
        t261r = static_cast<std::uint32_t>(t261a - t261b) & 0xffffffffu;
        batch_set_sub_flags(state, t261a, t261b, t261r, 32u);
        state.regs[7] = t261r;
    // 0x00938136: e9b7000000 JMP
        goto L_009381f2;
    // 0x0093813b: 803e00 CMP
    L_0093813b:
        batch_guest_pc = 0x0093813bu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t263a)) return BatchLiftStatus::invalid_memory;
        t263b = 0x00000000u;
        t263r = static_cast<std::uint32_t>(t263a - t263b) & 0x000000ffu;
        batch_set_sub_flags(state, t263a, t263b, t263r, 8u);
    // 0x0093813e: 0f8487fdffff JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937ecb;
    // 0x00938144: 47 INC
    L_00938144:
        t265a = state.regs[7];
        t265r = static_cast<std::uint32_t>(t265a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t265a, t265r, 32u);
        state.regs[7] = t265r;
    // 0x00938145: 803f00 CMP
        batch_guest_pc = 0x00938145u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t266a)) return BatchLiftStatus::invalid_memory;
        t266b = 0x00000000u;
        t266r = static_cast<std::uint32_t>(t266a - t266b) & 0x000000ffu;
        batch_set_sub_flags(state, t266a, t266b, t266r, 8u);
    // 0x00938148: 75fa JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00938144;
    // 0x0093814a: 2bfe SUB
        t268a = state.regs[7];
        t268b = state.regs[6];
        t268r = static_cast<std::uint32_t>(t268a - t268b) & 0xffffffffu;
        batch_set_sub_flags(state, t268a, t268b, t268r, 32u);
        state.regs[7] = t268r;
    // 0x0093814c: e9a1000000 JMP
        goto L_009381f2;
    // 0x00938151: 8b842454040000 MOV
    L_00938151:
        batch_guest_pc = 0x00938151u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t270)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t270;
    // 0x00938158: 8b08 MOV
        batch_guest_pc = 0x00938158u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t271)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t271;
    // 0x0093815a: 83c004 ADD
        t272a = state.regs[0];
        t272b = 0x00000004u;
        t272r = static_cast<std::uint32_t>(t272a + t272b) & 0xffffffffu;
        batch_set_add_flags(state, t272a, t272b, t272r, 32u);
        state.regs[0] = t272r;
    // 0x0093815d: 89842454040000 MOV
        batch_guest_pc = 0x0093815du;
        t273 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t273)) return BatchLiftStatus::invalid_memory;
    // 0x00938164: 8b442434 MOV
        batch_guest_pc = 0x00938164u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t274)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t274;
    // 0x00938168: 48 DEC
        t275a = state.regs[0];
        t275r = static_cast<std::uint32_t>(t275a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t275a, t275r, 32u);
        state.regs[0] = t275r;
    // 0x00938169: 83f803 CMP
        t276a = state.regs[0];
        t276b = 0x00000003u;
        t276r = static_cast<std::uint32_t>(t276a - t276b) & 0xffffffffu;
        batch_set_sub_flags(state, t276a, t276b, t276r, 32u);
    // 0x0093816c: 7739 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_009381a7;
    // 0x0093816e: ff248554839300 JMP
        batch_guest_pc = 0x0093816eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] * 4u + 0x00938354u), t278a)) return BatchLiftStatus::invalid_memory;
        switch (t278a) {
        case 0x00938175u: goto L_00938175;
        case 0x00938180u: goto L_00938180;
        case 0x0093818du: goto L_0093818d;
        case 0x00938198u: goto L_00938198;
        default:
        state.eip = t278a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x00938175: 8a542414 MOV
    L_00938175:
        batch_guest_pc = 0x00938175u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t279)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t279 << 0u) & 0x000000ffu);
    // 0x00938179: 8811 MOV
        batch_guest_pc = 0x00938179u;
        t280 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t280)) return BatchLiftStatus::invalid_memory;
    // 0x0093817b: e96affffff JMP
        goto L_009380ea;
    // 0x00938180: 668b442414 MOV
    L_00938180:
        batch_guest_pc = 0x00938180u;
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t282)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffff0000u) | ((t282 << 0u) & 0x0000ffffu);
    // 0x00938185: 668901 MOV
        batch_guest_pc = 0x00938185u;
        t283 = state.regs[0] & 0x0000ffffu;
        if (!memory.store16(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t283)) return BatchLiftStatus::invalid_memory;
    // 0x00938188: e95dffffff JMP
        goto L_009380ea;
    // 0x0093818d: 8b542414 MOV
    L_0093818d:
        batch_guest_pc = 0x0093818du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t285)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t285;
    // 0x00938191: 8911 MOV
        batch_guest_pc = 0x00938191u;
        t286 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t286)) return BatchLiftStatus::invalid_memory;
    // 0x00938193: e952ffffff JMP
        goto L_009380ea;
    // 0x00938198: 8b442414 MOV
    L_00938198:
        batch_guest_pc = 0x00938198u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t288)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t288;
    // 0x0093819c: 99 CDQ
        state.regs[2] = (state.regs[0] & 0x80000000u) != 0u ? 0xffffffffu : 0u;
    // 0x0093819d: 8901 MOV
        batch_guest_pc = 0x0093819du;
        t290 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t290)) return BatchLiftStatus::invalid_memory;
    // 0x0093819f: 895104 MOV
        batch_guest_pc = 0x0093819fu;
        t291 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t291)) return BatchLiftStatus::invalid_memory;
    // 0x009381a2: e943ffffff JMP
        goto L_009380ea;
    // 0x009381a7: 8b442414 MOV
    L_009381a7:
        batch_guest_pc = 0x009381a7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t293)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t293;
    // 0x009381ab: 8901 MOV
        batch_guest_pc = 0x009381abu;
        t294 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t294)) return BatchLiftStatus::invalid_memory;
    // 0x009381ad: e938ffffff JMP
        goto L_009380ea;
    // 0x009381b2: 8b842454040000 MOV
    L_009381b2:
        batch_guest_pc = 0x009381b2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t296)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t296;
    // 0x009381b9: 83c004 ADD
        t297a = state.regs[0];
        t297b = 0x00000004u;
        t297r = static_cast<std::uint32_t>(t297a + t297b) & 0xffffffffu;
        batch_set_add_flags(state, t297a, t297b, t297r, 32u);
        state.regs[0] = t297r;
    // 0x009381bc: 397c2434 CMP
        batch_guest_pc = 0x009381bcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t298a)) return BatchLiftStatus::invalid_memory;
        t298b = state.regs[7];
        t298r = static_cast<std::uint32_t>(t298a - t298b) & 0xffffffffu;
        batch_set_sub_flags(state, t298a, t298b, t298r, 32u);
    // 0x009381c0: 8d742440 LEA
        t299 = static_cast<std::uint32_t>(state.regs[4] + 0x00000040u);
        state.regs[6] = t299;
    // 0x009381c4: 89842454040000 MOV
        batch_guest_pc = 0x009381c4u;
        t300 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000454u), t300)) return BatchLiftStatus::invalid_memory;
    // 0x009381cb: bf01000000 MOV
        t301 = 0x00000001u;
        state.regs[7] = t301;
    // 0x009381d0: 7509 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009381db;
    // 0x009381d2: 8a48fc MOV
        batch_guest_pc = 0x009381d2u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t303)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t303 << 0u) & 0x000000ffu);
    // 0x009381d5: 884c2440 MOV
        batch_guest_pc = 0x009381d5u;
        t304 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t304)) return BatchLiftStatus::invalid_memory;
    // 0x009381d9: eb17 JMP
        goto L_009381f2;
    // 0x009381db: 8a50fc MOV
    L_009381db:
        batch_guest_pc = 0x009381dbu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t306)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t306 << 0u) & 0x000000ffu);
    // 0x009381de: 88542440 MOV
        batch_guest_pc = 0x009381deu;
        t307 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t307)) return BatchLiftStatus::invalid_memory;
    // 0x009381e2: eb0e JMP
        goto L_009381f2;
    // 0x009381e4: c644244025 MOV
    L_009381e4:
        batch_guest_pc = 0x009381e4u;
        t309 = 0x00000025u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t309)) return BatchLiftStatus::invalid_memory;
    // 0x009381e9: bf01000000 MOV
        t310 = 0x00000001u;
        state.regs[7] = t310;
    // 0x009381ee: 8d742440 LEA
    L_009381ee:
        t311 = static_cast<std::uint32_t>(state.regs[4] + 0x00000040u);
        state.regs[6] = t311;
    // 0x009381f2: 837c242000 CMP
    L_009381f2:
        batch_guest_pc = 0x009381f2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t312a)) return BatchLiftStatus::invalid_memory;
        t312b = 0x00000000u;
        t312r = static_cast<std::uint32_t>(t312a - t312b) & 0xffffffffu;
        batch_set_sub_flags(state, t312a, t312b, t312r, 32u);
    // 0x009381f7: 8b5c242c MOV
        batch_guest_pc = 0x009381f7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t313)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t313;
    // 0x009381fb: 8bef MOV
        t314 = state.regs[7];
        state.regs[5] = t314;
    // 0x009381fd: 7474 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00938273;
    // 0x009381ff: 837c242002 CMP
        batch_guest_pc = 0x009381ffu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t316a)) return BatchLiftStatus::invalid_memory;
        t316b = 0x00000002u;
        t316r = static_cast<std::uint32_t>(t316a - t316b) & 0xffffffffu;
        batch_set_sub_flags(state, t316a, t316b, t316r, 32u);
    // 0x00938204: 7539 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093823f;
    // 0x00938206: c644241330 MOV
        batch_guest_pc = 0x00938206u;
        t318 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t318)) return BatchLiftStatus::invalid_memory;
    // 0x0093820b: 85f6 TEST
        t319a = state.regs[6];
        t319b = state.regs[6];
        t319r = (t319a & t319b) & 0xffffffffu;
        batch_set_logic_flags(state, t319r, 32u);
    // 0x0093820d: 7435 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00938244;
    // 0x0093820f: 8a06 MOV
        batch_guest_pc = 0x0093820fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t321)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t321 << 0u) & 0x000000ffu);
    // 0x00938211: 3c2b CMP
        t322a = state.regs[0] & 0x000000ffu;
        t322b = 0x0000002bu;
        t322r = static_cast<std::uint32_t>(t322a - t322b) & 0x000000ffu;
        batch_set_sub_flags(state, t322a, t322b, t322r, 8u);
    // 0x00938213: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093821d;
    // 0x00938215: 3c2d CMP
        t324a = state.regs[0] & 0x000000ffu;
        t324b = 0x0000002du;
        t324r = static_cast<std::uint32_t>(t324a - t324b) & 0x000000ffu;
        batch_set_sub_flags(state, t324a, t324b, t324r, 8u);
    // 0x00938217: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093821d;
    // 0x00938219: 3c20 CMP
        t326a = state.regs[0] & 0x000000ffu;
        t326b = 0x00000020u;
        t326r = static_cast<std::uint32_t>(t326a - t326b) & 0x000000ffu;
        batch_set_sub_flags(state, t326a, t326b, t326r, 8u);
    // 0x0093821b: 7527 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00938244;
    // 0x0093821d: 8b842450040000 MOV
    L_0093821d:
        batch_guest_pc = 0x0093821du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000450u), t328)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t328;
    // 0x00938224: 50 PUSH
        batch_guest_pc = 0x00938224u;
        t329a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t329a)) return BatchLiftStatus::invalid_memory;
    // 0x00938225: 6a01 PUSH
        batch_guest_pc = 0x00938225u;
        t330a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t330a)) return BatchLiftStatus::invalid_memory;
    // 0x00938227: 56 PUSH
        batch_guest_pc = 0x00938227u;
        t331a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t331a)) return BatchLiftStatus::invalid_memory;
    // 0x00938228: ff942458040000 CALL
        batch_guest_pc = 0x00938228u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000458u), t332t)) return BatchLiftStatus::invalid_memory;
        t332_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, t332t, 0x0093822fu);
        if (t332_call_status != BatchLiftStatus::returned) return t332_call_status;
    // 0x0093822f: 83c40c ADD
        t333a = state.regs[4];
        t333b = 0x0000000cu;
        t333r = static_cast<std::uint32_t>(t333a + t333b) & 0xffffffffu;
        batch_set_add_flags(state, t333a, t333b, t333r, 32u);
        state.regs[4] = t333r;
    // 0x00938232: 83f8ff CMP
        t334a = state.regs[0];
        t334b = 0xffffffffu;
        t334r = static_cast<std::uint32_t>(t334a - t334b) & 0xffffffffu;
        batch_set_sub_flags(state, t334a, t334b, t334r, 32u);
    // 0x00938235: 0f8495000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009382d0;
    // 0x0093823b: 4f DEC
        t336a = state.regs[7];
        t336r = static_cast<std::uint32_t>(t336a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t336a, t336r, 32u);
        state.regs[7] = t336r;
    // 0x0093823c: 46 INC
        t337a = state.regs[6];
        t337r = static_cast<std::uint32_t>(t337a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t337a, t337r, 32u);
        state.regs[6] = t337r;
    // 0x0093823d: eb05 JMP
        goto L_00938244;
    // 0x0093823f: c644241320 MOV
    L_0093823f:
        batch_guest_pc = 0x0093823fu;
        t339 = 0x00000020u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t339)) return BatchLiftStatus::invalid_memory;
    // 0x00938244: 3beb CMP
    L_00938244:
        t340a = state.regs[5];
        t340b = state.regs[3];
        t340r = static_cast<std::uint32_t>(t340a - t340b) & 0xffffffffu;
        batch_set_sub_flags(state, t340a, t340b, t340r, 32u);
    // 0x00938246: 7d2b JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00938273;
    // 0x00938248: eb06 JMP
        goto L_00938250;
    // 0x00938250: 8b8c2450040000 MOV
    L_00938250:
        batch_guest_pc = 0x00938250u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000450u), t343)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t343;
    // 0x00938257: 51 PUSH
        batch_guest_pc = 0x00938257u;
        t344a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t344a)) return BatchLiftStatus::invalid_memory;
    // 0x00938258: 8d542417 LEA
        t345 = static_cast<std::uint32_t>(state.regs[4] + 0x00000017u);
        state.regs[2] = t345;
    // 0x0093825c: 6a01 PUSH
        batch_guest_pc = 0x0093825cu;
        t346a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t346a)) return BatchLiftStatus::invalid_memory;
    // 0x0093825e: 52 PUSH
        batch_guest_pc = 0x0093825eu;
        t347a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t347a)) return BatchLiftStatus::invalid_memory;
    // 0x0093825f: ff942458040000 CALL
        batch_guest_pc = 0x0093825fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000458u), t348t)) return BatchLiftStatus::invalid_memory;
        t348_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, t348t, 0x00938266u);
        if (t348_call_status != BatchLiftStatus::returned) return t348_call_status;
    // 0x00938266: 83c40c ADD
        t349a = state.regs[4];
        t349b = 0x0000000cu;
        t349r = static_cast<std::uint32_t>(t349a + t349b) & 0xffffffffu;
        batch_set_add_flags(state, t349a, t349b, t349r, 32u);
        state.regs[4] = t349r;
    // 0x00938269: 83f8ff CMP
        t350a = state.regs[0];
        t350b = 0xffffffffu;
        t350r = static_cast<std::uint32_t>(t350a - t350b) & 0xffffffffu;
        batch_set_sub_flags(state, t350a, t350b, t350r, 32u);
    // 0x0093826c: 7462 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009382d0;
    // 0x0093826e: 45 INC
        t352a = state.regs[5];
        t352r = static_cast<std::uint32_t>(t352a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t352a, t352r, 32u);
        state.regs[5] = t352r;
    // 0x0093826f: 3beb CMP
        t353a = state.regs[5];
        t353b = state.regs[3];
        t353r = static_cast<std::uint32_t>(t353a - t353b) & 0xffffffffu;
        batch_set_sub_flags(state, t353a, t353b, t353r, 32u);
    // 0x00938271: 7cdd JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00938250;
    // 0x00938273: 85ff TEST
    L_00938273:
        t355a = state.regs[7];
        t355b = state.regs[7];
        t355r = (t355a & t355b) & 0xffffffffu;
        batch_set_logic_flags(state, t355r, 32u);
    // 0x00938275: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00938290;
    // 0x00938277: 8b842450040000 MOV
        batch_guest_pc = 0x00938277u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000450u), t357)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t357;
    // 0x0093827e: 50 PUSH
        batch_guest_pc = 0x0093827eu;
        t358a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t358a)) return BatchLiftStatus::invalid_memory;
    // 0x0093827f: 57 PUSH
        batch_guest_pc = 0x0093827fu;
        t359a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t359a)) return BatchLiftStatus::invalid_memory;
    // 0x00938280: 56 PUSH
        batch_guest_pc = 0x00938280u;
        t360a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t360a)) return BatchLiftStatus::invalid_memory;
    // 0x00938281: ff942458040000 CALL
        batch_guest_pc = 0x00938281u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000458u), t361t)) return BatchLiftStatus::invalid_memory;
        t361_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, t361t, 0x00938288u);
        if (t361_call_status != BatchLiftStatus::returned) return t361_call_status;
    // 0x00938288: 83c40c ADD
        t362a = state.regs[4];
        t362b = 0x0000000cu;
        t362r = static_cast<std::uint32_t>(t362a + t362b) & 0xffffffffu;
        batch_set_add_flags(state, t362a, t362b, t362r, 32u);
        state.regs[4] = t362r;
    // 0x0093828b: 83f8ff CMP
        t363a = state.regs[0];
        t363b = 0xffffffffu;
        t363r = static_cast<std::uint32_t>(t363a - t363b) & 0xffffffffu;
        batch_set_sub_flags(state, t363a, t363b, t363r, 32u);
    // 0x0093828e: 7440 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009382d0;
    // 0x00938290: 837c242000 CMP
    L_00938290:
        batch_guest_pc = 0x00938290u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t365a)) return BatchLiftStatus::invalid_memory;
        t365b = 0x00000000u;
        t365r = static_cast<std::uint32_t>(t365a - t365b) & 0xffffffffu;
        batch_set_sub_flags(state, t365a, t365b, t365r, 32u);
    // 0x00938295: 752c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009382c3;
    // 0x00938297: 3beb CMP
        t367a = state.regs[5];
        t367b = state.regs[3];
        t367r = static_cast<std::uint32_t>(t367a - t367b) & 0xffffffffu;
        batch_set_sub_flags(state, t367a, t367b, t367r, 32u);
    // 0x00938299: c644241320 MOV
        batch_guest_pc = 0x00938299u;
        t368 = 0x00000020u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t368)) return BatchLiftStatus::invalid_memory;
    // 0x0093829e: 7d23 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009382c3;
    // 0x009382a0: 8b8c2450040000 MOV
    L_009382a0:
        batch_guest_pc = 0x009382a0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000450u), t370)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t370;
    // 0x009382a7: 51 PUSH
        batch_guest_pc = 0x009382a7u;
        t371a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t371a)) return BatchLiftStatus::invalid_memory;
    // 0x009382a8: 8d542417 LEA
        t372 = static_cast<std::uint32_t>(state.regs[4] + 0x00000017u);
        state.regs[2] = t372;
    // 0x009382ac: 6a01 PUSH
        batch_guest_pc = 0x009382acu;
        t373a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t373a)) return BatchLiftStatus::invalid_memory;
    // 0x009382ae: 52 PUSH
        batch_guest_pc = 0x009382aeu;
        t374a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t374a)) return BatchLiftStatus::invalid_memory;
    // 0x009382af: ff942458040000 CALL
        batch_guest_pc = 0x009382afu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000458u), t375t)) return BatchLiftStatus::invalid_memory;
        t375_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, t375t, 0x009382b6u);
        if (t375_call_status != BatchLiftStatus::returned) return t375_call_status;
    // 0x009382b6: 83c40c ADD
        t376a = state.regs[4];
        t376b = 0x0000000cu;
        t376r = static_cast<std::uint32_t>(t376a + t376b) & 0xffffffffu;
        batch_set_add_flags(state, t376a, t376b, t376r, 32u);
        state.regs[4] = t376r;
    // 0x009382b9: 83f8ff CMP
        t377a = state.regs[0];
        t377b = 0xffffffffu;
        t377r = static_cast<std::uint32_t>(t377a - t377b) & 0xffffffffu;
        batch_set_sub_flags(state, t377a, t377b, t377r, 32u);
    // 0x009382bc: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009382d0;
    // 0x009382be: 45 INC
        t379a = state.regs[5];
        t379r = static_cast<std::uint32_t>(t379a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t379a, t379r, 32u);
        state.regs[5] = t379r;
    // 0x009382bf: 3beb CMP
        t380a = state.regs[5];
        t380b = state.regs[3];
        t380r = static_cast<std::uint32_t>(t380a - t380b) & 0xffffffffu;
        batch_set_sub_flags(state, t380a, t380b, t380r, 32u);
    // 0x009382c1: 7cdd JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_009382a0;
    // 0x009382c3: 016c2414 ADD
    L_009382c3:
        batch_guest_pc = 0x009382c3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t382a)) return BatchLiftStatus::invalid_memory;
        t382b = state.regs[5];
        t382r = static_cast<std::uint32_t>(t382a + t382b) & 0xffffffffu;
        batch_set_add_flags(state, t382a, t382b, t382r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t382r)) return BatchLiftStatus::invalid_memory;
    // 0x009382c7: 8b5c243c MOV
        batch_guest_pc = 0x009382c7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t383)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t383;
    // 0x009382cb: e91afeffff JMP
        goto L_009380ea;
    // 0x009382d0: 5f POP
    L_009382d0:
        batch_guest_pc = 0x009382d0u;
        if (!memory.load32(state.regs[4], t385a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t385a;
    // 0x009382d1: 5e POP
        batch_guest_pc = 0x009382d1u;
        if (!memory.load32(state.regs[4], t386a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t386a;
    // 0x009382d2: 5d POP
        batch_guest_pc = 0x009382d2u;
        if (!memory.load32(state.regs[4], t387a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t387a;
    // 0x009382d3: 83c8ff OR
        t388a = state.regs[0];
        t388b = 0xffffffffu;
        t388r = (t388a | t388b) & 0xffffffffu;
        batch_set_logic_flags(state, t388r, 32u);
        state.regs[0] = t388r;
    // 0x009382d6: 5b POP
        batch_guest_pc = 0x009382d6u;
        if (!memory.load32(state.regs[4], t389a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t389a;
    // 0x009382d7: 81c438040000 ADD
        t390a = state.regs[4];
        t390b = 0x00000438u;
        t390r = static_cast<std::uint32_t>(t390a + t390b) & 0xffffffffu;
        batch_set_add_flags(state, t390a, t390b, t390r, 32u);
        state.regs[4] = t390r;
    // 0x009382dd: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
