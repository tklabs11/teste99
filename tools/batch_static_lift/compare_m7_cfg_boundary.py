"""Compare the x86 original, host lift, and Android ARM64 boundary fixtures."""

import argparse
from pathlib import Path


FIELDS = (
    "boundary", "eax", "ecx", "edx", "ebx", "esp_delta",
    "ebp", "esi", "edi", "flags", "fields", "buffer",
)


def snapshot(path: Path):
    lines = path.read_text(encoding="utf-8-sig").splitlines()
    records = [line for line in lines if line.startswith("kind=")]
    if len(records) != 1:
        raise ValueError(f"expected exactly one snapshot in {path}")
    result = dict(token.split("=", 1) for token in records[0].split()
                  if "=" in token)
    if any(field not in result for field in FIELDS):
        raise ValueError(f"snapshot lacks fields in {path}")
    return result


def compare(reference: Path, host: Path, android: Path):
    baseline = snapshot(reference)
    if baseline["kind"] != "original_x86":
        raise ValueError("reference is not labeled original_x86")
    reference_text = reference.read_text(encoding="utf-8-sig")
    if "boundary_reached=True" not in reference_text or "error=none" not in reference_text:
        raise ValueError("x86 reference did not reach its boundary cleanly")
    for label, path in (("lift_x86_host", host), ("lift_android_arm64", android)):
        candidate = snapshot(path)
        if candidate["kind"] != label:
            raise ValueError(f"expected {label} snapshot in {path}")
        differences = [field for field in FIELDS
                       if candidate[field] != baseline[field]]
        if differences:
            print(f"FAIL {label} different={','.join(differences)}")
            return 1
        print(f"PASS original_x86_vs_{label} boundary=0x{baseline['boundary']} "
              "registers=matched flags=matched object=matched buffer=matched")
    return 0


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("reference", type=Path)
    parser.add_argument("host", type=Path)
    parser.add_argument("android", type=Path)
    args = parser.parse_args()
    raise SystemExit(compare(args.reference, args.host, args.android))
