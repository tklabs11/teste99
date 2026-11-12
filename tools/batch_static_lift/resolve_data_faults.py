#!/usr/bin/env python3
"""Turn a logged guest data fault into the image window that answers it.

The guest names every access it cannot serve (`fault=read@0x.../4 pc=0x...`), and
the walk stops at the first one. This tool reads those lines, looks the address up
in the original PE and produces exactly the window the image is missing — the
pointer run when the address is one, the string when it is text, the aligned word
otherwise — so the repair is one command from the log instead of one investigation
per wall.

`--apply` inserts the new windows into ``generate_initterm_guest_image.py``. The
insertion is idempotent: a window already covering the address is never added
twice, and an address covered by an existing window is reported and skipped.
"""

import argparse
import json
import re
import sys
from pathlib import Path

import BatchStaticLift as lifter
import find_pointer_tables as tables
import generate_initterm_guest_image as image

FAULT_LINE = re.compile(
    r"fault=(read|write)@0x([0-9a-fA-F]+)/(\d+)"
    r"(?:\s+pc=0x([0-9a-fA-F]+))?")
# The image generator refuses to build when a lifted body reads an address no
# window covers, and names each one with the bodies that read it — possibly
# several, separated by slashes. Those are the same repair, found before a run
# instead of during one.
STATIC_READ = re.compile(r"0x([0-9a-fA-F]{8})\s*\(spore[\w/]*\)")
# Printable ASCII plus the whitespace a C string may contain.
STRING_BYTES = set(range(0x20, 0x7F)) | {0x09, 0x0A, 0x0D}
MAX_STRING_BYTES = 0x200


def read_log_text(path):
    """The log as one string, whatever encoding the shell wrote it in.

    PowerShell's ``>`` writes UTF-16LE, so a log produced that way has NUL bytes
    between characters and a UTF-8 read turns it into unparsable text.
    """

    raw = Path(path).read_bytes()
    if raw[:2] in (b"\xff\xfe", b"\xfe\xff") or (len(raw) > 1 and raw[1:2] == b"\x00"):
        return raw.decode("utf-16-le", errors="replace")
    if raw[:2] == b"\xef\xbb\xbf":
        return raw[2:].decode("utf-8", errors="replace")
    return raw.decode("utf-8", errors="replace")


def read_log_lines(path):
    return read_log_text(path).splitlines()


def parse_faults(paths):
    """Every fault a set of logs recorded, in the order it happened.

    The whole text is searched, not each line: a shell that wraps long lines can
    put an address and the name it belongs to on different lines.
    """

    found = []
    for path in paths:
        text = read_log_text(path)
        ordered = []
        for match in FAULT_LINE.finditer(text):
            ordered.append((match.start(), {
                "log": str(path),
                "static": False,
                "write": match.group(1) == "write",
                "address": int(match.group(2), 16),
                "size": int(match.group(3)),
                "pc": int(match.group(4), 16) if match.group(4) else 0,
            }))
        for match in STATIC_READ.finditer(text):
            ordered.append((match.start(), {
                "log": str(path),
                "static": True,
                "write": False,
                "address": int(match.group(1), 16),
                "size": 4,
                "pc": 0,
            }))
        ordered.sort(key=lambda item: item[0])
        found.extend(record for _, record in ordered)
    return found


def section_of(sections, image_base, address):
    """The parsed section tuple that contains an address, or None."""

    rva = address - image_base
    for section in sections:
        name, section_rva, virtual_size, _, raw_size = section
        if section_rva <= rva < section_rva + max(virtual_size, raw_size):
            return section
    return None


