section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _null
	sub rsp, 16
	mov qword [rbp - 8], rdi
	call _ft_strlen
	mov qword [rbp - 16], rax
	mov rdx, qword [rbp - 16]
	mov rdi, 1
	mov rsi, qword [rbp - 8]
	mov rax, 0x2000000 | 4
	syscall
	xor rax, rax
	mov eax, dword [rbp - 16]
	jmp _end
_null:
	xor rax, rax
_end:
	leave
	ret
