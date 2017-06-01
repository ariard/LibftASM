section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _memcpy
	extern _malloc

_ft_strdup:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp-0x8], rdi
	call _ft_strlen
	mov QWORD [rbp-0xf], rax
	mov rdi, rax
	call _malloc
	mov rdi, rax
	mov rsi, QWORD [rbp-0x8]
	mov rdx, QWORD [rbp-0xf]
	call _ft_memcpy
	mov rax, rdi
	leave
	ret
