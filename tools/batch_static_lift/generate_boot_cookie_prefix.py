#!/usr/bin/env python3
"""Verify and emit the initial security-cookie path up to its first Win32 call."""

import argparse
import json
from pathlib import Path

import BatchStaticLift as lifter


ENTRY = 0x011e1548
BOUNDARY = 0x011e157f
ALTERNATE_BRANCH_GUARD = 0x011e1578
DATA_ADDRESS = 0x015cfe70


def cpp_array(name, values):
    literals = ", ".join(f"0x{value:02x}u" for value in values)
    return (f"inline constexpr std::array<std::uint8_t, {len(values)}> "
            f"{name}{{{literals}}};")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--candidate", type=Path, required=True)
    parser.add_argument("--batch", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--include-time-call", action="store_true",
                        help="translate the verified Win32 call and stop at 0x011e1585")
    args = parser.parse_args()

    reference_hash = lifter.sha256_file(args.reference)
    if reference_hash != lifter.EXPECTED_SHA256:
        parser.error("reference PE hash does not match the verified build")
    reference = lifter.parse_pe(args.reference)
    candidate = lifter.parse_pe(args.candidate)
    batch = json.loads(args.batch.read_text(encoding="utf-8"))
    function = next(
        (record["function"] for record in batch["functions"]
         if lifter.parse_address(record["function"]["entry"]) == ENTRY),
        None,
    )
    if function is None:
        parser.error("security-cookie function is absent from the selected batch")
    original = lifter.validate_function_bytes(function, reference)
    current = lifter.validate_function_bytes(function, candidate)
    if original != current:
        parser.error("security-cookie instruction bytes differ between PE builds")
    original_data = lifter.read_pe_bytes(reference, DATA_ADDRESS, 8)[2]
    current_data = lifter.read_pe_bytes(candidate, DATA_ADDRESS, 8)[2]
    if original_data != current_data or original_data[:4] != b"N\xe6@\xbb":
        parser.error("initial PE security-cookie data differs between builds")

    by_address = {
        lifter.parse_address(item["address"]): item
        for item in function["instructions"]
    }
    time_call = by_address.get(BOUNDARY)
    if (time_call is None or time_call.get("mnemonic", "").upper() != "CALL"
            or time_call.get("operands") != ["dword ptr [0x013cc1cc]"]
            or time_call.get("bytes") != "ff15ccc13c01"):
        parser.error("first Win32 call is not the expected boundary")
    iat_imports = lifter.parse_pe_iat_imports(reference)
    if iat_imports.get(0x013cc1cc) != "KERNEL32.dll!GetSystemTimeAsFileTime":
        parser.error("first Win32 call has an unexpected IAT target")
    boundary_address = BOUNDARY + (time_call["length"] if args.include_time_call else 0)
    boundary = by_address.get(boundary_address)
    if boundary is None:
        parser.error("cookie boundary instruction is absent")
    prefix = [
        by_address[address] for address in sorted(by_address)
        if address < boundary_address
    ]
    cursor = ENTRY
    for instruction in prefix:
        if lifter.parse_address(instruction["address"]) != cursor:
            parser.error(f"gap in cookie prefix at 0x{cursor:08x}")
        cursor += instruction["length"]
    if cursor != boundary_address:
        parser.error("cookie prefix does not reach the first Win32 call")

    address_set = {lifter.parse_address(item["address"]) for item in prefix}
    address_set.add(boundary_address)
    translated = []
    for index, instruction in enumerate(prefix):
        address = lifter.parse_address(instruction["address"])
        next_address = address + instruction["length"]
        if address == ALTERNATE_BRANCH_GUARD:
            body = [
                f"state.eip = 0x{address:08x}u;",
                "return BatchLiftStatus::unsupported_dependency;",
            ]
        else:
            body = lifter.translate_instruction(
                instruction, index, address_set, next_address,
                iat_imports=iat_imports,
            )
        translated.append((instruction, body))
    source = lifter.static_source(
        function, translated, [],
        terminal_status=(boundary_address, "unsupported_dependency"),
    )
    raw = b"".join(bytes.fromhex(item["bytes"]) for item in prefix)
    raw += bytes.fromhex(boundary["bytes"])
    if len(raw) != boundary_address - ENTRY + boundary["length"]:
        parser.error("cookie raw byte span has an unexpected length")

    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / "spore_011e1548_prefix.cpp").write_text(
        source + "\n", encoding="utf-8"
    )
    (args.output / "cookie_reference_bytes.hpp").write_text(
        "#pragma once\n#include <array>\n#include <cstdint>\n"
        + cpp_array("kCookieCodeBytes", raw) + "\n"
        + cpp_array("kCookieInitialData", original_data) + "\n",
        encoding="utf-8",
    )
    manifest = {
        "reference_sha256": reference_hash,
        "candidate_sha256": lifter.sha256_file(args.candidate),
        "function": f"0x{ENTRY:08x}",
        "boundary": f"0x{boundary_address:08x}",
        "verified_function_instructions": len(original),
        "prefix_instructions_before_boundary": len(prefix),
        "prefix_bytes_including_boundary": len(raw),
        "alternate_branch_guard": f"0x{ALTERNATE_BRANCH_GUARD:08x}",
        "initial_data_address": f"0x{DATA_ADDRESS:08x}",
        "initial_data_bytes": original_data.hex(),
        "time_call": "0x011e157f KERNEL32.dll!GetSystemTimeAsFileTime",
        "scope": ("original initial cookie data, first Win32 call executed"
                  if args.include_time_call else
                  "original initial cookie data, no Win32 call executed"),
    }
    (args.output / "manifest.json").write_text(
        json.dumps(manifest, indent=2) + "\n", encoding="utf-8"
    )
    print(f"generated {len(prefix)} cookie prefix records to 0x{boundary_address:08x}")


if __name__ == "__main__":
    main()