def string_bounds(data, offset, limit=MAX_STRING_BYTES):
    """Bounds of the printable run around ``offset``, including its terminator.

    Returns ``(start, end)`` relative to ``data`` or None when the byte at
    ``offset`` is not printable. The run stops at the first byte that is neither
    printable nor the terminator, so the window never swallows a table.
    """

    if offset >= len(data) or data[offset] not in STRING_BYTES:
        return None
    start = offset
    while (start > 0 and data[start - 1] in STRING_BYTES
           and offset - start < limit):
        start -= 1
    end = offset
    while (end + 1 < len(data) and data[end + 1] in STRING_BYTES
           and end + 1 - start < limit):
        end += 1
    # The terminator is part of what the guest reads.
    if end + 1 < len(data) and data[end + 1] == 0:
        end += 1
    return start, end + 1


def covering_window(windows, address, size):
    """The declared window that already serves an access, or None."""

    for base, window_size, name, _, _ in windows:
        if base <= address and address + size <= base + window_size:
            return name
    return None


def describe_neighbour(data, end):
    """What follows a run, as evidence for where its bound comes from."""

    if end + 4 > len(data):
        return "end of the readable section"
    word = int.from_bytes(data[end:end + 4], "little")
    if word == 0xCCCCCCCC:
        return "int3 padding"
    if word == 0:
        return "a zero word"
    if all(byte in STRING_BYTES for byte in data[end:end + 4]):
        return "text"
    return f"the non-pointer word 0x{word:08x}"


def source_clause(fault):
    """The instruction the fault came from, when the log named one."""

    if not fault.get("pc"):
        return ""
    return f" from 0x{fault['pc']:08x}"


def access_clause(fault):
    """The verb for what the guest was doing: a write is not a read."""

    return "writes" if fault.get("write") else "reads"


def data_block_bounds(data, offset, code_spans, limit=MAX_STRING_BYTES):
    """Bounds of the non-text, non-pointer block around ``offset``.

    A class descriptor or a small table sits between runs of text and runs of code
    pointers. Expanding to that block is what stops a guest read from needing one
    four-byte window per fault: the block is bounded by what is observed in the
    file, not by a guessed margin.
    """

    if offset >= len(data):
        return None

    def is_text(index):
        word = data[index:index + 4]
        return len(word) == 4 and all(byte in STRING_BYTES for byte in word)

    def is_code(index):
        if index + 4 > len(data):
            return False
        value = int.from_bytes(data[index:index + 4], "little")
        return any(low <= value < high for low, high in code_spans)

    def is_block(index):
        return not is_text(index) and not is_code(index)

    aligned = offset - (offset % 4)
    if not is_block(aligned):
        return None
    start = aligned
    while start >= 4 and is_block(start - 4) and aligned - start < limit:
        start -= 4
    end = aligned + 4
    while end + 4 <= len(data) and is_block(end) and end - start < limit:
        end += 4
    return start, end


def plan_static_reads(pe, addresses):
    """One window per run of consecutive words a lifted body reads directly.

    A body that reads an absolute address names exactly the words it needs, so the
    window is the union of those words and nothing else. Heuristics do not apply
    here: a float constant table can look like ASCII, and a wide guess would cover
    data no body asked for.
    """

    _, image_base, sections = pe
    ordered = sorted(set(addresses))
    runs = []
    for address in ordered:
        if runs and address == runs[-1][1] + 4:
            runs[-1][1] = address
        else:
            runs.append([address, address])
    planned = []
    for start, last in runs:
        section = section_of(sections, image_base, start)
        if section is None:
            continue
        name, _, _, _, _ = section
        stem = name.strip("\0").lstrip(".").replace("/", "_") or "image"
        base = start - (start % 4)
        end = last + 4
        planned.append({
            "status": "window",
            "base": base,
            "size": end - base,
            "name": f"{stem}_reads_{base:08x}",
            "writable": name.strip("\0") == ".data",
            "reason": (
                f"the {end - base >> 2} word(s) a lifted body reads directly, "
                f"from 0x{start:08x} to 0x{last:08x}; the addresses are the ones "
                f"the image generator reported as unmapped"),
            "kind": "static_reads",
        })
    return planned


