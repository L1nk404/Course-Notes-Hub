	# Memory Layout

![[Pasted image 20240524161008.png]]

---
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
    nop                     # No operation
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

That's what that code is doing:

1. First of all, we located a empty space in the memory called *mydata*, with size 4.
2. Then, we moved the value 100 to *mydata*.
3. We moved the *mydata* **value** to *ecx* register, in this way, the ecx register now stores the value 100.
4. Using `$mydata` we moved the mydata address to the *edx* register.
5. Now we moved the *500* value to *eax* register
6. Now we change the *mydata* value indirectly by moving the *eax* value to the location which is pointed by the value of *edx* (denoted by "( )") which is the address of *mydata*.

## Accessing and Moving Indexed values

In that sessions we'll see how to access elements of an Array
To access an element in an array we have to use the *base_address*.
The base address is the label name and it requires 3 parameters :
1. **offset_address** - This is the distance (in bytes) from the base address to the desired element within the array.  If the elements in the array are of type int (which typically have a size of 4 bytes), and you want to access the third element, the offset would be $2 * 4$ (because array indexing starts from 0). Therefore, the offset would be 8 bytes. To calculate the address of the specific element, we use 
$$
	Element Address=Base Address+(Index×Element Size)
$$
        (!) The offset_address is often left as 0 because the actual offset is calculated using the index and size. This is why it appears as 0 or is omitted. The index and size together form the effective offset.
2. **index** - The index of the required element.
3. **size** - size of the target element in bytes.

Take the following example:

```
.section .data                           # Initialized Data
    Numbers:                             # Array   
            .int  10,20,30,40,50,60

.section .text
.globl _start

_start:
    nop
    # edi is usead as a pointer to the destination in string operations
    movl $2, %edi                    # storing the index value to the 3rd element on the register       
    movl Numbers(,%edi,4), %eax      # Acessing the 3rd element

    # exit syscall
    movl $1, %eax
    movl $0, %ebx
    int $0x80

```

We can see that we omitted the offset_address, in that case, we just skipped and let the index and the size form the offset address.

---

## Memory Addressing

### Direct Memory Addressing

Lets suppose that the user wants to move the number 5 to the 0xAAAA memory location.
How this can be done?
The answer is simple. We just need to use the memory region address using the `movl $5 0xAAAA` command.

![[Pasted image 20240716162116.png]]

This is called **Direct Memory Addressing** 

### Indirect Memory Addressing

Now, suppose that the address is not accessible by us, so we cannot access this memory address.
In this case we have to perform 2 steps in order to move 5 to 0xAAAA memory address:

1. We have to move the memory address into one of our general purpose register, like the *eax* register, so, `movl 0xAAAA, %eax`.
2. Then we move the data to the address that is pointed by the eax register using `movl $5, (%eax)`.

### Pratical Example

```
.section .data
    Number:
        .int 0 

.section .text
.globl _start
_start:
    nop
    # direct addressing
    movl $5, Number     # Moving the number 5 to Number address

    # indirect addressing
    movl $Number, %eax   # Moving the address of Number to eax
    movl $10, (%eax)     # Moving 10 to address pointed by eax

    # exit sycall
    movl $1, %eax
    movl $0, %ebx
    int $0x80
```

## Indirect address pointer

Let's take a look in another example:

```
.section .data
    myNumber:
        .int 4,8

.section .text
_globl _start
_start:
    nop

    movl $myNumber, %eax        # Moving myNumber addr to eax register
    movl $2, (%eax)             # Moving 4 bytes 
    movb $9,2 (%eax)            # Moving 1 byte
    movw $3,6 (%eax)            # Moving 2 bytes

    # exit syscal
    movl $1, %eax
    movl $0, %ebx
    int $0x80
```

Take *myNumber* label. We can represent the way that it is stored in the memory in the following example:

| byte index|  7   |  6   |  5   |  4   |  3   |  2   |  1   |  0   |
| --------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| bytes     | 00   | 00   | 00   | 08   | 00   | 00   | 00   | 04   |

When we use the **movl** command we are moving the number 2 contained in a **4 byte** (0000002) to the eax pointer, we are moving it to the first index of myNumber, in this way, the memory layout will be:

| byte index|  7   |  6   |  5   |  4   |  3   |  2   |  1   |  0   |
| --------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| bytes     | 00   | 00   | 00   | 08   |**00**|**00**|**00**|**02**|

Now, when we use the option **movb** we are moving **1 byte**. So `movb $9,2 ($eax)` we are moving only the number 9 (09) to the third index (because the 2 after comma) to the on the memory location:

| byte index|  7   |  6   |  5   |  4   |  3   |  2   |  1   |  0   |
| --------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| bytes     | 00   | 00   | 00   | 08   |  00  |**09**|  00  |  02  |

Finally, moving 2 bytes with the command `movw $3,6 (%eax)` to the index 6. We have:

| byte index|  7   |  6   |  5   |  4   |  3   |  2   |  1   |  0   |
| --------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| bytes     |**00**|**03**| 00   | 08   |  00  |  09  |  00  |  02  |


## Stack Frame

A stack frame is a data structure that holds information about a function call in a program, specifically in the call stack. Every time a function is invoked, a new stack frame is created and pushed onto the stack, and when the function completes, its frame is popped off the stack.

A stack frame typically contains:
1. **Return address**: The location  in the memory address which points to the next instruction in the calling function  to return to after the function call is finished.
2. **Function parameters**: The arguments passed to the function.
3. **Local variables**: Variables that are defined within the function.
4. **Saved registers**: The values of certain CPU registers that the function may need to restore later.
5. **Stack pointer**: Points to the current position in the stack.

Understanding stack frames is crucial in low-level programming and concepts like buffer overflows, which are common in cybersecurity exploits.