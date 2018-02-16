section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp
	cmp rdi, 0		; check if str exists
	je _end
	mov rcx, 0x7FFFFFFFFFFFFFFF ; set counter to max
	xor al, al					; set accumulator to null
	cld							; auto-increase mode
	repne scasb					; scan string until match with accumulator; decrease counter
	mov rax, 0x7FFFFFFFFFFFFFFE ; set accumulator to max -1
	sub rax, rcx
_end:	
	leave
	ret
