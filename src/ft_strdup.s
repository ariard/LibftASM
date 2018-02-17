section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_memcpy

_ft_strdup:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _end
	sub rsp, 24
	mov qword [rbp - 8], rdi
	call _ft_strlen
	add rax, 1
	mov qword [rbp - 16], rax
	mov rdi, qword rax
	call _malloc
	leave
	ret
	mov qword [rbp - 24], rax
	mov rdi, qword rax
	mov rsi, qword [rbp - 8]
	mov rdx, qword [rbp - 16]
	call _ft_memcpy 			; beware NULL char
	mov rax, qword [rbp - 24]
_end:
	leave
	ret
