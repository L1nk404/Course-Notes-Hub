.section .data
    myNumber:
        .int 4,8

.section .text
.globl _start
_start:
    nop

    movl $myNumber, %eax        # Moving myNumber addr to eax register
    movl $2, (%eax)             # Moving 4 bytes 
    movb $9,2 (%eax)            # Moving 1 byte
    movw $3,6 (%eax)            # Moving 2 bytes

    # exit syscal
    movl $1, %eax
    movl $0, %ebx
    int $0x80