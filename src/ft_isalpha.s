section .text
	global _ft_isalpha

_ft_isalpha:
	push rbp
	mov rbp, rsp
	xor rax, rax
	cmp rdi, 0x41
	jl _no_match
	cmp rdi, 0x5a
	jle _match
	cmp rdi, 0x61
	jl _no_match
	cmp rdi, 0x7a
	jle _match
	jmp _no_match
_no_match:
	add eax, 0x0
	jmp _end
_match:
	add eax, 0x1
	jmp _end
_end:
	leave
	ret
