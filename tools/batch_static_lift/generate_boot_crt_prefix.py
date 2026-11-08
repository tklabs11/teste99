#!/usr/bin/env python3
"""Emit the verified ___tmainCRTStartup prefix behind the entry JMP.

Every stage shares the same verified bytes and adds one more boundary:

- ``seh-call-boundary`` stops before ``0x011e0ee7 -> __SEH_prolog4``.
- ``startupinfo-call`` executes that call and the whole ``__SEH_prolog4``
  body, then ``0x011e0ef8 -> KERNEL32!GetStartupInfoA`` at ``0x011e0efe``.
- ``interlocked-call`` adds ``0x011e0f1e -> InterlockedCompareExchange``.
- ``startup-lock`` adds the startup-state read at ``0x011e0f43``.
- ``initterm-call`` stops on ``0x011e0f6f -> MSVCR90!_initterm_e``.
- ``initterm-executed`` runs the table walk through the shim and lands on
  ``0x011e0f85`` with the initializer result in EAX.
"""

import argparse
import json
from pathlib import Path

import BatchStaticLift as lifter


CRT_ENTRY = 0x011e0ee0
SEH_PROLOG = 0x011e11d4
SEH_PROLOG_END = 0x011e1219

SEH_CALL = 0x011e0ee7
SEH_CALL_BYTES = "e8e8020000"
STARTUPINFO_CALL = 0x011e0ef8
STARTUPINFO_CALL_BYTES = "ff159cc23c01"
STARTUPINFO_IAT = 0x013cc29c
STARTUPINFO_SYMBOL = "KERNEL32.dll!GetStartupInfoA"
AFTER_STARTUPINFO = 0x011e0efe

INTERLOCKED_CALL = 0x011e0f1e
INTERLOCKED_CALL_BYTES = "ff1594c13c01"
INTERLOCKED_IAT = 0x013cc194
INTERLOCKED_SYMBOL = "KERNEL32.dll!InterlockedCompareExchange"
AFTER_INTERLOCKED = 0x011e0f24
STARTUP_STATE_AFTER_LOCK = 0x011e0f43

# Both call targets are import thunks; the lifter rewrites the direct CALLs into
# import calls, so their bodies never need to be lifted.
AMSG_EXIT_THUNK = 0x011e1368
AMSG_EXIT_CALL = 0x011e0f4e
AMSG_EXIT_THUNK_BYTES = "ff253cc33c01"
AMSG_EXIT_IAT = 0x013cc33c
AMSG_EXIT_SYMBOL = "MSVCR90.dll!_amsg_exit"
INITTERM_THUNK = 0x011e1514
INITTERM_CALL = 0x011e0f6f
INITTERM_CALL_BYTES = "e8a0050000"
INITTERM_THUNK_BYTES = "ff251cc33c01"
INITTERM_IAT = 0x013cc31c
INITTERM_SYMBOL = "MSVCR90.dll!_initterm_e"
INITTERM_TABLE = 0x013eb09c
INITTERM_TABLE_END = 0x013eb0ac
# After the table walk returns, the CRT pops both push arguments, tests the
# result and jumps over the fatal path onto the startup-state read.
INITTERM_EXECUTED = 0x011e0f85
# With the state at __initializing the CRT walks the C++ initializer table.
INITTERM_WALK_THUNK = 0x011e150e
INITTERM_WALK_CALL = 0x011e0f98
INITTERM_WALK_CALL_BYTES = "e871050000"
INITTERM_WALK_THUNK_BYTES = "ff2520c33c01"
INITTERM_WALK_IAT = 0x013cc320
INITTERM_WALK_SYMBOL = "MSVCR90.dll!_initterm"
CPP_INIT_TABLE = 0x013cc80c
CPP_INIT_TABLE_END = 0x013eb098
CPP_INIT_TABLE_HEAD_BYTES = 0x40

# The CRT lock uses these .data globals through absolute operands. Both live
# past SizeOfRawData, so the loader zero-fills them and the guest maps zeros.
STARTUP_LOCK_REGION = 0x0171e740
STARTUP_LOCK_REGION_BYTES = 0x20
STARTUP_STATE = 0x0171e74c
STARTUP_LOCK = 0x0171e750

