.section .text                  #  Initialized data
msg:
    .ascii "Enter a string: "

.equ msg_length, 16


.section .bss                   # Unitialized data
    .comm user_input, 40

.equ buffer_size, 40


.section .text
.globl _start

_start:

        nop

        # Syscall: write(4) - Asks the user to enter a string
        movl    $4,             %eax
        movl    $1,             %ebx        # stdout(1)
        movl    $msg,           %ecx        # msg pointer
        movl    $msg_length,    %edx
        int     $0x80

        # Syscall: read(3) - Receive string from the user
        movl    $3,             %eax        # read syscall
        movl    $0,             %ebx        # stdin(0)
        movl    $user_input,    %ecx        # buffer_var pointer
        movl    $buffer_size,   %edx        
        int     $0x80

        # Syscall: write(4) - Print the user string
        movl    $4,             %eax
        movl    $1,             %ebx
        movl    $user_input,    %ecx
        movl    $buffer_size,   %edx
        int     $0x80

        # Exit
        movl    $1, %eax
        movl    $0, %ebx
        int     $0x80