def plan_window(pe, windows, fault):
    """The window a fault needs, or a reason it needs none."""

    _, image_base, sections = pe
    address = fault["address"]
    size = max(fault["size"], 4)
    covered = covering_window(windows, address, size)
    if covered is not None:
        return {"status": "covered", "window": covered}
    section = section_of(sections, image_base, address)
    if section is None:
        return {"status": "no_section",
                "reason": f"0x{address:08x} is not in any PE section"}
    name, section_rva, virtual_size, _, raw_size = section
    stem = name.strip("\0").lstrip(".").replace("/", "_") or "image"
    section_base = image_base + section_rva
    span = max(virtual_size, raw_size)

    # The window is read from a word-aligned start that leaves room on both
    # sides, so a run or a block can be measured in both directions and never
    # past the section: a window cannot cover bytes the file does not have.
    aligned_base = address - (address % 4)

    # BSS has no file content, so no byte in the file can bound a window there.
    # The loader works in pages, so a whole page is the only bound that comes
    # from the platform rather than from a guess; the generator zero-fills it
    # exactly as the loader would.
    if image.classify(pe, address, size) == "bss":
        page_base = address - (address % 0x1000)
        page_end = min(page_base + 0x1000, section_base + span)
        page_size = page_end - page_base
        if page_size >= size and image.classify(pe, page_base, page_size) == "bss":
            return {
                "status": "window",
                "base": page_base,
                "size": page_size,
                "name": f"{stem}_page_{page_base:08x}",
                "writable": True,
                "reason": (
                    f"the loader-zeroed page the guest {access_clause(fault)} at "
                    f"0x{address:08x}{source_clause(fault)}; the file holds no "
                    f"bytes here, so the page is zero-filled at load time"),
                "kind": "bss_page",
            }

    back = min(256, aligned_base - section_base)
    back -= back % 4
    read_start = aligned_base - back
    # Both directions need room: a string or a block that starts before the fault
    # still has to be readable past it, or the scan ends at the fault address and
    # reports a window that stops one byte short of what the guest needs.
    limit = min(4096, span - (read_start - section_base))
    try:
        _, _, data = lifter.read_pe_bytes(pe, read_start, limit)
    except ValueError:
        return {"status": "not_backed",
                "reason": (f"0x{address:08x} is past the raw data of "
                           f"{name.strip(chr(0))}")}
    fault_offset = address - read_start

    spans = tables.code_spans(sections, image_base)
    words = [
        int.from_bytes(data[offset:offset + 4], "little")
        for offset in range(0, len(data) - 3, 4)
    ]
    for start, end, targets in tables.pointer_runs(words, read_start, spans):
        if start <= address < end:
            return {
                "status": "window",
                "base": start,
                "size": end - start,
                "name": f"{stem}_{start:08x}",
                "writable": False,
                "reason": (
                    f"the {len(targets)}-entry run of code pointers the guest "
                    f"{access_clause(fault)} at 0x{address:08x}{source_clause(fault)}; the run "
                    f"ends at {describe_neighbour(data, end - read_start)}"),
                "kind": "code_pointer_run",
            }
    bounds = string_bounds(data, fault_offset, limit)
    if bounds is not None:
        start, end = bounds
        # Windows are word-aligned like the loader's own granularity, so a string
        # never starts inside a word that another window may already own.
        base_abs = (read_start + start) & ~3
        end_abs = read_start + end
        # The end is word-aligned too, and never before the access it serves.
        minimum_end = (address + size + 3) & ~3
        end_abs = end_abs & ~3
        if end_abs < minimum_end:
            end_abs = minimum_end
        # A string table stores its entries back to back, separated by a single
        # NUL. Covering one entry per fault would cost a window per string, so the
        # window grows over every adjacent word that is entirely text or NUL and
        # stops at the first word that is not — an observed bound, not a margin.
        def text_word(offset):
            word = data[offset:offset + 4]
            return len(word) == 4 and all(
                byte in STRING_BYTES or byte == 0 for byte in word)

        while base_abs - 4 >= section_base:
            offset = base_abs - 4 - read_start
            if offset < 0 or not text_word(offset):
                break
            base_abs -= 4
        while end_abs + 4 <= section_base + span:
            offset = end_abs - read_start
            if offset + 4 > len(data) or not text_word(offset):
                break
            end_abs += 4
        return {
            "status": "window",
            "base": base_abs,
            "size": end_abs - base_abs,
            "name": f"{stem}_strings_{base_abs:08x}",
            "writable": False,
            "reason": (
                f"the string table the guest {access_clause(fault)} at "
                f"0x{address:08x}{source_clause(fault)}; it covers every adjacent "
                f"word of text and stops at the first word that is not"),
            "kind": "string_table",
        }
    block = data_block_bounds(data, fault_offset, spans, limit)
    if block is not None:
        start, end = block
        return {
            "status": "window",
            "base": read_start + start,
            "size": end - start,
            "name": f"{stem}_block_{read_start + start:08x}",
            "writable": name.strip("\0") == ".data",
            "reason": (
                f"the block of data the guest {access_clause(fault)} at 0x{address:08x}"
                f"{source_clause(fault)}; it is bounded by the text and the code "
                f"pointer runs around it"),
            "kind": "data_block",
        }
    return {
        "status": "window",
        "base": aligned_base,
        "size": size,
        "name": f"{stem}_{aligned_base:08x}",
        "writable": name.strip("\0") == ".data",
        "reason": (
            f"the word the guest {access_clause(fault)} at 0x{address:08x}"
            f"{source_clause(fault)}; the file supplies it unchanged"),
        "kind": "word",
    }


