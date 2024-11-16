.section  .data
	bcd_data: 	
		.byte	0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0x5   # 10 bytes

.section .text
.globl _start
_start:
	nop
	
	fbld 	bcd_data	 # it will store bcd_data into st0 register

	# exit
	movl 	$1, %eax
	movl	$0, %ebx
	int 	$0x80
