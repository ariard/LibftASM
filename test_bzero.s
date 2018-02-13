	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.intel_syntax noprefix
	.globl	_ft_bzero
	.p2align	4, 0x90
_ft_bzero:                              ## @ft_bzero
	.cfi_startproc
## BB#0:
	push	rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Lcfi2:
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	rsi, qword ptr [rbp - 8]
	cmp	byte ptr [rsi], 0
	jne	LBB0_2
## BB#1:
	jmp	LBB0_7
LBB0_2:
	mov	qword ptr [rbp - 24], -1
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [rbp - 24]
	add	rax, 1
	mov	qword ptr [rbp - 24], rax
	cmp	rax, qword ptr [rbp - 16]
	jae	LBB0_7
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=1
	mov	rax, qword ptr [rbp - 8]
	cmp	byte ptr [rax], 0
	je	LBB0_6
## BB#5:                                ##   in Loop: Header=BB0_3 Depth=1
	mov	rax, qword ptr [rbp - 8]
	mov	rcx, rax
	add	rcx, 1
	mov	qword ptr [rbp - 8], rcx
	mov	byte ptr [rax], 0
LBB0_6:                                 ##   in Loop: Header=BB0_3 Depth=1
	jmp	LBB0_3
LBB0_7:
	pop	rbp
	ret
	.cfi_endproc


.subsections_via_symbols
