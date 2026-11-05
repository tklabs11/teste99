#!/usr/bin/env python3

import argparse
import json
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32


PROLOGUES = (
    bytes.fromhex("8bff558bec"),
    bytes.fromhex("558bec"),
    bytes.fromhex("8bff55"),
)


def main() -> int:
    parser = argparse.ArgumentParser(description="Find small leaf-like candidates in a PE32 .text section.")
    parser.add_argument("pe")
    parser.add_argument("--output", required=True)
    parser.add_argument("--limit", type=int, default=40)
    args = parser.parse_args()

    pe = pefile.PE(args.pe, fast_load=False)
    image_base = pe.OPTIONAL_HEADER.ImageBase
    text = next(section for section in pe.sections if section.Name.rstrip(b"\0") == b".text")
    start_rva = text.VirtualAddress
    end_rva = start_rva + text.Misc_VirtualSize
    raw = pe.get_data(start_rva, end_rva - start_rva)
    md = Cs(CS_ARCH_X86, CS_MODE_32)

    candidates = []
    offsets = set()
    for prologue in PROLOGUES:
        cursor = 0
        while True:
            offset = raw.find(prologue, cursor)
            if offset < 0:
                break
            offsets.add(offset)
            cursor = offset + 1

    for offset in sorted(offsets):
        rva = start_rva + offset
        instructions = []
        for instruction in md.disasm(raw[offset:offset + 128], image_base + rva):
            instructions.append({
                "address": hex(instruction.address),
                "bytes": instruction.bytes.hex(),
                "mnemonic": instruction.mnemonic,
                "operands": instruction.op_str,
            })
            if instruction.mnemonic in {"ret", "retf", "iretd"}:
                break
            if len(instructions) >= 48:
                break

        if not instructions or instructions[-1]["mnemonic"] not in {"ret", "retf", "iretd"}:
            continue
        if any(item["mnemonic"].startswith("call") for item in instructions):
            continue
        if instructions[-1]["bytes"] == "":
            continue

        size = sum(len(bytes.fromhex(item["bytes"])) for item in instructions)
        candidates.append({
            "rva": hex(rva),
            "va": hex(image_base + rva),
            "size": size,
            "instruction_count": len(instructions),
            "instructions": instructions,
        })

    candidates.sort(
        key=lambda item: (-item["instruction_count"], -item["size"], int(item["rva"], 16))
    )
    candidates = candidates[:args.limit]
    report = {
        "path": args.pe,
        "sha256": __import__("hashlib").sha256(open(args.pe, "rb").read()).hexdigest(),
        "text_rva": hex(start_rva),
        "text_size": hex(end_rva - start_rva),
        "candidate_count": len(candidates),
        "candidates": candidates,
    }
    with open(args.output, "w", encoding="utf-8") as stream:
        json.dump(report, stream, indent=2)
        stream.write("\n")
    print(json.dumps({"candidate_count": len(candidates), "output": args.output}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
