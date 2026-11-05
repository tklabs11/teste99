#!/usr/bin/env python3

import argparse
import json
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32


def main() -> int:
    parser = argparse.ArgumentParser(description="Find direct x86 xrefs to PE virtual addresses")
    parser.add_argument("exe", type=Path)
    parser.add_argument("addresses", nargs="+", help="Destination virtual addresses in hex")
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()

    destinations = {int(address, 0) for address in args.addresses}
    pe = pefile.PE(str(args.exe), fast_load=False)
    image_base = pe.OPTIONAL_HEADER.ImageBase
    text = pe.sections[0]

    disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
    disassembler.detail = True
    section_va = image_base + text.VirtualAddress
    section_data = text.get_data()

    xrefs = []
    instructions = disassembler.disasm_lite(section_data, section_va)
    for address, size, mnemonic, operands in instructions:
        for operand_text in operands.replace(",", " ").split():
            try:
                operand_address = int(operand_text.strip(), 16)
            except ValueError:
                continue
            if operand_address in destinations:
                xrefs.append({
                    "source_va": f"0x{address:X}",
                    "destination_va": f"0x{operand_address:X}",
                    "mnemonic": mnemonic,
                    "operands": operands,
                    "bytes": section_data[address - section_va:address - section_va + size].hex(),
                })

    result = {
        "executable": str(args.exe),
        "destinations": [f"0x{address:X}" for address in sorted(destinations)],
        "xref_count": len(xrefs),
        "xrefs": xrefs,
    }
    rendered = json.dumps(result, indent=2)
    print(rendered)
    if args.output:
        args.output.write_text(rendered + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
