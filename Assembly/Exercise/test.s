.section .data
    hello_msg:    .asciz "Hello "  # Message to prepend to the name
    output_msg:   .space 32         # Buffer for the final output message (size can be adjusted)

.section .bss
    .comm name_buffer, 15            # Buffer to store the name, length 15

.section .text

.globl _start
_start:
    # Read syscall (3)
    movl $3,    %eax                # syscall number for read
    movl $0,    %ebx                # file descriptor: stdin
    movl $name_buffer,  %ecx        # buffer to store the data
    movl $15,   %edx                # size of input
    int $0x80                         # invoke syscall

    # Construct the output message
    # Copy "Hello " to output_msg
    movl $hello_msg, %esi           # Load address of hello_msg
    movl $output_msg, %edi          # Load address of output_msg
    movl $7, %ecx                   # Length of "Hello " (6 + null terminator)
    rep movsb                        # Copy the string from hello_msg to output_msg



    # Append the name to the output_msg
    movl $name_buffer, %esi         # Load address of name_buffer
    movl $output_msg + 7, %edi      # Address to start copying the name
    movl $15, %edx                  # Maximum length to copy
    int $0x80                        # Read the number of bytes in name_buffer
    subl %eax, %edx                 # Calculate actual length to append
    rep movsb                        # Append the name to output_msg

    # Write syscall (4)
    movl $4,    %eax                # syscall number for write
    movl $1,    %ebx                # file descriptor: stdout
    movl $output_msg, %ecx          # pointer to message
    addl $7, %ecx                   # Move pointer past "Hello "
    addl %eax, %edx                 # Set edx to the total length of the output message
    int $0x80                        # invoke syscall

    # Exit syscall (1)
    movl $1,    %eax                # syscall number for exit
    xorl %ebx, %ebx                 # exit code 0
    int $0x80                        # invoke syscall
