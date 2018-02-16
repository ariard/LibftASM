section .data
	int_format: db "int is %d", 0
	flag: db "flag", 0

section .text
	global _ft_strrev
	extern _ft_strlen
	extern _printf

_ft_strrev:
	push rbp
	mov rbp, rsp	
	cmp rdi, 0
	je _end
	sub rsp, 9
	mov qword [rbp - 8], rdi
	call _ft_strlen
	cmp eax, 0
	je _null
	mov rsi, qword [rbp - 8]
	add rsi, rax
	dec rsi
	mov rdi, qword [rbp - 8]
_loop:
	cmp rdi, rsi
	je _string
	xor rax, rax
	mov dil, byte [rsi]
	jmp _end2
	mov byte [rdi], al
	mov byte [rdi], ah
	inc rdi
	dec rsi
	jmp _loop
_string:
	mov rax, qword [rbp - 8]
	jmp _end
_null:
	xor rax, rax
_end:
	leave
	ret
_end2:
	mov rax, rdi
	leave 
	ret
