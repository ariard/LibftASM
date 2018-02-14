section .text
	global _ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _end
	cmp rsi, 0
	je _end
	mov rcx, rdx
	cld
	repnz movsb
	mov rax, rdi	
_end:
	leave
	ret
