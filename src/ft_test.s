section .text
	global _ft_test
	extern _malloc

_ft_test:
	push rbp
	mov rbp, rsp
	sub rsp, 24
	add rsp, 24
	mov rdi, 20
	call _malloc

_end:
	leave
	ret
