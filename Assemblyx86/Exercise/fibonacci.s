.section .data
msg:
    .ascii "Enter a natural number: "
msg_length = . - msg                # Calculate the length of msg

overflow_msg:
    .ascii "Overflow detected\n"
overflow_msg_lenght = . - overflow_msg

x:                                  
    .long 0                         # Set initial value for Fibonacci (0)        
y: 
    .long 1                         # Set initial value for Fibonacci (1)          

new_line:
    .ascii "\n"
    .equ new_line_length, 2

.section .bss
    .comm int_input, 4              # Reserve 4 bytes for user input
    .comm tmp, 4                    # Stores fibonacci number
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

    # Convert ASCII from int_input into Integer
    call ascii_to_int               # ASCII to Integer and signed the value onto EDX

fibonacci_loop:
    # Condition to break the loop
    cmp     $0, %edx                # if edx = 0
    je      exit                    # jmp to exit

    # Save EDX on the stack to prevent the value to be changed
    pushl   %edx                    # Push EDX counter onto the stack

    # Passing the value of Fibonacci nummber (x) into eax
    movl    x, %eax

    # Print current Fibonacci_number
    call    print_fibonacci_number

    # Calculate Fibonacci Number
    movl    x, %eax                  # Moving x value to EAX
    movl    y, %ecx                  # Moving y value to ECX
    movl    %ecx, tmp                # Saving y value to tmp
    addl    %eax, %ecx               # ecx(y) = eax + ecx = x + y 
    movl    tmp, %eax                # Moving tmp value to EAX
    movl    %eax, x                  # Set x (eax) to previous y (tmp)
    movl    %ecx, y                  # Set y to next Fibonacci number

    # Break if overlow
    jo     overflow_exit             # Exit with code 1

    # Restore the counter value from the stack
    popl    %edx                    

    # decrement the counter by 1
    decl    %edx

    jmp fibonacci_loop

exit:
    # exit - return 0
    movl    $1, %eax
    movl    $0, %ebx                
    int     $0x80

overflow_exit:
    # Write syscall - Prompt Overflow detect to user:
    movl    $4, %eax
    movl    $1, %ebx
    movl    $overflow_msg , %ecx
    movl    $overflow_msg_lenght, %edx
    int     $0x80


    # exit - return 1
    movl    $1, %eax
    movl    $1, %ebx
    int     $0x80


###################################################################################

print_fibonacci_number:
    # Convert eax (Fibonacci number) to ASCII
    movl    %eax, %esi              # Copy Fibonacci number to esi fpr conversion
    movl    $num_str, %edi          # Pointer the buffer to num_str
    addl    $11, %edi               # Move to the end of bugffer for reverse storage
    movb    $0, (%edi)              # Null-terminate at the address stored in EDI

convert_loop:
    # Divide esi by 10 to get each digit
    movl    $10, %ecx               # Set divisor to 10 in ECX
    xorl    %edx, %edx              # Clear edx for division
    divl    %ecx                    # Divide esi by 10; quotient in EAX, remainder in EDX
    addb    $'0', %dl               # Add ASCII 0 (code 48) to %dl (ED low) value 
    decl    %edi                    # Move buffer pointer back (decreasing 1)
    movb    %dl, (%edi)             # Store ASCII digit in buffer 
    testl   %eax, %eax              # Check if the quotient is zero 
    jnz     convert_loop            # Repeat if eax != 0

    # Clearing ZF
    movl    $1, %eax
    testl   %eax, %eax

    # Write syscall - Print the number
    movl    $4, %eax
    movl    $1, %ebx
    movl    $num_str, %ecx
    movl    $12, %edx
    int     $0x80

    # Write syscall - Print new line after each Fibonacci number
    movl    $4, %eax
    movl    $1, %ebx
    movl    $new_line, %ecx          
    movl    $new_line_length, %edx
    int     $0x80

    ret                              # Return

ascii_to_int:
    
    # Convert ASCII input in int_input to integer in EDX
    xorl    %edx, %edx               # Clear EDX for the result (counter)
    movl    $int_input, %esi         # Point ESI to the start of int_input buffer

ascii_to_int_loop:
    movb    (%esi), %al              # Load a byte from int_input
    cmpb    $0x0A, %al               # Check for Line Feed (LN) ASCII code
    je      fibonacci_loop           # If LN, break loop
    subb    $'0', %al                # Convert ASCII to int (subtract ASCII '0')
    imull   $10, %edx                # Multiply current result by 10
    addl    %eax, %edx               # Add the new digit to result in EDX
    incl    %esi                     # Move pointer to the next character
    jmp     ascii_to_int_loop        # Repeat for next digit
