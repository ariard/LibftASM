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
	sub rsp, 24
	mov qword [rbp - 8], rdi
	call _ft_strlen
	cmp rax, 0
	je _null
	dec rax
	mov rsi, qword [rbp - 8]
	add rsi, rax
	mov rdi, qword [rbp - 8]
	mov ch, 2
_loop:
	mov al, byte [rsi]
	mov cl, byte [rdi]
	mov byte [rdi], al
	mov byte [rsi], cl
	inc rdi
	cmp rdi, rsi
	je _string
	dec rsi
	cmp rdi, rsi
	je _string
	jmp _loop
_string:
	mov rax, qword [rbp - 8]
	jmp _end
_null:
	xor rax, rax
_end:
	leave
	ret
