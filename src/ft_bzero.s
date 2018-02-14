section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _end
	cmp rsi, 0
	je _end
_loop:
	mov byte [rdi], 0
	inc rdi	
	dec rsi
	jnz _loop
_end:
	leave
	ret
