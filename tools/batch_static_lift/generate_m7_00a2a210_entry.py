"""Generate the PE-verified entry of FUN_00a2a210 up to its first CALL."""

import argparse
import hashlib
import json
import struct
from pathlib import Path

import BatchStaticLift as lifter
import generate_call_closure as closure


ENTRY = 0x00A2A210
STOP = 0x00A2A24E
TARGET = 0x00921260
ROOT_CALL = 0x00A33817
ROOT_ENTRY = 0x00A33600
ROOT_STOP = 0x00A33831
ROOT_NEXT_TARGET = 0x00A2F210
ROOT_LEAF = 0x00743B50
NEXT_STOP = 0x00A2A275
NEXT_TARGET = 0x00921340
SECOND_STOP = 0x00A2A29E
SECOND_TARGET = 0x00A23570
LOOKUP_TARGET = 0x009212C0
TABLE_BASE = 0x0143D850
TABLE_SIZE = 0x404


def generate(exe: Path, batches: list[Path], output: Path,
             through_first_call: bool = False,
             through_second_call: bool = False):
    through_first_call = through_first_call or through_second_call
    digest = lifter.sha256_file(exe)
    if digest != lifter.EXPECTED_SHA256:
        raise ValueError(f"PE hash mismatch: {digest}")
    exported = closure.load_exported_functions(batches, digest)
    if any(address not in exported for address in
           (ENTRY, TARGET, ROOT_ENTRY, ROOT_NEXT_TARGET, ROOT_LEAF,
            NEXT_TARGET, SECOND_TARGET, LOOKUP_TARGET)):
        raise ValueError("a required constructor entry or call target is absent")
    pe = lifter.parse_pe(exe)
    verified = lifter.validate_function_bytes(exported[ENTRY], pe)
    target_verified = lifter.validate_function_bytes(exported[TARGET], pe)
    lifter.validate_function_bytes(exported[ROOT_ENTRY], pe)
    lifter.validate_function_bytes(exported[ROOT_LEAF], pe)
    leaf_source, _ = lifter.translate_function(exported[ROOT_LEAF])
    stop = SECOND_STOP if through_second_call else (
        NEXT_STOP if through_first_call else STOP)
    expected_target = SECOND_TARGET if through_second_call else (
        NEXT_TARGET if through_first_call else TARGET)
    source, diagnostics = lifter.translate_function_prefix(
        exported[ENTRY], stop, set(exported) if through_first_call else None
    )
    blocked = [item for item in diagnostics if item["status"] == "blocked"]
    if len(blocked) != 1 or blocked[0]["target"] != f"0x{expected_target:08x}":
        raise ValueError(f"unexpected boundary: {blocked}")
    prefix = [item for item in verified
              if lifter.parse_address(item["address"]) < stop]
    encoded = b"".join(bytes.fromhex(item["bytes"]) for item in prefix)
    expected_count = 42 if through_second_call else (26 if through_first_call else 18)
    if len(prefix) != expected_count or len(encoded) != stop - ENTRY:
        raise ValueError("unexpected instruction count or prefix byte length")
    target_encoded = b"".join(bytes.fromhex(item["bytes"])
                              for item in target_verified)
    if through_first_call and len(target_verified) != 38:
        raise ValueError("unexpected first-call target instruction count")
    target_source = None
    if through_first_call:
        target_source, _ = lifter.translate_function(exported[TARGET])
    next_source = lookup_source = None
    next_encoded = lookup_encoded = table_bytes = b""
    if through_second_call:
        next_verified = lifter.validate_function_bytes(exported[NEXT_TARGET], pe)
        lookup_verified = lifter.validate_function_bytes(exported[LOOKUP_TARGET], pe)
        if len(next_verified) != 8 or len(lookup_verified) != 26:
            raise ValueError("unexpected lookup function instruction count")
        next_encoded = b"".join(bytes.fromhex(item["bytes"])
                                for item in next_verified)
        lookup_encoded = b"".join(bytes.fromhex(item["bytes"])
                                  for item in lookup_verified)
        next_source, _ = lifter.translate_function(
            exported[NEXT_TARGET], set(exported))
        lookup_source, _ = lifter.translate_function(exported[LOOKUP_TARGET])
        _, _, table_bytes = lifter.read_pe_bytes(pe, TABLE_BASE, TABLE_SIZE)
    root_source, root_diagnostics = lifter.translate_function_prefix(
        exported[ROOT_ENTRY], ROOT_STOP, set(exported)
    )
    root_blocked = [item for item in root_diagnostics
                    if item["status"] == "blocked"]
    if len(root_blocked) != 1 or root_blocked[0]["target"] != (
            f"0x{ROOT_NEXT_TARGET:08x}"):
        raise ValueError(f"unexpected constructor boundary: {root_blocked}")
    root_translated = [item for item in root_diagnostics
                       if item["status"] == "translated"]
    if not any(item["address"] == f"0x{ROOT_CALL:08x}"
               for item in root_translated):
        raise ValueError("constructor CALL was not translated")
    _, _, root_call = lifter.read_pe_bytes(pe, ROOT_CALL, 5)
    if root_call[0] != 0xE8 or (
        ROOT_CALL + 5 + struct.unpack_from("<i", root_call, 1)[0]
    ) != ENTRY:
        raise ValueError("constructor boundary does not call the selected entry")
    if output.exists() and any(output.iterdir()):
        raise ValueError(f"output directory is not empty: {output}")
    output.mkdir(parents=True, exist_ok=True)
    (output / f"spore_{ENTRY:08x}_prefix.cpp").write_text(
        source + "\n", encoding="utf-8"
    )
    (output / f"spore_{ROOT_ENTRY:08x}_prefix.cpp").write_text(
        leaf_source + "\n\n" + root_source + "\n", encoding="utf-8"
    )
    if target_source is not None:
        (output / f"spore_{TARGET:08x}.cpp").write_text(
            target_source + "\n", encoding="utf-8"
        )
    if next_source is not None and lookup_source is not None:
        (output / f"spore_{NEXT_TARGET:08x}.cpp").write_text(
            next_source + "\n", encoding="utf-8")
        (output / f"spore_{LOOKUP_TARGET:08x}.cpp").write_text(
            lookup_source + "\n", encoding="utf-8")
    byte_values = ", ".join(f"0x{byte:02x}u" for byte in encoded)
    target_values = ", ".join(f"0x{byte:02x}u" for byte in target_encoded)
    (output / "m7_entry_reference_bytes.hpp").write_text(
        "#pragma once\n#include <array>\n#include <cstdint>\n"
        f"inline constexpr std::array<std::uint8_t, {len(encoded)}> "
        f"kM7EntryBytes = {{{byte_values}}};\n"
        f"inline constexpr std::array<std::uint8_t, 5> kM7RootCallBytes = "
        "{" + ", ".join(f"0x{byte:02x}u" for byte in root_call) + "};\n"
        + (f"inline constexpr std::array<std::uint8_t, {len(target_encoded)}> "
           f"kM7TargetBytes = {{{target_values}}};\n"
           if through_first_call else "")
        + (f"inline constexpr std::array<std::uint8_t, {len(next_encoded)}> "
           "kM7NextBytes = {" + ", ".join(f"0x{byte:02x}u" for byte in next_encoded) + "};\n"
           f"inline constexpr std::array<std::uint8_t, {len(lookup_encoded)}> "
           "kM7LookupBytes = {" + ", ".join(f"0x{byte:02x}u" for byte in lookup_encoded) + "};\n"
           f"inline constexpr std::array<std::uint8_t, {len(table_bytes)}> "
           "kM7TableBytes = {" + ", ".join(f"0x{byte:02x}u" for byte in table_bytes) + "};\n"
           if through_second_call else ""),
        encoding="utf-8",
    )
    report = {
        "schema": "spore-m7-00a2a210-entry-v1",
        "source_sha256": digest,
        "entry": f"0x{ENTRY:08x}",
        "boundary": blocked[0],
        "boundary_executed": False,
        "translated_instruction_count": len(prefix),
        "first_call_executed": through_first_call,
        "second_call_executed": through_second_call,
        "first_call_target_instruction_count": len(target_verified) if through_first_call else 0,
        "lookup_table_address": f"0x{TABLE_BASE:08x}" if through_second_call else None,
        "lookup_table_sha256": hashlib.sha256(table_bytes).hexdigest() if through_second_call else None,
        "verified_prefix_sha256": hashlib.sha256(encoded).hexdigest(),
        "verified_prefix_bytes": encoded.hex(),
        "constructor_call_address": f"0x{ROOT_CALL:08x}",
        "constructor_call_bytes": root_call.hex(),
        "constructor_generated_stop": f"0x{ROOT_STOP:08x}",
        "constructor_generated_instruction_count": len(root_translated),
        "constructor_generated_stop_reachable_in_fixture": False,
        "last_executed_byte_if_reached": f"0x{stop - 1:08x}",
    }
    (output / "report.json").write_text(
        json.dumps(report, indent=2) + "\n", encoding="utf-8"
    )
    print(f"Generated {len(prefix)} PE-verified instructions from "
          f"0x{ENTRY:08x}; boundary 0x{stop:08x} -> 0x{expected_target:08x}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--exe", required=True, type=Path)
    parser.add_argument("--batch", required=True, action="append", type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--through-first-call", action="store_true")
    parser.add_argument("--through-second-call", action="store_true")
    args = parser.parse_args()
    generate(args.exe, args.batch, args.output, args.through_first_call,
             args.through_second_call)
