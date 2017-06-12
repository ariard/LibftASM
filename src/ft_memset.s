section .text
	global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp-0x8], rdi
	mov rax, rsi
	mov rcx, rdx
	cld
	repnz stosb
	mov rax, QWORD [rbp-0x8]
	leave
	ret
