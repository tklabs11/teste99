import argparse
import struct
from pathlib import Path


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--symbol", required=True)
    args = parser.parse_args()

    data = args.input.read_bytes()
    if len(data) % 4:
        raise ValueError(f"{args.input} is not a valid SPIR-V word stream")

    words = struct.unpack(f"<{len(data) // 4}I", data)
    if not words or words[0] != 0x07230203:
        raise ValueError(f"{args.input} does not contain a SPIR-V module")

    args.output.parent.mkdir(parents=True, exist_ok=True)
    with args.output.open("w", encoding="ascii", newline="\n") as header:
        header.write("#pragma once\n#include <cstdint>\n\n")
        header.write(f"static const uint32_t {args.symbol}[] = {{\n")
        for offset in range(0, len(words), 8):
            chunk = words[offset:offset + 8]
            header.write("    " + ", ".join(f"0x{word:08x}" for word in chunk))
            if offset + 8 < len(words):
                header.write(",")
            header.write("\n")
        header.write("};\n")


if __name__ == "__main__":
    main()
