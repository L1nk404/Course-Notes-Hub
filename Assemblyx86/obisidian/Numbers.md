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

#### Sign in code

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
	movl 	unsigned_int, %eax	# EAX now hold 10 (unsigned)
	addl	$5, %eax		        # add 5 to EAX ( 10 + 5 = 15)
	movl 	%eax, result_unsigned	# Store result in result_unsigned

exit:
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
```
### SIMD Integers
#### MMX Integers
#### SSE Integers

### Binary Coded Decimal

### Floating Point Number
