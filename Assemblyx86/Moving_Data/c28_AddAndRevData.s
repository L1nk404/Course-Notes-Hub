/*
Adding and removing data from stack
*/

.section .data

.section .text
.globl _start

_start:
    nop
    nop

    # Stack frame
    movl    %esp, %ebp 		# Creating the stack boundary 

    # create some memory space in stack frame
    subl    $8, %esp    	# Create 8 bytes of space on stack frame
    
    # Adding the data in stack frame
    movl    $100, %eax     # Passing the data to a general purpose register
    pushl   %eax           # Adding the data contained in %eax (100) register to the stack

    movl    $200, %eax     # Passing the second data (200) using eax
    pushl   %eax           # Adding $200 to the stack

    # Changing the value of EAX after pushing it into the stack
    movl    $300, %eax     # Change %eax to 300, but this won't affect the stack

    # Removing data
    popl    %eax           # Remove the top of the stack (200) into EAX (EAX value = 200)
    popl    %eax           # Remove the next value (100) into EAX (EAX value = 100)


    # exit syscall
    movl   $1, %eax
    movl   $0, %ebx
    int    $0x80