section .text
	global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _null
	sub rsp, 8
	mov qword [rbp - 8], rdi
	mov al, sil
	mov rcx, rdx
	cld
	rep stosb
	mov rax, qword [rbp - 8]
	jmp _end
_null:
	mov rax, qword [rbp - 8]
_end:
	leave
	ret
