	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.intel_syntax noprefix
	.globl	_ft_strrev
	.align	4, 0x90
_ft_strrev:                             ## @ft_strrev
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp2:
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 16], 0
	mov	dword ptr [rbp - 12], 5
	mov	eax, dword ptr [rbp - 12]
	mov	ecx, dword ptr [rbp - 16]
	add	ecx, 1
	sub	eax, ecx
	movsxd	rdi, eax
	mov	rdx, qword ptr [rbp - 8]
	mov	sil, byte ptr [rdx + rdi]
	movsxd	rdx, dword ptr [rbp - 16]
	mov	rdi, qword ptr [rbp - 8]
	mov	byte ptr [rdi + rdx], sil
	mov	rax, qword ptr [rbp - 8]
	pop	rbp
	ret
	.cfi_endproc


.subsections_via_symbols
