#!/usr/bin/env python3

import argparse
import collections
import csv
import hashlib
import json
import re
import struct
import sys
from pathlib import Path


EXPECTED_SHA256 = "6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b"
EXPECTED_LANGUAGE = "x86:LE:32:default"
MAX_INPUT_BYTES = 256 * 1024 * 1024
MAX_BATCH_BYTES = 128 * 1024 * 1024
PILOT_SELECTION_COUNTS = {
    30: {"small": 10, "medium": 10, "conditional_branch": 10},
    100: {"small": 30, "medium": 30, "conditional_branch": 40},
    300: {"small": 90, "medium": 90, "conditional_branch": 120},
}
REGISTER_INDEX = {
    "EAX": 0,
    "ECX": 1,
    "EDX": 2,
    "EBX": 3,
    "ESP": 4,
    "EBP": 5,
    "ESI": 6,
    "EDI": 7,
}
REGISTER = re.compile(r"^(EAX|ECX|EDX|EBX|ESP|EBP|ESI|EDI)$", re.IGNORECASE)
REGISTER_ALIASES = {
    "AL": (0, 8, 0), "CL": (1, 8, 0), "DL": (2, 8, 0), "BL": (3, 8, 0),
    "AH": (0, 8, 8), "CH": (1, 8, 8), "DH": (2, 8, 8), "BH": (3, 8, 8),
    "AX": (0, 16, 0), "CX": (1, 16, 0), "DX": (2, 16, 0), "BX": (3, 16, 0),
    "SP": (4, 16, 0), "BP": (5, 16, 0), "SI": (6, 16, 0), "DI": (7, 16, 0),
}
MEMORY_OPERAND = re.compile(
    r"^(?:(byte|word|dword|qword|double|float|xmmword) ptr )?\[\s*"
    r"(EAX|ECX|EDX|EBX|ESP|EBP|ESI|EDI)"
    r"(?:\s*([+-])\s*(-?(?:0x[0-9a-f]+|[0-9]+)))?\s*\]$",
    re.IGNORECASE,
)
INDEXED_MEMORY_OPERAND = re.compile(
    r"^(?:(byte|word|dword|qword|double|float|xmmword) ptr )?\[\s*"
    r"(EAX|ECX|EDX|EBX|ESP|EBP|ESI|EDI)\s*\+\s*"
    r"(EAX|ECX|EDX|EBX|EBP|ESI|EDI)\s*\*\s*"
    r"(0x[0-9a-f]+|[0-9]+)"
    r"(?:\s*([+-])\s*(-?(?:0x[0-9a-f]+|[0-9]+)))?\s*\]$",
    re.IGNORECASE,
)
# A scaled index with no base register, which is how a jump or lookup table is
# addressed: "dword ptr [EAX*0x4 + 0x6923e0]".
INDEX_ONLY_MEMORY_OPERAND = re.compile(
    r"^(?:(byte|word|dword|qword|double|float|xmmword) ptr )?\[\s*"
    r"(EAX|ECX|EDX|EBX|ESP|EBP|ESI|EDI)\s*\*\s*"
    r"(0x[0-9a-f]+|[0-9]+)"
    r"(?:\s*([+-])\s*(-?(?:0x[0-9a-f]+|[0-9]+)))?\s*\]$",
    re.IGNORECASE,
)
FS_MEMORY_OPERAND = re.compile(
    r"^(?:(byte|word|dword|qword|double|float) ptr )?FS:\[\s*"
    r"([+-]?(?:0x[0-9a-f]+|[0-9]+))\s*\]$",
    re.IGNORECASE,
)
ABSOLUTE_MEMORY_OPERAND = re.compile(
    r"^(?:(byte|word|dword|qword|double|float|xmmword) ptr )?\[\s*(0x[0-9a-f]+|[0-9]+)\s*\]$",
    re.IGNORECASE,
)
XMM_REGISTER = re.compile(r"^XMM([0-7])$", re.IGNORECASE)
X87_ST_REGISTER = re.compile(r"^ST([0-7])$", re.IGNORECASE)
# x87 arithmetic codes match batch_guest_x87_compute: the left operand is the
# destination, and codes 4 and 5 are the reversed forms the FSUBR/FDIVR
# mnemonics select.
X87_ARITHMETIC = {
    "FADD": 0, "FMUL": 1, "FDIV": 2, "FSUB": 3, "FSUBR": 4, "FDIVR": 5,
}
X87_ARITHMETIC_POP = {
    "FADDP": 0, "FMULP": 1, "FDIVP": 2, "FSUBP": 3, "FSUBRP": 4, "FDIVRP": 5,
}
# How many stack registers each compare form pops, and which ones also copy the
# result into EFLAGS instead of only the x87 status word.
X87_COMPARE_POPS = {
    "FCOM": 0, "FCOMP": 1, "FCOMPP": 2, "FUCOMPP": 2,
    "FCOMI": 0, "FCOMIP": 1, "FUCOMI": 0, "FUCOMIP": 1,
}
X87_EFLAGS_COMPARES = {"FCOMI", "FCOMIP", "FUCOMI", "FUCOMIP"}
# Every operand kind that reads guest memory through an effective address.
MEMORY_OPERAND_KINDS = {
    "absolute_memory", "memory", "fs_memory", "indexed_memory",
}
ADDRESS = re.compile(r"^0x[0-9a-fA-F]+$")
SSE_DATA_TRANSFER_MNEMONICS = {
    "MOVAPS", "MOVAPD", "MOVUPS", "MOVUPD", "MOVSS", "MOVSD",
    "MOVDQA", "MOVDQU", "MOVD", "MOVQ",
}
SSE_ARITHMETIC_MNEMONICS = {
    "ADDPS", "ADDPD", "ADDSS", "ADDSD", "SUBPS", "SUBPD", "SUBSS",
    "SUBSD", "MULPS", "MULPD", "MULSS", "MULSD", "DIVPS", "DIVPD",
    "DIVSS", "DIVSD", "MINPS", "MINPD", "MINSS", "MINSD", "MAXPS",
    "MAXPD", "MAXSS", "MAXSD", "SQRTPS", "SQRTPD", "SQRTSS",
    "SQRTSD", "RSQRTPS", "RCPPS",
}
SSE_LOGICAL_MNEMONICS = {
    "ANDPS", "ANDPD", "ANDNPS", "ANDNPD", "ORPS", "ORPD", "XORPS",
    "XORPD",
}
SSE_CONVERSION_MNEMONICS = {
    "CVTPS2PD", "CVTPD2PS", "CVTPS2DQ", "CVTTPS2DQ", "CVTDQ2PS",
    "CVTSS2SD", "CVTSD2SS", "CVTSS2SI", "CVTTSS2SI", "CVTSI2SS",
    "CVTSD2SI", "CVTTSD2SI", "CVTSI2SD",
}
CF = "((state.eflags & 0x001u) != 0u)"
PF = "((state.eflags & 0x004u) != 0u)"
ZF = "((state.eflags & 0x040u) != 0u)"
SF = "((state.eflags & 0x080u) != 0u)"
OF = "((state.eflags & 0x800u) != 0u)"
SUPPORTED_CONDITIONS = {
    "JA": f"!{CF} && !{ZF}",
    "JAE": f"!{CF}",
    "JB": CF,
    "JBE": f"{CF} || {ZF}",
    "JC": CF,
    "JE": ZF,
    "JZ": ZF,
    "JG": f"!{ZF} && ({SF} == {OF})",
    "JGE": f"{SF} == {OF}",
    "JL": f"{SF} != {OF}",
    "JLE": f"{ZF} || ({SF} != {OF})",
    "JNA": f"{CF} || {ZF}",
    "JNAE": CF,
    "JNB": f"!{CF}",
    "JNBE": f"!{CF} && !{ZF}",
    "JNC": f"!{CF}",
    "JNE": f"!{ZF}",
    "JNG": f"{ZF} || ({SF} != {OF})",
    "JNGE": f"{SF} != {OF}",
    "JNL": f"{SF} == {OF}",
    "JNLE": f"!{ZF} && ({SF} == {OF})",
    "JNO": f"!{OF}",
    "JNP": f"!{PF}",
    "JNS": f"!{SF}",
    "JNZ": f"!{ZF}",
    "JO": OF,
    "JP": PF,
    "JPE": PF,
    "JPO": f"!{PF}",
    "JS": SF,
}


class LiftRejected(Exception):
    def __init__(self, reasons, instruction_diagnostics):
        super().__init__("function contains instructions that cannot be translated")
        self.reasons = reasons
        self.instruction_diagnostics = instruction_diagnostics


def parse_address(value):
    if not isinstance(value, str) or not ADDRESS.fullmatch(value):
        raise ValueError(f"invalid address: {value!r}")
    return int(value, 16)


def parse_operand(text, infer_memory_width=None):
    value = text.strip()
    match = REGISTER.fullmatch(value)
    if match:
        return ("register", REGISTER_INDEX[match.group(1).upper()], 32, 0)
    alias = REGISTER_ALIASES.get(value.upper())
    if alias:
        return ("register", *alias)
    immediate = re.fullmatch(r"[+-]?(?:0x[0-9a-f]+|[0-9]+)", value, re.IGNORECASE)
    if immediate:
        number = value
        sign = -1 if number.startswith("-") else 1
        number = number[1:] if number[:1] in "+-" else number
        value_int = int(number, 16 if number.lower().startswith("0x") else 10) * sign
        return ("immediate", value_int & 0xFFFFFFFF, None, 0)
    match = ABSOLUTE_MEMORY_OPERAND.fullmatch(value)
    if match:
        token = match.group(2)
        address = int(token, 16 if token.lower().startswith("0x") else 10)
        memory_width = {
            "byte": 8,
            "word": 16,
            "dword": 32,
            "qword": 64,
            "double": 64,
            "float": 32,
            "xmmword": 128,
        }.get((match.group(1) or "").lower(), infer_memory_width)
        if memory_width is None:
            raise ValueError(f"memory operand width is ambiguous: {text!r}")
        return ("absolute_memory", address, 0, memory_width)
    match = FS_MEMORY_OPERAND.fullmatch(value)
    if match:
        token = match.group(2)
        sign = -1 if token.startswith("-") else 1
        token = token[1:] if token[:1] in "+-" else token
        displacement = sign * int(
            token, 16 if token.lower().startswith("0x") else 10
        )
        memory_width = {
            "byte": 8,
            "word": 16,
            "dword": 32,
            "qword": 64,
            "double": 64,
            "float": 32,
            "xmmword": 128,
        }.get((match.group(1) or "").lower(), infer_memory_width)
        if memory_width is None:
            raise ValueError(f"memory operand width is ambiguous: {text!r}")
        return ("fs_memory", displacement, 0, memory_width)
    match = MEMORY_OPERAND.fullmatch(value)
    if match:
        token = match.group(4)
        if token and token.startswith("-"):
            magnitude = token[1:]
            displacement = -(
                int(magnitude, 16) if magnitude.lower().startswith("0x")
                else int(magnitude, 10)
            )
        else:
            displacement = (
                int(token, 16) if token and token.lower().startswith("0x")
                else int(token, 10) if token
                else 0
            )
        if match.group(3) == "-":
            displacement = -displacement
        memory_width = {
            "byte": 8,
            "word": 16,
            "dword": 32,
            "qword": 64,
            "double": 64,
            "float": 32,
            "xmmword": 128,
        }.get((match.group(1) or "").lower(), infer_memory_width)
        if memory_width is None:
            raise ValueError(f"memory operand width is ambiguous: {text!r}")
        return (
            "memory",
            REGISTER_INDEX[match.group(2).upper()],
            displacement,
            memory_width,
        )
    match = INDEXED_MEMORY_OPERAND.fullmatch(value)
    if match:
        scale_token = match.group(4)
        scale = int(
            scale_token,
            16 if scale_token.lower().startswith("0x") else 10,
        )
        if scale not in {1, 2, 4, 8}:
            raise ValueError(f"unsupported x86 index scale in {text!r}")
        displacement_token = match.group(6)
        displacement = 0
        if displacement_token:
            negative = displacement_token.startswith("-")
            magnitude = displacement_token[1:] if negative else displacement_token
            displacement = int(
                magnitude, 16 if magnitude.lower().startswith("0x") else 10,
            ) * (-1 if negative else 1)
        if match.group(5) == "-":
            displacement = -displacement
        memory_width = {
            "byte": 8,
            "word": 16,
            "dword": 32,
            "qword": 64,
            "double": 64,
            "float": 32,
            "xmmword": 128,
        }.get((match.group(1) or "").lower(), infer_memory_width)
        if memory_width is None:
            raise ValueError(f"memory operand width is ambiguous: {text!r}")
        return (
            "indexed_memory",
            REGISTER_INDEX[match.group(2).upper()],
            REGISTER_INDEX[match.group(3).upper()],
            scale,
            displacement,
            memory_width,
        )
    match = INDEX_ONLY_MEMORY_OPERAND.fullmatch(value)
    if match:
        scale_token = match.group(3)
        scale = int(
            scale_token,
            16 if scale_token.lower().startswith("0x") else 10,
        )
        if scale not in {1, 2, 4, 8}:
            raise ValueError(f"unsupported x86 index scale in {text!r}")
        displacement = 0
        displacement_token = match.group(5)
        if displacement_token:
            negative = displacement_token.startswith("-")
            magnitude = displacement_token[1:] if negative else displacement_token
            displacement = int(
                magnitude, 16 if magnitude.lower().startswith("0x") else 10,
            ) * (-1 if negative else 1)
        if match.group(4) == "-":
            displacement = -displacement
        memory_width = {
            "byte": 8,
            "word": 16,
            "dword": 32,
            "qword": 64,
            "double": 64,
            "float": 32,
            "xmmword": 128,
        }.get((match.group(1) or "").lower(), infer_memory_width)
        if memory_width is None:
            raise ValueError(f"memory operand width is ambiguous: {text!r}")
        return (
            "indexed_memory",
            None,
            REGISTER_INDEX[match.group(2).upper()],
            scale,
            displacement,
            memory_width,
        )
    raise ValueError(f"unsupported operand syntax or width: {text!r}")


