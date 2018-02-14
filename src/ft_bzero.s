section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp
	cmp rdi, 0x0 		; check if ptr exists
	je _end
	cmp rsi, 0x0		; check if size exists
	je _end
_loop:
	mov byte [rdi], 0x0
	inc rdi				; increase ptr
	dec rsi				; decrease ptr
	jnz _loop
_end:
	leave
	ret
