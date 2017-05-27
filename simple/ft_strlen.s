section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp
	mov DWORD [rbp-0x4], 0x0
_loop_count:
	add rdi, 0x1
	mov eax, DWORD [rbp-0x4]
	add eax, 0x1 	
	mov DWORD [rbp-0x4], eax
	cmp BYTE [rdi], 0x0
	jne _loop_count
	leave
	ret
