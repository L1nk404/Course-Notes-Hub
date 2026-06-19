extern printf

.globl _start

.section .data
    missing_arg_msg:                # Message to be prompt in case of missing args
        .ascii      "Usage: ./%s <target_ip> <target_port>\n"

    ip_buffer:
        .asciz      "IP: %s\n"
    port_buffer:
        .asciz      "Port: %s\n"

.section .bss
    self_name_buffer:               # Reserved space for program name
        .space  128
    ip_storage:                     # Buffer for IP
        .space  16          
    port_storage:                   # Buffer for Port
        .space  8   

.section .text

_start:
    # Save base pointer
    pushl   %ebp
    movl    %esp, %ebp

    # argc is at [ebp + 8]
    movl    8(%ebp), %ecx           # Get argc
    cmpl    $3, %ecx                # Check if argc < 3
    jl      _missing_args_exit

_missing_args_exit:
    # Load argv[0](program name)
    movl    12(%ebp), %eax          # argv[0] is at ebp + 12
    #movl    %eax, self_name_buffer  # store program name at self_name_buffer

    # Print the error message
    pushl   %eax                    # Push program name to stack 
    pushl   $missing_arg_msg        # Push message string
    call    printf                  # call printf function

    addl    $8, %esp                # Cleaning stack
    
    movl    $1, %eax
    movl    $1, %ebx
    int     $0x80

