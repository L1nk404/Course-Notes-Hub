.section .text
.globl _start
_start:
	nop
	movl	$0x7fffffff, %eax
	addl	$1, %eax		# triggering OF
	jo	jump_here		# jump if OV

jump_here:
	movl	$1, %eax
	movl 	$0, $ebx
	int	$0x80