STAGES = {
    "seh-call-boundary": {
        "boundary": SEH_CALL,
        "include": set(),
        "emit_prolog": False,
        "executed": 2,
    },
    "startupinfo-call": {
        "boundary": AFTER_STARTUPINFO,
        "include": {SEH_PROLOG},
        "emit_prolog": True,
        "executed": 9,
    },
    "interlocked-call": {
        "boundary": AFTER_INTERLOCKED,
        "include": {SEH_PROLOG},
        "emit_prolog": True,
        "executed": 18,
    },
    "startup-lock": {
        "boundary": STARTUP_STATE_AFTER_LOCK,
        "include": {SEH_PROLOG},
        "emit_prolog": True,
        # 9 instructions up to the compare-exchange plus 0x0f24, 0x0f26, 0x0f40
        # and 0x0f42; the 9 instruction _amsg_exit block is not taken.
        "executed": 13,
    },
    "initterm-call": {
        "boundary": INITTERM_CALL,
        "include": {SEH_PROLOG},
        "emit_prolog": True,
        # The 13 above plus 0x0f43, 0x0f48, 0x0f4a, 0x0f56, 0x0f5b, 0x0f5d,
        # 0x0f5f, 0x0f65 and 0x0f6a.
        "executed": 22,
    },
    "initterm-executed": {
        "boundary": INITTERM_EXECUTED,
        # __SEH_prolog4 is declared here but its body comes from the closure
        # build, so this stage emits no spore_011e11d4.cpp of its own.
        "include": {SEH_PROLOG},
        "emit_prolog": False,
        "prolog_counted": True,
        # The 22 above plus the _initterm_e call it now resolves through the
        # shim, the two POPs, the TEST and the JZ that lands on the boundary.
        "executed": 27,
    },
    "startup-state-initializing": {
        "boundary": INITTERM_WALK_CALL,
        "include": {SEH_PROLOG},
        "emit_prolog": False,
        "prolog_counted": True,
        # The 27 above plus 0x0f85, 0x0f8a, 0x0f8c and the two PUSHes that
        # prepare the C++ initializer table for _initterm.
        "executed": 32,
    },
    "cpp-walk-initializers": {
        # Same verified boundary; the harness then drives the _initterm call
        # itself with this batch's lifted bodies registered.
        "boundary": INITTERM_WALK_CALL,
        "include": {SEH_PROLOG},
        "emit_prolog": False,
        "prolog_counted": True,
        "executed": 32,
        "cpp_walk": True,
    },
}

ALIASES = {
    AMSG_EXIT_CALL: (AMSG_EXIT_THUNK, AMSG_EXIT_SYMBOL, AMSG_EXIT_IAT),
    INITTERM_CALL: (INITTERM_THUNK, INITTERM_SYMBOL, INITTERM_IAT),
    INITTERM_WALK_CALL: (INITTERM_WALK_THUNK, INITTERM_WALK_SYMBOL,
                         INITTERM_WALK_IAT),
}


def cpp_array(name, values):
    literals = ", ".join(f"0x{value:02x}u" for value in values)
    return (f"inline constexpr std::array<std::uint8_t, {len(values)}> "
            f"{name}{{{literals}}};")


def translate_prefix(instructions, boundary, exported_entries, iat_imports,
                     aliases=None):
    addresses = {
        lifter.parse_address(item["address"]) for item in instructions
    }
    addresses.add(boundary)
    exit_targets = {
        lifter.parse_address(target) for instruction in instructions
        for target in instruction.get("flows_to", [])
        if not target.startswith("0xEXTERNAL")
        and lifter.parse_address(target) > boundary
    }
    addresses |= exit_targets
    translated = []
    for index, instruction in enumerate(instructions):
        address = lifter.parse_address(instruction["address"])
        body = lifter.translate_instruction(
            instruction, index, addresses, address + instruction["length"],
            exported_function_entries=exported_entries,
            iat_imports=iat_imports,
            direct_import_aliases=aliases,
        )
        translated.append((instruction, body))
    return translated, exit_targets


def region_is_bss(pe, address, size):
    image, image_base, sections = pe
    rva = address - image_base
    for _, section_rva, virtual_size, _, raw_size in sections:
        if section_rva <= rva < section_rva + virtual_size:
            return rva + size <= section_rva + virtual_size \
                and rva >= section_rva + raw_size
    return False


def verify_thunks(parser, pe, iat_imports, by_address, aliases):
    for call_address, (thunk, symbol, iat_address) in sorted(aliases.items()):
        instruction = by_address.get(call_address)
        if instruction is None:
            parser.error(f"call site 0x{call_address:08x} is absent")
        if lifter.direct_call_target(instruction) != thunk:
            parser.error(
                f"call site 0x{call_address:08x} no longer targets "
                f"0x{thunk:08x}")
        _, _, encoded = lifter.read_pe_bytes(pe, thunk, 6)
        expected = b"\xff\x25" + iat_address.to_bytes(4, "little")
        if encoded != expected:
            parser.error(
                f"thunk 0x{thunk:08x} is not JMP [0x{iat_address:08x}]")
        if iat_imports.get(iat_address) != symbol:
            parser.error(
                f"IAT slot 0x{iat_address:08x} is not {symbol}")


