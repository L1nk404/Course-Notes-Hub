.section .text
.globl _start
_start:
    nop                 # no opertaion (for the debug)

    # imediate values
    movl $25, %eax      # moving the decimal number 25 (32 bit) to eax register
    movw $4,  %bx       # bx is 16 bits register
    movb $1,  %cl       # cl is a 8 bit register (the lower 8 bit register of ecx register)

    # Exit syscall
    movl $1,  %eax     
    movl $0,  %ebx      
    int  $0x80