#!/usr/bin/env python3
"""Compare exported closure instruction bytes across two Spore PE builds.

This is a static byte check, not a claim that indirect calls or boot work.
"""

import argparse
import hashlib
import json
from collections import defaultdict
from pathlib import Path

import pefile


def section_records(reference, candidate):
    records = []
    for left, right in zip(reference.sections, candidate.sections):
        name = left.Name.rstrip(b"\0").decode("ascii", "replace")
        left_bytes = reference.__data__[
            left.PointerToRawData:left.PointerToRawData + left.SizeOfRawData
        ]
        right_bytes = candidate.__data__[
            right.PointerToRawData:right.PointerToRawData + right.SizeOfRawData
        ]
        differences = [
            index for index, (a, b) in enumerate(zip(left_bytes, right_bytes))
            if a != b
        ]
        records.append({
            "name": name,
            "rva": f"0x{left.VirtualAddress:08x}",
            "same_layout": (
                left.Name == right.Name
                and left.VirtualAddress == right.VirtualAddress
                and left.PointerToRawData == right.PointerToRawData
            ),
            "reference_size": len(left_bytes),
            "candidate_size": len(right_bytes),
            "different_common_bytes": len(differences),
            "first_different_va": (
                f"0x{reference.OPTIONAL_HEADER.ImageBase + left.VirtualAddress + differences[0]:08x}"
                if differences else None
            ),
            "last_different_va": (
                f"0x{reference.OPTIONAL_HEADER.ImageBase + left.VirtualAddress + differences[-1]:08x}"
                if differences else None
            ),
        })
    return records


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--candidate", type=Path, required=True)
    parser.add_argument("--closure", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    closure = json.loads(args.closure.read_text(encoding="utf-8"))
    reference_bytes = args.reference.read_bytes()
    candidate_bytes = args.candidate.read_bytes()
    reference_hash = hashlib.sha256(reference_bytes).hexdigest()
    candidate_hash = hashlib.sha256(candidate_bytes).hexdigest()
    if reference_hash != closure["source_sha256"]:
        parser.error("reference PE hash differs from the closure source")

    reference = pefile.PE(data=reference_bytes, fast_load=True)
    candidate = pefile.PE(data=candidate_bytes, fast_load=True)
    same_pe_layout = (
        reference.FILE_HEADER.Machine == candidate.FILE_HEADER.Machine == 0x014c
        and reference.OPTIONAL_HEADER.ImageBase == candidate.OPTIONAL_HEADER.ImageBase
        and reference.OPTIONAL_HEADER.AddressOfEntryPoint
        == candidate.OPTIONAL_HEADER.AddressOfEntryPoint
        and len(reference.sections) == len(candidate.sections)
    )
    sections = section_records(reference, candidate)
    same_pe_layout = same_pe_layout and all(
        section["same_layout"] for section in sections
    )

    by_batch = defaultdict(set)
    for record in closure["functions"]:
        by_batch[record["batch"]].add(record["address"])
    checked_functions = checked_instructions = checked_bytes = mismatched = 0
    examples = []
    for batch_path, selected in by_batch.items():
        batch = json.loads(Path(batch_path).read_text(encoding="utf-8"))
        for record in batch["functions"]:
            function = record["function"]
            if function["entry"] not in selected:
                continue
            checked_functions += 1
            for instruction in function["instructions"]:
                address = int(instruction["address"], 16)
                encoded = bytes.fromhex(instruction["bytes"])
                reference_rva = address - reference.OPTIONAL_HEADER.ImageBase
                candidate_rva = address - candidate.OPTIONAL_HEADER.ImageBase
                original = reference.get_data(reference_rva, len(encoded))
                current = candidate.get_data(candidate_rva, len(encoded))
                checked_instructions += 1
                checked_bytes += len(encoded)
                if original != encoded or current != encoded:
                    mismatched += 1
                    if len(examples) < 20:
                        examples.append({
                            "function": function["entry"],
                            "address": instruction["address"],
                            "export": encoded.hex(),
                            "reference": original.hex(),
                            "candidate": current.hex(),
                        })

    result = {
        "reference_sha256": reference_hash,
        "candidate_sha256": candidate_hash,
        "same_pe_layout": same_pe_layout,
        "entry_va": f"0x{reference.OPTIONAL_HEADER.ImageBase + reference.OPTIONAL_HEADER.AddressOfEntryPoint:08x}",
        "sections": sections,
        "closure_functions": len(closure["functions"]),
        "checked_functions": checked_functions,
        "checked_instructions": checked_instructions,
        "checked_instruction_bytes": checked_bytes,
        "mismatched_instructions": mismatched,
        "mismatch_examples": examples,
        "scope": "exported direct-call-and-tail-jump closure only; indirect targets and resources unverified",
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(
        f"checked={checked_functions} functions, {checked_instructions} instructions, "
        f"{checked_bytes} bytes; mismatched={mismatched}; layout={same_pe_layout}"
    )
    return 0 if (same_pe_layout and checked_functions == len(closure["functions"])
                 and mismatched == 0) else 1


if __name__ == "__main__":
    raise SystemExit(main())
