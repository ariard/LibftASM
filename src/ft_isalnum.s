section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	push rbp
	mov rbp, rsp
	call _ft_isalpha
	mov dword [rbp-0x4], eax
	cmp dword [rbp-0x4], 0x1
	je _end
	call _ft_isdigit
_end:
	leave
	ret
