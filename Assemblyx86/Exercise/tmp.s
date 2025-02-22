.section .data
    ip_buffer: .asciz "IP: %s\n"
    port_buffer: .asciz "Port: %s\n"

.section .bss
    ip_storage: .space 16  # Buffer for IP
    port_storage: .space 8  # Buffer for Port

.section .text
.global _start

_start:
    # Save the base pointer
    pushl %ebp
    movl %esp, %ebp

    # argc is at [ebp + 8]
    movl 8(%ebp), %ecx      # Get argc
    cmpl $3, %ecx           # Check if argc < 3
    jl _error               # Not enough arguments

    # argv[1] is at [ebp + 12]
    movl 12(%ebp), %eax     # argv[1] -> pointer to IP string
    movl %eax, ip_storage   # Save the pointer or load it into a buffer

    # argv[2] is at [ebp + 16]
    movl 16(%ebp), %eax     # argv[2] -> pointer to Port string
    movl %eax, port_storage # Save the pointer or load it into a buffer

    # (Optional) Print IP and Port for verification
    pushl ip_storage
    pushl $ip_buffer
    call printf
    addl $8, %esp           # Clean up stack after printf

    pushl port_storage
    pushl $port_buffer
    call printf
    addl $8, %esp           # Clean up stack after printf

    # Proceed to connect to the socket
    call socket_connect

    # Exit the program
    call exit

_error:
    # Print an error message and exit
    movl $1, %ebx
    movl $1, %eax
    int $0x80

socket_connect:
    # Example socket connection logic goes here
    # Use syscalls for `socket`, `connect`, etc.
    ret
