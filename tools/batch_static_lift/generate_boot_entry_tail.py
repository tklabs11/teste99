#!/usr/bin/env python3
"""Generate only the PE entry CALL and terminal JMP for a bounded test."""

import argparse
import json
from pathlib import Path

import BatchStaticLift as lifter


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--candidate", type=Path, required=True)
    parser.add_argument("--batch", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    reference_hash = lifter.sha256_file(args.reference)
    if reference_hash != lifter.EXPECTED_SHA256:
        parser.error("reference PE hash does not match the verified build")
    reference = lifter.parse_pe(args.reference)
    candidate = lifter.parse_pe(args.candidate)
    batch = json.loads(args.batch.read_text(encoding="utf-8"))
    entry = next(
        (record["function"] for record in batch["functions"]
         if record["function"]["entry"] == "0x011e11a0"),
        None,
    )
    if entry is None:
        parser.error("PE entry 0x011e11a0 is absent from the selected batch")
    original = lifter.validate_function_bytes(entry, reference)
    current = lifter.validate_function_bytes(entry, candidate)
    if original != current:
        parser.error("entry instruction records differ between PE builds")
    source, diagnostics = lifter.translate_function(
        entry, {0x011e1548, 0x011e0ee0}
    )
    if len(diagnostics) != 2 or any(
            item["status"] != "translated" for item in diagnostics):
        parser.error("both entry instructions must translate")

    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / "spore_011e11a0.cpp").write_text(
        source + "\n", encoding="utf-8"
    )
    entry_bytes = bytes.fromhex("".join(item["bytes"] for item in original))
    byte_literals = ", ".join(f"0x{value:02x}u" for value in entry_bytes)
    (args.output / "entry_bytes.hpp").write_text(
        "#pragma once\n#include <array>\n#include <cstdint>\n"
        f"inline constexpr std::array<std::uint8_t, {len(entry_bytes)}> "
        f"kVerifiedPeEntryBytes{{{byte_literals}}};\n",
        encoding="utf-8",
    )
    manifest = {
        "reference_sha256": reference_hash,
        "candidate_sha256": lifter.sha256_file(args.candidate),
        "entry": entry["entry"],
        "instructions": diagnostics,
        "verified_bytes": entry_bytes.hex(),
        "children_are_test_stubs": True,
        "scope": "entry CALL and terminal JMP only; cookie and CRT bodies not executed",
    }
    (args.output / "manifest.json").write_text(
        json.dumps(manifest, indent=2) + "\n", encoding="utf-8"
    )
    print("generated entry CALL/JMP from 10 verified PE bytes")


if __name__ == "__main__":
    main()
