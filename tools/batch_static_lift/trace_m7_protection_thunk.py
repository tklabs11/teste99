"""Verify the PE-backed jump chain reached from the Marco 7 missing target."""

import argparse
import json
from pathlib import Path

import BatchStaticLift as lifter


CHAIN = (
    0x00401714, 0x00401899, 0x00401923, 0x00401953,
    0x00402385, 0x00402414, 0x004029E6, 0x00402B23,
    0x00403694, 0x004036D4, 0x00403A95, 0x004044F4,
    0x00404651,
)


def trace(exe: Path, batch: Path) -> None:
    source_hash = lifter.sha256_file(exe)
    if source_hash != lifter.EXPECTED_SHA256:
        raise ValueError(f"unexpected PE SHA-256: {source_hash}")
    data = json.loads(batch.read_text(encoding="utf-8"))
    if data["selected_source_sha256"] != source_hash:
        raise ValueError("export batch refers to a different PE")
    pe = lifter.parse_pe(exe)
    functions = {int(item["function"]["entry"], 16): item["function"]
                 for item in data["functions"]}

    section, _, stub = lifter.read_pe_bytes(pe, 0x011E073E, 5)
    if section != ".text" or stub != bytes.fromhex("e9d10f22ff"):
        raise ValueError("0x011e073e stub differs from verified bytes")
    target = 0x011E073E + 5 + int.from_bytes(stub[1:], "little", signed=True)
    if target != CHAIN[0]:
        raise ValueError("stub jump target differs from export chain")
    print(f"PE_SHA256={source_hash}")
    print(f"0x011e073e {stub.hex()} JMP 0x{target:08x}")

    for index, address in enumerate(CHAIN):
        function = functions.get(address)
        if function is None:
            raise ValueError(f"export missing 0x{address:08x}")
        lifter.validate_function_bytes(function, pe)
        next_address = CHAIN[index + 1] if index + 1 < len(CHAIN) else None
        if next_address is not None and not any(
            f"0x{next_address:08x}" in instruction["flows_to"]
            for instruction in function["instructions"]
        ):
            raise ValueError(f"no direct flow from 0x{address:08x} to 0x{next_address:08x}")
        print(f"FUNCTION 0x{address:08x} instructions={len(function['instructions'])} bytes=verified")
        for instruction in function["instructions"]:
            print(f"  {instruction['address']} {instruction['bytes']} "
                  f"{instruction['mnemonic']} {','.join(instruction['operands'])}")

    iat = lifter.parse_pe_iat_imports(pe)
    slot = 0x00401719 + 0x00FCAAAF
    if iat.get(slot) != "KERNEL32.dll!VirtualAlloc":
        raise ValueError(f"unexpected IAT target at 0x{slot:08x}: {iat.get(slot)}")
    print(f"IAT_SLOT=0x{slot:08x} {iat[slot]}")
    print("VIRTUALALLOC_ARGS=lpAddress:0 size:0xbfa43 allocationType:0x3000 protect:0x40")
    print("INTERPRETATION=dynamic executable allocation and byte writes; final callee semantics unproven")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--exe", required=True, type=Path)
    parser.add_argument("--batch", required=True, type=Path)
    args = parser.parse_args()
    trace(args.exe, args.batch)
