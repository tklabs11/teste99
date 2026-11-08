#!/usr/bin/env python3
"""Verify and emit the boot prefix through the GetCurrentProcessId import.

The prefix starts at the security cookie, runs the Win32 time call, mixes its
result through ESI, and stops either at the `CALL [GetCurrentProcessId]` site
(0x011e158b) or after that call at 0x011e1591.
"""

import argparse
import json
from pathlib import Path

import BatchStaticLift as lifter


ENTRY = 0x011e1548
ALTERNATE_BRANCH_GUARD = 0x011e1578
DATA_ADDRESS = 0x015cfe70

TIME_CALL = 0x011e157f
TIME_CALL_BYTES = "ff15ccc13c01"
TIME_IAT = 0x013cc1cc
TIME_SYMBOL = "KERNEL32.dll!GetSystemTimeAsFileTime"
AFTER_TIME_CALL = 0x011e1585

PID_CALL = 0x011e158b
PID_CALL_BYTES = "ff1514c13c01"
PID_IAT = 0x013cc114
PID_SYMBOL = "KERNEL32.dll!GetCurrentProcessId"
AFTER_PID_CALL = 0x011e1591

MOV_ESI_HIGH = 0x011e1585
MOV_ESI_HIGH_BYTES = "8b75fc"
XOR_ESI_LOW = 0x011e1588
XOR_ESI_LOW_BYTES = "3375f8"

XOR_ESI_EAX = 0x011e1591
XOR_ESI_EAX_BYTES = "33f0"
TID_CALL = 0x011e1593
TID_CALL_BYTES = "ff153cc13c01"
TID_IAT = 0x013cc13c
TID_SYMBOL = "KERNEL32.dll!GetCurrentThreadId"
XOR_ESI_TID = 0x011e1599
TICK_CALL = 0x011e159b
TICK_CALL_BYTES = "ff1530c13c01"
TICK_IAT = 0x013cc130
TICK_SYMBOL = "KERNEL32.dll!GetTickCount"
XOR_ESI_TICK = 0x011e15a1
QPC_LEA = 0x011e15a3
QPC_LEA_BYTES = "8d45f0"
QPC_PUSH = 0x011e15a6
QPC_PUSH_BYTES = "50"
QPC_CALL = 0x011e15a7
QPC_CALL_BYTES = "ff15b8c23c01"
QPC_IAT = 0x013cc2b8
QPC_SYMBOL = "KERNEL32.dll!QueryPerformanceCounter"
QPC_MOV_HIGH = 0x011e15ad
QPC_MOV_HIGH_BYTES = "8b45f4"
QPC_XOR_LOW = 0x011e15b0
QPC_XOR_LOW_BYTES = "3345f0"
XOR_ESI_QPC = 0x011e15b3
AFTER_ENTROPY_MIX = 0x011e15b5

STAGES = {
    "pid-call-boundary": PID_CALL,
    "pid-call-executed": AFTER_PID_CALL,
    "entropy-complete": AFTER_ENTROPY_MIX,
    "cookie-complete": 0x011e15de,   # one past the function's RET
}


def cpp_array(name, values):
    literals = ", ".join(f"0x{value:02x}u" for value in values)
    return (f"inline constexpr std::array<std::uint8_t, {len(values)}> "
            f"{name}{{{literals}}};")


def validate_import_call(by_address, address, encoded, operands, symbol,
                         iat_address, iat_imports):
    call = by_address.get(address)
    if call is None:
        raise ValueError(f"instruction 0x{address:08x} is absent from the export")
    if str(call.get("mnemonic", "")).upper() != "CALL":
        raise ValueError(f"0x{address:08x} is not the expected CALL")
    if call.get("bytes") != encoded:
        raise ValueError(
            f"0x{address:08x} bytes {call.get('bytes')} differ from {encoded}")
    if call.get("operands") != operands:
        raise ValueError(
            f"0x{address:08x} operands {call.get('operands')} differ from "
            f"{operands}")
    if iat_imports.get(iat_address) != symbol:
        raise ValueError(
            f"IAT slot 0x{iat_address:08x} does not resolve to {symbol}")


def validate_esi_mix(by_address):
    high = by_address.get(MOV_ESI_HIGH)
    low = by_address.get(XOR_ESI_LOW)
    if high is None or low is None:
        raise ValueError("the ESI mix instructions are absent from the export")
    if high.get("bytes") != MOV_ESI_HIGH_BYTES:
        raise ValueError(
            f"0x{MOV_ESI_HIGH:08x} bytes {high.get('bytes')} differ from "
            f"{MOV_ESI_HIGH_BYTES}")
    if high.get("mnemonic", "").upper() != "MOV":
        raise ValueError(f"0x{MOV_ESI_HIGH:08x} is not the expected MOV")
    if low.get("bytes") != XOR_ESI_LOW_BYTES:
        raise ValueError(
            f"0x{XOR_ESI_LOW:08x} bytes {low.get('bytes')} differ from "
            f"{XOR_ESI_LOW_BYTES}")
    if low.get("mnemonic", "").upper() != "XOR":
        raise ValueError(f"0x{XOR_ESI_LOW:08x} is not the expected XOR")
    if lifter.parse_address(high["address"]) + high["length"] != XOR_ESI_LOW:
        raise ValueError("the ESI mix instructions are not adjacent")


