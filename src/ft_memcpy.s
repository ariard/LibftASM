section .text
	global _ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _end
	cmp rsi, 0
	je _end
	sub rsp, 0xc
	mov [rbp - 0x8], rdi
	mov rcx, rdx
	cld
	rep movsb
	mov rax, [rbp - 0x8]
_end:
	leave
	ret
