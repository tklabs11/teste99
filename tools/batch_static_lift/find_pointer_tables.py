#!/usr/bin/env python3
"""Report runs of code pointers stored in a PE section.

The engine hands method pointers to code through tables in ``.rdata``, and those
calls are indirect: a recursive descent from a direct-call root never sees them,
so a measured batch stops at the first table entry it has to call. Reading the
tables straight out of the file gives the addresses that measurement must
include, taken from the binary instead of from a guess about which slot is used
next.

A run is a maximal sequence of 4-byte little-endian words that all point into an
executable section. Runs are printed with their bounds, their length and their
targets, and ``--into`` keeps only the runs that reach a chosen address range.
"""

import argparse
import json
import sys
from pathlib import Path

import BatchStaticLift as lifter


def code_spans(sections, image_base):
    """Virtual ranges of the executable sections, as half-open pairs."""

    spans = []
    for name, section_rva, virtual_size, _, raw_size in sections:
        if name.strip("\0") != ".text":
            continue
        base = image_base + section_rva
        spans.append((base, base + max(virtual_size, raw_size)))
    if not spans:
        raise SystemExit("no .text section: the image has no code to point at")
    return spans


def pointer_runs(words, base, spans):
    """Maximal runs of words that point into one of ``spans``.

    ``words`` holds one 4-byte word each, starting at ``base``. Returns
    ``(start, end, targets)`` per run, where ``end`` is exclusive.
    """

    def is_code(value):
        return any(low <= value < high for low, high in spans)

    runs = []
    index = 0
    while index < len(words):
        if not is_code(words[index]):
            index += 1
            continue
        start = index
        while index < len(words) and is_code(words[index]):
            index += 1
        runs.append((
            base + start * 4,
            base + index * 4,
            words[start:index],
        ))
    return runs


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--section", default=".rdata")
    parser.add_argument("--into", nargs=2, type=lambda v: int(v, 0),
                        metavar=("LO", "HI"),
                        help="keep runs with a target in this range")
    parser.add_argument("--min-entries", type=int, default=2)
    parser.add_argument("--json", type=Path)
    args = parser.parse_args()

    if lifter.sha256_file(args.reference) != lifter.EXPECTED_SHA256:
        raise SystemExit("reference PE hash does not match the verified build")
    pe = lifter.parse_pe(args.reference)
    image, image_base, sections = pe
    spans = code_spans(sections, image_base)
    selected = [
        section for section in sections
        if section[0].strip("\0") == args.section
    ]
    if not selected:
        raise SystemExit(f"the image has no {args.section} section")
    _, section_rva, virtual_size, _, raw_size = selected[0]
    base = image_base + section_rva
    size = min(virtual_size, raw_size)
    size -= size % 4
    _, _, data = lifter.read_pe_bytes(pe, base, size)
    words = [
        int.from_bytes(data[offset:offset + 4], "little")
        for offset in range(0, size, 4)
    ]
    runs = pointer_runs(words, base, spans)
    if args.into:
        low, high = args.into
        runs = [
            run for run in runs
            if any(low <= target < high for target in run[2])
        ]
    runs = [run for run in runs if len(run[2]) >= args.min_entries]
    targets = sorted({target for run in runs for target in run[2]})
    report = {
        "reference_sha256": lifter.EXPECTED_SHA256,
        "section": args.section,
        "code_spans": [f"0x{low:08x}..0x{high:08x}" for low, high in spans],
        "into": (
            [f"0x{args.into[0]:08x}", f"0x{args.into[1]:08x}"]
            if args.into else None),
        "run_count": len(runs),
        "pointer_count": sum(len(run[2]) for run in runs),
        "unique_targets": len(targets),
        "runs": [
            {
                "start": f"0x{start:08x}",
                "end": f"0x{end:08x}",
                "entries": len(run_targets),
                "targets": [f"0x{target:08x}" for target in run_targets],
            }
            for start, end, run_targets in runs
        ],
        "targets": [f"0x{target:08x}" for target in targets],
    }
    print(json.dumps(report, indent=2))
    if args.json:
        args.json.write_text(
            json.dumps(report, indent=2) + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    sys.exit(main())
