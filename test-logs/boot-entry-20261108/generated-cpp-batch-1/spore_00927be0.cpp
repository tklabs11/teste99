#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009267a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926960(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926f10(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009272c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927700(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927c24(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927c9b(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927d29(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927d35(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927d80(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927d84(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927df0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927e21(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927e53(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927e57(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927ee1(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00928070(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009280b1(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092828f(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00927be0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00927be0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33c = 0, t33r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t41a = 0, t41c = 0, t41r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67a = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69a = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71a = 0;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t74a = 0, t74c = 0, t74r = 0;
    std::uint32_t t75a = 0, t75b = 0, t75r = 0;
    std::uint32_t t77a = 0, t77b = 0, t77r = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81a = 0, t81c = 0, t81r = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88a = 0, t88c = 0, t88r = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95a = 0, t95c = 0, t95r = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t101a = 0, t101c = 0, t101r = 0;
    std::uint32_t t102a = 0, t102b = 0, t102r = 0;
    std::uint32_t t104a = 0, t104b = 0, t104r = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108a = 0, t108b = 0, t108r = 0;
    std::uint32_t t110 = 0;
    BatchLiftStatus t111_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t112a = 0, t112b = 0, t112r = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117a = 0, t117b = 0, t117r = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121 = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t123a = 0, t123b = 0, t123r = 0;
    std::uint32_t t124a = 0, t124b = 0, t124r = 0;
    std::uint32_t t126 = 0;
    std::uint32_t t128a = 0, t128b = 0, t128r = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131a = 0, t131b = 0, t131r = 0;
    std::uint32_t t134a = 0, t134b = 0, t134r = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137a = 0, t137b = 0, t137r = 0;
    std::uint32_t t139a = 0, t139b = 0, t139r = 0;
    std::uint32_t t141a = 0, t141b = 0, t141r = 0;
    std::uint32_t t143a = 0, t143b = 0, t143r = 0;
    std::uint32_t t144a = 0, t144b = 0, t144r = 0;
    std::uint32_t t146a = 0, t146b = 0, t146r = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150 = 0;
    std::uint32_t t151a = 0, t151b = 0, t151r = 0;
    std::uint32_t t153a = 0, t153b = 0, t153r = 0;
    std::uint32_t t155a = 0;
    std::uint32_t t156a = 0;
    std::uint32_t t157a = 0;
    std::uint32_t t158 = 0;
    BatchLiftStatus t159_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t160 = 0;
    std::uint32_t t161a = 0, t161b = 0, t161r = 0;
    std::uint32_t t163a = 0, t163b = 0, t163r = 0;
    std::uint32_t t165 = 0;
    std::uint32_t t166 = 0;
    std::uint32_t t167 = 0;
    std::uint32_t t168a = 0, t168b = 0, t168r = 0;
    std::uint32_t t171 = 0;
    std::uint32_t t172a = 0, t172b = 0, t172r = 0;
    std::uint32_t t173a = 0, t173b = 0, t173r = 0;
    std::uint32_t t175 = 0;
    std::uint32_t t176a = 0, t176b = 0, t176r = 0;
    std::uint32_t t178a = 0, t178b = 0, t178r = 0;
    std::uint32_t t180 = 0;
    std::uint32_t t181a = 0, t181b = 0, t181r = 0;
    std::uint32_t t184a = 0, t184b = 0, t184r = 0;
    std::uint32_t t186a = 0, t186b = 0, t186r = 0;
    std::uint32_t t188 = 0;
    std::uint32_t t189a = 0, t189b = 0, t189r = 0;
    std::uint32_t t191 = 0;
    std::uint32_t t192a = 0, t192r = 0;
    std::uint32_t t193 = 0;
    std::uint32_t t194 = 0;
    std::uint32_t t195 = 0;
    std::uint32_t t196a = 0, t196c = 0, t196r = 0;
    std::uint32_t t197 = 0;
    std::uint32_t t198a = 0, t198b = 0, t198r = 0;
    std::uint32_t t199 = 0;
    std::uint32_t t200a = 0, t200c = 0, t200r = 0;
    std::uint32_t t201 = 0;
    std::uint32_t t202a = 0, t202b = 0, t202r = 0;
    std::uint32_t t204a = 0, t204b = 0, t204r = 0;
    std::uint32_t t206 = 0;
    std::uint32_t t207a = 0, t207r = 0;
    std::uint32_t t208a = 0, t208b = 0, t208r = 0;
    std::uint32_t t209a = 0, t209b = 0, t209r = 0;
    std::uint32_t t211 = 0;
    std::uint32_t t212 = 0;
    std::uint32_t t213a = 0, t213b = 0, t213r = 0;
    std::uint32_t t215 = 0;
    std::uint32_t t216a = 0, t216c = 0, t216r = 0;
    std::uint32_t t217 = 0;
    std::uint32_t t218 = 0;
    std::uint32_t t219a = 0, t219b = 0, t219r = 0;
    std::uint32_t t222a = 0, t222b = 0, t222r = 0;
    std::uint32_t t223a = 0, t223b = 0, t223r = 0;
    std::uint32_t t224a = 0, t224b = 0, t224r = 0;
    std::uint32_t t226 = 0;
    std::uint32_t t227a = 0, t227b = 0, t227r = 0;
    std::uint32_t t229 = 0;
    std::uint32_t t230a = 0;
    std::uint32_t t231a = 0, t231b = 0, t231r = 0;
    std::uint32_t t232a = 0, t232b = 0, t232r = 0;
    std::uint32_t t233 = 0;
    std::uint32_t t234a = 0, t234b = 0, t234r = 0;
    std::uint32_t t236 = 0;
    std::uint32_t t237 = 0;
    std::uint32_t t238 = 0;
    std::uint32_t t239a = 0, t239b = 0, t239r = 0;
    std::uint32_t t240a = 0, t240b = 0, t240r = 0;
    std::uint32_t t242a = 0, t242b = 0, t242r = 0;
    std::uint32_t t244 = 0;
    std::uint32_t t245a = 0, t245b = 0, t245r = 0;
    std::uint32_t t248a = 0, t248b = 0, t248r = 0;
    std::uint32_t t250a = 0, t250b = 0, t250r = 0;
    std::uint32_t t252 = 0;
    std::uint32_t t253 = 0;
    std::uint32_t t254a = 0, t254b = 0, t254r = 0;
    std::uint32_t t255a = 0, t255b = 0, t255r = 0;
    std::uint32_t t257 = 0;
    std::uint32_t t258 = 0;
    std::uint32_t t259a = 0, t259b = 0, t259r = 0;
    std::uint32_t t260a = 0, t260b = 0, t260r = 0;
    std::uint32_t t262a = 0, t262b = 0, t262r = 0;
    std::uint32_t t264 = 0;
    std::uint32_t t265 = 0;
    std::uint32_t t266a = 0, t266b = 0, t266r = 0;
    std::uint32_t t267a = 0, t267b = 0, t267r = 0;
    std::uint32_t t269 = 0;
    std::uint32_t t270 = 0;
    std::uint32_t t271 = 0;
    std::uint32_t t272a = 0, t272b = 0, t272r = 0;
    std::uint32_t t273 = 0;
    std::uint32_t t274a = 0, t274b = 0, t274r = 0;
    std::uint32_t t276a = 0, t276b = 0, t276r = 0;
    std::uint32_t t278 = 0;
    BatchLiftStatus t279_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t280 = 0;
    std::uint32_t t281 = 0;
    std::uint32_t t282a = 0, t282c = 0, t282r = 0;
    std::uint32_t t283 = 0;
    std::uint32_t t285a = 0, t285b = 0, t285r = 0;
    std::uint32_t t287a = 0, t287b = 0, t287r = 0;
    std::uint32_t t288 = 0;
    std::uint32_t t290a = 0, t290b = 0, t290r = 0;
    std::uint32_t t292a = 0, t292b = 0, t292r = 0;
    std::uint32_t t294 = 0;
    std::uint32_t t295a = 0, t295b = 0, t295r = 0;
    std::uint32_t t297 = 0;
    std::uint32_t t298a = 0;
    std::uint32_t t299 = 0;
    BatchLiftStatus t300_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t301 = 0;
    std::uint32_t t302a = 0, t302b = 0, t302r = 0;
    std::uint32_t t304 = 0;
    std::uint32_t t305a = 0, t305b = 0, t305r = 0;
    std::uint32_t t307a = 0, t307b = 0, t307r = 0;
    std::uint32_t t309a = 0, t309b = 0, t309r = 0;
    std::uint32_t t311 = 0;
    std::uint32_t t312a = 0;
    std::uint32_t t313 = 0;
    BatchLiftStatus t314_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t315a = 0, t315b = 0, t315r = 0;
    std::uint32_t t317 = 0;
    std::uint32_t t318a = 0, t318b = 0, t318r = 0;
    std::uint32_t t319a = 0, t319b = 0, t319r = 0;
    std::uint32_t t320 = 0;
    std::uint32_t t321a = 0, t321b = 0, t321r = 0;
    std::uint32_t t322 = 0;
    std::uint32_t t323a = 0, t323b = 0, t323r = 0;
    std::uint32_t t325a = 0, t325b = 0, t325r = 0;
    std::uint32_t t327 = 0;
    std::uint32_t t328a = 0, t328r = 0;
    std::uint32_t t329 = 0;
    std::uint32_t t330a = 0, t330b = 0, t330r = 0;
    std::uint32_t t332 = 0;
    std::uint32_t t333 = 0;
    std::uint32_t t334a = 0, t334b = 0, t334r = 0;
    std::uint32_t t336 = 0;
    std::uint32_t t338 = 0;
    std::uint32_t t339a = 0, t339r = 0;
    std::uint32_t t340a = 0;
    BatchLiftStatus t341_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t342a = 0, t342b = 0, t342r = 0;
    std::uint32_t t344 = 0;
    std::uint32_t t345 = 0;
    std::uint32_t t346a = 0;
    std::uint32_t t347 = 0;
    std::uint32_t t348 = 0;
    std::uint32_t t349a = 0;
    std::uint32_t t350a = 0;
    std::uint32_t t351a = 0;
    BatchLiftStatus t352_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t353a = 0, t353b = 0, t353r = 0;
    std::uint32_t t354 = 0;
    std::uint32_t t355a = 0, t355b = 0, t355r = 0;
    std::uint32_t t358 = 0;
    std::uint32_t t359a = 0;
    BatchLiftStatus t360_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t361a = 0, t361r = 0;
    std::uint32_t t362a = 0, t362b = 0, t362r = 0;
    std::uint32_t t364a = 0, t364b = 0, t364r = 0;
    std::uint32_t t366 = 0;
    std::uint32_t t367a = 0;
    std::uint32_t t368a = 0;
    std::uint32_t t369a = 0;
    std::uint32_t t370a = 0;
    std::uint32_t t371a = 0, t371b = 0, t371r = 0;
    std::uint32_t t373a = 0, t373b = 0, t373r = 0;
    std::uint32_t t374a = 0, t374b = 0, t374r = 0;
    std::uint32_t t375a = 0, t375b = 0, t375r = 0;
    std::uint32_t t377a = 0, t377b = 0, t377r = 0;
    std::uint32_t t379a = 0, t379b = 0, t379r = 0;
    std::uint32_t t380 = 0;
    std::uint32_t t381 = 0;
    std::uint32_t t382 = 0;
    std::uint32_t t383 = 0;
    std::uint32_t t384a = 0, t384b = 0, t384r = 0;
    std::uint32_t t386 = 0;
    std::uint32_t t387a = 0;
    std::uint32_t t388 = 0;
    BatchLiftStatus t389_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t390a = 0;
    std::uint32_t t391a = 0;
    std::uint32_t t392a = 0;
    std::uint32_t t393a = 0;
    std::uint32_t t394a = 0, t394b = 0, t394r = 0;
    std::uint32_t t396 = 0;
    std::uint32_t t397a = 0, t397b = 0, t397r = 0;
    std::uint32_t t398a = 0;
    std::uint32_t t399a = 0;
    std::uint32_t t400a = 0;
    std::uint32_t t401 = 0;
    std::uint32_t t402 = 0;
    std::uint32_t t403a = 0;
    std::uint32_t t404a = 0, t404b = 0, t404r = 0;
    std::uint32_t t406 = 0;
    std::uint32_t t407 = 0;
    std::uint32_t t408 = 0;
    std::uint32_t t409 = 0;
    std::uint32_t t410 = 0;
    std::uint32_t t411 = 0;
    std::uint32_t t412 = 0;
    std::uint32_t t413 = 0;
    std::uint32_t t414 = 0;
    std::uint32_t t415a = 0, t415b = 0, t415r = 0;
    std::uint32_t t416 = 0;
    std::uint32_t t417a = 0, t417b = 0, t417r = 0;
    std::uint32_t t419a = 0, t419b = 0, t419r = 0;
    std::uint32_t t420a = 0;
    std::uint32_t t421a = 0;
    std::uint32_t t422a = 0;
    std::uint32_t t423a = 0;
    std::uint32_t t424a = 0, t424b = 0, t424r = 0;
    std::uint32_t t426 = 0;
    std::uint32_t t427 = 0;
    std::uint32_t t428 = 0;
    std::uint32_t t429 = 0;
    std::uint32_t t430 = 0;
    std::uint32_t t431 = 0;
    std::uint32_t t432 = 0;
    std::uint32_t t433 = 0;
    std::uint32_t t434a = 0, t434b = 0, t434r = 0;
    std::uint32_t t435 = 0;
    std::uint32_t t436 = 0;
    std::uint32_t t437a = 0, t437b = 0, t437r = 0;
    std::uint32_t t438a = 0;
    std::uint32_t t439 = 0;
    std::uint32_t t440 = 0;
    std::uint32_t t441 = 0;
    std::uint32_t t442a = 0;
    std::uint32_t t443a = 0;
    std::uint32_t t444a = 0;
    std::uint32_t t445a = 0, t445b = 0, t445r = 0;
    std::uint32_t t447a = 0, t447b = 0, t447r = 0;
    std::uint32_t t448a = 0;
    std::uint32_t t449a = 0;
    std::uint32_t t450a = 0;
    std::uint32_t t451 = 0;
    std::uint32_t t452a = 0;
    std::uint32_t t453a = 0, t453b = 0, t453r = 0;
    std::uint32_t t455 = 0;
    std::uint32_t t456 = 0;
    std::uint32_t t457 = 0;
    std::uint32_t t458 = 0;
    std::uint32_t t459 = 0;
    std::uint32_t t460 = 0;
    std::uint32_t t461 = 0;
    std::uint32_t t462 = 0;
    std::uint32_t t463a = 0, t463b = 0, t463r = 0;
    std::uint32_t t464a = 0, t464b = 0, t464r = 0;
    std::uint32_t t466 = 0;
    std::uint32_t t467 = 0;
    std::uint32_t t468a = 0, t468b = 0, t468r = 0;
    std::uint32_t t469 = 0;
    std::uint32_t t470 = 0;
    std::uint32_t t471 = 0;
    std::uint32_t t472 = 0;
    std::uint32_t t473a = 0, t473b = 0, t473r = 0;
    std::uint32_t t474 = 0;
    std::uint32_t t475 = 0;
    std::uint32_t t476a = 0, t476b = 0, t476r = 0;
    std::uint32_t t477a = 0;
    std::uint32_t t478 = 0;
    std::uint32_t t479 = 0;
    std::uint32_t t480a = 0;
    std::uint32_t t481a = 0;
    std::uint32_t t482a = 0;
    std::uint32_t t483a = 0, t483b = 0, t483r = 0;
    std::uint32_t t485 = 0;
    std::uint32_t t486 = 0;
    std::uint32_t t487 = 0;
    std::uint32_t t488 = 0;
    std::uint32_t t489 = 0;
    std::uint32_t t490 = 0;
    std::uint32_t t491 = 0;
    std::uint32_t t492 = 0;
    std::uint32_t t493 = 0;
    std::uint32_t t494a = 0, t494b = 0, t494r = 0;
    std::uint32_t t495 = 0;
    std::uint32_t t496a = 0, t496b = 0, t496r = 0;
    std::uint32_t t498 = 0;
    std::uint32_t t499 = 0;
    std::uint32_t t500 = 0;
    std::uint32_t t501 = 0;
    std::uint32_t t502 = 0;
    std::uint32_t t503 = 0;
    std::uint32_t t504 = 0;
    std::uint32_t t505 = 0;
    std::uint32_t t506a = 0, t506b = 0, t506r = 0;
    std::uint32_t t508 = 0;
    std::uint32_t t509a = 0, t509b = 0, t509r = 0;
    std::uint32_t t510 = 0;
    std::uint32_t t511 = 0;
    std::uint32_t t512a = 0, t512b = 0, t512r = 0;
    std::uint32_t t513 = 0;
    std::uint32_t t514 = 0;
    std::uint32_t t515 = 0;
    std::uint32_t t516a = 0;
    std::uint32_t t517a = 0;
    std::uint32_t t518a = 0;
    std::uint32_t t519a = 0;
    std::uint32_t t520a = 0, t520b = 0, t520r = 0;
    std::uint32_t t522a = 0, t522b = 0, t522r = 0;
    std::uint32_t t524 = 0;
    std::uint32_t t525a = 0, t525b = 0, t525r = 0;
    std::uint32_t t526a = 0, t526b = 0, t526r = 0;
    std::uint32_t t527a = 0, t527b = 0, t527r = 0;
    std::uint32_t t529a = 0, t529b = 0, t529r = 0;
    std::uint32_t t530 = 0;
    std::uint32_t t531 = 0;
    std::uint32_t t532a = 0, t532b = 0, t532r = 0;
    std::uint32_t t533 = 0;
    std::uint32_t t534 = 0;
    std::uint32_t t536a = 0, t536b = 0, t536r = 0;
    std::uint32_t t537 = 0;
    std::uint32_t t538a = 0, t538b = 0, t538r = 0;
    std::uint32_t t539a = 0, t539b = 0, t539r = 0;
    std::uint32_t t540 = 0;
    std::uint32_t t541 = 0;
    std::uint32_t t542a = 0, t542b = 0, t542r = 0;
    std::uint32_t t543 = 0;
    std::uint32_t t544 = 0;
    std::uint32_t t546a = 0, t546b = 0, t546r = 0;
    std::uint32_t t547 = 0;
    std::uint32_t t548 = 0;
    std::uint32_t t549 = 0;
    std::uint32_t t550a = 0, t550b = 0, t550r = 0;
    std::uint32_t t551 = 0;
    std::uint32_t t552a = 0, t552b = 0, t552r = 0;
    std::uint32_t t553 = 0;
    std::uint32_t t554 = 0;
    std::uint32_t t555 = 0;
    std::uint32_t t556 = 0;
    std::uint32_t t557a = 0, t557b = 0, t557r = 0;
    std::uint32_t t558 = 0;
    std::uint32_t t559 = 0;
    std::uint32_t t560 = 0;
    std::uint32_t t561 = 0;
    std::uint32_t t562a = 0, t562b = 0, t562r = 0;
    std::uint32_t t564 = 0;
    std::uint32_t t565 = 0;
    std::uint32_t t566a = 0, t566c = 0, t566r = 0;
    std::uint32_t t567a = 0, t567b = 0, t567r = 0;
    std::uint32_t t568a = 0, t568b = 0, t568r = 0;
    std::uint32_t t569 = 0;
    std::uint32_t t570a = 0;
    std::uint32_t t571a = 0;
    std::uint32_t t572a = 0;
    std::uint32_t t573 = 0;
    std::uint32_t t574a = 0;
    std::uint32_t t575a = 0, t575b = 0, t575r = 0;

    // 0x00927be0: 83ec20 SUB
        t0a = state.regs[4];
        t0b = 0x00000020u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00927be3: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00927be4: 55 PUSH
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00927be5: 33c0 XOR
        t3a = state.regs[0];
        t3b = state.regs[0];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[0] = t3r;
    // 0x00927be7: f644243008 TEST
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t4a)) return BatchLiftStatus::invalid_memory;
        t4b = 0x00000008u;
        t4r = (t4a & t4b) & 0x000000ffu;
        batch_set_logic_flags(state, t4r, 8u);
    // 0x00927bec: 56 PUSH
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00927bed: 8be9 MOV
        t6 = state.regs[1];
        state.regs[5] = t6;
    // 0x00927bef: 57 PUSH
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00927bf0: 896c2428 MOV
        t8 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00927bf4: 89442414 MOV
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00927bf8: 89442424 MOV
        t10 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00927bfc: 89442418 MOV
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00927c00: 0f85c4040000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009280ca;
    // 0x00927c06: 8b442434 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00927c0a: 50 PUSH
        t14a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00927c0b: e890ebffff CALL
        if (!batch_guest_call32(memory, state, 0x009267a0u, 0x00927c10u)) return BatchLiftStatus::invalid_memory;
        t15_call_status = spore_lift_009267a0(memory, state);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x00927c10u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927c10: 83c404 ADD
        t16a = state.regs[4];
        t16b = 0x00000004u;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[4] = t16r;
    // 0x00927c13: 89442410 MOV
        t17 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00927c17: eb0b JMP
        goto L_00927c24;
    // 0x00927c20: 8b442410 MOV
    L_00927c20:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x00927c24: 8b7c2438 MOV
    L_00927c24:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t20;
    // 0x00927c28: 8bf7 MOV
        t21 = state.regs[7];
        state.regs[6] = t21;
    // 0x00927c2a: 83e601 AND
        t22a = state.regs[6];
        t22b = 0x00000001u;
        t22r = (t22a & t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
        state.regs[6] = t22r;
    // 0x00927c2d: 81e700020000 AND
        t23a = state.regs[7];
        t23b = 0x00000200u;
        t23r = (t23a & t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[7] = t23r;
    // 0x00927c33: 8974241c MOV
        t24 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00927c37: 897c242c MOV
        t25 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t25)) return BatchLiftStatus::invalid_memory;
    // 0x00927c3b: 0f85f4000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927d35;
    // 0x00927c41: 8b5d04 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t27;
    // 0x00927c44: 3bc3 CMP
        t28a = state.regs[0];
        t28b = state.regs[3];
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x00927c46: 7717 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00927c5f;
    // 0x00927c48: 85f6 TEST
        t30a = state.regs[6];
        t30b = state.regs[6];
        t30r = (t30a & t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
    // 0x00927c4a: 7513 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927c5f;
    // 0x00927c4c: 8bc8 MOV
        t32 = state.regs[0];
        state.regs[1] = t32;
    // 0x00927c4e: c1e903 SHR
        t33a = state.regs[1];
        t33c = 3u;
        if (t33c != 0u) {
        t33r = static_cast<std::uint32_t>(t33a >> t33c);
        batch_set_shr_flags(state, t33a, t33c, t33r, 32u);
            state.regs[1] = t33r;
        }
    // 0x00927c51: 8d548d00 LEA
        t34 = static_cast<std::uint32_t>(state.regs[5] + state.regs[1] * 4u + 0x00000000u);
        state.regs[2] = t34;
    // 0x00927c55: 8b0a MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35;
    // 0x00927c57: 85c9 TEST
        t36a = state.regs[1];
        t36b = state.regs[1];
        t36r = (t36a & t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
    // 0x00927c59: 0f8581040000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009280e0;
    // 0x00927c5f: 8bc8 MOV
    L_00927c5f:
        t38 = state.regs[0];
        state.regs[1] = t38;
    // 0x00927c61: 3d00020000 CMP
        t39a = state.regs[0];
        t39b = 0x00000200u;
        t39r = static_cast<std::uint32_t>(t39a - t39b) & 0xffffffffu;
        batch_set_sub_flags(state, t39a, t39b, t39r, 32u);
    // 0x00927c66: 735e JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00927cc6;
    // 0x00927c68: c1e903 SHR
        t41a = state.regs[1];
        t41c = 3u;
        if (t41c != 0u) {
        t41r = static_cast<std::uint32_t>(t41a >> t41c);
        batch_set_shr_flags(state, t41a, t41c, t41r, 32u);
            state.regs[1] = t41r;
        }
    // 0x00927c6b: 8d54cd28 LEA
        t42 = static_cast<std::uint32_t>(state.regs[5] + state.regs[1] * 8u + 0x00000028u);
        state.regs[2] = t42;
    // 0x00927c6f: 894c2414 MOV
        t43 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x00927c73: 8b4a08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t44;
    // 0x00927c76: 3bca CMP
        t45a = state.regs[1];
        t45b = state.regs[2];
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
    // 0x00927c78: 0f84b7000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927d35;
    // 0x00927c7e: 8b9568040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000468u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t47;
    // 0x00927c84: 85d2 TEST
        t48a = state.regs[2];
        t48b = state.regs[2];
        t48r = (t48a & t48b) & 0xffffffffu;
        batch_set_logic_flags(state, t48r, 32u);
    // 0x00927c86: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927ca3;
    // 0x00927c88: 85f6 TEST
        t50a = state.regs[6];
        t50b = state.regs[6];
        t50r = (t50a & t50b) & 0xffffffffu;
        batch_set_logic_flags(state, t50r, 32u);
    // 0x00927c8a: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927c96;
    // 0x00927c8c: 8d3401 LEA
        t52 = static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000000u);
        state.regs[6] = t52;
    // 0x00927c8f: 3bf2 CMP
        t53a = state.regs[6];
        t53b = state.regs[2];
        t53r = static_cast<std::uint32_t>(t53a - t53b) & 0xffffffffu;
        batch_set_sub_flags(state, t53a, t53b, t53r, 32u);
    // 0x00927c91: 0f93c2 SETNC
        state.regs[2] = (state.regs[2] & 0xffffff00u) | (((!((state.eflags & 0x001u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927c94: eb05 JMP
        goto L_00927c9b;
    // 0x00927c96: 3bca CMP
    L_00927c96:
        t56a = state.regs[1];
        t56b = state.regs[2];
        t56r = static_cast<std::uint32_t>(t56a - t56b) & 0xffffffffu;
        batch_set_sub_flags(state, t56a, t56b, t56r, 32u);
    // 0x00927c98: 0f92c2 SETC
        state.regs[2] = (state.regs[2] & 0xffffff00u) | (((((state.eflags & 0x001u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927c9b: 84d2 TEST
    L_00927c9b:
        t58a = state.regs[2] & 0x000000ffu;
        t58b = state.regs[2] & 0x000000ffu;
        t58r = (t58a & t58b) & 0x000000ffu;
        batch_set_logic_flags(state, t58r, 8u);
    // 0x00927c9d: 0f8492000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927d35;
    // 0x00927ca3: 834c010401 OR
    L_00927ca3:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000004u), t60a)) return BatchLiftStatus::invalid_memory;
        t60b = 0x00000001u;
        t60r = (t60a | t60b) & 0xffffffffu;
        batch_set_logic_flags(state, t60r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000004u), t60r)) return BatchLiftStatus::invalid_memory;
    // 0x00927ca8: 8b710c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t61)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t61;
    // 0x00927cab: 8b5108 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t62;
    // 0x00927cae: 8d4108 LEA
        t63 = static_cast<std::uint32_t>(state.regs[1] + 0x00000008u);
        state.regs[0] = t63;
    // 0x00927cb1: 89720c MOV
        t64 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t64)) return BatchLiftStatus::invalid_memory;
    // 0x00927cb4: 8b490c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t65)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t65;
    // 0x00927cb7: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t66;
    // 0x00927cb9: 5f POP
        if (!memory.load32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t67a;
    // 0x00927cba: 5e POP
        if (!memory.load32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t68a;
    // 0x00927cbb: 5d POP
        if (!memory.load32(state.regs[4], t69a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t69a;
    // 0x00927cbc: 895108 MOV
        t70 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x00927cbf: 5b POP
        if (!memory.load32(state.regs[4], t71a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t71a;
    // 0x00927cc0: 83c420 ADD
        t72a = state.regs[4];
        t72b = 0x00000020u;
        t72r = static_cast<std::uint32_t>(t72a + t72b) & 0xffffffffu;
        batch_set_add_flags(state, t72a, t72b, t72r, 32u);
        state.regs[4] = t72r;
    // 0x00927cc3: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00927cc6: c1e906 SHR
    L_00927cc6:
        t74a = state.regs[1];
        t74c = 6u;
        if (t74c != 0u) {
        t74r = static_cast<std::uint32_t>(t74a >> t74c);
        batch_set_shr_flags(state, t74a, t74c, t74r, 32u);
            state.regs[1] = t74r;
        }
    // 0x00927cc9: 83f920 CMP
        t75a = state.regs[1];
        t75b = 0x00000020u;
        t75r = static_cast<std::uint32_t>(t75a - t75b) & 0xffffffffu;
        batch_set_sub_flags(state, t75a, t75b, t75r, 32u);
    // 0x00927ccc: 7709 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00927cd7;
    // 0x00927cce: 83c138 ADD
        t77a = state.regs[1];
        t77b = 0x00000038u;
        t77r = static_cast<std::uint32_t>(t77a + t77b) & 0xffffffffu;
        batch_set_add_flags(state, t77a, t77b, t77r, 32u);
        state.regs[1] = t77r;
    // 0x00927cd1: 894c2414 MOV
        t78 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t78)) return BatchLiftStatus::invalid_memory;
    // 0x00927cd5: eb52 JMP
        goto L_00927d29;
    // 0x00927cd7: 8bc8 MOV
    L_00927cd7:
        t80 = state.regs[0];
        state.regs[1] = t80;
    // 0x00927cd9: c1e909 SHR
        t81a = state.regs[1];
        t81c = 9u;
        if (t81c != 0u) {
        t81r = static_cast<std::uint32_t>(t81a >> t81c);
        batch_set_shr_flags(state, t81a, t81c, t81r, 32u);
            state.regs[1] = t81r;
        }
    // 0x00927cdc: 83f914 CMP
        t82a = state.regs[1];
        t82b = 0x00000014u;
        t82r = static_cast<std::uint32_t>(t82a - t82b) & 0xffffffffu;
        batch_set_sub_flags(state, t82a, t82b, t82r, 32u);
    // 0x00927cdf: 7709 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00927cea;
    // 0x00927ce1: 83c15b ADD
        t84a = state.regs[1];
        t84b = 0x0000005bu;
        t84r = static_cast<std::uint32_t>(t84a + t84b) & 0xffffffffu;
        batch_set_add_flags(state, t84a, t84b, t84r, 32u);
        state.regs[1] = t84r;
    // 0x00927ce4: 894c2414 MOV
        t85 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t85)) return BatchLiftStatus::invalid_memory;
    // 0x00927ce8: eb3f JMP
        goto L_00927d29;
    // 0x00927cea: 8bc8 MOV
    L_00927cea:
        t87 = state.regs[0];
        state.regs[1] = t87;
    // 0x00927cec: c1e90c SHR
        t88a = state.regs[1];
        t88c = 12u;
        if (t88c != 0u) {
        t88r = static_cast<std::uint32_t>(t88a >> t88c);
        batch_set_shr_flags(state, t88a, t88c, t88r, 32u);
            state.regs[1] = t88r;
        }
    // 0x00927cef: 83f90a CMP
        t89a = state.regs[1];
        t89b = 0x0000000au;
        t89r = static_cast<std::uint32_t>(t89a - t89b) & 0xffffffffu;
        batch_set_sub_flags(state, t89a, t89b, t89r, 32u);
    // 0x00927cf2: 7709 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00927cfd;
    // 0x00927cf4: 83c16e ADD
        t91a = state.regs[1];
        t91b = 0x0000006eu;
        t91r = static_cast<std::uint32_t>(t91a + t91b) & 0xffffffffu;
        batch_set_add_flags(state, t91a, t91b, t91r, 32u);
        state.regs[1] = t91r;
    // 0x00927cf7: 894c2414 MOV
        t92 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t92)) return BatchLiftStatus::invalid_memory;
    // 0x00927cfb: eb2c JMP
        goto L_00927d29;
    // 0x00927cfd: 8bc8 MOV
    L_00927cfd:
        t94 = state.regs[0];
        state.regs[1] = t94;
    // 0x00927cff: c1e90f SHR
        t95a = state.regs[1];
        t95c = 15u;
        if (t95c != 0u) {
        t95r = static_cast<std::uint32_t>(t95a >> t95c);
        batch_set_shr_flags(state, t95a, t95c, t95r, 32u);
            state.regs[1] = t95r;
        }
    // 0x00927d02: 83f904 CMP
        t96a = state.regs[1];
        t96b = 0x00000004u;
        t96r = static_cast<std::uint32_t>(t96a - t96b) & 0xffffffffu;
        batch_set_sub_flags(state, t96a, t96b, t96r, 32u);
    // 0x00927d05: 7709 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00927d10;
    // 0x00927d07: 83c177 ADD
        t98a = state.regs[1];
        t98b = 0x00000077u;
        t98r = static_cast<std::uint32_t>(t98a + t98b) & 0xffffffffu;
        batch_set_add_flags(state, t98a, t98b, t98r, 32u);
        state.regs[1] = t98r;
    // 0x00927d0a: 894c2414 MOV
        t99 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t99)) return BatchLiftStatus::invalid_memory;
    // 0x00927d0e: eb19 JMP
        goto L_00927d29;
    // 0x00927d10: c1e812 SHR
    L_00927d10:
        t101a = state.regs[0];
        t101c = 18u;
        if (t101c != 0u) {
        t101r = static_cast<std::uint32_t>(t101a >> t101c);
        batch_set_shr_flags(state, t101a, t101c, t101r, 32u);
            state.regs[0] = t101r;
        }
    // 0x00927d13: 83f802 CMP
        t102a = state.regs[0];
        t102b = 0x00000002u;
        t102r = static_cast<std::uint32_t>(t102a - t102b) & 0xffffffffu;
        batch_set_sub_flags(state, t102a, t102b, t102r, 32u);
    // 0x00927d16: 7709 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00927d21;
    // 0x00927d18: 83c07c ADD
        t104a = state.regs[0];
        t104b = 0x0000007cu;
        t104r = static_cast<std::uint32_t>(t104a + t104b) & 0xffffffffu;
        batch_set_add_flags(state, t104a, t104b, t104r, 32u);
        state.regs[0] = t104r;
    // 0x00927d1b: 89442414 MOV
        t105 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t105)) return BatchLiftStatus::invalid_memory;
    // 0x00927d1f: eb08 JMP
        goto L_00927d29;
    // 0x00927d21: c74424147e000000 MOV
    L_00927d21:
        t107 = 0x0000007eu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t107)) return BatchLiftStatus::invalid_memory;
    // 0x00927d29: f6c301 TEST
    L_00927d29:
        t108a = state.regs[3] & 0x000000ffu;
        t108b = 0x00000001u;
        t108r = (t108a & t108b) & 0x000000ffu;
        batch_set_logic_flags(state, t108r, 8u);
    // 0x00927d2c: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927d35;
    // 0x00927d2e: 8bcd MOV
        t110 = state.regs[5];
        state.regs[1] = t110;
    // 0x00927d30: e8cbf9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00927700u, 0x00927d35u)) return BatchLiftStatus::invalid_memory;
        t111_call_status = spore_lift_00927700(memory, state);
        if (t111_call_status != BatchLiftStatus::returned) return t111_call_status;
        if (state.eip != 0x00927d35u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927d35: 85ff TEST
    L_00927d35:
        t112a = state.regs[7];
        t112b = state.regs[7];
        t112r = (t112a & t112b) & 0xffffffffu;
        batch_set_logic_flags(state, t112r, 32u);
    // 0x00927d37: 0f85e4010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927f21;
    // 0x00927d3d: 8b4d38 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000038u), t114)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t114;
    // 0x00927d40: 8b5c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t115)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t115;
    // 0x00927d44: 8d7530 LEA
        t116 = static_cast<std::uint32_t>(state.regs[5] + 0x00000030u);
        state.regs[6] = t116;
    // 0x00927d47: 3bce CMP
        t117a = state.regs[1];
        t117b = state.regs[6];
        t117r = static_cast<std::uint32_t>(t117a - t117b) & 0xffffffffu;
        batch_set_sub_flags(state, t117a, t117b, t117r, 32u);
    // 0x00927d49: 0f8480000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927dcf;
    // 0x00927d4f: 90 NOP
    // 0x00927d50: 8b5104 MOV
    L_00927d50:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t120;
    // 0x00927d53: 8b8568040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000468u), t121)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t121;
    // 0x00927d59: 8b7908 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t122)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t122;
    // 0x00927d5c: 81e2f8ffff7f AND
        t123a = state.regs[2];
        t123b = 0x7ffffff8u;
        t123r = (t123a & t123b) & 0xffffffffu;
        batch_set_logic_flags(state, t123r, 32u);
        state.regs[2] = t123r;
    // 0x00927d62: 85c0 TEST
        t124a = state.regs[0];
        t124b = state.regs[0];
        t124r = (t124a & t124b) & 0xffffffffu;
        batch_set_logic_flags(state, t124r, 32u);
    // 0x00927d64: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927d6a;
    // 0x00927d66: b001 MOV
        t126 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t126 << 0u) & 0x000000ffu);
    // 0x00927d68: eb1a JMP
        goto L_00927d84;
    // 0x00927d6a: 837c241c00 CMP
    L_00927d6a:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t128a)) return BatchLiftStatus::invalid_memory;
        t128b = 0x00000000u;
        t128r = static_cast<std::uint32_t>(t128a - t128b) & 0xffffffffu;
        batch_set_sub_flags(state, t128a, t128b, t128r, 32u);
    // 0x00927d6f: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927d7b;
    // 0x00927d71: 8d1c0a LEA
        t130 = static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0x00000000u);
        state.regs[3] = t130;
    // 0x00927d74: 3bd8 CMP
        t131a = state.regs[3];
        t131b = state.regs[0];
        t131r = static_cast<std::uint32_t>(t131a - t131b) & 0xffffffffu;
        batch_set_sub_flags(state, t131a, t131b, t131r, 32u);
    // 0x00927d76: 0f93c0 SETNC
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((!((state.eflags & 0x001u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927d79: eb05 JMP
        goto L_00927d80;
    // 0x00927d7b: 3bc8 CMP
    L_00927d7b:
        t134a = state.regs[1];
        t134b = state.regs[0];
        t134r = static_cast<std::uint32_t>(t134a - t134b) & 0xffffffffu;
        batch_set_sub_flags(state, t134a, t134b, t134r, 32u);
    // 0x00927d7d: 0f92c0 SETC
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((((state.eflags & 0x001u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927d80: 8b5c2410 MOV
    L_00927d80:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t136)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t136;
    // 0x00927d84: 81fb00020000 CMP
    L_00927d84:
        t137a = state.regs[3];
        t137b = 0x00000200u;
        t137r = static_cast<std::uint32_t>(t137a - t137b) & 0xffffffffu;
        batch_set_sub_flags(state, t137a, t137b, t137r, 32u);
    // 0x00927d8a: 731f JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00927dab;
    // 0x00927d8c: 3b8d44040000 CMP
        t139a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000444u), t139b)) return BatchLiftStatus::invalid_memory;
        t139r = static_cast<std::uint32_t>(t139a - t139b) & 0xffffffffu;
        batch_set_sub_flags(state, t139a, t139b, t139r, 32u);
    // 0x00927d92: 7517 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927dab;
    // 0x00927d94: 3bfe CMP
        t141a = state.regs[7];
        t141b = state.regs[6];
        t141r = static_cast<std::uint32_t>(t141a - t141b) & 0xffffffffu;
        batch_set_sub_flags(state, t141a, t141b, t141r, 32u);
    // 0x00927d96: 7513 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927dab;
    // 0x00927d98: 83c310 ADD
        t143a = state.regs[3];
        t143b = 0x00000010u;
        t143r = static_cast<std::uint32_t>(t143a + t143b) & 0xffffffffu;
        batch_set_add_flags(state, t143a, t143b, t143r, 32u);
        state.regs[3] = t143r;
    // 0x00927d9b: 3bd3 CMP
        t144a = state.regs[2];
        t144b = state.regs[3];
        t144r = static_cast<std::uint32_t>(t144a - t144b) & 0xffffffffu;
        batch_set_sub_flags(state, t144a, t144b, t144r, 32u);
    // 0x00927d9d: 7608 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00927da7;
    // 0x00927d9f: 84c0 TEST
        t146a = state.regs[0] & 0x000000ffu;
        t146b = state.regs[0] & 0x000000ffu;
        t146r = (t146a & t146b) & 0x000000ffu;
        batch_set_logic_flags(state, t146r, 8u);
    // 0x00927da1: 0f8552030000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009280f9;
    // 0x00927da7: 8b5c2410 MOV
    L_00927da7:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t148)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t148;
    // 0x00927dab: 897e08 MOV
    L_00927dab:
        t149 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t149)) return BatchLiftStatus::invalid_memory;
    // 0x00927dae: 89770c MOV
        t150 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t150)) return BatchLiftStatus::invalid_memory;
    // 0x00927db1: 3bd3 CMP
        t151a = state.regs[2];
        t151b = state.regs[3];
        t151r = static_cast<std::uint32_t>(t151a - t151b) & 0xffffffffu;
        batch_set_sub_flags(state, t151a, t151b, t151r, 32u);
    // 0x00927db3: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927dbd;
    // 0x00927db5: 84c0 TEST
        t153a = state.regs[0] & 0x000000ffu;
        t153b = state.regs[0] & 0x000000ffu;
        t153r = (t153a & t153b) & 0x000000ffu;
        batch_set_logic_flags(state, t153r, 8u);
    // 0x00927db7: 0f85aa030000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00928167;
    // 0x00927dbd: 6a00 PUSH
    L_00927dbd:
        t155a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t155a)) return BatchLiftStatus::invalid_memory;
    // 0x00927dbf: 52 PUSH
        t156a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t156a)) return BatchLiftStatus::invalid_memory;
    // 0x00927dc0: 51 PUSH
        t157a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t157a)) return BatchLiftStatus::invalid_memory;
    // 0x00927dc1: 8bcd MOV
        t158 = state.regs[5];
        state.regs[1] = t158;
    // 0x00927dc3: e898ebffff CALL
        if (!batch_guest_call32(memory, state, 0x00926960u, 0x00927dc8u)) return BatchLiftStatus::invalid_memory;
        t159_call_status = spore_lift_00926960(memory, state);
        if (t159_call_status != BatchLiftStatus::returned) return t159_call_status;
        if (state.eip != 0x00927dc8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927dc8: 8b4e08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t160)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t160;
    // 0x00927dcb: 3bce CMP
        t161a = state.regs[1];
        t161b = state.regs[6];
        t161r = static_cast<std::uint32_t>(t161a - t161b) & 0xffffffffu;
        batch_set_sub_flags(state, t161a, t161b, t161r, 32u);
    // 0x00927dcd: 7581 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927d50;
    // 0x00927dcf: 81fb00020000 CMP
    L_00927dcf:
        t163a = state.regs[3];
        t163b = 0x00000200u;
        t163r = static_cast<std::uint32_t>(t163a - t163b) & 0xffffffffu;
        batch_set_sub_flags(state, t163a, t163b, t163r, 32u);
    // 0x00927dd5: 7259 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00927e30;
    // 0x00927dd7: 8b542414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t165)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t165;
    // 0x00927ddb: 8b4cd530 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + state.regs[2] * 8u + 0x00000030u), t166)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t166;
    // 0x00927ddf: 8d74d528 LEA
        t167 = static_cast<std::uint32_t>(state.regs[5] + state.regs[2] * 8u + 0x00000028u);
        state.regs[6] = t167;
    // 0x00927de3: 3bce CMP
        t168a = state.regs[1];
        t168b = state.regs[6];
        t168r = static_cast<std::uint32_t>(t168a - t168b) & 0xffffffffu;
        batch_set_sub_flags(state, t168a, t168b, t168r, 32u);
    // 0x00927de5: 7449 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927e30;
    // 0x00927de7: eb07 JMP
        goto L_00927df0;
    // 0x00927df0: 8b5104 MOV
    L_00927df0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t171)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t171;
    // 0x00927df3: 81e2f8ffff7f AND
        t172a = state.regs[2];
        t172b = 0x7ffffff8u;
        t172r = (t172a & t172b) & 0xffffffffu;
        batch_set_logic_flags(state, t172r, 32u);
        state.regs[2] = t172r;
    // 0x00927df9: 3bd3 CMP
        t173a = state.regs[2];
        t173b = state.regs[3];
        t173r = static_cast<std::uint32_t>(t173a - t173b) & 0xffffffffu;
        batch_set_sub_flags(state, t173a, t173b, t173r, 32u);
    // 0x00927dfb: 722c JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00927e29;
    // 0x00927dfd: 8b8568040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000468u), t175)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t175;
    // 0x00927e03: 85c0 TEST
        t176a = state.regs[0];
        t176b = state.regs[0];
        t176r = (t176a & t176b) & 0xffffffffu;
        batch_set_logic_flags(state, t176r, 32u);
    // 0x00927e05: 0f846e030000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928179;
    // 0x00927e0b: 837c241c00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t178a)) return BatchLiftStatus::invalid_memory;
        t178b = 0x00000000u;
        t178r = static_cast<std::uint32_t>(t178a - t178b) & 0xffffffffu;
        batch_set_sub_flags(state, t178a, t178b, t178r, 32u);
    // 0x00927e10: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927e1c;
    // 0x00927e12: 8d3c0a LEA
        t180 = static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0x00000000u);
        state.regs[7] = t180;
    // 0x00927e15: 3bf8 CMP
        t181a = state.regs[7];
        t181b = state.regs[0];
        t181r = static_cast<std::uint32_t>(t181a - t181b) & 0xffffffffu;
        batch_set_sub_flags(state, t181a, t181b, t181r, 32u);
    // 0x00927e17: 0f93c0 SETNC
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((!((state.eflags & 0x001u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927e1a: eb05 JMP
        goto L_00927e21;
    // 0x00927e1c: 3bc8 CMP
    L_00927e1c:
        t184a = state.regs[1];
        t184b = state.regs[0];
        t184r = static_cast<std::uint32_t>(t184a - t184b) & 0xffffffffu;
        batch_set_sub_flags(state, t184a, t184b, t184r, 32u);
    // 0x00927e1e: 0f92c0 SETC
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((((state.eflags & 0x001u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927e21: 84c0 TEST
    L_00927e21:
        t186a = state.regs[0] & 0x000000ffu;
        t186b = state.regs[0] & 0x000000ffu;
        t186r = (t186a & t186b) & 0x000000ffu;
        batch_set_logic_flags(state, t186r, 8u);
    // 0x00927e23: 0f8550030000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00928179;
    // 0x00927e29: 8b4908 MOV
    L_00927e29:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t188)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t188;
    // 0x00927e2c: 3bce CMP
        t189a = state.regs[1];
        t189b = state.regs[6];
        t189r = static_cast<std::uint32_t>(t189a - t189b) & 0xffffffffu;
        batch_set_sub_flags(state, t189a, t189b, t189r, 32u);
    // 0x00927e2e: 75c0 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927df0;
    // 0x00927e30: 8b4c2414 MOV
    L_00927e30:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t191)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t191;
    // 0x00927e34: 41 INC
        t192a = state.regs[1];
        t192r = static_cast<std::uint32_t>(t192a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t192a, t192r, 32u);
        state.regs[1] = t192r;
    // 0x00927e35: 8bd9 MOV
        t193 = state.regs[1];
        state.regs[3] = t193;
    // 0x00927e37: 894c2414 MOV
        t194 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t194)) return BatchLiftStatus::invalid_memory;
    // 0x00927e3b: 8d7ccd28 LEA
        t195 = static_cast<std::uint32_t>(state.regs[5] + state.regs[1] * 8u + 0x00000028u);
        state.regs[7] = t195;
    // 0x00927e3f: c1fb05 SAR
        t196a = state.regs[3];
        t196c = 5u;
        if (t196c != 0u) {
        t196r = (t196a >> t196c) | ((t196a & 0x80000000u) ? (0xffffffffu << (32u - t196c)) : 0u);
        batch_set_sar_flags(state, t196a, t196c, t196r, 32u);
            state.regs[3] = t196r;
        }
    // 0x00927e42: 8b949d30040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + state.regs[3] * 4u + 0x00000430u), t197)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t197;
    // 0x00927e49: 83e11f AND
        t198a = state.regs[1];
        t198b = 0x0000001fu;
        t198r = (t198a & t198b) & 0xffffffffu;
        batch_set_logic_flags(state, t198r, 32u);
        state.regs[1] = t198r;
    // 0x00927e4c: be01000000 MOV
        t199 = 0x00000001u;
        state.regs[6] = t199;
    // 0x00927e51: d3e6 SHL
        t200a = state.regs[6];
        t200c = (state.regs[1] & 0x1fu);
        if (t200c != 0u) {
        t200r = static_cast<std::uint32_t>(t200a << t200c) & 0xffffffffu;
        batch_set_shl_flags(state, t200a, t200c, t200r, 32u);
            state.regs[6] = t200r;
        }
    // 0x00927e53: 89542420 MOV
    L_00927e53:
        t201 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t201)) return BatchLiftStatus::invalid_memory;
    // 0x00927e57: 3bf2 CMP
    L_00927e57:
        t202a = state.regs[6];
        t202b = state.regs[2];
        t202r = static_cast<std::uint32_t>(t202a - t202b) & 0xffffffffu;
        batch_set_sub_flags(state, t202a, t202b, t202r, 32u);
    // 0x00927e59: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00927e5f;
    // 0x00927e5b: 85f6 TEST
        t204a = state.regs[6];
        t204b = state.regs[6];
        t204r = (t204a & t204b) & 0xffffffffu;
        batch_set_logic_flags(state, t204r, 32u);
    // 0x00927e5d: 752c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927e8b;
    // 0x00927e5f: 8d849d30040000 LEA
    L_00927e5f:
        t206 = static_cast<std::uint32_t>(state.regs[5] + state.regs[3] * 4u + 0x00000430u);
        state.regs[0] = t206;
    // 0x00927e66: 43 INC
    L_00927e66:
        t207a = state.regs[3];
        t207r = static_cast<std::uint32_t>(t207a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t207a, t207r, 32u);
        state.regs[3] = t207r;
    // 0x00927e67: 83c004 ADD
        t208a = state.regs[0];
        t208b = 0x00000004u;
        t208r = static_cast<std::uint32_t>(t208a + t208b) & 0xffffffffu;
        batch_set_add_flags(state, t208a, t208b, t208r, 32u);
        state.regs[0] = t208r;
    // 0x00927e6a: 83fb04 CMP
        t209a = state.regs[3];
        t209b = 0x00000004u;
        t209r = static_cast<std::uint32_t>(t209a - t209b) & 0xffffffffu;
        batch_set_sub_flags(state, t209a, t209b, t209r, 32u);
    // 0x00927e6d: 0f83ae000000 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00927f21;
    // 0x00927e73: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t211)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t211;
    // 0x00927e75: 89542420 MOV
        t212 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t212)) return BatchLiftStatus::invalid_memory;
    // 0x00927e79: 85d2 TEST
        t213a = state.regs[2];
        t213b = state.regs[2];
        t213r = (t213a & t213b) & 0xffffffffu;
        batch_set_logic_flags(state, t213r, 32u);
    // 0x00927e7b: 74e9 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927e66;
    // 0x00927e7d: 8bc3 MOV
        t215 = state.regs[3];
        state.regs[0] = t215;
    // 0x00927e7f: c1e008 SHL
        t216a = state.regs[0];
        t216c = 8u;
        if (t216c != 0u) {
        t216r = static_cast<std::uint32_t>(t216a << t216c) & 0xffffffffu;
        batch_set_shl_flags(state, t216a, t216c, t216r, 32u);
            state.regs[0] = t216r;
        }
    // 0x00927e82: 8d7c2828 LEA
        t217 = static_cast<std::uint32_t>(state.regs[0] + state.regs[5] * 1u + 0x00000028u);
        state.regs[7] = t217;
    // 0x00927e86: be01000000 MOV
        t218 = 0x00000001u;
        state.regs[6] = t218;
    // 0x00927e8b: 85f2 TEST
    L_00927e8b:
        t219a = state.regs[2];
        t219b = state.regs[6];
        t219r = (t219a & t219b) & 0xffffffffu;
        batch_set_logic_flags(state, t219r, 32u);
    // 0x00927e8d: 750a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927e99;
    // 0x00927e8f: 90 NOP
    // 0x00927e90: 03f6 ADD
    L_00927e90:
        t222a = state.regs[6];
        t222b = state.regs[6];
        t222r = static_cast<std::uint32_t>(t222a + t222b) & 0xffffffffu;
        batch_set_add_flags(state, t222a, t222b, t222r, 32u);
        state.regs[6] = t222r;
    // 0x00927e92: 83c708 ADD
        t223a = state.regs[7];
        t223b = 0x00000008u;
        t223r = static_cast<std::uint32_t>(t223a + t223b) & 0xffffffffu;
        batch_set_add_flags(state, t223a, t223b, t223r, 32u);
        state.regs[7] = t223r;
    // 0x00927e95: 85f2 TEST
        t224a = state.regs[2];
        t224b = state.regs[6];
        t224r = (t224a & t224b) & 0xffffffffu;
        batch_set_logic_flags(state, t224r, 32u);
    // 0x00927e97: 74f7 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927e90;
    // 0x00927e99: 8b4f08 MOV
    L_00927e99:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t226)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t226;
    // 0x00927e9c: 3bcf CMP
        t227a = state.regs[1];
        t227b = state.regs[7];
        t227r = static_cast<std::uint32_t>(t227a - t227b) & 0xffffffffu;
        batch_set_sub_flags(state, t227a, t227b, t227r, 32u);
    // 0x00927e9e: 7514 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927eb4;
    // 0x00927ea0: 8bce MOV
        t229 = state.regs[6];
        state.regs[1] = t229;
    // 0x00927ea2: f7d1 NOT
        t230a = state.regs[1];
        state.regs[1] = (~t230a & 0xffffffffu);
    // 0x00927ea4: 23d1 AND
        t231a = state.regs[2];
        t231b = state.regs[1];
        t231r = (t231a & t231b) & 0xffffffffu;
        batch_set_logic_flags(state, t231r, 32u);
        state.regs[2] = t231r;
    // 0x00927ea6: 83c708 ADD
        t232a = state.regs[7];
        t232b = 0x00000008u;
        t232r = static_cast<std::uint32_t>(t232a + t232b) & 0xffffffffu;
        batch_set_add_flags(state, t232a, t232b, t232r, 32u);
        state.regs[7] = t232r;
    // 0x00927ea9: 89949d30040000 MOV
        t233 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + state.regs[3] * 4u + 0x00000430u), t233)) return BatchLiftStatus::invalid_memory;
    // 0x00927eb0: 03f6 ADD
        t234a = state.regs[6];
        t234b = state.regs[6];
        t234r = static_cast<std::uint32_t>(t234a + t234b) & 0xffffffffu;
        batch_set_add_flags(state, t234a, t234b, t234r, 32u);
        state.regs[6] = t234r;
    // 0x00927eb2: eb9f JMP
        goto L_00927e53;
    // 0x00927eb4: 8b5104 MOV
    L_00927eb4:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t236)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t236;
    // 0x00927eb7: 8b442428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t237)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t237;
    // 0x00927ebb: 8ba868040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000468u), t238)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t238;
    // 0x00927ec1: 81e2f8ffff7f AND
        t239a = state.regs[2];
        t239b = 0x7ffffff8u;
        t239r = (t239a & t239b) & 0xffffffffu;
        batch_set_logic_flags(state, t239r, 32u);
        state.regs[2] = t239r;
    // 0x00927ec7: 85ed TEST
    L_00927ec7:
        t240a = state.regs[5];
        t240b = state.regs[5];
        t240r = (t240a & t240b) & 0xffffffffu;
        batch_set_logic_flags(state, t240r, 32u);
    // 0x00927ec9: 743c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927f07;
    // 0x00927ecb: 837c241c00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t242a)) return BatchLiftStatus::invalid_memory;
        t242b = 0x00000000u;
        t242r = static_cast<std::uint32_t>(t242a - t242b) & 0xffffffffu;
        batch_set_sub_flags(state, t242a, t242b, t242r, 32u);
    // 0x00927ed0: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927edc;
    // 0x00927ed2: 8d040a LEA
        t244 = static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0x00000000u);
        state.regs[0] = t244;
    // 0x00927ed5: 3bc5 CMP
        t245a = state.regs[0];
        t245b = state.regs[5];
        t245r = static_cast<std::uint32_t>(t245a - t245b) & 0xffffffffu;
        batch_set_sub_flags(state, t245a, t245b, t245r, 32u);
    // 0x00927ed7: 0f93c0 SETNC
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((!((state.eflags & 0x001u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927eda: eb05 JMP
        goto L_00927ee1;
    // 0x00927edc: 3bcd CMP
    L_00927edc:
        t248a = state.regs[1];
        t248b = state.regs[5];
        t248r = static_cast<std::uint32_t>(t248a - t248b) & 0xffffffffu;
        batch_set_sub_flags(state, t248a, t248b, t248r, 32u);
    // 0x00927ede: 0f92c0 SETC
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((((state.eflags & 0x001u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927ee1: 84c0 TEST
    L_00927ee1:
        t250a = state.regs[0] & 0x000000ffu;
        t250b = state.regs[0] & 0x000000ffu;
        t250r = (t250a & t250b) & 0x000000ffu;
        batch_set_logic_flags(state, t250r, 8u);
    // 0x00927ee3: 7522 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927f07;
    // 0x00927ee5: 8b4908 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t252)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t252;
    // 0x00927ee8: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t253)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t253;
    // 0x00927eeb: 81e2f8ffff7f AND
        t254a = state.regs[2];
        t254b = 0x7ffffff8u;
        t254r = (t254a & t254b) & 0xffffffffu;
        batch_set_logic_flags(state, t254r, 32u);
        state.regs[2] = t254r;
    // 0x00927ef1: 3bcf CMP
        t255a = state.regs[1];
        t255b = state.regs[7];
        t255r = static_cast<std::uint32_t>(t255a - t255b) & 0xffffffffu;
        batch_set_sub_flags(state, t255a, t255b, t255r, 32u);
    // 0x00927ef3: 75d2 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927ec7;
    // 0x00927ef5: 8b542420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t257)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t257;
    // 0x00927ef9: 8b6c2428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t258)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t258;
    // 0x00927efd: 83c708 ADD
        t259a = state.regs[7];
        t259b = 0x00000008u;
        t259r = static_cast<std::uint32_t>(t259a + t259b) & 0xffffffffu;
        batch_set_add_flags(state, t259a, t259b, t259r, 32u);
        state.regs[7] = t259r;
    // 0x00927f00: 03f6 ADD
        t260a = state.regs[6];
        t260b = state.regs[6];
        t260r = static_cast<std::uint32_t>(t260a + t260b) & 0xffffffffu;
        batch_set_add_flags(state, t260a, t260b, t260r, 32u);
        state.regs[6] = t260r;
    // 0x00927f02: e950ffffff JMP
        goto L_00927e57;
    // 0x00927f07: 3bcf CMP
    L_00927f07:
        t262a = state.regs[1];
        t262b = state.regs[7];
        t262r = static_cast<std::uint32_t>(t262a - t262b) & 0xffffffffu;
        batch_set_sub_flags(state, t262a, t262b, t262r, 32u);
    // 0x00927f09: 0f85b7020000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009281c6;
    // 0x00927f0f: 8b542420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t264)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t264;
    // 0x00927f13: 8b6c2428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t265)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t265;
    // 0x00927f17: 83c708 ADD
        t266a = state.regs[7];
        t266b = 0x00000008u;
        t266r = static_cast<std::uint32_t>(t266a + t266b) & 0xffffffffu;
        batch_set_add_flags(state, t266a, t266b, t266r, 32u);
        state.regs[7] = t266r;
    // 0x00927f1a: 03f6 ADD
        t267a = state.regs[6];
        t267b = state.regs[6];
        t267r = static_cast<std::uint32_t>(t267a + t267b) & 0xffffffffu;
        batch_set_add_flags(state, t267a, t267b, t267r, 32u);
        state.regs[6] = t267r;
    // 0x00927f1c: e936ffffff JMP
        goto L_00927e57;
    // 0x00927f21: 8b8d40040000 MOV
    L_00927f21:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000440u), t269)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t269;
    // 0x00927f27: 8b4104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t270)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t270;
    // 0x00927f2a: 8b542410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t271)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t271;
    // 0x00927f2e: 25f8ffff7f AND
        t272a = state.regs[0];
        t272b = 0x7ffffff8u;
        t272r = (t272a & t272b) & 0xffffffffu;
        batch_set_logic_flags(state, t272r, 32u);
        state.regs[0] = t272r;
    // 0x00927f33: 8d7210 LEA
        t273 = static_cast<std::uint32_t>(state.regs[2] + 0x00000010u);
        state.regs[6] = t273;
    // 0x00927f36: 3bc6 CMP
        t274a = state.regs[0];
        t274b = state.regs[6];
        t274r = static_cast<std::uint32_t>(t274a - t274b) & 0xffffffffu;
        batch_set_sub_flags(state, t274a, t274b, t274r, 32u);
    // 0x00927f38: 0f83f7020000 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00928235;
    // 0x00927f3e: f6450401 TEST
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t276a)) return BatchLiftStatus::invalid_memory;
        t276b = 0x00000001u;
        t276r = (t276a & t276b) & 0x000000ffu;
        batch_set_logic_flags(state, t276r, 8u);
    // 0x00927f42: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927f5f;
    // 0x00927f44: 8bcd MOV
        t278 = state.regs[5];
        state.regs[1] = t278;
    // 0x00927f46: e8b5f7ffff CALL
        if (!batch_guest_call32(memory, state, 0x00927700u, 0x00927f4bu)) return BatchLiftStatus::invalid_memory;
        t279_call_status = spore_lift_00927700(memory, state);
        if (t279_call_status != BatchLiftStatus::returned) return t279_call_status;
        if (state.eip != 0x00927f4bu) return BatchLiftStatus::invalid_control_flow;
    // 0x00927f4b: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t280)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t280;
    // 0x00927f4f: 8b7c242c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t281)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t281;
    // 0x00927f53: c1e803 SHR
        t282a = state.regs[0];
        t282c = 3u;
        if (t282c != 0u) {
        t282r = static_cast<std::uint32_t>(t282a >> t282c);
        batch_set_shr_flags(state, t282a, t282c, t282r, 32u);
            state.regs[0] = t282r;
        }
    // 0x00927f56: 89442414 MOV
        t283 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t283)) return BatchLiftStatus::invalid_memory;
    // 0x00927f5a: e9d6fdffff JMP
        goto L_00927d35;
    // 0x00927f5f: 837c242c00 CMP
    L_00927f5f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t285a)) return BatchLiftStatus::invalid_memory;
        t285b = 0x00000000u;
        t285r = static_cast<std::uint32_t>(t285a - t285b) & 0xffffffffu;
        batch_set_sub_flags(state, t285a, t285b, t285r, 32u);
    // 0x00927f64: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927f75;
    // 0x00927f66: 81642438fffdffff AND
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t287a)) return BatchLiftStatus::invalid_memory;
        t287b = 0xfffffdffu;
        t287r = (t287a & t287b) & 0xffffffffu;
        batch_set_logic_flags(state, t287r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t287r)) return BatchLiftStatus::invalid_memory;
    // 0x00927f6e: 8bc2 MOV
        t288 = state.regs[2];
        state.regs[0] = t288;
    // 0x00927f70: e9affcffff JMP
        goto L_00927c24;
    // 0x00927f75: 80bd6d04000000 CMP
    L_00927f75:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000046du), t290a)) return BatchLiftStatus::invalid_memory;
        t290b = 0x00000000u;
        t290r = static_cast<std::uint32_t>(t290a - t290b) & 0x000000ffu;
        batch_set_sub_flags(state, t290a, t290b, t290r, 8u);
    // 0x00927f7c: 742e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927fac;
    // 0x00927f7e: 3b9594040000 CMP
        t292a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000494u), t292b)) return BatchLiftStatus::invalid_memory;
        t292r = static_cast<std::uint32_t>(t292a - t292b) & 0xffffffffu;
        batch_set_sub_flags(state, t292a, t292b, t292r, 32u);
    // 0x00927f84: 7226 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00927fac;
    // 0x00927f86: 8b8d88040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000488u), t294)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t294;
    // 0x00927f8c: 3b8d90040000 CMP
        t295a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000490u), t295b)) return BatchLiftStatus::invalid_memory;
        t295r = static_cast<std::uint32_t>(t295a - t295b) & 0xffffffffu;
        batch_set_sub_flags(state, t295a, t295b, t295r, 32u);
    // 0x00927f92: 7d18 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00927fac;
    // 0x00927f94: 8b542434 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t297)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t297;
    // 0x00927f98: 52 PUSH
        t298a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t298a)) return BatchLiftStatus::invalid_memory;
    // 0x00927f99: 8bcd MOV
        t299 = state.regs[5];
        state.regs[1] = t299;
    // 0x00927f9b: e870efffff CALL
        if (!batch_guest_call32(memory, state, 0x00926f10u, 0x00927fa0u)) return BatchLiftStatus::invalid_memory;
        t300_call_status = spore_lift_00926f10(memory, state);
        if (t300_call_status != BatchLiftStatus::returned) return t300_call_status;
        if (state.eip != 0x00927fa0u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927fa0: 89442418 MOV
        t301 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t301)) return BatchLiftStatus::invalid_memory;
    // 0x00927fa4: 85c0 TEST
        t302a = state.regs[0];
        t302b = state.regs[0];
        t302r = (t302a & t302b) & 0xffffffffu;
        batch_set_logic_flags(state, t302r, 32u);
    // 0x00927fa6: 0f85e1000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092808d;
    // 0x00927fac: 8b4c2438 MOV
    L_00927fac:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t304)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t304;
    // 0x00927fb0: f7c100000040 TEST
        t305a = state.regs[1];
        t305b = 0x40000000u;
        t305r = (t305a & t305b) & 0xffffffffu;
        batch_set_logic_flags(state, t305r, 32u);
    // 0x00927fb6: 750d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927fc5;
    // 0x00927fb8: 80bd6c04000000 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000046cu), t307a)) return BatchLiftStatus::invalid_memory;
        t307b = 0x00000000u;
        t307r = static_cast<std::uint32_t>(t307a - t307b) & 0x000000ffu;
        batch_set_sub_flags(state, t307a, t307b, t307r, 8u);
    // 0x00927fbf: 0f84d6000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092809b;
    // 0x00927fc5: 80bd6d04000000 CMP
    L_00927fc5:
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000046du), t309a)) return BatchLiftStatus::invalid_memory;
        t309b = 0x00000000u;
        t309r = static_cast<std::uint32_t>(t309a - t309b) & 0x000000ffu;
        batch_set_sub_flags(state, t309a, t309b, t309r, 8u);
    // 0x00927fcc: 7429 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927ff7;
    // 0x00927fce: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t311)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t311;
    // 0x00927fd2: 50 PUSH
        t312a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t312a)) return BatchLiftStatus::invalid_memory;
    // 0x00927fd3: 8bcd MOV
        t313 = state.regs[5];
        state.regs[1] = t313;
    // 0x00927fd5: e8e6f2ffff CALL
        if (!batch_guest_call32(memory, state, 0x009272c0u, 0x00927fdau)) return BatchLiftStatus::invalid_memory;
        t314_call_status = spore_lift_009272c0(memory, state);
        if (t314_call_status != BatchLiftStatus::returned) return t314_call_status;
        if (state.eip != 0x00927fdau) return BatchLiftStatus::invalid_control_flow;
    // 0x00927fda: 85c0 TEST
        t315a = state.regs[0];
        t315b = state.regs[0];
        t315r = (t315a & t315b) & 0xffffffffu;
        batch_set_logic_flags(state, t315r, 32u);
    // 0x00927fdc: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927ff7;
    // 0x00927fde: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t317)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t317;
    // 0x00927fe1: 81e1f8ffff7f AND
        t318a = state.regs[1];
        t318b = 0x7ffffff8u;
        t318r = (t318a & t318b) & 0xffffffffu;
        batch_set_logic_flags(state, t318r, 32u);
        state.regs[1] = t318r;
    // 0x00927fe7: 834c010401 OR
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000004u), t319a)) return BatchLiftStatus::invalid_memory;
        t319b = 0x00000001u;
        t319r = (t319a | t319b) & 0xffffffffu;
        batch_set_logic_flags(state, t319r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000004u), t319r)) return BatchLiftStatus::invalid_memory;
    // 0x00927fec: 8d4c0104 LEA
        t320 = static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000004u);
        state.regs[1] = t320;
    // 0x00927ff0: 83c008 ADD
        t321a = state.regs[0];
        t321b = 0x00000008u;
        t321r = static_cast<std::uint32_t>(t321a + t321b) & 0xffffffffu;
        batch_set_add_flags(state, t321a, t321b, t321r, 32u);
        state.regs[0] = t321r;
    // 0x00927ff3: 89442418 MOV
        t322 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t322)) return BatchLiftStatus::invalid_memory;
    // 0x00927ff7: 837c241800 CMP
    L_00927ff7:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t323a)) return BatchLiftStatus::invalid_memory;
        t323b = 0x00000000u;
        t323r = static_cast<std::uint32_t>(t323a - t323b) & 0xffffffffu;
        batch_set_sub_flags(state, t323a, t323b, t323r, 32u);
    // 0x00927ffc: 0f858b000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092808d;
    // 0x00928002: 83bdac04000000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004acu), t325a)) return BatchLiftStatus::invalid_memory;
        t325b = 0x00000000u;
        t325r = static_cast<std::uint32_t>(t325a - t325b) & 0xffffffffu;
        batch_set_sub_flags(state, t325a, t325b, t325r, 32u);
    // 0x00928009: 0f847e000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092808d;
    // 0x0092800f: 8b442424 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t327)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t327;
    // 0x00928013: 40 INC
        t328a = state.regs[0];
        t328r = static_cast<std::uint32_t>(t328a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t328a, t328r, 32u);
        state.regs[0] = t328r;
    // 0x00928014: 89442424 MOV
        t329 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t329)) return BatchLiftStatus::invalid_memory;
    // 0x00928018: 3b85b4040000 CMP
        t330a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004b4u), t330b)) return BatchLiftStatus::invalid_memory;
        t330r = static_cast<std::uint32_t>(t330a - t330b) & 0xffffffffu;
        batch_set_sub_flags(state, t330a, t330b, t330r, 32u);
    // 0x0092801e: 736d JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0092808d;
    // 0x00928020: 8b95e4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004e4u), t332)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t332;
    // 0x00928026: 8b7a18 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000018u), t333)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t333;
    // 0x00928029: 85ff TEST
        t334a = state.regs[7];
        t334b = state.regs[7];
        t334r = (t334a & t334b) & 0xffffffffu;
        batch_set_logic_flags(state, t334r, 32u);
    // 0x0092802b: 7e18 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00928045;
    // 0x0092802d: 8bf7 MOV
        t336 = state.regs[7];
        state.regs[6] = t336;
    // 0x0092802f: 90 NOP
    // 0x00928030: 8b85e4040000 MOV
    L_00928030:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004e4u), t338)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t338;
    // 0x00928036: ff4818 DEC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t339a)) return BatchLiftStatus::invalid_memory;
        t339r = static_cast<std::uint32_t>(t339a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t339a, t339r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t339r)) return BatchLiftStatus::invalid_memory;
    // 0x00928039: 50 PUSH
        t340a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t340a)) return BatchLiftStatus::invalid_memory;
    // 0x0092803a: ff15dcc23c01 CALL
        t341_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x00928040u);
        if (t341_call_status != BatchLiftStatus::returned) return t341_call_status;
        if (state.eip != 0x00928040u) return BatchLiftStatus::invalid_control_flow;
    // 0x00928040: 83ee01 SUB
        t342a = state.regs[6];
        t342b = 0x00000001u;
        t342r = static_cast<std::uint32_t>(t342a - t342b) & 0xffffffffu;
        batch_set_sub_flags(state, t342a, t342b, t342r, 32u);
        state.regs[6] = t342r;
    // 0x00928043: 75eb JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00928030;
    // 0x00928045: 8b85b0040000 MOV
    L_00928045:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004b0u), t344)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t344;
    // 0x0092804b: 8b95ac040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004acu), t345)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t345;
    // 0x00928051: 50 PUSH
        t346a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t346a)) return BatchLiftStatus::invalid_memory;
    // 0x00928052: 8b442438 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t347)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t347;
    // 0x00928056: 8d4840 LEA
        t348 = static_cast<std::uint32_t>(state.regs[0] + 0x00000040u);
        state.regs[1] = t348;
    // 0x00928059: 51 PUSH
        t349a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t349a)) return BatchLiftStatus::invalid_memory;
    // 0x0092805a: 50 PUSH
        t350a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t350a)) return BatchLiftStatus::invalid_memory;
    // 0x0092805b: 55 PUSH
        t351a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t351a)) return BatchLiftStatus::invalid_memory;
    // 0x0092805c: ffd2 CALL
        t352_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092805eu);
        if (t352_call_status != BatchLiftStatus::returned) return t352_call_status;
    // 0x0092805e: 83c410 ADD
        t353a = state.regs[4];
        t353b = 0x00000010u;
        t353r = static_cast<std::uint32_t>(t353a + t353b) & 0xffffffffu;
        batch_set_add_flags(state, t353a, t353b, t353r, 32u);
        state.regs[4] = t353r;
    // 0x00928061: 8ad8 MOV
        t354 = state.regs[0] & 0x000000ffu;
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t354 << 0u) & 0x000000ffu);
    // 0x00928063: 85ff TEST
        t355a = state.regs[7];
        t355b = state.regs[7];
        t355r = (t355a & t355b) & 0xffffffffu;
        batch_set_logic_flags(state, t355r, 32u);
    // 0x00928065: 7e1e JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00928085;
    // 0x00928067: eb07 JMP
        goto L_00928070;
    // 0x00928070: 8bb5e4040000 MOV
    L_00928070:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004e4u), t358)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t358;
    // 0x00928076: 56 PUSH
        t359a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t359a)) return BatchLiftStatus::invalid_memory;
    // 0x00928077: ff15d8c23c01 CALL
        t360_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x0092807du);
        if (t360_call_status != BatchLiftStatus::returned) return t360_call_status;
        if (state.eip != 0x0092807du) return BatchLiftStatus::invalid_control_flow;
    // 0x0092807d: ff4618 INC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t361a)) return BatchLiftStatus::invalid_memory;
        t361r = static_cast<std::uint32_t>(t361a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t361a, t361r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t361r)) return BatchLiftStatus::invalid_memory;
    // 0x00928080: 83ef01 SUB
        t362a = state.regs[7];
        t362b = 0x00000001u;
        t362r = static_cast<std::uint32_t>(t362a - t362b) & 0xffffffffu;
        batch_set_sub_flags(state, t362a, t362b, t362r, 32u);
        state.regs[7] = t362r;
    // 0x00928083: 75eb JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00928070;
    // 0x00928085: 84db TEST
    L_00928085:
        t364a = state.regs[3] & 0x000000ffu;
        t364b = state.regs[3] & 0x000000ffu;
        t364r = (t364a & t364b) & 0x000000ffu;
        batch_set_logic_flags(state, t364r, 8u);
    // 0x00928087: 0f8593fbffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927c20;
    // 0x0092808d: 8b442418 MOV
    L_0092808d:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t366)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t366;
    // 0x00928091: 5f POP
        if (!memory.load32(state.regs[4], t367a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t367a;
    // 0x00928092: 5e POP
        if (!memory.load32(state.regs[4], t368a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t368a;
    // 0x00928093: 5d POP
        if (!memory.load32(state.regs[4], t369a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t369a;
    // 0x00928094: 5b POP
        if (!memory.load32(state.regs[4], t370a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t370a;
    // 0x00928095: 83c420 ADD
        t371a = state.regs[4];
        t371b = 0x00000020u;
        t371r = static_cast<std::uint32_t>(t371a + t371b) & 0xffffffffu;
        batch_set_add_flags(state, t371a, t371b, t371r, 32u);
        state.regs[4] = t371r;
    // 0x00928098: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092809b: 33c0 XOR
    L_0092809b:
        t373a = state.regs[0];
        t373b = state.regs[0];
        t373r = (t373a ^ t373b) & 0xffffffffu;
        batch_set_logic_flags(state, t373r, 32u);
        state.regs[0] = t373r;
    // 0x0092809d: 81c900000040 OR
        t374a = state.regs[1];
        t374b = 0x40000000u;
        t374r = (t374a | t374b) & 0xffffffffu;
        batch_set_logic_flags(state, t374r, 32u);
        state.regs[1] = t374r;
    // 0x009280a3: 3944241c CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t375a)) return BatchLiftStatus::invalid_memory;
        t375b = state.regs[0];
        t375r = static_cast<std::uint32_t>(t375a - t375b) & 0xffffffffu;
        batch_set_sub_flags(state, t375a, t375b, t375r, 32u);
    // 0x009280a7: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009280ae;
    // 0x009280a9: 83e1fc AND
        t377a = state.regs[1];
        t377b = 0xfffffffcu;
        t377r = (t377a & t377b) & 0xffffffffu;
        batch_set_logic_flags(state, t377r, 32u);
        state.regs[1] = t377r;
    // 0x009280ac: eb03 JMP
        goto L_009280b1;
    // 0x009280ae: 83c901 OR
    L_009280ae:
        t379a = state.regs[1];
        t379b = 0x00000001u;
        t379r = (t379a | t379b) & 0xffffffffu;
        batch_set_logic_flags(state, t379r, 32u);
        state.regs[1] = t379r;
    // 0x009280b1: 894c2438 MOV
    L_009280b1:
        t380 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t380)) return BatchLiftStatus::invalid_memory;
    // 0x009280b5: 89442414 MOV
        t381 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t381)) return BatchLiftStatus::invalid_memory;
    // 0x009280b9: 89442424 MOV
        t382 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t382)) return BatchLiftStatus::invalid_memory;
    // 0x009280bd: 89442418 MOV
        t383 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t383)) return BatchLiftStatus::invalid_memory;
    // 0x009280c1: f6c108 TEST
        t384a = state.regs[1] & 0x000000ffu;
        t384b = 0x00000008u;
        t384r = (t384a & t384b) & 0x000000ffu;
        batch_set_logic_flags(state, t384r, 8u);
    // 0x009280c4: 0f8456fbffff JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927c20;
    // 0x009280ca: 8b442434 MOV
    L_009280ca:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t386)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t386;
    // 0x009280ce: 50 PUSH
        t387a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t387a)) return BatchLiftStatus::invalid_memory;
    // 0x009280cf: 8bcd MOV
        t388 = state.regs[5];
        state.regs[1] = t388;
    // 0x009280d1: e83aeeffff CALL
        if (!batch_guest_call32(memory, state, 0x00926f10u, 0x009280d6u)) return BatchLiftStatus::invalid_memory;
        t389_call_status = spore_lift_00926f10(memory, state);
        if (t389_call_status != BatchLiftStatus::returned) return t389_call_status;
        if (state.eip != 0x009280d6u) return BatchLiftStatus::invalid_control_flow;
    // 0x009280d6: 5f POP
        if (!memory.load32(state.regs[4], t390a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t390a;
    // 0x009280d7: 5e POP
        if (!memory.load32(state.regs[4], t391a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t391a;
    // 0x009280d8: 5d POP
        if (!memory.load32(state.regs[4], t392a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t392a;
    // 0x009280d9: 5b POP
        if (!memory.load32(state.regs[4], t393a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t393a;
    // 0x009280da: 83c420 ADD
        t394a = state.regs[4];
        t394b = 0x00000020u;
        t394r = static_cast<std::uint32_t>(t394a + t394b) & 0xffffffffu;
        batch_set_add_flags(state, t394a, t394b, t394r, 32u);
        state.regs[4] = t394r;
    // 0x009280dd: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009280e0: 8b410c MOV
    L_009280e0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t396)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t396;
    // 0x009280e3: 816104fbffff7f AND
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t397a)) return BatchLiftStatus::invalid_memory;
        t397b = 0x7ffffffbu;
        t397r = (t397a & t397b) & 0xffffffffu;
        batch_set_logic_flags(state, t397r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t397r)) return BatchLiftStatus::invalid_memory;
    // 0x009280ea: 5f POP
        if (!memory.load32(state.regs[4], t398a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t398a;
    // 0x009280eb: 5e POP
        if (!memory.load32(state.regs[4], t399a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t399a;
    // 0x009280ec: 5d POP
        if (!memory.load32(state.regs[4], t400a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t400a;
    // 0x009280ed: 8902 MOV
        t401 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t401)) return BatchLiftStatus::invalid_memory;
    // 0x009280ef: 8d4108 LEA
        t402 = static_cast<std::uint32_t>(state.regs[1] + 0x00000008u);
        state.regs[0] = t402;
    // 0x009280f2: 5b POP
        if (!memory.load32(state.regs[4], t403a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t403a;
    // 0x009280f3: 83c420 ADD
        t404a = state.regs[4];
        t404b = 0x00000020u;
        t404r = static_cast<std::uint32_t>(t404a + t404b) & 0xffffffffu;
        batch_set_add_flags(state, t404a, t404b, t404r, 32u);
        state.regs[4] = t404r;
    // 0x009280f6: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009280f9: 8b7108 MOV
    L_009280f9:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t406)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t406;
    // 0x009280fc: 8b790c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t407)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t407;
    // 0x009280ff: 8d4108 LEA
        t408 = static_cast<std::uint32_t>(state.regs[1] + 0x00000008u);
        state.regs[0] = t408;
    // 0x00928102: 897e0c MOV
        t409 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t409)) return BatchLiftStatus::invalid_memory;
    // 0x00928105: 8b710c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t410)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t410;
    // 0x00928108: 8b38 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t411)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t411;
    // 0x0092810a: 897e08 MOV
        t412 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t412)) return BatchLiftStatus::invalid_memory;
    // 0x0092810d: 8b7c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t413)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t413;
    // 0x00928111: 8bf2 MOV
        t414 = state.regs[2];
        state.regs[6] = t414;
    // 0x00928113: 2bf7 SUB
        t415a = state.regs[6];
        t415b = state.regs[7];
        t415r = static_cast<std::uint32_t>(t415a - t415b) & 0xffffffffu;
        batch_set_sub_flags(state, t415a, t415b, t415r, 32u);
        state.regs[6] = t415r;
    // 0x00928115: 89442438 MOV
        t416 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t416)) return BatchLiftStatus::invalid_memory;
    // 0x00928119: 83fe10 CMP
        t417a = state.regs[6];
        t417b = 0x00000010u;
        t417r = static_cast<std::uint32_t>(t417a - t417b) & 0xffffffffu;
        batch_set_sub_flags(state, t417a, t417b, t417r, 32u);
    // 0x0092811c: 730f JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0092812d;
    // 0x0092811e: 834c0a0401 OR
    L_0092811e:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0x00000004u), t419a)) return BatchLiftStatus::invalid_memory;
        t419b = 0x00000001u;
        t419r = (t419a | t419b) & 0xffffffffu;
        batch_set_logic_flags(state, t419r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0x00000004u), t419r)) return BatchLiftStatus::invalid_memory;
    // 0x00928123: 5f POP
        if (!memory.load32(state.regs[4], t420a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t420a;
    // 0x00928124: 5e POP
        if (!memory.load32(state.regs[4], t421a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t421a;
    // 0x00928125: 5d POP
        if (!memory.load32(state.regs[4], t422a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t422a;
    // 0x00928126: 5b POP
        if (!memory.load32(state.regs[4], t423a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t423a;
    // 0x00928127: 83c420 ADD
        t424a = state.regs[4];
        t424b = 0x00000020u;
        t424r = static_cast<std::uint32_t>(t424a + t424b) & 0xffffffffu;
        batch_set_add_flags(state, t424a, t424b, t424r, 32u);
        state.regs[4] = t424r;
    // 0x0092812a: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092812d: 8b453c MOV
    L_0092812d:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000003cu), t426)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t426;
    // 0x00928130: 8d1439 LEA
        t427 = static_cast<std::uint32_t>(state.regs[1] + state.regs[7] * 1u + 0x00000000u);
        state.regs[2] = t427;
    // 0x00928133: 8d5d30 LEA
        t428 = static_cast<std::uint32_t>(state.regs[5] + 0x00000030u);
        state.regs[3] = t428;
    // 0x00928136: 89420c MOV
        t429 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t429)) return BatchLiftStatus::invalid_memory;
    // 0x00928139: 895a08 MOV
        t430 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t430)) return BatchLiftStatus::invalid_memory;
    // 0x0092813c: 89530c MOV
        t431 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x0000000cu), t431)) return BatchLiftStatus::invalid_memory;
    // 0x0092813f: 895008 MOV
        t432 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t432)) return BatchLiftStatus::invalid_memory;
    // 0x00928142: 899544040000 MOV
        t433 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000444u), t433)) return BatchLiftStatus::invalid_memory;
    // 0x00928148: 83cf01 OR
        t434a = state.regs[7];
        t434b = 0x00000001u;
        t434r = (t434a | t434b) & 0xffffffffu;
        batch_set_logic_flags(state, t434r, 32u);
        state.regs[7] = t434r;
    // 0x0092814b: 8bc6 MOV
        t435 = state.regs[6];
        state.regs[0] = t435;
    // 0x0092814d: 897904 MOV
        t436 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t436)) return BatchLiftStatus::invalid_memory;
    // 0x00928150: 83c801 OR
        t437a = state.regs[0];
        t437b = 0x00000001u;
        t437r = (t437a | t437b) & 0xffffffffu;
        batch_set_logic_flags(state, t437r, 32u);
        state.regs[0] = t437r;
    // 0x00928153: 5f POP
        if (!memory.load32(state.regs[4], t438a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t438a;
    // 0x00928154: 894204 MOV
        t439 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t439)) return BatchLiftStatus::invalid_memory;
    // 0x00928157: 8b442434 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t440)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t440;
    // 0x0092815b: 893432 MOV
        t441 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + state.regs[6] * 1u + 0x00000000u), t441)) return BatchLiftStatus::invalid_memory;
    // 0x0092815e: 5e POP
        if (!memory.load32(state.regs[4], t442a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t442a;
    // 0x0092815f: 5d POP
        if (!memory.load32(state.regs[4], t443a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t443a;
    // 0x00928160: 5b POP
        if (!memory.load32(state.regs[4], t444a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t444a;
    // 0x00928161: 83c420 ADD
        t445a = state.regs[4];
        t445b = 0x00000020u;
        t445r = static_cast<std::uint32_t>(t445a + t445b) & 0xffffffffu;
        batch_set_add_flags(state, t445a, t445b, t445r, 32u);
        state.regs[4] = t445r;
    // 0x00928164: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00928167: 834c0a0401 OR
    L_00928167:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0x00000004u), t447a)) return BatchLiftStatus::invalid_memory;
        t447b = 0x00000001u;
        t447r = (t447a | t447b) & 0xffffffffu;
        batch_set_logic_flags(state, t447r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0x00000004u), t447r)) return BatchLiftStatus::invalid_memory;
    // 0x0092816c: 5f POP
        if (!memory.load32(state.regs[4], t448a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t448a;
    // 0x0092816d: 5e POP
        if (!memory.load32(state.regs[4], t449a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t449a;
    // 0x0092816e: 5d POP
        if (!memory.load32(state.regs[4], t450a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t450a;
    // 0x0092816f: 8d4108 LEA
        t451 = static_cast<std::uint32_t>(state.regs[1] + 0x00000008u);
        state.regs[0] = t451;
    // 0x00928172: 5b POP
        if (!memory.load32(state.regs[4], t452a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t452a;
    // 0x00928173: 83c420 ADD
        t453a = state.regs[4];
        t453b = 0x00000020u;
        t453r = static_cast<std::uint32_t>(t453a + t453b) & 0xffffffffu;
        batch_set_add_flags(state, t453a, t453b, t453r, 32u);
        state.regs[4] = t453r;
    // 0x00928176: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00928179: 8b7108 MOV
    L_00928179:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t455)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t455;
    // 0x0092817c: 8b790c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t456)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t456;
    // 0x0092817f: 8d4108 LEA
        t457 = static_cast<std::uint32_t>(state.regs[1] + 0x00000008u);
        state.regs[0] = t457;
    // 0x00928182: 897e0c MOV
        t458 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t458)) return BatchLiftStatus::invalid_memory;
    // 0x00928185: 8b710c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t459)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t459;
    // 0x00928188: 8b38 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t460)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t460;
    // 0x0092818a: 897e08 MOV
        t461 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t461)) return BatchLiftStatus::invalid_memory;
    // 0x0092818d: 8bf2 MOV
        t462 = state.regs[2];
        state.regs[6] = t462;
    // 0x0092818f: 2bf3 SUB
        t463a = state.regs[6];
        t463b = state.regs[3];
        t463r = static_cast<std::uint32_t>(t463a - t463b) & 0xffffffffu;
        batch_set_sub_flags(state, t463a, t463b, t463r, 32u);
        state.regs[6] = t463r;
    // 0x00928191: 83fe10 CMP
        t464a = state.regs[6];
        t464b = 0x00000010u;
        t464r = static_cast<std::uint32_t>(t464a - t464b) & 0xffffffffu;
        batch_set_sub_flags(state, t464a, t464b, t464r, 32u);
    // 0x00928194: 7288 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0092811e;
    // 0x00928196: 8b7d3c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000003cu), t466)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t466;
    // 0x00928199: 8d1419 LEA
        t467 = static_cast<std::uint32_t>(state.regs[1] + state.regs[3] * 1u + 0x00000000u);
        state.regs[2] = t467;
    // 0x0092819c: 83c530 ADD
        t468a = state.regs[5];
        t468b = 0x00000030u;
        t468r = static_cast<std::uint32_t>(t468a + t468b) & 0xffffffffu;
        batch_set_add_flags(state, t468a, t468b, t468r, 32u);
        state.regs[5] = t468r;
    // 0x0092819f: 896a08 MOV
        t469 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t469)) return BatchLiftStatus::invalid_memory;
    // 0x009281a2: 897a0c MOV
        t470 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t470)) return BatchLiftStatus::invalid_memory;
    // 0x009281a5: 89550c MOV
        t471 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t471)) return BatchLiftStatus::invalid_memory;
    // 0x009281a8: 895708 MOV
        t472 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t472)) return BatchLiftStatus::invalid_memory;
    // 0x009281ab: 83cb01 OR
        t473a = state.regs[3];
        t473b = 0x00000001u;
        t473r = (t473a | t473b) & 0xffffffffu;
        batch_set_logic_flags(state, t473r, 32u);
        state.regs[3] = t473r;
    // 0x009281ae: 895904 MOV
        t474 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t474)) return BatchLiftStatus::invalid_memory;
    // 0x009281b1: 8bce MOV
        t475 = state.regs[6];
        state.regs[1] = t475;
    // 0x009281b3: 83c901 OR
        t476a = state.regs[1];
        t476b = 0x00000001u;
        t476r = (t476a | t476b) & 0xffffffffu;
        batch_set_logic_flags(state, t476r, 32u);
        state.regs[1] = t476r;
    // 0x009281b6: 5f POP
        if (!memory.load32(state.regs[4], t477a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t477a;
    // 0x009281b7: 894a04 MOV
        t478 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t478)) return BatchLiftStatus::invalid_memory;
    // 0x009281ba: 893432 MOV
        t479 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + state.regs[6] * 1u + 0x00000000u), t479)) return BatchLiftStatus::invalid_memory;
    // 0x009281bd: 5e POP
        if (!memory.load32(state.regs[4], t480a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t480a;
    // 0x009281be: 5d POP
        if (!memory.load32(state.regs[4], t481a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t481a;
    // 0x009281bf: 5b POP
        if (!memory.load32(state.regs[4], t482a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t482a;
    // 0x009281c0: 83c420 ADD
        t483a = state.regs[4];
        t483b = 0x00000020u;
        t483r = static_cast<std::uint32_t>(t483a + t483b) & 0xffffffffu;
        batch_set_add_flags(state, t483a, t483b, t483r, 32u);
        state.regs[4] = t483r;
    // 0x009281c3: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009281c6: 8b7108 MOV
    L_009281c6:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t485)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t485;
    // 0x009281c9: 8b790c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t486)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t486;
    // 0x009281cc: 8d4108 LEA
        t487 = static_cast<std::uint32_t>(state.regs[1] + 0x00000008u);
        state.regs[0] = t487;
    // 0x009281cf: 897e0c MOV
        t488 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t488)) return BatchLiftStatus::invalid_memory;
    // 0x009281d2: 8b710c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t489)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t489;
    // 0x009281d5: 8b38 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t490)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t490;
    // 0x009281d7: 897e08 MOV
        t491 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t491)) return BatchLiftStatus::invalid_memory;
    // 0x009281da: 8b742410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t492)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t492;
    // 0x009281de: 8bfa MOV
        t493 = state.regs[2];
        state.regs[7] = t493;
    // 0x009281e0: 2bfe SUB
        t494a = state.regs[7];
        t494b = state.regs[6];
        t494r = static_cast<std::uint32_t>(t494a - t494b) & 0xffffffffu;
        batch_set_sub_flags(state, t494a, t494b, t494r, 32u);
        state.regs[7] = t494r;
    // 0x009281e2: 89442438 MOV
        t495 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t495)) return BatchLiftStatus::invalid_memory;
    // 0x009281e6: 83ff10 CMP
        t496a = state.regs[7];
        t496b = 0x00000010u;
        t496r = static_cast<std::uint32_t>(t496a - t496b) & 0xffffffffu;
        batch_set_sub_flags(state, t496a, t496b, t496r, 32u);
    // 0x009281e9: 0f822fffffff JC
        if (((state.eflags & 0x001u) != 0u)) goto L_0092811e;
    // 0x009281ef: 8b442428 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t498)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t498;
    // 0x009281f3: 8b683c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000003cu), t499)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t499;
    // 0x009281f6: 8d5830 LEA
        t500 = static_cast<std::uint32_t>(state.regs[0] + 0x00000030u);
        state.regs[3] = t500;
    // 0x009281f9: 8d1431 LEA
        t501 = static_cast<std::uint32_t>(state.regs[1] + state.regs[6] * 1u + 0x00000000u);
        state.regs[2] = t501;
    // 0x009281fc: 895a08 MOV
        t502 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t502)) return BatchLiftStatus::invalid_memory;
    // 0x009281ff: 896a0c MOV
        t503 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t503)) return BatchLiftStatus::invalid_memory;
    // 0x00928202: 89530c MOV
        t504 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x0000000cu), t504)) return BatchLiftStatus::invalid_memory;
    // 0x00928205: 895508 MOV
        t505 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t505)) return BatchLiftStatus::invalid_memory;
    // 0x00928208: 81fe00020000 CMP
        t506a = state.regs[6];
        t506b = 0x00000200u;
        t506r = static_cast<std::uint32_t>(t506a - t506b) & 0xffffffffu;
        batch_set_sub_flags(state, t506a, t506b, t506r, 32u);
    // 0x0092820e: 7306 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00928216;
    // 0x00928210: 899044040000 MOV
        t508 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000444u), t508)) return BatchLiftStatus::invalid_memory;
    // 0x00928216: 83ce01 OR
    L_00928216:
        t509a = state.regs[6];
        t509b = 0x00000001u;
        t509r = (t509a | t509b) & 0xffffffffu;
        batch_set_logic_flags(state, t509r, 32u);
        state.regs[6] = t509r;
    // 0x00928219: 8bc7 MOV
        t510 = state.regs[7];
        state.regs[0] = t510;
    // 0x0092821b: 897104 MOV
        t511 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t511)) return BatchLiftStatus::invalid_memory;
    // 0x0092821e: 83c801 OR
        t512a = state.regs[0];
        t512b = 0x00000001u;
        t512r = (t512a | t512b) & 0xffffffffu;
        batch_set_logic_flags(state, t512r, 32u);
        state.regs[0] = t512r;
    // 0x00928221: 894204 MOV
        t513 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t513)) return BatchLiftStatus::invalid_memory;
    // 0x00928224: 8b442438 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t514)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t514;
    // 0x00928228: 893c3a MOV
        t515 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + state.regs[7] * 1u + 0x00000000u), t515)) return BatchLiftStatus::invalid_memory;
    // 0x0092822b: 5f POP
        if (!memory.load32(state.regs[4], t516a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t516a;
    // 0x0092822c: 5e POP
        if (!memory.load32(state.regs[4], t517a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t517a;
    // 0x0092822d: 5d POP
        if (!memory.load32(state.regs[4], t518a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t518a;
    // 0x0092822e: 5b POP
        if (!memory.load32(state.regs[4], t519a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t519a;
    // 0x0092822f: 83c420 ADD
        t520a = state.regs[4];
        t520b = 0x00000020u;
        t520r = static_cast<std::uint32_t>(t520a + t520b) & 0xffffffffu;
        batch_set_add_flags(state, t520a, t520b, t520r, 32u);
        state.regs[4] = t520r;
    // 0x00928232: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00928235: 837c241c00 CMP
    L_00928235:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t522a)) return BatchLiftStatus::invalid_memory;
        t522b = 0x00000000u;
        t522r = static_cast<std::uint32_t>(t522a - t522b) & 0xffffffffu;
        batch_set_sub_flags(state, t522a, t522b, t522r, 32u);
    // 0x0092823a: 743c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00928278;
    // 0x0092823c: 8bf1 MOV
        t524 = state.regs[1];
        state.regs[6] = t524;
    // 0x0092823e: 2bca SUB
        t525a = state.regs[1];
        t525b = state.regs[2];
        t525r = static_cast<std::uint32_t>(t525a - t525b) & 0xffffffffu;
        batch_set_sub_flags(state, t525a, t525b, t525r, 32u);
        state.regs[1] = t525r;
    // 0x00928240: 03c8 ADD
        t526a = state.regs[1];
        t526b = state.regs[0];
        t526r = static_cast<std::uint32_t>(t526a + t526b) & 0xffffffffu;
        batch_set_add_flags(state, t526a, t526b, t526r, 32u);
        state.regs[1] = t526r;
    // 0x00928242: f6c107 TEST
        t527a = state.regs[1] & 0x000000ffu;
        t527b = 0x00000007u;
        t527r = (t527a & t527b) & 0x000000ffu;
        batch_set_logic_flags(state, t527r, 8u);
    // 0x00928245: 7515 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092825c;
    // 0x00928247: 2bc2 SUB
        t529a = state.regs[0];
        t529b = state.regs[2];
        t529r = static_cast<std::uint32_t>(t529a - t529b) & 0xffffffffu;
        batch_set_sub_flags(state, t529a, t529b, t529r, 32u);
        state.regs[0] = t529r;
    // 0x00928249: 8bf8 MOV
        t530 = state.regs[0];
        state.regs[7] = t530;
    // 0x0092824b: 895104 MOV
        t531 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t531)) return BatchLiftStatus::invalid_memory;
    // 0x0092824e: 834c110401 OR
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000004u), t532a)) return BatchLiftStatus::invalid_memory;
        t532b = 0x00000001u;
        t532r = (t532a | t532b) & 0xffffffffu;
        batch_set_logic_flags(state, t532r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000004u), t532r)) return BatchLiftStatus::invalid_memory;
    // 0x00928253: 8d441104 LEA
        t533 = static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000004u);
        state.regs[0] = t533;
    // 0x00928257: 891411 MOV
        t534 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000000u), t534)) return BatchLiftStatus::invalid_memory;
    // 0x0092825a: eb33 JMP
        goto L_0092828f;
    // 0x0092825c: 83e1f8 AND
    L_0092825c:
        t536a = state.regs[1];
        t536b = 0xfffffff8u;
        t536r = (t536a & t536b) & 0xffffffffu;
        batch_set_logic_flags(state, t536r, 32u);
        state.regs[1] = t536r;
    // 0x0092825f: 8bf9 MOV
        t537 = state.regs[1];
        state.regs[7] = t537;
    // 0x00928261: 2bfe SUB
        t538a = state.regs[7];
        t538b = state.regs[6];
        t538r = static_cast<std::uint32_t>(t538a - t538b) & 0xffffffffu;
        batch_set_sub_flags(state, t538a, t538b, t538r, 32u);
        state.regs[7] = t538r;
    // 0x00928263: 2bc7 SUB
        t539a = state.regs[0];
        t539b = state.regs[7];
        t539r = static_cast<std::uint32_t>(t539a - t539b) & 0xffffffffu;
        batch_set_sub_flags(state, t539a, t539b, t539r, 32u);
        state.regs[0] = t539r;
    // 0x00928265: 8bd0 MOV
        t540 = state.regs[0];
        state.regs[2] = t540;
    // 0x00928267: 895104 MOV
        t541 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t541)) return BatchLiftStatus::invalid_memory;
    // 0x0092826a: 834c110401 OR
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000004u), t542a)) return BatchLiftStatus::invalid_memory;
        t542b = 0x00000001u;
        t542r = (t542a | t542b) & 0xffffffffu;
        batch_set_logic_flags(state, t542r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000004u), t542r)) return BatchLiftStatus::invalid_memory;
    // 0x0092826f: 8d441104 LEA
        t543 = static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000004u);
        state.regs[0] = t543;
    // 0x00928273: 891411 MOV
        t544 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000000u), t544)) return BatchLiftStatus::invalid_memory;
    // 0x00928276: eb17 JMP
        goto L_0092828f;
    // 0x00928278: 2bc2 SUB
    L_00928278:
        t546a = state.regs[0];
        t546b = state.regs[2];
        t546r = static_cast<std::uint32_t>(t546a - t546b) & 0xffffffffu;
        batch_set_sub_flags(state, t546a, t546b, t546r, 32u);
        state.regs[0] = t546r;
    // 0x0092827a: 8bf8 MOV
        t547 = state.regs[0];
        state.regs[7] = t547;
    // 0x0092827c: 8bc2 MOV
        t548 = state.regs[2];
        state.regs[0] = t548;
    // 0x0092827e: 8d3411 LEA
        t549 = static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000000u);
        state.regs[6] = t549;
    // 0x00928281: 83c801 OR
        t550a = state.regs[0];
        t550b = 0x00000001u;
        t550r = (t550a | t550b) & 0xffffffffu;
        batch_set_logic_flags(state, t550r, 32u);
        state.regs[0] = t550r;
    // 0x00928284: 8bd7 MOV
        t551 = state.regs[7];
        state.regs[2] = t551;
    // 0x00928286: 83ca01 OR
        t552a = state.regs[2];
        t552b = 0x00000001u;
        t552r = (t552a | t552b) & 0xffffffffu;
        batch_set_logic_flags(state, t552r, 32u);
        state.regs[2] = t552r;
    // 0x00928289: 894104 MOV
        t553 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t553)) return BatchLiftStatus::invalid_memory;
    // 0x0092828c: 895604 MOV
        t554 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t554)) return BatchLiftStatus::invalid_memory;
    // 0x0092828f: 89b540040000 MOV
    L_0092828f:
        t555 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000440u), t555)) return BatchLiftStatus::invalid_memory;
    // 0x00928295: 8bc7 MOV
        t556 = state.regs[7];
        state.regs[0] = t556;
    // 0x00928297: 83c801 OR
        t557a = state.regs[0];
        t557b = 0x00000001u;
        t557r = (t557a | t557b) & 0xffffffffu;
        batch_set_logic_flags(state, t557r, 32u);
        state.regs[0] = t557r;
    // 0x0092829a: 89760c MOV
        t558 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t558)) return BatchLiftStatus::invalid_memory;
    // 0x0092829d: 897608 MOV
        t559 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t559)) return BatchLiftStatus::invalid_memory;
    // 0x009282a0: 894604 MOV
        t560 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t560)) return BatchLiftStatus::invalid_memory;
    // 0x009282a3: 893c37 MOV
        t561 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + state.regs[6] * 1u + 0x00000000u), t561)) return BatchLiftStatus::invalid_memory;
    // 0x009282a6: 80bd6c04000000 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000046cu), t562a)) return BatchLiftStatus::invalid_memory;
        t562b = 0x00000000u;
        t562r = static_cast<std::uint32_t>(t562a - t562b) & 0x000000ffu;
        batch_set_sub_flags(state, t562a, t562b, t562r, 8u);
    // 0x009282ad: 7519 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009282c8;
    // 0x009282af: 8b8540040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000440u), t564)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t564;
    // 0x009282b5: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t565)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t565;
    // 0x009282b8: d1ea SHR
        t566a = state.regs[2];
        t566c = 1u;
        if (t566c != 0u) {
        t566r = static_cast<std::uint32_t>(t566a >> t566c);
        batch_set_shr_flags(state, t566a, t566c, t566r, 32u);
            state.regs[2] = t566r;
        }
    // 0x009282ba: 81e2fcffff3f AND
        t567a = state.regs[2];
        t567b = 0x3ffffffcu;
        t567r = (t567a & t567b) & 0xffffffffu;
        batch_set_logic_flags(state, t567r, 32u);
        state.regs[2] = t567r;
    // 0x009282c0: 03d0 ADD
        t568a = state.regs[2];
        t568b = state.regs[0];
        t568r = static_cast<std::uint32_t>(t568a + t568b) & 0xffffffffu;
        batch_set_add_flags(state, t568a, t568b, t568r, 32u);
        state.regs[2] = t568r;
    // 0x009282c2: 899568040000 MOV
        t569 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000468u), t569)) return BatchLiftStatus::invalid_memory;
    // 0x009282c8: 5f POP
    L_009282c8:
        if (!memory.load32(state.regs[4], t570a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t570a;
    // 0x009282c9: 5e POP
        if (!memory.load32(state.regs[4], t571a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t571a;
    // 0x009282ca: 5d POP
        if (!memory.load32(state.regs[4], t572a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t572a;
    // 0x009282cb: 8d4108 LEA
        t573 = static_cast<std::uint32_t>(state.regs[1] + 0x00000008u);
        state.regs[0] = t573;
    // 0x009282ce: 5b POP
        if (!memory.load32(state.regs[4], t574a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t574a;
    // 0x009282cf: 83c420 ADD
        t575a = state.regs[4];
        t575b = 0x00000020u;
        t575r = static_cast<std::uint32_t>(t575a + t575b) & 0xffffffffu;
        batch_set_add_flags(state, t575a, t575b, t575r, 32u);
        state.regs[4] = t575r;
    // 0x009282d2: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
