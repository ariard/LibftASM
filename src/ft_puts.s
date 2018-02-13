section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp
	lea rsi, [rel rdi]
	call _ft_strlen
	mov rdx, rax
	mov rdi, 1
	mov rax, 0x2000000 | 4
	syscall
	leave
	ret
