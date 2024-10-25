.section .text
.globl _start
_start:

	nop
	nop
	
	# Setting Parity Flag (PF)
	movb 	$0xA,  %al 	# 0xA = 1010 binary (a pair of digit 1)	 	
	test	%al,   %al	# perform AND op: (0000 1010) & (0000 1010) => 0000 1010

	# Clearing the PF
	movb	$0x1,  %al	# Moving 0001 to the al register	 
	test 	%al,   %al

	# exit
	movl 	$1, %eax
	movl 	$0, %ebx
	int	$0x80
