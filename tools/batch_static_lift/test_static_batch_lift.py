import csv
import hashlib
import json
import struct
import tempfile
import unittest
from pathlib import Path

import BatchStaticLift as lifter
import diagnose_call_closure as diagnostic


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

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body, {0x401000}, {})

        self.assertIn("indirect or unresolved call", raised.exception.reasons[0])

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

    def test_lea_rejects_indexed_addressing_until_supported(self):
        body = function([
            instruction(
                0x401000, "8d4488fc", "LEA",
                ("EAX", "dword ptr [EAX + ECX*4 + -0x4]"),
            ),
            instruction(0x401004, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        self.assertIn("unsupported operand syntax", raised.exception.reasons[0])

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

    def test_indirect_call_is_reported_as_a_blocker(self):
        body = function([
            instruction(
                0x401000, "ffd0", "CALL", ("EAX",),
                flow="COMPUTED_CALL",
            ),
            instruction(0x401002, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        self.assertIn("indirect or unresolved call", raised.exception.reasons[0])

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
            instruction(0x402000, "d900", "FLD", ("dword ptr [EAX]",)),
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
                ("EAX", "dword ptr [EAX + ECX*4]"),
            ),
            instruction(0x401003, "c3", "RET", flow="TERMINAL"),
        ])

        with self.assertRaises(lifter.LiftRejected) as raised:
            lifter.translate_function(body)

        rejected = [
            item for item in raised.exception.instruction_diagnostics
            if item.get("status") == "rejected"
        ]
        self.assertIn("EAX + ECX*4", rejected[0]["reason"])

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

        self.assertIn("not an exported instruction", raised.exception.reasons[0])

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
                    code = bytes.fromhex("d900909090c3")
                    instructions = [
                        insn(entry, bytes.fromhex("d900"), "FLD", ("dword ptr [EAX]",)),
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
            self.assertEqual(summary["rejection_counts_by_kind"], {"unsupported_opcode": 1})
            self.assertEqual(len(list(output_dir.glob("*.cpp"))), 29)
            self.assertTrue(report_path.is_file())
            rejected = next(
                item for item in summary["functions"] if item["status"] == "rejected"
            )
            self.assertEqual(rejected["instruction_diagnostics"][0]["mnemonic"], "FLD")


if __name__ == "__main__":
    unittest.main()
