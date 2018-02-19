section .text
	global _ft_strjoin
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy
	extern _ft_strcat

_ft_strjoin: 
	push rbp
	mov rbp, rsp
	sub rsp, 32
	cmp rdi, 0
	je _null
	cmp rsi, 0
	je _null
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi		
	mov rdi, qword [rbp - 8]
	call _ft_strlen
	mov qword [rbp - 24], rax
	mov rdi, qword [rbp - 16]	
	call _ft_strlen
	add rax, 1
	add rax, qword [rbp - 24]
	mov rdi, rax
	call _malloc 
	mov rdi, rax
	mov rsi, qword [rbp - 8]
	mov rdx, qword [rbp - 24]
	add rdx, 1
	call _ft_memcpy
	mov rdi, rax
	mov rsi, qword [rbp - 16]
	call _ft_strcat
	jmp _end
_null:
	xor rax, rax		
_end:
	leave
	ret
