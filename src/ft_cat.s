section .data
	len equ 100

section .bss
	buffer resd 100	

section .text
	global _ft_cat
	extern _ft_bzero	
	extern _printf

_ft_cat:
	cmp rdi, 0
	jl _end
	xor rax, rax
	sub rsp, 0x60
	mov qword [rbp - 0x8], rdi
_read:
	lea rdi, [rel buffer]
	mov rsi, len
	call _ft_bzero
	lea rsi, [rel buffer]
	mov rdi, qword [rbp - 0x8]
	mov rdx, len
	mov rax, 0x2000000 | 3
	syscall	
	cmp rax, -1
	je _end
;	mov qword [rbp - 0x40], rax
;	mov qword [rbp - 0x50], rsi
;	lea rdi, [rel int_format]
;	mov rsi, rax
;	call _printf
;	xor rax, rax
;	mov rax, qword [rbp - 0x40]
;	mov rsi, qword [rbp - 0x50]
	mov qword [rbp - 0x20], rax
	mov rdi, 1
	mov rdx, rax
	mov rax, 0x2000000 | 4
	syscall
;	mov rax, qword [rbp - 0x20]
;	lea rdi, [rel int_format2]
;	mov rsi, rax
;	call _printf
	xor rax, rax
	mov rax, qword [rbp - 0x20]
	cmp rax, 0
	jg _read
_end:
	leave
	ret
