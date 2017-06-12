section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp
	mov rcx, 0x7FFFFFFFFFFFFFFF
	xor al, al
	cld
	repnz scasb
	mov rax, 0x7FFFFFFFFFFFFFFE
	sub rax, rcx
	leave
	ret
