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