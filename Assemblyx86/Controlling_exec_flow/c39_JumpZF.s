.section .text
.globl _start
_start:
	nop

	movl 	$4, %eax
	xorl 	%eax, %eax
	
	jz	jump_here	# jump if zero


jump_here:
	# exit
	movl 	$1, %eax
	movl	$0, %ebx
	int	$0X80 	
