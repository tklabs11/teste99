#!/usr/bin/env python3
"""Recover the C++ initializer closure for one table batch.

The CRT walks ``__xc_a..__xc_z`` in table order and calls every non-null entry,
so a batch is always a contiguous slice of that table. Each batch's closure is
recovered with Ghidra: every discovered direct call/jump target is first
resolved to its containing function, because engine code shares mid-function
blocks and lifting a partial block leaves its backward branches unresolved.

Round 1 disassembles the batch itself; later rounds disassemble only the newly
discovered roots. Everything is written under ``--output``: ``closure.json``
(the exported bodies), ``addresses.txt`` and ``summary.json``.
"""

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

import BatchStaticLift as lifter


CPP_INIT_TABLE = 0x013cc80c
CPP_INIT_TABLE_END = 0x013eb098
TEXT_LOW = 0x00401000
TEXT_HIGH = 0x013cbf2a


def table_targets(pe):
    _, _, data = lifter.read_pe_bytes(
        pe, CPP_INIT_TABLE, CPP_INIT_TABLE_END - CPP_INIT_TABLE)
    return [
        value for value in (
            int.from_bytes(data[offset:offset + 4], "little")
            for offset in range(0, len(data), 4)
        ) if value
    ]


def run_ghidra(ghidra, project, project_name, program, script_path, script,
               output, addresses):
    args = [ghidra, project, project_name, "-process", program,
            "-noanalysis", "-scriptPath", script_path,
            "-postScript", script, str(output)]
    args += [f"0x{address:08x}" for address in addresses]
    subprocess.run(args, capture_output=True, text=True, check=False)
    if not output.exists():
        raise SystemExit(f"Ghidra produced no output for {script}")
    return json.loads(output.read_text(encoding="utf-8"))


def direct_targets(function):
    """Direct code targets of one exported body, ignoring IAT calls."""

    found = set()
    indirect = []
    for instruction in function["instructions"]:
        if instruction["mnemonic"] not in ("CALL", "JMP"):
            continue
        operand = instruction["operands"][0] if instruction["operands"] else ""
        if re.fullmatch(r"dword ptr \[0x[0-9a-f]+\]", operand):
            continue
        if re.fullmatch(r"0x[0-9a-f]+", operand):
            target = int(operand, 16)
            if TEXT_LOW <= target < TEXT_HIGH:
                found.add(target)
            continue
        indirect.append(f"{instruction['mnemonic']} {operand}")
    return found, indirect


def import_symbols(function, iat):
    symbols = set()
    for instruction in function["instructions"]:
        if instruction["mnemonic"] != "CALL":
            continue
        operand = instruction["operands"][0] if instruction["operands"] else ""
        if re.fullmatch(r"dword ptr \[0x[0-9a-f]+\]", operand):
            slot = int(operand.split("[")[1].split("]")[0], 16)
            symbols.add(iat.get(slot, f"unknown-{slot:08x}"))
    return symbols


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--batch-index", type=int, default=1)
    parser.add_argument("--batch-size", type=int, default=256)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--ghidra", default=r"C:\Users\wesll\Documents"
                        r"\ghidra_12.1.4_PUBLIC\support\analyzeHeadless.bat")
    parser.add_argument("--project", default=r"C:\SporeAnalysis\SporeREA4G")
    parser.add_argument("--project-name", default="SporeREA4G")
    parser.add_argument("--program", default="SporeApp.exe")
    parser.add_argument("--script-path", default=r"C:\Users\wesll\ghidra_scripts")
    parser.add_argument("--rounds", type=int, default=12)
    parser.add_argument("--roots", action="append", default=[],
                        type=lambda value: int(value, 0),
                        help="walk from these addresses instead of a table slice")
    args = parser.parse_args()

    if lifter.sha256_file(args.reference) != lifter.EXPECTED_SHA256:
        parser.error("reference PE hash does not match the verified build")
    pe = lifter.parse_pe(args.reference)
    iat = lifter.parse_pe_iat_imports(pe)
    targets = table_targets(pe)
    start = (args.batch_index - 1) * args.batch_size
    if args.roots:
        batch = list(args.roots)
    else:
        batch = targets[start:start + args.batch_size]
    if not batch:
        parser.error("the requested batch is outside the table")
    args.output.mkdir(parents=True, exist_ok=True)

    known = {}
    imports = set()
    indirect = {}
    pending = list(batch)
    canonical = {}
    rounds = 0
    while pending and rounds < args.rounds:
        rounds += 1
        bodies = run_ghidra(
            args.ghidra, args.project, args.project_name, args.program,
            args.script_path, "DisassembleSporeRoutines.java",
            args.output / f"round{rounds}.json", pending)
        discovered = set()
        for record in bodies["functions"]:
            function = record["function"]
            known[int(function["entry"], 16)] = function
            imports |= import_symbols(function, iat)
            direct, notes = direct_targets(function)
            if notes:
                indirect[function["entry"]] = notes
            discovered |= direct
        # Every new root must be the function that contains it, not a shared
        # mid-function block.
        candidates = sorted(discovered - set(known))
        if candidates:
            resolved = run_ghidra(
                args.ghidra, args.project, args.project_name, args.program,
                args.script_path, "ResolveSporeFunctionEntries.java",
                args.output / f"resolve{rounds}.json", candidates)["addresses"]
            for item in resolved:
                address = int(item["address"], 16)
                root = item["function_containing"] or item["function_at"]
                root = int(root, 16) if root else address
                canonical[address] = root
            pending = sorted(
                {canonical.get(address, address) for address in candidates}
                - set(known))
        else:
            pending = []
        print(f"rodada {rounds}: corpos={len(bodies['functions'])} "
              f"acumulado={len(known)} novos={len(pending)}")

    closure = {"functions": [
        {"function": known[address]} for address in sorted(known)]}
    (args.output / "closure.json").write_text(
        json.dumps(closure, indent=1) + "\n", encoding="utf-8")
    (args.output / "addresses.txt").write_text(
        "\n".join(f"0x{address:08x}" for address in sorted(known)) + "\n",
        encoding="utf-8")
    instructions = sum(len(fn["instructions"]) for fn in known.values())
    truncated = sorted(
        address for address, fn in known.items()
        if fn.get("instructions_truncated"))
    summary = {
        "batch_index": args.batch_index,
        "batch_size": len(batch),
        "table_slice": [f"0x{batch[0]:08x}", f"0x{batch[-1]:08x}"],
        "next_table_entry": (
            f"0x{targets[start + len(batch)]:08x}" if not args.roots else None),
        "roots": len(known),
        "initializers_in_batch": len(batch),
        "helper_roots": len(set(known) - set(batch)),
        "instructions": instructions,
        "imports": sorted(imports),
        "canonicalised_targets": {
            f"0x{address:08x}": f"0x{root:08x}"
            for address, root in sorted(canonical.items())
            if root != address
        },
        "truncated_exports": [f"0x{address:08x}" for address in truncated],
        "indirect_calls": indirect,
    }
    (args.output / "summary.json").write_text(
        json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    print(f"closure do lote {args.batch_index}: {len(known)} corpos, "
          f"{instructions} instruções, {len(imports)} imports, "
          f"{len(summary['canonicalised_targets'])} alvos canonicalizados, "
          f"{len(truncated)} exports truncados")


if __name__ == "__main__":
    main()