def initterm_table(pe):
    _, _, data = lifter.read_pe_bytes(
        pe, INITTERM_TABLE, INITTERM_TABLE_END - INITTERM_TABLE)
    return [
        int.from_bytes(data[offset:offset + 4], "little")
        for offset in range(0, len(data), 4)
    ]


def initterm_table_is_valid(pe):
    entries = initterm_table(pe)
    return (
        len(entries) == 4
        and entries[0] == 0
        and all(entry == 0 or entry >= 0x00400000 for entry in entries)
    )


def cpp_initializer_targets(pe):
    """Every non-null target in the C++ initializer table _initterm walks."""

    _, _, data = lifter.read_pe_bytes(
        pe, CPP_INIT_TABLE, CPP_INIT_TABLE_END - CPP_INIT_TABLE)
    targets = [
        int.from_bytes(data[offset:offset + 4], "little")
        for offset in range(0, len(data), 4)
    ]
    return [target for target in targets if target]


def cpp_initializer_table_is_valid(pe):
    _, image_base, sections = pe
    text = next(
        (section for section in sections if section[0] == ".text"), None)
    if text is None:
        return False
    _, text_rva, text_size, _, _ = text
    low = image_base + text_rva
    high = low + text_size
    targets = cpp_initializer_targets(pe)
    return bool(targets) and len(targets) == len(set(targets)) \
        and all(low <= target < high for target in targets)


