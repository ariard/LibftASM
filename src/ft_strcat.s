section .text
	global _ft_strcat
	extern _ft_strlen
	extern _ft_memcpy

_ft_strcat:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _end
	cmp rsi, 0
	je _end	
	sub rsp, 0x20
	mov qword [rbp - 0x8], rdi
	call _ft_strlen
	mov rdi, qword [rbp - 0x8]
	add rdi, rax
	mov qword [rbp - 0x8], rdi
	mov qword [rbp - 0x10], rsi
	mov rdi, rsi
	call _ft_strlen
	mov rdi, qword [rbp - 0x8]
	mov rsi, qword [rbp - 0x10]
	mov rdx, rax
	call _ft_memcpy
	add rax, 0x1 
	mov byte [rax], 0x0
_end:
	leave
	ret
