section .text
	global ft_memcpy
	
_ft_memcpy:
	push rbp
	mov rbp, rsp
	cmp BYTE [rdi], 0x0
	jne _copy_s2
_loop_s1:
	add rdi, 0x1
	cmp BYTE [rdi], 0x0
	jne _loop_s1					
_copy_s2:
	cmp BYTE [rsi], 0x0
	jne _end
	mov BYTE [rdi], BYTE [rsi]
	add rdi, 0x1
	add rsi, 0x1
	jmp _copy_s2
_end:
	mov BYTE [rdi], 0x0
	leave
	ret	
