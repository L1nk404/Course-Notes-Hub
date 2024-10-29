/*
Data exchange instruction
*/

.section .text
.globl _start
_start:
    nop
    nop

    movl    $3, %eax
    movl    $5, %ebx

    # Exchange instruction - swap the eax and ebx values
    xchg    %eax, %ebx              # Exchange data between EAX and EBX
    # Now eax = 5, ebx = 3

    # Byte swap - change (reverse) the order of the bytes
    movl    $0x12345678, %ecx       # Moving hexa value to ecx
    bswap   %ecx                   
    # Now ecx = 78563412 

    # Exit Syscall
    movl    $1, %eax
    movl    $0, %ebx
    int     $0x80
