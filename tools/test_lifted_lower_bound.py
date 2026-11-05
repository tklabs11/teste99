#!/usr/bin/env python3


RECORDS = [
    (0x00000000, 10, 20),
    (0x00000008, 11, 21),
    (0x00000010, 12, 22),
    (0x00000020, 13, 23),
    (0xFFFFFFFF, 14, 24),
]


def lower_bound(records: list[tuple[int, int, int]], key: int) -> int:
    low = 0
    high = len(records)
    while low < high:
        middle = low + ((high - low) >> 1)
        if records[middle][0] < key:
            low = middle + 1
        else:
            high = middle
    return low


def main() -> int:
    keys = [0x00000000, 0x00000007, 0x00000008, 0x00000009,
            0x00000010, 0x00000018, 0xFFFFFFFF, 0xFFFFFFFE]
    failed = False
    for key in keys:
        actual = lower_bound(RECORDS, key)
        print(f"lower_bound_{key:08X}={actual}")
        if key == 0x00000000 and actual != 0:
            failed = True
        elif key == 0x00000007 and actual != 1:
            failed = True
        elif key == 0x00000008 and actual != 1:
            failed = True
        elif key == 0x00000009 and actual != 2:
            failed = True
        elif key == 0x00000010 and actual != 2:
            failed = True
        elif key == 0x00000018 and actual != 3:
            failed = True
        elif key in (0xFFFFFFFF, 0xFFFFFFFE) and actual != 4:
            failed = True
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
