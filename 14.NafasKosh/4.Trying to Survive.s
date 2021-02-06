	.file	"t.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d%d%d"
.LC1:
	.string	"%s"
.LC2:
	.string	"%d %d %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-36(%rbp), %rcx
	leaq	-40(%rbp), %rdx
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -32(%rbp)
	movl	$0, -28(%rbp)
	movl	$0, -24(%rbp)
	movl	-44(%rbp), %edx
	movl	-40(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L2
	movl	-44(%rbp), %edx
	movl	-36(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L2
	movl	-44(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-36(%rbp), %edx
	movl	-40(%rbp), %eax
	cmpl	%eax, %edx
	cmovge	%edx, %eax
	movl	%eax, -28(%rbp)
	movl	-40(%rbp), %edx
	movl	-36(%rbp), %eax
	cmpl	%eax, %edx
	cmovle	%edx, %eax
	movl	%eax, -32(%rbp)
	jmp	.L3
.L2:
	movl	-40(%rbp), %edx
	movl	-44(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L4
	movl	-40(%rbp), %edx
	movl	-36(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L4
	movl	-40(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-44(%rbp), %edx
	movl	-36(%rbp), %eax
	cmpl	%eax, %edx
	cmovge	%edx, %eax
	movl	%eax, -28(%rbp)
	movl	-36(%rbp), %edx
	movl	-44(%rbp), %eax
	cmpl	%eax, %edx
	cmovle	%edx, %eax
	movl	%eax, -32(%rbp)
	jmp	.L3
.L4:
	movl	-36(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-44(%rbp), %edx
	movl	-40(%rbp), %eax
	cmpl	%eax, %edx
	cmovge	%edx, %eax
	movl	%eax, -28(%rbp)
	movl	-40(%rbp), %edx
	movl	-44(%rbp), %eax
	cmpl	%eax, %edx
	cmovle	%edx, %eax
	movl	%eax, -32(%rbp)
.L3:
	movl	-32(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
	leaq	-13(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movzbl	-13(%rbp), %eax
	cmpb	$65, %al
	jne	.L5
	movzbl	-12(%rbp), %eax
	cmpb	$66, %al
	jne	.L5
	movl	-24(%rbp), %ecx
	movl	-28(%rbp), %edx
	movl	-32(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L5:
	movzbl	-13(%rbp), %eax
	cmpb	$65, %al
	jne	.L7
	movzbl	-12(%rbp), %eax
	cmpb	$67, %al
	jne	.L7
	movl	-28(%rbp), %ecx
	movl	-24(%rbp), %edx
	movl	-32(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L7:
	movzbl	-13(%rbp), %eax
	cmpb	$66, %al
	jne	.L8
	movzbl	-12(%rbp), %eax
	cmpb	$65, %al
	jne	.L8
	movl	-24(%rbp), %ecx
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L8:
	movzbl	-13(%rbp), %eax
	cmpb	$66, %al
	jne	.L9
	movzbl	-12(%rbp), %eax
	cmpb	$67, %al
	jne	.L9
	movl	-32(%rbp), %ecx
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L9:
	movzbl	-13(%rbp), %eax
	cmpb	$67, %al
	jne	.L10
	movzbl	-12(%rbp), %eax
	cmpb	$65, %al
	jne	.L10
	movl	-28(%rbp), %ecx
	movl	-32(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L10:
	movzbl	-13(%rbp), %eax
	cmpb	$67, %al
	jne	.L6
	movzbl	-12(%rbp), %eax
	cmpb	$66, %al
	jne	.L6
	movl	-32(%rbp), %ecx
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L6:
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L12
	call	__stack_chk_fail@PLT
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:

