.section .text
.globl _start

_start:
	nop
	nop

	# Setting the SF
	movl	$-1,  %eax	# Send a negative value to eax
	test	%eax, %eax	# Make an and op with negative result

	# Clearing the SF
	movl 	$1,   %eax
	test 	%eax, %eax

	# exit
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