def validate_entropy_block(by_address, iat_imports):
    """Check the straight-line block that mixes thread, tick and counter."""
    for address, encoded, mnemonic in (
        (XOR_ESI_EAX, XOR_ESI_EAX_BYTES, "XOR"),
        (XOR_ESI_TID, XOR_ESI_EAX_BYTES, "XOR"),
        (XOR_ESI_TICK, XOR_ESI_EAX_BYTES, "XOR"),
        (XOR_ESI_QPC, XOR_ESI_EAX_BYTES, "XOR"),
        (QPC_LEA, QPC_LEA_BYTES, "LEA"),
        (QPC_PUSH, QPC_PUSH_BYTES, "PUSH"),
        (QPC_MOV_HIGH, QPC_MOV_HIGH_BYTES, "MOV"),
        (QPC_XOR_LOW, QPC_XOR_LOW_BYTES, "XOR"),
    ):
        item = by_address.get(address)
        if item is None:
            raise ValueError(f"instruction 0x{address:08x} is absent from the export")
        if item.get("bytes") != encoded:
            raise ValueError(
                f"0x{address:08x} bytes {item.get('bytes')} differ from {encoded}")
        if str(item.get("mnemonic", "")).upper() != mnemonic:
            raise ValueError(
                f"0x{address:08x} is not the expected {mnemonic}")
    validate_import_call(
        by_address, TID_CALL, TID_CALL_BYTES,
        [f"dword ptr [0x{TID_IAT:08x}]"], TID_SYMBOL, TID_IAT, iat_imports,
    )
    validate_import_call(
        by_address, TICK_CALL, TICK_CALL_BYTES,
        [f"dword ptr [0x{TICK_IAT:08x}]"], TICK_SYMBOL, TICK_IAT, iat_imports,
    )
    validate_import_call(
        by_address, QPC_CALL, QPC_CALL_BYTES,
        [f"dword ptr [0x{QPC_IAT:08x}]"], QPC_SYMBOL, QPC_IAT, iat_imports,
    )


def resolve_boundary(stage):
    if stage not in STAGES:
        raise ValueError(f"unknown boot prefix stage: {stage}")
    return STAGES[stage]


def build_prefix(by_address, boundary_address):
    prefix = [
        by_address[address] for address in sorted(by_address)
        if address < boundary_address
    ]
    if not prefix:
        raise ValueError("the selected boundary precedes the function entry")
    cursor = ENTRY
    for instruction in prefix:
        if lifter.parse_address(instruction["address"]) != cursor:
            raise ValueError(f"gap in boot prefix at 0x{cursor:08x}")
        cursor += instruction["length"]
    if cursor != boundary_address:
        raise ValueError(
            f"boot prefix ends at 0x{cursor:08x}, expected the boundary "
            f"0x{boundary_address:08x}")
    # A complete-function stage has no trailing boundary instruction: the last
    # translated instruction is the function's own RET.
    boundary = by_address.get(boundary_address)
    return prefix, boundary


def translate_prefix(prefix, boundary_address, iat_imports):
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
    return translated


