.globl _main

.section .data  
    msg:                        # Message to prompt to the user
        .ascii "Enter a natural number up to 4 digits: "

    msg_len = . - msg           # msg lenght 

.section .bss
    .comm int_data, 4           # Buffer to store the integer after conversion 
    .comm str_data, 4           # 4 * 3 = 
    .comm str_output, 5

.section .text

_main:

    # write(stdout(1), msg, msg_lenght) syscall - Prompt to the user enters a number
    movl    $4, %eax            # write syscall(4)
    movl    $1, %ebx            # stdout(1)        
    movl    $msg, %ecx          # "Enter a natural number up to 4 digits: "
    movl    $msg_len, %edx      # buffer size
    int     $0x80               # system call !

    # read(stdin(0), str_data, 4) syscall - Read a naturam number up to 4 digits
    movl    $3, %eax            # read syscall(3)
    movl    $0, %ebx            # stdin(0)
    movl    $str_data, %ecx     # pointing to the buffer
    movl    $4, %edx            # buffer size
    int     $0x80               # system call !

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
    xorl    %eax, %eax          # Zeroing EAX (acumulator for the integer result)
    xorl    %edi, %edi          # Zeroing EDI (counter)
    movl    $str_data, %esi     # ESI points to the start of the string

convert_loop:
    # Setting conditions of the loop
    ## Case 1 - User enter exactly 4 digits (String will not have NULL)
    cmpb    $3, %edi            # Check if the digits count = 4 (3+1)
    je      end_conversion      # If 4 digits, end loop

    ## Case 2 - The user enter fewer than 4 digits
    movzbl  (%esi), %ebx        # Load the current byte into EBX (zero-extended)
    cmpb    $0, %bl             # Check if it's the NULL(0x0) terminator 
    je      end_conversion      # If NULL, end loop

    # Conversion alghorithm
    subb    $0x30, %bl          # BL = (%esi) - 0x30 
    imull   $10, %eax, %eax     # EAX = EAX * 10
    addl    %ebx, %eax          # EAX = EBX + EAX      

    # Move pointer and loop
    incl    %esi                # Move the pointer to next character
    incl    %edi                # Increment counter
    jmp     convert_loop

end_conversion:
    movl    %eax, int_data      # Move the EAX value (int num) to int_data

    ############################################################################
    # Adding + 3 to int_data

    movl    $3, %eax            # Load EAX 
    addl    %eax, int_data      # int_data = int_data + 3

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

    # Zeroing the str_data
    movl    $0x00000, str_data  # Zero 4 bytes of int_data
    leal    str_data+4, %edi     
    movb    $0x00, (%edi)       # Zero 1 byte of int_data


    # exit(0)
    movl    $1, %eax
    movl    $0, %ebx            # Return code: 0
    int     $0x80               # Goodbye 

