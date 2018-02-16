section .text
	global _ft_strrev
	extern _ft_strlen

_ft_strrev:
	push rbp
	mov rbp, rsp	
	cmp rdi, 0
	je _end
	sub rsp, 9
	mov qword [rbp - 8], rdi
	call _ft_strlen
	mov rsi, qword [rbp - 8]
	add rsi, rax - 1
_loop:
	cmp rdi, rsi
	je _end
	mov byte [rbp - 9], byte [rdi]
	mov byte [rdi], byte [rsi]
	mov byte [rsi], byte [rbp - 9]
	jmp _loop
_end:
	mov rax, qword [rbp - 8]
	leave
	ret
