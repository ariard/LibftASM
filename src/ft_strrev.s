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
	sub rsp, 20
	mov qword [rbp - 8], rdi
	call _ft_strlen
	cmp eax, 0
	je _null
	dec eax
	mov rsi, qword [rbp - 8]
	mov rdi, qword [rbp - 8]
	mov dword [rbp - 16], eax
	mov dword [rbp - 20], 0
_loop:
	cmp rax, 0
	je _string
	movsxd rdi, dword [rbp - 16]
	mov rax, qword [rbp - 8]
	mov cl, byte [rax + rdi]
	mov rdi, qword [rbp - 8]
	mov byte [rdi], cl  		; try with load b ?
	jmp _string			; litteraly hijack
_string:
	mov rax, qword [rbp - 8]
	jmp _end
_null:
	xor rax, rax
_end:
	leave
	ret
_end2:
	mov al, cl
	leave 
	ret
