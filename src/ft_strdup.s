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
	sub rsp, 0x20
	mov qword [rbp - 0x8], rdi
	call _ft_strlen
	add rax, 0x1
	mov qword [rbp - 0x10], rax
	mov rdi, qword rax
	call _malloc
	mov qword [rbp - 0x18], rax
	mov rdi, qword rax
	mov rsi, qword [rbp - 0x8]
	mov rdx, qword [rbp - 0x10]
	call _ft_memcpy 			; beware NULL char
	mov rax, qword [rbp -0x18]
_end:
	leave
	ret