def render_entry(window):
    """One ``WINDOWS`` entry, in the shape the generator already uses."""

    size = (f"0x{window['size']:02x}" if window["size"] < 0x100
            else f"0x{window['size']:x}")
    writable = "True" if window["writable"] else "False"
    return (
        f"    (0x{window['base']:08x}, {size}, \"{window['name']}\", {writable},\n"
        f"     \"{window['reason']}\"),\n"
    )


def reconcile(pe, window):
    """Grow a planned window over the windows it overlaps, or refuse.

    The guest map rejects overlap, so a new window must absorb what it touches.
    Absorbing is only safe when the whole merged range is the same kind of data:
    mixing file bytes with loader-zeroed BSS inside one window would emit the
    wrong contents for part of it, so that case fails loudly instead.
    """

    superseded = list(window.get("superseded", []))
    base, size = window["base"], window["size"]
    kind = image.classify(pe, base, size)
    changed = True
    while changed:
        changed = False
        for existing in image.WINDOWS:
            name, other_base, other_size = existing[2], existing[0], existing[1]
            if name == window["name"] or name in superseded:
                continue
            if (other_base + other_size <= base
                    or base + size <= other_base):
                continue
            low = min(base, other_base)
            high = max(base + size, other_base + other_size)
            merged = image.classify(pe, low, high - low)
            if merged != kind:
                raise SystemExit(
                    f"window {window['name']} overlaps {name} and the merged "
                    f"range would be {merged} while the window is {kind}")
            base, size = low, high - low
            superseded.append(name)
            changed = True
    window["base"], window["size"] = base, size
    window["superseded"] = superseded
    return superseded


