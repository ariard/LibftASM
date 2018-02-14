section .text
	global _ft_isdigit

_ft_isdigit:
	push rbp
	mov rbp, rsp
	xor rax, rax
	cmp rdi, 0x30
	jl _no_match
	cmp rdi, 0x39
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
