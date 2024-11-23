# Program: Create Directory
# Description:
#   1. Prompts the user to enter a directory name.
#   2. Reads the directory name input.
#   3. Replaces any trailing newline with a null terminator.
#   4. Creates the directory using the `mkdir` syscall.
#   5. Exits gracefully.
# Usage:
#   Assemble and link the program, then run it:
#     as -o mkdir.o mkdir.s
#     ld -o mkdir mkdir.o
#     ./mkdir
# Note:
#   The directory is created with permissions `0755` (rwxr-xr-x).


.section .data
msg:
    .ascii "Enter a folder name: "
msg_len = . - msg                   # Calculate the lenght of msg

sucess_prompt:
    .ascii "The directory was created with permissions `0755` (rwxr-xr-x)\n"
succes_len = . - sucess_prompt

error_prompt:
    .ascii "The directory creation was failed!\n"
error_len = . - error_prompt

.section .bss
    .comm folder_name, 20           # Reserves 20 bytes of memory for the user input

.section .text
.globl _start

_start:
    nop

    # Write sycall - Prompt the user to enter the fodler name
    movl    $4, %eax                # write syscall (4)
    movl    $1, %ebx                # stdout (1)
    movl    $msg, %ecx              # message to be prompt
    movl    $msg_len, %edx          # lenght of msg
    int     $0x80                   # trigger syscall

    # Read syscall - Read folder_name
    movl    $3, %eax                # read syscall (3)
    movl    $0, %ebx                #stdin (0)
    movl    $folder_name, %ecx      # pointing to the buffer
    movl    $20, %edx               # buffer lenght
    int     $0x80                   # trigger syscall

    #########################################################################################
    # That part of code do:
	#
	# 1.  Validate Input Lenght 
    #      
    #      Counts the character to ensure input does not exceed 19 bytes (excluding '\0').
    #
    # 2. Adding Null Terminator at user input.
    #
    #    After the user enters the folder name, there may be a trailing newline (\n) included 
    #    the input buffer. So We have to replace the new line (\n) to null terminator (\0)
    #
    #     ASCII table:
    #      - Line Feed (\n) = 0x0A
    #      - Null character = 0x00
    #########################################################################################
    
    movl    $folder_name, %esi      # Pointing to buffer
    xorl    %edi, %edi              # Zeroing EDI

check_input_length: 
    cmpb    $0x0A, (%esi)           # Check if current char is '\n'
    je      null_terminate          # if True, jump to null_terminate
    inc     %esi                    # move to the next character (increment pointer by 1)
    inc     %edi                    # increment edi
    cmpl    $19, %edi               # check if counter = 20
    je      truncate_input          # if limit reached, truncate input
    jne     check_input_length      # Loop if not null terminator

null_terminate:
    movb    $0x00, (%esi)           # Replace '\n' with '\0'
    jmp     end_validation          # Continue program

truncate_input:
    movl    $folder_name, %esi      # reset pointer to start of buffer
    addl    $19, %esi               # move the pointer to the 20th character (index 19)
    movb    $0x00, (%esi)           # add null temrinator ('\0') at 20th byte

end_validation:
    #########################################################################################
    # mkdir syscall (39)
    # 
    # int mkdir(const char *pathname, mode_t mode)
    #
    #  mode_t: Data type used to specify file or directory permissions in octal (e.g., 0755).
    #           
    #  Octal  Code	         Permissions Description
    #  0777	  rwxrwxrwx	     Full access for all users.
    #  0755	  rwxr-xr-x	     Read, write, execute for owner; read, execute for group/others.
    #  0700	  rwx------	     Full access for owner only.
    #  0644	  rw-r--r--	     Read/write for owner; read-only for group/others. 
    #########################################################################################
     
    # mkdir syscall 
    movl    $39, %eax               # mkdir syscall (39)
    movl    $folder_name, %ebx      # string - pathname
    movl    $0755, %ecx             # mode_t - rwxr-xr-x
    int     $0x80                   # trigger mkdir

    # error checker
    cmp     $0, %eax                # check if the syscall was sussceful (return value (eax) = 0)
    jl      error_exit              # if syscall failed (return value (eax) < 0 )

    # write syscall - prompt success
    movl    $4, %eax
    movl    $1, %ebx
    movl    $sucess_prompt, %ecx
    movl    $succes_len, %edx
    int     $0x80

    # exit syscall
    movl    $1, %eax
    movl    $0, %ebx
    int     $0x80

error_exit:
    # write syscall - prompt error
    movl    $4, %eax
    movl    $1, %ebx
    movl    $error_prompt, %ecx
    movl    $error_len, %edx
    int     $0x80

    # exit - code -1
    movl    $1, %eax
    movl    $-1, %ebx               # return code -1
    int     $0x80
