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
- mov*b* => 8 bit data
    - *b* stands for bytes

Example:

`movl $4 %eax`
###  Practical Example
Let's debug the following code:

```nasm
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

```nasm
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
	ElementAddress=BaseAddress+(Index\times ElementSize)
$$

> [!NOTE]
> The offset_address is often left as 0 because the actual offset is calculated using the index and size. This is why it appears as 0 or is omitted. The index and size together form the effective offset.

2. **index** - The index of the required element.
3. **size** - size of the target element in bytes.

Take the following example:

```nasm
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

```nasm
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

```nasm
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


# Stack Frame

A stack frame is a data structure that holds information about a function call in a program, specifically in the call stack. Every time a function is invoked, a new stack frame is created and pushed onto the stack, and when the function completes, its frame is popped off the stack.

A stack frame typically contains:
1. **Return address**: The memory location to return to after the function call is finished.
2. **Function parameters**: The arguments passed to the function.
3. **Local variables**: Variables that are defined within the function.
4. **Saved registers**: Values of certain CPU registers that the function may need to restore later.
5. **Stack pointer**: Points to the current position in the stack.

Understanding stack frames is crucial in low-level programming and is also relevant for concepts like buffer overflows, which are common in cybersecurity exploits.

Before we see an example, let's remember the roles of the **EBP** and **ESP** registers. From [[Register]] we have:

"""
7. **EBP (Extended Base Pointer)**:	    
    - **Primary Use**: Used to point to the base of the stack frame, facilitating stack operations.
    - **Example**: Accessing local variables and function parameters on the stack.
8. **ESP (Extended Stack Pointer)**:    
    - **Primary Use**: Points to the top of the stack, managing stack operations.
    - **Example**: Pushing and popping values from the stack.
"""

Let's analyse that register a bit deeper:

### EBP

The **Base Pointer (ebp)** register acts as a **fixed reference point** within the stack frame of a function. The ebp remains constant throughout the execution of a function.
ebp is used to access variables, parameters, and saved registers with fixed offsets, making it easier to navigate the stack. Think of it as a stable anchor that provides structure within the stack frame. You can think the ebp as a Home Page, where is the start point of a website and you can navigate throught it from the Home Page.
So , in a direct way, the base pointer (ebp) acts like a fixed reference or anchor point in the stack. While the stack pointer (esp) changes dynamically as data is added or removed from the stack, ebp stays constant within a function, making it easy to locate and access data like local variables and function parameters. In this way, ebp is like a home page—it provides a stable point from which other locations (data on the stack) can be easily reached.

### ESP

The **ESP register (Extended Stack Pointer)** in x86 assembly is a special-purpose register that always points to the top of the stack. It keeps track of where the current "top" (last used location) of the stack is in memory, dynamically changing as data is pushed onto or popped off the stack.
The stack is used to manage function calls, local variables, and other temporary data needed during program execution. The stack grows downward in memory (i.e., toward lower memory addresses).

#### Key Roles of `ESP`:

1. **Tracks the Top of the Stack**: `ESP` always points to the memory address at the top of the stack. This is the most recent item that has been added to the stack, such as a return address, function parameter, or local variable.
    
2. **Changes Dynamically**: Unlike the base pointer (`EBP`), which remains constant throughout a function, `ESP` is constantly updated. It changes when:
    
    - You **push** data onto the stack (which decreases `ESP`).
    - You **pop** data off the stack (which increases `ESP`).
    - You **allocate space** for local variables (by subtracting from `ESP`).
    - You **deallocate space** when the function returns (by restoring `ESP`).
    
3. **Used for Memory Management**: When you need to allocate memory for local variables or temporary storage within a function, the stack pointer (`ESP`) is adjusted to create space on the stack. Similarly, when you return from a function, `ESP` is restored to its previous value, "cleaning up" the stack.

So, in a nutshell, we have:

- **`ESP` (Stack Pointer)**:    
    - Always points to the **top of the stack**.
    - It dynamically changes as you push or pop values or allocate memory (for local variables, return addresses, etc.).
    - **Tracks the current position in the stack** during function execution.
    
- **`EBP` (Base Pointer)**:    
    - Points to the **base of the current stack frame**.
    - **Remains fixed** throughout the function execution to serve as a stable reference point for accessing function parameters, saved registers, and local variables.
    - Typically does not change until the function exits.

So, everything works around the EBP stack pointer perspective. **We need to the ebp pointer to tell us where we are from the stack frame**


### First Example

```nasm
.section .data

