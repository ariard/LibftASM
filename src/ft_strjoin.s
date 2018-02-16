section .text
	global _ft_strjoin
	extern _ft_strdup

_ft_strjoin: 
	push rbp
	mob rbp, rsp
	subp rsp, 24
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi		
	call _ft_strdup
	mov qword [rbp - 24], rax
	mov rdi, qword [rbp - 16]
	call _ft_strdup 
	mov rdi, qword [rbp - 24]
	mov rsi, rax
	call _ft_strcat
_end
	leave
	ret 		 
