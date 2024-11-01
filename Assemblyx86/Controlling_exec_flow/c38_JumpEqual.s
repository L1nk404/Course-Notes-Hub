.section .text
.globl _start

_start:
	nop

	movl	$4, %eax
	movl	$8, %ebx

	# comparing eax with ebx
	cmp 	%eax, %ebx	# doing eax(4) - ebx(8) = -4
	je	jump_here 	# je stands for jump if equal - the jmp will no be taken

jump_here:
	# exit
	movl 	$1, %eax
	movl 	$0, %ebx
	int	$0x80

