.section .data
	value1:	.int	1,2 	# .int = 32 bit size

.section .text
.globl _start
_start:
	nop
	
	# mov value1 into one of the MMX registers
	movq 	value1, %mm0
	
	# exit
	movl 	$1, %eax
	movl 	$0, %ebx
	int	$0x80

