.section .data
msg:
    .ascii "Hello World\n"

.equ str_length, 13  # Defining a static symbol (analogous to #define in C)

.section .text
.globl _start
_start:
    # Write "Hello World\n" to stdout
    movl $4, %eax          # syscall number for sys_write (4)
    movl $1, %ebx          # file descriptor for stdout (1)
    movl $msg, %ecx        # pointer to the message
    movl $str_length, %edx # length of the message
    int $0x80              # trigger the system call

    # Exit the program
    movl $1, %eax          # syscall number for sys_exit (1)
    movl $0, %ebx          # exit code 0
    int $0x80              # trigger the system call
