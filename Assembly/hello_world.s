.section .data               # Initialized data
msg:
    .ascii "Hello world\n"   # 13 characters

.section .text               # Executable code
.global main        # label (main)
main:                      # func implemented

    # Here we are telling the assembly program that we are
    # going to use write (4) System Call
    movl $4, %eax            # Move the immediate value 4 into the EAX register

    # Now we'll tell the system call their arguments
    movl $1, %ebx            # File descriptor for write syscall (stdout)
    movl $msg, %ecx          # Moving buffer pointer to write syscall (just the first element of msg)
    movl $13, %edx           # Moving the buffer size (character counter) in bytes
    int $0x80                # At the end of a syscall we use the 0x80 interrupt code

    # Exit the program
    movl $1, %eax            # 1 is syscall number for exit syscall
    xorl %ebx, %ebx          # 0 is a standard exit code
    int $0x80                # Interrupting exit syscall
