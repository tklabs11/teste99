#!/usr/bin/env python3

import sys


MASK32 = 0xFFFFFFFF


def lifting_add(a: int, b: int) -> int:
    return (a + b) & MASK32


def lifting_mul(a: int, b: int) -> int:
    return (a * b) & MASK32


def lifting_mix(a: int, b: int) -> int:
    return ((a << 3) ^ ((b >> 2) + 0x9E3779B9)) & MASK32


def lifting_accumulate(values: list[int]) -> int:
    result = 0
    for value in values:
        result = lifting_mix(result, value)
    return result


def main() -> int:
    cases = [
        ("add", lifting_add(0xFFFFFFFF, 2), 0x00000001),
        ("mul", lifting_mul(0x80000000, 3), 0x80000000),
        ("mix", lifting_mix(0x12345678, 0xABCDEF01), 0x588846B9),
        (
            "accumulate",
            lifting_accumulate([0, 1, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF]),
            0xBB3A3870,
        ),
    ]

    failed = 0
    for name, actual, expected in cases:
        if actual != expected:
            print(f"FAIL {name}: actual={actual:#010x}, expected={expected:#010x}", file=sys.stderr)
            failed += 1
        else:
            print(f"PASS {name}: {actual:#010x}")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
