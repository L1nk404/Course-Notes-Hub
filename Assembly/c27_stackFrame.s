.section .data

.section .text
.globl _start

_start:
    nop
    nop

    # copy the esp address to ebp (base pointer)
    movl    %esp, %ebp  # the base address is the ebp address, so ebp is in the bottom of the stack

    # create some memory space in stack frame
    subl    $8, %esp

    # exit syscall
    movl   $1, %eax
    movl   $0, %ebx
    int    $0x80