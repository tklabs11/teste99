# First real PE function candidate

## Observed target

- Executable SHA-256: `290703b34fe4573b242c3e271cc90568992abe6fb3fa9333a7341044a759fc74`
- Section: `.text`
- RVA: `0x79C00`
- VA: `0x0479C00`
- Observed body: 128 file-backed bytes before the candidate's return
- Direct calls: none observed in the candidate body

## Static observations

The region begins with a standard `push ebp; mov ebp, esp; sub esp, ...` prologue and
ends with an epilogue and `ret`.

Observed behavior includes:

- a loop comparing two addresses;
- pointer increments by 8 bytes;
- conditional branches;
- two `fld`/`fstp` pairs copying 32-bit float values;
- writing one 32-bit result through a stack-derived pointer.

No function name, x86 calling convention, parameter types, return type, caller set, or caller
state is established by the focused scan alone.

## Not established

- This is not confirmed gameplay or gameplay-adjacent code.
- The parameter roles are inferred only from instruction offsets.
- The x86 body may be compiler-generated `try/catch` or thunk-adjacent logic.
- The candidate is not yet suitable for ARM64 implementation.

## Required verification

1. Complete focused Ghidra reference analysis for VA `0x0479C00`.
2. Recover direct callers and data references.
3. Confirm function boundaries and stack parameters.
4. Run a controlled x86 observation with a representative caller, when permitted and technically available.
5. Reconstruct the function as a named semantic operation, not a blind byte translation.
6. Add independent x86-equivalent and ARM64 reference cases before declaring lift success.
