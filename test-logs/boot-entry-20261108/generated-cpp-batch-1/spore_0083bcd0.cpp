#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00429480(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00454cb0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00455d60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0076e430(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0076e470(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00838ab0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00838f20(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00838ff0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00839090(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00839540(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083a3c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083a830(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083ba40(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083bc50(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083be39(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083bf06(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083bff0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c1b1(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c25c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c440(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c4b1(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c524(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c5b7(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c618(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c649(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c65e(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c6a8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c72f(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0083c731(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0083bcd0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0083bcd0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24a = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    BatchLiftStatus t34_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39 = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42a = 0, t42c = 0, t42r = 0;
    std::uint32_t t43a = 0, t43r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0, t45c = 0, t45r = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0;
    BatchLiftStatus t51_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57a = 0;
    BatchLiftStatus t58_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62a = 0;
    std::uint32_t t63 = 0;
    BatchLiftStatus t64_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67a = 0;
    std::uint32_t t68a = 0, t68c = 0, t68r = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70c = 0, t70r = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t75a = 0;
    std::uint32_t t76a = 0, t76b = 0, t76r = 0;
    std::uint32_t t77a = 0, t77b = 0, t77r = 0;
    std::uint32_t t78a = 0;
    std::uint32_t t79 = 0;
    BatchLiftStatus t80_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86a = 0, t86b = 0, t86r = 0;
    std::uint32_t t88a = 0, t88b = 0, t88r = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96a = 0, t96r = 0;
    std::uint32_t t97a = 0, t97b = 0, t97r = 0;
    std::uint32_t t99a = 0, t99b = 0, t99r = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102a = 0, t102b = 0, t102r = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104a = 0, t104b = 0, t104r = 0;
    std::uint32_t t106a = 0;
    std::uint32_t t107a = 0;
    std::uint32_t t108a = 0;
    std::uint32_t t109a = 0;
    std::uint32_t t110a = 0;
    std::uint32_t t111a = 0;
    BatchLiftStatus t112_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t113a = 0, t113b = 0, t113r = 0;
    std::uint32_t t114a = 0, t114b = 0, t114r = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t118 = 0;
    std::uint32_t t119a = 0;
    std::uint32_t t120a = 0;
    std::uint32_t t121a = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124 = 0;
    BatchLiftStatus t125_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t126a = 0, t126b = 0, t126r = 0;
    std::uint32_t t127a = 0, t127b = 0, t127r = 0;
    std::uint32_t t128 = 0;
    std::uint32_t t129a = 0, t129b = 0, t129r = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132 = 0;
    std::uint32_t t133 = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t135 = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139a = 0, t139b = 0, t139r = 0;
    std::uint32_t t141 = 0;
    std::uint32_t t142a = 0, t142b = 0, t142r = 0;
    std::uint32_t t144 = 0;
    std::uint32_t t145a = 0, t145b = 0, t145r = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t147 = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150 = 0;
    std::uint32_t t151 = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153a = 0, t153r = 0;
    std::uint32_t t154a = 0, t154b = 0, t154r = 0;
    std::uint32_t t156a = 0, t156b = 0, t156r = 0;
    std::uint32_t t157 = 0;
    std::uint32_t t158 = 0;
    std::uint32_t t159a = 0, t159b = 0, t159r = 0;
    std::uint32_t t160 = 0;
    std::uint32_t t161a = 0, t161b = 0, t161r = 0;
    std::uint32_t t163a = 0;
    std::uint32_t t164a = 0;
    std::uint32_t t165a = 0;
    std::uint32_t t166a = 0;
    std::uint32_t t167 = 0;
    std::uint32_t t168a = 0;
    std::uint32_t t169a = 0;
    BatchLiftStatus t170_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t171 = 0;
    std::uint32_t t172 = 0;
    std::uint32_t t173a = 0, t173b = 0, t173r = 0;
    std::uint32_t t174 = 0;
    std::uint32_t t176 = 0;
    std::uint32_t t177 = 0;
    std::uint32_t t178a = 0;
    std::uint32_t t179a = 0;
    std::uint32_t t180a = 0;
    std::uint32_t t181 = 0;
    BatchLiftStatus t182_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t183 = 0;
    std::uint32_t t184a = 0, t184b = 0, t184r = 0;
    std::uint32_t t185a = 0, t185b = 0, t185r = 0;
    std::uint32_t t186a = 0, t186b = 0, t186r = 0;
    std::uint32_t t187 = 0;
    std::uint32_t t188 = 0;
    std::uint32_t t189 = 0;
    std::uint32_t t190 = 0;
    std::uint32_t t191 = 0;
    std::uint32_t t192a = 0;
    std::uint32_t t193 = 0;
    std::uint32_t t194a = 0, t194b = 0, t194r = 0;
    std::uint32_t t195 = 0;
    BatchLiftStatus t196_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t197 = 0;
    std::uint32_t t198 = 0;
    std::uint32_t t199a = 0, t199b = 0, t199r = 0;
    std::uint32_t t200a = 0, t200b = 0, t200r = 0;
    std::uint32_t t202a = 0, t202b = 0, t202r = 0;
    std::uint32_t t204a = 0;
    BatchLiftStatus t205_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t206a = 0, t206b = 0, t206r = 0;
    std::uint32_t t207 = 0;
    std::uint32_t t208 = 0;
    std::uint32_t t209a = 0, t209b = 0, t209r = 0;
    std::uint32_t t210a = 0, t210b = 0, t210r = 0;
    std::uint32_t t212a = 0, t212b = 0, t212r = 0;
    std::uint32_t t214 = 0;
    std::uint32_t t215 = 0;
    std::uint32_t t216a = 0, t216b = 0, t216r = 0;
    std::uint32_t t217 = 0;
    std::uint32_t t218 = 0;
    std::uint32_t t219 = 0;
    std::uint32_t t220 = 0;
    std::uint32_t t221 = 0;
    std::uint32_t t222 = 0;
    std::uint32_t t223 = 0;
    std::uint32_t t224a = 0, t224r = 0;
    std::uint32_t t225a = 0, t225b = 0, t225r = 0;
    std::uint32_t t227a = 0, t227b = 0, t227r = 0;
    std::uint32_t t228 = 0;
    std::uint32_t t229 = 0;
    std::uint32_t t230a = 0, t230b = 0, t230r = 0;
    std::uint32_t t231 = 0;
    std::uint32_t t232a = 0, t232b = 0, t232r = 0;
    std::uint32_t t234a = 0;
    std::uint32_t t235a = 0;
    std::uint32_t t236a = 0;
    std::uint32_t t237a = 0;
    std::uint32_t t238 = 0;
    std::uint32_t t239a = 0;
    std::uint32_t t240a = 0;
    BatchLiftStatus t241_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t242 = 0;
    std::uint32_t t243 = 0;
    std::uint32_t t244a = 0, t244b = 0, t244r = 0;
    std::uint32_t t245 = 0;
    std::uint32_t t247 = 0;
    std::uint32_t t248 = 0;
    std::uint32_t t249a = 0;
    std::uint32_t t250a = 0;
    std::uint32_t t251a = 0;
    std::uint32_t t252 = 0;
    BatchLiftStatus t253_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t254 = 0;
    std::uint32_t t255a = 0, t255b = 0, t255r = 0;
    std::uint32_t t256a = 0, t256b = 0, t256r = 0;
    std::uint32_t t257a = 0, t257b = 0, t257r = 0;
    std::uint32_t t258 = 0;
    std::uint32_t t259 = 0;
    std::uint32_t t260 = 0;
    std::uint32_t t261 = 0;
    std::uint32_t t262 = 0;
    std::uint32_t t263 = 0;
    std::uint32_t t264a = 0;
    std::uint32_t t265a = 0, t265b = 0, t265r = 0;
    std::uint32_t t266 = 0;
    BatchLiftStatus t267_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t268 = 0;
    std::uint32_t t269 = 0;
    std::uint32_t t270a = 0, t270b = 0, t270r = 0;
    std::uint32_t t271a = 0, t271b = 0, t271r = 0;
    std::uint32_t t273a = 0, t273b = 0, t273r = 0;
    std::uint32_t t275a = 0;
    std::uint32_t t277a = 0;
    std::uint32_t t278 = 0;
    std::uint32_t t279a = 0;
    std::uint32_t t280 = 0;
    std::uint32_t t281a = 0;
    BatchLiftStatus t282_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t283a = 0, t283b = 0, t283r = 0;
    std::uint32_t t284 = 0;
    std::uint32_t t285 = 0;
    std::uint32_t t286a = 0, t286b = 0, t286r = 0;
    std::uint32_t t288 = 0;
    std::uint32_t t289 = 0;
    std::uint32_t t290a = 0;
    std::uint32_t t291a = 0;
    std::uint32_t t292 = 0;
    BatchLiftStatus t293_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t294 = 0;
    std::uint32_t t295 = 0;
    std::uint32_t t296 = 0;
    std::uint32_t t297 = 0;
    std::uint32_t t298a = 0, t298b = 0, t298r = 0;
    std::uint32_t t299a = 0, t299b = 0, t299r = 0;
    std::uint32_t t300a = 0, t300b = 0, t300r = 0;
    std::uint32_t t302a = 0, t302b = 0, t302r = 0;
    std::uint32_t t304a = 0;
    BatchLiftStatus t305_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t306a = 0, t306b = 0, t306r = 0;
    std::uint32_t t307 = 0;
    std::uint32_t t308 = 0;
    std::uint32_t t309 = 0;
    std::uint32_t t310 = 0;
    std::uint32_t t311 = 0;
    std::uint32_t t312 = 0;
    std::uint32_t t313 = 0;
    std::uint32_t t314 = 0;
    std::uint32_t t315 = 0;
    std::uint32_t t316 = 0;
    std::uint32_t t317 = 0;
    std::uint32_t t318 = 0;
    std::uint32_t t319a = 0, t319b = 0, t319r = 0;
    std::uint32_t t321a = 0, t321b = 0, t321r = 0;
    std::uint32_t t323a = 0;
    std::uint32_t t324 = 0;
    std::uint32_t t325a = 0;
    BatchLiftStatus t326_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t327a = 0, t327b = 0, t327r = 0;
    std::uint32_t t328a = 0, t328b = 0, t328r = 0;
    std::uint32_t t330a = 0, t330b = 0, t330r = 0;
    std::uint32_t t331 = 0;
    std::uint32_t t333 = 0;
    std::uint32_t t334a = 0, t334b = 0, t334r = 0;
    std::uint32_t t335a = 0, t335r = 0;
    std::uint32_t t336 = 0;
    std::uint32_t t337a = 0, t337b = 0, t337r = 0;
    std::uint32_t t338a = 0, t338b = 0, t338r = 0;
    std::uint32_t t339 = 0;
    std::uint32_t t340a = 0, t340b = 0, t340r = 0;
    std::uint32_t t341 = 0;
    std::uint32_t t342 = 0;
    std::uint32_t t344 = 0;
    std::uint32_t t345 = 0;
    std::uint32_t t346a = 0, t346b = 0, t346r = 0;
    std::uint32_t t347a = 0, t347b = 0, t347r = 0;
    std::uint32_t t348 = 0;
    std::uint32_t t349a = 0, t349b = 0, t349r = 0;
    std::uint32_t t351a = 0, t351b = 0, t351r = 0;
    std::uint32_t t352 = 0;
    std::uint32_t t353a = 0;
    std::uint32_t t354a = 0;
    std::uint32_t t355a = 0;
    BatchLiftStatus t356_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t357a = 0, t357b = 0, t357r = 0;
    std::uint32_t t358a = 0, t358b = 0, t358r = 0;
    std::uint32_t t359 = 0;
    std::uint32_t t360 = 0;
    std::uint32_t t361 = 0;
    std::uint32_t t362a = 0, t362b = 0, t362r = 0;
    std::uint32_t t363 = 0;
    std::uint32_t t364 = 0;
    std::uint32_t t366 = 0;
    std::uint32_t t367a = 0, t367b = 0, t367r = 0;
    std::uint32_t t368 = 0;
    std::uint32_t t369 = 0;
    std::uint32_t t370a = 0, t370b = 0, t370r = 0;
    std::uint32_t t371a = 0, t371b = 0, t371r = 0;
    std::uint32_t t372a = 0, t372b = 0, t372r = 0;
    std::uint32_t t374 = 0;
    std::uint32_t t375a = 0;
    std::uint32_t t376a = 0;
    BatchLiftStatus t377_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t378a = 0, t378b = 0, t378r = 0;
    std::uint32_t t379a = 0, t379b = 0, t379r = 0;
    std::uint32_t t381 = 0;
    std::uint32_t t382a = 0, t382b = 0, t382r = 0;
    std::uint32_t t384 = 0;
    std::uint32_t t385 = 0;
    std::uint32_t t386a = 0, t386b = 0, t386r = 0;
    std::uint32_t t388a = 0, t388b = 0, t388r = 0;
    std::uint32_t t389a = 0;
    std::uint32_t t390 = 0;
    std::uint32_t t391a = 0;
    std::uint32_t t392 = 0;
    std::uint32_t t393a = 0;
    BatchLiftStatus t394_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t395a = 0, t395b = 0, t395r = 0;
    std::uint32_t t396 = 0;
    std::uint32_t t397 = 0;
    std::uint32_t t398a = 0, t398b = 0, t398r = 0;
    std::uint32_t t400 = 0;
    std::uint32_t t401 = 0;
    std::uint32_t t402a = 0;
    std::uint32_t t403a = 0;
    BatchLiftStatus t404_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t405 = 0;
    std::uint32_t t406 = 0;
    std::uint32_t t407 = 0;
    std::uint32_t t408 = 0;
    std::uint32_t t409a = 0, t409b = 0, t409r = 0;
    std::uint32_t t410a = 0, t410b = 0, t410r = 0;
    std::uint32_t t412 = 0;
    std::uint32_t t413 = 0;
    std::uint32_t t414a = 0, t414b = 0, t414r = 0;
    std::uint32_t t415a = 0, t415r = 0;
    std::uint32_t t416 = 0;
    std::uint32_t t417a = 0, t417b = 0, t417r = 0;
    std::uint32_t t418 = 0;
    std::uint32_t t419 = 0;
    std::uint32_t t421 = 0;
    std::uint32_t t422 = 0;
    std::uint32_t t423 = 0;
    std::uint32_t t424a = 0;
    std::uint32_t t425a = 0;
    std::uint32_t t426 = 0;
    BatchLiftStatus t427_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t428a = 0;
    std::uint32_t t429 = 0;
    std::uint32_t t430a = 0;
    std::uint32_t t431 = 0;
    std::uint32_t t432a = 0;
    BatchLiftStatus t433_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t434a = 0, t434b = 0, t434r = 0;
    std::uint32_t t435 = 0;
    std::uint32_t t436 = 0;
    std::uint32_t t437a = 0, t437b = 0, t437r = 0;
    std::uint32_t t439 = 0;
    std::uint32_t t440 = 0;
    std::uint32_t t441a = 0;
    std::uint32_t t442a = 0;
    BatchLiftStatus t443_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t444 = 0;
    std::uint32_t t445 = 0;
    std::uint32_t t446 = 0;
    std::uint32_t t447 = 0;
    std::uint32_t t448a = 0, t448b = 0, t448r = 0;
    std::uint32_t t449a = 0, t449b = 0, t449r = 0;
    std::uint32_t t450 = 0;
    std::uint32_t t452a = 0, t452b = 0, t452r = 0;
    std::uint32_t t454a = 0;
    BatchLiftStatus t455_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t456a = 0, t456b = 0, t456r = 0;
    std::uint32_t t457 = 0;
    std::uint32_t t458 = 0;
    std::uint32_t t460 = 0;
    std::uint32_t t461 = 0;
    std::uint32_t t462 = 0;
    std::uint32_t t463 = 0;
    std::uint32_t t464a = 0, t464b = 0, t464r = 0;
    std::uint32_t t465 = 0;
    std::uint32_t t467 = 0;
    std::uint32_t t468a = 0, t468b = 0, t468r = 0;
    std::uint32_t t469a = 0, t469r = 0;
    std::uint32_t t470 = 0;
    std::uint32_t t471a = 0, t471b = 0, t471r = 0;
    std::uint32_t t472 = 0;
    std::uint32_t t473 = 0;
    std::uint32_t t475 = 0;
    std::uint32_t t476 = 0;
    std::uint32_t t477a = 0, t477b = 0, t477r = 0;
    std::uint32_t t478a = 0, t478b = 0, t478r = 0;
    std::uint32_t t480a = 0, t480b = 0, t480r = 0;
    std::uint32_t t481 = 0;
    std::uint32_t t482a = 0;
    std::uint32_t t483a = 0;
    std::uint32_t t484a = 0;
    BatchLiftStatus t485_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t486a = 0, t486b = 0, t486r = 0;
    std::uint32_t t487a = 0, t487b = 0, t487r = 0;
    std::uint32_t t488 = 0;
    std::uint32_t t489a = 0, t489b = 0, t489r = 0;
    std::uint32_t t491 = 0;
    std::uint32_t t492a = 0, t492b = 0, t492r = 0;
    std::uint32_t t494a = 0, t494b = 0, t494r = 0;
    std::uint32_t t496 = 0;
    std::uint32_t t497a = 0, t497b = 0, t497r = 0;
    std::uint32_t t498a = 0, t498r = 0;
    std::uint32_t t499 = 0;
    std::uint32_t t500a = 0, t500b = 0, t500r = 0;
    std::uint32_t t501a = 0, t501b = 0, t501r = 0;
    std::uint32_t t502a = 0, t502r = 0;
    std::uint32_t t503 = 0;
    std::uint32_t t504a = 0, t504b = 0, t504r = 0;
    std::uint32_t t505 = 0;
    std::uint32_t t506 = 0;
    std::uint32_t t508 = 0;
    std::uint32_t t509 = 0;
    std::uint32_t t510a = 0, t510b = 0, t510r = 0;
    std::uint32_t t511a = 0, t511b = 0, t511r = 0;
    std::uint32_t t512 = 0;
    std::uint32_t t513a = 0, t513b = 0, t513r = 0;
    std::uint32_t t515a = 0, t515b = 0, t515r = 0;
    std::uint32_t t516 = 0;
    std::uint32_t t517a = 0;
    std::uint32_t t518a = 0;
    std::uint32_t t519a = 0;
    BatchLiftStatus t520_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t521a = 0, t521b = 0, t521r = 0;
    std::uint32_t t522a = 0, t522b = 0, t522r = 0;
    std::uint32_t t523a = 0, t523b = 0, t523r = 0;
    std::uint32_t t525 = 0;
    std::uint32_t t526 = 0;
    std::uint32_t t527a = 0, t527b = 0, t527r = 0;
    std::uint32_t t528a = 0, t528b = 0, t528r = 0;
    std::uint32_t t529 = 0;
    std::uint32_t t530 = 0;
    std::uint32_t t531 = 0;
    std::uint32_t t533 = 0;
    std::uint32_t t534a = 0, t534b = 0, t534r = 0;
    std::uint32_t t535a = 0, t535r = 0;
    std::uint32_t t536 = 0;
    std::uint32_t t537a = 0, t537b = 0, t537r = 0;
    std::uint32_t t538a = 0, t538b = 0, t538r = 0;
    std::uint32_t t539 = 0;
    std::uint32_t t540a = 0, t540b = 0, t540r = 0;
    std::uint32_t t541 = 0;
    std::uint32_t t542 = 0;
    std::uint32_t t544 = 0;
    std::uint32_t t545 = 0;
    std::uint32_t t546a = 0, t546b = 0, t546r = 0;
    std::uint32_t t547a = 0, t547b = 0, t547r = 0;
    std::uint32_t t548 = 0;
    std::uint32_t t549a = 0, t549b = 0, t549r = 0;
    std::uint32_t t551a = 0, t551b = 0, t551r = 0;
    std::uint32_t t552 = 0;
    std::uint32_t t553a = 0;
    std::uint32_t t554a = 0;
    std::uint32_t t555a = 0;
    BatchLiftStatus t556_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t557a = 0, t557b = 0, t557r = 0;
    std::uint32_t t558a = 0, t558b = 0, t558r = 0;
    std::uint32_t t559 = 0;
    std::uint32_t t560 = 0;
    std::uint32_t t561 = 0;
    std::uint32_t t562a = 0, t562b = 0, t562r = 0;
    std::uint32_t t563 = 0;
    std::uint32_t t564 = 0;
    std::uint32_t t566 = 0;
    std::uint32_t t567 = 0;
    std::uint32_t t568a = 0;
    std::uint32_t t569 = 0;
    std::uint32_t t570a = 0;
    std::uint32_t t571 = 0;
    std::uint32_t t572 = 0;
    std::uint32_t t573a = 0;
    BatchLiftStatus t574_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t575a = 0, t575b = 0, t575r = 0;
    std::uint32_t t577 = 0;
    std::uint32_t t578 = 0;
    std::uint32_t t579 = 0;
    std::uint32_t t580a = 0, t580b = 0, t580r = 0;
    std::uint32_t t582 = 0;
    std::uint32_t t583 = 0;
    std::uint32_t t584 = 0;
    std::uint32_t t585 = 0;
    std::uint32_t t586 = 0;
    std::uint32_t t587a = 0, t587b = 0, t587r = 0;
    std::uint32_t t589 = 0;
    std::uint32_t t590a = 0;
    BatchLiftStatus t591_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t592 = 0;
    std::uint32_t t594 = 0;
    std::uint32_t t595a = 0;
    std::uint32_t t596a = 0;
    std::uint32_t t597 = 0;
    BatchLiftStatus t598_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t599a = 0;
    std::uint32_t t600 = 0;
    std::uint32_t t601a = 0;
    std::uint32_t t602 = 0;
    std::uint32_t t603a = 0;
    std::uint32_t t604 = 0;
    BatchLiftStatus t605_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t606a = 0, t606b = 0, t606r = 0;
    std::uint32_t t607 = 0;
    std::uint32_t t608 = 0;
    std::uint32_t t609a = 0, t609b = 0, t609r = 0;
    std::uint32_t t611 = 0;
    std::uint32_t t612 = 0;
    std::uint32_t t613a = 0;
    std::uint32_t t614a = 0;
    std::uint32_t t615 = 0;
    BatchLiftStatus t616_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t617 = 0;
    std::uint32_t t618 = 0;
    std::uint32_t t619 = 0;
    std::uint32_t t620 = 0;
    std::uint32_t t621a = 0, t621b = 0, t621r = 0;
    std::uint32_t t622a = 0, t622b = 0, t622r = 0;
    std::uint32_t t624a = 0, t624b = 0, t624r = 0;
    std::uint32_t t626a = 0;
    BatchLiftStatus t627_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t628a = 0, t628b = 0, t628r = 0;
    std::uint32_t t629 = 0;
    std::uint32_t t630 = 0;
    std::uint32_t t631a = 0, t631b = 0, t631r = 0;
    std::uint32_t t632a = 0, t632b = 0, t632r = 0;
    std::uint32_t t633 = 0;
    std::uint32_t t635a = 0, t635b = 0, t635r = 0;
    std::uint32_t t637a = 0;
    BatchLiftStatus t638_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t639a = 0, t639b = 0, t639r = 0;
    std::uint32_t t640a = 0, t640b = 0, t640r = 0;
    std::uint32_t t642a = 0, t642b = 0, t642r = 0;
    std::uint32_t t644 = 0;
    std::uint32_t t645 = 0;
    std::uint32_t t646a = 0, t646b = 0, t646r = 0;
    std::uint32_t t647 = 0;
    std::uint32_t t648 = 0;
    std::uint32_t t649 = 0;
    std::uint32_t t650 = 0;
    std::uint32_t t651 = 0;
    std::uint32_t t652a = 0, t652r = 0;
    std::uint32_t t653a = 0, t653b = 0, t653r = 0;
    std::uint32_t t655a = 0, t655b = 0, t655r = 0;
    std::uint32_t t656 = 0;
    std::uint32_t t657 = 0;
    std::uint32_t t658a = 0, t658b = 0, t658r = 0;
    std::uint32_t t659 = 0;
    std::uint32_t t660a = 0, t660r = 0;
    std::uint32_t t661a = 0, t661b = 0, t661r = 0;
    std::uint32_t t663 = 0;
    std::uint32_t t664a = 0;
    std::uint32_t t665a = 0;
    std::uint32_t t666a = 0;
    std::uint32_t t667a = 0;
    std::uint32_t t668a = 0, t668r = 0;
    std::uint32_t t669a = 0;
    std::uint32_t t670a = 0;
    BatchLiftStatus t671_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t672 = 0;
    std::uint32_t t673 = 0;
    std::uint32_t t674a = 0, t674r = 0;
    std::uint32_t t675a = 0, t675b = 0, t675r = 0;
    std::uint32_t t676a = 0, t676b = 0, t676r = 0;
    std::uint32_t t677 = 0;
    std::uint32_t t679 = 0;
    std::uint32_t t680 = 0;
    std::uint32_t t681 = 0;
    std::uint32_t t682a = 0;
    std::uint32_t t683a = 0;
    std::uint32_t t684a = 0;
    std::uint32_t t685 = 0;
    BatchLiftStatus t686_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t687a = 0, t687b = 0, t687r = 0;
    std::uint32_t t688a = 0, t688b = 0, t688r = 0;
    std::uint32_t t689a = 0, t689b = 0, t689r = 0;
    std::uint32_t t690 = 0;
    std::uint32_t t691 = 0;
    std::uint32_t t692a = 0, t692b = 0, t692r = 0;
    std::uint32_t t693a = 0;
    std::uint32_t t694 = 0;
    std::uint32_t t695a = 0;
    std::uint32_t t697 = 0;
    BatchLiftStatus t698_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t699 = 0;
    std::uint32_t t700a = 0;
    std::uint32_t t701 = 0;
    std::uint32_t t702a = 0, t702b = 0, t702r = 0;
    BatchLiftStatus t703_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t705 = 0;
    std::uint32_t t706a = 0, t706b = 0, t706r = 0;
    BatchLiftStatus t707_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t708 = 0;
    std::uint32_t t709a = 0, t709b = 0, t709r = 0;
    std::uint32_t t710a = 0, t710b = 0, t710r = 0;
    std::uint32_t t712a = 0, t712b = 0, t712r = 0;
    std::uint32_t t714a = 0;
    BatchLiftStatus t715_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t716a = 0, t716b = 0, t716r = 0;
    std::uint32_t t717 = 0;
    BatchLiftStatus t718_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t719 = 0;
    std::uint32_t t720a = 0, t720b = 0, t720r = 0;
    std::uint32_t t721a = 0, t721b = 0, t721r = 0;
    std::uint32_t t723a = 0, t723b = 0, t723r = 0;
    std::uint32_t t725a = 0;
    BatchLiftStatus t726_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t727a = 0, t727b = 0, t727r = 0;
    std::uint32_t t728 = 0;
    std::uint32_t t729 = 0;
    std::uint32_t t730a = 0, t730b = 0, t730r = 0;
    std::uint32_t t731a = 0, t731b = 0, t731r = 0;
    std::uint32_t t732 = 0;
    std::uint32_t t734a = 0, t734b = 0, t734r = 0;
    std::uint32_t t736a = 0;
    BatchLiftStatus t737_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t738a = 0, t738b = 0, t738r = 0;
    std::uint32_t t739 = 0;
    std::uint32_t t740 = 0;
    std::uint32_t t741a = 0, t741b = 0, t741r = 0;
    std::uint32_t t742 = 0;
    std::uint32_t t743a = 0, t743b = 0, t743r = 0;
    std::uint32_t t745 = 0;
    std::uint32_t t747 = 0;
    BatchLiftStatus t748_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t749 = 0;
    std::uint32_t t750a = 0, t750b = 0, t750r = 0;
    std::uint32_t t751a = 0, t751b = 0, t751r = 0;
    std::uint32_t t753a = 0, t753b = 0, t753r = 0;
    std::uint32_t t755a = 0;
    BatchLiftStatus t756_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t757a = 0, t757b = 0, t757r = 0;
    std::uint32_t t758 = 0;
    std::uint32_t t759 = 0;
    std::uint32_t t760a = 0, t760b = 0, t760r = 0;
    std::uint32_t t761a = 0, t761b = 0, t761r = 0;
    std::uint32_t t763a = 0, t763b = 0, t763r = 0;
    std::uint32_t t765a = 0;
    BatchLiftStatus t766_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t767a = 0, t767b = 0, t767r = 0;
    std::uint32_t t768 = 0;
    std::uint32_t t770 = 0;
    BatchLiftStatus t771_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t772 = 0;
    std::uint32_t t773a = 0, t773b = 0, t773r = 0;
    std::uint32_t t774a = 0, t774b = 0, t774r = 0;
    std::uint32_t t776 = 0;
    std::uint32_t t777 = 0;
    BatchLiftStatus t778_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t779 = 0;
    std::uint32_t t780a = 0, t780b = 0, t780r = 0;
    std::uint32_t t781a = 0, t781b = 0, t781r = 0;
    std::uint32_t t783a = 0, t783b = 0, t783r = 0;
    std::uint32_t t785a = 0;
    BatchLiftStatus t786_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t787a = 0, t787b = 0, t787r = 0;
    std::uint32_t t788 = 0;
    std::uint32_t t789 = 0;
    std::uint32_t t790a = 0, t790b = 0, t790r = 0;
    std::uint32_t t791a = 0, t791b = 0, t791r = 0;
    std::uint32_t t793a = 0, t793b = 0, t793r = 0;
    std::uint32_t t795a = 0;
    BatchLiftStatus t796_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t797a = 0, t797b = 0, t797r = 0;
    std::uint32_t t798 = 0;
    std::uint32_t t799 = 0;
    std::uint32_t t800a = 0;
    std::uint32_t t801a = 0;
    std::uint32_t t802a = 0;
    std::uint32_t t803a = 0;
    std::uint32_t t804 = 0;
    std::uint32_t t805a = 0, t805b = 0, t805r = 0;

    // 0x0083bcd0: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x0083bcd6: 6aff PUSH
        t1a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bcd8: 68f4742101 PUSH
        t2a = 0x012174f4u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bcdd: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bcde: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x0083bce5: 8b4c2414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x0083bce9: 81ece0000000 SUB
        t6a = state.regs[4];
        t6b = 0x000000e0u;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0083bcef: 53 PUSH
        t7a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bcf0: 55 PUSH
        t8a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bcf1: 56 PUSH
        t9a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bcf2: 8bc1 MOV
        t10 = state.regs[1];
        state.regs[0] = t10;
    // 0x0083bcf4: 57 PUSH
        t11a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bcf5: 8d7001 LEA
        t12 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[6] = t12;
    // 0x0083bcf8: 8a10 MOV
    L_0083bcf8:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t13 << 0u) & 0x000000ffu);
    // 0x0083bcfa: 40 INC
        t14a = state.regs[0];
        t14r = static_cast<std::uint32_t>(t14a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t14a, t14r, 32u);
        state.regs[0] = t14r;
    // 0x0083bcfb: 84d2 TEST
        t15a = state.regs[2] & 0x000000ffu;
        t15b = state.regs[2] & 0x000000ffu;
        t15r = (t15a & t15b) & 0x000000ffu;
        batch_set_logic_flags(state, t15r, 8u);
    // 0x0083bcfd: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083bcf8;
    // 0x0083bcff: 8bac2400010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000100u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t17;
    // 0x0083bd06: 2bc6 SUB
        t18a = state.regs[0];
        t18b = state.regs[6];
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
        state.regs[0] = t18r;
    // 0x0083bd08: 03c1 ADD
        t19a = state.regs[0];
        t19b = state.regs[1];
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[0] = t19r;
    // 0x0083bd0a: 50 PUSH
        t20a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd0b: 51 PUSH
        t21a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd0c: 8d4d10 LEA
        t22 = static_cast<std::uint32_t>(state.regs[5] + 0x00000010u);
        state.regs[1] = t22;
    // 0x0083bd0f: e89c8fc1ff CALL
        t23_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00454cb0u, 0x0083bd14u);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x0083bd14u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bd14: 687cc43e01 PUSH
        t24a = 0x013ec47cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd19: 8d4d20 LEA
        t25 = static_cast<std::uint32_t>(state.regs[5] + 0x00000020u);
        state.regs[1] = t25;
    // 0x0083bd1c: 687cc43e01 PUSH
        t26a = 0x013ec47cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd21: e88a8fc1ff CALL
        t27_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00454cb0u, 0x0083bd26u);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x0083bd26u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bd26: 8b7d30 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000030u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t28;
    // 0x0083bd29: 8b7534 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000034u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t29;
    // 0x0083bd2c: 8d5d30 LEA
        t30 = static_cast<std::uint32_t>(state.regs[5] + 0x00000030u);
        state.regs[3] = t30;
    // 0x0083bd2f: 57 PUSH
        t31a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd30: 56 PUSH
        t32a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd31: 56 PUSH
        t33a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd32: e8e9d1ffff CALL
        t34_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00838f20u, 0x0083bd37u);
        if (t34_call_status != BatchLiftStatus::returned) return t34_call_status;
        if (state.eip != 0x0083bd37u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bd37: 8b4b04 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35;
    // 0x0083bd3a: 83c40c ADD
        t36a = state.regs[4];
        t36b = 0x0000000cu;
        t36r = static_cast<std::uint32_t>(t36a + t36b) & 0xffffffffu;
        batch_set_add_flags(state, t36a, t36b, t36r, 32u);
        state.regs[4] = t36r;
    // 0x0083bd3d: 51 PUSH
        t37a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd3e: 50 PUSH
        t38a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd3f: 8bcb MOV
        t39 = state.regs[3];
        state.regs[1] = t39;
    // 0x0083bd41: e8ea26f3ff CALL
        t40_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0076e430u, 0x0083bd46u);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
        if (state.eip != 0x0083bd46u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bd46: 2bf7 SUB
        t41a = state.regs[6];
        t41b = state.regs[7];
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
        state.regs[6] = t41r;
    // 0x0083bd48: c1fe05 SAR
        t42a = state.regs[6];
        t42c = 5u;
        if (t42c != 0u) {
        t42r = (t42a >> t42c) | ((t42a & 0x80000000u) ? (0xffffffffu << (32u - t42c)) : 0u);
        batch_set_sar_flags(state, t42a, t42c, t42r, 32u);
            state.regs[6] = t42r;
        }
    // 0x0083bd4b: f7de NEG
        t43a = state.regs[6];
        t43r = static_cast<std::uint32_t>(0u - t43a) & 0xffffffffu;
        batch_set_neg_flags(state, t43a, t43r, 32u);
        state.regs[6] = t43r;
    // 0x0083bd4d: 8d4d44 LEA
        t44 = static_cast<std::uint32_t>(state.regs[5] + 0x00000044u);
        state.regs[1] = t44;
    // 0x0083bd50: c1e605 SHL
        t45a = state.regs[6];
        t45c = 5u;
        if (t45c != 0u) {
        t45r = static_cast<std::uint32_t>(t45a << t45c) & 0xffffffffu;
        batch_set_shl_flags(state, t45a, t45c, t45r, 32u);
            state.regs[6] = t45r;
        }
    // 0x0083bd53: 017304 ADD
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t46a)) return BatchLiftStatus::invalid_memory;
        t46b = state.regs[6];
        t46r = static_cast<std::uint32_t>(t46a + t46b) & 0xffffffffu;
        batch_set_add_flags(state, t46a, t46b, t46r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t46r)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd56: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t47;
    // 0x0083bd59: 8b01 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x0083bd5b: 52 PUSH
        t49a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd5c: 50 PUSH
        t50a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd5d: e8defcffff CALL
        t51_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0083ba40u, 0x0083bd62u);
        if (t51_call_status != BatchLiftStatus::returned) return t51_call_status;
        if (state.eip != 0x0083bd62u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bd62: 8b7d58 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000058u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t52;
    // 0x0083bd65: 8b755c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000005cu), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t53;
    // 0x0083bd68: 8d5d58 LEA
        t54 = static_cast<std::uint32_t>(state.regs[5] + 0x00000058u);
        state.regs[3] = t54;
    // 0x0083bd6b: 57 PUSH
        t55a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd6c: 56 PUSH
        t56a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd6d: 56 PUSH
        t57a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd6e: e87dd2ffff CALL
        t58_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00838ff0u, 0x0083bd73u);
        if (t58_call_status != BatchLiftStatus::returned) return t58_call_status;
        if (state.eip != 0x0083bd73u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bd73: 8b4b04 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t59)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t59;
    // 0x0083bd76: 83c40c ADD
        t60a = state.regs[4];
        t60b = 0x0000000cu;
        t60r = static_cast<std::uint32_t>(t60a + t60b) & 0xffffffffu;
        batch_set_add_flags(state, t60a, t60b, t60r, 32u);
        state.regs[4] = t60r;
    // 0x0083bd79: 51 PUSH
        t61a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd7a: 50 PUSH
        t62a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bd7b: 8bcb MOV
        t63 = state.regs[3];
        state.regs[1] = t63;
    // 0x0083bd7d: e8ee26f3ff CALL
        t64_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0076e470u, 0x0083bd82u);
        if (t64_call_status != BatchLiftStatus::returned) return t64_call_status;
        if (state.eip != 0x0083bd82u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bd82: 2bf7 SUB
        t65a = state.regs[6];
        t65b = state.regs[7];
        t65r = static_cast<std::uint32_t>(t65a - t65b) & 0xffffffffu;
        batch_set_sub_flags(state, t65a, t65b, t65r, 32u);
        state.regs[6] = t65r;
    // 0x0083bd84: b8555555d5 MOV
        t66 = 0xd5555555u;
        state.regs[0] = t66;
    // 0x0083bd89: f7ee IMUL
        t67a = state.regs[6];
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(state.regs[0])) * static_cast<std::int32_t>(t67a);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.regs[2] = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x0083bd8b: c1fa02 SAR
        t68a = state.regs[2];
        t68c = 2u;
        if (t68c != 0u) {
        t68r = (t68a >> t68c) | ((t68a & 0x80000000u) ? (0xffffffffu << (32u - t68c)) : 0u);
        batch_set_sar_flags(state, t68a, t68c, t68r, 32u);
            state.regs[2] = t68r;
        }
    // 0x0083bd8e: 8bc2 MOV
        t69 = state.regs[2];
        state.regs[0] = t69;
    // 0x0083bd90: c1e81f SHR
        t70a = state.regs[0];
        t70c = 31u;
        if (t70c != 0u) {
        t70r = static_cast<std::uint32_t>(t70a >> t70c);
        batch_set_shr_flags(state, t70a, t70c, t70r, 32u);
            state.regs[0] = t70r;
        }
    // 0x0083bd93: 03c2 ADD
        t71a = state.regs[0];
        t71b = state.regs[2];
        t71r = static_cast<std::uint32_t>(t71a + t71b) & 0xffffffffu;
        batch_set_add_flags(state, t71a, t71b, t71r, 32u);
        state.regs[0] = t71r;
    // 0x0083bd95: 8d1440 LEA
        t72 = static_cast<std::uint32_t>(state.regs[0] + state.regs[0] * 2u + 0x00000000u);
        state.regs[2] = t72;
    // 0x0083bd98: 03d2 ADD
        t73a = state.regs[2];
        t73b = state.regs[2];
        t73r = static_cast<std::uint32_t>(t73a + t73b) & 0xffffffffu;
        batch_set_add_flags(state, t73a, t73b, t73r, 32u);
        state.regs[2] = t73r;
    // 0x0083bd9a: 03d2 ADD
        t74a = state.regs[2];
        t74b = state.regs[2];
        t74r = static_cast<std::uint32_t>(t74a + t74b) & 0xffffffffu;
        batch_set_add_flags(state, t74a, t74b, t74r, 32u);
        state.regs[2] = t74r;
    // 0x0083bd9c: 6834044101 PUSH
        t75a = 0x01410434u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t75a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bda1: 03d2 ADD
        t76a = state.regs[2];
        t76b = state.regs[2];
        t76r = static_cast<std::uint32_t>(t76a + t76b) & 0xffffffffu;
        batch_set_add_flags(state, t76a, t76b, t76r, 32u);
        state.regs[2] = t76r;
    // 0x0083bda3: 015304 ADD
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t77a)) return BatchLiftStatus::invalid_memory;
        t77b = state.regs[2];
        t77r = static_cast<std::uint32_t>(t77a + t77b) & 0xffffffffu;
        batch_set_add_flags(state, t77a, t77b, t77r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t77r)) return BatchLiftStatus::invalid_memory;
    // 0x0083bda6: 682c044101 PUSH
        t78a = 0x0141042cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t78a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bdab: 8d8db8000000 LEA
        t79 = static_cast<std::uint32_t>(state.regs[5] + 0x000000b8u);
        state.regs[1] = t79;
    // 0x0083bdb1: e8fa8ec1ff CALL
        t80_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00454cb0u, 0x0083bdb6u);
        if (t80_call_status != BatchLiftStatus::returned) return t80_call_status;
        if (state.eip != 0x0083bdb6u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bdb6: 8bbc2408010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000108u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t81;
    // 0x0083bdbd: 33ed XOR
        t82a = state.regs[5];
        t82b = state.regs[5];
        t82r = (t82a ^ t82b) & 0xffffffffu;
        batch_set_logic_flags(state, t82r, 32u);
        state.regs[5] = t82r;
    // 0x0083bdbf: 8d84240c010000 LEA
        t83 = static_cast<std::uint32_t>(state.regs[4] + 0x0000010cu);
        state.regs[0] = t83;
    // 0x0083bdc6: 896c2464 MOV
        t84 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000064u), t84)) return BatchLiftStatus::invalid_memory;
    // 0x0083bdca: 89442414 MOV
        t85 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t85)) return BatchLiftStatus::invalid_memory;
    // 0x0083bdce: 85ff TEST
        t86a = state.regs[7];
        t86b = state.regs[7];
        t86r = (t86a & t86b) & 0xffffffffu;
        batch_set_logic_flags(state, t86r, 32u);
    // 0x0083bdd0: 0f8459090000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c72f;
    // 0x0083bdd6: 33c0 XOR
    L_0083bdd6:
        t88a = state.regs[0];
        t88b = state.regs[0];
        t88r = (t88a ^ t88b) & 0xffffffffu;
        batch_set_logic_flags(state, t88r, 32u);
        state.regs[0] = t88r;
    // 0x0083bdd8: 89442420 MOV
        t89 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t89)) return BatchLiftStatus::invalid_memory;
    // 0x0083bddc: 89442424 MOV
        t90 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t90)) return BatchLiftStatus::invalid_memory;
    // 0x0083bde0: 89442428 MOV
        t91 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t91)) return BatchLiftStatus::invalid_memory;
    // 0x0083bde4: 8bc7 MOV
        t92 = state.regs[7];
        state.regs[0] = t92;
    // 0x0083bde6: 8d5001 LEA
        t93 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t93;
    // 0x0083bde9: 8da42400000000 LEA
        t94 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t94;
    // 0x0083bdf0: 8a08 MOV
    L_0083bdf0:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t95)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t95 << 0u) & 0x000000ffu);
    // 0x0083bdf2: 40 INC
        t96a = state.regs[0];
        t96r = static_cast<std::uint32_t>(t96a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t96a, t96r, 32u);
        state.regs[0] = t96r;
    // 0x0083bdf3: 84c9 TEST
        t97a = state.regs[1] & 0x000000ffu;
        t97b = state.regs[1] & 0x000000ffu;
        t97r = (t97a & t97b) & 0x000000ffu;
        batch_set_logic_flags(state, t97r, 8u);
    // 0x0083bdf5: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083bdf0;
    // 0x0083bdf7: 2bc2 SUB
        t99a = state.regs[0];
        t99b = state.regs[2];
        t99r = static_cast<std::uint32_t>(t99a - t99b) & 0xffffffffu;
        batch_set_sub_flags(state, t99a, t99b, t99r, 32u);
        state.regs[0] = t99r;
    // 0x0083bdf9: 8d1c38 LEA
        t100 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 1u + 0x00000000u);
        state.regs[3] = t100;
    // 0x0083bdfc: 8beb MOV
        t101 = state.regs[3];
        state.regs[5] = t101;
    // 0x0083bdfe: 2bef SUB
        t102a = state.regs[5];
        t102b = state.regs[7];
        t102r = static_cast<std::uint32_t>(t102a - t102b) & 0xffffffffu;
        batch_set_sub_flags(state, t102a, t102b, t102r, 32u);
        state.regs[5] = t102r;
    // 0x0083be00: 8d7501 LEA
        t103 = static_cast<std::uint32_t>(state.regs[5] + 0x00000001u);
        state.regs[6] = t103;
    // 0x0083be03: 83fe01 CMP
        t104a = state.regs[6];
        t104b = 0x00000001u;
        t104r = static_cast<std::uint32_t>(t104a - t104b) & 0xffffffffu;
        batch_set_sub_flags(state, t104a, t104b, t104r, 32u);
    // 0x0083be06: 7624 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0083be2c;
    // 0x0083be08: 68d1000000 PUSH
        t106a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t106a)) return BatchLiftStatus::invalid_memory;
    // 0x0083be0d: 6838bb3e01 PUSH
        t107a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
    // 0x0083be12: 6a00 PUSH
        t108a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t108a)) return BatchLiftStatus::invalid_memory;
    // 0x0083be14: 6a00 PUSH
        t109a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t109a)) return BatchLiftStatus::invalid_memory;
    // 0x0083be16: 688cb14101 PUSH
        t110a = 0x0141b18cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t110a)) return BatchLiftStatus::invalid_memory;
    // 0x0083be1b: 56 PUSH
        t111a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t111a)) return BatchLiftStatus::invalid_memory;
    // 0x0083be1c: e87fb57000 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x0083be21u)) return BatchLiftStatus::invalid_memory;
        t112_call_status = spore_lift_00f473a0(memory, state);
        if (t112_call_status != BatchLiftStatus::returned) return t112_call_status;
        if (state.eip != 0x0083be21u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083be21: 83c418 ADD
        t113a = state.regs[4];
        t113b = 0x00000018u;
        t113r = static_cast<std::uint32_t>(t113a + t113b) & 0xffffffffu;
        batch_set_add_flags(state, t113a, t113b, t113r, 32u);
        state.regs[4] = t113r;
    // 0x0083be24: 03f0 ADD
        t114a = state.regs[6];
        t114b = state.regs[0];
        t114r = static_cast<std::uint32_t>(t114a + t114b) & 0xffffffffu;
        batch_set_add_flags(state, t114a, t114b, t114r, 32u);
        state.regs[6] = t114r;
    // 0x0083be26: 89742428 MOV
        t115 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t115)) return BatchLiftStatus::invalid_memory;
    // 0x0083be2a: eb0d JMP
        goto L_0083be39;
    // 0x0083be2c: b8ac7b6601 MOV
    L_0083be2c:
        t117 = 0x01667bacu;
        state.regs[0] = t117;
    // 0x0083be31: c7442428ad7b6601 MOV
        t118 = 0x01667badu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t118)) return BatchLiftStatus::invalid_memory;
    // 0x0083be39: 55 PUSH
    L_0083be39:
        t119a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t119a)) return BatchLiftStatus::invalid_memory;
    // 0x0083be3a: 57 PUSH
        t120a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t120a)) return BatchLiftStatus::invalid_memory;
    // 0x0083be3b: 50 PUSH
        t121a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t121a)) return BatchLiftStatus::invalid_memory;
    // 0x0083be3c: 89442430 MOV
        t122 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t122)) return BatchLiftStatus::invalid_memory;
    // 0x0083be40: 8944242c MOV
        t123 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t123)) return BatchLiftStatus::invalid_memory;
    // 0x0083be44: 8bf0 MOV
        t124 = state.regs[0];
        state.regs[6] = t124;
    // 0x0083be46: e8f9489a00 CALL
        t125_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x0083be4bu);
        if (t125_call_status != BatchLiftStatus::returned) return t125_call_status;
        if (state.eip != 0x0083be4bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083be4b: 2bf7 SUB
        t126a = state.regs[6];
        t126b = state.regs[7];
        t126r = static_cast<std::uint32_t>(t126a - t126b) & 0xffffffffu;
        batch_set_sub_flags(state, t126a, t126b, t126r, 32u);
        state.regs[6] = t126r;
    // 0x0083be4d: 03f3 ADD
        t127a = state.regs[6];
        t127b = state.regs[3];
        t127r = static_cast<std::uint32_t>(t127a + t127b) & 0xffffffffu;
        batch_set_add_flags(state, t127a, t127b, t127r, 32u);
        state.regs[6] = t127r;
    // 0x0083be4f: 89742430 MOV
        t128 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t128)) return BatchLiftStatus::invalid_memory;
    // 0x0083be53: 83c40c ADD
        t129a = state.regs[4];
        t129b = 0x0000000cu;
        t129r = static_cast<std::uint32_t>(t129a + t129b) & 0xffffffffu;
        batch_set_add_flags(state, t129a, t129b, t129r, 32u);
        state.regs[4] = t129r;
    // 0x0083be56: c60600 MOV
        t130 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t130)) return BatchLiftStatus::invalid_memory;
    // 0x0083be59: beac7b6601 MOV
        t131 = 0x01667bacu;
        state.regs[6] = t131;
    // 0x0083be5e: 8bfe MOV
        t132 = state.regs[6];
        state.regs[7] = t132;
    // 0x0083be60: c78424f800000000000000 MOV
        t133 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t133)) return BatchLiftStatus::invalid_memory;
    // 0x0083be6b: 89742430 MOV
        t134 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t134)) return BatchLiftStatus::invalid_memory;
    // 0x0083be6f: 897c2434 MOV
        t135 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t135)) return BatchLiftStatus::invalid_memory;
    // 0x0083be73: c7442438ad7b6601 MOV
        t136 = 0x01667badu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t136)) return BatchLiftStatus::invalid_memory;
    // 0x0083be7b: 8b442420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t137)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t137;
    // 0x0083be7f: c68424f800000001 MOV
        t138 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t138)) return BatchLiftStatus::invalid_memory;
    // 0x0083be87: 3b442424 CMP
        t139a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t139b)) return BatchLiftStatus::invalid_memory;
        t139r = static_cast<std::uint32_t>(t139a - t139b) & 0xffffffffu;
        batch_set_sub_flags(state, t139a, t139b, t139r, 32u);
    // 0x0083be8b: 0f84c6010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c057;
    // 0x0083be91: 8a08 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t141)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t141 << 0u) & 0x000000ffu);
    // 0x0083be93: 80f93a CMP
        t142a = state.regs[1] & 0x000000ffu;
        t142b = 0x0000003au;
        t142r = static_cast<std::uint32_t>(t142a - t142b) & 0x000000ffu;
        batch_set_sub_flags(state, t142a, t142b, t142r, 8u);
    // 0x0083be96: 0f85de000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083bf7a;
    // 0x0083be9c: 8b4c2414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t144)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t144;
    // 0x0083bea0: 83c104 ADD
        t145a = state.regs[1];
        t145b = 0x00000004u;
        t145r = static_cast<std::uint32_t>(t145a + t145b) & 0xffffffffu;
        batch_set_add_flags(state, t145a, t145b, t145r, 32u);
        state.regs[1] = t145r;
    // 0x0083bea3: 8d7801 LEA
        t146 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[7] = t146;
    // 0x0083bea6: 894c2414 MOV
        t147 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t147)) return BatchLiftStatus::invalid_memory;
    // 0x0083beaa: 8b49fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0xfffffffcu), t148)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t148;
    // 0x0083bead: 8bc7 MOV
        t149 = state.regs[7];
        state.regs[0] = t149;
    // 0x0083beaf: 894c2410 MOV
        t150 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t150)) return BatchLiftStatus::invalid_memory;
    // 0x0083beb3: 8d5001 LEA
        t151 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t151;
    // 0x0083beb6: 8a08 MOV
    L_0083beb6:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t152)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t152 << 0u) & 0x000000ffu);
    // 0x0083beb8: 40 INC
        t153a = state.regs[0];
        t153r = static_cast<std::uint32_t>(t153a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t153a, t153r, 32u);
        state.regs[0] = t153r;
    // 0x0083beb9: 84c9 TEST
        t154a = state.regs[1] & 0x000000ffu;
        t154b = state.regs[1] & 0x000000ffu;
        t154r = (t154a & t154b) & 0x000000ffu;
        batch_set_logic_flags(state, t154r, 8u);
    // 0x0083bebb: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083beb6;
    // 0x0083bebd: 2bc2 SUB
        t156a = state.regs[0];
        t156b = state.regs[2];
        t156r = static_cast<std::uint32_t>(t156a - t156b) & 0xffffffffu;
        batch_set_sub_flags(state, t156a, t156b, t156r, 32u);
        state.regs[0] = t156r;
    // 0x0083bebf: 8d3438 LEA
        t157 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 1u + 0x00000000u);
        state.regs[6] = t157;
    // 0x0083bec2: 8bde MOV
        t158 = state.regs[6];
        state.regs[3] = t158;
    // 0x0083bec4: 2bdf SUB
        t159a = state.regs[3];
        t159b = state.regs[7];
        t159r = static_cast<std::uint32_t>(t159a - t159b) & 0xffffffffu;
        batch_set_sub_flags(state, t159a, t159b, t159r, 32u);
        state.regs[3] = t159r;
    // 0x0083bec6: 8d4301 LEA
        t160 = static_cast<std::uint32_t>(state.regs[3] + 0x00000001u);
        state.regs[0] = t160;
    // 0x0083bec9: 83f801 CMP
        t161a = state.regs[0];
        t161b = 0x00000001u;
        t161r = static_cast<std::uint32_t>(t161a - t161b) & 0xffffffffu;
        batch_set_sub_flags(state, t161a, t161b, t161r, 32u);
    // 0x0083becc: 762b JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0083bef9;
    // 0x0083bece: 68d1000000 PUSH
        t163a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t163a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bed3: 6838bb3e01 PUSH
        t164a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t164a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bed8: 6a00 PUSH
        t165a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t165a)) return BatchLiftStatus::invalid_memory;
    // 0x0083beda: 6a00 PUSH
        t166a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t166a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bedc: 8d4301 LEA
        t167 = static_cast<std::uint32_t>(state.regs[3] + 0x00000001u);
        state.regs[0] = t167;
    // 0x0083bedf: 688cb14101 PUSH
        t168a = 0x0141b18cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t168a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bee4: 50 PUSH
        t169a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t169a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bee5: e8b6b47000 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x0083beeau)) return BatchLiftStatus::invalid_memory;
        t170_call_status = spore_lift_00f473a0(memory, state);
        if (t170_call_status != BatchLiftStatus::returned) return t170_call_status;
        if (state.eip != 0x0083beeau) return BatchLiftStatus::invalid_control_flow;
    // 0x0083beea: 8be8 MOV
        t171 = state.regs[0];
        state.regs[5] = t171;
    // 0x0083beec: 8d542b01 LEA
        t172 = static_cast<std::uint32_t>(state.regs[3] + state.regs[5] * 1u + 0x00000001u);
        state.regs[2] = t172;
    // 0x0083bef0: 83c418 ADD
        t173a = state.regs[4];
        t173b = 0x00000018u;
        t173r = static_cast<std::uint32_t>(t173a + t173b) & 0xffffffffu;
        batch_set_add_flags(state, t173a, t173b, t173r, 32u);
        state.regs[4] = t173r;
    // 0x0083bef3: 8954244c MOV
        t174 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t174)) return BatchLiftStatus::invalid_memory;
    // 0x0083bef7: eb0d JMP
        goto L_0083bf06;
    // 0x0083bef9: bdac7b6601 MOV
    L_0083bef9:
        t176 = 0x01667bacu;
        state.regs[5] = t176;
    // 0x0083befe: c744244cad7b6601 MOV
        t177 = 0x01667badu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t177)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf06: 53 PUSH
    L_0083bf06:
        t178a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t178a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf07: 57 PUSH
        t179a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t179a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf08: 55 PUSH
        t180a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t180a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf09: 896c2450 MOV
        t181 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t181)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf0d: e832489a00 CALL
        t182_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x0083bf12u);
        if (t182_call_status != BatchLiftStatus::returned) return t182_call_status;
        if (state.eip != 0x0083bf12u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bf12: 8b44241c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t183)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t183;
    // 0x0083bf16: 2bf7 SUB
        t184a = state.regs[6];
        t184b = state.regs[7];
        t184r = static_cast<std::uint32_t>(t184a - t184b) & 0xffffffffu;
        batch_set_sub_flags(state, t184a, t184b, t184r, 32u);
        state.regs[6] = t184r;
    // 0x0083bf18: 03f5 ADD
        t185a = state.regs[6];
        t185b = state.regs[5];
        t185r = static_cast<std::uint32_t>(t185a + t185b) & 0xffffffffu;
        batch_set_add_flags(state, t185a, t185b, t185r, 32u);
        state.regs[6] = t185r;
    // 0x0083bf1a: 83c40c ADD
        t186a = state.regs[4];
        t186b = 0x0000000cu;
        t186r = static_cast<std::uint32_t>(t186a + t186b) & 0xffffffffu;
        batch_set_add_flags(state, t186a, t186b, t186r, 32u);
        state.regs[4] = t186r;
    // 0x0083bf1d: 89742448 MOV
        t187 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t187)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf21: c60600 MOV
        t188 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t188)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf24: 89442454 MOV
        t189 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000054u), t189)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf28: c744245800000000 MOV
        t190 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000058u), t190)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf30: 8d4c2444 LEA
        t191 = static_cast<std::uint32_t>(state.regs[4] + 0x00000044u);
        state.regs[1] = t191;
    // 0x0083bf34: 51 PUSH
        t192a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t192a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf35: 8b8c2404010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000104u), t193)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t193;
    // 0x0083bf3c: 83c158 ADD
        t194a = state.regs[1];
        t194b = 0x00000058u;
        t194r = static_cast<std::uint32_t>(t194a + t194b) & 0xffffffffu;
        batch_set_add_flags(state, t194a, t194b, t194r, 32u);
        state.regs[1] = t194r;
    // 0x0083bf3f: c68424fc00000002 MOV
        t195 = 0x00000002u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000fcu), t195)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf47: e8e4e8ffff CALL
        t196_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0083a830u, 0x0083bf4cu);
        if (t196_call_status != BatchLiftStatus::returned) return t196_call_status;
        if (state.eip != 0x0083bf4cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bf4c: 8b54244c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t197)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t197;
    // 0x0083bf50: 8b442444 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t198)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t198;
    // 0x0083bf54: 2bd0 SUB
        t199a = state.regs[2];
        t199b = state.regs[0];
        t199r = static_cast<std::uint32_t>(t199a - t199b) & 0xffffffffu;
        batch_set_sub_flags(state, t199a, t199b, t199r, 32u);
        state.regs[2] = t199r;
    // 0x0083bf56: 83fa01 CMP
        t200a = state.regs[2];
        t200b = 0x00000001u;
        t200r = static_cast<std::uint32_t>(t200a - t200b) & 0xffffffffu;
        batch_set_sub_flags(state, t200a, t200b, t200r, 32u);
    // 0x0083bf59: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083bf68;
    // 0x0083bf5b: 85c0 TEST
        t202a = state.regs[0];
        t202b = state.regs[0];
        t202r = (t202a & t202b) & 0xffffffffu;
        batch_set_logic_flags(state, t202r, 32u);
    // 0x0083bf5d: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083bf68;
    // 0x0083bf5f: 50 PUSH
        t204a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t204a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf60: e81bb47000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083bf65u)) return BatchLiftStatus::invalid_memory;
        t205_call_status = spore_lift_00f47380(memory, state);
        if (t205_call_status != BatchLiftStatus::returned) return t205_call_status;
        if (state.eip != 0x0083bf65u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bf65: 83c404 ADD
        t206a = state.regs[4];
        t206b = 0x00000004u;
        t206r = static_cast<std::uint32_t>(t206a + t206b) & 0xffffffffu;
        batch_set_add_flags(state, t206a, t206b, t206r, 32u);
        state.regs[4] = t206r;
    // 0x0083bf68: 8b4c2428 MOV
    L_0083bf68:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t207)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t207;
    // 0x0083bf6c: 8b442420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t208)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t208;
    // 0x0083bf70: 2bc8 SUB
        t209a = state.regs[1];
        t209b = state.regs[0];
        t209r = static_cast<std::uint32_t>(t209a - t209b) & 0xffffffffu;
        batch_set_sub_flags(state, t209a, t209b, t209r, 32u);
        state.regs[1] = t209r;
    // 0x0083bf72: 83f901 CMP
        t210a = state.regs[1];
        t210b = 0x00000001u;
        t210r = static_cast<std::uint32_t>(t210a - t210b) & 0xffffffffu;
        batch_set_sub_flags(state, t210a, t210b, t210r, 32u);
    // 0x0083bf75: e9e4060000 JMP
        goto L_0083c65e;
    // 0x0083bf7a: 80f92a CMP
    L_0083bf7a:
        t212a = state.regs[1] & 0x000000ffu;
        t212b = 0x0000002au;
        t212r = static_cast<std::uint32_t>(t212a - t212b) & 0x000000ffu;
        batch_set_sub_flags(state, t212a, t212b, t212r, 8u);
    // 0x0083bf7d: 0f85d4000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c057;
    // 0x0083bf83: 8b4c2414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t214)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t214;
    // 0x0083bf87: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t215)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t215;
    // 0x0083bf89: 83c104 ADD
        t216a = state.regs[1];
        t216b = 0x00000004u;
        t216r = static_cast<std::uint32_t>(t216a + t216b) & 0xffffffffu;
        batch_set_add_flags(state, t216a, t216b, t216r, 32u);
        state.regs[1] = t216r;
    // 0x0083bf8c: 8d7801 LEA
        t217 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[7] = t217;
    // 0x0083bf8f: 8bc7 MOV
        t218 = state.regs[7];
        state.regs[0] = t218;
    // 0x0083bf91: 89542410 MOV
        t219 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t219)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf95: 894c2414 MOV
        t220 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t220)) return BatchLiftStatus::invalid_memory;
    // 0x0083bf99: 8d5001 LEA
        t221 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t221;
    // 0x0083bf9c: 8d642400 LEA
        t222 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t222;
    // 0x0083bfa0: 8a08 MOV
    L_0083bfa0:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t223)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t223 << 0u) & 0x000000ffu);
    // 0x0083bfa2: 40 INC
        t224a = state.regs[0];
        t224r = static_cast<std::uint32_t>(t224a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t224a, t224r, 32u);
        state.regs[0] = t224r;
    // 0x0083bfa3: 84c9 TEST
        t225a = state.regs[1] & 0x000000ffu;
        t225b = state.regs[1] & 0x000000ffu;
        t225r = (t225a & t225b) & 0x000000ffu;
        batch_set_logic_flags(state, t225r, 8u);
    // 0x0083bfa5: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083bfa0;
    // 0x0083bfa7: 2bc2 SUB
        t227a = state.regs[0];
        t227b = state.regs[2];
        t227r = static_cast<std::uint32_t>(t227a - t227b) & 0xffffffffu;
        batch_set_sub_flags(state, t227a, t227b, t227r, 32u);
        state.regs[0] = t227r;
    // 0x0083bfa9: 8d3438 LEA
        t228 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 1u + 0x00000000u);
        state.regs[6] = t228;
    // 0x0083bfac: 8bde MOV
        t229 = state.regs[6];
        state.regs[3] = t229;
    // 0x0083bfae: 2bdf SUB
        t230a = state.regs[3];
        t230b = state.regs[7];
        t230r = static_cast<std::uint32_t>(t230a - t230b) & 0xffffffffu;
        batch_set_sub_flags(state, t230a, t230b, t230r, 32u);
        state.regs[3] = t230r;
    // 0x0083bfb0: 8d4301 LEA
        t231 = static_cast<std::uint32_t>(state.regs[3] + 0x00000001u);
        state.regs[0] = t231;
    // 0x0083bfb3: 83f801 CMP
        t232a = state.regs[0];
        t232b = 0x00000001u;
        t232r = static_cast<std::uint32_t>(t232a - t232b) & 0xffffffffu;
        batch_set_sub_flags(state, t232a, t232b, t232r, 32u);
    // 0x0083bfb6: 762b JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0083bfe3;
    // 0x0083bfb8: 68d1000000 PUSH
        t234a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t234a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bfbd: 6838bb3e01 PUSH
        t235a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t235a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bfc2: 6a00 PUSH
        t236a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t236a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bfc4: 6a00 PUSH
        t237a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t237a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bfc6: 8d4301 LEA
        t238 = static_cast<std::uint32_t>(state.regs[3] + 0x00000001u);
        state.regs[0] = t238;
    // 0x0083bfc9: 688cb14101 PUSH
        t239a = 0x0141b18cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t239a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bfce: 50 PUSH
        t240a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t240a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bfcf: e8ccb37000 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x0083bfd4u)) return BatchLiftStatus::invalid_memory;
        t241_call_status = spore_lift_00f473a0(memory, state);
        if (t241_call_status != BatchLiftStatus::returned) return t241_call_status;
        if (state.eip != 0x0083bfd4u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bfd4: 8be8 MOV
        t242 = state.regs[0];
        state.regs[5] = t242;
    // 0x0083bfd6: 8d442b01 LEA
        t243 = static_cast<std::uint32_t>(state.regs[3] + state.regs[5] * 1u + 0x00000001u);
        state.regs[0] = t243;
    // 0x0083bfda: 83c418 ADD
        t244a = state.regs[4];
        t244b = 0x00000018u;
        t244r = static_cast<std::uint32_t>(t244a + t244b) & 0xffffffffu;
        batch_set_add_flags(state, t244a, t244b, t244r, 32u);
        state.regs[4] = t244r;
    // 0x0083bfdd: 8944244c MOV
        t245 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t245)) return BatchLiftStatus::invalid_memory;
    // 0x0083bfe1: eb0d JMP
        goto L_0083bff0;
    // 0x0083bfe3: bdac7b6601 MOV
    L_0083bfe3:
        t247 = 0x01667bacu;
        state.regs[5] = t247;
    // 0x0083bfe8: c744244cad7b6601 MOV
        t248 = 0x01667badu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t248)) return BatchLiftStatus::invalid_memory;
    // 0x0083bff0: 53 PUSH
    L_0083bff0:
        t249a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t249a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bff1: 57 PUSH
        t250a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t250a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bff2: 55 PUSH
        t251a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t251a)) return BatchLiftStatus::invalid_memory;
    // 0x0083bff3: 896c2450 MOV
        t252 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t252)) return BatchLiftStatus::invalid_memory;
    // 0x0083bff7: e848479a00 CALL
        t253_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x0083bffcu);
        if (t253_call_status != BatchLiftStatus::returned) return t253_call_status;
        if (state.eip != 0x0083bffcu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083bffc: 8b4c241c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t254)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t254;
    // 0x0083c000: 2bf7 SUB
        t255a = state.regs[6];
        t255b = state.regs[7];
        t255r = static_cast<std::uint32_t>(t255a - t255b) & 0xffffffffu;
        batch_set_sub_flags(state, t255a, t255b, t255r, 32u);
        state.regs[6] = t255r;
    // 0x0083c002: 03f5 ADD
        t256a = state.regs[6];
        t256b = state.regs[5];
        t256r = static_cast<std::uint32_t>(t256a + t256b) & 0xffffffffu;
        batch_set_add_flags(state, t256a, t256b, t256r, 32u);
        state.regs[6] = t256r;
    // 0x0083c004: 83c40c ADD
        t257a = state.regs[4];
        t257b = 0x0000000cu;
        t257r = static_cast<std::uint32_t>(t257a + t257b) & 0xffffffffu;
        batch_set_add_flags(state, t257a, t257b, t257r, 32u);
        state.regs[4] = t257r;
    // 0x0083c007: 89742448 MOV
        t258 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t258)) return BatchLiftStatus::invalid_memory;
    // 0x0083c00b: c60600 MOV
        t259 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t259)) return BatchLiftStatus::invalid_memory;
    // 0x0083c00e: c744245400000000 MOV
        t260 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000054u), t260)) return BatchLiftStatus::invalid_memory;
    // 0x0083c016: 894c2458 MOV
        t261 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000058u), t261)) return BatchLiftStatus::invalid_memory;
    // 0x0083c01a: 8b8c2400010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000100u), t262)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t262;
    // 0x0083c021: 8d542444 LEA
        t263 = static_cast<std::uint32_t>(state.regs[4] + 0x00000044u);
        state.regs[2] = t263;
    // 0x0083c025: 52 PUSH
        t264a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t264a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c026: 83c158 ADD
        t265a = state.regs[1];
        t265b = 0x00000058u;
        t265r = static_cast<std::uint32_t>(t265a + t265b) & 0xffffffffu;
        batch_set_add_flags(state, t265a, t265b, t265r, 32u);
        state.regs[1] = t265r;
    // 0x0083c029: c68424fc00000003 MOV
        t266 = 0x00000003u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000fcu), t266)) return BatchLiftStatus::invalid_memory;
    // 0x0083c031: e8fae7ffff CALL
        t267_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0083a830u, 0x0083c036u);
        if (t267_call_status != BatchLiftStatus::returned) return t267_call_status;
        if (state.eip != 0x0083c036u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c036: 8b4c244c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t268)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t268;
    // 0x0083c03a: 8b442444 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t269)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t269;
    // 0x0083c03e: 2bc8 SUB
        t270a = state.regs[1];
        t270b = state.regs[0];
        t270r = static_cast<std::uint32_t>(t270a - t270b) & 0xffffffffu;
        batch_set_sub_flags(state, t270a, t270b, t270r, 32u);
        state.regs[1] = t270r;
    // 0x0083c040: 83f901 CMP
        t271a = state.regs[1];
        t271b = 0x00000001u;
        t271r = static_cast<std::uint32_t>(t271a - t271b) & 0xffffffffu;
        batch_set_sub_flags(state, t271a, t271b, t271r, 32u);
    // 0x0083c043: 0f8e08060000 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c651;
    // 0x0083c049: 85c0 TEST
        t273a = state.regs[0];
        t273b = state.regs[0];
        t273r = (t273a & t273b) & 0xffffffffu;
        batch_set_logic_flags(state, t273r, 32u);
    // 0x0083c04b: 0f8400060000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c651;
    // 0x0083c051: 50 PUSH
        t275a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t275a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c052: e9f2050000 JMP
        goto L_0083c649;
    // 0x0083c057: 6884b54101 PUSH
    L_0083c057:
        t277a = 0x0141b584u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t277a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c05c: 8d442424 LEA
        t278 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[0] = t278;
    // 0x0083c060: 50 PUSH
        t279a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t279a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c061: 8d8c24c8000000 LEA
        t280 = static_cast<std::uint32_t>(state.regs[4] + 0x000000c8u);
        state.regs[1] = t280;
    // 0x0083c068: 51 PUSH
        t281a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t281a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c069: e822d0ffff CALL
        t282_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00839090u, 0x0083c06eu);
        if (t282_call_status != BatchLiftStatus::returned) return t282_call_status;
        if (state.eip != 0x0083c06eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c06e: 83c40c ADD
        t283a = state.regs[4];
        t283b = 0x0000000cu;
        t283r = static_cast<std::uint32_t>(t283a + t283b) & 0xffffffffu;
        batch_set_add_flags(state, t283a, t283b, t283r, 32u);
        state.regs[4] = t283r;
    // 0x0083c071: 8d542430 LEA
        t284 = static_cast<std::uint32_t>(state.regs[4] + 0x00000030u);
        state.regs[2] = t284;
    // 0x0083c075: c68424f800000004 MOV
        t285 = 0x00000004u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t285)) return BatchLiftStatus::invalid_memory;
    // 0x0083c07d: 3bc2 CMP
        t286a = state.regs[0];
        t286b = state.regs[2];
        t286r = static_cast<std::uint32_t>(t286a - t286b) & 0xffffffffu;
        batch_set_sub_flags(state, t286a, t286b, t286r, 32u);
    // 0x0083c07f: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c099;
    // 0x0083c081: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t288)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t288;
    // 0x0083c084: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t289)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t289;
    // 0x0083c086: 51 PUSH
        t290a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t290a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c087: 52 PUSH
        t291a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t291a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c088: 8d4c2438 LEA
        t292 = static_cast<std::uint32_t>(state.regs[4] + 0x00000038u);
        state.regs[1] = t292;
    // 0x0083c08c: e81f8cc1ff CALL
        t293_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00454cb0u, 0x0083c091u);
        if (t293_call_status != BatchLiftStatus::returned) return t293_call_status;
        if (state.eip != 0x0083c091u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c091: 8b7c2434 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t294)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t294;
    // 0x0083c095: 8b742430 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t295)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t295;
    // 0x0083c099: 8b8c24c8000000 MOV
    L_0083c099:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x000000c8u), t296)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t296;
    // 0x0083c0a0: 8b8424c0000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x000000c0u), t297)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t297;
    // 0x0083c0a7: 2bc8 SUB
        t298a = state.regs[1];
        t298b = state.regs[0];
        t298r = static_cast<std::uint32_t>(t298a - t298b) & 0xffffffffu;
        batch_set_sub_flags(state, t298a, t298b, t298r, 32u);
        state.regs[1] = t298r;
    // 0x0083c0a9: 33db XOR
        t299a = state.regs[3];
        t299b = state.regs[3];
        t299r = (t299a ^ t299b) & 0xffffffffu;
        batch_set_logic_flags(state, t299r, 32u);
        state.regs[3] = t299r;
    // 0x0083c0ab: 83f901 CMP
        t300a = state.regs[1];
        t300b = 0x00000001u;
        t300r = static_cast<std::uint32_t>(t300a - t300b) & 0xffffffffu;
        batch_set_sub_flags(state, t300a, t300b, t300r, 32u);
    // 0x0083c0ae: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c0bd;
    // 0x0083c0b0: 3bc3 CMP
        t302a = state.regs[0];
        t302b = state.regs[3];
        t302r = static_cast<std::uint32_t>(t302a - t302b) & 0xffffffffu;
        batch_set_sub_flags(state, t302a, t302b, t302r, 32u);
    // 0x0083c0b2: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c0bd;
    // 0x0083c0b4: 50 PUSH
        t304a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t304a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c0b5: e8c6b27000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c0bau)) return BatchLiftStatus::invalid_memory;
        t305_call_status = spore_lift_00f47380(memory, state);
        if (t305_call_status != BatchLiftStatus::returned) return t305_call_status;
        if (state.eip != 0x0083c0bau) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c0ba: 83c404 ADD
        t306a = state.regs[4];
        t306b = 0x00000004u;
        t306r = static_cast<std::uint32_t>(t306a + t306b) & 0xffffffffu;
        batch_set_add_flags(state, t306a, t306b, t306r, 32u);
        state.regs[4] = t306r;
    // 0x0083c0bd: b8ac7b6601 MOV
    L_0083c0bd:
        t307 = 0x01667bacu;
        state.regs[0] = t307;
    // 0x0083c0c2: b9ad7b6601 MOV
        t308 = 0x01667badu;
        state.regs[1] = t308;
    // 0x0083c0c7: 89442478 MOV
        t309 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000078u), t309)) return BatchLiftStatus::invalid_memory;
    // 0x0083c0cb: 8944247c MOV
        t310 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000007cu), t310)) return BatchLiftStatus::invalid_memory;
    // 0x0083c0cf: 898c2480000000 MOV
        t311 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000080u), t311)) return BatchLiftStatus::invalid_memory;
    // 0x0083c0d6: 89842488000000 MOV
        t312 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000088u), t312)) return BatchLiftStatus::invalid_memory;
    // 0x0083c0dd: 8984248c000000 MOV
        t313 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000008cu), t313)) return BatchLiftStatus::invalid_memory;
    // 0x0083c0e4: 898c2490000000 MOV
        t314 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000090u), t314)) return BatchLiftStatus::invalid_memory;
    // 0x0083c0eb: 899c2498000000 MOV
        t315 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000098u), t315)) return BatchLiftStatus::invalid_memory;
    // 0x0083c0f2: 899c249c000000 MOV
        t316 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000009cu), t316)) return BatchLiftStatus::invalid_memory;
    // 0x0083c0f9: 899c24a0000000 MOV
        t317 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x000000a0u), t317)) return BatchLiftStatus::invalid_memory;
    // 0x0083c100: c68424f800000005 MOV
        t318 = 0x00000005u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t318)) return BatchLiftStatus::invalid_memory;
    // 0x0083c108: 3bf7 CMP
        t319a = state.regs[6];
        t319b = state.regs[7];
        t319r = static_cast<std::uint32_t>(t319a - t319b) & 0xffffffffu;
        batch_set_sub_flags(state, t319a, t319b, t319r, 32u);
    // 0x0083c10a: 0f848e000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c19e;
    // 0x0083c110: 803e2d CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t321a)) return BatchLiftStatus::invalid_memory;
        t321b = 0x0000002du;
        t321r = static_cast<std::uint32_t>(t321a - t321b) & 0x000000ffu;
        batch_set_sub_flags(state, t321a, t321b, t321r, 8u);
    // 0x0083c113: 0f8585000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c19e;
    // 0x0083c119: 0fb65601 MOVZX
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000001u), t323a)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t323a;
    // 0x0083c11d: 8d5e01 LEA
        t324 = static_cast<std::uint32_t>(state.regs[6] + 0x00000001u);
        state.regs[3] = t324;
    // 0x0083c120: 52 PUSH
        t325a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t325a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c121: ff1518c53c01 CALL
        t326_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!isalpha", 0x013cc518u, 0x0083c127u);
        if (t326_call_status != BatchLiftStatus::returned) return t326_call_status;
        if (state.eip != 0x0083c127u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c127: 83c404 ADD
        t327a = state.regs[4];
        t327b = 0x00000004u;
        t327r = static_cast<std::uint32_t>(t327a + t327b) & 0xffffffffu;
        batch_set_add_flags(state, t327a, t327b, t327r, 32u);
        state.regs[4] = t327r;
    // 0x0083c12a: 85c0 TEST
        t328a = state.regs[0];
        t328b = state.regs[0];
        t328r = (t328a & t328b) & 0xffffffffu;
        batch_set_logic_flags(state, t328r, 32u);
    // 0x0083c12c: 7470 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c19e;
    // 0x0083c12e: 807fff5e CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0xffffffffu), t330a)) return BatchLiftStatus::invalid_memory;
        t330b = 0x0000005eu;
        t330r = static_cast<std::uint32_t>(t330a - t330b) & 0x000000ffu;
        batch_set_sub_flags(state, t330a, t330b, t330r, 8u);
    // 0x0083c132: c644241b01 MOV
        t331 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001bu), t331)) return BatchLiftStatus::invalid_memory;
    // 0x0083c137: 0f8514010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c251;
    // 0x0083c13d: 8bcf MOV
        t333 = state.regs[7];
        state.regs[1] = t333;
    // 0x0083c13f: 2bce SUB
        t334a = state.regs[1];
        t334b = state.regs[6];
        t334r = static_cast<std::uint32_t>(t334a - t334b) & 0xffffffffu;
        batch_set_sub_flags(state, t334a, t334b, t334r, 32u);
        state.regs[1] = t334r;
    // 0x0083c141: 49 DEC
        t335a = state.regs[1];
        t335r = static_cast<std::uint32_t>(t335a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t335a, t335r, 32u);
        state.regs[1] = t335r;
    // 0x0083c142: 8bc7 MOV
        t336 = state.regs[7];
        state.regs[0] = t336;
    // 0x0083c144: 2bc1 SUB
        t337a = state.regs[0];
        t337b = state.regs[1];
        t337r = static_cast<std::uint32_t>(t337a - t337b) & 0xffffffffu;
        batch_set_sub_flags(state, t337a, t337b, t337r, 32u);
        state.regs[0] = t337r;
    // 0x0083c146: 2bc6 SUB
        t338a = state.regs[0];
        t338b = state.regs[6];
        t338r = static_cast<std::uint32_t>(t338a - t338b) & 0xffffffffu;
        batch_set_sub_flags(state, t338a, t338b, t338r, 32u);
        state.regs[0] = t338r;
    // 0x0083c148: 89442410 MOV
        t339 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t339)) return BatchLiftStatus::invalid_memory;
    // 0x0083c14c: 83f801 CMP
        t340a = state.regs[0];
        t340b = 0x00000001u;
        t340r = static_cast<std::uint32_t>(t340a - t340b) & 0xffffffffu;
        batch_set_sub_flags(state, t340a, t340b, t340r, 32u);
    // 0x0083c14f: c744241c01000000 MOV
        t341 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t341)) return BatchLiftStatus::invalid_memory;
    // 0x0083c157: 8d442410 LEA
        t342 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t342;
    // 0x0083c15b: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0083c161;
    // 0x0083c15d: 8d44241c LEA
        t344 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[0] = t344;
    // 0x0083c161: 8b00 MOV
    L_0083c161:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t345)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t345;
    // 0x0083c163: 03c1 ADD
        t346a = state.regs[0];
        t346b = state.regs[1];
        t346r = static_cast<std::uint32_t>(t346a + t346b) & 0xffffffffu;
        batch_set_add_flags(state, t346a, t346b, t346r, 32u);
        state.regs[0] = t346r;
    // 0x0083c165: 03c6 ADD
        t347a = state.regs[0];
        t347b = state.regs[6];
        t347r = static_cast<std::uint32_t>(t347a + t347b) & 0xffffffffu;
        batch_set_add_flags(state, t347a, t347b, t347r, 32u);
        state.regs[0] = t347r;
    // 0x0083c167: 8d2c31 LEA
        t348 = static_cast<std::uint32_t>(state.regs[1] + state.regs[6] * 1u + 0x00000000u);
        state.regs[5] = t348;
    // 0x0083c16a: 3be8 CMP
        t349a = state.regs[5];
        t349b = state.regs[0];
        t349r = static_cast<std::uint32_t>(t349a - t349b) & 0xffffffffu;
        batch_set_sub_flags(state, t349a, t349b, t349r, 32u);
    // 0x0083c16c: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c185;
    // 0x0083c16e: 2bf8 SUB
        t351a = state.regs[7];
        t351b = state.regs[0];
        t351r = static_cast<std::uint32_t>(t351a - t351b) & 0xffffffffu;
        batch_set_sub_flags(state, t351a, t351b, t351r, 32u);
        state.regs[7] = t351r;
    // 0x0083c170: 8d4f01 LEA
        t352 = static_cast<std::uint32_t>(state.regs[7] + 0x00000001u);
        state.regs[1] = t352;
    // 0x0083c173: 51 PUSH
        t353a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t353a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c174: 50 PUSH
        t354a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t354a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c175: 55 PUSH
        t355a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t355a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c176: ff1580c43c01 CALL
        t356_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memmove", 0x013cc480u, 0x0083c17cu);
        if (t356_call_status != BatchLiftStatus::returned) return t356_call_status;
        if (state.eip != 0x0083c17cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c17c: 83c40c ADD
        t357a = state.regs[4];
        t357b = 0x0000000cu;
        t357r = static_cast<std::uint32_t>(t357a + t357b) & 0xffffffffu;
        batch_set_add_flags(state, t357a, t357b, t357r, 32u);
        state.regs[4] = t357r;
    // 0x0083c17f: 03fd ADD
        t358a = state.regs[7];
        t358b = state.regs[5];
        t358r = static_cast<std::uint32_t>(t358a + t358b) & 0xffffffffu;
        batch_set_add_flags(state, t358a, t358b, t358r, 32u);
        state.regs[7] = t358r;
    // 0x0083c181: 897c2434 MOV
        t359 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t359)) return BatchLiftStatus::invalid_memory;
    // 0x0083c185: 8b442414 MOV
    L_0083c185:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t360)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t360;
    // 0x0083c189: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t361)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t361;
    // 0x0083c18b: 83c004 ADD
        t362a = state.regs[0];
        t362b = 0x00000004u;
        t362r = static_cast<std::uint32_t>(t362a + t362b) & 0xffffffffu;
        batch_set_add_flags(state, t362a, t362b, t362r, 32u);
        state.regs[0] = t362r;
    // 0x0083c18e: 89442414 MOV
        t363 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t363)) return BatchLiftStatus::invalid_memory;
    // 0x0083c192: 899424ac000000 MOV
        t364 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x000000acu), t364)) return BatchLiftStatus::invalid_memory;
    // 0x0083c199: e9be000000 JMP
        goto L_0083c25c;
    // 0x0083c19e: 8b842400010000 MOV
    L_0083c19e:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000100u), t366)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t366;
    // 0x0083c1a5: 83c030 ADD
        t367a = state.regs[0];
        t367b = 0x00000030u;
        t367r = static_cast<std::uint32_t>(t367a + t367b) & 0xffffffffu;
        batch_set_add_flags(state, t367a, t367b, t367r, 32u);
        state.regs[0] = t367r;
    // 0x0083c1a8: c644241b00 MOV
        t368 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001bu), t368)) return BatchLiftStatus::invalid_memory;
    // 0x0083c1ad: 89442410 MOV
        t369 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t369)) return BatchLiftStatus::invalid_memory;
    // 0x0083c1b1: 33db XOR
    L_0083c1b1:
        t370a = state.regs[3];
        t370b = state.regs[3];
        t370r = (t370a ^ t370b) & 0xffffffffu;
        batch_set_logic_flags(state, t370r, 32u);
        state.regs[3] = t370r;
    // 0x0083c1b3: 33ed XOR
        t371a = state.regs[5];
        t371b = state.regs[5];
        t371r = (t371a ^ t371b) & 0xffffffffu;
        batch_set_logic_flags(state, t371r, 32u);
        state.regs[5] = t371r;
    // 0x0083c1b5: 3bf7 CMP
        t372a = state.regs[6];
        t372b = state.regs[7];
        t372r = static_cast<std::uint32_t>(t372a - t372b) & 0xffffffffu;
        batch_set_sub_flags(state, t372a, t372b, t372r, 32u);
    // 0x0083c1b7: 0f848e030000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c54b;
    // 0x0083c1bd: 8d4900 LEA
        t374 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t374;
    // 0x0083c1c0: 68a8b24101 PUSH
    L_0083c1c0:
        t375a = 0x0141b2a8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t375a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c1c5: 56 PUSH
        t376a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t376a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c1c6: ff15dcc43c01 CALL
        t377_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_stricmp", 0x013cc4dcu, 0x0083c1ccu);
        if (t377_call_status != BatchLiftStatus::returned) return t377_call_status;
        if (state.eip != 0x0083c1ccu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c1cc: 83c408 ADD
        t378a = state.regs[4];
        t378b = 0x00000008u;
        t378r = static_cast<std::uint32_t>(t378a + t378b) & 0xffffffffu;
        batch_set_add_flags(state, t378a, t378b, t378r, 32u);
        state.regs[4] = t378r;
    // 0x0083c1cf: 85c0 TEST
        t379a = state.regs[0];
        t379b = state.regs[0];
        t379r = (t379a & t379b) & 0xffffffffu;
        batch_set_logic_flags(state, t379r, 32u);
    // 0x0083c1d1: 0f852f010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c306;
    // 0x0083c1d7: 8b442420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t381)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t381;
    // 0x0083c1db: 3b442424 CMP
        t382a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t382b)) return BatchLiftStatus::invalid_memory;
        t382r = static_cast<std::uint32_t>(t382a - t382b) & 0xffffffffu;
        batch_set_sub_flags(state, t382a, t382b, t382r, 32u);
    // 0x0083c1df: 0f85b1040000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c696;
    // 0x0083c1e5: 8b4c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t384)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t384;
    // 0x0083c1e9: 8b4104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t385)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t385;
    // 0x0083c1ec: 3901 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t386a)) return BatchLiftStatus::invalid_memory;
        t386b = state.regs[0];
        t386r = static_cast<std::uint32_t>(t386a - t386b) & 0xffffffffu;
        batch_set_sub_flags(state, t386a, t386b, t386r, 32u);
    // 0x0083c1ee: 0f84e6040000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c6da;
    // 0x0083c1f4: 8148e000c00000 OR
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xffffffe0u), t388a)) return BatchLiftStatus::invalid_memory;
        t388b = 0x0000c000u;
        t388r = (t388a | t388b) & 0xffffffffu;
        batch_set_logic_flags(state, t388r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0xffffffe0u), t388r)) return BatchLiftStatus::invalid_memory;
    // 0x0083c1fb: 6884b54101 PUSH
        t389a = 0x0141b584u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t389a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c200: 8d4c2424 LEA
        t390 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[1] = t390;
    // 0x0083c204: 51 PUSH
        t391a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t391a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c205: 8d9424e8000000 LEA
        t392 = static_cast<std::uint32_t>(state.regs[4] + 0x000000e8u);
        state.regs[2] = t392;
    // 0x0083c20c: 52 PUSH
        t393a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t393a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c20d: e87eceffff CALL
        t394_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00839090u, 0x0083c212u);
        if (t394_call_status != BatchLiftStatus::returned) return t394_call_status;
        if (state.eip != 0x0083c212u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c212: 83c40c ADD
        t395a = state.regs[4];
        t395b = 0x0000000cu;
        t395r = static_cast<std::uint32_t>(t395a + t395b) & 0xffffffffu;
        batch_set_add_flags(state, t395a, t395b, t395r, 32u);
        state.regs[4] = t395r;
    // 0x0083c215: 8d4c2430 LEA
        t396 = static_cast<std::uint32_t>(state.regs[4] + 0x00000030u);
        state.regs[1] = t396;
    // 0x0083c219: c68424f800000007 MOV
        t397 = 0x00000007u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t397)) return BatchLiftStatus::invalid_memory;
    // 0x0083c221: 3bc1 CMP
        t398a = state.regs[0];
        t398b = state.regs[1];
        t398r = static_cast<std::uint32_t>(t398a - t398b) & 0xffffffffu;
        batch_set_sub_flags(state, t398a, t398b, t398r, 32u);
    // 0x0083c223: 7414 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c239;
    // 0x0083c225: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t400)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t400;
    // 0x0083c228: 8b00 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t401)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t401;
    // 0x0083c22a: 52 PUSH
        t402a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t402a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c22b: 50 PUSH
        t403a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t403a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c22c: e87f8ac1ff CALL
        t404_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00454cb0u, 0x0083c231u);
        if (t404_call_status != BatchLiftStatus::returned) return t404_call_status;
        if (state.eip != 0x0083c231u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c231: 8b7c2434 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t405)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t405;
    // 0x0083c235: 8b742430 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t406)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t406;
    // 0x0083c239: 8b8c24e8000000 MOV
    L_0083c239:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x000000e8u), t407)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t407;
    // 0x0083c240: 8b8424e0000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x000000e0u), t408)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t408;
    // 0x0083c247: 2bc8 SUB
        t409a = state.regs[1];
        t409b = state.regs[0];
        t409r = static_cast<std::uint32_t>(t409a - t409b) & 0xffffffffu;
        batch_set_sub_flags(state, t409a, t409b, t409r, 32u);
        state.regs[1] = t409r;
    // 0x0083c249: 83f901 CMP
        t410a = state.regs[1];
        t410b = 0x00000001u;
        t410r = static_cast<std::uint32_t>(t410a - t410b) & 0xffffffffu;
        batch_set_sub_flags(state, t410a, t410b, t410r, 32u);
    // 0x0083c24c: e9d3020000 JMP
        goto L_0083c524;
    // 0x0083c251: c78424ac000000ffffffff MOV
    L_0083c251:
        t412 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x000000acu), t412)) return BatchLiftStatus::invalid_memory;
    // 0x0083c25c: 8bc7 MOV
    L_0083c25c:
        t413 = state.regs[7];
        state.regs[0] = t413;
    // 0x0083c25e: 2bc6 SUB
        t414a = state.regs[0];
        t414b = state.regs[6];
        t414r = static_cast<std::uint32_t>(t414a - t414b) & 0xffffffffu;
        batch_set_sub_flags(state, t414a, t414b, t414r, 32u);
        state.regs[0] = t414r;
    // 0x0083c260: 48 DEC
        t415a = state.regs[0];
        t415r = static_cast<std::uint32_t>(t415a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t415a, t415r, 32u);
        state.regs[0] = t415r;
    // 0x0083c261: 8944241c MOV
        t416 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t416)) return BatchLiftStatus::invalid_memory;
    // 0x0083c265: 83f8ff CMP
        t417a = state.regs[0];
        t417b = 0xffffffffu;
        t417r = static_cast<std::uint32_t>(t417a - t417b) & 0xffffffffu;
        batch_set_sub_flags(state, t417a, t417b, t417r, 32u);
    // 0x0083c268: c7442410ffffffff MOV
        t418 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t418)) return BatchLiftStatus::invalid_memory;
    // 0x0083c270: 8d44241c LEA
        t419 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[0] = t419;
    // 0x0083c274: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0083c27a;
    // 0x0083c276: 8d442410 LEA
        t421 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t421;
    // 0x0083c27a: 8b00 MOV
    L_0083c27a:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t422)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t422;
    // 0x0083c27c: 8d4c3001 LEA
        t423 = static_cast<std::uint32_t>(state.regs[0] + state.regs[6] * 1u + 0x00000001u);
        state.regs[1] = t423;
    // 0x0083c280: 51 PUSH
        t424a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t424a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c281: 53 PUSH
        t425a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t425a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c282: 8d8c2480000000 LEA
        t426 = static_cast<std::uint32_t>(state.regs[4] + 0x00000080u);
        state.regs[1] = t426;
    // 0x0083c289: e8228ac1ff CALL
        t427_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00454cb0u, 0x0083c28eu);
        if (t427_call_status != BatchLiftStatus::returned) return t427_call_status;
        if (state.eip != 0x0083c28eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c28e: 6884b54101 PUSH
        t428a = 0x0141b584u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t428a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c293: 8d542424 LEA
        t429 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[2] = t429;
    // 0x0083c297: 52 PUSH
        t430a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t430a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c298: 8d8424b8000000 LEA
        t431 = static_cast<std::uint32_t>(state.regs[4] + 0x000000b8u);
        state.regs[0] = t431;
    // 0x0083c29f: 50 PUSH
        t432a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t432a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c2a0: e8ebcdffff CALL
        t433_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00839090u, 0x0083c2a5u);
        if (t433_call_status != BatchLiftStatus::returned) return t433_call_status;
        if (state.eip != 0x0083c2a5u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c2a5: 83c40c ADD
        t434a = state.regs[4];
        t434b = 0x0000000cu;
        t434r = static_cast<std::uint32_t>(t434a + t434b) & 0xffffffffu;
        batch_set_add_flags(state, t434a, t434b, t434r, 32u);
        state.regs[4] = t434r;
    // 0x0083c2a8: 8d4c2430 LEA
        t435 = static_cast<std::uint32_t>(state.regs[4] + 0x00000030u);
        state.regs[1] = t435;
    // 0x0083c2ac: c68424f800000006 MOV
        t436 = 0x00000006u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t436)) return BatchLiftStatus::invalid_memory;
    // 0x0083c2b4: 3bc1 CMP
        t437a = state.regs[0];
        t437b = state.regs[1];
        t437r = static_cast<std::uint32_t>(t437a - t437b) & 0xffffffffu;
        batch_set_sub_flags(state, t437a, t437b, t437r, 32u);
    // 0x0083c2b6: 7414 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c2cc;
    // 0x0083c2b8: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t439)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t439;
    // 0x0083c2bb: 8b00 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t440)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t440;
    // 0x0083c2bd: 52 PUSH
        t441a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t441a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c2be: 50 PUSH
        t442a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t442a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c2bf: e8ec89c1ff CALL
        t443_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00454cb0u, 0x0083c2c4u);
        if (t443_call_status != BatchLiftStatus::returned) return t443_call_status;
        if (state.eip != 0x0083c2c4u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c2c4: 8b7c2434 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t444)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t444;
    // 0x0083c2c8: 8b742430 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t445)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t445;
    // 0x0083c2cc: 8b8c24b8000000 MOV
    L_0083c2cc:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x000000b8u), t446)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t446;
    // 0x0083c2d3: 8b8424b0000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x000000b0u), t447)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t447;
    // 0x0083c2da: 2bc8 SUB
        t448a = state.regs[1];
        t448b = state.regs[0];
        t448r = static_cast<std::uint32_t>(t448a - t448b) & 0xffffffffu;
        batch_set_sub_flags(state, t448a, t448b, t448r, 32u);
        state.regs[1] = t448r;
    // 0x0083c2dc: 83f901 CMP
        t449a = state.regs[1];
        t449b = 0x00000001u;
        t449r = static_cast<std::uint32_t>(t449a - t449b) & 0xffffffffu;
        batch_set_sub_flags(state, t449a, t449b, t449r, 32u);
    // 0x0083c2df: c68424f800000005 MOV
        t450 = 0x00000005u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t450)) return BatchLiftStatus::invalid_memory;
    // 0x0083c2e7: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c2f6;
    // 0x0083c2e9: 85c0 TEST
        t452a = state.regs[0];
        t452b = state.regs[0];
        t452r = (t452a & t452b) & 0xffffffffu;
        batch_set_logic_flags(state, t452r, 32u);
    // 0x0083c2eb: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c2f6;
    // 0x0083c2ed: 50 PUSH
        t454a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t454a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c2ee: e88db07000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c2f3u)) return BatchLiftStatus::invalid_memory;
        t455_call_status = spore_lift_00f47380(memory, state);
        if (t455_call_status != BatchLiftStatus::returned) return t455_call_status;
        if (state.eip != 0x0083c2f3u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c2f3: 83c404 ADD
        t456a = state.regs[4];
        t456b = 0x00000004u;
        t456r = static_cast<std::uint32_t>(t456a + t456b) & 0xffffffffu;
        batch_set_add_flags(state, t456a, t456b, t456r, 32u);
        state.regs[4] = t456r;
    // 0x0083c2f6: 8d942498000000 LEA
    L_0083c2f6:
        t457 = static_cast<std::uint32_t>(state.regs[4] + 0x00000098u);
        state.regs[2] = t457;
    // 0x0083c2fd: 89542410 MOV
        t458 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t458)) return BatchLiftStatus::invalid_memory;
    // 0x0083c301: e9abfeffff JMP
        goto L_0083c1b1;
    // 0x0083c306: b8ac7b6601 MOV
    L_0083c306:
        t460 = 0x01667bacu;
        state.regs[0] = t460;
    // 0x0083c30b: 89442448 MOV
        t461 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t461)) return BatchLiftStatus::invalid_memory;
    // 0x0083c30f: 8944244c MOV
        t462 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t462)) return BatchLiftStatus::invalid_memory;
    // 0x0083c313: c7442450ad7b6601 MOV
        t463 = 0x01667badu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t463)) return BatchLiftStatus::invalid_memory;
    // 0x0083c31b: 803e5b CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t464a)) return BatchLiftStatus::invalid_memory;
        t464b = 0x0000005bu;
        t464r = static_cast<std::uint32_t>(t464a - t464b) & 0x000000ffu;
        batch_set_sub_flags(state, t464a, t464b, t464r, 8u);
    // 0x0083c31e: c68424f800000008 MOV
        t465 = 0x00000008u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t465)) return BatchLiftStatus::invalid_memory;
    // 0x0083c326: 753d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c365;
    // 0x0083c328: 8bc7 MOV
        t467 = state.regs[7];
        state.regs[0] = t467;
    // 0x0083c32a: 2bc6 SUB
        t468a = state.regs[0];
        t468b = state.regs[6];
        t468r = static_cast<std::uint32_t>(t468a - t468b) & 0xffffffffu;
        batch_set_sub_flags(state, t468a, t468b, t468r, 32u);
        state.regs[0] = t468r;
    // 0x0083c32c: 43 INC
        t469a = state.regs[3];
        t469r = static_cast<std::uint32_t>(t469a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t469a, t469r, 32u);
        state.regs[3] = t469r;
    // 0x0083c32d: 8944241c MOV
        t470 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t470)) return BatchLiftStatus::invalid_memory;
    // 0x0083c331: 83f801 CMP
        t471a = state.regs[0];
        t471b = 0x00000001u;
        t471r = static_cast<std::uint32_t>(t471a - t471b) & 0xffffffffu;
        batch_set_sub_flags(state, t471a, t471b, t471r, 32u);
    // 0x0083c334: c744244001000000 MOV
        t472 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t472)) return BatchLiftStatus::invalid_memory;
    // 0x0083c33c: 8d44241c LEA
        t473 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[0] = t473;
    // 0x0083c340: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0083c346;
    // 0x0083c342: 8d442440 LEA
        t475 = static_cast<std::uint32_t>(state.regs[4] + 0x00000040u);
        state.regs[0] = t475;
    // 0x0083c346: 8b00 MOV
    L_0083c346:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t476)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t476;
    // 0x0083c348: 03c6 ADD
        t477a = state.regs[0];
        t477b = state.regs[6];
        t477r = static_cast<std::uint32_t>(t477a + t477b) & 0xffffffffu;
        batch_set_add_flags(state, t477a, t477b, t477r, 32u);
        state.regs[0] = t477r;
    // 0x0083c34a: 3bf0 CMP
        t478a = state.regs[6];
        t478b = state.regs[0];
        t478r = static_cast<std::uint32_t>(t478a - t478b) & 0xffffffffu;
        batch_set_sub_flags(state, t478a, t478b, t478r, 32u);
    // 0x0083c34c: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c365;
    // 0x0083c34e: 2bf8 SUB
        t480a = state.regs[7];
        t480b = state.regs[0];
        t480r = static_cast<std::uint32_t>(t480a - t480b) & 0xffffffffu;
        batch_set_sub_flags(state, t480a, t480b, t480r, 32u);
        state.regs[7] = t480r;
    // 0x0083c350: 8d5701 LEA
        t481 = static_cast<std::uint32_t>(state.regs[7] + 0x00000001u);
        state.regs[2] = t481;
    // 0x0083c353: 52 PUSH
        t482a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t482a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c354: 50 PUSH
        t483a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t483a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c355: 56 PUSH
        t484a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t484a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c356: ff1580c43c01 CALL
        t485_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memmove", 0x013cc480u, 0x0083c35cu);
        if (t485_call_status != BatchLiftStatus::returned) return t485_call_status;
        if (state.eip != 0x0083c35cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c35c: 83c40c ADD
        t486a = state.regs[4];
        t486b = 0x0000000cu;
        t486r = static_cast<std::uint32_t>(t486a + t486b) & 0xffffffffu;
        batch_set_add_flags(state, t486a, t486b, t486r, 32u);
        state.regs[4] = t486r;
    // 0x0083c35f: 03fe ADD
        t487a = state.regs[7];
        t487b = state.regs[6];
        t487r = static_cast<std::uint32_t>(t487a + t487b) & 0xffffffffu;
        batch_set_add_flags(state, t487a, t487b, t487r, 32u);
        state.regs[7] = t487r;
    // 0x0083c361: 897c2434 MOV
        t488 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t488)) return BatchLiftStatus::invalid_memory;
    // 0x0083c365: 3bdd CMP
    L_0083c365:
        t489a = state.regs[3];
        t489b = state.regs[5];
        t489r = static_cast<std::uint32_t>(t489a - t489b) & 0xffffffffu;
        batch_set_sub_flags(state, t489a, t489b, t489r, 32u);
    // 0x0083c367: 0f94c0 SETZ
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x0083c36a: 8844245c MOV
        t491 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000005cu), t491)) return BatchLiftStatus::invalid_memory;
    // 0x0083c36e: 3bf7 CMP
        t492a = state.regs[6];
        t492b = state.regs[7];
        t492r = static_cast<std::uint32_t>(t492a - t492b) & 0xffffffffu;
        batch_set_sub_flags(state, t492a, t492b, t492r, 32u);
    // 0x0083c370: 7453 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c3c5;
    // 0x0083c372: 807fff5d CMP
    L_0083c372:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0xffffffffu), t494a)) return BatchLiftStatus::invalid_memory;
        t494b = 0x0000005du;
        t494r = static_cast<std::uint32_t>(t494a - t494b) & 0x000000ffu;
        batch_set_sub_flags(state, t494a, t494b, t494r, 8u);
    // 0x0083c376: 7549 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c3c1;
    // 0x0083c378: 8bc7 MOV
        t496 = state.regs[7];
        state.regs[0] = t496;
    // 0x0083c37a: 2bc6 SUB
        t497a = state.regs[0];
        t497b = state.regs[6];
        t497r = static_cast<std::uint32_t>(t497a - t497b) & 0xffffffffu;
        batch_set_sub_flags(state, t497a, t497b, t497r, 32u);
        state.regs[0] = t497r;
    // 0x0083c37c: 48 DEC
        t498a = state.regs[0];
        t498r = static_cast<std::uint32_t>(t498a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t498a, t498r, 32u);
        state.regs[0] = t498r;
    // 0x0083c37d: 8bcf MOV
        t499 = state.regs[7];
        state.regs[1] = t499;
    // 0x0083c37f: 2bc8 SUB
        t500a = state.regs[1];
        t500b = state.regs[0];
        t500r = static_cast<std::uint32_t>(t500a - t500b) & 0xffffffffu;
        batch_set_sub_flags(state, t500a, t500b, t500r, 32u);
        state.regs[1] = t500r;
    // 0x0083c381: 2bce SUB
        t501a = state.regs[1];
        t501b = state.regs[6];
        t501r = static_cast<std::uint32_t>(t501a - t501b) & 0xffffffffu;
        batch_set_sub_flags(state, t501a, t501b, t501r, 32u);
        state.regs[1] = t501r;
    // 0x0083c383: 4b DEC
        t502a = state.regs[3];
        t502r = static_cast<std::uint32_t>(t502a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t502a, t502r, 32u);
        state.regs[3] = t502r;
    // 0x0083c384: 894c2440 MOV
        t503 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t503)) return BatchLiftStatus::invalid_memory;
    // 0x0083c388: 83f901 CMP
        t504a = state.regs[1];
        t504b = 0x00000001u;
        t504r = static_cast<std::uint32_t>(t504a - t504b) & 0xffffffffu;
        batch_set_sub_flags(state, t504a, t504b, t504r, 32u);
    // 0x0083c38b: c744241c01000000 MOV
        t505 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t505)) return BatchLiftStatus::invalid_memory;
    // 0x0083c393: 8d4c2440 LEA
        t506 = static_cast<std::uint32_t>(state.regs[4] + 0x00000040u);
        state.regs[1] = t506;
    // 0x0083c397: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0083c39d;
    // 0x0083c399: 8d4c241c LEA
        t508 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[1] = t508;
    // 0x0083c39d: 8b09 MOV
    L_0083c39d:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t509)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t509;
    // 0x0083c39f: 03c8 ADD
        t510a = state.regs[1];
        t510b = state.regs[0];
        t510r = static_cast<std::uint32_t>(t510a + t510b) & 0xffffffffu;
        batch_set_add_flags(state, t510a, t510b, t510r, 32u);
        state.regs[1] = t510r;
    // 0x0083c3a1: 03ce ADD
        t511a = state.regs[1];
        t511b = state.regs[6];
        t511r = static_cast<std::uint32_t>(t511a + t511b) & 0xffffffffu;
        batch_set_add_flags(state, t511a, t511b, t511r, 32u);
        state.regs[1] = t511r;
    // 0x0083c3a3: 8d2c30 LEA
        t512 = static_cast<std::uint32_t>(state.regs[0] + state.regs[6] * 1u + 0x00000000u);
        state.regs[5] = t512;
    // 0x0083c3a6: 3be9 CMP
        t513a = state.regs[5];
        t513b = state.regs[1];
        t513r = static_cast<std::uint32_t>(t513a - t513b) & 0xffffffffu;
        batch_set_sub_flags(state, t513a, t513b, t513r, 32u);
    // 0x0083c3a8: 7413 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c3bd;
    // 0x0083c3aa: 2bf9 SUB
        t515a = state.regs[7];
        t515b = state.regs[1];
        t515r = static_cast<std::uint32_t>(t515a - t515b) & 0xffffffffu;
        batch_set_sub_flags(state, t515a, t515b, t515r, 32u);
        state.regs[7] = t515r;
    // 0x0083c3ac: 8d5701 LEA
        t516 = static_cast<std::uint32_t>(state.regs[7] + 0x00000001u);
        state.regs[2] = t516;
    // 0x0083c3af: 52 PUSH
        t517a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t517a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c3b0: 51 PUSH
        t518a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t518a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c3b1: 55 PUSH
        t519a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t519a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c3b2: ff1580c43c01 CALL
        t520_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memmove", 0x013cc480u, 0x0083c3b8u);
        if (t520_call_status != BatchLiftStatus::returned) return t520_call_status;
        if (state.eip != 0x0083c3b8u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c3b8: 83c40c ADD
        t521a = state.regs[4];
        t521b = 0x0000000cu;
        t521r = static_cast<std::uint32_t>(t521a + t521b) & 0xffffffffu;
        batch_set_add_flags(state, t521a, t521b, t521r, 32u);
        state.regs[4] = t521r;
    // 0x0083c3bb: 03fd ADD
        t522a = state.regs[7];
        t522b = state.regs[5];
        t522r = static_cast<std::uint32_t>(t522a + t522b) & 0xffffffffu;
        batch_set_add_flags(state, t522a, t522b, t522r, 32u);
        state.regs[7] = t522r;
    // 0x0083c3bd: 3bf7 CMP
    L_0083c3bd:
        t523a = state.regs[6];
        t523b = state.regs[7];
        t523r = static_cast<std::uint32_t>(t523a - t523b) & 0xffffffffu;
        batch_set_sub_flags(state, t523a, t523b, t523r, 32u);
    // 0x0083c3bf: 75b1 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c372;
    // 0x0083c3c1: 897c2434 MOV
    L_0083c3c1:
        t525 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t525)) return BatchLiftStatus::invalid_memory;
    // 0x0083c3c5: 8b442414 MOV
    L_0083c3c5:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t526)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t526;
    // 0x0083c3c9: 83c004 ADD
        t527a = state.regs[0];
        t527b = 0x00000004u;
        t527r = static_cast<std::uint32_t>(t527a + t527b) & 0xffffffffu;
        batch_set_add_flags(state, t527a, t527b, t527r, 32u);
        state.regs[0] = t527r;
    // 0x0083c3cc: 807fff5e CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0xffffffffu), t528a)) return BatchLiftStatus::invalid_memory;
        t528b = 0x0000005eu;
        t528r = static_cast<std::uint32_t>(t528a - t528b) & 0x000000ffu;
        batch_set_sub_flags(state, t528a, t528b, t528r, 8u);
    // 0x0083c3d0: 89442414 MOV
        t529 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t529)) return BatchLiftStatus::invalid_memory;
    // 0x0083c3d4: 8b40fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t530)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t530;
    // 0x0083c3d7: 89442458 MOV
        t531 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000058u), t531)) return BatchLiftStatus::invalid_memory;
    // 0x0083c3db: 755b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c438;
    // 0x0083c3dd: 8bcf MOV
        t533 = state.regs[7];
        state.regs[1] = t533;
    // 0x0083c3df: 2bce SUB
        t534a = state.regs[1];
        t534b = state.regs[6];
        t534r = static_cast<std::uint32_t>(t534a - t534b) & 0xffffffffu;
        batch_set_sub_flags(state, t534a, t534b, t534r, 32u);
        state.regs[1] = t534r;
    // 0x0083c3e1: 49 DEC
        t535a = state.regs[1];
        t535r = static_cast<std::uint32_t>(t535a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t535a, t535r, 32u);
        state.regs[1] = t535r;
    // 0x0083c3e2: 8bc7 MOV
        t536 = state.regs[7];
        state.regs[0] = t536;
    // 0x0083c3e4: 2bc1 SUB
        t537a = state.regs[0];
        t537b = state.regs[1];
        t537r = static_cast<std::uint32_t>(t537a - t537b) & 0xffffffffu;
        batch_set_sub_flags(state, t537a, t537b, t537r, 32u);
        state.regs[0] = t537r;
    // 0x0083c3e6: 2bc6 SUB
        t538a = state.regs[0];
        t538b = state.regs[6];
        t538r = static_cast<std::uint32_t>(t538a - t538b) & 0xffffffffu;
        batch_set_sub_flags(state, t538a, t538b, t538r, 32u);
        state.regs[0] = t538r;
    // 0x0083c3e8: 89442440 MOV
        t539 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t539)) return BatchLiftStatus::invalid_memory;
    // 0x0083c3ec: 83f801 CMP
        t540a = state.regs[0];
        t540b = 0x00000001u;
        t540r = static_cast<std::uint32_t>(t540a - t540b) & 0xffffffffu;
        batch_set_sub_flags(state, t540a, t540b, t540r, 32u);
    // 0x0083c3ef: c744241c01000000 MOV
        t541 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t541)) return BatchLiftStatus::invalid_memory;
    // 0x0083c3f7: 8d442440 LEA
        t542 = static_cast<std::uint32_t>(state.regs[4] + 0x00000040u);
        state.regs[0] = t542;
    // 0x0083c3fb: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0083c401;
    // 0x0083c3fd: 8d44241c LEA
        t544 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[0] = t544;
    // 0x0083c401: 8b00 MOV
    L_0083c401:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t545)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t545;
    // 0x0083c403: 03c1 ADD
        t546a = state.regs[0];
        t546b = state.regs[1];
        t546r = static_cast<std::uint32_t>(t546a + t546b) & 0xffffffffu;
        batch_set_add_flags(state, t546a, t546b, t546r, 32u);
        state.regs[0] = t546r;
    // 0x0083c405: 03c6 ADD
        t547a = state.regs[0];
        t547b = state.regs[6];
        t547r = static_cast<std::uint32_t>(t547a + t547b) & 0xffffffffu;
        batch_set_add_flags(state, t547a, t547b, t547r, 32u);
        state.regs[0] = t547r;
    // 0x0083c407: 8d2c31 LEA
        t548 = static_cast<std::uint32_t>(state.regs[1] + state.regs[6] * 1u + 0x00000000u);
        state.regs[5] = t548;
    // 0x0083c40a: 3be8 CMP
        t549a = state.regs[5];
        t549b = state.regs[0];
        t549r = static_cast<std::uint32_t>(t549a - t549b) & 0xffffffffu;
        batch_set_sub_flags(state, t549a, t549b, t549r, 32u);
    // 0x0083c40c: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c425;
    // 0x0083c40e: 2bf8 SUB
        t551a = state.regs[7];
        t551b = state.regs[0];
        t551r = static_cast<std::uint32_t>(t551a - t551b) & 0xffffffffu;
        batch_set_sub_flags(state, t551a, t551b, t551r, 32u);
        state.regs[7] = t551r;
    // 0x0083c410: 8d4f01 LEA
        t552 = static_cast<std::uint32_t>(state.regs[7] + 0x00000001u);
        state.regs[1] = t552;
    // 0x0083c413: 51 PUSH
        t553a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t553a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c414: 50 PUSH
        t554a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t554a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c415: 55 PUSH
        t555a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t555a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c416: ff1580c43c01 CALL
        t556_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memmove", 0x013cc480u, 0x0083c41cu);
        if (t556_call_status != BatchLiftStatus::returned) return t556_call_status;
        if (state.eip != 0x0083c41cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c41c: 83c40c ADD
        t557a = state.regs[4];
        t557b = 0x0000000cu;
        t557r = static_cast<std::uint32_t>(t557a + t557b) & 0xffffffffu;
        batch_set_add_flags(state, t557a, t557b, t557r, 32u);
        state.regs[4] = t557r;
    // 0x0083c41f: 03fd ADD
        t558a = state.regs[7];
        t558b = state.regs[5];
        t558r = static_cast<std::uint32_t>(t558a + t558b) & 0xffffffffu;
        batch_set_add_flags(state, t558a, t558b, t558r, 32u);
        state.regs[7] = t558r;
    // 0x0083c421: 897c2434 MOV
        t559 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t559)) return BatchLiftStatus::invalid_memory;
    // 0x0083c425: 8b442414 MOV
    L_0083c425:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t560)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t560;
    // 0x0083c429: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t561)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t561;
    // 0x0083c42b: 83c004 ADD
        t562a = state.regs[0];
        t562b = 0x00000004u;
        t562r = static_cast<std::uint32_t>(t562a + t562b) & 0xffffffffu;
        batch_set_add_flags(state, t562a, t562b, t562r, 32u);
        state.regs[0] = t562r;
    // 0x0083c42e: 89442414 MOV
        t563 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t563)) return BatchLiftStatus::invalid_memory;
    // 0x0083c432: 89542460 MOV
        t564 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000060u), t564)) return BatchLiftStatus::invalid_memory;
    // 0x0083c436: eb08 JMP
        goto L_0083c440;
    // 0x0083c438: c7442460ffffffff MOV
    L_0083c438:
        t566 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000060u), t566)) return BatchLiftStatus::invalid_memory;
    // 0x0083c440: 8d442448 LEA
    L_0083c440:
        t567 = static_cast<std::uint32_t>(state.regs[4] + 0x00000048u);
        state.regs[0] = t567;
    // 0x0083c444: 50 PUSH
        t568a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t568a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c445: 8d4c2448 LEA
        t569 = static_cast<std::uint32_t>(state.regs[4] + 0x00000048u);
        state.regs[1] = t569;
    // 0x0083c449: 51 PUSH
        t570a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t570a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c44a: 8b8c2408010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000108u), t571)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t571;
    // 0x0083c451: 8d542438 LEA
        t572 = static_cast<std::uint32_t>(state.regs[4] + 0x00000038u);
        state.regs[2] = t572;
    // 0x0083c455: 52 PUSH
        t573a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t573a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c456: e8e5d0ffff CALL
        t574_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00839540u, 0x0083c45bu);
        if (t574_call_status != BatchLiftStatus::returned) return t574_call_status;
        if (state.eip != 0x0083c45bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c45b: 837c244400 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t575a)) return BatchLiftStatus::invalid_memory;
        t575b = 0x00000000u;
        t575r = static_cast<std::uint32_t>(t575a - t575b) & 0xffffffffu;
        batch_set_sub_flags(state, t575a, t575b, t575r, 32u);
    // 0x0083c460: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c46a;
    // 0x0083c462: c744246403000000 MOV
        t577 = 0x00000003u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000064u), t577)) return BatchLiftStatus::invalid_memory;
    // 0x0083c46a: 8b442410 MOV
    L_0083c46a:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t578)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t578;
    // 0x0083c46e: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t579)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t579;
    // 0x0083c471: 3b4808 CMP
        t580a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t580b)) return BatchLiftStatus::invalid_memory;
        t580r = static_cast<std::uint32_t>(t580a - t580b) & 0xffffffffu;
        batch_set_sub_flags(state, t580a, t580b, t580r, 32u);
    // 0x0083c474: 732e JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0083c4a4;
    // 0x0083c476: 8d5120 LEA
        t582 = static_cast<std::uint32_t>(state.regs[1] + 0x00000020u);
        state.regs[2] = t582;
    // 0x0083c479: 894c2440 MOV
        t583 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t583)) return BatchLiftStatus::invalid_memory;
    // 0x0083c47d: 895004 MOV
        t584 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t584)) return BatchLiftStatus::invalid_memory;
    // 0x0083c480: 894c241c MOV
        t585 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t585)) return BatchLiftStatus::invalid_memory;
    // 0x0083c484: c68424f800000009 MOV
        t586 = 0x00000009u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t586)) return BatchLiftStatus::invalid_memory;
    // 0x0083c48c: 85c9 TEST
        t587a = state.regs[1];
        t587b = state.regs[1];
        t587r = (t587a & t587b) & 0xffffffffu;
        batch_set_logic_flags(state, t587r, 32u);
    // 0x0083c48e: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c49a;
    // 0x0083c490: 8d442444 LEA
        t589 = static_cast<std::uint32_t>(state.regs[4] + 0x00000044u);
        state.regs[0] = t589;
    // 0x0083c494: 50 PUSH
        t590a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t590a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c495: e816c6ffff CALL
        t591_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00838ab0u, 0x0083c49au);
        if (t591_call_status != BatchLiftStatus::returned) return t591_call_status;
        if (state.eip != 0x0083c49au) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c49a: c68424f800000008 MOV
    L_0083c49a:
        t592 = 0x00000008u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t592)) return BatchLiftStatus::invalid_memory;
    // 0x0083c4a2: eb0d JMP
        goto L_0083c4b1;
    // 0x0083c4a4: 8d542444 LEA
    L_0083c4a4:
        t594 = static_cast<std::uint32_t>(state.regs[4] + 0x00000044u);
        state.regs[2] = t594;
    // 0x0083c4a8: 52 PUSH
        t595a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t595a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c4a9: 51 PUSH
        t596a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t596a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c4aa: 8bc8 MOV
        t597 = state.regs[0];
        state.regs[1] = t597;
    // 0x0083c4ac: e80fdfffff CALL
        t598_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0083a3c0u, 0x0083c4b1u);
        if (t598_call_status != BatchLiftStatus::returned) return t598_call_status;
        if (state.eip != 0x0083c4b1u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c4b1: 6884b54101 PUSH
    L_0083c4b1:
        t599a = 0x0141b584u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t599a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c4b6: 8d442424 LEA
        t600 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[0] = t600;
    // 0x0083c4ba: 50 PUSH
        t601a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t601a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c4bb: 8d8c24d8000000 LEA
        t602 = static_cast<std::uint32_t>(state.regs[4] + 0x000000d8u);
        state.regs[1] = t602;
    // 0x0083c4c2: 51 PUSH
        t603a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t603a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c4c3: 8beb MOV
        t604 = state.regs[3];
        state.regs[5] = t604;
    // 0x0083c4c5: e8c6cbffff CALL
        t605_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00839090u, 0x0083c4cau);
        if (t605_call_status != BatchLiftStatus::returned) return t605_call_status;
        if (state.eip != 0x0083c4cau) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c4ca: 83c40c ADD
        t606a = state.regs[4];
        t606b = 0x0000000cu;
        t606r = static_cast<std::uint32_t>(t606a + t606b) & 0xffffffffu;
        batch_set_add_flags(state, t606a, t606b, t606r, 32u);
        state.regs[4] = t606r;
    // 0x0083c4cd: 8d542430 LEA
        t607 = static_cast<std::uint32_t>(state.regs[4] + 0x00000030u);
        state.regs[2] = t607;
    // 0x0083c4d1: c68424f80000000a MOV
        t608 = 0x0000000au;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t608)) return BatchLiftStatus::invalid_memory;
    // 0x0083c4d9: 3bc2 CMP
        t609a = state.regs[0];
        t609b = state.regs[2];
        t609r = static_cast<std::uint32_t>(t609a - t609b) & 0xffffffffu;
        batch_set_sub_flags(state, t609a, t609b, t609r, 32u);
    // 0x0083c4db: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c4f5;
    // 0x0083c4dd: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t611)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t611;
    // 0x0083c4e0: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t612)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t612;
    // 0x0083c4e2: 51 PUSH
        t613a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t613a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c4e3: 52 PUSH
        t614a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t614a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c4e4: 8d4c2438 LEA
        t615 = static_cast<std::uint32_t>(state.regs[4] + 0x00000038u);
        state.regs[1] = t615;
    // 0x0083c4e8: e8c387c1ff CALL
        t616_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00454cb0u, 0x0083c4edu);
        if (t616_call_status != BatchLiftStatus::returned) return t616_call_status;
        if (state.eip != 0x0083c4edu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c4ed: 8b7c2434 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t617)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t617;
    // 0x0083c4f1: 8b742430 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t618)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t618;
    // 0x0083c4f5: 8b8c24d8000000 MOV
    L_0083c4f5:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x000000d8u), t619)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t619;
    // 0x0083c4fc: 8b8424d0000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x000000d0u), t620)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t620;
    // 0x0083c503: 2bc8 SUB
        t621a = state.regs[1];
        t621b = state.regs[0];
        t621r = static_cast<std::uint32_t>(t621a - t621b) & 0xffffffffu;
        batch_set_sub_flags(state, t621a, t621b, t621r, 32u);
        state.regs[1] = t621r;
    // 0x0083c505: 83f901 CMP
        t622a = state.regs[1];
        t622b = 0x00000001u;
        t622r = static_cast<std::uint32_t>(t622a - t622b) & 0xffffffffu;
        batch_set_sub_flags(state, t622a, t622b, t622r, 32u);
    // 0x0083c508: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c517;
    // 0x0083c50a: 85c0 TEST
        t624a = state.regs[0];
        t624b = state.regs[0];
        t624r = (t624a & t624b) & 0xffffffffu;
        batch_set_logic_flags(state, t624r, 32u);
    // 0x0083c50c: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c517;
    // 0x0083c50e: 50 PUSH
        t626a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t626a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c50f: e86cae7000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c514u)) return BatchLiftStatus::invalid_memory;
        t627_call_status = spore_lift_00f47380(memory, state);
        if (t627_call_status != BatchLiftStatus::returned) return t627_call_status;
        if (state.eip != 0x0083c514u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c514: 83c404 ADD
        t628a = state.regs[4];
        t628b = 0x00000004u;
        t628r = static_cast<std::uint32_t>(t628a + t628b) & 0xffffffffu;
        batch_set_add_flags(state, t628a, t628b, t628r, 32u);
        state.regs[4] = t628r;
    // 0x0083c517: 8b542450 MOV
    L_0083c517:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t629)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t629;
    // 0x0083c51b: 8b442448 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t630)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t630;
    // 0x0083c51f: 2bd0 SUB
        t631a = state.regs[2];
        t631b = state.regs[0];
        t631r = static_cast<std::uint32_t>(t631a - t631b) & 0xffffffffu;
        batch_set_sub_flags(state, t631a, t631b, t631r, 32u);
        state.regs[2] = t631r;
    // 0x0083c521: 83fa01 CMP
        t632a = state.regs[2];
        t632b = 0x00000001u;
        t632r = static_cast<std::uint32_t>(t632a - t632b) & 0xffffffffu;
        batch_set_sub_flags(state, t632a, t632b, t632r, 32u);
    // 0x0083c524: c68424f800000005 MOV
    L_0083c524:
        t633 = 0x00000005u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t633)) return BatchLiftStatus::invalid_memory;
    // 0x0083c52c: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c53b;
    // 0x0083c52e: 85c0 TEST
        t635a = state.regs[0];
        t635b = state.regs[0];
        t635r = (t635a & t635b) & 0xffffffffu;
        batch_set_logic_flags(state, t635r, 32u);
    // 0x0083c530: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c53b;
    // 0x0083c532: 50 PUSH
        t637a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t637a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c533: e848ae7000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c538u)) return BatchLiftStatus::invalid_memory;
        t638_call_status = spore_lift_00f47380(memory, state);
        if (t638_call_status != BatchLiftStatus::returned) return t638_call_status;
        if (state.eip != 0x0083c538u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c538: 83c404 ADD
        t639a = state.regs[4];
        t639b = 0x00000004u;
        t639r = static_cast<std::uint32_t>(t639a + t639b) & 0xffffffffu;
        batch_set_add_flags(state, t639a, t639b, t639r, 32u);
        state.regs[4] = t639r;
    // 0x0083c53b: 3bf7 CMP
    L_0083c53b:
        t640a = state.regs[6];
        t640b = state.regs[7];
        t640r = static_cast<std::uint32_t>(t640a - t640b) & 0xffffffffu;
        batch_set_sub_flags(state, t640a, t640b, t640r, 32u);
    // 0x0083c53d: 0f857dfcffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c1c0;
    // 0x0083c543: 85db TEST
        t642a = state.regs[3];
        t642b = state.regs[3];
        t642r = (t642a & t642b) & 0xffffffffu;
        batch_set_logic_flags(state, t642r, 32u);
    // 0x0083c545: 0f85a3010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c6ee;
    // 0x0083c54b: 8b442414 MOV
    L_0083c54b:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t644)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t644;
    // 0x0083c54f: 8b18 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t645)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t645;
    // 0x0083c551: 83c004 ADD
        t646a = state.regs[0];
        t646b = 0x00000004u;
        t646r = static_cast<std::uint32_t>(t646a + t646b) & 0xffffffffu;
        batch_set_add_flags(state, t646a, t646b, t646r, 32u);
        state.regs[0] = t646r;
    // 0x0083c554: 89442414 MOV
        t647 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t647)) return BatchLiftStatus::invalid_memory;
    // 0x0083c558: 8bc3 MOV
        t648 = state.regs[3];
        state.regs[0] = t648;
    // 0x0083c55a: 8d5001 LEA
        t649 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t649;
    // 0x0083c55d: 8d4900 LEA
        t650 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t650;
    // 0x0083c560: 8a08 MOV
    L_0083c560:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t651)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t651 << 0u) & 0x000000ffu);
    // 0x0083c562: 40 INC
        t652a = state.regs[0];
        t652r = static_cast<std::uint32_t>(t652a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t652a, t652r, 32u);
        state.regs[0] = t652r;
    // 0x0083c563: 84c9 TEST
        t653a = state.regs[1] & 0x000000ffu;
        t653b = state.regs[1] & 0x000000ffu;
        t653r = (t653a & t653b) & 0x000000ffu;
        batch_set_logic_flags(state, t653r, 8u);
    // 0x0083c565: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083c560;
    // 0x0083c567: 2bc2 SUB
        t655a = state.regs[0];
        t655b = state.regs[2];
        t655r = static_cast<std::uint32_t>(t655a - t655b) & 0xffffffffu;
        batch_set_sub_flags(state, t655a, t655b, t655r, 32u);
        state.regs[0] = t655r;
    // 0x0083c569: 8d2c03 LEA
        t656 = static_cast<std::uint32_t>(state.regs[3] + state.regs[0] * 1u + 0x00000000u);
        state.regs[5] = t656;
    // 0x0083c56c: 8bc5 MOV
        t657 = state.regs[5];
        state.regs[0] = t657;
    // 0x0083c56e: 2bc3 SUB
        t658a = state.regs[0];
        t658b = state.regs[3];
        t658r = static_cast<std::uint32_t>(t658a - t658b) & 0xffffffffu;
        batch_set_sub_flags(state, t658a, t658b, t658r, 32u);
        state.regs[0] = t658r;
    // 0x0083c570: 89442410 MOV
        t659 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t659)) return BatchLiftStatus::invalid_memory;
    // 0x0083c574: 40 INC
        t660a = state.regs[0];
        t660r = static_cast<std::uint32_t>(t660a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t660a, t660r, 32u);
        state.regs[0] = t660r;
    // 0x0083c575: 83f801 CMP
        t661a = state.regs[0];
        t661b = 0x00000001u;
        t661r = static_cast<std::uint32_t>(t661a - t661b) & 0xffffffffu;
        batch_set_sub_flags(state, t661a, t661b, t661r, 32u);
    // 0x0083c578: 7630 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0083c5aa;
    // 0x0083c57a: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t663)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t663;
    // 0x0083c57e: 68d1000000 PUSH
        t664a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t664a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c583: 6838bb3e01 PUSH
        t665a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t665a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c588: 6a00 PUSH
        t666a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t666a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c58a: 6a00 PUSH
        t667a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t667a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c58c: 40 INC
        t668a = state.regs[0];
        t668r = static_cast<std::uint32_t>(t668a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t668a, t668r, 32u);
        state.regs[0] = t668r;
    // 0x0083c58d: 688cb14101 PUSH
        t669a = 0x0141b18cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t669a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c592: 50 PUSH
        t670a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t670a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c593: e808ae7000 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x0083c598u)) return BatchLiftStatus::invalid_memory;
        t671_call_status = spore_lift_00f473a0(memory, state);
        if (t671_call_status != BatchLiftStatus::returned) return t671_call_status;
        if (state.eip != 0x0083c598u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c598: 8bf8 MOV
        t672 = state.regs[0];
        state.regs[7] = t672;
    // 0x0083c59a: 8b442428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t673)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t673;
    // 0x0083c59e: 40 INC
        t674a = state.regs[0];
        t674r = static_cast<std::uint32_t>(t674a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t674a, t674r, 32u);
        state.regs[0] = t674r;
    // 0x0083c59f: 83c418 ADD
        t675a = state.regs[4];
        t675b = 0x00000018u;
        t675r = static_cast<std::uint32_t>(t675a + t675b) & 0xffffffffu;
        batch_set_add_flags(state, t675a, t675b, t675r, 32u);
        state.regs[4] = t675r;
    // 0x0083c5a2: 03c7 ADD
        t676a = state.regs[0];
        t676b = state.regs[7];
        t676r = static_cast<std::uint32_t>(t676a + t676b) & 0xffffffffu;
        batch_set_add_flags(state, t676a, t676b, t676r, 32u);
        state.regs[0] = t676r;
    // 0x0083c5a4: 89442470 MOV
        t677 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000070u), t677)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5a8: eb0d JMP
        goto L_0083c5b7;
    // 0x0083c5aa: bfac7b6601 MOV
    L_0083c5aa:
        t679 = 0x01667bacu;
        state.regs[7] = t679;
    // 0x0083c5af: c7442470ad7b6601 MOV
        t680 = 0x01667badu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000070u), t680)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5b7: 8b442410 MOV
    L_0083c5b7:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t681)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t681;
    // 0x0083c5bb: 50 PUSH
        t682a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t682a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5bc: 53 PUSH
        t683a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t683a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5bd: 57 PUSH
        t684a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t684a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5be: 897c2474 MOV
        t685 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000074u), t685)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5c2: e87d419a00 CALL
        t686_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x0083c5c7u);
        if (t686_call_status != BatchLiftStatus::returned) return t686_call_status;
        if (state.eip != 0x0083c5c7u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c5c7: 2beb SUB
        t687a = state.regs[5];
        t687b = state.regs[3];
        t687r = static_cast<std::uint32_t>(t687a - t687b) & 0xffffffffu;
        batch_set_sub_flags(state, t687a, t687b, t687r, 32u);
        state.regs[5] = t687r;
    // 0x0083c5c9: 03ef ADD
        t688a = state.regs[5];
        t688b = state.regs[7];
        t688r = static_cast<std::uint32_t>(t688a + t688b) & 0xffffffffu;
        batch_set_add_flags(state, t688a, t688b, t688r, 32u);
        state.regs[5] = t688r;
    // 0x0083c5cb: 83c40c ADD
        t689a = state.regs[4];
        t689b = 0x0000000cu;
        t689r = static_cast<std::uint32_t>(t689a + t689b) & 0xffffffffu;
        batch_set_add_flags(state, t689a, t689b, t689r, 32u);
        state.regs[4] = t689r;
    // 0x0083c5ce: 896c246c MOV
        t690 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000006cu), t690)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5d2: c6450000 MOV
        t691 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t691)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5d6: 807c241b00 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001bu), t692a)) return BatchLiftStatus::invalid_memory;
        t692b = 0x00000000u;
        t692r = static_cast<std::uint32_t>(t692a - t692b) & 0x000000ffu;
        batch_set_sub_flags(state, t692a, t692b, t692r, 8u);
    // 0x0083c5db: 55 PUSH
        t693a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t693a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5dc: c68424fc0000000b MOV
        t694 = 0x0000000bu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x000000fcu), t694)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5e4: 57 PUSH
        t695a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t695a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5e5: 7422 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c609;
    // 0x0083c5e7: 8d8c2490000000 LEA
        t697 = static_cast<std::uint32_t>(state.regs[4] + 0x00000090u);
        state.regs[1] = t697;
    // 0x0083c5ee: e8bd86c1ff CALL
        t698_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00454cb0u, 0x0083c5f3u);
        if (t698_call_status != BatchLiftStatus::returned) return t698_call_status;
        if (state.eip != 0x0083c5f3u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c5f3: 8d4c2478 LEA
        t699 = static_cast<std::uint32_t>(state.regs[4] + 0x00000078u);
        state.regs[1] = t699;
    // 0x0083c5f7: 51 PUSH
        t700a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t700a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c5f8: 8b8c2404010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000104u), t701)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t701;
    // 0x0083c5ff: 83c144 ADD
        t702a = state.regs[1];
        t702b = 0x00000044u;
        t702r = static_cast<std::uint32_t>(t702a + t702b) & 0xffffffffu;
        batch_set_add_flags(state, t702a, t702b, t702r, 32u);
        state.regs[1] = t702r;
    // 0x0083c602: e849f6ffff CALL
        t703_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x0083bc50u, 0x0083c607u);
        if (t703_call_status != BatchLiftStatus::returned) return t703_call_status;
        if (state.eip != 0x0083c607u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c607: eb0f JMP
        goto L_0083c618;
    // 0x0083c609: 8b8c2408010000 MOV
    L_0083c609:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000108u), t705)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t705;
    // 0x0083c610: 83c120 ADD
        t706a = state.regs[1];
        t706b = 0x00000020u;
        t706r = static_cast<std::uint32_t>(t706a + t706b) & 0xffffffffu;
        batch_set_add_flags(state, t706a, t706b, t706r, 32u);
        state.regs[1] = t706r;
    // 0x0083c613: e84897c1ff CALL
        t707_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00455d60u, 0x0083c618u);
        if (t707_call_status != BatchLiftStatus::returned) return t707_call_status;
        if (state.eip != 0x0083c618u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c618: 8b442470 MOV
    L_0083c618:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000070u), t708)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t708;
    // 0x0083c61c: 2bc7 SUB
        t709a = state.regs[0];
        t709b = state.regs[7];
        t709r = static_cast<std::uint32_t>(t709a - t709b) & 0xffffffffu;
        batch_set_sub_flags(state, t709a, t709b, t709r, 32u);
        state.regs[0] = t709r;
    // 0x0083c61e: 83f801 CMP
        t710a = state.regs[0];
        t710b = 0x00000001u;
        t710r = static_cast<std::uint32_t>(t710a - t710b) & 0xffffffffu;
        batch_set_sub_flags(state, t710a, t710b, t710r, 32u);
    // 0x0083c621: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c630;
    // 0x0083c623: 85ff TEST
        t712a = state.regs[7];
        t712b = state.regs[7];
        t712r = (t712a & t712b) & 0xffffffffu;
        batch_set_logic_flags(state, t712r, 32u);
    // 0x0083c625: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c630;
    // 0x0083c627: 57 PUSH
        t714a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t714a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c628: e853ad7000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c62du)) return BatchLiftStatus::invalid_memory;
        t715_call_status = spore_lift_00f47380(memory, state);
        if (t715_call_status != BatchLiftStatus::returned) return t715_call_status;
        if (state.eip != 0x0083c62du) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c62d: 83c404 ADD
        t716a = state.regs[4];
        t716b = 0x00000004u;
        t716r = static_cast<std::uint32_t>(t716a + t716b) & 0xffffffffu;
        batch_set_add_flags(state, t716a, t716b, t716r, 32u);
        state.regs[4] = t716r;
    // 0x0083c630: 8d4c2478 LEA
    L_0083c630:
        t717 = static_cast<std::uint32_t>(state.regs[4] + 0x00000078u);
        state.regs[1] = t717;
    // 0x0083c634: e847cebeff CALL
        t718_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00429480u, 0x0083c639u);
        if (t718_call_status != BatchLiftStatus::returned) return t718_call_status;
        if (state.eip != 0x0083c639u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c639: 8b442438 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t719)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t719;
    // 0x0083c63d: 2bc6 SUB
        t720a = state.regs[0];
        t720b = state.regs[6];
        t720r = static_cast<std::uint32_t>(t720a - t720b) & 0xffffffffu;
        batch_set_sub_flags(state, t720a, t720b, t720r, 32u);
        state.regs[0] = t720r;
    // 0x0083c63f: 83f801 CMP
        t721a = state.regs[0];
        t721b = 0x00000001u;
        t721r = static_cast<std::uint32_t>(t721a - t721b) & 0xffffffffu;
        batch_set_sub_flags(state, t721a, t721b, t721r, 32u);
    // 0x0083c642: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c651;
    // 0x0083c644: 85f6 TEST
        t723a = state.regs[6];
        t723b = state.regs[6];
        t723r = (t723a & t723b) & 0xffffffffu;
        batch_set_logic_flags(state, t723r, 32u);
    // 0x0083c646: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c651;
    // 0x0083c648: 56 PUSH
        t725a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t725a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c649: e832ad7000 CALL
    L_0083c649:
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c64eu)) return BatchLiftStatus::invalid_memory;
        t726_call_status = spore_lift_00f47380(memory, state);
        if (t726_call_status != BatchLiftStatus::returned) return t726_call_status;
        if (state.eip != 0x0083c64eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c64e: 83c404 ADD
        t727a = state.regs[4];
        t727b = 0x00000004u;
        t727r = static_cast<std::uint32_t>(t727a + t727b) & 0xffffffffu;
        batch_set_add_flags(state, t727a, t727b, t727r, 32u);
        state.regs[4] = t727r;
    // 0x0083c651: 8b442420 MOV
    L_0083c651:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t728)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t728;
    // 0x0083c655: 8b542428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t729)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t729;
    // 0x0083c659: 2bd0 SUB
        t730a = state.regs[2];
        t730b = state.regs[0];
        t730r = static_cast<std::uint32_t>(t730a - t730b) & 0xffffffffu;
        batch_set_sub_flags(state, t730a, t730b, t730r, 32u);
        state.regs[2] = t730r;
    // 0x0083c65b: 83fa01 CMP
        t731a = state.regs[2];
        t731b = 0x00000001u;
        t731r = static_cast<std::uint32_t>(t731a - t731b) & 0xffffffffu;
        batch_set_sub_flags(state, t731a, t731b, t731r, 32u);
    // 0x0083c65e: c78424f8000000ffffffff MOV
    L_0083c65e:
        t732 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x000000f8u), t732)) return BatchLiftStatus::invalid_memory;
    // 0x0083c669: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c678;
    // 0x0083c66b: 85c0 TEST
        t734a = state.regs[0];
        t734b = state.regs[0];
        t734r = (t734a & t734b) & 0xffffffffu;
        batch_set_logic_flags(state, t734r, 32u);
    // 0x0083c66d: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c678;
    // 0x0083c66f: 50 PUSH
        t736a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t736a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c670: e80bad7000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c675u)) return BatchLiftStatus::invalid_memory;
        t737_call_status = spore_lift_00f47380(memory, state);
        if (t737_call_status != BatchLiftStatus::returned) return t737_call_status;
        if (state.eip != 0x0083c675u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c675: 83c404 ADD
        t738a = state.regs[4];
        t738b = 0x00000004u;
        t738r = static_cast<std::uint32_t>(t738a + t738b) & 0xffffffffu;
        batch_set_add_flags(state, t738a, t738b, t738r, 32u);
        state.regs[4] = t738r;
    // 0x0083c678: 8b442414 MOV
    L_0083c678:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t739)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t739;
    // 0x0083c67c: 8b38 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t740)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t740;
    // 0x0083c67e: 83c004 ADD
        t741a = state.regs[0];
        t741b = 0x00000004u;
        t741r = static_cast<std::uint32_t>(t741a + t741b) & 0xffffffffu;
        batch_set_add_flags(state, t741a, t741b, t741r, 32u);
        state.regs[0] = t741r;
    // 0x0083c681: 89442414 MOV
        t742 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t742)) return BatchLiftStatus::invalid_memory;
    // 0x0083c685: 85ff TEST
        t743a = state.regs[7];
        t743b = state.regs[7];
        t743r = (t743a & t743b) & 0xffffffffu;
        batch_set_logic_flags(state, t743r, 32u);
    // 0x0083c687: 0f8549f7ffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0083bdd6;
    // 0x0083c68d: 8b6c2464 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000064u), t745)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t745;
    // 0x0083c691: e999000000 JMP
        goto L_0083c72f;
    // 0x0083c696: 8d4c2478 LEA
    L_0083c696:
        t747 = static_cast<std::uint32_t>(state.regs[4] + 0x00000078u);
        state.regs[1] = t747;
    // 0x0083c69a: e8e1cdbeff CALL
        t748_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00429480u, 0x0083c69fu);
        if (t748_call_status != BatchLiftStatus::returned) return t748_call_status;
        if (state.eip != 0x0083c69fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c69f: 8b442438 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t749)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t749;
    // 0x0083c6a3: 2bc6 SUB
        t750a = state.regs[0];
        t750b = state.regs[6];
        t750r = static_cast<std::uint32_t>(t750a - t750b) & 0xffffffffu;
        batch_set_sub_flags(state, t750a, t750b, t750r, 32u);
        state.regs[0] = t750r;
    // 0x0083c6a5: 83f801 CMP
        t751a = state.regs[0];
        t751b = 0x00000001u;
        t751r = static_cast<std::uint32_t>(t751a - t751b) & 0xffffffffu;
        batch_set_sub_flags(state, t751a, t751b, t751r, 32u);
    // 0x0083c6a8: 7e0d JLE
    L_0083c6a8:
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c6b7;
    // 0x0083c6aa: 85f6 TEST
        t753a = state.regs[6];
        t753b = state.regs[6];
        t753r = (t753a & t753b) & 0xffffffffu;
        batch_set_logic_flags(state, t753r, 32u);
    // 0x0083c6ac: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c6b7;
    // 0x0083c6ae: 56 PUSH
        t755a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t755a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c6af: e8ccac7000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c6b4u)) return BatchLiftStatus::invalid_memory;
        t756_call_status = spore_lift_00f47380(memory, state);
        if (t756_call_status != BatchLiftStatus::returned) return t756_call_status;
        if (state.eip != 0x0083c6b4u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c6b4: 83c404 ADD
        t757a = state.regs[4];
        t757b = 0x00000004u;
        t757r = static_cast<std::uint32_t>(t757a + t757b) & 0xffffffffu;
        batch_set_add_flags(state, t757a, t757b, t757r, 32u);
        state.regs[4] = t757r;
    // 0x0083c6b7: 8b4c2428 MOV
    L_0083c6b7:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t758)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t758;
    // 0x0083c6bb: 8b442420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t759)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t759;
    // 0x0083c6bf: 2bc8 SUB
        t760a = state.regs[1];
        t760b = state.regs[0];
        t760r = static_cast<std::uint32_t>(t760a - t760b) & 0xffffffffu;
        batch_set_sub_flags(state, t760a, t760b, t760r, 32u);
        state.regs[1] = t760r;
    // 0x0083c6c1: 83f901 CMP
        t761a = state.regs[1];
        t761b = 0x00000001u;
        t761r = static_cast<std::uint32_t>(t761a - t761b) & 0xffffffffu;
        batch_set_sub_flags(state, t761a, t761b, t761r, 32u);
    // 0x0083c6c4: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c6d3;
    // 0x0083c6c6: 85c0 TEST
        t763a = state.regs[0];
        t763b = state.regs[0];
        t763r = (t763a & t763b) & 0xffffffffu;
        batch_set_logic_flags(state, t763r, 32u);
    // 0x0083c6c8: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c6d3;
    // 0x0083c6ca: 50 PUSH
        t765a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t765a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c6cb: e8b0ac7000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c6d0u)) return BatchLiftStatus::invalid_memory;
        t766_call_status = spore_lift_00f47380(memory, state);
        if (t766_call_status != BatchLiftStatus::returned) return t766_call_status;
        if (state.eip != 0x0083c6d0u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c6d0: 83c404 ADD
        t767a = state.regs[4];
        t767b = 0x00000004u;
        t767r = static_cast<std::uint32_t>(t767a + t767b) & 0xffffffffu;
        batch_set_add_flags(state, t767a, t767b, t767r, 32u);
        state.regs[4] = t767r;
    // 0x0083c6d3: b802000000 MOV
    L_0083c6d3:
        t768 = 0x00000002u;
        state.regs[0] = t768;
    // 0x0083c6d8: eb57 JMP
        goto L_0083c731;
    // 0x0083c6da: 8d4c2478 LEA
    L_0083c6da:
        t770 = static_cast<std::uint32_t>(state.regs[4] + 0x00000078u);
        state.regs[1] = t770;
    // 0x0083c6de: e89dcdbeff CALL
        t771_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00429480u, 0x0083c6e3u);
        if (t771_call_status != BatchLiftStatus::returned) return t771_call_status;
        if (state.eip != 0x0083c6e3u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c6e3: 8b542438 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t772)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t772;
    // 0x0083c6e7: 2bd6 SUB
        t773a = state.regs[2];
        t773b = state.regs[6];
        t773r = static_cast<std::uint32_t>(t773a - t773b) & 0xffffffffu;
        batch_set_sub_flags(state, t773a, t773b, t773r, 32u);
        state.regs[2] = t773r;
    // 0x0083c6e9: 83fa01 CMP
        t774a = state.regs[2];
        t774b = 0x00000001u;
        t774r = static_cast<std::uint32_t>(t774a - t774b) & 0xffffffffu;
        batch_set_sub_flags(state, t774a, t774b, t774r, 32u);
    // 0x0083c6ec: ebba JMP
        goto L_0083c6a8;
    // 0x0083c6ee: 8d4c2478 LEA
    L_0083c6ee:
        t776 = static_cast<std::uint32_t>(state.regs[4] + 0x00000078u);
        state.regs[1] = t776;
    // 0x0083c6f2: bd01000000 MOV
        t777 = 0x00000001u;
        state.regs[5] = t777;
    // 0x0083c6f7: e884cdbeff CALL
        t778_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00429480u, 0x0083c6fcu);
        if (t778_call_status != BatchLiftStatus::returned) return t778_call_status;
        if (state.eip != 0x0083c6fcu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c6fc: 8b542438 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t779)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t779;
    // 0x0083c700: 2bd6 SUB
        t780a = state.regs[2];
        t780b = state.regs[6];
        t780r = static_cast<std::uint32_t>(t780a - t780b) & 0xffffffffu;
        batch_set_sub_flags(state, t780a, t780b, t780r, 32u);
        state.regs[2] = t780r;
    // 0x0083c702: 3bd5 CMP
        t781a = state.regs[2];
        t781b = state.regs[5];
        t781r = static_cast<std::uint32_t>(t781a - t781b) & 0xffffffffu;
        batch_set_sub_flags(state, t781a, t781b, t781r, 32u);
    // 0x0083c704: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c713;
    // 0x0083c706: 85f6 TEST
        t783a = state.regs[6];
        t783b = state.regs[6];
        t783r = (t783a & t783b) & 0xffffffffu;
        batch_set_logic_flags(state, t783r, 32u);
    // 0x0083c708: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c713;
    // 0x0083c70a: 56 PUSH
        t785a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t785a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c70b: e870ac7000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c710u)) return BatchLiftStatus::invalid_memory;
        t786_call_status = spore_lift_00f47380(memory, state);
        if (t786_call_status != BatchLiftStatus::returned) return t786_call_status;
        if (state.eip != 0x0083c710u) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c710: 83c404 ADD
        t787a = state.regs[4];
        t787b = 0x00000004u;
        t787r = static_cast<std::uint32_t>(t787a + t787b) & 0xffffffffu;
        batch_set_add_flags(state, t787a, t787b, t787r, 32u);
        state.regs[4] = t787r;
    // 0x0083c713: 8b4c2428 MOV
    L_0083c713:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t788)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t788;
    // 0x0083c717: 8b442420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t789)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t789;
    // 0x0083c71b: 2bc8 SUB
        t790a = state.regs[1];
        t790b = state.regs[0];
        t790r = static_cast<std::uint32_t>(t790a - t790b) & 0xffffffffu;
        batch_set_sub_flags(state, t790a, t790b, t790r, 32u);
        state.regs[1] = t790r;
    // 0x0083c71d: 83f901 CMP
        t791a = state.regs[1];
        t791b = 0x00000001u;
        t791r = static_cast<std::uint32_t>(t791a - t791b) & 0xffffffffu;
        batch_set_sub_flags(state, t791a, t791b, t791r, 32u);
    // 0x0083c720: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0083c72f;
    // 0x0083c722: 85c0 TEST
        t793a = state.regs[0];
        t793b = state.regs[0];
        t793r = (t793a & t793b) & 0xffffffffu;
        batch_set_logic_flags(state, t793r, 32u);
    // 0x0083c724: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0083c72f;
    // 0x0083c726: 50 PUSH
        t795a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t795a)) return BatchLiftStatus::invalid_memory;
    // 0x0083c727: e854ac7000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0083c72cu)) return BatchLiftStatus::invalid_memory;
        t796_call_status = spore_lift_00f47380(memory, state);
        if (t796_call_status != BatchLiftStatus::returned) return t796_call_status;
        if (state.eip != 0x0083c72cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0083c72c: 83c404 ADD
        t797a = state.regs[4];
        t797b = 0x00000004u;
        t797r = static_cast<std::uint32_t>(t797a + t797b) & 0xffffffffu;
        batch_set_add_flags(state, t797a, t797b, t797r, 32u);
        state.regs[4] = t797r;
    // 0x0083c72f: 8bc5 MOV
    L_0083c72f:
        t798 = state.regs[5];
        state.regs[0] = t798;
    // 0x0083c731: 8b8c24f0000000 MOV
    L_0083c731:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x000000f0u), t799)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t799;
    // 0x0083c738: 5f POP
        if (!memory.load32(state.regs[4], t800a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t800a;
    // 0x0083c739: 5e POP
        if (!memory.load32(state.regs[4], t801a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t801a;
    // 0x0083c73a: 5d POP
        if (!memory.load32(state.regs[4], t802a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t802a;
    // 0x0083c73b: 5b POP
        if (!memory.load32(state.regs[4], t803a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t803a;
    // 0x0083c73c: 64890d00000000 MOV
        t804 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t804)) return BatchLiftStatus::invalid_memory;
    // 0x0083c743: 81c4ec000000 ADD
        t805a = state.regs[4];
        t805b = 0x000000ecu;
        t805r = static_cast<std::uint32_t>(t805a + t805b) & 0xffffffffu;
        batch_set_add_flags(state, t805a, t805b, t805r, 32u);
        state.regs[4] = t805r;
    // 0x0083c749: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
