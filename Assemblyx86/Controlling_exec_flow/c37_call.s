.section .text
.globl _start

_start:
	nop

	movl 	$1, %eax
	movl	$2, %ebx

	call  	move_data	# Here we'll call the move_data label

	# exit 
	movl 	$1, %eax
	movl 	$0, %ebx
	int 	$0x80

move_data: 	 	# another label (similar to function)
	
	movl 	$100, %eax		
	movl 	$200, %ebx	

	ret			# return to the instruction right after call move_data <_start> 
