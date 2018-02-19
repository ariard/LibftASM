section .data
	int_format: db "int is %d\n", 0

section .text
	global _ft_strcat
	extern _ft_strlen
	extern _strlen
	extern _ft_memcpy
	extern _printf

_ft_strcat:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _null
	cmp rsi, 0
	je _null
	sub rsp, 40
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi
	call _ft_strlen
	mov qword [rbp - 24], rax
	mov rdi, qword [rbp - 8]
	add rdi, rax
	mov qword [rbp - 32], rdi
	mov rdi, qword [rbp - 16]
	call _ft_strlen 
	cmp rax, 0
	je _cpy
	add rax, 1 
_cpy:
	mov rdi, qword [rbp - 32]
	mov rsi, qword [rbp - 16]
	mov rdx, rax 	; beware NULL char
	call _ft_memcpy
	mov rax, qword [rbp - 8]
	jmp _end
_null:
	xor rax, rax	
_end:
	leave
	ret
