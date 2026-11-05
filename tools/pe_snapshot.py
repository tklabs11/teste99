#!/usr/bin/env python3

import argparse
import hashlib
import json
from pathlib import Path

import pefile


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def import_names(pe: pefile.PE) -> dict[str, list[str]]:
    imports: dict[str, list[str]] = {}
    for descriptor in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
        dll = descriptor.dll.decode("ascii", errors="replace")
        names: list[str] = []
        for entry in descriptor.imports:
            if entry.name:
                names.append(entry.name.decode("ascii", errors="replace"))
            else:
                names.append(f"ordinal:{entry.ordinal}")
        imports[dll] = sorted(names)
    return dict(sorted(imports.items(), key=lambda item: item[0].lower()))


def directory_offsets(pe: pefile.PE) -> dict[str, int | None]:
    names = (
        "EXPORT_TABLE",
        "IMPORT_TABLE",
        "RESOURCE_TABLE",
        "EXCEPTION_TABLE",
        "SECURITY_DIRECTORY",
        "BASERELOC_TABLE",
        "DEBUG_DIRECTORY",
        "ARCHITECTURE",
        "GLOBALPTR",
        "TLS_TABLE",
        "LOAD_CONFIG_TABLE",
        "BOUND_IMPORT",
        "IAT",
        "DELAY_IMPORT_DESC",
        "COM_DESCRIPTOR",
    )
    result: dict[str, int | None] = {}
    for index, name in enumerate(names):
        directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[index]
        result[name] = directory.VirtualAddress if directory.VirtualAddress else None
    return result


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Create a reproducible PE snapshot for static recompilation research."
    )
    parser.add_argument("pe", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    pe_path = args.pe.resolve()
    pe = pefile.PE(str(pe_path), fast_load=False)
    report = {
        "path": str(pe_path),
        "sha256": sha256(pe_path),
        "machine": pe.FILE_HEADER.Machine,
        "is_x86": pe.FILE_HEADER.Machine == pefile.MACHINE_TYPE["IMAGE_FILE_MACHINE_I386"],
        "subsystem": pe.OPTIONAL_HEADER.Subsystem,
        "image_base": pe.OPTIONAL_HEADER.ImageBase,
        "entry_point": pe.OPTIONAL_HEADER.AddressOfEntryPoint,
        "size_of_image": pe.OPTIONAL_HEADER.SizeOfImage,
        "size_of_headers": pe.OPTIONAL_HEADER.SizeOfHeaders,
        "checksum": pe.OPTIONAL_HEADER.CheckSum,
        "directory_addresses": directory_offsets(pe),
        "number_of_symbols": pe.FILE_HEADER.NumberOfSymbols,
        "pointer_to_symbol_table": pe.FILE_HEADER.PointerToSymbolTable,
        "sections": [
            {
                "name": section.Name.decode("ascii", errors="replace").rstrip("\x00"),
                "virtual_address": section.VirtualAddress,
                "virtual_size": section.Misc_VirtualSize,
                "raw_size": section.SizeOfRawData,
            }
            for section in pe.sections
        ],
        "imports": import_names(pe),
    }
    report["import_dll_count"] = len(report["imports"])
    report["import_count"] = sum(len(names) for names in report["imports"].values())

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(f"Wrote {args.output} ({report['import_count']} imports across {report['import_dll_count']} DLLs)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