def apply_windows(path, windows, pe=None, log=None):
    """Insert entries into the generator's ``WINDOWS`` list."""

    if not windows:
        return []
    source = Path(path).read_text(encoding="utf-8")
    marker = "WINDOWS = ["
    dropped = []
    for window in windows:
        if pe is not None:
            dropped.extend(reconcile(pe, window))
        # A planned window that reuses a declared name is a replacement: the same
        # name cannot appear twice, and the plan was made from the same evidence.
        dropped.append(window["name"])
    for name in dropped:
        entry = re.compile(r"    \([^)]*\"%s\".*?\),\n" % re.escape(name), re.S)
        source = entry.sub("", source)
        if log is not None:
            log(f"superseded {name}")
    start = source.index(marker)
    end = source.index("\n]\n", start)
    block = "".join(render_entry(window) for window in windows)
    Path(path).write_text(
        source[:end] + "\n" + block.rstrip("\n") + source[end:],
        encoding="utf-8",
    )
    return dropped


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--log", type=Path, nargs="+", default=[],
                        help="stage logs to read faults from")
    parser.add_argument("--address", nargs="+", default=[],
                        help="explicit fault addresses when no log is given")
    parser.add_argument("--size", type=int, default=4,
                        help="access width for explicit addresses")
    parser.add_argument("--write", action="store_true",
                        help="explicit addresses are writes, not reads")
    parser.add_argument("--apply", action="store_true",
                        help="insert the planned windows into the generator")
    parser.add_argument("--json", type=Path)
    args = parser.parse_args()

    if lifter.sha256_file(args.reference) != lifter.EXPECTED_SHA256:
        raise SystemExit("reference PE hash does not match the verified build")
    if not args.log and not args.address:
        parser.error("give at least one --log or --address")

    faults = parse_faults(args.log)
    faults += [
        {"log": "<argument>", "static": False, "write": args.write,
         "size": args.size,
         "address": int(value, 0), "pc": 0}
        for value in args.address
        if value != "none"
    ]
    if not faults:
        raise SystemExit("no fault in the supplied logs")

    pe = lifter.parse_pe(args.reference)
    windows = list(image.WINDOWS)
    planned = []
    reports = []
    # A fault without a program counter came from the image generator's static
    # scan, not from an execution: those name the exact words a body reads.
    static = [fault["address"] for fault in faults if fault.get("static")]
    runtime = [fault for fault in faults if not fault.get("static")]
    for plan in plan_static_reads(pe, static):
        if any(window["base"] == plan["base"] for window in planned):
            continue
        planned.append(plan)
        windows.append((
            plan["base"], plan["size"], plan["name"],
            plan["writable"], plan["reason"],
        ))
    for fault in runtime:
        plan = plan_window(pe, windows, fault)
        plan["fault"] = {
            "address": f"0x{fault['address']:08x}",
            "size": fault["size"],
            "write": fault["write"],
            "pc": f"0x{fault['pc']:08x}" if fault["pc"] else None,
        }
        reports.append(plan)
        if plan["status"] != "window":
            continue
        if any(window["base"] == plan["base"] for window in planned):
            continue
        planned.append(plan)
        windows.append((
            plan["base"], plan["size"], plan["name"],
            plan["writable"], plan["reason"],
        ))

    rendered = []
    for plan in planned:
        rendered.append(render_entry(plan))
        print(f"WINDOW {plan['name']} 0x{plan['base']:08x}/0x{plan['size']:x} "
              f"{plan['kind']}")
        print(render_entry(plan).rstrip("\n"))
    for report in reports:
        if report["status"] == "covered":
            print(f"covered {report['fault']['address']} by "
                  f"{report['window']}")
        elif report["status"] != "window":
            print(f"skipped {report['fault']['address']}: "
                  f"{report['reason']}")
    if args.apply and planned:
        apply_windows(
            Path(image.__file__).resolve(), planned, pe=pe, log=print)
        print(f"applied {len(planned)} window(s) to {Path(image.__file__).name}")
    result = {
        "reference_sha256": lifter.EXPECTED_SHA256,
        "faults": reports,
        "planned": planned,
        "rendered": rendered,
    }
    if args.json:
        args.json.write_text(json.dumps(result, indent=2) + "\n",
                             encoding="utf-8")
    return 0


if __name__ == "__main__":
    sys.exit(main())
