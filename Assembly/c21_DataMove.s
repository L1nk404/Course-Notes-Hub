.section .bss
    .comm mydata, 4         # size 4

.section .text
.globl _start
_start:
    nop
    movl $100, mydata       # moving 100 to mydata 
    # mydata value: 100

    movl mydata, %ecx       # moving mydata to ecx register
    # ecx value: mydata = 100

    # when we use $ before a variable we are refering to their memmory address
    movl $mydata, %edx      # moving the address of mydata to edx register
    movl $500,    %eax      # moving 500 to eax register
    movl %eax,   (%edx)     # moving the eax value to the location which is pointed by the value of edx
                            # ... In that case, we moved eax value to mydata
    # Finally, the mydata value is 500.


    # Exit syscall
    movl $1, %eax
    movl $0, %ebx
    int $0x80