.section .text
.globl _start

_start:
	nop
	nop

	# Setting the ZF
	movl 	$1,   %eax
	xorl	%eax, %eax

	# Clearing the ZF
	movl 	$1,   %eax
	test	%eax, %eax	

	# exit
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
