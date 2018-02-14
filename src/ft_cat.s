 wction .data
	len equ 100

section .bss
	buffer resd 100	

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov QWORD [rbp-0x4], rdi
_read:
	mov rdi, QWORD [rbp-0x4]
	lea rsi, [rel buffer]
	mov rdx, len
	mov rax, 0x2000000 | 3
	syscall	
	cmp rax, 0
	je _end
	mov rdi, 1
	lea rsi, [rel buffer]
	mov rdx, rax
	mov rax, 0x2000000 | 4
	syscall
	jmp _read
_end:
	add rsp, 16
	leave
	ret
