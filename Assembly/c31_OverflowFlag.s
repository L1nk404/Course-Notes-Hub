.section .text
.globl _start
_start:

    nop
    nop

    # Set the Overflow Flag
    movl    $0x7fffffff, %eax   # Here we reached the register data limit
    addl    $1,          %eax   # adding 1_d and triggering the overflow

    # Clear the OF
    xorl    %eax, %eax          # Clear the register, now eax = 0

    # exit
    movl    $1, %eax
    movl    $0, %ebx
    int     $0x80
