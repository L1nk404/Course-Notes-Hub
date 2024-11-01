.section .data                   # Initialized data
msg:
    .ascii "Enter a string: "
.equ msg_length, 16              # Define msg length


.section .bss                    # Uninitialized data
    .comm user_input, 40         # Reserve 40 bytes for user input
.equ buffer_size, 40             # Define buffer size


.section .text
.globl _start

_start:

    nop

    # Syscall: write(4) - Asks the user to enter a string
    movl    $4, %eax             # Syscall number for sys_write
    movl    $1, %ebx             # stdout (1)
    movl    $msg, %ecx           # msg pointer
    movl    $msg_length, %edx    # msg length
    int     $0x80                # Trigger kernel interrupt

    # Syscall: read(3) - Receive string from the user
    movl    $3, %eax             # Syscall number for sys_read
    movl    $0, %ebx             # stdin (0)
    movl    $user_input, %ecx    # buffer pointer
    movl    $buffer_size, %edx   # buffer size
    int     $0x80                # Trigger kernel interrupt

    # Syscall: write(4) - Print the user string
    movl    $4, %eax             # Syscall number for sys_write
    movl    $1, %ebx             # stdout (1)
    movl    $user_input, %ecx    # buffer pointer
    movl    $buffer_size, %edx   # buffer size
    int     $0x80                # Trigger kernel interrupt

    # Exit
    movl    $1, %eax             # Syscall number for sys_exit
    movl    $0, %ebx             # Return code 0
    int     $0x80                # Trigger kernel interrupt
