section .text
	global _ft_test
	extern _malloc

_ft_test:
	push rbp
	mov rbp, rsp
	sub rsp, 32
	mov rax, 10
	mov rdi, rax
	call _malloc
	xor ecx, ecx
	mov qword [rbp - 32], rax
	mov eax, ecx
_end:
	leave
	ret
