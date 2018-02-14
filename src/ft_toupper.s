section .text
	global _ft_toupper

_ft_toupper:
	push rbp
	mov rbp, rsp
	cmp edi, 0x61
	jl _end
	cmp edi, 0x7a
	jg _end
	sub edi, 0x20
	mov eax, edi
_end:
	leave
	ret