.section .text

.globl _start

  
_start:

nop
nop

  
# copy the esp address to ebp (base pointer)
movl %esp, %ebp

# create some memory space in stack frame
subl $8, %esp
```

Let's walk through the assembly code step by step and visualize how the stack frame changes with each operation.

#### 1. Initial State:

Before the program executes the instructions, the stack pointer (ESP) points to some memory location, for simplicity, let's say 0xFFFC. **The base pointer (EBP) is uninitialized and will be set later**.

**Stack before execution:**

```    
Memory Address    Stack Content
0xFFFC            [Undefined]   <- ESP (top of the stack)
```

At this point, ESP points to 0xFFFC (an arbitrary initial value), and EBP has not been set yet.

From debugger (with real memory values): 

![[Pasted image 20240918204837.png]]

Notice that  the memory space (or the distance) between *ebp* and *esp* are 0

![[Pasted image 20240918205343.png]]
#### 2. After movl %esp, %ebp

This instruction copies the current value of the stack pointer (ESP) into the base pointer (EBP). Now both ESP and EBP point to the same location, 0xFFFC.

**Stack after movl %esp, %ebp:**

```
Memory Address    Stack Content
0xFFFC            [Undefined]   <- ESP (top of the stack), EBP (base pointer)
```

From debugger:

![[Pasted image 20240918204914.png]]

Now, both ESP and EBP point to the same memory address (0xFFFC), marking the initial top and base of the stack frame.
From now, the base pointer fixed the location, and will not change, like said above, everything will work through the ebp perspective.

#### 3. After subl $8, %esp

This instruction subtracts 8 bytes from the stack pointer (ESP), moving ESP down the stack (toward a lower memory address) to allocate space for local variables.

**Stack after subl $8, %esp**:

```
Memory Address    Stack Content
0xFFFC            [Undefined]   <- EBP (base pointer)
0xFFF8            [Empty space (local variable)]
0xFFF4            [Empty space (local variable)]
ESP -> 0xFFF4     (New top of the stack, 8 bytes lower)
```

From debugger:

![[Pasted image 20240918210248.png]]

Now, the distance is 8 bytes, like in the image bellow, so, the stack now have 8 bytes of memory space:

![[Pasted image 20240918210433.png]]

We can also see the stack on gdb:

![[Pasted image 20240918211549.png]]

Is also possible to see the **EBP** base pointer (bottom of stack) which is the 3rd element:

![[Pasted image 20240918211943.png]]

So, the stack is filled from left (top) to the right (bottom).

Here is important to note that the **top of the stack lies in a lower memory space**, you can imagine an analogy with a jar upside down filled from the top to the bottom:

 ```
    (Bottom)
 EBP -> | 1st item |
        | 2nd item |  <- (allocated space for local variables)
 ESP -> |__________|  <- (stack pointer moves down as the jar fills up)
     (Top)
```


> [!attention]
> It is important to note that the 8 bytes that we allocated are not the entire space that the stack can store, as the stack frame can grow dynamically. So as we'll see in the next section, we can add as much data as we want. 
> The 8 bytes that we allocated are typically done to reserve local memory for temporary variables or other data that may be needed within the function or code block.
 
## Adding and Removing Data on Stack

To add and remove items on stack frame we use the following commands:

- **PUSH** - used to added data on stack frame.
- **POP** - used to remove data from stack frame.

Let's see an example:

```nasm
/*
Adding and removing data from stack
*/

.section .data

.section .text
.globl _start

_start:
    nop
    nop

    # Stack frame
    movl    %esp, %ebp 		# Creating the stack boundary 

    # create some memory space in stack frame
    subl    $8, %esp    	# Create 8 bytes of space on stack frame
    
    # Adding the data in stack frame
    movl    $100, %eax     # Passing the data to a general purpose register
    pushl   %eax           # Adding the data contained in %eax (100) register to the stack

    movl    $200, %ebx     # Passing the second data (200) to other general purpose register
    pushl   %ebx           # Adding $200 to the stack

    # Changing the value of EBX after pushing it into the stack
    movl    $300, %ebx     # Change %ebx to 300, but this won't affect the stack

    # Removing data
    popl    %ebx           # Removing the ebx value from the stack (this will be 200)
    popl    %eax           # Removing the eax value from the stack (this will be 100)


    # exit syscall
    movl   $1, %eax
    movl   $0, %ebx
    int    $0x80
