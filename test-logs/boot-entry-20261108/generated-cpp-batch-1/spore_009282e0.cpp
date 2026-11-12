#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009267f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009268b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926af0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926fd0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927be0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00928376(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009283cb(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009283e5(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009284c5(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009282e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009282e0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30c = 0, t30r = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33c = 0, t33r = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0, t36c = 0, t36r = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39c = 0, t39r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0, t42c = 0, t42r = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t44a = 0, t44r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76a = 0, t76c = 0, t76r = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t79a = 0;
    BatchLiftStatus t80_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t81a = 0, t81b = 0, t81r = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86a = 0, t86b = 0, t86r = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95a = 0, t95b = 0, t95r = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t99a = 0, t99b = 0, t99r = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t105a = 0, t105r = 0;
    std::uint32_t t106a = 0, t106b = 0, t106r = 0;
    std::uint32_t t107a = 0, t107b = 0, t107r = 0;
    std::uint32_t t108a = 0, t108b = 0, t108r = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0, t111b = 0, t111r = 0;
    std::uint32_t t113a = 0, t113b = 0, t113r = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t118a = 0, t118b = 0, t118r = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121a = 0, t121b = 0, t121r = 0;
    std::uint32_t t123a = 0, t123b = 0, t123r = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126a = 0, t126b = 0, t126r = 0;
    std::uint32_t t128a = 0, t128b = 0, t128r = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132a = 0, t132b = 0, t132r = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t135 = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137a = 0, t137r = 0;
    std::uint32_t t138a = 0, t138b = 0, t138r = 0;
    std::uint32_t t139 = 0;
    std::uint32_t t141 = 0;
    std::uint32_t t142a = 0, t142b = 0, t142r = 0;
    std::uint32_t t144a = 0, t144b = 0, t144r = 0;
    std::uint32_t t146a = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150a = 0, t150b = 0, t150r = 0;
    std::uint32_t t151a = 0, t151b = 0, t151r = 0;
    std::uint32_t t153a = 0, t153b = 0, t153r = 0;
    std::uint32_t t154 = 0;
    std::uint32_t t155a = 0, t155b = 0, t155r = 0;
    std::uint32_t t157a = 0, t157b = 0, t157r = 0;
    std::uint32_t t159a = 0, t159b = 0, t159r = 0;
    std::uint32_t t161a = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163 = 0;
    std::uint32_t t164a = 0;
    std::uint32_t t165a = 0;
    std::uint32_t t166a = 0;
    std::uint32_t t167a = 0, t167b = 0, t167r = 0;
    std::uint32_t t168a = 0;
    std::uint32_t t169a = 0;
    std::uint32_t t170 = 0;
    BatchLiftStatus t171_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t172a = 0;
    std::uint32_t t173a = 0;
    std::uint32_t t174a = 0;
    std::uint32_t t175a = 0, t175b = 0, t175r = 0;
    std::uint32_t t176a = 0;
    std::uint32_t t177a = 0, t177b = 0, t177r = 0;
    std::uint32_t t179 = 0;
    std::uint32_t t180a = 0, t180c = 0, t180r = 0;
    std::uint32_t t181a = 0;
    std::uint32_t t182a = 0, t182b = 0, t182r = 0;
    std::uint32_t t184a = 0, t184b = 0, t184r = 0;
    std::uint32_t t186a = 0, t186b = 0, t186r = 0;
    std::uint32_t t188 = 0;
    std::uint32_t t189 = 0;
    std::uint32_t t190a = 0, t190b = 0, t190r = 0;
    std::uint32_t t191a = 0, t191b = 0, t191r = 0;
    std::uint32_t t192a = 0, t192b = 0, t192r = 0;
    std::uint32_t t193 = 0;
    std::uint32_t t194a = 0, t194r = 0;
    std::uint32_t t195a = 0, t195b = 0, t195r = 0;
    std::uint32_t t196a = 0, t196b = 0, t196r = 0;
    std::uint32_t t197a = 0, t197b = 0, t197r = 0;
    std::uint32_t t198 = 0;
    std::uint32_t t199a = 0, t199b = 0, t199r = 0;
    std::uint32_t t200a = 0, t200b = 0, t200r = 0;
    std::uint32_t t201 = 0;
    std::uint32_t t202 = 0;
    std::uint32_t t203a = 0, t203b = 0, t203r = 0;
    std::uint32_t t204 = 0;
    std::uint32_t t205 = 0;
    std::uint32_t t206 = 0;
    std::uint32_t t207a = 0;
    std::uint32_t t208a = 0;
    std::uint32_t t209 = 0;
    std::uint32_t t210 = 0;
    BatchLiftStatus t211_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t212a = 0;
    std::uint32_t t213a = 0;
    std::uint32_t t214a = 0;
    std::uint32_t t215 = 0;
    std::uint32_t t216a = 0;
    std::uint32_t t217a = 0, t217b = 0, t217r = 0;
    std::uint32_t t219 = 0;
    std::uint32_t t220 = 0;
    std::uint32_t t221a = 0;
    std::uint32_t t222 = 0;
    std::uint32_t t223 = 0;
    std::uint32_t t224a = 0;
    std::uint32_t t225 = 0;
    BatchLiftStatus t226_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t227 = 0;
    std::uint32_t t228a = 0, t228b = 0, t228r = 0;
    std::uint32_t t230 = 0;
    std::uint32_t t231 = 0;
    std::uint32_t t232a = 0, t232b = 0, t232r = 0;
    std::uint32_t t233a = 0;
    std::uint32_t t234 = 0;
    std::uint32_t t235a = 0, t235b = 0, t235r = 0;
    std::uint32_t t237 = 0;
    std::uint32_t t238a = 0, t238b = 0, t238r = 0;
    std::uint32_t t239 = 0;
    std::uint32_t t240 = 0;
    std::uint32_t t241a = 0, t241r = 0;
    std::uint32_t t242a = 0, t242b = 0, t242r = 0;
    std::uint32_t t243a = 0, t243b = 0, t243r = 0;
    std::uint32_t t244a = 0, t244b = 0, t244r = 0;
    std::uint32_t t245 = 0;
    std::uint32_t t246a = 0, t246b = 0, t246r = 0;
    std::uint32_t t247a = 0, t247b = 0, t247r = 0;
    std::uint32_t t249a = 0, t249b = 0, t249r = 0;
    std::uint32_t t250 = 0;
    std::uint32_t t251 = 0;
    std::uint32_t t252 = 0;
    std::uint32_t t253a = 0, t253b = 0, t253r = 0;
    std::uint32_t t254a = 0, t254b = 0, t254r = 0;
    std::uint32_t t255a = 0, t255b = 0, t255r = 0;
    std::uint32_t t256a = 0, t256b = 0, t256r = 0;
    std::uint32_t t258 = 0;
    std::uint32_t t259a = 0, t259b = 0, t259r = 0;
    std::uint32_t t260 = 0;
    std::uint32_t t261a = 0;
    std::uint32_t t262a = 0, t262b = 0, t262r = 0;
    std::uint32_t t263a = 0;
    std::uint32_t t264 = 0;
    std::uint32_t t265 = 0;
    std::uint32_t t266 = 0;
    std::uint32_t t267a = 0;
    std::uint32_t t268 = 0;
    std::uint32_t t269a = 0;
    std::uint32_t t270a = 0, t270b = 0, t270r = 0;
    std::uint32_t t272 = 0;
    std::uint32_t t273a = 0, t273b = 0, t273r = 0;
    std::uint32_t t274 = 0;
    std::uint32_t t275a = 0, t275b = 0, t275r = 0;
    std::uint32_t t276 = 0;
    std::uint32_t t277 = 0;
    std::uint32_t t278a = 0, t278b = 0, t278r = 0;
    std::uint32_t t279a = 0, t279b = 0, t279r = 0;
    std::uint32_t t280 = 0;
    std::uint32_t t281 = 0;
    std::uint32_t t282 = 0;
    std::uint32_t t283 = 0;
    std::uint32_t t284a = 0, t284b = 0, t284r = 0;
    std::uint32_t t285a = 0;
    std::uint32_t t286 = 0;
    std::uint32_t t287 = 0;
    std::uint32_t t288 = 0;
    BatchLiftStatus t289_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t290 = 0;
    std::uint32_t t291 = 0;
    std::uint32_t t292 = 0;
    std::uint32_t t293 = 0;
    std::uint32_t t294 = 0;
    std::uint32_t t295a = 0, t295b = 0, t295r = 0;
    std::uint32_t t297a = 0, t297b = 0, t297r = 0;
    std::uint32_t t298 = 0;
    std::uint32_t t299a = 0, t299b = 0, t299r = 0;
    std::uint32_t t301a = 0, t301b = 0, t301r = 0;
    std::uint32_t t302 = 0;
    std::uint32_t t303a = 0, t303b = 0, t303r = 0;
    std::uint32_t t304 = 0;
    std::uint32_t t305 = 0;
    std::uint32_t t306 = 0;
    std::uint32_t t307a = 0, t307b = 0, t307r = 0;
    std::uint32_t t308a = 0, t308b = 0, t308r = 0;
    std::uint32_t t309 = 0;
    std::uint32_t t310 = 0;
    std::uint32_t t311 = 0;
    std::uint32_t t312a = 0, t312b = 0, t312r = 0;
    std::uint32_t t313a = 0, t313b = 0, t313r = 0;
    std::uint32_t t315 = 0;
    std::uint32_t t316a = 0, t316b = 0, t316r = 0;
    std::uint32_t t317a = 0;
    std::uint32_t t318 = 0;
    std::uint32_t t319 = 0;
    BatchLiftStatus t320_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t321 = 0;
    std::uint32_t t322a = 0;
    std::uint32_t t323a = 0;
    std::uint32_t t324 = 0;
    std::uint32_t t325a = 0;
    std::uint32_t t326a = 0;
    std::uint32_t t327a = 0, t327b = 0, t327r = 0;
    std::uint32_t t329 = 0;
    std::uint32_t t330 = 0;
    std::uint32_t t331 = 0;
    std::uint32_t t332 = 0;
    std::uint32_t t333 = 0;
    std::uint32_t t334 = 0;
    std::uint32_t t335a = 0, t335b = 0, t335r = 0;
    std::uint32_t t336 = 0;
    std::uint32_t t337 = 0;
    std::uint32_t t338a = 0, t338b = 0, t338r = 0;
    std::uint32_t t339 = 0;
    std::uint32_t t340 = 0;
    std::uint32_t t341 = 0;
    std::uint32_t t342a = 0, t342b = 0, t342r = 0;
    std::uint32_t t344a = 0, t344b = 0, t344r = 0;
    std::uint32_t t346 = 0;
    std::uint32_t t347 = 0;
    std::uint32_t t348 = 0;
    std::uint32_t t349 = 0;
    std::uint32_t t350 = 0;
    std::uint32_t t351 = 0;
    std::uint32_t t352 = 0;
    std::uint32_t t353a = 0;
    std::uint32_t t354a = 0;
    std::uint32_t t355a = 0;
    std::uint32_t t356a = 0;
    std::uint32_t t357a = 0, t357b = 0, t357r = 0;
    std::uint32_t t359a = 0;
    std::uint32_t t360a = 0;
    std::uint32_t t361 = 0;
    std::uint32_t t362 = 0;
    BatchLiftStatus t363_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t364 = 0;
    std::uint32_t t365a = 0;
    std::uint32_t t366a = 0;
    std::uint32_t t367a = 0;
    std::uint32_t t368a = 0;
    std::uint32_t t369a = 0, t369b = 0, t369r = 0;
    std::uint32_t t371a = 0;
    std::uint32_t t372a = 0;
    std::uint32_t t373a = 0;
    std::uint32_t t374a = 0, t374b = 0, t374r = 0;
    std::uint32_t t375a = 0;
    std::uint32_t t376a = 0, t376b = 0, t376r = 0;

    // 0x009282e0: 83ec18 SUB
        t0a = state.regs[4];
        t0b = 0x00000018u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x009282e3: 56 PUSH
        batch_guest_pc = 0x009282e3u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009282e4: 57 PUSH
        batch_guest_pc = 0x009282e4u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009282e5: 8b7c2428 MOV
        batch_guest_pc = 0x009282e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t3;
    // 0x009282e9: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x009282eb: 8b4c242c MOV
        batch_guest_pc = 0x009282ebu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x009282ef: 89742408 MOV
        batch_guest_pc = 0x009282efu;
        t6 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x009282f3: 83ff08 CMP
        t7a = state.regs[7];
        t7b = 0x00000008u;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x009282f6: 7724 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0092831c;
    // 0x009282f8: 85c9 TEST
        t9a = state.regs[1];
        t9b = state.regs[1];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x009282fa: 7520 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092831c;
    // 0x009282fc: 8b442430 MOV
        batch_guest_pc = 0x009282fcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00928300: a900040000 TEST
        t12a = state.regs[0];
        t12b = 0x00000400u;
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
    // 0x00928305: 7515 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092831c;
    // 0x00928307: 50 PUSH
        batch_guest_pc = 0x00928307u;
        t14a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00928308: 8b442428 MOV
        batch_guest_pc = 0x00928308u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x0092830c: 50 PUSH
        batch_guest_pc = 0x0092830cu;
        t16a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x0092830d: 8bce MOV
        t17 = state.regs[6];
        state.regs[1] = t17;
    // 0x0092830f: e8ccf8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00927be0u, 0x00928314u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00927be0(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00928314u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928314: 5f POP
        batch_guest_pc = 0x00928314u;
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t19a;
    // 0x00928315: 5e POP
        batch_guest_pc = 0x00928315u;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t20a;
    // 0x00928316: 83c418 ADD
        t21a = state.regs[4];
        t21b = 0x00000018u;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[4] = t21r;
    // 0x00928319: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092831c: 83ff10 CMP
    L_0092831c:
        t23a = state.regs[7];
        t23b = 0x00000010u;
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x0092831f: 7305 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00928326;
    // 0x00928321: bf10000000 MOV
        t25 = 0x00000010u;
        state.regs[7] = t25;
    // 0x00928326: 8d47ff LEA
    L_00928326:
        t26 = static_cast<std::uint32_t>(state.regs[7] + 0xffffffffu);
        state.regs[0] = t26;
    // 0x00928329: 85c7 TEST
        t27a = state.regs[7];
        t27b = state.regs[0];
        t27r = (t27a & t27b) & 0xffffffffu;
        batch_set_logic_flags(state, t27r, 32u);
    // 0x0092832b: 7423 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928350;
    // 0x0092832d: 8bd0 MOV
        t29 = state.regs[0];
        state.regs[2] = t29;
    // 0x0092832f: d1ea SHR
        t30a = state.regs[2];
        t30c = 1u;
        if (t30c != 0u) {
        t30r = static_cast<std::uint32_t>(t30a >> t30c);
        batch_set_shr_flags(state, t30a, t30c, t30r, 32u);
            state.regs[2] = t30r;
        }
    // 0x00928331: 0bc2 OR
        t31a = state.regs[0];
        t31b = state.regs[2];
        t31r = (t31a | t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
        state.regs[0] = t31r;
    // 0x00928333: 8bd0 MOV
        t32 = state.regs[0];
        state.regs[2] = t32;
    // 0x00928335: c1ea02 SHR
        t33a = state.regs[2];
        t33c = 2u;
        if (t33c != 0u) {
        t33r = static_cast<std::uint32_t>(t33a >> t33c);
        batch_set_shr_flags(state, t33a, t33c, t33r, 32u);
            state.regs[2] = t33r;
        }
    // 0x00928338: 0bc2 OR
        t34a = state.regs[0];
        t34b = state.regs[2];
        t34r = (t34a | t34b) & 0xffffffffu;
        batch_set_logic_flags(state, t34r, 32u);
        state.regs[0] = t34r;
    // 0x0092833a: 8bd0 MOV
        t35 = state.regs[0];
        state.regs[2] = t35;
    // 0x0092833c: c1ea04 SHR
        t36a = state.regs[2];
        t36c = 4u;
        if (t36c != 0u) {
        t36r = static_cast<std::uint32_t>(t36a >> t36c);
        batch_set_shr_flags(state, t36a, t36c, t36r, 32u);
            state.regs[2] = t36r;
        }
    // 0x0092833f: 0bc2 OR
        t37a = state.regs[0];
        t37b = state.regs[2];
        t37r = (t37a | t37b) & 0xffffffffu;
        batch_set_logic_flags(state, t37r, 32u);
        state.regs[0] = t37r;
    // 0x00928341: 8bd0 MOV
        t38 = state.regs[0];
        state.regs[2] = t38;
    // 0x00928343: c1ea08 SHR
        t39a = state.regs[2];
        t39c = 8u;
        if (t39c != 0u) {
        t39r = static_cast<std::uint32_t>(t39a >> t39c);
        batch_set_shr_flags(state, t39a, t39c, t39r, 32u);
            state.regs[2] = t39r;
        }
    // 0x00928346: 0bc2 OR
        t40a = state.regs[0];
        t40b = state.regs[2];
        t40r = (t40a | t40b) & 0xffffffffu;
        batch_set_logic_flags(state, t40r, 32u);
        state.regs[0] = t40r;
    // 0x00928348: 8bf8 MOV
        t41 = state.regs[0];
        state.regs[7] = t41;
    // 0x0092834a: c1ef10 SHR
        t42a = state.regs[7];
        t42c = 16u;
        if (t42c != 0u) {
        t42r = static_cast<std::uint32_t>(t42a >> t42c);
        batch_set_shr_flags(state, t42a, t42c, t42r, 32u);
            state.regs[7] = t42r;
        }
    // 0x0092834d: 0bf8 OR
        t43a = state.regs[7];
        t43b = state.regs[0];
        t43r = (t43a | t43b) & 0xffffffffu;
        batch_set_logic_flags(state, t43r, 32u);
        state.regs[7] = t43r;
    // 0x0092834f: 47 INC
        t44a = state.regs[7];
        t44r = static_cast<std::uint32_t>(t44a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t44a, t44r, 32u);
        state.regs[7] = t44r;
    // 0x00928350: f6c107 TEST
    L_00928350:
        t45a = state.regs[1] & 0x000000ffu;
        t45b = 0x00000007u;
        t45r = (t45a & t45b) & 0x000000ffu;
        batch_set_logic_flags(state, t45r, 8u);
    // 0x00928353: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092835f;
    // 0x00928355: 83c107 ADD
        t47a = state.regs[1];
        t47b = 0x00000007u;
        t47r = static_cast<std::uint32_t>(t47a + t47b) & 0xffffffffu;
        batch_set_add_flags(state, t47a, t47b, t47r, 32u);
        state.regs[1] = t47r;
    // 0x00928358: 83e1f8 AND
        t48a = state.regs[1];
        t48b = 0xfffffff8u;
        t48r = (t48a & t48b) & 0xffffffffu;
        batch_set_logic_flags(state, t48r, 32u);
        state.regs[1] = t48r;
    // 0x0092835b: 894c242c MOV
        batch_guest_pc = 0x0092835bu;
        t49 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t49)) return BatchLiftStatus::invalid_memory;
    // 0x0092835f: 53 PUSH
    L_0092835f:
        batch_guest_pc = 0x0092835fu;
        t50a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
    // 0x00928360: 8b5c2428 MOV
        batch_guest_pc = 0x00928360u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t51;
    // 0x00928364: 83c30b ADD
        t52a = state.regs[3];
        t52b = 0x0000000bu;
        t52r = static_cast<std::uint32_t>(t52a + t52b) & 0xffffffffu;
        batch_set_add_flags(state, t52a, t52b, t52r, 32u);
        state.regs[3] = t52r;
    // 0x00928367: 83fb10 CMP
        t53a = state.regs[3];
        t53b = 0x00000010u;
        t53r = static_cast<std::uint32_t>(t53a - t53b) & 0xffffffffu;
        batch_set_sub_flags(state, t53a, t53b, t53r, 32u);
    // 0x0092836a: 7605 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00928371;
    // 0x0092836c: 83e3f8 AND
        t55a = state.regs[3];
        t55b = 0xfffffff8u;
        t55r = (t55a & t55b) & 0xffffffffu;
        batch_set_logic_flags(state, t55r, 32u);
        state.regs[3] = t55r;
    // 0x0092836f: eb05 JMP
        goto L_00928376;
    // 0x00928371: bb10000000 MOV
    L_00928371:
        t57 = 0x00000010u;
        state.regs[3] = t57;
    // 0x00928376: 8b442434 MOV
    L_00928376:
        batch_guest_pc = 0x00928376u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t58;
    // 0x0092837a: 8bd0 MOV
        t59 = state.regs[0];
        state.regs[2] = t59;
    // 0x0092837c: 83e201 AND
        t60a = state.regs[2];
        t60b = 0x00000001u;
        t60r = (t60a & t60b) & 0xffffffffu;
        batch_set_logic_flags(state, t60r, 32u);
        state.regs[2] = t60r;
    // 0x0092837f: 55 PUSH
        batch_guest_pc = 0x0092837fu;
        t61a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x00928380: 89542420 MOV
        batch_guest_pc = 0x00928380u;
        t62 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x00928384: a804 TEST
        t63a = state.regs[0] & 0x000000ffu;
        t63b = 0x00000004u;
        t63r = (t63a & t63b) & 0x000000ffu;
        batch_set_logic_flags(state, t63r, 8u);
    // 0x00928386: 0f84d6010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928562;
    // 0x0092838c: a802 TEST
        t65a = state.regs[0] & 0x000000ffu;
        t65b = 0x00000002u;
        t65r = (t65a & t65b) & 0x000000ffu;
        batch_set_logic_flags(state, t65r, 8u);
    // 0x0092838e: 0f84ce010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928562;
    // 0x00928394: 8d043b LEA
        t67 = static_cast<std::uint32_t>(state.regs[3] + state.regs[7] * 1u + 0x00000000u);
        state.regs[0] = t67;
    // 0x00928397: 8d4c0810 LEA
        t68 = static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000010u);
        state.regs[1] = t68;
    // 0x0092839b: 33c0 XOR
        t69a = state.regs[0];
        t69b = state.regs[0];
        t69r = (t69a ^ t69b) & 0xffffffffu;
        batch_set_logic_flags(state, t69r, 32u);
        state.regs[0] = t69r;
    // 0x0092839d: 894c2424 MOV
        batch_guest_pc = 0x0092839du;
        t70 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x009283a1: 89442414 MOV
        batch_guest_pc = 0x009283a1u;
        t71 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x009283a5: 89442430 MOV
        batch_guest_pc = 0x009283a5u;
        t72 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x009283a9: 81fb00020000 CMP
        t73a = state.regs[3];
        t73b = 0x00000200u;
        t73r = static_cast<std::uint32_t>(t73a - t73b) & 0xffffffffu;
        batch_set_sub_flags(state, t73a, t73b, t73r, 32u);
    // 0x009283af: 730b JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_009283bc;
    // 0x009283b1: 8beb MOV
        t75 = state.regs[3];
        state.regs[5] = t75;
    // 0x009283b3: c1ed03 SHR
        t76a = state.regs[5];
        t76c = 3u;
        if (t76c != 0u) {
        t76r = static_cast<std::uint32_t>(t76a >> t76c);
        batch_set_shr_flags(state, t76a, t76c, t76r, 32u);
            state.regs[5] = t76r;
        }
    // 0x009283b6: 896c241c MOV
        batch_guest_pc = 0x009283b6u;
        t77 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t77)) return BatchLiftStatus::invalid_memory;
    // 0x009283ba: eb0f JMP
        goto L_009283cb;
    // 0x009283bc: 53 PUSH
    L_009283bc:
        batch_guest_pc = 0x009283bcu;
        t79a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t79a)) return BatchLiftStatus::invalid_memory;
    // 0x009283bd: e82ee4ffff CALL
        if (!batch_guest_call32(memory, state, 0x009267f0u, 0x009283c2u)) return BatchLiftStatus::invalid_memory;
        t80_call_status = spore_lift_009267f0(memory, state);
        if (t80_call_status != BatchLiftStatus::returned) return t80_call_status;
        if (state.eip != 0x009283c2u) return BatchLiftStatus::invalid_control_flow;
    // 0x009283c2: 83c404 ADD
        t81a = state.regs[4];
        t81b = 0x00000004u;
        t81r = static_cast<std::uint32_t>(t81a + t81b) & 0xffffffffu;
        batch_set_add_flags(state, t81a, t81b, t81r, 32u);
        state.regs[4] = t81r;
    // 0x009283c5: 8be8 MOV
        t82 = state.regs[0];
        state.regs[5] = t82;
    // 0x009283c7: 8944241c MOV
        batch_guest_pc = 0x009283c7u;
        t83 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t83)) return BatchLiftStatus::invalid_memory;
    // 0x009283cb: 33c9 XOR
    L_009283cb:
        t84a = state.regs[1];
        t84b = state.regs[1];
        t84r = (t84a ^ t84b) & 0xffffffffu;
        batch_set_logic_flags(state, t84r, 32u);
        state.regs[1] = t84r;
    // 0x009283cd: 894c242c MOV
        batch_guest_pc = 0x009283cdu;
        t85 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t85)) return BatchLiftStatus::invalid_memory;
    // 0x009283d1: 85c9 TEST
    L_009283d1:
        t86a = state.regs[1];
        t86b = state.regs[1];
        t86r = (t86a & t86b) & 0xffffffffu;
        batch_set_logic_flags(state, t86r, 32u);
    // 0x009283d3: 750c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009283e1;
    // 0x009283d5: 8d4dff LEA
        t88 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffffu);
        state.regs[1] = t88;
    // 0x009283d8: 8d4630 LEA
        t89 = static_cast<std::uint32_t>(state.regs[6] + 0x00000030u);
        state.regs[0] = t89;
    // 0x009283db: 894c242c MOV
        batch_guest_pc = 0x009283dbu;
        t90 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t90)) return BatchLiftStatus::invalid_memory;
    // 0x009283df: eb04 JMP
        goto L_009283e5;
    // 0x009283e1: 8d44ce28 LEA
    L_009283e1:
        t92 = static_cast<std::uint32_t>(state.regs[6] + state.regs[1] * 8u + 0x00000028u);
        state.regs[0] = t92;
    // 0x009283e5: 8b500c MOV
    L_009283e5:
        batch_guest_pc = 0x009283e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t93)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t93;
    // 0x009283e8: 89442418 MOV
        batch_guest_pc = 0x009283e8u;
        t94 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t94)) return BatchLiftStatus::invalid_memory;
    // 0x009283ec: 3bd0 CMP
        t95a = state.regs[2];
        t95b = state.regs[0];
        t95r = static_cast<std::uint32_t>(t95a - t95b) & 0xffffffffu;
        batch_set_sub_flags(state, t95a, t95b, t95r, 32u);
    // 0x009283ee: 7477 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928467;
    // 0x009283f0: 8b7204 MOV
    L_009283f0:
        batch_guest_pc = 0x009283f0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t97;
    // 0x009283f3: 81e6f8ffff7f AND
        t98a = state.regs[6];
        t98b = 0x7ffffff8u;
        t98r = (t98a & t98b) & 0xffffffffu;
        batch_set_logic_flags(state, t98r, 32u);
        state.regs[6] = t98r;
    // 0x009283f9: 3bf3 CMP
        t99a = state.regs[6];
        t99b = state.regs[3];
        t99r = static_cast<std::uint32_t>(t99a - t99b) & 0xffffffffu;
        batch_set_sub_flags(state, t99a, t99b, t99r, 32u);
    // 0x009283fb: 7255 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00928452;
    // 0x009283fd: 8b442434 MOV
        batch_guest_pc = 0x009283fdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t101)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t101;
    // 0x00928401: 8d0c3a LEA
        t102 = static_cast<std::uint32_t>(state.regs[2] + state.regs[7] * 1u + 0x00000000u);
        state.regs[1] = t102;
    // 0x00928404: 8d4c0107 LEA
        t103 = static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000007u);
        state.regs[1] = t103;
    // 0x00928408: 8bef MOV
        t104 = state.regs[7];
        state.regs[5] = t104;
    // 0x0092840a: f7dd NEG
        t105a = state.regs[5];
        t105r = static_cast<std::uint32_t>(0u - t105a) & 0xffffffffu;
        batch_set_neg_flags(state, t105a, t105r, 32u);
        state.regs[5] = t105r;
    // 0x0092840c: 23cd AND
        t106a = state.regs[1];
        t106b = state.regs[5];
        t106r = (t106a & t106b) & 0xffffffffu;
        batch_set_logic_flags(state, t106r, 32u);
        state.regs[1] = t106r;
    // 0x0092840e: 2bc8 SUB
        t107a = state.regs[1];
        t107b = state.regs[0];
        t107r = static_cast<std::uint32_t>(t107a - t107b) & 0xffffffffu;
        batch_set_sub_flags(state, t107a, t107b, t107r, 32u);
        state.regs[1] = t107r;
    // 0x00928410: 83e908 SUB
        t108a = state.regs[1];
        t108b = 0x00000008u;
        t108r = static_cast<std::uint32_t>(t108a - t108b) & 0xffffffffu;
        batch_set_sub_flags(state, t108a, t108b, t108r, 32u);
        state.regs[1] = t108r;
    // 0x00928413: 03f2 ADD
        t109a = state.regs[6];
        t109b = state.regs[2];
        t109r = static_cast<std::uint32_t>(t109a + t109b) & 0xffffffffu;
        batch_set_add_flags(state, t109a, t109b, t109r, 32u);
        state.regs[6] = t109r;
    // 0x00928415: 8d0419 LEA
        t110 = static_cast<std::uint32_t>(state.regs[1] + state.regs[3] * 1u + 0x00000000u);
        state.regs[0] = t110;
    // 0x00928418: 3bc6 CMP
        t111a = state.regs[0];
        t111b = state.regs[6];
        t111r = static_cast<std::uint32_t>(t111a - t111b) & 0xffffffffu;
        batch_set_sub_flags(state, t111a, t111b, t111r, 32u);
    // 0x0092841a: 7736 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00928452;
    // 0x0092841c: 85c9 TEST
        t113a = state.regs[1];
        t113b = state.regs[1];
        t113r = (t113a & t113b) & 0xffffffffu;
        batch_set_logic_flags(state, t113r, 32u);
    // 0x0092841e: 7432 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928452;
    // 0x00928420: 8b4c2410 MOV
        batch_guest_pc = 0x00928420u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t115)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t115;
    // 0x00928424: 8b8140040000 MOV
        batch_guest_pc = 0x00928424u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t116)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t116;
    // 0x0092842a: 8d880000c0fe LEA
        t117 = static_cast<std::uint32_t>(state.regs[0] + 0xfec00000u);
        state.regs[1] = t117;
    // 0x00928430: 3bd1 CMP
        t118a = state.regs[2];
        t118b = state.regs[1];
        t118r = static_cast<std::uint32_t>(t118a - t118b) & 0xffffffffu;
        batch_set_sub_flags(state, t118a, t118b, t118r, 32u);
    // 0x00928432: 7310 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00928444;
    // 0x00928434: 8b4c2414 MOV
        batch_guest_pc = 0x00928434u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t120;
    // 0x00928438: 85c9 TEST
        t121a = state.regs[1];
        t121b = state.regs[1];
        t121r = (t121a & t121b) & 0xffffffffu;
        batch_set_logic_flags(state, t121r, 32u);
    // 0x0092843a: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928440;
    // 0x0092843c: 3bd1 CMP
        t123a = state.regs[2];
        t123b = state.regs[1];
        t123r = static_cast<std::uint32_t>(t123a - t123b) & 0xffffffffu;
        batch_set_sub_flags(state, t123a, t123b, t123r, 32u);
    // 0x0092843e: 7304 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00928444;
    // 0x00928440: 89542414 MOV
    L_00928440:
        batch_guest_pc = 0x00928440u;
        t125 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t125)) return BatchLiftStatus::invalid_memory;
    // 0x00928444: 3bd0 CMP
    L_00928444:
        t126a = state.regs[2];
        t126b = state.regs[0];
        t126r = static_cast<std::uint32_t>(t126a - t126b) & 0xffffffffu;
        batch_set_sub_flags(state, t126a, t126b, t126r, 32u);
    // 0x00928446: 720a JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00928452;
    // 0x00928448: 3b542430 CMP
        batch_guest_pc = 0x00928448u;
        t128a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t128b)) return BatchLiftStatus::invalid_memory;
        t128r = static_cast<std::uint32_t>(t128a - t128b) & 0xffffffffu;
        batch_set_sub_flags(state, t128a, t128b, t128r, 32u);
    // 0x0092844c: 7604 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00928452;
    // 0x0092844e: 89542430 MOV
        batch_guest_pc = 0x0092844eu;
        t130 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t130)) return BatchLiftStatus::invalid_memory;
    // 0x00928452: 8b520c MOV
    L_00928452:
        batch_guest_pc = 0x00928452u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t131)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t131;
    // 0x00928455: 3b542418 CMP
        batch_guest_pc = 0x00928455u;
        t132a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t132b)) return BatchLiftStatus::invalid_memory;
        t132r = static_cast<std::uint32_t>(t132a - t132b) & 0xffffffffu;
        batch_set_sub_flags(state, t132a, t132b, t132r, 32u);
    // 0x00928459: 7595 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009283f0;
    // 0x0092845b: 8b742410 MOV
        batch_guest_pc = 0x0092845bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t134)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t134;
    // 0x0092845f: 8b6c241c MOV
        batch_guest_pc = 0x0092845fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t135)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t135;
    // 0x00928463: 8b4c242c MOV
        batch_guest_pc = 0x00928463u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t136)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t136;
    // 0x00928467: 41 INC
    L_00928467:
        t137a = state.regs[1];
        t137r = static_cast<std::uint32_t>(t137a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t137a, t137r, 32u);
        state.regs[1] = t137r;
    // 0x00928468: 81f980000000 CMP
        t138a = state.regs[1];
        t138b = 0x00000080u;
        t138r = static_cast<std::uint32_t>(t138a - t138b) & 0xffffffffu;
        batch_set_sub_flags(state, t138a, t138b, t138r, 32u);
    // 0x0092846e: 894c242c MOV
        batch_guest_pc = 0x0092846eu;
        t139 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t139)) return BatchLiftStatus::invalid_memory;
    // 0x00928472: 0f8c59ffffff JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_009283d1;
    // 0x00928478: 8b4c2430 MOV
        batch_guest_pc = 0x00928478u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t141)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t141;
    // 0x0092847c: 85c9 TEST
        t142a = state.regs[1];
        t142b = state.regs[1];
        t142r = (t142a & t142b) & 0xffffffffu;
        batch_set_logic_flags(state, t142r, 32u);
    // 0x0092847e: 740b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092848b;
    // 0x00928480: 837c242000 CMP
        batch_guest_pc = 0x00928480u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t144a)) return BatchLiftStatus::invalid_memory;
        t144b = 0x00000000u;
        t144r = static_cast<std::uint32_t>(t144a - t144b) & 0xffffffffu;
        batch_set_sub_flags(state, t144a, t144b, t144r, 32u);
    // 0x00928485: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092848b;
    // 0x00928487: 6a01 PUSH
        batch_guest_pc = 0x00928487u;
        t146a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t146a)) return BatchLiftStatus::invalid_memory;
    // 0x00928489: eb3a JMP
        goto L_009284c5;
    // 0x0092848b: 8b8640040000 MOV
    L_0092848b:
        batch_guest_pc = 0x0092848bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000440u), t148)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t148;
    // 0x00928491: 8b6804 MOV
        batch_guest_pc = 0x00928491u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t149)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t149;
    // 0x00928494: 81e5f8ffff7f AND
        t150a = state.regs[5];
        t150b = 0x7ffffff8u;
        t150r = (t150a & t150b) & 0xffffffffu;
        batch_set_logic_flags(state, t150r, 32u);
        state.regs[5] = t150r;
    // 0x0092849a: 81fd00004001 CMP
        t151a = state.regs[5];
        t151b = 0x01400000u;
        t151r = static_cast<std::uint32_t>(t151a - t151b) & 0xffffffffu;
        batch_set_sub_flags(state, t151a, t151b, t151r, 32u);
    // 0x009284a0: 7608 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_009284aa;
    // 0x009284a2: 81642438fffeffff AND
        batch_guest_pc = 0x009284a2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t153a)) return BatchLiftStatus::invalid_memory;
        t153b = 0xfffffeffu;
        t153r = (t153a & t153b) & 0xffffffffu;
        batch_set_logic_flags(state, t153r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t153r)) return BatchLiftStatus::invalid_memory;
    // 0x009284aa: 8b4c2414 MOV
    L_009284aa:
        batch_guest_pc = 0x009284aau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t154)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t154;
    // 0x009284ae: 85c9 TEST
        t155a = state.regs[1];
        t155b = state.regs[1];
        t155r = (t155a & t155b) & 0xffffffffu;
        batch_set_logic_flags(state, t155r, 32u);
    // 0x009284b0: 7438 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009284ea;
    // 0x009284b2: 837c242000 CMP
        batch_guest_pc = 0x009284b2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t157a)) return BatchLiftStatus::invalid_memory;
        t157b = 0x00000000u;
        t157r = static_cast<std::uint32_t>(t157a - t157b) & 0xffffffffu;
        batch_set_sub_flags(state, t157a, t157b, t157r, 32u);
    // 0x009284b7: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009284c3;
    // 0x009284b9: f744243800010000 TEST
        batch_guest_pc = 0x009284b9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t159a)) return BatchLiftStatus::invalid_memory;
        t159b = 0x00000100u;
        t159r = (t159a & t159b) & 0xffffffffu;
        batch_set_logic_flags(state, t159r, 32u);
    // 0x009284c1: 7427 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009284ea;
    // 0x009284c3: 6a00 PUSH
    L_009284c3:
        batch_guest_pc = 0x009284c3u;
        t161a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t161a)) return BatchLiftStatus::invalid_memory;
    // 0x009284c5: 8b542438 MOV
    L_009284c5:
        batch_guest_pc = 0x009284c5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t162)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t162;
    // 0x009284c9: 8b4104 MOV
        batch_guest_pc = 0x009284c9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t163)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t163;
    // 0x009284cc: 52 PUSH
        batch_guest_pc = 0x009284ccu;
        t164a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t164a)) return BatchLiftStatus::invalid_memory;
    // 0x009284cd: 57 PUSH
        batch_guest_pc = 0x009284cdu;
        t165a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t165a)) return BatchLiftStatus::invalid_memory;
    // 0x009284ce: 53 PUSH
        batch_guest_pc = 0x009284ceu;
        t166a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t166a)) return BatchLiftStatus::invalid_memory;
    // 0x009284cf: 25f8ffff7f AND
        t167a = state.regs[0];
        t167b = 0x7ffffff8u;
        t167r = (t167a & t167b) & 0xffffffffu;
        batch_set_logic_flags(state, t167r, 32u);
        state.regs[0] = t167r;
    // 0x009284d4: 50 PUSH
        batch_guest_pc = 0x009284d4u;
        t168a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t168a)) return BatchLiftStatus::invalid_memory;
    // 0x009284d5: 51 PUSH
        batch_guest_pc = 0x009284d5u;
        t169a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t169a)) return BatchLiftStatus::invalid_memory;
    // 0x009284d6: 8bce MOV
        t170 = state.regs[6];
        state.regs[1] = t170;
    // 0x009284d8: e813e6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926af0u, 0x009284ddu)) return BatchLiftStatus::invalid_memory;
        t171_call_status = spore_lift_00926af0(memory, state);
        if (t171_call_status != BatchLiftStatus::returned) return t171_call_status;
        if (state.eip != 0x009284ddu) return BatchLiftStatus::invalid_control_flow;
    // 0x009284dd: 5d POP
        batch_guest_pc = 0x009284ddu;
        if (!memory.load32(state.regs[4], t172a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t172a;
    // 0x009284de: 5b POP
        batch_guest_pc = 0x009284deu;
        if (!memory.load32(state.regs[4], t173a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t173a;
    // 0x009284df: 5f POP
        batch_guest_pc = 0x009284dfu;
        if (!memory.load32(state.regs[4], t174a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t174a;
    // 0x009284e0: 83c008 ADD
        t175a = state.regs[0];
        t175b = 0x00000008u;
        t175r = static_cast<std::uint32_t>(t175a + t175b) & 0xffffffffu;
        batch_set_add_flags(state, t175a, t175b, t175r, 32u);
        state.regs[0] = t175r;
    // 0x009284e3: 5e POP
        batch_guest_pc = 0x009284e3u;
        if (!memory.load32(state.regs[4], t176a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t176a;
    // 0x009284e4: 83c418 ADD
        t177a = state.regs[4];
        t177b = 0x00000018u;
        t177r = static_cast<std::uint32_t>(t177a + t177b) & 0xffffffffu;
        batch_set_add_flags(state, t177a, t177b, t177r, 32u);
        state.regs[4] = t177r;
    // 0x009284e7: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009284ea: 8b4c2438 MOV
    L_009284ea:
        batch_guest_pc = 0x009284eau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t179)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t179;
    // 0x009284ee: c1e908 SHR
        t180a = state.regs[1];
        t180c = 8u;
        if (t180c != 0u) {
        t180r = static_cast<std::uint32_t>(t180a >> t180c);
        batch_set_shr_flags(state, t180a, t180c, t180r, 32u);
            state.regs[1] = t180r;
        }
    // 0x009284f1: f6d1 NOT
        t181a = state.regs[1] & 0x000000ffu;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | (((~t181a & 0x000000ffu) << 0u) & 0x000000ffu);
    // 0x009284f3: f6c101 TEST
        t182a = state.regs[1] & 0x000000ffu;
        t182b = 0x00000001u;
        t182r = (t182a & t182b) & 0x000000ffu;
        batch_set_logic_flags(state, t182r, 8u);
    // 0x009284f6: 7462 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092855a;
    // 0x009284f8: 3b6c2424 CMP
        batch_guest_pc = 0x009284f8u;
        t184a = state.regs[5];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t184b)) return BatchLiftStatus::invalid_memory;
        t184r = static_cast<std::uint32_t>(t184a - t184b) & 0xffffffffu;
        batch_set_sub_flags(state, t184a, t184b, t184r, 32u);
    // 0x009284fc: 725c JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0092855a;
    // 0x009284fe: f644243801 TEST
        batch_guest_pc = 0x009284feu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t186a)) return BatchLiftStatus::invalid_memory;
        t186b = 0x00000001u;
        t186r = (t186a & t186b) & 0x000000ffu;
        batch_set_logic_flags(state, t186r, 8u);
    // 0x00928503: 7455 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092855a;
    // 0x00928505: 8b5004 MOV
        batch_guest_pc = 0x00928505u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t188)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t188;
    // 0x00928508: 8b4c2434 MOV
        batch_guest_pc = 0x00928508u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t189)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t189;
    // 0x0092850c: 81e2f8ffff7f AND
        t190a = state.regs[2];
        t190b = 0x7ffffff8u;
        t190r = (t190a & t190b) & 0xffffffffu;
        batch_set_logic_flags(state, t190r, 32u);
        state.regs[2] = t190r;
    // 0x00928512: 2bd3 SUB
        t191a = state.regs[2];
        t191b = state.regs[3];
        t191r = static_cast<std::uint32_t>(t191a - t191b) & 0xffffffffu;
        batch_set_sub_flags(state, t191a, t191b, t191r, 32u);
        state.regs[2] = t191r;
    // 0x00928514: 03d0 ADD
        t192a = state.regs[2];
        t192b = state.regs[0];
        t192r = static_cast<std::uint32_t>(t192a + t192b) & 0xffffffffu;
        batch_set_add_flags(state, t192a, t192b, t192r, 32u);
        state.regs[2] = t192r;
    // 0x00928516: 8d740a08 LEA
        t193 = static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0x00000008u);
        state.regs[6] = t193;
    // 0x0092851a: f7df NEG
        t194a = state.regs[7];
        t194r = static_cast<std::uint32_t>(0u - t194a) & 0xffffffffu;
        batch_set_neg_flags(state, t194a, t194r, 32u);
        state.regs[7] = t194r;
    // 0x0092851c: 23f7 AND
        t195a = state.regs[6];
        t195b = state.regs[7];
        t195r = (t195a & t195b) & 0xffffffffu;
        batch_set_logic_flags(state, t195r, 32u);
        state.regs[6] = t195r;
    // 0x0092851e: 2bf1 SUB
        t196a = state.regs[6];
        t196b = state.regs[1];
        t196r = static_cast<std::uint32_t>(t196a - t196b) & 0xffffffffu;
        batch_set_sub_flags(state, t196a, t196b, t196r, 32u);
        state.regs[6] = t196r;
    // 0x00928520: 83ee08 SUB
        t197a = state.regs[6];
        t197b = 0x00000008u;
        t197r = static_cast<std::uint32_t>(t197a - t197b) & 0xffffffffu;
        batch_set_sub_flags(state, t197a, t197b, t197r, 32u);
        state.regs[6] = t197r;
    // 0x00928523: 8bce MOV
        t198 = state.regs[6];
        state.regs[1] = t198;
    // 0x00928525: 2bc8 SUB
        t199a = state.regs[1];
        t199b = state.regs[0];
        t199r = static_cast<std::uint32_t>(t199a - t199b) & 0xffffffffu;
        batch_set_sub_flags(state, t199a, t199b, t199r, 32u);
        state.regs[1] = t199r;
    // 0x00928527: 2be9 SUB
        t200a = state.regs[5];
        t200b = state.regs[1];
        t200r = static_cast<std::uint32_t>(t200a - t200b) & 0xffffffffu;
        batch_set_sub_flags(state, t200a, t200b, t200r, 32u);
        state.regs[5] = t200r;
    // 0x00928529: 8bd5 MOV
        t201 = state.regs[5];
        state.regs[2] = t201;
    // 0x0092852b: 895604 MOV
        batch_guest_pc = 0x0092852bu;
        t202 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t202)) return BatchLiftStatus::invalid_memory;
    // 0x0092852e: 834c160401 OR
        batch_guest_pc = 0x0092852eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + state.regs[2] * 1u + 0x00000004u), t203a)) return BatchLiftStatus::invalid_memory;
        t203b = 0x00000001u;
        t203r = (t203a | t203b) & 0xffffffffu;
        batch_set_logic_flags(state, t203r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + state.regs[2] * 1u + 0x00000004u), t203r)) return BatchLiftStatus::invalid_memory;
    // 0x00928533: 891416 MOV
        batch_guest_pc = 0x00928533u;
        t204 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + state.regs[2] * 1u + 0x00000000u), t204)) return BatchLiftStatus::invalid_memory;
    // 0x00928536: 8d541604 LEA
        t205 = static_cast<std::uint32_t>(state.regs[6] + state.regs[2] * 1u + 0x00000004u);
        state.regs[2] = t205;
    // 0x0092853a: 8b542410 MOV
        batch_guest_pc = 0x0092853au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t206)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t206;
    // 0x0092853e: 51 PUSH
        batch_guest_pc = 0x0092853eu;
        t207a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t207a)) return BatchLiftStatus::invalid_memory;
    // 0x0092853f: 50 PUSH
        batch_guest_pc = 0x0092853fu;
        t208a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t208a)) return BatchLiftStatus::invalid_memory;
    // 0x00928540: 8bca MOV
        t209 = state.regs[2];
        state.regs[1] = t209;
    // 0x00928542: 898240040000 MOV
        batch_guest_pc = 0x00928542u;
        t210 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000440u), t210)) return BatchLiftStatus::invalid_memory;
    // 0x00928548: e863e3ffff CALL
        if (!batch_guest_call32(memory, state, 0x009268b0u, 0x0092854du)) return BatchLiftStatus::invalid_memory;
        t211_call_status = spore_lift_009268b0(memory, state);
        if (t211_call_status != BatchLiftStatus::returned) return t211_call_status;
        if (state.eip != 0x0092854du) return BatchLiftStatus::invalid_control_flow;
    // 0x0092854d: 5d POP
        batch_guest_pc = 0x0092854du;
        if (!memory.load32(state.regs[4], t212a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t212a;
    // 0x0092854e: 5b POP
        batch_guest_pc = 0x0092854eu;
        if (!memory.load32(state.regs[4], t213a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t213a;
    // 0x0092854f: 5f POP
        batch_guest_pc = 0x0092854fu;
        if (!memory.load32(state.regs[4], t214a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t214a;
    // 0x00928550: 8d4608 LEA
        t215 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[0] = t215;
    // 0x00928553: 5e POP
        batch_guest_pc = 0x00928553u;
        if (!memory.load32(state.regs[4], t216a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t216a;
    // 0x00928554: 83c418 ADD
        t217a = state.regs[4];
        t217b = 0x00000018u;
        t217r = static_cast<std::uint32_t>(t217a + t217b) & 0xffffffffu;
        batch_set_add_flags(state, t217a, t217b, t217r, 32u);
        state.regs[4] = t217r;
    // 0x00928557: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092855a: 8b4c2434 MOV
    L_0092855a:
        batch_guest_pc = 0x0092855au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t219)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t219;
    // 0x0092855e: 8b442438 MOV
        batch_guest_pc = 0x0092855eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t220)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t220;
    // 0x00928562: 50 PUSH
    L_00928562:
        batch_guest_pc = 0x00928562u;
        t221a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t221a)) return BatchLiftStatus::invalid_memory;
    // 0x00928563: 8d043b LEA
        t222 = static_cast<std::uint32_t>(state.regs[3] + state.regs[7] * 1u + 0x00000000u);
        state.regs[0] = t222;
    // 0x00928566: 8d4c0810 LEA
        t223 = static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000010u);
        state.regs[1] = t223;
    // 0x0092856a: 51 PUSH
        batch_guest_pc = 0x0092856au;
        t224a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t224a)) return BatchLiftStatus::invalid_memory;
    // 0x0092856b: 8bce MOV
        t225 = state.regs[6];
        state.regs[1] = t225;
    // 0x0092856d: e86ef6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00927be0u, 0x00928572u)) return BatchLiftStatus::invalid_memory;
        t226_call_status = spore_lift_00927be0(memory, state);
        if (t226_call_status != BatchLiftStatus::returned) return t226_call_status;
        if (state.eip != 0x00928572u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928572: 8bc8 MOV
        t227 = state.regs[0];
        state.regs[1] = t227;
    // 0x00928574: 85c9 TEST
        t228a = state.regs[1];
        t228b = state.regs[1];
        t228r = (t228a & t228b) & 0xffffffffu;
        batch_set_logic_flags(state, t228r, 32u);
    // 0x00928576: 0f84a2010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092871e;
    // 0x0092857c: 8b542434 MOV
        batch_guest_pc = 0x0092857cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t230)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t230;
    // 0x00928580: 8d0411 LEA
        t231 = static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000000u);
        state.regs[0] = t231;
    // 0x00928583: 33d2 XOR
        t232a = state.regs[2];
        t232b = state.regs[2];
        t232r = (t232a ^ t232b) & 0xffffffffu;
        batch_set_logic_flags(state, t232r, 32u);
        state.regs[2] = t232r;
    // 0x00928585: f7f7 DIV
        t233a = state.regs[7];
        if (t233a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::uint64_t dividend = (static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0];
        const std::uint64_t quotient = dividend / t233a;
        if (quotient > 0xffffffffull) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(dividend % t233a);
        }
    // 0x00928587: 8d69f8 LEA
        t234 = static_cast<std::uint32_t>(state.regs[1] + 0xfffffff8u);
        state.regs[5] = t234;
    // 0x0092858a: 85d2 TEST
        t235a = state.regs[2];
        t235b = state.regs[2];
        t235r = (t235a & t235b) & 0xffffffffu;
        batch_set_logic_flags(state, t235r, 32u);
    // 0x0092858c: 0f84a5000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928637;
    // 0x00928592: 8b442434 MOV
        batch_guest_pc = 0x00928592u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t237)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t237;
    // 0x00928596: 03cf ADD
        t238a = state.regs[1];
        t238b = state.regs[7];
        t238r = static_cast<std::uint32_t>(t238a + t238b) & 0xffffffffu;
        batch_set_add_flags(state, t238a, t238b, t238r, 32u);
        state.regs[1] = t238r;
    // 0x00928598: 8d7401ff LEA
        t239 = static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0xffffffffu);
        state.regs[6] = t239;
    // 0x0092859c: 8bcf MOV
        t240 = state.regs[7];
        state.regs[1] = t240;
    // 0x0092859e: f7d9 NEG
        t241a = state.regs[1];
        t241r = static_cast<std::uint32_t>(0u - t241a) & 0xffffffffu;
        batch_set_neg_flags(state, t241a, t241r, 32u);
        state.regs[1] = t241r;
    // 0x009285a0: 23f1 AND
        t242a = state.regs[6];
        t242b = state.regs[1];
        t242r = (t242a & t242b) & 0xffffffffu;
        batch_set_logic_flags(state, t242r, 32u);
        state.regs[6] = t242r;
    // 0x009285a2: 2bf0 SUB
        t243a = state.regs[6];
        t243b = state.regs[0];
        t243r = static_cast<std::uint32_t>(t243a - t243b) & 0xffffffffu;
        batch_set_sub_flags(state, t243a, t243b, t243r, 32u);
        state.regs[6] = t243r;
    // 0x009285a4: 83ee08 SUB
        t244a = state.regs[6];
        t244b = 0x00000008u;
        t244r = static_cast<std::uint32_t>(t244a - t244b) & 0xffffffffu;
        batch_set_sub_flags(state, t244a, t244b, t244r, 32u);
        state.regs[6] = t244r;
    // 0x009285a7: 8bd6 MOV
        t245 = state.regs[6];
        state.regs[2] = t245;
    // 0x009285a9: 2bd5 SUB
        t246a = state.regs[2];
        t246b = state.regs[5];
        t246r = static_cast<std::uint32_t>(t246a - t246b) & 0xffffffffu;
        batch_set_sub_flags(state, t246a, t246b, t246r, 32u);
        state.regs[2] = t246r;
    // 0x009285ab: 83fa10 CMP
        t247a = state.regs[2];
        t247b = 0x00000010u;
        t247r = static_cast<std::uint32_t>(t247a - t247b) & 0xffffffffu;
        batch_set_sub_flags(state, t247a, t247b, t247r, 32u);
    // 0x009285ae: 7302 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_009285b2;
    // 0x009285b0: 03f7 ADD
        t249a = state.regs[6];
        t249b = state.regs[7];
        t249r = static_cast<std::uint32_t>(t249a + t249b) & 0xffffffffu;
        batch_set_add_flags(state, t249a, t249b, t249r, 32u);
        state.regs[6] = t249r;
    // 0x009285b2: 8b4d04 MOV
    L_009285b2:
        batch_guest_pc = 0x009285b2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t250)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t250;
    // 0x009285b5: 8bfe MOV
        t251 = state.regs[6];
        state.regs[7] = t251;
    // 0x009285b7: 8bc1 MOV
        t252 = state.regs[1];
        state.regs[0] = t252;
    // 0x009285b9: 2bfd SUB
        t253a = state.regs[7];
        t253b = state.regs[5];
        t253r = static_cast<std::uint32_t>(t253a - t253b) & 0xffffffffu;
        batch_set_sub_flags(state, t253a, t253b, t253r, 32u);
        state.regs[7] = t253r;
    // 0x009285bb: 25f8ffff7f AND
        t254a = state.regs[0];
        t254b = 0x7ffffff8u;
        t254r = (t254a & t254b) & 0xffffffffu;
        batch_set_logic_flags(state, t254r, 32u);
        state.regs[0] = t254r;
    // 0x009285c0: 2bc7 SUB
        t255a = state.regs[0];
        t255b = state.regs[7];
        t255r = static_cast<std::uint32_t>(t255a - t255b) & 0xffffffffu;
        batch_set_sub_flags(state, t255a, t255b, t255r, 32u);
        state.regs[0] = t255r;
    // 0x009285c2: f6c102 TEST
        t256a = state.regs[1] & 0x000000ffu;
        t256b = 0x00000002u;
        t256r = (t256a & t256b) & 0x000000ffu;
        batch_set_logic_flags(state, t256r, 8u);
    // 0x009285c5: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009285e6;
    // 0x009285c7: 8b4d00 MOV
        batch_guest_pc = 0x009285c7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t258)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t258;
    // 0x009285ca: 03cf ADD
        t259a = state.regs[1];
        t259b = state.regs[7];
        t259r = static_cast<std::uint32_t>(t259a + t259b) & 0xffffffffu;
        batch_set_add_flags(state, t259a, t259b, t259r, 32u);
        state.regs[1] = t259r;
    // 0x009285cc: 8bd0 MOV
        t260 = state.regs[0];
        state.regs[2] = t260;
    // 0x009285ce: 5d POP
        batch_guest_pc = 0x009285ceu;
        if (!memory.load32(state.regs[4], t261a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t261a;
    // 0x009285cf: 83ca02 OR
        t262a = state.regs[2];
        t262b = 0x00000002u;
        t262r = (t262a | t262b) & 0xffffffffu;
        batch_set_logic_flags(state, t262r, 32u);
        state.regs[2] = t262r;
    // 0x009285d2: 5b POP
        batch_guest_pc = 0x009285d2u;
        if (!memory.load32(state.regs[4], t263a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t263a;
    // 0x009285d3: 890e MOV
        batch_guest_pc = 0x009285d3u;
        t264 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t264)) return BatchLiftStatus::invalid_memory;
    // 0x009285d5: 895604 MOV
        batch_guest_pc = 0x009285d5u;
        t265 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t265)) return BatchLiftStatus::invalid_memory;
    // 0x009285d8: 890406 MOV
        batch_guest_pc = 0x009285d8u;
        t266 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + state.regs[0] * 1u + 0x00000000u), t266)) return BatchLiftStatus::invalid_memory;
    // 0x009285db: 5f POP
        batch_guest_pc = 0x009285dbu;
        if (!memory.load32(state.regs[4], t267a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t267a;
    // 0x009285dc: 8d4608 LEA
        t268 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[0] = t268;
    // 0x009285df: 5e POP
        batch_guest_pc = 0x009285dfu;
        if (!memory.load32(state.regs[4], t269a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t269a;
    // 0x009285e0: 83c418 ADD
        t270a = state.regs[4];
        t270b = 0x00000018u;
        t270r = static_cast<std::uint32_t>(t270a + t270b) & 0xffffffffu;
        batch_set_add_flags(state, t270a, t270b, t270r, 32u);
        state.regs[4] = t270r;
    // 0x009285e3: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009285e6: 8bc8 MOV
    L_009285e6:
        t272 = state.regs[0];
        state.regs[1] = t272;
    // 0x009285e8: 83c901 OR
        t273a = state.regs[1];
        t273b = 0x00000001u;
        t273r = (t273a | t273b) & 0xffffffffu;
        batch_set_logic_flags(state, t273r, 32u);
        state.regs[1] = t273r;
    // 0x009285eb: 894e04 MOV
        batch_guest_pc = 0x009285ebu;
        t274 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t274)) return BatchLiftStatus::invalid_memory;
    // 0x009285ee: 834c060401 OR
        batch_guest_pc = 0x009285eeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + state.regs[0] * 1u + 0x00000004u), t275a)) return BatchLiftStatus::invalid_memory;
        t275b = 0x00000001u;
        t275r = (t275a | t275b) & 0xffffffffu;
        batch_set_logic_flags(state, t275r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + state.regs[0] * 1u + 0x00000004u), t275r)) return BatchLiftStatus::invalid_memory;
    // 0x009285f3: 890406 MOV
        batch_guest_pc = 0x009285f3u;
        t276 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + state.regs[0] * 1u + 0x00000000u), t276)) return BatchLiftStatus::invalid_memory;
    // 0x009285f6: 8b5504 MOV
        batch_guest_pc = 0x009285f6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t277)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t277;
    // 0x009285f9: 81e207000080 AND
        t278a = state.regs[2];
        t278b = 0x80000007u;
        t278r = (t278a & t278b) & 0xffffffffu;
        batch_set_logic_flags(state, t278r, 32u);
        state.regs[2] = t278r;
    // 0x009285ff: 0bd7 OR
        t279a = state.regs[2];
        t279b = state.regs[7];
        t279r = (t279a | t279b) & 0xffffffffu;
        batch_set_logic_flags(state, t279r, 32u);
        state.regs[2] = t279r;
    // 0x00928601: 895504 MOV
        batch_guest_pc = 0x00928601u;
        t280 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t280)) return BatchLiftStatus::invalid_memory;
    // 0x00928604: 893e MOV
        batch_guest_pc = 0x00928604u;
        t281 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t281)) return BatchLiftStatus::invalid_memory;
    // 0x00928606: 8b7c2410 MOV
        batch_guest_pc = 0x00928606u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t282)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t282;
    // 0x0092860a: 8b8778040000 MOV
        batch_guest_pc = 0x0092860au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000478u), t283)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t283;
    // 0x00928610: 83c508 ADD
        t284a = state.regs[5];
        t284b = 0x00000008u;
        t284r = static_cast<std::uint32_t>(t284a + t284b) & 0xffffffffu;
        batch_set_add_flags(state, t284a, t284b, t284r, 32u);
        state.regs[5] = t284r;
    // 0x00928613: 55 PUSH
        batch_guest_pc = 0x00928613u;
        t285a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t285a)) return BatchLiftStatus::invalid_memory;
    // 0x00928614: 8bcf MOV
        t286 = state.regs[7];
        state.regs[1] = t286;
    // 0x00928616: 89442438 MOV
        batch_guest_pc = 0x00928616u;
        t287 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t287)) return BatchLiftStatus::invalid_memory;
    // 0x0092861a: c7877804000000000000 MOV
        batch_guest_pc = 0x0092861au;
        t288 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000478u), t288)) return BatchLiftStatus::invalid_memory;
    // 0x00928624: e8a7e9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926fd0u, 0x00928629u)) return BatchLiftStatus::invalid_memory;
        t289_call_status = spore_lift_00926fd0(memory, state);
        if (t289_call_status != BatchLiftStatus::returned) return t289_call_status;
        if (state.eip != 0x00928629u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928629: 8b4c2434 MOV
        batch_guest_pc = 0x00928629u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t290)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t290;
    // 0x0092862d: 8bee MOV
        t291 = state.regs[6];
        state.regs[5] = t291;
    // 0x0092862f: 898f78040000 MOV
        batch_guest_pc = 0x0092862fu;
        t292 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000478u), t292)) return BatchLiftStatus::invalid_memory;
    // 0x00928635: 8bf7 MOV
        t293 = state.regs[7];
        state.regs[6] = t293;
    // 0x00928637: 8b4d04 MOV
    L_00928637:
        batch_guest_pc = 0x00928637u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t294)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t294;
    // 0x0092863a: f6c102 TEST
        t295a = state.regs[1] & 0x000000ffu;
        t295b = 0x00000002u;
        t295r = (t295a & t295b) & 0x000000ffu;
        batch_set_logic_flags(state, t295r, 8u);
    // 0x0092863d: 0f85ce000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00928711;
    // 0x00928643: 81e1f8ffff7f AND
        t297a = state.regs[1];
        t297b = 0x7ffffff8u;
        t297r = (t297a & t297b) & 0xffffffffu;
        batch_set_logic_flags(state, t297r, 32u);
        state.regs[1] = t297r;
    // 0x00928649: 8d5310 LEA
        t298 = static_cast<std::uint32_t>(state.regs[3] + 0x00000010u);
        state.regs[2] = t298;
    // 0x0092864c: 3bca CMP
        t299a = state.regs[1];
        t299b = state.regs[2];
        t299r = static_cast<std::uint32_t>(t299a - t299b) & 0xffffffffu;
        batch_set_sub_flags(state, t299a, t299b, t299r, 32u);
    // 0x0092864e: 0f86bd000000 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00928711;
    // 0x00928654: 2bcb SUB
        t301a = state.regs[1];
        t301b = state.regs[3];
        t301r = static_cast<std::uint32_t>(t301a - t301b) & 0xffffffffu;
        batch_set_sub_flags(state, t301a, t301b, t301r, 32u);
        state.regs[1] = t301r;
    // 0x00928656: 8bd1 MOV
        t302 = state.regs[1];
        state.regs[2] = t302;
    // 0x00928658: 83ca01 OR
        t303a = state.regs[2];
        t303b = 0x00000001u;
        t303r = (t303a | t303b) & 0xffffffffu;
        batch_set_logic_flags(state, t303r, 32u);
        state.regs[2] = t303r;
    // 0x0092865b: 89542b04 MOV
        batch_guest_pc = 0x0092865bu;
        t304 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + state.regs[5] * 1u + 0x00000004u), t304)) return BatchLiftStatus::invalid_memory;
    // 0x0092865f: 8b5504 MOV
        batch_guest_pc = 0x0092865fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t305)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t305;
    // 0x00928662: 8d042b LEA
        t306 = static_cast<std::uint32_t>(state.regs[3] + state.regs[5] * 1u + 0x00000000u);
        state.regs[0] = t306;
    // 0x00928665: 81e207000080 AND
        t307a = state.regs[2];
        t307b = 0x80000007u;
        t307r = (t307a & t307b) & 0xffffffffu;
        batch_set_logic_flags(state, t307r, 32u);
        state.regs[2] = t307r;
    // 0x0092866b: 0bd3 OR
        t308a = state.regs[2];
        t308b = state.regs[3];
        t308r = (t308a | t308b) & 0xffffffffu;
        batch_set_logic_flags(state, t308r, 32u);
        state.regs[2] = t308r;
    // 0x0092866d: 895504 MOV
        batch_guest_pc = 0x0092866du;
        t309 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t309)) return BatchLiftStatus::invalid_memory;
    // 0x00928670: 8b7c0104 MOV
        batch_guest_pc = 0x00928670u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000004u), t310)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t310;
    // 0x00928674: 8d1401 LEA
        t311 = static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000000u);
        state.regs[2] = t311;
    // 0x00928677: 81e7f8ffff7f AND
        t312a = state.regs[7];
        t312b = 0x7ffffff8u;
        t312r = (t312a & t312b) & 0xffffffffu;
        batch_set_logic_flags(state, t312r, 32u);
        state.regs[7] = t312r;
    // 0x0092867d: f644170401 TEST
        batch_guest_pc = 0x0092867du;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + state.regs[2] * 1u + 0x00000004u), t313a)) return BatchLiftStatus::invalid_memory;
        t313b = 0x00000001u;
        t313r = (t313a & t313b) & 0x000000ffu;
        batch_set_logic_flags(state, t313r, 8u);
    // 0x00928682: 742e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009286b2;
    // 0x00928684: 8bbe78040000 MOV
        batch_guest_pc = 0x00928684u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000478u), t315)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t315;
    // 0x0092868a: 83c008 ADD
        t316a = state.regs[0];
        t316b = 0x00000008u;
        t316r = static_cast<std::uint32_t>(t316a + t316b) & 0xffffffffu;
        batch_set_add_flags(state, t316a, t316b, t316r, 32u);
        state.regs[0] = t316r;
    // 0x0092868d: 50 PUSH
        batch_guest_pc = 0x0092868du;
        t317a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t317a)) return BatchLiftStatus::invalid_memory;
    // 0x0092868e: 8bce MOV
        t318 = state.regs[6];
        state.regs[1] = t318;
    // 0x00928690: c7867804000000000000 MOV
        batch_guest_pc = 0x00928690u;
        t319 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000478u), t319)) return BatchLiftStatus::invalid_memory;
    // 0x0092869a: e831e9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926fd0u, 0x0092869fu)) return BatchLiftStatus::invalid_memory;
        t320_call_status = spore_lift_00926fd0(memory, state);
        if (t320_call_status != BatchLiftStatus::returned) return t320_call_status;
        if (state.eip != 0x0092869fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092869f: 8d4508 LEA
        t321 = static_cast<std::uint32_t>(state.regs[5] + 0x00000008u);
        state.regs[0] = t321;
    // 0x009286a2: 5d POP
        batch_guest_pc = 0x009286a2u;
        if (!memory.load32(state.regs[4], t322a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t322a;
    // 0x009286a3: 5b POP
        batch_guest_pc = 0x009286a3u;
        if (!memory.load32(state.regs[4], t323a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t323a;
    // 0x009286a4: 89be78040000 MOV
        batch_guest_pc = 0x009286a4u;
        t324 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000478u), t324)) return BatchLiftStatus::invalid_memory;
    // 0x009286aa: 5f POP
        batch_guest_pc = 0x009286aau;
        if (!memory.load32(state.regs[4], t325a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t325a;
    // 0x009286ab: 5e POP
        batch_guest_pc = 0x009286abu;
        if (!memory.load32(state.regs[4], t326a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t326a;
    // 0x009286ac: 83c418 ADD
        t327a = state.regs[4];
        t327b = 0x00000018u;
        t327r = static_cast<std::uint32_t>(t327a + t327b) & 0xffffffffu;
        batch_set_add_flags(state, t327a, t327b, t327r, 32u);
        state.regs[4] = t327r;
    // 0x009286af: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009286b2: 8b7208 MOV
    L_009286b2:
        batch_guest_pc = 0x009286b2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t329)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t329;
    // 0x009286b5: 8b5a0c MOV
        batch_guest_pc = 0x009286b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t330)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t330;
    // 0x009286b8: 895e0c MOV
        batch_guest_pc = 0x009286b8u;
        t331 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t331)) return BatchLiftStatus::invalid_memory;
    // 0x009286bb: 8b720c MOV
        batch_guest_pc = 0x009286bbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t332)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t332;
    // 0x009286be: 8b5a08 MOV
        batch_guest_pc = 0x009286beu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t333)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t333;
    // 0x009286c1: 895e08 MOV
        batch_guest_pc = 0x009286c1u;
        t334 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t334)) return BatchLiftStatus::invalid_memory;
    // 0x009286c4: 03cf ADD
        t335a = state.regs[1];
        t335b = state.regs[7];
        t335r = static_cast<std::uint32_t>(t335a + t335b) & 0xffffffffu;
        batch_set_add_flags(state, t335a, t335b, t335r, 32u);
        state.regs[1] = t335r;
    // 0x009286c6: 8b7c2410 MOV
        batch_guest_pc = 0x009286c6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t336)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t336;
    // 0x009286ca: 8bf1 MOV
        t337 = state.regs[1];
        state.regs[6] = t337;
    // 0x009286cc: 83ce01 OR
        t338a = state.regs[6];
        t338b = 0x00000001u;
        t338r = (t338a | t338b) & 0xffffffffu;
        batch_set_logic_flags(state, t338r, 32u);
        state.regs[6] = t338r;
    // 0x009286cf: 897004 MOV
        batch_guest_pc = 0x009286cfu;
        t339 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t339)) return BatchLiftStatus::invalid_memory;
    // 0x009286d2: 890c01 MOV
        batch_guest_pc = 0x009286d2u;
        t340 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000000u), t340)) return BatchLiftStatus::invalid_memory;
    // 0x009286d5: 8bb740040000 MOV
        batch_guest_pc = 0x009286d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000440u), t341)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t341;
    // 0x009286db: 3bc6 CMP
        t342a = state.regs[0];
        t342b = state.regs[6];
        t342r = static_cast<std::uint32_t>(t342a - t342b) & 0xffffffffu;
        batch_set_sub_flags(state, t342a, t342b, t342r, 32u);
    // 0x009286dd: 7423 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928702;
    // 0x009286df: 3bd6 CMP
        t344a = state.regs[2];
        t344b = state.regs[6];
        t344r = static_cast<std::uint32_t>(t344a - t344b) & 0xffffffffu;
        batch_set_sub_flags(state, t344a, t344b, t344r, 32u);
    // 0x009286e1: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928702;
    // 0x009286e3: 8b573c MOV
        batch_guest_pc = 0x009286e3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000003cu), t346)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t346;
    // 0x009286e6: 8d4f30 LEA
        t347 = static_cast<std::uint32_t>(state.regs[7] + 0x00000030u);
        state.regs[1] = t347;
    // 0x009286e9: 894808 MOV
        batch_guest_pc = 0x009286e9u;
        t348 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t348)) return BatchLiftStatus::invalid_memory;
    // 0x009286ec: 89500c MOV
        batch_guest_pc = 0x009286ecu;
        t349 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t349)) return BatchLiftStatus::invalid_memory;
    // 0x009286ef: 89410c MOV
        batch_guest_pc = 0x009286efu;
        t350 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t350)) return BatchLiftStatus::invalid_memory;
    // 0x009286f2: 894208 MOV
        batch_guest_pc = 0x009286f2u;
        t351 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t351)) return BatchLiftStatus::invalid_memory;
    // 0x009286f5: 8d4508 LEA
        t352 = static_cast<std::uint32_t>(state.regs[5] + 0x00000008u);
        state.regs[0] = t352;
    // 0x009286f8: 5d POP
        batch_guest_pc = 0x009286f8u;
        if (!memory.load32(state.regs[4], t353a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t353a;
    // 0x009286f9: 5b POP
        batch_guest_pc = 0x009286f9u;
        if (!memory.load32(state.regs[4], t354a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t354a;
    // 0x009286fa: 5f POP
        batch_guest_pc = 0x009286fau;
        if (!memory.load32(state.regs[4], t355a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t355a;
    // 0x009286fb: 5e POP
        batch_guest_pc = 0x009286fbu;
        if (!memory.load32(state.regs[4], t356a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t356a;
    // 0x009286fc: 83c418 ADD
        t357a = state.regs[4];
        t357b = 0x00000018u;
        t357r = static_cast<std::uint32_t>(t357a + t357b) & 0xffffffffu;
        batch_set_add_flags(state, t357a, t357b, t357r, 32u);
        state.regs[4] = t357r;
    // 0x009286ff: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00928702: 51 PUSH
    L_00928702:
        batch_guest_pc = 0x00928702u;
        t359a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t359a)) return BatchLiftStatus::invalid_memory;
    // 0x00928703: 50 PUSH
        batch_guest_pc = 0x00928703u;
        t360a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t360a)) return BatchLiftStatus::invalid_memory;
    // 0x00928704: 8bcf MOV
        t361 = state.regs[7];
        state.regs[1] = t361;
    // 0x00928706: 898740040000 MOV
        batch_guest_pc = 0x00928706u;
        t362 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000440u), t362)) return BatchLiftStatus::invalid_memory;
    // 0x0092870c: e89fe1ffff CALL
        if (!batch_guest_call32(memory, state, 0x009268b0u, 0x00928711u)) return BatchLiftStatus::invalid_memory;
        t363_call_status = spore_lift_009268b0(memory, state);
        if (t363_call_status != BatchLiftStatus::returned) return t363_call_status;
        if (state.eip != 0x00928711u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928711: 8d4508 LEA
    L_00928711:
        t364 = static_cast<std::uint32_t>(state.regs[5] + 0x00000008u);
        state.regs[0] = t364;
    // 0x00928714: 5d POP
        batch_guest_pc = 0x00928714u;
        if (!memory.load32(state.regs[4], t365a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t365a;
    // 0x00928715: 5b POP
        batch_guest_pc = 0x00928715u;
        if (!memory.load32(state.regs[4], t366a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t366a;
    // 0x00928716: 5f POP
        batch_guest_pc = 0x00928716u;
        if (!memory.load32(state.regs[4], t367a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t367a;
    // 0x00928717: 5e POP
        batch_guest_pc = 0x00928717u;
        if (!memory.load32(state.regs[4], t368a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t368a;
    // 0x00928718: 83c418 ADD
        t369a = state.regs[4];
        t369b = 0x00000018u;
        t369r = static_cast<std::uint32_t>(t369a + t369b) & 0xffffffffu;
        batch_set_add_flags(state, t369a, t369b, t369r, 32u);
        state.regs[4] = t369r;
    // 0x0092871b: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092871e: 5d POP
    L_0092871e:
        batch_guest_pc = 0x0092871eu;
        if (!memory.load32(state.regs[4], t371a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t371a;
    // 0x0092871f: 5b POP
        batch_guest_pc = 0x0092871fu;
        if (!memory.load32(state.regs[4], t372a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t372a;
    // 0x00928720: 5f POP
        batch_guest_pc = 0x00928720u;
        if (!memory.load32(state.regs[4], t373a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t373a;
    // 0x00928721: 33c0 XOR
        t374a = state.regs[0];
        t374b = state.regs[0];
        t374r = (t374a ^ t374b) & 0xffffffffu;
        batch_set_logic_flags(state, t374r, 32u);
        state.regs[0] = t374r;
    // 0x00928723: 5e POP
        batch_guest_pc = 0x00928723u;
        if (!memory.load32(state.regs[4], t375a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t375a;
    // 0x00928724: 83c418 ADD
        t376a = state.regs[4];
        t376b = 0x00000018u;
        t376r = static_cast<std::uint32_t>(t376a + t376b) & 0xffffffffu;
        batch_set_add_flags(state, t376a, t376b, t376r, 32u);
        state.regs[4] = t376r;
    // 0x00928727: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
