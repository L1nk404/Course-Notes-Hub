### Jump instruction

We can use the jump instruction to jump to any part of the code, the instruction syntax is _jmp_, we can use as parameter the address memory, or a label (similar to function in high-level language):
- `jmp <address_memory>
- `jmp <label>

Let's see a example:

```nasm
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
```

In the code above the the execution flow is:
$$
	\_start \rightarrow move\_data \rightarrow jmp\_back
$$

> [!warning] Note
> Is important to note that when we  jump to some local, we **don't** return back when that label ends, so, if we want to return, we must jump back to the place where we are just after the _jmp_ instruction

### Call Instruction

Different to _jmp_ instruction, _call_ instruction back to the last location after the label called by _call_, we just need to use _ret_ (return) instruction to it.
In the example above, we can save some lines:

```nasm
.section .text
.globl _start

_start:
	nop

	movl 	$1, %eax
	movl	$2, %ebx

	call  	move_data	# Here we'll call the move_data label

	# exit 
	movl 	$150, %eax
	movl 	$250, %ebx

move_data: 	 	# another label (similar to function)
	
	movl 	$100, %eax		
	movl 	$200, %ebx	

	ret			# return to the instruction right after call move_data <_start> 
```

So, the execution flow will be
$$
	\_start \rightarrow move\_data \rightarrow \_start
$$

The call instruction save the memory address on the stack of the instruction right after call. So when the _ret_ is triggered, it jmp back to that memory address.
We can see it using gdb debugger:

![[Pasted image 20241029213611.png]]

Note that the memory address of the next instruction before call on \_start is  saved on the stack.
After _ret_ instruction executed, the memory are excluded from stack frame.