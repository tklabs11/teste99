"""Compare original x86, host lift, and Android lift entry snapshots."""

import argparse
from pathlib import Path


FIELDS = (
    "boundary", "eax", "ecx", "edx", "ebx", "esp_delta",
    "ebp", "esi", "edi", "flags", "fs_head", "stack",
)


def snapshot(path: Path):
    lines = path.read_text(encoding="utf-8-sig").splitlines()
    records = [line for line in lines if line.startswith("kind=")]
    if len(records) != 1:
        raise ValueError(f"expected one snapshot in {path}")
    values = dict(token.split("=", 1) for token in records[0].split()
                  if "=" in token)
    if any(field not in values for field in ("kind", *FIELDS)):
        raise ValueError(f"incomplete snapshot in {path}")
    return values


def compare(reference: Path, host: Path, android: Path):
    x86 = snapshot(reference)
    reference_text = reference.read_text(encoding="utf-8-sig")
    if x86["kind"] != "original_x86" or "instructions=18" not in reference_text \
            or "boundary_reached=True" not in reference_text \
            or "error=none" not in reference_text:
        raise ValueError("original x86 reference did not reach boundary cleanly")
    for kind, path in (("lift_x86_host", host),
                       ("lift_android_arm64", android)):
        candidate = snapshot(path)
        if candidate["kind"] != kind:
            raise ValueError(f"unexpected execution label in {path}")
        differences = [field for field in FIELDS
                       if candidate[field] != x86[field]]
        if differences:
            print(f"FAIL original_x86_vs_{kind} different={','.join(differences)}")
            return 1
        print(f"PASS original_x86_vs_{kind} boundary=0x{x86['boundary']} "
              "registers=matched flags=matched fs_head=matched stack=matched")
    return 0


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("reference", type=Path)
    parser.add_argument("host", type=Path)
    parser.add_argument("android", type=Path)
    args = parser.parse_args()
    raise SystemExit(compare(args.reference, args.host, args.android))
