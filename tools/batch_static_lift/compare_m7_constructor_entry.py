"""Compare the constructor-to-FUN_00a2a210 native and ARM64 snapshots."""

import argparse
from pathlib import Path


FIELDS = (
    "eax", "ecx", "ebx", "esp_delta", "ebp", "esi", "edi",
    "eflags", "fs_head_delta", "seh_prev", "seh_handler",
    "seh_cookie", "stack_object", "saved", "object",
)


def snapshot(path: Path, kind: str):
    lines = path.read_text(encoding="utf-8-sig").splitlines()
    records = [line for line in lines if line.startswith(f"case={kind} ")]
    if len(records) != 1:
        raise ValueError(f"expected one {kind} snapshot in {path}")
    values = dict(token.split("=", 1) for token in records[0].split()
                  if "=" in token)
    if any(field not in values for field in FIELDS):
        raise ValueError(f"incomplete {kind} snapshot in {path}")
    return values


def compare(x86_log: Path, android_log: Path, boundary: str = "0x00a2a24e"):
    x86_text = x86_log.read_text(encoding="utf-8-sig")
    arm_text = android_log.read_text(encoding="utf-8-sig")
    if f"PASS original_x86_vs_lifted_x86 stop={boundary}" not in x86_text:
        raise ValueError("native x86 comparison did not pass")
    if f"PASS lifted_arm64 stop={boundary}" not in arm_text:
        raise ValueError("Android ARM64 path did not reach the boundary")
    reference = snapshot(x86_log, "original_x86")
    for kind, path in (("lifted_x86", x86_log),
                       ("lifted_arm64", android_log)):
        candidate = snapshot(path, kind)
        differences = [field for field in FIELDS
                       if candidate[field] != reference[field]]
        if differences:
            print(f"FAIL original_x86_vs_{kind} different={','.join(differences)}")
            return 1
        print(f"PASS original_x86_vs_{kind} constructor_call=0x00a33817 "
              f"boundary={boundary} registers=matched_except_caller_saved_edx "
              "flags=matched stack=matched object=matched")
    return 0


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("x86_log", type=Path)
    parser.add_argument("android_log", type=Path)
    parser.add_argument("--boundary", default="0x00a2a24e")
    args = parser.parse_args()
    raise SystemExit(compare(args.x86_log, args.android_log, args.boundary))
