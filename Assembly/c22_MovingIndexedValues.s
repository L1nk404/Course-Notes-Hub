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
