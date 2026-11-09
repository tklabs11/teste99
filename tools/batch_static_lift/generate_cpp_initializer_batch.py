#!/usr/bin/env python3
"""Lift the CRT helper chain one batch of initializers needs.

A batch runs in table order and stops at the first requirement it cannot
satisfy. This generator lifts exactly what the batch needs:

- roots: the batch's initializers, in table order;
- CRT helpers (``0x011e0000..0x011effff``) are followed transitively, because
  they belong to the runtime the port already reproduces;
- an engine body is followed only when ``--engine-body`` names it, so entering
  engine code is always an explicit decision recorded on the command line;
- anything else outside that range stays unregistered, so the walk fails closed
  there and names it.

Every body is byte-validated against both PE builds. Output:
``spore_<address>.cpp`` files, ``batch_entries.hpp`` and ``manifest.json``.
"""

import argparse
import json
import re
from pathlib import Path

import BatchStaticLift as lifter


CPP_INIT_TABLE = 0x013cc80c
CPP_INIT_TABLE_END = 0x013eb098
CRT_LOW = 0x011e0000
CRT_HIGH = 0x011f0000
TEXT_LOW = 0x00401000
TEXT_HIGH = 0x013cbf2a


def body_map(closure):
    return {
        int(record["function"]["entry"], 16): record["function"]
        for record in closure["functions"]
    }


def table_targets(pe):
    _, _, data = lifter.read_pe_bytes(
        pe, CPP_INIT_TABLE, CPP_INIT_TABLE_END - CPP_INIT_TABLE)
    return [
        value for value in (
            int.from_bytes(data[offset:offset + 4], "little")
            for offset in range(0, len(data), 4)
        ) if value
    ]


def direct_calls(function):
    direct, indirect = [], []
    for instruction in function["instructions"]:
        if instruction["mnemonic"] not in ("CALL", "JMP"):
            continue
        operand = instruction["operands"][0] if instruction["operands"] else ""
        if re.fullmatch(r"dword ptr \[0x[0-9a-f]+\]", operand):
            continue
        if re.fullmatch(r"0x[0-9a-f]+", operand):
            target = int(operand, 16)
            if TEXT_LOW <= target < TEXT_HIGH:
                direct.append(target)
            continue
        indirect.append(
            f"0x{int(instruction['address'], 16):08x}: "
            f"{instruction['mnemonic']} {operand}")
    return direct, indirect


def imports_of(function, iat):
    symbols = set()
    for instruction in function["instructions"]:
        if instruction["mnemonic"] != "CALL":
            continue
        operand = instruction["operands"][0] if instruction["operands"] else ""
        if re.fullmatch(r"dword ptr \[0x[0-9a-f]+\]", operand):
            slot = int(operand.split("[")[1].split("]")[0], 16)
            symbols.add(iat.get(slot, f"unknown-{slot:08x}"))
    return symbols


def thunk_symbol(function, iat):
    """Return the import symbol when a body is only ``JMP [IAT]``."""

    instructions = function["instructions"]
    if len(instructions) != 1 or instructions[0]["mnemonic"] != "JMP":
        return None
    operand = instructions[0]["operands"][0] if instructions[0]["operands"] else ""
    match = re.fullmatch(r"dword ptr \[(0x[0-9a-f]+)\]", operand)
    if match is None:
        return None
    return iat.get(int(match.group(1), 16))


def lifted_instruction_addresses(required, bodies):
    """Every instruction address inside the bodies this batch lifts."""
    return {
        int(instruction["address"], 16)
        for address in required
        for instruction in bodies[address]["instructions"]
    }


