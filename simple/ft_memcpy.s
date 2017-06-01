section .text
	global _ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp-0x4], rdi
	mov rcx, rdx
	cld
	repnz movsb
	mov rax, QWORD [rbp-0x4]
	leave
	ret
