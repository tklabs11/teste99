#!/usr/bin/env python3

import argparse
import json
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32


def main() -> int:
    parser = argparse.ArgumentParser(description="Disassemble and record the PE entry point.")
    parser.add_argument("pe", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--bytes", dest="byte_count", type=int, default=128)
    args = parser.parse_args()

    pe_path = args.pe.resolve()
    pe = pefile.PE(str(pe_path), fast_load=False)
    rva = pe.OPTIONAL_HEADER.AddressOfEntryPoint
    va = pe.OPTIONAL_HEADER.ImageBase + rva
    raw = pe.get_data(rva, args.byte_count)
    md = Cs(CS_ARCH_X86, CS_MODE_32)

    instructions = [
        {
            "address": instruction.address,
            "address_hex": hex(instruction.address),
            "bytes": instruction.bytes.hex(),
            "mnemonic": instruction.mnemonic,
            "operands": instruction.op_str,
        }
        for instruction in md.disasm(raw, va)
    ]

    report = {
        "path": str(pe_path),
        "sha256": __import__("hashlib").sha256(pe_path.read_bytes()).hexdigest(),
        "entry_rva": rva,
        "entry_rva_hex": hex(rva),
        "entry_va": va,
        "entry_va_hex": hex(va),
        "requested_bytes": args.byte_count,
        "instructions": instructions,
    }

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"Wrote {args.output} with {len(instructions)} instructions")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