def call_sites_to(function):
    """(call address, target) for every direct CALL in a body."""

    sites = []
    for instruction in function["instructions"]:
        if instruction["mnemonic"] != "CALL":
            continue
        operand = instruction["operands"][0] if instruction["operands"] else ""
        if re.fullmatch(r"0x[0-9a-f]+", operand):
            sites.append((int(instruction["address"], 16), int(operand, 16)))
    return sites


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--candidate", type=Path, required=True)
    parser.add_argument("--closure", type=Path, required=True,
                        help="closure.json from prepare_cpp_initializer_batch")
    parser.add_argument("--initializers", type=int, default=6,
                        help="how many table initializers to lift, in order")
    parser.add_argument("--engine-body", action="append", default=[],
                        type=lambda value: int(value, 0),
                        help="engine body to lift and follow (repeatable)")
    parser.add_argument("--bodies", type=int, default=0,
                        help="lift at most this many bodies, closest first")
    parser.add_argument("--allow-unresolved", action="store_true",
                        help="dispatch a call to an unlifted body instead of "
                             "rejecting the batch")
    parser.add_argument("--follow-range", action="append", default=[],
                        type=lambda value: tuple(
                            int(part, 0) for part in value.split(":")),
                        help="low:high code range followed like the CRT range")
    parser.add_argument("--follow-outside", action="store_true",
                        help="follow every direct target, so --bodies alone "
                             "bounds the batch")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    if lifter.sha256_file(args.reference) != lifter.EXPECTED_SHA256:
        parser.error("reference PE hash does not match the verified build")
    reference = lifter.parse_pe(args.reference)
    candidate = lifter.parse_pe(args.candidate)
    iat = lifter.parse_pe_iat_imports(reference)
    bodies = body_map(json.loads(args.closure.read_text(encoding="utf-8")))
    targets = table_targets(reference)
    roots = targets[:args.initializers]

    required, engine, missing, seen, thunks = [], set(), [], set(), {}
    unresolved = set()
    engine_roots = set(args.engine_body)
    # An engine body the batch must include can be reachable only through a
    # function pointer, so it is seeded rather than discovered. The command line
    # order is the priority order when --bodies caps the batch.
    pending = list(args.engine_body) + list(roots)
    while pending:
        address = pending.pop(0)
        if address in seen:
            continue
        seen.add(address)
        function = bodies.get(address)
        if function is None:
            missing.append(address)
            continue
        symbol = thunk_symbol(function, iat)
        if symbol is not None:
            # An import thunk is not a body: its call sites become import
            # calls, exactly like the boot prefix does for other thunks.
            thunks[address] = symbol
            continue
        if args.bodies and len(required) >= args.bodies:
            # The batch is capped: this reachable body stays unlifted and its
            # callers dispatch to it, which is the runtime batch boundary.
            unresolved.add(address)
            continue
        required.append(address)
        direct, _ = direct_calls(function)
        for target in direct:
            if CRT_LOW <= target < CRT_HIGH:
                pending.append(target)
            elif args.follow_outside:
                # Reachability, not address range, decides what belongs to the
                # batch: the caller caps it with --bodies.
                pending.append(target)
            elif any(low <= target < high
                     for low, high in args.follow_range):
                # The image's own statically linked runtime: followed exactly
                # like the CRT range, because it is runtime code.
                pending.append(target)
            elif target in engine_roots:
                pending.append(target)
            elif target not in roots:
                engine.add(target)

    for address in required:
        lifter.validate_function_bytes(bodies[address], reference)
        lifter.validate_function_bytes(bodies[address], candidate)

    # A direct CALL or JMP that lands inside a body being lifted is local
    # control flow, not a request for another body.
    local = lifted_instruction_addresses(required, bodies)
    engine = {target for target in engine if target not in local}
    # Direct calls a lifted body makes to an address it does not lift: the
    # dispatcher resolves them at runtime, and one of them is where the walk
    # will stop.
    pending_bodies = sorted({
        target for address in required
        for target in direct_calls(bodies[address])[0]
        if target not in set(required) and target not in thunks
        and target not in local
    })

    entries = set(required)
    engine = {target for target in engine if target not in thunks}
    args.output.mkdir(parents=True, exist_ok=True)
    failures = []
    for address in sorted(entries):
        aliases = {}
        for call_address, target in call_sites_to(bodies[address]):
            if target in thunks:
                iat_slot = next(
                    slot for slot, name in iat.items()
                    if name == thunks[target])
                aliases[call_address] = (target, thunks[target], iat_slot)
        try:
            source, _ = lifter.translate_function(
                bodies[address], exported_function_entries=entries,
                iat_imports=iat, direct_import_aliases=aliases or None,
                allow_unresolved_calls=args.allow_unresolved)
        except lifter.LiftRejected as error:
            failures.append({
                "entry": f"0x{address:08x}",
                "reasons": list(getattr(error, "reasons", [])),
            })
            continue
        (args.output / f"spore_{address:08x}.cpp").write_text(
            source + "\n", encoding="utf-8")
    if failures:
        (args.output / "manifest.json").write_text(
            json.dumps({"failures": failures}, indent=2) + "\n",
            encoding="utf-8")
        for item in failures:
            print(f"FALHOU {item['entry']}: {item['reasons'][:2]}")
        raise SystemExit("the batch closure is not fully translatable")

    symbols = sorted({
        symbol for address in entries
        for symbol in imports_of(bodies[address], iat)
    } | set(thunks.values()))
    blocker = f"0x{min(engine):08x}u" if engine else "0u"

    declarations = "\n".join(
        f"BatchLiftStatus spore_lift_{address:08x}("
        "BatchLiftMemory& memory, BatchLiftState& state);"
        for address in sorted(entries))
    header = "\n".join([
        "#pragma once",
        "#include <cstdint>",
        "",
        declarations,
        "",
        "// Initializers this batch registers, in table order.",
        "inline constexpr std::uint32_t kBatchInitializers[] = {",
        "    " + ", ".join(f"0x{address:08x}u" for address in roots) + ",",
        "};",
        f"inline constexpr std::uint32_t kBatchInitializerCount = "
        f"{len(roots)}u;",
        "",
        "// The first table initializer this batch does not register: the walk",
        "// must stop exactly there.",
        f"inline constexpr std::uint32_t kBatchNextInitializer = "
        f"0x{targets[len(roots)]:08x}u;",
        "",
        "// The first engine body the batch needs, and every lifted body entry.",
        f"inline constexpr std::uint32_t kBatchEngineBlocker = {blocker};",
        "",
        "// Lifted bodies call these through the dispatcher because the batch does",
        "// not lift them: the walk stops at the first one it actually reaches.",
        "// The placeholder entry only exists because C++ forbids an empty array;",
        "// kBatchPendingBodyCount is zero when there is nothing pending.",
        "inline constexpr std::uint32_t kBatchPendingBodies[] = {",
        ("    " + ", ".join(f"0x{address:08x}u" for address in pending_bodies)
         + ",") if pending_bodies else "    0u,",
        "};",
        f"inline constexpr std::uint32_t kBatchPendingBodyCount = "
        f"{len(pending_bodies)}u;",
        "struct BatchBodyEntry {",
        "    std::uint32_t entry;",
        "    BatchLiftStatus (*body)(BatchLiftMemory&, BatchLiftState&);",
        "};",
        "inline constexpr BatchBodyEntry kBatchBodyTable[] = {",
        *[f"    {{0x{address:08x}u, &spore_lift_{address:08x}}},"
          for address in sorted(entries)],
        "};",
    ]) + "\n"
    (args.output / "batch_entries.hpp").write_text(header, encoding="utf-8")
    manifest = {
        "initializers": [f"0x{value:08x}" for value in roots],
        "bodies": [f"0x{address:08x}" for address in sorted(entries)],
        "instructions": sum(len(bodies[address]["instructions"])
                            for address in entries),
        "imports": symbols,
        "next_initializer": f"0x{targets[len(roots)]:08x}",
        "engine_blockers": [f"0x{value:08x}" for value in sorted(engine)],
        "pending_bodies": [f"0x{value:08x}" for value in pending_bodies],
        "missing_bodies": [f"0x{value:08x}" for value in sorted(missing)],
    }
    (args.output / "manifest.json").write_text(
        json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(f"lote gerado: {len(roots)} inicializadores, {len(entries)} corpos, "
          f"{manifest['instructions']} instruções, {len(symbols)} imports, "
          f"pendentes {len(pending_bodies)}, "
          f"bloqueio de engine {manifest['engine_blockers'][:1]}")


if __name__ == "__main__":
    main()
