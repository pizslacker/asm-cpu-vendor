# asm-cpu-vendor

  > "If you can read assembly, then everything is open source." -- Programmer Joke

Retreive CPU vendor string with inline assembly code.

Here is a breakdown of how the GCC extended inline assembly works in this context:

- **The cpuid instruction**: This opcode returns processor information and feature bits. The data it returns depends on the value loaded into the `EAX` register before it executes.
- **Leaf `0`**: Passing `0` into `EAX` requests the "Maximum Input Value for Basic CPUID Information" (returned in `EAX`) and the "Vendor Identification String".

- **Operand Constraints**:

  - `"=a"`, `"=b"`, `"=c"`, `"=d"` map the output variables directly to the `EAX`, `EBX`, `ECX`, and EDX hardware registers. The `=` denotes they are write-only outputs.

  - `"a" (0)` tells the compiler to load the integer `0` into the `EAX` register right before executing the `cpuid` instruction.

**The String Order**: Historically, the 12-character vendor string is returned in a non-alphabetical register order: `EBX`, then `EDX`, then `ECX`. For example, on an Intel chip, `EBX` holds "Genu", `EDX` holds "ineI", and `ECX` holds "ntel".

`volatile`: This keyword tells the compiler's optimizer not to move, cache, or delete this assembly block, ensuring the instruction executes exactly where you placed it.
