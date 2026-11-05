# Third real PE function candidate

## Observed target

- Executable SHA-256: `290703b34fe4573b242c3e271cc90568992abe6fb3fa9333a7341044a759fc74`
- Section: `.text`
- RVA: `0x22430`
- VA: `0x422430`
- Observed body: 122 bytes, 47 instructions
- Direct calls: none inside the candidate body
- Direct callers found locally:
  - VA `0x412B7B`
  - VA `0x412B92`
  - VA `0x461557`

## Static semantic reconstruction

The function computes:

```cpp
(end - begin) / 12
```

Then performs a binary search over 12-byte records, comparing the first `uint32_t` field with a
pointer supplied as the third argument:

```cpp
const uint32_t key = *requested_key;
while (count > 0) {
    const Record* middle = begin + count / 2;
    if (middle->key < key)
        begin = middle + 1;
    else
        count = middle - begin;
    // Equivalent to searching for the first key >= requested_key.
}
return begin;
```

This is consistent with a lower-bound/search function over sorted unsigned 32-bit keys in
records containing three 32-bit words.

## Caller evidence

- A direct caller at VA `0x461557` pushes a begin pointer, an end pointer, a key-pointer and one
  additional argument to the call.
- The candidate consumes the first three arguments and does not read the fourth argument.
- Caller cleanup adds 16 bytes to ESP, consistent with the four stack arguments.
- The function returns the matching insertion/search boundary pointer.
- Two additional callers exist, at nearby addresses `0x412B7B` and `0x412B92`.

## Implementation status

`lifted_lower_bound.cpp` models the operation with a 12-byte three-word record.
`test_lifted_lower_bound.py` supplies independent sorted-array test vectors.

`emulate_lower_bound_candidate.py` executes the exact 122-byte PE machine code with Unicorn and compares
the returned pointer index with an independent Python lower-bound implementation. The initial boundary
and interpolation cases matched the Python oracle.

The ARM64 C++ reference has been pushed to an `arm64-v8a` physical device and executed successfully.
Device execution validates native ARM64 compilation; it does not yet prove equivalence of the original
x86 machine body across every input.