def reference_header(raw, initial_data, boundary_address, complete=False):
    constants = (
        ("kCookieBoundaryAddress", boundary_address),
        ("kCookieTimeCallAddress", TIME_CALL),
        ("kCookieProcessIdCallAddress", PID_CALL),
        ("kCookieThreadIdCallAddress", TID_CALL),
        ("kCookieTickCountCallAddress", TICK_CALL),
        ("kCookiePerformanceCounterCallAddress", QPC_CALL),
        ("kCookieProcessIdXorAddress", XOR_ESI_EAX),
        ("kCookieThreadIdXorAddress", XOR_ESI_TID),
        ("kCookieTickCountXorAddress", XOR_ESI_TICK),
        ("kCookiePerformanceCounterXorAddress", XOR_ESI_QPC),
    )
    body = "".join(
        f"inline constexpr std::uint32_t {name} = 0x{value:08x}u;\n"
        for name, value in constants
    )
    body += ("inline constexpr bool kCookieFunctionComplete = "
             + ("true;\n" if complete else "false;\n"))
    if complete:
        body += "#define SPORE_COOKIE_FUNCTION_COMPLETE 1\n"
    return (
        "#pragma once\n#include <array>\n#include <cstdint>\n"
        + cpp_array("kCookieCodeBytes", raw) + "\n"
        + cpp_array("kCookieInitialData", initial_data) + "\n"
        + body
    )


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--candidate", type=Path, required=True)
    parser.add_argument("--batch", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--stage", choices=sorted(STAGES), required=True,
                        help="pid-call-boundary stops at 0x011e158b; "
                             "pid-call-executed also calls the import and "
                             "stops at 0x011e1591")
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
    iat_imports = lifter.parse_pe_iat_imports(reference)
    try:
        validate_import_call(
            by_address, TIME_CALL, TIME_CALL_BYTES,
            [f"dword ptr [0x{TIME_IAT:08x}]"], TIME_SYMBOL, TIME_IAT,
            iat_imports,
        )
        validate_esi_mix(by_address)
        validate_import_call(
            by_address, PID_CALL, PID_CALL_BYTES,
            [f"dword ptr [0x{PID_IAT:08x}]"], PID_SYMBOL, PID_IAT,
            iat_imports,
        )
        validate_entropy_block(by_address, iat_imports)
        boundary_address = resolve_boundary(args.stage)
        prefix, boundary = build_prefix(by_address, boundary_address)
    except ValueError as error:
        parser.error(str(error))

    translated = translate_prefix(prefix, boundary_address, iat_imports)
    complete = boundary is None
    source = (
        lifter.static_source(function, translated, [])
        if complete else
        lifter.static_source(
            function, translated, [],
            terminal_status=(boundary_address, "unsupported_dependency"),
        )
    )
    raw = b"".join(bytes.fromhex(item["bytes"]) for item in prefix)
    if not complete:
        raw += bytes.fromhex(boundary["bytes"])
    expected_span = boundary_address - ENTRY + (
        0 if complete else boundary["length"])
    if len(raw) != expected_span:
        parser.error(
            f"raw byte span {len(raw)} differs from {expected_span}")

    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / "spore_011e1548_prefix.cpp").write_text(
        source + "\n", encoding="utf-8"
    )
    (args.output / "cookie_reference_bytes.hpp").write_text(
        reference_header(raw, original_data, boundary_address, complete),
        encoding="utf-8",
    )
    manifest = {
        "reference_sha256": reference_hash,
        "candidate_sha256": lifter.sha256_file(args.candidate),
        "stage": args.stage,
        "function": f"0x{ENTRY:08x}",
        "boundary": f"0x{boundary_address:08x}",
        "boundary_bytes": boundary["bytes"] if boundary else None,
        "function_complete": complete,
        "verified_function_instructions": len(original),
        "prefix_instructions_before_boundary": len(prefix),
        "prefix_bytes_including_boundary": len(raw),
        "alternate_branch_guard": f"0x{ALTERNATE_BRANCH_GUARD:08x}",
        "initial_data_address": f"0x{DATA_ADDRESS:08x}",
        "initial_data_bytes": original_data.hex(),
        "imports": [
            {"address": f"0x{TIME_CALL:08x}", "symbol": TIME_SYMBOL,
             "iat": f"0x{TIME_IAT:08x}", "argument_count": 1,
             "executed": boundary_address > TIME_CALL},
            {"address": f"0x{PID_CALL:08x}", "symbol": PID_SYMBOL,
             "iat": f"0x{PID_IAT:08x}", "argument_count": 0,
             "executed": boundary_address > PID_CALL},
            {"address": f"0x{TID_CALL:08x}", "symbol": TID_SYMBOL,
             "iat": f"0x{TID_IAT:08x}", "argument_count": 0,
             "executed": boundary_address > TID_CALL},
            {"address": f"0x{TICK_CALL:08x}", "symbol": TICK_SYMBOL,
             "iat": f"0x{TICK_IAT:08x}", "argument_count": 0,
             "executed": boundary_address > TICK_CALL},
            {"address": f"0x{QPC_CALL:08x}", "symbol": QPC_SYMBOL,
             "iat": f"0x{QPC_IAT:08x}", "argument_count": 1,
             "executed": boundary_address > QPC_CALL},
        ],
        "process_id_call_executed": boundary_address > PID_CALL,
        "entropy_mix_complete": boundary_address > XOR_ESI_QPC,
        "scope": (
            "complete ___security_init_cookie with real Win32 entropy"
            if complete else
            "original initial cookie data; complete CRT entropy mix through "
            "the performance counter"
            if boundary_address > XOR_ESI_QPC else
            "original initial cookie data; time call executed; the next "
            "recorded import is the terminal boundary"
            if boundary_address > PID_CALL else
            "original initial cookie data; time call executed; process-id "
            "call is the terminal boundary"
        ),
    }
    (args.output / "manifest.json").write_text(
        json.dumps(manifest, indent=2) + "\n", encoding="utf-8"
    )
    print(
        f"generated {len(prefix)} prefix records for stage {args.stage} "
        f"to 0x{boundary_address:08x}")


if __name__ == "__main__":
    main()
