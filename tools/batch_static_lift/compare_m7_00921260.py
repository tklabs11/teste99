"""Compare full-function native x86 reference with translated snapshots.

Both programs use isolated fixtures, not game boot state. The original x86
program executes byte-verified PE instructions. The lift is compiled for the
chosen host or Android target.
"""

import argparse
import re
from pathlib import Path

REFERENCE = re.compile(
    r"case=(\d+) result=([0-9a-f]+) flags=([0-9a-f]+) "
    r"output=([0-9a-f]+) object=([0-9a-f]+)"
)
LIFT = re.compile(
    r"case=(\d+) status=(\d+) eip=([0-9a-f]+) flags=([0-9a-f]+) "
    r"output=([0-9a-f]+) regs=([0-9a-f,]+) object=([0-9a-f]+)"
)


def compare(reference_path, lift_path):
    references = Path(reference_path).read_text(encoding="utf-8").splitlines()
    lifts = Path(lift_path).read_text(encoding="utf-8").splitlines()
    if len(references) != 3 or len(lifts) != 3:
        raise ValueError("expected exactly three fixture snapshots per side")
    success = True
    for index, (reference, translated) in enumerate(zip(references, lifts)):
        original = REFERENCE.fullmatch(reference)
        lift = LIFT.fullmatch(translated)
        if not original or not lift:
            raise ValueError(f"unrecognized snapshot format in case {index}")
        registers = lift[6].split(",")
        checks = {
            "case": original[1] == lift[1] == str(index),
            "status": lift[2] == "0",
            "return_address": lift[3] == "00921300",
            "eax": original[2] == registers[0],
            "flags": original[3] == lift[4],
            "output": original[4] == lift[5],
            "object": original[5] == lift[7],
        }
        failed = [name for name, passed in checks.items() if not passed]
        if failed:
            success = False
            print(f"FAIL case={index} fields={','.join(failed)}")
        else:
            print(f"PASS case={index} x86_original_vs_lift instructions=38")
    return 0 if success else 1


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("reference")
    parser.add_argument("lift")
    args = parser.parse_args()
    raise SystemExit(compare(args.reference, args.lift))
