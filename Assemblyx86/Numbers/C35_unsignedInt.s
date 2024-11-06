.section .data
	signed_value: 		.int -10 	# Example of a signed integer for comparison
	unsigned_value: 	.int 10  	# Example of an unsigned integer

	result_signed:		.int 0		# Placeholder for signed result
    result_unsigned:	.int 0 		# Placeholder for unsigned result

.section .text
.globl _start

_start:
	# Load signed integer into EAX
	movl 	signed_int, %eax		# EAX now hold -10
	addl 	$5, %eax 				# add 5 to EAX ( -10 + 5 = -5)
	movl 	%eax, result_signed		# Store result in result_signed

	# Load unsigned integer into EAX
	movl 	unsigned_int, %eax		# EAX now hold 10 (unsigned)
	addl	$5, %eax				# add 5 to EAX ( 10 + 5 = 15)
	movl 	%eax, result_unsigned	# Store result in result_unsigned

exit:
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
	
