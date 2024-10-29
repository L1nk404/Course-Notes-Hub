.section  .data
    string:                         # label name
        .ascii "Hello World\n"      # string type
    a:
        .int  4                     # int type
    pi:
        .float 3.14                 # float type
    
.section .text
.globl _start
_start:                             # main function
    movl $1, %eax                   # 1 is exit syscall number
    movl $0, %ebx                   # 0 is a standard exit code
    int $0x80