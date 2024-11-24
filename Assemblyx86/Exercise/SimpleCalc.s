#  Program Description:
#  --------------------
#  This program takes a natural number (up to 4 digits) as input from the user, processes it,
#  adds 3 to the number, and then converts the resulting integer back into a string for display.
# 
#  Key Steps:
#  1. Prompt the user to enter a natural number using a system call (write).
#  2. Read the user input (up to 4 characters) into a buffer (str_data) using a system call (read).
#  3. Convert the user input (a string of ASCII digits) into an integer (str_to_int_loop).
#     - Handles both 4-digit and shorter input (stopping at a NULL terminator if present).
#  4. Add 3 to the resulting integer (simple arithmetic operation).
#  5. Convert the resulting integer back into a string (int_to_str_loop).
#     - The conversion stores digits in reverse order and adds a NULL terminator.
#  6. Display the resulting string using a system call (write).
# 
#  Notes:
#  - The program uses explicit buffer zeroing to ensure clean and predictable memory usage.
#  - Handles edge cases like shorter input strings or zero as input.
#  - Relies on basic system calls (`write`, `read`, `exit`) for input/output and termination.


.globl _main

.section .data  
    msg:                            # Message to prompt to the user
        .ascii "Enter a natural number up to 4 digits: "

    msg_len = . - msg               # msg lenght 

.section .bss
    .comm int_data, 4               # Buffer to store the integer after conversion 
    .comm str_data, 4               # Buffer to str_data (user_input)
    .comm str_output, 6             # Buffer for str_output, 5 bytes to digits + NULL

.section .text

_main:

    # write(stdout(1), msg, msg_lenght) syscall - Prompt to the user enters a number
    movl    $4, %eax                # write syscall(4)
    movl    $1, %ebx                # stdout(1)        
    movl    $msg, %ecx              # "Enter a natural number up to 4 digits: "
    movl    $msg_len, %edx          # buffer size
    int     $0x80                   # system call !

    movl    $0x00000000, str_data   # Zero out str_data buffer before reading input

    # read(stdin(0), str_data, 4) syscall - Read a naturam number up to 4 digits
    movl    $3, %eax                # read syscall(3)
    movl    $0, %ebx                # stdin(0)
    movl    $str_data, %ecx         # pointing to the buffer
    movl    $4, %edx                # buffer size
    int     $0x80                   # system call !

    ############################################################################
    # This part of the code converts str_data into a integer type
    # (str)str_data => int (int)data
    #
    # Alghorithm:
    #   - Start with an initial value of $0$ in a register to accumulate the result.
    #   - For each character in the string:
	#       - Subtract 0x30 (ASCII value for 0) to get the numeric value of the character.
	#       - Multiply the current accumulated result by $10$.
	#       - Add the numeric value to the accumulated result.


    # Initialize the variables
    xorl    %eax, %eax              # Zeroing EAX (acumulator for the integer result)
    xorl    %edi, %edi              # Zeroing EDI (counter)
    movl    $str_data, %esi         # ESI points to the start of the string

str_to_int_loop:
    # Setting conditions of the loop
    ## Case 1 - User enter exactly 4 digits (String will not have NULL)
    cmp     $3, %edi                # Check if the digits count = 4 (3+1)
    je      end_str_to_int          # If 4 digits, end loop

    ## Case 2 - The user enter fewer than 4 digits
    movzbl  (%esi), %ebx            # Load the current byte into EBX (zero-extended)
    cmpb    $0, %bl                 # Check if it's the NULL(0x0) terminator 
    je      end_str_to_int          # If NULL, end loop

    # Conversion alghorithm
    subb    $0x30, %bl              # BL = (%esi) - 0x30 
    imull   $10, %eax, %eax         # EAX = EAX * 10
    addl    %ebx, %eax              # EAX = EBX + EAX      

    # Move pointer and loop
    incl    %esi                    # Move the pointer to next character
    incl    %edi                    # Increment counter
    jmp     str_to_int_loop

end_str_to_int:
    movl    %eax, int_data          # Move the EAX value (int num) to int_data

    ############################################################################
    # Adding + 3 to int_data

    movl    $3, %eax                # Load EAX 
    addl    %eax, int_data          # int_data = int_data + 3

    ############################################################################
    # This part of code converts int_data to str_data
    # (int)int_data => (str)str_data
    #
    # Algorithm:
    #   - Zero the label
    #   - Repeat until quotient becomes 0:
    #       - Get the LSD of the number (number % 10).
    #       - Convert it to ASCII by adding  ().
    #       - Store the character (in reverse order)

    # Initialize the variables
    movl    int_data, %esi          # Copy int_data into ESI to divide

    ## Zeroing the str_data
    movl    $0x00000000, str_output # Zero 4 bytes of int_data
    leal    str_data+4, %edi        # Pointing to the 5th Byte
    movb    $0x00, (%edi)           # Zero 1 byte of int_data (NULL terminator)

int_to_str_loop:
    # ESI % 10
    movl    $10, %ecx               # Set divisor to 10
    xorl    %edx, %edx              # Zeroing EDX for division
    divl    %ecx                    # Divide ESI(actual_int) by 10
    addb    $0x30, %dl              # Add "0" to MOD(actual_int)
    decl    %edi                    # Move buffer to the left
    movb    %dl, (%edi)             # Store ASCII digit in buffer
    testl   %eax, %eax              # Check if quotient is Zero
    jnz     int_to_str_loop         # Repeat if EAX != 0 

    # write(stdout(1), str_output, 6) syscall - Prompt to the user enters a number
    movl    $4, %eax
    movl    $1, %ebx
    movl    $str_output, %ecx
    movl    $6, %edx
    int     $0x80

    # exit(0) 
    movl    $1, %eax                
    movl    $0, %ebx                # Return code: 0
    int     $0x80                   # Goodbye 

