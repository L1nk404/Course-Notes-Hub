## How CPU Loads Number in Memory
Take the following flowchart as example:
![[Number_Asm_dark.drawio.png]]
The process is:
1. The user inputs a decimal value: **123456**
2. The CPU convert from decimal to hexadecimal: **0x bc 61 4e**
3. The hexadecimal value is stored in memory in reverse order: **0x 4e 61 bc**

## Numeric Data Type

|Data Type|Size|Range (Signed)|Range (Unsigned)|
|---|---|---|---|
|`.byte`|1 byte (8 bits)|-128 to 127|0 to 255|
|`.word`|2 bytes (16 bits)|-32,768 to 32,767|0 to 65,535|
|`.int`|4 bytes (32 bits)|-2,147,483,648 to 2,147,483,647|0 to 4,294,967,295|
|`.long`|4 bytes (32 bits)|Same as `.int`|Same as `.int`|
|`.quad`|8 bytes (64 bits)|-2^63 to 2^63 - 1|0 to 2^64 - 1|
|`.short`|2 bytes (16 bits)|Same as `.word`|Same as `.word`|
|`.float`|4 bytes (32 bits)|Single-precision float|Single-precision float|
|`.double`|8 bytes (64 bits)|Double-precision float|Double-precision float|
|`.ascii`|Variable|ASCII text, no null terminator|ASCII text, no null terminator|
|`.asciz`|Variable|ASCII text, null-terminated|ASCII text, null-terminated|

### Integers
#### Signed
In a short way, signed integers are integers which has sign. A **signed** integer can represent both **negative** and **positive** values. In the common **two’s complement** representation (used in x86 processors), the most significant bit (MSB) is used to indicate the **sign** of the number
###### Range:
The range for signed numbers is  $[-2^{n-1}, 2^{n-1} + 1]$,  where $n$ is the number of bits.
So, in 32 bits system, $n=32$, the range is $[−2.147.483.648 , 2.147.483.647]$.
#### Unsigned
An **unsigned** integer can only represent **non-negative** values (i.e., zero and positive numbers). All bits in an unsigned integer are used to represent the magnitude of the number.
###### Range:
The range of unsigned integers are $[0, 2^n - 1]$. In 32 bit system, $n=32$, so, $[0, 4.294.967.295]$.
#### Practical Example
```nasm
.section .data
	signed_value: 		    .int -10 	# Example of a signed integer for comparison
	unsigned_value: 	    .int 10  	# Example of an unsigned integer

	result_signed:		    .int 0		# Placeholder for signed result
    	result_unsigned:	.int 0 		# Placeholder for unsigned result

.section .text
.globl _start

_start:
	# Load signed integer into EAX
	movl 	signed_int, %eax	# EAX now hold -10
	addl 	$5, %eax 		    # add 5 to EAX ( -10 + 5 = -5)
	movl 	%eax, result_signed	# Store result in result_signed

	# Load unsigned integer into EAX
	movl 	unsigned_int, %eax	    # EAX now hold 10 (unsigned)
	addl	$5, %eax		        # add 5 to EAX ( 10 + 5 = 15)
	movl 	%eax, result_unsigned	# Store result in result_unsigned

exit:
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
```
### SIMD Integers
**SIMD** (Single Instruction, Multiple Data) is a technique used in computer architecture that allows a single instruction to perform the same operation on multiple pieces of data simultaneously. **SIMD integer operations** specifically apply SIMD techniques to **integer data types**.
##### What is SIMD
In SIMD, multiple data elements are **packed** into a single **wide register**, and operations are performed on these elements **in parallel**. This parallelism can lead to significant performance improvements in tasks that require repetitive calculations on arrays or vectors of data, such as image processing, audio processing, scientific simulations, and more.
#### SIMD Registers in x86 Architecture
Different than the general purposes registers that holds only 32 bits of data. It holds instruction section such:
- **MMX** (Multimedia Extension) - holds 64 bits registers
- **SSE** (Streaming SIMD Extension) - 128 bits 
##### MMX Registers
The MMX are a instruction section that holds 8 64 bits registers, named from **mm0** to **mm7**. These registers are used to store integer data.

Each MMX register can hold:
- **Eight 8-bit integers** (bytes), or
- **Four 16-bit integers** (words), or
- **Two 32-bit integers** (doublewords).
###### Syntax
To move data to the MMX register we use the letter "q" on the _mov_ operator:

```nasm
.section .data
	value1:	.int	1,2   # 32 bit size

.section .text
.globl _start
_start:
	nop
	
	# mov value1 into one of the MMX registers
	movq 	value1, %mm0
	
	# exit
	movl 	$1, %eax
	movl 	$0, %ebx
	int	    $0x80
```

Using the debugger we can see the _mm0_ register before the value be store:

![[Pasted image 20241110173601.png]]

In the _uint64_, the _u_ stands for unsigned, the _64_ stands for 64 bits, It shows the data stored in this 64 bit unsigned register.
The _v2_ means that the 64 bits register are divided into two 32 bits parts, and how the value stored on each one.
After execute the movq instruction, we can see how the data was stored:

![[Pasted image 20241110174003.png]]

So we can notice that the first element (1) was stored in the most right hand side, and the second element (2) was stored on the top left.
Now look to the _v4\_int16_, notice that there is a 0x0 stored between 0x1 and 0x2. The reason for that is because our data is 32 bit, so the 0x0 is alocated for the 32 bits number.
##### SSE Registers


### Binary Coded Decimal

### Floating Point Number
