section .text
	global _ft_strjoin
	extern _ft_strdup
	extern _ft_strcat

_ft_strjoin: 
	push rbp
	mov rbp, rsp
	sub rsp, 24
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi		
	call _ft_strdup
	mov qword [rbp - 24], rax
	mov rdi, qword [rbp - 16]
	call _ft_strdup 
	mov rdi, qword [rbp - 24]
	mov rsi, rax
	call _ft_strcat
_end:
	leave
	ret 		 
