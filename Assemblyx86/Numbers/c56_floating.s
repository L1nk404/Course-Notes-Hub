.section .data
    myfloat1:                                # Define a 4-byte (single-precision) floating-point number 1.23
        .float      1.23            
    myfloat2:                                # Define an 8-byte (double-precision) floating-point number 1234.5432
        .double     1234.5432       
	multifloat:                              # Define multiple 4-bytes floating-point numbers
        .float 		1.2, 3.5, 77.45, 11.06
.section .bss
    .lcomm data, 8                           # Reserve 8 bytes in uninitialized memory (common block)

.section .text
.globl _start                                # Declare _start as the entry point for the program
_start:
    nop                                      # Placeholder for alignment or debugging (no operation)

    # Load single-precision float (myfloat1) into FPU stack
    flds    myfloat1                         # Load single-precision (4 bytes) floating-point value into ST(0)
    # Load double-precision float (myfloat2) into top of FPU stack, myfloat1 will be passed to ST(1)
    fldl    myfloat2                         # Load double-precision (8 bytes) floating-point value into ST(0)
    # Store the top of the FPU stack (ST(0) = myfloat2) into memory (data)
    fstpl   data                             # Store and pop the double-precision value from ST(0) into memory
    
    # Load mulitple 4-bytes floating-point numbers at xmm0
    movups	multifloat,	%xmm0				 

    # Exit syscall
    movl    $1, %eax                         # Load syscall number for exit (1) into EAX
    movl    $0, %ebx                         # Clear EBX (set to 0) for exit status
    int     $0x80                            # Trigger the syscall using interrupt 0x80
