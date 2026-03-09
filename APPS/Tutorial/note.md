### NASM (Netwide Assembler)

a popular, open-source assembler used to convert **x86** assembly language into machine code. It supports various operating systems like Linux, Windows, and macOS, using a simple **Intel-style** syntax.

### CISC and RISC computer architecture

> **RISC** uses simple, fixed-length instructions executed in a single clock cycle, ideal for power efficiency (ARM, Apple Silicon). **CISC** uses complex, variable-length instructions, allowing multiple operations per command, designed for high performance in desktops (Intel x86). 


## CPU components:

1. A high frequency clock (Heart-beat)

   - Cycles between 0 and 1 that synchronizes operations.
    ensuring components like the CPU and RAM work together in time.
2. A Control unit (Brain)
   - Directs the flow of data and manages instruction execution.
   It fetches, decodes, and executes instructions by sending control signals to the ALU, memory, and I/O devices.
3. The arithmetic logic unit (ALU)
   - Complete operations like ADD, AND, OR, NOT, etc
3. Storage location (registery, fastest memory to access in cpu)


## Fetch Decode Execute cycle

## Memory

- Memory access is slower than register access.
- To reduce read/write time for memory, **caches** are used
   - in 86x: **level-1 cache** (stored on CPU), **level-2 cache** (stored outside and accessed by high-speed data bus)



## Types of Buses

> Communication system that transfers data between components like the CPU, memory, and I/O devices

1. **Data Bus:** Carries the actual data being processed (payload) between the CPU, memory, and peripheral devices.

2. **Address Bus:** Carries information about where data is located in memory or which device is being accessed.

3. **Control Bus:** Transmits command signals from the CPU to synchronize and manage connected components.

### Register names:
> 64-bit:  rax  rbx  rcx  rdx  rsi  rdi  rsp  rbp  r8-r15
> 32-bit:  eax  ebx  ecx  edx  esi  edi  esp  ebp  r8d-r15d
> 16-bit:  ax   bx   cx   dx   si   di   sp   bp   r8w-r15w
> 8-bit:   al   bl   cl   dl   sil  dil  spl  bpl  r8b-r15b


**for Linux/WSL**

- rdi  = 1st function argument
- rsi  = 2nd function argument
- rdx  = 3rd function argument
- rcx  = 4th function argument
- r8   = 5th function argument
- r9   = 6th function argument
- rax  = Return value


## Directives

- db = define byte (8 bits)
- dw = define word (16 bits)
- dd = define double word (32 bits) ← Your case
- dq = define quad word (64 bits)