def cpp_u32(value):
    return f"0x{value & 0xFFFFFFFF:08x}u"


def memory_address(operand):
    if operand[0] == "absolute_memory":
        return cpp_u32(operand[1])
    if operand[0] == "fs_memory":
        return (
            "static_cast<std::uint32_t>(state.fs_base + "
            f"{cpp_u32(operand[1])})"
        )
    if operand[0] == "indexed_memory":
        _, base, index, scale, displacement, _ = operand
        if base is None:
            return (
                "static_cast<std::uint32_t>("
                f"state.regs[{index}] * {scale}u + "
                f"{cpp_u32(displacement)})"
            )
        return (
            "static_cast<std::uint32_t>("
            f"state.regs[{base}] + state.regs[{index}] * {scale}u + "
            f"{cpp_u32(displacement)})"
        )
    _, register, displacement, _ = operand
    return f"static_cast<std::uint32_t>(state.regs[{register}] + {cpp_u32(displacement)})"


def width_mask(width):
    return (1 << width) - 1


def register_read(register, temp):
    _, index, width, shift = register
    mask = cpp_u32(width_mask(width))
    if shift:
        return [f"{temp} = (state.regs[{index}] >> {shift}u) & {mask};"]
    if width == 32:
        return [f"{temp} = state.regs[{index}];"]
    return [f"{temp} = state.regs[{index}] & {mask};"]


def emit_load(operand, temp):
    kind, value = operand[0], operand[1]
    if kind == "register":
        return register_read(operand, temp)
    if kind == "immediate":
        return [f"{temp} = {cpp_u32(value)};"]
    method = {
        8: "load8",
        16: "load16",
        32: "load32",
        64: "load64",
    }[operand_width(operand)]
    return [f"if (!memory.{method}({memory_address(operand)}, {temp})) "
            "return BatchLiftStatus::invalid_memory;"]


def emit_store(operand, value):
    kind = operand[0]
    if kind == "register":
        _, index, width, shift = operand
        if width == 32:
            return [f"state.regs[{index}] = {value};"]
        mask = width_mask(width) << shift
        return [
            f"state.regs[{index}] = (state.regs[{index}] & {cpp_u32(~mask)}) | "
            f"(({value} << {shift}u) & {cpp_u32(mask)});"
        ]
    if kind in {
        "absolute_memory", "memory", "fs_memory", "indexed_memory",
    }:
        method = {
            8: "store8",
            16: "store16",
            32: "store32",
            64: "store64",
        }[operand_width(operand)]
        return [f"if (!memory.{method}({memory_address(operand)}, {value})) "
                "return BatchLiftStatus::invalid_memory;"]
    raise ValueError("an immediate cannot be an instruction destination")


def resolve_operands(text_operands, infer_untyped_memory=True):
    operands = []
    for text in text_operands:
        try:
            operands.append(parse_operand(text))
        except ValueError as error:
            if "memory operand width is ambiguous" not in str(error):
                raise
            operands.append(None)
    widths = {
        operand[2] if operand[0] == "register" else
        operand[3] if operand[0] in {"absolute_memory", "memory"} else
        operand[5] if operand[0] == "indexed_memory" else None
        for operand in operands if operand is not None
    }
    widths.discard(None)
    inferred_width = (
        next(iter(widths))
        if infer_untyped_memory and len(widths) == 1
        else None
    )
    resolved = []
    for text, operand in zip(text_operands, operands):
        if operand is None:
            if inferred_width is None:
                raise ValueError(f"memory operand width is ambiguous: {text!r}")
            resolved.append(parse_operand(text, inferred_width))
        else:
            resolved.append(operand)
    return resolved


def operand_width(operand, default=None):
    if operand[0] == "register":
        return operand[2]
    if operand[0] in {
        "absolute_memory", "memory", "fs_memory", "indexed_memory",
    }:
        if operand[0] == "indexed_memory":
            return operand[5]
        return operand[3]
    return default


def classify_instruction(mnemonic):
    normalized = str(mnemonic).upper()
    if normalized == "MOVSS":
        return "sse_scalar_data_transfer"
    if normalized in SSE_DATA_TRANSFER_MNEMONICS:
        return "sse_data_transfer"
    if normalized in SSE_ARITHMETIC_MNEMONICS:
        return "sse_arithmetic"
    if normalized in SSE_LOGICAL_MNEMONICS:
        return "sse_logical"
    if normalized in SSE_CONVERSION_MNEMONICS:
        return "sse_conversion"
    if normalized.startswith("F"):
        return "x87"
    return "other"


def parse_movss_operand(text):
    value = text.strip()
    xmm = XMM_REGISTER.fullmatch(value)
    if xmm:
        return ("xmm", int(xmm.group(1)), 32, 0)
    return parse_operand(value, 32)


def branch_target(instruction, address_set):
    targets = instruction.get("flows_to", [])
    if len(targets) != 1:
        raise ValueError(
            f"branch has {len(targets)} statically resolved targets; exactly one is required"
        )
    target = parse_address(targets[0])
    if target not in address_set:
        raise ValueError(f"branch target {targets[0]} is not an exported instruction")
    return target


def direct_call_target(instruction):
    mnemonic = instruction.get("mnemonic", "").upper()
    flow = str(instruction.get("flow", "")).upper()
    if mnemonic != "CALL":
        raise ValueError(f"unsupported call transfer instruction {mnemonic or 'UNKNOWN'}")
    if "COMPUTED" in flow:
        raise ValueError("indirect or unresolved call is not supported")

    operands = instruction.get("operands", [])
    if len(operands) != 1:
        raise ValueError("direct CALL requires exactly one immediate target")
    operand = operands[0].strip()
    if REGISTER.fullmatch(operand) or "[" in operand or not ADDRESS.fullmatch(operand):
        raise ValueError("indirect or unresolved call is not supported")
    target = parse_address(operand)

    references = [
        reference for reference in instruction.get("references", [])
        if reference.get("is_call") and reference.get("to")
    ]
    if len(references) != 1:
        raise ValueError(
            f"direct CALL has {len(references)} resolved call references; exactly one is required"
        )
    reference_target = parse_address(references[0]["to"])
    if reference_target != target:
        raise ValueError(
            f"CALL operand target 0x{target:08x} differs from exported reference "
            f"0x{reference_target:08x}"
        )
    flow_targets = instruction.get("flows_to", [])
    if flow_targets:
        if len(flow_targets) != 1 or parse_address(flow_targets[0]) != target:
            raise ValueError("CALL flow target differs from its immediate operand")
    return target


def direct_tail_jump_target(instruction):
    if (str(instruction.get("mnemonic", "")).upper() != "JMP"
            or str(instruction.get("flow", "")).upper() != "CALL_TERMINATOR"):
        raise ValueError("not a direct tail jump")
    operands = instruction.get("operands", [])
    flows = instruction.get("flows_to", [])
    if len(operands) != 1 or len(flows) != 1:
        raise ValueError("tail jump requires one operand and one flow target")
    operand = str(operands[0]).strip()
    if not ADDRESS.fullmatch(operand):
        raise ValueError("tail jump target is not an immediate address")
    target = parse_address(operand)
    if parse_address(flows[0]) != target:
        raise ValueError("tail jump flow differs from its immediate operand")
    references = [
        parse_address(reference["to"])
        for reference in instruction.get("references", [])
        if reference.get("is_call") and reference.get("to")
    ]
    if len(references) != 1 or references[0] != target:
        raise ValueError("tail jump reference differs from its immediate operand")
    return target


def indirect_iat_import(instruction, iat_imports):
    if not iat_imports:
        return None
    for operand in instruction.get("operands", []):
        match = re.fullmatch(
            r"(?:(?:byte|word|dword) ptr )?\[\s*(0x[0-9a-f]+|[0-9]+)\s*\]",
            str(operand).strip(),
            re.IGNORECASE,
        )
        if match is None:
            continue
        token = match.group(1)
        address = int(token, 16 if token.lower().startswith("0x") else 10)
        symbol = iat_imports.get(address)
        if symbol is not None:
            return {"iat_address": address, "symbol": symbol}
    return None


def out_of_body_jump_target(instruction, addresses):
    """The target of a JMP that leaves its own body, which is a tail call.

    Ghidra marks most tail calls as CALL_TERMINATOR, but a one-instruction
    ``JMP thunk`` sometimes reaches the same shape without that label, and a
    jump whose target is not an instruction of this body can only be a tail
    call.
    """

    if str(instruction.get("mnemonic", "")).upper() != "JMP":
        return None
    operands = instruction.get("operands", [])
    flows = instruction.get("flows_to", [])
    if len(operands) != 1 or len(flows) != 1:
        return None
    if not ADDRESS.fullmatch(str(operands[0]).strip()):
        return None
    target = parse_address(flows[0])
    if target in addresses:
        return None
    if parse_address(str(operands[0]).strip()) != target:
        return None
    return target


def function_call_targets(function, iat_imports=None):
    addresses = {
        parse_address(instruction["address"])
        for instruction in function.get("instructions", [])
    }
    targets = []
    for instruction in function.get("instructions", []):
        mnemonic = str(instruction.get("mnemonic", "")).upper()
        flow = str(instruction.get("flow", "")).upper()
        if mnemonic == "JMP" and flow == "CALL_TERMINATOR":
            targets.append(direct_tail_jump_target(instruction))
            continue
        if mnemonic == "JMP":
            tail = out_of_body_jump_target(instruction, addresses)
            if tail is not None:
                targets.append(tail)
                continue
        if mnemonic in {"CALL", "CALLF"} or flow in {
            "UNCONDITIONAL_CALL", "CONDITIONAL_CALL", "COMPUTED_CALL"
        }:
            try:
                targets.append(direct_call_target(instruction))
            except ValueError:
                if indirect_iat_import(instruction, iat_imports) is None:
                    raise
    return targets


