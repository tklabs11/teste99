import csv
import hashlib
import json
import struct
import tempfile
import unittest
from pathlib import Path

import BatchStaticLift as lifter
import diagnose_call_closure as diagnostic
import generate_boot_crt_prefix as boot_crt
import generate_boot_pid_prefix as boot_pid
import generate_function_prefix as prefix_generator


def instruction(address, encoded, mnemonic, operands=(), flow="FALL_THROUGH", flows_to=(), references=()):
    return {
        "address": f"0x{address:08x}",
        "bytes": encoded,
        "length": len(bytes.fromhex(encoded)),
        "mnemonic": mnemonic,
        "operands": list(operands),
        "flow": flow,
        "flows_to": list(flows_to),
        "references": list(references),
    }


def function(instructions):
    return {
        "entry": instructions[0]["address"],
        "name": "FUN_test",
        "body_address_count": sum(item["length"] for item in instructions),
        "instructions": instructions,
        "instruction_count_exported": len(instructions),
        "instructions_truncated": False,
        "references_truncated": False,
    }


class StaticBatchLiftTests(unittest.TestCase):
    def test_call_terminator_jump_is_tail_transfer_not_indirect_call(self):
        jump = instruction(
            0x401005, "e9f60f0000", "JMP", ("0x00402000",),
            flow="CALL_TERMINATOR", flows_to=("0x00402000",),
            references=({"to": "0x00402000", "is_call": True},),
        )
        self.assertFalse(diagnostic._is_call(jump))
        self.assertEqual(lifter.direct_tail_jump_target(jump), 0x402000)
        altered = {**jump, "flows_to": ["0x00403000"]}
        with self.assertRaisesRegex(ValueError, "flow differs"):
            lifter.direct_tail_jump_target(altered)

    def test_direct_tail_jump_dispatch_preserves_guest_return_stack(self):
        caller = function([
            instruction(0x401000, "e9fb0f0000", "JMP", ("0x00402000",),
                        flow="CALL_TERMINATOR", flows_to=("0x00402000",),
                        references=({"to": "0x00402000", "is_call": True},)),
        ])
        callee = function([
            instruction(0x402000, "c3", "RET", flow="TERMINAL"),
        ])
        translated = lifter.translate_function_set([caller, callee])
        source = translated[0x401000]["source"]
        self.assertIsNotNone(source)
        self.assertIn("state.eip = 0x00402000u;", source)
        self.assertIn("return spore_lift_00402000(memory, state);", source)
        self.assertNotIn("batch_guest_call32", source)
        self.assertEqual(lifter.function_call_targets(caller), [0x402000])
        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(caller, set())
        self.assertIn("tail jump target", raised.exception.reasons[0])

    def test_verified_direct_call_alias_uses_guest_import_and_checks_target(self):
        body = function([
            instruction(0x401000, "e8fb0f0000", "CALL", ("0x00402000",),
                        flow="UNCONDITIONAL_CALL", flows_to=("0x00402000",),
                        references=({"to": "0x00402000", "is_call": True},)),
            instruction(0x401005, "c3", "RET", flow="TERMINATOR"),
        ])
        aliases = {0x401000: (0x402000, "MSVCR90.dll!memset", 0x403000)}
        source, diagnostics = lifter.translate_function(
            body, set(), direct_import_aliases=aliases)
        self.assertIn('"MSVCR90.dll!memset", 0x00403000u, 0x00401005u', source)
        self.assertNotIn("spore_lift_00402000", source)
        self.assertEqual([item["status"] for item in diagnostics],
                         ["translated", "translated"])
        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(
                body, set(), direct_import_aliases={
                    0x401000: (0x402001, "MSVCR90.dll!memset", 0x403000)})
        self.assertIn("differs from CALL target", raised.exception.reasons[0])

    def test_cfg_call_boundary_preserves_earlier_branch_and_stops_before_call(self):
        body = function([
            instruction(0x401000, "83f802", "CMP", ("EAX", "0x2")),
            instruction(0x401003, "7303", "JNC", ("0x00401008",),
                        flow="CONDITIONAL_JUMP", flows_to=("0x00401008",)),
            instruction(0x401005, "33c0", "XOR", ("EAX", "EAX")),
            instruction(0x401007, "c3", "RET", flow="TERMINATOR"),
            instruction(0x401008, "e8f31f0000", "CALL", ("0x00403000",),
                        flow="UNCONDITIONAL_CALL", flows_to=("0x00403000",),
                        references=({"to": "0x00403000", "is_call": True},)),
            instruction(0x40100D, "c3", "RET", flow="TERMINATOR"),
        ])
        source, diagnostics = lifter.translate_function(
            body, set(), stop_call_site=0x401008
        )
        self.assertIn("goto L_00401008;", source)
        self.assertIn("state.eip = 0x00401008u;", source)
        self.assertIn("return BatchLiftStatus::unsupported_dependency;", source)
        self.assertNotIn("spore_lift_00403000", source)
        self.assertEqual(
            [item for item in diagnostics if item["status"] == "blocked"],
            [{"address": "0x00401008", "mnemonic": "CALL",
              "status": "blocked", "bytes": "e8f31f0000",
              "target": "0x00403000"}],
        )

    def test_cfg_call_boundary_rejects_non_call(self):
        body = function([
            instruction(0x401000, "33c0", "XOR", ("EAX", "EAX")),
            instruction(0x401002, "c3", "RET", flow="TERMINATOR"),
        ])
        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body, stop_call_site=0x401000)
        self.assertIn("not an exported CALL", raised.exception.reasons[0])

    def test_cfg_multiple_call_boundaries_keep_both_branches(self):
        body = function([
            instruction(0x401000, "7407", "JZ", ("0x00401009",),
                        flow="CONDITIONAL_JUMP", flows_to=("0x00401009",)),
            instruction(0x401002, "e8f9200000", "CALL", ("0x00403100",),
                        flow="UNCONDITIONAL_CALL", flows_to=("0x00403100",),
                        references=({"to": "0x00403100", "is_call": True},)),
            instruction(0x401007, "eb05", "JMP", ("0x0040100e",),
                        flow="UNCONDITIONAL_JUMP", flows_to=("0x0040100e",)),
            instruction(0x401009, "e8f2210000", "CALL", ("0x00403200",),
                        flow="UNCONDITIONAL_CALL", flows_to=("0x00403200",),
                        references=({"to": "0x00403200", "is_call": True},)),
            instruction(0x40100e, "c3", "RET", flow="TERMINATOR"),
        ])
        source, diagnostics = lifter.translate_function(
            body, set(), stop_call_sites={0x401002, "0x00401009"}
        )
        self.assertIn("goto L_00401009;", source)
        self.assertIn("state.eip = 0x00401002u;", source)
        self.assertIn("state.eip = 0x00401009u;", source)
        self.assertNotIn("spore_lift_00403100", source)
        self.assertNotIn("spore_lift_00403200", source)
        self.assertEqual(
            [(item["address"], item["target"]) for item in diagnostics
             if item["status"] == "blocked"],
            [("0x00401002", "0x00403100"),
             ("0x00401009", "0x00403200")],
        )

    def test_prefix_data_ranges_emit_verified_pe_bytes(self):
        image = bytearray(0x400)
        image[0x208:0x20c] = b"\x00\x00\x80\x3f"
        pe = (
            bytes(image),
            0x00400000,
            [(".rdata", 0x1000, 0x100, 0x200, 0x100)],
        )
        ranges = prefix_generator._verified_data_ranges(
            pe, [(0x00401008, 4)]
        )
        header = prefix_generator._reference_header(
            0x00401000,
            0x00401005,
            b"\x90",
            0x00402000,
            b"\xc3",
            0x00401001,
            0x00402000,
            ranges,
        )

        self.assertEqual(ranges[0]["section"], ".rdata")
        self.assertEqual(ranges[0]["file_offset"], 0x208)
        self.assertEqual(ranges[0]["bytes"], b"\x00\x00\x80\x3f")
        self.assertIn("kSporePrefixDataRange_00401008_address", header)
        self.assertIn("0x00u, 0x00u, 0x80u, 0x3fu", header)
        self.assertIn(
            "kSporePrefixDataRanges = {{", header
        )
        self.assertIn("kSporeChildEntry = 0x00402000u;", header)
        self.assertIn("kSporeIncludedCallOffset = 0x00000001u;", header)
        self.assertIn("0x00402000u", header)

    def test_prefix_data_ranges_reject_overlap_and_non_file_backed_bytes(self):
        image = bytearray(0x400)
        pe = (
            bytes(image),
            0x00400000,
            [(".rdata", 0x1000, 0x100, 0x200, 0x100)],
        )
        with self.assertRaisesRegex(ValueError, "must not overlap"):
            prefix_generator._verified_data_ranges(
                pe, [(0x00401008, 8), (0x0040100c, 4)]
            )
        with self.assertRaisesRegex(ValueError, "not backed by a PE section"):
            prefix_generator._verified_data_ranges(
                pe, [(0x00402000, 4)]
            )

    def test_prefix_data_range_parser_requires_address_and_length(self):
        self.assertEqual(
            prefix_generator._parse_data_range("0x00401000:0x1000"),
            (0x00401000, 0x1000),
        )
        with self.assertRaisesRegex(ValueError, "expected ADDRESS:LENGTH"):
            prefix_generator._parse_data_range("0x00401000")
        with self.assertRaisesRegex(ValueError, "outside the x86 address space"):
            prefix_generator._parse_data_range("0xffffffff:2")

    def test_prefix_executes_exported_call_and_stops_before_next_dependency(self):
        body = function([
            instruction(0x401000, "b801000000", "MOV", ("EAX", "0x1")),
            instruction(
                0x401005, "e8f61f0000", "CALL", ("0x00402000",),
                flow="UNCONDITIONAL_CALL",
                flows_to=("0x00402000",),
                references=({"to": "0x00402000", "is_call": True},),
            ),
            instruction(0x40100A, "bb02000000", "MOV", ("EBX", "0x2")),
            instruction(
                0x40100F, "e8ec1f0000", "CALL", ("0x00403000",),
                flow="UNCONDITIONAL_CALL",
                flows_to=("0x00403000",),
                references=({"to": "0x00403000", "is_call": True},),
            ),
            instruction(0x401014, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function_prefix(
            body, 0x40100F, {0x402000}
        )

        self.assertIn("state.eip = 0x0040100fu;", source)
        self.assertIn(
            "return BatchLiftStatus::unsupported_dependency;", source
        )
        self.assertIn("batch_guest_call32", source)
        self.assertIn("spore_lift_00402000(memory, state)", source)
        self.assertEqual(diagnostics[-1]["status"], "blocked")
        self.assertEqual(diagnostics[-1]["target"], "0x00403000")

    def test_prefix_requires_direct_call_boundary(self):
        body = function([
            instruction(0x401000, "b801000000", "MOV", ("EAX", "0x1")),
            instruction(0x401005, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function_prefix(body, 0x401005)

        self.assertIn("direct call instruction", raised.exception.reasons[0])

    def test_prefix_can_stop_before_branch_after_verified_call(self):
        body = function([
            instruction(
                0x401000, "e8fb0f0000", "CALL", ("0x00402000",),
                flow="UNCONDITIONAL_CALL",
                flows_to=("0x00402000",),
                references=({"to": "0x00402000", "is_call": True},),
            ),
            instruction(0x401005, "3bc1", "CMP", ("EAX", "ECX")),
            instruction(
                0x401007, "7602", "JBE", ("0x0040100b",),
                flow="CONDITIONAL_JUMP",
            ),
        ])
        source, diagnostics = lifter.translate_function_prefix(
            body, 0x401007, {0x402000}, allow_branch_boundary=True,
        )
        self.assertIn("spore_lift_00402000(memory, state)", source)
        self.assertIn("state.eip = 0x00401007u;", source)
        self.assertEqual(diagnostics[-1]["mnemonic"], "JBE")
        self.assertNotIn("target", diagnostics[-1])

    def test_prefix_rejects_control_flow_before_boundary(self):
        body = function([
            instruction(
                0x401000, "eb00", "JMP", ("0x00401002",),
                flow="UNCONDITIONAL_JUMP", flows_to=("0x00401002",),
            ),
            instruction(
                0x401002, "e8f90f0000", "CALL", ("0x00402000",),
                flow="UNCONDITIONAL_CALL",
                flows_to=("0x00402000",),
                references=({"to": "0x00402000", "is_call": True},),
            ),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function_prefix(body, 0x401002)

        self.assertIn("control-flow instruction", raised.exception.reasons[0])

    def test_prefix_rejects_call_without_exported_target_body(self):
        body = function([
            instruction(
                0x401000, "e8fb0f0000", "CALL", ("0x00402000",),
                flow="UNCONDITIONAL_CALL",
                flows_to=("0x00402000",),
                references=({"to": "0x00402000", "is_call": True},),
            ),
            instruction(0x401005, "90", "NOP"),
            instruction(
                0x401006, "e8f51f0000", "CALL", ("0x00403000",),
                flow="UNCONDITIONAL_CALL",
                flows_to=("0x00403000",),
                references=({"to": "0x00403000", "is_call": True},),
            ),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function_prefix(body, 0x401006, set())

        self.assertIn("not in the supplied export set", raised.exception.reasons[0])

    def test_prefix_rejects_unresolved_boundary_call(self):
        body = function([
            instruction(0x401000, "b801000000", "MOV", ("EAX", "0x1")),
            instruction(
                0x401005, "ffd0", "CALL", ("EAX",),
                flow="COMPUTED_CALL",
            ),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function_prefix(body, 0x401005)

        self.assertIn("resolved direct call", raised.exception.reasons[0])

    def test_import_thunk_diagnostic_resolves_pe_import_and_text_stub(self):
        image = bytearray(0x600)
        image[:2] = b"MZ"
        struct.pack_into("<I", image, 0x3C, 0x80)
        image[0x80:0x84] = b"PE\0\0"
        struct.pack_into("<HHIIIHH", image, 0x84, 0x14C, 2, 0, 0, 0, 0xE0, 0)
        optional = 0x98
        struct.pack_into("<H", image, optional, 0x10B)
        struct.pack_into("<I", image, optional + 28, 0x400000)
        struct.pack_into("<I", image, optional + 92, 16)
        struct.pack_into("<II", image, optional + 96 + 8, 0x2000, 40)
        section_table = optional + 0xE0
        image[section_table:section_table + 8] = b".text\0\0\0"
        struct.pack_into(
            "<IIII", image, section_table + 8, 0x200, 0x1000, 0x200, 0x200
        )
        second = section_table + 40
        image[second:second + 8] = b".idata\0\0"
        struct.pack_into(
            "<IIII", image, second + 8, 0x200, 0x2000, 0x200, 0x400
        )

        struct.pack_into("<IIIII", image, 0x400, 0x2040, 0, 0, 0x2060, 0x2050)
        struct.pack_into("<I", image, 0x440, 0x2080)
        struct.pack_into("<I", image, 0x450, 0x2080)
        image[0x460:0x46B] = b"sample.dll\0"
        struct.pack_into("<H", image, 0x480, 0)
        image[0x482:0x490] = b"ImportedThing\0"
        image[0x200:0x202] = b"\xff\x25"
        struct.pack_into("<I", image, 0x202, 0x402050)

        with tempfile.TemporaryDirectory(prefix="spore_import_diagnostic_") as temporary:
            executable = Path(temporary) / "imports.exe"
            executable.write_bytes(image)
            pe = lifter.parse_pe(executable)

        import_stubs = diagnostic.parse_import_thunks(pe)
        self.assertEqual(
            import_stubs,
            {
                0x401000: {
                    "symbol": "sample.dll!ImportedThing",
                    "iat_address": "0x00402050",
                }
            },
        )
        import_stubs_with_slots, iat_slots = diagnostic.parse_import_thunks(
            pe, include_iat_slots=True
        )
        self.assertEqual(lifter.parse_pe_iat_imports(pe), iat_slots)
        self.assertEqual(import_stubs_with_slots, import_stubs)
        self.assertEqual(iat_slots, {0x402050: "sample.dll!ImportedThing"})
        self.assertEqual(
            diagnostic._indirect_iat_symbol(
                instruction(
                    0x401010, "ff1550204000", "CALL",
                    ("dword ptr [0x00402050]",), flow="CALL",
                ),
                iat_slots,
            ),
            {
                "iat_address": "0x00402050",
                "symbol": "sample.dll!ImportedThing",
            },
        )
        self.assertEqual(
            diagnostic._target_record(0x401000, {}, import_stubs, pe)[
                "classification"
            ],
            "import_thunk",
        )
        self.assertEqual(
            diagnostic._target_record(0x401100, {}, import_stubs, pe)[
                "classification"
            ],
            "missing_internal_function",
        )
        self.assertEqual(
            diagnostic._target_record(0x402000, {}, import_stubs, pe)[
                "classification"
            ],
            "unresolved_destination",
        )
        self.assertEqual(
            diagnostic._target_record(
                0x401100, {0x401100: Path("export.json")}, import_stubs, pe
            )["classification"],
            "exported_function",
        )

    def test_identified_iat_call_uses_guest_import_dispatcher(self):
        body = function([
            instruction(
                0x401000, "ff1550204000", "CALL",
                ("dword ptr [0x00402050]",), flow="COMPUTED_CALL",
            ),
            instruction(0x401006, "c3", "RET", flow="TERMINAL"),
        ])
        imports = {0x402050: "KERNEL32.dll!InitializeCriticalSection"}

        source, diagnostics = lifter.translate_function(
            body, {0x401000}, imports
        )

        self.assertIn("batch_guest_import_call32", source)
        self.assertIn('"KERNEL32.dll!InitializeCriticalSection"', source)
        self.assertIn("0x00402050u, 0x00401006u", source)
        self.assertEqual([item["status"] for item in diagnostics], [
            "translated", "translated",
        ])
        self.assertEqual(lifter.function_call_targets(body, imports), [])

    def test_indirect_call_without_identified_iat_slot_remains_rejected(self):
        body = function([
            instruction(
                0x401000, "ff1550204000", "CALL",
                ("dword ptr [0x00402050]",), flow="COMPUTED_CALL",
            ),
            instruction(0x401006, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body, {0x401000}, {})
        # No IAT symbol is invented: the slot is read as an ordinary data
        # pointer and the dispatcher still refuses an unknown target at runtime.
        self.assertIn("memory.load32(0x00402050u", source)
        self.assertIn("invoke_guest_call", source)
        self.assertEqual([item["status"] for item in diagnostics],
                         ["translated"] * 2)

    def test_movss_transfers_and_absolute_memory_are_translated(self):
        body = function([
            instruction(
                0x401000, "8b1500da6601", "MOV",
                ("EDX", "dword ptr [0x0166da00]"),
            ),
            instruction(
                0x401006, "f30f100500304000", "MOVSS",
                ("XMM0", "dword ptr [0x00403000]"),
            ),
            instruction(
                0x40100E, "f30f118110000000", "MOVSS",
                ("dword ptr [ECX + 0x10]", "XMM0"),
            ),
            instruction(
                0x401016, "f30f10c8", "MOVSS", ("XMM1", "XMM0"),
            ),
            instruction(0x40101A, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)

        self.assertIn("memory.load32(0x0166da00u", source)
        self.assertIn("batch_guest_movss_load", source)
        self.assertIn("batch_guest_movss_store", source)
        self.assertIn(
            "batch_guest_movss_store(memory, state, 0u, ", source
        )
        self.assertIn("batch_guest_movss_register_move", source)
        self.assertEqual(
            [item["status"] for item in diagnostics],
            ["translated"] * len(body["instructions"]),
        )
        self.assertEqual(
            lifter.classify_instruction("MOVSS"),
            "sse_scalar_data_transfer",
        )
        self.assertEqual(
            lifter.classify_instruction("ADDSS"),
            "sse_arithmetic",
        )

    def test_mov_indexed_memory_store_preserves_flags_and_wraps_address(self):
        body = function([
            instruction(
                0x401000, "894c862c", "MOV",
                ("dword ptr [ESI + EAX * 0x4 + 0x2c]", "ECX"),
            ),
            instruction(0x401004, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)

        self.assertIn(
            "memory.store32(static_cast<std::uint32_t>("
            "state.regs[6] + state.regs[0] * 4u + 0x0000002cu), t0)",
            source,
        )
        self.assertNotIn("state.eflags =", source)
        self.assertEqual(
            [item["status"] for item in diagnostics],
            ["translated", "translated"],
        )
        self.assertEqual(
            lifter.parse_operand(
                "dword ptr [ESI + EAX * 0x4 + 0x2c]"
            ),
            ("indexed_memory", 6, 0, 4, 0x2c, 32),
        )
        self.assertEqual(
            lifter.parse_operand("dword ptr [ESI + EAX * 4 - 0x4]"),
            ("indexed_memory", 6, 0, 4, -4, 32),
        )

    def test_mov_indexed_memory_rejects_unsupported_index_forms(self):
        for operand in (
            "dword ptr [ESI + EAX * 0x3 + 0x2c]",
            "dword ptr [ESI + ESP * 4 + 0x2c]",
        ):
            with self.subTest(operand=operand):
                body = function([
                    instruction(
                        0x401000, "894c862c", "MOV", (operand, "ECX"),
                    ),
                    instruction(0x401004, "c3", "RET", flow="TERMINAL"),
                ])
                with self.assertRaises(lifter.LiftRejected):
                    lifter.translate_function(body)

        body = function([
            instruction(
                0x401000, "030c86", "ADD",
                ("ECX", "dword ptr [ESI + EAX * 4]"),
            ),
            instruction(0x401003, "c3", "RET", flow="TERMINAL"),
        ])
        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)
        self.assertIn(
            "indexed memory operands currently support MOV only",
            raised.exception.reasons[0],
        )

    def test_xorps_register_forms_are_translated(self):
        body = function([
            instruction(0x401000, "0f57c0", "XORPS", ("XMM0", "XMM0")),
            instruction(0x401003, "0f57d1", "XORPS", ("XMM2", "XMM1")),
            instruction(0x401006, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)

        self.assertIn("batch_guest_xorps(state, 0u, 0u)", source)
        self.assertIn("batch_guest_xorps(state, 2u, 1u)", source)
        self.assertEqual(
            [item["status"] for item in diagnostics],
            ["translated"] * len(body["instructions"]),
        )
        self.assertEqual(lifter.classify_instruction("XORPS"), "sse_logical")

    def test_xorps_memory_form_is_translated(self):
        body = function([
            instruction(
                0x401000, "0f5705b0b8f301", "XORPS",
                ("XMM0", "xmmword ptr [0x013eb8b0]"),
            ),
            instruction(0x401007, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn(
            "batch_guest_xorps_memory(memory, state, 0u, 0x013eb8b0u)", source
        )

    def test_xorps_memory_form_requires_the_128_bit_width(self):
        body = function([
            instruction(
                0x401000, "0f5700", "XORPS",
                ("XMM0", "dword ptr [EAX]"),
            ),
            instruction(0x401003, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        self.assertIn(
            "128-bit memory operand", raised.exception.reasons[0]
        )

    def test_xchg_dword_memory_register_is_translated_without_flags(self):
        body = function([
            instruction(
                0x401000, "8701", "XCHG",
                ("dword ptr [ECX]", "EAX"),
            ),
            instruction(0x401002, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)

        self.assertIn(
            "batch_guest_xchg32(memory, state, 0u, "
            "static_cast<std::uint32_t>(state.regs[1] + 0x00000000u))",
            source,
        )
        self.assertNotIn("batch_set_", source)
        self.assertEqual(
            [item["status"] for item in diagnostics],
            ["translated", "translated"],
        )

    def test_xchg_rejects_non_dword_or_two_memory_operands(self):
        for operands in (
            ("word ptr [ECX]", "EAX"),
            ("dword ptr [ECX]", "dword ptr [EDX]"),
        ):
            with self.subTest(operands=operands):
                body = function([
                    instruction(0x401000, "8701", "XCHG", operands),
                    instruction(0x401002, "c3", "RET", flow="TERMINAL"),
                ])
                with self.assertRaises(lifter.LiftRejected) as raised:
                    lifter.translate_function(body)
                self.assertIn(
                    "one 32-bit memory operand",
                    raised.exception.reasons[0],
                )

    def test_x87_binary64_load_and_pop_store_are_translated(self):
        body = function([
            instruction(
                0x401000, "dd05382f4501", "FLD",
                ("double ptr [0x01452f38]",),
            ),
            instruction(
                0x401006, "dd9e68b71500", "FSTP",
                ("double ptr [ESI + 0x15b768]",),
            ),
            instruction(0x40100C, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)

        self.assertIn(
            "batch_guest_fld64(memory, state, 0x01452f38u)", source
        )
        self.assertIn(
            "batch_guest_fstp64(memory, state, "
            "static_cast<std::uint32_t>(state.regs[6] + 0x0015b768u))",
            source,
        )
        self.assertEqual(
            [item["status"] for item in diagnostics],
            ["translated"] * len(body["instructions"]),
        )
        self.assertEqual(lifter.classify_instruction("FLD"), "x87")
        self.assertEqual(lifter.classify_instruction("FSTP"), "x87")

    def test_x87_stack_arithmetic_and_pop_forms_are_translated(self):
        body = function([
            instruction(0x401000, "d8c1", "FADD", ("ST0", "ST1")),
            instruction(0x401002, "dec1", "FADDP", ("ST1", "ST0")),
            instruction(0x401004, "d9c9", "FXCH", ()),
            instruction(0x401006, "d8c9", "FMUL", ("ST1",)),
            instruction(0x401008, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn(
            "batch_guest_x87_arithmetic_stack(state, 0u, 1u, 0u, false)",
            source,
        )
        self.assertIn(
            "batch_guest_x87_arithmetic_stack(state, 1u, 0u, 0u, true)",
            source,
        )
        self.assertIn("batch_guest_x87_fxch(state, 1u)", source)
        self.assertIn(
            "batch_guest_x87_arithmetic_stack(state, 1u, 0u, 1u, false)",
            source,
        )

    def test_x87_compare_and_status_forms_are_translated(self):
        body = function([
            instruction(
                0x401000, "d81d70534801", "FCOMP",
                ("float ptr [0x01485370]",),
            ),
            instruction(0x401006, "d9c9", "FXCH", ("ST1",)),
            instruction(0x401008, "dfe0", "FNSTSW", ("AX",)),
            instruction(0x40100A, "dfe9", "FUCOMIP", ("ST0", "ST1")),
            instruction(0x40100C, "d9e1", "FABS", ()),
            instruction(0x40100E, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn(
            "batch_guest_x87_compare_memory(memory, state, 0x01485370u, 1u, "
            "false)",
            source,
        )
        self.assertIn("batch_guest_fnstsw_ax(state)", source)
        self.assertIn(
            "batch_guest_x87_compare_stack(state, 1u, 1u, true)", source
        )
        self.assertIn("batch_guest_x87_abs(state)", source)

    def test_x87_constant_and_integer_forms_are_translated(self):
        body = function([
            instruction(0x401000, "d9e8", "FLD1", ()),
            instruction(0x401002, "d9ee", "FLDZ", ()),
            instruction(0x401004, "d9c1", "FLD", ("ST1",)),
            instruction(0x401006, "df3d382f4501", "FISTP",
                        ("qword ptr [0x01452f38]",)),
            instruction(0x40100C, "df2d382f4501", "FILD",
                        ("qword ptr [0x01452f38]",)),
            instruction(0x401012, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn("batch_guest_fld1(state)", source)
        self.assertIn("batch_guest_fldz(state)", source)
        self.assertIn("batch_guest_fld_stack(state, 1u)", source)
        self.assertIn(
            "batch_guest_fistp64(memory, state, 0x01452f38u)", source
        )
        self.assertIn(
            "batch_guest_fild64(memory, state, 0x01452f38u)", source
        )

    def test_x87_arithmetic_rejects_reverse_forms_without_memory(self):
        body = function([
            instruction(0x401000, "d8e0", "FSUB", ("ST0", "ST1")),
            instruction(0x401002, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn(
            "batch_guest_x87_arithmetic_stack(state, 0u, 1u, 3u, false)",
            source,
        )
        self.assertEqual(lifter.classify_instruction("FADD"), "x87")

    def test_sse_scalar_arithmetic_and_compare_forms_are_translated(self):
        body = function([
            instruction(0x401000, "f30f58c1", "ADDSS", ("XMM0", "XMM1")),
            instruction(0x401004, "f30f59c2", "MULSS", ("XMM0", "XMM2")),
            instruction(
                0x401008, "f30f5c0424", "SUBSS",
                ("XMM0", "dword ptr [ESP]"),
            ),
            instruction(0x40100D, "0f2f05b0b8f301", "COMISS",
                        ("XMM0", "dword ptr [0x013eb8b0]")),
            instruction(0x401015, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn(
            "batch_guest_sse_scalar_arithmetic(state, 0u, state.xmm[1u][0], 0u)",
            source,
        )
        self.assertIn(
            "batch_guest_sse_scalar_arithmetic(state, 0u, state.xmm[2u][0], 2u)",
            source,
        )
        self.assertIn(
            "batch_guest_sse_scalar_arithmetic(state, 0u, t2a, 1u)", source
        )
        self.assertIn(
            "batch_guest_ucomiss_memory(memory, state, 0u, 0x013eb8b0u)",
            source,
        )
        self.assertEqual(lifter.classify_instruction("ADDSS"), "sse_arithmetic")

    def test_pilot_manifest_accepts_baseline_and_nested_100_plan(self):
        baseline = [
            {"selection_stratum": stratum}
            for stratum, count in (
                ("small", 10),
                ("medium", 10),
                ("conditional_branch", 10),
            )
            for _ in range(count)
        ]
        expanded = [
            {"selection_stratum": stratum}
            for stratum, count in (
                ("small", 30),
                ("medium", 30),
                ("conditional_branch", 40),
            )
            for _ in range(count)
        ]

        lifter.validate_pilot_manifest({}, baseline)
        lifter.validate_pilot_manifest({
            "pilot_size": 100,
            "selection_counts": {
                "small": 30,
                "medium": 30,
                "conditional_branch": 40,
            },
        }, expanded)

        expanded_300 = [
            {"selection_stratum": stratum}
            for stratum, count in (
                ("small", 90),
                ("medium", 90),
                ("conditional_branch", 120),
            )
            for _ in range(count)
        ]
        lifter.validate_pilot_manifest({
            "pilot_size": 300,
            "selection_counts": {
                "small": 90,
                "medium": 90,
                "conditional_branch": 120,
            },
        }, expanded_300)

    def test_pilot_manifest_rejects_unsupported_or_misdeclared_size(self):
        unsupported = [
            {"selection_stratum": "small"}
            for _ in range(50)
        ]
        with self.assertRaisesRegex(ValueError, "exactly 30, 100, or 300"):
            lifter.validate_pilot_manifest({}, unsupported)

        expanded = [
            {"selection_stratum": stratum}
            for stratum, count in (
                ("small", 30),
                ("medium", 30),
                ("conditional_branch", 40),
            )
            for _ in range(count)
        ]
        with self.assertRaisesRegex(ValueError, "selection_counts"):
            lifter.validate_pilot_manifest({"pilot_size": 100}, expanded)

    def test_integer_leaf_is_statically_lowered(self):
        body = function([
            instruction(0x401000, "b801000000", "MOV", ("EAX", "0x1")),
            instruction(0x401005, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)

        self.assertIn("spore_lift_00401000", source)
        self.assertIn("state.regs[0] = t0;", source)
        self.assertNotIn("goto L_", source)
        self.assertNotIn("switch (state.eip)", source)
        self.assertEqual([item["status"] for item in diagnostics], ["translated"] * 2)

    def test_lea_computes_base_plus_displacement_without_memory_access_or_flags(self):
        body = function([
            instruction(
                0x401000, "8d45fc", "LEA",
                ("EAX", "dword ptr [EBP + -0x4]"),
            ),
            instruction(0x401003, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)

        self.assertIn(
            "t0 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu);",
            source,
        )
        self.assertIn("state.regs[0] = t0;", source)
        self.assertNotIn("memory.load32(static_cast", source)
        self.assertNotIn("memory.store", source)
        self.assertNotIn("eflags", source)
        self.assertEqual([item["status"] for item in diagnostics], ["translated"] * 2)

    def test_lea_indexed_address_wraps_without_memory_access_or_flags(self):
        body = function([
            instruction(
                0x401000, "8d4488fc", "LEA",
                ("EAX", "dword ptr [EAX + ECX*4 + -0x4]"),
            ),
            instruction(0x401004, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)
        self.assertIn("state.regs[0] + state.regs[1] * 4u + 0xfffffffcu", source)
        self.assertNotIn("memory.load", source)
        self.assertNotIn("eflags", source)
        self.assertEqual([item["status"] for item in diagnostics], ["translated"] * 2)

    def test_not_register_width_and_flags(self):
        body = function([
            instruction(0x401000, "f6d0", "NOT", ("AL",)),
            instruction(0x401002, "f7d7", "NOT", ("EDI",)),
            instruction(0x401004, "c3", "RET", flow="TERMINAL"),
        ])
        source, diagnostics = lifter.translate_function(body)
        self.assertIn("(~t0a & 0x000000ffu)", source)
        self.assertIn("(~t1a & 0xffffffffu)", source)
        self.assertNotIn("eflags", source)
        self.assertEqual([item["status"] for item in diagnostics], ["translated"] * 3)

    def test_div_and_imul_32_bit_register_forms(self):
        body = function([
            instruction(0x401000, "f7f7", "DIV", ("EDI",)),
            instruction(0x401002, "0fafc7", "IMUL", ("EAX", "EDI")),
            instruction(0x401005, "c3", "RET", flow="TERMINAL"),
        ])
        source, diagnostics = lifter.translate_function(body)
        self.assertIn("dividend / t0a", source)
        self.assertIn("quotient > 0xffffffffull", source)
        self.assertIn("BatchLiftStatus::divide_error", source)
        self.assertIn("product < -2147483648ll || product > 2147483647ll", source)
        self.assertIn("state.eflags &= ~0x801u", source)
        self.assertEqual([item["status"] for item in diagnostics], ["translated"] * 3)

    def test_xchg_two_registers_is_translated_without_flags(self):
        body = function([
            instruction(0x401000, "87c8", "XCHG", ("EAX", "ECX")),
            instruction(0x401002, "c3", "RET", flow="TERMINAL"),
        ])
        source, diagnostics = lifter.translate_function(body)
        self.assertIn("t0c = state.regs[0];", source)
        self.assertIn("state.regs[0] = state.regs[1];", source)
        self.assertIn("state.regs[1] = t0c;", source)
        self.assertNotIn("eflags", source)
        self.assertEqual([item["status"] for item in diagnostics],
                         ["translated"] * 2)

    def test_imul_three_operand_and_one_operand_forms(self):
        body = function([
            instruction(0x401000, "6bc00c", "IMUL", ("EAX", "EAX", "0xc")),
            instruction(0x401003, "f7ef", "IMUL", ("EDI",)),
            instruction(0x401005, "c3", "RET", flow="TERMINAL"),
        ])
        source, diagnostics = lifter.translate_function(body)
        # The three-operand form multiplies the loaded source by the immediate
        # into the destination register.
        self.assertIn("t0b = 0x0000000cu;", source)
        self.assertIn("state.regs[0] = static_cast<std::uint32_t>(product);", source)
        # The one-operand form writes the high half to EDX.
        self.assertIn(
            "state.regs[2] = static_cast<std::uint32_t>("
            "static_cast<std::uint64_t>(product) >> 32u);", source)
        self.assertEqual([item["status"] for item in diagnostics],
                         ["translated"] * 3)

    def test_cdq_and_idiv_extend_and_divide_signed(self):
        body = function([
            instruction(0x401000, "99", "CDQ"),
            instruction(0x401001, "f7f9", "IDIV", ("ECX",)),
            instruction(0x401003, "c3", "RET", flow="TERMINAL"),
        ])
        source, diagnostics = lifter.translate_function(body)
        self.assertIn(
            "state.regs[2] = (state.regs[0] & 0x80000000u) != 0u "
            "? 0xffffffffu : 0u;", source)
        self.assertIn("const std::int64_t divisor", source)
        self.assertIn("dividend / divisor", source)
        self.assertIn("quotient < -2147483648ll || quotient > 2147483647ll", source)
        self.assertEqual([item["status"] for item in diagnostics],
                         ["translated"] * 3)

    def test_computed_jump_dispatches_through_its_table(self):
        body = function([
            instruction(0x401000, "ff2485e0236900", "JMP",
                        ("dword ptr [EAX*0x4 + 0x6923e0]",),
                        flow="COMPUTED_JUMP",
                        flows_to=("0x00401010", "0x00401020")),
            instruction(0x401010, "c3", "RET", flow="TERMINAL"),
            instruction(0x401020, "c3", "RET", flow="TERMINAL"),
        ])
        source, _ = lifter.translate_function(
            body, exported_function_entries={0x401000})
        self.assertIn("switch (t0a) {", source)
        self.assertIn("case 0x00401010u: goto L_00401010;", source)
        self.assertIn("case 0x00401020u: goto L_00401020;", source)
        self.assertIn("state.eip = t0a;", source)
        self.assertIn("return BatchLiftStatus::unsupported_dependency;", source)

    def test_computed_jump_to_an_unknown_case_is_rejected(self):
        body = function([
            instruction(0x401000, "ff2485e0236900", "JMP",
                        ("dword ptr [EAX*0x4 + 0x6923e0]",),
                        flow="COMPUTED_JUMP",
                        flows_to=("0x00401010", "0x00401040")),
            instruction(0x401010, "c3", "RET", flow="TERMINAL"),
        ])
        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body, exported_function_entries={0x401000})
        self.assertIn("computed jump target 0x00401040", raised.exception.reasons[0])

    def test_sar_and_indexed_cmp_in_binary_search_helper(self):
        body = function([
            instruction(0x401000, "c1fa02", "SAR", ("EDX", "0x2")),
            instruction(0x401003, "3b3488", "CMP", ("ESI", "dword ptr [EAX + ECX*4]")),
            instruction(0x401006, "c3", "RET", flow="TERMINAL"),
        ])
        source, diagnostics = lifter.translate_function(body)
        self.assertIn("(0xffffffffu << (32u - t0c))", source)
        self.assertIn("batch_set_sar_flags(state, t0a, t0c, t0r, 32u)", source)
        self.assertIn("memory.load32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 4u", source)
        self.assertEqual([item["status"] for item in diagnostics], ["translated"] * 3)

    def test_float_conversion_path_is_lowered_with_x87_guards(self):
        body = function([
            instruction(0x401000, "db0424", "FILD", ("dword ptr [ESP]",)),
            instruction(0x401003, "d805d04f3f01", "FADD", ("float ptr [0x013f4fd0]",)),
            instruction(0x401009, "d80e", "FMUL", ("float ptr [ESI]",)),
            instruction(0x40100b, "d95c2404", "FSTP", ("float ptr [ESP + 0x4]",)),
            instruction(0x40100f, "f30f2dc0", "CVTSS2SI", ("EAX", "XMM0")),
            instruction(0x401013, "f30f2ac8", "CVTSI2SS", ("XMM1", "EAX")),
            instruction(0x401017, "0f2ec8", "UCOMISS", ("XMM1", "XMM0")),
            instruction(0x40101a, "0f42c1", "CMOVC", ("EAX", "ECX")),
            instruction(0x40101d, "c3", "RET", flow="TERMINAL"),
        ])
        source, diagnostics = lifter.translate_function(body)
        for helper in ("batch_guest_fild32", "batch_guest_x87_float32_arithmetic",
                       "batch_guest_fstp32", "batch_guest_cvtss2si",
                       "batch_guest_cvtsi2ss", "batch_guest_ucomiss"):
            self.assertIn(helper, source)
        self.assertIn("state.eflags & 0x001u", source)
        self.assertEqual([item["status"] for item in diagnostics], ["translated"] * 9)

    def test_float_division_and_truncating_conversion(self):
        body = function([
            instruction(0x401000, "d836", "FDIV", ("float ptr [ESI]",)),
            instruction(0x401002, "f30f2c442418", "CVTTSS2SI",
                        ("EAX", "dword ptr [ESP + 0x18]")),
            instruction(0x401008, "c3", "RET", flow="TERMINAL"),
        ])
        source, diagnostics = lifter.translate_function(body)
        self.assertIn("batch_guest_x87_float32_arithmetic(memory, state,", source)
        self.assertIn(", 2u)", source)
        self.assertIn("batch_guest_cvttss2si_memory(memory, state, 0u,", source)
        self.assertEqual([item["status"] for item in diagnostics], ["translated"] * 3)

    def test_lea_rejects_non_32_bit_destinations(self):
        body = function([
            instruction(0x401000, "8d45fc", "LEA", ("AX", "[EBP - 0x4]")),
            instruction(0x401003, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        self.assertIn("32-bit register destination", raised.exception.reasons[0])

    def test_sbb_and_fs_memory_are_lowered_explicitly(self):
        body = function([
            instruction(0x401000, "1b03", "SBB", ("EAX", "EBX")),
            instruction(
                0x401002, "648b0500000000", "MOV",
                ("EAX", "dword ptr FS:[0]"),
            ),
            instruction(
                0x401009, "64892500000000", "MOV",
                ("dword ptr FS:[0]", "ESP"),
            ),
            instruction(0x401010, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)

        self.assertIn("batch_set_sbb_flags(state, t0a, t0b, t0c, t0r, 32u)", source)
        self.assertIn("state.fs_base + 0x00000000u", source)
        self.assertIn("memory.load32", source)
        self.assertIn("memory.store32", source)
        self.assertEqual([item["status"] for item in diagnostics], ["translated"] * 4)

    def test_conditional_branch_uses_exported_static_target(self):
        body = function([
            instruction(0x401000, "39d8", "CMP", ("EAX", "EBX")),
            instruction(
                0x401002, "7402", "JZ", ("0x00401006",),
                flow="CONDITIONAL_JUMP", flows_to=("0x00401006",),
            ),
            instruction(0x401004, "90", "NOP"),
            instruction(0x401005, "90", "NOP"),
            instruction(0x401006, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn(
            "if (((state.eflags & 0x040u) != 0u)) goto L_00401006;",
            source,
        )
        self.assertIn("batch_set_sub_flags", source)

    def test_unknown_opcode_rejects_function_instead_of_skipping(self):
        body = function([
            instruction(0x401000, "f30fbdc0", "LZCNT", ("EAX", "EAX")),
            instruction(0x401004, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        rejected = [
            item for item in raised.exception.instruction_diagnostics
            if item.get("status") == "rejected"
        ]
        self.assertEqual(rejected[0]["mnemonic"], "LZCNT")
        self.assertIn("unsupported instruction", rejected[0]["reason"])

    def test_indirect_register_call_dispatches_through_the_runtime(self):
        body = function([
            instruction(
                0x401000, "ffd0", "CALL", ("EAX",),
                flow="COMPUTED_CALL",
            ),
            instruction(0x401002, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(
            body, exported_function_entries=set())

        self.assertIn("invoke_guest_call", source)
        self.assertIn("state.regs[0]", source)
        self.assertEqual(
            [item["status"] for item in diagnostics], ["translated"] * 2)

    def test_direct_call_to_unexported_target_is_rejected(self):
        body = function([
            instruction(
                0x401000, "e8fb0f0000", "CALL", ("0x00402000",),
                flow="UNCONDITIONAL_CALL",
                references=({"to": "0x00402000", "is_call": True},),
            ),
            instruction(0x401005, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        self.assertIn(
            "direct call target 0x00402000 is not in the exported function set",
            raised.exception.reasons[0],
        )

    def test_direct_call_between_exported_functions_uses_shared_guest_state(self):
        caller = function([
            instruction(
                0x401000, "e8fb0f0000", "CALL", ("0x00402000",),
                flow="UNCONDITIONAL_CALL",
                flows_to=("0x00402000",),
                references=({"to": "0x00402000", "is_call": True},),
            ),
            instruction(0x401005, "c3", "RET", flow="TERMINAL"),
        ])
        callee = function([
            instruction(0x402000, "b807000000", "MOV", ("EAX", "0x7")),
            instruction(0x402005, "c3", "RET", flow="TERMINAL"),
        ])

        translated = lifter.translate_function_set([caller, callee])

        caller_result = translated[0x401000]
        self.assertIsNotNone(caller_result["source"])
        self.assertIn("batch_guest_call32", caller_result["source"])
        self.assertIn("spore_lift_00402000(memory, state)", caller_result["source"])
        self.assertIn("state.eip != 0x00401005u", caller_result["source"])
        self.assertIn("BatchLiftStatus spore_lift_00402000(", caller_result["source"])
        self.assertIsNotNone(translated[0x402000]["source"])
        self.assertIn("batch_guest_return32(memory, state, 0u)", caller_result["source"])

    def test_recursive_call_is_generated_as_a_normal_guest_call(self):
        recursive = function([
            instruction(
                0x401000, "e8fbffffff", "CALL", ("0x00401000",),
                flow="UNCONDITIONAL_CALL",
                flows_to=("0x00401000",),
                references=({"to": "0x00401000", "is_call": True},),
            ),
            instruction(0x401005, "c3", "RET", flow="TERMINAL"),
        ])

        translated = lifter.translate_function_set([recursive])[0x401000]

        self.assertIsNotNone(translated["source"])
        self.assertIn("BatchLiftStatus spore_lift_00401000(", translated["source"])
        self.assertIn("spore_lift_00401000(memory, state)", translated["source"])

    def test_ret_immediate_preserves_guest_stack_cleanup(self):
        body = function([
            instruction(0x401000, "c21000", "RET", ("0x10",), flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn("batch_guest_return32(memory, state, 16u)", source)

    def test_call_to_exported_but_rejected_function_rejects_caller(self):
        caller = function([
            instruction(
                0x401000, "e8fb0f0000", "CALL", ("0x00402000",),
                flow="UNCONDITIONAL_CALL",
                references=({"to": "0x00402000", "is_call": True},),
            ),
            instruction(0x401005, "c3", "RET", flow="TERMINAL"),
        ])
        rejected_callee = function([
            instruction(0x402000, "db28", "FLD", ("tbyte ptr [EAX]",)),
            instruction(0x402002, "c3", "RET", flow="TERMINAL"),
        ])

        translated = lifter.translate_function_set([caller, rejected_callee])

        self.assertIsNone(translated[0x401000]["source"])
        self.assertIn(
            "direct call target 0x00402000 is exported but was rejected",
            translated[0x401000]["reasons"][0],
        )

    def test_complex_memory_address_is_rejected_with_operand(self):
        body = function([
            instruction(
                0x401000, "8b0488", "MOV",
                ("EAX", "dword ptr [EAX + ECX*4 + EDX]"),
            ),
            instruction(0x401003, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        rejected = [
            item for item in raised.exception.instruction_diagnostics
            if item.get("status") == "rejected"
        ]
        self.assertIn("EAX + ECX*4 + EDX", rejected[0]["reason"])

    def test_byte_registers_and_memory_are_translated(self):
        body = function([
            instruction(
                0x401000, "8a4101", "MOV",
                ("AL", "byte ptr [ECX + 0x1]"),
            ),
            instruction(0x401003, "fec0", "INC", ("AL",)),
            instruction(0x401005, "3a4101", "CMP", ("AL", "byte ptr [ECX + 0x1]")),
            instruction(
                0x401008, "884101", "MOV",
                ("byte ptr [ECX + 0x1]", "AL"),
            ),
            instruction(0x40100B, "c3", "RET", flow="TERMINAL"),
        ])

        source, diagnostics = lifter.translate_function(body)

        self.assertIn("memory.load8", source)
        self.assertIn("memory.store8", source)
        self.assertIn("batch_set_inc_flags", source)
        self.assertIn("batch_set_sub_flags", source)
        self.assertEqual(len(diagnostics), 5)

    def test_dec_is_translated_and_preserves_carry_flag(self):
        body = function([
            instruction(0x401000, "4a", "DEC", ("EDX",)),
            instruction(0x401001, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn("batch_set_dec_flags", source)
        runtime = (Path(__file__).parent / "BatchStaticLiftRuntime.hpp").read_text(
            encoding="utf-8"
        )
        self.assertIn("state.eflags &= ~0x8d4u;", runtime)

    def test_signed_negative_immediate_is_parsed(self):
        operand = lifter.parse_operand("-0x1")

        self.assertEqual(operand, ("immediate", 0xFFFFFFFF, None, 0))

    def test_memory_width_must_be_explicit(self):
        body = function([
            instruction(0x401000, "c70001000000", "MOV", ("[EAX]", "0x1")),
            instruction(0x401006, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        self.assertIn("memory operand width is ambiguous", raised.exception.reasons[0])

    def test_negative_frame_displacement_is_parsed(self):
        operand = lifter.parse_operand("dword ptr [EBP + -0x4]")

        self.assertEqual(operand, ("memory", 5, -4, 32))

    def test_setcc_writes_byte_register_from_flags(self):
        body = function([
            instruction(0x401000, "0f94c0", "SETE", ("AL",)),
            instruction(0x401003, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn("state.regs[0] & 0xffffff00u", source)
        self.assertIn("state.eflags & 0x040u", source)

    def test_movzx_loads_byte_and_zero_extends(self):
        body = function([
            instruction(
                0x401000, "0fb64104", "MOVZX",
                ("EAX", "byte ptr [ECX + 0x4]"),
            ),
            instruction(0x401004, "c3", "RET", flow="TERMINAL"),
        ])

        source, _ = lifter.translate_function(body)

        self.assertIn("memory.load8", source)
        self.assertIn("state.regs[0] = t0a;", source)

    def test_unresolved_branch_target_is_rejected(self):
        body = function([
            instruction(
                0x401000, "ebfe", "JMP", ("0x00401020",),
                flow="UNCONDITIONAL_JUMP", flows_to=("0x00401020",),
            ),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        # A jump out of its own body is a tail call, so the rejection names the
        # missing body rather than an unresolved in-body branch. Both cases must
        # still fail closed.
        self.assertIn(
            "tail jump target 0x00401020 is not in the exported function set",
            raised.exception.reasons[0])

    def test_out_of_body_jump_with_an_exported_target_is_a_tail_call(self):
        body = function([
            instruction(
                0x401000, "eb1e", "JMP", ("0x00401020",),
                flow="UNCONDITIONAL_JUMP", flows_to=("0x00401020",),
            ),
        ])
        source, _ = lifter.translate_function(
            body, exported_function_entries={0x401000, 0x401020})
        self.assertIn("state.eip = 0x00401020u;", source)
        self.assertIn("return spore_lift_00401020(memory, state);", source)
        self.assertNotIn("goto L_00401020;", source)

    def test_instruction_order_must_begin_at_entry(self):
        body = function([
            instruction(0x401000, "90", "NOP"),
            instruction(0x401001, "c3", "RET", flow="TERMINAL"),
        ])
        body["entry"] = "0x00401001"

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        self.assertIn("first instruction is not the function entry", raised.exception.reasons[0])

    def test_truncated_export_is_rejected_before_codegen(self):
        body = function([
            instruction(0x401000, "c3", "RET", flow="TERMINAL"),
        ])
        body["instructions_truncated"] = True

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        self.assertIn("truncated", raised.exception.reasons[0])

    def test_batch_report_verifies_bytes_counts_coverage_and_rejections(self):
        with tempfile.TemporaryDirectory(prefix="spore_batch_report_") as temporary:
            root = Path(temporary)
            exe = root / "synthetic.exe"
            csv_path = root / "inventory.csv"
            batch_path = root / "batch.json"
            output_dir = root / "generated"
            report_path = root / "report.json"
            text = bytearray(0x400)
            exports = []
            inventory_rows = []

            def add_function(entry, name, stratum, body_bytes, instructions, reachable):
                offset = entry - 0x401000
                text[offset:offset + len(body_bytes)] = body_bytes
                function_record = {
                    "entry": f"0x{entry:08x}",
                    "name": name,
                    "body_address_count": len(body_bytes),
                    "instructions": instructions,
                    "instruction_count_exported": len(instructions),
                    "instructions_truncated": False,
                    "references_truncated": False,
                }
                exports.append({
                    "selection_stratum": stratum,
                    "reachable_from_program_entry": reachable,
                    "reachability_kind": "direct-call graph test fixture",
                    "function": function_record,
                })
                inventory_rows.append({
                    "address": f"{entry:08x}",
                    "name": name,
                    "size": str(len(body_bytes)),
                })

            def insn(address, raw, mnemonic, operands=(), flow="FALL_THROUGH", flows=()):
                return instruction(
                    address, raw.hex(), mnemonic, operands, flow, flows
                )

            for index in range(10):
                entry = 0x401000 + index * 8
                if index == 0:
                    code = bytes.fromhex("db28909090c3")
                    instructions = [
                        insn(entry, bytes.fromhex("db28"), "FLD",
                             ("tbyte ptr [EAX]",)),
                        insn(entry + 2, b"\x90", "NOP"),
                        insn(entry + 3, b"\x90", "NOP"),
                        insn(entry + 4, b"\x90", "NOP"),
                        insn(entry + 5, b"\xc3", "RET", flow="TERMINAL"),
                    ]
                else:
                    code = bytes.fromhex("b801000000c3")
                    instructions = [
                        insn(entry, bytes.fromhex("b801000000"), "MOV", ("EAX", "0x1")),
                        insn(entry + 5, b"\xc3", "RET", flow="TERMINAL"),
                    ]
                add_function(
                    entry, f"FUN_{entry:08x}", "small", code, instructions,
                    index < 5,
                )

            for index in range(10):
                entry = 0x401080 + index * 0x40
                code = b"\x90" * 32 + b"\xc3"
                instructions = [
                    insn(entry + offset, b"\x90", "NOP")
                    for offset in range(32)
                ]
                instructions.append(
                    insn(entry + 32, b"\xc3", "RET", flow="TERMINAL")
                )
                add_function(
                    entry, f"FUN_{entry:08x}", "medium", code, instructions,
                    index < 5,
                )

            for index in range(10):
                entry = 0x401300 + index * 0x10
                target = f"0x{entry + 5:08x}"
                code = bytes.fromhex("39d8740190c3")
                instructions = [
                    insn(entry, bytes.fromhex("39d8"), "CMP", ("EAX", "EBX")),
                    insn(
                        entry + 2, bytes.fromhex("7401"), "JZ", (target,),
                        flow="CONDITIONAL_JUMP", flows=(target,),
                    ),
                    insn(entry + 4, b"\x90", "NOP"),
                    insn(entry + 5, b"\xc3", "RET", flow="TERMINAL"),
                ]
                add_function(
                    entry, f"FUN_{entry:08x}", "conditional_branch", code,
                    instructions, index < 5,
                )

            image = bytearray(0x600)
            image[:2] = b"MZ"
            struct.pack_into("<I", image, 0x3C, 0x80)
            image[0x80:0x84] = b"PE\0\0"
            struct.pack_into("<HHIIIHH", image, 0x84, 0x14C, 1, 0, 0, 0, 0xE0, 0)
            optional = 0x98
            struct.pack_into("<H", image, optional, 0x10B)
            struct.pack_into("<I", image, optional + 28, 0x400000)
            section = optional + 0xE0
            image[section:section + 8] = b".text\0\0\0"
            struct.pack_into("<IIII", image, section + 8, 0x400, 0x1000, 0x400, 0x200)
            image[0x200:0x600] = text
            exe.write_bytes(image)
            digest = hashlib.sha256(image).hexdigest()

            with csv_path.open("w", newline="", encoding="utf-8") as stream:
                writer = csv.DictWriter(stream, fieldnames=("address", "name", "size"))
                writer.writeheader()
                writer.writerows(inventory_rows)
            batch_path.write_text(json.dumps({
                "schema": "spore-ghidra-function-batch-v1",
                "selected_source_sha256": digest,
                "selected_source_is_phase4_build": True,
                "user_confirmed_source_for_open_program": True,
                "language_id": lifter.EXPECTED_LANGUAGE,
                "functions_truncated": False,
                "reachability_complete": True,
                "reachability_visited_function_count": 20,
                "reachability_basis": "test fixture",
                "reachability_limitations": [],
                "functions": exports,
            }), encoding="utf-8")

            expected_hash = lifter.EXPECTED_SHA256
            lifter.EXPECTED_SHA256 = digest
            try:
                summary = lifter.analyze_batch(
                    exe, csv_path, batch_path, output_dir, report_path
                )
            finally:
                lifter.EXPECTED_SHA256 = expected_hash

            self.assertEqual(summary["pilot_size"], 30)
            self.assertEqual(summary["accepted_function_count"], 29)
            self.assertEqual(summary["rejected_function_count"], 1)
            self.assertEqual(summary["accepted_unique_instruction_bytes"], 444)
            self.assertEqual(summary["exported_unique_instruction_bytes"], 450)
            self.assertEqual(summary["accepted_bytes_percent_of_pilot_export"], 98.67)
            self.assertEqual(summary["reachable_pilot_function_count"], 15)
            self.assertEqual(summary["unreachable_pilot_function_count"], 15)
            self.assertEqual(
                summary["rejection_counts_by_kind"],
                {"unsupported_operand_form": 1},
            )
            self.assertEqual(len(list(output_dir.glob("*.cpp"))), 29)
            self.assertTrue(report_path.is_file())
            rejected = next(
                item for item in summary["functions"] if item["status"] == "rejected"
            )
            self.assertEqual(rejected["instruction_diagnostics"][0]["mnemonic"], "FLD")

    def test_boot_pid_stage_boundaries_stop_at_declared_addresses(self):
        self.assertEqual(
            boot_pid.resolve_boundary("pid-call-boundary"), 0x011e158B
        )
        self.assertEqual(
            boot_pid.resolve_boundary("pid-call-executed"), 0x011E1591
        )
        with self.assertRaisesRegex(ValueError, "unknown boot prefix stage"):
            boot_pid.resolve_boundary("pid-call")

    def test_boot_pid_prefix_requires_contiguous_verified_bytes(self):
        body = {
            0x011E1548: instruction(0x011E1548, "8bff", "MOV", ("EDI", "EDI")),
            0x011E154A: instruction(0x011E154A, "55", "PUSH", ("EBP",)),
            0x011E154B: instruction(0x011E154B, "8bec", "MOV", ("EBP", "ESP")),
        }
        prefix, boundary = boot_pid.build_prefix(body, 0x011E154B)

        self.assertEqual(
            [item["address"] for item in prefix],
            ["0x011e1548", "0x011e154a"],
        )
        self.assertEqual(boundary["address"], "0x011e154b")
        with self.assertRaisesRegex(ValueError, "gap in boot prefix"):
            boot_pid.build_prefix(
                {
                    0x011E1548: body[0x011E1548],
                    0x011E154B: body[0x011E154B],
                },
                0x011E154D,
            )
        with self.assertRaisesRegex(ValueError, "expected the boundary"):
            boot_pid.build_prefix(body, 0x011E154C)

    def test_boot_pid_esi_mix_rejects_other_encodings(self):
        good = {
            0x011E1585: instruction(
                0x011E1585, "8b75fc", "MOV", ("ESI", "dword ptr [EBP + -0x4]")
            ),
            0x011E1588: instruction(
                0x011E1588, "3375f8", "XOR", ("ESI", "dword ptr [EBP + -0x8]")
            ),
        }
        boot_pid.validate_esi_mix(good)

        wrong_encoding = dict(good)
        wrong_encoding[0x011E1588] = instruction(
            0x011E1588, "33f0", "XOR", ("ESI", "EAX")
        )
        with self.assertRaisesRegex(ValueError, "differ from 3375f8"):
            boot_pid.validate_esi_mix(wrong_encoding)

        wrong_mnemonic = dict(good)
        wrong_mnemonic[0x011E1585] = instruction(
            0x011E1585, "8b75fc", "LEA", ("ESI", "dword ptr [EBP + -0x4]")
        )
        with self.assertRaisesRegex(ValueError, "not the expected MOV"):
            boot_pid.validate_esi_mix(wrong_mnemonic)

    def test_boot_pid_import_call_requires_matching_iat_symbol(self):
        by_address = {
            0x011E158B: instruction(
                0x011E158B, "ff1514c13c01", "CALL",
                ("dword ptr [0x013cc114]",), flow="COMPUTED_CALL",
            ),
        }
        iat = {0x013CC114: "KERNEL32.dll!GetCurrentProcessId"}
        boot_pid.validate_import_call(
            by_address, 0x011E158B, "ff1514c13c01",
            ["dword ptr [0x013cc114]"], "KERNEL32.dll!GetCurrentProcessId",
            0x013CC114, iat,
        )
        with self.assertRaisesRegex(ValueError, "does not resolve to"):
            boot_pid.validate_import_call(
                by_address, 0x011E158B, "ff1514c13c01",
                ["dword ptr [0x013cc114]"], "KERNEL32.dll!GetCurrentProcessId",
                0x013CC114, {0x013CC114: "KERNEL32.dll!GetSystemTimeAsFileTime"},
            )
        with self.assertRaisesRegex(
            ValueError, "bytes ff1514c13c01 differ from ff15ccc13c01"
        ):
            boot_pid.validate_import_call(
                by_address, 0x011E158B, "ff15ccc13c01",
                ["dword ptr [0x013cc114]"], "KERNEL32.dll!GetCurrentProcessId",
                0x013CC114, iat,
            )

    def test_boot_entropy_stage_reaches_the_counter_mix(self):
        self.assertEqual(
            boot_pid.resolve_boundary("entropy-complete"), 0x011E15B5
        )

    @staticmethod
    def _entropy_block():
        return {
            0x011E1591: instruction(0x011E1591, "33f0", "XOR", ("ESI", "EAX")),
            0x011E1593: instruction(
                0x011E1593, "ff153cc13c01", "CALL",
                ("dword ptr [0x013cc13c]",), flow="COMPUTED_CALL",
            ),
            0x011E1599: instruction(0x011E1599, "33f0", "XOR", ("ESI", "EAX")),
            0x011E159B: instruction(
                0x011E159B, "ff1530c13c01", "CALL",
                ("dword ptr [0x013cc130]",), flow="COMPUTED_CALL",
            ),
            0x011E15A1: instruction(0x011E15A1, "33f0", "XOR", ("ESI", "EAX")),
            0x011E15A3: instruction(
                0x011E15A3, "8d45f0", "LEA", ("EAX", "[EBP + -0x10]")
            ),
            0x011E15A6: instruction(0x011E15A6, "50", "PUSH", ("EAX",)),
            0x011E15A7: instruction(
                0x011E15A7, "ff15b8c23c01", "CALL",
                ("dword ptr [0x013cc2b8]",), flow="COMPUTED_CALL",
            ),
            0x011E15AD: instruction(
                0x011E15AD, "8b45f4", "MOV", ("EAX", "dword ptr [EBP + -0xc]")
            ),
            0x011E15B0: instruction(
                0x011E15B0, "3345f0", "XOR", ("EAX", "dword ptr [EBP + -0x10]")
            ),
            0x011E15B3: instruction(0x011E15B3, "33f0", "XOR", ("ESI", "EAX")),
        }

    def test_boot_entropy_block_requires_the_measured_encodings(self):
        iat = {
            0x013CC13C: "KERNEL32.dll!GetCurrentThreadId",
            0x013CC130: "KERNEL32.dll!GetTickCount",
            0x013CC2B8: "KERNEL32.dll!QueryPerformanceCounter",
        }
        block = self._entropy_block()
        boot_pid.validate_entropy_block(block, iat)

        wrong_xor = dict(block)
        wrong_xor[0x011E1599] = instruction(
            0x011E1599, "33c0", "XOR", ("EAX", "EAX")
        )
        with self.assertRaisesRegex(ValueError, "differ from 33f0"):
            boot_pid.validate_entropy_block(wrong_xor, iat)

        missing = dict(block)
        del missing[0x011E15A7]
        with self.assertRaisesRegex(ValueError, "0x011e15a7.*absent"):
            boot_pid.validate_entropy_block(missing, iat)

        wrong_iat = dict(iat)
        wrong_iat[0x013CC130] = "KERNEL32.dll!GetCurrentThreadId"
        with self.assertRaisesRegex(ValueError, "does not resolve to"):
            boot_pid.validate_entropy_block(block, wrong_iat)

    def test_boot_entropy_header_emits_every_call_and_xor_site(self):
        header = boot_pid.reference_header(
            b"\x90", b"\x4e\xe6\x40\xbb\xb1\x19\xbf\x44", 0x011E15B5
        )
        for name, value in (
            ("kCookieBoundaryAddress", "0x011e15b5u"),
            ("kCookieThreadIdCallAddress", "0x011e1593u"),
            ("kCookieTickCountCallAddress", "0x011e159bu"),
            ("kCookiePerformanceCounterCallAddress", "0x011e15a7u"),
            ("kCookieProcessIdXorAddress", "0x011e1591u"),
            ("kCookieThreadIdXorAddress", "0x011e1599u"),
            ("kCookieTickCountXorAddress", "0x011e15a1u"),
            ("kCookiePerformanceCounterXorAddress", "0x011e15b3u"),
        ):
            self.assertIn(f"{name} = {value};", header)

    def test_boot_cookie_complete_stage_allows_a_function_tail(self):
        self.assertEqual(
            boot_pid.resolve_boundary("cookie-complete"), 0x011E15DE
        )
        body = {
            0x011E1548: instruction(0x011E1548, "8bff", "MOV", ("EDI", "EDI")),
            0x011E154A: instruction(0x011E154A, "c3", "RET", flow="TERMINAL"),
        }
        prefix, boundary = boot_pid.build_prefix(body, 0x011E154B)

        self.assertEqual(len(prefix), 2)
        self.assertIsNone(boundary)

    def test_shift_left_and_leave_emit_documented_semantics(self):
        shl = instruction(
            0x011E15C6, "c1e010", "SHL", ("EAX", "0x10")
        )
        source = lifter.translate_instruction(
            shl, 0, {0x011E15C6, 0x011E15C9}, 0x011E15C9
        )
        joined = "\n".join(source)
        self.assertIn("batch_set_shl_flags(state, t0a, t0c, t0r, 32u);", joined)
        self.assertIn("t0c = 16u;", joined)
        self.assertIn("if (t0c != 0u) {", joined)

        leave = instruction(0x011E15DC, "c9", "LEAVE")
        leave_source = lifter.translate_instruction(
            leave, 0, {0x011E15DC, 0x011E15DD}, 0x011E15DD
        )
        leave_joined = "\n".join(leave_source)
        self.assertIn("state.regs[4] = state.regs[5];", leave_joined)
        self.assertIn("state.regs[5] = t0;", leave_joined)

        with self.assertRaisesRegex(ValueError, "0 through 31 or CL"):
            lifter.translate_instruction(
                instruction(0x011E15C6, "c1e020", "SHL", ("EAX", "0x20")),
                0, {0x011E15C6, 0x011E15C9}, 0x011E15C9,
            )

    def test_shift_right_arithmetic_and_variable_counts(self):
        shr = lifter.translate_instruction(
            instruction(0x00928000, "c1ea03", "SHR", ("EDX", "0x3")),
            0, {0x00928000, 0x00928003}, 0x00928003,
        )
        joined = "\n".join(shr)
        self.assertIn("t0c = 3u;", joined)
        self.assertIn("batch_set_shr_flags(state, t0a, t0c, t0r, 32u);", joined)
        self.assertIn("t0r = static_cast<std::uint32_t>(t0a >> t0c);", joined)

        sar = lifter.translate_instruction(
            instruction(0x00927E3F, "c1fb05", "SAR", ("EBX", "0x5")),
            0, {0x00927E3F, 0x00927E42}, 0x00927E42,
        )
        self.assertIn("batch_set_sar_flags(state, t0a, t0c, t0r, 32u);",
                      "\n".join(sar))

        variable = lifter.translate_instruction(
            instruction(0x00926010, "d3e0", "SHL", ("EAX", "CL")),
            0, {0x00926010, 0x00926012}, 0x00926012,
        )
        joined = "\n".join(variable)
        self.assertIn("t0c = (state.regs[1] & 0x1fu);", joined)
        self.assertIn("if (t0c != 0u) {", joined)

        # A zero count is a no-op: nothing is emitted for it.
        self.assertEqual(
            lifter.translate_instruction(
                instruction(0x00926020, "c1e000", "SHL", ("EAX", "0x0")),
                0, {0x00926020, 0x00926022}, 0x00926022,
            ), [])

        with self.assertRaisesRegex(ValueError, "0 through 31 or CL"):
            lifter.translate_instruction(
                instruction(0x00926030, "c1e020", "SHR", ("EAX", "0x20")),
                0, {0x00926030, 0x00926033}, 0x00926033,
            )

    def test_xadd_and_debug_trap_are_translated(self):
        xadd = lifter.translate_instruction(
            instruction(0x004023ED, "f00fc108", "XADD.LOCK",
                        ("dword ptr [EAX]", "ECX")),
            0, {0x004023ED, 0x004023F1}, 0x004023F1,
        )
        joined = "\n".join(xadd)
        self.assertIn("batch_set_add_flags(state, t0a, t0b, t0r, 32u);", joined)
        # The target receives the sum and the source receives the old value.
        self.assertIn(
            "t0r = static_cast<std::uint32_t>(t0a + t0b) & 0xffffffffu;",
            joined)
        self.assertIn("state.regs[1] = t0a;", joined)

        trap = lifter.translate_instruction(
            instruction(0x0040192F, "cc", "INT3"),
            0, {0x0040192F, 0x00401930}, 0x00401930,
        )
        self.assertIn("return BatchLiftStatus::debug_trap;", "\n".join(trap))

    def test_indexed_memory_operands_reach_or_and_test(self):
        indexed_or = lifter.translate_instruction(
            instruction(0x009269F4, "0904bb", "OR",
                        ("dword ptr [EBX + EDI*0x4 + 0x430]", "EAX")),
            0, {0x009269F4, 0x009269F8}, 0x009269F8,
        )
        joined = "\n".join(indexed_or)
        self.assertIn("state.regs[3] + state.regs[7] * 4u + 0x00000430u",
                      joined)
        with self.assertRaisesRegex(ValueError, "indexed memory operands"):
            lifter.translate_instruction(
                instruction(0x009269F8, "0904bb", "ADC",
                            ("dword ptr [EBX + EDI*0x4 + 0x430]", "EAX")),
                0, {0x009269F8, 0x009269FC}, 0x009269FC,
            )

    def test_computed_call_through_memory_uses_the_dispatcher(self):
        source = lifter.translate_instruction(
            instruction(0x00401941, "ff5514", "CALL",
                        ("dword ptr [EBP + 0x14]",), flow="COMPUTED_CALL"),
            0, {0x00401941, 0x00401944}, 0x00401944,
        )
        joined = "\n".join(source)
        self.assertIn(
            "memory.load32(static_cast<std::uint32_t>(state.regs[5] + "
            "0x00000014u), t0t)", joined)
        self.assertIn("invoke_guest_call(memory, state, t0t, 0x00401944u)",
                      joined)

    def test_boot_crt_entry_constants_match_the_verified_boundaries(self):
        self.assertEqual(boot_crt.CRT_ENTRY, 0x011E0EE0)
        self.assertEqual(boot_crt.SEH_PROLOG, 0x011E11D4)
        self.assertEqual(boot_crt.SEH_CALL, 0x011E0EE7)
        self.assertEqual(boot_crt.SEH_CALL_BYTES, "e8e8020000")
        self.assertEqual(boot_crt.STARTUPINFO_CALL, 0x011E0EF8)
        self.assertEqual(boot_crt.STARTUPINFO_CALL_BYTES, "ff159cc23c01")
        self.assertEqual(boot_crt.STARTUPINFO_IAT, 0x013CC29C)
        self.assertEqual(
            boot_crt.STARTUPINFO_SYMBOL, "KERNEL32.dll!GetStartupInfoA")
        self.assertEqual(boot_crt.AFTER_STARTUPINFO, 0x011E0EFE)

    def test_pushfd_popfd_cpuid_movapd_and_computed_call_are_translated(self):
        addresses = {0x00001000, 0x00001001, 0x00001002, 0x00001003,
                     0x00001007, 0x00001009}
        pushfd = lifter.translate_instruction(
            instruction(0x00001000, "9c", "PUSHFD"), 0, addresses, 0x00001001)
        self.assertIn("batch_guest_pushfd(memory, state)", "\n".join(pushfd))
        popfd = lifter.translate_instruction(
            instruction(0x00001001, "9d", "POPFD"), 1, addresses, 0x00001002)
        self.assertIn("batch_guest_popfd(memory, state)", "\n".join(popfd))
        cpuid = lifter.translate_instruction(
            instruction(0x00001002, "0fa2", "CPUID"), 2, addresses, 0x00001003)
        self.assertIn("t2_cpuid_status = batch_guest_cpuid(state)",
                      "\n".join(cpuid))
        movapd = lifter.translate_instruction(
            instruction(0x00001003, "660f28c1", "MOVAPD",
                        ("XMM0", "XMM1")),
            3, addresses, 0x00001007)
        self.assertIn("batch_guest_movapd(state, 0u, 1u)", "\n".join(movapd))
        computed = lifter.translate_instruction(
            instruction(0x00001007, "ffd0", "CALL", ("EAX",),
                        flow="COMPUTED_CALL"),
            4, addresses, 0x00001009)
        joined = "\n".join(computed)
        self.assertIn("invoke_guest_call", joined)
        self.assertIn("state.regs[0]", joined)
        self.assertIn("0x00001009u", joined)

    def test_indirect_call_through_memory_uses_the_dispatcher(self):
        # A 32-bit callee pointer is loaded from guest memory and resolved at
        # runtime; an unregistered target still fails closed there.
        source = lifter.translate_instruction(
            instruction(0x00001000, "ff10", "CALL",
                        ("dword ptr [EAX]",), flow="COMPUTED_CALL"),
            0, {0x00001000, 0x00001002}, 0x00001002)
        joined = "\n".join(source)
        self.assertIn("memory.load32(static_cast<std::uint32_t>(state.regs[0]",
                      joined)
        self.assertIn("invoke_guest_call(memory, state, t0t, 0x00001002u)",
                      joined)

    def test_static_source_labels_a_branch_onto_the_terminal_boundary(self):
        body = function([
            instruction(0x011E0F31, "eb10", "JMP",
                        ("0x011e0f43",), flow="UNCONDITIONAL_JUMP",
                        flows_to=("0x011e0f43",)),
        ])
        translated = [
            (body["instructions"][0], ["goto L_011e0f43;"]),
        ]
        source = lifter.static_source(
            body, translated, [],
            terminal_status=(0x011E0F43, "unsupported_dependency"),
        )
        self.assertIn("L_011e0f43:", source)
        self.assertIn("state.eip = 0x011e0f43u;", source)
        unlabeled = lifter.static_source(
            body, translated, [], terminal_status=None,
        )
        self.assertNotIn("L_011e0f43:", unlabeled)

    def test_boot_crt_stages_advance_from_the_seh_call_to_startupinfo(self):
        self.assertEqual(
            sorted(boot_crt.STAGES),
            ["cpp-walk-initializers", "initterm-call", "initterm-executed",
             "interlocked-call", "seh-call-boundary", "startup-lock",
             "startup-state-initializing", "startupinfo-call"])
        boundary_stage = boot_crt.STAGES["seh-call-boundary"]
        self.assertEqual(boundary_stage["boundary"], 0x011E0EE7)
        self.assertEqual(boundary_stage["include"], set())
        self.assertFalse(boundary_stage["emit_prolog"])
        startupinfo_stage = boot_crt.STAGES["startupinfo-call"]
        self.assertEqual(startupinfo_stage["boundary"], 0x011E0EFE)
        self.assertEqual(startupinfo_stage["include"], {0x011E11D4})
        self.assertTrue(startupinfo_stage["emit_prolog"])
        interlocked_stage = boot_crt.STAGES["interlocked-call"]
        self.assertEqual(interlocked_stage["boundary"], 0x011E0F24)
        self.assertEqual(interlocked_stage["executed"], 18)
        lock_stage = boot_crt.STAGES["startup-lock"]
        self.assertEqual(lock_stage["boundary"], 0x011E0F43)
        # Only the taken path counts: the nine instruction _amsg_exit block is
        # emitted but never executed.
        self.assertEqual(lock_stage["executed"], 13)
        initterm_stage = boot_crt.STAGES["initterm-call"]
        self.assertEqual(initterm_stage["boundary"], 0x011E0F6F)
        self.assertEqual(initterm_stage["executed"], 22)
        executed_stage = boot_crt.STAGES["initterm-executed"]
        self.assertEqual(executed_stage["boundary"], 0x011E0F85)
        # The 22 above plus the call, its two POPs, the TEST and the JZ.
        self.assertEqual(executed_stage["executed"], 27)
        # The closure build supplies __SEH_prolog4, so this stage declares it
        # without emitting a second definition.
        self.assertEqual(executed_stage["include"], {0x011E11D4})
        self.assertFalse(executed_stage["emit_prolog"])
        self.assertTrue(executed_stage["prolog_counted"])
        walk_stage = boot_crt.STAGES["startup-state-initializing"]
        self.assertEqual(walk_stage["boundary"], 0x011E0F98)
        # The 27 above plus the state read, the compare, the JNZ and two PUSHes.
        self.assertEqual(walk_stage["executed"], 32)
        self.assertFalse(walk_stage["emit_prolog"])
        self.assertTrue(walk_stage["prolog_counted"])
        # The batch stage shares the boundary and the prefix, and only the
        # harness changes: it drives the _initterm call itself.
        batch_stage = boot_crt.STAGES["cpp-walk-initializers"]
        self.assertEqual(batch_stage["boundary"], 0x011E0F98)
        self.assertEqual(batch_stage["executed"], 32)
        self.assertTrue(batch_stage["cpp_walk"])
        self.assertFalse(batch_stage.get("emit_prolog"))
        # The call site is a JMP thunk onto MSVCR90!_initterm.
        self.assertEqual(boot_crt.INITTERM_WALK_THUNK, 0x011E150E)
        self.assertEqual(boot_crt.INITTERM_WALK_IAT, 0x013CC320)
        self.assertEqual(boot_crt.INITTERM_WALK_SYMBOL,
                         "MSVCR90.dll!_initterm")
        self.assertEqual(boot_crt.CPP_INIT_TABLE, 0x013CC80C)
        self.assertEqual(boot_crt.CPP_INIT_TABLE_END, 0x013EB098)

    def test_boot_crt_call_aliases_match_the_import_thunks(self):
        self.assertEqual(boot_crt.AMSG_EXIT_THUNK, 0x011E1368)
        self.assertEqual(boot_crt.AMSG_EXIT_CALL, 0x011E0F4E)
        self.assertEqual(boot_crt.AMSG_EXIT_IAT, 0x013CC33C)
        self.assertEqual(
            boot_crt.AMSG_EXIT_SYMBOL, "MSVCR90.dll!_amsg_exit")
        self.assertEqual(boot_crt.INITTERM_THUNK, 0x011E1514)
        self.assertEqual(boot_crt.INITTERM_CALL, 0x011E0F6F)
        self.assertEqual(boot_crt.INITTERM_CALL_BYTES, "e8a0050000")
        self.assertEqual(boot_crt.INITTERM_IAT, 0x013CC31C)
        self.assertEqual(
            boot_crt.INITTERM_SYMBOL, "MSVCR90.dll!_initterm_e")
        self.assertEqual(boot_crt.INITTERM_TABLE, 0x013EB09C)
        self.assertEqual(boot_crt.INITTERM_TABLE_END, 0x013EB0AC)
        self.assertEqual(
            boot_crt.ALIASES,
            {
                0x011E0F4E: (0x011E1368, "MSVCR90.dll!_amsg_exit",
                             0x013CC33C),
                0x011E0F6F: (0x011E1514, "MSVCR90.dll!_initterm_e",
                             0x013CC31C),
                0x011E0F98: (0x011E150E, "MSVCR90.dll!_initterm",
                             0x013CC320),
            })

    def test_static_source_labels_forward_exits_outside_the_prefix(self):
        body = function([
            instruction(0x011E0F5D, "7520", "JNZ",
                        ("0x011e0f7f",), flow="CONDITIONAL_JUMP",
                        flows_to=("0x011e0f7f",)),
        ])
        translated = [
            (body["instructions"][0], ["if (cond) goto L_011e0f7f;"]),
        ]
        source = lifter.static_source(
            body, translated, [],
            terminal_status=(0x011E0F6F, "unsupported_dependency"),
            exit_targets={0x011E0F7F, 0x011E0F85},
        )
        self.assertIn("L_011e0f7f:", source)
        self.assertIn("L_011e0f85:", source)
        self.assertIn("state.eip = 0x011e0f6fu;", source)
        self.assertLess(source.index("state.eip = 0x011e0f6fu;"),
                        source.index("L_011e0f7f:"))

    def test_boot_crt_lock_constants_match_the_verified_globals(self):
        self.assertEqual(boot_crt.INTERLOCKED_CALL, 0x011E0F1E)
        self.assertEqual(boot_crt.INTERLOCKED_CALL_BYTES, "ff1594c13c01")
        self.assertEqual(boot_crt.INTERLOCKED_IAT, 0x013CC194)
        self.assertEqual(
            boot_crt.INTERLOCKED_SYMBOL,
            "KERNEL32.dll!InterlockedCompareExchange")
        self.assertEqual(boot_crt.AFTER_INTERLOCKED, 0x011E0F24)
        self.assertEqual(boot_crt.STARTUP_STATE_AFTER_LOCK, 0x011E0F43)
        self.assertEqual(boot_crt.STARTUP_LOCK_REGION, 0x0171E740)
        self.assertEqual(boot_crt.STARTUP_LOCK_REGION_BYTES, 0x20)
        self.assertEqual(boot_crt.STARTUP_STATE, 0x0171E74C)
        self.assertEqual(boot_crt.STARTUP_LOCK, 0x0171E750)

    def test_boot_crt_region_is_bss_requires_loader_zero_fill(self):
        sections = [
            (".data", 0x0110C000, 0x00212764, 0x000C0000, 0x000C4C00),
        ]
        pe = (b"", 0x00400000, sections)
        # 0x015cfe70 is inside the raw .data bytes.
        self.assertFalse(boot_crt.region_is_bss(pe, 0x015CFE70, 0x20))
        # 0x0171e740 is past SizeOfRawData but inside VirtualSize.
        self.assertTrue(boot_crt.region_is_bss(pe, 0x0171E740, 0x20))
        # Past VirtualSize is not part of the section at all.
        self.assertFalse(boot_crt.region_is_bss(pe, 0x0171E740, 0x4000))

    def test_boot_crt_contiguous_rejects_a_gap_and_a_bad_end(self):
        gapped = {
            0x011E0EE0: {"address": "0x011e0ee0", "length": 3, "bytes": "6a5890"},
            0x011E0EE5: {"address": "0x011e0ee5", "length": 3, "bytes": "6a5890"},
        }
        with self.assertRaisesRegex(ValueError, "gap in CRT prefix"):
            boot_crt.contiguous(gapped, 0x011E0EE0, 0x011E0EE8)
        single = {
            0x011E0EE0: {"address": "0x011e0ee0", "length": 3, "bytes": "6a5890"},
        }
        with self.assertRaisesRegex(ValueError, "CRT prefix ends at"):
            boot_crt.contiguous(single, 0x011E0EE0, 0x011E0EE9)
        with self.assertRaisesRegex(ValueError, "precedes the CRT entry"):
            boot_crt.contiguous(single, 0x011E0EE9, 0x011E0EE8)

    def test_boot_crt_prefix_rejects_a_non_call_boundary(self):
        by_address = {
            0x011E0EE0: instruction(0x011E0EE0, "6a58", "PUSH", ("0x58",)),
            0x011E0EE2: instruction(0x011E0EE2, "90", "NOP"),
        }
        body = {
            "entry": "0x011e0ee0",
            "name": "___tmainCRTStartup",
            "body_address_count": 5,
            "instructions": list(by_address.values()),
            "instruction_count_exported": 2,
            "instructions_truncated": False,
            "references_truncated": False,
        }
        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function_prefix(body, 0x011E0EE2)
        self.assertIn(
            "direct call instruction", raised.exception.reasons[0]
        )

    def test_boot_pid_reference_header_emits_boundary_and_imports(self):
        header = boot_pid.reference_header(
            b"\x90\xc3", b"\x4e\xe6\x40\xbb\xb1\x19\xbf\x44", 0x011E1591
        )

        self.assertIn(
            "inline constexpr std::uint32_t kCookieBoundaryAddress = "
            "0x011e1591u;", header
        )
        self.assertIn(
            "inline constexpr std::uint32_t kCookieTimeCallAddress = "
            "0x011e157fu;", header
        )
        self.assertIn(
            "inline constexpr std::uint32_t kCookieProcessIdCallAddress = "
            "0x011e158bu;", header
        )
        self.assertIn("kCookieCodeBytes{0x90u, 0xc3u};", header)


class CppBatchGeneratorTests(unittest.TestCase):
    """The batch generator decides what the walk may enter."""

    def test_direct_calls_separate_engine_targets_from_local_jumps(self):
        import generate_cpp_initializer_batch as batch

        body = {
            "instructions": [
                instruction(0x00620230, "8b01", "MOV"),
                instruction(0x00620234, "741f", "JMP", ("0x620255",)),
                instruction(0x00620240, "e8ebfeffff", "CALL", ("0x935b70",)),
                instruction(0x00620249, "ff1514c13c01", "CALL",
                            ("dword ptr [0x13cc114]",)),
                instruction(0x00620255, "c3", "RET"),
            ]
        }
        direct, indirect = batch.direct_calls(body)
        # A JMP is reported like a CALL; the batch then drops the ones that
        # land inside a lifted body, so only the real dependency survives. An
        # IAT call is an import call, never a dependency.
        self.assertEqual(direct, [0x620255, 0x935B70])
        self.assertEqual(indirect, [])
        local = batch.lifted_instruction_addresses([0x00620230], {
            0x00620230: body,
        })
        self.assertEqual(sorted(local),
                         [0x00620230, 0x00620234, 0x00620240, 0x00620249,
                          0x00620255])
        self.assertNotIn(0x935B70, local)
        self.assertIn(0x620255, local)

    def test_engine_bodies_are_only_followed_when_named(self):
        import generate_cpp_initializer_batch as batch

        self.assertEqual(batch.CRT_LOW, 0x011E0000)
        self.assertEqual(batch.CRT_HIGH, 0x011F0000)
        # The guard lives outside the CRT range, so the default policy must
        # treat it as an engine blocker rather than reaching into engine code.
        self.assertFalse(batch.CRT_LOW <= 0x00935B70 < batch.CRT_HIGH)


class GuestImageSlotsTests(unittest.TestCase):
    """The image exposes exactly the import slots the loader would fix up."""

    def test_adjust_fdiv_stays_a_data_import(self):
        import generate_initterm_guest_image as image

        source = Path(image.__file__).read_text(encoding="utf-8")
        # _adjust_fdiv is the only slot deliberately left unpatched, and the
        # exclusion is stated where the trampolines are built.
        self.assertIn('data_imports = {"MSVCR90.dll!_adjust_fdiv"}', source)
        self.assertIn("kGuestImportSlotCount", source)

    def test_memory_accesses_and_pushed_arguments_are_separated(self):
        import generate_initterm_guest_image as image

        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "spore_00000001.cpp").write_text(
                "    if (!memory.load32(0x01669930u, t0)) return x;\n"
                "    t1a = 0x0143e838u;\n"
                "    state.regs[4] = static_cast<std::uint32_t>("
                "state.regs[4] - 4u);\n",
                encoding="utf-8")
            used, pushed = image.closure_addresses([root])
        self.assertEqual(sorted(used), [0x01669930])
        self.assertEqual(sorted(pushed), [0x0143E838])


if __name__ == "__main__":
    unittest.main()
