#!/usr/bin/env python3

import argparse
import json
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32


def main() -> int:
    parser = argparse.ArgumentParser(description="Disassemble focused regions of a PE32 executable.")
    parser.add_argument("pe", type=Path)
    parser.add_argument("rvas", nargs="+", help="RVA in hexadecimal, for example 0xDE1548")
    parser.add_argument("--bytes", dest="byte_count", type=int, default=128)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    pe_path = args.pe.resolve()
    pe = pefile.PE(str(pe_path), fast_load=False)
    image_base = pe.OPTIONAL_HEADER.ImageBase
    md = Cs(CS_ARCH_X86, CS_MODE_32)

    regions = []
    for rva_text in args.rvas:
        rva = int(rva_text, 0)
        va = image_base + rva
        raw = pe.get_data(rva, args.byte_count)
        instructions = [
            {
                "address_hex": hex(instruction.address),
                "bytes": instruction.bytes.hex(),
                "mnemonic": instruction.mnemonic,
                "operands": instruction.op_str,
            }
            for instruction in md.disasm(raw, va)
        ]
        regions.append({"rva_hex": hex(rva), "va_hex": hex(va), "instructions": instructions})

    report = {
        "path": str(pe_path),
        "sha256": __import__("hashlib").sha256(pe_path.read_bytes()).hexdigest(),
        "regions": regions,
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"Wrote {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
