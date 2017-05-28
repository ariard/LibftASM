section .data
hello:
	.string db "Hello World!", 10
	.len equ $ - hello.string

section .text
	global _ft_test

_ft_test:
	push rbp
	mov rbp, rsp
	mov eax, 0x0
	cmp edi, 0x61
	jl _end
	cmp edi, 0x7a
	jg _end
	sub edi, 0x20 
	mov eax, edi
_end:
	leave
	ret
