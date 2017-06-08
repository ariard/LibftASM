section .text
	global _ft_strcat
	extern _ft_strlen
	extern _ft_memcpy

_ft_strcat:
	push rbp
	mov rbp, rsp
	sub rsp, 32
	mov QWORD [rbp-0x8], rdi
	mov QWORD [rbp-0x10], rdi
	call _ft_strlen
	mov QWORD [rbp-0x18], rax
	mov rdi, rsi
	call _ft_strlen
	mov QWORD [rbp-0x20], rax
	mov rax, QWORD [rbp-0x18]
	add QWORD [rbp-0x10], rax
	mov rdi, QWORD [rbp-0x10]
	mov rdx, QWORD [rbp-0x20]
	call _ft_memcpy
	mov rax, QWORD [rbp-0x8]
	add rsp, 32
	leave
	ret
