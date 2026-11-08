#!/usr/bin/env python3
"""Emit the lifted CRT C-initializer closure that `_initterm_e` runs.

Bodies come from the verified batch plus the records recovered with
tools/ghidra_scripts (Ghidra had never analysed these CRT routines). Three
call targets are import thunks, so their call sites become import calls and no
thunk body is lifted.
"""

import argparse
import json
from pathlib import Path

import BatchStaticLift as lifter


# The table entries _initterm_e receives at 0x011e0f6f.
INITIALIZERS = (0x011e10bf, 0x011e1304, 0x011e135a)

# Call targets that are plain `JMP [IAT]` thunks: (thunk, iat, symbol).
THUNKS = {
    0x011e1312: (0x013cc340, "MSVCR90.dll!?terminate@@YAXXZ"),
    0x011e16f6: (0x013cc2f0, "MSVCR90.dll!_controlfp_s"),
    0x011e16f0: (0x013cc2f4, "MSVCR90.dll!_invoke_watson"),
}


def cpp_name(entry):
    return f"spore_{entry:08x}.cpp"


def load_functions(paths):
    functions = {}
    for path in paths:
        batch = json.loads(path.read_text(encoding="utf-8"))
        for record in batch["functions"]:
            function = record["function"]
            functions[lifter.parse_address(function["entry"])] = function
    return functions


def closure_of(functions):
    """Walk direct calls from the initializer table, stopping at import thunks."""
    pending = list(INITIALIZERS)
    selected = {}
    unresolved = set()
    while pending:
        entry = pending.pop()
        if entry in selected:
            continue
        if entry in THUNKS:
            continue
        function = functions.get(entry)
        if function is None:
            unresolved.add(entry)
            continue
        selected[entry] = function
        for instruction in function["instructions"]:
            if instruction["mnemonic"].upper() != "CALL":
                continue
            try:
                target = lifter.direct_call_target(instruction)
            except ValueError:
                continue
            if target not in selected:
                pending.append(target)
    return selected, unresolved


def call_sites(functions):
    for entry, function in functions.items():
        for instruction in function["instructions"]:
            if instruction["mnemonic"].upper() != "CALL":
                continue
            try:
                target = lifter.direct_call_target(instruction)
            except ValueError:
                continue
            yield entry, lifter.parse_address(instruction["address"]), target


def verify_thunk(pe, iat_imports, thunk, iat, symbol):
    _, _, encoded = lifter.read_pe_bytes(pe, thunk, 6)
    expected = b"\xff\x25" + iat.to_bytes(4, "little")
    if encoded != expected:
        raise SystemExit(
            f"0x{thunk:08x} is not JMP [0x{iat:08x}]")
    if iat_imports.get(iat) != symbol:
        raise SystemExit(f"IAT 0x{iat:08x} is not {symbol}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--candidate", type=Path, required=True)
    parser.add_argument("--batch", type=Path, required=True)
    parser.add_argument("--extra-batch", type=Path, action="append", default=[])
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    reference_hash = lifter.sha256_file(args.reference)
    if reference_hash != lifter.EXPECTED_SHA256:
        parser.error("reference PE hash does not match the verified build")
    reference = lifter.parse_pe(args.reference)
    candidate = lifter.parse_pe(args.candidate)
    iat_imports = lifter.parse_pe_iat_imports(reference)
    functions = load_functions([args.batch, *args.extra_batch])
    selected, unresolved = closure_of(functions)
    missing = [f"0x{entry:08x}" for entry in INITIALIZERS
               if entry not in functions]
    if missing:
        parser.error(f"initializer records are missing: {', '.join(missing)}")
    if unresolved:
        parser.error("closure needs records for: " + ", ".join(
            f"0x{entry:08x}" for entry in sorted(unresolved)))
    for thunk, (iat, symbol) in THUNKS.items():
        verify_thunk(reference, iat_imports, thunk, iat, symbol)

    aliases = {}
    for owner, address, target in call_sites(selected):
        if target in THUNKS:
            iat, symbol = THUNKS[target]
            aliases[address] = (target, symbol, iat)

    exported = set(selected)
    args.output.mkdir(parents=True, exist_ok=True)
    emitted = []
    imports = set()
    for entry in sorted(selected):
        function = selected[entry]
        if (lifter.validate_function_bytes(function, reference)
                != lifter.validate_function_bytes(function, candidate)):
            parser.error(
                f"0x{entry:08x} differs between the two PE builds")
        try:
            source, diagnostics = lifter.translate_function(
                function,
                exported_function_entries=exported,
                iat_imports=iat_imports,
                direct_import_aliases=aliases,
            )
        except lifter.LiftRejected as error:
            parser.error(f"0x{entry:08x} is not translatable: {error.reasons}")
        (args.output / cpp_name(entry)).write_text(source + "\n",
                                                   encoding="utf-8")
        emitted.append({
            "entry": f"0x{entry:08x}",
            "source": cpp_name(entry),
            "instructions": len(function["instructions"]),
            "translated": sum(1 for item in diagnostics
                              if item["status"] == "translated"),
        })
        for symbol in _symbols(function, iat_imports, aliases):
            imports.add(symbol)

    header = ["#pragma once", "#include <cstdint>"]
    for entry in sorted(selected):
        header.append(
            f"BatchLiftStatus spore_lift_{entry:08x}("
            "BatchLiftMemory& memory, BatchLiftState& state);")
    header.append("")
    for index, entry in enumerate(INITIALIZERS):
        header.append(
            f"inline constexpr std::uint32_t kCrtInitializer{index} = "
            f"0x{entry:08x}u;")
    (args.output / "closure_entries.hpp").write_text(
        "\n".join(header) + "\n", encoding="utf-8")
    manifest = {
        "reference_sha256": reference_hash,
        "candidate_sha256": lifter.sha256_file(args.candidate),
        "initializers": [f"0x{entry:08x}" for entry in INITIALIZERS],
        "functions": emitted,
        "instruction_total": sum(item["instructions"] for item in emitted),
        "import_aliases": sorted(
            f"0x{address:08x}->{symbol}" for address, (_, symbol, _)
            in aliases.items()),
        "imports": sorted(imports),
    }
    (args.output / "manifest.json").write_text(
        json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(
        f"translated {len(emitted)} routines "
        f"({manifest['instruction_total']} instructions), "
        f"{len(imports)} imports, {len(aliases)} thunk call sites")


def _symbols(function, iat_imports, aliases):
    found = set()
    for instruction in function["instructions"]:
        address = lifter.parse_address(instruction["address"])
        if address in aliases:
            found.add(aliases[address][1])
            continue
        imported = lifter.indirect_iat_import(instruction, iat_imports)
        if imported is not None:
            found.add(imported["symbol"])
    return found


if __name__ == "__main__":
    main()
