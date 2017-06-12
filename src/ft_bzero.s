section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp
_loop_zero:
	mov BYTE [rdi], 0x0
	add rdi, 0x1
	sub BYTE [rsi], 0x1
	cmp BYTE [rsi], 0x0
	jg _loop_zero
	leave
	ret	