def translate_instruction(
    instruction, index, addresses, next_address, exported_function_entries=None,
    iat_imports=None, direct_import_aliases=None, allow_unresolved_calls=False,
):
    mnemonic = instruction["mnemonic"].upper()
    operands_text = instruction.get("operands", [])
    flow = str(instruction.get("flow", "")).upper()
    # Ghidra renders "LOCK XADD" as XADD.LOCK. The guest runs one thread, so the
    # lock prefix is a no-op for atomicity and the base instruction carries the
    # behaviour.
    if mnemonic.endswith(".LOCK"):
        mnemonic = mnemonic[: -len(".LOCK")]

    if mnemonic in {"CALL", "CALLF"} or flow in {
        "UNCONDITIONAL_CALL", "CONDITIONAL_CALL", "COMPUTED_CALL"
    }:
        if next_address is None or next_address not in addresses:
            raise ValueError("CALL return address is not an exported instruction")
        alias = (direct_import_aliases or {}).get(
            parse_address(instruction["address"]))
        if alias is not None:
            target = direct_call_target(instruction)
            expected_target, symbol, iat_address = alias
            if target != expected_target:
                raise ValueError(
                    f"direct import alias target 0x{expected_target:08x} "
                    f"differs from CALL target 0x{target:08x}")
            return [
                f"t{index}_call_status = batch_guest_import_call32("
                f"memory, state, \"{symbol}\", "
                f"0x{iat_address:08x}u, 0x{next_address:08x}u);",
                f"if (t{index}_call_status != BatchLiftStatus::returned) "
                f"return t{index}_call_status;",
                f"if (state.eip != 0x{next_address:08x}u) "
                "return BatchLiftStatus::invalid_control_flow;",
            ]
        try:
            target = direct_call_target(instruction)
        except ValueError as direct_error:
            imported = indirect_iat_import(instruction, iat_imports)
            if imported is None:
                computed = None
                if len(operands_text) == 1:
                    try:
                        computed = parse_operand(
                            operands_text[0], infer_memory_width=32)
                    except ValueError:
                        computed = None
                if (computed is not None and computed[0] == "register"
                        and computed[2] == 32):
                    # CALL r32: the callee is only known at runtime, so the
                    # dispatcher resolves it against the lifted bodies.
                    return [
                        f"t{index}_call_status = state.imports == nullptr "
                        "? BatchLiftStatus::unsupported_import "
                        ": state.imports->invoke_guest_call(memory, state, "
                        f"state.regs[{computed[1]}], 0x{next_address:08x}u);",
                        f"if (t{index}_call_status != BatchLiftStatus::returned) "
                        f"return t{index}_call_status;",
                    ]
                if (computed is not None
                        and computed[0] in {
                            "memory", "indexed_memory", "absolute_memory",
                        } and operand_width(computed) == 32):
                    # CALL [mem]: a function pointer read at runtime. The
                    # pointer itself is loaded from guest memory and the
                    # dispatcher still requires a lifted body for the target.
                    return [
                        f"if (!memory.load32({memory_address(computed)}, "
                        f"t{index}t)) return BatchLiftStatus::invalid_memory;",
                        f"t{index}_call_status = state.imports == nullptr "
                        "? BatchLiftStatus::unsupported_import "
                        ": state.imports->invoke_guest_call(memory, state, "
                        f"t{index}t, 0x{next_address:08x}u);",
                        f"if (t{index}_call_status != BatchLiftStatus::returned) "
                        f"return t{index}_call_status;",
                    ]
                raise direct_error
            return [
                f"t{index}_call_status = batch_guest_import_call32("
                f"memory, state, \"{imported['symbol']}\", "
                f"0x{imported['iat_address']:08x}u, 0x{next_address:08x}u);",
                f"if (t{index}_call_status != BatchLiftStatus::returned) "
                f"return t{index}_call_status;",
                f"if (state.eip != 0x{next_address:08x}u) "
                "return BatchLiftStatus::invalid_control_flow;",
            ]
        if exported_function_entries is None or target not in exported_function_entries:
            if not allow_unresolved_calls:
                raise ValueError(
                    f"direct call target 0x{target:08x} is not in the exported function set"
                )
            # The callee exists in the image but this batch does not lift it, so
            # the call goes through the dispatcher. A target without a body
            # fails closed there and names itself, which is the batch boundary.
            return [
                f"t{index}_call_status = state.imports == nullptr "
                "? BatchLiftStatus::unsupported_import "
                ": state.imports->invoke_guest_call(memory, state, "
                f"0x{target:08x}u, 0x{next_address:08x}u);",
                f"if (t{index}_call_status != BatchLiftStatus::returned) "
                f"return t{index}_call_status;",
                f"if (state.eip != 0x{next_address:08x}u) "
                "return BatchLiftStatus::invalid_control_flow;",
            ]
        return [
            f"if (!batch_guest_call32(memory, state, 0x{target:08x}u, "
            f"0x{next_address:08x}u)) return BatchLiftStatus::invalid_memory;",
            f"t{index}_call_status = spore_lift_{target:08x}(memory, state);",
            f"if (t{index}_call_status != BatchLiftStatus::returned) "
            f"return t{index}_call_status;",
            f"if (state.eip != 0x{next_address:08x}u) "
            "return BatchLiftStatus::invalid_control_flow;",
        ]
    if "JUMP" in flow and mnemonic not in {"JMP", *SUPPORTED_CONDITIONS}:
        raise ValueError(f"unsupported jump instruction {mnemonic}")
    if mnemonic == "MOVSS":
        if len(operands_text) != 2:
            raise ValueError(
                f"MOVSS expects 2 operands; found {len(operands_text)}"
            )
        destination = parse_movss_operand(operands_text[0])
        source = parse_movss_operand(operands_text[1])
        if destination[0] == "xmm":
            if source[0] == "xmm":
                return [
                    "if (!batch_guest_movss_register_move("
                    f"state, {destination[1]}u, {source[1]}u)) "
                    "return BatchLiftStatus::invalid_control_flow;"
                ]
            if source[0] in MEMORY_OPERAND_KINDS and operand_width(source) == 32:
                return [
                    "if (!batch_guest_movss_load("
                    f"memory, state, {destination[1]}u, "
                    f"{memory_address(source)})) "
                    "return BatchLiftStatus::invalid_memory;"
                ]
            raise ValueError(
                "MOVSS XMM destination requires an XMM register or 32-bit memory source"
            )
        if (destination[0] in MEMORY_OPERAND_KINDS
                and operand_width(destination) == 32
                and source[0] == "xmm"):
            return [
                "if (!batch_guest_movss_store("
                f"memory, state, {source[1]}u, "
                f"{memory_address(destination)})) "
                "return BatchLiftStatus::invalid_memory;"
            ]
        raise ValueError(
            "MOVSS destination must be an XMM register or 32-bit memory operand"
        )
    if mnemonic in {"MOVAPS", "MOVAPD"}:
        if len(operands_text) != 2:
            raise ValueError(
                f"{mnemonic} expects 2 operands; found {len(operands_text)}"
            )
        destination = XMM_REGISTER.fullmatch(operands_text[0].strip())
        source = XMM_REGISTER.fullmatch(operands_text[1].strip())
        if destination is None or source is None:
            raise ValueError(
                f"{mnemonic} currently requires two XMM register operands")
        helper = "batch_guest_movaps" if mnemonic == "MOVAPS" else "batch_guest_movapd"
        return [
            f"if (!{helper}("
            f"state, {int(destination.group(1))}u, "
            f"{int(source.group(1))}u)) "
            "return BatchLiftStatus::invalid_control_flow;"
        ]
    if mnemonic in {"PUSHFD", "POPFD"}:
        if operands_text:
            raise ValueError(
                f"{mnemonic} expects no operands; found {len(operands_text)}")
        helper = ("batch_guest_pushfd" if mnemonic == "PUSHFD"
                  else "batch_guest_popfd")
        return [
            f"if (!{helper}(memory, state)) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic == "CPUID":
        if operands_text:
            raise ValueError(
                f"CPUID expects no operands; found {len(operands_text)}")
        return [
            f"t{index}_cpuid_status = batch_guest_cpuid(state);",
            f"if (t{index}_cpuid_status != BatchLiftStatus::returned) "
            f"return t{index}_cpuid_status;",
        ]
    if mnemonic == "XORPS":
        if len(operands_text) != 2:
            raise ValueError(
                f"XORPS expects 2 operands; found {len(operands_text)}"
            )
        destination = XMM_REGISTER.fullmatch(operands_text[0].strip())
        source = XMM_REGISTER.fullmatch(operands_text[1].strip())
        if destination is None:
            raise ValueError("XORPS destination must be an XMM register")
        if source is not None:
            return [
                "if (!batch_guest_xorps("
                f"state, {int(destination.group(1))}u, "
                f"{int(source.group(1))}u)) "
                "return BatchLiftStatus::invalid_control_flow;"
            ]
        memory = parse_operand(operands_text[1], 128)
        if (memory[0] not in MEMORY_OPERAND_KINDS
                or operand_width(memory) != 128):
            raise ValueError(
                "XORPS source must be an XMM register or a 128-bit memory "
                "operand")
        return [
            "if (!batch_guest_xorps_memory("
            f"memory, state, {int(destination.group(1))}u, "
            f"{memory_address(memory)})) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic == "XCHG":
        if len(operands_text) != 2:
            raise ValueError(
            f"XCHG expects 2 operands; found {len(operands_text)}"
            )
        operands = [
            parse_operand(operand, infer_memory_width=32)
            for operand in operands_text
        ]
        memory_operands = [
            operand for operand in operands
            if operand[0] in {"absolute_memory", "memory"}
        ]
        register_operands = [
            operand for operand in operands
            if operand[0] == "register" and operand[2] == 32
        ]
        if (
            len(memory_operands) == 1
            and len(register_operands) == 1
            and memory_operands[0][3] == 32
        ):
            return [
                "if (!batch_guest_xchg32("
                f"memory, state, {register_operands[0][1]}u, "
                f"{memory_address(memory_operands[0])})) "
                "return BatchLiftStatus::invalid_memory;"
            ]
        doubles = [
            operand for operand in operands
            if operand[0] == "register" and operand[2] == 32
        ]
        if len(doubles) == 2:
            # XCHG r32, r32 changes no flags.
            left, right = doubles[0][1], doubles[1][1]
            return [
                f"t{index}c = state.regs[{left}];",
                f"state.regs[{left}] = state.regs[{right}];",
                f"state.regs[{right}] = t{index}c;",
            ]
        raise ValueError(
            "XCHG requires either one 32-bit memory operand with one 32-bit "
            "register or two 32-bit registers"
        )
    if mnemonic in {"FLD", "FLD1", "FLDZ"}:
        if mnemonic != "FLD":
            if operands_text:
                raise ValueError(f"{mnemonic} expects no operands")
            helper = (
                "batch_guest_fld1" if mnemonic == "FLD1"
                else "batch_guest_fldz"
            )
            return [
                f"if (!{helper}(state)) "
                "return BatchLiftStatus::invalid_x87_state;"
            ]
        if len(operands_text) != 1:
            raise ValueError(
                f"FLD expects 1 operand; found {len(operands_text)}")
        text = operands_text[0].strip()
        stack = X87_ST_REGISTER.fullmatch(text)
        if stack is not None:
            return [
                "if (!batch_guest_fld_stack("
                f"state, {int(stack.group(1))}u)) "
                "return BatchLiftStatus::invalid_x87_state;"
            ]
        operand = parse_operand(text)
        if operand[0] not in MEMORY_OPERAND_KINDS:
            raise ValueError("FLD requires a stack register or memory operand")
        helper = {32: "batch_guest_fld32", 64: "batch_guest_fld64"}.get(
            operand_width(operand))
        if helper is None:
            raise ValueError(
                "FLD supports 32- and 64-bit memory operands only")
        return [
            "if (!" + helper + f"(memory, state, {memory_address(operand)})) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic in {"FST", "FSTP"}:
        if len(operands_text) != 1:
            raise ValueError(
                f"{mnemonic} expects 1 operand; found {len(operands_text)}")
        text = operands_text[0].strip()
        stack = X87_ST_REGISTER.fullmatch(text)
        if stack is not None:
            if mnemonic != "FSTP":
                raise ValueError("FST requires a memory operand")
            return [
                "if (!batch_guest_fstp_stack("
                f"state, {int(stack.group(1))}u)) "
                "return BatchLiftStatus::invalid_x87_state;"
            ]
        operand = parse_operand(text)
        if operand[0] not in MEMORY_OPERAND_KINDS:
            raise ValueError(f"{mnemonic} requires a memory operand")
        width = operand_width(operand)
        helpers = (
            {32: "batch_guest_fstp32", 64: "batch_guest_fstp64"}
            if mnemonic == "FSTP" else {32: "batch_guest_fst32"}
        )
        helper = helpers.get(width)
        if helper is None:
            raise ValueError(
                f"{mnemonic} does not support {width}-bit memory operands")
        return [
            "if (!" + helper + f"(memory, state, {memory_address(operand)})) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic in {"FILD", "FISTP"}:
        if len(operands_text) != 1:
            raise ValueError(
                f"{mnemonic} expects 1 operand; found {len(operands_text)}")
        operand = parse_operand(operands_text[0])
        if operand[0] not in MEMORY_OPERAND_KINDS:
            raise ValueError(f"{mnemonic} requires a memory operand")
        width = operand_width(operand)
        helpers = (
            {32: "batch_guest_fild32", 64: "batch_guest_fild64"}
            if mnemonic == "FILD" else {64: "batch_guest_fistp64"}
        )
        helper = helpers.get(width)
        if helper is None:
            raise ValueError(
                f"{mnemonic} does not support {width}-bit memory operands")
        return [
            "if (!" + helper + f"(memory, state, {memory_address(operand)})) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic in X87_ARITHMETIC or mnemonic in X87_ARITHMETIC_POP:
        pop = mnemonic in X87_ARITHMETIC_POP
        operation = X87_ARITHMETIC.get(mnemonic, X87_ARITHMETIC_POP.get(mnemonic))
        if not 0 <= operation <= 5:
            raise ValueError(f"unknown x87 arithmetic operation {mnemonic}")
        if len(operands_text) > 2:
            raise ValueError(f"{mnemonic} expects at most 2 operands")
        if not operands_text:
            if not pop:
                raise ValueError(f"{mnemonic} expects an operand")
            # A bare FADDP and friends are FADDP ST(1), ST(0).
            return [
                "if (!batch_guest_x87_arithmetic_stack("
                f"state, 1u, 0u, {operation}u, true)) "
                "return BatchLiftStatus::invalid_x87_state;"
            ]
        indexes = []
        for text in operands_text:
            stack = X87_ST_REGISTER.fullmatch(text.strip())
            if stack is None:
                indexes = None
                break
            indexes.append(int(stack.group(1)))
        if indexes is not None:
            destination = indexes[0]
            source = indexes[1] if len(indexes) == 2 else 0
            return [
                "if (!batch_guest_x87_arithmetic_stack("
                f"state, {destination}u, {source}u, {operation}u, "
                f"{'true' if pop else 'false'})) "
                "return BatchLiftStatus::invalid_x87_state;"
            ]
        if len(operands_text) != 1:
            raise ValueError(
                f"{mnemonic} takes stack registers or one 32-bit memory operand")
        operand = parse_operand(operands_text[0])
        if (operand[0] not in MEMORY_OPERAND_KINDS
                or operand_width(operand) != 32):
            raise ValueError(
                f"{mnemonic} requires a stack register or 32-bit memory")
        return [
            "if (!batch_guest_x87_float32_arithmetic("
            f"memory, state, {memory_address(operand)}, {operation}u)) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic in {"FCHS", "FABS", "FSQRT"}:
        if operands_text:
            raise ValueError(
                f"{mnemonic} expects no operands; found {len(operands_text)}")
        helper = {
            "FCHS": "batch_guest_x87_chs",
            "FABS": "batch_guest_x87_abs",
            "FSQRT": "batch_guest_x87_sqrt",
        }[mnemonic]
        return [
            f"if (!{helper}(state)) "
            "return BatchLiftStatus::invalid_x87_state;"
        ]
    if mnemonic == "FXCH":
        if len(operands_text) > 1:
            raise ValueError(
                f"FXCH expects at most 1 operand; found {len(operands_text)}")
        if not operands_text:
            index = 1
        else:
            stack = X87_ST_REGISTER.fullmatch(operands_text[0].strip())
            if stack is None:
                raise ValueError("FXCH requires a stack register operand")
            index = int(stack.group(1))
        return [
            f"if (!batch_guest_x87_fxch(state, {index}u)) "
            "return BatchLiftStatus::invalid_x87_state;"
        ]
    if mnemonic == "FNSTSW":
        if len(operands_text) != 1 or operands_text[0].strip().upper() != "AX":
            raise ValueError("FNSTSW is only supported with the AX destination")
        return [
            "if (!batch_guest_fnstsw_ax(state)) "
            "return BatchLiftStatus::invalid_x87_state;"
        ]
    if mnemonic in X87_COMPARE_POPS:
        pops = X87_COMPARE_POPS[mnemonic]
        to_eflags = mnemonic in X87_EFLAGS_COMPARES
        if len(operands_text) > 2:
            raise ValueError(f"{mnemonic} expects at most 2 operands")
        if len(operands_text) == 2:
            left = X87_ST_REGISTER.fullmatch(operands_text[0].strip())
            right = X87_ST_REGISTER.fullmatch(operands_text[1].strip())
            if left is None or right is None or int(left.group(1)) != 0:
                raise ValueError(
                    f"{mnemonic} compares ST(0) with a stack register")
            return [
                "if (!batch_guest_x87_compare_stack("
                f"state, {int(right.group(1))}u, {pops}u, "
                f"{'true' if to_eflags else 'false'})) "
                "return BatchLiftStatus::invalid_x87_state;"
            ]
        if not operands_text:
            if pops == 0:
                raise ValueError(f"{mnemonic} expects an operand")
            # A bare FCOMP is FCOMP ST(1); the compare-and-pop-pair forms
            # always compare ST(0) with ST(1).
            return [
                "if (!batch_guest_x87_compare_stack("
                f"state, 1u, {pops}u, "
                f"{'true' if to_eflags else 'false'})) "
                "return BatchLiftStatus::invalid_x87_state;"
            ]
        text = operands_text[0].strip()
        stack = X87_ST_REGISTER.fullmatch(text)
        if stack is not None:
            return [
                "if (!batch_guest_x87_compare_stack("
                f"state, {int(stack.group(1))}u, {pops}u, "
                f"{'true' if to_eflags else 'false'})) "
                "return BatchLiftStatus::invalid_x87_state;"
            ]
        operand = parse_operand(text)
        if (operand[0] not in MEMORY_OPERAND_KINDS
                or operand_width(operand) != 32):
            raise ValueError(
                f"{mnemonic} requires a stack register or 32-bit memory")
        return [
            "if (!batch_guest_x87_compare_memory("
            f"memory, state, {memory_address(operand)}, {pops}u, "
            f"{'true' if to_eflags else 'false'})) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic == "CVTTSS2SI":
        if len(operands_text) != 2:
            raise ValueError("CVTTSS2SI expects two operands")
        destination = REGISTER.fullmatch(operands_text[0].strip())
        if destination is None:
            raise ValueError("CVTTSS2SI destination must be a 32-bit register")
        dst = REGISTER_INDEX[destination.group(0).upper()]
        source = operands_text[1].strip()
        register = XMM_REGISTER.fullmatch(source)
        if register is not None:
            return [
                "if (!batch_guest_cvttss2si("
                f"state, {dst}u, {int(register.group(1))}u)) "
                "return BatchLiftStatus::invalid_control_flow;"
            ]
        operand = parse_operand(source, 32)
        if (operand[0] not in MEMORY_OPERAND_KINDS
                or operand_width(operand) != 32):
            raise ValueError(
                "CVTTSS2SI requires a 32-bit register and 32-bit memory")
        return [
            "if (!batch_guest_cvttss2si_memory("
            f"memory, state, {dst}u, {memory_address(operand)})) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic in {"CVTSS2SI", "CVTSI2SS"}:
        if len(operands_text) != 2:
            raise ValueError(f"{mnemonic} expects two operands")
        destination = operands_text[0].strip()
        source = operands_text[1].strip()
        if mnemonic == "CVTSS2SI":
            register = REGISTER.fullmatch(destination)
            xmm = XMM_REGISTER.fullmatch(source)
            if register is None or xmm is None:
                raise ValueError(
                    "CVTSS2SI requires a 32-bit register and XMM register")
            return [
                "if (!batch_guest_cvtss2si("
                f"state, {REGISTER_INDEX[register.group(0).upper()]}u, "
                f"{int(xmm.group(1))}u)) "
                "return BatchLiftStatus::invalid_control_flow;"
            ]
        xmm = XMM_REGISTER.fullmatch(destination)
        if xmm is None:
            raise ValueError("CVTSI2SS destination must be an XMM register")
        register = REGISTER.fullmatch(source)
        if register is not None:
            return [
                "if (!batch_guest_cvtsi2ss("
                f"state, {int(xmm.group(1))}u, "
                f"{REGISTER_INDEX[register.group(0).upper()]}u)) "
                "return BatchLiftStatus::invalid_control_flow;"
            ]
        operand = parse_operand(source, 32)
        if (operand[0] not in MEMORY_OPERAND_KINDS
                or operand_width(operand) != 32):
            raise ValueError(
                "CVTSI2SS requires a 32-bit register or 32-bit memory source")
        return [
            "if (!batch_guest_cvtsi2ss_memory("
            f"memory, state, {int(xmm.group(1))}u, {memory_address(operand)})) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic in {"COMISS", "UCOMISS"}:
        if len(operands_text) != 2:
            raise ValueError(f"{mnemonic} expects two operands")
        left = XMM_REGISTER.fullmatch(operands_text[0].strip())
        if left is None:
            raise ValueError(
                f"{mnemonic} requires an XMM register destination")
        right = XMM_REGISTER.fullmatch(operands_text[1].strip())
        if right is not None:
            return [
                "if (!batch_guest_ucomiss("
                f"state, {int(left.group(1))}u, {int(right.group(1))}u)) "
                "return BatchLiftStatus::invalid_control_flow;"
            ]
        memory = parse_operand(operands_text[1], 32)
        if (memory[0] not in MEMORY_OPERAND_KINDS
                or operand_width(memory) != 32):
            raise ValueError(
                f"{mnemonic} source must be an XMM register or a 32-bit "
                "memory operand")
        return [
            "if (!batch_guest_ucomiss_memory("
            f"memory, state, {int(left.group(1))}u, "
            f"{memory_address(memory)})) "
            "return BatchLiftStatus::invalid_memory;"
        ]
    if mnemonic in {"ADDSS", "SUBSS", "MULSS", "DIVSS"}:
        if len(operands_text) != 2:
            raise ValueError(f"{mnemonic} expects two operands")
        destination = XMM_REGISTER.fullmatch(operands_text[0].strip())
        if destination is None:
            raise ValueError(
                f"{mnemonic} destination must be an XMM register")
        operation = {"ADDSS": 0, "SUBSS": 1, "MULSS": 2, "DIVSS": 3}[mnemonic]
        right = XMM_REGISTER.fullmatch(operands_text[1].strip())
        if right is not None:
            source_bits = f"state.xmm[{int(right.group(1))}u][0]"
            prefix = []
        else:
            memory = parse_operand(operands_text[1], 32)
            if (memory[0] not in MEMORY_OPERAND_KINDS
                    or operand_width(memory) != 32):
                raise ValueError(
                    f"{mnemonic} source must be an XMM register or a 32-bit "
                    "memory operand")
            prefix = [
                f"if (!memory.load32({memory_address(memory)}, t{index}a)) "
                "return BatchLiftStatus::invalid_memory;"
            ]
            source_bits = f"t{index}a"
        return prefix + [
            "if (!batch_guest_sse_scalar_arithmetic("
            f"state, {int(destination.group(1))}u, {source_bits}, "
            f"{operation}u)) "
            "return BatchLiftStatus::invalid_control_flow;"
        ]
    if mnemonic == "LAHF":
        if operands_text:
            raise ValueError(
                f"LAHF expects no operands; found {len(operands_text)}")
        return [
            "if (!batch_guest_lahf(state)) "
            "return BatchLiftStatus::invalid_control_flow;"
        ]

    set_condition = None
    if mnemonic.startswith("SET") and len(mnemonic) > 3:
        set_condition = "J" + mnemonic[3:]
        if set_condition not in SUPPORTED_CONDITIONS:
            raise ValueError(f"unsupported condition-code instruction {mnemonic}")
    operands = (
        [parse_operand(value, 8) for value in operands_text]
        if set_condition is not None
        else resolve_operands(
            operands_text,
            infer_untyped_memory=mnemonic not in {"MOVZX", "MOVSX"},
        )
    )
    if mnemonic not in {
        "MOV", "LEA", "CMP", "OR", "TEST", "JMP", "MOVZX", "MOVSX",
    } and any(
        operand[0] == "indexed_memory" for operand in operands
    ):
        raise ValueError("indexed memory operands currently support MOV only")
    temp = f"t{index}"
    lines = []

    def require(count):
        if len(operands) != count:
            raise ValueError(f"{mnemonic} expects {count} operands; found {len(operands)}")

    if mnemonic == "NOP":
        require(0)
    elif mnemonic == "INT3":
        require(0)
        # The guest has no debugger to receive the break, so it stops here.
        lines.append("return BatchLiftStatus::debug_trap;")
    elif mnemonic == "XADD":
        require(2)
        if operands[1][0] != "register" or operand_width(operands[1]) != 32:
            raise ValueError("XADD requires a 32-bit register source")
        if operands[0][0] not in {
            "register", "memory", "indexed_memory", "absolute_memory",
        } or operand_width(operands[0]) != 32:
            raise ValueError("XADD requires a 32-bit register or memory target")
        lines += emit_load(operands[0], f"{temp}a")
        lines += emit_load(operands[1], f"{temp}b")
        lines += [
            f"{temp}r = static_cast<std::uint32_t>({temp}a + {temp}b) "
            "& 0xffffffffu;",
            f"batch_set_add_flags(state, {temp}a, {temp}b, {temp}r, 32u);",
        ]
        lines += emit_store(operands[0], f"{temp}r")
        lines += emit_store(operands[1], f"{temp}a")
    elif mnemonic == "CMOVC":
        require(2)
        if any(operand[0] != "register" or operand_width(operand) != 32
               for operand in operands):
            raise ValueError("CMOVC requires two 32-bit registers")
        lines.append(
            f"if ((state.eflags & 0x001u) != 0u) state.regs[{operands[0][1]}] = state.regs[{operands[1][1]}];"
        )
    elif set_condition is not None:
        require(1)
        if operand_width(operands[0]) != 8:
            raise ValueError(f"{mnemonic} destination must be an 8-bit register or memory operand")
        lines += emit_store(operands[0], f"({SUPPORTED_CONDITIONS[set_condition]} ? 1u : 0u)")
    elif mnemonic == "MOV":
        require(2)
        if any(
            operand_width(operand) not in {None, 8, 16, 32}
            for operand in operands
        ):
            raise ValueError("MOV supports only 8-, 16-, or 32-bit operands")
        if operands[0][0] in {"immediate"} or (
            operands[0][0] in {
                "absolute_memory", "memory", "fs_memory", "indexed_memory",
            } and operands[1][0] in {
                "absolute_memory", "memory", "fs_memory", "indexed_memory",
            }
        ):
            raise ValueError("MOV destination/source operand combination is invalid")
        destination_width = operand_width(operands[0])
        source_width = operand_width(operands[1])
        if destination_width and source_width and destination_width != source_width:
            raise ValueError("MOV operand widths differ")
        if operands[1][0] == "immediate" and destination_width:
            if operands[1][1] > width_mask(destination_width):
                raise ValueError("MOV immediate does not fit the destination width")
        lines += emit_load(operands[1], temp)
        lines += emit_store(operands[0], temp)
    elif mnemonic == "LEA":
        require(2)
        if operands[0][0] != "register" or operand_width(operands[0]) != 32:
            raise ValueError("LEA requires a 32-bit register destination")
        if operands[1][0] not in {"memory", "indexed_memory"}:
            raise ValueError("LEA source must be a supported effective address")
        lines.append(f"{temp} = {memory_address(operands[1])};")
        lines += emit_store(operands[0], temp)
    elif mnemonic == "NOT":
        require(1)
        if operands[0][0] not in {"register", "memory", "absolute_memory", "fs_memory"}:
            raise ValueError("NOT requires a register or memory destination")
        width = operand_width(operands[0])
        if width not in {8, 16, 32}:
            raise ValueError("NOT requires an 8-, 16-, or 32-bit destination")
        lines += emit_load(operands[0], f"{temp}a")
        lines += emit_store(operands[0], f"(~{temp}a & {cpp_u32(width_mask(width))})")
    elif mnemonic in {"MOVZX", "MOVSX"}:
        require(2)
        destination_width = operand_width(operands[0])
        source_width = operand_width(operands[1])
        if operands[0][0] != "register" or not source_width:
            raise ValueError(f"{mnemonic} requires a register destination and sized source")
        if destination_width <= source_width:
            raise ValueError(f"{mnemonic} destination must be wider than its source")
        lines += emit_load(operands[1], f"{temp}a")
        if mnemonic == "MOVSX":
            sign = 1 << (source_width - 1)
            lines.append(
                f"{temp}a = static_cast<std::uint32_t>("
                f"({temp}a ^ {cpp_u32(sign)}) - {cpp_u32(sign)});"
            )
        lines += emit_store(operands[0], f"{temp}a")
    elif mnemonic == "DIV":
        require(1)
        if operands[0][0] != "register" or operand_width(operands[0]) != 32:
            raise ValueError("DIV currently requires a 32-bit register divisor")
        lines += emit_load(operands[0], f"{temp}a")
        lines += [
            f"if ({temp}a == 0u) return BatchLiftStatus::divide_error;",
            "{",
            f"const std::uint64_t dividend = (static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0];",
            f"const std::uint64_t quotient = dividend / {temp}a;",
            "if (quotient > 0xffffffffull) return BatchLiftStatus::divide_error;",
            "state.regs[0] = static_cast<std::uint32_t>(quotient);",
            f"state.regs[2] = static_cast<std::uint32_t>(dividend % {temp}a);",
            "}",
        ]
    elif mnemonic == "IMUL":
        if len(operands) == 1:
            # IMUL r/m32: the implicit form writes EDX:EAX.
            if operand_width(operands[0]) != 32:
                raise ValueError("IMUL requires a 32-bit operand")
            lines += emit_load(operands[0], f"{temp}a")
            lines += [
                "{",
                "const std::int64_t product = "
                "static_cast<std::int64_t>("
                "static_cast<std::int32_t>(state.regs[0])) * "
                f"static_cast<std::int32_t>({temp}a);",
                "state.regs[0] = static_cast<std::uint32_t>(product);",
                "state.regs[2] = static_cast<std::uint32_t>("
                "static_cast<std::uint64_t>(product) >> 32u);",
                "state.eflags &= ~0x801u;",
                "if (product < -2147483648ll || product > 2147483647ll) "
                "state.eflags |= 0x801u;",
                "}",
            ]
        else:
            if len(operands) not in {2, 3}:
                raise ValueError(
                    f"IMUL expects 1, 2 or 3 operands; found {len(operands)}")
            if operands[0][0] != "register" or operand_width(operands[0]) != 32:
                raise ValueError("IMUL requires a 32-bit register destination")
            if len(operands) == 3:
                multiplicand, multiplier = operands[1], operands[2]
                if multiplier[0] != "immediate":
                    raise ValueError(
                        "IMUL with three operands requires an immediate "
                        "multiplier")
            else:
                multiplicand, multiplier = operands[0], operands[1]
            if operand_width(multiplicand) != 32:
                raise ValueError("IMUL requires a 32-bit source")
            lines += emit_load(multiplicand, f"{temp}a")
            if multiplier[0] == "immediate":
                lines.append(f"{temp}b = {cpp_u32(multiplier[1])};")
            else:
                if operand_width(multiplier) != 32:
                    raise ValueError("IMUL requires a 32-bit multiplier")
                lines += emit_load(multiplier, f"{temp}b")
            lines += [
                "{",
                "const std::int64_t product = "
                f"static_cast<std::int64_t>(static_cast<std::int32_t>({temp}a)) "
                f"* static_cast<std::int32_t>({temp}b);",
                f"state.regs[{operands[0][1]}] = "
                "static_cast<std::uint32_t>(product);",
                "state.eflags &= ~0x801u;",
                "if (product < -2147483648ll || product > 2147483647ll) "
                "state.eflags |= 0x801u;",
                "}",
            ]
    elif mnemonic.startswith("CMOV"):
        require(2)
        condition = SUPPORTED_CONDITIONS.get("J" + mnemonic[len("CMOV"):])
        if condition is None:
            raise ValueError(f"{mnemonic} condition is not modelled")
        if operands[0][0] != "register" or operand_width(operands[0]) != 32:
            raise ValueError("CMOV requires a 32-bit register destination")
        if operand_width(operands[1]) != 32:
            raise ValueError("CMOV requires a 32-bit source")
        lines += emit_load(operands[1], f"{temp}a")
        # A conditional move loads only when the condition holds; no flags change.
        lines.append(
            f"if ({condition}) state.regs[{operands[0][1]}] = {temp}a;")
    elif mnemonic == "IDIV":
        require(1)
        if operand_width(operands[0]) != 32:
            raise ValueError("IDIV requires a 32-bit divisor")
        lines += emit_load(operands[0], f"{temp}a")
        lines += [
            f"if ({temp}a == 0u) return BatchLiftStatus::divide_error;",
            "{",
            f"const std::int64_t divisor = static_cast<std::int64_t>("
            f"static_cast<std::int32_t>({temp}a));",
            "const std::int64_t dividend = static_cast<std::int64_t>("
            "(static_cast<std::uint64_t>(state.regs[2]) << 32u) "
            "| state.regs[0]);",
            "const std::int64_t quotient = dividend / divisor;",
            "const std::int64_t remainder = dividend % divisor;",
            "if (quotient < -2147483648ll || quotient > 2147483647ll) "
            "return BatchLiftStatus::divide_error;",
            "state.regs[0] = static_cast<std::uint32_t>(quotient);",
            "state.regs[2] = static_cast<std::uint32_t>(remainder);",
            "}",
        ]
    elif mnemonic == "CDQ":
        require(0)
        # Sign-extend EAX into EDX:EAX. No flags change.
        lines.append(
            "state.regs[2] = (state.regs[0] & 0x80000000u) != 0u "
            "? 0xffffffffu : 0u;")
    elif mnemonic in {"SHL", "SHR", "SAR"}:
        require(2)
        if operands[0][0] != "register" or operand_width(operands[0]) != 32:
            raise ValueError(
                f"{mnemonic} currently requires a 32-bit register destination")
        if operands[1][0] == "immediate" and 0 <= operands[1][1] <= 31:
            count_expression = f"{operands[1][1]}u"
            constant_count = operands[1][1]
        elif operands[1][0] == "register" and operands[1][1] == 1:
            # CL carries the count and x86 masks it to five bits.
            count_expression = "(state.regs[1] & 0x1fu)"
            constant_count = None
        else:
            raise ValueError(
                f"{mnemonic} requires an immediate count 0 through 31 or CL")
        # A zero immediate count changes neither the destination nor the flags.
        if constant_count != 0:
            lines += emit_load(operands[0], f"{temp}a")
            lines += [f"{temp}c = {count_expression};", f"if ({temp}c != 0u) {{"]
            if mnemonic == "SHL":
                lines += [
                    f"{temp}r = static_cast<std::uint32_t>({temp}a << {temp}c) "
                    "& 0xffffffffu;",
                    f"batch_set_shl_flags(state, {temp}a, {temp}c, {temp}r, 32u);",
                ]
            elif mnemonic == "SHR":
                lines += [
                    f"{temp}r = static_cast<std::uint32_t>({temp}a >> {temp}c);",
                    f"batch_set_shr_flags(state, {temp}a, {temp}c, {temp}r, 32u);",
                ]
            else:
                lines += [
                    f"{temp}r = ({temp}a >> {temp}c) | "
                    f"(({temp}a & 0x80000000u) ? "
                    f"(0xffffffffu << (32u - {temp}c)) : 0u);",
                    f"batch_set_sar_flags(state, {temp}a, {temp}c, {temp}r, 32u);",
                ]
            lines += [
                f"    {line}" for line in emit_store(operands[0], f"{temp}r")
            ]
            lines.append("}")
    elif mnemonic == "LEAVE":
        require(0)
        lines += [
            "state.regs[4] = state.regs[5];",
            f"if (!memory.load32(state.regs[4], {temp})) "
            "return BatchLiftStatus::invalid_memory;",
            f"state.regs[5] = {temp};",
            "state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);",
        ]
    elif mnemonic in {"ADD", "SUB", "SBB", "CMP", "TEST", "AND", "OR", "XOR", "INC", "DEC", "NEG"}:
        if mnemonic in {"INC", "DEC", "NEG"}:
            require(1)
        else:
            require(2)
        if operands[0][0] == "immediate":
            raise ValueError(f"{mnemonic} destination cannot be immediate")
        if len(operands) == 2 and operands[0][0] in {
            "memory", "fs_memory", "indexed_memory", "absolute_memory",
        } and operands[1][0] in {
            "memory", "fs_memory", "indexed_memory", "absolute_memory",
        }:
            raise ValueError(f"{mnemonic} cannot use two memory operands")
        op_width = operand_width(operands[0])
        if op_width not in {8, 16, 32}:
            raise ValueError(f"{mnemonic} destination width is unsupported")
        if len(operands) == 2:
            source_width = operand_width(operands[1])
            if source_width and source_width != op_width:
                raise ValueError(f"{mnemonic} operand widths differ")
            if operands[1][0] == "immediate":
                value = operands[1][1]
                unsigned_fit = value <= width_mask(op_width)
                signed_fit = (
                    value >= (1 << 32) - (1 << (op_width - 1))
                    and (value & width_mask(op_width)) & (1 << (op_width - 1))
                )
                if not unsigned_fit and not signed_fit:
                    raise ValueError(f"{mnemonic} immediate does not fit the operand width")
        lines += emit_load(operands[0], f"{temp}a")
        if len(operands) == 2:
            lines += emit_load(operands[1], f"{temp}b")
        mask = cpp_u32(width_mask(op_width))
        if mnemonic in {"INC", "DEC", "NEG"}:
            operation = "+" if mnemonic == "INC" else "-"
            right = "1u" if mnemonic in {"INC", "DEC"} else f"{temp}a"
            left = "0u" if mnemonic == "NEG" else f"{temp}a"
            lines.append(
                f"{temp}r = static_cast<std::uint32_t>({left} {operation} {right}) & {mask};"
            )
            flag_function = {
                "INC": "batch_set_inc_flags",
                "DEC": "batch_set_dec_flags",
                "NEG": "batch_set_neg_flags",
            }[mnemonic]
            lines.append(f"{flag_function}(state, {temp}a, {temp}r, {op_width}u);")
            lines += emit_store(operands[0], f"{temp}r")
        elif mnemonic in {"ADD", "SUB", "SBB", "CMP"}:
            if mnemonic == "SBB":
                lines.append(
                    f"{temp}c = (state.eflags & 0x001u) != 0u ? 1u : 0u;"
                )
                lines.append(
                    f"{temp}r = static_cast<std::uint32_t>("
                    f"{temp}a - {temp}b - {temp}c) & {mask};"
                )
                lines.append(
                    f"batch_set_sbb_flags(state, {temp}a, {temp}b, "
                    f"{temp}c, {temp}r, {op_width}u);"
                )
                lines += emit_store(operands[0], f"{temp}r")
                operation = None
            else:
                operation = "+" if mnemonic == "ADD" else "-"
            if operation is None:
                pass
            else:
                lines += [
                    f"{temp}r = static_cast<std::uint32_t>({temp}a {operation} {temp}b) & {mask};",
                    f"batch_set_{'add' if mnemonic == 'ADD' else 'sub'}_flags("
                    f"state, {temp}a, {temp}b, {temp}r, {op_width}u);",
                ]
                if mnemonic != "CMP":
                    lines += emit_store(operands[0], f"{temp}r")
        else:
            operator = {
                "TEST": "&",
                "AND": "&",
                "OR": "|",
                "XOR": "^",
            }[mnemonic]
            lines.append(f"{temp}r = ({temp}a {operator} {temp}b) & {mask};")
            lines.append(f"batch_set_logic_flags(state, {temp}r, {op_width}u);")
            if mnemonic != "TEST":
                lines += emit_store(operands[0], f"{temp}r")
    elif mnemonic == "PUSH":
        require(1)
        if operand_width(operands[0]) not in {None, 32}:
            raise ValueError("PUSH currently supports only 32-bit operands")
        lines += emit_load(operands[0], f"{temp}a")
        lines += [
            "state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);",
            f"if (!memory.store32(state.regs[4], {temp}a)) "
            "return BatchLiftStatus::invalid_memory;",
        ]
    elif mnemonic == "POP":
        require(1)
        if operands[0][0] == "immediate":
            raise ValueError("POP destination cannot be immediate")
        if operand_width(operands[0]) not in {None, 32}:
            raise ValueError("POP currently supports only 32-bit operands")
        lines += [
            f"if (!memory.load32(state.regs[4], {temp}a)) "
            "return BatchLiftStatus::invalid_memory;",
            "state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);",
        ]
        lines += emit_store(operands[0], f"{temp}a")
    elif mnemonic == "JMP":
        require(1)
        if operands[0][0] != "immediate":
            if operands[0][0] not in {
                "absolute_memory", "memory", "indexed_memory",
            } or operand_width(operands[0]) != 32:
                raise ValueError("indirect JMP is not supported")
            # A jump table: the slot is read at runtime and dispatched to the
            # case bodies the provider resolved. An address outside them fails
            # closed instead of jumping somewhere unknown.
            imported = indirect_iat_import(instruction, iat_imports)
            if imported is not None:
                # JMP [IAT]: a tail-called import leaves this body's return
                # address on the stack, so the shim returns to our caller.
                return [
                    f"t{index}_call_status = batch_guest_import_tail_call32("
                    f"memory, state, \"{imported['symbol']}\", "
                    f"0x{imported['iat_address']:08x}u);",
                    f"if (t{index}_call_status != BatchLiftStatus::returned) "
                    f"return t{index}_call_status;",
                    "return BatchLiftStatus::returned;",
                ]
            targets = sorted({
                parse_address(target)
                for target in instruction.get("flows_to", [])
            })
            if not targets:
                raise ValueError(
                    "computed jump has no statically resolved targets")
            outside = [target for target in targets if target not in addresses]
            if outside:
                raise ValueError(
                    "computed jump target "
                    f"0x{outside[0]:08x} is not an exported instruction")
            lines += emit_load(operands[0], f"{temp}a")
            lines.append(f"switch ({temp}a) {{")
            for target in targets:
                lines.append(f"case 0x{target:08x}u: goto L_{target:08x};")
            lines += [
                "default:",
                # The guest jumped through a table slot that names nothing this
                # body contains, so the run stops with that address visible.
                f"state.eip = {temp}a;",
                "return BatchLiftStatus::unsupported_dependency;",
                "}",
            ]
        else:
            tail = (direct_tail_jump_target(instruction)
                    if flow == "CALL_TERMINATOR"
                    else out_of_body_jump_target(instruction, addresses))
            if tail is not None:
                if (exported_function_entries is not None
                        and tail in exported_function_entries):
                    lines += [
                        f"state.eip = 0x{tail:08x}u;",
                        f"return spore_lift_{tail:08x}(memory, state);",
                    ]
                elif allow_unresolved_calls:
                    # The target is a body this batch does not lift. A tail jump
                    # pushes no return address, so the callee returns straight to
                    # this body's caller and there is nothing to verify here.
                    lines += [
                        f"state.eip = 0x{tail:08x}u;",
                        "return state.imports == nullptr "
                        "? BatchLiftStatus::unsupported_import "
                        ": state.imports->invoke_guest_tail_call(memory, state, "
                        f"0x{tail:08x}u);",
                    ]
                else:
                    raise ValueError(
                        f"tail jump target 0x{tail:08x} is not in the exported function set"
                    )
            else:
                target = branch_target(instruction, addresses)
                lines.append(f"goto L_{target:08x};")
    elif mnemonic in SUPPORTED_CONDITIONS:
        require(1)
        if operands[0][0] != "immediate":
            raise ValueError(f"indirect {mnemonic} is not supported")
        target = branch_target(instruction, addresses)
        if next_address is None or next_address not in addresses:
            raise ValueError("conditional branch has no exported fallthrough instruction")
        lines.append(
            f"if ({SUPPORTED_CONDITIONS[mnemonic]}) goto L_{target:08x};"
        )
    elif mnemonic in {"RET", "RETN"}:
        if len(operands) > 1 or (operands and operands[0][0] != "immediate"):
            raise ValueError("RET cleanup must be one immediate operand")
        cleanup = operands[0][1] if operands else 0
        if cleanup > 0xFFFF:
            raise ValueError("RET cleanup exceeds the x86 immediate width")
        lines += [
            f"if (!batch_guest_return32(memory, state, {cleanup}u)) "
            "return BatchLiftStatus::invalid_memory;",
            "return BatchLiftStatus::returned;",
        ]
    else:
        raise ValueError(f"unsupported instruction {mnemonic}")

    if mnemonic not in {"RET", "RETN", "JMP"} and mnemonic not in SUPPORTED_CONDITIONS:
        if next_address is None or next_address not in addresses:
            raise ValueError(
                f"{mnemonic} falls through to an address not present in the exported function"
            )
    return lines


def static_source(function, translated, call_targets, terminal_status=None,
                  exit_targets=()):
    entry = parse_address(function["entry"])
    symbol = f"spore_lift_{entry:08x}"
    declarations = [
        f"BatchLiftStatus spore_lift_{target:08x}("
        "BatchLiftMemory& memory, BatchLiftState& state);"
        for target in sorted(set(call_targets))
    ]
    body_lines = []
    branch_targets = {
        parse_address(target)
        for instruction, _ in translated
        if instruction["mnemonic"].upper() == "JMP"
        or instruction["mnemonic"].upper() in SUPPORTED_CONDITIONS
        for target in instruction.get("flows_to", [])
        if ADDRESS.fullmatch(str(target))
    }
    for index, (instruction, instruction_body) in enumerate(translated):
        used_temps = sorted(set(re.findall(
            r"\bt\d+(?:a|b|c|r|t)?\b",
            "\n".join(instruction_body),
        )))
        if used_temps:
            body_lines.append(
                "std::uint32_t " + ", ".join(
                    f"{name} = 0" for name in used_temps
                ) + ";"
            )
        if any(
            f"t{index}_call_status" in line for line in instruction_body
        ):
            body_lines.append(
                f"BatchLiftStatus t{index}_call_status = "
                "BatchLiftStatus::invalid_control_flow;"
            )
        if instruction["mnemonic"].upper() == "CPUID":
            body_lines.append(
                f"BatchLiftStatus t{index}_cpuid_status = "
                "BatchLiftStatus::invalid_control_flow;"
            )
    body_lines.append("")
    for instruction, instruction_body in translated:
        address = parse_address(instruction["address"])
        body_lines.append(
            f"// 0x{address:08x}: {instruction['bytes']} "
            f"{instruction['mnemonic'].upper()}"
        )
        if address in branch_targets:
            body_lines.append(
                f"L_{address:08x}:"
            )
        body_lines.extend(f"    {line}" for line in instruction_body)
    if terminal_status is not None:
        terminal_address, status = terminal_status
        if terminal_address in branch_targets:
            # A branch onto the boundary leaves the prefix with the same
            # terminal status as falling through to it.
            body_lines.append(f"L_{terminal_address:08x}:")
        body_lines += [
            f"state.eip = 0x{terminal_address:08x}u;",
            f"return BatchLiftStatus::{status};",
        ]
    # A branch that leaves the verified prefix forward reports its own exit
    # address instead of pretending the prefix covers it.
    for target in sorted(exit_targets):
        body_lines += [
            f"L_{target:08x}:",
            f"state.eip = 0x{target:08x}u;",
            "return BatchLiftStatus::unsupported_dependency;",
        ]
    return "\n".join([
        '#include "BatchStaticLiftRuntime.hpp"',
        *declarations,
        "",
        "",
        f"BatchLiftStatus {symbol}(BatchLiftMemory& memory, BatchLiftState& state) {{",
        f"    batch_guest_note_body(0x{entry:08x}u);",
        *[f"    {line}" if line else "" for line in body_lines],
        "}",
    ])


def translate_function(
    function, exported_function_entries=None, iat_imports=None,
    stop_call_site=None, stop_call_sites=None, direct_import_aliases=None,
    allow_unresolved_calls=False,
):
    reasons = []
    diagnostics = []
    instructions = function.get("instructions")
    if not isinstance(instructions, list) or not instructions:
        raise LiftRejected(["instruction list is absent or empty"], diagnostics)
    if function.get("instruction_count_exported") != len(instructions):
        reasons.append("instruction count metadata differs from exported instruction records")
    if function.get("instructions_truncated") is not False:
        reasons.append("instruction export is truncated or truncation status is missing")
    if function.get("references_truncated") is not False:
        reasons.append("reference export is truncated or truncation status is missing")
    if reasons:
        raise LiftRejected(reasons, diagnostics)

    addresses = []
    by_address = {}
    for instruction in instructions:
        try:
            address = parse_address(instruction["address"])
            encoded = bytes.fromhex(instruction["bytes"])
            if not encoded or len(encoded) != int(instruction["length"]):
                raise ValueError("encoded bytes do not match instruction length")
            if address in by_address:
                raise ValueError("duplicate instruction address")
            by_address[address] = instruction
            addresses.append(address)
        except (KeyError, TypeError, ValueError) as error:
            reasons.append(f"malformed instruction record: {error}")
            diagnostics.append({
                "address": instruction.get("address"),
                "mnemonic": instruction.get("mnemonic"),
                "reason": str(error),
            })
    if reasons:
        raise LiftRejected(reasons, diagnostics)

    addresses.sort()
    address_set = set(addresses)
    if addresses[0] != parse_address(function["entry"]):
        raise LiftRejected(
            ["first instruction is not the function entry"],
            [{
                "address": function["entry"],
                "mnemonic": "FUNCTION_ENTRY",
                "status": "rejected",
                "reason": "first instruction is not the function entry",
            }],
        )
    stops = set(stop_call_sites or ())
    if stop_call_site is not None:
        stops.add(stop_call_site)
    stops = {
        parse_address(site) if isinstance(site, str) else int(site)
        for site in stops
    }
    for site in sorted(stops):
        boundary = by_address.get(site)
        if boundary is None or boundary.get("mnemonic", "").upper() != "CALL":
            raise LiftRejected(
                [f"stop site 0x{site:08x} is not an exported CALL"],
                diagnostics,
            )
        try:
            direct_call_target(boundary)
        except (KeyError, TypeError, ValueError) as error:
            raise LiftRejected(
                [f"stop site 0x{site:08x} is not a direct CALL: {error}"],
                diagnostics,
            ) from error
    translated = []
    for index, address in enumerate(addresses):
        instruction = by_address[address]
        next_address = (
            address + int(instruction["length"])
            if address + int(instruction["length"]) in address_set
            else None
        )
        try:
            if address in stops:
                target = direct_call_target(instruction)
                body = [
                    f"state.eip = 0x{address:08x}u;",
                    "return BatchLiftStatus::unsupported_dependency;",
                ]
            else:
                body = translate_instruction(
                    instruction,
                    index,
                    address_set,
                    next_address,
                    exported_function_entries,
                    iat_imports,
                    direct_import_aliases,
                    allow_unresolved_calls,
                )
            translated.append((instruction, body))
            diagnostics.append({
                "address": instruction["address"],
                "mnemonic": instruction["mnemonic"].upper(),
                "status": "blocked" if address in stops else "translated",
                "bytes": instruction["bytes"],
                **({"target": f"0x{target:08x}"} if address in stops else {}),
            })
        except (KeyError, TypeError, ValueError) as error:
            diagnostics.append({
                "address": instruction.get("address"),
                "mnemonic": instruction.get("mnemonic", "UNKNOWN").upper(),
                "status": "rejected",
                "reason": str(error),
                "operands": instruction.get("operands", []),
            })
            reasons.append(f"{instruction.get('address')}: {error}")

    if reasons:
        raise LiftRejected(reasons, diagnostics)
    if not translated or translated[-1][0]["mnemonic"].upper() not in {
        "RET", "RETN", "JMP", *SUPPORTED_CONDITIONS
    }:
        diagnostics.append({
            "address": translated[-1][0]["address"] if translated else None,
            "mnemonic": "FUNCTION_EXIT",
            "status": "rejected",
            "reason": "function has no recognized terminal return or unconditional transfer",
        })
        raise LiftRejected(
            ["function has no recognized terminal return or unconditional transfer"],
            diagnostics,
        )
    call_targets = []
    for instruction in instructions:
        address = parse_address(instruction["address"])
        if address in stops or address in (direct_import_aliases or {}):
            continue
        try:
            targets = function_call_targets(
                {"instructions": [instruction]}, iat_imports)
        except ValueError:
            # Indirect calls dispatch through the runtime, so they need no
            # spore_lift_* declaration here.
            continue
        call_targets.extend(targets)
    return static_source(function, translated, call_targets), diagnostics


def translate_function_prefix(
    function, stop_address, exported_function_entries=None,
    allow_branch_boundary=False,
):
    stop_address = (
        parse_address(stop_address) if isinstance(stop_address, str)
        else int(stop_address)
    )
    instructions = function.get("instructions")
    diagnostics = []
    reasons = []
    if not isinstance(instructions, list) or not instructions:
        raise LiftRejected(["instruction list is absent or empty"], diagnostics)
    if function.get("instruction_count_exported") != len(instructions):
        reasons.append("instruction count metadata differs from exported instruction records")
    if function.get("instructions_truncated") is not False:
        reasons.append("instruction export is truncated or truncation status is missing")
    if function.get("references_truncated") is not False:
        reasons.append("reference export is truncated or truncation status is missing")
    if reasons:
        raise LiftRejected(reasons, diagnostics)

    by_address = {}
    for instruction in instructions:
        try:
            address = parse_address(instruction["address"])
            encoded = bytes.fromhex(instruction["bytes"])
            if not encoded or len(encoded) != int(instruction["length"]):
                raise ValueError("encoded bytes do not match instruction length")
            if address in by_address:
                raise ValueError("duplicate instruction address")
            by_address[address] = instruction
        except (KeyError, TypeError, ValueError) as error:
            reasons.append(f"malformed instruction record: {error}")
            diagnostics.append({
                "address": instruction.get("address"),
                "mnemonic": instruction.get("mnemonic"),
                "status": "rejected",
                "reason": str(error),
            })
    if reasons:
        raise LiftRejected(reasons, diagnostics)

    entry = parse_address(function["entry"])
    if entry != min(by_address):
        raise LiftRejected(
            ["first instruction is not the function entry"],
            [{
                "address": function["entry"],
                "mnemonic": "FUNCTION_ENTRY",
                "status": "rejected",
                "reason": "first instruction is not the function entry",
            }],
        )
    boundary = by_address.get(stop_address)
    if boundary is None:
        raise LiftRejected(
            [f"prefix boundary 0x{stop_address:08x} is not an exported instruction"],
            [{
                "address": f"0x{stop_address:08x}",
                "mnemonic": "PREFIX_BOUNDARY",
                "status": "rejected",
                "reason": "prefix boundary is not an exported instruction",
            }],
        )
    branch_boundary = (
        allow_branch_boundary
        and boundary.get("mnemonic", "").upper() in SUPPORTED_CONDITIONS
    )
    if (boundary.get("mnemonic", "").upper() not in {"CALL", "CALLF"}
            and not branch_boundary):
        raise LiftRejected(
            ["prefix boundary must be a direct call instruction"],
            [{
                "address": boundary.get("address"),
                "mnemonic": boundary.get("mnemonic", "UNKNOWN").upper(),
                "status": "rejected",
                "reason": "prefix boundary must be a direct call instruction",
            }],
        )
    boundary_target = None
    if not branch_boundary:
        try:
            boundary_target = direct_call_target(boundary)
        except (KeyError, TypeError, ValueError) as error:
            raise LiftRejected(
                [f"prefix boundary call is not a resolved direct call: {error}"],
                [{
                    "address": boundary.get("address"),
                    "mnemonic": boundary.get("mnemonic", "CALL").upper(),
                    "status": "rejected",
                    "reason": str(error),
                }],
            ) from error

    prefix_instructions = [
        by_address[address]
        for address in sorted(by_address)
        if address < stop_address
    ]
    if not prefix_instructions:
        raise LiftRejected(
            ["prefix contains no instructions before its boundary"],
            [{
                "address": boundary["address"],
                "mnemonic": "PREFIX_BOUNDARY",
                "status": "rejected",
                "reason": "prefix contains no instructions before its boundary",
            }],
        )

    cursor = entry
    for instruction in prefix_instructions:
        address = parse_address(instruction["address"])
        if address != cursor:
            raise LiftRejected(
                ["prefix is not a contiguous instruction sequence"],
                [{
                    "address": instruction["address"],
                    "mnemonic": instruction["mnemonic"].upper(),
                    "status": "rejected",
                    "reason": f"expected fall-through instruction at 0x{cursor:08x}",
                }],
            )
        flow = instruction.get("flow", "").upper()
        if flow not in {"FALL_THROUGH", "UNCONDITIONAL_CALL"}:
            raise LiftRejected(
                ["prefix contains a control-flow instruction before its boundary"],
                [{
                    "address": instruction["address"],
                    "mnemonic": instruction["mnemonic"].upper(),
                    "status": "rejected",
                    "reason": "only fall-through instructions are allowed before the prefix boundary",
                }],
            )
        if flow == "UNCONDITIONAL_CALL":
            try:
                target = direct_call_target(instruction)
            except (KeyError, TypeError, ValueError) as error:
                raise LiftRejected(
                    [f"prefix call is not a resolved direct call: {error}"],
                    [{
                        "address": instruction.get("address"),
                        "mnemonic": instruction.get("mnemonic", "CALL").upper(),
                        "status": "rejected",
                        "reason": str(error),
                    }],
                ) from error
            if target not in (exported_function_entries or set()):
                raise LiftRejected(
                    [f"prefix call target 0x{target:08x} is not in the supplied export set"],
                    [{
                        "address": instruction["address"],
                        "mnemonic": instruction["mnemonic"].upper(),
                        "status": "rejected",
                        "reason": (
                            f"direct call target 0x{target:08x} is not in the "
                            "supplied export set"
                        ),
                        "target": f"0x{target:08x}",
                    }],
                )
        cursor += int(instruction["length"])
    if cursor != stop_address:
        raise LiftRejected(
            ["prefix does not end at the requested call boundary"],
            [{
                "address": f"0x{stop_address:08x}",
                "mnemonic": "PREFIX_BOUNDARY",
                "status": "rejected",
                "reason": f"preceding instructions end at 0x{cursor:08x}",
            }],
        )

    addresses = {
        parse_address(instruction["address"])
        for instruction in prefix_instructions
    }
    addresses.add(stop_address)
    translated = []
    for index, instruction in enumerate(prefix_instructions):
        address = parse_address(instruction["address"])
        next_address = address + int(instruction["length"])
        try:
            body = translate_instruction(
                instruction,
                index,
                addresses,
                next_address,
                exported_function_entries,
            )
            translated.append((instruction, body))
            diagnostics.append({
                "address": instruction["address"],
                "mnemonic": instruction["mnemonic"].upper(),
                "status": "translated",
                "bytes": instruction["bytes"],
            })
        except (KeyError, TypeError, ValueError) as error:
            diagnostics.append({
                "address": instruction.get("address"),
                "mnemonic": instruction.get("mnemonic", "UNKNOWN").upper(),
                "status": "rejected",
                "reason": str(error),
                "operands": instruction.get("operands", []),
            })
            raise LiftRejected(
                [f"{instruction.get('address')}: {error}"], diagnostics
            ) from error

    diagnostics.append({
        "address": boundary["address"],
        "mnemonic": boundary["mnemonic"].upper(),
        "status": "blocked",
        "reason": (
            "prefix stops before conditional branch"
            if branch_boundary else
            f"prefix stops before direct call to 0x{boundary_target:08x}"
        ),
        **({} if branch_boundary else {
            "target": f"0x{boundary_target:08x}"}),
    })
    call_targets = [
        direct_call_target(instruction)
        for instruction in prefix_instructions
        if instruction.get("flow", "").upper() == "UNCONDITIONAL_CALL"
    ]
    return static_source(
        function,
        translated,
        call_targets,
        terminal_status=(stop_address, "unsupported_dependency"),
    ), diagnostics


def translate_function_set(functions, iat_imports=None):
    function_by_entry = {}
    for function in functions:
        entry = parse_address(function["entry"])
        if entry in function_by_entry:
            raise ValueError(f"duplicate exported function entry 0x{entry:08x}")
        function_by_entry[entry] = function

    exported_entries = set(function_by_entry)
    results = {}
    for entry, function in function_by_entry.items():
        try:
            source, diagnostics = translate_function(
                function, exported_entries, iat_imports
            )
        except LiftRejected as error:
            results[entry] = {
                "source": None,
                "diagnostics": error.instruction_diagnostics,
                "reasons": error.reasons,
            }
        else:
            results[entry] = {
                "source": source,
                "diagnostics": diagnostics,
                "reasons": [],
            }

    accepted_entries = {
        entry for entry, result in results.items() if result["source"] is not None
    }
    while True:
        rejected = []
        for entry in sorted(accepted_entries):
            function = function_by_entry[entry]
            unresolved = sorted(set(
                target for target in function_call_targets(function, iat_imports)
                if target not in accepted_entries
            ))
            if unresolved:
                rejected.append((entry, unresolved))
        if not rejected:
            break
        for entry, unresolved in rejected:
            result = results[entry]
            for target in unresolved:
                reason = (
                    f"direct call target 0x{target:08x} is exported but was "
                    "rejected by the static-lift backend"
                )
                result["reasons"].append(reason)
                call_instruction = next(
                    instruction for instruction in function_by_entry[entry]["instructions"]
                    if instruction.get("mnemonic", "").upper() == "CALL"
                    and direct_call_target(instruction) == target
                )
                result["diagnostics"].append({
                    "address": call_instruction["address"],
                    "mnemonic": "CALL",
                    "status": "rejected",
                    "reason": reason,
                    "operands": call_instruction.get("operands", []),
                })
            result["source"] = None
            accepted_entries.remove(entry)

    return results


def parse_pe(path):
    if path.stat().st_size > MAX_INPUT_BYTES:
        raise ValueError("selected executable exceeds the 256 MiB input limit")
    image = path.read_bytes()
    if image[:2] != b"MZ":
        raise ValueError("selected executable is not a PE file")
    pe_offset = struct.unpack_from("<I", image, 0x3C)[0]
    if image[pe_offset:pe_offset + 4] != b"PE\0\0":
        raise ValueError("selected executable has no PE signature")
    machine, section_count, _, _, _, optional_size, _ = struct.unpack_from(
        "<HHIIIHH", image, pe_offset + 4
    )
    if machine != 0x14C:
        raise ValueError(f"expected PE32 x86, got machine 0x{machine:x}")
    optional = pe_offset + 24
    if struct.unpack_from("<H", image, optional)[0] != 0x10B:
        raise ValueError("expected PE32 optional header")
    image_base = struct.unpack_from("<I", image, optional + 28)[0]
    section_table = optional + optional_size
    sections = []
    for index in range(section_count):
        offset = section_table + index * 40
        name = image[offset:offset + 8].split(b"\0", 1)[0].decode("ascii", "replace")
        virtual_size, virtual_address, raw_size, raw_offset = struct.unpack_from(
            "<IIII", image, offset + 8
        )
        sections.append((name, virtual_address, virtual_size, raw_offset, raw_size))
    return image, image_base, sections


def _pe_rva_to_offset(pe, rva, size):
    image, _, sections = pe
    for _, section_rva, _, raw_offset, raw_size in sections:
        if section_rva <= rva and rva + size <= section_rva + raw_size:
            return raw_offset + rva - section_rva
    if rva < len(image) and rva + size <= len(image):
        return rva
    raise ValueError(f"PE RVA 0x{rva:08x} is not backed by file data")


def parse_pe_iat_imports(pe):
    image, image_base, _ = pe
    if len(image) < 0x40:
        raise ValueError("PE image is too small to contain a DOS header")
    pe_offset = struct.unpack_from("<I", image, 0x3c)[0]
    optional = pe_offset + 24
    if optional + 96 + 16 > len(image):
        raise ValueError("PE image is too small to contain PE32 import directories")
    directory_count = struct.unpack_from("<I", image, optional + 92)[0]
    if directory_count <= 1:
        return {}
    import_rva, import_size = struct.unpack_from(
        "<II", image, optional + 96 + 8
    )
    if import_rva == 0 or import_size == 0:
        return {}

    slots = {}
    descriptor_offset = _pe_rva_to_offset(pe, import_rva, 20)
    descriptor_end = descriptor_offset + import_size
    terminated = False
    while descriptor_offset + 20 <= min(descriptor_end, len(image)):
        original_thunk, _, _, name_rva, first_thunk = struct.unpack_from(
            "<IIIII", image, descriptor_offset
        )
        if not any((original_thunk, name_rva, first_thunk)):
            terminated = True
            break
        dll_offset = _pe_rva_to_offset(pe, name_rva, 1)
        dll_end = image.find(b"\0", dll_offset)
        if dll_end < 0:
            raise ValueError("unterminated DLL name in PE import descriptor")
        dll_name = image[dll_offset:dll_end].decode("ascii", "replace")
        lookup_rva = original_thunk or first_thunk
        index = 0
        thunk_terminated = False
        while True:
            thunk_offset = _pe_rva_to_offset(pe, lookup_rva + index * 4, 4)
            thunk_value = struct.unpack_from("<I", image, thunk_offset)[0]
            if thunk_value == 0:
                thunk_terminated = True
                break
            if thunk_value & 0x80000000:
                symbol = f"ordinal_{thunk_value & 0xffff}"
            else:
                import_name_offset = _pe_rva_to_offset(pe, thunk_value, 3)
                name_offset = import_name_offset + 2
                name_end = image.find(b"\0", name_offset)
                if name_end < 0:
                    raise ValueError("unterminated function name in PE import table")
                symbol = image[name_offset:name_end].decode("ascii", "replace")
            iat_va = image_base + first_thunk + index * 4
            if iat_va in slots:
                raise ValueError(f"duplicate PE IAT slot at 0x{iat_va:08x}")
            slots[iat_va] = f"{dll_name}!{symbol}"
            index += 1
        if not thunk_terminated:
            raise ValueError(f"unterminated PE import lookup table for {dll_name}")
        descriptor_offset += 20
    if not terminated:
        raise ValueError("unterminated PE import descriptor table")
    return slots


def read_pe_bytes(pe, va, length):
    image, image_base, sections = pe
    rva = va - image_base
    for name, section_va, virtual_size, raw_offset, raw_size in sections:
        span = max(virtual_size, raw_size)
        if section_va <= rva and rva + length <= section_va + span:
            offset = raw_offset + rva - section_va
            raw = image[offset:offset + length]
            if len(raw) != length:
                raise ValueError(f"{name} bytes at 0x{va:08x} exceed raw file data")
            return name, offset, raw
    raise ValueError(f"VA 0x{va:08x} is not backed by a PE section")


def validate_function_bytes(function, pe):
    verified = []
    occupied = set()
    for instruction in function["instructions"]:
        address = parse_address(instruction["address"])
        encoded = bytes.fromhex(instruction["bytes"])
        if len(encoded) != int(instruction["length"]):
            raise ValueError(f"instruction length mismatch at 0x{address:08x}")
        section, _, original = read_pe_bytes(pe, address, len(encoded))
        if original != encoded:
            raise ValueError(f"Ghidra bytes differ from selected PE at 0x{address:08x}")
        if section != ".text":
            raise ValueError(f"instruction at 0x{address:08x} is in {section}, not .text")
        for offset in range(address, address + len(encoded)):
            if offset in occupied:
                raise ValueError(f"overlapping instructions at 0x{offset:08x}")
            occupied.add(offset)
        verified.append({
            "address": instruction["address"],
            "bytes": instruction["bytes"],
            "length": len(encoded),
        })
    body = function.get("body_address_count")
    if body is None or int(body) != len(occupied):
        raise ValueError(
            f"body byte count {body!r} differs from decoded instruction bytes {len(occupied)}"
        )
    return verified


def load_inventory(csv_path):
    rows = {}
    with csv_path.open(newline="", encoding="utf-8-sig") as stream:
        for row in csv.DictReader(stream):
            address = int(row["address"], 16)
            if address in rows:
                raise ValueError(f"duplicate inventory address 0x{address:08x}")
            rows[address] = row
    return rows


def sha256_file(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def validate_pilot_manifest(batch, functions):
    pilot_size = len(functions)
    if pilot_size not in PILOT_SELECTION_COUNTS:
        raise ValueError(
            f"pilot must contain exactly 30, 100, or 300 functions, got {pilot_size}"
        )
    if batch.get("pilot_size", pilot_size) != pilot_size:
        raise ValueError("pilot_size metadata differs from the exported function count")

    expected_counts = PILOT_SELECTION_COUNTS[pilot_size]
    declared_counts = batch.get("selection_counts")
    if declared_counts is not None and declared_counts != expected_counts:
        raise ValueError(
            f"declared pilot strata differ from expected {pilot_size}-function plan: "
            f"{declared_counts}"
        )
    if pilot_size in {100, 300} and declared_counts is None:
        raise ValueError(
            f"{pilot_size}-function export is missing selection_counts metadata"
        )

    actual_counts = collections.Counter(
        entry.get("selection_stratum") for entry in functions
    )
    if dict(actual_counts) != expected_counts:
        raise ValueError(
            f"pilot strata differ from required {pilot_size}-function plan: "
            f"{dict(actual_counts)}"
        )


def analyze_batch(executable, inventory_path, batch_path, output_dir, report_path):
    source_hash = sha256_file(executable)
    if source_hash != EXPECTED_SHA256:
        raise ValueError(f"PE SHA-256 mismatch: expected {EXPECTED_SHA256}, got {source_hash}")
    if batch_path.stat().st_size > MAX_BATCH_BYTES:
        raise ValueError("batch export exceeds the 128 MiB input limit")
    batch = json.loads(batch_path.read_text(encoding="utf-8"))
    if batch.get("schema") != "spore-ghidra-function-batch-v1":
        raise ValueError(f"unsupported batch schema: {batch.get('schema')!r}")
    if batch.get("selected_source_sha256") != EXPECTED_SHA256:
        raise ValueError("batch export source SHA-256 differs from selected executable")
    if batch.get("selected_source_is_phase4_build") is not True:
        raise ValueError("batch export does not identify the approved Phase 4 build")
    if batch.get("user_confirmed_source_for_open_program") is not True:
        raise ValueError("batch export is missing explicit Ghidra source confirmation")
    if batch.get("language_id") != EXPECTED_LANGUAGE:
        raise ValueError(f"unexpected Ghidra language: {batch.get('language_id')!r}")
    if batch.get("functions_truncated") is not False:
        raise ValueError("batch function list is incomplete or truncation status is absent")
    functions = batch.get("functions")
    if not isinstance(functions, list):
        raise ValueError("batch export is missing its function list")
    validate_pilot_manifest(batch, functions)
    if not isinstance(batch.get("reachability_complete"), bool):
        raise ValueError("batch export is missing a definite reachability completeness flag")
    if not isinstance(batch.get("reachability_visited_function_count"), int):
        raise ValueError("batch export is missing its reachability traversal count")
    inventory = load_inventory(inventory_path)
    pe = parse_pe(executable)
    if output_dir.exists() and any(output_dir.iterdir()):
        raise ValueError(f"output directory is not empty: {output_dir}")
    if report_path.exists():
        raise ValueError(f"report already exists; preserve it before rerunning: {report_path}")
    summary = {
        "schema": "spore-static-lift-batch-report-v1",
        "source_sha256": source_hash,
        "batch_export": str(batch_path),
        "pilot_size": len(functions),
        "selection_counts": {},
        "accepted_function_count": 0,
        "rejected_function_count": 0,
        "accepted_instruction_count": 0,
        "rejected_function_instruction_count": 0,
        "rejected_instruction_diagnostic_count": 0,
        "accepted_instruction_bytes": 0,
        "accepted_unique_instruction_bytes": 0,
        "exported_instruction_bytes": 0,
        "exported_unique_instruction_bytes": 0,
        "overlapping_function_instruction_bytes": 0,
        "accepted_bytes_percent_of_pilot_export": 0.0,
        "reachable_pilot_function_count": 0,
        "unreachable_pilot_function_count": 0,
        "unknown_reachability_pilot_function_count": 0,
        "accepted_reachable_function_count": 0,
        "reachability_complete": batch.get("reachability_complete"),
        "reachability_visited_function_count": batch.get(
            "reachability_visited_function_count"
        ),
        "reachability_root_addresses": batch.get("reachability_root_addresses", []),
        "reachable_function_count_if_complete": (
            batch.get("reachability_visited_function_count")
            if batch.get("reachability_complete")
            else None
        ),
        "reachability_basis": batch.get("reachability_basis"),
        "reachability_limitations": batch.get("reachability_limitations", []),
        "rejection_counts_by_kind": {},
        "functions": [],
    }
    instruction_mnemonics = collections.Counter()
    exported_byte_addresses = set()
    accepted_byte_addresses = set()
    rejection_kinds = collections.Counter()
    function_rejection_reasons = collections.Counter()
    generated_files = {}
    function_records = []
    for function_export in functions:
        function = function_export.get("function")
        if not isinstance(function, dict):
            raise ValueError("batch entry is missing its function record")
        function_records.append(function)
    translations = translate_function_set(function_records)
    seen_entries = set()
    for function_export in functions:
        function = function_export.get("function")
        address = parse_address(function["entry"])
        if address in seen_entries:
            raise ValueError(f"duplicate pilot function entry 0x{address:08x}")
        seen_entries.add(address)
        if address not in inventory:
            raise ValueError(f"0x{address:08x} is absent from the function inventory")
        row = inventory[address]
        if row["name"] != function.get("name"):
            raise ValueError(f"inventory name differs at 0x{address:08x}")
        if int(row["size"], 0) != int(function["body_address_count"]):
            raise ValueError(f"inventory/body size differs at 0x{address:08x}")

        verified = validate_function_bytes(function, pe)
        byte_count = sum(item["length"] for item in verified)
        summary["exported_instruction_bytes"] += byte_count
        for item in verified:
            start = parse_address(item["address"])
            exported_byte_addresses.update(range(start, start + item["length"]))
        stratum = function_export.get("selection_stratum", "unknown")
        summary["selection_counts"][stratum] = (
            summary["selection_counts"].get(stratum, 0) + 1
        )
        is_reachable = function_export.get("reachable_from_program_entry")
        if is_reachable not in {True, False, None}:
            raise ValueError(f"invalid reachability state for 0x{address:08x}")
        if batch["reachability_complete"] and is_reachable is None:
            raise ValueError(
                f"complete reachability traversal has unknown state for 0x{address:08x}"
            )
        if not batch["reachability_complete"] and is_reachable is False:
            raise ValueError(
                f"incomplete reachability traversal cannot mark 0x{address:08x} unreachable"
            )
        if is_reachable is True:
            summary["reachable_pilot_function_count"] += 1
        elif is_reachable is False:
            summary["unreachable_pilot_function_count"] += 1
        else:
            summary["unknown_reachability_pilot_function_count"] += 1

        record = {
            "address": f"0x{address:08x}",
            "name": function["name"],
            "selection_stratum": stratum,
            "inventory_size_bytes": int(row["size"], 0),
            "instruction_count": len(function["instructions"]),
            "instruction_bytes": byte_count,
            "reachable_from_program_entry": is_reachable,
            "reachability_kind": function_export.get("reachability_kind"),
            "verified_bytes": verified,
            "status": "rejected",
            "rejection_reasons": [],
            "instruction_diagnostics": [],
        }
        translation = translations[address]
        if translation["source"] is None:
            record["rejection_reasons"] = translation["reasons"]
            record["instruction_diagnostics"] = translation["diagnostics"]
            summary["rejected_function_count"] += 1
            summary["rejected_function_instruction_count"] += len(function["instructions"])
            function_rejection_reasons.update(translation["reasons"])
        else:
            source = translation["source"]
            diagnostics = translation["diagnostics"]
            filename = f"spore_{address:08x}_arm64.cpp"
            generated_files[filename] = source + "\n"
            record["status"] = "accepted"
            record["generated_source"] = filename
            record["instruction_diagnostics"] = diagnostics
            summary["accepted_function_count"] += 1
            summary["accepted_instruction_count"] += len(function["instructions"])
            summary["accepted_instruction_bytes"] += byte_count
            for item in verified:
                start = parse_address(item["address"])
                accepted_byte_addresses.update(range(start, start + item["length"]))
            if is_reachable is True:
                summary["accepted_reachable_function_count"] += 1

        for instruction in function["instructions"]:
            instruction_mnemonics[instruction["mnemonic"].upper()] += 1
        supported_count = sum(
            item.get("status") == "translated"
            for item in record["instruction_diagnostics"]
        )
        rejected_count = sum(
            item.get("status") == "rejected"
            for item in record["instruction_diagnostics"]
        )
        summary["rejected_instruction_diagnostic_count"] += rejected_count
        for diagnostic in record["instruction_diagnostics"]:
            if diagnostic.get("status") != "rejected":
                continue
            reason = diagnostic.get("reason", "").lower()
            if "call" in reason:
                kind = "direct_or_indirect_call"
            elif "memory access" in reason:
                kind = "memory_access"
            elif "operand" in reason or "addressing" in reason:
                kind = "unsupported_operand_form"
            elif "branch" in reason or "target" in reason or "fallthrough" in reason:
                kind = "control_flow"
            elif "unsupported instruction" in reason:
                kind = "unsupported_opcode"
            else:
                kind = "other"
            rejection_kinds[kind] += 1
        record["instruction_diagnostic_counts"] = {
            "translated": supported_count,
            "rejected": rejected_count,
        }
        summary["functions"].append(record)

    summary["accepted_unique_instruction_bytes"] = len(accepted_byte_addresses)
    summary["exported_unique_instruction_bytes"] = len(exported_byte_addresses)
    summary["overlapping_function_instruction_bytes"] = (
        summary["exported_instruction_bytes"]
        - summary["exported_unique_instruction_bytes"]
    )
    if summary["exported_unique_instruction_bytes"]:
        summary["accepted_bytes_percent_of_pilot_export"] = round(
            100.0 * summary["accepted_unique_instruction_bytes"]
            / summary["exported_unique_instruction_bytes"],
            2,
        )
    summary["rejection_counts_by_kind"] = dict(sorted(rejection_kinds.items()))
    summary["function_rejection_reason_counts"] = dict(
        sorted(function_rejection_reasons.items())
    )
    summary["mnemonic_counts"] = dict(sorted(instruction_mnemonics.items()))
    summary["coverage_definition"] = (
        "Exact instruction bytes from complete functions accepted and emitted by this "
        "static backend; not whole-.text coverage and not proof of game execution."
    )
    output_dir.mkdir(parents=True, exist_ok=True)
    report_path.parent.mkdir(parents=True, exist_ok=True)
    for filename, source in generated_files.items():
        (output_dir / filename).write_text(source, encoding="utf-8")
    report_path.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    return summary


def main():
    parser = argparse.ArgumentParser(
        description="Verify a 30/100-function Ghidra batch and emit fail-closed static C++ lifts."
    )
    parser.add_argument("--exe", type=Path, required=True)
    parser.add_argument("--csv", type=Path, required=True)
    parser.add_argument("--batch", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    args = parser.parse_args()
    try:
        summary = analyze_batch(
            args.exe, args.csv, args.batch, args.output_dir, args.report
        )
    except (
        OSError, ValueError, KeyError, TypeError, json.JSONDecodeError, struct.error
    ) as error:
        print(f"batch lift failed: {error}", file=sys.stderr)
        return 1
    print(
        "Pilot functions: "
        f"{summary['accepted_function_count']} accepted, "
        f"{summary['rejected_function_count']} rejected; "
        f"{summary['accepted_instruction_bytes']}/"
        f"{summary['exported_instruction_bytes']} accepted instruction bytes."
    )
    print(
        "Reachability: "
        f"{summary['reachable_pilot_function_count']}/"
        f"{summary['pilot_size']} pilot functions reported reachable from program entry."
    )
    print(f"Report: {args.report}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