```

- **The process:**
	- After setting the boundaries and the size of the stack frame we start to add the data using the general-purpose EAX register
	- We add the value: 100 and 200 each 4 bytes size.
	- After all, we pop each data, note that in this step, we pop from the TOP to the Bottom of the stack frame.

Now what do we do with we add 3 values and we want to remove the middle one?
The process is little tricky, you can see it, on the bellow example:

```nasm
.section .text
.globl _start

_start:
    # Stack frame
    movl    %esp, %ebp         # Creating the stack boundary

    # Push values onto the stack using EAX
    movl    $100, %eax         # Load 100 into EAX
    pushl   %eax               # Push 100 onto the stack

    movl    $200, %eax         # Load 200 into EAX
    pushl   %eax               # Push 200 onto the stack

    movl    $300, %eax         # Load 300 into EAX
    pushl   %eax               # Push 300 onto the stack

    # Stack state:
    # +------+
    # | 300  |  <-- Top of stack
    # +------+
    # | 200  |
    # +------+
    # | 100  |
    # +------+

    # Now we want to remove only the 200 from the stack.

    # Step 1: Pop 300 into EAX
    popl    %eax               # Pop the top value (300) into EAX

    # Step 2: Pop 200 from the stack (which is now at the top)
    popl    %eax               # Pop 200 (we just discard it by overwriting EAX)

    # Step 3: Push 300 back onto the stack (restore 300)
    pushl   %eax               # Push the saved value (300) back onto the stack

    # Now the stack contains:
    # +------+
    # | 300  |  <-- Top of stack
    # +------+
    # | 100  |
    # +------+

    # Exit syscall
    movl    $1, %eax           # Syscall number for exit
    movl    $0, %ebx           # Exit code 0
    int     $0x80              # Trigger interrupt to exit
```

---
# Flags Register
In computing, especially in processor architectures like x86, a  [flag register](https://en.wikipedia.org/wiki/FLAGS_register) or simply _flag_ is a single bit in a special register that indicates a specific state or the result of an operation. In the case of x86 processors, these bits are contained in a register called **eflags** (or just **FLAGS** in older versions of x86).

> [!abstract] Before we proceed
>  Let's take a quick view on the difference between unsigned and signed integer. 
> ##### 1. Unsigned Integer:
> An **unsigned** integer can only represent **non-negative** values (i.e., zero and positive numbers). All bits in an unsigned integer are used to represent the magnitude of the number.
> ###### Example for an 8-bit Unsigned Integer:
> - **Range**: 0 to 255.
> - **Binary Representation**: All 8 bits are used for the magnitude.
> ##### 2. Signed Integer:
> A **signed** integer can represent both **negative** and **positive** values. In the common **two’s complement** representation (used in x86 processors), the most significant bit (MSB) is used to indicate the **sign** of the number:
> - `0` in the MSB indicates a **positive** or **zero** value.
> - `1` in the MSB indicates a **negative** value.
> ###### Example for an 8-bit Signed Integer (Two’s Complement):
> - **Range**: -128 to 127.
> - **Binary Representation**: The MSB represents the sign, while the remaining bits represent the magnitude.		

### O que é uma Flag?
A _flag_ is a **status indicator** that generally reflects the result of an arithmetic, logical, or control operation. These indicators are useful because they inform the processor (and consequently the programmer) of what happened during a given instruction.
#### Common flags of x86 processors:
- **Carry Flag(CF)** 
	- Overflow of unsigned integers => CF = 1
- **Overflow Flag (OF)**
	- Overflow/underflow of signed integers => OF = 1
- **Parity Flag (PF)**
	- If the number of digit 1 on a $result$ is:
		- odd => PF = 0
		- even => PF = 1
- **Sign Flag (SF)**
	- if $result > 0$ => SF = 0
	- If $result < 0$ => SF = 1
- **Zero Flag (ZF)**
	- if $result \neq 0$ => SF = 0
	- if $result = 0$ => SF = 1
### Carry Flag
A **Carry Flag** (or _CF_) is one of the most important flags in the x86 processor, mainly used for arithmetic operations. It is part of the _EFLAGS_ (or _FLAGS_ in older processors), which is a 32-bit register that contains various status flags.
#### Function of the Carry Flag
The _carry flag_ is used to indicate that an _unsigned integer overflow_ occurred in a specific arithmetic calculation. Essentially, when performing an operation that results in a value larger than the available space, this flag is set to _1_. Otherwise, it is set to _0_.
For example:
	If an instruction has an 8-bit destination operand but the instruction generates a result larger than $11111111_{b}$ ($255_d$), the Carry flag is set to 1 (CF = 1)
#### Manipulating the Carry flag
We use two operators to control manipulate the CF:
- **stc** - stands for "set carry flag", it sets the C flag to one.
- **clc** - stands for "clear the carry flag", it reset the value to zero.

Here you can see an simple example of code using that instruction:

```nasm
.section .text
.globl _start

