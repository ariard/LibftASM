section .text
	global _ft_isprint

_ft_isprint:
	push rbp
	mov rbp, rsp
	xor rax, rax
	cmp rdi, 0x20
	jl _no_match
	cmp rdi, 0x7e
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
