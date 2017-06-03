section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_memcpy

_ft_strdup:
	push rbp
	mov rbp, rsp
	push r12
	push r13
	mov r12, rdi
	call _ft_strlen
	mov r13, rax
	mov rdi, r13
	call _malloc
	mov rdi, rax
	mov rsi, r12
	mov rdx, r13
	call _ft_memcpy
	pop r13
	pop r12
	leave
	ret
