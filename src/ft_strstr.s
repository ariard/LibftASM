section .text
	global _ft_strstr
	extern _ft_strchr
	extern _ft_strcmp

_ft_strstr:
	push rbp
	mov rbp, rsp
	sub rsp, 24
	cmp rdi, 0
	je _end
	cmp rsi, 0
	je _back_needle
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi
	xor esi, esi
_loop:
	mov sil, byte [rsi]
	call _ft_strchr
	cmp rax, 0
	je _null_needle
	mov qword [rbp - 24], rax
	mov rdi, rax	
	mov rsi, qword [rbp - 16]
	call _ft_strcmp	
	cmp rax, 0
	jne _loop
	mov rax, qword [rbp - 24]
	jmp _end
_null_needle:
	xor rax, rax
	jmp _end
_back_needle:
	mov rax, rsi
_end:
	leave
	ret