def contiguous(by_address, start, stop):
    prefix = [
        by_address[address] for address in sorted(by_address)
        if start <= address < stop
    ]
    if not prefix:
        raise ValueError("the selected boundary precedes the CRT entry")
    cursor = start
    for instruction in prefix:
        if lifter.parse_address(instruction["address"]) != cursor:
            raise ValueError(f"gap in CRT prefix at 0x{cursor:08x}")
        cursor += instruction["length"]
    if cursor != stop:
        raise ValueError(
            f"CRT prefix ends at 0x{cursor:08x}, expected 0x{stop:08x}")
    return prefix


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--candidate", type=Path, required=True)
    parser.add_argument("--batch", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--stage", choices=sorted(STAGES), required=True)
    args = parser.parse_args()

    reference_hash = lifter.sha256_file(args.reference)
    if reference_hash != lifter.EXPECTED_SHA256:
        parser.error("reference PE hash does not match the verified build")
    reference = lifter.parse_pe(args.reference)
    candidate = lifter.parse_pe(args.candidate)
    iat_imports = lifter.parse_pe_iat_imports(reference)
    batch = json.loads(args.batch.read_text(encoding="utf-8"))
    functions = {
        lifter.parse_address(record["function"]["entry"]): record["function"]
        for record in batch["functions"]
    }
    crt = functions.get(CRT_ENTRY)
    seh = functions.get(SEH_PROLOG)
    if crt is None or seh is None:
        parser.error("CRT entry or __SEH_prolog4 is absent from the batch")
    for function in (crt, seh):
        if (lifter.validate_function_bytes(function, reference)
                != lifter.validate_function_bytes(function, candidate)):
            parser.error("function bytes differ between the two PE builds")

    stage = STAGES[args.stage]
    boundary = stage["boundary"]
    aliases = {
        address: alias for address, alias in ALIASES.items()
        if address < boundary
    }
    by_address = {
        lifter.parse_address(item["address"]): item
        for item in crt["instructions"]
    }
    seh_call = by_address.get(SEH_CALL)
    if (seh_call is None or seh_call.get("bytes") != SEH_CALL_BYTES
            or lifter.direct_call_target(seh_call) != SEH_PROLOG):
        parser.error("the __SEH_prolog4 call site is not the expected one")
    startupinfo_call = by_address.get(STARTUPINFO_CALL)
    if (startupinfo_call is None
            or startupinfo_call.get("bytes") != STARTUPINFO_CALL_BYTES
            or iat_imports.get(STARTUPINFO_IAT) != STARTUPINFO_SYMBOL):
        parser.error("the GetStartupInfoA call site is not the expected one")
    if boundary > INTERLOCKED_CALL:
        interlocked_call = by_address.get(INTERLOCKED_CALL)
        if (interlocked_call is None
                or interlocked_call.get("bytes") != INTERLOCKED_CALL_BYTES
                or iat_imports.get(INTERLOCKED_IAT) != INTERLOCKED_SYMBOL):
            parser.error(
                "the InterlockedCompareExchange call site is not the "
                "expected one")
        if not region_is_bss(reference, STARTUP_LOCK_REGION,
                             STARTUP_LOCK_REGION_BYTES):
            parser.error(
                "the startup lock globals are no longer loader zero-filled")
    if boundary >= INITTERM_CALL:
        verify_thunks(parser, reference, iat_imports, by_address, aliases)
        if not initterm_table_is_valid(reference):
            parser.error(
                "the CRT initializer table changed shape at "
                f"0x{INITTERM_TABLE:08x}")
    if boundary >= INITTERM_WALK_CALL:
        if not cpp_initializer_table_is_valid(reference):
            parser.error(
                "the C++ initializer table at "
                f"0x{CPP_INIT_TABLE:08x} changed shape")

    try:
        prefix = contiguous(by_address, CRT_ENTRY, boundary)
        translated, exit_targets = translate_prefix(
            prefix, boundary, stage["include"], iat_imports, aliases
        )
        prolog_source = None
        if stage["emit_prolog"]:
            prolog_source, _ = lifter.translate_function(
                seh, exported_function_entries={SEH_PROLOG},
                iat_imports=iat_imports,
            )
    except (ValueError, lifter.LiftRejected) as error:
        parser.error(f"CRT prefix is not translatable: {error}")

    source = lifter.static_source(
        crt, translated, sorted(stage["include"]),
        terminal_status=(boundary, "unsupported_dependency"),
        exit_targets=exit_targets,
    )
    raw = b"".join(bytes.fromhex(item["bytes"]) for item in prefix)
    boundary_instruction = by_address[boundary]
    raw += bytes.fromhex(boundary_instruction["bytes"])

    seh_instructions = lifter.validate_function_bytes(seh, reference)
    seh_bytes = b"".join(
        bytes.fromhex(item["bytes"]) for item in seh_instructions
    )

    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / "spore_011e0ee0.cpp").write_text(
        source + "\n", encoding="utf-8"
    )
    if prolog_source is not None:
        (args.output / "spore_011e11d4.cpp").write_text(
            prolog_source + "\n", encoding="utf-8"
        )
    (args.output / "crt_reference_bytes.hpp").write_text(
        "#pragma once\n#include <array>\n#include <cstdint>\n"
        + cpp_array("kCrtPrefixBytes", raw) + "\n"
        + cpp_array("kSehPrologBytes", seh_bytes) + "\n"
        + f"inline constexpr std::uint32_t kCrtEntry = 0x{CRT_ENTRY:08x}u;\n"
        + f"inline constexpr std::uint32_t kCrtStop = 0x{boundary:08x}u;\n"
        + f"inline constexpr std::uint32_t kCrtPrefixInstructions = "
          f"{len(prefix)}u;\n"
        + f"inline constexpr std::uint32_t kSehPrologEntry = "
          f"0x{SEH_PROLOG:08x}u;\n"
        + f"inline constexpr std::uint32_t kSehPrologInstructions = "
          f"{len(seh_instructions)}u;\n"
        + f"inline constexpr bool kSehPrologExecuted = "
          f"{'true' if stage.get('prolog_counted', stage['emit_prolog']) else 'false'};\n"
        + f"inline constexpr std::uint32_t kCrtPrefixExecutedInstructions = "
          f"{stage['executed']}u;\n"
        + f"inline constexpr std::uint32_t kStartupInfoCall = "
          f"0x{STARTUPINFO_CALL:08x}u;\n"
        + f"inline constexpr std::uint32_t kInterlockedCall = "
          f"0x{INTERLOCKED_CALL:08x}u;\n"
        + f"inline constexpr std::uint32_t kStartupLockState = "
          f"0x{STARTUP_STATE:08x}u;\n"
        + f"inline constexpr std::uint32_t kStartupLock = "
          f"0x{STARTUP_LOCK:08x}u;\n"
        + f"inline constexpr std::uint32_t kStartupLockRegion = "
          f"0x{STARTUP_LOCK_REGION:08x}u;\n"
        + f"inline constexpr std::uint32_t kStartupLockRegionBytes = "
          f"{STARTUP_LOCK_REGION_BYTES}u;\n"
        + f"inline constexpr bool kStartupLockExecuted = "
          f"{'true' if boundary > INTERLOCKED_CALL else 'false'};\n"
        + f"inline constexpr std::uint32_t kInittermCall = "
          f"0x{INITTERM_CALL:08x}u;\n"
        + f"inline constexpr std::uint32_t kAmsgExitCall = "
          f"0x{AMSG_EXIT_CALL:08x}u;\n"
        + f"inline constexpr std::uint32_t kInittermTable = "
          f"0x{INITTERM_TABLE:08x}u;\n"
        + f"inline constexpr std::uint32_t kInittermTableEnd = "
          f"0x{INITTERM_TABLE_END:08x}u;\n"
        + f"inline constexpr bool kInittermCallIsBoundary = "
          f"{'true' if boundary == INITTERM_CALL else 'false'};\n"
        + f"inline constexpr std::uint32_t kInittermExecutedAddress = "
          f"0x{INITTERM_EXECUTED:08x}u;\n"
        + f"inline constexpr bool kInittermExecutedIsBoundary = "
          f"{'true' if boundary == INITTERM_EXECUTED else 'false'};\n"
        + f"inline constexpr std::uint32_t kInittermWalkCall = "
          f"0x{INITTERM_WALK_CALL:08x}u;\n"
        + f"inline constexpr std::uint32_t kCppInitTable = "
          f"0x{CPP_INIT_TABLE:08x}u;\n"
        + f"inline constexpr std::uint32_t kCppInitTableEnd = "
          f"0x{CPP_INIT_TABLE_END:08x}u;\n"
        + f"inline constexpr bool kInittermWalkIsBoundary = "
          f"{'true' if boundary == INITTERM_WALK_CALL else 'false'};\n"
        + f"inline constexpr bool kCppWalkEnabled = "
          f"{'true' if stage.get('cpp_walk') else 'false'};\n",
        encoding="utf-8",
    )
    manifest = {
        "reference_sha256": reference_hash,
        "candidate_sha256": lifter.sha256_file(args.candidate),
        "stage": args.stage,
        "crt_entry": f"0x{CRT_ENTRY:08x}",
        "boundary": f"0x{boundary:08x}",
        "boundary_bytes": boundary_instruction["bytes"],
        "seh_prolog": f"0x{SEH_PROLOG:08x}",
        "seh_prolog_executed": stage["emit_prolog"],
        "seh_prolog_instructions": len(seh_instructions),
        "startupinfo_call": f"0x{STARTUPINFO_CALL:08x}",
        "startupinfo_symbol": STARTUPINFO_SYMBOL,
        "startupinfo_executed": stage["emit_prolog"],
        "interlocked_call": f"0x{INTERLOCKED_CALL:08x}",
        "interlocked_symbol": INTERLOCKED_SYMBOL,
        "interlocked_executed": boundary > INTERLOCKED_CALL,
        "startup_lock_state": f"0x{STARTUP_STATE:08x}",
        "startup_lock": f"0x{STARTUP_LOCK:08x}",
        "startup_lock_region": f"0x{STARTUP_LOCK_REGION:08x}",
        "startup_lock_region_is_loader_zero_filled":
            region_is_bss(reference, STARTUP_LOCK_REGION,
                          STARTUP_LOCK_REGION_BYTES),
        "crt_prefix_instructions": len(prefix),
        "crt_prefix_bytes": len(raw),
        "crt_prefix_executed_instructions": stage["executed"],
        "import_aliases": [
            f"0x{address:08x}->0x{thunk:08x}:{symbol}"
            for address, (thunk, symbol, _) in sorted(aliases.items())
        ],
        "initterm_table": [f"0x{entry:08x}"
                           for entry in initterm_table(reference)],
        "initterm_call_is_boundary": boundary == INITTERM_CALL,
        "initterm_executed_is_boundary": boundary == INITTERM_EXECUTED,
        "initterm_walk_call": f"0x{INITTERM_WALK_CALL:08x}",
        "initterm_walk_symbol": INITTERM_WALK_SYMBOL,
        "cpp_initializer_table": f"0x{CPP_INIT_TABLE:08x}",
        "cpp_initializer_table_end": f"0x{CPP_INIT_TABLE_END:08x}",
        "cpp_initializer_count": len(cpp_initializer_targets(reference))
            if boundary >= INITTERM_WALK_CALL else 0,
        "initterm_walk_is_boundary": boundary == INITTERM_WALK_CALL,
    }
    (args.output / "manifest.json").write_text(
        json.dumps(manifest, indent=2) + "\n", encoding="utf-8"
    )
    print(
        f"generated stage {args.stage}: {len(prefix)} CRT prefix records to "
        f"0x{boundary:08x} ({stage['executed']} executed), "
        f"seh_prolog={stage['emit_prolog']}, "
        f"lock_block={boundary > INTERLOCKED_CALL}")


if __name__ == "__main__":
    main()
