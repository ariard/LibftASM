section .text
	global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _end
	mov rax,  rsi
	mov rcx, rdx
	cld
	repnz stosb
	mov rax, rdi
_end:
	leave
	ret
