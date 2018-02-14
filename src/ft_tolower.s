section .text
	global _ft_tolower

_ft_tolower:
	push rbp
	mov rbp, rsp
	cmp edi, 0x41
	jl _end
	cmp edi, 0x5a
	jg _end
	add edi, 0x20
	mov eax, edi
_end:
	leave
	ret
