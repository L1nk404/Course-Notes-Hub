# Data type

| Directive | Data Type                                               |
| --------- | ------------------------------------------------------- |
| .ascii    | Text string                                             |
| .asciz    | Null-terminated text string                             |
| .byte     | Byte value                                              |
| .double   | Double-precision floating-point number                  |
| .float    | Single-precision floating-point number                  |
| .int      | 32-bit integer number                                   |
| .long     | 32-bit integer number (same as .int)                    |
| .octa     | 16-byte integer number                                  |
| .quad     | 8-byte integer number                                   |
| .short    | 16-bit integer number                                   |
| .single   | Single-precision floating-point number (same as .float) |

# Moving Data

##### Syntax

    mov<size> <source> <destination>`

##### mov data size:
- mov*l* => 32 bit long data
    - *l* stands for long
- mov*w* => 16 bit word data
    - *w* stands for world
- mov*b* => 8 bit byte data
    - *b* stands for bytes

Example:

`movl $4 %eax`
###  Practical Example
Let's debug the following code:

```
.section .text
.globl _start
_start:
    nop                 # for the debug

    movl $25, %eax      # moving the decimal number 25 (32 bit) to eax register
    movw $4,  %bx       # bx is 16 bits register
    movb $1,  %cl       # cl is a 8 bit register (the lower 8 bit register of ecx register)

    movl $1,  %eax      # exit
    movl $0,  %ebx      # return code
    int  $0x80          # interrupt
```

![[Pasted image 20240610161802.png]]

When we move the the decimal number *4* to *%bx* register, we are moving the value 4 to the 16 bit *bx low* register, the another one is empty. This is important to understand.
The same occurs with ECX register, but now, with a 8 bit register *cl - c low* 

| <---------- | ECX 32 BITS | ----------> |
| :---------: | :---------: | :---------: |
|   16 bits   |   8 bits    |   8 bits    |
|     Cx      |     ch      |     cl      |
|    empty    |    empty    |      1      |

## Immediate Values vs. System Calls

It's important to understand the different uses of immediate values (like $1) and system calls, as well as why system calls typically use 32-bit registers. Let's break down the concepts:

1. Immediate Values:
    An immediate value is a constant used directly in an instruction.
    For example, in the instruction movl $25, %eax, $25 is an immediate value.
    Immediate values can be any constant value (like 1, 25, 100, etc.) and are used in various contexts, such as arithmetic operations, data movement, and more.

2. System Calls:
    A system call is a request made by a program to the operating system to perform a specific operation, like reading from a file, writing to a file, or exiting the program.
    Each system call has a unique number. For example, on Linux, the sys_exit system call number is 1.

### Distinguishing Immediate Values and System Calls

- **Immediate Value** - Represents a constant value directly used in an operation.
    Example: movl $25, %eax uses $25 as a constant value.

- **System Call** - A specific request to the operating system to perform a service.
    Example: movl $1, %eax sets up the system call number for sys_exit.

To distinguish between an immediate value and a system call in assembly code, you need to look at the context in which the immediate value is being used. 

1. **Instruction Context**:
    - Immediate values are often used in arithmetic operations, data movement, and other non-system call instructions.
    - System calls are typically identified by a combination of setting up a specific system call number in a register and then invoking a software interrupt or system call instruction.

2. **Registers and Instructions**:
    - System calls on x86 Linux typically involve moving a specific number into the eax register followed by the int 0x80 instruction.
    - Immediate values can be moved into any register and used in various instructions.

### A bit advanced example:

```
.section .bss
    .comm mydata, 4         # size 4

.section .text
.globl _start
_start:
    nop
    movl $100, mydata       # moving 100 to mydata 
    # mydata value: 100

    movl mydata, %ecx       # moving mydata to ecx register
    # ecx value: mydata = 100

    # when we use $ before a variable we are refering to their memmory address
    movl $mydata, %edx      # moving the address of mydata to edx register
    movl $500,    %eax      # moving 500 to eax register
    movl %eax,   (%edx)     # moving the eax value to the location which is pointed by the value of edx
                            # ... In that case, we moved eax value to mydata
    # Finally, the mydata value is 500.


    # Exit syscall
    movl $1, %eax
    movl $0, %ebx
    int $0x80
```

