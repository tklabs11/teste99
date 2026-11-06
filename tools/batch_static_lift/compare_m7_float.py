"""Compare PE-backed FUN_00921360 x86 and Android fixture outputs."""

import argparse
import re
from pathlib import Path


def fields(line):
    return dict(re.findall(r"(case|status|eax|output|flags|depth)=([0-9a-f]+)", line))


def compare(reference, arm64):
    original = Path(reference).read_text(encoding="utf-8").splitlines()
    translated = Path(arm64).read_text(encoding="utf-8").splitlines()
    if len(original) != len(translated) or len(original) != 4:
        raise ValueError("expected four fixture snapshots on each side")
    good = True
    for index, (left, right) in enumerate(zip(original, translated)):
        x86, arm = fields(left), fields(right)
        passed = (x86.get("case") == arm.get("case") == str(index)
                  and arm.get("status") == "0" and arm.get("depth") == "0"
                  and x86.get("eax") == arm.get("eax")
                  and x86.get("output") == arm.get("output"))
        # Final flags come from ADD ESP,0x10; PF depends on the different native
        # and guest stack addresses. UCOMISS flags need a separate micro-test.
        print(f"{'PASS' if passed else 'FAIL'} case={index} "
              f"x86_original_vs_arm64_lift eax={arm.get('eax')} output={arm.get('output')}")
        good &= passed
    return 0 if good else 1


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("reference")
    parser.add_argument("arm64")
    args = parser.parse_args()
    raise SystemExit(compare(args.reference, args.arm64))
