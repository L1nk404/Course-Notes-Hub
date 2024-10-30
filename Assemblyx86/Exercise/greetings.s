.section .data                   # Initialized data
    ask_name_msg:               .ascii "Enter your name: "
    hello_msg:                  .ascii "Hello "
    output_msg:                 .space 32               # Buffer for the final output msg

.section .bss                    # Uninitialized variables
    .comm name_buffer, 15       # Name var, length 15

.section .text

.globl _start
_start:
    nop

    # Write syscall (4)  -- First Message
    /*
    More info: man 2 write
    ssize_t write(int fd, const void buf[.count], size_t count);
    */
    movl    $4,    %eax         # Calling write
    movl    $1,    %ebx         # File descriptor: stdout
    movl    $ask_name_msg, %ecx # Pointer to message
    movl    $17,   %edx         # Length of message
    int     $0x80                # Invoke syscall

    # Read syscall (3)  -- Input
    /*
    More info: man 2 read
    ssize_t read(int fd, void buf[.count], size_t count);
    fd = stdin (0) -> ebx register (base pointer of array)
    buf = place to store the data -> ecx (iterates over the array)
    count = length -> edx (used in input/output operations)
    */
    movl    $3,    %eax             # Calling read
    movl    $0,    %ebx             # File descriptor: stdin
    movl    $name_buffer, %ecx      # Buffer to store the data
    movl    $15,   %edx             # Size of input
    int     $0x80                    # Invoke syscall

    # Construct the output message
    movl    $hello_msg,   %esi      # Load address of hello_msg
    movl    $output_msg,  %edi      # Load address of output_msg
    movl    $7,           %ecx      # Lenght of "Hello " + null
    rep     movsb                        # Copy the string from hello_msg to output_msg
    /*rep works like a loop:
    The rep (repeat) prefix in x86 assembly language is used to repeat certain 
    string instructions a specified number of times, as determined by the value
    in the ECX register. It simplifies repetitive operations on strings or arrays.
    */

    # Append the name to the output_msg
    movl     $name_buffer,      %esi    # Load address of name_buffer
    movl     $output_msg + 7,   %edi    # Address to start copying the name
    movl     $15,               %ecx    # Maximum lenght to copy
    int      $0x80                       # Read the number of bytes in name_buffer
    subl     %eax, %edx                 # Calculate actual lenght to append
    rep     movsb                            # Append the name to ouput_msg


    # Write syscall (4)                 
    movl    $4,     %eax                # write syscall
    movl    $1,     %ebx                # stdout
    movl    $output_msg, %ecx           # pointer to message
    addl    %eax,   %edx                # Set edx to the total length of the output_msg
    int     $0x80                        # invoke write
    # exit 
    movl    $1,     %eax
    movl    $0,     %ebx
    int     $0x80