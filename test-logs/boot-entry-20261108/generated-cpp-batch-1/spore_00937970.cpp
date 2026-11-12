#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0092ce00(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092ce40(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009379c7(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937a2d(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937bd2(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937c10(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937c42(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937cb8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937ce1(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937d1b(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00937d3f(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00937970(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00937970u);
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0, t12r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33a = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    BatchLiftStatus t43_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45a = 0, t45r = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0, t49r = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0, t53r = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0, t55r = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0, t59r = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0, t61r = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t68a = 0, t68r = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71a = 0;
    std::uint32_t t72a = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76a = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78a = 0, t78b = 0, t78r = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86a = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88a = 0, t88b = 0, t88r = 0;
    std::uint32_t t90a = 0;
    std::uint32_t t91a = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94a = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96a = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98a = 0;
    std::uint32_t t99a = 0, t99r = 0;
    std::uint32_t t100a = 0;
    std::uint32_t t101a = 0, t101b = 0, t101r = 0;
    BatchLiftStatus t103_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t105 = 0;
    std::uint32_t t107a = 0, t107r = 0;
    std::uint32_t t108a = 0, t108b = 0, t108r = 0;
    std::uint32_t t112 = 0;
    std::uint32_t t113a = 0, t113b = 0, t113r = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t118 = 0;
    std::uint32_t t119a = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121a = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t123a = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125a = 0;
    std::uint32_t t126a = 0, t126b = 0, t126r = 0;
    BatchLiftStatus t128_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t129 = 0;
    std::uint32_t t130a = 0, t130r = 0;
    std::uint32_t t131a = 0, t131b = 0, t131r = 0;
    std::uint32_t t132a = 0, t132b = 0, t132r = 0;
    std::uint32_t t133 = 0;
    std::uint32_t t135 = 0;
    std::uint32_t t136a = 0, t136b = 0, t136r = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t139a = 0, t139b = 0, t139r = 0;
    std::uint32_t t142 = 0;
    std::uint32_t t143a = 0;
    std::uint32_t t144 = 0;
    std::uint32_t t145a = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t147a = 0;
    std::uint32_t t148a = 0;
    std::uint32_t t149a = 0, t149b = 0, t149r = 0;
    BatchLiftStatus t151_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t152 = 0;
    std::uint32_t t153a = 0, t153b = 0, t153r = 0;
    std::uint32_t t154 = 0;
    std::uint32_t t155 = 0;
    std::uint32_t t156a = 0, t156r = 0;
    std::uint32_t t157a = 0, t157b = 0, t157r = 0;
    std::uint32_t t159a = 0, t159b = 0, t159r = 0;
    std::uint32_t t160a = 0, t160b = 0, t160r = 0;
    std::uint32_t t161 = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163 = 0;
    std::uint32_t t165a = 0, t165b = 0, t165r = 0;
    std::uint32_t t167a = 0, t167b = 0, t167r = 0;
    std::uint32_t t169 = 0;
    std::uint32_t t170 = 0;
    std::uint32_t t171 = 0;
    std::uint32_t t172 = 0;
    std::uint32_t t173a = 0, t173r = 0;
    std::uint32_t t174 = 0;
    std::uint32_t t175a = 0, t175r = 0;
    std::uint32_t t176 = 0;
    std::uint32_t t177a = 0, t177b = 0, t177r = 0;
    std::uint32_t t178a = 0, t178b = 0, t178r = 0;
    std::uint32_t t180 = 0;
    std::uint32_t t181a = 0, t181b = 0, t181r = 0;
    std::uint32_t t183 = 0;
    std::uint32_t t184a = 0, t184b = 0, t184r = 0;
    std::uint32_t t186 = 0;
    std::uint32_t t187 = 0;
    std::uint32_t t188a = 0, t188b = 0, t188r = 0;
    std::uint32_t t190 = 0;
    std::uint32_t t191a = 0, t191b = 0, t191r = 0;
    std::uint32_t t193 = 0;
    std::uint32_t t195 = 0;
    std::uint32_t t196a = 0, t196b = 0, t196r = 0;
    std::uint32_t t198a = 0, t198r = 0;
    std::uint32_t t199 = 0;
    std::uint32_t t200a = 0, t200r = 0;
    std::uint32_t t201a = 0, t201b = 0, t201r = 0;
    std::uint32_t t203a = 0, t203b = 0, t203r = 0;
    std::uint32_t t205a = 0, t205b = 0, t205r = 0;
    std::uint32_t t207 = 0;
    std::uint32_t t208a = 0, t208b = 0, t208r = 0;
    std::uint32_t t210a = 0, t210r = 0;
    std::uint32_t t211 = 0;
    std::uint32_t t212a = 0, t212b = 0, t212r = 0;
    std::uint32_t t214 = 0;
    std::uint32_t t215 = 0;
    std::uint32_t t216a = 0, t216b = 0, t216r = 0;
    std::uint32_t t219 = 0;
    std::uint32_t t220a = 0, t220r = 0;
    std::uint32_t t221a = 0, t221r = 0;
    std::uint32_t t222 = 0;
    std::uint32_t t223 = 0;
    std::uint32_t t224a = 0, t224b = 0, t224r = 0;
    std::uint32_t t227a = 0, t227r = 0;
    std::uint32_t t228 = 0;
    std::uint32_t t230 = 0;
    std::uint32_t t231a = 0, t231b = 0, t231r = 0;
    std::uint32_t t232a = 0, t232r = 0;
    std::uint32_t t233a = 0, t233b = 0, t233c = 0, t233r = 0;
    std::uint32_t t234a = 0, t234b = 0, t234r = 0;
    std::uint32_t t235a = 0, t235b = 0, t235r = 0;
    std::uint32_t t236 = 0;
    std::uint32_t t237 = 0;
    std::uint32_t t238 = 0;
    std::uint32_t t239 = 0;
    std::uint32_t t240 = 0;
    std::uint32_t t241a = 0, t241r = 0;
    std::uint32_t t242a = 0, t242b = 0, t242r = 0;
    std::uint32_t t244a = 0, t244b = 0, t244r = 0;
    std::uint32_t t245 = 0;
    std::uint32_t t246 = 0;
    std::uint32_t t248 = 0;
    std::uint32_t t249a = 0, t249b = 0, t249r = 0;
    std::uint32_t t250a = 0, t250b = 0, t250r = 0;
    std::uint32_t t251a = 0, t251b = 0, t251r = 0;
    std::uint32_t t253 = 0;
    std::uint32_t t254 = 0;
    std::uint32_t t255a = 0;
    std::uint32_t t256a = 0, t256c = 0, t256r = 0;
    std::uint32_t t257 = 0;
    std::uint32_t t258a = 0, t258c = 0, t258r = 0;
    std::uint32_t t259a = 0, t259b = 0, t259r = 0;
    std::uint32_t t260 = 0;
    std::uint32_t t261 = 0;
    std::uint32_t t262a = 0;
    std::uint32_t t263a = 0, t263b = 0, t263r = 0;
    std::uint32_t t264a = 0, t264b = 0, t264r = 0;
    std::uint32_t t265a = 0, t265r = 0;
    std::uint32_t t266 = 0;
    std::uint32_t t267 = 0;
    std::uint32_t t268a = 0, t268b = 0, t268r = 0;
    std::uint32_t t270 = 0;
    std::uint32_t t271a = 0, t271b = 0, t271r = 0;
    std::uint32_t t273a = 0, t273r = 0;
    std::uint32_t t274 = 0;
    std::uint32_t t275a = 0, t275b = 0, t275r = 0;
    std::uint32_t t277a = 0, t277r = 0;
    std::uint32_t t278 = 0;
    std::uint32_t t279a = 0, t279r = 0;
    std::uint32_t t280a = 0, t280b = 0, t280r = 0;
    std::uint32_t t282 = 0;
    std::uint32_t t284 = 0;
    std::uint32_t t285 = 0;
    std::uint32_t t286a = 0, t286r = 0;
    std::uint32_t t287 = 0;
    std::uint32_t t288 = 0;
    std::uint32_t t289 = 0;
    std::uint32_t t290a = 0, t290b = 0, t290r = 0;
    std::uint32_t t292 = 0;
    std::uint32_t t294 = 0;
    std::uint32_t t295a = 0, t295r = 0;
    std::uint32_t t296a = 0, t296b = 0, t296r = 0;
    std::uint32_t t298a = 0, t298b = 0, t298r = 0;
    std::uint32_t t300a = 0, t300b = 0, t300r = 0;
    std::uint32_t t302a = 0, t302r = 0;
    std::uint32_t t303 = 0;
    std::uint32_t t304 = 0;
    std::uint32_t t305a = 0, t305b = 0, t305r = 0;
    std::uint32_t t307a = 0, t307b = 0, t307r = 0;
    std::uint32_t t309a = 0, t309b = 0, t309r = 0;
    std::uint32_t t311a = 0, t311b = 0, t311r = 0;
    std::uint32_t t313 = 0;
    std::uint32_t t314a = 0, t314b = 0, t314r = 0;
    std::uint32_t t316a = 0, t316r = 0;
    std::uint32_t t317 = 0;
    std::uint32_t t318 = 0;
    std::uint32_t t319 = 0;
    std::uint32_t t320a = 0, t320r = 0;
    std::uint32_t t321 = 0;
    std::uint32_t t322a = 0, t322b = 0, t322r = 0;
    std::uint32_t t324a = 0, t324r = 0;
    std::uint32_t t325 = 0;
    std::uint32_t t327 = 0;
    std::uint32_t t328a = 0, t328b = 0, t328r = 0;
    std::uint32_t t330a = 0, t330r = 0;
    std::uint32_t t331 = 0;
    std::uint32_t t333a = 0, t333b = 0, t333r = 0;
    std::uint32_t t335a = 0, t335r = 0;
    std::uint32_t t336 = 0;
    std::uint32_t t337a = 0, t337b = 0, t337r = 0;
    std::uint32_t t339a = 0, t339b = 0, t339r = 0;
    std::uint32_t t340 = 0;
    std::uint32_t t341a = 0, t341b = 0, t341r = 0;
    std::uint32_t t343 = 0;
    std::uint32_t t344a = 0, t344r = 0;
    std::uint32_t t345a = 0, t345r = 0;
    std::uint32_t t346 = 0;
    std::uint32_t t347a = 0, t347b = 0, t347r = 0;
    std::uint32_t t349 = 0;
    std::uint32_t t350a = 0;
    std::uint32_t t351a = 0;
    std::uint32_t t352a = 0;
    std::uint32_t t353a = 0;
    std::uint32_t t354a = 0, t354b = 0, t354r = 0;

    // 0x00937970: dd442408 FLD
        if (!batch_guest_fld64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x00937974: 81ec74010000 SUB
        t1a = state.regs[4];
        t1b = 0x00000174u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
        state.regs[4] = t1r;
    // 0x0093797a: 53 PUSH
        batch_guest_pc = 0x0093797au;
        t2a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0093797b: 8b9c247c010000 MOV
        batch_guest_pc = 0x0093797bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000017cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t3;
    // 0x00937982: 55 PUSH
        batch_guest_pc = 0x00937982u;
        t4a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00937983: 8bac248c010000 MOV
        batch_guest_pc = 0x00937983u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000018cu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t5;
    // 0x0093798a: 83ec08 SUB
        t6a = state.regs[4];
        t6b = 0x00000008u;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0093798d: dd1c24 FSTP
        if (!batch_guest_fstp64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00937990: ff15a0c33c01 CALL
        t8_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_isnan", 0x013cc3a0u, 0x00937996u);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00937996u) return BatchLiftStatus::invalid_control_flow;
    // 0x00937996: 83c408 ADD
        t9a = state.regs[4];
        t9b = 0x00000008u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[4] = t9r;
    // 0x00937999: 85c0 TEST
        t10a = state.regs[0];
        t10b = state.regs[0];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x0093799b: 744d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009379ea;
    // 0x0093799d: 4d DEC
        t12a = state.regs[5];
        t12r = static_cast<std::uint32_t>(t12a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t12a, t12r, 32u);
        state.regs[5] = t12r;
    // 0x0093799e: c6450000 MOV
        batch_guest_pc = 0x0093799eu;
        t13 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x009379a2: 4d DEC
        t14a = state.regs[5];
        t14r = static_cast<std::uint32_t>(t14a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t14a, t14r, 32u);
        state.regs[5] = t14r;
    // 0x009379a3: 837b1861 CMP
        batch_guest_pc = 0x009379a3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000018u), t15a)) return BatchLiftStatus::invalid_memory;
        t15b = 0x00000061u;
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x009379a7: 7c10 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_009379b9;
    // 0x009379a9: c645006e MOV
        batch_guest_pc = 0x009379a9u;
        t17 = 0x0000006eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x009379ad: 4d DEC
        t18a = state.regs[5];
        t18r = static_cast<std::uint32_t>(t18a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t18a, t18r, 32u);
        state.regs[5] = t18r;
    // 0x009379ae: c6450061 MOV
        batch_guest_pc = 0x009379aeu;
        t19 = 0x00000061u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x009379b2: 4d DEC
        t20a = state.regs[5];
        t20r = static_cast<std::uint32_t>(t20a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t20a, t20r, 32u);
        state.regs[5] = t20r;
    // 0x009379b3: c645006e MOV
        batch_guest_pc = 0x009379b3u;
        t21 = 0x0000006eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x009379b7: eb0e JMP
        goto L_009379c7;
    // 0x009379b9: c645004e MOV
    L_009379b9:
        batch_guest_pc = 0x009379b9u;
        t23 = 0x0000004eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x009379bd: 4d DEC
        t24a = state.regs[5];
        t24r = static_cast<std::uint32_t>(t24a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t24a, t24r, 32u);
        state.regs[5] = t24r;
    // 0x009379be: c6450041 MOV
        batch_guest_pc = 0x009379beu;
        t25 = 0x00000041u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x009379c2: 4d DEC
        t26a = state.regs[5];
        t26r = static_cast<std::uint32_t>(t26a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t26a, t26r, 32u);
        state.regs[5] = t26r;
    // 0x009379c3: c645004e MOV
        batch_guest_pc = 0x009379c3u;
        t27 = 0x0000004eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x009379c7: 8b8c2488010000 MOV
    L_009379c7:
        batch_guest_pc = 0x009379c7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000188u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t28;
    // 0x009379ce: 81e100000080 AND
        t29a = state.regs[1];
        t29b = 0x80000000u;
        t29r = (t29a & t29b) & 0xffffffffu;
        batch_set_logic_flags(state, t29r, 32u);
        state.regs[1] = t29r;
    // 0x009379d4: 33c0 XOR
        t30a = state.regs[0];
        t30b = state.regs[0];
        t30r = (t30a ^ t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
        state.regs[0] = t30r;
    // 0x009379d6: 0bc1 OR
        t31a = state.regs[0];
        t31b = state.regs[1];
        t31r = (t31a | t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
        state.regs[0] = t31r;
    // 0x009379d8: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009379df;
    // 0x009379da: 4d DEC
        t33a = state.regs[5];
        t33r = static_cast<std::uint32_t>(t33a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t33a, t33r, 32u);
        state.regs[5] = t33r;
    // 0x009379db: c645002d MOV
        batch_guest_pc = 0x009379dbu;
        t34 = 0x0000002du;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x009379df: 8bc5 MOV
    L_009379df:
        t35 = state.regs[5];
        state.regs[0] = t35;
    // 0x009379e1: 5d POP
        batch_guest_pc = 0x009379e1u;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t36a;
    // 0x009379e2: 5b POP
        batch_guest_pc = 0x009379e2u;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t37a;
    // 0x009379e3: 81c474010000 ADD
        t38a = state.regs[4];
        t38b = 0x00000174u;
        t38r = static_cast<std::uint32_t>(t38a + t38b) & 0xffffffffu;
        batch_set_add_flags(state, t38a, t38b, t38r, 32u);
        state.regs[4] = t38r;
    // 0x009379e9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009379ea: dd842484010000 FLD
    L_009379ea:
        if (!batch_guest_fld64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000184u))) return BatchLiftStatus::invalid_memory;
    // 0x009379f1: 83ec08 SUB
        t41a = state.regs[4];
        t41b = 0x00000008u;
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
        state.regs[4] = t41r;
    // 0x009379f4: dd1c24 FSTP
        if (!batch_guest_fstp64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x009379f7: ff15a4c33c01 CALL
        t43_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_finite", 0x013cc3a4u, 0x009379fdu);
        if (t43_call_status != BatchLiftStatus::returned) return t43_call_status;
        if (state.eip != 0x009379fdu) return BatchLiftStatus::invalid_control_flow;
    // 0x009379fd: 83c408 ADD
        t44a = state.regs[4];
        t44b = 0x00000008u;
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        state.regs[4] = t44r;
    // 0x00937a00: 4d DEC
        t45a = state.regs[5];
        t45r = static_cast<std::uint32_t>(t45a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t45a, t45r, 32u);
        state.regs[5] = t45r;
    // 0x00937a01: 85c0 TEST
        t46a = state.regs[0];
        t46b = state.regs[0];
        t46r = (t46a & t46b) & 0xffffffffu;
        batch_set_logic_flags(state, t46r, 32u);
    // 0x00937a03: 754b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937a50;
    // 0x00937a05: 884500 MOV
        batch_guest_pc = 0x00937a05u;
        t48 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00937a08: 4d DEC
        t49a = state.regs[5];
        t49r = static_cast<std::uint32_t>(t49a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t49a, t49r, 32u);
        state.regs[5] = t49r;
    // 0x00937a09: 837b1861 CMP
        batch_guest_pc = 0x00937a09u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000018u), t50a)) return BatchLiftStatus::invalid_memory;
        t50b = 0x00000061u;
        t50r = static_cast<std::uint32_t>(t50a - t50b) & 0xffffffffu;
        batch_set_sub_flags(state, t50a, t50b, t50r, 32u);
    // 0x00937a0d: 7c10 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00937a1f;
    // 0x00937a0f: c6450066 MOV
        batch_guest_pc = 0x00937a0fu;
        t52 = 0x00000066u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00937a13: 4d DEC
        t53a = state.regs[5];
        t53r = static_cast<std::uint32_t>(t53a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t53a, t53r, 32u);
        state.regs[5] = t53r;
    // 0x00937a14: c645006e MOV
        batch_guest_pc = 0x00937a14u;
        t54 = 0x0000006eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t54)) return BatchLiftStatus::invalid_memory;
    // 0x00937a18: 4d DEC
        t55a = state.regs[5];
        t55r = static_cast<std::uint32_t>(t55a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t55a, t55r, 32u);
        state.regs[5] = t55r;
    // 0x00937a19: c6450069 MOV
        batch_guest_pc = 0x00937a19u;
        t56 = 0x00000069u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t56)) return BatchLiftStatus::invalid_memory;
    // 0x00937a1d: eb0e JMP
        goto L_00937a2d;
    // 0x00937a1f: c6450046 MOV
    L_00937a1f:
        batch_guest_pc = 0x00937a1fu;
        t58 = 0x00000046u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x00937a23: 4d DEC
        t59a = state.regs[5];
        t59r = static_cast<std::uint32_t>(t59a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t59a, t59r, 32u);
        state.regs[5] = t59r;
    // 0x00937a24: c645004e MOV
        batch_guest_pc = 0x00937a24u;
        t60 = 0x0000004eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t60)) return BatchLiftStatus::invalid_memory;
    // 0x00937a28: 4d DEC
        t61a = state.regs[5];
        t61r = static_cast<std::uint32_t>(t61a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t61a, t61r, 32u);
        state.regs[5] = t61r;
    // 0x00937a29: c6450049 MOV
        batch_guest_pc = 0x00937a29u;
        t62 = 0x00000049u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x00937a2d: 8b8c2488010000 MOV
    L_00937a2d:
        batch_guest_pc = 0x00937a2du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000188u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t63;
    // 0x00937a34: 81e100000080 AND
        t64a = state.regs[1];
        t64b = 0x80000000u;
        t64r = (t64a & t64b) & 0xffffffffu;
        batch_set_logic_flags(state, t64r, 32u);
        state.regs[1] = t64r;
    // 0x00937a3a: 33c0 XOR
        t65a = state.regs[0];
        t65b = state.regs[0];
        t65r = (t65a ^ t65b) & 0xffffffffu;
        batch_set_logic_flags(state, t65r, 32u);
        state.regs[0] = t65r;
    // 0x00937a3c: 0bc1 OR
        t66a = state.regs[0];
        t66b = state.regs[1];
        t66r = (t66a | t66b) & 0xffffffffu;
        batch_set_logic_flags(state, t66r, 32u);
        state.regs[0] = t66r;
    // 0x00937a3e: 749f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009379df;
    // 0x00937a40: 4d DEC
        t68a = state.regs[5];
        t68r = static_cast<std::uint32_t>(t68a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t68a, t68r, 32u);
        state.regs[5] = t68r;
    // 0x00937a41: c645002d MOV
        batch_guest_pc = 0x00937a41u;
        t69 = 0x0000002du;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t69)) return BatchLiftStatus::invalid_memory;
    // 0x00937a45: 8bc5 MOV
        t70 = state.regs[5];
        state.regs[0] = t70;
    // 0x00937a47: 5d POP
        batch_guest_pc = 0x00937a47u;
        if (!memory.load32(state.regs[4], t71a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t71a;
    // 0x00937a48: 5b POP
        batch_guest_pc = 0x00937a48u;
        if (!memory.load32(state.regs[4], t72a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t72a;
    // 0x00937a49: 81c474010000 ADD
        t73a = state.regs[4];
        t73b = 0x00000174u;
        t73r = static_cast<std::uint32_t>(t73a + t73b) & 0xffffffffu;
        batch_set_add_flags(state, t73a, t73b, t73r, 32u);
        state.regs[4] = t73r;
    // 0x00937a4f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00937a50: 8b4b18 MOV
    L_00937a50:
        batch_guest_pc = 0x00937a50u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000018u), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t75;
    // 0x00937a53: 57 PUSH
        batch_guest_pc = 0x00937a53u;
        t76a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
    // 0x00937a54: 8b7b10 MOV
        batch_guest_pc = 0x00937a54u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000010u), t77)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t77;
    // 0x00937a57: 33c0 XOR
        t78a = state.regs[0];
        t78b = state.regs[0];
        t78r = (t78a ^ t78b) & 0xffffffffu;
        batch_set_logic_flags(state, t78r, 32u);
        state.regs[0] = t78r;
    // 0x00937a59: 81ff08040000 CMP
        t79a = state.regs[7];
        t79b = 0x00000408u;
        t79r = static_cast<std::uint32_t>(t79a - t79b) & 0xffffffffu;
        batch_set_sub_flags(state, t79a, t79b, t79r, 32u);
    // 0x00937a5f: 894c2418 MOV
        batch_guest_pc = 0x00937a5fu;
        t80 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x00937a63: c644240f00 MOV
        batch_guest_pc = 0x00937a63u;
        t81 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000fu), t81)) return BatchLiftStatus::invalid_memory;
    // 0x00937a68: c644240e00 MOV
        batch_guest_pc = 0x00937a68u;
        t82 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000eu), t82)) return BatchLiftStatus::invalid_memory;
    // 0x00937a6d: 884500 MOV
        batch_guest_pc = 0x00937a6du;
        t83 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t83)) return BatchLiftStatus::invalid_memory;
    // 0x00937a70: 0f8fe7020000 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00937d5d;
    // 0x00937a76: 8d41bb LEA
        t85 = static_cast<std::uint32_t>(state.regs[1] + 0xffffffbbu);
        state.regs[0] = t85;
    // 0x00937a79: 56 PUSH
        batch_guest_pc = 0x00937a79u;
        t86a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t86a)) return BatchLiftStatus::invalid_memory;
    // 0x00937a7a: 8bf5 MOV
        t87 = state.regs[5];
        state.regs[6] = t87;
    // 0x00937a7c: 83f821 CMP
        t88a = state.regs[0];
        t88b = 0x00000021u;
        t88r = static_cast<std::uint32_t>(t88a - t88b) & 0xffffffffu;
        batch_set_sub_flags(state, t88a, t88b, t88r, 32u);
    // 0x00937a7f: 7761 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00937ae2;
    // 0x00937a81: 0fb680747d9300 MOVZX
        batch_guest_pc = 0x00937a81u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00937d74u), t90a)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t90a;
    // 0x00937a88: ff2485687d9300 JMP
        batch_guest_pc = 0x00937a88u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] * 4u + 0x00937d68u), t91a)) return BatchLiftStatus::invalid_memory;
        switch (t91a) {
        case 0x00937a8fu: goto L_00937a8f;
        case 0x00937ae2u: goto L_00937ae2;
        case 0x00937b34u: goto L_00937b34;
        default:
        state.eip = t91a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x00937a8f: dd84248c010000 FLD
    L_00937a8f:
        if (!batch_guest_fld64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x0000018cu))) return BatchLiftStatus::invalid_memory;
    // 0x00937a96: 8d4c2424 LEA
        t93 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[1] = t93;
    // 0x00937a9a: 51 PUSH
        batch_guest_pc = 0x00937a9au;
        t94a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t94a)) return BatchLiftStatus::invalid_memory;
    // 0x00937a9b: 8d542424 LEA
        t95 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[2] = t95;
    // 0x00937a9f: 52 PUSH
        batch_guest_pc = 0x00937a9fu;
        t96a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t96a)) return BatchLiftStatus::invalid_memory;
    // 0x00937aa0: 8d44241c LEA
        t97 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[0] = t97;
    // 0x00937aa4: 50 PUSH
        batch_guest_pc = 0x00937aa4u;
        t98a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t98a)) return BatchLiftStatus::invalid_memory;
    // 0x00937aa5: 47 INC
        t99a = state.regs[7];
        t99r = static_cast<std::uint32_t>(t99a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t99a, t99r, 32u);
        state.regs[7] = t99r;
    // 0x00937aa6: 57 PUSH
        batch_guest_pc = 0x00937aa6u;
        t100a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t100a)) return BatchLiftStatus::invalid_memory;
    // 0x00937aa7: 83ec08 SUB
        t101a = state.regs[4];
        t101b = 0x00000008u;
        t101r = static_cast<std::uint32_t>(t101a - t101b) & 0xffffffffu;
        batch_set_sub_flags(state, t101a, t101b, t101r, 32u);
        state.regs[4] = t101r;
    // 0x00937aaa: dd1c24 FSTP
        if (!batch_guest_fstp64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00937aad: e84e53ffff CALL
        if (!batch_guest_call32(memory, state, 0x0092ce00u, 0x00937ab2u)) return BatchLiftStatus::invalid_memory;
        t103_call_status = spore_lift_0092ce00(memory, state);
        if (t103_call_status != BatchLiftStatus::returned) return t103_call_status;
        if (state.eip != 0x00937ab2u) return BatchLiftStatus::invalid_control_flow;
    // 0x00937ab2: d9ee FLDZ
        if (!batch_guest_fldz(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x00937ab4: 8b4c242c MOV
        batch_guest_pc = 0x00937ab4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t105)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t105;
    // 0x00937ab8: dd8424a4010000 FLD
        if (!batch_guest_fld64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x000001a4u))) return BatchLiftStatus::invalid_memory;
    // 0x00937abf: 49 DEC
        t107a = state.regs[1];
        t107r = static_cast<std::uint32_t>(t107a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t107a, t107r, 32u);
        state.regs[1] = t107r;
    // 0x00937ac0: 83c418 ADD
        t108a = state.regs[4];
        t108b = 0x00000018u;
        t108r = static_cast<std::uint32_t>(t108a + t108b) & 0xffffffffu;
        batch_set_add_flags(state, t108a, t108b, t108r, 32u);
        state.regs[4] = t108r;
    // 0x00937ac3: dfe9 FUCOMIP
        if (!batch_guest_x87_compare_stack(state, 1u, 1u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x00937ac5: ddd8 FSTP
        if (!batch_guest_fstp_stack(state, 0u)) return BatchLiftStatus::invalid_x87_state;
    // 0x00937ac7: 9f LAHF
        if (!batch_guest_lahf(state)) return BatchLiftStatus::invalid_control_flow;
    // 0x00937ac8: 894c2418 MOV
        batch_guest_pc = 0x00937ac8u;
        t112 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t112)) return BatchLiftStatus::invalid_memory;
    // 0x00937acc: f6c444 TEST
        t113a = (state.regs[0] >> 8u) & 0x000000ffu;
        t113b = 0x00000044u;
        t113r = (t113a & t113b) & 0x000000ffu;
        batch_set_logic_flags(state, t113r, 8u);
    // 0x00937acf: 0f8a6d010000 JP
        if (((state.eflags & 0x004u) != 0u)) goto L_00937c42;
    // 0x00937ad5: c744241800000000 MOV
        batch_guest_pc = 0x00937ad5u;
        t115 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t115)) return BatchLiftStatus::invalid_memory;
    // 0x00937add: e960010000 JMP
        goto L_00937c42;
    // 0x00937ae2: dd84248c010000 FLD
    L_00937ae2:
        if (!batch_guest_fld64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x0000018cu))) return BatchLiftStatus::invalid_memory;
    // 0x00937ae9: 8d542424 LEA
        t118 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[2] = t118;
    // 0x00937aed: 52 PUSH
        batch_guest_pc = 0x00937aedu;
        t119a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t119a)) return BatchLiftStatus::invalid_memory;
    // 0x00937aee: 8d442424 LEA
        t120 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[0] = t120;
    // 0x00937af2: 50 PUSH
        batch_guest_pc = 0x00937af2u;
        t121a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t121a)) return BatchLiftStatus::invalid_memory;
    // 0x00937af3: 8d4c241c LEA
        t122 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[1] = t122;
    // 0x00937af7: 51 PUSH
        batch_guest_pc = 0x00937af7u;
        t123a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t123a)) return BatchLiftStatus::invalid_memory;
    // 0x00937af8: 8d5701 LEA
        t124 = static_cast<std::uint32_t>(state.regs[7] + 0x00000001u);
        state.regs[2] = t124;
    // 0x00937afb: 52 PUSH
        batch_guest_pc = 0x00937afbu;
        t125a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t125a)) return BatchLiftStatus::invalid_memory;
    // 0x00937afc: 83ec08 SUB
        t126a = state.regs[4];
        t126b = 0x00000008u;
        t126r = static_cast<std::uint32_t>(t126a - t126b) & 0xffffffffu;
        batch_set_sub_flags(state, t126a, t126b, t126r, 32u);
        state.regs[4] = t126r;
    // 0x00937aff: dd1c24 FSTP
        if (!batch_guest_fstp64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00937b02: e8f952ffff CALL
        if (!batch_guest_call32(memory, state, 0x0092ce00u, 0x00937b07u)) return BatchLiftStatus::invalid_memory;
        t128_call_status = spore_lift_0092ce00(memory, state);
        if (t128_call_status != BatchLiftStatus::returned) return t128_call_status;
        if (state.eip != 0x00937b07u) return BatchLiftStatus::invalid_control_flow;
    // 0x00937b07: 8b44242c MOV
        batch_guest_pc = 0x00937b07u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t129)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t129;
    // 0x00937b0b: 48 DEC
        t130a = state.regs[0];
        t130r = static_cast<std::uint32_t>(t130a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t130a, t130r, 32u);
        state.regs[0] = t130r;
    // 0x00937b0c: 83c418 ADD
        t131a = state.regs[4];
        t131b = 0x00000018u;
        t131r = static_cast<std::uint32_t>(t131a + t131b) & 0xffffffffu;
        batch_set_add_flags(state, t131a, t131b, t131r, 32u);
        state.regs[4] = t131r;
    // 0x00937b0f: 807b0800 CMP
        batch_guest_pc = 0x00937b0fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[3] + 0x00000008u), t132a)) return BatchLiftStatus::invalid_memory;
        t132b = 0x00000000u;
        t132r = static_cast<std::uint32_t>(t132a - t132b) & 0x000000ffu;
        batch_set_sub_flags(state, t132a, t132b, t132r, 8u);
    // 0x00937b13: 89442418 MOV
        batch_guest_pc = 0x00937b13u;
        t133 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t133)) return BatchLiftStatus::invalid_memory;
    // 0x00937b17: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937b1e;
    // 0x00937b19: c644241301 MOV
        batch_guest_pc = 0x00937b19u;
        t135 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t135)) return BatchLiftStatus::invalid_memory;
    // 0x00937b1e: 83f8fc CMP
    L_00937b1e:
        t136a = state.regs[0];
        t136b = 0xfffffffcu;
        t136r = static_cast<std::uint32_t>(t136a - t136b) & 0xffffffffu;
        batch_set_sub_flags(state, t136a, t136b, t136r, 32u);
    // 0x00937b21: c644241201 MOV
        batch_guest_pc = 0x00937b21u;
        t137 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000012u), t137)) return BatchLiftStatus::invalid_memory;
    // 0x00937b26: 0f8c01010000 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00937c2d;
    // 0x00937b2c: 3bc7 CMP
        t139a = state.regs[0];
        t139b = state.regs[7];
        t139r = static_cast<std::uint32_t>(t139a - t139b) & 0xffffffffu;
        batch_set_sub_flags(state, t139a, t139b, t139r, 32u);
    // 0x00937b2e: 0f8df9000000 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00937c2d;
    // 0x00937b34: dd84248c010000 FLD
    L_00937b34:
        if (!batch_guest_fld64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x0000018cu))) return BatchLiftStatus::invalid_memory;
    // 0x00937b3b: 8d442424 LEA
        t142 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[0] = t142;
    // 0x00937b3f: 50 PUSH
        batch_guest_pc = 0x00937b3fu;
        t143a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t143a)) return BatchLiftStatus::invalid_memory;
    // 0x00937b40: 8d4c2424 LEA
        t144 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[1] = t144;
    // 0x00937b44: 51 PUSH
        batch_guest_pc = 0x00937b44u;
        t145a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t145a)) return BatchLiftStatus::invalid_memory;
    // 0x00937b45: 8d54241c LEA
        t146 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[2] = t146;
    // 0x00937b49: 52 PUSH
        batch_guest_pc = 0x00937b49u;
        t147a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t147a)) return BatchLiftStatus::invalid_memory;
    // 0x00937b4a: 57 PUSH
        batch_guest_pc = 0x00937b4au;
        t148a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t148a)) return BatchLiftStatus::invalid_memory;
    // 0x00937b4b: 83ec08 SUB
        t149a = state.regs[4];
        t149b = 0x00000008u;
        t149r = static_cast<std::uint32_t>(t149a - t149b) & 0xffffffffu;
        batch_set_sub_flags(state, t149a, t149b, t149r, 32u);
        state.regs[4] = t149r;
    // 0x00937b4e: dd1c24 FSTP
        if (!batch_guest_fstp64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00937b51: e8ea52ffff CALL
        if (!batch_guest_call32(memory, state, 0x0092ce40u, 0x00937b56u)) return BatchLiftStatus::invalid_memory;
        t151_call_status = spore_lift_0092ce40(memory, state);
        if (t151_call_status != BatchLiftStatus::returned) return t151_call_status;
        if (state.eip != 0x00937b56u) return BatchLiftStatus::invalid_control_flow;
    // 0x00937b56: 8d44243c LEA
        t152 = static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu);
        state.regs[0] = t152;
    // 0x00937b5a: 83c418 ADD
        t153a = state.regs[4];
        t153b = 0x00000018u;
        t153r = static_cast<std::uint32_t>(t153a + t153b) & 0xffffffffu;
        batch_set_add_flags(state, t153a, t153b, t153r, 32u);
        state.regs[4] = t153r;
    // 0x00937b5d: 8d5001 LEA
        t154 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t154;
    // 0x00937b60: 8a08 MOV
    L_00937b60:
        batch_guest_pc = 0x00937b60u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t155)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t155 << 0u) & 0x000000ffu);
    // 0x00937b62: 40 INC
        t156a = state.regs[0];
        t156r = static_cast<std::uint32_t>(t156a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t156a, t156r, 32u);
        state.regs[0] = t156r;
    // 0x00937b63: 84c9 TEST
        t157a = state.regs[1] & 0x000000ffu;
        t157b = state.regs[1] & 0x000000ffu;
        t157r = (t157a & t157b) & 0x000000ffu;
        batch_set_logic_flags(state, t157r, 8u);
    // 0x00937b65: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937b60;
    // 0x00937b67: 2bc2 SUB
        t159a = state.regs[0];
        t159b = state.regs[2];
        t159r = static_cast<std::uint32_t>(t159a - t159b) & 0xffffffffu;
        batch_set_sub_flags(state, t159a, t159b, t159r, 32u);
        state.regs[0] = t159r;
    // 0x00937b69: 807b0800 CMP
        batch_guest_pc = 0x00937b69u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[3] + 0x00000008u), t160a)) return BatchLiftStatus::invalid_memory;
        t160b = 0x00000000u;
        t160r = static_cast<std::uint32_t>(t160a - t160b) & 0x000000ffu;
        batch_set_sub_flags(state, t160a, t160b, t160r, 8u);
    // 0x00937b6d: 8bc8 MOV
        t161 = state.regs[0];
        state.regs[1] = t161;
    // 0x00937b6f: 8b442414 MOV
        batch_guest_pc = 0x00937b6fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t162)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t162;
    // 0x00937b73: 894c241c MOV
        batch_guest_pc = 0x00937b73u;
        t163 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t163)) return BatchLiftStatus::invalid_memory;
    // 0x00937b77: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937b8a;
    // 0x00937b79: 3bc1 CMP
        t165a = state.regs[0];
        t165b = state.regs[1];
        t165r = static_cast<std::uint32_t>(t165a - t165b) & 0xffffffffu;
        batch_set_sub_flags(state, t165a, t165b, t165r, 32u);
    // 0x00937b7b: 7c0d JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00937b8a;
    // 0x00937b7d: 807c241200 CMP
        batch_guest_pc = 0x00937b7du;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000012u), t167a)) return BatchLiftStatus::invalid_memory;
        t167b = 0x00000000u;
        t167r = static_cast<std::uint32_t>(t167a - t167b) & 0x000000ffu;
        batch_set_sub_flags(state, t167a, t167b, t167r, 8u);
    // 0x00937b82: 7506 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937b8a;
    // 0x00937b84: 8d75ff LEA
        t169 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffffu);
        state.regs[6] = t169;
    // 0x00937b87: c6062e MOV
        batch_guest_pc = 0x00937b87u;
        t170 = 0x0000002eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t170)) return BatchLiftStatus::invalid_memory;
    // 0x00937b8a: 8d440424 LEA
    L_00937b8a:
        t171 = static_cast<std::uint32_t>(state.regs[4] + state.regs[0] * 1u + 0x00000024u);
        state.regs[0] = t171;
    // 0x00937b8e: 8d4c0c24 LEA
        t172 = static_cast<std::uint32_t>(state.regs[4] + state.regs[1] * 1u + 0x00000024u);
        state.regs[1] = t172;
    // 0x00937b92: 49 DEC
        t173a = state.regs[1];
        t173r = static_cast<std::uint32_t>(t173a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t173a, t173r, 32u);
        state.regs[1] = t173r;
    // 0x00937b93: 89442418 MOV
        batch_guest_pc = 0x00937b93u;
        t174 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t174)) return BatchLiftStatus::invalid_memory;
    // 0x00937b97: 48 DEC
        t175a = state.regs[0];
        t175r = static_cast<std::uint32_t>(t175a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t175a, t175r, 32u);
        state.regs[0] = t175r;
    // 0x00937b98: 8bd1 MOV
        t176 = state.regs[1];
        state.regs[2] = t176;
    // 0x00937b9a: 2bd0 SUB
        t177a = state.regs[2];
        t177b = state.regs[0];
        t177r = static_cast<std::uint32_t>(t177a - t177b) & 0xffffffffu;
        batch_set_sub_flags(state, t177a, t177b, t177r, 32u);
        state.regs[2] = t177r;
    // 0x00937b9c: 3bd7 CMP
        t178a = state.regs[2];
        t178b = state.regs[7];
        t178r = static_cast<std::uint32_t>(t178a - t178b) & 0xffffffffu;
        batch_set_sub_flags(state, t178a, t178b, t178r, 32u);
    // 0x00937b9e: 7e03 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00937ba3;
    // 0x00937ba0: 8d0c38 LEA
        t180 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 1u + 0x00000000u);
        state.regs[1] = t180;
    // 0x00937ba3: 3bc8 CMP
    L_00937ba3:
        t181a = state.regs[1];
        t181b = state.regs[0];
        t181r = static_cast<std::uint32_t>(t181a - t181b) & 0xffffffffu;
        batch_set_sub_flags(state, t181a, t181b, t181r, 32u);
    // 0x00937ba5: 7633 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00937bda;
    // 0x00937ba7: 8d542424 LEA
    L_00937ba7:
        t183 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[2] = t183;
    // 0x00937bab: 3bca CMP
        t184a = state.regs[1];
        t184b = state.regs[2];
        t184r = static_cast<std::uint32_t>(t184a - t184b) & 0xffffffffu;
        batch_set_sub_flags(state, t184a, t184b, t184r, 32u);
    // 0x00937bad: 721a JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00937bc9;
    // 0x00937baf: 8b54241c MOV
        batch_guest_pc = 0x00937bafu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t186)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t186;
    // 0x00937bb3: 8d541424 LEA
        t187 = static_cast<std::uint32_t>(state.regs[4] + state.regs[2] * 1u + 0x00000024u);
        state.regs[2] = t187;
    // 0x00937bb7: 3bca CMP
        t188a = state.regs[1];
        t188b = state.regs[2];
        t188r = static_cast<std::uint32_t>(t188a - t188b) & 0xffffffffu;
        batch_set_sub_flags(state, t188a, t188b, t188r, 32u);
    // 0x00937bb9: 770e JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00937bc9;
    // 0x00937bbb: 8a11 MOV
        batch_guest_pc = 0x00937bbbu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t190)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t190 << 0u) & 0x000000ffu);
    // 0x00937bbd: 80fa30 CMP
        t191a = state.regs[2] & 0x000000ffu;
        t191b = 0x00000030u;
        t191r = static_cast<std::uint32_t>(t191a - t191b) & 0x000000ffu;
        batch_set_sub_flags(state, t191a, t191b, t191r, 8u);
    // 0x00937bc0: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937bcb;
    // 0x00937bc2: c644241300 MOV
        batch_guest_pc = 0x00937bc2u;
        t193 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t193)) return BatchLiftStatus::invalid_memory;
    // 0x00937bc7: eb09 JMP
        goto L_00937bd2;
    // 0x00937bc9: b230 MOV
    L_00937bc9:
        t195 = 0x00000030u;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t195 << 0u) & 0x000000ffu);
    // 0x00937bcb: 807c241300 CMP
    L_00937bcb:
        batch_guest_pc = 0x00937bcbu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t196a)) return BatchLiftStatus::invalid_memory;
        t196b = 0x00000000u;
        t196r = static_cast<std::uint32_t>(t196a - t196b) & 0x000000ffu;
        batch_set_sub_flags(state, t196a, t196b, t196r, 8u);
    // 0x00937bd0: 7503 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937bd5;
    // 0x00937bd2: 4e DEC
    L_00937bd2:
        t198a = state.regs[6];
        t198r = static_cast<std::uint32_t>(t198a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t198a, t198r, 32u);
        state.regs[6] = t198r;
    // 0x00937bd3: 8816 MOV
        batch_guest_pc = 0x00937bd3u;
        t199 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t199)) return BatchLiftStatus::invalid_memory;
    // 0x00937bd5: 49 DEC
    L_00937bd5:
        t200a = state.regs[1];
        t200r = static_cast<std::uint32_t>(t200a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t200a, t200r, 32u);
        state.regs[1] = t200r;
    // 0x00937bd6: 3bc8 CMP
        t201a = state.regs[1];
        t201b = state.regs[0];
        t201r = static_cast<std::uint32_t>(t201a - t201b) & 0xffffffffu;
        batch_set_sub_flags(state, t201a, t201b, t201r, 32u);
    // 0x00937bd8: 77cd JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00937ba7;
    // 0x00937bda: 803e00 CMP
    L_00937bda:
        batch_guest_pc = 0x00937bdau;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t203a)) return BatchLiftStatus::invalid_memory;
        t203b = 0x00000000u;
        t203r = static_cast<std::uint32_t>(t203a - t203b) & 0x000000ffu;
        batch_set_sub_flags(state, t203a, t203b, t203r, 8u);
    // 0x00937bdd: 7507 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937be6;
    // 0x00937bdf: 807c241200 CMP
        batch_guest_pc = 0x00937bdfu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000012u), t205a)) return BatchLiftStatus::invalid_memory;
        t205b = 0x00000000u;
        t205r = static_cast<std::uint32_t>(t205a - t205b) & 0x000000ffu;
        batch_set_sub_flags(state, t205a, t205b, t205r, 8u);
    // 0x00937be4: 750e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937bf4;
    // 0x00937be6: 8b442414 MOV
    L_00937be6:
        batch_guest_pc = 0x00937be6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t207)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t207;
    // 0x00937bea: 3b44241c CMP
        batch_guest_pc = 0x00937beau;
        t208a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t208b)) return BatchLiftStatus::invalid_memory;
        t208r = static_cast<std::uint32_t>(t208a - t208b) & 0xffffffffu;
        batch_set_sub_flags(state, t208a, t208b, t208r, 32u);
    // 0x00937bee: 7d04 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00937bf4;
    // 0x00937bf0: 4e DEC
        t210a = state.regs[6];
        t210r = static_cast<std::uint32_t>(t210a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t210a, t210r, 32u);
        state.regs[6] = t210r;
    // 0x00937bf1: c6062e MOV
        batch_guest_pc = 0x00937bf1u;
        t211 = 0x0000002eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t211)) return BatchLiftStatus::invalid_memory;
    // 0x00937bf4: 837c241400 CMP
    L_00937bf4:
        batch_guest_pc = 0x00937bf4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t212a)) return BatchLiftStatus::invalid_memory;
        t212b = 0x00000000u;
        t212r = static_cast<std::uint32_t>(t212a - t212b) & 0xffffffffu;
        batch_set_sub_flags(state, t212a, t212b, t212r, 32u);
    // 0x00937bf9: 7e29 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00937c24;
    // 0x00937bfb: 8b442418 MOV
        batch_guest_pc = 0x00937bfbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t214)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t214;
    // 0x00937bff: 8d4c2424 LEA
        t215 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[1] = t215;
    // 0x00937c03: 3bc1 CMP
        t216a = state.regs[0];
        t216b = state.regs[1];
        t216r = static_cast<std::uint32_t>(t216a - t216b) & 0xffffffffu;
        batch_set_sub_flags(state, t216a, t216b, t216r, 32u);
    // 0x00937c05: 0f8610010000 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00937d1b;
    // 0x00937c0b: eb03 JMP
        goto L_00937c10;
    // 0x00937c10: 8a50ff MOV
    L_00937c10:
        batch_guest_pc = 0x00937c10u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0xffffffffu), t219)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t219 << 0u) & 0x000000ffu);
    // 0x00937c13: 48 DEC
        t220a = state.regs[0];
        t220r = static_cast<std::uint32_t>(t220a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t220a, t220r, 32u);
        state.regs[0] = t220r;
    // 0x00937c14: 4e DEC
        t221a = state.regs[6];
        t221r = static_cast<std::uint32_t>(t221a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t221a, t221r, 32u);
        state.regs[6] = t221r;
    // 0x00937c15: 8d4c2424 LEA
        t222 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[1] = t222;
    // 0x00937c19: 8816 MOV
        batch_guest_pc = 0x00937c19u;
        t223 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t223)) return BatchLiftStatus::invalid_memory;
    // 0x00937c1b: 3bc1 CMP
        t224a = state.regs[0];
        t224b = state.regs[1];
        t224r = static_cast<std::uint32_t>(t224a - t224b) & 0xffffffffu;
        batch_set_sub_flags(state, t224a, t224b, t224r, 32u);
    // 0x00937c1d: 77f1 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00937c10;
    // 0x00937c1f: e9f7000000 JMP
        goto L_00937d1b;
    // 0x00937c24: 4e DEC
    L_00937c24:
        t227a = state.regs[6];
        t227r = static_cast<std::uint32_t>(t227a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t227a, t227r, 32u);
        state.regs[6] = t227r;
    // 0x00937c25: c60630 MOV
        batch_guest_pc = 0x00937c25u;
        t228 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t228)) return BatchLiftStatus::invalid_memory;
    // 0x00937c28: e9ee000000 JMP
        goto L_00937d1b;
    // 0x00937c2d: 8b54241c MOV
    L_00937c2d:
        batch_guest_pc = 0x00937c2du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t230)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t230;
    // 0x00937c31: 83ea67 SUB
        t231a = state.regs[2];
        t231b = 0x00000067u;
        t231r = static_cast<std::uint32_t>(t231a - t231b) & 0xffffffffu;
        batch_set_sub_flags(state, t231a, t231b, t231r, 32u);
        state.regs[2] = t231r;
    // 0x00937c34: f7da NEG
        t232a = state.regs[2];
        t232r = static_cast<std::uint32_t>(0u - t232a) & 0xffffffffu;
        batch_set_neg_flags(state, t232a, t232r, 32u);
        state.regs[2] = t232r;
    // 0x00937c36: 1bd2 SBB
        t233a = state.regs[2];
        t233b = state.regs[2];
        t233c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t233r = static_cast<std::uint32_t>(t233a - t233b - t233c) & 0xffffffffu;
        batch_set_sbb_flags(state, t233a, t233b, t233c, t233r, 32u);
        state.regs[2] = t233r;
    // 0x00937c38: 83e2e0 AND
        t234a = state.regs[2];
        t234b = 0xffffffe0u;
        t234r = (t234a & t234b) & 0xffffffffu;
        batch_set_logic_flags(state, t234r, 32u);
        state.regs[2] = t234r;
    // 0x00937c3b: 83c265 ADD
        t235a = state.regs[2];
        t235b = 0x00000065u;
        t235r = static_cast<std::uint32_t>(t235a + t235b) & 0xffffffffu;
        batch_set_add_flags(state, t235a, t235b, t235r, 32u);
        state.regs[2] = t235r;
    // 0x00937c3e: 8954241c MOV
        batch_guest_pc = 0x00937c3eu;
        t236 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t236)) return BatchLiftStatus::invalid_memory;
    // 0x00937c42: 8d442424 LEA
    L_00937c42:
        t237 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[0] = t237;
    // 0x00937c46: 8d5001 LEA
        t238 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t238;
    // 0x00937c49: 8da42400000000 LEA
        t239 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t239;
    // 0x00937c50: 8a08 MOV
    L_00937c50:
        batch_guest_pc = 0x00937c50u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t240)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t240 << 0u) & 0x000000ffu);
    // 0x00937c52: 40 INC
        t241a = state.regs[0];
        t241r = static_cast<std::uint32_t>(t241a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t241a, t241r, 32u);
        state.regs[0] = t241r;
    // 0x00937c53: 84c9 TEST
        t242a = state.regs[1] & 0x000000ffu;
        t242b = state.regs[1] & 0x000000ffu;
        t242r = (t242a & t242b) & 0x000000ffu;
        batch_set_logic_flags(state, t242r, 8u);
    // 0x00937c55: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937c50;
    // 0x00937c57: 2bc2 SUB
        t244a = state.regs[0];
        t244b = state.regs[2];
        t244r = static_cast<std::uint32_t>(t244a - t244b) & 0xffffffffu;
        batch_set_sub_flags(state, t244a, t244b, t244r, 32u);
        state.regs[0] = t244r;
    // 0x00937c59: 8bf8 MOV
        t245 = state.regs[0];
        state.regs[7] = t245;
    // 0x00937c5b: 8b442418 MOV
        batch_guest_pc = 0x00937c5bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t246)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t246;
    // 0x00937c5f: 99 CDQ
        state.regs[2] = (state.regs[0] & 0x80000000u) != 0u ? 0xffffffffu : 0u;
    // 0x00937c60: 8bd8 MOV
        t248 = state.regs[0];
        state.regs[3] = t248;
    // 0x00937c62: 33da XOR
        t249a = state.regs[3];
        t249b = state.regs[2];
        t249r = (t249a ^ t249b) & 0xffffffffu;
        batch_set_logic_flags(state, t249r, 32u);
        state.regs[3] = t249r;
    // 0x00937c64: 2bda SUB
        t250a = state.regs[3];
        t250b = state.regs[2];
        t250r = static_cast<std::uint32_t>(t250a - t250b) & 0xffffffffu;
        batch_set_sub_flags(state, t250a, t250b, t250r, 32u);
        state.regs[3] = t250r;
    // 0x00937c66: 85db TEST
        t251a = state.regs[3];
        t251b = state.regs[3];
        t251r = (t251a & t251b) & 0xffffffffu;
        batch_set_logic_flags(state, t251r, 32u);
    // 0x00937c68: 7e2b JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00937c95;
    // 0x00937c6a: 8d9b00000000 LEA
        t253 = static_cast<std::uint32_t>(state.regs[3] + 0x00000000u);
        state.regs[3] = t253;
    // 0x00937c70: b867666666 MOV
    L_00937c70:
        t254 = 0x66666667u;
        state.regs[0] = t254;
    // 0x00937c75: f7eb IMUL
        t255a = state.regs[3];
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(state.regs[0])) * static_cast<std::int32_t>(t255a);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.regs[2] = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x00937c77: c1fa02 SAR
        t256a = state.regs[2];
        t256c = 2u;
        if (t256c != 0u) {
        t256r = (t256a >> t256c) | ((t256a & 0x80000000u) ? (0xffffffffu << (32u - t256c)) : 0u);
        batch_set_sar_flags(state, t256a, t256c, t256r, 32u);
            state.regs[2] = t256r;
        }
    // 0x00937c7a: 8bca MOV
        t257 = state.regs[2];
        state.regs[1] = t257;
    // 0x00937c7c: c1e91f SHR
        t258a = state.regs[1];
        t258c = 31u;
        if (t258c != 0u) {
        t258r = static_cast<std::uint32_t>(t258a >> t258c);
        batch_set_shr_flags(state, t258a, t258c, t258r, 32u);
            state.regs[1] = t258r;
        }
    // 0x00937c7f: 03ca ADD
        t259a = state.regs[1];
        t259b = state.regs[2];
        t259r = static_cast<std::uint32_t>(t259a + t259b) & 0xffffffffu;
        batch_set_add_flags(state, t259a, t259b, t259r, 32u);
        state.regs[1] = t259r;
    // 0x00937c81: 8ac1 MOV
        t260 = state.regs[1] & 0x000000ffu;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t260 << 0u) & 0x000000ffu);
    // 0x00937c83: b20a MOV
        t261 = 0x0000000au;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t261 << 0u) & 0x000000ffu);
    // 0x00937c85: f6ea IMUL
        t262a = state.regs[2] & 0x000000ffu;
        {
        const std::int32_t product = static_cast<std::int32_t>(static_cast<std::int8_t>(state.regs[0])) * static_cast<std::int32_t>(static_cast<std::int8_t>(t262a));
        state.regs[0] = (state.regs[0] & 0xffff0000u) | (static_cast<std::uint32_t>(product) & 0xffffu);
        state.eflags &= ~0x801u;
        if (product < -128 || product > 127) state.eflags |= 0x801u;
        }
    // 0x00937c87: 2ad8 SUB
        t263a = state.regs[3] & 0x000000ffu;
        t263b = state.regs[0] & 0x000000ffu;
        t263r = static_cast<std::uint32_t>(t263a - t263b) & 0x000000ffu;
        batch_set_sub_flags(state, t263a, t263b, t263r, 8u);
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t263r << 0u) & 0x000000ffu);
    // 0x00937c89: 80c330 ADD
        t264a = state.regs[3] & 0x000000ffu;
        t264b = 0x00000030u;
        t264r = static_cast<std::uint32_t>(t264a + t264b) & 0x000000ffu;
        batch_set_add_flags(state, t264a, t264b, t264r, 8u);
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t264r << 0u) & 0x000000ffu);
    // 0x00937c8c: 4e DEC
        t265a = state.regs[6];
        t265r = static_cast<std::uint32_t>(t265a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t265a, t265r, 32u);
        state.regs[6] = t265r;
    // 0x00937c8d: 881e MOV
        batch_guest_pc = 0x00937c8du;
        t266 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t266)) return BatchLiftStatus::invalid_memory;
    // 0x00937c8f: 8bd9 MOV
        t267 = state.regs[1];
        state.regs[3] = t267;
    // 0x00937c91: 85db TEST
        t268a = state.regs[3];
        t268b = state.regs[3];
        t268r = (t268a & t268b) & 0xffffffffu;
        batch_set_logic_flags(state, t268r, 32u);
    // 0x00937c93: 7fdb JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00937c70;
    // 0x00937c95: 8d45ff LEA
    L_00937c95:
        t270 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffffu);
        state.regs[0] = t270;
    // 0x00937c98: 3bf0 CMP
        t271a = state.regs[6];
        t271b = state.regs[0];
        t271r = static_cast<std::uint32_t>(t271a - t271b) & 0xffffffffu;
        batch_set_sub_flags(state, t271a, t271b, t271r, 32u);
    // 0x00937c9a: 720c JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00937ca8;
    // 0x00937c9c: 4e DEC
        t273a = state.regs[6];
        t273r = static_cast<std::uint32_t>(t273a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t273a, t273r, 32u);
        state.regs[6] = t273r;
    // 0x00937c9d: c60630 MOV
        batch_guest_pc = 0x00937c9du;
        t274 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t274)) return BatchLiftStatus::invalid_memory;
    // 0x00937ca0: 3bf0 CMP
        t275a = state.regs[6];
        t275b = state.regs[0];
        t275r = static_cast<std::uint32_t>(t275a - t275b) & 0xffffffffu;
        batch_set_sub_flags(state, t275a, t275b, t275r, 32u);
    // 0x00937ca2: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00937ca8;
    // 0x00937ca4: 4e DEC
        t277a = state.regs[6];
        t277r = static_cast<std::uint32_t>(t277a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t277a, t277r, 32u);
        state.regs[6] = t277r;
    // 0x00937ca5: c60630 MOV
        batch_guest_pc = 0x00937ca5u;
        t278 = 0x00000030u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t278)) return BatchLiftStatus::invalid_memory;
    // 0x00937ca8: 4e DEC
    L_00937ca8:
        t279a = state.regs[6];
        t279r = static_cast<std::uint32_t>(t279a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t279a, t279r, 32u);
        state.regs[6] = t279r;
    // 0x00937ca9: 837c241800 CMP
        batch_guest_pc = 0x00937ca9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t280a)) return BatchLiftStatus::invalid_memory;
        t280b = 0x00000000u;
        t280r = static_cast<std::uint32_t>(t280a - t280b) & 0xffffffffu;
        batch_set_sub_flags(state, t280a, t280b, t280r, 32u);
    // 0x00937cae: 7c05 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00937cb5;
    // 0x00937cb0: c6062b MOV
        batch_guest_pc = 0x00937cb0u;
        t282 = 0x0000002bu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t282)) return BatchLiftStatus::invalid_memory;
    // 0x00937cb3: eb03 JMP
        goto L_00937cb8;
    // 0x00937cb5: c6062d MOV
    L_00937cb5:
        batch_guest_pc = 0x00937cb5u;
        t284 = 0x0000002du;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t284)) return BatchLiftStatus::invalid_memory;
    // 0x00937cb8: 8a54241c MOV
    L_00937cb8:
        batch_guest_pc = 0x00937cb8u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t285)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t285 << 0u) & 0x000000ffu);
    // 0x00937cbc: 4e DEC
        t286a = state.regs[6];
        t286r = static_cast<std::uint32_t>(t286a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t286a, t286r, 32u);
        state.regs[6] = t286r;
    // 0x00937cbd: 8d443c24 LEA
        t287 = static_cast<std::uint32_t>(state.regs[4] + state.regs[7] * 1u + 0x00000024u);
        state.regs[0] = t287;
    // 0x00937cc1: 8d4c2425 LEA
        t288 = static_cast<std::uint32_t>(state.regs[4] + 0x00000025u);
        state.regs[1] = t288;
    // 0x00937cc5: 8816 MOV
        batch_guest_pc = 0x00937cc5u;
        t289 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t289)) return BatchLiftStatus::invalid_memory;
    // 0x00937cc7: 3bc1 CMP
        t290a = state.regs[0];
        t290b = state.regs[1];
        t290r = static_cast<std::uint32_t>(t290a - t290b) & 0xffffffffu;
        batch_set_sub_flags(state, t290a, t290b, t290r, 32u);
    // 0x00937cc9: 7621 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00937cec;
    // 0x00937ccb: 8a5c2413 MOV
        batch_guest_pc = 0x00937ccbu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t292)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t292 << 0u) & 0x000000ffu);
    // 0x00937ccf: 90 NOP
    // 0x00937cd0: 8a48ff MOV
    L_00937cd0:
        batch_guest_pc = 0x00937cd0u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0xffffffffu), t294)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t294 << 0u) & 0x000000ffu);
    // 0x00937cd3: 48 DEC
        t295a = state.regs[0];
        t295r = static_cast<std::uint32_t>(t295a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t295a, t295r, 32u);
        state.regs[0] = t295r;
    // 0x00937cd4: 80f930 CMP
        t296a = state.regs[1] & 0x000000ffu;
        t296b = 0x00000030u;
        t296r = static_cast<std::uint32_t>(t296a - t296b) & 0x000000ffu;
        batch_set_sub_flags(state, t296a, t296b, t296r, 8u);
    // 0x00937cd7: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937cdd;
    // 0x00937cd9: 32db XOR
        t298a = state.regs[3] & 0x000000ffu;
        t298b = state.regs[3] & 0x000000ffu;
        t298r = (t298a ^ t298b) & 0x000000ffu;
        batch_set_logic_flags(state, t298r, 8u);
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t298r << 0u) & 0x000000ffu);
    // 0x00937cdb: eb04 JMP
        goto L_00937ce1;
    // 0x00937cdd: 84db TEST
    L_00937cdd:
        t300a = state.regs[3] & 0x000000ffu;
        t300b = state.regs[3] & 0x000000ffu;
        t300r = (t300a & t300b) & 0x000000ffu;
        batch_set_logic_flags(state, t300r, 8u);
    // 0x00937cdf: 7503 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937ce4;
    // 0x00937ce1: 4e DEC
    L_00937ce1:
        t302a = state.regs[6];
        t302r = static_cast<std::uint32_t>(t302a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t302a, t302r, 32u);
        state.regs[6] = t302r;
    // 0x00937ce2: 880e MOV
        batch_guest_pc = 0x00937ce2u;
        t303 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t303)) return BatchLiftStatus::invalid_memory;
    // 0x00937ce4: 8d4c2425 LEA
    L_00937ce4:
        t304 = static_cast<std::uint32_t>(state.regs[4] + 0x00000025u);
        state.regs[1] = t304;
    // 0x00937ce8: 3bc1 CMP
        t305a = state.regs[0];
        t305b = state.regs[1];
        t305r = static_cast<std::uint32_t>(t305a - t305b) & 0xffffffffu;
        batch_set_sub_flags(state, t305a, t305b, t305r, 32u);
    // 0x00937cea: 77e4 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00937cd0;
    // 0x00937cec: 3816 CMP
    L_00937cec:
        batch_guest_pc = 0x00937cecu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t307a)) return BatchLiftStatus::invalid_memory;
        t307b = state.regs[2] & 0x000000ffu;
        t307r = static_cast<std::uint32_t>(t307a - t307b) & 0x000000ffu;
        batch_set_sub_flags(state, t307a, t307b, t307r, 8u);
    // 0x00937cee: 7507 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937cf7;
    // 0x00937cf0: 807c241200 CMP
        batch_guest_pc = 0x00937cf0u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000012u), t309a)) return BatchLiftStatus::invalid_memory;
        t309b = 0x00000000u;
        t309r = static_cast<std::uint32_t>(t309a - t309b) & 0x000000ffu;
        batch_set_sub_flags(state, t309a, t309b, t309r, 8u);
    // 0x00937cf5: 7516 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937d0d;
    // 0x00937cf7: 83ff01 CMP
    L_00937cf7:
        t311a = state.regs[7];
        t311b = 0x00000001u;
        t311r = static_cast<std::uint32_t>(t311a - t311b) & 0xffffffffu;
        batch_set_sub_flags(state, t311a, t311b, t311r, 32u);
    // 0x00937cfa: 7f0d JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00937d09;
    // 0x00937cfc: 8b942488010000 MOV
        batch_guest_pc = 0x00937cfcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000188u), t313)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t313;
    // 0x00937d03: 807a0800 CMP
        batch_guest_pc = 0x00937d03u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t314a)) return BatchLiftStatus::invalid_memory;
        t314b = 0x00000000u;
        t314r = static_cast<std::uint32_t>(t314a - t314b) & 0x000000ffu;
        batch_set_sub_flags(state, t314a, t314b, t314r, 8u);
    // 0x00937d07: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937d0d;
    // 0x00937d09: 4e DEC
    L_00937d09:
        t316a = state.regs[6];
        t316r = static_cast<std::uint32_t>(t316a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t316a, t316r, 32u);
        state.regs[6] = t316r;
    // 0x00937d0a: c6062e MOV
        batch_guest_pc = 0x00937d0au;
        t317 = 0x0000002eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t317)) return BatchLiftStatus::invalid_memory;
    // 0x00937d0d: 8a442424 MOV
    L_00937d0d:
        batch_guest_pc = 0x00937d0du;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t318)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t318 << 0u) & 0x000000ffu);
    // 0x00937d11: 8b9c2488010000 MOV
        batch_guest_pc = 0x00937d11u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000188u), t319)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t319;
    // 0x00937d18: 4e DEC
        t320a = state.regs[6];
        t320r = static_cast<std::uint32_t>(t320a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t320a, t320r, 32u);
        state.regs[6] = t320r;
    // 0x00937d19: 8806 MOV
        batch_guest_pc = 0x00937d19u;
        t321 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t321)) return BatchLiftStatus::invalid_memory;
    // 0x00937d1b: 837c242000 CMP
    L_00937d1b:
        batch_guest_pc = 0x00937d1bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t322a)) return BatchLiftStatus::invalid_memory;
        t322b = 0x00000000u;
        t322r = static_cast<std::uint32_t>(t322a - t322b) & 0xffffffffu;
        batch_set_sub_flags(state, t322a, t322b, t322r, 32u);
    // 0x00937d20: 7406 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00937d28;
    // 0x00937d22: 4e DEC
        t324a = state.regs[6];
        t324r = static_cast<std::uint32_t>(t324a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t324a, t324r, 32u);
        state.regs[6] = t324r;
    // 0x00937d23: c6062d MOV
        batch_guest_pc = 0x00937d23u;
        t325 = 0x0000002du;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t325)) return BatchLiftStatus::invalid_memory;
    // 0x00937d26: eb17 JMP
        goto L_00937d3f;
    // 0x00937d28: 8b4304 MOV
    L_00937d28:
        batch_guest_pc = 0x00937d28u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t327)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t327;
    // 0x00937d2b: 83f802 CMP
        t328a = state.regs[0];
        t328b = 0x00000002u;
        t328r = static_cast<std::uint32_t>(t328a - t328b) & 0xffffffffu;
        batch_set_sub_flags(state, t328a, t328b, t328r, 32u);
    // 0x00937d2e: 7506 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937d36;
    // 0x00937d30: 4e DEC
        t330a = state.regs[6];
        t330r = static_cast<std::uint32_t>(t330a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t330a, t330r, 32u);
        state.regs[6] = t330r;
    // 0x00937d31: c6062b MOV
        batch_guest_pc = 0x00937d31u;
        t331 = 0x0000002bu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t331)) return BatchLiftStatus::invalid_memory;
    // 0x00937d34: eb09 JMP
        goto L_00937d3f;
    // 0x00937d36: 83f803 CMP
    L_00937d36:
        t333a = state.regs[0];
        t333b = 0x00000003u;
        t333r = static_cast<std::uint32_t>(t333a - t333b) & 0xffffffffu;
        batch_set_sub_flags(state, t333a, t333b, t333r, 32u);
    // 0x00937d39: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937d3f;
    // 0x00937d3b: 4e DEC
        t335a = state.regs[6];
        t335r = static_cast<std::uint32_t>(t335a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t335a, t335r, 32u);
        state.regs[6] = t335r;
    // 0x00937d3c: c60620 MOV
        batch_guest_pc = 0x00937d3cu;
        t336 = 0x00000020u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t336)) return BatchLiftStatus::invalid_memory;
    // 0x00937d3f: 833b01 CMP
    L_00937d3f:
        batch_guest_pc = 0x00937d3fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t337a)) return BatchLiftStatus::invalid_memory;
        t337b = 0x00000001u;
        t337r = static_cast<std::uint32_t>(t337a - t337b) & 0xffffffffu;
        batch_set_sub_flags(state, t337a, t337b, t337r, 32u);
    // 0x00937d42: 7516 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00937d5a;
    // 0x00937d44: 2bee SUB
        t339a = state.regs[5];
        t339b = state.regs[6];
        t339r = static_cast<std::uint32_t>(t339a - t339b) & 0xffffffffu;
        batch_set_sub_flags(state, t339a, t339b, t339r, 32u);
        state.regs[5] = t339r;
    // 0x00937d46: 8bc5 MOV
        t340 = state.regs[5];
        state.regs[0] = t340;
    // 0x00937d48: 3b430c CMP
        batch_guest_pc = 0x00937d48u;
        t341a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000000cu), t341b)) return BatchLiftStatus::invalid_memory;
        t341r = static_cast<std::uint32_t>(t341a - t341b) & 0xffffffffu;
        batch_set_sub_flags(state, t341a, t341b, t341r, 32u);
    // 0x00937d4b: 7d0d JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00937d5a;
    // 0x00937d4d: 8d4900 LEA
        t343 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t343;
    // 0x00937d50: 4e DEC
    L_00937d50:
        t344a = state.regs[6];
        t344r = static_cast<std::uint32_t>(t344a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t344a, t344r, 32u);
        state.regs[6] = t344r;
    // 0x00937d51: 40 INC
        t345a = state.regs[0];
        t345r = static_cast<std::uint32_t>(t345a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t345a, t345r, 32u);
        state.regs[0] = t345r;
    // 0x00937d52: c60620 MOV
        batch_guest_pc = 0x00937d52u;
        t346 = 0x00000020u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t346)) return BatchLiftStatus::invalid_memory;
    // 0x00937d55: 3b430c CMP
        batch_guest_pc = 0x00937d55u;
        t347a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000000cu), t347b)) return BatchLiftStatus::invalid_memory;
        t347r = static_cast<std::uint32_t>(t347a - t347b) & 0xffffffffu;
        batch_set_sub_flags(state, t347a, t347b, t347r, 32u);
    // 0x00937d58: 7cf6 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00937d50;
    // 0x00937d5a: 8bc6 MOV
    L_00937d5a:
        t349 = state.regs[6];
        state.regs[0] = t349;
    // 0x00937d5c: 5e POP
        batch_guest_pc = 0x00937d5cu;
        if (!memory.load32(state.regs[4], t350a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t350a;
    // 0x00937d5d: 5f POP
    L_00937d5d:
        batch_guest_pc = 0x00937d5du;
        if (!memory.load32(state.regs[4], t351a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t351a;
    // 0x00937d5e: 5d POP
        batch_guest_pc = 0x00937d5eu;
        if (!memory.load32(state.regs[4], t352a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t352a;
    // 0x00937d5f: 5b POP
        batch_guest_pc = 0x00937d5fu;
        if (!memory.load32(state.regs[4], t353a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t353a;
    // 0x00937d60: 81c474010000 ADD
        t354a = state.regs[4];
        t354b = 0x00000174u;
        t354r = static_cast<std::uint32_t>(t354a + t354b) & 0xffffffffu;
        batch_set_add_flags(state, t354a, t354b, t354r, 32u);
        state.regs[4] = t354r;
    // 0x00937d66: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
