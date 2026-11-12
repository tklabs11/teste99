#!/usr/bin/env python3
"""Merge measured closures into one file, newest measurement winning.

Each input is a ``closure.json`` produced by ``prepare_cpp_initializer_batch``.
A body is kept once, keyed by its canonical entry; when two measurements
disagree, the record that is not truncated wins, and otherwise the later input
wins because it was measured with the current boundary rules.
"""

import argparse
import json
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", type=Path, nargs="+", required=True,
                        help="closures to merge, oldest first")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    merged = {}
    replaced = 0
    for path in args.input:
        data = json.loads(path.read_text(encoding="utf-8"))
        for record in data["functions"]:
            function = record["function"]
            entry = function["entry"]
            previous = merged.get(entry)
            if previous is not None:
                previous_ok = previous.get("instructions_truncated") is False
                current_ok = function.get("instructions_truncated") is False
                if previous_ok and not current_ok:
                    continue
                replaced += 1
            merged[entry] = function

    closure = {"functions": [
        {"function": merged[entry]} for entry in sorted(merged)]}
    args.output.write_text(
        json.dumps(closure, indent=1) + "\n", encoding="utf-8")
    instructions = sum(
        len(function["instructions"]) for function in merged.values())
    truncated = sorted(
        entry for entry, function in merged.items()
        if function.get("instructions_truncated") is not False)
    print(f"merged {len(args.input)} closures into {len(merged)} bodies, "
          f"{instructions} instructions, {replaced} replaced, "
          f"{len(truncated)} truncated")
    for entry in truncated:
        print(f"   truncated {entry}")


if __name__ == "__main__":
    main()
