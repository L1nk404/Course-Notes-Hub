.section .bss   # Session of memory of initialized variables

    # .comm stands for common memory, is used to define bss data
    .comm buffer_var, 15 # Defining a data named buffer_var that holds 15 bytes

.section .text

.globl _start
_start:
    # read syscall for taking user input

    # ssize_t read(int fd, void buf[.count], size_t count)
    # fd to file descriptor, buf to buffer pointer, size is the lenght of buffer

    movl $3, %eax           # read syscall
    movl $0, %ebx           # file descriptor (stdin)
    movl $buffer_var, %ecx  # buffer_var pointer
    movl $15, %edx          # buffer size
    int $0x80               # trigger read syscall

    # write syscall for printing the buffer_var

    movl $4, %eax           # write syscall
    movl $1, %ebx           # stdout
    movl $buffer_var, %ecx  # buffer_var pointer
    movl $15, %edx          # buffer size
    int $0x80               # trigger write syscall

    # exit syscall to exit the program
    movl $1, %eax
    movl $0, %ebx
    int $0x80