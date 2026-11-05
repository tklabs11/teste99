#!/usr/bin/env python3

import struct

F32_MASK = 0xFFFFFFFF


def f32(value: float) -> float:
    return struct.unpack("<f", struct.pack("<f", value))[0]


def checksum(destination: list[float]) -> int:
    result = 0x811C9DC5
    for value in destination:
        bits = struct.unpack("<I", struct.pack("<f", f32(value)))[0]
        result = ((result ^ bits) * 0x01000193) & F32_MASK
    return result


def main() -> int:
    destination = [1.0, -2.0, 0.25, 8.0, 3.5, -0.125, 2.0, 0.0]
    source = [0.5, 2.0, -4.0, 0.125, -3.0, 7.0, 0.75, -9.0]
    scalar = 1.25
    destination = [f32(destination[i] + f32(scalar * source[i])) for i in range(len(destination))]
    expected = checksum(destination)
    print(f"array_multiply_add={expected:08X}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
