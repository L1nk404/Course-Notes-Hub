.section .data

.section .text
.globl _start

_start:
    nop
    nop

    # copy the esp address to ebp
    movl    %esp, %ebp  # the base address is the ebp address, so ebp is in the bottom of the stack

    # create some memory space in stack frame
    
