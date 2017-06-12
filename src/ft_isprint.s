section .text
	global _ft_isprint

_ft_isprint:
	push rbp
	mov rbp, rsp
	mov DWORD [rbp-0x4], edi
	mov DWORD [rbp-0x8], 0x0
	mov eax, DWORD [rbp-0x8]
	cmp DWORD [rbp-0x4], 0x20
	jl _no_match
	cmp DWORD [rbp-0x4], 0x7e
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
