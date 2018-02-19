section .text
	global _ft_isascii

_ft_isascii:
	push rbp
	mov rbp, rsp
	xor rax, rax
	cmp rdi, 0x0
	jl _no_match
	cmp rdi, 0x7f
	jle _match
	jmp _end
_no_match:
	add eax, 0x0
	jmp _end
_match:
	add eax, 0x1
	jmp _end
_end:
	leave
	ret