_start:
    nop
    nop

    # set the C Flag (stc - set CF)
    stc                             # here we are fliping the CF to 1

    # unset the C flag (clc - clear CF)
    clc                             # Here we are clearing the CF flag (0)

    movl    $1, %eax
    movl    $0, %ebx
    int     $0x80
```

### Overflow Flag

The **Overflow Flag** (or _OF_) is another crucial status flag in the x86 processor, and it is primarily used to detect **signed integer overflow**. It is part of the same **EFLAGS** (or **FLAGS** in older processors) register, which holds various status indicators used to describe the result of executed instructions.
#### Function of the Overflow Flag
The _overflow flag_ is used to indicate when the result of an arithmetic operation (typically addition or subtraction) has exceeded the capacity of the destination operand when treated as a **signed** number. Essentially, this means that if the sign of the result does not make sense given the signs of the operands, the _overflow flag_ is set to **1**. Otherwise, it is set to **0**.
For example:
	1. If an instruction has a 16-bit destination operando but generates a negative result smaller than $1111111111111111_b$ ($-32.768_d$), the _Overflow Flag_ is set (OF = 1)
		2. Let $a > b> 0>c$  three numbers, if:
			- $a+b<0$, then CF = 1
			- $b-a<0$, then CF = 1
			- $a-c<0$, then CF = 1
		 This happens because the result exceeds the representable range for the   signed data type. 
	
> [!abstract] Note
> The range for signed numbers is  $[-2^{n-1}, 2^{n-1} + 1]$,  where $n$ is the number of bits.
> So, by putting $n=16$, the range is $[-32768,3267]$

#### Manipulating the Overflow Flag
The manipulation of the Overflow Flag is a bit tricky. The maximum amount of data a register can hold is **0x7fffffff** ($2147483647_d$). We send this value to the register to reach its limit, and then, we send more data, causing the Overflow Flag (OF) to be triggered by the register overflow.
To clear the register we use the XOR logical operator with itself. (A xor A = 0, for every A)

```nasm
.section .text
.globl _start
_start:  

nop
nop  

# Set the Overflow Flag
movl $0x7fffffff, %eax     # Here we reached the register data limit
addl $1, %eax              # adding 1_d and triggering the overflow

# Clear the OF
xorl %eax, %eax            # Clear the register, now eax = 0  

# exit
movl $1, %eax
movl $0, %ebx
int $0x80
```

Note that , when we trigger the OF, another flags such the Parity Flag and Sing Flag are triggered too.

![[Pasted image 20241025113431.png]]

We'll see these flags bellow, and you be able to understand why that happens. 
### Parity Flag
The **Parity Flag** (or _PF_) is a status flag in the x86 processor used to indicate the **parity** of the **result of an arithmetic or logical operation**. Like the other flags, it is part of the **EFLAGS** (or **FLAGS** in older processors), which is a 32-bit register that holds various status flags.
#### Function of the Parity Flag
The **parity flag** is used to indicate whether the number of **1-bits** in the **least significant byte (the lower 8 bits)** of a result of a arithmetical or logical operation is **even** or **odd**. If the number of 1-bits is even, the _parity flag_ is set to **1**. Otherwise, it is set to **0**.
For example:
	- $0011 + 1010 = 1101$ => $1101$ have a odd quantity of 1 => PF = 0
	- $0000+1111=1100$ => $1100$ have an even quantity of 1 => PF = 1

#### Manipulating the Parity Flag
In that case we need to perform an arithmetical operation and make the result have a pair number of digit 1.
For that we move a byte with even bits (take $0xA=1010$ for example) of data (_movb_) to the _al_ register which is the lower 8 bits of the _eax_ register[^eax-details]. After that, we use the _test_ logical operator, which is similar to the _and_ but doesn't store the result (see the difference on the end of this section). So:
$$
	0000\ 1010\ \land 0000\ 1010 \implies 0000\ 1010 
$$
Therefore, CF will set to 1.
To clear, we move a odd bit, like $0x1$ to the _al_ register and use _test_ logical operator. In that case:
$$
	0000\ 0001\ \land 0000\ 0001 \implies 0000\ 0001 
$$
thus, CF will be 0.

```nasm
.section .text
.globl _start
_start:

	nop
	nop
	
	# Setting Parity Flag (PF)
	movb 	$0xA,  %al 	# 0xA = 1010 binary (a pair of digit 1)	 	
	test	%al,   %al	# perform AND op: (0000 1010) & (0000 1010) => 0000 1010

	# Clearing the PF
	movb	$0x1,  %al	# Moving 0001 to the al register
	test    %al,   %al	 

	# exit
	movl 	$1, %eax
	movl 	$0, %ebx
	int	$0x80
