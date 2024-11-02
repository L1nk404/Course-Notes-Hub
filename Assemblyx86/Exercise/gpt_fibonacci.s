.section .data
msg:
    .ascii "Enter a natural number: "
msg_length = . - msg                # Calculate the length of msg

x:                                  
    .long 0                         # Set initial value for Fibonacci (0)        
y: 
    .long 1                         # Set initial value for Fibonacci (1)          

new_line:
    .ascii "\n"
new_line_length = . - new_line      # Corrected length calculation

.section .bss
    .comm int_input, 4              # Reserve 4 bytes for user input
    .comm tmp, 4                    # Temporary storage for Fibonacci calculation
    .comm num_str, 12               # Buffer for ASCII conversion of Fibonacci number

.section .text
.globl _start

_start:
    nop

    # Write syscall - Prompt the user to enter a number
    movl    $4, %eax                # write syscall (4)
    movl    $1, %ebx                # stdout (1)
    movl    $msg, %ecx
    movl    $msg_length, %edx
    int     $0x80

    # Read syscall
    movl    $3, %eax                # read syscall (3)
    movl    $0, %ebx                # stdin (0)
    movl    $int_input, %ecx        # Pointing to buffer
    movl    $4, %edx                # buffer length
    int     $0x80

    # Load the number of terms entered by the user into the loop counter register
    movl    int_input, %edx         # Load user input to edx (loop counter)

fibonacci_loop:
    # Condition to break the loop
    cmpl    $0, %edx                # if edx == 0
    je      exit                    # jump to exit

    # Load the current Fibonacci number (x) into eax
    movl    x, %eax                 # Load value of x into eax

    # Convert eax (Fibonacci number) to ASCII
    pushl   %edx                    # Save the loop counter on the stack
    movl    %eax, %esi              # Copy Fibonacci number to esi for conversion
    movl    $num_str, %edi          # Pointer to buffer (num_str)
    addl    $11, %edi               # Move to the end of buffer for reverse storage
    movb    $0, (%edi)              # Null-terminate at the address stored in EDI

convert_to_ascii:
    # Divide esi by 10 to get each digit
    movl    $10, %ecx
    xorl    %edx, %edx              # Clear edx for division (edx: remainder)
    divl    %ecx                    # Divide esi by 10; quotient in esi, remainder in edx
    addb    $'0', %dl               # Convert remainder to ASCII    
    decl    %edi                    # Move backward in buffer
    movb    %dl, (%edi)             # Store ASCII digit in buffer
    testl   %esi, %esi              # Check if %esi is 0
    jnz     convert_to_ascii        # Repeat if esi != 0

    popl    %edx                    # Restore the loop counter from the stack

    # Write syscall - Print the Fibonacci number
    movl    $4, %eax                # sys_write
    movl    $1, %ebx                # stdout
    movl    %edi, %ecx              # Buffer starting address after conversion
    movl    $num_str + 12, %edx     # Calculate buffer length
    subl    %edi, %edx              # Adjust length based on edi position
    int     $0x80                   # Make syscall to print number

    # Write syscall - Print newline after each Fibonacci number
    movl    $4, %eax
    movl    $1, %ebx
    movl    $new_line, %ecx
    movl    $new_line_length, %edx
    int     $0x80

    # Calculate the next Fibonacci number
    movl    y, %ecx                 # Load y into ecx
    movl    %ecx, tmp               # Save current y into tmp
    addl    x, %ecx                 # ecx = x + y
    movl    %ecx, y                 # Set y to next Fibonacci number
    movl    tmp, x                  # Set x to previous y (from tmp)

    # Decrement the loop counter directly
    decl    %edx                    # Decrement edx by 1 (number of terms)

    # Repeat the loop
    jmp     fibonacci_loop          # Jump to fibonacci_loop

exit:
    # Exit syscall
    movl    $1, %eax
    xorl    %ebx, %ebx              # Return code 0
    int     $0x80
