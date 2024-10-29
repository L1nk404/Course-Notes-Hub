.section .data
    msg:
        .ascii "Hello World"

.section .text
.globl _start

_start:
    push $msg
    call printf

    push $0 
    call exit
    