.section .text
.globl _start

_start:
	nop

	movl 	$1, %eax
	movl	$2, %ebx

	jmp  	move_data   # Here we'll jump to the move_data label

	# that part of code will not be executed after a jump to move_data
	movl 	$150, %eax
	movl 	$250, %ebx

jmp_back: 		# The code will be executed from here
	
	# exit
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
	
move_data: 	 	# another label (similar to function)
	
	movl 	$100, %eax		
	movl 	$200, %ebx
	
	jmp	jmp_back
