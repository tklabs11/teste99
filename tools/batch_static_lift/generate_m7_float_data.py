"""Emit only the PE-backed data used by the FUN_00921360 test harness."""

import argparse
import hashlib
from pathlib import Path

import BatchStaticLift as lifter

PE_SHA256 = "6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b"


def generate(pe_path, output_path):
    image = Path(pe_path).read_bytes()
    if hashlib.sha256(image).hexdigest() != PE_SHA256:
        raise ValueError("source PE hash differs from the verified reference")
    pe = lifter.parse_pe(Path(pe_path))
    sections = [
        ("kM7TableData", 0x0143D850, 0x404),
        ("kM7Correction", 0x013F4FD0, 4),
    ]
    lines = ["#pragma once", "#include <array>", "#include <cstdint>", ""]
    for name, address, size in sections:
        _, _, data = lifter.read_pe_bytes(pe, address, size)
        lines.append(f"inline constexpr std::array<std::uint8_t, {size}> {name} = {{{{")
        for offset in range(0, size, 16):
            lines.append("    " + ", ".join(f"0x{byte:02x}u" for byte in data[offset:offset+16]) + ",")
        lines.append("}};")
        lines.append("")
    Path(output_path).write_text("\n".join(lines), encoding="utf-8")
    print(f"PE-backed data generated: table=0x0143d850+0x404 correction=0x013f4fd0+4 sha256={PE_SHA256}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--exe", required=True)
    parser.add_argument("--output", required=True)
    args = parser.parse_args()
    generate(args.exe, args.output)