```

There's another way to clear the CF.
We can add 1 bit to the _al_ register, but it's not so reliable as the method above, because it will only work if _al_ stores a even number of bits.

> [!info] Differences between **test** and **and**
>**Effect on the Destination Operand**:
> - **and** modifies the destination operand with the result of the AND operation.
> - **test** does **not** modify either operand; it just checks the result and updates the CPU’s flags.
>
>**Purpose**:
> - **and** Used to perform actual bitwise operations on data. For example, masking out specific bits.
> - **test**: Used to perform a comparison to see if certain bits are set or clear, without modifying the operands.

[^eax-details]: **EAX** (32-bit): The general-purpose 32-bit register. * **AX** (16-bit): The lower 16 bits of EAX. * **AH** (8-bit): The higher 8 bits of AX. * **AL** (8-bit): The lower 8 bits of AX.
### Sign Flag
The **Sign Flag** (or _SF_) is a status flag in the x86 processor that indicates the **sign** of the **result of an arithmetic or logical operation**. Like the other flags, it is part of the **EFLAGS** register, which contains multiple status indicators used to describe the outcome of operations.
#### Function of the Sign Flag
The **sign flag** is used to reflect the **most significant bit (MSB)** of the result. In x86 architecture, the most significant bit determines whether a number is positive or negative when working with **signed** integers. If the result’s MSB is `1`, the **sign flag** is set to **1** (_SF = 1_), indicating a **negative** result. If the MSB is `0`, the **sign flag** is cleared to **0** (_SF = 0_), indicating a **positive** result.
For example:
	If the most significant bit (MSB) of the destination operand is 1, the Sign Flag is set (_SF = 1_).

#### Manipulating Sign Flag
The manipulation of the SF is similar to the  PF, we sing a negative value to the _eax_ register and use test to do a logical operator resulting in a negative result, which trigger the SF. To clear we make the result be positive.

```nasm
.section .text
.globl _start

_start:
	nop
	nop

	# Setting the SF
	movl	$-1,  %eax	# Send a negative value to eax
	test	$eax, %eax	# Make an and op with negative result

	# Clearing the SF
	movl $1,   %eax
	test %eax, %eax

	# exit
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
```

### Zero Flag
The **Zero Flag** (or _ZF_) is a status flag in the x86 processor that indicates whether the **result of an arithmetic or logical operation** is **zero**. Like other flags, it is part of the **EFLAGS** register, which holds various status indicators used to describe the outcome of operations.
#### Function of the Zero Flag
The **Zero Flag** is set to **1** (_ZF = 1_) if the result of an arithmetic or logical operation is **zero**. Otherwise, it is cleared to **0** (_ZF = 0_).
For example:
	if an operand is subtracted from another of equal value, the Zero flag is set (_ZF = 1_).
#### Manipulating Sign Flag
Here we use _xor_  operation to make a logical result to be zero, finally we use test to clear the flag:

```nasm
.section .text
.globl _start

_start:
	nop
	nop

	# Setting the ZF
	movl 	$1,   %eax
	xorl	%eax, %eax

	# Clearing the ZF
	movl 	$1,   %eax
	test	%eax, %eax	

	# exit
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
```


