section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp
	mov qword [rbp - 8], rdi
	mov	qword [rbp - 16], rsi
	mov	rsi, [rbp - 8]
	test rsi, rsi
	je _end
	mov qword [rbp - 24], 0
_loop:
	mov rsi, [rbp - 8]
	test rsi, rsi
	je _end
	mov rax, qword [rbp - 8]
	mov rcx, rax
	add rcx, 1
	mov qword [rbp - 8], rcx
	mov byte [rax], 0
	mov rax, qword [rbp - 24]
	add rax, 1
	mov qword [rbp - 24], rax
	cmp rax, qword [rbp - 16]
	jl _loop
_end:
	leave
	ret
