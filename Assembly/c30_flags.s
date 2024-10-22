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