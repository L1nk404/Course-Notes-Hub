## Numeric Data Type

### Integers
#### Signed
In a short way, signed integers are integers which has sign. A **signed** integer can represent both **negative** and **positive** values. In the common **two’s complement** representation (used in x86 processors), the most significant bit (MSB) is used to indicate the **sign** of the number
###### Range:
The range for signed numbers is  $[-2^{n-1}, 2^{n-1} + 1]$,  where $n$ is the number of bits.
So, in 32 bits system, $n=32$, the range is $[−2.147.483.648 , 2.147.483.647]$.
#### Unsigned
An **unsigned** integer can only represent **non-negative** values (i.e., zero and positive numbers). All bits in an unsigned integer are used to represent the magnitude of the number.
###### Range:
The range of unsigned integers are $[0, 2^n]$. In 32 bit system, $n=32$, so, $[0, 4.294.967.295]$.

### SIMD Integers
#### MMX Integers
#### SSE Integers

### Binary Coded Decimal

### Floating Point Number
